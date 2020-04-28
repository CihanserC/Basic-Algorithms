main:
	addi $t0,$zero,0 	#	SUM VARİABLE	= t0
	addi $t1,$zero,10	#	A   VARİABLE	= t1
	addi $t2,$zero,18	#	B   VARİABLE	= t2
	
	while:
		
		slt  $t3,$t2,$t1
		bne $t3,$zero,printexit
	
		add $a0,$zero,$t0	# a0 = sum
		add $a1,$zero,$t1	# a1 = A
	
		jal addfunc		# jump and link
	
		add $t0,$zero,$v0 	# t0 = v0
		add $t1,$zero,$v1	# t1 = v1
	
		j while 
	
addfunc:

	add $a0,$a0,$a1		# a0 = a0 + a1 -> sum = sum + A 
	addi $a1,$a1,1		# a1 = a1 + 1
	add $v0,$zero,$a0 	# assign Sum to v0
	add $v1,$zero,$a1 	# assign A to v1
	jr $ra 		  

printexit:
	add $v0,$zero,1		# print 
	add $a0,$zero,$t0 		
	syscall	
	
	add  $v0,$zero,10 	# Program is done
	syscall
