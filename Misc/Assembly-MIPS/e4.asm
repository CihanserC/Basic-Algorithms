.data
	message:	.asciiz "Hello MIPS"		#asci character with null termination
	number:		.word 0x1000			#define integer  (word = 2xbyte)
	character:	.byte 'C'			#define character
	.text
main:

		add $v0,$zero,4				#Show char command   Pseudo instruction code : li $v0,4
		lui $at,0x1001 	#hex1001 = dec4097 	# load address of message to a0 register
		ori $a0,$at,0x0000			# load address of message to a0 register
		syscall					#send the command
			
		add $v0,$zero,4				#Show char command   Pseudo instruction code : li $v0,4 
		lui $t0,0x1001				#load address of character to a0 la $a0,character
		ori $a0,$t0,0x0010			#load address of character to a0
		syscall                 		#send the command
		
		add $v0,$zero,1				#Show integer command   Pseudo instruction code : li $v0,1 
		lw $a0,number 				#load word from address another method: add  $a0,$zero,$t2 put integer to a0 register
		syscall					#send the command

		#http://courses.missouristate.edu/KenVollmar/MARS/Help/SyscallHelp.html