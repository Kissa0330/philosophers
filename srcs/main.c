/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:02:23 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/29 11:18:09 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	philo_init(int ac, char *av[], t_philo *philo_info)
{
	philo_info->n_o_p = ft_atoi(av[1]);
	if (philo_info->n_o_p < 1)
		return (-1);
	philo_info->t_t_d = ft_atoi(av[2]);
	if (philo_info->t_t_d < 1)
		return (-1);
	philo_info->t_t_e = ft_atoi(av[3]);
	if (philo_info->t_t_e < 1)
		return (-1);
	philo_info->t_t_s = ft_atoi(av[4]);
	if (philo_info->t_t_s < 1)
		return (-1);
	if (ac == 6)
	{
		philo_info->must_eat = ft_atoi(av[5]);
		if (philo_info->must_eat < 1)
			return (-1);
	}
	else
		philo_info->must_eat = -1;
	return (0);
}

void *philo_life(void *philo_info)
{
	return (philo_info);
}

int main(int ac, char *av[])
{
	pthread_t	handle;
	t_philo		philo_info;

	if (ac != 5 && ac != 6)
		return (-1);
	if (philo_init(ac, av, &philo_info) == -1)
		return (-1);
	printf("%d\n", philo_info.n_o_p);
	printf("%d\n", philo_info.t_t_d);
	printf("%d\n", philo_info.t_t_e);
	printf("%d\n", philo_info.t_t_s);
	printf("%d\n", philo_info.must_eat);
	// pthread_create(&handle, NULL, philo_life, &philo_info);
	// pthread_join(handle, NULL);
	return (0);
}
