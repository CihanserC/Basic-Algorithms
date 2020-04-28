.data
.text
addi $t0,$zero,0 #sum
addi $t1,$zero,0x000A#a
addi $t2,$zero,18#a

add $a0,$t0,$zero  #ssum
add $a1,$t1,$zero	#a
add $a2,$t2,$zero	#b

jal addfunc

add $t3 ,$v0,$zero

addi $v0,$zero,1	#print
add $a0,$zero,$t3	#print
syscall			#print

addi $v0,$zero,10	#end
syscall			#end




addfunc:
bne $a1,$a2,else
add $v0,$zero,$a1
jr $ra
else:
addi $sp,$sp,-4
sw $ra,0($sp)
addi $sp,$sp,-4
sw $a1,0($sp)

addi $a1,$a1,1
jal addfunc

lw $a1,0($sp)
sw $zero,0($sp)
addi $sp,$sp,4
lw $ra,0($sp)
sw $zero,0($sp)
addi $sp,$sp,4

add $v0,$v0,$a1
jr $ra








