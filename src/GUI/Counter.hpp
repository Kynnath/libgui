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
      Counter(int i_id, int i_value);   // May throw
      Counter & operator=(int i_value); // May throw (strong)
  };
}


#endif	/* COUNTER_HPP */

