.data
.text
main:
	addi $t0,$zero,0	#sum=0
	addi $t1,$zero,10	#a=10
	addi $t2,$zero,18	#b=18
	
	while: 	slt $t3,$t2,$t1 #a<=b
		bne $t3,$zero,print
		add $t0,$t0,$t1
		addi $t1,$t1,1
		j while
	
	print:
	addi $v0,$zero,1	#print sum
	add $a0,$zero,$t0	
	syscall
	
	addi $v0,$zero,10	#end the program
	syscall			#end the program
	