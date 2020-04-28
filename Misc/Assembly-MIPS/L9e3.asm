.data
.text
main:
	addi $a0,$a0,10
	jal fibo
	
	add $t2,$v0,$zero
	addi $v0,$zero 1	#print sum
 	add $a0,$zero,$t2	#print sum
 	syscall			#print sum
 		
 	addi $v0,$zero 10	#end program
 	syscall			#end program


 	fibo:
 		addi $t5,$zero,1
 		slt $t0,$t5,$a0
 		bne $t0,$zero,fiborec
 		add $v0,$a0,$zero
 		jr $ra
 		
 	fiborec:	
 		addi $sp,$sp,-12
 		sw $ra,0($sp)		#save address
 		
 		sw $a0,4($sp)		#save n
 		addi $a0,$a0,-1		#n-1
 		
 		jal fibo
 		
 		lw $a0,4($sp)		#restore n
 		sw $v0,8($sp)		#save return value fib(n-1)
 		
 		addi $a0,$a0,-2		#n-2
 		jal fibo
 		
 		lw $t1,8($sp)		#restore return value
 		add $v0,$v0,$t1		
 		
 		lw $ra,0($sp)		#restore address
 		addi $sp,$sp,12
 		
 		jr $ra
 		
 # int fibo( int n):
 #	if(n<=1):
 #		return n
 #	else
 #		return fibo(n-1) + fibo(n-2)	