/****************************************************************************
*
*   Copyright (c) 2017 Windhover Labs, L.L.C. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
*
* 1. Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in
*    the documentation and/or other materials provided with the
*    distribution.
* 3. Neither the name Windhover Labs, L.L.C. nor the names of its 
*    contributors may be used to endorse or promote products derived 
*    from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
* COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
* OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
* AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
* ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
*****************************************************************************/

/* Conversion routines for platforms that do not support 'double' directly. */

#include "double_conversion.h"
#include <math.h>

typedef union {
    float f;
    uint32_t i;
} conversion_t;

/* Note: IEE 754 standard specifies float formats as follows:
 * Single precision: sign,  8-bit exp, 23-bit frac.
 * Double precision: sign, 11-bit exp, 52-bit frac.
 */

uint64_t float_to_double(float value)
{
    conversion_t in;
    in.f = value;
    uint8_t sign;
    int16_t exponent;
    uint64_t mantissa;
    
    /* Decompose input value */
    sign = (in.i >> 31) & 1;
    exponent = ((in.i >> 23) & 0xFF) - 127;
    mantissa = in.i & 0x7FFFFF;
    
    if (exponent == 128)
    {
        /* Special value (NaN etc.) */
        exponent = 1024;
    }
    else if (exponent == -127)
    {
        if (!mantissa)
        {
            /* Zero */
            exponent = -1023;
        }
        else
        {
            /* Denormalized */
            mantissa <<= 1;
            while (!(mantissa & 0x800000))
            {
                mantissa <<= 1;
                exponent--;
            }
            mantissa &= 0x7FFFFF;
        }
    }
    
    /* Combine fields */
    mantissa <<= 29;
    mantissa |= (uint64_t)(exponent + 1023) << 52;
    mantissa |= (uint64_t)sign << 63;
    
    return mantissa;
}

float double_to_float(uint64_t value)
{
    uint8_t sign;
    int16_t exponent;
    uint32_t mantissa;
    conversion_t out;

    /* Decompose input value */
    sign = (value >> 63) & 1;
    exponent = ((value >> 52) & 0x7FF) - 1023;
    mantissa = (value >> 28) & 0xFFFFFF; /* Highest 24 bits */
 
    /* Figure if value is in range representable by floats. */
    if (exponent == 1024)
    {
        /* Special value */
        exponent = 128;
    }
    else if (exponent > 127)
    {
        /* Too large */        
        if (sign)
            return -INFINITY;
        else
            return INFINITY;
    }
    else if (exponent < -150)
    {
        /* Too small */
        if (sign)
            return -0.0f;
        else
            return 0.0f;
    }
    else if (exponent < -126)
    {
        /* Denormalized */
        mantissa |= 0x1000000;
        mantissa >>= (-126 - exponent);
        exponent = -127;
    }
 
    /* Round off mantissa */
    mantissa = (mantissa + 1) >> 1;
    
    /* Check if mantissa went over 2.0 */
    if (mantissa & 0x800000)
    {
        exponent += 1;
        mantissa &= 0x7FFFFF;
        mantissa >>= 1;
    }
    
    /* Combine fields */
    out.i = mantissa;
    out.i |= (uint32_t)(exponent + 127) << 23;
    out.i |= (uint32_t)sign << 31;
    
    return out.f;
}


