                     GOTO                                                     main
             fib:  FPARAM                                                        n
                      VAR                                                       t0
                       EQ                  n                  1     lab_rel_true_0
                   ASSIGN                  0                                    t0
                     GOTO                                            lab_rel_end_0
  lab_rel_true_0:  ASSIGN                  1                                    t0
   lab_rel_end_0:     VAR                                                       t1
                       EQ                  n                  0     lab_rel_true_1
                   ASSIGN                  0                                    t1
                     GOTO                                            lab_rel_end_1
  lab_rel_true_1:  ASSIGN                  1                                    t1
   lab_rel_end_1:     VAR                                                       t2
                       EQ                 t0                  1      lab_or_true_2
                       EQ                 t1                  1      lab_or_true_2
                   ASSIGN                  0                                    t2
                     GOTO                                             lab_or_end_2
   lab_or_true_2:  ASSIGN                  1                                    t2
    lab_or_end_2:      EQ                 t2                  0       lab_if_end_3
                   ASSIGN                  1                                   fib
                   RETURN                                                         
    lab_if_end_3:     VAR                                                       t3
                      SUB                  n                  1                 t3
                   APARAM                                                       t3
                     CALL                                                      fib
                      VAR                                                       t4
                      SUB                  n                  2                 t4
                   APARAM                                                       t4
                     CALL                                                      fib
                      VAR                                                       t5
                      ADD                fib                fib                 t5
                   ASSIGN                 t5                                   fib
                   RETURN                                                         
   calculate_gcd:  FPARAM                                                        a
                   FPARAM                                                        b
                      VAR                                                       t6
                       EQ                  b                  0     lab_rel_true_4
                   ASSIGN                  0                                    t6
                     GOTO                                            lab_rel_end_4
  lab_rel_true_4:  ASSIGN                  1                                    t6
   lab_rel_end_4:      EQ                 t6                  0         lab_else_5
                   ASSIGN                  a                         calculate_gcd
                   RETURN                                                         
                     GOTO                                             lab_if_end_5
      lab_else_5:     VAR                                                       t7
                      MOD                  a                  b                 t7
                   APARAM                                                        b
                   APARAM                                                       t7
                     CALL                                            calculate_gcd
                   ASSIGN      calculate_gcd                         calculate_gcd
                   RETURN                                                         
    lab_if_end_5:    GOTO                                        calculate_sum_of_ten_non_negative
calculate_sum_of_ten_non_negative:  FPARAM                                                        n
                      VAR                                                      sum
                      VAR                                                        i
                   ASSIGN                  0                                   sum
                   ASSIGN                  0                                     i
  lab_for_cond_6:     VAR                                                       t8
                       LT                  i                 10     lab_rel_true_7
                   ASSIGN                  0                                    t8
                     GOTO                                            lab_rel_end_7
  lab_rel_true_7:  ASSIGN                  1                                    t8
   lab_rel_end_7:      EQ                 t8                  1    lab_for_block_6
                     GOTO                                            lab_for_end_6
 lab_for_block_6:     ADD                  n                  1                  n
                      VAR                                                       t9
                       LT                  n                  0     lab_rel_true_8
                   ASSIGN                  0                                    t9
                     GOTO                                            lab_rel_end_8
  lab_rel_true_8:  ASSIGN                  1                                    t9
   lab_rel_end_8:      EQ                 t9                  0       lab_if_end_9
                     GOTO                                          lab_for_in_de_6
    lab_if_end_9:     VAR                                                      t10
                       GT                  n              30000    lab_rel_true_10
                   ASSIGN                  0                                   t10
                     GOTO                                           lab_rel_end_10
 lab_rel_true_10:  ASSIGN                  1                                   t10
  lab_rel_end_10:      EQ                t10                  0      lab_if_end_11
                     GOTO                                            lab_for_end_6
   lab_if_end_11:     VAR                                                      t11
                      ADD                sum                  n                t11
                   ASSIGN                t11                                   sum
                      ADD                  n                  1                  n
 lab_for_in_de_6:     ADD                  i                  1                  i
                     GOTO                                           lab_for_cond_6
   lab_for_end_6:  ASSIGN                sum                     calculate_sum_of_ten_non_negative
                   RETURN                                                         
calculate_factorial:  FPARAM                                                   number
                      VAR                                                factorial
                      VAR                                                        i
                   ASSIGN                  1                             factorial
                   ASSIGN                  1                                     i
 lab_for_cond_12:     VAR                                                      t12
                       LE                  i             number    lab_rel_true_13
                   ASSIGN                  0                                   t12
                     GOTO                                           lab_rel_end_13
 lab_rel_true_13:  ASSIGN                  1                                   t12
  lab_rel_end_13:      EQ                t12                  1   lab_for_block_12
                     GOTO                                           lab_for_end_12
