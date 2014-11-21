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
    Interface::Interface()
        : fontFace { "resource/font/ocraext.ttf", 72 }
        , root {0,0,900,600,{0,0}}
    {
        root.AddChild( {-150, 200, 0, 0, {1,0}} ); // Player score
        root.AddChild( { 150, 200, 0, 0, {2,0}} ); // AI score
    }

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

    void Interface::Draw() const
    {
        /*glUseProgram( m_shaders[2].m_shaderID );
        glt::GeometryTransform geometryTransform;
        geometryTransform.Reset();
        geometryTransform.DefineOrthographicProjection( 0.0, 960.0, 0.0, 600.0, -1.0, 1.0 );
        glBindTexture( GL_TEXTURE_2D, fontFace.Texture().Name() );
        glBindVertexArray( fontFace.VertexArray() );

        glt::Frame cursor { { { 300.0f - ( playerScoreLength / 2.0f ), 500, 0 } }, { { 0, 0, 1 } }, { { 0, 1, 0 } } };
        for ( auto const& character : playerScore )
        {
            fnt::Glyph glyph = fontFace.GlyphData( static_cast<uint32_t>(character) );
            glUniformMatrix4fv( (GLint)m_shaders.back().m_mvpLocation, 1, GL_FALSE, &geometryTransform.BuildMVPMatrix( cursor ).m_data[0] );
            glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, glyph.m_indicesOffset );
            cursor.m_position.Add( { glyph.m_advance, 0.0, 0.0 } );
        }

        cursor.m_position = vec::Vector3{ 660.0f - ( aiScoreLength / 2.0f ), 500, 0 };
        for ( auto const& character : aiScore )
        {
            fnt::Glyph glyph = fontFace.GlyphData( static_cast<uint32_t>(character) );
            glUniformMatrix4fv( (GLint)m_shaders.back().m_mvpLocation, 1, GL_FALSE, &geometryTransform.BuildMVPMatrix( cursor ).m_data[0] );
            glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, glyph.m_indicesOffset );
            cursor.m_position.Add( { glyph.m_advance, 0.0, 0.0 } );
        }*/
    }
}