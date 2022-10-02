/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:47:28 by takanoraika       #+#    #+#             */
/*   Updated: 2022/10/02 19:19:44 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*dead_monitor(void *philo_ptr)
{
	t_philo	*philo;
	bool	is_died;

	philo = philo_ptr;
	if (pthread_mutex_lock(&(philo->monit_mutex)) != 0)
		return (NULL);
	if (is_died)
		output_log(TYPE_DIED, philo->num, philo->ptr_rule);
	if (pthread_mutex_unlock(&(philo->monit_mutex)) != 0)
		return (NULL);
	return (NULL);
}
