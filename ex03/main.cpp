/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 04:08:02 by macbook           #+#    #+#             */
/*   Updated: 2025/04/12 03:57:02 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	leaks(void)
{
	system("leaks office");
}

int	main(void)
{
	atexit(leaks);
	//Intern and Bureaucrat creation forms
	Intern intern;
	std::cout << std::endl;
	Bureaucrat seniorBureaucrat("Senior Bureaucrat", 1);
	std::cout << seniorBureaucrat << std::endl;
	std::cout << std::endl;
	// Form Creations
	AForm *robotomyForm = intern.makeForm("robotomy request", "robotomyTarget");
	AForm *presidentialForm = intern.makeForm("presidential pardon", "presidentialTarget");
	AForm *shrubberyForm = intern.makeForm("shrubbery creation", "shrubberyTarget");
	AForm *randomForm = intern.makeForm("random form", "randomTarget");
	std::cout << std::endl;
	// Robotomy Form Executions
	try
	{
		seniorBureaucrat.executeForm(*robotomyForm);
	}
	catch (const AForm::NotSignedException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		seniorBureaucrat.signAForm(*robotomyForm);
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	// Presidential Form Executions
	try
	{
		seniorBureaucrat.executeForm(*presidentialForm);
	}
	catch (const AForm::NotSignedException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		seniorBureaucrat.signAForm(*presidentialForm);
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		seniorBureaucrat.executeForm(*presidentialForm);
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	// Shrubbery Form Executions
	try
	{
		seniorBureaucrat.executeForm(*shrubberyForm);
	}
	catch (const AForm::NotSignedException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		seniorBureaucrat.signAForm(*shrubberyForm);
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		seniorBureaucrat.executeForm(*shrubberyForm);
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	delete shrubberyForm;
	delete presidentialForm;
	delete robotomyForm;
	if (randomForm)
		delete randomForm;
	return (0);
}