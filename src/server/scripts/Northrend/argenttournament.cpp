/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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
#include "SpellAuraEffects.h"
#include "ScriptMgr.h"
#include "Group.h"
#include "ScriptedFollowerAI.h"

/*######
## Quest Soporte Threat From Above
## npc_Chillmaw
######*/

// UPDATE `creature_template` SET `ScriptName`='npc_chillmaw' WHERE `entry`=33687;
// *Known bug, The NPC doesn't despawns until server restarts

enum Chillmaw
{
    SPELL_FROST_BREATH  = 65248,
    SPELL_WING_BUFFET   = 65260,
    BOMBARDIER_1        = 0,
    BOMBARDIER_2        = 1,
    BOMBARDIER_3        = 2
};

enum TimersGral
{
    TIMER_SPELL_MIN         = 1000,
    TIMER_SPELL_MAX         = 2000,
    TIMER_MoviTimer_MIN     = 1000,
    TIMER_MoviTimer_MAX     = 2000
};

enum SpellGral
{
    SHIELD_BREAKER                          = 62626,
    CHARGE                                  = 68321,
    THRUST                                  = 62544,
    DEFEND                                  = 62552,
    RIDE_VEHICLE                            = 63151,
    PLAYER_ON_TOURNAMENT_MOUNT              = 63034,
    LANCE_EQUIPPED                          = 62853,
    SHIELD_LEVEL1                           = 62719,
    SHIELD_LEVEL2                           = 64100,
    SHIELD_LEVEL3                           = 63132,
    YELLOW_ROSE_FIREWORK                    = 11544
};


class npc_chillmaw : public CreatureScript
{
public:
    npc_chillmaw() : CreatureScript("npc_chillmaw") { }

    struct npc_chillmawAI : public ScriptedAI
    {
        npc_chillmawAI(Creature *c) : ScriptedAI(c), vehicle(c->GetVehicleKit())
        {
            assert(vehicle);
        }
        
        EventMap events;
        Vehicle *vehicle;

        uint32 Spell_FrostBreath_Timer;
        uint32 Spell_WingBuffet_Timer;

        bool Pasajero_1;
        bool Pasajero_2;
        bool Pasajero_3;

        void Reset()
        {
            me->SetReactState(REACT_AGGRESSIVE);            
            Spell_FrostBreath_Timer = 6000;
            Spell_WingBuffet_Timer = 1500;
            Pasajero_1 = false;
            Pasajero_2 = false;
            Pasajero_3 = false;
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;
            
            if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;
  
            if (Spell_FrostBreath_Timer <= diff)
            {   
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(pTarget, SPELL_FROST_BREATH);
                Spell_FrostBreath_Timer = urand(15000, 16500);
            } else Spell_FrostBreath_Timer -=diff;

            if (Spell_WingBuffet_Timer <= diff)
            {
                DoCast(me, SPELL_WING_BUFFET);
                Spell_WingBuffet_Timer = urand(4000, 6500);
            } else Spell_WingBuffet_Timer -= diff;

            if (!Pasajero_1 && (me->GetHealth() < me->GetMaxHealth() * 0.70))
            {
                if (Creature *Bombardier1 = CAST_CRE(vehicle->GetPassenger(BOMBARDIER_1)))
                {
                    Bombardier1->ExitVehicle();
                    Bombardier1->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    Bombardier1->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    Bombardier1->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
                    Bombardier1->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                }
                Pasajero_1 = true;
            }

            if (!Pasajero_2 && (me->GetHealth() < me->GetMaxHealth() * 0.50))
            {
                if (Creature *Bombardier2 = CAST_CRE(vehicle->GetPassenger(BOMBARDIER_2)))
                {
                    Bombardier2->ExitVehicle();
                    Bombardier2->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    Bombardier2->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    Bombardier2->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
                    Bombardier2->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                }
                Pasajero_2 = true;
            }

            if (!Pasajero_3 && (me->GetHealth() < me->GetMaxHealth() * 0.25))
            {
                if (Creature *Bombardier3 = CAST_CRE(vehicle->GetPassenger(BOMBARDIER_3)))
                {
                    Bombardier3->ExitVehicle();
                    Bombardier3->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);                    
                    Bombardier3->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    Bombardier3->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
                    Bombardier3->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                }
                Pasajero_3 = true;
            }
            DoMeleeAttackIfReady();
        }
    };

    void EnterCombat(Unit* /*who*/) { }
        
    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_chillmawAI (pCreature);
    }
};

/*######
## npc_vendor_argent_tournament
UPDATE `creature_template` SET `ScriptName`='npc_vendor_argent_tournament' WHERE `entry` IN (33553, 33554, 33556, 33555, 33557, 33307, 33310, 33653, 33650, 33657);
######*/

const uint32 ArgentTournamentVendor[10][4] =
{
    {33553,13726,2,14460},  // Orc
    {33554,13726,8,14464},  // Troll
    {33556,13728,6,14458},  // Tauren
    {33555,13729,5,14459},  // Undead
    {33557,13731,10,14465}, // Blood Elf
    {33307,13699,1,14456},  // Human
    {33310,13713,3,14457},  // Dwarf
    {33653,13725,4,14463},  // Night Elf
    {33650,13723,7,14462},  // Gnome
    {33657,13724,11,14461}  // Draenei
};

class npc_vendor_argent_tournament : public CreatureScript
{
public:
    npc_vendor_argent_tournament() : CreatureScript("npc_vendor_argent_tournament") { }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        bool npcCheck = false;
        bool questCheck = false;
        bool raceCheck = false;
        uint32 textId = 0;
	
        for (int i = 0; (i < 10) && !npcCheck; i++)
        {
            if (pCreature->GetEntry() == ArgentTournamentVendor[i][0])
            {
                npcCheck = true;
                questCheck = pPlayer->GetQuestStatus(ArgentTournamentVendor[i][1]) == QUEST_STATUS_COMPLETE;
                raceCheck = pPlayer->getRace() == ArgentTournamentVendor[i][2];
                textId = ArgentTournamentVendor[i][3];
		    }
	    }
	
        if (questCheck || raceCheck)
            pPlayer->GetSession()->SendListInventory(pCreature->GetGUID()); 
        else
            pPlayer->SEND_GOSSIP_MENU(textId, pCreature->GetGUID());
        return true;
    }
};


/*######
* quest_givers_argent_tournament
UPDATE `creature_template` SET `ScriptName`='quest_givers_argent_tournament' WHERE `entry` IN (33593, 33592, 33225, 33312, 33335, 33379, 33373, 33361, 33403, 33372);
######*/

class quest_givers_argent_tournament : public CreatureScript
{
public:
    quest_givers_argent_tournament(): CreatureScript("quest_givers_argent_tournament"){}

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {

            if (pCreature->isQuestGiver())
            {    
                Object *pObject = (Object*)pCreature;
                QuestRelations* pObjectQR = sObjectMgr->GetCreatureQuestRelationMap();
                QuestRelations* pObjectQIR = sObjectMgr->GetCreatureQuestInvolvedRelation();
                QuestMenu &qm = pPlayer->PlayerTalkClass->GetQuestMenu();
                qm.ClearMenu();
                
                for (QuestRelations::const_iterator i = pObjectQIR->lower_bound(pObject->GetEntry()); i != pObjectQIR->upper_bound(pObject->GetEntry()); ++i)
                {
                    uint32 quest_id = i->second;
                    QuestStatus status = pPlayer->GetQuestStatus(quest_id);
                    if (status == QUEST_STATUS_COMPLETE && !pPlayer->GetQuestRewardStatus(quest_id))
                        qm.AddMenuItem(quest_id, 4);
                    else if (status == QUEST_STATUS_INCOMPLETE)
                        qm.AddMenuItem(quest_id, 4);
                    //else if (status == QUEST_STATUS_AVAILABLE)
                    //    qm.AddMenuItem(quest_id, 2);
                }
                
                bool EligibilityAlliance = pPlayer->GetQuestStatus(13686) == QUEST_STATUS_COMPLETE;
                bool EligibilityHorde = pPlayer->GetQuestStatus(13687) == QUEST_STATUS_COMPLETE;

                for (QuestRelations::const_iterator i = pObjectQR->lower_bound(pObject->GetEntry()); i != pObjectQR->upper_bound(pObject->GetEntry()); ++i)
                {
                    uint32 quest_id = i->second;
                    Quest const* pQuest = sObjectMgr->GetQuestTemplate(quest_id);

                    if (!pQuest) 
                        continue;

                    switch (quest_id)
                    {
                        case 13707: // Valiant Of Orgrimmar
                        case 13708: // Valiant Of Sen'jin
                        case 13709: // Valiant Of Thunder Bluff
                        case 13710: // Valiant Of Undercity
                        case 13711: // Valiant Of Silvermoon
                            if(!EligibilityHorde)
                            {
                                QuestStatus status = pPlayer->GetQuestStatus(quest_id);
                                if (pQuest->IsAutoComplete() && pPlayer->CanTakeQuest(pQuest, false))
                                    qm.AddMenuItem(quest_id, 4);
                                else 
                                    if (status == QUEST_STATUS_NONE && pPlayer->CanTakeQuest(pQuest, false))
                                        qm.AddMenuItem(quest_id, 2);
                            }
                            break;
                        case 13593: // Valiant Of Stormwind
                        case 13703: // Valiant Of Ironforge
                        case 13706: // Valiant Of Darnassus
                        case 13704: // Valiant Of Gnomeregan
                        case 13705: // Valiant Of The Exodar
                            if (!EligibilityAlliance)
                            {
                                QuestStatus status = pPlayer->GetQuestStatus(quest_id);
                                if (pQuest->IsAutoComplete() && pPlayer->CanTakeQuest(pQuest, false))
                                    qm.AddMenuItem(quest_id, 4);
                                else 
                                    if (status == QUEST_STATUS_NONE && pPlayer->CanTakeQuest(pQuest, false))
                                        qm.AddMenuItem(quest_id, 2);
                            }
                            break;
                        default:
                            QuestStatus status = pPlayer->GetQuestStatus(quest_id);

                            if (pQuest->IsAutoComplete() && pPlayer->CanTakeQuest(pQuest, false))
                                qm.AddMenuItem(quest_id, 4);
                            else 
                                if (status == QUEST_STATUS_NONE && pPlayer->CanTakeQuest(pQuest, false))
                                    qm.AddMenuItem(quest_id, 2);
                            break;
                    }
                }
            }
            pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
            return true;
    }
};

/*######
## npc_dame_evniki_kapsalis
######*/

enum eDameEnvikiKapsalis
{
    TITLE_CRUSADER    = 123
};

class npc_dame_evniki_kapsalis : public CreatureScript
{
public:
    npc_dame_evniki_kapsalis() : CreatureScript("npc_dame_evniki_kapsalis") { }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pPlayer->HasTitle(TITLE_CRUSADER))
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_TRADE)
            pPlayer->GetSession()->SendListInventory(pCreature->GetGUID());
        return true;
    }
};

/*######
* npc_quest_givers_for_crusaders
UPDATE `creature_template` SET `ScriptName`='npc_quest_givers_for_crusaders' WHERE `entry` IN (34882, 35094);
######*/

class npc_quest_givers_for_crusaders : public CreatureScript
{
public:
    npc_quest_givers_for_crusaders() : CreatureScript("npc_quest_givers_for_crusaders") { }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pPlayer->HasTitle(TITLE_CRUSADER))
            if (pCreature->isQuestGiver())
                pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
        return true;
    }
};

/*######
## npc_squire_david
######*/

enum eSquireDavid
{
    QUEST_THE_ASPIRANT_S_CHALLENGE_H                    = 13680,
    QUEST_THE_ASPIRANT_S_CHALLENGE_A                    = 13679,
    NPC_ARGENT_VALIANT                                  = 33448,
    GOSSIP_TEXTID_SQUIRE                                = 14407
};

#define GOSSIP_SQUIRE_ITEM_1 "I am ready to fight!"
#define GOSSIP_SQUIRE_ITEM_2 "How do the Argent Crusader raiders fight?"

class npc_squire_david : public CreatureScript
{
public:
    npc_squire_david() : CreatureScript("npc_squire_david") { }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if ((pPlayer->GetQuestStatus(QUEST_THE_ASPIRANT_S_CHALLENGE_H) == QUEST_STATUS_INCOMPLETE) ||
            (pPlayer->GetQuestStatus(QUEST_THE_ASPIRANT_S_CHALLENGE_A) == QUEST_STATUS_INCOMPLETE) && 
            (pPlayer->HasAura(RIDE_VEHICLE)) &&
            (pPlayer->HasAura(PLAYER_ON_TOURNAMENT_MOUNT)) &&
            (pPlayer->HasAura(LANCE_EQUIPPED)) &&
            (!pPlayer->isInCombat()))
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SQUIRE_ITEM_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SQUIRE_ITEM_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
        }

        pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_SQUIRE, pCreature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();

        if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
        {
            pPlayer->CLOSE_GOSSIP_MENU();
            pCreature->SummonCreature(NPC_ARGENT_VALIANT,8575.451f,952.472f,547.554f,0.38f);
        }
        return true;
    }
};

