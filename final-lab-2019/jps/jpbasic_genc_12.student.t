function f
  params
    v
  endparams

  vars
    c 10
    i 1
  endvars

     %3 = 0
     %4 = 1
     %6 = v
     %5 = %6[%3]
     c[%3] = %5
     %3 = %3 + %4
     %6 = v
     %5 = %6[%3]
     c[%3] = %5
     %3 = %3 + %4
     %6 = v
     %5 = %6[%3]
     c[%3] = %5
     %3 = %3 + %4
     %6 = v
     %5 = %6[%3]
     c[%3] = %5
     %3 = %3 + %4
     %6 = v
     %5 = %6[%3]
     c[%3] = %5
     %3 = %3 + %4
     %6 = v
     %5 = %6[%3]
     c[%3] = %5
     %3 = %3 + %4
     %6 = v
     %5 = %6[%3]
     c[%3] = %5
     %3 = %3 + %4
     %6 = v
     %5 = %6[%3]
     c[%3] = %5
     %3 = %3 + %4
     %6 = v
     %5 = %6[%3]
     c[%3] = %5
     %3 = %3 + %4
     %6 = v
     %5 = %6[%3]
     c[%3] = %5
     %3 = %3 + %4
     %7 = 'e'
     writec %7
     %7 = 'n'
     writec %7
     %7 = ' '
     writec %7
     %7 = 'f'
     writec %7
     %7 = '.'
     writec %7
     %7 = ' '
     writec %7
     %7 = 'c'
     writec %7
     %7 = ':'
     writec %7
     %7 = ' '
     writec %7
     %8 = 0
     i = %8
  label while1 :
     %9 = 10
     %10 = i < %9
     ifFalse %10 goto endWhile1
     %11 = 1
     %11 = %11 * i
     %12 = c[%11]
     writei %12
     %13 = ' '
     writec %13
     %14 = 1
     %15 = i + %14
     i = %15
     goto while1
  label endWhile1 :
     %16 = '\n'
     writec %16
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
     %11 = 0
     %12 = 1
     %14 = v
     %13 = d[%11]
     %14[%11] = %13
     %11 = %11 + %12
     %14 = v
     %13 = d[%11]
     %14[%11] = %13
     %11 = %11 + %12
     %14 = v
     %13 = d[%11]
     %14[%11] = %13
     %11 = %11 + %12
     %14 = v
     %13 = d[%11]
     %14[%11] = %13
     %11 = %11 + %12
     %14 = v
     %13 = d[%11]
     %14[%11] = %13
     %11 = %11 + %12
     %14 = v
     %13 = d[%11]
     %14[%11] = %13
     %11 = %11 + %12
     %14 = v
     %13 = d[%11]
     %14[%11] = %13
     %11 = %11 + %12
     %14 = v
     %13 = d[%11]
     %14[%11] = %13
     %11 = %11 + %12
     %14 = v
     %13 = d[%11]
     %14[%11] = %13
     %11 = %11 + %12
     %14 = v
     %13 = d[%11]
     %14[%11] = %13
     %11 = %11 + %12
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
     %10 = 0
     %11 = 1
     %12 = a[%10]
     b[%10] = %12
     %10 = %10 + %11
     %12 = a[%10]
     b[%10] = %12
     %10 = %10 + %11
     %12 = a[%10]
     b[%10] = %12
     %10 = %10 + %11
     %12 = a[%10]
     b[%10] = %12
     %10 = %10 + %11
     %12 = a[%10]
     b[%10] = %12
     %10 = %10 + %11
     %12 = a[%10]
     b[%10] = %12
     %10 = %10 + %11
     %12 = a[%10]
     b[%10] = %12
     %10 = %10 + %11
     %12 = a[%10]
     b[%10] = %12
     %10 = %10 + %11
     %12 = a[%10]
     b[%10] = %12
     %10 = %10 + %11
     %12 = a[%10]
     b[%10] = %12
     %10 = %10 + %11
     %13 = 'd'
     writec %13
     %13 = 'e'
     writec %13
     %13 = 's'
     writec %13
     %13 = 'p'
     writec %13
     %13 = 'r'
     writec %13
     %13 = 'e'
     writec %13
     %13 = 's'
     writec %13
     %13 = ' '
     writec %13
     %13 = 'd'
     writec %13
     %13 = 'e'
     writec %13
     %13 = ' '
     writec %13
     %13 = 'b'
     writec %13
     %13 = '='
     writec %13
     %13 = 'a'
     writec %13
     %13 = '.'
     writec %13
     %13 = ' '
     writec %13
     %13 = 'b'
     writec %13
     %13 = ':'
     writec %13
     %13 = ' '
     writec %13
     %14 = 0
     i = %14
  label while2 :
     %15 = 10
     %16 = i < %15
     ifFalse %16 goto endWhile2
     %17 = 1
     %17 = %17 * i
     %18 = b[%17]
     writei %18
     %19 = ' '
     writec %19
     %20 = 1
     %21 = i + %20
     i = %21
     goto while2
  label endWhile2 :
     %22 = '\n'
     writec %22
     %23 = 'd'
     writec %23
     %23 = 'e'
     writec %23
     %23 = 's'
     writec %23
     %23 = 'p'
     writec %23
     %23 = 'r'
     writec %23
     %23 = 'e'
     writec %23
     %23 = 's'
     writec %23
     %23 = ' '
     writec %23
     %23 = 'd'
     writec %23
     %23 = 'e'
     writec %23
     %23 = ' '
     writec %23
     %23 = 'b'
     writec %23
     %23 = '='
     writec %23
     %23 = 'a'
     writec %23
     %23 = '.'
     writec %23
     %23 = ' '
     writec %23
     %23 = 'a'
     writec %23
     %23 = ':'
     writec %23
     %23 = ' '
     writec %23
     %24 = 0
     i = %24
  label while3 :
     %25 = 10
     %26 = i < %25
     ifFalse %26 goto endWhile3
     %27 = 1
     %27 = %27 * i
     %28 = a[%27]
     writei %28
     %29 = ' '
     writec %29
     %30 = 1
     %31 = i + %30
     i = %31
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
     %43 = '\n'
     writec %43
     %44 = &a
     pushparam %44
     call g
     popparam 
     %45 = 'd'
     writec %45
     %45 = 'e'
     writec %45
     %45 = 's'
     writec %45
     %45 = 'p'
     writec %45
     %45 = 'r'
     writec %45
     %45 = 'e'
     writec %45
     %45 = 's'
     writec %45
     %45 = ' '
     writec %45
     %45 = 'd'
     writec %45
     %45 = 'e'
     writec %45
     %45 = ' '
     writec %45
     %45 = 'g'
     writec %45
     %45 = '('
     writec %45
     %45 = 'a'
     writec %45
     %45 = ')'
     writec %45
     %45 = '.'
     writec %45
     %45 = ' '
     writec %45
     %45 = 'a'
     writec %45
     %45 = ':'
     writec %45
     %45 = ' '
     writec %45
     %46 = 0
     i = %46
  label while5 :
     %47 = 10
     %48 = i < %47
     ifFalse %48 goto endWhile5
     %49 = 1
     %49 = %49 * i
     %50 = a[%49]
     writei %50
     %51 = ' '
     writec %51
     %52 = 1
     %53 = i + %52
     i = %53
     goto while5
  label endWhile5 :
     %54 = '\n'
     writec %54
     return
endfunction


