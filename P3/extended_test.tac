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
                      VAR                                                       t4
                   APARAM                                                       t3
                     CALL                                                      fib
                   ASSIGN                fib                                    t4
                      VAR                                                       t5
                      SUB                  n                  2                 t5
                      VAR                                                       t6
                   APARAM                                                       t5
                     CALL                                                      fib
                   ASSIGN                fib                                    t6
                      VAR                                                       t7
                      ADD                 t4                 t6                 t7
                   ASSIGN                 t7                                   fib
                   RETURN                                                         
   calculate_gcd:  FPARAM                                                        a
                   FPARAM                                                        b
                      VAR                                                       t8
                       EQ                  b                  0     lab_rel_true_4
                   ASSIGN                  0                                    t8
                     GOTO                                            lab_rel_end_4
  lab_rel_true_4:  ASSIGN                  1                                    t8
   lab_rel_end_4:      EQ                 t8                  0         lab_else_5
                   ASSIGN                  a                         calculate_gcd
                   RETURN                                                         
                     GOTO                                             lab_if_end_5
      lab_else_5:     VAR                                                       t9
                      MOD                  a                  b                 t9
                      VAR                                                      t10
                   APARAM                                                        b
                   APARAM                                                       t9
                     CALL                                            calculate_gcd
                   ASSIGN      calculate_gcd                                   t10
                   ASSIGN                t10                         calculate_gcd
                   RETURN                                                         
    lab_if_end_5:    GOTO                                        calculate_sum_of_ten_non_negative
calculate_sum_of_ten_non_negative:  FPARAM                                                        n
                      VAR                                                      sum
                      VAR                                                        i
                   ASSIGN                  0                                   sum
                   ASSIGN                  0                                     i
  lab_for_cond_6:     VAR                                                      t11
                       LT                  i                 10     lab_rel_true_7
                   ASSIGN                  0                                   t11
                     GOTO                                            lab_rel_end_7
  lab_rel_true_7:  ASSIGN                  1                                   t11
   lab_rel_end_7:      EQ                t11                  1    lab_for_block_6
                     GOTO                                            lab_for_end_6
 lab_for_block_6:     ADD                  n                  1                  n
                      VAR                                                      t12
                       LT                  n                  0     lab_rel_true_8
                   ASSIGN                  0                                   t12
                     GOTO                                            lab_rel_end_8
  lab_rel_true_8:  ASSIGN                  1                                   t12
   lab_rel_end_8:      EQ                t12                  0       lab_if_end_9
                     GOTO                                          lab_for_in_de_6
    lab_if_end_9:     VAR                                                      t13
                       GT                  n              30000    lab_rel_true_10
                   ASSIGN                  0                                   t13
                     GOTO                                           lab_rel_end_10
 lab_rel_true_10:  ASSIGN                  1                                   t13
  lab_rel_end_10:      EQ                t13                  0      lab_if_end_11
                     GOTO                                            lab_for_end_6
   lab_if_end_11:     VAR                                                      t14
                      ADD                sum                  n                t14
                   ASSIGN                t14                                   sum
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
 lab_for_cond_12:     VAR                                                      t15
                       LE                  i             number    lab_rel_true_13
                   ASSIGN                  0                                   t15
                     GOTO                                           lab_rel_end_13
 lab_rel_true_13:  ASSIGN                  1                                   t15
  lab_rel_end_13:      EQ                t15                  1   lab_for_block_12
                     GOTO                                           lab_for_end_12
lab_for_block_12:     VAR                                                      t16
                     MULT          factorial                  i                t16
                   ASSIGN                t16                             factorial
lab_for_in_de_12:     ADD                  i                  1                  i
                     GOTO                                          lab_for_cond_12
  lab_for_end_12:  ASSIGN          factorial                     calculate_factorial
                   RETURN                                                         
