cmake_minimum_required(VERSION 3.15...3.27)
project(daft_lib VERSION "0.0.1")
set(CMAKE_CXX_STANDARD 20)

macro(do_find_python)
    # cf https://nanobind.readthedocs.io/en/latest/building.html
    if (CMAKE_VERSION VERSION_LESS 3.18)
        set(DEV_MODULE Development)
    else()
        set(DEV_MODULE Development.Module)
    endif()
    find_package(Python 3.8 COMPONENTS Interpreter ${DEV_MODULE} REQUIRED)
endmacro()

macro(do_find_nanobind)
    do_find_python()
    # Detect the installed nanobind package and import it into CMake
    execute_process(
        COMMAND "${Python_EXECUTABLE}" -m nanobind --cmake_dir
        OUTPUT_STRIP_TRAILING_WHITESPACE OUTPUT_VARIABLE nanobind_ROOT)
    find_package(nanobind CONFIG REQUIRED)
    if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
        set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
        set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
    endif()
endmacro()

# Main
do_find_nanobind()
nanobind_add_module(daft_lib daft_lib.cpp)

# Attempt to link SDL2 "a la cmake": this has no effect within pyodide / emscripten
# find_package(SDL2 REQUIRED)
# target_link_libraries(daft_lib PUBLIC SDL2::SDL2 SDL2::SDL2main)
# target_compile_options(daft_lib PUBLIC "-sUSE_SDL=2")

# Link with SDL the emscripten way: this is required, but not sufficient to link with SDL2.a
target_compile_options(daft_lib PUBLIC "-sUSE_SDL=2")
target_link_options(daft_lib PUBLIC "-sUSE_SDL=2")


# target_compile_options(daft_lib PUBLIC "-sDYLINK_DEBUG=1")
# target_link_options(daft_lib PUBLIC "-sDYLINK_DEBUG=1")
# target_compile_options(daft_lib PUBLIC "-sASSERTIONS=2")
# target_link_options(daft_lib PUBLIC "-sASSERTIONS=2")

# Manually link libSDL2.a from the emscripten sysroot (using a fPIC compiled version)
# Important: wasm32-emscripten/pic libs are *not compiled by default*, thus meta.yaml 
#            will trigger their build it with the following lines
#      script: |
#        embuilder build sdl2 libhtml5 --pic
set(ems_lib_path_pic ${EMSCRIPTEN_SYSROOT}/lib/wasm32-emscripten/pic)
target_link_libraries(daft_lib PUBLIC ${ems_lib_path_pic}/libSDL2.a)

# Failed attempt to link getprocaddr
# target_link_libraries(daft_lib PUBLIC ${ems_lib_path_pic}/libGL-webgl2-getprocaddr.a)

install(TARGETS daft_lib DESTINATION .)
