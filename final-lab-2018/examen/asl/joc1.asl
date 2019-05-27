func f_read(x:array[2] of int, y:array[2] of int)
	var i:int
	i = 0;
	while i<2 do
		y[i] = 5;
		read x[i];
		i = i+1;
	endwhile
endfunc


func main()
	var a,b:array [2] of int
	var i:int
	f_read(a,b);	
	write a[0];
	write "\n";
	write b[0];
endfunc
