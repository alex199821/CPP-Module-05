/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 04:08:02 by macbook           #+#    #+#             */
/*   Updated: 2025/04/11 04:08:04 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

// void	leaks(void)
// {
// 	system("leaks office");
// }

int	main(void)
{
	// atexit(leaks);
	Bureaucrat averageBureaucrat("Bureaucrat John", 43);
	std::cout << averageBureaucrat << std::endl;
	std::cout << std::endl;
	AForm standardForm("Standard AForm", 75, 75);
	std::cout << standardForm << std::endl;
	std::cout << std::endl;
	AForm preseidentialForm("Presidential AForm", 1, 1);
	std::cout << preseidentialForm << std::endl;
	std::cout << std::endl;
	try
	{
		averageBureaucrat.signAForm(preseidentialForm);
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		averageBureaucrat.signAForm(standardForm);
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}