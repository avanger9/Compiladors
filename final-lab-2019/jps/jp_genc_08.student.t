function main
  vars
    a 10
    i 1
    x 1
  endvars

     %2 = 5
     i = %2
     %3 = 2
     %4 = 1
     %4 = %4 * %3
     %5 = 2222
     a[%4] = %5
  label while1 :
     %6 = 5
     %7 = - %6
     %9 = i <= %7
     %8 = not %9
     ifFalse %8 goto endWhile1
     %10 = 1
     %10 = %10 * i
     %11 = a[%10]
     x = %11
     %12 = 'a'
     writec %12
     %12 = '['
     writec %12
     writei i
     %13 = ']'
     writec %13
     %13 = ' '
     writec %13
     %13 = 'o'
     writec %13
     %13 = 'k'
     writec %13
     %14 = 2
     %15 = i == %14
     ifFalse %15 goto endif1
     %16 = 1
     %16 = %16 * i
     %17 = a[%16]
     writei %17
  label endif1 :
     writeln
     %19 = 1
     %20 = i - %19
     i = %20
     goto while1
  label endWhile1 :
     %21 = 'b'
     writec %21
     %21 = 'a'
     writec %21
     %21 = 'd'
     writec %21
     %21 = ' '
     writec %21
     %21 = 'm'
     writec %21
     %21 = 'e'
     writec %21
     %21 = 's'
     writec %21
     %21 = 's'
     writec %21
     %21 = 'a'
     writec %21
     %21 = 'g'
     writec %21
     %21 = 'e'
     writec %21
     %21 = '!'
     writec %21
     writeln
     return
endfunction


