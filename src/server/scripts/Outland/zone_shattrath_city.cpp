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
SDName: Shattrath_City
SD%Complete: 100
SDComment: Quest support: 10004, 10009, 10211.
SDCategory: Shattrath City
EndScriptData */

/* ContentData
npc_raliq_the_drunk
npc_salsalabim
npc_kservant
EndContentData */

#include "ScriptMgr.h"
#include "Player.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "WorldSession.h"

/*######
## npc_raliq_the_drunk
######*/

enum RaliqTheDrunk
{
    SAY_RALIQ_ATTACK         = 0,
    OPTION_ID_COLLECT_A_DEBT = 0,
    MENU_ID_COLLECT_A_DEBT   = 7729,
    NPC_TEXT_WUT_YOU_WANT    = 9440,
    CRACKIN_SOME_SKULLS      = 10009,
    SPELL_UPPERCUT           = 10966
};

class npc_raliq_the_drunk : public CreatureScript
{
public:
    npc_raliq_the_drunk() : CreatureScript("npc_raliq_the_drunk") { }

    struct npc_raliq_the_drunkAI : public ScriptedAI
    {
        npc_raliq_the_drunkAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            Uppercut_Timer = 5000;
        }

        uint32 Uppercut_Timer;

        void Reset() override
        {
            Initialize();
            me->RestoreFaction();
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (Uppercut_Timer <= diff)
            {
                DoCastVictim(SPELL_UPPERCUT);
                Uppercut_Timer = 15000;
            } else Uppercut_Timer -= diff;

            DoMeleeAttackIfReady();
        }

        bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            ClearGossipMenuFor(player);
            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                CloseGossipMenuFor(player);
                me->SetFaction(FACTION_OGRE);
                Talk(SAY_RALIQ_ATTACK, player);
                AttackStart(player);
            }
            return true;
        }

        bool GossipHello(Player* player) override
        {
            if (player->GetQuestStatus(CRACKIN_SOME_SKULLS) == QUEST_STATUS_INCOMPLETE)
            {
                AddGossipItemFor(player, MENU_ID_COLLECT_A_DEBT, OPTION_ID_COLLECT_A_DEBT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                SendGossipMenuFor(player, NPC_TEXT_WUT_YOU_WANT, me->GetGUID());
            }
            else
            {
                ClearGossipMenuFor(player);
                SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
            }
            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_raliq_the_drunkAI(creature);
    }
};

/*######
# npc_salsalabim
######*/

enum Salsalabim
{
    SAY_DEMONIC_AGGRO          = 0,
    OPTION_ID_ALTRUIS_SENT_ME  = 0,
    MENU_ID_ALTRUIS_SENT_ME    = 7725,
    NPC_TEXT_SAL_GROWLS_AT_YOU = 9435,
    PATIENCE_AND_UNDERSTANDING = 10004,
    SPELL_MAGNETIC_PULL        = 31705
};

class npc_salsalabim : public CreatureScript
{
public:
    npc_salsalabim() : CreatureScript("npc_salsalabim") { }

    struct npc_salsalabimAI : public ScriptedAI
    {
        npc_salsalabimAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            MagneticPull_Timer = 15000;
        }

        uint32 MagneticPull_Timer;

        void Reset() override
        {
            Initialize();
            me->RestoreFaction();
        }

        void DamageTaken(Unit* done_by, uint32 &damage) override
        {
            if (done_by->GetTypeId() == TYPEID_PLAYER && me->HealthBelowPctDamaged(20, damage))
            {
                done_by->ToPlayer()->GroupEventHappens(PATIENCE_AND_UNDERSTANDING, me);
                damage = 0;
                EnterEvadeMode();
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (MagneticPull_Timer <= diff)
            {
                DoCastVictim(SPELL_MAGNETIC_PULL);
                MagneticPull_Timer = 15000;
            } else MagneticPull_Timer -= diff;

            DoMeleeAttackIfReady();
        }

        bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            ClearGossipMenuFor(player);
            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                CloseGossipMenuFor(player);
                me->SetFaction(FACTION_DEMON);
                Talk(SAY_DEMONIC_AGGRO, player);
                AttackStart(player);
            }
            return true;
        }

        bool GossipHello(Player* player) override
        {
            if (player->GetQuestStatus(PATIENCE_AND_UNDERSTANDING) == QUEST_STATUS_INCOMPLETE)
            {
                AddGossipItemFor(player, MENU_ID_ALTRUIS_SENT_ME, OPTION_ID_ALTRUIS_SENT_ME, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                SendGossipMenuFor(player, NPC_TEXT_SAL_GROWLS_AT_YOU, me->GetGUID());
            }
            else
            {
                if (me->IsQuestGiver())
                    player->PrepareQuestMenu(me->GetGUID());
                SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
            }
            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_salsalabimAI(creature);
    }
};

