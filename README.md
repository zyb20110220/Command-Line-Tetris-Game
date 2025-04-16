# Command Line Tetris Game

A command-line implementation of the classic Tetris game written in C++, featuring colored blocks, score tracking, level system, and more.

## Features

- Classic Tetris gameplay mechanics
- Colored terminal interface
- 7 different tetrimino shapes
- Real-time next piece preview
- Display of current score, level, and cleared lines
- Game speed increases with level progression

## Game Interface

### Start Screen
![Start Screen](resources/start-page.bmp)

### Game Screen
![Game Screen](resources/game-page.bmp)

## System Requirements

- Linux operating system
- C++17 or higher
- CMake 3.10 or higher
- Terminal with ANSI escape sequence support

## Building and Running

1. Create a build directory:
```bash
mkdir -p build
cd build
```

2. Generate build files:
```bash
cmake ..
```

3. Compile the project:
```bash
make
```

4. Run the game:
```bash
./tetris
```

5. One-command build and run (optional):
```bash
cd /workspaces/Command-Line-Tetris-Game && rm -rf build && mkdir build && cd build && cmake .. && make && cd /workspaces/Command-Line-Tetris-Game/build && ./tetris
```

## Testing

The project includes automated tests that can be run using:

```bash
cd build
ctest
```

## Game Controls

- ←: Move piece left
- →: Move piece right
- ↑: Rotate piece
- ↓: Accelerate piece descent
- Q: Quit game

## Game Rules

- Pieces automatically fall, and players can control their movement and rotation
- When a line is completely filled, it will be cleared and points are awarded
- More points are awarded for clearing multiple lines at once
- Every 10 lines cleared increases the level
- Game difficulty increases with each level (faster falling speed)
- Game ends when new pieces can't be placed

## Project Structure

```
.
├── CMakeLists.txt          # CMake build configuration
├── auto_release/           # Auto-release scripts
│   └── release.ts         # Auto-release implementation
├── include/               # Header files directory
│   ├── game_logic.h      # Game logic
│   ├── game_state.h      # Game state
│   ├── renderer.h        # Renderer
│   ├── terminal.h        # Terminal control
│   └── tetris.h          # Main game class
├── resources/            # Resources directory
│   ├── game-page.bmp    # Game screen screenshot
│   └── start-page.bmp   # Start screen screenshot
└── src/                  # Source files directory
    ├── game_logic.cpp   # Game logic implementation
    ├── game_state.cpp   # Game state implementation
    ├── renderer.cpp     # Renderer implementation
    ├── terminal.cpp     # Terminal control implementation
    └── tetris.cpp       # Main game implementation
```

## Technical Details

This project utilizes:
- C++ Standard Library
- ANSI Terminal Control
- CMake Build System
- Object-Oriented Programming Design

## Automated Releases

The project is configured with an automated release system that creates new releases every Monday. Each release includes:
- Compiled executable
- Version number and release notes
- Build timestamp

## Contributing

Contributions and suggestions are welcome. If you'd like to contribute:

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some amazing feature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Create a Pull Request