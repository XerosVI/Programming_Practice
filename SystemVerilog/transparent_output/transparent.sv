module transparent (
    input logic clk,
    input logic reset,
    input logic p,
    output logic y
);
    typedef enum logic [1:0] {S0, S1, S2, S3} state_t;
    state_t state, nextstate;

  always_ff @(posedge clk, posedge reset) begin
        if (reset) begin
            state <= S0;
        end else begin
            state <= nextstate;
        end
    end

    always_comb begin
        case (state)
            S0: nextstate = p ? S1 : S0;
            S1: nextstate = p ? S3 : S2;
            S2: nextstate = p ? S1 : S0;
            S3: nextstate = p ? S3 : S2;
            default: nextstate = S0;
        endcase
    end

    assign y = state[1] & p;
endmodule
