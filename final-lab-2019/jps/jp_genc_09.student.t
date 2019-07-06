function main
  vars
    a 10
    i 1
    x 1
  endvars

     %2 = 5
     i = %2
  label while1 :
     %3 = 10
     %4 = i < %3
     ifFalse %4 goto endWhile1
     %5 = 1
     %5 = %5 * i
     %6 = a[%5]
     x = %6
     %7 = 'a'
     writec %7
     %7 = '['
     writec %7
     writei i
     %8 = ']'
     writec %8
     %8 = ' '
     writec %8
     %8 = 'o'
     writec %8
     %8 = 'k'
     writec %8
     writeln
     %10 = 1
     %11 = i + %10
     i = %11
     goto while1
  label endWhile1 :
     %12 = 10
     %13 = 1
     %13 = %13 * %12
     %14 = a[%13]
     writei %14
     %15 = 'b'
     writec %15
     %15 = 'a'
     writec %15
     %15 = 'd'
     writec %15
     %15 = ' '
     writec %15
     %15 = 'm'
     writec %15
     %15 = 'e'
     writec %15
     %15 = 's'
     writec %15
     %15 = 's'
     writec %15
     %15 = 'a'
     writec %15
     %15 = 'g'
     writec %15
     %15 = 'e'
     writec %15
     %15 = '!'
     writec %15
     writeln
     return
endfunction


