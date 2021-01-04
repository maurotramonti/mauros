#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  char mkfs_str[36];
  char grub_str[96];
  if (argc < 2) {
    printf("ERRORE: non è stato specificato alcun output.\n");
    exit (-1);
  }

  sprintf(mkfs_str, "sudo mkfs.vfat -F 32 -n MaurOS -I %s1", argv[1]);
  if (system(mkfs_str) == -1) exit (-1);
  sprintf(mkfs_str, "sudo mount %s1 /mnt", argv[1]);
  if (system(mkfs_str) == -1) exit (-1);
  sprintf(grub_str, "sudo grub-install --root-directory=/mnt --no-floppy --recheck --target=i386-pc --force %s", argv[1]);
  if (system(grub_str) == -1) exit (-1);
  if (system("sudo cp sysroot/* -r /mnt") == -1) exit (-1);
  if (system("sudo cp isodir/boot/grub/grub.cfg /mnt/boot/grub/") == -1) exit (-1);
  system("sudo umount /mnt");
  return 0;
}
