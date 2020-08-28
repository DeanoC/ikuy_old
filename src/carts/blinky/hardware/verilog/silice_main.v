`define IKUY 1

M_main __main(
  .clock(clk),
  .reset(clean_reset),
  .out_led(__main_out_led)
);

module M_main(
input clock
);


always @(posedge clock) begin
end




always @* begin
// _always_pre
end
endmodule

