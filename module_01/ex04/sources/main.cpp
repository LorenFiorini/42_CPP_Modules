/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 08:46:26 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/29 03:36:36 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	check_argc(int argc);
int check_words(std::string line, std::string s1, std::string s2);
int	check_input_file(std::ifstream &ifs);
int	check_output_file(std::ofstream &ofs);
int	replace_words(std::string filename, std::string s1, std::string s2);

int	main(int argc, char **argv)
{
	std::string		filename;
	std::string		s1;
	std::string		s2;

	if (check_argc(argc) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (replace_words(argv[1], argv[2], argv[3]) == EXIT_FAILURE)
		return (1);
	return (0);
}

int	check_argc(int argc)
{
	if (argc != 4)
	{
		std::cerr << "Error: wrong number of arguments" << std::endl;
		std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	replace_words(std::string filename, std::string s1, std::string s2)
{
	std::string		line;
	
	// Check the input file
	std::ifstream	ifs(filename);
	if (check_input_file(ifs) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	// Read the file
	std::getline(ifs, line, '\x1A');
	ifs.close();
	// Check the words
	if (check_words(line, s1, s2) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	// Create the output file
	std::ofstream	ofs(filename + ".replace");
	if (check_output_file(ofs) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	// Replace the words
	size_t i = line.find(s1, 0);
	while (i != std::string::npos)
	{
		line.erase(i, s1.length());
		line.insert(i, s2);
		i += s2.length();
		i = line.find(s1, i);
	}
	// Write the output file
	ofs << line;
	ofs.close();
	return (EXIT_SUCCESS);
}

int check_words(std::string line, std::string s1, std::string s2)
{
	if (line.empty())
	{
		std::cerr << "Error: file is empty" << std::endl;
		return (EXIT_FAILURE);
	}
	if (s1.empty())
	{
		std::cerr << "Error: empty string" << std::endl;
		return (EXIT_FAILURE);
	}
	if (s1 == s2)
	{
		std::cerr << "Error: s1 and s2 are the same" << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	check_input_file(std::ifstream &ifs)
{
	if (!ifs.is_open())
	{
		std::cerr << "Error: cannot open file" << std::endl;
		return (EXIT_FAILURE);
	}
	if (!ifs.good())
	{
		std::cerr << "Error: cannot read file" << std::endl;
		ifs.close();
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	check_output_file(std::ofstream &ofs)
{
	if (!ofs.is_open())
	{
		std::cerr << "Error: cannot open file" << std::endl;
		return (EXIT_FAILURE);
	}
	if (!ofs.good())
	{
		std::cerr << "Error: cannot write to file" << std::endl;
		ofs.close();
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}