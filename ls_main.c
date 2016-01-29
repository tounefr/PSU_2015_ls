/*
** ls_main.c for  in /home/thomas/Documents/LS
** 
** Made by Thomas Henon
** Login   <thomas.henon@epitech.eu>
** 
** Started on  Sat Nov 28 16:29:52 2015 Thomas Henon
** Last update Sat Nov 28 16:30:26 2015 Thomas Henon
*/

#include "ls.h"

t_list		*ls_files(char *root_path)
{
  t_file	*file;
  t_list	*files;

  files = 0;
  if (init_t_file(&file, root_path, root_path))
    {
      if (file->is_dir)
	ls_dir(file, &files);
      else
	append_list(&files, file);
    }
  return (files);
}

char		ls_dir(t_file *dir_var, t_list **files)
{
  DIR		*s_dir;
  struct dirent *dirent_var;
  t_file	*file;

  s_dir = opendir(dir_var->name);
  my_malloc((void*)&dirent_var, sizeof(struct dirent));
  while ((dirent_var = readdir(s_dir)) != NULL)
    {
      if (init_t_file(&file, dir_var->name, dirent_var->d_name))
	{
	  if (my_strcmp(dirent_var->d_name, ".") &&
	      my_strcmp(dirent_var->d_name, ".."))
	    append_list(files, file);
	}
    }
  return (1);
}
