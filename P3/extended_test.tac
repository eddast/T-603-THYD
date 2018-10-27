                     GOTO                                                     main
   calculate_gcd:  FPARAM                                                        a
                   FPARAM                                                        b
                      VAR                                                       t0
                       EQ                  b                  0     lab_rel_true_0
                   ASSIGN                  0                                    t0
                     GOTO                                            lab_rel_end_0
  lab_rel_true_0:  ASSIGN                  1                                    t0
   lab_rel_end_0:      EQ                 t0                  0         lab_else_1
                   ASSIGN                  a                         calculate_gcd
                   RETURN                                                         
                     GOTO                                             lab_if_end_1
      lab_else_1:  APARAM                                                        b
                      VAR                                                       t1
                      MOD                  a                  b                 t1
                   APARAM                                                       t1
                     CALL                                            calculate_gcd
                   ASSIGN      calculate_gcd                         calculate_gcd
                   RETURN                                                         
    lab_if_end_1:    GOTO                                        calculate_sum_of_ten_non_negative
calculate_sum_of_ten_non_negative:  FPARAM                                                        n
                      VAR                                                      sum
                      VAR                                                        i
                   ASSIGN                  0                                   sum
                   ASSIGN                  0                                     i
  lab_for_cond_2:     VAR                                                       t2
                       LT                  i                 10     lab_rel_true_3
                   ASSIGN                  0                                    t2
                     GOTO                                            lab_rel_end_3
  lab_rel_true_3:  ASSIGN                  1                                    t2
   lab_rel_end_3:      EQ                 t2                  1    lab_for_block_2
                     GOTO                                            lab_for_end_2
 lab_for_block_2:     ADD                  n                  1                  n
                      VAR                                                       t3
                       LT                  n                  0     lab_rel_true_4
                   ASSIGN                  0                                    t3
                     GOTO                                            lab_rel_end_4
  lab_rel_true_4:  ASSIGN                  1                                    t3
   lab_rel_end_4:      EQ                 t3                  0       lab_if_end_5
                     GOTO                                          lab_for_in_de_2
    lab_if_end_5:     VAR                                                       t4
                       GT                  n              30000     lab_rel_true_6
                   ASSIGN                  0                                    t4
                     GOTO                                            lab_rel_end_6
  lab_rel_true_6:  ASSIGN                  1                                    t4
   lab_rel_end_6:      EQ                 t4                  0       lab_if_end_7
                     GOTO                                            lab_for_end_2
    lab_if_end_7:     VAR                                                       t5
                      ADD                sum                  n                 t5
                   ASSIGN                 t5                                   sum
                      ADD                  n                  1                  n
 lab_for_in_de_2:     ADD                  i                  1                  i
                     GOTO                                           lab_for_cond_2
   lab_for_end_2:  ASSIGN                sum                     calculate_sum_of_ten_non_negative
                   RETURN                                                         
calculate_factorial:  FPARAM                                                   number
                      VAR                                                factorial
                      VAR                                                        i
                   ASSIGN                  1                             factorial
                   ASSIGN                  1                                     i
  lab_for_cond_8:     VAR                                                       t6
                       LE                  i             number     lab_rel_true_9
                   ASSIGN                  0                                    t6
                     GOTO                                            lab_rel_end_9
  lab_rel_true_9:  ASSIGN                  1                                    t6
   lab_rel_end_9:      EQ                 t6                  1    lab_for_block_8
                     GOTO                                            lab_for_end_8
 lab_for_block_8:     VAR                                                       t7
                     MULT          factorial                  i                 t7
                   ASSIGN                 t7                             factorial
 lab_for_in_de_8:     ADD                  i                  1                  i
                     GOTO                                           lab_for_cond_8
   lab_for_end_8:  ASSIGN          factorial                     calculate_factorial
                   RETURN                                                         
get_largest_of_four_distinct_numbers:  FPARAM                                                        a
                   FPARAM                                                        b
                   FPARAM                                                        c
                   FPARAM                                                        d
                      VAR                                                       t8
                       GE                  a                  b    lab_rel_true_10
                   ASSIGN                  0                                    t8
                     GOTO                                           lab_rel_end_10
 lab_rel_true_10:  ASSIGN                  1                                    t8
  lab_rel_end_10:     VAR                                                       t9
                       LE                  c                  a    lab_rel_true_11
                   ASSIGN                  0                                    t9
                     GOTO                                           lab_rel_end_11
 lab_rel_true_11:  ASSIGN                  1                                    t9
  lab_rel_end_11:     VAR                                                      t10
                       EQ                 t8                  0   lab_and_false_12
                       EQ                 t9                  0   lab_and_false_12
                   ASSIGN                  1                                   t10
                     GOTO                                           lab_and_end_12
