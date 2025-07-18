# FVD

**FVD** (Felt VGA Driver) is an extremely simple and minimal 16-color 80x25 VGA text mode driver written in C for the **i386** processor architecture.

**FVD** is not intended for production use.

### Features

- **FVD** provides the following functions:
    - `void clear_screen(void)`
        - Clear the VGA screen and reset the cursor to the top left

    - `void print_char(const char character, uint8_t color)`
        - Print a single character to the VGA screen with a specified VGA color code

    - `void print_string(const char* string, uint8_t color)`
        - Print a character array to the VGA screen with a specified VGA color code

- You can utilize the following color definitions:
    - `VGA_COLOR_BLACK`         (0)
    - `VGA_COLOR_BLUE`          (1)
    - `VGA_COLOR_GREEN`         (2)
    - `VGA_COLOR_CYAN`          (3)
    - `VGA_COLOR_RED`           (4)
    - `VGA_COLOR_MAGENTA`       (5)
    - `VGA_COLOR_BROWN`         (6)
    - `VGA_COLOR_LIGHT_GREY`    (7)
    - `VGA_COLOR_DARK_GREY`     (8)
    - `VGA_COLOR_LIGHT_BLUE`    (9)
    - `VGA_COLOR_LIGHT_GREEN`   (10)
    - `VGA_COLOR_LIGHT_CYAN`    (11)
    - `VGA_COLOR_LIGHT_RED`     (12)
    - `VGA_COLOR_LIGHT_MAGENTA` (13)
    - `VGA_COLOR_LIGHT_BROWN`   (14)
    - `VGA_COLOR_WHITE`         (15)

- The following constants are also provided:
    - `VGA_ADDRESS` (0xB8000)
    - `VGA_WIDTH`   (80)
    - `VGA_HEIGHT`  (25)

- Additionally, the following constants are available to be manually manipulated:
    - `unsigned char* VGA_MEMORY`
        - Pointer to `VGA_ADDRESS`

    - `uint8_t vga_cursor_row`
        - Current row of the VGA cursor

    - `uint8_t vga_cursor_col`
        - Current column of the VGA cursor


### Build instructions

- Ensure you have [Git](https://git-scm.com/), [GNU Make](https://www.gnu.org/software/make/), [i386-elf-gcc](https://wiki.osdev.org/GCC_Cross-Compiler), and [i386-elf-binutils](https://wiki.osdev.org/GCC_Cross-Compiler) installed on your host system.
- Clone the repository: `git clone https://github.com/FeltMacaroon389/FVD.git`
- Move into the cloned directory: `cd FVD`
- Run `make` to compile a 32-bit ELF executable (`fvd.o`), as well as a freestanding 32-bit binary (`fvd.bin`), located in `build/`


### Example usages

- `vga_cursor_row = VGA_HEIGHT / 2; `
  `print_string("Hello, World!\n", VGA_COLOR_WHITE);`

    - This would print "Hello, World!" in white on the middle row of the screen

- `VGA_MEMORY[VGA_WIDTH * VGA_HEIGHT]     = 'X';`
  `VGA_MEMORY[VGA_WIDTH * VGA_HEIGHT + 1] = VGA_COLOR_RED;`

    - This would display a red X in the middle of the screen


### License

**FVD** is licensed under the **MIT license**
A copy of this license can be found at `LICENSE`

