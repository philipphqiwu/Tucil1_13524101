# Brute-Force LinkedIn Queens Solver

A desktop application that solves the LinkedIn Queens puzzle using both **brute-force** and **backtracking** approaches. The solver tests queen placements across colored regions to find valid configurations where exactly one queen is placed per row, column, and color region — with no two queens adjacent (including diagonals).

Built with **Qt 6 / QML** for a modern graphical interface and a C++ backend implementing the MVC (Model-View-Controller) architecture. The app features a live visualization of the solving process, configurable solve speed, and the ability to load/save board configurations.

## Features

- **Two solving algorithms**: Pure brute-force and optimized backtracking
- **Real-time visualization**: Watch the solver place and remove queens step-by-step
- **Adjustable speed**: Control iteration update frequency and delay
- **File I/O**: Load board configurations from `.txt` files and save solutions
- **Dark/Light mode**: Toggle between themes

## Requirements

### System Requirements

- **Qt**: Version 6.8 or higher (Qt 6.10.2 recommended)
  - Qt Quick module required
- **C++ Compiler**: MinGW 13+ (Windows) or GCC/Clang with C++17 support
- **CMake**: Version 3.16 or higher
- **Operating System**: Windows (primary), macOS, or Linux with Qt support
- **Memory**: At least 512 MB RAM

### Installation

1. **Install Qt 6.8+**: Download from [Qt Online Installer](https://www.qt.io/download-qt-installer)
   - During installation, select a Qt version (e.g., 6.10.2) and the MinGW kit
   - CMake is bundled with Qt

2. **Clone this repository**:

   ```bash
   git clone https://github.com/philipphqiwu/Tucil1_13524101.git
   cd Tucil1_13524101
   ```

## Compilation Instructions

### Using Qt Creator (Recommended)

1. Open `src/CMakeLists.txt` in Qt Creator
2. Select the **Desktop Qt 6.x MinGW 64-bit** kit
3. Choose **Release** build configuration
4. Click **Build** (Ctrl+B)
5. The executable `appqueenss.exe` will be generated in the build directory

### Using Command Line

From the `src/` directory:

```bash
# Configure (adjust CMAKE_PREFIX_PATH to your Qt installation)
cmake -B build/Release -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH="C:/Qt/6.10.2/mingw_64"

# Build
cmake --build build/Release
```

### Deploying as Standalone Executable

After building, run `windeployqt` to bundle all required DLLs:

```bash
# Add Qt and MinGW to PATH first
set PATH=C:\Qt\6.10.2\mingw_64\bin;C:\Qt\Tools\mingw1310_64\bin;%PATH%

# Deploy dependencies
windeployqt build/Release/appqueenss.exe --qmldir .
```

The entire build folder can then be distributed as a standalone application.

## Running the Program

### Step 1: Launch the Application

Run `appqueenss.exe` from the build directory (or from the `bin/` folder).

### Step 2: Load a Board

1. Click **Choose file** on the Input screen
2. Select a `.txt` file containing the board configuration

**Input file format** — each line is a row, and letters represent color regions:

```
AABC
ABBC
DBBC
DDDC
```

### Step 3: Solve

1. Choose the algorithm: **Backtracking** (optimized/heuristic) or **Brute Force** (exhaustive)
2. Adjust visualization speed if desired (update interval and delay)
3. Click **Solve** to watch the solver in action
4. Once solved, you can **save** the solution to either a `.txt` or `.png` file

## Project Structure

```
Tucil1_13524101/
├── src/
│   ├── CMakeLists.txt
│   ├── main.cpp
│   ├── Main.qml
│   ├── ApplicationFlow.qml
│   ├── ApplicationFlowForm.ui.qml
│   ├── Home.qml
│   ├── HomeForm.ui.qml
│   ├── InputScreen.qml
│   ├── InputScreenForm.ui.qml
│   ├── SolvingScreen.qml
│   ├── SolvingScreenForm.ui.qml
│   ├── ResultsScreen.qml
│   ├── ResultsScreenForm.ui.qml
│   ├── HowToPlay.qml
│   ├── HowToPlayForm.ui.qml
│   ├── BoardGrid.qml
│   ├── Colors.qml
│   ├── CustomButton.qml
│   ├── CustomButtonForm.ui.qml
│   ├── CustomToolBar.qml
│   ├── CustomToolBarForm.ui.qml
│   ├── backend/
│   │   ├── queenscontroller.cpp/h
│   │   ├── queensmodel.cpp/h
│   │   ├── queensparser.cpp/h
│   │   └── queenssolver.cpp/h
│   └── Resources/
│       └── images/
├── bin/
├── test/
├── doc/
└── README.md
```

## Author

**Philipp Hamara**
13524101 — Informatics Engineering, Institut Teknologi Bandung