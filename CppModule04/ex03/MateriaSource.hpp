#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{

	public:

		MateriaSource();
		MateriaSource( MateriaSource const & src );
		virtual ~MateriaSource();

		MateriaSource &		operator=( MateriaSource const & rhs );

		virtual void		learnMateria(AMateria* materia);
		virtual AMateria*	createMateria(std::string const & type);

	private:
		AMateria* _inventory[4];
};

#endif /* *************************************************** MATERIASOURCE_H */
