/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saksoy <saksoy@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:09:39 by saksoy            #+#    #+#             */
/*   Updated: 2022/02/24 14:30:52 by saksoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int ft_putstr(char *str)
{
    int i = 0;
    int len = 0;
    
    if(str == NULL)
    {
        return (ft_putstr("(null)"));
    }
    while(str[i])
    {
        len += write(1, &str[i], 1);
        i++;
    }
    return (len);
}

int ft_putnbr(long int number)
{
    int len = 0;
    if(number == -2147483648)
        return(ft_putstr("-2147483648"));
    if(number < 0)
    {
        len += write(1, "-", 1);
        number = number * -1;
    }
    if(number > 9)
        len += ft_putnbr(number/10);
    len += write(1, &"0123456789"[number%10], 1);
    return (len);
}

int ft_puthex(long int number)
{
    int len;
    if(number > 15)
        len += ft_puthex(number/16);
    len += write(1, &"0123456789abcdef"[number%16], 1);
    return (len);
}

int arg_printer(va_list macro, char c)
{
    if(c == 's')
        return (ft_putstr(va_arg(macro, char *)));
    if(c == 'd')
        return (ft_putnbr(va_arg(macro, int)));
    if(c == 'x')
        return (ft_puthex(va_arg(macro, unsigned int)));
    return (0);
}

int ft_printf(char *str, ...)
{
    va_list macro;
    int i = 0;
    int len = 0;
    
    va_start(macro, str);
    while(str[i])
    {
        if(str[i] == '%')
        {
            len += arg_printer(macro, str[i + 1]);
            i++;
        }
        else
            len += write(1, &str[i], 1);
        i++;
    }
    va_end(macro);
    return (len);
}
