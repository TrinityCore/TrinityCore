/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDComment: Quest support: 10004, 10009, 10211. Flask vendors, Teleport to Caverns of Time
SDCategory: Shattrath City
EndScriptData */

/* ContentData
npc_raliq_the_drunk
npc_salsalabim
npc_shattrathflaskvendors
npc_zephyr
npc_kservant
npc_ishanah
npc_khadgar
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "Player.h"
#include "WorldSession.h"

/*######
## npc_raliq_the_drunk
######*/

#define GOSSIP_RALIQ            "You owe Sim'salabim money. Hand them over or die!"

enum eRaliq
{
    SPELL_UPPERCUT          = 10966,
    QUEST_CRACK_SKULLS      = 10009,
    FACTION_HOSTILE_RD      = 45
};

class npc_raliq_the_drunk : public CreatureScript
{
public:
    npc_raliq_the_drunk() : CreatureScript("npc_raliq_the_drunk") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF+1)
        {
            player->CLOSE_GOSSIP_MENU();
            creature->setFaction(FACTION_HOSTILE_RD);
            creature->AI()->AttackStart(player);
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (player->GetQuestStatus(QUEST_CRACK_SKULLS) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_RALIQ, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        player->SEND_GOSSIP_MENU(9440, creature->GetGUID());
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_raliq_the_drunkAI (creature);
    }

    struct npc_raliq_the_drunkAI : public ScriptedAI
    {
        npc_raliq_the_drunkAI(Creature* creature) : ScriptedAI(creature)
        {
            m_uiNormFaction = creature->getFaction();
        }

        uint32 m_uiNormFaction;
        uint32 Uppercut_Timer;

        void Reset()
        {
            Uppercut_Timer = 5000;
            me->RestoreFaction();
        }

        void UpdateAI(uint32 diff)
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
    };
};

/*######
# npc_salsalabim
######*/

#define FACTION_HOSTILE_SA              90
#define FACTION_FRIENDLY_SA             35
#define QUEST_10004                     10004

#define SPELL_MAGNETIC_PULL             31705

class npc_salsalabim : public CreatureScript
{
public:
    npc_salsalabim() : CreatureScript("npc_salsalabim") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (player->GetQuestStatus(QUEST_10004) == QUEST_STATUS_INCOMPLETE)
        {
            creature->setFaction(FACTION_HOSTILE_SA);
            creature->AI()->AttackStart(player);
        }
        else
        {
            if (creature->IsQuestGiver())
                player->PrepareQuestMenu(creature->GetGUID());
            player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        }
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_salsalabimAI (creature);
    }

    struct npc_salsalabimAI : public ScriptedAI
    {
        npc_salsalabimAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 MagneticPull_Timer;

        void Reset()
        {
            MagneticPull_Timer = 15000;
            me->RestoreFaction();
        }

        void DamageTaken(Unit* done_by, uint32 &damage)
        {
            if (done_by->GetTypeId() == TYPEID_PLAYER && me->HealthBelowPctDamaged(20, damage))
            {
                done_by->ToPlayer()->GroupEventHappens(QUEST_10004, me);
                damage = 0;
                EnterEvadeMode();
            }
        }

        void UpdateAI(uint32 diff)
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
    };
};

/*
##################################################
Shattrath City Flask Vendors provides flasks to people exalted with 3 fActions:
Haldor the Compulsive
Arcanist Xorith
Both sell special flasks for use in Outlands 25man raids only,
purchasable for one Mark of Illidari each
Purchase requires exalted reputation with Scryers/Aldor, Cenarion Expedition and The Sha'tar
##################################################
*/

class npc_shattrathflaskvendors : public CreatureScript
{
public:
    npc_shattrathflaskvendors() : CreatureScript("npc_shattrathflaskvendors") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_TRADE)
            player->GetSession()->SendListInventory(creature->GetGUID());

        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->GetEntry() == 23484)
        {
            // Aldor vendor
            if (creature->IsVendor() && (player->GetReputationRank(932) == REP_EXALTED) && (player->GetReputationRank(935) == REP_EXALTED) && (player->GetReputationRank(942) == REP_EXALTED))
            {
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);
                player->SEND_GOSSIP_MENU(11085, creature->GetGUID());
            }
            else
            {
                player->SEND_GOSSIP_MENU(11083, creature->GetGUID());
            }
        }

        if (creature->GetEntry() == 23483)
        {
            // Scryers vendor
            if (creature->IsVendor() && (player->GetReputationRank(934) == REP_EXALTED) && (player->GetReputationRank(935) == REP_EXALTED) && (player->GetReputationRank(942) == REP_EXALTED))
            {
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);
                player->SEND_GOSSIP_MENU(11085, creature->GetGUID());
            }
            else
            {
                player->SEND_GOSSIP_MENU(11084, creature->GetGUID());
            }
        }

        return true;
    }
};

/*######
# npc_zephyr
######*/

#define GOSSIP_HZ "Take me to the Caverns of Time."

class npc_zephyr : public CreatureScript
{
public:
    npc_zephyr() : CreatureScript("npc_zephyr") { }

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF+1)
            player->CastSpell(player, 37778, false);

        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (player->GetReputationRank(989) >= REP_REVERED)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HZ, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());

        return true;
    }
};

/*######
# npc_kservant
######*/

enum KServant
{
    SAY1       = 0,
    WHISP1     = 1,
    WHISP2     = 2,
    WHISP3     = 3,
    WHISP4     = 4,
    WHISP5     = 5,
    WHISP6     = 6,
    WHISP7     = 7,
    WHISP8     = 8,
    WHISP9     = 9,
    WHISP10    = 10,
    WHISP11    = 11,
    WHISP12    = 12,
    WHISP13    = 13,
    WHISP14    = 14,
    WHISP15    = 15,
    WHISP16    = 16,
    WHISP17    = 17,
    WHISP18    = 18,
    WHISP19    = 19,
    WHISP20    = 20,
    WHISP21    = 21
};

