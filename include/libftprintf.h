/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:16:19 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/01/23 14:16:20 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# define NOTHING		0
# define H				1
# define HH				2
# define J				3
# define Z				4
# define L				5
# define LL				6
# define HASH			7
# define ZERO			8
# define MINUS			9
# define PLUS			10
# define SPACE			11
# define APOSTROPHE		12
# define BASE_10		"0123456789"
# define BASE_16_UPPER	"0123456789ABCDEF"
# define BASE_16_LOWER	"0123456789abcdef"
# define ABS(x) ((x) < 0 ? -(x) : (x))
# include <wchar.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct		s_param
{
	const char		*str;
	size_t			length;
	int				flags[4];
	int				width;
	int				precision;
	int				modifier;
	char			conversion;
	int				error;
	int				precinit;
	int				star;
	int				precstar;
	int				fd_pf;
}					t_param;

int					ft_printf(const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);
char				*str_null(char *str, t_param *param);
int					ft_print_arg(t_param param, va_list list);
int					ft_is_valid(const char *str, size_t *i);
int					ft_pf_write(const char *str, int start, int end);
t_param				ft_fd_arg(const char *str,
					size_t len, va_list list, int fd);
t_param				ft_get_arg(const char *str, size_t len, va_list list);
intmax_t			ft_get_signed_nbr(t_param param, va_list list);
intmax_t			ft_get_unsigned_nbr(t_param param, va_list list);

int					ft_set_access(t_param *param, const char *str, size_t *i);
int					ft_set_width(t_param *param, const char *str,
					size_t *i, va_list list);
int					ft_set_precision(t_param *parse,
					const char *str, size_t *i, va_list list);
int					ft_set_modifier(t_param *arg, const char *str, size_t *i);
int					ft_set_flags(t_param *param, const char *str, size_t *i);

int					ft_p_char(t_param param, va_list list);
int					ft_print_integer(t_param param, intmax_t nbr);
int					ft_print_string(t_param param, char *str);
int					ft_print_hex(t_param param, int base, uintmax_t n);
int					ft_print_param(t_param pf, char *str);

int					check_flag(char c);
int					check_corect(const char c);
int					ft_atoi_printf(const char *str, size_t *i);
size_t				base_count(uintmax_t n, unsigned int base);

char				ft_putwchar(t_param pf, wchar_t w_char);
void				ft_put_wchar(t_param pf,
					unsigned char *ch_w, int size);
int					ft_wchar_str(wchar_t *wstr, t_param pf);
size_t				count_wchar(wchar_t *string, t_param pf, int what);
char				ft_print_wchar(unsigned char *ch_w,
					wchar_t w_char, t_param pf);

int					ft_isdigit(int ch);
int					ft_strlen(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
char				*ft_strchr(const char *string, int symbol);
char				*ft_strdup(const char *str);

int					ft_set_prec(t_param **param, int count, int n);
void				ft_set_prec_2(t_param **pf, int *count, int n);
int					ft_integer_null(t_param pf, int nbr);
int					width_string_3(char c, t_param pf, int len, int i);
#endif
