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
#include "SFML/Window/Event.hpp"
#include "FNT/Face.hpp"
#include "GLT/Shader.hpp"
#include "MSG/Messenger.hpp"
#include "Language.hpp"
#include "Node.hpp"

namespace gui
{
  class Interface
  {
    msg::Messenger & m_messenger;
    msg::Dequeueer m_queue;
    fnt::Face fontFace;
    std::vector<std::u32string> m_labels;
    std::map<std::string, unsigned int> m_identifierPosition;
    std::vector< glt::Shader > m_shaders;
    std::vector<Node> m_nodes;
    std::vector<int> m_commands;
    msg::Filter m_commandsFilter;

    void LoadScreen(std::string const& i_filename);
    
    public:
      Interface(msg::Messenger & i_messenger);
      void Init(msg::Filter filter, std::vector<int> const& i_commands);
      void ProcessInput(sf::Event c_event);
      void Update();
      void LoadLanguage( Language const& i_language );
      void Draw() const;
  };
}

#endif	/* INTERFACE_HPP */

