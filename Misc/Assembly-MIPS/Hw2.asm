# Cihanser Çalışkan - 16070001020 #
.data
list : .space 40 

character : .byte ' '
msg1 : .asciiz "f_iter : "
msg2 : .asciiz " f_rec : "
msg3 : .asciiz "\n"

array :  .word 95, 86, 79, 63, 52, 41, 34, 28, 17, 6 
.text

main : 

addi $t0,$zero,0	# S = 0
addi $t1,$zero,10	# N = 10
addi $t2,$t1,-1		# f = N-1
la $t3,array

add $a0,$zero,$t0	# passing S value
add $a1,$zero,$t2	# passing F value
add $a2,$zero,$t3	# passing array[0]
jal f_iter

### Print Message 1 ###	"f_iter : "
addi $v0,$zero,4
la $a0,msg1
syscall
####

addi $t5,$zero,0	# i=0
while1 : 		# Print Array
slt $t4,$t5,$t1
beq $t4,$zero,whileend1
### Print String ###
addi $v0,$zero,1
lw $a0,($t3)
syscall
####
addi $t3,$t3,4		# change pointer index
addi $t5,$t5,1 		# increment i
j while1
whileend1 : 
### Print Message 3 ###	"\n"
addi $v0,$zero,4
la $a0,msg3
syscall
####

addi $t0,$zero,0	# S = 0
addi $t1,$zero,10	# N = 10
addi $t2,$t1,-1		# f = N-1

add $a0,$zero,$t0	# passing S value
add $a1,$zero,$t2	# passing F value
add $a2,$zero,$t3	# passing array[0]
jal f_rec

### Print Message 2 ###	"f_rec : "
addi $v0,$zero,4
la $a0,msg2
syscall
####

addi $t5,$zero,0	# i=0
la $t3,array		# set address to initial 
while2 : 		# Print Array
slt $t4,$t5,$t1
beq $t4,$zero,whileend2
### Print String ###
addi $v0,$zero,1
lw $a0,($t3)
syscall
####
addi $t3,$t3,4		# change pointer index
addi $t5,$t5,1 		# increment i
j while2
whileend2 : 
### Print Message 3 ###	"\n"
addi $v0,$zero,4
la $a0,msg3
syscall
####

### END ###
addi $v0,$zero,10
syscall 
####

### FUNCTİONS ###

f_iter : 

addi $t5,$zero,0	# t=0

slt $t7,$a0,$a1
beq $t7,$zero,iter_end

add $t5,$a0,$a0 	# S  = S x 2
add $t5,$t5,$t5		# S  = S x 2
add $t5,$t5,$a2

add $t6,$a1,$a1
add $t6,$t6,$t6
add $t6,$t6,$a2

lw $t8,0($t5)
lw $t9,0($t6) 
sw $t8,0($t5) 
sw $t9,0($t6)

addi $a0,$a0,1	
addi $a1,$a1,-1

j f_iter
iter_end :
jr $ra 

f_rec : 

addi $t5,$zero,0	# t = 0 ;
slt $t7,$a0,$a1
beq $t7,$zero,rec_end

add $t5,$a0,$a0 	# S  = S x 2
add $t5,$t5,$t5		# S  = S x 2
add $t5,$t5,$a2

add $t6,$a1,$a1
add $t6,$t6,$t6
add $t6,$t6,$a2

lw $t8,0($t5)
lw $t9,0($t6) 
sw $t8,0($t5) 
sw $t9,0($t6)

addi $a0,$a0,1	
addi $a1,$a1,-1

jal f_rec
rec_end : 
jr $ra