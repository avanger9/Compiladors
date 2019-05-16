func f(a:array[10] of int, b:array[10] of int)
	var i:int
	i = 0;
	
	write "\n";
	while i<10 do
		write i; write " ";
		a[i] = 5;
		b[i] = 3;
		write b[i]; write " ";
		i=i+1;
	endwhile
	write "\n";
	write i;
endfunc

func main()
	var i:int
	var a,b:array[10] of int
	i = 0;
	while i<10 do
		a[i] = 0;
		b[i] = 2;
		write a[i];
		write " ";
		i=i+1;
	endwhile
	write "\n";
	f(a,b);
	i=0;
	while i<10 do
		write a[i];
		write " ";
		i=i+1;
	endwhile
	write "\n";
endfunc