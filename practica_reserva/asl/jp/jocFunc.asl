func f(a:int, b:int) : int
	var n: int
	n = a*b;
	return n;
endfunc

func v(m:int)
	m = 10;
endfunc

func main()
	
	var n,m,t:int
	n = 5;
	m = 4;
	t = f(n,m);
	v(m);
	write t;
	write "\n";
	write m;

endfunc