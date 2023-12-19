/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:02:35 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/11 16:15:45 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main(void)
{
	try {
		MutantStack<int> stk;

		stk.push(5);
		stk.push(17);

		std::cout << stk.top() << std::endl;
		stk.pop();
		std::cout << stk.size() << std::endl;

		stk.push(3);
		stk.push(5);
		stk.push(737);

		MutantStack<int>::iterator it = stk.begin();
		MutantStack<int>::iterator jt = stk.end();

		++it;
		--it;
		while (it != jt) {
			std::cout << *it << std::endl;
			++it;
		}

		std::stack<int> s(stk);
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		MutantStack< int, std::vector<int> > stk;

		stk.push(25);
		stk.push(17);

		std::cout << stk.top() << std::endl;
		stk.pop();
		std::cout << stk.size() << std::endl;

		stk.push(3);
		stk.push(45);
		stk.push(7);

		MutantStack< int, std::vector<int> >::iterator it = stk.begin();
		MutantStack< int, std::vector<int> >::iterator jt = stk.end();

		++it;
		--it;
		while (it != jt) {
			std::cout << *it << std::endl;
			++it;
		}

		std::stack< int, std::vector<int> > s(stk);
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		MutantStack< int, std::list<int> > stk;

		stk.push(3);
		stk.push(1);

		std::cout << stk.top() << std::endl;
		stk.pop();
		std::cout << stk.size() << std::endl;

		stk.push(33);
		stk.push(54);
		stk.push(7327);

		MutantStack< int, std::list<int> >::iterator it = stk.begin();
		MutantStack< int, std::list<int> >::iterator jt = stk.end();

		++it;
		--it;
		while (it != jt) {
			std::cout << *it << std::endl;
			++it;
		}

		std::stack< int, std::list<int> > s(stk);
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return (0);
}
