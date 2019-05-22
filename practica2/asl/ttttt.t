function f
  params
    v
  endparams

  vars
    c 10
    i 1
  endvars

     c = v
     %3 = 'e'
     writec %3
     %3 = 'n'
     writec %3
     %3 = ' '
     writec %3
     %3 = 'f'
     writec %3
     %3 = '.'
     writec %3
     %3 = ' '
     writec %3
     %3 = 'c'
     writec %3
     %3 = ':'
     writec %3
     %3 = ' '
     writec %3
     %4 = 0
     i = %4
  label while1 :
     %5 = 10
     %6 = i < %5
     ifFalse %6 goto endWhile1
     %7 = 1
     %7 = %7 * i
     %8 = c[%7]
     writei %8
     %9 = ' '
     writec %9
     %10 = 1
     %11 = i + %10
     i = %11
     goto while1
  label endWhile1 :
     %13 = '\n'
     writec %13
     return
endfunction

function g
  params
    v
  endparams

  vars
    d 10
    i 1
  endvars

     %3 = 0
     i = %3
  label while1 :
     %4 = 10
     %5 = i < %4
     ifFalse %5 goto endWhile1
     %6 = 1
     %6 = %6 * i
     %7 = 1
     %8 = - %7
     d[%6] = %8
     %9 = 1
     %10 = i + %9
     i = %10
     goto while1
  label endWhile1 :
     v = d
     return
endfunction

function main
  vars
    a 10
    b 10
    i 1
    j 1
  endvars

     %2 = 0
     i = %2
  label while1 :
     %3 = 10
     %4 = i < %3
     ifFalse %4 goto endWhile1
     %5 = 1
     %5 = %5 * i
     a[%5] = i
     %6 = 1
     %6 = %6 * i
     %7 = 0
     b[%6] = %7
     %8 = 1
     %9 = i + %8
     i = %9
     goto while1
  label endWhile1 :
     b = a
     %11 = 'd'
     writec %11
     %11 = 'e'
     writec %11
     %11 = 's'
     writec %11
     %11 = 'p'
     writec %11
     %11 = 'r'
     writec %11
     %11 = 'e'
     writec %11
     %11 = 's'
     writec %11
     %11 = ' '
     writec %11
     %11 = 'd'
     writec %11
     %11 = 'e'
     writec %11
     %11 = ' '
     writec %11
     %11 = 'b'
     writec %11
     %11 = '='
     writec %11
     %11 = 'a'
     writec %11
     %11 = '.'
     writec %11
     %11 = ' '
     writec %11
     %11 = 'b'
     writec %11
     %11 = ':'
     writec %11
     %11 = ' '
     writec %11
     %12 = 0
     i = %12
  label while2 :
     %13 = 10
     %14 = i < %13
     ifFalse %14 goto endWhile2
     %15 = 1
     %15 = %15 * i
     %16 = b[%15]
     writei %16
     %17 = ' '
     writec %17
     %18 = 1
     %19 = i + %18
     i = %19
     goto while2
  label endWhile2 :
     %21 = '\n'
     writec %21
     %22 = 'd'
     writec %22
     %22 = 'e'
     writec %22
     %22 = 's'
     writec %22
     %22 = 'p'
     writec %22
     %22 = 'r'
     writec %22
     %22 = 'e'
     writec %22
     %22 = 's'
     writec %22
     %22 = ' '
     writec %22
     %22 = 'd'
     writec %22
     %22 = 'e'
     writec %22
     %22 = ' '
     writec %22
     %22 = 'b'
     writec %22
     %22 = '='
     writec %22
     %22 = 'a'
     writec %22
     %22 = '.'
     writec %22
     %22 = ' '
     writec %22
     %22 = 'a'
     writec %22
     %22 = ':'
     writec %22
     %22 = ' '
     writec %22
     %23 = 0
     i = %23
  label while3 :
     %24 = 10
     %25 = i < %24
     ifFalse %25 goto endWhile3
     %26 = 1
     %26 = %26 * i
     %27 = a[%26]
     writei %27
     %28 = ' '
     writec %28
     %29 = 1
     %30 = i + %29
     i = %30
     goto while3
  label endWhile3 :
     %32 = '\n'
     writec %32
     %33 = &a
     pushparam %33
     call f
     popparam 
     %34 = 'd'
     writec %34
     %34 = 'e'
     writec %34
     %34 = 's'
     writec %34
     %34 = 'p'
     writec %34
     %34 = 'r'
     writec %34
     %34 = 'e'
     writec %34
     %34 = 's'
     writec %34
     %34 = ' '
     writec %34
     %34 = 'd'
     writec %34
     %34 = 'e'
     writec %34
     %34 = ' '
     writec %34
     %34 = 'f'
     writec %34
     %34 = '('
     writec %34
     %34 = 'a'
     writec %34
     %34 = ')'
     writec %34
     %34 = '.'
     writec %34
     %34 = ' '
     writec %34
     %34 = 'a'
     writec %34
     %34 = ':'
     writec %34
     %34 = ' '
     writec %34
     %35 = 0
     i = %35
  label while4 :
     %36 = 10
     %37 = i < %36
     ifFalse %37 goto endWhile4
     %38 = 1
     %38 = %38 * i
     %39 = a[%38]
     writei %39
     %40 = ' '
     writec %40
     %41 = 1
     %42 = i + %41
     i = %42
     goto while4
  label endWhile4 :
     %44 = '\n'
     writec %44
     %45 = &a
     pushparam %45
     call g
     popparam 
     %46 = 'd'
     writec %46
     %46 = 'e'
     writec %46
     %46 = 's'
     writec %46
     %46 = 'p'
     writec %46
     %46 = 'r'
     writec %46
     %46 = 'e'
     writec %46
     %46 = 's'
     writec %46
     %46 = ' '
     writec %46
     %46 = 'd'
     writec %46
     %46 = 'e'
     writec %46
     %46 = ' '
     writec %46
     %46 = 'g'
     writec %46
     %46 = '('
     writec %46
     %46 = 'a'
     writec %46
     %46 = ')'
     writec %46
     %46 = '.'
     writec %46
     %46 = ' '
     writec %46
     %46 = 'a'
     writec %46
     %46 = ':'
     writec %46
     %46 = ' '
     writec %46
     %47 = 0
     i = %47
  label while5 :
     %48 = 10
     %49 = i < %48
     ifFalse %49 goto endWhile5
     %50 = 1
     %50 = %50 * i
     %51 = a[%50]
     writei %51
     %52 = ' '
     writec %52
     %53 = 1
     %54 = i + %53
     i = %54
     goto while5
  label endWhile5 :
     %56 = '\n'
     writec %56
     return
endfunction


