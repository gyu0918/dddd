#include <stdio.h>

int	main(void)
{
	int	i;
	int	result[28] = {0};

	i = 0;
	while ( i < 5)
	{
		scanf("%d", &result[i]);
		i++;
	}
	printf("%d\n", result[0]);
	printf("%d", result[1]);
}
