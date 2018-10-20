                     GOTO                                                     main
            hehe:  FPARAM                                                        y
                   FPARAM                                                        x
                   FPARAM                                                        z
                   ASSIGN                  1                                  hehe
                   RETURN                                                         
            main:     VAR                                                        k
                      VAR                                                        t
                      VAR                                                        a
                   APARAM                                                        k
                   APARAM                                                        t
                   APARAM                                                        a
                     CALL                                                     hehe
                   RETURN                                                         