/*######
## npc_argent_valiant
######*/

enum eArgentValiant
{
    SPELL_CHARGE                = 63010,
    SPELL_SHIELD_BREAKER        = 65147,
    SPELL_DEFEND                = 62719,
    SPELL_THRUST                = 62544,

    NPC_ARGENT_VALIANT_CREDIT   = 38595
};

enum eValiantText
{
    NPC_FACTION_VAILIANT_TEXT_SAY_START_1   = -1850004, //Stand ready!
    NPC_FACTION_VAILIANT_TEXT_SAY_START_2   = -1850005, //Let the battle begin!
    NPC_FACTION_VAILIANT_TEXT_SAY_START_3   = -1850006, //Prepare your self!
    NPC_ARGENT_VAILIANT_TEXT_SAY_START      = -1850007, //You think you have the courage?  We shall see.
    NPC_ARGENT_VAILIANT_TEXT_SAY_WIN        = -1850008, //Impressive demonstration. I think you\'re able to join the ranks of the valiants.
    NPC_ARGENT_VAILIANT_TEXT_SAY_LOOSE      = -1850009, //I\'ve won. You'll probably have more luck next time.
    NPC_FACTION_VAILIANT_TEXT_SAY_WIN_1     = -1850010, //I stand defeated. Nice battle !
    NPC_FACTION_VAILIANT_TEXT_SAY_WIN_2     = -1850011, //It seems that I\'ve underestimated your skills. Well done.'
    NPC_FACTION_VAILIANT_TEXT_SAY_LOOSE     = -1850012  //You\'ll probably have more luck next time.
 };

class npc_argent_valiant : public CreatureScript
{
public:
    npc_argent_valiant() : CreatureScript("npc_argent_valiant") { }

    struct npc_argent_valiantAI : public ScriptedAI
    {
        npc_argent_valiantAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            me->CastSpell(me, SPELL_DEFEND, true);
            me->CastSpell(me, SPELL_DEFEND, true);
            pCreature->GetMotionMaster()->MovePoint(0,8599.258f,963.951f,547.553f);
            pCreature->setFaction(35); 
        }

        uint32 uiChargeTimer;
        uint32 uiShieldBreakerTimer;
        uint32 uiDefendTimer;

        void Reset()
        {
            uiChargeTimer = 7000;
            uiShieldBreakerTimer = 10000;
        }

        void MovementInform(uint32 uiType, uint32 /*uiId*/)
        {
            if (uiType != POINT_MOTION_TYPE)
                return;

            me->setFaction(14);
        }

        void DamageTaken(Unit* pDoneBy, uint32& uiDamage)
        {
            if(pDoneBy)
            {
                if (uiDamage > me->GetHealth() && (pDoneBy->GetTypeId() == TYPEID_PLAYER || pDoneBy->GetOwner()))
                {
                    DoScriptText(NPC_ARGENT_VAILIANT_TEXT_SAY_WIN, me);
                    uiDamage = 0;

                    if (pDoneBy->GetOwner())
                        (pDoneBy->GetOwner())->ToPlayer()->KilledMonsterCredit(NPC_ARGENT_VALIANT_CREDIT,0);
                    if (pDoneBy->GetTypeId() == TYPEID_PLAYER)
                        pDoneBy->ToPlayer()->KilledMonsterCredit(NPC_ARGENT_VALIANT_CREDIT,0);

                    me->setFaction(35);
                    me->ForcedDespawn(5000);
                    me->SetHomePosition(me->GetPositionX(),me->GetPositionY(),me->GetPositionZ(),me->GetOrientation());
                    EnterEvadeMode();
                }
            }
        }

        void KilledUnit(Unit* /*victim*/)
        {
            me->setFaction(35);
            me->ForcedDespawn(5000);
            DoScriptText(NPC_ARGENT_VAILIANT_TEXT_SAY_LOOSE, me);
            me->CombatStop(true);
        }

        void DoMeleeAttackIfReady()
        {
            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            if (me->isAttackReady())
            {
                if (me->IsWithinMeleeRange(me->getVictim()))
                {
                    DoCastVictim(SPELL_THRUST);
                    me->resetAttackTimer();
                }
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(NPC_ARGENT_VAILIANT_TEXT_SAY_START, me);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            if (uiChargeTimer <= uiDiff)
            {
                DoCastVictim(SPELL_CHARGE);
                uiChargeTimer = 7000;
            } else uiChargeTimer -= uiDiff;

            if (uiShieldBreakerTimer <= uiDiff)
            {
                DoCastVictim(SPELL_SHIELD_BREAKER);
                uiShieldBreakerTimer = 10000;
            } else uiShieldBreakerTimer -= uiDiff;

            if (uiDefendTimer <= uiDiff)
            {
                me->CastSpell(me, SPELL_DEFEND, true);
                uiDefendTimer = 10000;
            } else uiDefendTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_argent_valiantAI(creature);
    }
};

/*######
* npc_crusader_rhydalla
######*/

class npc_crusader_rhydalla : public CreatureScript
{
public:
    npc_crusader_rhydalla(): CreatureScript("npc_crusader_rhydalla"){}

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        // uint64 const guid = pCreature->GetGUID();

        if (pCreature->isQuestGiver())
        {    
            Object *pObject = (Object*)pCreature;
            QuestRelations* pObjectQR = sObjectMgr->GetCreatureQuestRelationMap();
            QuestRelations* pObjectQIR = sObjectMgr->GetCreatureQuestInvolvedRelation();
            QuestMenu &qm = pPlayer->PlayerTalkClass->GetQuestMenu();
            qm.ClearMenu();

            for (QuestRelations::const_iterator i = pObjectQIR->lower_bound(pObject->GetEntry()); i != pObjectQIR->upper_bound(pObject->GetEntry()); ++i)
            {
                uint32 quest_id = i->second;
                QuestStatus status = pPlayer->GetQuestStatus(quest_id);
                if (status == QUEST_STATUS_COMPLETE && !pPlayer->GetQuestRewardStatus(quest_id))
                    qm.AddMenuItem(quest_id, 4);
                else if (status == QUEST_STATUS_INCOMPLETE)
                    qm.AddMenuItem(quest_id, 4);
                //else if (status == QUEST_STATUS_AVAILABLE)
                //    qm.AddMenuItem(quest_id, 2);
            }

            for (QuestRelations::const_iterator i = pObjectQR->lower_bound(pObject->GetEntry()); i != pObjectQR->upper_bound(pObject->GetEntry()); ++i)
            {
                uint32 quest_id = i->second;
                Quest const* pQuest = sObjectMgr->GetQuestTemplate(quest_id);
                if (!pQuest)
                    continue;
                QuestStatus status;
                bool allowed = false;

                switch(quest_id)
                {
                    case 13664: // The Black Knigh's Fall
                        allowed = (pPlayer->GetQuestStatus(13700) == QUEST_STATUS_COMPLETE) || (pPlayer->GetQuestStatus(13701) == QUEST_STATUS_COMPLETE);
                        if (allowed)
                        {
                            status = pPlayer->GetQuestStatus(quest_id);
                            if (pQuest->IsAutoComplete() && pPlayer->CanTakeQuest(pQuest, false))
                                qm.AddMenuItem(quest_id, 4);
                            else 
                                if (status == QUEST_STATUS_NONE && pPlayer->CanTakeQuest(pQuest, false))
                                    qm.AddMenuItem(quest_id, 2);
                        }
                        break;
                    default:
                        status = pPlayer->GetQuestStatus(quest_id);
                        if (pQuest->IsAutoComplete() && pPlayer->CanTakeQuest(pQuest, false))
                            qm.AddMenuItem(quest_id, 4);
                        else 
                            if (status == QUEST_STATUS_NONE && pPlayer->CanTakeQuest(pQuest, false))
                                qm.AddMenuItem(quest_id, 2);
                        break;
                }
            }
        }
        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
        return true;
    }
};

/*######
* npc_eadric_the_pure
######*/

class npc_eadric_the_pure : public CreatureScript
{
public:
    npc_eadric_the_pure(): CreatureScript("npc_eadric_the_pure"){}
        
    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        // uint64 const guid = pCreature->GetGUID();

        if (pCreature->isQuestGiver())
        {    
            Object *pObject = (Object*)pCreature;
            QuestRelations* pObjectQR = sObjectMgr->GetCreatureQuestRelationMap();
            QuestRelations* pObjectQIR = sObjectMgr->GetCreatureQuestInvolvedRelation();

            QuestMenu &qm = pPlayer->PlayerTalkClass->GetQuestMenu();
            qm.ClearMenu();

            for (QuestRelations::const_iterator i = pObjectQIR->lower_bound(pObject->GetEntry()); i != pObjectQIR->upper_bound(pObject->GetEntry()); ++i)
            {
                uint32 quest_id = i->second;
                QuestStatus status = pPlayer->GetQuestStatus(quest_id);
                if (status == QUEST_STATUS_COMPLETE && !pPlayer->GetQuestRewardStatus(quest_id))
                    qm.AddMenuItem(quest_id, 4);
                else 
                    if (status == QUEST_STATUS_INCOMPLETE)
                        qm.AddMenuItem(quest_id, 4);
                //else if (status == QUEST_STATUS_AVAILABLE)
                //    qm.AddMenuItem(quest_id, 2);
            }

            for (QuestRelations::const_iterator i = pObjectQR->lower_bound(pObject->GetEntry()); i != pObjectQR->upper_bound(pObject->GetEntry()); ++i)
            {
                uint32 quest_id = i->second;
                Quest const* pQuest = sObjectMgr->GetQuestTemplate(quest_id);
                if (!pQuest) continue;
                QuestStatus status;
                bool allowed=false;
                
                switch(quest_id)
                {
                    case 13682: // Alliance Threat From Above
                    case 13809: // Horde Threat From Above
                        allowed = (pPlayer->GetQuestStatus(13664) == QUEST_STATUS_COMPLETE) && pPlayer->GetQuestRewardStatus(13664);
                        if (allowed)
                        {
                            status = pPlayer->GetQuestStatus(quest_id);
                            if (pQuest->IsAutoComplete() && pPlayer->CanTakeQuest(pQuest, false))
                                qm.AddMenuItem(quest_id, 4);
                            else 
                                if (status == QUEST_STATUS_NONE && pPlayer->CanTakeQuest(pQuest, false))
                                    qm.AddMenuItem(quest_id, 2);
                        }
                        break;
                    default:
                        status = pPlayer->GetQuestStatus(quest_id);

                        if (pQuest->IsAutoComplete() && pPlayer->CanTakeQuest(pQuest, false))
                            qm.AddMenuItem(quest_id, 4);
                        else 
                            if (status == QUEST_STATUS_NONE && pPlayer->CanTakeQuest(pQuest, false))
                                qm.AddMenuItem(quest_id, 2);
                        break;
                }
            }
        }
        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
        return true;
    }
};

/*######
* npc_justicar_mariel_trueheart
######*/

class npc_justicar_mariel_trueheart : public CreatureScript
{
public:
    npc_justicar_mariel_trueheart(): CreatureScript("npc_justicar_mariel_trueheart"){}

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        // uint64 const guid = pCreature->GetGUID();

