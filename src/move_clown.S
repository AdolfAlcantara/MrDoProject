.globl move_clown
.type integrate, @function
.extern player

.text

move_clown:
    move $t0, $a0
    la $s0, player

switch:
    ori $t9, $zero, 1
    beq $t0, $t9, move_left
    ori $t9, $zero, 2
    beq $t0, $t9, move_right
    ori $t9, $zero, 4
    beq $t0, $t9, move_down
    ori $t9, $zero, 8
    beq $t0, $t9, move_up
    j default

move_left:

    ori $t1, $zero, 4
    lw $t2, 4($s0)
    beq $t2, $t1, mli
    slt $t9, $t1, $t2
    bne $t9, $zero, mli
    j end_mli

mli:
    addi $t2,$t2, -4
    sw $t2,4($s0)

end_mli:
    j end_switch

move_right:

    ori $t1, $zero, 40
    lw $t2, 4($s0)
    beq $t2, $t1, mri
    slt $t9, $t2, $t1
    bne $t9, $zero, mri
    j end_mri

mri:
    addi $t2, $t2, 4
    sw $t2, 4($s0)

end_mri:
    j end_switch

move_down:

    ori $t1, $zero, 26
    lw $t2, 8($s0)
    beq $t2, $t1, mdi
    slt $t9, $t2, $t1
    bne $t9, $zero, mdi
    j end_mdi

mdi:
    addi $t2,$t2,2
    sw $t2, 8($s0)

end_mdi:
    j end_switch

move_up:

    ori $t1, $zero, 6
    lw $t2, 8($s0)
    beq $t1, $t2, mui
    slt $t9, $t1, $t2 
    bne $t9, $zero, mui
    j end_mui

mui:
    addi $t2,$t2, -2
    sw $t2, 8($s0)

end_mui:
    j end_switch

default:
    j end_switch

end_switch:
    jr $ra

