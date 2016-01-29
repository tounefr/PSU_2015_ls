/*
** my_putchar.c for my_putchar in /home/henon_t/rendu/Piscine_C_J03
** 
** Made by Thomas Henon
** Login   <henon_t@epitech.net>
** 
** Started on  Wed Sep 30 09:59:45 2015 Thomas Henon
** Last update Sat Nov 28 16:18:36 2015 Thomas Henon
*/

char	my_putchar(char c)
{
  write(1, &c, 1);
  return (1);
}
