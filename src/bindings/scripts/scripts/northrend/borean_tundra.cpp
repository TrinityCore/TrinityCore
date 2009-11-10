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
SDName: Borean_Tundra
SD%Complete: 100
SDComment: Quest support: 11708. Taxi vendors.
SDCategory: Borean Tundra
EndScriptData */

/* ContentData
npc_fizzcrank_fullthrottle
npc_surristrasz
npc_tiare
npc_iruk
npc_corastrasza
npc_jenny
npc_sinkhole_kill_credit
npc_khunok_the_behemoth
npc_scourge_prisoner
mob_nerubar_victim
npc_keristrasza
npc_nesingwary_trapper
npc_lurgglbr
npc_nexus_drake_hatchling
EndContentData */

#include "precompiled.h"
#include "escort_ai.h"
#include "follower_ai.h"

/*######
## npc_fizzcrank_fullthrottle
######*/

#define GOSSIP_ITEM_GO_ON   "Go on."
#define GOSSIP_ITEM_TELL_ME "Tell me what's going on out here, Fizzcrank."

enum eFizzcrank
{
    GOSSIP_TEXTID_FIZZCRANK1    = 12456,
    GOSSIP_TEXTID_FIZZCRANK2    = 12457,
    GOSSIP_TEXTID_FIZZCRANK3    = 12458,
    GOSSIP_TEXTID_FIZZCRANK4    = 12459,
    GOSSIP_TEXTID_FIZZCRANK5    = 12460,
    GOSSIP_TEXTID_FIZZCRANK6    = 12461,
    GOSSIP_TEXTID_FIZZCRANK7    = 12462,
    GOSSIP_TEXTID_FIZZCRANK8    = 12463,
    GOSSIP_TEXTID_FIZZCRANK9    = 12464,

    QUEST_THE_MECHAGNOMES       = 11708
};

bool GossipHello_npc_fizzcrank_fullthrottle(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (pPlayer->GetQuestStatus(QUEST_THE_MECHAGNOMES) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_TELL_ME, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    pPlayer->SEND_GOSSIP_MENU(pCreature->GetNpcTextId(), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_fizzcrank_fullthrottle(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_GO_ON, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_FIZZCRANK1, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_GO_ON, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_FIZZCRANK2, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+3:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_GO_ON, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_FIZZCRANK3, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+4:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_GO_ON, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_FIZZCRANK4, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+5:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_GO_ON, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_FIZZCRANK5, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+6:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_GO_ON, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_FIZZCRANK6, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+7:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_GO_ON, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_FIZZCRANK7, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+8:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_GO_ON, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_FIZZCRANK8, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+9:
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_FIZZCRANK9, pCreature->GetGUID());
            pPlayer->AreaExploredOrEventHappens(QUEST_THE_MECHAGNOMES);
            break;
    }
    return true;
}

/*######
## npc_surristrasz
######*/

#define GOSSIP_ITEM_FREE_FLIGHT "I'd like passage to the Transitus Shield."
#define GOSSIP_ITEM_FLIGHT      "May I use a drake to fly elsewhere?"

enum eSurristrasz
{
    SPELL_ABMER_TO_COLDARRA     = 46064
};

bool GossipHello_npc_surristrasz(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (pCreature->isTaxi())
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_FREE_FLIGHT, GOSSIP_SENDER_MAIN, GOSSIP_OPTION_GOSSIP);
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_ITEM_FLIGHT, GOSSIP_SENDER_MAIN, GOSSIP_OPTION_TAXIVENDOR);
    }

    pPlayer->SEND_GOSSIP_MENU(pCreature->GetNpcTextId(), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_surristrasz(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_OPTION_GOSSIP)
    {
        pPlayer->CLOSE_GOSSIP_MENU();

        //TaxiPath 795 (amber to coldarra)
        pPlayer->CastSpell(pPlayer, SPELL_ABMER_TO_COLDARRA, true);
    }

    if (uiAction == GOSSIP_OPTION_TAXIVENDOR)
        pPlayer->GetSession()->SendTaxiMenu(pCreature);

    return true;
}

