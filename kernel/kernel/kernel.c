#include <stdio.h>

#include <kernel/tty.h>
#include <kernel/isr.h>
#include <kernel/gdt.h>
#include <debug.h>


void kernel_main() {
	const char* mauros_title = " __  __                   ___  ____\n"
														 "|  \\/  | __ _ _   _ _ __ / _ \\/ ___|\n"
														 "| |\\/| |/ _` | | | | '__| | | \\___ \\\n"
														 "| |  | | (_| | |_| | |  | |_| |___) |\n"
														 "|_|  |_|\\__,_|\\__,_|_|   \\___/|____/\n\n";
	terminal_initialize();
	init_gdt();

	put_ok("Initialized GDT");
	isr_install();
	put_ok("Initialized ISR");
	irq_install();

	printf(mauros_title);
	printf("MaurOS > ");


}
