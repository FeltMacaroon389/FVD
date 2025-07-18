#ifndef FVD_H
#define FVD_H

#include <stdint.h>

// VGA constants
#define VGA_ADDRESS		0xB8000
#define VGA_WIDTH		80
#define VGA_HEIGHT		25

// VGA color definitions
#define VGA_COLOR_BLACK		0
#define VGA_COLOR_BLUE		1
#define VGA_COLOR_GREEN		2
#define VGA_COLOR_CYAN		3
#define VGA_COLOR_RED		4
#define VGA_COLOR_MAGENTA	5
#define VGA_COLOR_BROWN		6
#define VGA_COLOR_LIGHT_GREY	7
#define VGA_COLOR_DARK_GREY	8
#define VGA_COLOR_LIGHT_BLUE	9
#define VGA_COLOR_LIGHT_GREEN	10
#define VGA_COLOR_LIGHT_CYAN	11
#define VGA_COLOR_LIGHT_RED	12
#define VGA_COLOR_LIGHT_MAGENTA	13
#define VGA_COLOR_LIGHT_BROWN	14
#define VGA_COLOR_WHITE		15

// Initialize variables
extern unsigned char* VGA_MEMORY;
extern uint8_t vga_cursor_row;
extern uint8_t vga_cursor_col;

// Function prototypes
void clear_screen(void);
void print_char(const char character, const uint8_t color);
void print_string(const char* string, const uint8_t color);

#endif // FVD_H

