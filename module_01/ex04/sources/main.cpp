/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 08:46:26 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/17 09:00:12 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Create a program that takes three parameters in the following order: a filename and
two strings, s1 and s2.
It will open the file <filename> and copies its content into a new file
<filename>.replace, replacing every occurrence of s1 with s2.
Using C file manipulation functions is forbidden and will be considered cheating. All
the member functions of the class std::string are allowed, except replace. Use them
wisely!
Of course, handle unexpected inputs and errors. You have to create and turn in your
own tests to ensure your program works as expected
*/

#include <iostream>
#include <fstream>
#include <string>


int	main(int argc, char **argv)
{
	std::string		filename;
	std::string		s1;
	std::string		s2;
	std::string		line;
	std::ifstream	ifs;
	std::ofstream	ofs;

	if (argc != 4)
	{
		std::cerr << "Error: wrong number of arguments" << std::endl;
		std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	ifs.open(filename);
	if (!ifs.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		return (1);
	}
	ofs.open(filename + ".replace");
	if (!ofs.is_open())
	{
		std::cerr << "Error: could not create file" << std::endl;
		return (1);
	}
	while (std::getline(ifs, line))
	{
		// while (line.find(s1) != std::string::npos)
		// 	line.replace(line.find(s1), s1.length(), s2);
		// ofs << line << std::endl;
	}
	ifs.close();
	ofs.close();
	return (0);
}