function dotprod
  params
    _result
    x
    y
  endparams

  vars
    i 1
    s 1
  endvars

     %3 = 0
     i = %3
     %4 = 0
     s = %4
  label while1 :
     %5 = 10
     %6 = i < %5
     ifFalse %6 goto endWhile1
     %7 = 1
     %7 = %7 * i
     %8 = x
     %8 = %8[%7]
     %9 = 1
     %9 = %9 * i
     %10 = y
     %10 = %10[%9]
     %11 = %8 * %10
     %12 = s + %11
     s = %12
     %13 = 1
     %14 = i + %13
     i = %14
     goto while1
  label endWhile1 :
     _result = s
     return
endfunction

function main
  vars
    a 10
    b 10
    i 1
  endvars

     %3 = 0
     i = %3
  label while1 :
     %4 = 10
     %5 = i < %4
     ifFalse %5 goto endWhile1
     %6 = 1
     %6 = %6 * i
     %7 = 1
     %8 = i + %7
     a[%6] = %8
     %9 = 9
     %10 = %9 - i
     %11 = 1
     %11 = %11 * %10
     %12 = 1
     %13 = i + %12
     %14 = 2
     %15 = %13 * %14
     b[%11] = %15
     %16 = 1
     %17 = i + %16
     i = %17
     goto while1
  label endWhile1 :
     %19 = 'd'
     writec %19
     %19 = 'o'
     writec %19
     %19 = 't'
     writec %19
     %19 = 'p'
     writec %19
     %19 = 'r'
     writec %19
     %19 = 'o'
     writec %19
     %19 = 'd'
     writec %19
     %19 = ' '
     writec %19
     %19 = 'm'
     writec %19
     %19 = 'a'
     writec %19
     %19 = 'n'
     writec %19
     %19 = 'u'
     writec %19
     %19 = 'a'
     writec %19
     %19 = 'l'
     writec %19
     %19 = ' '
     writec %19
     %19 = '='
     writec %19
     %19 = ' '
     writec %19
     pushparam 
     %20 = &a
     pushparam %20
     %21 = &b
     pushparam %21
     call dotprod
     popparam 
     popparam 
     popparam %22
     writei %22
     writeln
     %24 = 'd'
     writec %24
     %24 = 'o'
     writec %24
     %24 = 't'
     writec %24
     %24 = 'p'
     writec %24
     %24 = 'r'
     writec %24
     %24 = 'o'
     writec %24
     %24 = 'd'
     writec %24
     %24 = ' '
     writec %24
     %24 = 'o'
     writec %24
     %24 = 'p'
     writec %24
     %24 = 'e'
     writec %24
     %24 = 'r'
     writec %24
     %24 = 'a'
     writec %24
     %24 = 'd'
     writec %24
     %24 = 'o'
     writec %24
     %24 = 'r'
     writec %24
     %24 = ' '
     writec %24
     %24 = '='
     writec %24
     %24 = ' '
     writec %24
     %25 = a * b
     writei %25
     writeln
     return
endfunction