        if (pCreature->isQuestGiver())
        {
            Object *pObject = (Object*)pCreature;
            QuestRelations* pObjectQR = sObjectMgr->GetCreatureQuestRelationMap();
            QuestRelations* pObjectQIR = sObjectMgr->GetCreatureQuestInvolvedRelation();

            QuestMenu &qm = pPlayer->PlayerTalkClass->GetQuestMenu();
            qm.ClearMenu();

            for (QuestRelations::const_iterator i = pObjectQIR->lower_bound(pObject->GetEntry()); i != pObjectQIR->upper_bound(pObject->GetEntry()); ++i)
            {
                uint32 quest_id = i->second;
                QuestStatus status = pPlayer->GetQuestStatus(quest_id);
                if (status == QUEST_STATUS_COMPLETE && !pPlayer->GetQuestRewardStatus(quest_id))
                    qm.AddMenuItem(quest_id, 4);
                else if (status == QUEST_STATUS_INCOMPLETE)
                    qm.AddMenuItem(quest_id, 4);
                //else if (status == QUEST_STATUS_AVAILABLE)
                //    qm.AddMenuItem(quest_id, 2);
            }

            for (QuestRelations::const_iterator i = pObjectQR->lower_bound(pObject->GetEntry()); i != pObjectQR->upper_bound(pObject->GetEntry()); ++i)
            {
                uint32 quest_id = i->second;
                Quest const* pQuest = sObjectMgr->GetQuestTemplate(quest_id);
                if (!pQuest) continue;
                QuestStatus status;
                bool allowed=false;

                switch(quest_id)
                {
                    case 13795: // The Scourgebane
                        allowed = (pPlayer->GetQuestStatus(13702) == QUEST_STATUS_COMPLETE && pPlayer->GetQuestRewardStatus(13702)) || (pPlayer->GetQuestStatus(13732) == QUEST_STATUS_COMPLETE && pPlayer->GetQuestRewardStatus(13732)) || (pPlayer->GetQuestStatus(13735) == QUEST_STATUS_COMPLETE && pPlayer->GetQuestRewardStatus(13735)) || (pPlayer->GetQuestStatus(13733) == QUEST_STATUS_COMPLETE && pPlayer->GetQuestRewardStatus(13733)) || (pPlayer->GetQuestStatus(13734) == QUEST_STATUS_COMPLETE && pPlayer->GetQuestRewardStatus(13734)) || (pPlayer->GetQuestStatus(13736) == QUEST_STATUS_COMPLETE && pPlayer->GetQuestRewardStatus(13736)) || (pPlayer->GetQuestStatus(13737) == QUEST_STATUS_COMPLETE && pPlayer->GetQuestRewardStatus(13737)) || (pPlayer->GetQuestStatus(13738) == QUEST_STATUS_COMPLETE && pPlayer->GetQuestRewardStatus(13738)) || (pPlayer->GetQuestStatus(13739) == QUEST_STATUS_COMPLETE && pPlayer->GetQuestRewardStatus(13739)) || (pPlayer->GetQuestStatus(13740) == QUEST_STATUS_COMPLETE && pPlayer->GetQuestRewardStatus(13740)); // If the player has finished any of the "A Champion Rises" quests                    
                        if (allowed)
                        {
                            status = pPlayer->GetQuestStatus(quest_id);
                            if (pQuest->IsAutoComplete() && pPlayer->CanTakeQuest(pQuest, false))
                                qm.AddMenuItem(quest_id, 4);
                            else 
                                if(status == QUEST_STATUS_NONE && pPlayer->CanTakeQuest(pQuest, false))
                                qm.AddMenuItem(quest_id, 2);
                        }
                        break;
                    default:
                        status = pPlayer->GetQuestStatus(quest_id);

                        if (pQuest->IsAutoComplete() && pPlayer->CanTakeQuest(pQuest, false))
                            qm.AddMenuItem(quest_id, 4);
                        else 
                            if (status == QUEST_STATUS_NONE && pPlayer->CanTakeQuest(pQuest, false))
                            qm.AddMenuItem(quest_id, 2);
                        break;
                }
            }
        }
        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
        return true;
    }
};

/*######
* npc_crok_scourgebane_argent
######*/

class npc_crok_scourgebane_argent : public CreatureScript
{
public:
    npc_crok_scourgebane_argent(): CreatureScript("npc_crok_scourgebane_argent"){}

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        // uint64 const guid = pCreature->GetGUID();

        if (pCreature->isQuestGiver())
        {
            Object *pObject = (Object*)pCreature;
            QuestRelations* pObjectQR = sObjectMgr->GetCreatureQuestRelationMap();
            QuestRelations* pObjectQIR = sObjectMgr->GetCreatureQuestInvolvedRelation();

            QuestMenu &qm = pPlayer->PlayerTalkClass->GetQuestMenu();
            qm.ClearMenu();

            for (QuestRelations::const_iterator i = pObjectQIR->lower_bound(pObject->GetEntry()); i != pObjectQIR->upper_bound(pObject->GetEntry()); ++i)
            {
                uint32 quest_id = i->second;
                QuestStatus status = pPlayer->GetQuestStatus(quest_id);
                if (status == QUEST_STATUS_COMPLETE && !pPlayer->GetQuestRewardStatus(quest_id))
                    qm.AddMenuItem(quest_id, 4);
                else 
                    if (status == QUEST_STATUS_INCOMPLETE)
                    qm.AddMenuItem(quest_id, 4);
                //else if (status == QUEST_STATUS_AVAILABLE)
                //    qm.AddMenuItem(quest_id, 2);
            }

            for (QuestRelations::const_iterator i = pObjectQR->lower_bound(pObject->GetEntry()); i != pObjectQR->upper_bound(pObject->GetEntry()); ++i)
            {
                uint32 quest_id = i->second;
                Quest const* pQuest = sObjectMgr->GetQuestTemplate(quest_id);
                if (!pQuest) continue;
                QuestStatus status;
                bool allowed=false;
               
                switch (quest_id)
                {
                    case 13788: // DK Threat From Above (Alliance)
                    case 13812: // DK Threat From Above (Horde)
                        allowed = (pPlayer->GetQuestStatus(13664) == QUEST_STATUS_COMPLETE) && pPlayer->GetQuestRewardStatus(13664);
                        if (allowed)
                        {
                            status = pPlayer->GetQuestStatus(quest_id);
                            if (pQuest->IsAutoComplete() && pPlayer->CanTakeQuest(pQuest, false))
                                qm.AddMenuItem(quest_id, 4);
                            else 
                                if (status == QUEST_STATUS_NONE && pPlayer->CanTakeQuest(pQuest, false))
                            qm.AddMenuItem(quest_id, 2);
                        }
                        break;
                    default:
                        status = pPlayer->GetQuestStatus(quest_id);
                        if (pQuest->IsAutoComplete() && pPlayer->CanTakeQuest(pQuest, false))
                            qm.AddMenuItem(quest_id, 4);
                        else 
                            if (status == QUEST_STATUS_NONE && pPlayer->CanTakeQuest(pQuest, false))
                                qm.AddMenuItem(quest_id, 2);
                        break;
                }
            }
        }
        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
        return true;
    }    
};

/*######
* npc_training_dummy_argent
######*/
// UPDATE `creature_template` SET `ScriptName`='npc_training_dummy_argent' WHERE `entry`=33229;
// UPDATE `creature_template` SET `ScriptName`='npc_training_dummy_argent' WHERE `entry`=33272;
// UPDATE `creature_template` SET `ScriptName`='npc_training_dummy_argent' WHERE `entry`=33243;
enum eTrainingdummy
{
	CREDIT_RANGE               = 33339,
	CREDIT_CHARGE              = 33340,
	CREDIT_MELEE               = 33341,
	NPC_MELEE                  = 33229,
	NPC_CHARGE                 = 33272,
	NPC_RANGE                  = 33243,
	SPELL_ARGENT_MELEE         = 62544,
	SPELL_ARGENT_CHARGE        = 68321,
	SPELL_ARGENT_BREAK_SHIELD  = 62626,  // spell goes't work
	SPELL_DEFEND_AURA          = 62719,  // it's spell spam in console
	SPELL_DEFEND_AURA_1        = 64100,  // it's spell spam in console
	NPC_ADVANCED_TARGET_DUMMY  = 2674,
	NPC_TARGET_DUMMY           = 2673
};

class npc_training_dummy_argent : public CreatureScript
{
public:
	npc_training_dummy_argent(): CreatureScript("npc_training_dummy_argent"){}
		
	struct npc_training_dummy_argentAI : Scripted_NoMovementAI
	{
	    npc_training_dummy_argentAI(Creature *pCreature) : Scripted_NoMovementAI(pCreature)
	    {
			Npc_Entry = pCreature->GetEntry();
	    }

			uint64 Npc_Entry;
			uint32 ResetTimer;
			uint32 DespawnTimer;
			uint32 ShielTimer;
	    void Reset()
	    {
			me->SetControlled(true,UNIT_STAT_STUNNED);//disable rotate
			me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);//imune to knock aways like blast wave
			me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
			ResetTimer = 5000;
			DespawnTimer = 15000;
			ShielTimer=0;
	    }

	    void EnterEvadeMode()
	    {
			if (!_EnterEvadeMode())
				return;
			Reset();
	    }

	    void DamageTaken(Unit * /*done_by*/, uint32 &damage)
	    {
			ResetTimer = 5000;
			damage = 0;
	    }

	    void EnterCombat(Unit * /*who*/)
	    {
		if (Npc_Entry != NPC_ADVANCED_TARGET_DUMMY && Npc_Entry != NPC_TARGET_DUMMY)
		    return;
	    }

		void SpellHit(Unit* caster,const SpellEntry* spell)
		{		
			if(caster->GetCharmerOrOwner())
			{
			Player * pPlayer = caster->GetCharmerOrOwner()->ToPlayer();
			switch (Npc_Entry)
				{
					case NPC_MELEE: // dummy melee
						if (pPlayer && spell->Id == SPELL_ARGENT_MELEE && (pPlayer->GetQuestStatus(13828) == QUEST_STATUS_INCOMPLETE || pPlayer->GetQuestStatus(13829) == QUEST_STATUS_INCOMPLETE))
							caster->GetCharmerOrOwner()->ToPlayer()->KilledMonsterCredit(CREDIT_MELEE, 0);
								return;
					case NPC_CHARGE: // dummy charge
						if (pPlayer && spell->Id == SPELL_ARGENT_CHARGE && (pPlayer->GetQuestStatus(13837) == QUEST_STATUS_INCOMPLETE || pPlayer->GetQuestStatus(13839) == QUEST_STATUS_INCOMPLETE))
							caster->GetCharmerOrOwner()->ToPlayer()->KilledMonsterCredit(CREDIT_CHARGE, 0);
								return;
					case NPC_RANGE: // dummy range
						if (pPlayer && spell->Id == SPELL_ARGENT_BREAK_SHIELD && (pPlayer->GetQuestStatus(13835) == QUEST_STATUS_INCOMPLETE || pPlayer->GetQuestStatus(13838) == QUEST_STATUS_INCOMPLETE))
							caster->GetCharmerOrOwner()->ToPlayer()->KilledMonsterCredit(CREDIT_RANGE, 0);
								return;
				}
			}
		}

	    void UpdateAI(const uint32 diff)
	    {
			if (ShielTimer <= diff)
			{
				if(Npc_Entry == NPC_RANGE)
					me->CastSpell(me,SPELL_DEFEND_AURA,true);

			if(Npc_Entry == NPC_CHARGE && !me->GetAura(SPELL_DEFEND_AURA_1))
						me->CastSpell(me,SPELL_DEFEND_AURA_1,true);
				ShielTimer = 8000;
			}
			else
				ShielTimer -= diff;

		if (!UpdateVictim())
		    return;
		if (!me->HasUnitState(UNIT_STAT_STUNNED))
		    me->SetControlled(true,UNIT_STAT_STUNNED);//disable rotate
			
		if (Npc_Entry != NPC_ADVANCED_TARGET_DUMMY && Npc_Entry != NPC_TARGET_DUMMY)
		{
			if (ResetTimer <= diff)
			{
				EnterEvadeMode();
				ResetTimer = 5000;
			}
			else
				ResetTimer -= diff;
				return;
			}
			else
			{
			if (DespawnTimer <= diff)
				me->DespawnOrUnsummon();
			else
				DespawnTimer -= diff;
			}
	    }
	    void MoveInLineOfSight(Unit * /*who*/){return;}
	};

	CreatureAI* GetAI(Creature* pCreature) const
	{
	    return new npc_training_dummy_argentAI(pCreature);
	}

};

void AddSC_ArgentTournament()
{
    new npc_training_dummy_argent;
}

/*######
## Npc Jeran Lockwood (33973)
#######*/
#define JERAN_DEFAULT_TEXTID 14453
#define JERAN_QUEST_TEXTID 14431
#define JERAN_RP_TEXTID 14434
#define GOSSIP_HELLO_JERAN_1 "Show me how to train with a Melee Target?"
#define GOSSIP_HELLO_JERAN_2 "Tell me more about Defend and Thrust!."
#define SPELL_CREDIT_JERAN 64113

class npc_jeran_lockwood : public CreatureScript
{
public:
    npc_jeran_lockwood() : CreatureScript("npc_jeran_lockwood") { }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if((pPlayer->GetQuestStatus(13828) == QUEST_STATUS_INCOMPLETE) || (pPlayer->GetQuestStatus(13829) == QUEST_STATUS_INCOMPLETE))
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_JERAN_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_JERAN_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
            pPlayer->SEND_GOSSIP_MENU(JERAN_QUEST_TEXTID, pCreature->GetGUID());
        }
        else
        {
            pPlayer->SEND_GOSSIP_MENU(JERAN_DEFAULT_TEXTID, pCreature->GetGUID());
        }
        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature /*pCreature*/, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        switch(uiAction)
        {
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->CastSpell(pPlayer,SPELL_CREDIT_JERAN,true);
            pPlayer->CLOSE_GOSSIP_MENU();
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_JERAN_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            pPlayer->SEND_GOSSIP_MENU(JERAN_RP_TEXTID, pCreature->GetGUID());
            break;
        }
        return true;
    }
};

