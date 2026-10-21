module recogev (
    input logic clk,
    input logic reset,
    input logic x,
    output logic y
);
    logic [2:0] state, nextstate;

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            state <= 3'b000;
        end else begin
            state <= nextstate;
        end
    end

    assign nextstate = {state[1:0], x};
    assign y = (^state) | (state == 3'b000);
endmodule
