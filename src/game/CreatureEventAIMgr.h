/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef TRINITY_CREATURE_EAI_MGR_H
#define TRINITY_CREATURE_EAI_MGR_H

#include "Common.h"
#include "CreatureEventAI.h"

class CreatureEventAIMgr
{
    public:
        CreatureEventAIMgr(){};
        ~CreatureEventAIMgr(){};

        void LoadCreatureEventAI_Texts();
        void LoadCreatureEventAI_Summons();
        void LoadCreatureEventAI_Scripts();

        CreatureEventAI_Event_Map  const& GetCreatureEventAIMap()       const { return m_CreatureEventAI_Event_Map; }
        CreatureEventAI_Summon_Map const& GetCreatureEventAISummonMap() const { return m_CreatureEventAI_Summon_Map; }
        CreatureEventAI_TextMap    const& GetCreatureEventAITextMap()   const { return m_CreatureEventAI_TextMap; }

    private:
        CreatureEventAI_Event_Map  m_CreatureEventAI_Event_Map;
        CreatureEventAI_Summon_Map m_CreatureEventAI_Summon_Map;
        CreatureEventAI_TextMap    m_CreatureEventAI_TextMap;
};

#define CreatureEAI_Mgr Trinity::Singleton<CreatureEventAIMgr>::Instance()
#endif
