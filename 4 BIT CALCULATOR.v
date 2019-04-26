module CALCI(
           input [3:0] A,B,                   // 4 BIT INPUT 
           input [1:0] D,                     // OPERATION (ADDITION,SUB,MUL,DIVISION)
           output [3:0] C,                    // 4 BIT OUTPUT
           output E 
    );
    reg [3:0] CALCI_Result;
    wire [4:0] tmp;
    assign C = CALCI_Result; 
    assign tmp = {1'b0,A} + {1'b0,B};         // CARRY
    assign E = tmp[4]; 
    always @(*)
    begin
        case(D)
        2'b00: 
           CALCI_Result = A + B ;             // ADDITION
        2'b01: 
           CALCI_Result = A - B ;             // SUBRACTION
        2'b10: 
           CALCI_Result = A * B;              // MUL
        2'b11: 
           CALCI_Result = A/B;                // DIVISION
        
          default: CALCI_Result = A + B ; 
        endcase
    end

endmodule
