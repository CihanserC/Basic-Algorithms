.data
.text
main:							#i=0 while(i<10) i++;
		addi $t0,$zero,0			#define i
		addi $t1,$zero,10			#define condition
		while:
			slt $t2,$t0,$t1			# pseudo instruction :bgt $t0,10,exit 
			beq $t2,$zero,exit
			addi $t0,$t0,1			#increment
			j while				#loop back
		exit:
		add $v0,$zero,1				#shOw integer i
		add  $a0,$zero,$t0 		
		syscall					

		add  $v0,$zero ,10			#Program is done
		syscall 				
	#--------------------------------------
	#t0 <- 0
	#t1 <- 10
	# while( t0<t1){
	#	t0 = t0 +1
	#	}
	#print t0