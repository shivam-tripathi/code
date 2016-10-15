#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>

int main(int argc, char const *argv[]) {
	int sock_fd, new_sock_fd, port_no, cli_len;
	char buffer[256];
	struct sockaddr_in serv_addr, cli_addr;
	int n;
	sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(sock_fd < 0){
		perror("Error opening socket");
		exit(1);
	}
}
