function f_read
  params
    x
    y
  endparams

  vars
    i 1
  endvars

     %3 = 0
     i = %3
  label while1 :
     %4 = 2
     %5 = i < %4
     ifFalse %5 goto endWhile1
     %6 = 1
     %6 = %6 * i
     %7 = 5
     %8 = y
     %8[%6] = %7
     %9 = 1
     %9 = %9 * i
     readi %10
     %11 = x
     %11[%9] = %10
     %12 = 1
     %13 = i + %12
     i = %13
     goto while1
  label endWhile1 :
     return
endfunction

function main
  vars
    a 2
    b 2
    i 1
  endvars

   %2 = &a
   pushparam %2
   %3 = &b
   pushparam %3
   call f_read
   popparam 
   popparam 
   %4 = 0
   %5 = 1
   %5 = %5 * %4
   %6 = a[%5]
   writei %6
   writeln
   %8 = 0
   %9 = 1
   %9 = %9 * %8
   %10 = b[%9]
   writei %10
   return
endfunction


