/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur_untils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:44:09 by lflandri          #+#    #+#             */
/*   Updated: 2022/10/27 17:15:32 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void	ft_reset_t_message_data(t_message_data *data_msg, int b_send)
{
	int	pidclient;

	pidclient = data_msg->client;
	data_msg->nbchar = 0;
	data_msg->nbreceived = 0;
	data_msg->client = 0;
	if ((data_msg->content))
	{
		free(data_msg->content);
		data_msg->content = NULL;
	}
	if (b_send)
		kill(pidclient, SIGUSR1);
}

void	ft_create_counter_char(int signal, t_message_data *data_msg)
{
	int	bit;
	int	nb_r;
	int	nb;

	nb_r = data_msg->nbreceived;
	if (signal == SIGUSR1)
		bit = 0;
	else
		bit = 1;
	data_msg->octet[nb_r % 8] = bit;
	if (nb_r % 8 == 7)
	{
		nb = ft_convert_octet_nb(data_msg->octet);
		data_msg->nbchar += nb * ft_power(256, nb_r / 8);
	}
}

void	ft_create_client(int tab[LEN_OCTET_U], t_message_data *data_msg)
{
	char	tab_octet[8];
	int		bit;
	int		nb;
	int		count;

	count = 0;
	while (count != LEN_OCTET_U)
	{
		if (tab[count] == SIGUSR1)
			bit = 0;
		else
			bit = 1;
		tab_octet[count % 8] = bit;
		if (count % 8 == 7)
		{
			nb = ft_convert_octet_nb(tab_octet);
			data_msg->client += nb * ft_power(256, count / 8);
		}
		count++;
	}
	if (kill(data_msg->client, SIGUSR1) == -1)
	{
		ft_reset_t_message_data(data_msg, 0);
		ft_printf("ERREUR réponse PID : Transfert Interrompu\n");
	}
}

void	ft_receive_client(int signal, t_message_data *data_msg)
{
	static int		tab[LEN_OCTET_U];
	static int		count = 0;

	tab[count++] = signal;
	if (count == LEN_OCTET_U)
	{
		count = 0;
		ft_create_client(tab, data_msg);
	}
}
