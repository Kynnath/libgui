/*
 * File:   Node.hpp
 * Author: JoPe
 *
 * Created on 18 de noviembre de 2014, 22:56
 */

#ifndef NODE_HPP
#define	NODE_HPP

#include <vector>
#include "Counter.hpp"

namespace gui
{
  struct Node
  {
    float m_coordX;
    float m_coordY;
    Counter m_counter;
  };
}

#endif	/* NODE_HPP */

