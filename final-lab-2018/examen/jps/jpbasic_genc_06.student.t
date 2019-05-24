function f
  params
    _result
    a
    f
  endparams

  vars
    x 1
    b 1
    z 10
  endvars

     %2 = 5
     %3 = 1
     %3 = %3 * %2
     readi %4
     z[%3] = %4
     %5 = 5
     %6 = 1
     %6 = %6 * %5
     %7 = z[%6]
     %8 = 88
     %9 = %7 + %8
     writei %9
     readi b
     readf f
     ifFalse b goto endif1
     %10 = 'h'
     writec %10
     writeln
     %10 = '\t'
     writec %10
     %10 = 'l'
     writec %10
     %10 = '\\'
     writec %10
     %10 = 'a'
     writec %10
     %11 = -. f
     %12 = -. %11
     %13 = -. %12
     writef %13
     writeln
  label endif1 :
     %15 = 1
     _result = %15
     return
endfunction

function fz
  params
    _result
    r
    u
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
     %7 = 0
     %8 = r == %7
     ifFalse %8 goto endif1
     pushparam 
     %9 = 55555
     pushparam %9
     %10 = 1
     %11 = 4
     %12 = %10 / %11
     %13 = float %12
     pushparam %13
     call f
     popparam 
     popparam 
     popparam %14
  label endif1 :
     %15 = 3
     %16 = r + %15
     %18 = float %16
     %17 = %18 *. u
     _result = %17
     return
endfunction

function main
  vars
    a 1
    q 1
  endvars

   %1 = 0
   q = %1
   pushparam 
   %2 = 3
   %3 = 4
   %4 = %2 + %3
   pushparam %4
   pushparam 
   %5 = 4444
   pushparam %5
   %6 = 2
   %8 = float %6
   %7 = q +. %8
   pushparam %7
   call fz
   popparam 
   popparam 
   popparam %9
   pushparam %9
   call fz
   popparam 
   popparam 
   popparam %10
   q = %10
   %11 = 3.7
   %12 = q +. %11
   %13 = 4
   %15 = float %13
   %14 = %12 +. %15
   writef %14
   writeln
   return
endfunction


