function f
  params
    a
  endparams

   %2 = 5
   %3 = 10
   %3 = %3 * %2
   %4 = 5
   %5 = 10
   %5 = %5 * %4
   %6 = a
   %6 = %6[%5]
   %7 = 10
   %9 = float %7
   %8 = %6 *. %9
   a[%3] = %8
   return
endfunction

function main
  vars
    b 10
    c 10
  endvars

   %2 = 5
   %3 = 10
   %3 = %3 * %2
   readf %4
   b[%3] = %4
   %5 = 7
   %6 = 10
   %6 = %6 * %5
   %7 = 5
   %8 = 10
   %8 = %8 * %7
   %9 = b[%8]
   c[%6] = %9
   %11 = 5
   %12 = 10
   %12 = %12 * %11
   %13 = b[%12]
   writef %13
   writeln
   %15 = 7
   %16 = 10
   %16 = %16 * %15
   %17 = c[%16]
   writef %17
   writeln
   %19 = &b
   pushparam %19
   call f
   popparam 
   %20 = 5
   %21 = 10
   %21 = %21 * %20
   %22 = b[%21]
   writef %22
   writeln
   %24 = 7
   %25 = 10
   %25 = %25 * %24
   %26 = c[%25]
   writef %26
   writeln
   return
endfunction


