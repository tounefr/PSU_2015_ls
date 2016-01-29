/*
** ls_display.c for  in /home/thomas/Documents/LS
** 
** Made by Thomas Henon
** Login   <thomas.henon@epitech.eu>
** 
** Started on  Sat Nov 28 16:26:22 2015 Thomas Henon
** Last update Sun Nov 29 20:34:05 2015 Thomas Henon
*/

#include "ls.h"

char		display_directories(t_list *roots, t_opt_args *args,
				    char display_root, char new_line)
{
  t_root	*root;
  t_file	*file;
  t_list	*files;

  while (roots != 0)
    {
      root = (t_root*)roots->datas;
      display_total_size(root, args);
      if (display_root)
	{
	  my_putstr(root->root_name);
	  my_putstr(":\n");
	}
      files = root->files;
      while (files != 0)
	{
	  file = (t_file*)files->datas;
	  display_entry(root, file, args);
	  files = files->next;
	}
      if (new_line && roots->next != 0)
	my_putchar('\n');
      roots = roots->next;
    }
}

char	display_file_type(mode_t st_mode)
{
  if (S_ISDIR(st_mode))
    my_putchar('d');
  else
    my_putchar('-');
}

char	display_file_rights(t_file *file)
{
  display_file_type(file->stat->st_mode);
  my_putchar(((S_IRUSR & file->stat->st_mode) ? 'r' : '-'));
  my_putchar(((S_IWUSR & file->stat->st_mode) ? 'w' : '-'));
  my_putchar(((S_IXUSR & file->stat->st_mode) ? 'x' : '-'));
  my_putchar(((S_IRWXG & file->stat->st_mode) ? 'r' : '-'));
  my_putchar(((S_IWGRP & file->stat->st_mode) ? 'w' : '-'));
  my_putchar(((S_IXGRP & file->stat->st_mode) ? 'x' : '-'));
  my_putchar(((S_IROTH & file->stat->st_mode) ? 'r' : '-'));
  my_putchar(((S_IWOTH & file->stat->st_mode) ? 'w' : '-'));
  my_putchar(((S_IXOTH & file->stat->st_mode) ? 'x' : '-'));
  my_putchar(' ');
}

char		display_file_owners(t_file *file)
{
  struct passwd *pwd;
  struct group	*grp;

  if (!(pwd = getpwuid(file->stat->st_uid)))
    perror(my_strcat("my_ls: ", "Cannot get file owners"));
  if (!(grp = getgrgid(file->stat->st_gid)))
    my_putstr(my_strcat("my_ls: ", "Cannot get file group"));
  if (!pwd || !grp)
    return (-1);
  my_putstr(pwd->pw_name);
  my_putchar(' ');
  my_putstr(grp->gr_name);
  my_putchar(' ');
}

char		display_total_size(t_root *root, t_opt_args *args)
{
  int		total_size;
  t_list	*files;
  t_file	*file;
  unsigned int	blocksize;

  if (!args->l)
    return (-1);
  total_size = 0;
  files = root->files;
  blocksize = 0;
  while (files != 0)
    {
      file = (t_file*)files->datas;
      if (file->name[0] != '.')
	blocksize += file->stat->st_blocks;
      files = files->next;
    }
  blocksize /= 2;
  my_putstr("total ");
  my_put_nbr(blocksize);
  my_putchar('\n');
}
