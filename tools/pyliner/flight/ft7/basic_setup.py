from os.path import join, dirname, basename, abspath

import pyliner
from navigation import constant, limiter, proportional

rocky = pyliner.Pyliner(
    airliner_map=join(dirname(abspath(__file__)), "cookiecutter.json"),
    ci_port=5009,
    to_port=5012,
    script_name=basename(__file__),
    log_dir=join(dirname(abspath(__file__)), "logs")
)
