function x2
  params
    _result
    a
  endparams

  vars
    i 1
    n 1
  endvars

     %2 = 0
     n = %2
     %3 = 0
     i = %3
  label while1 :
     %4 = 10
     %5 = i < %4
     ifFalse %5 goto endWhile1
     %6 = 1
     %6 = %6 * i
     %7 = a
     %7 = %7[%6]
     %8 = 0
     %9 = %7 == %8
     ifFalse %9 goto endif1
     %10 = 1
     %11 = n + %10
     n = %11
  label endif1 :
     %12 = 1
     %12 = %12 * i
     %13 = 1
     %13 = %13 * i
     %14 = a
     %14 = %14[%13]
     %15 = 2
     %16 = %14 * %15
     %17 = a
     %17[%12] = %16
     %18 = 1
     %18 = %18 * i
     %19 = a
     %19 = %19[%18]
     writei %19
     writeln
     %21 = 1
     %22 = i + %21
     i = %22
     goto while1
  label endWhile1 :
     _result = n
     return
endfunction

function main
  vars
    x 10
    i 1
    z 1
  endvars

     %2 = 0
     i = %2
  label while1 :
     %3 = 10
     %4 = i < %3
     ifFalse %4 goto endWhile1
     %5 = 1
     %5 = %5 * i
     x[%5] = i
     %6 = 1
     %7 = i + %6
     i = %7
     goto while1
  label endWhile1 :
     %8 = 0
     i = %8
  label while2 :
     %9 = 10
     %10 = i < %9
     ifFalse %10 goto endWhile2
     %11 = 1
     %11 = %11 * i
     %12 = x[%11]
     writei %12
     writeln
     %14 = 1
     %15 = i + %14
     i = %15
     goto while2
  label endWhile2 :
     pushparam 
     %16 = &x
     pushparam %16
     call x2
     popparam 
     popparam %17
     z = %17
     %18 = 'z'
     writec %18
     %18 = ':'
     writec %18
     writei z
     writeln
     %20 = 0
     i = %20
  label while3 :
     %21 = 10
     %22 = i < %21
     ifFalse %22 goto endWhile3
     %23 = 'x'
     writec %23
     %23 = '['
     writec %23
     writei i
     %24 = ']'
     writec %24
     %24 = '='
     writec %24
     %25 = 1
     %25 = %25 * i
     %26 = x[%25]
     writei %26
     writeln
     %28 = 1
     %29 = i + %28
     i = %29
     goto while3
  label endWhile3 :
     return
endfunction