/*#####
## Npc Rugan Steelbelly (33972)
#######*/
#define RUGAN_DEFAULT_TEXTID 14453
#define RUGAN_QUEST_TEXTID 14436
#define RUGAN_RP_TEXTID 14437
#define GOSSIP_HELLO_RUGAN_1 "Show me how to train with a Charge Target?"
#define GOSSIP_HELLO_RUGAN_2 "Tell me more about the Charge!"
#define SPELL_CREDIT_RUGAN 64114

class npc_rugan_steelbelly : public CreatureScript
{
public:
    npc_rugan_steelbelly() : CreatureScript("npc_rugan_steelbelly") { }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if((pPlayer->GetQuestStatus(13837) == QUEST_STATUS_INCOMPLETE) || (pPlayer->GetQuestStatus(13839) == QUEST_STATUS_INCOMPLETE))
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_RUGAN_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_RUGAN_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
            pPlayer->SEND_GOSSIP_MENU(RUGAN_QUEST_TEXTID, pCreature->GetGUID());
        }
        else
        {
            pPlayer->SEND_GOSSIP_MENU(RUGAN_DEFAULT_TEXTID, pCreature->GetGUID());
        }
        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature /*pCreature*/, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        switch(uiAction)
        {
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->CastSpell(pPlayer,SPELL_CREDIT_RUGAN,true);
            pPlayer->CLOSE_GOSSIP_MENU();
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_RUGAN_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            pPlayer->SEND_GOSSIP_MENU(RUGAN_RP_TEXTID, pCreature->GetGUID());
            break;
        }
        return true;
    }
};

/*######
## Npc Valis Windchaser
#######*/
#define VALIS_DEFAULT_TEXTID 14453
#define VALIS_QUEST_TEXTID 14438
#define VALIS_RP_TEXTID 14439
#define GOSSIP_HELLO_VALIS_1 "Show me how to train with a Ranged Target."
#define GOSSIP_HELLO_VALIS_2 "Tell me more about using the Shield-Breaker."
#define SPELL_CREDIT_VALIS 64115

class npc_valis_windchaser : public CreatureScript
{
public:
    npc_valis_windchaser() : CreatureScript("npc_valis_windchaser") { }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if((pPlayer->GetQuestStatus(13835) == QUEST_STATUS_INCOMPLETE) || 
            (pPlayer->GetQuestStatus(13838) == QUEST_STATUS_INCOMPLETE))
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_VALIS_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_VALIS_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
            pPlayer->SEND_GOSSIP_MENU(VALIS_QUEST_TEXTID, pCreature->GetGUID());
        }
        else
        pPlayer->SEND_GOSSIP_MENU(VALIS_DEFAULT_TEXTID, pCreature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature /*pCreature*/, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        
        switch (uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                pPlayer->CastSpell(pPlayer,SPELL_CREDIT_VALIS,true);
                pPlayer->CLOSE_GOSSIP_MENU();
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_VALIS_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                pPlayer->SEND_GOSSIP_MENU(VALIS_RP_TEXTID, pCreature->GetGUID());
                break;
        }
        return true;
    }
};

/*######
## npc_Keritose Quest Support 13172
-- Quest Support Seeds of Chaos (13172)
UPDATE creature_template SET type_flags=8, spell1=59234, spell2=53112, VehicleId=156, unk16=25, unk17=20, movementId=199, RegenHealth=1 WHERE entry=31157;
UPDATE creature_template SET `ScriptName` = 'npc_keritose', npcflag='3' WHERE entry=30946;
UPDATE creature_template SET KillCredit2=31555 WHERE entry IN (31554, 30949 , 30951)
######*/
#define GOSSIP_KERITOSE_I  "I am prepared to join the assault, keritose do you have a Skeletal Gryphon ready for me!"

enum eKeritose
{
	QUEST_SEEDS_OF_CHAOS	            	  = 13172,
	SPELL_TAXI_KERITOSE	       		          = 58698, 
};
class npc_keritose : public CreatureScript
{
public:
    npc_keritose() : CreatureScript("npc_keritose") { }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        if(pPlayer->GetQuestStatus(QUEST_SEEDS_OF_CHAOS) == QUEST_STATUS_INCOMPLETE)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_KERITOSE_I, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature /*pCreature*/, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
       
        switch (uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                pPlayer->CastSpell(pPlayer, SPELL_TAXI_KERITOSE, true);
                pPlayer->CLOSE_GOSSIP_MENU();
                break;
        }
        return true;
    }
};

/*######
## npc_valiant  
######*/

#define GOSSIP_VALIANT_1    "I am ready to fight."
//#define GOSSIP_VALIANT_GOSS "Are you sure you ready to fight a champion?"
#define SAY_START_1         "On your guard!"
#define SAY_START_2         "Prepare yourself!"
#define SAY_END             "I have been defeated. Good Fight !"

enum ValiantQuest
{
    QUEST_AMONG_THECHAMPIONS_A      = 13790,
    QUEST_AMONG_THECHAMPIONS_H      = 13811,
    QUEST_AMONG_THECHAMPIONS_A2     = 13793,
    QUEST_AMONG_THECHAMPIONS_H2     = 13814,
    MOUNTED_MELEE_VICTORY           = 63596

};

class npc_valiant : public CreatureScript
{
public:
    npc_valiant() : CreatureScript("npc_valiant") { }

    struct npc_valiantAI : public ScriptedAI
    {
        Unit *pTarget;
        uint32 SpellTimer,MoviTimer;
        int8 x,y;    
       
        npc_valiantAI(Creature* pCreature) : ScriptedAI(pCreature){}
       
        void Escudo()
        {
            if (Aura *cAura = me->GetAura(DEFEND))
            {
                switch (cAura->GetStackAmount())
                {
                    case 1:
                        me->RemoveAura(SHIELD_LEVEL2);
                        me->RemoveAura(SHIELD_LEVEL3);
                        me->CastSpell(me, SHIELD_LEVEL1, true);
                        break;
                    case 2:
                        me->RemoveAura(SHIELD_LEVEL1);
                        me->RemoveAura(SHIELD_LEVEL3);
                        me->CastSpell(me, SHIELD_LEVEL2, true);
                        break;
                    case 3:
                        me->RemoveAura(SHIELD_LEVEL2);
                        me->RemoveAura(SHIELD_LEVEL1);
                        me->CastSpell(me, SHIELD_LEVEL3, true);
                        break;
                }
            }
        }

        void Reset()
        {
            me->setFaction(35);
            me->SetReactState(REACT_PASSIVE);
            me->SetVisible(true);
        }
       
        void EnterCombat(Unit* who)
        {
            SpellTimer= urand(TIMER_SPELL_MIN,TIMER_SPELL_MAX );
            MoviTimer = urand(TIMER_MoviTimer_MIN,TIMER_MoviTimer_MAX);
        }
       
        void JustDied(Unit* Killer)
        {
            me->MonsterSay(SAY_END, LANG_UNIVERSAL, 0);
            me->setFaction(35);
            me->SetHealth(1);
            pTarget->CastSpell(pTarget, MOUNTED_MELEE_VICTORY, true);
            me->SetVisible(false);
        }
       
        void KilledUnit(Unit *victim)
        {
            Reset();
            EnterEvadeMode();
        }
       
        void SpellHit(Unit *caster, const SpellEntry *spell)
        {
            if ((spell->Id == SHIELD_BREAKER)||(spell->Id == CHARGE))
            {
                if (Aura *cAura = me->GetAura(DEFEND))
                {
                    switch (cAura->GetStackAmount())
                    {
                        case 0:
                        case 1:
                            me->RemoveAura(DEFEND);
                            me->RemoveAura(SHIELD_LEVEL2);
                            me->RemoveAura(SHIELD_LEVEL3);
                            me->RemoveAura(SHIELD_LEVEL1);
                            break;
                        case 2:
                            cAura->SetStackAmount(1);
                            break;
                        case 3:
                            cAura->SetStackAmount(2);
                            break;
                    }
                }
                Escudo();
            }
        }

        void SpellHitTarget(Unit *pTarget, const SpellEntry *spell)
        {
            if ((spell->Id == SHIELD_BREAKER)||(spell->Id == CHARGE))
            {
                if (Aura *pAura = pTarget->GetAura(DEFEND))
                {
                    switch (pAura->GetStackAmount())
                    {
                        case 0:
                            pTarget->RemoveAura(DEFEND);
                            break;
                        case 1:
                            pAura->SetStackAmount(0);
                            break;
                        case 2:
                            pAura->SetStackAmount(1);
                            break;
                        case 3:
                            pAura->SetStackAmount(2);
                            break;
                    }
                }
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            pTarget = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 200, true);
               
            if (SpellTimer<=uiDiff)
            {
                if (pTarget && me->IsInRange(pTarget,5,40,false))
                {
                    switch (urand(0,7))
                    {
                        case 0: 
                        case 1: 
                        case 2: 
                            DoCastAOE(SHIELD_BREAKER, true);
                            break;
                        case 3: 
                        case 4:
                        case 5:
                        case 6:
                            DoCastAOE(CHARGE, true);
                            break;
                        case 7:
                            me->CastSpell(me, DEFEND, true);
                            Escudo();
                            break;
                    }
                }
                else
                {
                    switch (urand(0,4))
                    {
                        case 0: 
                            me->CastSpell(me, DEFEND, true);
                            Escudo();
                            break;
                        case 1:
                        case 2:
                        case 3:
                        case 4:
                            DoCastAOE(THRUST, true);
                            break;
                    }
                }
                SpellTimer= urand(TIMER_SPELL_MIN,TIMER_SPELL_MAX );
            } else 
                SpellTimer -= uiDiff;
            if (MoviTimer<=uiDiff)
            {
                x =urand(0,7);
                y =urand(0,7);
                switch (urand(0,3))
                {
                    case 0:
                        me->GetMotionMaster()->MovePoint(0, (pTarget->GetPositionX()+x), (pTarget->GetPositionY()+y), pTarget->GetPositionZ());
                        break;
                    case 1: 
                        me->GetMotionMaster()->MovePoint(0, (pTarget->GetPositionX()-x), (pTarget->GetPositionY()+y), pTarget->GetPositionZ());
                        break;
                    case 2: 
                        me->GetMotionMaster()->MovePoint(0, (pTarget->GetPositionX()+x), (pTarget->GetPositionY()-y), pTarget->GetPositionZ());
                        break;
                    case 3: 
                        me->GetMotionMaster()->MovePoint(0, (pTarget->GetPositionX()-x), (pTarget->GetPositionY()-y), pTarget->GetPositionZ());
                        break;
                }
                MoviTimer = urand(TIMER_MoviTimer_MIN,TIMER_MoviTimer_MAX);
                } else 
                    MoviTimer -= uiDiff;

                DoMeleeAttackIfReady();
        }
    };

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        if (((pPlayer->GetQuestStatus(QUEST_AMONG_THECHAMPIONS_H) == QUEST_STATUS_INCOMPLETE)  ||
            (pPlayer->GetQuestStatus(QUEST_AMONG_THECHAMPIONS_H2) == QUEST_STATUS_INCOMPLETE) ||
            (pPlayer->GetQuestStatus(QUEST_AMONG_THECHAMPIONS_A) == QUEST_STATUS_INCOMPLETE)  ||
            (pPlayer->GetQuestStatus(QUEST_AMONG_THECHAMPIONS_A2) == QUEST_STATUS_INCOMPLETE)) &&
            (pPlayer->HasAura(RIDE_VEHICLE)) &&
            (pPlayer->HasAura(PLAYER_ON_TOURNAMENT_MOUNT)) &&
            (pPlayer->HasAura(LANCE_EQUIPPED)) &&
            (!pPlayer->isInCombat()))

        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_VALIANT_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
            return true;
        }
        return false;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
        {
            pPlayer->CLOSE_GOSSIP_MENU();
            pCreature->setFaction(14);
            pCreature->SetReactState(REACT_AGGRESSIVE);
            pCreature->MonsterSay(urand(0,1) ? SAY_START_1 : SAY_START_2, LANG_UNIVERSAL, 0);
            pCreature->AI()->AttackStart(pPlayer);
            pCreature->AddThreat(pPlayer, 0.0f);
            pCreature->SetInCombatWith(pPlayer);
            pPlayer->SetInCombatWith(pCreature);
        }
        return true;
    }        
            
    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_valiantAI (pCreature);
    }
};

/*######
## Free Your Mind Quest 12893
######*/

