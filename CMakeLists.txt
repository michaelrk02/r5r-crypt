cmake_minimum_required(VERSION 2.6)

###########################################################
# SETUP

# Global
set(PROJECT_LIBRARY SHARED CACHE STRING "Set the library type. Can be SHARED, STATIC, or MODULE")
set(PROJECT_DEBUG TRUE CACHE BOOL "Enable debugging")

# Main project
set(__PROJECT__ "R5R")
set(__LIBRARY__ ${PROJECT_LIBRARY})
set(__DEBUG__ ${PROJECT_DEBUG})
set(__INCLUDE__ "./include")
set(__SRC__ "./src")

# Side projects
set(__R5R_ENC__ "r5r-enc")
set(__R5R_DEC__ "r5r-dec")

###########################################################
# MAIN PROJECT

include_directories(${__INCLUDE__})

project(${__PROJECT__})
add_library(${__PROJECT__} ${__LIBRARY__}
    "${__SRC__}/R5R-Encrypt.cpp"
    "${__SRC__}/R5R-Decrypt.cpp"
    "${__SRC__}/R5R-Misc.cpp"
)

target_compile_definitions(${__PROJECT__}
    PUBLIC "-D__R5R_BUILD__"
)

###########################################################
# SIDE PROJECT: R5R_ENC

set(__R5R_ENC_SRC__ "${__SRC__}/${__R5R_ENC__}")

project(${__R5R_ENC__})
add_executable(${__R5R_ENC__}
    "${__R5R_ENC_SRC__}/main.cpp"
)

add_dependencies(${__R5R_ENC__}
    ${__PROJECT__}
)

target_link_libraries(${__R5R_ENC__}
    ${__PROJECT__}
)

###########################################################
# SIDE PROJECT: R5R_DEC

set(__R5R_DEC_SRC__ "${__SRC__}/${__R5R_DEC__}")

project(${__R5R_DEC__})
add_executable(${__R5R_DEC__}
    "${__R5R_DEC_SRC__}/main.cpp"
)

add_dependencies(${__R5R_DEC__}
    ${__PROJECT__}
)

target_link_libraries(${__R5R_DEC__}
    ${__PROJECT__}
)