/*######
## npc_tiare
######*/

#define GOSSIP_ITEM_TELEPORT    "Teleport me to Amber Ledge, please."

enum eTiare
{
    SPELL_TELEPORT_COLDARRA     = 50135
};

bool GossipHello_npc_tiare(Player* pPlayer, Creature* pCreature)
{
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_TELEPORT, GOSSIP_SENDER_MAIN, GOSSIP_OPTION_GOSSIP);
    pPlayer->SEND_GOSSIP_MENU(pCreature->GetNpcTextId(), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_tiare(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_OPTION_GOSSIP)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        pPlayer->CastSpell(pPlayer, SPELL_TELEPORT_COLDARRA, true);
    }
    return true;
}

/*######
## npc_sinkhole_kill_credit
######*/

enum eSinkhole
{
    SPELL_SET_CART                = 46797,
    SPELL_EXPLODE_CART            = 46799,
    SPELL_SUMMON_CART             = 46798,
    SPELL_SUMMON_WORM             = 46800,
};

struct TRINITY_DLL_DECL npc_sinkhole_kill_creditAI : public ScriptedAI
{
    npc_sinkhole_kill_creditAI(Creature* c) : ScriptedAI(c){}

    uint32 Phase_Timer;
    uint8  Phase;
    uint64 casterGuid;

    void Reset()
    {
        Phase_Timer = 500;
        Phase = 0;
        casterGuid = 0;
    }

    void SpellHit(Unit *caster, const SpellEntry *spell)
    {
        if (Phase)
            return;

        if (spell->Id == SPELL_SET_CART && caster->GetTypeId() == TYPEID_PLAYER
            && CAST_PLR(caster)->GetQuestStatus(11897) == QUEST_STATUS_INCOMPLETE)
        {
            Phase = 1;
            casterGuid = caster->GetGUID();
        }
    }

    void EnterCombat(Unit* who) { }

    void UpdateAI(const uint32 diff)
    {
        if (!Phase)
            return;

        if (Phase_Timer <= diff)
        {
            switch (Phase)
            {
                case 1:
                    DoCast(m_creature, SPELL_EXPLODE_CART, true);
                    DoCast(m_creature, SPELL_SUMMON_CART, true);
                    if (GameObject* cart = m_creature->FindNearestGameObject(188160,3))
                        cart->SetUInt32Value(GAMEOBJECT_FACTION, 14);
                    Phase_Timer = 3000;
                    Phase = 2;
                    break;
                case 2:
                    if (GameObject* cart = m_creature->FindNearestGameObject(188160,3))
                        cart->UseDoorOrButton();
                    DoCast(m_creature, SPELL_EXPLODE_CART, true);
                    Phase_Timer = 3000;
                    Phase = 3;
                    break;
                case 3:
                    DoCast(m_creature, SPELL_EXPLODE_CART, true);
                    Phase_Timer = 2000;
                    Phase = 4;
                case 5:
                    DoCast(m_creature, SPELL_SUMMON_WORM, true);
                    if (Unit* worm = m_creature->FindNearestCreature(26250, 3))
                    {
                        worm->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        worm->HandleEmoteCommand(EMOTE_ONESHOT_EMERGE);
                    }
                    Phase_Timer = 1000;
                    Phase = 6;
                    break;
                case 6:
                    DoCast(m_creature, SPELL_EXPLODE_CART, true);
                    if (Unit* worm = m_creature->FindNearestCreature(26250, 3))
                    {
                        m_creature->DealDamage(worm, worm->GetHealth());
                        worm->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
                    }
                    Phase_Timer = 2000;
                    Phase = 7;
                    break;
                case 7:
                    DoCast(m_creature, SPELL_EXPLODE_CART, true);
                    if(Player *caster = Unit::GetPlayer(casterGuid))
                        CAST_PLR(caster)->KilledMonster(m_creature->GetCreatureInfo(),m_creature->GetGUID());
                    Phase_Timer = 5000;
                    Phase = 8;
                    break;
                case 8:
                    EnterEvadeMode();
                    break;
            }
        } else Phase_Timer -= diff;

    }

};

