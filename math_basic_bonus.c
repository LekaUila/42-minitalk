/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:24:26 by lflandri          #+#    #+#             */
/*   Updated: 2022/10/27 11:38:57 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_power(int nb, int p)
{
	if (p > 0)
		return (nb * ft_power(nb, p - 1));
	if (p == 0)
		return (1);
	return (0);
}

char	ft_convert_octet_char(char tab[8])
{
	int		i;
	char	result;
	int		p_2;

	result = 0;
	i = 8;
	p_2 = 1;
	while (i)
	{
		i--;
		result += tab[i] * p_2;
		p_2 = p_2 * 2;
	}
	return (result);
}

int	ft_convert_octet_nb(char tab[8])
{
	int		i;
	int		result;
	int		p_2;

	result = 0;
	i = 8;
	p_2 = 1;
	while (i)
	{
		i--;
		result += tab[i] * p_2;
		p_2 = p_2 * 2;
	}
	return (result);
}

void	ft_convert_c_octet(unsigned char c, char tab[8])
{
	int	i;
	int	result;

	result = 0;
	i = 0;
	while (i != 8)
	{
		tab[i] = 0;
		i++;
	}
	while (c)
	{
		i--;
		result = c % 2;
		c = c / 2;
		if (result)
			tab[i] = 1;
	}
}
