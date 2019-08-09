.globl initLevel

.extern walls

.text

initLevel:
    la $s0, walls
    ori $s1, $zero, 13

main_for:
    move $s3, $zero                 #;y=0  

main_for_if:
    slt $t9, $s3, $s1               #;y<13
    beq $t9, $zero, end_main_for

switch:
    beq $s3, $zero, for_zero
    ori $t1, $zero, 1
    beq $s3, $t1, for_one
    ori $t1, $zero, 2
    beq $s3, $t1, for_two
    ori $t1, $zero, 3
    beq $s3, $t1, for_tffssen
    ori $t1, $zero, 4
    beq $s3, $t1, for_tffssen
    ori $t1, $zero, 5
    beq $s3, $t1, for_tffssen
    ori $t1, $zero, 6
    beq $s3, $t1, for_tffssen
    ori $t1, $zero, 7
    beq $s3, $t1, for_tffssen
    ori $t1, $zero, 8
    beq $s3, $t1, for_tffssen
    ori $t1, $zero, 9
    beq $s3, $t1, for_tffssen
    ori $t1, $zero, 10
    beq $s3, $t1, for_ten
    ori $t1, $zero, 11
    beq $s3, $t1, for_eleven
    ori $t1, $zero, 12
    beq $s3, $t1, for_twelve
    j end_switch

for_zero:
    ori $s4, $zero, 0

for_zero_if:
    ori $t1, $zero, 3
    slt $t9, $s4, $t1
    bne $t9, $zero, fzi_true
    beq $s4, $t1, fzi_true
    j fzi_false

fzi_true:
    addi $sp, $sp, -4
    sw $ra, 0($sp)
    jal multiply
    lw $ra, 0($sp)
    addi $sp, $sp, 4
    addi $s4, $s4, 1
    j for_zero_if

fzi_false:
    ori $s4, $zero, 10
    addi $sp, $sp, -4
    sw $ra, 0($sp)
    jal multiply
    lw $ra, 0($sp)
    addi $sp, $sp, 4
    ori $s4, $zero, 11
    addi $sp, $sp, -4
    sw $ra, 0($sp)
    jal multiply
    lw $ra, 0($sp)
    addi $sp, $sp, 4
    j end_switch

for_one:
    ori $s4, $zero, 0

for_one_if:
    ori $t1, $zero, 8
    slt $t9, $s4, $t1
    bne $t9, $zero, foi_true
    beq $s4, $t1, foi_true
    j foi_false

foi_true:
    ori $t1, $zero, 5
    beq $t1, $s4, skip_five_one
    addi $sp, $sp, -4
    sw $ra, 0($sp)
    jal multiply
    lw $ra, 0($sp)
    addi $sp, $sp, 4
    addi $s4, $s4, 1
    j for_one_if

skip_five_one:
    addi $s4, $s4, 1
    j for_one_if

foi_false:
    ori $s4, $zero, 11
    addi $sp, $sp, -4
    sw $ra, 0($sp)
    jal multiply
    lw $ra, 0($sp)
    addi $sp, $sp, 4
    j end_switch

for_two:
    ori $s4, $zero, 0

for_two_if:
    ori $t1, $zero, 9
    slt $t9, $s4, $t1
    bne $t9, $zero, fti_true
    beq $s4, $t1, fti_true
    j fti_false

fti_true:
    ori $t1, $zero, 5
    beq $t1, $s4, skip_five_two
    addi $sp, $sp, -4
    sw $ra, 0($sp)
    jal multiply
    lw $ra, 0($sp)
    addi $sp, $sp, 4
    addi $s4, $s4, 1
    j for_two_if

skip_five_two:
    addi $s4, $s4, 1
    j for_two_if

fti_false:
    j end_switch

for_tffssen:
     ori $s4, $zero, 0

for_tffssen_if:
    ori $t1, $zero, 9
    slt $t9, $s4, $t1
    bne $t9, $zero, ftffsseni_true
    beq $s4, $t1, ftffsseni_true
    j ftffsseni_false

ftffsseni_true:
    ori $t1, $zero, 5
    beq $t1, $s4, skip_five_tffssen
    addi $sp, $sp, -4
    sw $ra, 0($sp)
    jal multiply
    lw $ra, 0($sp)
    addi $sp, $sp, 4
    addi $s4, $s4, 1
    j for_tffssen_if

skip_five_tffssen:
    addi $s4, $s4, 1
    j for_tffssen_if

ftffsseni_false:
    j end_switch

for_ten:
    ori $s4, $zero, 0

for_ten_if:
    ori $t1, $zero, 9
    slt $t9, $s4, $t1
    bne $t9, $zero, ftei_true
    beq $s4, $t1, ftei_true
    j ftei_false

ftei_true:
    ori $t1, $zero, 5
    beq $t1, $s4, skip_five_ten
    addi $sp, $sp, -4
    sw $ra, 0($sp)
    jal multiply
    lw $ra, 0($sp)
    addi $sp, $sp, 4
    addi $s4, $s4, 1
    j for_ten_if

skip_five_ten:
    addi $s4, $s4, 1
    j for_ten_if

ftei_false:
    j end_switch

for_eleven:
    ori $s4, $zero, 0

for_eleven_if:
    ori $t1, $zero, 8
    slt $t9, $s4, $t1
    bne $t9, $zero, fei_true
    beq $s4, $t1, fei_true
    j fei_false

fei_true:
    ori $t1, $zero, 5
    beq $t1, $s4, skip_five_eleven
    addi $sp, $sp, -4
    sw $ra, 0($sp)
    jal multiply
    lw $ra, 0($sp)
    addi $sp, $sp, 4
    addi $s4, $s4, 1
    j for_eleven_if

skip_five_eleven:
    addi $s4, $s4, 1
    j for_eleven_if

fei_false:
    ori $s4, $zero, 11
    addi $sp, $sp, -4
    sw $ra, 0($sp)
    jal multiply
    lw $ra, 0($sp)
    addi $sp, $sp, 4
    j end_switch

for_twelve:
    ori $s4, $zero, 10
    addi $sp, $sp, -4
    sw $ra, 0($sp)
    jal multiply
    lw $ra, 0($sp)
    addi $sp, $sp, 4
    ori $s4, $zero, 11
    addi $sp, $sp, -4
    sw $ra, 0($sp)
    jal multiply
    lw $ra, 0($sp)
    addi $sp, $sp, 4
    j end_switch

end_switch:
    addi $s3, $s3, 1
    j main_for_if

end_main_for:
    jr $ra
#;--------------------------------------------------
multiply:
        move $t0, $s3
        move $t1, $s4
        move $t2, $zero
while:
    slt $t9, $zero, $t0
    bne $t9, $zero, addition

endwhile:
    add $t2, $t2, $t1
    #show $t2
    sll $t2,$t2,1
    add $t2, $t2, $s0
    ori $t3,$zero, 1
    sb $t3, 1($t2)
    jr $ra

addition:
    addi $t2, $t2, 12
    addi $t0, $t0, -1
    #show $t2
    j while

#;-----------------------------------

    
    




    