/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:35:19 by rlebaill          #+#    #+#             */
/*   Updated: 2025/03/03 15:06:12 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "usage: ./RPN <expression in reverse polish noatation>" << std::endl;
		return (1);
	}
	std::stack<int> stack;
	std::string input = av[1];
	int	a = 0;
	int	b = 0;
	for (int i = 0; i < (int)input.size(); i++)
	{
		if (i % 2 == 1 && input[i] != ' ')
		{
			std::cerr << "Error: bad input" << std::endl;
			return (1);
		}
		else if (i % 2 == 0 && !('0' <= input[i] && input[i] <= '9') && input[i] != '+'
		&& input[i] != '-' && input[i] != '*' && input[i] != '/')
		{
			std::cerr << "Error: bad input" << std::endl;
			return (1);
		}
		if ('0' <= input[i] && input[i] <= '9')
			a++;
		else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
			b++;
	}
	if (a != b + 1)
	{
		std::cerr << "Error: bad input" << std::endl;
		return (1);
	}
	for (int i = 0; i < (int)input.size(); i += 2)
	{
		if ('0' <= input[i] && input[i] <= '9')
			stack.push(input[i] - '0');
		else
		{
			int a;
			int b;
			a = stack.top();
			stack.pop();
			b = stack.top();
			stack.pop();
			if (input[i] == '+')
				stack.push(b + a);
			else if (input[i] == '-')
				stack.push(b - a);
			else if (input[i] == '*')
				stack.push(b * a);
			else
				stack.push(b / a);
		}
	}
	std::cout << stack.top() << std::endl;
	return (0);	
}
