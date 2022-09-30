/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:37:26 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/30 17:45:48 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	free_philos(t_philo *philo)
{
	// int	i;

	if (philo->forks != NULL)
		free(philo->forks);
	if (philo->rule != NULL)
		free(philo->rule);
	// while (i < philo->rule.n_o_p)
	// {
	// 	i ++;
	// }
}