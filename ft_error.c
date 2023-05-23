/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:00:13 by lflandri          #+#    #+#             */
/*   Updated: 2022/10/25 11:04:23 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./LIBFT/libft.h"

void	ft_error(char *error_msg)
{
	ft_printf("%s\n", error_msg);
	exit(EXIT_FAILURE);
}