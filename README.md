# Pong-Raylib

A simple Pong game built using **C++** and **Raylib**.

## Features
- Classic Pong gameplay
- Simple and lightweight
- Cross-platform support (Windows, Linux, macOS, WebAssembly)

---

## Installation
### 1. Install Raylib
#### **Windows**
Using **vcpkg**:
```sh
vcpkg install raylib
```

Manual installation:
1. Download Raylib from [https://github.com/raysan5/raylib/releases](https://github.com/raysan5/raylib/releases)
2. Extract and place the `raylib` folder in your project directory.
3. Link it during compilation (see build steps below).

#### **Linux/macOS**
Using package manager:
```sh
# Debian/Ubuntu
sudo apt install libraylib-dev

# Arch Linux
sudo pacman -S raylib

# macOS (using Homebrew)
brew install raylib
```

Manual installation:
```sh
git clone https://github.com/raysan5/raylib.git
cd raylib/src
make PLATFORM=PLATFORM_DESKTOP
sudo make install
```

---

## Build Instructions
### **Windows (MinGW)**
```sh
g++ -o pong main.cpp -I<raylib_include_path> -L<raylib_lib_path> -lraylib -lopengl32 -lgdi32 -lwinmm
```
Replace `<raylib_include_path>` and `<raylib_lib_path>` with the appropriate paths to your Raylib installation.

### **Linux/macOS**
```sh
g++ -o pong main.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
```

---

## Running the Game
After building, run:
```sh
./pong
```

---

## Deploying to Web (WASM)
### **Install Emscripten**
1. Download and install the [Emscripten SDK](https://emscripten.org/docs/getting_started/downloads.html)
2. Activate it:
   ```sh
   source /path/to/emsdk/emsdk_env.sh
   ```

### **Compile for WebAssembly**
```sh
emcc main.cpp -o pong.html -I<raylib_include_path> -L<raylib_lib_path> -lraylib -s USE_GLFW=3 -s ALLOW_MEMORY_GROWTH=1 -s WASM=1 --shell-file shell.html
```

### **Run Locally**
Start a local web server:
```sh
emrun --no_browser --port 8080 pong.html
```
Then open `http://localhost:8080` in your browser.

---

## License
This project is licensed under the **MIT License**.

---

## Credits
- Developed with [Raylib](https://www.raylib.com/)
- Inspired by the classic Pong game

