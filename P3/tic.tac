					GOTO		main
factorial:				FPARAM		n
					LE		n		1			if_inside
					GOTO		if_end
if_inside:				ASSIGN		1		factorial
					RETURN
if_end:					VAR		t1
					SUB		n		1			t1
					APARAM		t1
					CALL		factorial
					VAR		t2
					MULT		n		factorial		factorial
					RETURN
main:					VAR		num
					APARAM		3
					CALL		factorial
					ASSIGN		factorial	num
					APARAM		num
					CALL		writeln
					RETURN
