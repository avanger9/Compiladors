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
     %9 = 0
     i = %9
  label while2 :
     %10 = 10
     %11 = i < %10
     ifFalse %11 goto endWhile2
     %12 = 1
     %12 = %12 * i
     %13 = x[%12]
     writei %13
     writeln
     %15 = 1
     %16 = i + %15
     i = %16
     goto while2
  label endWhile2 :
     pushparam 
     %18 = &x
     pushparam %18
     call x2
     popparam 
     popparam %19
     z = %19
     %20 = 'z'
     writec %20
     %20 = ':'
     writec %20
     writei z
     writeln
     %22 = 0
     i = %22
  label while3 :
     %23 = 10
     %24 = i < %23
     ifFalse %24 goto endWhile3
     %25 = 'x'
     writec %25
     %25 = '['
     writec %25
     writei i
     %26 = ']'
     writec %26
     %26 = '='
     writec %26
     %27 = 1
     %27 = %27 * i
     %28 = x[%27]
     writei %28
     writeln
     %30 = 1
     %31 = i + %30
     i = %31
     goto while3
  label endWhile3 :
     return
endfunction


