#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define bool int
#define true 1
#define false 0

inline void ersolve(char* str, bool verbose)
{
  struct hostent* hp;
  struct in_addr sin_addr;
  char* ip;
  char* hostname;
  hp=gethostbyname(str);
  if (hp)
  {
    hostname=hp->h_name;
    if (hp->h_length>(int)sizeof(sin_addr)) 
      hp->h_length=sizeof(sin_addr);
    memcpy(&sin_addr,hp->h_addr,hp->h_length);
    ip=inet_ntoa(sin_addr);    
    hp = gethostbyaddr((char*)&sin_addr.s_addr, sizeof(sin_addr.s_addr), AF_INET);
    hostname = hp?hp->h_name:inet_ntoa(sin_addr);
    printf("%s == %s",hostname,ip);
    if (verbose)
      printf(" ( %s )",str);
    printf("\n");
  }
  else
  {
    printf("%s [!]\n",str);
    return;
  }
}

void usage(void)
{
  fprintf(stderr,"Usage: ersolve [-v] <host>...\n\n");
  exit(EXIT_FAILURE);
}

int main(int argc, char** argv)
{
  bool verbose;
  if (argc<=1)
    usage();
  argv++;
  if (!strcmp(*argv,"-v"))
  {
    verbose=true;
    argv++;
  }
  else
    verbose=false;
  if (!*argv)
    usage();
  while(*argv)
  {
    ersolve(*argv,verbose);
    argv++;
  }
}
