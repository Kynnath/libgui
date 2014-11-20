/*
 * File:   Node.cpp
 * Author: JoPe
 *
 * Created on 18 de noviembre de 2014, 22:56
 */

#include "Node.hpp"

namespace gui
{
    Node::Node(const int& cX, const int& cY, const int& w, const int& h, const Counter& c)
        : m_coordX( cX )
        , m_coordY( cY )
        , m_width ( w )
        , m_height( h )
        , m_counter( c )
    {}

    void Node::AddChild(const Node& i_node)
    {
        m_children.push_back( i_node );
    }

    void Node::Draw() const
    {
        m_counter.Draw();
        for ( auto const& child : m_children )
        {
            child.Draw();
        }
    }
}