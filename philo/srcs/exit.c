/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:37:26 by takanoraika       #+#    #+#             */
/*   Updated: 2022/10/01 14:32:00 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	free_philos(t_philo *philo)
{
	int	i;
	int	n_o_p;

	n_o_p = philo->rule->n_o_p;
	if (philo->forks != NULL)
		free(philo->forks);
	if (philo->rule != NULL)
		free(philo->rule);
	i = 0;
	free(philo);
	// while (i < n_o_p)
	// {
	// 	i ++;
	// }
}