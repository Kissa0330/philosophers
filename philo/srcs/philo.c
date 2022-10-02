/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:17:31 by takanoraika       #+#    #+#             */
/*   Updated: 2022/10/02 19:18:33 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	take_fork(t_philo *philo)
{
}

void	eat_pasta(t_philo *philo)
{
}

void	get_sleep(t_philo *philo)
{
}

int	philo_life(void *philo_ptr)
{
	t_philo	*philo;

	philo = philo_ptr;
	if (philo->id % 2 != 0)
		usleep(1000);
	while (1)
	{
		eat_pasta(philo);
		get_sleep(philo);
		output_log(TYPE_THINK, philo->forks, philo->ptr_rule);
	}
	return (0);
}