lab_for_block_12:     VAR                                                      t13
                     MULT          factorial                  i                t13
                   ASSIGN                t13                             factorial
lab_for_in_de_12:     ADD                  i                  1                  i
                     GOTO                                          lab_for_cond_12
  lab_for_end_12:  ASSIGN          factorial                     calculate_factorial
                   RETURN                                                         
get_largest_of_four_distinct_numbers:  FPARAM                                                        a
                   FPARAM                                                        b
                   FPARAM                                                        c
                   FPARAM                                                        d
                      VAR                                                      t14
                       GE                  a                  b    lab_rel_true_14
                   ASSIGN                  0                                   t14
                     GOTO                                           lab_rel_end_14
 lab_rel_true_14:  ASSIGN                  1                                   t14
  lab_rel_end_14:     VAR                                                      t15
                       LE                  c                  a    lab_rel_true_15
                   ASSIGN                  0                                   t15
                     GOTO                                           lab_rel_end_15
 lab_rel_true_15:  ASSIGN                  1                                   t15
  lab_rel_end_15:     VAR                                                      t16
                       EQ                t14                  0   lab_and_false_16
                       EQ                t15                  0   lab_and_false_16
                   ASSIGN                  1                                   t16
                     GOTO                                           lab_and_end_16
lab_and_false_16:  ASSIGN                  0                                   t16
  lab_and_end_16:      EQ                t16                  0      lab_if_end_17
                   ASSIGN                  a                     get_largest_of_four_distinct_numbers
                   RETURN                                                         
   lab_if_end_17:     VAR                                                      t17
                       GE                  b                  a    lab_rel_true_18
                   ASSIGN                  0                                   t17
                     GOTO                                           lab_rel_end_18
 lab_rel_true_18:  ASSIGN                  1                                   t17
  lab_rel_end_18:     VAR                                                      t18
                       LE                  c                  b    lab_rel_true_19
                   ASSIGN                  0                                   t18
                     GOTO                                           lab_rel_end_19
 lab_rel_true_19:  ASSIGN                  1                                   t18
  lab_rel_end_19:     VAR                                                      t19
                       EQ                t17                  0   lab_and_false_20
                       EQ                t18                  0   lab_and_false_20
                   ASSIGN                  1                                   t19
                     GOTO                                           lab_and_end_20
lab_and_false_20:  ASSIGN                  0                                   t19
  lab_and_end_20:      EQ                t19                  0        lab_else_21
                   ASSIGN                  b                     get_largest_of_four_distinct_numbers
                   RETURN                                                         
                     GOTO                                            lab_if_end_21
     lab_else_21:  ASSIGN                  c                     get_largest_of_four_distinct_numbers
                   RETURN                                                         
   lab_if_end_21:  ASSIGN                0.0                     get_largest_of_four_distinct_numbers
                   RETURN                                                         
