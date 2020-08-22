`timescale 1ns / 1ps

module main(
	input wire sysclk,
	output wire [3:0] led
);
    reg	[25:0]	counter;
    always @(posedge sysclk)
    counter <= counter + 1'b1;
    assign led[0] = counter[25];

endmodule
