
#include "to_custom_test_utils.h"
#include "to_platform_stubs.h"

#include "ut_cfe_evs_hooks.h"
#include "ut_cfe_time_stubs.h"
#include "ut_cfe_psp_memutils_stubs.h"
#include "ut_cfe_tbl_stubs.h"
#include "ut_cfe_tbl_hooks.h"
#include "ut_cfe_fs_stubs.h"
#include "ut_cfe_time_stubs.h"
#include "ut_osapi_stubs.h"
#include "ut_osfileapi_stubs.h"
#include "ut_cfe_sb_stubs.h"
#include "ut_cfe_es_stubs.h"
#include "ut_cfe_evs_stubs.h"

#include <time.h>

/*
 * Function Definitions
 */

void TO_Custom_Test_Setup(void)
{
    /* initialize test environment to default state for every test */

    CFE_PSP_MemSet(&TO_AppCustomData, 0x00, sizeof(TO_AppCustomData_t));
    CFE_PSP_MemSet(&TO_App_Return, 0x00, sizeof(TO_App_Return));
    CFE_PSP_MemSet(&TO_Platform_Stubs_Returns, 0x00, sizeof(TO_Platform_Stubs_Returns));

    Ut_CFE_EVS_Reset();
    Ut_CFE_FS_Reset();
    Ut_CFE_TIME_Reset();
    Ut_CFE_TBL_Reset();
    Ut_CFE_SB_Reset();
    Ut_CFE_ES_Reset();
    Ut_OSAPI_Reset();
    Ut_OSFILEAPI_Reset();
}

void TO_Custom_Test_TearDown(void) 
{
    
}
