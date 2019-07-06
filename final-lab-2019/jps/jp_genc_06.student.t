3
3
3
function f
  params
    _result
    a
    b
  endparams

     %2 = 0
     %4 = 1
     %6 = a
     %5 = %6[%2]
     %3 = %5
     %2 = %2 + %4
     %6 = a
     %5 = %6[%2]
     %2 = %2 + %4
     %7 = %3 < %5
     ifFalse %7 goto false11
     %3 = %5
  label false11 :
     %6 = a
     %5 = %6[%2]
     %2 = %2 + %4
     %8 = %3 < %5
     ifFalse %8 goto false22
     %3 = %5
  label false22 :
     %9 = b + %3
     _result = %9
     return
endfunction

function g
  params
    _result
    a
    b
  endparams

     %2 = 0
     %4 = 1
     %6 = b
     %5 = %6[%2]
     %7 = float %5
     %3 = %7
     %2 = %2 + %4
     %6 = b
     %5 = %6[%2]
     %2 = %2 + %4
     %8 = %3 <. %5
     ifFalse %8 goto false11
     %9 = %5
     %3 = float %9
  label false11 :
     %6 = b
     %5 = %6[%2]
     %2 = %2 + %4
     %10 = %3 <. %5
     ifFalse %10 goto false22
     %11 = %5
     %3 = float %11
  label false22 :
     %13 = a <= %3
     %12 = not %13
     ifFalse %12 goto else5
     %14 = 0
     %16 = 1
     %18 = b
     %17 = %18[%14]
     %19 = float %17
     %15 = %19
     %14 = %14 + %16
     %18 = b
     %17 = %18[%14]
     %14 = %14 + %16
     %20 = %15 <. %17
     ifFalse %20 goto false31
     %21 = %17
     %15 = float %21
  label false31 :
     %18 = b
     %17 = %18[%14]
     %14 = %14 + %16
     %22 = %15 <. %17
     ifFalse %22 goto false42
     %23 = %17
     %15 = float %23
  label false42 :
     _result = %15
     goto endif5
  label else5 :
     %24 = 2
     %25 = 1
     %25 = %25 * %24
     %26 = b
     %26 = %26[%25]
     _result = %26
  label endif5 :
     return
endfunction

function main
  vars
    a 3
    b 3
  endvars

   %3 = 0
   %4 = 1
   %4 = %4 * %3
   %5 = 7
   a[%4] = %5
   %6 = 1
   %7 = 1
   %7 = %7 * %6
   %8 = 3
   a[%7] = %8
   %9 = 2
   %10 = 1
   %10 = %10 * %9
   %11 = 14
   a[%10] = %11
   %12 = 0
   %13 = 1
   %13 = %13 * %12
   %14 = 'o'
   b[%13] = %14
   %15 = 1
   %16 = 1
   %16 = %16 * %15
   %17 = 'c'
   b[%16] = %17
   %18 = 2
   %19 = 1
   %19 = %19 * %18
   %20 = 'a'
   b[%19] = %20
   %21 = 'a'
   writec %21
   %21 = ')'
   writec %21
   %21 = ' '
   writec %21
   %21 = 'f'
   writec %21
   %21 = '('
   writec %21
   %21 = 'a'
   writec %21
   %21 = ','
   writec %21
   %21 = ' '
   writec %21
   %21 = '2'
   writec %21
   %21 = '3'
   writec %21
   %21 = ')'
   writec %21
   %21 = '='
   writec %21
   pushparam 
   %23 = &a
   pushparam %23
   %22 = 23
   pushparam %22
   call f
   popparam 
   popparam 
   popparam %24
   writei %24
   writeln
   %26 = 'b'
   writec %26
   %26 = ')'
   writec %26
   %26 = ' '
   writec %26
   %26 = 'g'
   writec %26
   %26 = '('
   writec %26
   %26 = '''
   writec %26
   %26 = 'z'
   writec %26
   %26 = '''
   writec %26
   %26 = ','
   writec %26
   %26 = ' '
   writec %26
   %26 = 'b'
   writec %26
   %26 = ')'
   writec %26
   %26 = '='
   writec %26
   pushparam 
   %27 = 'z'
   pushparam %27
   %28 = &b
   pushparam %28
   call g
   popparam 
   popparam 
   popparam %29
   writec %29
   writeln
   %31 = 'c'
   writec %31
   %31 = ')'
   writec %31
   %31 = ' '
   writec %31
   %31 = 'g'
   writec %31
   %31 = '('
   writec %31
   %31 = '''
   writec %31
   %31 = 'e'
   writec %31
   %31 = '''
   writec %31
   %31 = ','
   writec %31
   %31 = ' '
   writec %31
   %31 = 'b'
   writec %31
   %31 = ')'
   writec %31
   %31 = '='
   writec %31
   pushparam 
   %32 = 'e'
   pushparam %32
   %33 = &b
   pushparam %33
   call g
   popparam 
   popparam 
   popparam %34
   writec %34
   writeln
   return
endfunction


