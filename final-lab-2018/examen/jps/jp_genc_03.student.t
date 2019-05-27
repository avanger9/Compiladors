function i_dotprod
  params
    _result
    x
    y
  endparams

   %4 = 0
   %5 = 1
   %8 = 0
   %7 = y
   %6 = %7[%4]
   %7 = x
   %9 = %7[%4]
   %3 = %6 * %9
   %8 = %8 + %3
   %4 = %4 + %5
   %7 = y
   %6 = %7[%4]
   %7 = x
   %9 = %7[%4]
   %3 = %6 * %9
   %8 = %8 + %3
   %4 = %4 + %5
   %7 = y
   %6 = %7[%4]
   %7 = x
   %9 = %7[%4]
   %3 = %6 * %9
   %8 = %8 + %3
   %4 = %4 + %5
   %7 = y
   %6 = %7[%4]
   %7 = x
   %9 = %7[%4]
   %3 = %6 * %9
   %8 = %8 + %3
   %4 = %4 + %5
   %7 = y
   %6 = %7[%4]
   %7 = x
   %9 = %7[%4]
   %3 = %6 * %9
   %8 = %8 + %3
   %4 = %4 + %5
   %7 = y
   %6 = %7[%4]
   %7 = x
   %9 = %7[%4]
   %3 = %6 * %9
   %8 = %8 + %3
   %4 = %4 + %5
   %7 = y
   %6 = %7[%4]
   %7 = x
   %9 = %7[%4]
   %3 = %6 * %9
   %8 = %8 + %3
   %4 = %4 + %5
   %7 = y
   %6 = %7[%4]
   %7 = x
   %9 = %7[%4]
   %3 = %6 * %9
   %8 = %8 + %3
   %4 = %4 + %5
   %7 = y
   %6 = %7[%4]
   %7 = x
   %9 = %7[%4]
   %3 = %6 * %9
   %8 = %8 + %3
   %4 = %4 + %5
   %7 = y
   %6 = %7[%4]
   %7 = x
   %9 = %7[%4]
   %3 = %6 * %9
   %8 = %8 + %3
   %4 = %4 + %5
   _result = %8
   return
endfunction

function f_dotprod
  params
    _result
    x
    y
  endparams

   %4 = 0
   %5 = 1
   %8 = 0
   %7 = y
   %6 = %7[%4]
   %7 = x
   %9 = %7[%4]
   %3 = %6 *. %9
   %8 = %8 +. %3
   %4 = %4 + %5
   %7 = y
   %6 = %7[%4]
   %7 = x
   %9 = %7[%4]
   %3 = %6 *. %9
   %8 = %8 +. %3
   %4 = %4 + %5
   %7 = y
   %6 = %7[%4]
   %7 = x
   %9 = %7[%4]
   %3 = %6 *. %9
   %8 = %8 +. %3
   %4 = %4 + %5
   %7 = y
   %6 = %7[%4]
   %7 = x
   %9 = %7[%4]
   %3 = %6 *. %9
   %8 = %8 +. %3
   %4 = %4 + %5
   %7 = y
   %6 = %7[%4]
   %7 = x
   %9 = %7[%4]
   %3 = %6 *. %9
   %8 = %8 +. %3
   %4 = %4 + %5
   %7 = y
   %6 = %7[%4]
   %7 = x
   %9 = %7[%4]
   %3 = %6 *. %9
   %8 = %8 +. %3
   %4 = %4 + %5
   %7 = y
   %6 = %7[%4]
   %7 = x
   %9 = %7[%4]
   %3 = %6 *. %9
   %8 = %8 +. %3
   %4 = %4 + %5
   %7 = y
   %6 = %7[%4]
   %7 = x
   %9 = %7[%4]
   %3 = %6 *. %9
   %8 = %8 +. %3
   %4 = %4 + %5
   %7 = y
   %6 = %7[%4]
   %7 = x
   %9 = %7[%4]
   %3 = %6 *. %9
   %8 = %8 +. %3
   %4 = %4 + %5
   %7 = y
   %6 = %7[%4]
   %7 = x
   %9 = %7[%4]
   %3 = %6 *. %9
   %8 = %8 +. %3
   %4 = %4 + %5
   _result = %8
   return
