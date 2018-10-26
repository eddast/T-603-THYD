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
 lab_for_block_0:     VAR                                                       t1
                       EQ                  i                  7     lab_rel_true_2
                   ASSIGN                  0                                    t1
                     GOTO                                            lab_rel_end_2
  lab_rel_true_2:  ASSIGN                  1                                    t1
   lab_rel_end_2:     VAR                                                       t2
                       EQ                  i                  3     lab_rel_true_3
                   ASSIGN                  0                                    t2
                     GOTO                                            lab_rel_end_3
  lab_rel_true_3:  ASSIGN                  1                                    t2
   lab_rel_end_3:     VAR                                                       t3
                       EQ                 t1                  1      lab_or_true_4
                       EQ                 t2                  1      lab_or_true_4
                   ASSIGN                  0                                    t3
                     GOTO                                             lab_or_end_4
   lab_or_true_4:  ASSIGN                  1                                    t3
    lab_or_end_4:      EQ                 t3                  0       lab_if_end_5
                     GOTO                                          lab_for_in_de_0
    lab_if_end_5:  APARAM                                                        i
                     CALL                                                  writeln
                   APARAM                                                        i
                     CALL                                                  writeln
                   ASSIGN                 10                                     j
  lab_for_cond_6:     VAR                                                       t4
                       LT                  j                 15     lab_rel_true_7
                   ASSIGN                  0                                    t4
                     GOTO                                            lab_rel_end_7
  lab_rel_true_7:  ASSIGN                  1                                    t4
   lab_rel_end_7:      EQ                 t4                  1    lab_for_block_6
                     GOTO                                            lab_for_end_6
 lab_for_block_6:     VAR                                                       t5
                       EQ                  j                 12     lab_rel_true_8
                   ASSIGN                  0                                    t5
                     GOTO                                            lab_rel_end_8
  lab_rel_true_8:  ASSIGN                  1                                    t5
   lab_rel_end_8:     VAR                                                       t6
                       EQ                  j                 13     lab_rel_true_9
                   ASSIGN                  0                                    t6
                     GOTO                                            lab_rel_end_9
  lab_rel_true_9:  ASSIGN                  1                                    t6
   lab_rel_end_9:     VAR                                                       t7
                       EQ                 t5                  1     lab_or_true_10
                       EQ                 t6                  1     lab_or_true_10
                   ASSIGN                  0                                    t7
                     GOTO                                            lab_or_end_10
  lab_or_true_10:  ASSIGN                  1                                    t7
   lab_or_end_10:      EQ                 t7                  0      lab_if_end_11
                     GOTO                                          lab_for_in_de_6
   lab_if_end_11:  APARAM                                                        j
                     CALL                                                  writeln
                   APARAM                                                        j
                     CALL                                                  writeln
 lab_for_in_de_6:     ADD                  j                  1                  j
                     GOTO                                           lab_for_cond_6
   lab_for_end_6:    GOTO                                          lab_for_in_de_0
 lab_for_in_de_0:     ADD                  i                  1                  i
                     GOTO                                           lab_for_cond_0
   lab_for_end_0:  RETURN                                                         
