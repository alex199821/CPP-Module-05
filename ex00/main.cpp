/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 04:09:06 by macbook           #+#    #+#             */
/*   Updated: 2025/04/12 04:07:00 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// void	leaks(void)
// {
// 	system("leaks office");
// }

int	main(void)
{
	// atexit(leaks);
	try
    {
        Bureaucrat weakBureaucrat("Jane", 151);  // Will throw an exception
        std::cout << weakBureaucrat << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
	Bureaucrat specialBureaucrat("John", 23);
	std::cout << specialBureaucrat << std::endl;
	Bureaucrat bureaucrat;
	std::cout << bureaucrat << std::endl;
	try
	{
		bureaucrat.setGrade(1);
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Updated grade is: " << bureaucrat.getGrade() << std::endl;
	try
	{
		bureaucrat.incrementGrade();
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		bureaucrat.decrementGrade();
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "Updated grade is: " << bureaucrat.getGrade() << std::endl;
	std::cout << std::endl;
	try
	{
		bureaucrat.setGrade(151);
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "Updated grade is: " << bureaucrat.getGrade() << std::endl;
	std::cout << std::endl;
	return (0);
}