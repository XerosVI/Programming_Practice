module recog011 (
    input  logic clk,
    input  logic reset,
    input  logic x,
    output logic y
);
    typedef enum logic [1:0] {S0, S1, S2, S3} state_t;
    state_t state, nextstate;

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            state <= S0;
        end else begin
            state <= nextstate;
        end
    end

    always_comb begin
        case (state)
            S0: nextstate = x ? S0 : S1;
            S1: nextstate = x ? S2 : S1;
            S2: nextstate = x ? S3 : S1;
            S3: nextstate = x ? S0 : S1;
            default: nextstate = S0;
        endcase
    end

    assign y = ~(state == S3);
endmodule
