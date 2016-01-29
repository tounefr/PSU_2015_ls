/*
** ls_util.c for  in /home/thomas/Documents/LS
** 
** Made by Thomas Henon
** Login   <thomas.henon@epitech.eu>
** 
** Started on  Sat Nov 28 16:28:40 2015 Thomas Henon
** Last update Wed Dec  2 15:28:19 2015 Thomas Henon
*/

#include "ls.h"

void	my_putstr_error(char *str)
{
  write(2, str, my_strlen(str));
}

void	my_malloc(void **ptr, int size)
{
  if (!(*ptr = malloc(size)))
    {
      my_putstr_error("Malloc error\n");
      exit(1);
    }
}

char *format_path(char *root, char *file)
{
  char *str;
  int i;
  int i2;

  i = -1;
  my_malloc((void*)&str, my_strlen(root) + my_strlen(file) + 2);
  while (root[++i] != 0)
    str[i] = root[i];
  if (root[i-1] != '/')
    str[i++] = '/';
  i2 = 0;
  if (*file == '/')
    file++;
  while (i2 < my_strlen(file))
    {
      str[i] = file[i2];
      i++;
      i2++;
    }
  str[i] = 0;
  return (str);
}

char		*my_strcat(char *str1, char *str2)
{
  char		*str3;
  unsigned int	i;
  unsigned int	i2;

  if (!(str3 = malloc(my_strlen(str1) + my_strlen(str2) + 1)))
    return (0);
  i = 0;
  i2 = 0;
  while (i2 < my_strlen(str1))
    {
      str3[i] = str1[i2];
      i++;
      i2++;
    }
  i2 = 0;
  while (i2 < my_strlen(str2))
    {
      str3[i] = str2[i2];
      i++;
      i2++;
    }
  str3[i] = '\0';
  return (str3);
}

char	is_hidden_file(t_file *file)
{
  if (!file->name)
    return (0);
  if (file->name[0] == '.')
    return (1);
  return (0);
}
