`include "alu_defines.vh"
`include "mips32_opcodes.vh" 

module ControlUnit(
    input [5:0] opc, //! Opcode
    input [5:0] func, //! Function
    output isJmp, //! Jump signal
    output isBeq, //! BEQ signal
    output isBne, //! BNE signal
    output [1:0] rfWriteDataSel, //! Register File Write Data Select
    output rfWriteAddrSel, //! Register File Write Address Select
    output rfWriteEnable, //! Register Write Enable
    output memWrite, //! Memory Write
    output memRead, //! Memory Read
    output aluSrc, //! ALU source
    output [2:0] aluFunc, //! ALU operation
    output bitXtend, //! Bit extension, 0 = sign extend, 1 = zero extend
    output invOpcode //! Invalid opcode or function
);

always @(*) begin
    isJmp = 1'd0;
    isBeq = 1'd0;
    isBne = 1'd0;
    rfWriteDataSel = 2'd0;
    rfWriteAddrSel = 1'd1;
    rfWriteEnable = 1'd0;
    memWrite = 1'd0;
    memRead = 1'd0;
    aluSrc = 1'd0;
    aluFunc = `ALU_UNDEF;
    bitXtend = 1'dz;
    invOpcode = 1'd0;

    case (opc)
        6'h00: begin
            rfWriteEnable = 1'd1;
            case (func)
                `MIPS_ADD: begin
                    aluFunc = `ALU_ADD;
                end
                `MIPS_SUB:begin
                    aluFunc = `ALU_SUB;
                end
                `MIPS_AND:begin
                    aluFunc = `ALU_AND;
                end
                `MIPS_OR:begin
                    aluFunc = `ALU_OR;
                end
                `MIPS_SLT:begin
                    aluFunc = `ALU_SLT;
                end
                default: begin
                end 
            endcase
        end 
        `MIPS_JUMP: begin
            isJmp = 1'd1;
        end
        `MIPS_BEQ: begin
            isBeq = 1'd1;
            aluFunc = `ALU_SUB;
        end
        `MIPS_BNE:begin
            isBne = 1'd1;
            aluFunc = `ALU_SUB;
        end
        `MIPS_LW: begin
            memRead =1'd1;
            rfWriteDataSel = 2'd1;
            rfWriteEnable = 1'd1;
            rfWriteAddrSel = 1'd0;
            aluSrc = 1'd1;
            bitXtend = 1'd1;
            aluFunc = `ALU_ADD;
        end
        `MIPS_SW: begin
            memWrite = 1'd1;
            aluSrc = 1'd1;
            bitXtend = 1'd1;
            aluFunc = `ALU_ADD;
        end
        default: begin
            
        end
    endcase
end
endmodule

