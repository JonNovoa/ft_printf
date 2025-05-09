/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:17:12 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/05/09 16:09:36 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "ft_printf.h"

#include "ft_printf.h"


int	ft_puthex(unsigned long n, char format)
{
	int	count;
	char	*base;

	count = 0;
	if (format == 'p')
	{
		/* puntero NULL debe imprimirse como "(nil)" */
		if (n == 0)
			return (ft_putstr("(nil)"));
		/* prefijo 0x para punteros no NULL */
		count += ft_putstr("0x");
		base = "0123456789abcdef";
		/* recursión usando 'x' para no reimprimir el prefijo */
		if (n >= 16)
			count += ft_puthex(n / 16, 'x');
		count += ft_putchar(base[n % 16]);
		return (count);
	}
	/* formatos %x y %X */
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_puthex(n / 16, format);
	count += ft_putchar(base[n % 16]);
	return (count);
}



/*
 int main(void)
{
    unsigned long n = 3059;
    ft_puthex(n, 'x');  // Imprime 131 en minúsculas
    write(1, "\n", 1);
    
    ft_puthex(n, 'X');  // Imprime 131 en mayúsculas
    write(1, "\n", 1);

    return 0;
} */