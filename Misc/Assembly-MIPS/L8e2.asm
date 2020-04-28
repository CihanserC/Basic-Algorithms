.data
.text
addi $t0,$zero,0 #sum
addi $t1,$zero,0x000A#a
addi $t2,$zero,18#b

add $a0,$zero,$t0
add $a1,$zero,$t1
add $a2,$zero,$t2
jal addfunc

#add $t4,$a0,$zero
addi $v0,$zero,1 #print integer
add $a0,$zero,$v1#print
syscall#print
#add $a0,$t4,$zero
addi $v0,$zero,10#end
syscall


#####
addfunc:

while: 
slt $t3,$a2,$a1 #b>a
bne $t3,$zero,whileend
add $a0,$a0,$a1
addi $a1,$a1,1
j while
whileend:
add $v1,$a0,$zero
jr $ra












