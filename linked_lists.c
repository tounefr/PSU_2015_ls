/*
** lists.c for  in /home/thomas/Documents/epitech/CPE_2015_Pushswap
** 
** Made by Thomas Henon
** Login   <thomas.henon@epitech.eu>
** 
** Started on  Mon Nov 16 20:11:45 2015 Thomas Henon
** Last update Sun Nov 29 18:26:30 2015 Thomas Henon
*/

#include "ls.h"

char	init_list(t_list **list, void *datas)
{
  if (!(*list = malloc(sizeof(t_list))))
    return (0);
  (*list)->datas = datas;
  (*list)->next = 0;
  return (1);
}

char		prepend_list(t_list **list, void *datas)
{
  t_list	*elem;

  if (*list == 0)
    {
      if (!init_list(list, datas))
	return (0);
      return (1);
    }
  if (!init_list(&elem, datas))
    return (0);
  elem->next = *list;
  *list = elem;
  return (1);
}

char		append_list(t_list **list, void *datas)
{
  t_list	*elem;
  t_list	*tmp;

  if (*list == 0)
    {
      if (!init_list(list, datas))
	return (0);
      return (1);
    }
  if (!init_list(&elem, datas))
    return (0);
  tmp = *list;
  while (tmp->next != 0)
    tmp = tmp->next;
  tmp->next = elem;
  return (1);
}

char		remove_last_list(t_list **list)
{
  t_list	*last;
  t_list	*prev;

  if (*list == 0)
    return (1);
  last = *list;
  if (last->next == 0)
    {
      free (*list);
      *list = 0;
      return (1);
    }
  while (last->next != 0)
    {
      prev = last;
      last = last->next;
    }
  prev->next = 0;
  free(last);
  return (1);
}

char		remove_first_list(t_list **list)
{
  t_list	*first;

  if (*list == 0)
    return (1);
  first = *list;
  if (first->next == 0)
    {
      free (*list);
      *list = 0;
    }
  *list = (*list)->next;
  free(first);
  return (1);
}
