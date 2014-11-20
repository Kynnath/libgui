/*
 * File:   Counter.cpp
 * Author: JoPe
 *
 * Created on 18 de noviembre de 2014, 23:22
 */

#include "Counter.hpp"

namespace gui
{
    Counter::Counter( int const& i_id, int const& i_value )
        : m_id(i_id)
        , m_value ( i_value )
        , m_valueString( std::to_string(i_value))
    {}

    void Counter::Draw() const
    {}



}