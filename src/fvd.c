#include <fvd.h>

#include <stdint.h>

// Initialize variables
unsigned char* VGA_MEMORY	= ((unsigned char*)VGA_ADDRESS);
uint8_t vga_cursor_row		= 0;
uint8_t vga_cursor_col		= 0;

// Function to clear the screen (fill with black spaces)
void clear_screen(void) {
	for (uint16_t i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
		VGA_MEMORY[i * 2]	= ' ';
		VGA_MEMORY[i * 2 + 1]	= VGA_COLOR_BLACK;
	}

	// Reset the cursor to the top left
	vga_cursor_row = 0;
	vga_cursor_col = 0;
}

// Function to print a single character to the screen at the cursor position
void print_char(const char character, const uint8_t color) {

	// If newline, set column to 0 and increment row
	if (character == '\n') {
		vga_cursor_col = 0;
		vga_cursor_row++;
		
		return;
	
	}
	
	// Set column to 0 and increment row if column is greater or equal to the VGA width
	if (vga_cursor_col >= VGA_WIDTH) {
		vga_cursor_col = 0;
		vga_cursor_row++;
	}
	
	// Wrap back to the top left of the screen if row is greater than the VGA height
	// TODO: Implement scrolling
	if (vga_cursor_row >= VGA_HEIGHT) {
		vga_cursor_row = 0;
		vga_cursor_col = 0;
	}
	
	// Calculate where to put the character
	uint16_t offset = (vga_cursor_row * VGA_WIDTH + vga_cursor_col) * 2;
	
	// Write character and color to VGA memory
	VGA_MEMORY[offset]	= character;
	VGA_MEMORY[offset + 1]	= color;
	
	// Increment VGA cursor column
	vga_cursor_col++;
}

// Function to print a character array to the screen
void print_string(const char* string, const uint8_t color) {
	for (uint32_t i = 0; string[i] != '\0'; i++) {
		print_char(string[i], color);
	}
}