enum YourMind
{
    QUEST_FREE_YOUR_MIND                = 12893,
    SPELL_SOVEREIGN_ROD                 = 29070,
    NPC_VILE_CREDIT_BUNNY               = 29845,
    NPC_LADY_NIGHTSWOOD_CREDIT_BUNNY    = 29846,
    NPC_LEAPER_BUNNY                    = 29847
};

class npc_vile : public CreatureScript
{
public:
    npc_vile() : CreatureScript("npc_vile") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_vileAI (pCreature);
    }

    struct npc_vileAI : public ScriptedAI
    {
        npc_vileAI(Creature *c) : ScriptedAI(c) {}

        bool spellHit;

        void Reset()
        {
            spellHit = false;
        }

        void SpellHit(Unit *Hitter, const SpellEntry *Spellkind)
        {
            if ((Spellkind->Id == SPELL_SOVEREIGN_ROD) && !spellHit &&
                (Hitter->GetTypeId() == TYPEID_PLAYER) && (CAST_PLR(Hitter)->IsActiveQuest(QUEST_FREE_YOUR_MIND)))
            {
                CAST_PLR(Hitter)->KilledMonsterCredit(NPC_VILE_CREDIT_BUNNY, 0);
                spellHit = true;
            }
        }
    };

};

class npc_lady_nightswood : public CreatureScript
{
public:
    npc_lady_nightswood() : CreatureScript("npc_lady_nightswood") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_lady_nightswoodAI (pCreature);
    }

    struct npc_lady_nightswoodAI : public ScriptedAI
    {
        npc_lady_nightswoodAI(Creature *c) : ScriptedAI(c) {}

        bool spellHit;

        void Reset()
        {
            spellHit = false;
        }

        void SpellHit(Unit *Hitter, const SpellEntry *Spellkind)
        {
            if ((Spellkind->Id == SPELL_SOVEREIGN_ROD) && !spellHit &&
                (Hitter->GetTypeId() == TYPEID_PLAYER) && (CAST_PLR(Hitter)->IsActiveQuest(QUEST_FREE_YOUR_MIND)))
            {
                CAST_PLR(Hitter)->KilledMonsterCredit(NPC_LADY_NIGHTSWOOD_CREDIT_BUNNY, 0);
                spellHit = true;
            }
        }
    };

};

class npc_leaper : public CreatureScript
{
public:
    npc_leaper() : CreatureScript("npc_leaper") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_leaperAI (pCreature);
    }

    struct npc_leaperAI : public ScriptedAI
    {
        npc_leaperAI(Creature *c) : ScriptedAI(c) {}

        bool spellHit;

        void Reset()
        {
            spellHit = false;
        }

        void SpellHit(Unit *Hitter, const SpellEntry *Spellkind)
        {
            if ((Spellkind->Id == SPELL_SOVEREIGN_ROD) && !spellHit &&
                (Hitter->GetTypeId() == TYPEID_PLAYER) && (CAST_PLR(Hitter)->IsActiveQuest(QUEST_FREE_YOUR_MIND)))
            {
                CAST_PLR(Hitter)->KilledMonsterCredit(NPC_LEAPER_BUNNY, 0);
                spellHit = true;
            }
        }
    };

};

/*######
## The Grand Melee Quests 
## 13665-13745-13750-13756-13761-13767-13772-13777-13782-13787.- http://www.wowhead.com/search?q=The+Grand+Melee SELECT entry,title FROM quest_template WHERE title LIKE 'The Grand Melee%'
######*/

enum ValiantGrandMelee
{
    QUEST_GRAND_MELEE_1                     = 13665,
    QUEST_GRAND_MELEE_2                     = 13745,
    QUEST_GRAND_MELEE_3                     = 13750,
    QUEST_GRAND_MELEE_4                     = 13756,
    QUEST_GRAND_MELEE_5                     = 13761,
    QUEST_GRAND_MELEE_6                     = 13767,
    QUEST_GRAND_MELEE_7                     = 13772,
    QUEST_GRAND_MELEE_8                     = 13777,
    QUEST_GRAND_MELEE_9                     = 13782,
    QUEST_GRAND_MELEE_10                    = 13787,
    MOUNTED_MELEE_VICTORY_GRAND             = 62724, // Crea item Credit.
};   

#define GOSSIP_VALIANT_1_GRAND    "I am ready to fight."
#define SAY_START_1_GRAND         "On your guard!"
#define SAY_START_2_GRAND         "Prepare yourself!"
#define SAY_END_GRAND             "I have been defeated. Good Fight !"

class npc_ValiantGrandMelee : public CreatureScript
{
public:
    npc_ValiantGrandMelee() : CreatureScript("npc_ValiantGrandMelee") { }
    
    struct npc_ValiantGrandMeleeAI : public ScriptedAI
    {
        Unit *pTarget;
        uint32 SpellTimer,MoviTimer;
        int8 x,y;    
       
        npc_ValiantGrandMeleeAI(Creature* pCreature) : ScriptedAI(pCreature){}
       
        void Escudo()
        {
            if (Aura *cAura = me->GetAura(DEFEND))
            {
                switch (cAura->GetStackAmount())
                {
                    case 1:
                        me->RemoveAura(SHIELD_LEVEL2);
                        me->RemoveAura(SHIELD_LEVEL3);
                        me->CastSpell(me, SHIELD_LEVEL1, true);
                        break;
                    case 2:
                        me->RemoveAura(SHIELD_LEVEL1);
                        me->RemoveAura(SHIELD_LEVEL3);
                        me->CastSpell(me, SHIELD_LEVEL2, true);
                        break;
                    case 3:
                        me->RemoveAura(SHIELD_LEVEL2);
                        me->RemoveAura(SHIELD_LEVEL1);
                        me->CastSpell(me, SHIELD_LEVEL3, true);
                        break;
                }
            }
        }

        void Reset()
        {
            me->setFaction(35);
            me->SetReactState(REACT_PASSIVE);
            me->SetVisible(true);
        }
       
        void EnterCombat(Unit* who)
        {
            SpellTimer= urand(TIMER_SPELL_MIN,TIMER_SPELL_MAX);
            MoviTimer = urand(TIMER_MoviTimer_MIN,TIMER_MoviTimer_MAX);
        }
       
        void JustDied(Unit* Killer)
        {
            me->CastSpell(me,YELLOW_ROSE_FIREWORK , true); 
            me->MonsterSay(SAY_END, LANG_UNIVERSAL, 0);            
            me->setFaction(35);
            me->SetHealth(1);
            pTarget->CastSpell(pTarget, MOUNTED_MELEE_VICTORY_GRAND, true);
            me->SetVisible(false);
        }
       
        void KilledUnit(Unit *victim)
        {
            Reset();
            EnterEvadeMode();
        }
       
        void SpellHit(Unit *caster, const SpellEntry *spell)
        {
            if ((spell->Id == SHIELD_BREAKER)||(spell->Id == CHARGE))
            {
                if (Aura *cAura = me->GetAura(DEFEND))
                {
                    switch (cAura->GetStackAmount())
                    {
                        case 0:
                        case 1:
                            me->RemoveAura(DEFEND);
                            me->RemoveAura(SHIELD_LEVEL2);
                            me->RemoveAura(SHIELD_LEVEL3);
                            me->RemoveAura(SHIELD_LEVEL1);
                            break;
                        case 2:
                            cAura->SetStackAmount(1);
                            break;
                        case 3:
                            cAura->SetStackAmount(2);
                            break;
                    }
                }
                Escudo();
            }
        }
        
        void SpellHitTarget(Unit *pTarget, const SpellEntry *spell)
        {
            if ((spell->Id == SHIELD_BREAKER)||(spell->Id == CHARGE))
            {
                if (Aura *pAura = pTarget->GetAura(DEFEND))
                {
                    switch (pAura->GetStackAmount())
                    {
                        case 0:
                            pTarget->RemoveAura(DEFEND);
                            break;
                        case 1:
                            pAura->SetStackAmount(0);
                            break;
                        case 2:
                            pAura->SetStackAmount(1);
                            break;
                        case 3:
                            pAura->SetStackAmount(2);
                            break;
                    }
                }
            }
        }
       
        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            pTarget = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 200, true);
               
            if (SpellTimer<=uiDiff)
            {
                if (pTarget && me->IsInRange(pTarget,5,40,false))
                {
                    switch (urand(0,7))
                    {
                        case 0: 
                        case 1: 
                        case 2: 
                            DoCastAOE(SHIELD_BREAKER, true);
                            break;
                        case 3: 
                        case 4:
                        case 5:
                        case 6:
                            DoCastAOE(CHARGE, true);
                            break;
                        case 7:
                            me->CastSpell(me, DEFEND, true);
                            Escudo();
                            break;
                    }
                }
                else
                {
                    switch (urand(0,4))
                    {
                        case 0: 
                            me->CastSpell(me, DEFEND, true);
                            Escudo();
                            break;
                        case 1:
                        case 2:
                        case 3:
                        case 4:
                            DoCastAOE(THRUST, true);
                            break;
                    }
                }
                SpellTimer= urand(TIMER_SPELL_MIN,TIMER_SPELL_MAX);
                } else 
                    SpellTimer -= uiDiff;

                if (MoviTimer<=uiDiff)
                {
                    x =urand(0,7);
                    y =urand(0,7);
                    switch (urand(0,3))
                    {
                        case 0:
                            me->GetMotionMaster()->MovePoint(0, (pTarget->GetPositionX()+x), (pTarget->GetPositionY()+y), pTarget->GetPositionZ());
                            break;
                        case 1: 
                            me->GetMotionMaster()->MovePoint(0, (pTarget->GetPositionX()-x), (pTarget->GetPositionY()+y), pTarget->GetPositionZ());
                            break;
                        case 2: 
                            me->GetMotionMaster()->MovePoint(0, (pTarget->GetPositionX()+x), (pTarget->GetPositionY()-y), pTarget->GetPositionZ());
                            break;
                        case 3: 
                            me->GetMotionMaster()->MovePoint(0, (pTarget->GetPositionX()-x), (pTarget->GetPositionY()-y), pTarget->GetPositionZ());
                            break;
                    }
                    MoviTimer = urand(TIMER_MoviTimer_MIN,TIMER_MoviTimer_MAX);
                } else 
                    MoviTimer -= uiDiff;

                DoMeleeAttackIfReady();
        }
    };

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        if (((pPlayer->GetQuestStatus(QUEST_GRAND_MELEE_1) == QUEST_STATUS_INCOMPLETE) ||
            (pPlayer->GetQuestStatus(QUEST_GRAND_MELEE_2) == QUEST_STATUS_INCOMPLETE)   ||
            (pPlayer->GetQuestStatus(QUEST_GRAND_MELEE_3) == QUEST_STATUS_INCOMPLETE)   ||
            (pPlayer->GetQuestStatus(QUEST_GRAND_MELEE_4) == QUEST_STATUS_INCOMPLETE)   ||
            (pPlayer->GetQuestStatus(QUEST_GRAND_MELEE_5) == QUEST_STATUS_INCOMPLETE)   ||
            (pPlayer->GetQuestStatus(QUEST_GRAND_MELEE_6) == QUEST_STATUS_INCOMPLETE)   ||
            (pPlayer->GetQuestStatus(QUEST_GRAND_MELEE_7) == QUEST_STATUS_INCOMPLETE)   ||
            (pPlayer->GetQuestStatus(QUEST_GRAND_MELEE_8) == QUEST_STATUS_INCOMPLETE)   ||
            (pPlayer->GetQuestStatus(QUEST_GRAND_MELEE_9) == QUEST_STATUS_INCOMPLETE)   ||
            (pPlayer->GetQuestStatus(QUEST_GRAND_MELEE_10) == QUEST_STATUS_INCOMPLETE)) &&
            (pPlayer->HasAura(RIDE_VEHICLE)) &&
            (pPlayer->HasAura(PLAYER_ON_TOURNAMENT_MOUNT)) &&
            (pPlayer->HasAura(LANCE_EQUIPPED)) &&
            (!pPlayer->isInCombat()))
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_VALIANT_1_GRAND, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
            return true;
        }

        return false;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
        {
            pPlayer->CLOSE_GOSSIP_MENU();
            pCreature->setFaction(14);
            pCreature->SetReactState(REACT_AGGRESSIVE);
            pCreature->MonsterSay(urand(0,1) ? SAY_START_1_GRAND : SAY_START_2_GRAND, LANG_UNIVERSAL, 0);
            pCreature->AI()->AttackStart(pPlayer);
            pCreature->AddThreat(pPlayer, 0.0f);
            pCreature->SetInCombatWith(pPlayer);
            pPlayer->SetInCombatWith(pCreature);
        }

        return true;
    }

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_ValiantGrandMeleeAI(creature);
    }
};

