/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junggkim <junggkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:44:55 by junggkim          #+#    #+#             */
/*   Updated: 2022/11/27 20:17:55 by junggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

void	print_conversion(const char *format, va_list ap, int *len);
void	check_format(const char *format, va_list ap, int *len);
int		ft_printf(const char *format, ...);
void	ft_memory(size_t address, int *len);
void	ft_hexa(unsigned int x, char xx, int *len);
void	ft_unsigned_int(unsigned int u, int *len);
void	ft_putstr(char *s, int *len);
void	ft_num(int number, int *len);

#endif
