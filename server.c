#include <stdio.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
    int soc, new_soc, fd, n;
    char buffer[1024], fname[50];
    struct sockaddr_in addr;
    soc = socket(AF_INET, SOCK_STREAM, 0);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(7891);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    bind(soc, (struct sockaddr *) &addr, sizeof(addr));
    printf("\nServer is Online");
    listen(soc, 5);
    new_soc = accept(soc, NULL, NULL);
    recv(new_soc, fname, 50, 0);
    printf("\nRequesting for file: %s\n", fname);
    fd = open(fname, O_RDONLY);
    if (fd < 0)
        send(new_soc, "\nFile not found\n", 15, 0);
    else
        while ((n = read(fd, buffer, sizeof(buffer))) > 0)
            send(new_soc, buffer, n, 0);
    printf("\nRequest sent\n");
    close(fd);
    return 0;
}