get_largest_of_four_distinct_numbers:  FPARAM                                                        a
                   FPARAM                                                        b
                   FPARAM                                                        c
                   FPARAM                                                        d
                      VAR                                                      t17
                       GE                  a                  b    lab_rel_true_14
                   ASSIGN                  0                                   t17
                     GOTO                                           lab_rel_end_14
 lab_rel_true_14:  ASSIGN                  1                                   t17
  lab_rel_end_14:     VAR                                                      t18
                       LE                  c                  a    lab_rel_true_15
                   ASSIGN                  0                                   t18
                     GOTO                                           lab_rel_end_15
 lab_rel_true_15:  ASSIGN                  1                                   t18
  lab_rel_end_15:     VAR                                                      t19
                       EQ                t17                  0   lab_and_false_16
                       EQ                t18                  0   lab_and_false_16
                   ASSIGN                  1                                   t19
                     GOTO                                           lab_and_end_16
lab_and_false_16:  ASSIGN                  0                                   t19
  lab_and_end_16:      EQ                t19                  0      lab_if_end_17
                   ASSIGN                  a                     get_largest_of_four_distinct_numbers
                   RETURN                                                         
   lab_if_end_17:     VAR                                                      t20
                       GE                  b                  a    lab_rel_true_18
                   ASSIGN                  0                                   t20
                     GOTO                                           lab_rel_end_18
 lab_rel_true_18:  ASSIGN                  1                                   t20
  lab_rel_end_18:     VAR                                                      t21
                       LE                  c                  b    lab_rel_true_19
                   ASSIGN                  0                                   t21
                     GOTO                                           lab_rel_end_19
 lab_rel_true_19:  ASSIGN                  1                                   t21
  lab_rel_end_19:     VAR                                                      t22
                       EQ                t20                  0   lab_and_false_20
                       EQ                t21                  0   lab_and_false_20
                   ASSIGN                  1                                   t22
                     GOTO                                           lab_and_end_20