lab_and_false_12:  ASSIGN                  0                                   t10
  lab_and_end_12:      EQ                t10                  0      lab_if_end_13
                   ASSIGN                  a                     get_largest_of_four_distinct_numbers
                   RETURN                                                         
   lab_if_end_13:     VAR                                                      t11
                       GE                  b                  a    lab_rel_true_14
                   ASSIGN                  0                                   t11
                     GOTO                                           lab_rel_end_14
 lab_rel_true_14:  ASSIGN                  1                                   t11
  lab_rel_end_14:     VAR                                                      t12
                       LE                  c                  b    lab_rel_true_15
                   ASSIGN                  0                                   t12
                     GOTO                                           lab_rel_end_15
 lab_rel_true_15:  ASSIGN                  1                                   t12
  lab_rel_end_15:     VAR                                                      t13
                       EQ                t11                  0   lab_and_false_16
                       EQ                t12                  0   lab_and_false_16
                   ASSIGN                  1                                   t13
                     GOTO                                           lab_and_end_16
lab_and_false_16:  ASSIGN                  0                                   t13
  lab_and_end_16:      EQ                t13                  0        lab_else_17
                   ASSIGN                  b                     get_largest_of_four_distinct_numbers
                   RETURN                                                         
                     GOTO                                            lab_if_end_17
     lab_else_17:  ASSIGN                  c                     get_largest_of_four_distinct_numbers
                   RETURN                                                         
   lab_if_end_17:  ASSIGN                0.0                     get_largest_of_four_distinct_numbers
                   RETURN                                                         
calculate_mean_of_three:  FPARAM                                                      one
                   FPARAM                                                      two
                   FPARAM                                                    three
                      VAR                                                      sum
                      VAR                                                     mean
                      VAR                                                      t14
                      ADD                one                two                t14
                      VAR                                                      t15
                      ADD                t14              three                t15
                   ASSIGN                t15                                   sum
                      VAR                                                      t16
                   DIVIDE                sum                3.0                t16
                   ASSIGN                t16                                  mean
                      VAR                                                      t17
                   DIVIDE                sum                3.0                t17
                   ASSIGN                t17                     calculate_mean_of_three
                   RETURN                                                         
    is_leap_year:  FPARAM                                                     year
                      VAR                                                 _is_leap
                   ASSIGN                  0                              _is_leap
                      VAR                                                      t18
                      MOD               year                  4                t18
                      VAR                                                      t19
                       NE                t18                  0    lab_rel_true_18
                   ASSIGN                  0                                   t19
                     GOTO                                           lab_rel_end_18
 lab_rel_true_18:  ASSIGN                  1                                   t19
  lab_rel_end_18:      EQ                t19                  0      lab_if_end_19
                   ASSIGN                  0                              _is_leap
   lab_if_end_19:     VAR                                                      t20
                      MOD               year                100                t20
                      VAR                                                      t21
                       EQ                t20                  0    lab_rel_true_20
                   ASSIGN                  0                                   t21
                     GOTO                                           lab_rel_end_20
 lab_rel_true_20:  ASSIGN                  1                                   t21
  lab_rel_end_20:      EQ                t21                  0        lab_else_21
                      VAR                                                      t22
                      MOD               year                400                t22
                      VAR                                                      t23
                       EQ                t22                  0    lab_rel_true_22
                   ASSIGN                  0                                   t23
                     GOTO                                           lab_rel_end_22
 lab_rel_true_22:  ASSIGN                  1                                   t23
  lab_rel_end_22:      EQ                t23                  0        lab_else_23
                   ASSIGN                  1                              _is_leap
                     GOTO                                            lab_if_end_23
     lab_else_23:  ASSIGN                  0                              _is_leap
   lab_if_end_23:    GOTO                                            lab_if_end_21
     lab_else_21:  ASSIGN                  1                              _is_leap
   lab_if_end_21:  ASSIGN           _is_leap                          is_leap_year
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
                      VAR                                                      t24
                      ADD               year                  1                t24
                   APARAM                                                      t24
                     CALL                                             is_leap_year
                   ASSIGN       is_leap_year                          is_leap_next
                      VAR                                                      t25
                      VAR                                                      t26
                       EQ        is_leap_now                  1     lab_or_true_25
                       EQ       is_leap_next                  1     lab_or_true_25
                   ASSIGN                  0                                   t26
                     GOTO                                            lab_or_end_25
  lab_or_true_25:  ASSIGN                  1                                   t26
   lab_or_end_25:      NE                t26                  0    lab_not_true_24
                   ASSIGN                  1                                   t25
                     GOTO                                           lab_not_end_24
 lab_not_true_24:  ASSIGN                  0                                   t25
  lab_not_end_24:      EQ                t25                  0      lab_if_end_26
                      VAR                                                      t27
                      SUB               year                  1                t27
                   APARAM                                                      t27
                     CALL                                             is_leap_year
                   ASSIGN       is_leap_year                      is_leap_previous
   lab_if_end_26:  APARAM                                              is_leap_now
                     CALL                                                  writeln
                   APARAM                                             is_leap_next
                     CALL                                                  writeln
                   APARAM                                         is_leap_previous
                     CALL                                                  writeln
                   RETURN                                                         
