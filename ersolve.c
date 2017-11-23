/* Copyright © 2003-2017 Jakub Wilk <jwilk@jwilk.net>
 * SPDX-License-Identifier: MIT
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void ersolve(char* str, bool verbose)
{
  struct hostent* hp;
  struct in_addr sin_addr;
  char* ip;
  char* hostname;
  hp = gethostbyname(str);
  if (!hp)
  {
    printf("%s [!]\n",str);
    return;
  }
  hostname = hp->h_name;
  if (hp->h_length > sizeof sin_addr)
    hp->h_length = sizeof sin_addr;
  memcpy(&sin_addr, hp->h_addr, hp->h_length);
  ip = inet_ntoa(sin_addr);
  hp = gethostbyaddr((char*)&sin_addr.s_addr, sizeof sin_addr.s_addr, AF_INET);
  hostname = hp ? hp->h_name : inet_ntoa(sin_addr);
  printf("%s == %s", hostname, ip);
  if (verbose)
    printf(" ( %s )", str);
  printf("\n");
}

void usage(void)
{
  fprintf(stderr,"Usage: ersolve [-v] <host>...\n\n");
  exit(EXIT_FAILURE);
}

int main(int argc, char** argv)
{
  bool verbose;
  if (argc <= 1)
    usage();
  argv++;
  if (strcmp(*argv, "-v") == 0)
  {
    verbose = true;
    argv++;
  }
  else
    verbose = false;
  while (*argv != NULL)
  {
    ersolve(*argv, verbose);
    argv++;
  }
}

/* vim:set ts=2 sts=2 sw=2 et:*/
