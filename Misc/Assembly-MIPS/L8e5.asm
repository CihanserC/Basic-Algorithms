.data
list: .space 100
character: .byte ' '
.text
main:
addi $t0,$zero,25
lui $t1,0x1001 
addi $t2,$zero,0 #counter 
add $a0,$t0,$zero
add $a1,$t1,$zero
jal fillArray

add $a0,$t0,$zero
add $a1,$t1,$zero
jal printArray

addi $v0,$zero,10
syscall
#############
fillArray:
addi $t2,$zero,0 #counter 
while:
slt $t3,$t2,$a0
beq $t3,$zero,whileend
sw $t2,($a1)
addi $t2,$t2,1
addi $a1,$a1,4
j while
whileend:
jr $ra

printArray:
addi $t2,$zero,0 #counter 
while2:
slt $t3,$t2,$a0
beq $t3,$zero,while2end

add $t5,$a0,$zero

addi $v0,$zero,1 #print integer interrupt
lw $a0,($a1)
syscall

addi $v0,$zero,4
lui $a0,0x1001
addi $a0,$a0,100
syscall

add $a0,$t5,$zero

addi $t2,$t2,1
addi $a1,$a1,4
j while2
while2end:
jr $ra
