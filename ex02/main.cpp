/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 04:08:02 by macbook           #+#    #+#             */
/*   Updated: 2025/04/11 22:43:43 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// void	leaks(void)
// {
// 	system("leaks office");
// }

int	main(void)
{
	// atexit(leaks);
	Bureaucrat juniorBureaucrat("Junior Bureaucrat", 150);
	std::cout << juniorBureaucrat << std::endl;
	std::cout << std::endl;
	Bureaucrat seniorBureaucrat("Senior Bureaucrat", 1);
	std::cout << seniorBureaucrat << std::endl;
	std::cout << std::endl;
	// ShrubberyCreationForm Tests
	std::string shrubberyTarget = "ShrubberyCreationForm";
	ShrubberyCreationForm ShrubberyCreationForm(shrubberyTarget);
	std::cout << std::endl;
	try
	{
		seniorBureaucrat.executeForm(ShrubberyCreationForm);
	}
	catch (const AForm::NotSignedException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		seniorBureaucrat.signAForm(ShrubberyCreationForm);
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		juniorBureaucrat.executeForm(ShrubberyCreationForm);
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		seniorBureaucrat.executeForm(ShrubberyCreationForm);
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	// RobotomyRequestForm Tests
	std::string robotomyTarget = "RobotomyRequestForm";
	RobotomyRequestForm RobotomyRequestForm(robotomyTarget);
	try
	{
		seniorBureaucrat.executeForm(RobotomyRequestForm);
	}
	catch (const AForm::NotSignedException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		seniorBureaucrat.signAForm(RobotomyRequestForm);
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		juniorBureaucrat.executeForm(RobotomyRequestForm);
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		seniorBureaucrat.executeForm(RobotomyRequestForm);
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	// PresidentialPardonForm Tests
	std::string presidentialTarget = "PresidentialPardonForm";
	PresidentialPardonForm PresidentialPardonForm(presidentialTarget);
	try
	{
		seniorBureaucrat.executeForm(PresidentialPardonForm);
	}
	catch (const AForm::NotSignedException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		seniorBureaucrat.signAForm(PresidentialPardonForm);
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		juniorBureaucrat.executeForm(PresidentialPardonForm);
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		seniorBureaucrat.executeForm(PresidentialPardonForm);
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}