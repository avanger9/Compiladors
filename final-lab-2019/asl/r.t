function main
  vars
    before 1
    a 10
    after 1
    i 1
  endvars

     %2 = 199
     before = %2
     %3 = 299
     after = %3
     %4 = 0
     %5 = 1
     %5 = %5 * %4
     %6 = 5
     a[%5] = %6
     %7 = 1
     %8 = 1
     %8 = %8 * %7
     %9 = 3
     a[%8] = %9
     %10 = 2
     %11 = 1
     %11 = %11 * %10
     %12 = 8
     a[%11] = %12
     %13 = 3
     %14 = 1
     %14 = %14 * %13
     %15 = 9
     a[%14] = %15
     %16 = 4
     %17 = 1
     %17 = %17 * %16
     %18 = 7
     a[%17] = %18
     %19 = 5
     %20 = 1
     %20 = %20 * %19
     %21 = 3
     a[%20] = %21
     %22 = 6
     %23 = 1
     %23 = %23 * %22
     %24 = 4
     a[%23] = %24
     %25 = 7
     %26 = 1
     %26 = %26 * %25
     %27 = 6
     a[%26] = %27
     %28 = 8
     %29 = 1
     %29 = %29 * %28
     %30 = 5
     a[%29] = %30
     %31 = 9
     %32 = 1
     %32 = %32 * %31
     %33 = 8
     a[%32] = %33
     %34 = 0
     i = %34
  label while1 :
     %35 = 10
     %36 = i < %35
     ifFalse %36 goto endWhile1
     %37 = 'a'
     writec %37
     %37 = '['
     writec %37
     writei i
     %38 = ']'
     writec %38
     %38 = '='
     writec %38
     %39 = 1
     %39 = %39 * i
     %40 = a[%39]
     writei %40
     writeln
     %42 = 1
     %43 = i + %42
     i = %43
     goto while1
  label endWhile1 :
     %44 = 'a'
     writec %44
     %44 = ')'
     writec %44
     %44 = ' '
     writec %44
     %44 = 'a'
     writec %44
     %44 = '.'
     writec %44
     %44 = 'm'
     writec %44
     %44 = 'a'
     writec %44
     %44 = 'x'
     writec %44
     %44 = '='
     writec %44
     %45 = 0
     %47 = 1
     %48 = a[%45]
     %46 = %48
     %45 = %45 + %47
     %48 = a[%45]
     %45 = %45 + %47
     %49 = %46 < %48
     ifFalse %49 goto false11
     %46 = %48
  label false11 :
     %48 = a[%45]
     %45 = %45 + %47
     %50 = %46 < %48
     ifFalse %50 goto false22
     %46 = %48
  label false22 :
     %48 = a[%45]
     %45 = %45 + %47
     %51 = %46 < %48
     ifFalse %51 goto false33
     %46 = %48
  label false33 :
     %48 = a[%45]
     %45 = %45 + %47
     %52 = %46 < %48
     ifFalse %52 goto false44
     %46 = %48
  label false44 :
     %48 = a[%45]
     %45 = %45 + %47
     %53 = %46 < %48
     ifFalse %53 goto false55
     %46 = %48
  label false55 :
     %48 = a[%45]
     %45 = %45 + %47
     %54 = %46 < %48
     ifFalse %54 goto false66
     %46 = %48
  label false66 :
     %48 = a[%45]
     %45 = %45 + %47
     %55 = %46 < %48
     ifFalse %55 goto false77
     %46 = %48
  label false77 :
     %48 = a[%45]
     %45 = %45 + %47
     %56 = %46 < %48
     ifFalse %56 goto false88
     %46 = %48
  label false88 :
     %48 = a[%45]
     %45 = %45 + %47
     %57 = %46 < %48
     ifFalse %57 goto false99
     %46 = %48
  label false99 :
     writei %46
     writeln
     %59 = 0
     %60 = 1
     %60 = %60 * %59
     %61 = 0
     %62 = 1
     %62 = %62 * %61
     %63 = a[%62]
     %64 = 5
     %65 = %63 * %64
     a[%60] = %65
     %66 = 'b'
     writec %66
     %66 = ')'
     writec %66
     %66 = ' '
     writec %66
     %66 = 'a'
     writec %66
     %66 = '.'
     writec %66
     %66 = 'm'
     writec %66
     %66 = 'a'
     writec %66
     %66 = 'x'
     writec %66
     %66 = '='
     writec %66
     %67 = 0
     %69 = 1
     %70 = a[%67]
     %68 = %70
     %67 = %67 + %69
     %70 = a[%67]
     %67 = %67 + %69
     %71 = %68 < %70
     ifFalse %71 goto false101
     %68 = %70
  label false101 :
     %70 = a[%67]
     %67 = %67 + %69
     %72 = %68 < %70
     ifFalse %72 goto false112
     %68 = %70
  label false112 :
     %70 = a[%67]
     %67 = %67 + %69
     %73 = %68 < %70
     ifFalse %73 goto false123
     %68 = %70
  label false123 :
     %70 = a[%67]
     %67 = %67 + %69
     %74 = %68 < %70
     ifFalse %74 goto false134
     %68 = %70
  label false134 :
     %70 = a[%67]
     %67 = %67 + %69
     %75 = %68 < %70
     ifFalse %75 goto false145
     %68 = %70
  label false145 :
     %70 = a[%67]
     %67 = %67 + %69
     %76 = %68 < %70
     ifFalse %76 goto false156
     %68 = %70
  label false156 :
     %70 = a[%67]
     %67 = %67 + %69
     %77 = %68 < %70
     ifFalse %77 goto false167
     %68 = %70
  label false167 :
     %70 = a[%67]
     %67 = %67 + %69
     %78 = %68 < %70
     ifFalse %78 goto false178
     %68 = %70
  label false178 :
     %70 = a[%67]
     %67 = %67 + %69
     %79 = %68 < %70
     ifFalse %79 goto false189
     %68 = %70
  label false189 :
     writei %68
     writeln
     %81 = 9
     %82 = 1
     %82 = %82 * %81
     %83 = 9
     %84 = 1
     %84 = %84 * %83
     %85 = a[%84]
     %86 = 0
     %87 = 1
     %87 = %87 * %86
     %88 = a[%87]
     %89 = %85 + %88
     a[%82] = %89
     %90 = 'c'
     writec %90
     %90 = ')'
     writec %90
     %90 = ' '
     writec %90
     %90 = 'a'
     writec %90
     %90 = '.'
     writec %90
     %90 = 'm'
     writec %90
     %90 = 'a'
     writec %90
     %90 = 'x'
     writec %90
     %90 = '='
     writec %90
     %91 = 0
     %93 = 1
     %94 = a[%91]
     %92 = %94
     %91 = %91 + %93
     %94 = a[%91]
     %91 = %91 + %93
     %95 = %92 < %94
     ifFalse %95 goto false191
     %92 = %94
  label false191 :
     %94 = a[%91]
     %91 = %91 + %93
     %96 = %92 < %94
     ifFalse %96 goto false202
     %92 = %94
  label false202 :
     %94 = a[%91]
     %91 = %91 + %93
     %97 = %92 < %94
     ifFalse %97 goto false213
     %92 = %94
  label false213 :
     %94 = a[%91]
     %91 = %91 + %93
     %98 = %92 < %94
     ifFalse %98 goto false224
     %92 = %94
  label false224 :
     %94 = a[%91]
     %91 = %91 + %93
     %99 = %92 < %94
     ifFalse %99 goto false235
     %92 = %94
  label false235 :
     %94 = a[%91]
     %91 = %91 + %93
     %100 = %92 < %94
     ifFalse %100 goto false246
     %92 = %94
  label false246 :
     %94 = a[%91]
     %91 = %91 + %93
     %101 = %92 < %94
     ifFalse %101 goto false257
     %92 = %94
  label false257 :
     %94 = a[%91]
     %91 = %91 + %93
     %102 = %92 < %94
     ifFalse %102 goto false268
     %92 = %94
  label false268 :
     %94 = a[%91]
     %91 = %91 + %93
     %103 = %92 < %94
     ifFalse %103 goto false279
     %92 = %94
  label false279 :
     writei %92
     writeln
     return
endfunction


