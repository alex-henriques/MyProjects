#ifndef HARL_HPP
#define HARL_HPP

#include <string> // check details first otherwise keep this;

class   Harl {
    private:
        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);

    public:
        void    complain(std::string level);
};


#endif