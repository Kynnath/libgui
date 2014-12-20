/*
 * File:   Counter.cpp
 * Author: JoPe
 *
 * Created on 18 de noviembre de 2014, 23:22
 */

#include "Counter.hpp"

namespace gui
{
  Counter::Counter(int i_id, int i_value) // May throw
    : m_id {i_id}
    , m_value {i_value}
    , m_valueString {std::to_string(i_value)}
  {}
  
  Counter & Counter::operator=(int i_value) // May throw (strong)
  {
    m_valueString = std::to_string(i_value);
    m_value = i_value;
    
    return *this;
  }
}