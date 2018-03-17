/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 15:10:15 by ayavorsk          #+#    #+#             */
/*   Updated: 2017/10/25 15:10:15 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int		space(const char *str)
{
	if (*str == '\n' || *str == '\t' || *str == '\r'
		|| *str == '\v' || *str == ' ' || *str == '\f')
		return (1);
	return (0);
}

long			ft_atoi(const char *str)
{
	int					i;
	unsigned long long	num;
	long long int		min;

	num = 0;
	i = 0;
	min = -1;
	while ((space(str)) == 1)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			min = 0;
		str++;
	}
	while (*str == '0')
		str++;
	while (*str >= '0' && *str <= '9' && i++ < 19)
		num = num * 10 + (long long int)(*str++ - '0');
	if (min == -1)
		return (num);
	else
		return (-num);
}
