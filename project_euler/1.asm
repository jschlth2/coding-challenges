; note: this doesn't really work because LC-3 is only a 16-bit processor and the result overflows.
;				the logic should be okay though.

	.ORIG x3000

    ; R0 <= total
    ; R1 <= count
    ; R2 <= NUM_1
    ; R3 <= NUM_2
    ; R4 <= MAX

    	  AND R0, R0, #0
        AND R1, R1, #0
        LD R2, NUM_1
        LD R3, NUM_2

	MAIN_LOOP
        ADD R1, R1, #1		; pre-increment the count
        JSR MULT_OF_NUM_1
        BRp PLUS
        JSR MULT_OF_NUM_2
        BRp PLUS
        BRnzp SKIP
	PLUS
    	  ADD R0, R0, R1
  SKIP
    	  ADD R1, R1, #1
        LD R4, MAX_N
        ADD R1, R1, R4
        BRzp TERMINATE
        LD R4, MAX_P
        ADD R1, R1, R4
        BRnzp MAIN_LOOP

	TERMINATE
		    HALT

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

MULT_OF_NUM_1
		    ST R1, ST_R1
        AND R5, R5, #0
	LOOP_1
    	  BRz	TRUE_1
        BRn	FALSE_1
        ADD R1, R1, R2
        BRp LOOP_1
    TRUE_1
    	  ADD R5, R5, #1
    FALSE_1
        LD R1, ST_R1
        AND R5, R5, R5		; setcc
        RET

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

MULT_OF_NUM_2
		    ST R1, ST_R1
        AND R5, R5, #0
	LOOP_2
    	  BRz	TRUE_2
        BRn	FALSE_2
        ADD R1, R1, R3
        BRp LOOP_2
    TRUE_2
    	  ADD R5, R5, #1
    FALSE_2
        LD R1, ST_R1
        AND R5, R5, R5		; setcc
        RET

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

ST_R1	.BLKW #1

NUM_1	.FILL #-3				; store inverse values
NUM_2	.FILL #-5
MAX_P	.FILL #1000			; positive
MAX_N	.FILL #-1000		; negative

    .END
