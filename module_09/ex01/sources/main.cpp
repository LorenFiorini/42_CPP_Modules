/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 23:56:41 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/22 06:31:41 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "Usage: ./RPN \"<expression>\"" << std::endl;
        return (1);
    }

    try {
        RPN rpn(argv[1]);
        std::cout << rpn << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
