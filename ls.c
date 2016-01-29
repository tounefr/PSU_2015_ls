/*
** ls.c for  in /home/thomas/Documents/LS
** 
** Made by Thomas Henon
** Login   <thomas.henon@epitech.eu>
** 
** Started on  Fri Nov 27 17:09:47 2015 Thomas Henon
** Last update Sun Nov 29 19:54:53 2015 Thomas Henon
*/

#include "ls.h"

int		my_ls(t_opt_args *args, t_list *opt_files)
{
  t_list	*roots;
  t_root	*root;
  t_file	*file;

  roots = 0;
  while (opt_files != 0)
    {
      root = 0;
      my_malloc((void*)&file, sizeof(t_file));
      my_malloc((void*)&root, sizeof(t_root));
      if (init_t_file(&file, (char*)opt_files->datas,
		      (char*)opt_files->datas))
	{
	  root->infos = file;
	  root->size_padding = 0;
	  root->root_name = (char*)opt_files->datas;
	  root->files = ls_files((char*)opt_files->datas);
	  append_list(&roots, (void*)root);
	}
      opt_files = opt_files->next;
    }
  sort_files(roots, args);
  display(roots, args);
}

int		main(int argc, char **argv)
{
  t_opt_args	*opt_args;
  t_list	*opt_files;

  set_opt_args(argc, argv, &opt_args);
  set_opt_files(argc, argv, &opt_files);
  my_ls(opt_args, opt_files);
  return (0);
}
