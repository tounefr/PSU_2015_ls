/*
** lists.h for  in /home/thomas/Documents/epitech/PSU_2015_my_ls
** 
** Made by Thomas Henon
** Login   <thomas.henon@epitech.eu>
** 
** Started on  Sun Nov 22 15:37:42 2015 Thomas Henon
** Last update Sun Nov 29 17:04:04 2015 Thomas Henon
*/

#ifndef __LISTS_H__
# define __LISTS_H__

typedef struct		s_list
{
  void			*datas;
  struct s_list		*next;
}			t_list;

char		init_list(t_list **list, void *datas);
char		prepend_list(t_list **list, void *datas);
char		append_list(t_list **list, void *datas);
int             nbr_elems_list(t_list *list);
char		remove_first_list(t_list **list);
char		remove_last_list(t_list **list);
char		get_index_list(t_list *list, unsigned int index);
unsigned int	nbr_elems_list(t_list *list);

#endif
