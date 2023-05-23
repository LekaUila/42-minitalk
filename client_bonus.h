/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:51:16 by lflandri          #+#    #+#             */
/*   Updated: 2022/10/27 17:12:52 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H
# include <sys/types.h>
# include <signal.h>
# include "./LIBFT/libft.h"

void	ft_error(char *error_msg);
void	ft_convert_c_octet(unsigned char c, char tab[8]);
void	ft_send_pid(int pid, int mypid);
void	redir_signal(int i);

#endif