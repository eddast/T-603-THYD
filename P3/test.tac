                     GOTO                                                     main
            main:     VAR                                                        k
                      VAR                                                        i
                       EQ                  0                  0         lab_else_0
                   ASSIGN                  0                                     k
                     GOTO                                             lab_if_end_0
      lab_else_0:  APARAM                                                        k
                     CALL                                                  writeln
                   ASSIGN                  0                                     i
    lab_if_end_0:  RETURN                                                         
