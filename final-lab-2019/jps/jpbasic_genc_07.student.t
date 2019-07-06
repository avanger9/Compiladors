function f
  params
    a
  endparams

   %2 = 5
   %3 = 1
   %3 = %3 * %2
   %4 = 5
   %5 = 1
   %5 = %5 * %4
   %6 = a
   %6 = %6[%5]
   %7 = 10
   %9 = float %7
   %8 = %6 *. %9
   %10 = a
   %10[%3] = %8
   return
endfunction

function main
  vars
    b 10
    c 10
  endvars

   %2 = 5
   %3 = 1
   %3 = %3 * %2
   readf %4
   b[%3] = %4
   %5 = 7
   %6 = 1
   %6 = %6 * %5
   %7 = 5
   %8 = 1
   %8 = %8 * %7
   %9 = b[%8]
   c[%6] = %9
   %10 = 5
   %11 = 1
   %11 = %11 * %10
   %12 = b[%11]
   writef %12
   writeln
   %14 = 7
   %15 = 1
   %15 = %15 * %14
   %16 = c[%15]
   writef %16
   writeln
   %18 = &b
   pushparam %18
   call f
   popparam 
   %19 = 5
   %20 = 1
   %20 = %20 * %19
   %21 = b[%20]
   writef %21
   writeln
   %23 = 7
   %24 = 1
   %24 = %24 * %23
   %25 = c[%24]
   writef %25
   writeln
   return
endfunction


