#define _WITH_GETLINE
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



int main() {

	FILE   *descpipe;
	char   buf[2048];
	size_t bufsize = 80;
	size_t chars=2048;
	char command[100];
/*	printf("Napisz zdanie:\n");
	chars = getline(&buf, &bufsize, stdin);
								
	printf("Uruchamiam wc by policzyc ile slow napisales:\n");
*/
	strcpy(command, "ls -la");

	descpipe = popen(command,"r");
										
	if(descpipe != NULL) {
												
		fread(buf,sizeof(char),chars,descpipe);
			
		printf("%s\n",buf);
		
		fclose(descpipe);
	}
											
										return 0;
}