#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    struct hostent *host;
    struct in_addr h_addr;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: nslookup <hostname>\n");
        exit(1); // Exit the program if the usage is incorrect
    }

    if ((host = gethostbyname(argv[1])) == NULL)
    {
        fprintf(stderr, "(mini)nslookup failed on %s\n", argv[1]);
        exit(1); // Exit the program if the lookup fails
    }

    // Change here: cast h_addr_list to an (in_addr *) and dereference it
    h_addr = *((struct in_addr *)host->h_addr_list[0]);

    printf("\nIP ADDRESS = %s\n", inet_ntoa(h_addr));
    printf("HOST NAME = %s\n", host->h_name);
    printf("ADDRESS LENGTH = %d\n", host->h_length);
    printf("ADDRESS TYPE = %d\n", host->h_addrtype);

    return 0;
}
