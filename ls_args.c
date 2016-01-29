/*
** ls_args.c for  in /home/thomas/Documents/LS
** 
** Made by Thomas Henon
** Login   <thomas.henon@epitech.eu>
** 
** Started on  Sat Nov 28 16:25:19 2015 Thomas Henon
** Last update Sat Nov 28 16:25:28 2015 Thomas Henon
*/

#include "ls.h"

void init_args(t_opt_args *args)
{
  args->l = 0;
  args->d = 0;
  args->r = 0;
  args->R = 0;
  args->t = 0;
}

void set_opt_arg(t_opt_args *args, char flag)
{
  if (flag == 'l')
    args->l = 1;
  if (flag == 'd')
    args->d = 1;
  if (flag == 'r')
    args->r = 1;
  if (flag == 'R')
    args->R = 1;
  if (flag == 't')
    args->t = 1;
}

void	set_opt_args(int argc, char **argv, t_opt_args **args)
{
  int	i;
  int	i2;

  *args = 0;
  my_malloc((void*)args, sizeof(t_opt_args));
  i = 1;
  while (i < argc)
    {
      i2 = 0;
      if (argv[i][0] == '-')
	{
	  while (i2 < my_strlen(argv[i]))
	    {
	      set_opt_arg(*args, argv[i][i2]);
	      i2++;
	    }
	}
      i++;
    }
}

void	set_opt_files(int argc, char **argv, t_list **opt_files)
{
  int	i;

  *opt_files = 0;
  i = 1;
  while (i < argc)
    {
      if (argv[i][0] != '-')
	append_list(opt_files, argv[i]);
      i++;
    }
  if (*opt_files == 0)
    append_list(opt_files, ".");
}
