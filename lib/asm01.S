

# global _asm_add
.globl asm_add
asm_add:
	# mov %eax, %edi
	# mov %ebx, %esi
	# add %eax, %ebx
	movl $0x04, %ecx
	movl $0x08, %esi
	inc %esi
	# jl block01
	# movb %esi, $0x09
	# movl    -4(%esp), %eax
	movl  %esp, %eax
	# add %edi, %esi
	# movl %edi, %eax
	ret

block01:
	inc %esi
	ret		

.globl asm_f1
asm_f1:
	push   %ebp
	mov    %esp,%ebp
	mov    0xc(%ebp),%eax
	add    0x8(%ebp),%eax
	movl   0x8, %eax
	mov    -0x1(%eax),%bl
	mov    %bx, %sp
	push   $0x20
        add    %eax,%eax
	pop    %ebp	
	ret
	
	
