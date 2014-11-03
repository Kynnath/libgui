/*
 * File:   Interface.cpp
 * Author: juan.garibotti
 *
 * Created on 29 de julio de 2014, 16:53
 */

#include "Interface.hpp"

#include "CSV/Table.hpp"
#include "TLS/Tools.hpp"
#include "Language.hpp"

namespace gui
{
    void Interface::LoadLanguage( Language const& i_language )
    {
        // Text is stored in a csv file sorted with label first, then
        // localized text in english, then spanish
        csv::Table labelText { "resource/gui/text.csv" };

        m_identifierPosition.clear();
        m_labels.clear();
        for( auto const& record : labelText )
        {
            m_identifierPosition.insert(std::make_pair(*record.begin(), m_labels.size()));
            m_labels.push_back( tls::Utf32FromUtf8( *(record.begin()+1+static_cast<int>(i_language))));
        }
    }
}