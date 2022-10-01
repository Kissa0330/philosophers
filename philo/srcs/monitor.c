/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:47:28 by takanoraika       #+#    #+#             */
/*   Updated: 2022/10/01 15:00:32 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*dead_monit(void *philo_ptr)
{
	t_philo	*philo;

	philo = philo_ptr;
	printf("%d\n", philo->eat_time);
	// if (pthread_mutex_lock(&(philo->monit_mutex)) != 0)
	// 	return (NULL);
	usleep(500);
	output_log(5, philo->num);
	philo->rule->died = 1;
	// if (pthread_mutex_unlock(&(philo->monit_mutex)) != 0)
	// 	return (NULL);
	return (NULL);
}