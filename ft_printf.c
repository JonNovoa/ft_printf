/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:16:52 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/05/05 14:36:43 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
    va_list	args;
    int		printed;
    int		i;

    va_start(args, format);
    printed = 0;
    i = 0;
    while (format[i])
    {
        if (format[i] == '%' && format[i + 1])
        {
            i++;
            if (format[i] == 'c')
                printed += ft_putchar(va_arg(args, int));
            else if (format[i] == 's')
                printed += ft_putstr(va_arg(args, char *));
            else if (format[i] == 'd' || format[i] == 'i')
                printed += ft_putnbr(va_arg(args, int));
            else if (format[i] == 'u')
                printed += ft_put_unsigned(va_arg(args, unsigned int));
            else if (format[i] == 'x' || format[i] == 'X')
                printed += ft_puthex(va_arg(args, unsigned int), format[i]);
            else if (format[i] == 'p')
            {
                printed += write(1, "0x", 2);
                printed += ft_puthex((unsigned long)va_arg(args, void *), 'x');
            }
            else if (format[i] == '%')
                printed += ft_handle_percent();
            else
                printed += ft_putchar(format[i]);
        }
        else
            printed += ft_putchar(format[i]);
        i++;
    }
    va_end(args);
    return (printed);
}