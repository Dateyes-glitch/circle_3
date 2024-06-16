#include "fractol.h"

int   ft_strlen(char *s)
{
  int i = -1;
  while (s[i++]);
  return i;
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	if (NULL == s1 || NULL == s2 || n <= 0)
		return (0);
	while (*s1 == *s2 && n > 0 && *s1 != '\0')
	{
		++s1;
		++s2;
		--n;
	}
	// chars are basically 1 byte int
	// 🚨 when 0, strings are equal !! 🚨
	return (*s1 - *s2);
}
/*
int   ft_strcmp(char *s1, char *s2)
{
  int i = 0;
  while ((s1[i] && s2[i]) && s1[i] == s2[i])
    i++;
  return (s1[i] - s2[i]);
}
*/
void  ft_putstr_fd(char *s, int fd)
{
  int i = 0;
  if (s == NULL || fd < 0)
    return ;
  if (s[i])
  {
    write(fd, s, 1);
    ft_putstr_fd(s + 1, fd);
  }
}

double	atodbl(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}
/*
double atodb(char *s)
{
  //todo: see where . is located in the string
  //if not in av[2] then input is discarded.
  //see if av[1] - '0' / 2 > 1 if so discard.
  //analyze way of converting to float

  long    int_part;
  double  frac_part;
  double  pow;
  int     sign;
  
  int_part = 0;
  frac_part = 0;
  sign += 1;
  pow = 1;
  while((*s >= 9 && *s <=13) || *s == 32)
    s++;
  while (*s == '+' || *s == '-')
    if (*s == '-')
      sign =  -sign;
  while (*s != '.' && *s)
    int_part = (int_part * 10) + (*s++ - 48);
    //int_part = (*s++ - 48); // --> could use this in my version since im checking first if before the dot is only one digit
  if (*s == '.')
    s++;
  while (*s)
  {
    pow = pow / 10;
    frac_part = frac_part + (*s++ - 48) * pow;
  }
  return ((double)((int_part + frac_part) * sign));
}
*/
