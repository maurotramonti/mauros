#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

	char dd_string[128];
	char fdisk_string[32];
	char losetup_string[40];
	char *fdisk_instructions = "\nAttenzione: inserire le lettere/numeri nella seguente sequenza (premere Invio dopo ognuno):\n"
													 	 " 1. n\n"
													   " 2. p\n"
													   " 3. 1\n"
													   " 4. (invio)\n"
													   " 5. (invio)\n"
													   " 6. a\n"
													   " 7. w\n\n";


	printf("Benvenuto nello strumento di creazione immagine disco - MaurOS\n");

	if (argc < 4) {

		printf("ERRORE: parametri mancanti.\nUtilizzo: ./disk_image OUTPUT LOOP1 LOOP2\n");
		exit(-1);

	}

	write(1, "[INFO]: creazione del file immagine...\n ", strlen("[INFO]: creazione del file immagine...\n"));
	sprintf(dd_string, "dd if=/dev/zero of=%s bs=512 count=131072", argv[1]);
	if (system(dd_string) == -1) exit (-1);
	write(1, "fatto\n", strlen("fatto\n"));
	write(1, fdisk_instructions, strlen(fdisk_instructions));
	sprintf(fdisk_string, "fdisk %s", argv[1]);
	system(fdisk_string);
	sprintf(losetup_string, "sudo losetup /dev/loop%d %s", atoi(argv[2]), argv[1]);
	if (system(losetup_string) == -1) exit(-1);
	sprintf(losetup_string, "sudo losetup /dev/loop%d %s -o 1048576", atoi(argv[3]), argv[1]);
	if (system(losetup_string) == -1) exit (-1);
	sprintf(losetup_string, "sudo mkdosfs -F32 -f 2 /dev/loop%d", atoi(argv[3]));
	if (system(losetup_string) == -1) exit (-1);
	sprintf(losetup_string, "sudo mount /dev/loop%d /mnt", atoi(argv[3]));
	if (system(losetup_string) == -1) exit (-1);
	write(1, "[INFO]: installazione di GRUB...", strlen("[INFO]: installazione di GRUB..."));
	sprintf(dd_string, "sudo grub-install --root-directory=/mnt --no-floppy --modules=\"normal part_msdos ext2 multiboot\" --target=i386-pc /dev/loop%d", atoi(argv[2]));
	if (system(dd_string) == -1) exit (-1);
	write(1, "fatto\n", strlen("fatto\n"));
	if (system("sudo cp sysroot/* -r /mnt") == -1) exit(-1);
	if (system("sudo cp isodir/boot/grub/grub.cfg -r /mnt/boot/grub/") == -1) exit(-1);
	system("sudo umount /mnt");
	printf("Immagine disco completata!\n");
	return 0;

}
