main:

	addi $t0,$zero,1 #	i	
	addi $t1,$zero,6 #	B 
	addi $t2,$zero,1 #	Result 
	
	
	add $a3,$zero,$t0
	jal printfact 
	add $a2,$zero,$t1
	add $a3,$zero,$t2 
	jal factorial
	
	add $v0,$zero,10
	syscall
	
printfact:

	add $v0,$zero,1	#print 
	add $a0,$zero,$a3		
	syscall	
	
	jr $ra
	
factorial:
	
	add $s0,$zero,$ra
	while:
	slt $t3,$a1,$a2 #while i<b
	beq $t3,$zero,exit
	
	addi $a1,$a1,1
	 
	mult $a1,$a3
	
	mflo $a3 
	
	jal printfact
	j while
	

exit: 

	jr $s0
