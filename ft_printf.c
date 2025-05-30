/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:16:52 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/05/09 18:52:16 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_format(va_list args, const char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_unsigned(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_puthex(va_arg(args, unsigned int), format));
	else if (format == 'p')
		return (ft_puthex((unsigned long)va_arg(args, void *), 'p'));
	else if (format == '%')
		return (ft_percent());
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;
	int		tmp;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			tmp = ft_check_format(args, format[i + 1]);
			len += tmp;
			i += 2;
		}
		else
		{
			len += ft_putchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return (len);
}

/*#include <stdio.h>
int main(void)
{
	int n = 42;
	unsigned int un = -42;
	char c = '\0';
	char *s = NULL;
	char *ptr = "Test";
	int rlen1, rlen2 = 0;
	// Test 1: Mix
    rlen1 = ft_printf(
	"\033[0;33mTest Mix: %c %s %d %i %u %x %X %p %%\n\033[0m",
	c, s, n, n, un, n, n, s);
	rlen2 = ft_printf(
	"\033[0;32mTest Mix: %c %s %d %i %u %x %X %p %%\n\033[0m",
	c, s, n, n, un, n, n, s);
	printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);
	printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);
	printf("\n\n");
	// Test 2: Char
	rlen1 = ft_printf("\033[0;33mTest char: %c\n\033[0m", 'A');
	rlen2 = printf("\033[0;32mTest char: %c\n\033[0m", 'A');
	printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);
	printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);
	printf("\n\n");
	// Test 3: String
	rlen1 = ft_printf("\033[0;33mTest string: %s\n\033[0m", "mundo");
	rlen2 = printf("\033[0;32mTest string: %s\n\033[0m", "mundo");
	printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);
	printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);
	printf("\n\n");
	// Test 4: Hex minusculas
	rlen1 = ft_printf("\033[0;33mTest hex: %x\n\033[0m", 25555555);
	rlen2 = printf("\033[0;32mTest hex: %x\n\033[0m", 25555555);
	printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);
	printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);
	printf("\n\n");
	// Test 5: Puntero
	rlen1 = ft_printf("\033[0;33mTest ptr: %p\n\033[0m", ptr);
	rlen2 = printf("\033[0;32mTest ptr: %p\n\033[0m", ptr);
	printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);
	printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);
	printf("\n\n");
	// Test 6: Hex mayusculas
	rlen1 = ft_printf("\033[0;33mTest HEX: %X\n\033[0m", 255);
	rlen2 = printf("\033[0;32mTest HEX: %X\n\033[0m", 255);
	printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);
	printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);
	printf("\n\n");
	// Test 7: Decimal
	rlen1 = ft_printf("\033[0;33mTest dec: %d\n\033[0m", 777);
	rlen2 = printf("\033[0;32mTest dec: %d\n\033[0m", 777);
	printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);
	printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);
	printf("\n\n");
	// Test 8: Int
	rlen1 = ft_printf("\033[0;33mTest int: %i\n\033[0m", 777);
	rlen2 = printf("\033[0;32mTest int: %i\n\033[0m", 777);
	printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);
	printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);
	printf("\n\n");
	// Test 9: Unsigned int
	rlen1 = ft_printf("\033[0;33mTest uns: %u\n\033[0m", -0);
	rlen2 = printf("\033[0;32mTest uns: %u\n\033[0m", -0);
	printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);
	printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);
	printf("\n\n");
	// Test 10: Porcentaje
	rlen1 = ft_printf("\033[0;33mTest porcentaje: %r\n\033[0m");
	rlen2 = ft_printf("\033[0;32mTest porcentaje: %r\n\033[0m");
	printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);
	printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);
	printf("\n\n");
	// Test 11: Locura
	rlen1 = ft_printf(
	"\033[0;33mTest locura: %%%c%%%s%%%d%%%i%%%u\
	%%%x%%%X%%%%%%%c%%%s%%%d%%%i"
	"%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u\
	%%%x%%%X%%%% %c%%\n\033[0m",
	'A', "42", 42, 42, 42, 42, 42,
	'B', "-42", -42, -42, -42, -42, 42,
	'C', "0", 0, 0, 0, 0, 42, 0);
	rlen2 = printf("\033[0;32mtest locura: \
    %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%%%%c%%%s\
	%%%d%%%i%%%u%%%x%%%X%%%% \
    %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n\033[0m",
	'A', "42", 42, 42, 42, 42, 42,
	'B', "-42", -42, -42, -42, -42, 42,
	'C', "0", 0, 0, 0, 0, 42, 0);

    printf("\033[0;33mft_printf devolvió: %d\n\033[0m", rlen1);
	printf("\033[0;32mprintf devolvió: %d\n\033[0m", rlen2);
	printf("\n\n");
	return 0;
}*/