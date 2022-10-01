all:
	as boot/bootsec.s -o bootsec.o
	as drivers/keypress.s -o keypress.o
	gcc drivers/keyboard.c -c -O0 -I ~/Elemental/include -o keyboard.o
	gcc kernel/kstrlen.c -c -O0 -I  ~/Elemental/include -o kstrlen.o 
	gcc drivers/write.c -c -O0 -I ~/Elemental/include -o write.o
	gcc kernel/kmain.c -c -I ~/Elemental/include -o kernel.o
	mkdir iso
	ld -o bootsec.bin --oformat=binary --Ttext=0x7c00 bootsec.o
	gcc kernel.o write.o keypress.o kstrlen.o keyboard.o  -o kernel.bin  
	cp kernel.bin iso
	cp bootsec.bin iso 
	cd iso
	mkisofs -o elemental.iso -b bootsec.bin -no-emul-boot -boot-load-size 4 -boot-info-table -J -R -V "test iso image" .

clear:
	rm -r iso
	rm bootsec.o keypress.o keyboard.o kmain.o kstrlen.o write.o bootsec.bin elemental.iso kernel.bin kernel.o
	rm -r iso