/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
SDComment: Quest support: 10004, 10009, 10211, 10231. Flask vendors, Teleport to Caverns of Time
SDCategory: Shattrath City
EndScriptData */

/* ContentData
npc_raliq_the_drunk
npc_salsalabim
npc_shattrathflaskvendors
npc_zephyr
npc_kservant
npc_dirty_larry
npc_ishanah
npc_khadgar
EndContentData */

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"

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

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
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
        npc_raliq_the_drunkAI(Creature* c) : ScriptedAI(c)
        {
            m_uiNormFaction = c->getFaction();
        }

        uint32 m_uiNormFaction;
        uint32 Uppercut_Timer;

        void Reset()
        {
            Uppercut_Timer = 5000;
            me->RestoreFaction();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (Uppercut_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_UPPERCUT);
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
            if (creature->isQuestGiver())
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
        npc_salsalabimAI(Creature* c) : ScriptedAI(c) {}

        uint32 MagneticPull_Timer;

        void Reset()
        {
            MagneticPull_Timer = 15000;
            me->RestoreFaction();
        }

        void DamageTaken(Unit* done_by, uint32 &damage)
        {
            if (done_by->GetTypeId() == TYPEID_PLAYER)
                if (me->HealthBelowPctDamaged(20, damage))
            {
                CAST_PLR(done_by)->GroupEventHappens(QUEST_10004, me);
                damage = 0;
                EnterEvadeMode();
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (MagneticPull_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_MAGNETIC_PULL);
                MagneticPull_Timer = 15000;
            } else MagneticPull_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

/*
##################################################
Shattrath City Flask Vendors provides flasks to people exalted with 3 factions:
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

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_TRADE)
            player->GetSession()->SendListInventory(creature->GetGUID());

        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->GetEntry() == 23484)
        {
            // Aldor vendor
            if (creature->isVendor() && (player->GetReputationRank(932) == REP_EXALTED) && (player->GetReputationRank(935) == REP_EXALTED) && (player->GetReputationRank(942) == REP_EXALTED))
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
            if (creature->isVendor() && (player->GetReputationRank(934) == REP_EXALTED) && (player->GetReputationRank(935) == REP_EXALTED) && (player->GetReputationRank(942) == REP_EXALTED))
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

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
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

#define SAY1       -1000234
#define WHISP1     -1000235
#define WHISP2     -1000236
#define WHISP3     -1000237
#define WHISP4     -1000238
#define WHISP5     -1000239
#define WHISP6     -1000240
#define WHISP7     -1000241
#define WHISP8     -1000242
#define WHISP9     -1000243
#define WHISP10    -1000244
#define WHISP11    -1000245
#define WHISP12    -1000246
#define WHISP13    -1000247
#define WHISP14    -1000248
#define WHISP15    -1000249
#define WHISP16    -1000250
#define WHISP17    -1000251
#define WHISP18    -1000252
#define WHISP19    -1000253
#define WHISP20    -1000254
#define WHISP21    -1000255
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
        npc_kservantAI(Creature* c) : npc_escortAI(c) {}

        void WaypointReached(uint32 i)
        {
            Player* player = GetPlayerForEscort();

            if (!player)
                return;

            switch (i)
            {
                case 0: DoScriptText(SAY1, me, player); break;
                case 4: DoScriptText(WHISP1, me, player); break;
                case 6: DoScriptText(WHISP2, me, player); break;
                case 7: DoScriptText(WHISP3, me, player); break;
                case 8: DoScriptText(WHISP4, me, player); break;
                case 17: DoScriptText(WHISP5, me, player); break;
                case 18: DoScriptText(WHISP6, me, player); break;
                case 19: DoScriptText(WHISP7, me, player); break;
                case 33: DoScriptText(WHISP8, me, player); break;
                case 34: DoScriptText(WHISP9, me, player); break;
                case 35: DoScriptText(WHISP10, me, player); break;
                case 36: DoScriptText(WHISP11, me, player); break;
                case 43: DoScriptText(WHISP12, me, player); break;
                case 44: DoScriptText(WHISP13, me, player); break;
                case 49: DoScriptText(WHISP14, me, player); break;
                case 50: DoScriptText(WHISP15, me, player); break;
                case 51: DoScriptText(WHISP16, me, player); break;
                case 52: DoScriptText(WHISP17, me, player); break;
                case 53: DoScriptText(WHISP18, me, player); break;
                case 54: DoScriptText(WHISP19, me, player); break;
                case 55: DoScriptText(WHISP20, me, player); break;
                case 56: DoScriptText(WHISP21, me, player);
                    if (player)
                        player->GroupEventHappens(10211, me);
                    break;
            }
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (HasEscortState(STATE_ESCORT_ESCORTING))
                return;

            if (who->GetTypeId() == TYPEID_PLAYER)
            {
                if (CAST_PLR(who)->GetQuestStatus(10211) == QUEST_STATUS_INCOMPLETE)
                {
                    float Radius = 10.0f;
                    if (me->IsWithinDistInMap(who, Radius))
                    {
                        Start(false, false, who->GetGUID());
                    }
                }
            }
        }

        void Reset() {}
    };
};

/*######
# npc_dirty_larry
######*/

#define GOSSIP_BOOK "Ezekiel said that you might have a certain book..."

#define SAY_1       -1000274
#define SAY_2       -1000275
#define SAY_3       -1000276
#define SAY_4       -1000277
#define SAY_5       -1000278
#define SAY_GIVEUP  -1000279

#define QUEST_WBI       10231
#define NPC_CREEPJACK   19726
#define NPC_MALONE      19725

class npc_dirty_larry : public CreatureScript
{
public:
    npc_dirty_larry() : CreatureScript("npc_dirty_larry") { }

    struct npc_dirty_larryAI : public ScriptedAI
    {
        npc_dirty_larryAI(Creature* c) : ScriptedAI(c) {}

        bool Event;
        bool Attack;
        bool Done;

        uint64 PlayerGUID;

        uint32 SayTimer;
        uint32 Step;

        void Reset()
        {
            Event = false;
            Attack = false;
            Done = false;

            PlayerGUID = 0;
            SayTimer = 0;
            Step = 0;

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->setFaction(1194);
            Unit* Creepjack = me->FindNearestCreature(NPC_CREEPJACK, 20);
            if (Creepjack)
            {
                CAST_CRE(Creepjack)->AI()->EnterEvadeMode();
                Creepjack->setFaction(1194);
                Creepjack->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }
            Unit* Malone = me->FindNearestCreature(NPC_MALONE, 20);
            if (Malone)
            {
                CAST_CRE(Malone)->AI()->EnterEvadeMode();
                Malone->setFaction(1194);
                Malone->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }
        }

        uint32 NextStep(uint32 Step)
        {
            Player* player = Unit::GetPlayer(*me, PlayerGUID);

            switch (Step)
            {
            case 0:{ me->SetInFront(player);
                Unit* Creepjack = me->FindNearestCreature(NPC_CREEPJACK, 20);
                if (Creepjack)
                    Creepjack->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
                Unit* Malone = me->FindNearestCreature(NPC_MALONE, 20);
                if (Malone)
                    Malone->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
                me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP); }return 2000;
            case 1: DoScriptText(SAY_1, me, player); return 3000;
            case 2: DoScriptText(SAY_2, me, player); return 5000;
            case 3: DoScriptText(SAY_3, me, player); return 2000;
            case 4: DoScriptText(SAY_4, me, player); return 2000;
            case 5: DoScriptText(SAY_5, me, player); return 2000;
            case 6: Attack = true; return 2000;
            default: return 0;
            }
        }

        void EnterCombat(Unit* /*who*/){}

        void UpdateAI(const uint32 diff)
        {
            if (SayTimer <= diff)
            {
                if (Event)
                    SayTimer = NextStep(++Step);
            } else SayTimer -= diff;

            if (Attack)
            {
                Player* player = Unit::GetPlayer(*me, PlayerGUID);
                me->setFaction(14);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                if (player)
                {
                Unit* Creepjack = me->FindNearestCreature(NPC_CREEPJACK, 20);
                if (Creepjack)
                {
                    Creepjack->Attack(player, true);
                    Creepjack->setFaction(14);
                    Creepjack->GetMotionMaster()->MoveChase(player);
                    Creepjack->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                }
                Unit* Malone = me->FindNearestCreature(NPC_MALONE, 20);
                if (Malone)
                {
                    Malone->Attack(player, true);
                    Malone->setFaction(14);
                    Malone->GetMotionMaster()->MoveChase(player);
                    Malone->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                }
                    DoStartMovement(player);
                    AttackStart(player);
                }
                Attack = false;
            }

            if (HealthBelowPct(5) && !Done)
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->RemoveAllAuras();

                Unit* Creepjack = me->FindNearestCreature(NPC_CREEPJACK, 20);
                if (Creepjack)
                {
                    CAST_CRE(Creepjack)->AI()->EnterEvadeMode();
                    Creepjack->setFaction(1194);
                    Creepjack->GetMotionMaster()->MoveTargetedHome();
                    Creepjack->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                }
                Unit* Malone = me->FindNearestCreature(NPC_MALONE, 20);
                if (Malone)
                {
                    CAST_CRE(Malone)->AI()->EnterEvadeMode();
                    Malone->setFaction(1194);
                    Malone->GetMotionMaster()->MoveTargetedHome();
                    Malone->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                }
                me->setFaction(1194);
                Done = true;
                DoScriptText(SAY_GIVEUP, me, NULL);
                me->DeleteThreatList();
                me->CombatStop();
                me->GetMotionMaster()->MoveTargetedHome();
                Player* player = Unit::GetPlayer(*me, PlayerGUID);
                if (player)
                    CAST_PLR(player)->GroupEventHappens(QUEST_WBI, me);
            }
            DoMeleeAttackIfReady();
        }
    };

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
        {
            CAST_AI(npc_dirty_larry::npc_dirty_larryAI, creature->AI())->Event = true;
            CAST_AI(npc_dirty_larry::npc_dirty_larryAI, creature->AI())->PlayerGUID = player->GetGUID();
            player->CLOSE_GOSSIP_MENU();
        }

        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->GetQuestStatus(QUEST_WBI) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_BOOK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_dirty_larryAI (creature);
    }

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

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
            player->SEND_GOSSIP_MENU(9458, creature->GetGUID());
        else if (uiAction == GOSSIP_ACTION_INFO_DEF+2)
            player->SEND_GOSSIP_MENU(9459, creature->GetGUID());

        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
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

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        switch (uiAction)
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
        if (creature->isQuestGiver())
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
    new npc_dirty_larry();
    new npc_ishanah();
    new npc_khadgar();
}
