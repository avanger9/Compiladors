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
     a[%5] = i
     %6 = 'a'
     writec %6
     %6 = '['
     writec %6
     writei i
     %7 = ']'
     writec %7
     %7 = '='
     writec %7
     %8 = 1
     %8 = %8 * i
     %9 = a[%8]
     writei %9
     writeln
     %11 = 1
     %12 = i + %11
     i = %12
     goto while1
  label endWhile1 :
     %13 = 10
     %14 = 1
     %14 = %14 * %13
     %15 = 9999
     a[%14] = %15
     %16 = 'b'
     writec %16
     %16 = 'a'
     writec %16
     %16 = 'd'
     writec %16
     %16 = ' '
     writec %16
     %16 = 'm'
     writec %16
     %16 = 'e'
     writec %16
     %16 = 's'
     writec %16
     %16 = 's'
     writec %16
     %16 = 'a'
     writec %16
     %16 = 'g'
     writec %16
     %16 = 'e'
     writec %16
     %16 = '!'
     writec %16
     writeln
     return
endfunction