/*######
## Squire Danny 
## Quest The Valiant's Challenge 13699-13713-13723-13724-13725-13726-13727-13728-13729-13731.
SELECT * FROM quest_template WHERE title LIKE 'The Valiant%s Challenge'
######*/

enum eSquireDanny
{
    NPC_ARGENT_CHAMPION_CREDIT                          = 33708,
    NPC_ARGENT_CHAMPION                                 = 33707,
    SAY_START_VALIANT                                   = -1850013,//"You believe you are ready to be a champion? Defend yourself!"  
    SAY_END_VALIANT                                     = -1850014//"Most impressive. You are worthy to gain the rank of champion"
};

struct QUEST_THE_VALIANT_CHALLENGE
{ 
  uint32 quest_id; 
};

QUEST_THE_VALIANT_CHALLENGE m_quest[] = {13699, 13713, 13723, 13724, 13725, 13726, 13727, 13728, 13729, 13731};

#define GOSSIP_SQUIRE_DANNY_1   "I am ready to fight!"

class npc_squire_danny : public CreatureScript
{
public:
    npc_squire_danny() : CreatureScript("npc_squire_danny") { }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {    
        for (int i = 0; i < 10; i++)
        {
            if (((pPlayer->GetQuestStatus(m_quest[i].quest_id) == QUEST_STATUS_INCOMPLETE))&&
                (pPlayer->HasAura(RIDE_VEHICLE)) &&
                (pPlayer->HasAura(PLAYER_ON_TOURNAMENT_MOUNT)) &&
                (pPlayer->HasAura(LANCE_EQUIPPED)) &&
                (!pPlayer->isInCombat()))
            {
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SQUIRE_DANNY_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

            }
        }

        pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_SQUIRE, pCreature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
        {
            pPlayer->CLOSE_GOSSIP_MENU();
            pCreature->SummonCreature(NPC_ARGENT_CHAMPION,8542.566406f,1086.951904f,556.769836f,1.044363f);
        }
        return true;
    }
};

/*######
## npc argent champion.
######*/

class npc_argent_champion : public CreatureScript
{
public:
    npc_argent_champion() : CreatureScript("npc_argent_champion") { }

    struct npc_argent_championAI : public ScriptedAI
    {
        npc_argent_championAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pCreature->GetMotionMaster()->MovePoint(0,8556.964844f,1114.514282f,556.787842f);            
            pCreature->setFaction(35); 
        }

        Unit *pTarget;
        uint32 SpellTimer,MoviTimer;
        int8 x,y;  

        void Escudo()
        {
            if (Aura *cAura = me->GetAura(DEFEND))
            {
                switch (cAura->GetStackAmount())
                {
                    case 1:
                        me->RemoveAura(SHIELD_LEVEL2);
                        me->RemoveAura(SHIELD_LEVEL3);
                        me->CastSpell(me, SHIELD_LEVEL1, true);
                        break;
                    case 2:
                        me->RemoveAura(SHIELD_LEVEL1);
                        me->RemoveAura(SHIELD_LEVEL3);
                        me->CastSpell(me, SHIELD_LEVEL2, true);
                        break;
                    case 3:
                        me->RemoveAura(SHIELD_LEVEL2);
                        me->RemoveAura(SHIELD_LEVEL1);
                        me->CastSpell(me, SHIELD_LEVEL3, true);
                        break;
                }
            }
        }

        void Reset(){ }

        void MovementInform(uint32 uiType, uint32 /*uiId*/)
        {
            if (uiType != POINT_MOTION_TYPE)
                return;
            me->setFaction(14);
        }

        void DamageTaken(Unit* pDoneBy, uint32& uiDamage)
        {
            if(pDoneBy)
            {
                if (uiDamage > me->GetHealth() && (pDoneBy->GetTypeId() == TYPEID_PLAYER || pDoneBy->GetOwner()))
                { 
                    me->CastSpell(me,YELLOW_ROSE_FIREWORK , true); // Fuegos Articiales al derrotarlo
                    DoScriptText(SAY_END_VALIANT , me);
                    uiDamage = 0;

                    if(pDoneBy->GetOwner())
                        (pDoneBy->GetOwner())->ToPlayer()->KilledMonsterCredit(NPC_ARGENT_CHAMPION_CREDIT,0);
                    if(pDoneBy->GetTypeId() == TYPEID_PLAYER)
                        pDoneBy->ToPlayer()->KilledMonsterCredit(NPC_ARGENT_CHAMPION_CREDIT,0);
                    
                    me->setFaction(35);
                    me->ForcedDespawn(5000);
                    me->SetHomePosition(me->GetPositionX(),me->GetPositionY(),me->GetPositionZ(),me->GetOrientation());
                    EnterEvadeMode();
                }
            }
        }

        void KilledUnit(Unit* /*victim*/)
        {
            me->setFaction(35);
            me->ForcedDespawn(5000);           
            me->CombatStop(true);
        }      
       
        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(SAY_START_VALIANT, me);
            SpellTimer= urand(TIMER_SPELL_MIN,TIMER_SPELL_MAX);
            MoviTimer = urand(TIMER_MoviTimer_MIN,TIMER_MoviTimer_MAX);
        }

        void SpellHit(Unit *caster, const SpellEntry *spell)
        {
            if ((spell->Id == SHIELD_BREAKER)||(spell->Id == CHARGE))
            {
                if (Aura *cAura = me->GetAura(DEFEND))
                {
                    switch (cAura->GetStackAmount())
                    {
                        case 0:
                        case 1:
                            me->RemoveAura(DEFEND);
                            me->RemoveAura(SHIELD_LEVEL2);
                            me->RemoveAura(SHIELD_LEVEL3);
                            me->RemoveAura(SHIELD_LEVEL1);
                            break;
                        case 2:
                            cAura->SetStackAmount(1);
                            break;
                        case 3:
                            cAura->SetStackAmount(2);
                            break;
                    }
                }
                Escudo();
            }
        }

        void SpellHitTarget(Unit *pTarget, const SpellEntry *spell)
        {
            if ((spell->Id == SHIELD_BREAKER)||(spell->Id == CHARGE))
            {
                if (Aura *pAura = pTarget->GetAura(DEFEND))
                {
                    switch (pAura->GetStackAmount())
                    {
                        case 0:
                            pTarget->RemoveAura(DEFEND);
                            break;
                        case 1:
                            pAura->SetStackAmount(0);
                            break;
                        case 2:
                            pAura->SetStackAmount(1);
                            break;
                        case 3:
                            pAura->SetStackAmount(2);
                            break;
                    }
                }
            }
        }
       
        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            pTarget = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 200, true);
               
            if (SpellTimer<=uiDiff)
            {
                if (pTarget && me->IsInRange(pTarget,5,40,false))
                {
                    switch (urand(0,7))
                    {
                        case 0:
                        case 1:
                        case 2:
                            DoCastAOE(SHIELD_BREAKER, true);
                            break;
                        case 3: 
                        case 4:
                        case 5:
                        case 6:
                            DoCastAOE(CHARGE, true);
                            break;
                        case 7:
                            me->CastSpell(me, DEFEND, true);
                            Escudo();
                            break;
                    }
                }
                else
                {
                    switch (urand(0,4))
                    {
                        case 0: 
                            me->CastSpell(me, DEFEND, true);
                            Escudo();
                            break;
                        case 1:
                        case 2:
                        case 3:
                        case 4:
                            DoCastAOE(THRUST, true);
                            break;
                    }
                }
                SpellTimer= urand(TIMER_SPELL_MIN,TIMER_SPELL_MAX );
            } else 
                SpellTimer -= uiDiff;

            if (MoviTimer<=uiDiff)
            {
                x =urand(0,7);
                y =urand(0,7);
                switch (urand(0,3))
                {
                    case 0:
                        me->GetMotionMaster()->MovePoint(0, (pTarget->GetPositionX()+x), (pTarget->GetPositionY()+y), pTarget->GetPositionZ());
                        break;
                    case 1: 
                        me->GetMotionMaster()->MovePoint(0, (pTarget->GetPositionX()-x), (pTarget->GetPositionY()+y), pTarget->GetPositionZ());
                        break;
                    case 2: 
                        me->GetMotionMaster()->MovePoint(0, (pTarget->GetPositionX()+x), (pTarget->GetPositionY()-y), pTarget->GetPositionZ());
                        break;
                    case 3: 
                        me->GetMotionMaster()->MovePoint(0, (pTarget->GetPositionX()-x), (pTarget->GetPositionY()-y), pTarget->GetPositionZ());
                        break;
                }
                MoviTimer = urand(TIMER_MoviTimer_MIN,TIMER_MoviTimer_MAX);
            } else
                MoviTimer -= uiDiff;

                DoMeleeAttackIfReady();
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_argent_championAI(creature);
    }
};

/*######
## Argent Tournament: Quest There's Something About the Squire "13654"
######*/

enum Maloric
{
    SPELL_INCAPACITATE_MALORIC              = 63124,
    SPELL_SEARCH_MALORIC_CREDIT             = 63126,
    QUEST_THERES_SOMETHING_ABOUT_THE_SQUIRE = 13654
};

class npc_maloric : public CreatureScript
{
public:
    npc_maloric() : CreatureScript("npc_maloric") {}

    struct npc_maloricAI : public ScriptedAI
    {
        npc_maloricAI(Creature *c) : ScriptedAI(c) {}
        
        void Reset() {}

        void SpellHit(Unit* pCaster, const SpellEntry* spell)
        {
            if (pCaster->GetTypeId() == TYPEID_PLAYER)
            {
                if (spell->Id == SPELL_INCAPACITATE_MALORIC && CAST_PLR(pCaster)->GetQuestStatus(QUEST_THERES_SOMETHING_ABOUT_THE_SQUIRE) == QUEST_STATUS_INCOMPLETE)
                {
                    DoCast(pCaster, SPELL_SEARCH_MALORIC_CREDIT, true);
                    me->DespawnOrUnsummon();
                }        
            }           
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_maloricAI(creature);
    }
};

/*######
##  npc_Scarlet_Onslaught 
######*/

enum Scarlet_Onslaught
{
    SPELL_DARKMENDERS_TINCTURE         = 52741, 
    QUEST_FROM_THEIR_CORPORSES_RISE    = 12813,
    NPC_CREDIT_BUNNY                   = 29398 // Quest template
};

class npc_Scarlet_Onslaught : public CreatureScript
{
public:
    npc_Scarlet_Onslaught() : CreatureScript("npc_Scarlet_Onslaught") {}

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_Scarlet_OnslaughtAI(creature);
    }	

    struct npc_Scarlet_OnslaughtAI : public ScriptedAI
    {
        npc_Scarlet_OnslaughtAI(Creature *c) : ScriptedAI(c) {}

        void SpellHit(Unit* pCaster, const SpellEntry* spell)
        {
            if (pCaster->GetTypeId() == TYPEID_PLAYER)
            {
                if (spell->Id == SPELL_DARKMENDERS_TINCTURE && CAST_PLR(pCaster)->GetQuestStatus(QUEST_FROM_THEIR_CORPORSES_RISE) == QUEST_STATUS_INCOMPLETE)
                    me->DespawnOrUnsummon();
            }           
        }
	};
};

/*######
## Quest 13042
## "Deep in the Bowels of The Underhalls"
######*/
enum eOsterkilgr
{
    SAY_QUEST1                                   = -1603500,
    SAY_QUEST2                                   = -1603501,    
    SPELL_FIREBALL                               = 14034,
    SPELL_FIRE_WAVE                              = 60290,
    QUEST_DEEP_IN_THE_BOWELS_OF_THE_UNDERHALLS   = 13042,
    CREATURE_CREDIT_BUNNY                        = 30412,
};

class npc_apprentice_osterkilgr : public CreatureScript
{
public:
    npc_apprentice_osterkilgr() : CreatureScript("npc_apprentice_osterkilgr") { }

    CreatureAI *GetAI(Creature *pCreature) const
    {
        return new npc_apprentice_osterkilgrAI(pCreature);
    }

    struct npc_apprentice_osterkilgrAI : public ScriptedAI
    {
        npc_apprentice_osterkilgrAI(Creature *pCreature) : ScriptedAI(pCreature) { }

        uint64 uiPlayerGUID;
        uint32 uiBlastWaveTimer;
        uint32 uiFireballTimer;
        uint32 uiYellTimer;
        bool bYelled;

        void Reset()
        {
            uiPlayerGUID = NULL;
            uiBlastWaveTimer = urand(8000,10000);
            uiFireballTimer = urand(2000,3000);
            bYelled = false;
        }

