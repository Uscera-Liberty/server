#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>

void error_msg(const char *msg) {
	fprintf(stderr, "%s;%d\n", msg, errno);
	//fprintf(stderr, "%s; error = %s(%d)\n", msg, strerror(errno), errno);
	exit(0);
}

int main() {
	struct sockaddr_in scd = {0};
	scd.sin_family = AF_INET;
	scd.sin_addr.s_addr = htonl(INADDR_ANY);
	scd.sin_port = htons(80);
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		error_msg("ERROR opening socket");
	int bind_num = bind(sockfd, (struct sockaddr *)&scd, sizeof(scd));
	if (bind_num < 0)
		error_msg("ERROR &_& ");
	if (listen(sockfd,5)<0)
		error_msg("ERROR listen");
	int len;
	memset(&scd, 0, sizeof(scd));
	if (accept(sockfd, (struct sockaddr *)&scd, &len)< 0)
		error_msg("ERROR accept");
	printf("Client %d accepted\n",ntohs(scd.sin_port));

		

}

