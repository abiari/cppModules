#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : Form("ShrubberyCreationForm", target, 145, 137)
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/


std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i )
{
	if (i.getIsSigned() == true)
		o << i.getName() + " at " + i.getTarget() + "needs Grade: " << i.getSignGrade() << " to be signed and Grade: " << i.getExecGrade() << " to be executed. Form is currently signed\n";
	else
		o << i.getName() + " at " + i.getTarget() + "needs Grade: " << i.getSignGrade() << " to be signed and Grade: " << i.getExecGrade() << " to be executed. Form is currently not signed\n";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw Form::GradeTooLowException();
	else if (this->getIsSigned() == false)
		throw Form::FormNotSigned();
	else
	{
		std::ofstream ofs(this->getTarget() + "_shrubbery");
		ofs << "		                                                               &   &&   #                   \n";
		ofs << "                                                                 .&.#&&&&&&&&&                      \n";
		ofs << "                (%/.%%,  %          (   && #                   %&&&&&&&&&&&&&&(                     \n";
		ofs << "                   %%%%%%%%%.%%       &&&&&&&             (& (&&&&&&&&&&&&&&#                       \n";
		ofs << "         .         %%%%%%%%%%%%% %   &%,&&&&&&% &       #*&&&&&&&&&&&&                              \n";
		ofs << "    .&&&&&&&&& &&/ *(%%%%%%%%%%%%%% .%,&&&&&&&&&&      (&&&&&&&&&&&&%                               \n";
		ofs << "   ,&&&&&&&&&&&&&&&&&# %& %%%%%%%%%%%%%.&&&&&&&&& *& &,&&&&&&&&&&&&      %#  %%,                    \n";
		ofs << "  *&&&&&&&&&&&&&&&&&&&&&&&&%%%%%%%%%%%%%%%&&&&&&&&& .&&&&&&&&&&& %. .%*%%%%%%%%%%%%%%%%(            \n";
		ofs << "        .*/(#&&&&&&&&&&&&&&&&%%%%%%%%%%%%%&&&&&&&&&&&&&&&&&&&&%%%%#%%%%%%%%%%%%%%%%%#               \n";
		ofs << "                ./#&&&&&&&&&&&&&%%%%%%%%%%%&&&&&&&&&&&&&&&&&%%%%%%%%%%%%%%%%%%%%%%(                 \n";
		ofs << "                    #&&&&&&&&&&&&&,%%%%%%%%%&&&&&&&&&&&&&%%%%%%%%%%%%%%%%%%%&/                      \n";
		ofs << "                       (&&&&&&&&&&%%%%%%%%%%%%&&&&&&&&%&%%%%%%%%%%%%%%%%   &.&&&   %% *&&           \n";
		ofs << "                    /     /&&&&&&&&%%%%%%%%%%%&&&&&&&%%%%%%%%%%%%%*  %&#&&&&&&&&&&&&&&&&&&&&&       \n";
		ofs << "           ########% ##.#   *%&&&&&%%&%%%%%%%%&%&&%&%%%%%%%%%%%%%&(&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&# \n";
		ofs << "      %####################,#  ,&&&&%&&%%%%%%%%%&&%%%%%%%%%%%%%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
		ofs << "       ##%/###################%#&&&&&&%%%%%%%%%&%&%%%%%%%%%%%%&&&&&&&&&&&&&&&&&&&&#  #&/  #&&. #&/  \n";
		ofs << "                 (%%#############%.(&&%&%%%%%%%%%%%%%%%%%%%%&&&&&&&&&&%(/*.                         \n";
		ofs << "                        (%##########&&&&%&%%%%%%%%%%%%%%&&&&&&&&((#&##%###  //                      \n";
		ofs << "                          .%##########&&&%%%%%%%%%%%#&%%&&#&####################%%#,                \n";
		ofs << "                               /%######%%%%%%%%%%%%%%&&#%############################/              \n";
		ofs << "                                 ########%%%%%%%%%%%%################. /%##*##/########(            \n";
		ofs << "                                   .####(((%%%%%%%%#(((%######% *                  % #/             \n";
		ofs << "                                     #((((((((((((((%#%%*                                           \n";
		ofs << "                                     #((((((((((((((((   *(%%                                       \n";
		ofs << "                                 (/  .(((((((((%(((%  /%(*                                          \n";
		ofs << "                                       #(%%%%((%%%%##                                               \n";
		ofs << "                                           %%%%%                                                    \n";
		ofs.close();
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
