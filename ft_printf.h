/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayegres- <ayegres@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 19:50:08 by ayegres            #+#    #+#            */
/*   Updated: 2024/04/11 20:08:49 by ayegres         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(char const *string, ...);
int	ft_write_int(int number);
int	ft_write_char(int character);
int	ft_write_string(char *str);
int	ft_write_hexadecimal(unsigned int number, char str);
int	ft_write_pointer(unsigned long long pointer);
int	ft_write_unsigned_int(unsigned int number);

#endif