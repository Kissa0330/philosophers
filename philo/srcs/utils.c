/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:02:25 by takanoraika       #+#    #+#             */
/*   Updated: 2022/10/02 19:18:02 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

long long	get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	output_log(int type, int ph_num, t_rule *rule)
{
	if (pthread_mutex_lock(&(rule->mutex_writing)) != 0)
		return ;
	if (type == TYPE_FORK)
		printf("%lld %d has taken a fork\n", get_timestamp(), ph_num);
	else if (type == TYPE_EAT)
		printf("%lld %d is eating\n", get_timestamp(), ph_num);
	else if (type == TYPE_SLEEP)
		printf("%lld %d is sleeping\n", get_timestamp(), ph_num);
	else if (type == TYPE_THINK)
		printf("%lld %d is thinking\n", get_timestamp(), ph_num);
	else if (type == TYPE_DIED)
		printf("%lld %d died\n", get_timestamp(), ph_num);
	if (pthread_mutex_unlock(&(rule->mutex_writing)) != 0)
		return ;
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
	while (*str == ' ' || *str == '\t' || *str == '\f' || *str == '\r'
		|| *str == '\n' || *str == '\v')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negativeflag = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if ((num * 10 + (*str - '0')) / 10 != num)
			return (overflow(negativeflag));
		num = num * 10 + (*str - '0');
		str++;
	}
	return ((int)num * negativeflag);
}
