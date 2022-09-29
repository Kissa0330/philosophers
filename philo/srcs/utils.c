/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:02:25 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/29 20:43:35 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

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

static int	overflow(int negativeflag)
{
	if (negativeflag == -1)
		return (0);
	else
		return (-1);
}

int	ft_atoi(const char *str)
{
	int				negativeflag;
	unsigned int	num;

	num = 0;
	negativeflag = 1;
	while (*str == ' ' || *str == '\t' || *str == '\f'
		|| *str == '\r' || *str == '\n' || *str == '\v')
		str ++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negativeflag = -1;
		str ++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if ((num * 10 + (*str - '0')) / 10 != num)
			return (overflow(negativeflag));
		num = num * 10 + (*str - '0');
		str ++;
	}
	return ((int)num * negativeflag);
}
