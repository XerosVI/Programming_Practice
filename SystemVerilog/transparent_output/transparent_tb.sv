`timescale 1ns/1ns

module transparent_tb ();
    logic clk, reset, p, y;

    transparent dut(clk, reset, p, y);

    always begin
        clk = 0; #10; clk = 1; #10;
    end

    initial begin
        $dumpfile("transparent_tb.vcd");
        $dumpvars(0, transparent_tb);
        reset = 1; #2;
        reset = 0;
    end

    initial begin
        p = 1; #3;
        p = 0; #4;
        p = 1; #8;
        p = 0; #10;
        p = 1; #20;
        p = 0; #20;
        p = 1; #20;
        p = 0; #20;
        p = 1; #20;
        p = 1; #25;
        $finish;
    end
endmodulew
