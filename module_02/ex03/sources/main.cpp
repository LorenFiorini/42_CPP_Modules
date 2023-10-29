/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 06:14:50 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/29 09:33:29 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
    Point a;
    Point b(2, 2);
    Point c(4, -1);
    
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    
    Point d(b);
    std::cout << "\nd: " << d << std::endl;
    if (bsp(a, b, c, d))
        std::cout << "bsp(a, b, c, d): True. d is inside the triangle abc" << std::endl;
    else
        std::cout << "bsp(a, b, c, d): False. d is not inside the triangle abc" << std::endl;
    
    Point e = c;
    std::cout << "\ne: " << e << std::endl;
    if (bsp(a, b, c, e))
        std::cout << "bsp(a, b, c, e): True. e is inside the triangle abc" << std::endl;
    else
        std::cout << "bsp(a, b, c, e): False. e is not inside the triangle abc" << std::endl;  
        
    Point f(2, 1);
    std::cout << "\nf: " << f << std::endl;
    if (bsp(a, b, c, f))
        std::cout << "bsp(a, b, c, f): True. f is inside the triangle abc" << std::endl;
    else
        std::cout << "bsp(a, b, c, f): False. f is not inside the triangle abc" << std::endl;
    
    Point g(2, 0);
    std::cout << "\ng: " << g << std::endl;
    if (bsp(a, b, c, g))
        std::cout << "bsp(a, b, c, g): True. g is inside the triangle abc" << std::endl;
    else
        std::cout << "bsp(a, b, c, g): False. g is not inside the triangle abc" << std::endl;

    Point h(3, 12);
    std::cout << "\nh: " << h << std::endl;
    if (bsp(a, b, c, h))
        std::cout << "bsp(a, b, c, h): True. h is inside the triangle abc" << std::endl;
    else
        std::cout << "bsp(a, b, c, h): False. h is not inside the triangle abc" << std::endl;
    
    Point p(1, 1);
    std::cout << "\np: " << p << std::endl;
    if (bsp(a, b, c, p))
        std::cout << "bsp(a, b, c, p): True. p is inside the triangle abc" << std::endl;
    else
        std::cout << "bsp(a, b, c, p): False. p is not inside the triangle abc" << std::endl;
    return (0);
}
