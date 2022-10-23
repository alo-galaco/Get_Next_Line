# include <unistd.h>
# include <stdio.h>

int	main ()
{
	FILE *p = open("poema.txt", O_RDONLY);
	char buffer[50];
	fgets(buffer, 50, p);
	printf("%s", buffer);
	fclose(p);
	return (0);
}
// {
// 	FILE *p = open("poema.txt", O_RDONLY);
// 	char buffer[5];
// 	while(fgets(buffer, 5, p) != NULL)
// 	{
// 		printf("%s", buffer);
// 	}
// 	fclose(p);
// 	return (0);
// }