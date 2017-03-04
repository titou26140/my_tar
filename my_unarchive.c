/*
** my_unarchive.c for tar in /home/timothe/Documents/Epitech/Semestre 2/rush/my_tar/
**
** Made by Timothe Duc
** Login   <timothe.duc@epitech.eu>
**
** Started on  Sat Mar  4 00:02:27 2017 Timothe Duc
** Last update Sat Mar  4 02:08:34 2017 Timothe Duc
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char *name_file(char *str)
{
  char *new_str;
  int i;

  new_str = malloc(strlen(str));
  i = 0;
  while (i < strlen(str) - 1)
  {
    new_str[i] = str[i];
    i = i + 1;
  }
  return (new_str);
}

int main(int ac, char **av)
{
  FILE *file;
  FILE *archive;
  char *buffer;
  char *name;
  int i;

  buffer = malloc(1025);
  if (ac < 2)
  {
    write(2, "Invalid arguments\n", 18);
    return (84);
  }
  if ((archive = fopen(av[1], "r")) == NULL)
  {
    write(2, "Unable to open file\n", 20);
    return (84);
  }
  else
  {
    while (fgets(buffer, 1024, archive) && buffer != NULL)
    {
      name = name_file(buffer);
      file = fopen(name, "w");
      i = 0;
      while (fgets(buffer, 1024, archive) && strcmp(buffer, "*\n") != 0)
      {
        fprintf(file, "%s", buffer);
      }
    }
    return (0);
  }
}
