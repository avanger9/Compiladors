function f
  params
    _result
    a
    b
  endparams

  vars
    x 1
    y 1
    z 10
  endvars

     %2 = 9
     %3 = 1
     %3 = %3 * %2
     %4 = 67
     %5 = a + %4
     z[%3] = %5
     %6 = 34
     x = %6
     %7 = 3
     %8 = 1
     %8 = %8 * %7
     %9 = 56
     %10 = 9
     %11 = 1
     %11 = %11 * %10
     %12 = z[%11]
     %13 = %9 + %12
     z[%8] = %13
     %14 = 3
     %15 = 1
     %15 = %15 * %14
     %16 = z[%15]
     %18 = %16 <= x
     %17 = not %18
     ifFalse %17 goto else1
     %19 = 78
     x = %19
     writef b
     writeln
     goto endif1
  label else1 :
     %21 = 99
     x = %21
  label endif1 :
     %22 = 3
     %23 = 1
     %23 = %23 * %22
     %24 = z[%23]
     writei %24
     writeln
     %26 = 1
     _result = %26
     return
endfunction

function fz
  params
    r
  endparams

  label while1 :
     %1 = 0
     %3 = r <= %1
     %2 = not %3
     ifFalse %2 goto endWhile1
     %4 = 1
     %5 = r - %4
     r = %5
     goto while1
  label endWhile1 :
     return
endfunction

function main
  vars
    a 1
  endvars

     %1 = 0
     a = %1
     pushparam 
     %2 = 3
     pushparam %2
     %3 = 2
     %4 = float %3
     pushparam %4
     call f
     popparam 
     popparam 
     popparam %5
     ifFalse %5 goto endif1
     %6 = 3.7
     %8 = float a
     %7 = %8 +. %6
     %9 = 4
     %11 = float %9
     %10 = %7 +. %11
     writef %10
     writeln
  label endif1 :
     return
endfunction


