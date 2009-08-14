/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ScriptData
SDName: Instance - Sethekk Halls
SD%Complete: 50
SDComment: Instance Data for Sethekk Halls instance
SDCategory: Auchindoun, Sethekk Halls
EndScriptData */

#include "precompiled.h"
#include "def_sethekk_halls.h"

enum
{
    NPC_ANZU   = 23035,
    IKISS_DOOR = 177203,
};

struct TRINITY_DLL_DECL instance_sethekk_halls : public ScriptedInstance
{
    instance_sethekk_halls(Map* pMap) : ScriptedInstance(pMap) {Initialize();};

	uint32 AnzuEncounter;
    uint64 m_uiIkissDoorGUID;

    void Initialize()
    {
		AnzuEncounter = NOT_STARTED;
        m_uiIkissDoorGUID = 0;
    }

    void OnCreatureCreate(Creature* pCreature, bool add)
    {
        if (pCreature->GetEntry() == NPC_ANZU && AnzuEncounter >= IN_PROGRESS)
        {
            pCreature->DealDamage(pCreature, pCreature->GetMaxHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
            pCreature->RemoveCorpse();
        } else {
            AnzuEncounter = IN_PROGRESS;
        }
    }

    void OnGameObjectCreate(GameObject* pGo, bool add)
    {
         if (pGo->GetEntry() == IKISS_DOOR)
            m_uiIkissDoorGUID = pGo->GetGUID();
    }

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
            case DATA_IKISSDOOREVENT:
                if (data == DONE)
                    DoUseDoorOrButton(m_uiIkissDoorGUID,DAY*IN_MILISECONDS);
                break;
            case TYPE_ANZU_ENCOUNTER:
                AnzuEncounter = data;
                break;
        }
    }
};

InstanceData* GetInstanceData_instance_sethekk_halls(Map* pMap)
{
    return new instance_sethekk_halls(pMap);
}

void AddSC_instance_sethekk_halls()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_sethekk_halls";
    newscript->GetInstanceData = &GetInstanceData_instance_sethekk_halls;
    newscript->RegisterSelf();
}

