cmake_minimum_required(VERSION 3.15...3.27)
project(daft_lib VERSION "0.0.1")
set(CMAKE_CXX_STANDARD 20)


macro(litgen_find_python)
    # cf https://nanobind.readthedocs.io/en/latest/building.html
    if (CMAKE_VERSION VERSION_LESS 3.18)
        set(DEV_MODULE Development)
    else()
        set(DEV_MODULE Development.Module)
    endif()

    find_package(Python 3.8 COMPONENTS Interpreter ${DEV_MODULE} REQUIRED)
endmacro()

macro(litgen_find_nanobind)
    litgen_find_python()

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


litgen_find_python()
litgen_find_nanobind()
nanobind_add_module(daft_lib daft_lib.cpp)

# Attempt to link SDL2 "a la cmake": this has no effect within pyodide / emscripten
# find_package(SDL2 REQUIRED)
# target_link_libraries(daft_lib PUBLIC SDL2::SDL2 SDL2::SDL2main)

# Link with SDL the emscripten way
target_compile_options(daft_lib PUBLIC "-sUSE_SDL=2")
target_link_options(daft_lib PUBLIC "-sUSE_SDL=2")

target_compile_options(daft_lib PUBLIC "-sRELOCATABLE=1")
target_link_options(daft_lib PUBLIC "-sRELOCATABLE=1")

set(ems_lib_path_pic ${EMSCRIPTEN_SYSROOT}/lib/wasm32-emscripten/pic)
# set(ems_lib_path_pic /home/pascal/dvp/_Bundle/_Pyodide/pyodide/packages/daft_lib/sdl_make_script)
target_link_libraries(daft_lib PUBLIC ${ems_lib_path_pic}/libSDL2.a)


#target_compile_options(daft_lib PUBLIC -sEMCC_FORCE_STDLIBS=1)
#target_link_options(daft_lib PUBLIC -sEMCC_FORCE_STDLIBS=1)

# Manually link libSDL2.a: this will fail because libSDL2.a is compiled without -fPIC
# set(ems_lib_path ${EMSCRIPTEN_SYSROOT}/lib/wasm32-emscripten/)
# target_link_directories(daft_lib PUBLIC ${ems_lib_path})
# target_link_libraries(daft_lib PUBLIC SDL2)

# Hack: manually link an old version of libSDL2.a compiled with -fPIC
# target_link_libraries(daft_lib PUBLIC /home/pascal/dvp/_Bundle/_Pyodide/old/old_pyodide_apr2024/emsdk/emsdk/upstream/emscripten/cache/sysroot/lib/wasm32-emscripten/pic/libSDL2.a)


# Hack: manually link with a custom compiled libSDL2.a
# target_link_libraries(daft_lib PUBLIC /home/pascal/dvp/_Bundle/_Pyodide/pyodide/packages/daft_lib/sdl2_pic_install/lib/libSDL2.a)


install(TARGETS daft_lib DESTINATION .)