        void EnterCombat(Unit * pWho)
        {
            if (pWho->GetTypeId() == TYPEID_PLAYER)
                uiPlayerGUID = pWho->GetGUID();                
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;
            
            if (Player *pPlayer = Unit::GetPlayer(*me, uiPlayerGUID))
            {                
                if (HealthBelowPct(40))
                {
                    if (!bYelled)
                    {
                        DoScriptText(SAY_QUEST1, me);
                        DoScriptText(SAY_QUEST2, me);
                        bYelled = true;
                    }

                    if (Group *pGroup = pPlayer->GetGroup())
                    {
                        for (GroupReference *itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
                        {
                            Player *PlayerGroup = itr->getSource();
                            if (PlayerGroup->isAlive() && PlayerGroup->IsAtGroupRewardDistance(me))
                                PlayerGroup->KilledMonsterCredit(CREATURE_CREDIT_BUNNY, 0);
                        }
                    }
                    else
                        pPlayer->KilledMonsterCredit(CREATURE_CREDIT_BUNNY, 0);
                }
            }

            if (uiBlastWaveTimer <= uiDiff)
            {
                DoCast(me->getVictim(), SPELL_FIRE_WAVE);
                uiBlastWaveTimer = urand(8000,10000);
            }
            else
                uiBlastWaveTimer -= uiDiff;

            if (uiFireballTimer <= uiDiff)
            {
                DoCast(me->getVictim(), SPELL_FIREBALL);
                uiFireballTimer = urand(3000,4000);
            }
            else
                uiFireballTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };
};

/*######
## Quest 13231 - 13228 (A/H) - 13232
## "The Broken Front"
## "Finish Me!"
######*/
enum eSoldier
{
    SAY_KILL_QUEST1                              = -1603511,
    SAY_KILL_QUEST2                              = -1603512,
    SAY_KILL_QUEST3                              = -1603513,
    SAY_KILL_QUEST4                              = -1603514,
    SAY_KILL_QUEST5                              = -1603515,
    SAY_QUEST_SOLDIER1                           = -1603516,
    SAY_QUEST_SOLDIER2                           = -1603517,
    SAY_QUEST_SOLDIER3                           = -1603518,
    SAY_QUEST_SOLDIER4                           = -1603519,
    SAY_QUEST_SOLDIER5                           = -1603520,
    SAY_QUEST_SOLDIER6                           = -1603521,
    SAY_QUEST_SOLDIER7                           = -1603522,
    SAY_QUEST_BERSERKER1                         = -1603523,
    SAY_QUEST_BERSERKER2                         = -1603524,
    SAY_QUEST_BERSERKER3                         = -1603525,
    SAY_QUEST_BERSERKER4                         = -1603526,
    SAY_QUEST_BERSERKER5                         = -1603527,
    SAY_QUEST_BERSERKER6                         = -1603528,
    SAY_QUEST_BERSERKER7                         = -1603529,
    SAY_QUEST_BERSERKER8                         = -1603530,
    CREATURE_DYING_SOLDIER_KC                    = 31312,
    CREATURE_DYING_BERSERKER_KC                  = 31272,
    QUEST_FINISH_ME                              = 13232,
    QUEST_THE_BROKEN_FRONT_A                     = 13231,
    QUEST_THE_BROKEN_FRONT_H                     = 13228,
};

#define GOSSIP_ITEM_DYING_SOLDIER   "Travel well, hero of the Alliance!"
#define GOSSIP_ITEM_DYING_SOLDIER1  "Stay with me, friend. I must know what happened here."
#define GOSSIP_ITEM_DYING_BERSERKER "Stay with me, friend. I must know what happened here."

class npc_dying_soldier : public CreatureScript
{
public:
    npc_dying_soldier() : CreatureScript("npc_dying_soldier") { }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pPlayer->GetQuestStatus(QUEST_FINISH_ME) == QUEST_STATUS_INCOMPLETE)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_DYING_SOLDIER, GOSSIP_SENDER_MAIN, GOSSIP_SENDER_INFO);

        if (pPlayer->GetQuestStatus(QUEST_THE_BROKEN_FRONT_A) == QUEST_STATUS_INCOMPLETE)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_DYING_SOLDIER1, GOSSIP_SENDER_MAIN, GOSSIP_SENDER_INFO+1);
            
        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        
        if (uiAction == GOSSIP_SENDER_INFO)
        {
            pPlayer->CLOSE_GOSSIP_MENU();
            if (pPlayer->GetQuestStatus(QUEST_FINISH_ME) == QUEST_STATUS_INCOMPLETE)
                pPlayer->KilledMonsterCredit(CREATURE_DYING_SOLDIER_KC, 0);
            pCreature->Kill(pCreature);
            DoScriptText(RAND(SAY_KILL_QUEST1, SAY_KILL_QUEST2, SAY_KILL_QUEST3, SAY_KILL_QUEST4, SAY_KILL_QUEST5), pCreature);
        }

        if (uiAction == GOSSIP_SENDER_INFO+1)
        {
            pPlayer->CLOSE_GOSSIP_MENU();
            DoScriptText(SAY_QUEST_SOLDIER1, pCreature);
            CAST_AI(npc_dying_soldier::npc_dying_soldierAI, pCreature->AI())->uiPlayerGUID = pPlayer->GetGUID();
            CAST_AI(npc_dying_soldier::npc_dying_soldierAI, pCreature->AI())->uiTalkTimer = 3000;
            CAST_AI(npc_dying_soldier::npc_dying_soldierAI, pCreature->AI())->bTalkTime = true;
        }

        return true;
    }
    
    CreatureAI *GetAI(Creature *pCreature) const
    {
        return new npc_dying_soldierAI(pCreature);
    }

    struct npc_dying_soldierAI : public ScriptedAI
    {
        npc_dying_soldierAI(Creature *pCreature) : ScriptedAI(pCreature) { }

        uint64 uiPlayerGUID;
        uint32 uiTalkTimer;
        uint32 uiStep;
        bool bTalkTime;

        void Reset()
        {
            uiPlayerGUID = 0;
            bTalkTime = false;
            uiStep = 0;
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (bTalkTime && uiTalkTimer <= uiDiff)
            {
                if (Player *pPlayer = Unit::GetPlayer(*me, uiPlayerGUID))
                {
                    switch(uiStep)
                    {
                        case 0:
                            DoScriptText(SAY_QUEST_SOLDIER2, me);
                            uiTalkTimer = 3000;
                            ++uiStep;
                            break;
                        case 1:
                            DoScriptText(SAY_QUEST_SOLDIER3, pPlayer);
                            uiTalkTimer = 3000;
                            ++uiStep;
                            break;
                        case 2:
                            DoScriptText(SAY_QUEST_SOLDIER4, me);
                            uiTalkTimer = 3000;
                            ++uiStep;
                            break;
                        case 3:
                            DoScriptText(SAY_QUEST_SOLDIER5, me);
                            uiTalkTimer = 3000;
                            ++uiStep;
                            break;
                        case 4:
                            DoScriptText(SAY_QUEST_SOLDIER6, me);
                            uiTalkTimer = 3000;
                            ++uiStep;
                            break;
                        case 5:
                            DoScriptText(SAY_QUEST_SOLDIER7, me);
                            if (pPlayer->GetQuestStatus(QUEST_THE_BROKEN_FRONT_A) == QUEST_STATUS_INCOMPLETE)
                                pPlayer->KilledMonsterCredit(CREATURE_DYING_SOLDIER_KC, 0);
                            bTalkTime = false;
                            uiStep = 0;
                            break;
                    }
                }
            }
            else
                uiTalkTimer -= uiDiff;
        }
    };
};

class npc_dying_berserker : public CreatureScript
{
public:
    npc_dying_berserker() : CreatureScript("npc_dying_berserker") { }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pPlayer->GetQuestStatus(QUEST_THE_BROKEN_FRONT_H) == QUEST_STATUS_INCOMPLETE)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_DYING_BERSERKER, GOSSIP_SENDER_MAIN, GOSSIP_SENDER_INFO);
            
        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        
        if (uiAction == GOSSIP_SENDER_INFO)
        {
            pPlayer->CLOSE_GOSSIP_MENU();
            DoScriptText(SAY_QUEST_BERSERKER1, pCreature);
            CAST_AI(npc_dying_berserker::npc_dying_berserkerAI, pCreature->AI())->uiPlayerGUID = pPlayer->GetGUID();
            CAST_AI(npc_dying_berserker::npc_dying_berserkerAI, pCreature->AI())->uiTalkTimer = 3000;
            CAST_AI(npc_dying_berserker::npc_dying_berserkerAI, pCreature->AI())->bTalkTime = true;
        }

        return true;
    }

    CreatureAI *GetAI(Creature *pCreature) const
    {
        return new npc_dying_berserkerAI(pCreature);
    }

    struct npc_dying_berserkerAI : public ScriptedAI
    {
        npc_dying_berserkerAI(Creature *pCreature) : ScriptedAI(pCreature) { }

        uint64 uiPlayerGUID;
        uint32 uiTalkTimer;
        uint32 uiStep;
        bool bTalkTime;

        void Reset()
        {
            uiPlayerGUID = 0;
            bTalkTime = false;
            uiStep = 0;
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (bTalkTime && uiTalkTimer <= uiDiff)
            {
                if (Player *pPlayer = Unit::GetPlayer(*me, uiPlayerGUID))
                {
                    switch(uiStep)
                    {
                        case 0:
                            DoScriptText(SAY_QUEST_BERSERKER2, me);
                            uiTalkTimer = 3000;
                            ++uiStep;
                            break;
                        case 1:
                            DoScriptText(SAY_QUEST_BERSERKER3, pPlayer);
                            uiTalkTimer = 3000;
                            ++uiStep;
                            break;
                        case 2:
                            DoScriptText(SAY_QUEST_BERSERKER4, me);
                            uiTalkTimer = 3000;
                            ++uiStep;
                            break;
                        case 3:
                            DoScriptText(SAY_QUEST_BERSERKER5, me);
                            uiTalkTimer = 3000;
                            ++uiStep;
                            break;
                        case 4:
                            DoScriptText(SAY_QUEST_BERSERKER6, me);
                            uiTalkTimer = 3000;
                            ++uiStep;
                            break;
                        case 5:
                            DoScriptText(SAY_QUEST_BERSERKER7, me);
                            uiTalkTimer = 3000;
                            ++uiStep;
                            break;
                        case 6:
                            DoScriptText(SAY_QUEST_BERSERKER8, me);
                            if (pPlayer->GetQuestStatus(QUEST_THE_BROKEN_FRONT_H) == QUEST_STATUS_INCOMPLETE)
                                pPlayer->KilledMonsterCredit(CREATURE_DYING_BERSERKER_KC, 0);
                            bTalkTime = false;
                            uiStep = 0;
                            break;
                    }
                }
            }
            else
                uiTalkTimer -= uiDiff;
        }
    };
};

/*######
## Quest A Blade Fit For A Champion Daily Argent Tournament.
## http://www.wowhead.com/search?q=A+Blade+Fit+For+A+Champion
## 13603, 13666, 13673, 13741, 13746, 13752, 13757, 13762, 13768, 13773, 13778, 13783
######*/

enum eLakeFrog
{
    SPELL_WARTSBGONE_LIP_BALM       = 62574,
    SPELL_FROG_LOVE                 = 62537,
    SPELL_WARTS                     = 62581,
    NPC_MAIDEN_OF_ASHWOOD_LAKE      = 33220,
    SAY_MAIDEM                      = -1850015 // Can it really be? Free after all these years?
};

struct QUEST_A_BLADE_FIT_FOR_A_CHAMPION
{ 
    uint32 quest_id; 
};

QUEST_A_BLADE_FIT_FOR_A_CHAMPION new_quest[] = 
{
    13603, 13666, 13673, 13741, 13746, 13752, 13757, 13762, 13768, 13773, 13778, 13783
};

class npc_lake_frog : public CreatureScript
{
public:
    npc_lake_frog() : CreatureScript("npc_lake_frog") { }

    struct npc_lake_frogAI : public FollowerAI 
    {
        npc_lake_frogAI(Creature *c) : FollowerAI(c) {}
       
        uint32 uiFollowTimer; 
        bool following;	
    
        void Reset () 
        {
            following = false;
            uiFollowTimer = 15000; // 15 seg te siguie la ranita
        }

        void UpdateAI(const uint32 diff)
        {
            if (following)
            {
                if (uiFollowTimer <= diff)
                {
                    SetFollowComplete();
                    me->DisappearAndDie();
                    me->Respawn(true);
                    Reset();
                }
                else uiFollowTimer-=diff;
            }
        }

