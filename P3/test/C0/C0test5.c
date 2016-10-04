int a;

main()
{
	a=1;
	if (a==1) {a=2;} else {;}
	if (a!=1) {a=3;} else {;}
	return;
}

/*
但因为我所定义的C0中if后面必须跟着else所以在处理上会更简单，就不会出现上述问题，只需要把程序如下写即可。
int a;

main()
{
	a=1;
	if(a==1) {a=2;} else {a=3;}
	return;
}
*/
