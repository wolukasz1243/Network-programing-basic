#define _WITH_GETLINE
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

/* Brak obslugi bledow! */

int main() {

	int    fifodesc;
	char   *buf = NULL;
	char buff[200];
	size_t bufsize = 80;
	size_t chars;
	//pid_t ja=getpid();
	//int jaa=ja;
	//sprintf(buff,"%d",jaa);
	char *ss;




	

	printf("Klient: napisz komunikat ktory chcesz przeslac do serwera:\n");
	chars = getline(&buf, &bufsize, stdin);
	

	printf("Podaj swoja nazw(nie mozna uzywac spacji i znaku #):");

	scanf("%s",buff);
	buff[strlen(buff)]='#';
	buff[strlen(buff)+1]='\0';

//	printf("%s\n",buff);
	strcat(buff,buf);	

//	printf("%s\n",buff);


	fifodesc = open("/tmp/fifo_wolukasz", O_WRONLY);
	if(fifodesc != -1) {
	
		write(fifodesc, buff, sizeof(buff));
		close(fifodesc);

	}

	return 0;

}