class npc_kservant : public CreatureScript
{
public:
    npc_kservant() : CreatureScript("npc_kservant") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_kservantAI(creature);
    }

    struct npc_kservantAI : public npc_escortAI
    {
    public:
        npc_kservantAI(Creature* creature) : npc_escortAI(creature) {}

        void WaypointReached(uint32 waypointId)
        {
            Player* player = GetPlayerForEscort();
            if (!player)
                return;

            switch (waypointId)
            {
                case 0:
                    Talk(SAY1, player->GetGUID());
                    break;
                case 4:
                    Talk(WHISP1, player->GetGUID());
                    break;
                case 6:
                    Talk(WHISP2, player->GetGUID());
                    break;
                case 7:
                    Talk(WHISP3, player->GetGUID());
                    break;
                case 8:
                    Talk(WHISP4, player->GetGUID());
                    break;
                case 17:
                    Talk(WHISP5, player->GetGUID());
                    break;
                case 18:
                    Talk(WHISP6, player->GetGUID());
                    break;
                case 19:
                    Talk(WHISP7, player->GetGUID());
                    break;
                case 33:
                    Talk(WHISP8, player->GetGUID());
                    break;
                case 34:
                    Talk(WHISP9, player->GetGUID());
                    break;
                case 35:
                    Talk(WHISP10, player->GetGUID());
                    break;
                case 36:
                    Talk(WHISP11, player->GetGUID());
                    break;
                case 43:
                    Talk(WHISP12, player->GetGUID());
                    break;
                case 44:
                    Talk(WHISP13, player->GetGUID());
                    break;
                case 49:
                    Talk(WHISP14, player->GetGUID());
                    break;
                case 50:
                    Talk(WHISP15, player->GetGUID());
                    break;
                case 51:
                    Talk(WHISP16, player->GetGUID());
                    break;
                case 52:
                    Talk(WHISP17, player->GetGUID());
                    break;
                case 53:
                    Talk(WHISP18, player->GetGUID());
                    break;
                case 54:
                    Talk(WHISP19, player->GetGUID());
                    break;
                case 55:
                    Talk(WHISP20, player->GetGUID());
                    break;
                case 56:
                    Talk(WHISP21, player->GetGUID());
                    player->GroupEventHappens(10211, me);
                    break;
            }
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (HasEscortState(STATE_ESCORT_ESCORTING))
                return;

            Player* player = who->ToPlayer();
            if (player && player->GetQuestStatus(10211) == QUEST_STATUS_INCOMPLETE)
            {
                float Radius = 10.0f;
                if (me->IsWithinDistInMap(who, Radius))
                {
                    Start(false, false, who->GetGUID());
                }
            }
        }

        void Reset() { }
    };
};

/*######
# npc_ishanah
######*/

#define ISANAH_GOSSIP_1 "Who are the Sha'tar?"
#define ISANAH_GOSSIP_2 "Isn't Shattrath a draenei city? Why do you allow others here?"

class npc_ishanah : public CreatureScript
{
public:
    npc_ishanah() : CreatureScript("npc_ishanah") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF+1)
            player->SEND_GOSSIP_MENU(9458, creature->GetGUID());
        else if (action == GOSSIP_ACTION_INFO_DEF+2)
            player->SEND_GOSSIP_MENU(9459, creature->GetGUID());

        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, ISANAH_GOSSIP_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, ISANAH_GOSSIP_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());

        return true;
    }
};

/*######
# npc_khadgar
######*/

#define KHADGAR_GOSSIP_1    "I've heard your name spoken only in whispers, mage. Who are you?"
#define KHADGAR_GOSSIP_2    "Go on, please."
#define KHADGAR_GOSSIP_3    "I see." //6th too this
#define KHADGAR_GOSSIP_4    "What did you do then?"
#define KHADGAR_GOSSIP_5    "What happened next?"
#define KHADGAR_GOSSIP_7    "There was something else I wanted to ask you."

class npc_khadgar : public CreatureScript
{
public:
    npc_khadgar() : CreatureScript("npc_khadgar") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        switch (action)
        {
        case GOSSIP_ACTION_INFO_DEF+1:
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, KHADGAR_GOSSIP_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
            player->SEND_GOSSIP_MENU(9876, creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, KHADGAR_GOSSIP_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
            player->SEND_GOSSIP_MENU(9877, creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+3:
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, KHADGAR_GOSSIP_4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
            player->SEND_GOSSIP_MENU(9878, creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+4:
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, KHADGAR_GOSSIP_5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+5);
            player->SEND_GOSSIP_MENU(9879, creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+5:
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, KHADGAR_GOSSIP_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+6);
            player->SEND_GOSSIP_MENU(9880, creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+6:
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, KHADGAR_GOSSIP_7, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+7);
            player->SEND_GOSSIP_MENU(9881, creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+7:
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, KHADGAR_GOSSIP_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            player->SEND_GOSSIP_MENU(9243, creature->GetGUID());
            break;
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (!player->hasQuest(10211))
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, KHADGAR_GOSSIP_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

            player->SEND_GOSSIP_MENU(9243, creature->GetGUID());

        return true;
    }
};

void AddSC_shattrath_city()
{
    new npc_raliq_the_drunk();
    new npc_salsalabim();
    new npc_shattrathflaskvendors();
    new npc_zephyr();
    new npc_kservant();
    new npc_ishanah();
    new npc_khadgar();
}
