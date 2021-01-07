#include <stdio.h>

#include <kernel/tty.h>
#include <kernel/isr.h>
#include <kernel/gdt.h>
#include <string.h>

static void add_version_info(int d, int m, int y) {
		terminal_set_coord(43, 5);
		printf("v");
		terminal_writestring_color(itoa(d), VGA_COLOR_CYAN);
		printf(".");
		terminal_writestring_color(itoa(m), VGA_COLOR_GREEN);
		printf(".");
		terminal_writestring_color(itoa(y), VGA_COLOR_RED);
		terminal_writestring_color("-alpha", VGA_COLOR_LIGHT_MAGENTA);
}

void kernel_main() {
	const char* mauros_title = "\t\t\t\t\t __  __                   ___  ____\n"
														 "\t\t\t\t\t|  \\/  | __ _ _   _ _ __ / _ \\/ ___|\n"
														 "\t\t\t\t\t| |\\/| |/ _` | | | | '__| | | \\___ \\\n"
														 "\t\t\t\t\t| |  | | (_| | |_| | |  | |_| |___) |\n"
														 "\t\t\t\t\t|_|  |_|\\__,_|\\__,_|_|   \\___/|____/";
	terminal_initialize();
	init_gdt();
	isr_install();
	irq_install();
	printf(mauros_title);
	add_version_info(7, 1, 21);
	printf("\n MaurOS > ");

}