CreatureAI* GetAI_npc_sinkhole_kill_credit(Creature* pCreature)
{
    return new npc_sinkhole_kill_creditAI(pCreature);
}

/*######
## npc_khunok_the_behemoth
######*/

struct TRINITY_DLL_DECL npc_khunok_the_behemothAI : public ScriptedAI
{
    npc_khunok_the_behemothAI(Creature *c) : ScriptedAI(c) {}

    void MoveInLineOfSight(Unit *who)
    {
        ScriptedAI::MoveInLineOfSight(who);

        if (who->GetTypeId() != TYPEID_UNIT)
            return;

        if (who->GetEntry() == 25861 && me->IsWithinDistInMap(who, 10.0f))
        {
            if (Unit *owner = who->GetOwner())
            {
                if (owner->GetTypeId() == TYPEID_PLAYER)
                {
                    DoCast(owner, 46231, true);
                    CAST_CRE(who)->ForcedDespawn();
                }
            }
        }
    }
};

CreatureAI* GetAI_npc_khunok_the_behemoth(Creature* pCreature)
{
    return new npc_khunok_the_behemothAI(pCreature);
}

/*######
## npc_keristrasza
######*/

enum eKeristrasza
{
    SPELL_TELEPORT_TO_SARAGOSA = 46772
};

#define GOSSIP_HELLO_KERI   "I am prepared to face Saragosa!"

bool GossipHello_npc_keristrasza(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (pPlayer->GetQuestStatus(11957) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_KERI, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

    pPlayer->SEND_GOSSIP_MENU(pCreature->GetNpcTextId(), pCreature->GetGUID());

    return true;
}

bool GossipSelect_npc_keristrasza(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF + 1)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        pPlayer->CastSpell(pPlayer, SPELL_TELEPORT_TO_SARAGOSA, true);
    }

    return true;
}

/*######
## npc_corastrasza
######*/

#define GOSSIP_ITEM_C_1 "I... I think so..."

enum eCorastrasza
{
    SPELL_SUMMON_WYRMREST_SKYTALON               = 61240,
    SPELL_WYRMREST_SKYTALON_RIDE_PERIODIC        = 61244,

    QUEST_ACES_HIGH_DAILY                        = 13414,
    QUEST_ACES_HIGH                              = 13413
};

