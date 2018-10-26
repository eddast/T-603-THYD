                     GOTO                                                     main
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
                   ASSIGN                400                              intfirst
                   ASSIGN                  4                             intsecond
                   APARAM                                                 intfirst
                   APARAM                                                intsecond
                     CALL                                            calculate_gcd
                   ASSIGN          intsecond                                   gcd
                   APARAM                                                      gcd
                     CALL                                                  writeln
                   APARAM                                                intsecond
                     CALL                                        calculate_sum_of_ten_non_negative
                   ASSIGN          intsecond                     sum_of_ten_subsequents
                   APARAM                                        sum_of_ten_subsequents
                     CALL                                                  writeln
                   APARAM                                                intsecond
                     CALL                                        calculate_factorial
                   ASSIGN          intsecond                             factorial
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
                   ASSIGN              _val3                                  mean
                   APARAM                                                     mean
                     CALL                                                  writeln
                   APARAM                                                    _val1
                   APARAM                                                    _val2
                   APARAM                                                    _val3
                   APARAM                                                    _val4
                     CALL                                        get_largest_of_four_distinct_numbers
                   ASSIGN              _val4                               largest
                   APARAM                                                  largest
                     CALL                                                  writeln
                   ASSIGN               2018                                  year
                   APARAM                                                     year
                     CALL                                             is_leap_year
                   ASSIGN               year                           is_leap_now
                      VAR                                                       t0
                      ADD               year                  1                 t0
                   APARAM                                                       t0
                     CALL                                             is_leap_year
                   ASSIGN                 t0                          is_leap_next
                      VAR                                                       t1
                      VAR                                                       t2
                       EQ        is_leap_now                  1      lab_or_true_1
                       EQ       is_leap_next                  1      lab_or_true_1
                   ASSIGN                  0                                    t2
                     GOTO                                             lab_or_end_1
   lab_or_true_1:  ASSIGN                  1                                    t2
    lab_or_end_1:      NE                 t2                  0     lab_not_true_0
                   ASSIGN                  1                                    t1
                     GOTO                                            lab_not_end_0
  lab_not_true_0:  ASSIGN                  0                                    t1
   lab_not_end_0:      EQ                 t1                  0       lab_if_end_2
                      VAR                                                       t3
                      SUB               year                  1                 t3
                   APARAM                                                       t3
                     CALL                                             is_leap_year
                   ASSIGN                 t3                      is_leap_previous
    lab_if_end_2:  APARAM                                              is_leap_now
                     CALL                                                  writeln
                   APARAM                                             is_leap_next
                     CALL                                                  writeln
                   APARAM                                         is_leap_previous
                     CALL                                                  writeln
                   RETURN                                                         
   calculate_gcd:  FPARAM                                                        a
                   FPARAM                                                        b
                      VAR                                                       t4
                       EQ                  b                  0     lab_rel_true_3
                   ASSIGN                  0                                    t4
                     GOTO                                            lab_rel_end_3
  lab_rel_true_3:  ASSIGN                  1                                    t4
   lab_rel_end_3:      EQ                 t4                  0         lab_else_4
                   ASSIGN                  a                         calculate_gcd
                   RETURN                                                         
                     GOTO                                             lab_if_end_4
      lab_else_4:  APARAM                                                        b
                      VAR                                                       t5
                      MOD                  a                  b                 t5
                   APARAM                                                       t5
                     CALL                                            calculate_gcd
                   ASSIGN                 t5                         calculate_gcd
                   RETURN                                                         
    lab_if_end_4:    GOTO                                        calculate_sum_of_ten_non_negative
calculate_sum_of_ten_non_negative:  FPARAM                                                        n
                      VAR                                                      sum
                      VAR                                                        i
                   ASSIGN                  0                                   sum
                   ASSIGN                  0                                     i
  lab_for_cond_5:     VAR                                                       t6
                       LT                  i                 10     lab_rel_true_6
                   ASSIGN                  0                                    t6
                     GOTO                                            lab_rel_end_6
  lab_rel_true_6:  ASSIGN                  1                                    t6
   lab_rel_end_6:      EQ                 t6                  1    lab_for_block_5
                     GOTO                                            lab_for_end_5
 lab_for_block_5:     ADD                  n                  1                  n
                      VAR                                                       t7
                       LT                  n                  0     lab_rel_true_7
                   ASSIGN                  0                                    t7
                     GOTO                                            lab_rel_end_7
  lab_rel_true_7:  ASSIGN                  1                                    t7
   lab_rel_end_7:      EQ                 t7                  0       lab_if_end_8
    lab_if_end_8:     VAR                                                       t8
                       GT                  n              30000     lab_rel_true_9
                   ASSIGN                  0                                    t8
                     GOTO                                            lab_rel_end_9
  lab_rel_true_9:  ASSIGN                  1                                    t8
   lab_rel_end_9:      EQ                 t8                  0      lab_if_end_10
   lab_if_end_10:     VAR                                                       t9
                      ADD                sum                  n                 t9
                   ASSIGN                 t9                                   sum
                      ADD                  n                  1                  n
 lab_for_in_de_5:     ADD                  i                  1                  i
                     GOTO                                           lab_for_cond_5
   lab_for_end_5:  ASSIGN                sum                     calculate_sum_of_ten_non_negative
                   RETURN                                                         
