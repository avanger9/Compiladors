6
3
function init
  params
    aC
  endparams

   %2 = 0
   %3 = 1
   %3 = %3 * %2
   %4 = 5.4
   %5 = -. %4
   %6 = aC
   %6[%3] = %5
   %7 = 1
   %8 = 1
   %8 = %8 * %7
   %9 = 3.7
   %10 = -. %9
   %11 = aC
   %11[%8] = %10
   %12 = 2
   %13 = 1
   %13 = %13 * %12
   %14 = 8.2
   %15 = -. %14
   %16 = aC
   %16[%13] = %15
   %17 = 3
   %18 = 1
   %18 = %18 * %17
   %19 = 5.1
   %20 = -. %19
   %21 = aC
   %21[%18] = %20
   %22 = 4
   %23 = 1
   %23 = %23 * %22
   %24 = 7.9
   %25 = -. %24
   %26 = aC
   %26[%23] = %25
   %27 = 5
   %28 = 1
   %28 = %28 * %27
   %29 = 10
   %30 = - %29
   %31 = aC
   %31[%28] = %30
   return
endfunction

function main
  vars
    a 6
    b 3
    i 1
  endvars

     %3 = &a
     pushparam %3
     call init
     popparam 
     %4 = 0
     %5 = 1
     %5 = %5 * %4
     %6 = 'h'
     b[%5] = %6
     %7 = 1
     %8 = 1
     %8 = %8 * %7
     %9 = 'b'
     b[%8] = %9
     %10 = 2
     %11 = 1
     %11 = %11 * %10
     %12 = 'o'
     b[%11] = %12
     %13 = 0
     i = %13
  label while1 :
     %14 = 6
     %15 = i < %14
     ifFalse %15 goto endWhile1
     %16 = 'a'
     writec %16
     %16 = '['
     writec %16
     writei i
     %17 = ']'
     writec %17
     %17 = '='
     writec %17
     %18 = 1
     %18 = %18 * i
     %19 = a[%18]
     writef %19
     writeln
     %21 = 1
     %22 = i + %21
     i = %22
     goto while1
  label endWhile1 :
     %23 = 1000
     i = %23
  label while2 :
     %24 = 1003
     %25 = i < %24
     ifFalse %25 goto endWhile2
     %26 = 'b'
     writec %26
     %26 = '['
     writec %26
     %27 = 1000
     %28 = i - %27
     writei %28
     %29 = ']'
     writec %29
     %29 = '='
     writec %29
     %30 = 1000
     %31 = i - %30
     %32 = 1
     %32 = %32 * %31
     %33 = b[%32]
     writec %33
     writeln
     %35 = 1
     %36 = i + %35
     i = %36
     goto while2
  label endWhile2 :
     %37 = 'a'
     writec %37
     %37 = ')'
     writec %37
     %37 = ' '
     writec %37
     %37 = 'a'
     writec %37
     %37 = '.'
     writec %37
     %37 = 'm'
     writec %37
     %37 = 'a'
     writec %37
     %37 = 'x'
     writec %37
     %37 = '='
     writec %37
     %38 = 0
     %40 = 1
     %41 = a[%38]
     %42 = float %41
     %39 = %42
     %38 = %38 + %40
     %41 = a[%38]
     %38 = %38 + %40
     %43 = %39 <. %41
     ifFalse %43 goto false11
     %44 = %41
     %39 = float %44
  label false11 :
     %41 = a[%38]
     %38 = %38 + %40
     %45 = %39 <. %41
     ifFalse %45 goto false22
     %46 = %41
     %39 = float %46
  label false22 :
     %41 = a[%38]
     %38 = %38 + %40
     %47 = %39 <. %41
     ifFalse %47 goto false33
     %48 = %41
     %39 = float %48
  label false33 :
     %41 = a[%38]
     %38 = %38 + %40
     %49 = %39 <. %41
     ifFalse %49 goto false44
     %50 = %41
     %39 = float %50
  label false44 :
     %41 = a[%38]
     %38 = %38 + %40
     %51 = %39 <. %41
     ifFalse %51 goto false55
     %52 = %41
     %39 = float %52
  label false55 :
     writef %39
     writeln
     %54 = 'b'
     writec %54
     %54 = ')'
     writec %54
     %54 = ' '
     writec %54
     %54 = 'b'
     writec %54
     %54 = '.'
     writec %54
     %54 = 'm'
     writec %54
     %54 = 'a'
     writec %54
     %54 = 'x'
     writec %54
     %54 = '='
     writec %54
     %55 = 0
     %57 = 1
     %58 = b[%55]
     %59 = float %58
     %56 = %59
     %55 = %55 + %57
     %58 = b[%55]
     %55 = %55 + %57
     %60 = %56 <. %58
     ifFalse %60 goto false61
     %61 = %58
     %56 = float %61
  label false61 :
     %58 = b[%55]
     %55 = %55 + %57
     %62 = %56 <. %58
     ifFalse %62 goto false72
     %63 = %58
     %56 = float %63
  label false72 :
     writec %56
     writeln
     return
endfunction


