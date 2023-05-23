/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:51:19 by lflandri          #+#    #+#             */
/*   Updated: 2022/10/27 12:16:40 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVEUR_H
# define SERVEUR_H
# define LEN_OCTET_U 32
# define LEN_SPEED_BUFFER 500
# include <sys/types.h>
# include <signal.h>
# include "./LIBFT/libft.h"

typedef struct s_message_data
{
	unsigned long long int	nbreceived;		
	unsigned int			nbchar;
	unsigned int			client;
	char					*content;
	char					octet[8];
}	t_message_data;

void	ft_error(char *error_msg);
int		ft_power(int nb, int p);
int		ft_convert_octet_nb(char tab[8]);
char	ft_convert_octet_char(char tab[8]);
void	ft_reset_t_message_data(t_message_data *data_msg, int b_send);
void	ft_receive_client(int signal, t_message_data *data_msg);
void	ft_create_counter_char(int signal, t_message_data *data_msg);

#endif