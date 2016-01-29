/*
** linked_lists2.c for  in /home/thomas/Documents/epitech/PSU_2015_my_ls
** 
** Made by Thomas Henon
** Login   <thomas.henon@epitech.eu>
** 
** Started on  Sun Nov 29 19:25:39 2015 Thomas Henon
** Last update Sun Nov 29 19:26:23 2015 Thomas Henon
*/

#include "ls.h"

char	nbr_elems_list(t_list *list)
{
  int	i;

  if (list == 0)
    return (0);
  i = 0;
  while (list != 0)
    {
      list = list->next;
      i++;
    }
  return (i);
}
