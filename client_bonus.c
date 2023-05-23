/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:08:11 by lflandri          #+#    #+#             */
/*   Updated: 2022/10/27 17:52:12 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

void	ft_send_octet(int pid, char octet[8])
{	
	int	i;
	int	kill_result;
	int	sleep_result;

	i = 0;
	while (i != 8)
	{	
		if (octet[i])
			kill_result = kill(pid, SIGUSR2);
		else
			kill_result = kill(pid, SIGUSR1);
		i++;
		if (kill_result == -1)
			ft_error("Erreur d'envoie d'octet\nVérifier votre PID\n╮(￣ω￣;)╭");
		sleep_result = sleep(6);
		if (!sleep_result)
			ft_error("Délai d'attente de réponse du serveur dépassé...");
	}
}

void	ft_send_len_message(int pid, char *message)
{
	int		rep;
	int		nb;
	int		len;
	char	octet[8];

	len = ft_strlen(message);
	rep = sizeof(int);
	while (rep)
	{
		nb = len % 256;
		len = len / 256;
		ft_convert_c_octet((unsigned char) nb, octet);
		ft_send_octet(pid, octet);
		rep--;
	}
}

void	ft_send_message(int pid, char *message)
{
	char	tab[8];
	int		mypid;

	mypid = getpid();
	ft_send_pid(pid, mypid);
	ft_send_len_message(pid, message);
	while (*message)
	{
		ft_convert_c_octet((unsigned char) *message, tab);
		ft_send_octet(pid, tab);
		message++;
	}
	ft_printf("😏 Ceci est une confirmation de message ! 😏\n");
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
		ft_error("Nombre d'argument invalide.  (¯ . ¯٥)");
	pid = ft_atoi(av[1]);
	if (pid < 1)
		ft_error("PID invalide. ┐('～`;)┌");
	signal(SIGUSR1, redir_signal);
	ft_send_message(pid, av[2]);
}
