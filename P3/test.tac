                     GOTO                                                     main
            haha:  FPARAM                                                        a
                   FPARAM                                                        b
                   ASSIGN                  1                                  haha
                   RETURN                                                         
            main:     VAR                                                        i
                   APARAM                                                        1
                   APARAM                                                      4.0
                     CALL                                                     haha
                   ASSIGN               haha                                     i
                   APARAM                                                        i
                     CALL                                                  writeln
                   RETURN                                                         
