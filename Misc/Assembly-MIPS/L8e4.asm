.data
list: .space 100

.text
addi $t0,$zero,25
lui $t1,0x1001

add $a0,$t0,$zero
add $a1,$t1,$zero
jal fillArray

addi $v0,$zero,10 #end
syscall

fillArray:
addi $t2,$zero,0
while: 
slt $t3,$t2,$a0
beq $t3,$zero,endwhile
sw $t2,($a1)
addi $t2,$t2,1
addi $a1,$a1,4
j while
endwhile:
jr $ra