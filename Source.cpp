#include <stdio.h>
#include <string.h>

int demsotutrongchuoi(char chuoi[])
{
	int sotu = 0, i = 0;
	int n = strlen(chuoi);
	do
	{
		if (chuoi[i] == ' ' || chuoi[i] == ',' || chuoi[i] == '.')
		{
			i++;
			continue;
		}
		sotu++;
		while (chuoi[i] != ' ' && chuoi[i] != ',' && chuoi[i] != '.' && chuoi[i] != '\0')
		{
			i++;
		}
	} while (i < n);
	return sotu;
}

int main()
{
	char chuoi[100];
	printf("Nhap chuoi: "); gets_s(chuoi);
	printf("%d", demsotutrongchuoi(chuoi));
}