/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:47:28 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/29 22:26:48 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	dead_monit(void *philo_ptr)
{
	t_philo	*philo;

	philo = philo_ptr;
	printf("somebody is dead");
	philo->rule->died = 1;
}