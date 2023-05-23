/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_untils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:20:47 by lflandri          #+#    #+#             */
/*   Updated: 2022/10/27 16:56:47 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	ft_send_octet_pid(int pid, char octet[8])
{	
	int	i;
	int	kill_result;

	i = 0;
	while (i != 8)
	{	
		usleep(1500);
		if (octet[i])
			kill_result = kill(pid, SIGUSR2);
		else
			kill_result = kill(pid, SIGUSR1);
		if (kill_result == -1)
			ft_error("Erreur d'envoie d'octet\nVérifier votre PID\n╮(￣ω￣;)╭");
		i++;
	}
}

void	ft_send_pid(int pid, int mypid)
{
	int		rep;
	int		nb;
	char	octet[8];
	int		sleep_result;

	rep = sizeof(int);
	while (rep)
	{
		nb = mypid % 256;
		mypid = mypid / 256;
		ft_convert_c_octet((unsigned char) nb, octet);
		ft_send_octet_pid(pid, octet);
		rep--;
	}
	sleep_result = sleep(6);
	if (!sleep_result)
		ft_error("Délai d'attente de réponse du serveur dépassé RIP");
}

void	redir_signal(int i)
{
	(void) i;
}