bool GossipHello_npc_corastrasza(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (pPlayer->GetQuestStatus(QUEST_ACES_HIGH) == QUEST_STATUS_INCOMPLETE || pPlayer->GetQuestStatus(QUEST_ACES_HIGH_DAILY) == QUEST_STATUS_INCOMPLETE) //It's the same dragon for both quests.
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_C_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
    }

    pPlayer->SEND_GOSSIP_MENU(pCreature->GetNpcTextId(), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_corastrasza(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
    {
        pPlayer->CLOSE_GOSSIP_MENU();

        pPlayer->CastSpell(pPlayer, SPELL_SUMMON_WYRMREST_SKYTALON, true);
        pPlayer->CastSpell(pPlayer, SPELL_WYRMREST_SKYTALON_RIDE_PERIODIC, true);

    }

    return true;
}

/*######
## npc_iruk
######*/

#define GOSSIP_ITEM_I  "<Search corpse for Issliruk's Totem.>"

enum eIruk
{
    QUEST_SPIRITS_WATCH_OVER_US             = 11961,
    SPELL_CREATURE_TOTEM_OF_ISSLIRUK        = 46816,
    GOSSIP_TEXT_I                           = 12585
};

bool GossipHello_npc_iruk(Player* pPlayer, Creature* pCreature)
{

    if (pPlayer->GetQuestStatus(QUEST_SPIRITS_WATCH_OVER_US) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_I, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    pPlayer->PlayerTalkClass->SendGossipMenu(GOSSIP_TEXT_I, pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_iruk(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->CastSpell(pPlayer, SPELL_CREATURE_TOTEM_OF_ISSLIRUK, true);
            pPlayer->CLOSE_GOSSIP_MENU();
            break;

    }
    return true;
}
/*######
## mob_nerubar_victim
######*/

#define WARSONG_PEON        25270

const uint32 nerubarVictims[3] =
{
    45526, 45527, 45514
};
struct TRINITY_DLL_DECL mob_nerubar_victimAI : public ScriptedAI
{
    mob_nerubar_victimAI(Creature *c) : ScriptedAI(c) {}

    void Reset() {}
    void EnterCombat(Unit *who) {}
    void MoveInLineOfSight(Unit *who) {}

    void JustDied(Unit* Killer)
    {
        if(Killer->GetTypeId() == TYPEID_PLAYER)
        {
            if( CAST_PLR(Killer)->GetQuestStatus(11611) == QUEST_STATUS_INCOMPLETE)
            {
                uint8 uiRand = rand()%100;
                if(uiRand < 25)
                {
                    Killer->CastSpell(m_creature,45532,true);
                    CAST_PLR(Killer)->KilledMonsterCredit(WARSONG_PEON, 0);
                }
                else if(uiRand < 75)
                    Killer->CastSpell(m_creature,nerubarVictims[rand()%3],true);
            }
        }
    }
};
CreatureAI* GetAI_mob_nerubar_victim(Creature *pCreature)
{
    return new mob_nerubar_victimAI (pCreature);
}
/*######
## npc_scourge_prisoner
######*/

enum eScourgePrisoner
{
    GO_SCOURGE_CAGE = 187867
};

struct TRINITY_DLL_DECL npc_scourge_prisonerAI : public ScriptedAI
{
    npc_scourge_prisonerAI(Creature* pCreature) : ScriptedAI (pCreature){}
    
    void Reset()
    {
        m_creature->SetReactState(REACT_PASSIVE);
        
        if(GameObject* pGO = m_creature->FindNearestGameObject(GO_SCOURGE_CAGE,5.0f))
        {
            if(pGO->GetGoState() == GO_STATE_ACTIVE)
                pGO->SetGoState(GO_STATE_READY);
        }
    }
    
};
CreatureAI* GetAI_npc_scourge_prisoner(Creature* pCreature)
{
    return new npc_scourge_prisonerAI(pCreature);
}

/*######
## npc_jenny
######*/
enum eJenny
{
    QUEST_LOADER_UP             = 11881,

    NPC_FEZZIX_GEARTWIST        = 25849,
    NPC_JENNY                   = 25969,

    SPELL_GIVE_JENNY_CREDIT     = 46358,
    SPELL_CRATES_CARRIED        = 46340,
    SPELL_DROP_CRATE            = 46342
};

struct TRINITY_DLL_DECL npc_jennyAI : public ScriptedAI
{
    npc_jennyAI(Creature *c) : ScriptedAI(c) {}

    bool setCrateNumber;

    void Reset()
    {
        if(!setCrateNumber == false)
            setCrateNumber = true;

        m_creature->SetReactState(REACT_PASSIVE);

        if(((Player*)m_creature->GetOwner())->GetTeamId() == TEAM_ALLIANCE)
        {
            m_creature->setFaction(FACTION_ESCORT_A_NEUTRAL_ACTIVE);
        }else{
            m_creature->setFaction(FACTION_ESCORT_H_NEUTRAL_ACTIVE);
        }
    }

    void DamageTaken(Unit* pDone_by, uint32& uiDamage)
    {
        m_creature->CastSpell(m_creature,SPELL_DROP_CRATE,true);
    }

    void MoveInLineOfSight(Unit* pWho)
    {
        if(pWho->GetEntry() == NPC_FEZZIX_GEARTWIST)
        {
            if(((Player*)m_creature->GetOwner())->GetQuestStatus(QUEST_LOADER_UP) == QUEST_STATUS_INCOMPLETE && m_creature->GetAura(SPELL_CRATES_CARRIED))
            {
                m_creature->CastSpell(((Player*)m_creature->GetOwner()),SPELL_GIVE_JENNY_CREDIT,true); // Maybe is not working.
                ((Player*)m_creature->GetOwner())->CompleteQuest(QUEST_LOADER_UP);
                m_creature->DisappearAndDie();
            }
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if(setCrateNumber)
        {
            m_creature->AddAura(SPELL_CRATES_CARRIED,m_creature);
            setCrateNumber = false;
        }

        if(setCrateNumber == false && !m_creature->HasAura(SPELL_CRATES_CARRIED))
        {
            m_creature->DisappearAndDie();
        }

    }
};

CreatureAI* GetAI_npc_jenny(Creature *pCreature)
{
    return new npc_jennyAI (pCreature);
}

/*######
## npc_npc_nesingwary_trapper
######*/

enum eNesingwaryTrapper
{
    GO_HIGH_QUALITY_FUR = 187983,
    
    GO_CARIBOU_TRAP_1   = 187982,
    GO_CARIBOU_TRAP_2   = 187995,
    GO_CARIBOU_TRAP_3   = 187996,
    GO_CARIBOU_TRAP_4   = 187997,
    GO_CARIBOU_TRAP_5   = 187998,
    GO_CARIBOU_TRAP_6   = 187999,
    GO_CARIBOU_TRAP_7   = 188000,
    GO_CARIBOU_TRAP_8   = 188001,
    GO_CARIBOU_TRAP_9   = 188002,
    GO_CARIBOU_TRAP_10  = 188003,
    GO_CARIBOU_TRAP_11  = 188004,
    GO_CARIBOU_TRAP_12  = 188005,
    GO_CARIBOU_TRAP_13  = 188006,
    GO_CARIBOU_TRAP_14  = 188007,
    GO_CARIBOU_TRAP_15  = 188008,
    
    SPELL_TRAPPED       = 46104,
};

//#define SAY_NESINGWARY_1 -1571008

struct TRINITY_DLL_DECL npc_nesingwary_trapperAI : public ScriptedAI
{
    npc_nesingwary_trapperAI(Creature *c) : ScriptedAI(c) {m_creature->SetVisibility(VISIBILITY_OFF);}
    
    GameObject* go_caribou;
    uint8  Phase;
    uint32 Phase_Timer;
    
    void Reset()
    {
        m_creature->SetVisibility(VISIBILITY_OFF);
        Phase_Timer = 2500;
        Phase = 1;
	go_caribou = NULL;
    }
    void EnterCombat(Unit *who) {}
    void MoveInLineOfSight(Unit *who) {}
    
    void JustDied(Unit* who)
    {
        if (go_caribou && go_caribou->GetTypeId() == TYPEID_GAMEOBJECT)
	    go_caribou->SetLootState(GO_JUST_DEACTIVATED);
        
        TempSummon *summon = (TempSummon*)m_creature;
	if (summon)
	    if (Unit *pTemp = summon->GetSummoner())
	        if (pTemp->GetTypeId() == TYPEID_PLAYER)
		    CAST_PLR(pTemp)->KilledMonsterCredit(m_creature->GetEntry(),0);
        
        go_caribou->SetGoState(GO_STATE_READY);
    }
    
    void UpdateAI(const uint32 diff)
    {
        if (Phase_Timer < diff)
        {
            switch (Phase)
            {
                case 1:
                    m_creature->SetVisibility(VISIBILITY_ON);
                    
                    Phase_Timer = 2000;
                    Phase = 2;
                    break;
                    
                case 2:
                    if (GameObject* go_fur = m_creature->FindNearestGameObject(GO_HIGH_QUALITY_FUR,11.0f))
                        m_creature->GetMotionMaster()->MovePoint(0,go_fur->GetPositionX(),go_fur->GetPositionY(),go_fur->GetPositionZ());
                    Phase_Timer = 1500;
                    Phase = 3;
                    break;
                    
                case 3:
                    //DoScriptText(SAY_NESINGWARY_1, m_creature);
                    
                    Phase_Timer = 2000;
                    Phase = 4;
                    break;
                    
                case 4:
                    m_creature->HandleEmoteCommand(EMOTE_ONESHOT_LOOT);
                    
                    Phase_Timer = 1000;
                    Phase = 5;
                    break;
                    
                case 5:
                    m_creature->HandleEmoteCommand(EMOTE_ONESHOT_NONE);
                    
                    Phase_Timer = 500;
                    Phase = 6;
                    break;
                    
                case 6:
                    if (GameObject* go_fur = m_creature->FindNearestGameObject(GO_HIGH_QUALITY_FUR,11.0f))
                        go_fur->Delete();
                    
                    Phase_Timer = 500;
                    Phase = 7;
                    break;
                    
                case 7:
                    if ((go_caribou = m_creature->FindNearestGameObject(GO_CARIBOU_TRAP_1, 5.0f)) ||
                        (go_caribou = m_creature->FindNearestGameObject(GO_CARIBOU_TRAP_2, 5.0f)) ||
                        (go_caribou = m_creature->FindNearestGameObject(GO_CARIBOU_TRAP_3, 5.0f)) ||
                        (go_caribou = m_creature->FindNearestGameObject(GO_CARIBOU_TRAP_4, 5.0f)) ||
                        (go_caribou = m_creature->FindNearestGameObject(GO_CARIBOU_TRAP_5, 5.0f)) ||
                        (go_caribou = m_creature->FindNearestGameObject(GO_CARIBOU_TRAP_6, 5.0f)) ||
                        (go_caribou = m_creature->FindNearestGameObject(GO_CARIBOU_TRAP_7, 5.0f)) ||
                        (go_caribou = m_creature->FindNearestGameObject(GO_CARIBOU_TRAP_8, 5.0f)) ||
                        (go_caribou = m_creature->FindNearestGameObject(GO_CARIBOU_TRAP_9, 5.0f)) ||
                        (go_caribou = m_creature->FindNearestGameObject(GO_CARIBOU_TRAP_10, 5.0f)) ||
                        (go_caribou = m_creature->FindNearestGameObject(GO_CARIBOU_TRAP_11, 5.0f)) ||
                        (go_caribou = m_creature->FindNearestGameObject(GO_CARIBOU_TRAP_12, 5.0f)) ||
                        (go_caribou = m_creature->FindNearestGameObject(GO_CARIBOU_TRAP_13, 5.0f)) ||
                        (go_caribou = m_creature->FindNearestGameObject(GO_CARIBOU_TRAP_14, 5.0f)) ||
                        (go_caribou = m_creature->FindNearestGameObject(GO_CARIBOU_TRAP_15, 5.0f)))
                        
                        go_caribou->SetGoState(GO_STATE_ACTIVE);
                        
                    Phase = 8;
                    Phase_Timer = 1000;
                    break;
                        
                case 8:
                    m_creature->CastSpell(m_creature,SPELL_TRAPPED,true);
                    Phase = 0;
                    break;
            }
        } else Phase_Timer -= diff;
    }
};

CreatureAI* GetAI_npc_nesingwary_trapper(Creature *pCreature)
{
    return new npc_nesingwary_trapperAI (pCreature);
}

/*######
## npc_lurgglbr
######*/

enum eLurgglbr
{
    QUEST_ESCAPE_WINTERFIN_CAVERNS      = 11570,
    
    GO_CAGE                             = 187369,
    
    FACTION_ESCORTEE_A                  = 774,
    FACTION_ESCORTEE_H                  = 775,
};

#define SAY_WP_1_LUR_START  -1571004
#define SAY_WP_1_LUR_END    -1571005
#define SAY_WP_41_LUR_START -1571006
#define SAY_WP_41_LUR_END   -1571007

struct TRINITY_DLL_DECL npc_lurgglbrAI : public npc_escortAI
{
    npc_lurgglbrAI(Creature* c) : npc_escortAI(c){}
    
    uint32 IntroTimer;
    uint32 IntroPhase;
    
    void Reset()
    {
        IntroTimer = 0;
        IntroPhase = 0;
    }
    
    void WaypointReached(uint32 i)
    {
        switch(i)
        {
            case 0:
                IntroPhase = 1;
                IntroTimer = 2000;
                break;
            case 41:
                IntroPhase = 4;
                IntroTimer = 2000;
                break;
        }
    }
    
    void UpdateAI(const uint32 diff)
    {
        if (IntroPhase)
        {
            if (IntroTimer < diff)
            {
                switch(IntroPhase)
                {
                    case 1:
                        //DoScriptText(SAY_WP_1_LUR_START,m_creature);
                        
                        IntroPhase = 2;
                        IntroTimer = 7500;
                        break;
                        
                    case 2:
                        //DoScriptText(SAY_WP_1_LUR_END,m_creature);
                        
                        IntroPhase = 3;
                        IntroTimer = 7500;
                        break;
                    case 3:
                        m_creature->SetReactState(REACT_AGGRESSIVE);
                        
                        IntroPhase = 0;
                        IntroTimer = 0;
                        break;
                        
                    case 4:
                        //DoScriptText(SAY_WP_41_LUR_START,m_creature);
                        
                        IntroPhase = 5;
                        IntroTimer = 8000;
                        break;
                    case 5:
                        //DoScriptText(SAY_WP_41_LUR_END,m_creature);
                        
                        IntroPhase = 6;
                        IntroTimer = 2500;
                        break;
                        
                    case 6:
                        if (Player* pPlayer = GetPlayerForEscort())
                            pPlayer->AreaExploredOrEventHappens(QUEST_ESCAPE_WINTERFIN_CAVERNS);
                        
                        IntroPhase = 7;
                        IntroTimer = 2500;
                        break;
                        
                    case 7:
                        m_creature->ForcedDespawn();
                        
                        IntroPhase = 0;
                        IntroTimer = 0;
                        break;
                }
            }else IntroTimer-=diff;
        }
        npc_escortAI::UpdateAI(diff);
    }
};

CreatureAI* GetAI_npc_lurgglbr(Creature* pCreature)
{
    return new npc_lurgglbrAI(pCreature);
}

bool QuestAccept_npc_lurgglbr(Player* pPlayer, Creature* pCreature, Quest const *_Quest)
{
    if (_Quest->GetQuestId() == QUEST_ESCAPE_WINTERFIN_CAVERNS)
    {
        if(GameObject* pGo = pCreature->FindNearestGameObject(GO_CAGE,5.0f))
        {
            pGo->SetRespawnTime(0);
            pGo->SetGoType(GAMEOBJECT_TYPE_BUTTON);
            pGo->UseDoorOrButton(20);
        }
        
        if (npc_escortAI* pEscortAI = CAST_AI(npc_lurgglbrAI, pCreature->AI()))
            pEscortAI->Start(true, false, pPlayer->GetGUID());
        
        if (pPlayer->GetTeam() == ALLIANCE)
            pCreature->setFaction(FACTION_ESCORTEE_A);
        
        if (pPlayer->GetTeam() == HORDE)
            pCreature->setFaction(FACTION_ESCORTEE_H);
        
        return true;
    }
    return false;
}

/*######
## npc_nexus_drake_hatchling
######*/

enum eNexusDrakeHatchling
{
    SPELL_DRAKE_HARPOON             = 46607,
    SPELL_RED_DRAGONBLOOD           = 46620,
    SPELL_DRAKE_HATCHLING_SUBDUED   = 46691,
    SPELL_SUBDUED                   = 46675,
    
    NPC_RAELORASZ                   = 26117,
    
    QUEST_DRAKE_HUNT                = 11919,
    QUEST_DRAKE_HUNT_D              = 11940
};

struct TRINITY_DLL_DECL npc_nexus_drake_hatchlingAI : public FollowerAI //The spell who makes the npc follow the player is missing, also we can use FollowerAI!
{
    npc_nexus_drake_hatchlingAI(Creature *c) : FollowerAI(c) {Reset();}
    
    bool WithRedDragonBlood;
    
    Unit* pPlayer;
    
    void Reset()
    {
        WithRedDragonBlood = false;
    }
    
    void EnterCombat(Unit* pWho)
    {
        if (m_creature->canAttack(pWho))
            m_creature->AI()->AttackStart(pWho);
    }
    
    void SpellHit(Unit *caster, const SpellEntry *spell)
    {
        if (spell->Id == SPELL_DRAKE_HARPOON)
        {
            pPlayer = caster;
            
            m_creature->CastSpell(m_creature,SPELL_RED_DRAGONBLOOD,true);
            
            WithRedDragonBlood = true;
        }
    }
    
    void MoveInLineOfSight(Unit *pWho)
    {
        FollowerAI::MoveInLineOfSight(pWho);
        
        if (m_creature->HasAura(SPELL_SUBDUED) && pWho->GetEntry() == NPC_RAELORASZ)
        {
            if (m_creature->IsWithinDistInMap(pWho, INTERACTION_DISTANCE))
            {
                ((Player*)(pPlayer))->KilledMonsterCredit(26175,0);
                ((Player*)(pPlayer))->RemoveAura(SPELL_DRAKE_HATCHLING_SUBDUED);
                SetFollowComplete();
                m_creature->DisappearAndDie();
            }
        }
    }
    
    void UpdateAI(const uint32 diff)
    {
        if (WithRedDragonBlood && !m_creature->HasAura(SPELL_RED_DRAGONBLOOD))
        {
            if (npc_nexus_drake_hatchlingAI* pDrakeAI = CAST_AI(npc_nexus_drake_hatchlingAI, m_creature->AI()))
            {
                EnterEvadeMode();
                pDrakeAI->StartFollow((Player*)(pPlayer), 35, NULL);
            }
            
            m_creature->CastSpell(m_creature,SPELL_SUBDUED,true);
            ((Player*)(pPlayer))->CastSpell((Player*)(pPlayer),SPELL_DRAKE_HATCHLING_SUBDUED,true);
            
            m_creature->AttackStop();
            WithRedDragonBlood = false;
        }
        
        if (!UpdateVictim())
            return;
        
        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_nexus_drake_hatchling(Creature* pCreature)
{
    return new npc_nexus_drake_hatchlingAI(pCreature);
}


void AddSC_borean_tundra()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "npc_fizzcrank_fullthrottle";
    newscript->pGossipHello = &GossipHello_npc_fizzcrank_fullthrottle;
    newscript->pGossipSelect = &GossipSelect_npc_fizzcrank_fullthrottle;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_surristrasz";
    newscript->pGossipHello = &GossipHello_npc_surristrasz;
    newscript->pGossipSelect = &GossipSelect_npc_surristrasz;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_tiare";
    newscript->pGossipHello = &GossipHello_npc_tiare;
    newscript->pGossipSelect = &GossipSelect_npc_tiare;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_sinkhole_kill_credit";
    newscript->GetAI = &GetAI_npc_sinkhole_kill_credit;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_khunok_the_behemoth";
    newscript->GetAI = &GetAI_npc_khunok_the_behemoth;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_keristrasza";
    newscript->pGossipHello = &GossipHello_npc_keristrasza;
    newscript->pGossipSelect = &GossipSelect_npc_keristrasza;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_corastrasza";
    newscript->pGossipHello = &GossipHello_npc_corastrasza;
    newscript->pGossipSelect = &GossipSelect_npc_corastrasza;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_iruk";
    newscript->pGossipHello = &GossipHello_npc_iruk;
    newscript->pGossipSelect = &GossipSelect_npc_iruk;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_nerubar_victim";
    newscript->GetAI = &GetAI_mob_nerubar_victim;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_scourge_prisoner";
    newscript->GetAI = &GetAI_npc_scourge_prisoner;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_jenny";
    newscript->GetAI = &GetAI_npc_jenny;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_nesingwary_trapper";
    newscript->GetAI = &GetAI_npc_nesingwary_trapper;
    newscript->RegisterSelf();
    newscript = new Script;
    
    newscript = new Script;
    newscript->Name = "npc_lurgglbr";
    newscript->GetAI = &GetAI_npc_lurgglbr;
    newscript->pQuestAccept = &QuestAccept_npc_lurgglbr;
    newscript->RegisterSelf();
    
    newscript = new Script;
    newscript->Name = "npc_nexus_drake_hatchling";
    newscript->GetAI = &GetAI_npc_nexus_drake_hatchling;
    newscript->RegisterSelf();
}
