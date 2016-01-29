/*
** ls_display2.c for  in /home/thomas/Documents/epitech/PSU_2015_my_ls
** 
** Made by Thomas Henon
** Login   <thomas.henon@epitech.eu>
** 
** Started on  Sun Nov 29 18:28:18 2015 Thomas Henon
** Last update Sun Nov 29 20:31:59 2015 Thomas Henon
*/

#include "ls.h"

char	display_file_date_last_mod(t_file *file)
{
  char	*mdate;
  int	i;

  i = 0;
  mdate = ctime(&file->stat->st_mtime);
  while (mdate[i] != '\n')
    i++;
  mdate[i] = '\0';
  my_putstr(mdate);
  my_putchar(' ');
}

char	display_entry(t_root *root, t_file *file, t_opt_args *args)
{
  if (!args->l)
    {
      my_putstr(file->name);
      my_putchar('\n');
      return (1);
    }
  display_file_rights(file);
  my_put_nbr((unsigned int)file->stat->st_nlink);
  my_putchar(' ');
  display_file_owners(file);
  my_put_nbr((unsigned int)file->stat->st_size);
  my_putchar(' ');
  display_file_date_last_mod(file);
  my_putstr(file->name);
  my_putchar('\n');
}

char		display_files(t_list *roots, t_opt_args *args, char new_line)
{
  t_root	*root;
  t_file	*file;
  t_list	*files;

  while (roots != 0)
    {
      root = (t_root*)roots->datas;
      files = root->files;
      while (files != 0)
	{
	  file = (t_file*)files->datas;
	  display_entry(root, file, args);
	  files = files->next;
	}
      roots = roots->next;
    }
  if (new_line)
    my_putchar('\n');
}

char		display(t_list *roots, t_opt_args *args)
{
  t_list	*files;
  t_list	*directories;
  char		display_roots;
  char		n_line;

  get_files_directories(roots, &files, &directories, args);
  display_roots = (directories != 0 && directories->next != 0) ? 1 : 0;
  n_line = (nbr_elems_list(files) + nbr_elems_list(directories)) > 1 ? 1 : 0;
  if (files)
    display_files(files, args, n_line);
  if (directories)
    display_directories(directories, args, display_roots, n_line);
}
