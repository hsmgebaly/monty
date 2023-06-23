# BrainF*ck Two-number multiplication formula
# The result must be a single digit number less than 10
# the following example 42: 4 will be in block #1, and 2 will be in block #2.
# The outcome will be kept in block 0.
# Block 1 will contain the multiplicand value.
# Block 2 will contain the multiplicands to be used.
# 42 will produce the output of 4*2 as the outcome.
# block 1 and block 2 read-in
# Each should have 48 subtracted, leaving a '0'.
# adding the value of block 1 to block 0 each time in a loop while block 2!= 0
# BLOCK 0	BLOCK 1		BLOCK 2		BLOCK 3 	BLOCK4
#    0		   4		   1		   0 		
>,------------------------------------------------ # read into #1
>,------------------------------------------------ # read into #2
[<[>>+<<<+>-]>>[<<+>>-] COPY BLOCK 1 INTO BLOCK 3 AND 0 THEN COPY BLOCK 3 BACK TO BLOCK 1
<-] MOVE BLOCK TO BLOCK 2 AND DECREASE (DONE WITH ONE ITERATION)
# MOVE TO BLOCK 0 AND INCREASE BY ASCII '0' (DEC 48)
<<++++++++++++++++++++++++++++++++++++++++++++++++.