endfunction

function i_readvec
  params
    x
  endparams

  vars
    i 1
  endvars

     %2 = 0
     i = %2
  label while1 :
     %3 = 10
     %4 = i < %3
     ifFalse %4 goto endWhile1
     %5 = 1
     %5 = %5 * i
     readi %6
     %7 = x
     %7[%5] = %6
     %8 = 1
     %9 = i + %8
     i = %9
     goto while1
  label endWhile1 :
     return
endfunction

function f_readvec
  params
    x
  endparams

  vars
    i 1
  endvars

     %2 = 0
     i = %2
  label while1 :
     %3 = 10
     %4 = i < %3
     ifFalse %4 goto endWhile1
     %5 = 1
     %5 = %5 * i
     readf %6
     %7 = x
     %7[%5] = %6
     %8 = 1
     %9 = i + %8
     i = %9
     goto while1
  label endWhile1 :
     return
endfunction

function main
  vars
    a 10
    b 10
    c 10
    d 10
  endvars

   %5 = &a
   pushparam %5
   call i_readvec
   popparam 
   %6 = &b
   pushparam %6
   call i_readvec
   popparam 
   %7 = &c
   pushparam %7
   call f_readvec
   popparam 
   %8 = &d
   pushparam %8
   call f_readvec
   popparam 
   %9 = 'd'
   writec %9
   %9 = 'o'
   writec %9
   %9 = 't'
   writec %9
   %9 = 'p'
   writec %9
   %9 = 'r'
   writec %9
   %9 = 'o'
   writec %9
   %9 = 'd'
   writec %9
   %9 = ' '
   writec %9
   %9 = 'i'
   writec %9
   %9 = 'n'
   writec %9
   %9 = 't'
   writec %9
   %9 = ' '
   writec %9
   %9 = 'f'
   writec %9
   %9 = 'u'
   writec %9
   %9 = 'n'
   writec %9
   %9 = 'c'
   writec %9
   %9 = 'i'
   writec %9
   %9 = 'o'
   writec %9
   %9 = ' '
   writec %9
   %9 = '='
   writec %9
   %9 = ' '
   writec %9
   pushparam 
   %10 = &a
   pushparam %10
   %11 = &b
   pushparam %11
   call i_dotprod
   popparam 
   popparam 
   popparam %12
   writei %12
   writeln
   %14 = 'd'
   writec %14
   %14 = 'o'
   writec %14
   %14 = 't'
   writec %14
   %14 = 'p'
   writec %14
   %14 = 'r'
   writec %14
   %14 = 'o'
   writec %14
   %14 = 'd'
   writec %14
   %14 = ' '
   writec %14
   %14 = 'f'
   writec %14
   %14 = 'l'
   writec %14
   %14 = 'o'
   writec %14
   %14 = 'a'
   writec %14
   %14 = 't'
   writec %14
   %14 = ' '
   writec %14
   %14 = 'f'
   writec %14
   %14 = 'u'
   writec %14
   %14 = 'n'
   writec %14
   %14 = 'c'
   writec %14
   %14 = 'i'
   writec %14
   %14 = 'o'
   writec %14
   %14 = ' '
   writec %14
   %14 = '='
   writec %14
   %14 = ' '
   writec %14
   pushparam 
   %15 = &c
   pushparam %15
   %16 = &d
   pushparam %16
   call f_dotprod
   popparam 
   popparam 
   popparam %17
   writef %17
   writeln
   %19 = 'd'
   writec %19
   %19 = 'o'
   writec %19
   %19 = 't'
   writec %19
   %19 = 'p'
   writec %19
   %19 = 'r'
   writec %19
   %19 = 'o'
   writec %19
   %19 = 'd'
   writec %19
   %19 = ' '
   writec %19
   %19 = 'i'
   writec %19
   %19 = 'n'
   writec %19
   %19 = 't'
   writec %19
   %19 = ' '
   writec %19
   %19 = 'l'
   writec %19
   %19 = 'o'
   writec %19
   %19 = 'c'
   writec %19
   %19 = 'a'
   writec %19
   %19 = 'l'
   writec %19
   %19 = ' '
   writec %19
   %19 = '='
   writec %19
   %19 = ' '
   writec %19
   %21 = 0
   %22 = 1
   %25 = 0
   %23 = a[%21]
   %24 = b[%21]
   %20 = %23 * %24
   %25 = %25 + %20
   %21 = %21 + %22
   %23 = a[%21]
   %24 = b[%21]
   %20 = %23 * %24
   %25 = %25 + %20
   %21 = %21 + %22
   %23 = a[%21]
   %24 = b[%21]
   %20 = %23 * %24
   %25 = %25 + %20
   %21 = %21 + %22
   %23 = a[%21]
   %24 = b[%21]
   %20 = %23 * %24
   %25 = %25 + %20
   %21 = %21 + %22
   %23 = a[%21]
   %24 = b[%21]
   %20 = %23 * %24
   %25 = %25 + %20
   %21 = %21 + %22
   %23 = a[%21]
   %24 = b[%21]
   %20 = %23 * %24
   %25 = %25 + %20
   %21 = %21 + %22
   %23 = a[%21]
   %24 = b[%21]
   %20 = %23 * %24
   %25 = %25 + %20
   %21 = %21 + %22
   %23 = a[%21]
   %24 = b[%21]
   %20 = %23 * %24
   %25 = %25 + %20
   %21 = %21 + %22
   %23 = a[%21]
   %24 = b[%21]
   %20 = %23 * %24
   %25 = %25 + %20
   %21 = %21 + %22
   %23 = a[%21]
   %24 = b[%21]
   %20 = %23 * %24
   %25 = %25 + %20
   %21 = %21 + %22
   writei %25
   writeln
   %27 = 'd'
   writec %27
   %27 = 'o'
   writec %27
   %27 = 't'
   writec %27
   %27 = 'p'
   writec %27
   %27 = 'r'
   writec %27
   %27 = 'o'
   writec %27
   %27 = 'd'
   writec %27
   %27 = ' '
   writec %27
   %27 = 'f'
   writec %27
   %27 = 'l'
   writec %27
   %27 = 'o'
   writec %27
   %27 = 'a'
   writec %27
   %27 = 't'
   writec %27
   %27 = ' '
   writec %27
   %27 = 'l'
   writec %27
   %27 = 'o'
   writec %27
   %27 = 'c'
   writec %27
   %27 = 'a'
   writec %27
   %27 = 'l'
   writec %27
   %27 = ' '
   writec %27
   %27 = '='
   writec %27
   %27 = ' '
   writec %27
   %29 = 0
   %30 = 1
   %33 = 0
   %31 = c[%29]
   %32 = d[%29]
   %28 = %31 *. %32
   %33 = %33 +. %28
   %29 = %29 + %30
   %31 = c[%29]
   %32 = d[%29]
   %28 = %31 *. %32
   %33 = %33 +. %28
   %29 = %29 + %30
   %31 = c[%29]
   %32 = d[%29]
   %28 = %31 *. %32
   %33 = %33 +. %28
   %29 = %29 + %30
   %31 = c[%29]
   %32 = d[%29]
   %28 = %31 *. %32
   %33 = %33 +. %28
   %29 = %29 + %30
   %31 = c[%29]
   %32 = d[%29]
   %28 = %31 *. %32
   %33 = %33 +. %28
   %29 = %29 + %30
   %31 = c[%29]
   %32 = d[%29]
   %28 = %31 *. %32
   %33 = %33 +. %28
   %29 = %29 + %30
   %31 = c[%29]
   %32 = d[%29]
   %28 = %31 *. %32
   %33 = %33 +. %28
   %29 = %29 + %30
   %31 = c[%29]
   %32 = d[%29]
   %28 = %31 *. %32
   %33 = %33 +. %28
   %29 = %29 + %30
   %31 = c[%29]
   %32 = d[%29]
   %28 = %31 *. %32
   %33 = %33 +. %28
   %29 = %29 + %30
   %31 = c[%29]
   %32 = d[%29]
   %28 = %31 *. %32
   %33 = %33 +. %28
   %29 = %29 + %30
   writef %33
   writeln
   return
endfunction


