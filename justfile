default:
    just -l


ems_clear_cache:
    rm -rf emsdk/emsdk/upstream/emscripten/cache

ems_show_fpic_libs:
    ls -al ./emsdk/emsdk/upstream/emscripten/cache/sysroot/lib/wasm32-emscripten/pic/

# Compile a dummy program to trigger the build of libSDL2.a with -fPIC
ems_trigger_fpic_lib_build:
    echo 'int main() {}' | emcc -x c -sUSE_SDL=2 -sRELOCATABLE=1  - -o output.js && rm output.js
    just ems_show_fpic_libs


build_daft_lib:
    pyodide build-recipes daft_lib


clean_daft_lib:
    rm -f dist/daft_lib*
    rm -rf packages/daft_lib/build
    rm -rf packages/daft_lib/dist

rebuild_daft_lib: clean_daft_lib build_daft_lib


build_imgui_bundle:
    pyodide build-recipes imgui_bundle

clean_imgui_bundle:
    rm -f dist/imgui_bundle*
    rm -rf packages/imgui_bundle/build
    rm -rf packages/imgui_bundle/dist

rebuild_imgui_bundle: clean_imgui_bundle build_imgui_bundle

rebuild_daft_app: ems_clear_cache
    cd packages/daft_lib/daft_ems_app && make clean && make

find_libsdl2:
    find . -name libSDL2.a 

