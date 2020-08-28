`define IKUY 1
$$HARDWARE=1

M_main __main(
  .clock(clk),
  .reset(clean_reset),
  .out_led(__main_out_led)
);