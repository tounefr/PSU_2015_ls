/*
** ls_util2.c for  in /home/thomas/Documents/epitech/PSU_2015_my_ls
** 
** Made by Thomas Henon
** Login   <thomas.henon@epitech.eu>
** 
** Started on  Sun Nov 29 19:43:47 2015 Thomas Henon
** Last update Sun Nov 29 19:46:42 2015 Thomas Henon
*/

long long	my_ll_power_rec(long long nb, int power)
{
  if (power != 1)
    nb = nb * my_ll_power_rec(nb, (power - 1));
  else
    return (nb);
}

int	my_nbr_length(long long nbr)
{
  int	length;
  int	rangs;
  char	neg;

  if (nbr < 0)
    {
      neg = 1;
      nbr = -nbr;
    }
  else
    neg = 0;
  rangs = 19;
  while (rangs >= 0)
    {
      if ((nbr / my_ll_power_rec(10, rangs)) == 0)
	  rangs--;
      else
	return (rangs+neg+1);
    }
  return (rangs+neg+1);
}
