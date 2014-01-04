/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

/* Script Data Start
SDName: CrystalSongForest
SDAuthor: Malcrom
SD%Complete: 99%
SDComment:
SDCategory: CrystalsongForest
Script Data End */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Player.h"

/*******************************************************
 * npc_warmage_violetstand
 *******************************************************/

enum Spells
{
    SPELL_TRANSITUS_SHIELD_BEAM = 48310
};

enum NPCs
{
    NPC_TRANSITUS_SHIELD_DUMMY   = 27306,
    NPC_WARMAGE_SARINA           = 32369,
    NPC_WARMAGE_HALISTER         = 32371,
    NPC_WARMAGE_ILSUDRIA         = 32372
};

class npc_warmage_violetstand : public CreatureScript
{
public:
    npc_warmage_violetstand() : CreatureScript("npc_warmage_violetstand") { }

    struct npc_warmage_violetstandAI : public ScriptedAI
    {
        npc_warmage_violetstandAI(Creature* creature) : ScriptedAI(creature)
        {
            SetCombatMovement(false);
        }

        uint64 targetGUID;

        void Reset() OVERRIDE
        {
            targetGUID = 0;
        }

        void UpdateAI(uint32 /*diff*/) OVERRIDE
        {
            if (me->IsNonMeleeSpellCast(false))
                return;

            if (me->GetEntry() == NPC_WARMAGE_SARINA)
            {
                if (!targetGUID)
                {
                    std::list<Creature*> orbList;
                    GetCreatureListWithEntryInGrid(orbList, me, NPC_TRANSITUS_SHIELD_DUMMY, 32.0f);
                    if (!orbList.empty())
                    {
                        for (std::list<Creature*>::const_iterator itr = orbList.begin(); itr != orbList.end(); ++itr)
                        {
                            if (Creature* pOrb = *itr)
                            {
                                if (pOrb->GetPositionY() < 1000)
                                {
                                    targetGUID = pOrb->GetGUID();
                                    break;
                                }
                            }
                        }
                    }
                }
            }else
            {
                if (!targetGUID)
                    if (Creature* pOrb = GetClosestCreatureWithEntry(me, NPC_TRANSITUS_SHIELD_DUMMY, 32.0f))
                        targetGUID = pOrb->GetGUID();

            }

            if (Creature* pOrb = me->GetCreature(*me, targetGUID))
                DoCast(pOrb, SPELL_TRANSITUS_SHIELD_BEAM);

        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_warmage_violetstandAI(creature);
    }
};

void AddSC_crystalsong_forest()
{
    new npc_warmage_violetstand;
}
