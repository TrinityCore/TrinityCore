/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

/* ScriptData
SDName: Stranglethorn_Vale
SD%Complete: 100
SDComment: Quest support: 592
SDCategory: Stranglethorn Vale
EndScriptData */

/* ContentData
npc_yenniku
EndContentData */

#include "ScriptMgr.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"

/*######
## npc_yenniku
######*/

enum Yenniku
{
    SPELL_YENNIKUS_RELEASE   = 3607,
    QUEST_SAVING_YENNIKU     = 592,
    FACTION_HORDE_GENERIC    = 83,
    FACTION_TROLL_BLOODSCALP = 28
};

class npc_yenniku : public CreatureScript
{
public:
    npc_yenniku() : CreatureScript("npc_yenniku") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_yennikuAI(creature);
    }

    struct npc_yennikuAI : public ScriptedAI
    {
        npc_yennikuAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            bReset = false;
        }

        void Initialize()
        {
            Reset_Timer = 0;
        }

        uint32 Reset_Timer;
        bool bReset;

        void Reset() override
        {
            Initialize();
            me->SetEmoteState(EMOTE_STATE_NONE);
        }

        void SpellHit(Unit* caster, const SpellInfo* spell) override
        {
            if (bReset || spell->Id != SPELL_YENNIKUS_RELEASE)
                return;

            if (Player* player = caster->ToPlayer())
            {
                if (player->GetQuestStatus(QUEST_SAVING_YENNIKU) == QUEST_STATUS_INCOMPLETE) // Yenniku's Release
                {
                    me->SetEmoteState(EMOTE_STATE_STUN);
                    me->CombatStop();                      // stop combat
                    me->DeleteThreatList();                // unsure of this
                    me->setFaction(FACTION_HORDE_GENERIC); // horde generic

                    bReset = true;
                    Reset_Timer = 60000;
                }
            }
        }

        void EnterCombat(Unit* /*who*/) override { }

        void UpdateAI(uint32 diff) override
        {
            if (bReset)
            {
                if (Reset_Timer <= diff)
                {
                    EnterEvadeMode();
                    bReset = false;
                    me->setFaction(FACTION_TROLL_BLOODSCALP); // troll, bloodscalp
                    return;
                }

                Reset_Timer -= diff;

                if (me->IsInCombat() && me->GetVictim())
                {
                    if (Player* player = me->EnsureVictim()->ToPlayer())
                    {
                        if (player->GetTeam() == HORDE)
                        {
                            me->CombatStop();
                            me->DeleteThreatList();
                        }
                    }
                }
             }

            //Return since we have no target
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_stranglethorn_vale()
{
    new npc_yenniku();
}
