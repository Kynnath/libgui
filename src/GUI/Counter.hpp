/*
 * File:   Counter.hpp
 * Author: JoPe
 *
 * Created on 18 de noviembre de 2014, 23:22
 */

#ifndef COUNTER_HPP
#define	COUNTER_HPP

#include <string>

namespace gui
{
    struct Counter
    {
        int m_id;
        int m_value;
        std::string m_valueString;

        public:
            Counter( int const& i_id, int const& i_value );
    };
}


#endif	/* COUNTER_HPP */

