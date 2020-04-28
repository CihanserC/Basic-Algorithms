.data
.text
main:
	addi $t0,$zero,30
	addi $t1,$zero,20
	#if t0 < t1 add else subtract
	slt $t2,$t0,$t1
	beq $t2,$zero,addition #branch not equal
	sub $t4,$t0,$t1
	j print
addition:	
	add $t4,$t0,$t1
print:
	add $v0,$zero,1	   #set v0 1			#Sho
	add $a0,$zero,$t4  #set value to a0
	syscall		   #system call(interrupt)
	

#	t0 <- 30
#	t1 <- 20
#	if t0 < t1
#	    t4 <- t0+t1
#	else
#	    t4 <- t0-t1
#	print t4