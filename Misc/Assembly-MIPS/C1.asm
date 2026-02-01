
main:

	addi $t0,$zero,0  # SUM VARIABLE	= t0
	addi $t1,$zero,10 # A VARIABLE	= t1
	addi $t2,$zero,18 # B VARIABLE	= t2
	
while:
	
	slt  $t3,$t2,$t1  # if(t2 < t1 ) then set 1 to t3 else set 0 to t3
	bne $t3,$zero,printexit
	
	add $t0,$t0,$t1 #	t0 = t0 + t1
	addi $t1,$t1,1	#	t1 = t1 + 1
	
	j while

printexit:
	
	add $v0,$zero,1	
	add $a0,$zero,$t0 		
	syscall	

	add  $v0,$zero,10 # Program is done
	syscall
