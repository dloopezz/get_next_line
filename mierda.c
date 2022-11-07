#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <fcntl.h> 
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int main()
{
	int fd = 0;
	char	*buf;
    int readed;
	
	fd = open("test.txt", fd, O_RDONLY);
	buf = malloc(sizeof(char) * (20));
	if (!buf)
		return (0);
	readed = read(fd, buf, 6);
	printf("1: %s\n", buf);
	readed = read(fd, buf, 6);
	printf("2: %s\n", buf);
    readed = read(fd, buf, 3);
	printf("3: %s\n", buf);
	return (0);
}
