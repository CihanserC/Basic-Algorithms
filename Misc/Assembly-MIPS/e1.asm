.data 
.text
	addi $t1,$zero,0x2001
	addi $t2,$zero,0x2000
	add $t3,$t1,$t2
	sub $t4,$t1,$t2
	#mult $t1,$t2
	div $t1,$t2
	mflo $t5
	mfhi $t6
	
	add $v0,$zero,1		   #set v0 1
	add $a0,$zero,$t3	  #set value to a0 register	
	syscall		   	  #system call(interrupt)
	
	add $v0,$zero,1		   #set v0 1
	add $a0,$zero,$t4	  #set value to a0 register	
	syscall		   	  #system call(interrupt)
	add $v0,$zero,1		   #set v0 1
	add $a0,$zero,$t5	  #set value to a0 register	
	syscall		   	  #system call(interrupt)
	add $v0,$zero,1		   #set v0 1
	add $a0,$zero,$t6	  #set value to a0 register	
	syscall		   	  #system call(interrupt)
	li   $v0, 1    # service 1 is print integer
	move $a0, $t0  # move register to be printed into argument register $a0
	syscall
	add $v0,$zero,1		   #set v0 1
	syscall	
	
	
	add  $v0,$zero ,10	#Program is done
	syscall 
