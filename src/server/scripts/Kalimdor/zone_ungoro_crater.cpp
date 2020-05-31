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
SDName: Ungoro Crater
SD%Complete: 100
SDComment: Support for Quest: 4245, 4491
SDCategory: Ungoro Crater
EndScriptData */

/* ContentData
npc_a-me
EndContentData */

#include "ScriptMgr.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedEscortAI.h"
#include "ScriptedFollowerAI.h"
#include "SpellInfo.h"

enum AmeData
{
    SAY_READY               = 0,
    SAY_AGGRO1              = 1,
    SAY_SEARCH              = 2,
    SAY_AGGRO2              = 3,
    SAY_AGGRO3              = 4,
    SAY_FINISH              = 5,

    SPELL_DEMORALIZINGSHOUT = 13730,

    QUEST_CHASING_AME       = 4245,
    ENTRY_TARLORD           = 6519,
    ENTRY_TARLORD1          = 6519,
    ENTRY_STOMPER           = 6513,
};

class npc_ame : public CreatureScript
{
public:
    npc_ame() : CreatureScript("npc_ame") { }

    struct npc_ameAI : public EscortAI
    {
        npc_ameAI(Creature* creature) : EscortAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            DemoralizingShoutTimer = 5000;
        }

        uint32 DemoralizingShoutTimer;

        void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
        {
            if (Player* player = GetPlayerForEscort())
            {
                switch (waypointId)
                {
                    case 19:
                        me->SummonCreature(ENTRY_STOMPER, -6391.69f, -1730.49f, -272.83f, 4.96f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                        Talk(SAY_AGGRO1, player);
                        break;
                    case 28:
                        Talk(SAY_SEARCH, player);
                        break;
                    case 38:
                        me->SummonCreature(ENTRY_TARLORD, -6370.75f, -1382.84f, -270.51f, 6.06f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                        Talk(SAY_AGGRO2, player);
                        break;
                    case 49:
                        me->SummonCreature(ENTRY_TARLORD1, -6324.44f, -1181.05f, -270.17f, 4.34f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                        Talk(SAY_AGGRO3, player);
                        break;
                    case 55:
                        Talk(SAY_FINISH, player);
                        player->GroupEventHappens(QUEST_CHASING_AME, me);
                        break;
                }
            }
        }

        void Reset() override
        {
            Initialize();
        }

        void JustSummoned(Creature* summoned) override
        {
            summoned->AI()->AttackStart(me);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (Player* player = GetPlayerForEscort())
                player->FailQuest(QUEST_CHASING_AME);
        }

        void UpdateAI(uint32 diff) override
        {
            EscortAI::UpdateAI(diff);
            if (!UpdateVictim())
                return;

            if (DemoralizingShoutTimer <= diff)
            {
                DoCastVictim(SPELL_DEMORALIZINGSHOUT);
                DemoralizingShoutTimer = 70000;
            } else DemoralizingShoutTimer -= diff;
        }

        void QuestAccept(Player* player, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_CHASING_AME)
            {
                Start(false, false, player->GetGUID());
                Talk(SAY_READY, player);
                me->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
                // Change faction so mobs attack
                me->SetFaction(FACTION_ESCORTEE_N_NEUTRAL_PASSIVE);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_ameAI(creature);
    }
};


void AddSC_ungoro_crater()
{
    new npc_ame();
}