calculate_mean_of_three:  FPARAM                                                      one
                   FPARAM                                                      two
                   FPARAM                                                    three
                      VAR                                                      sum
                      VAR                                                     mean
                      VAR                                                      t20
                      ADD                one                two                t20
                      VAR                                                      t21
                      ADD                t20              three                t21
                   ASSIGN                t21                                   sum
                      VAR                                                      t22
                   DIVIDE                sum                3.0                t22
                   ASSIGN                t22                                  mean
                      VAR                                                      t23
                   DIVIDE                sum                3.0                t23
                   ASSIGN                t23                     calculate_mean_of_three
                   RETURN                                                         
    is_leap_year:  FPARAM                                                     year
                      VAR                                                 _is_leap
                   ASSIGN                  0                              _is_leap
                      VAR                                                      t24
                      MOD               year                  4                t24
                      VAR                                                      t25
                       NE                t24                  0    lab_rel_true_22
                   ASSIGN                  0                                   t25
                     GOTO                                           lab_rel_end_22
 lab_rel_true_22:  ASSIGN                  1                                   t25
  lab_rel_end_22:      EQ                t25                  0      lab_if_end_23
                   ASSIGN                  0                              _is_leap
   lab_if_end_23:     VAR                                                      t26
                      MOD               year                100                t26
                      VAR                                                      t27
                       EQ                t26                  0    lab_rel_true_24
                   ASSIGN                  0                                   t27
                     GOTO                                           lab_rel_end_24
 lab_rel_true_24:  ASSIGN                  1                                   t27
  lab_rel_end_24:      EQ                t27                  0        lab_else_25
                      VAR                                                      t28
                      MOD               year                400                t28
                      VAR                                                      t29
                       EQ                t28                  0    lab_rel_true_26
                   ASSIGN                  0                                   t29
                     GOTO                                           lab_rel_end_26
 lab_rel_true_26:  ASSIGN                  1                                   t29
  lab_rel_end_26:      EQ                t29                  0        lab_else_27
                   ASSIGN                  1                              _is_leap
                     GOTO                                            lab_if_end_27
     lab_else_27:  ASSIGN                  0                              _is_leap
   lab_if_end_27:    GOTO                                            lab_if_end_25
     lab_else_25:  ASSIGN                  1                              _is_leap
   lab_if_end_25:  ASSIGN           _is_leap                          is_leap_year
                   RETURN                                                         
            main:     VAR                                                     mean
                      VAR                                                    _val1
                      VAR                                                    _val2
                      VAR                                                    _val3
                      VAR                                                    _val4
                      VAR                                                  largest
                      VAR                                              is_leap_now
                      VAR                                             is_leap_next
                      VAR                                         is_leap_previous
                      VAR                                                 intfirst
                      VAR                                                intsecond
                      VAR                                                      gcd
                      VAR                                        sum_of_ten_subsequents
                      VAR                                                factorial
                      VAR                                              sum_1_to_10
                      VAR                                                     year
                   APARAM                                                       10
                     CALL                                                      fib
                   APARAM                                                      fib
                     CALL                                                  writeln
                   ASSIGN                400                              intfirst
                   ASSIGN                  4                             intsecond
                   APARAM                                                 intfirst
                   APARAM                                                intsecond
                     CALL                                            calculate_gcd
                   ASSIGN      calculate_gcd                                   gcd
                   APARAM                                                      gcd
                     CALL                                                  writeln
                   APARAM                                                intsecond
                     CALL                                        calculate_sum_of_ten_non_negative
                   ASSIGN  calculate_sum_of_ten_non_negative                     sum_of_ten_subsequents
                   APARAM                                        sum_of_ten_subsequents
                     CALL                                                  writeln
                   APARAM                                                intsecond
                     CALL                                        calculate_factorial
                   ASSIGN  calculate_factorial                             factorial
                   APARAM                                                factorial
                     CALL                                                  writeln
                   ASSIGN               13.1                                 _val1
                   ASSIGN              13.20                                 _val2
                   ASSIGN              13.57                                 _val3
                   ASSIGN              13.37                                 _val4
                   APARAM                                                    _val1
                   APARAM                                                    _val2
                   APARAM                                                    _val3
                     CALL                                        calculate_mean_of_three
                   ASSIGN  calculate_mean_of_three                                  mean
                   APARAM                                                     mean
                     CALL                                                  writeln
                   APARAM                                                    _val1
                   APARAM                                                    _val2
                   APARAM                                                    _val3
                   APARAM                                                    _val4
                     CALL                                        get_largest_of_four_distinct_numbers
                   ASSIGN  get_largest_of_four_distinct_numbers                               largest
                   APARAM                                                  largest
                     CALL                                                  writeln
                   ASSIGN               2018                                  year
                   APARAM                                                     year
                     CALL                                             is_leap_year
                   ASSIGN       is_leap_year                           is_leap_now
                      VAR                                                      t30
                      ADD               year                  1                t30
                   APARAM                                                      t30
                     CALL                                             is_leap_year
                   ASSIGN       is_leap_year                          is_leap_next
                      VAR                                                      t31
                      VAR                                                      t32
                       EQ        is_leap_now                  1     lab_or_true_29
                       EQ       is_leap_next                  1     lab_or_true_29
                   ASSIGN                  0                                   t32
                     GOTO                                            lab_or_end_29
  lab_or_true_29:  ASSIGN                  1                                   t32
   lab_or_end_29:      NE                t32                  0    lab_not_true_28
                   ASSIGN                  1                                   t31
                     GOTO                                           lab_not_end_28
 lab_not_true_28:  ASSIGN                  0                                   t31
  lab_not_end_28:      EQ                t31                  0      lab_if_end_30
                      VAR                                                      t33
                      SUB               year                  1                t33
                   APARAM                                                      t33
                     CALL                                             is_leap_year
                   ASSIGN       is_leap_year                      is_leap_previous
   lab_if_end_30:  APARAM                                              is_leap_now
                     CALL                                                  writeln
                   APARAM                                             is_leap_next
                     CALL                                                  writeln
                   APARAM                                         is_leap_previous
                     CALL                                                  writeln
                   RETURN                                                         
