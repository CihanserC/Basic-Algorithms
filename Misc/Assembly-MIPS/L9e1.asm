.data
.text
addi $t0,$zero,0 #sum
addi $t1,$zero,0x000A#a
addi $t2,$zero,18#a

addi $sp,$sp,-4	#stack push
sw $t0,0($sp)#stack push
addi $sp,$sp,-4#stack push
sw $t1,0($sp)#stack push
addi $sp,$sp,-4#stack push
sw $t2,0($sp)#stack push

jal addfunc

lw $a0,0($sp)#stack pop
addi $sp,$sp,4#stack pop

#add $t4,$a0,$zero
addi $v0,$zero,1 #print integer
syscall#print
#add $a0,$t4,$zero
addi $v0,$zero,10#end
syscall


#####
addfunc:

lw $a2, 0($sp)#stack pop
addi $sp,$sp,4#stack pop
lw $a1, 0($sp)#stack pop
addi $sp,$sp,4#stack pop
lw $a0 0($sp)#stack pop
addi $sp,$sp,4#stack pop


while: 
slt $t3,$a2,$a1 #b>a
bne $t3,$zero,whileend
add $a0,$a0,$a1
addi $a1,$a1,1
j while
whileend:
addi $sp,$sp,-4#stack push
sw $a0,0($sp)#stack push
jr $ra











