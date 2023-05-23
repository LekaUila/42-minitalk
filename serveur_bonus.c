/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:01:35 by lflandri          #+#    #+#             */
/*   Updated: 2022/10/27 17:13:11 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur_bonus.h"

void	ft_add_char_to_malloc(t_message_data *data_msg, char *speed_buffer)
{
	char	*tempo;

	if (data_msg->content == NULL)
	{		
		data_msg->content = ft_calloc(1, 1);
		if (!(data_msg->content))
			ft_error("Erreur de création de Malloc.... (ﾒ￣▽￣)︻┳═一");
	}
	tempo = data_msg->content;
	data_msg->content = ft_strjoin(tempo, speed_buffer);
	free(tempo);
	if (!(data_msg->content))
		ft_error("Erreur de création de Malloc.... (ﾒ￣▽￣)︻┳═一");
}

void	ft_add_char_to_content(t_message_data *data_msg)
{
	static char	*speed_buffer = NULL;
	static int	count = 0;

	if (speed_buffer == NULL)
	{		
		speed_buffer = ft_calloc(1, LEN_SPEED_BUFFER + 1);
		if (!(speed_buffer))
			ft_error("Erreur de création de Malloc.... (ﾒ￣▽￣)︻┳═一");
	}
	speed_buffer[count] = ft_convert_octet_char(data_msg->octet);
	count++;
	data_msg->nbchar += -1;
	if (!(data_msg->nbchar) || count == LEN_SPEED_BUFFER)
	{
		ft_add_char_to_malloc(data_msg, speed_buffer);
		free(speed_buffer);
		speed_buffer = NULL;
		count = 0;
	}
}

void	ft_convert_message(int signal, t_message_data *data_msg)
{
	int		bit;

	if (signal == SIGUSR1)
		bit = 0;
	else
		bit = 1;
	data_msg->octet[data_msg->nbreceived % 8] = bit;
	if (data_msg->nbreceived % 8 == 7)
		ft_add_char_to_content(data_msg);
}

void	ft_signal_analyser(int signal)
{
	static t_message_data	data_msg = {0, 0, 0, 0, {0, 0, 0, 0, 0, 0, 0, 0}};

	if (!(data_msg.client))
	{
		ft_receive_client(signal, &data_msg);
		return ;
	}
	if (data_msg.nbreceived < sizeof(int) * 8)
		ft_create_counter_char(signal, &data_msg);
	else
		ft_convert_message(signal, &data_msg);
	data_msg.nbreceived += 1;
	usleep(25);
	if (!(data_msg.nbchar) && data_msg.nbreceived >= LEN_OCTET_U)
	{
		ft_printf("%s\n", data_msg.content);
		ft_reset_t_message_data(&data_msg, 1);
	}
	else if (kill(data_msg.client, SIGUSR1) == -1)
	{
		ft_reset_t_message_data(&data_msg, 0);
		ft_printf("Le client n'as pas reçu la réponse : Transfert Interrompu\n");
	}
}

int	main(void)
{
	pid_t		pid;

	pid = getpid();
	ft_printf("Voici mon jolie petit PID : %i (─‿‿─)\n", pid);
	signal(SIGUSR1, ft_signal_analyser);
	signal(SIGUSR2, ft_signal_analyser);
	while (1)
		sleep(42);
}