        void ReceiveEmote(Player* pPlayer, uint32 emote)
        {
            if (following) 
                return;
			
            if (emote==TEXT_EMOTE_KISS)
                for (int i = 0; i < 12; i++)
                {
                    {
                        if (pPlayer->GetQuestStatus(new_quest[i].quest_id) == QUEST_STATUS_INCOMPLETE && !pPlayer->HasAura(SPELL_WARTSBGONE_LIP_BALM))
                            pPlayer->AddAura(SPELL_WARTS,pPlayer);
                        else if(roll_chance_i(10))
                        {
                            //if (Unit* pMaidem = me->SummonCreature(NPC_MAIDEN_OF_ASHWOOD_LAKE,me->GetPositionX(),me->GetPositionY(),me->GetPositionZ(),0,TEMPSUMMON_TIMED_DESPAWN,30000))
                            //{
                            pPlayer->SummonCreature(NPC_MAIDEN_OF_ASHWOOD_LAKE,me->GetPositionX(),me->GetPositionY(),me->GetPositionZ(),0,TEMPSUMMON_TIMED_DESPAWN,30000);
                            //DoScriptText(SAY_MAIDEM, pMaidem);
                            me->DisappearAndDie();		
                            me->Respawn(true); 
                            //}
                        }
                        else
                        {
                            pPlayer->RemoveAura(SPELL_WARTSBGONE_LIP_BALM);	
                            me->AddAura(SPELL_FROG_LOVE,me);
                            StartFollow(pPlayer, 35, NULL); 
                            following=true;
                        }
                    }
                }
        }
    };

    CreatureAI *GetAI(Creature *pCreature) const
    {
        return new npc_lake_frogAI(pCreature);
    }
};


enum MaidenOFAshwoodLake
{
    MAIDEN_DEFAULT_TEXTID       = 14319,
    MAIDEN_REWARD_TEXTID        = 14320,
    SPELL_SUMMON_ASHWOOD_BRAND  = 62554
};

#define GOSSIP_HELLO_MAIDEN "Glad to help. my lady. I'm toid you were once the guardian of a fabled sword. Do you know where I might find it?"

class npc_maiden_of_ashwood_lake : public CreatureScript
{
public:
    npc_maiden_of_ashwood_lake() : CreatureScript("npc_maiden_of_ashwood_lake") { }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if(!pPlayer->HasItemCount(44981,1,true))
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_MAIDEN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            pPlayer->SEND_GOSSIP_MENU(MAIDEN_DEFAULT_TEXTID, pCreature->GetGUID());
            pCreature->ForcedDespawn(10000);
            return true;
        }

        pPlayer->SEND_GOSSIP_MENU(MAIDEN_DEFAULT_TEXTID, pCreature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature /*pCreature*/, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        switch(uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                pPlayer->CastSpell(pPlayer,SPELL_SUMMON_ASHWOOD_BRAND,true);
                pPlayer->SEND_GOSSIP_MENU(MAIDEN_REWARD_TEXTID, pCreature->GetGUID());
                break;
        }
        return true;
    }
};

#define NPC_TEXTID_MAIDEN_OF_DRAK_MAR_01 -1850000
#define NPC_TEXTID_MAIDEN_OF_DRAK_MAR_02 -1850001
#define NPC_TEXTID_MAIDEN_OF_DRAK_MAR_03 -1850002
#define NPC_TEXTID_MAIDEN_OF_DRAK_MAR_04 -1850003
#define MAIDEN_OF_DRAK_MAR_TIMER_00 2000
#define MAIDEN_OF_DRAK_MAR_TIMER_01 5000
#define MAIDEN_OF_DRAK_MAR_TIMER_02 6000
#define MAIDEN_OF_DRAK_MAR_TIMER_03 7000
#define MAIDEN_OF_DRAK_MAR_TIMER_04 20000
#define MAIDEN_OF_DRAK_MAR_GOB_01 194239
#define MAIDEN_OF_DRAK_MAR_GOB_02 194238
//Summon  :X: 4602.977 Y: -1600.141 Z: 156.7834 O: 0.7504916

class npc_maiden_of_drak_mar : public CreatureScript
{
public:
    npc_maiden_of_drak_mar() : CreatureScript("npc_maiden_of_drak_mar") { }

    struct npc_maiden_of_drak_marAI : public ScriptedAI
    {
        uint32 phase;
        uint32 uiPhaseTimer;
        uint64 firstGobGuid;
        uint64 secondGobGuid;

        npc_maiden_of_drak_marAI(Creature *c) : ScriptedAI(c)
        {
            phase = 0;
            uiPhaseTimer = MAIDEN_OF_DRAK_MAR_TIMER_00;
            if(GameObject* go = me->SummonGameObject(MAIDEN_OF_DRAK_MAR_GOB_01,4602.977f,-1600.141f,156.7834f,0.7504916f,0,0,0,0,0))
                firstGobGuid = go->GetGUID();
        }

        void UpdateAI(const uint32 diff)
        {
            if (uiPhaseTimer <= diff)
            {
                phase++;
                switch (phase)
                {
                    case 1:
                        DoScriptText(NPC_TEXTID_MAIDEN_OF_DRAK_MAR_01, me);
                        uiPhaseTimer = MAIDEN_OF_DRAK_MAR_TIMER_01;
                        break;
                    case 2:
                        DoScriptText(NPC_TEXTID_MAIDEN_OF_DRAK_MAR_02, me);
                        uiPhaseTimer = MAIDEN_OF_DRAK_MAR_TIMER_02;
                        break;
                    case 3:
                       DoScriptText(NPC_TEXTID_MAIDEN_OF_DRAK_MAR_03, me);
                        uiPhaseTimer = MAIDEN_OF_DRAK_MAR_TIMER_03;
                        break;
                    case 4:
                        DoScriptText(NPC_TEXTID_MAIDEN_OF_DRAK_MAR_04, me);
                        if(GameObject* go = me->SummonGameObject(MAIDEN_OF_DRAK_MAR_GOB_02,4603.351f,-1599.288f,156.8822f,2.234018f,0,0,0,0,0))
                        secondGobGuid = go->GetGUID(); 
                        uiPhaseTimer = MAIDEN_OF_DRAK_MAR_TIMER_04;
                        break;
                    case 5:
                        if (GameObject* go = GameObject::GetGameObject(*me,firstGobGuid))
                            go->RemoveFromWorld();
                        if (GameObject* go = GameObject::GetGameObject(*me,secondGobGuid))
                            go->RemoveFromWorld();
                        me->ForcedDespawn();
                        break;
                    default:
                        if (GameObject* go = GameObject::GetGameObject(*me,firstGobGuid))
                            go->RemoveFromWorld();
                        if (GameObject* go = GameObject::GetGameObject(*me,secondGobGuid))
                            go->RemoveFromWorld();
                        me->ForcedDespawn();
                    break;
                }
            }
            else
            {
            uiPhaseTimer -= diff;
        }
    }
};
    CreatureAI *GetAI(Creature *pCreature) const
    {
        return new npc_maiden_of_drak_marAI(pCreature);
    }
};

/*######
Argent Tournament - Spell
Spell Fixed:
    - 62960 - Charge Mount Npc.
    - 62575 - Shield Mount Npc.
    - 62544 - Melee Mount Npc.
    - 62863 - Duel Mount Npc.

DELETE FROM `spell_script_names` WHERE `spell_id` IN (62960,62575,62544,62863);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
('62960', 'spell_tournament_charge'),
('62575', 'spell_tournament_shield'),
('62544', 'spell_tournament_melee'),
('62863', 'spell_tournament_duel');
######*/

class spell_tournament_charge : public SpellScriptLoader
{
public:
    spell_tournament_charge() : SpellScriptLoader("spell_tournament_charge") { }

    class spell_tournament_charge_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_tournament_charge_SpellScript);

        void HandleEffectScriptEffect(SpellEffIndex /*effIndex*/)
        {
            if (Unit* pTarget = GetHitUnit())
            {
                if (Unit *caster = GetCaster())
                {
                    caster->CastSpell(pTarget,74399,true);
                    caster->CastSpell(pTarget,68321,true);

                    if (pTarget->GetTypeId() == TYPEID_UNIT && pTarget->ToCreature()->GetEntry() == 33272)
                    {
                        // Kill Credit
                        if (Unit *player = caster->GetCharmerOrOwner())
                            player->CastSpell(player,62658,true);
                    }
                }

                if (pTarget->GetAura(64100))
                    pTarget->RemoveAuraFromStack(64100);
                else 
                    if (pTarget->GetAura(62552))
                        pTarget->RemoveAuraFromStack(62552);
                    else 
                        if (pTarget->GetAura(62719))
                            pTarget->RemoveAuraFromStack(62719);
            }
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_tournament_charge_SpellScript::HandleEffectScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript *GetSpellScript() const
    {
        return new spell_tournament_charge_SpellScript();
    }
};

class spell_tournament_shield : public SpellScriptLoader
{
public:
    spell_tournament_shield() : SpellScriptLoader("spell_tournament_shield") { }

    class spell_tournament_shield_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_tournament_shield_SpellScript);

        void HandleEffectScriptEffect(SpellEffIndex /*effIndex*/)
        {
            if (Unit* pTarget = GetHitUnit())
            {
                if (Unit *caster = GetCaster())
                {
                    caster->CastSpell(pTarget,62626,true );

                    if (pTarget->GetTypeId() == TYPEID_UNIT && pTarget->ToCreature()->GetEntry() == 33243)
                    {
                        // Kill Credit
                        if (Unit *player = caster->GetCharmerOrOwner())
                            player->CastSpell(player,62673,true);
                    }
                }

                if (pTarget->GetAura(64100))
                    pTarget->RemoveAuraFromStack(64100);
                else 
                    if (pTarget->GetAura(62552))
                        pTarget->RemoveAuraFromStack(62552);
                    else 
                        if (pTarget->GetAura(62719))
                            pTarget->RemoveAuraFromStack(62719);
            }
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_tournament_shield_SpellScript::HandleEffectScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript *GetSpellScript() const
    {
        return new spell_tournament_shield_SpellScript();
    }
};

class spell_tournament_melee : public SpellScriptLoader
{
public:
    spell_tournament_melee() : SpellScriptLoader("spell_tournament_melee") { }

    class spell_tournament_melee_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_tournament_melee_SpellScript);

        void HandleEffectScriptEffect(SpellEffIndex /*effIndex*/)
        {
            if (Unit* pTarget = GetHitUnit())
            {
                if (Unit *caster = GetCaster())
                {
                    if (pTarget->GetTypeId() == TYPEID_UNIT && pTarget->ToCreature()->GetEntry() == 33229)
                    {
                        // Kill Credit
                        if (Unit *player = caster->GetCharmerOrOwner())
                            player->CastSpell(player,62672,true);
                    }
                }
            }
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_tournament_melee_SpellScript::HandleEffectScriptEffect, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript *GetSpellScript() const
    {
        return new spell_tournament_melee_SpellScript();
    }
};

class spell_tournament_duel : public SpellScriptLoader
{
public:
    spell_tournament_duel() : SpellScriptLoader("spell_tournament_duel") { }

    class spell_tournament_duel_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_tournament_duel_SpellScript);

        void HandleEffectScriptEffect(SpellEffIndex /*effIndex*/)
        {
            if (Unit* pTarget = GetHitUnit())
            {
                if (pTarget->GetTypeId() != TYPEID_PLAYER)
                    return;

                if (Unit *caster = GetCaster()->GetCharmerOrOwner())
                    caster->CastSpell(pTarget,62875,true);
            }
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_tournament_duel_SpellScript::HandleEffectScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript *GetSpellScript() const
    {
        return new spell_tournament_duel_SpellScript();
    }
};

void AddSC_Argen_Tournament()
{
    new npc_chillmaw;
    new spell_tournament_charge;
    new spell_tournament_shield;
    new spell_tournament_melee;
    new spell_tournament_duel;
    new npc_dame_evniki_kapsalis;
    new npc_squire_david;
    new npc_argent_valiant;
    new npc_vendor_argent_tournament;
    new quest_givers_argent_tournament;
    new npc_quest_givers_for_crusaders;
    new npc_justicar_mariel_trueheart;
    new npc_crusader_rhydalla;
    new npc_eadric_the_pure;
    new npc_crok_scourgebane_argent;
    new npc_training_dummy_argent;
    new npc_valis_windchaser;
    new npc_rugan_steelbelly;
    new npc_jeran_lockwood;
    new npc_keritose;
    new npc_valiant;
    new npc_vile;
    new npc_lady_nightswood;
    new npc_leaper;
    new npc_ValiantGrandMelee;
    new npc_squire_danny;
    new npc_argent_champion;
    new npc_maloric;
    new npc_Scarlet_Onslaught;
    new npc_apprentice_osterkilgr;
    new npc_dying_soldier;
    new npc_dying_berserker;
    new npc_lake_frog;
    new npc_maiden_of_ashwood_lake;
    new npc_maiden_of_drak_mar;
}