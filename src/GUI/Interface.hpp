/*
 * File:   Interface.hpp
 * Author: juan.garibotti
 *
 * Created on 29 de julio de 2014, 16:53
 */

#ifndef INTERFACE_HPP
#define	INTERFACE_HPP

#include <map>
#include <string>
#include <vector>

namespace gui
{
    enum class Language;

    class Interface
    {
        std::vector<std::u32string> m_labels;
        std::map<std::string, unsigned int> m_identifierPosition;

        public:
            Interface();

            void LoadLanguage( Language const& i_language );
    };
}

#endif	/* INTERFACE_HPP */

