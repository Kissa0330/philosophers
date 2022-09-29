/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:37:26 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/29 22:11:01 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	free_philos(t_philo *philo)
{
	size_t	i;

	if (philo->forks != NULL)
		free(forks);
	if (philo->rule != NULL)
		free(rule);
	while (i < philo->rule.n_o_p)
	{
		i ++;
	}
	
}