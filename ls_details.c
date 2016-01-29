/*
** ls_details.c for  in /home/thomas/Documents/LS
** 
** Made by Thomas Henon
** Login   <thomas.henon@epitech.eu>
** 
** Started on  Sat Nov 28 16:31:12 2015 Thomas Henon
** Last update Sun Nov 29 20:26:51 2015 Thomas Henon
*/

#include "ls.h"

char		get_files_directories(t_list *roots, t_list **files,
				      t_list **directories, t_opt_args *args)
{
  t_root	*root;

  *files = 0;
  *directories = 0;
  while (roots != 0)
    {
      root = (t_root*)roots->datas;
      if (S_ISDIR(root->infos->stat->st_mode))
	append_list(directories, root);
      else
	append_list(files, root);
      roots = roots->next;
    }
}

int		get_total_size(t_root *root)
{
  unsigned int	total_size;
  t_file	*file;

  total_size = 0;
  while (root->files != 0)
    {
      file = (t_file*)root->files->datas;
      total_size += (unsigned int)file->stat->st_size;
      root->files = root->files->next;
    }
  return (total_size);
}

char		init_t_file(t_file **file, char *root, char *name)
{
  struct stat	*stat_var;
  char		*path;

  my_malloc((void*)&stat_var, sizeof(struct stat));
  my_malloc((void*)file, sizeof(t_file));
  path = name;
  if (my_strcmp(root, name))
    path = format_path(root, name);
  if (lstat(path, stat_var) == -1)
    {
      perror(my_strcat("my_ls: ", name));
      return (0);
    }
  (*file)->name = name;
  (*file)->stat = stat_var;
  (*file)->is_dir = S_ISDIR(stat_var->st_mode);
  return (1);
}
