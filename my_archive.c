/*
** my_archive.c for my_tar in /home/timothe/Documents/Epitech/Semestre 2/rush/my_tar/
**
** Made by Timothe Duc
** Login   <timothe.duc@epitech.eu>
**
** Started on  Fri Mar  3 21:31:12 2017 Timothe Duc
** Last update Fri Mar  3 23:40:41 2017 Timothe Duc
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main (int ac, char **av)
{
  FILE *file;
  FILE *archive;
  int i;
  char *bufer;

  file = NULL;
  archive = NULL;
  i = 2;
  bufer = malloc(1025);
  if (ac < 3)
  {
    write(2, "Invalid arguments\n", 18);
    return (84);
  }
  archive = fopen(av[1], "a");
  while (av[i] != NULL)
  {
    if ((file = fopen(av[i], "r")) == NULL)
    {
      perror("Unable to open file");
      return (84);
    }
    else
    {
      while (fgets(bufer, 1024, file) != NULL)
        fprintf(archive, "%s", bufer);
    }
    fprintf(archive, "%s", "\n*\n");
    i = i + 1;
    fclose(file);
  }
  i = 2;
  while (av[i] != NULL)
  {
    remove(av[i]);
    i = i + 1;
  }
  return (0);
}
