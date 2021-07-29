#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class Ice : public AMateria
{

	public:

		Ice();
		Ice( Ice const & src );
		virtual ~Ice();

		virtual AMateria*	clone() const;
		virtual void		use(ICharacter& target);
	private:

};

#endif /* ************************************************************* ICE_H */