calculate_factorial:  FPARAM                                                   number
                      VAR                                                factorial
                      VAR                                                        i
                   ASSIGN                  1                             factorial
                   ASSIGN                  1                                     i
 lab_for_cond_11:     VAR                                                      t10
                       LE                  i             number    lab_rel_true_12
                   ASSIGN                  0                                   t10
                     GOTO                                           lab_rel_end_12
 lab_rel_true_12:  ASSIGN                  1                                   t10
  lab_rel_end_12:      EQ                t10                  1   lab_for_block_11
                     GOTO                                           lab_for_end_11
lab_for_block_11:     VAR                                                      t11
                     MULT          factorial                  i                t11
                   ASSIGN                t11                             factorial
lab_for_in_de_11:     ADD                  i                  1                  i
                     GOTO                                          lab_for_cond_11
  lab_for_end_11:  ASSIGN          factorial                     calculate_factorial
                   RETURN                                                         
get_largest_of_four_distinct_numbers:  FPARAM                                                        a
                   FPARAM                                                        b
                   FPARAM                                                        c
                   FPARAM                                                        d
                      VAR                                                      t12
                       GE                  a                  b    lab_rel_true_13
                   ASSIGN                  0                                   t12
                     GOTO                                           lab_rel_end_13
 lab_rel_true_13:  ASSIGN                  1                                   t12
  lab_rel_end_13:     VAR                                                      t13
                       LE                  c                  a    lab_rel_true_14
                   ASSIGN                  0                                   t13
                     GOTO                                           lab_rel_end_14
 lab_rel_true_14:  ASSIGN                  1                                   t13
  lab_rel_end_14:     VAR                                                      t14
                       EQ                t12                  0   lab_and_false_15
                       EQ                t13                  0   lab_and_false_15
                   ASSIGN                  1                                   t14
                     GOTO                                           lab_and_end_15
lab_and_false_15:  ASSIGN                  0                                   t14
  lab_and_end_15:      EQ                t14                  0      lab_if_end_16
                   ASSIGN                  a                     get_largest_of_four_distinct_numbers
                   RETURN                                                         
   lab_if_end_16:     VAR                                                      t15
                       GE                  b                  a    lab_rel_true_17
                   ASSIGN                  0                                   t15
                     GOTO                                           lab_rel_end_17
 lab_rel_true_17:  ASSIGN                  1                                   t15
  lab_rel_end_17:     VAR                                                      t16
                       LE                  c                  b    lab_rel_true_18
                   ASSIGN                  0                                   t16
                     GOTO                                           lab_rel_end_18
 lab_rel_true_18:  ASSIGN                  1                                   t16
  lab_rel_end_18:     VAR                                                      t17
                       EQ                t15                  0   lab_and_false_19
                       EQ                t16                  0   lab_and_false_19
                   ASSIGN                  1                                   t17
                     GOTO                                           lab_and_end_19
lab_and_false_19:  ASSIGN                  0                                   t17
  lab_and_end_19:      EQ                t17                  0        lab_else_20
                   ASSIGN                  b                     get_largest_of_four_distinct_numbers
                   RETURN                                                         
                     GOTO                                            lab_if_end_20
     lab_else_20:  ASSIGN                  c                     get_largest_of_four_distinct_numbers
                   RETURN                                                         
   lab_if_end_20:  ASSIGN                0.0                     get_largest_of_four_distinct_numbers
                   RETURN                                                         
calculate_mean_of_three:  FPARAM                                                      one
                   FPARAM                                                      two
                   FPARAM                                                    three
                      VAR                                                      sum
                      VAR                                                     mean
                      VAR                                                      t18
                      ADD                one                two                t18
                      VAR                                                      t19
                      ADD                t18              three                t19
                   ASSIGN                t19                                   sum
                      VAR                                                      t20
                   DIVIDE                sum                3.0                t20
                   ASSIGN                t20                                  mean
                      VAR                                                      t21
                   DIVIDE                sum                3.0                t21
                   ASSIGN                t21                     calculate_mean_of_three
                   RETURN                                                         
    is_leap_year:  FPARAM                                                     year
                      VAR                                                 _is_leap
                   ASSIGN                  0                              _is_leap
                      VAR                                                      t22
                      MOD               year                  4                t22
                      VAR                                                      t23
                       NE                t22                  0    lab_rel_true_21
                   ASSIGN                  0                                   t23
                     GOTO                                           lab_rel_end_21
 lab_rel_true_21:  ASSIGN                  1                                   t23
  lab_rel_end_21:      EQ                t23                  0      lab_if_end_22
                   ASSIGN                  0                              _is_leap
   lab_if_end_22:     VAR                                                      t24
                      MOD               year                100                t24
                      VAR                                                      t25
                       EQ                t24                  0    lab_rel_true_23
                   ASSIGN                  0                                   t25
                     GOTO                                           lab_rel_end_23
 lab_rel_true_23:  ASSIGN                  1                                   t25
  lab_rel_end_23:      EQ                t25                  0        lab_else_24
                      VAR                                                      t26
                      MOD               year                400                t26
                      VAR                                                      t27
                       EQ                t26                  0    lab_rel_true_25
                   ASSIGN                  0                                   t27
                     GOTO                                           lab_rel_end_25
 lab_rel_true_25:  ASSIGN                  1                                   t27
  lab_rel_end_25:      EQ                t27                  0        lab_else_26
                   ASSIGN                  1                              _is_leap
                     GOTO                                            lab_if_end_26
     lab_else_26:  ASSIGN                  0                              _is_leap
   lab_if_end_26:    GOTO                                            lab_if_end_24
     lab_else_24:  ASSIGN                  1                              _is_leap
   lab_if_end_24:  ASSIGN           _is_leap                          is_leap_year
                   RETURN                                                         
