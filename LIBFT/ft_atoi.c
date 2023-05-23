/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:09:36 by lflandri          #+#    #+#             */
/*   Updated: 2022/10/02 09:41:20 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int			sign;
	long int	nb;

	str = (char *) str;
	nb = 0;
	sign = 1;
	while (*str == 32 || (8 < *str && *str < 14))
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*(str++) == 45)
			sign = -1;
	}
	while (*str > 47 && *str < 58)
	{
		nb = (nb * 10) + (*str - 48);
		str++;
	}
	return (sign * nb);
}
