.data
list: .space 100


.text

addi $t0,$zero,25
lui $t1,0x1001
addi $t2,$zero,0 #counter 


while:
slt $t3,$t2,$t0
beq $t3,$zero,whileend
sw $t2,($t1)
addi $t2,$t2,1
addi $t1,$t1,4
j while
whileend:
addi $v0,$zero,10
syscall