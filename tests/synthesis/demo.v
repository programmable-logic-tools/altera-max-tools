
module test(
	input clock,
	input[3:0] a,
	output reg c
	);

always @(posedge clock)
begin
/*
	if (a)
		c <= b;
	else
		c <= 0;
*/
	c <= (a == 4'b1100) || (a == 4'b0011);
end

//assign c = a + b;

endmodule

