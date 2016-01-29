/*
** ls_sort.c for  in /home/thomas/Documents/LS
** 
** Made by Thomas Henon
** Login   <thomas.henon@epitech.eu>
** 
** Started on  Sat Nov 28 16:29:10 2015 Thomas Henon
** Last update Sun Nov 29 18:25:25 2015 Thomas Henon
*/

#include "ls.h"

char		sort_by_mod_time(t_list *files)
{
  t_list	*first;
  char		sorted;
  t_file	*tmp;

  first = files;
  sorted = 0;
  while (!sorted)
    {
      sorted = 1;
      while (files->next != 0)
	{
	  if (((t_file*)files->datas)->stat->st_mtime <
	      ((t_file*)files->next->datas)->stat->st_mtime)
	    {
	      tmp = files->datas;
	      files->datas = files->next->datas;
	      files->next->datas = tmp;
	      sorted = 0;
	    }
	  files = files->next;
	}
      files = first;
    }
}

char		sort_reverse(t_list **files)
{
  t_list	*next;
  t_list	*prev;

  prev = 0;
  while (*files != 0)
    {
      next = (*files)->next;
      (*files)->next = prev;
      prev = *files;
      *files = next;
    }
}

void	sort_files(t_list *roots, t_opt_args *args)
{
  t_root *root;
  t_list *files;

  while (roots != 0)
    {
      root = (t_root*)roots->datas;
      files = (t_list*)root->files;
      if (args->t)
	sort_by_mod_time(files);
      if (args->r)
	sort_reverse(&files);
      roots = roots->next;
    }
}
