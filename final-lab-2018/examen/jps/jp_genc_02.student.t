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
     %11 = %8 *. %10
     %12 = s +. %11
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
     %9 = 2.5
     %11 = float %8
     %10 = %11 /. %9
     a[%6] = %10
     %12 = 9
     %13 = %12 - i
     %14 = 1
     %14 = %14 * %13
     %15 = 1
     %16 = i + %15
     %17 = 0.7
     %19 = float %16
     %18 = %19 *. %17
     b[%14] = %18
     %20 = 1
     %21 = i + %20
     i = %21
     goto while1
  label endWhile1 :
     %23 = 'd'
     writec %23
     %23 = 'o'
     writec %23
     %23 = 't'
     writec %23
     %23 = 'p'
     writec %23
     %23 = 'r'
     writec %23
     %23 = 'o'
     writec %23
     %23 = 'd'
     writec %23
     %23 = ' '
     writec %23
     %23 = 'm'
     writec %23
     %23 = 'a'
     writec %23
     %23 = 'n'
     writec %23
     %23 = 'u'
     writec %23
     %23 = 'a'
     writec %23
     %23 = 'l'
     writec %23
     %23 = ' '
     writec %23
     %23 = '='
     writec %23
     %23 = ' '
     writec %23
     pushparam 
     %24 = &a
     pushparam %24
     %25 = &b
     pushparam %25
     call dotprod
     popparam 
     popparam 
     popparam %26
     writef %26
     writeln
     %28 = 'd'
     writec %28
     %28 = 'o'
     writec %28
     %28 = 't'
     writec %28
     %28 = 'p'
     writec %28
     %28 = 'r'
     writec %28
     %28 = 'o'
     writec %28
     %28 = 'd'
     writec %28
     %28 = ' '
     writec %28
     %28 = 'o'
     writec %28
     %28 = 'p'
     writec %28
     %28 = 'e'
     writec %28
     %28 = 'r'
     writec %28
     %28 = 'a'
     writec %28
     %28 = 'd'
     writec %28
     %28 = 'o'
     writec %28
     %28 = 'r'
     writec %28
     %28 = ' '
     writec %28
     %28 = '='
     writec %28
     %28 = ' '
     writec %28
     %30 = 0
     %31 = 1
     %34 = 0
     %32 = a[%30]
     %33 = b[%30]
     %29 = %32 *. %33
     %34 = %34 +. %29
     %30 = %30 + %31
     %32 = a[%30]
     %33 = b[%30]
     %29 = %32 *. %33
     %34 = %34 +. %29
     %30 = %30 + %31
     %32 = a[%30]
     %33 = b[%30]
     %29 = %32 *. %33
     %34 = %34 +. %29
     %30 = %30 + %31
     %32 = a[%30]
     %33 = b[%30]
     %29 = %32 *. %33
     %34 = %34 +. %29
     %30 = %30 + %31
     %32 = a[%30]
     %33 = b[%30]
     %29 = %32 *. %33
     %34 = %34 +. %29
     %30 = %30 + %31
     %32 = a[%30]
     %33 = b[%30]
     %29 = %32 *. %33
     %34 = %34 +. %29
     %30 = %30 + %31
     %32 = a[%30]
     %33 = b[%30]
     %29 = %32 *. %33
     %34 = %34 +. %29
     %30 = %30 + %31
     %32 = a[%30]
     %33 = b[%30]
     %29 = %32 *. %33
     %34 = %34 +. %29
     %30 = %30 + %31
     %32 = a[%30]
     %33 = b[%30]
     %29 = %32 *. %33
     %34 = %34 +. %29
     %30 = %30 + %31
     %32 = a[%30]
     %33 = b[%30]
     %29 = %32 *. %33
     %34 = %34 +. %29
     %30 = %30 + %31
     writef %34
     writeln
     return
endfunction


