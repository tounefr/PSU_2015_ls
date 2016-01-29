/*
** ls.h for  in /home/thomas/Documents/LS
** 
** Made by Thomas Henon
** Login   <thomas.henon@epitech.eu>
** 
** Started on  Fri Nov 27 17:10:12 2015 Thomas Henon
** Last update Sun Nov 29 20:21:44 2015 Thomas Henon
*/

#ifndef __MY_LS_H__
#define __MY_LS_H__

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <dirent.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "my.h"

typedef struct	s_opt_args
{
  char		l;
  char		d;
  char		r;
  char		R;
  char		t;
}		t_opt_args;

typedef struct	s_list
{
  void		*datas;
  struct s_list	*next;
}		t_list;

typedef struct	s_file
{
  char		*name;
  char		is_dir;
  struct stat	*stat;
}		t_file;

typedef struct	s_root
{
  char		*root_name;
  t_list	*files;
  t_file	*infos;
  unsigned int	size_padding;
  unsigned int	total_size;
}		t_root;

/*
** ls_args.c
*/
void	init_args(t_opt_args *);
void	set_opt_arg(t_opt_args *, char);
void	set_opt_args(int, char **, t_opt_args **);
void	set_opt_files(int, char **, t_list **);

/*
** ls.c
*/
int	my_ls(t_opt_args *, t_list *);
int	main(int, char **);

/*
** ls_details.c
*/
char		get_files_directories(t_list *, t_list **, t_list **, t_opt_args *);
int		get_total_size(t_root *);
char		init_t_file(t_file **, char *, char *);

/*
** ls_display.c
*/
char		display_directories(t_list *, t_opt_args *, char, char);
char		display_file_type(mode_t);
char		display_file_rights(t_file *);
char		display_file_owners(t_file *);
char		display_total_size(t_root *, t_opt_args *);
char		display_file_date_last_mod(t_file *);
char		display_entry(t_root *, t_file *, t_opt_args *);
char		display_files(t_list *, t_opt_args *, char);
char		display(t_list *, t_opt_args *);

/*
** ls_main.c
*/
t_list		*ls_files(char *);
char		ls_dir(t_file *, t_list **);

/*
** ls_sort.c
*/
char		sort_by_mod_time(t_list *);
char		sort_reverse(t_list **);
void		sort_files(t_list *, t_opt_args *);

/*
** ls_util.c
*/
void	my_putstr_error(char *);
void	my_malloc(void **, int);
char	*format_path(char *, char *);
char	*my_strcat(char *, char *);
char	is_hidden_file(t_file *);


#endif
