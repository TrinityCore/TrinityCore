/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2011 gmlt.A
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"
#include "Group.h"
#include "operation_gnomeregan.h"

class npc_og_mekkatorque : public CreatureScript
{
public:
    npc_og_mekkatorque() : CreatureScript("npc_og_mekkatorque") { }

    struct npc_og_mekkatorqueAI : public npc_escortAI
    {
        npc_og_mekkatorqueAI(Creature* pCreature) : npc_escortAI(pCreature) { }

        uint32 uiStep;
        uint32 uiStep_timer;

        void Reset()
        {
            uiStep          = 0;
            uiStep_timer    = 0;
        }

        void WaypointReached(uint32 i)
        {
            switch (i)
            {
                case 0:
                    break;
            }
        }

        void JumpToNextStep(uint32 uiTimer)
        {
            uiStep_timer = uiTimer;
            ++uiStep;
        }

        void SetHoldState(bool b_OnHold)
        {
            SetEscortPaused(b_OnHold);
        }

        void UpdateAI(const uint32 diff)
        {
            npc_escortAI::UpdateAI(diff);

            if (uiStep_timer <= diff)
            {
                switch (uiStep)
                {
                    case 0:  // countdown
                        break;
                }
            }
            else 
                uiStep_timer -= diff;

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void PartyCast(uint32 spell)
        {
            if (Player* pPlayer = GetPlayerForEscort())
            {
                if (Group *pGroup = pPlayer->GetGroup())
                {
                    for (GroupReference *itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
                    {
                        if (Player* pMember = itr->getSource())
                            pMember->CastSpell(pMember, spell, true);
                    }
                }
                else
                {
                    pPlayer->CastSpell(pPlayer, spell, true);
                }
            }
        }

        void DoTalk(Creature* pTalker, const char* text,uint32 sound, bool yell)
        {
            if (yell)
                pTalker->MonsterYell(text, LANG_UNIVERSAL, NULL);
            else
                pTalker->MonsterSay(text, LANG_UNIVERSAL, NULL);

            DoPlaySoundToSet(pTalker, sound);
        }

        void DoPlayMusic(uint8 musicId)
        {
            switch (musicId)
            {
                case 0:
                    PartyCast(SPELL_MUSIC_START);
                    break;
                case 1:
                    PartyCast(SPELL_MUSIC);
                    break;
                case 2:
                    PartyCast(SPELL_MUSIC_END);
                    break;
                default:
                    sLog->outError("Unexpected musicId (%i) in npc_og_mekkatorqueAI::DoPlayMusic call", musicId);
            }
        }
    };

    bool OnQuestAccept(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
    {
        if (pQuest->GetQuestId() == QUEST_OPERATION_GNOMEREGAN)
        {
            if (npc_og_mekkatorqueAI* pEscortAI = CAST_AI(npc_og_mekkatorqueAI, pCreature->AI()))
            {
                pEscortAI->Start(true, false, pPlayer->GetGUID(), pQuest);
            }
        }
        return true;
    }

    CreatureAI *GetAI(Creature* pCreature) const
    {
        return new npc_og_mekkatorqueAI(pCreature);
    }
};

void AddSC_operation_gnomeregan()
{
    new npc_og_mekkatorque;
}