/*######
# npc_kservant
######*/

enum KServant
{
    SAY1          = 0,
    WHISP1        = 1,
    WHISP2        = 2,
    WHISP3        = 3,
    WHISP4        = 4,
    WHISP5        = 5,
    WHISP6        = 6,
    WHISP7        = 7,
    WHISP8        = 8,
    WHISP9        = 9,
    WHISP10       = 10,
    WHISP11       = 11,
    WHISP12       = 12,
    WHISP13       = 13,
    WHISP14       = 14,
    WHISP15       = 15,
    WHISP16       = 16,
    WHISP17       = 17,
    WHISP18       = 18,
    WHISP19       = 19,
    WHISP20       = 20,
    WHISP21       = 21,
    CITY_OF_LIGHT = 10211
};

class npc_kservant : public CreatureScript
{
public:
    npc_kservant() : CreatureScript("npc_kservant") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_kservantAI(creature);
    }

    struct npc_kservantAI : public EscortAI
    {
    public:
        npc_kservantAI(Creature* creature) : EscortAI(creature) { }

        void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
        {
            Player* player = GetPlayerForEscort();
            if (!player)
                return;

            switch (waypointId)
            {
                case 0:
                    Talk(SAY1, player);
                    break;
                case 4:
                    Talk(WHISP1, player);
                    break;
                case 6:
                    Talk(WHISP2, player);
                    break;
                case 7:
                    Talk(WHISP3, player);
                    break;
                case 8:
                    Talk(WHISP4, player);
                    break;
                case 17:
                    Talk(WHISP5, player);
                    break;
                case 18:
                    Talk(WHISP6, player);
                    break;
                case 19:
                    Talk(WHISP7, player);
                    break;
                case 33:
                    Talk(WHISP8, player);
                    break;
                case 34:
                    Talk(WHISP9, player);
                    break;
                case 35:
                    Talk(WHISP10, player);
                    break;
                case 36:
                    Talk(WHISP11, player);
                    break;
                case 43:
                    Talk(WHISP12, player);
                    break;
                case 44:
                    Talk(WHISP13, player);
                    break;
                case 49:
                    Talk(WHISP14, player);
                    break;
                case 50:
                    Talk(WHISP15, player);
                    break;
                case 51:
                    Talk(WHISP16, player);
                    break;
                case 52:
                    Talk(WHISP17, player);
                    break;
                case 53:
                    Talk(WHISP18, player);
                    break;
                case 54:
                    Talk(WHISP19, player);
                    break;
                case 55:
                    Talk(WHISP20, player);
                    break;
                case 56:
                    Talk(WHISP21, player);
                    player->GroupEventHappens(CITY_OF_LIGHT, me);
                    break;
            }
        }

        void MoveInLineOfSight(Unit* who) override

        {
            if (HasEscortState(STATE_ESCORT_ESCORTING))
                return;

            Player* player = who->ToPlayer();
            if (player && player->GetQuestStatus(CITY_OF_LIGHT) == QUEST_STATUS_INCOMPLETE)
            {
                float Radius = 10.0f;
                if (me->IsWithinDistInMap(who, Radius))
                {
                    Start(false, false, who->GetGUID());
                }
            }
        }

        void Reset() override { }
    };
};

void AddSC_shattrath_city()
{
    new npc_raliq_the_drunk();
    new npc_salsalabim();
    new npc_kservant();
}
