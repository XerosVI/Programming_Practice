`timescale 1ns/1ns

module recogev_tb ();
    logic clk, reset, x, y;

    recogev dut(clk, reset, x, y);

    always begin
        clk = 0; #10; clk = 1; #10;
    end

    initial begin
        $dumpfile("recogev_tb.vcd");
        $dumpvars(0, recogev_tb);

        x = 1;
        reset = 1; #2;
        reset = 0; #13;

        x = 0; #10;
        x = 1; #20;
        x = 0; #20;
        x = 1; #20;
        x = 0; #20;
        x = 1; #20;
        x = 1; #40;

        $finish;
    end
endmodule
