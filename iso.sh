#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub
mkdir -p isodir/modules

cp sysroot/boot/mauros.kernel isodir/boot/mauros.kernel
cat > isodir/boot/grub/grub.cfg << EOF

set default=0
set timeout=1

menuentry "MaurOS v6.1.21-alpha" {
	multiboot /boot/mauros.kernel
	boot
}
EOF
grub-mkrescue -o mauros.iso isodir
