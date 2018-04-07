#include "server.hh"

/*--------- GLOBALS --------*/
int sock; /* stores socket file descriptor */
int err; /* used to store error vals form functions */

#define PORT 1337
#define BACKLOG 10  /* Passed to listen() */

/*------ END GLOBALS -------*/

void handle(int newsock)
{
	printf("RUNS");
	char * buf = (char *) malloc(1000);
	recv(newsock,(void *) buf, 1000, NULL );
	printf("%s",buf);
	free(buf);
}
 
int main(void)
{

	/* set up ip addr struct information */
	struct sockaddr_in ip_Addr;
	memset (&ip_Addr,0,sizeof(ip_Addr)); /*sets data to 0*/
	ip_Addr.sin_family = AF_INET;
	ip_Addr.sin_addr.s_addr = INADDR_ANY;
	ip_Addr.sin_port = htons( PORT);
	
	/* allocate socket */
	sock = socket(PF_INET, SOCK_STREAM, 0); /*TCP socket setup*/
	if (sock < 0){ /*error checking*/
		perror("socket");
		exit(-1);	
	}

	/* set socket options 
		1 == reuse port
	*/
	int optval = 1;
	err = setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (char *) &optval, sizeof(int));
	if( err == -1){	
        perror("setsockopt");
		exit(-1);
	}

	/* bind socket to IP addr and port */
	err = bind( sock, (struct sockaddr *) &ip_Addr, sizeof(ip_Addr) );
	if( err  == -1){	
        perror("bind");
		exit(-1);
	}

	/*put socket into listening mode*/
	err = listen( sock, BACKLOG);
	if (err == -1) {
		perror("listen");
		exit(-1);
	}

	int slave_Socket = 0;
    /* Main loop */
    while (1) {

		/* accept incoming connection */
		struct sockaddr_in slave_IP;
		int size = sizeof(slave_IP);
		slave_Socket = accept(sock,(struct sockaddr *)&slave_IP, (socklen_t*) & size);
		if( slave_Socket < 0){
			perror( "accept");
			exit(-1);
		}
        else {
            printf("Got a connection from %s on port %d\n", 
                    inet_ntoa(slave_IP.sin_addr), htons(slave_IP.sin_port));
            handle(slave_Socket);
			close(slave_Socket);
			printf("connection closed\n");
        }
    }
    return 0;
}
