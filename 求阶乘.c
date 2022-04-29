int FacRec(int i)
{
	if (i == 1)
		return i;
	else
		return i * FacRec(i - 1);
}
int FacNonRec(int i)
{
	int sum = 1;
	for (; i > 1; i--)
	{
		sum *= i;
	}
	return sum;
}
int main()
{
	int i = 0;
	scanf("%d", &i);
	int a = FacRec(i);
	int b = FacNonRec(i);
	printf("%d %d", a, b);
	return 0;
}