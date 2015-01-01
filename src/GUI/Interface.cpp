/*
 * File:   Interface.cpp
 * Author: juan.garibotti
 *
 * Created on 29 de julio de 2014, 16:53
 */

#include "Interface.hpp"

#include <algorithm>
#include <fstream>
#include "CSV/Table.hpp"
#include "GLT/GeometryTransform.hpp"
#include "TLS/Tools.hpp"
#include "GameData.hpp"
#include "Language.hpp"

namespace gui
{
  namespace
  {
    GLfloat GetLength( std::string const& i_string, fnt::Face const& i_face )
    {
      GLfloat length = 0;
      for ( auto const& character : i_string )
      {
        length += i_face.GlyphData( static_cast<uint32_t>(character) ).m_advance;
      }
      return length;
    }
    
    int IndexFromName(std::string const& i_name)
    {
      if (i_name == "playerScore") return 1;
      if (i_name == "aiScore") return 2;
      return 0;
    }
  }
  
  void Interface::LoadScreen(std::string const& i_filename )
  {
    csv::Table table {i_filename};
    for (auto const& record : table)
    {
      if (std::stoi(record[0]) == 0)
      {
        m_nodes.push_back({std::stof(record[1]), std::stof(record[2]), {IndexFromName(record[3]),0}});
      }
    }
  }
  
  Interface::Interface(msg::Messenger & i_messenger)
    : m_messenger { i_messenger }
    , m_queue { m_messenger.Register(msg::Filter()) }
    , fontFace { "resource/font/ocraext.ttf", 72 }
  {}

  void Interface::Init(msg::Filter filter, std::vector<int> const& i_commands)
  {
    m_commands = i_commands;
    m_commandsFilter = filter;
    char32_t numbers[] =
    {
      '0','1','2','3','4','5','6','7','8','9',0
    };
    fontFace.LoadGlyphs( numbers );

    std::ifstream shaderFile { "resource/shader/Text.vs" };
    std::string vertexShader;
    char character = static_cast<char>( shaderFile.get() );
    while ( shaderFile.good() )
    {
      vertexShader += character;
      character = static_cast<char>( shaderFile.get() );
    }
    shaderFile.close();
    shaderFile.open( "resource/shader/Text.fs" );
    std::string fragmentShader;
    character = static_cast<char>( shaderFile.get() );
    while ( shaderFile.good() )
    {
      fragmentShader += character;
      character = static_cast<char>( shaderFile.get() );
    }
    m_shaders.push_back( glt::LoadShaderCode( vertexShader.c_str(), fragmentShader.c_str() ) );
    
    LoadScreen("resource/gui/scores.csv");
  }
  
  void Interface::ProcessInput(sf::Event c_event)
  {
    if ( c_event.type == sf::Event::Closed )
    {
      m_messenger.Post( m_commandsFilter,{m_commands[0],1} );
    }
    else if ( c_event.type == sf::Event::KeyPressed )
    {
      if ( c_event.key.code == sf::Keyboard::Up )
      {
        m_messenger.Post( m_commandsFilter,{m_commands[1],1} );
      }
      else if ( c_event.key.code == sf::Keyboard::Down )
      {
        m_messenger.Post( m_commandsFilter,{m_commands[2],1} );
      }
    }
    else if ( c_event.type == sf::Event::KeyReleased )
    {
      if ( c_event.key.code == sf::Keyboard::Up ||
           c_event.key.code == sf::Keyboard::Down )
      {
        m_messenger.Post( m_commandsFilter,{m_commands[3],1} );
      }
    }
  }

  void Interface::Update()
  {
    while (!m_queue.IsEmpty())
    {
      auto message = m_queue.Front();
      
      for (auto & node : m_nodes)
      {
        if (message.m_id == node.m_counter.m_id)
        {
          node.m_counter = message.m_value;
          break;
        }
      }
      m_queue.Pop();
    }
  }

  void Interface::LoadLanguage( Language const& /*i_language*/ )
  {/*
    // Text is stored in a csv file sorted with label first, then
    // localized text in english, then spanish
    csv::Table labelText { "resource/gui/text.csv" };

    m_identifierPosition.clear();
    m_labels.clear();
    for( auto const& record : labelText )
    {
      m_identifierPosition.insert(std::make_pair(*record.begin(), m_labels.size()));
      m_labels.push_back( tls::Utf32FromUtf8( *(record.begin()+1+static_cast<int>(i_language))));
    }*/
  }

  void Interface::Draw() const
  {
    float resolutionX = 960;
    float resolutionY = 600;
    glUseProgram( m_shaders[0].m_shaderID );
    glt::GeometryTransform geometryTransform;
    geometryTransform.Reset();
    geometryTransform.DefineOrthographicProjection( 0.0, resolutionX, 0.0, resolutionY, -1.0, 1.0 );
    glBindTexture( GL_TEXTURE_2D, fontFace.Texture().Name() );
    glBindVertexArray( fontFace.VertexArray() );

    for ( auto const& node : m_nodes)
    {
      glt::Frame cursor { { { node.m_coordX * resolutionX - ( GetLength(node.m_counter.m_valueString,fontFace) / 2.0f ), node.m_coordY * resolutionY, 0 } }, { { 0, 0, 1 } }, { { 0, 1, 0 } } };
      for ( auto const& character : node.m_counter.m_valueString )
      {
        fnt::Glyph glyph = fontFace.GlyphData( static_cast<uint32_t>(character) );
        glUniformMatrix4fv( (GLint)m_shaders.back().m_mvpLocation, 1, GL_FALSE, &geometryTransform.BuildMVPMatrix( cursor ).m_data[0] );
        glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, glyph.m_indicesOffset );
        cursor.m_position.Add( { glyph.m_advance, 0.0, 0.0 } );
      }
    }
    
    /*glt::Frame cursor { { { m_node1.m_coordX * resolutionX - ( GetLength(m_node1.m_counter.m_valueString,fontFace) / 2.0f ), m_node1.m_coordY * resolutionY, 0 } }, { { 0, 0, 1 } }, { { 0, 1, 0 } } };
    for ( auto const& character : m_node1.m_counter.m_valueString )
    {
      fnt::Glyph glyph = fontFace.GlyphData( static_cast<uint32_t>(character) );
      glUniformMatrix4fv( (GLint)m_shaders.back().m_mvpLocation, 1, GL_FALSE, &geometryTransform.BuildMVPMatrix( cursor ).m_data[0] );
      glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, glyph.m_indicesOffset );
      cursor.m_position.Add( { glyph.m_advance, 0.0, 0.0 } );
    }

    cursor.m_position = vec::Vector3{ m_node2.m_coordX * resolutionX - ( GetLength(m_node2.m_counter.m_valueString,fontFace) / 2.0f ), m_node2.m_coordY * resolutionY, 0 };
    for ( auto const& character : m_node2.m_counter.m_valueString )
    {
      fnt::Glyph glyph = fontFace.GlyphData( static_cast<uint32_t>(character) );
      glUniformMatrix4fv( (GLint)m_shaders.back().m_mvpLocation, 1, GL_FALSE, &geometryTransform.BuildMVPMatrix( cursor ).m_data[0] );
      glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, glyph.m_indicesOffset );
      cursor.m_position.Add( { glyph.m_advance, 0.0, 0.0 } );
    }*/
  }
}