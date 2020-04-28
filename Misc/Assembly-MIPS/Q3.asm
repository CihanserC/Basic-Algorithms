main:
	addi $t0,$zero,0 #	SUM VARÝABLE	
	addi $t1,$zero,10 #	A VARÝABLE	
	addi $t2,$zero,18 #	B VARÝABLE	
	
	while:
		
		slt  $t3,$t2,$t1
		bne $t3,$zero,printexit
	
		add $a0,$zero,$t0 # a0 = sum
		add $a1,$zero,$t1 # a1 = A
	
		jal addfunc
	
		add $t0,$zero,$v0
		add $t1,$zero,$v1
	
		j while 
	
addfunc:

	add $a0,$a0,$a1
	addi $a1,$a1,1
	add $v0,$zero,$a0  #assign Sum to v0
	add $v1,$zero,$a1  # assign A to v1
	jr $ra 		  

printexit:
	add $v0,$zero,1	
	add $a0,$zero,$t0 		
	syscall	
	
	add  $v0,$zero,10 #Program is done
	syscall
