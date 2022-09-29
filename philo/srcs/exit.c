/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:37:26 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/29 21:44:10 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	free_philos(t_philo *philo)
{
	size_t	i;

	if (philo->forks != NULL)
		free(forks);
	while (i < philo->rule.n_o_p)
	{
		i ++;
	}
	
}