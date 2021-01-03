#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/mauros.kernel isodir/boot/mauros.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "MaurOS" {
	multiboot /boot/mauros.kernel
}
EOF
grub-mkrescue -o mauros.iso isodir
