                     GOTO                                                     main
            main:     VAR                                                        i
                      VAR                                                        j
                   ASSIGN                  0                                     i
  lab_for_cond_0:     VAR                                                       t0
                       LT                  i                 10     lab_rel_true_1
                   ASSIGN                  0                                    t0
                     GOTO                                            lab_rel_end_1
  lab_rel_true_1:  ASSIGN                  1                                    t0
   lab_rel_end_1:      EQ                 t0                  1    lab_for_block_0
                     GOTO                                            lab_for_end_0
 lab_for_block_0:  APARAM                                                        i
                     CALL                                                  writeln
                   ASSIGN                 10                                     j
  lab_for_cond_2:     VAR                                                       t1
                       LT                  j                 20     lab_rel_true_3
                   ASSIGN                  0                                    t1
                     GOTO                                            lab_rel_end_3
  lab_rel_true_3:  ASSIGN                  1                                    t1
   lab_rel_end_3:      EQ                 t1                  1    lab_for_block_2
                     GOTO                                            lab_for_end_2
 lab_for_block_2:     VAR                                                       t2
                       EQ                  j                 12     lab_rel_true_4
                   ASSIGN                  0                                    t2
                     GOTO                                            lab_rel_end_4
  lab_rel_true_4:  ASSIGN                  1                                    t2
   lab_rel_end_4:      EQ                 t2                  0       lab_if_end_5
                     GOTO                                            lab_for_end_2
    lab_if_end_5:  APARAM                                                        j
                     CALL                                                  writeln
 lab_for_in_de_2:     ADD                  j                  1                  j
                     GOTO                                           lab_for_cond_2
   lab_for_end_2:     VAR                                                       t3
                       EQ                  i                  7     lab_rel_true_6
                   ASSIGN                  0                                    t3
                     GOTO                                            lab_rel_end_6
  lab_rel_true_6:  ASSIGN                  1                                    t3
   lab_rel_end_6:      EQ                 t3                  0       lab_if_end_7
                     GOTO                                            lab_for_end_0
    lab_if_end_7:    GOTO                                          lab_for_in_de_0
 lab_for_in_de_0:     ADD                  i                  1                  i
                     GOTO                                           lab_for_cond_0
   lab_for_end_0:  RETURN                                                         
