

bootblock: bootasm.S bootmain.c
	$(CC) $(CFLAGS) -fno-pic -O -nostdinc -I. -c bootmain.c
	$(CC) $(CFLAGS) -fno-pic -nostdinc -I. -c bootasm.S
	$(LD) $(LDFLAGS) -N -e start -Ttext 0x7C00 -o bootblock.o bootasm.o bootmain.o
	$(OBJDUMP) -S bootblock.o > bootblock.asm
	$(OBJCOPY) -S -O binary -j .text bootblock.o bootblock
	./sign.pl bootblock

# entryother: $(KERNELDIR)/arch/i386/entryother.S
# 	$(CC) $(CFLAGS) -fno-pic -nostdinc -I. -c $(KERNELDIR)/arch/i386/entryother.S
# 	$(LD) $(LDFLAGS) -N -e start -Ttext 0x7000 -o $(KERNELDIR)/arch/i386/bootblockother.o entryother.o
# 	$(OBJCOPY) -S -O binary -j .text $(KERNELDIR)/arch/i386/bootblockother.o $(KERNELDIR)/arch/i386/entryother
# 	$(OBJDUMP) -S $(KERNELDIR)/arch/i386/bootblockother.o > $(KERNELDIR)/arch/i386/entryother.asm

# initcode: $(KERNELDIR)/arch/i386/initcode.S
# 	$(CC) $(CFLAGS) -nostdinc -I. -c $(KERNELDIR)/arch/i386/initcode.S
# 	$(LD) $(LDFLAGS) -N -e start -Ttext 0 -o $(KERNELDIR)/arch/i386/initcode.out initcode.o
# 	$(OBJCOPY) -S -O binary $(KERNELDIR)/arch/i386/initcode.out $(KERNELDIR)/arch/i386/initcode
# 	$(OBJDUMP) -S initcode.o > $(KERNELDIR)/arch/i386/initcode.asm

entryother: entryother.S
	$(CC) $(CFLAGS) -fno-pic -nostdinc -I. -c entryother.S
	$(LD) $(LDFLAGS) -N -e start -Ttext 0x7000 -o bootblockother.o entryother.o
	$(OBJCOPY) -S -O binary -j .text bootblockother.o entryother
	$(OBJDUMP) -S bootblockother.o > entryother.asm

initcode: initcode.S
	$(CC) $(CFLAGS) -nostdinc -I. -c initcode.S
	$(LD) $(LDFLAGS) -N -e start -Ttext 0 -o initcode.out initcode.o
	$(OBJCOPY) -S -O binary initcode.out initcode
	$(OBJDUMP) -S initcode.o > initcode.asm


