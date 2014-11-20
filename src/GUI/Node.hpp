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
    class Node
    {
        std::vector<Node> m_children;
        int m_coordX;
        int m_coordY;
        int m_width;
        int m_height;
        Counter m_counter;

        public:
            Node( int const& cX, int const& cY, int const& w, int const& h, Counter const& c );
            void AddChild( Node const& i_node );
            void Draw() const;
    };
}


#endif	/* NODE_HPP */

