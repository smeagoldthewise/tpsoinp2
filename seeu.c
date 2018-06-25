#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
//#include "unp.h"

char *smtp_server = "pop.orange.fr";
unsigned short port = 110;

unsigned char bufw[1025];
unsigned char bufr[1025];

char *user="billiottet.matthieu@orange.fr";
char *pass="Alemon71";

//char *pass=
int main()
{

	char* ip[100];
        unsigned long smtpAddr;

        struct in_addr **addr_list;
	struct hostent *he;

        if ((he = gethostbyname(smtp_server)) == NULL)
        {
                herror("gethostbyname");
                return 1;
        }
        //test zone
        addr_list = (struct in_addr **) he->h_addr_list;

        for(int j = 0 ; addr_list[j] != NULL ; j++)
        {
                strcpy(ip, inet_ntoa(*addr_list[j]));
        }

        printf("Smtp Adress is = %s \n", ip);


	struct sockaddr_in serverSockAddr;
	serverSockAddr.sin_port = htons(110);
	serverSockAddr.sin_family = AF_INET;
	serverSockAddr.sin_zero[8] = 0;

        inet_aton(smtp_server,&serverSockAddr.sin_addr.s_addr);


	//struct hostent *serverHostEnt;
	//unsigned long hostAddr;
	int sock = -1;
	sock = socket(AF_INET,SOCK_STREAM,0);

	printf("so : %d \n", sock);
	//hostAddr = inet_addr(smtp_server);
	//printf("value = %lu \n", hostAddr);
	int co = connect(sock, (struct sockaddr *)&serverSockAddr, sizeof(serverSockAddr));

	printf("co : %d \n", co);

	// Autentify

	autentify(sock);

	return 0;
}

void autentify(int socket)
{

	sprintf(bufw, "USER %s\r\n", user);
	writen(socket, bufr, 1025);
	n = readn(socket, bufr, 1024);
	test_ok(bufr,1);
}

int writen(int fd, char *ptr, int n)
{
	int nl, nw;
	nl = n;
	while( nl > 0)
	{
		nw = write(fd, ptr, nl);
		if( nw <= 0)
		{
			perror("error");
			return nw;
		}
    		nl -= nw;
		ptr += nw;
	}
	return(n-nl);
}

int readn(int fd, char *ptr, int n)
{
	int nl, nr;
        nl, n;
        while(nl > 0)
	{
		return nr;
	}
	else if(nr ==0) break;
	nl -= nr;
	ptr += nr;


}
