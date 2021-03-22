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
SDName: Zangarmarsh
SD%Complete: 100
SDComment: Quest support: 9752, 9785, Mark Of ... buffs.
SDCategory: Zangarmarsh
EndScriptData */

/* ContentData
npcs_ashyen_and_keleth
npc_kayra_longmane
EndContentData */

#include "ScriptMgr.h"
#include "Player.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"

/*######
## npcs_ashyen_and_keleth
######*/

#define GOSSIP_ITEM_BLESS_ASH     "Grant me your mark, wise ancient."
#define GOSSIP_ITEM_BLESS_KEL     "Grant me your mark, mighty ancient."

enum AshyenAndKeleth
{
    NPC_ASHYEN                  = 17900,
    NPC_KELETH                  = 17901,

    SPELL_BLESS_ASH_EXA         = 31815,
    SPELL_BLESS_ASH_REV         = 31811,
    SPELL_BLESS_ASH_HON         = 31810,
    SPELL_BLESS_ASH_FRI         = 31808,

    SPELL_BLESS_KEL_EXA         = 31814,
    SPELL_BLESS_KEL_REV         = 31813,
    SPELL_BLESS_KEL_HON         = 31812,
    SPELL_BLESS_KEL_FRI         = 31807
};

class npcs_ashyen_and_keleth : public CreatureScript
{
public:
    npcs_ashyen_and_keleth() : CreatureScript("npcs_ashyen_and_keleth") { }

    struct npcs_ashyen_and_kelethAI : public ScriptedAI
    {
        npcs_ashyen_and_kelethAI(Creature* creature) : ScriptedAI(creature) { }

        bool GossipHello(Player* player) override
        {
            if (player->GetReputationRank(942) > REP_NEUTRAL)
            {
                if (me->GetEntry() == NPC_ASHYEN)
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_BLESS_ASH, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

                if (me->GetEntry() == NPC_KELETH)
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_BLESS_KEL, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            }
            SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());

            return true;
        }

        bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            ClearGossipMenuFor(player);
            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                me->SetPowerType(POWER_MANA);
                me->SetMaxPower(POWER_MANA, 200);             //set a "fake" mana value, we can't depend on database doing it in this case
                me->SetPower(POWER_MANA, 200);

                if (me->GetEntry() == NPC_ASHYEN)                //check which Creature we are dealing with
                {
                    uint32 spell = 0;
                    switch (player->GetReputationRank(942))
                    {                                               //mark of lore
                        case REP_FRIENDLY:
                            spell = SPELL_BLESS_ASH_FRI;
                            break;
                        case REP_HONORED:
                            spell = SPELL_BLESS_ASH_HON;
                            break;
                        case REP_REVERED:
                            spell = SPELL_BLESS_ASH_REV;
                            break;
                        case REP_EXALTED:
                            spell = SPELL_BLESS_ASH_EXA;
                            break;
                        default:
                            break;
                    }

                    if (spell)
                        DoCast(player, spell, true);
                }

                if (me->GetEntry() == NPC_KELETH)
                {
                    uint32 spell = 0;
                    switch (player->GetReputationRank(942))         //mark of war
                    {
                        case REP_FRIENDLY:
                            spell = SPELL_BLESS_KEL_FRI;
                            break;
                        case REP_HONORED:
                            spell = SPELL_BLESS_KEL_HON;
                            break;
                        case REP_REVERED:
                            spell = SPELL_BLESS_KEL_REV;
                            break;
                        case REP_EXALTED:
                            spell = SPELL_BLESS_KEL_EXA;
                            break;
                        default:
                            break;
                    }

                    if (spell)
                        DoCast(player, spell, true);
                }
                CloseGossipMenuFor(player);
                player->TalkedToCreature(me->GetEntry(), me->GetGUID());
            }
            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npcs_ashyen_and_kelethAI(creature);
    }
};

/*######
## npc_kayra_longmane
######*/

enum Kayra
{
    SAY_START           = 0,
    SAY_AMBUSH1         = 1,
    SAY_PROGRESS        = 2,
    SAY_AMBUSH2         = 3,
    SAY_END             = 4,

    QUEST_ESCAPE_FROM   = 9752,
    NPC_SLAVEBINDER     = 18042
};

class npc_kayra_longmane : public CreatureScript
{
public:
    npc_kayra_longmane() : CreatureScript("npc_kayra_longmane") { }

    struct npc_kayra_longmaneAI : public EscortAI
    {
        npc_kayra_longmaneAI(Creature* creature) : EscortAI(creature) { }

        void Reset() override { }

        void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
        {
            Player* player = GetPlayerForEscort();
            if (!player)
                return;

            switch (waypointId)
            {
                case 4:
                    Talk(SAY_AMBUSH1, player);
                    DoSpawnCreature(NPC_SLAVEBINDER, -10.0f, -5.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                    DoSpawnCreature(NPC_SLAVEBINDER, -8.0f, 5.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                    break;
                case 5:
                    Talk(SAY_PROGRESS, player);
                    SetRun();
                    break;
                case 16:
                    Talk(SAY_AMBUSH2, player);
                    DoSpawnCreature(NPC_SLAVEBINDER, -10.0f, -5.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                    DoSpawnCreature(NPC_SLAVEBINDER, -8.0f, 5.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                    break;
                case 17:
                    SetRun(false);
                    break;
                case 25:
                    Talk(SAY_END, player);
                    player->GroupEventHappens(QUEST_ESCAPE_FROM, me);
                    break;
            }
        }

        void QuestAccept(Player* player, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_ESCAPE_FROM)
            {
                Talk(SAY_START, player);
                Start(false, false, player->GetGUID());
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_kayra_longmaneAI(creature);
    }
};

/*######
## AddSC
######*/

void AddSC_zangarmarsh()
{
    new npcs_ashyen_and_keleth();
    new npc_kayra_longmane();
}
