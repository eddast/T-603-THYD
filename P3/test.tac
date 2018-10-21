                     GOTO                                                     main
            main:     VAR                                                        i
                   ASSIGN                  1                                     i
  lab_for_cond_0:     VAR                                                       t0
                       LE                  i                 10     lab_rel_true_1
                   ASSIGN                  0                                    t0
                     GOTO                                            lab_rel_end_1
  lab_rel_true_1:  ASSIGN                  1                                    t0
   lab_rel_end_1:      EQ                 t0                  1    lab_for_block_0
                     GOTO                                            lab_for_end_0
 lab_for_block_0:  APARAM                                                        i
                     CALL                                                  writeln
 lab_for_in_de_0:     ADD                  i                  1                  i
                     GOTO                                           lab_for_cond_0
   lab_for_end_0:  RETURN                                                         
