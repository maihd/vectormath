VectorMath WASM examples and tests
----------------------------------

How to build
------------
- Setup emscripten on terminal
- Call follow commands:
    ```console
        emcc main.cpp -I../../include -o dist/index.html -lGL -s USE_SDL=2 -s WASM=1
    ```
- (Only Windows) just add `emsdk` to your environment `Path`, and run build.bat
- Host dist/index.html with local web server (lite-server, python http-server, ...)

FAQs
----
- Why pure WebGL? I'm attempting to learn WASM/WebGL with native C/C++.
- Why SDL instead of GLFW? I feel SDL more cleaner and better.
- Where the build.sh? My development environment is only Windows.