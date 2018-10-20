                     GOTO                                                     main
            main:     VAR                                                        k
                      VAR                                                        e
                      VAR                                                        a
                      VAR                                                        b
                      VAR                                                       t0
                       EQ                  a                  0    lab_and_false_0
                       EQ                  b                  0    lab_and_false_0
                   ASSIGN                  1                                    t0
                     GOTO                                            lab_and_end_0
 lab_and_false_0:  ASSIGN                  0                                    t0
   lab_and_end_0:  ASSIGN                 t0                                     k
                      VAR                                                       t1
                       EQ                  a                  1      lab_or_true_1
                       EQ                  b                  1      lab_or_true_1
                   ASSIGN                  0                                    t1
                     GOTO                                             lab_or_end_1
   lab_or_true_1:  ASSIGN                  1                                    t1
    lab_or_end_1:  ASSIGN                 t1                                     e
                   RETURN                                                         