lab_and_false_20:  ASSIGN                  0                                   t22
  lab_and_end_20:      EQ                t22                  0        lab_else_21
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
                      VAR                                                      t23
                      ADD                one                two                t23
                      VAR                                                      t24
                      ADD                t23              three                t24
                   ASSIGN                t24                                   sum
                      VAR                                                      t25
                   DIVIDE                sum                3.0                t25
                   ASSIGN                t25                                  mean
                      VAR                                                      t26
                   DIVIDE                sum                3.0                t26
                   ASSIGN                t26                     calculate_mean_of_three
                   RETURN                                                         
    is_leap_year:  FPARAM                                                     year
                      VAR                                                 _is_leap
                   ASSIGN                  0                              _is_leap
                      VAR                                                      t27
                      MOD               year                  4                t27
                      VAR                                                      t28
                       NE                t27                  0    lab_rel_true_22
                   ASSIGN                  0                                   t28
                     GOTO                                           lab_rel_end_22
 lab_rel_true_22:  ASSIGN                  1                                   t28
  lab_rel_end_22:      EQ                t28                  0      lab_if_end_23
                   ASSIGN                  0                              _is_leap
   lab_if_end_23:     VAR                                                      t29
                      MOD               year                100                t29
                      VAR                                                      t30
                       EQ                t29                  0    lab_rel_true_24
                   ASSIGN                  0                                   t30
                     GOTO                                           lab_rel_end_24
 lab_rel_true_24:  ASSIGN                  1                                   t30
  lab_rel_end_24:      EQ                t30                  0        lab_else_25
                      VAR                                                      t31
                      MOD               year                400                t31
                      VAR                                                      t32
                       EQ                t31                  0    lab_rel_true_26
                   ASSIGN                  0                                   t32
                     GOTO                                           lab_rel_end_26
 lab_rel_true_26:  ASSIGN                  1                                   t32
  lab_rel_end_26:      EQ                t32                  0        lab_else_27
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
                      VAR                                                     fibi
                      VAR                                                      t33
                   APARAM                                                       10
                     CALL                                                      fib
                   ASSIGN                fib                                   t33
                   ASSIGN                t33                                  fibi
                   APARAM                                                     fibi
                     CALL                                                  writeln
                   ASSIGN                400                              intfirst
                   ASSIGN                  4                             intsecond
                      VAR                                                      t34
                   APARAM                                                 intfirst
                   APARAM                                                intsecond
                     CALL                                            calculate_gcd
                   ASSIGN      calculate_gcd                                   t34
                   ASSIGN                t34                                   gcd
                   APARAM                                                      gcd
                     CALL                                                  writeln
                      VAR                                                      t35
                   APARAM                                                intsecond
                     CALL                                        calculate_sum_of_ten_non_negative
                   ASSIGN  calculate_sum_of_ten_non_negative                                   t35
                   ASSIGN                t35                     sum_of_ten_subsequents
                   APARAM                                        sum_of_ten_subsequents
                     CALL                                                  writeln
                      VAR                                                      t36
                   APARAM                                                intsecond
                     CALL                                        calculate_factorial
                   ASSIGN  calculate_factorial                                   t36
                   ASSIGN                t36                             factorial
                   APARAM                                                factorial
                     CALL                                                  writeln
                   ASSIGN               13.1                                 _val1
                   ASSIGN              13.20                                 _val2
                   ASSIGN              13.57                                 _val3
                   ASSIGN              13.37                                 _val4
                      VAR                                                      t37
                   APARAM                                                    _val1
                   APARAM                                                    _val2
                   APARAM                                                    _val3
                     CALL                                        calculate_mean_of_three
                   ASSIGN  calculate_mean_of_three                                   t37
                   ASSIGN                t37                                  mean
                   APARAM                                                     mean
                     CALL                                                  writeln
                      VAR                                                      t38
                   APARAM                                                    _val1
                   APARAM                                                    _val2
                   APARAM                                                    _val3
                   APARAM                                                    _val4
                     CALL                                        get_largest_of_four_distinct_numbers
                   ASSIGN  get_largest_of_four_distinct_numbers                                   t38
                   ASSIGN                t38                               largest
                   APARAM                                                  largest
                     CALL                                                  writeln
                   ASSIGN               2018                                  year
                      VAR                                                      t39
                   APARAM                                                     year
                     CALL                                             is_leap_year
                   ASSIGN       is_leap_year                                   t39
                   ASSIGN                t39                           is_leap_now
                      VAR                                                      t40
                      ADD               year                  1                t40
                      VAR                                                      t41
                   APARAM                                                      t40
                     CALL                                             is_leap_year
                   ASSIGN       is_leap_year                                   t41
                   ASSIGN                t41                          is_leap_next
                      VAR                                                      t42
                      VAR                                                      t43
                       EQ        is_leap_now                  1     lab_or_true_29
                       EQ       is_leap_next                  1     lab_or_true_29
                   ASSIGN                  0                                   t43
                     GOTO                                            lab_or_end_29
  lab_or_true_29:  ASSIGN                  1                                   t43
   lab_or_end_29:      NE                t43                  0    lab_not_true_28
                   ASSIGN                  1                                   t42
                     GOTO                                           lab_not_end_28
 lab_not_true_28:  ASSIGN                  0                                   t42
  lab_not_end_28:      EQ                t42                  0      lab_if_end_30
                      VAR                                                      t44
                      SUB               year                  1                t44
                      VAR                                                      t45
                   APARAM                                                      t44
                     CALL                                             is_leap_year
                   ASSIGN       is_leap_year                                   t45
                   ASSIGN                t45                      is_leap_previous
   lab_if_end_30:  APARAM                                              is_leap_now
                     CALL                                                  writeln
                   APARAM                                             is_leap_next
                     CALL                                                  writeln
                   APARAM                                         is_leap_previous
                     CALL                                                  writeln
                   RETURN                                                         
