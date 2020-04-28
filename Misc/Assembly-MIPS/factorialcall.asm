main:

	addi $t0,$zero,1 	# t0 = i = 1 
	addi $t1,$zero,6 	# t1 = B = 6
	addi $t2,$zero,1	# t2 = Result = 1 
	
	add $a1,$zero,$t2	# a0 a bilerek ellemedim çünkü print te kullanılıyor.
	jal print
	add $t2,$zero,$a1
	
	add $a1,$zero,$t2 # a1 = result
	add $a2,$zero,$t0 # a2 = i	
	add $a3,$zero,$t1 # a3 = B  
	jal factorial
	
	add  $v0,$zero,10 	# Exit
	syscall
	
print:
	
	add $v0,$zero,1		# Print Result
	add $a0,$zero,$a1 		
	syscall	
	
	jr $ra
	
factorial:
	
	
	slt $t3,$a3,$a2 
	bne $t3,$zero,exit
	
	addi $a2,$a2,1
	
	j factorial
	add $v0,$zero,$a0  # assign i to v0
	add $v1,$zero,$a1  # assign A to v1
	jr $ra


exit: 

