/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:02:25 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/28 18:26:37 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void output_log(int type, int ph_num)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	if (type == 1)
		printf("%ld%d %d has taken a fork\n",tv.tv_sec, tv.tv_usec / 1000, ph_num);
	else if (type == 2)
		printf("%ld%d %d is eating\n",tv.tv_sec, tv.tv_usec / 1000, ph_num);
	else if (type == 3)
		printf("%ld%d %d is sleeping\n",tv.tv_sec, tv.tv_usec / 1000, ph_num);
	else if (type == 4)
		printf("%ld%d %d is thinking\n",tv.tv_sec, tv.tv_usec / 1000, ph_num);
	else if (type == 5)
		printf("%ld%d %d died\n",tv.tv_sec, tv.tv_usec / 1000, ph_num);
}