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

#include "ScriptedPch.h"
#include "ScriptedEscortAI.h"
#include "ScriptedFollowerAI.h"

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

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
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

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
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
    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
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

struct npc_sinkhole_kill_creditAI : public ScriptedAI
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

    void EnterCombat(Unit* who){}

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
                        m_creature->Kill(worm);
                        worm->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
                    }
                    Phase_Timer = 2000;
                    Phase = 7;
                    break;
                case 7:
                    DoCast(m_creature, SPELL_EXPLODE_CART, true);
                    if(Player *caster = Unit::GetPlayer(casterGuid))
                        caster->KilledMonster(m_creature->GetCreatureInfo(),m_creature->GetGUID());
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

struct npc_khunok_the_behemothAI : public ScriptedAI
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
                    owner->CastSpell(owner, 46231, true);
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

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

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
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_C_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
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
    switch (uiAction)
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
struct mob_nerubar_victimAI : public ScriptedAI
{
    mob_nerubar_victimAI(Creature *c) : ScriptedAI(c) {}

    void Reset() {}
    void EnterCombat(Unit *who) {}
    void MoveInLineOfSight(Unit *who) {}

    void JustDied(Unit* Killer)
    {
        if (Killer->GetTypeId() == TYPEID_PLAYER)
        {
            if (CAST_PLR(Killer)->GetQuestStatus(11611) == QUEST_STATUS_INCOMPLETE)
            {
                uint8 uiRand = urand(0,99);
                if (uiRand < 25)
                {
                    Killer->CastSpell(m_creature,45532,true);
                    CAST_PLR(Killer)->KilledMonsterCredit(WARSONG_PEON, 0);
                }
                else if (uiRand < 75)
                    Killer->CastSpell(m_creature, nerubarVictims[urand(0,2)], true);
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

struct npc_scourge_prisonerAI : public ScriptedAI
{
    npc_scourge_prisonerAI(Creature* pCreature) : ScriptedAI (pCreature){}

    void Reset()
    {
        m_creature->SetReactState(REACT_PASSIVE);

        if (GameObject* pGO = m_creature->FindNearestGameObject(GO_SCOURGE_CAGE,5.0f))
            if (pGO->GetGoState() == GO_STATE_ACTIVE)
                pGO->SetGoState(GO_STATE_READY);
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

struct npc_jennyAI : public ScriptedAI
{
    npc_jennyAI(Creature* pCreature) : ScriptedAI(pCreature) {}

    bool setCrateNumber;

    void Reset()
    {
        if(!setCrateNumber)
            setCrateNumber = true;

        m_creature->SetReactState(REACT_PASSIVE);

        switch (CAST_PLR(m_creature->GetOwner())->GetTeamId())
        {
            case TEAM_ALLIANCE:
                m_creature->setFaction(FACTION_ESCORT_A_NEUTRAL_ACTIVE);
                break;
            default:
            case TEAM_HORDE:
                m_creature->setFaction(FACTION_ESCORT_H_NEUTRAL_ACTIVE);
                break;
        }
    }

    void DamageTaken(Unit* pDone_by, uint32& uiDamage)
    {
        DoCast(m_creature, SPELL_DROP_CRATE, true);
    }

    void UpdateAI(const uint32 diff)
    {
        if(setCrateNumber)
        {
            m_creature->AddAura(SPELL_CRATES_CARRIED,m_creature);
            setCrateNumber = false;
        }

        if (!setCrateNumber && !m_creature->HasAura(SPELL_CRATES_CARRIED))
            m_creature->DisappearAndDie();

        if (!UpdateVictim())
            return;
    }
};

CreatureAI* GetAI_npc_jenny(Creature *pCreature)
{
    return new npc_jennyAI (pCreature);
}

/*######
## npc_fezzix_geartwist
######*/

struct npc_fezzix_geartwistAI : public ScriptedAI
{
    npc_fezzix_geartwistAI(Creature* pCreature) : ScriptedAI(pCreature) {}

    void MoveInLineOfSight(Unit* pWho)
    {
        ScriptedAI::MoveInLineOfSight(pWho);

        if (pWho->GetTypeId() != TYPEID_UNIT)
            return;

        if (pWho->GetEntry() == NPC_JENNY && m_creature->IsWithinDistInMap(pWho, 10.0f))
        {
            if (Unit* pOwner = pWho->GetOwner())
            {
                if (pOwner->GetTypeId() == TYPEID_PLAYER)
                {
                    if (pWho->HasAura(SPELL_CRATES_CARRIED))
                    {
                        pOwner->CastSpell(pOwner, SPELL_GIVE_JENNY_CREDIT, true); // Maybe is not working.
                        CAST_PLR(pOwner)->CompleteQuest(QUEST_LOADER_UP);
                        CAST_CRE(pWho)->DisappearAndDie();
                    }
                }
            }
        }
    }
};

CreatureAI* GetAI_npc_fezzix_geartwist(Creature* pCreature)
{
    return new npc_fezzix_geartwistAI(pCreature);
}

/*######
## npc_nesingwary_trapper
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

struct npc_nesingwary_trapperAI : public ScriptedAI
{
    npc_nesingwary_trapperAI(Creature *c) : ScriptedAI(c) { c->SetVisibility(VISIBILITY_OFF); }

    GameObject *go_caribou;
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

    void JustDied(Unit *who)
    {
        if (go_caribou && go_caribou->GetTypeId() == TYPEID_GAMEOBJECT)
            go_caribou->SetLootState(GO_JUST_DEACTIVATED);

        if (TempSummon *summon = (TempSummon*)m_creature)
            if (summon->isSummon())
                if (Unit *pTemp = summon->GetSummoner())
                    if (pTemp->GetTypeId() == TYPEID_PLAYER)
                        CAST_PLR(pTemp)->KilledMonsterCredit(m_creature->GetEntry(),0);

        if (go_caribou && go_caribou->GetTypeId() == TYPEID_GAMEOBJECT)
            go_caribou->SetGoState(GO_STATE_READY);
    }

    void UpdateAI(const uint32 diff)
    {
        if (Phase_Timer <= diff)
        {
            switch (Phase)
            {
                case 1:
                    m_creature->SetVisibility(VISIBILITY_ON);
                    Phase_Timer = 2000;
                    Phase = 2;
                    break;

                case 2:
                    if (GameObject *go_fur = m_creature->FindNearestGameObject(GO_HIGH_QUALITY_FUR, 11.0f))
                        m_creature->GetMotionMaster()->MovePoint(0, go_fur->GetPositionX(), go_fur->GetPositionY(), go_fur->GetPositionZ());
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
                    if (GameObject *go_fur = m_creature->FindNearestGameObject(GO_HIGH_QUALITY_FUR, 11.0f))
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
                    DoCast(m_creature, SPELL_TRAPPED, true);
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

/*#define SAY_WP_1_LUR_START  -1571004
#define SAY_WP_1_LUR_END    -1571005
#define SAY_WP_41_LUR_START -1571006
#define SAY_WP_41_LUR_END   -1571007*/

struct npc_lurgglbrAI : public npc_escortAI
{
    npc_lurgglbrAI(Creature* pCreature) : npc_escortAI(pCreature){}

    uint32 IntroTimer;
    uint32 IntroPhase;

    void Reset()
    {
        if (!HasEscortState(STATE_ESCORT_ESCORTING))
        {
            IntroTimer = 0;
            IntroPhase = 0;
        }
    }

    void WaypointReached(uint32 i)
    {
        switch (i)
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
            if (IntroTimer <= diff)
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
            } else IntroTimer -= diff;
        }
        npc_escortAI::UpdateAI(diff);

        if (!UpdateVictim())
            return;
    }
};

CreatureAI* GetAI_npc_lurgglbr(Creature* pCreature)
{
    return new npc_lurgglbrAI(pCreature);
}

bool QuestAccept_npc_lurgglbr(Player* pPlayer, Creature* pCreature, Quest const *pQuest)
{
    if (pQuest->GetQuestId() == QUEST_ESCAPE_WINTERFIN_CAVERNS)
    {
        if(GameObject* pGo = pCreature->FindNearestGameObject(GO_CAGE, 5.0f))
        {
            pGo->SetRespawnTime(0);
            pGo->SetGoType(GAMEOBJECT_TYPE_BUTTON);
            pGo->UseDoorOrButton(20);
        }

        if (npc_escortAI* pEscortAI = CAST_AI(npc_lurgglbrAI, pCreature->AI()))
            pEscortAI->Start(true, false, pPlayer->GetGUID());

        switch (pPlayer->GetTeam())
        {
            case ALLIANCE:
                pCreature->setFaction(FACTION_ESCORTEE_A);
                break;
            default:
            case HORDE:
                pCreature->setFaction(FACTION_ESCORTEE_H);
                break;
        }

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

struct npc_nexus_drake_hatchlingAI : public FollowerAI //The spell who makes the npc follow the player is missing, also we can use FollowerAI!
{
    npc_nexus_drake_hatchlingAI(Creature *c) : FollowerAI(c)
    {
          pHarpooner = NULL;
    }

    Player *pHarpooner;
    bool WithRedDragonBlood;

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
        if (spell->Id == SPELL_DRAKE_HARPOON && caster->GetTypeId() == TYPEID_PLAYER)
        {
            pHarpooner = CAST_PLR(caster);
            DoCast(m_creature, SPELL_RED_DRAGONBLOOD, true);
        }
        WithRedDragonBlood = true;
    }

    void MoveInLineOfSight(Unit *pWho)
    {
        FollowerAI::MoveInLineOfSight(pWho);

        if (!pHarpooner || !pHarpooner->IsInWorld())
            return;

        if (m_creature->HasAura(SPELL_SUBDUED) && pWho->GetEntry() == NPC_RAELORASZ)
        {
            if (m_creature->IsWithinDistInMap(pWho, INTERACTION_DISTANCE))
            {
                pHarpooner->KilledMonsterCredit(26175,0);
                pHarpooner->RemoveAura(SPELL_DRAKE_HATCHLING_SUBDUED);
                SetFollowComplete();
                pHarpooner = NULL;
                m_creature->DisappearAndDie();
            }
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (WithRedDragonBlood && pHarpooner && pHarpooner->IsInWorld() && !m_creature->HasAura(SPELL_RED_DRAGONBLOOD))
        {
            if (npc_nexus_drake_hatchlingAI* pDrakeAI = CAST_AI(npc_nexus_drake_hatchlingAI, m_creature->AI()))
            {
                EnterEvadeMode();
                pDrakeAI->StartFollow(pHarpooner, 35, NULL);
            }

            DoCast(m_creature, SPELL_SUBDUED, true);
            pHarpooner->CastSpell(pHarpooner, SPELL_DRAKE_HATCHLING_SUBDUED, true);

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

/*######
## npc_thassarian
######*/

enum eThassarian
{
    QUEST_LAST_RITES        = 12019,

    SPELL_TRANSFORM_VALANAR = 46753,
    SPELL_STUN              = 46957,
    SPELL_SHADOW_BOLT       = 15537,

    NPC_IMAGE_LICH_KING     = 26203,
    NPC_COUNSELOR_TALBOT    = 25301,
    NPC_PRINCE_VALANAR      = 28189,
    NPC_GENERAL_ARLOS       = 25250,
    NPC_LERYSSA             = 25251,

    SAY_TALBOT_1            = -1571004,
    SAY_LICH_1              = -1571005,
    SAY_TALBOT_2            = -1571006,
    SAY_THASSARIAN_1        = -1571007,
    SAY_THASSARIAN_2        = -1571008,
    SAY_LICH_2              = -1571009,
    SAY_THASSARIAN_3        = -1571010,
    SAY_TALBOT_3            = -1571011,
    SAY_LICH_3              = -1571012,
    SAY_TALBOT_4            = -1571013,
    SAY_ARLOS_1             = -1571014,
    SAY_ARLOS_2             = -1571015,
    SAY_LERYSSA_1           = -1571016,
    SAY_THASSARIAN_4        = -1571017,
    SAY_LERYSSA_2           = -1571018,
    SAY_THASSARIAN_5        = -1571019,
    SAY_LERYSSA_3           = -1571020,
    SAY_THASSARIAN_6        = -1571021,
    SAY_LERYSSA_4           = -1571022,
    SAY_THASSARIAN_7        = -1571023,
};

#define GOSSIP_ITEM_T   "Let's do this, Thassarian. It's now or never."

struct npc_thassarianAI : public npc_escortAI
{
    npc_thassarianAI(Creature* pCreature) : npc_escortAI(pCreature)
    {
        pArthas      = NULL;
        pTalbot      = NULL;
        pLeryssa     = NULL;
        pArlos       = NULL;
        pCreature->RemoveStandFlags(UNIT_STAND_STATE_SIT);
    }

    Creature* pArthas;
    Creature* pTalbot;
    Creature* pLeryssa;
    Creature* pArlos;

    bool bArthasInPosition;
    bool bArlosInPosition;
    bool bLeryssaInPosition;
    bool bTalbotInPosition;

    uint32 uiPhase;
    uint32 uiPhase_Timer;

    void Reset()
    {
        m_creature->RestoreFaction();
        m_creature->RemoveStandFlags(UNIT_STAND_STATE_SIT);

        bArthasInPosition           = false;
        bArlosInPosition            = false;
        bLeryssaInPosition          = false;
        bTalbotInPosition           = false;

        uiPhase = 0;
        uiPhase_Timer = 0;
    }

    void WaypointReached(uint32 uiPointId)
    {
        Player* pPlayer = GetPlayerForEscort();

        if (!pPlayer)
            return;

        switch(uiPointId)
        {
            case 3:
                SetEscortPaused(true);
                if (pArthas = m_creature->SummonCreature(NPC_IMAGE_LICH_KING, 3730.313, 3518.689, 473.324, 1.562, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 120000))
                {
                    pArthas->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    pArthas->SetReactState(REACT_PASSIVE);
                    pArthas->AddUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                    pArthas->GetMotionMaster()->MovePoint(0, 3737.374756,3564.841309,477.433014);
                }
                if (pTalbot = m_creature->SummonCreature(NPC_COUNSELOR_TALBOT, 3747.23, 3614.936, 473.321, 4.462012, TEMPSUMMON_CORPSE_TIMED_DESPAWN,120000))
                {
                    pTalbot->AddUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                    pTalbot->GetMotionMaster()->MovePoint(0, 3738.000977,3568.882080,477.433014);
                }
                m_creature->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                break;

            case 4:
                SetEscortPaused(true);
                uiPhase = 7;
                break;
        }
    }

    void UpdateAI(const uint32 uiDiff)
    {
        npc_escortAI::UpdateAI(uiDiff);

        if (bArthasInPosition && bTalbotInPosition)
        {
            uiPhase = 1;
            bArthasInPosition = false;
            bTalbotInPosition = false;
        }

        if (bArlosInPosition && bLeryssaInPosition)
        {
            bArlosInPosition   = false;
            bLeryssaInPosition = false;
            DoScriptText(SAY_THASSARIAN_1, m_creature);
            SetEscortPaused(false);
        }

        if (uiPhase_Timer <= uiDiff)
        {
            switch (uiPhase)
            {
                case 1:
                    if (pTalbot)
                        pTalbot->SetStandState(UNIT_STAND_STATE_KNEEL);
                    uiPhase_Timer = 3000;
                    ++uiPhase;
                    break;

                case 2:
                    if (pTalbot)
                    {
                        pTalbot->UpdateEntry(NPC_PRINCE_VALANAR,ALLIANCE);
                        pTalbot->setFaction(14);
                        pTalbot->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        pTalbot->SetReactState(REACT_PASSIVE);
                    }
                    uiPhase_Timer = 5000;
                    ++uiPhase;
                    break;

                case 3:
                    if (pTalbot)
                        DoScriptText(SAY_TALBOT_1, pTalbot);
                    uiPhase_Timer = 5000;
                    ++uiPhase;
                    break;

                case 4:
                    if (pArthas)
                        DoScriptText(SAY_LICH_1, pArthas);
                    uiPhase_Timer = 5000;
                    ++uiPhase;
                    break;

                case 5:
                    if (pTalbot)
                        DoScriptText(SAY_TALBOT_2, pTalbot);
                    uiPhase_Timer = 5000;
                    ++uiPhase;
                    break;

                case 6:
                    if (pArlos = m_creature->SummonCreature(NPC_GENERAL_ARLOS, 3745.527100, 3615.655029, 473.321533, 4.447805, TEMPSUMMON_CORPSE_TIMED_DESPAWN,120000))
                    {
                        pArlos->AddUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                        pArlos->GetMotionMaster()->MovePoint(0, 3735.570068, 3572.419922, 477.441010);
                    }
                    if (pLeryssa = m_creature->SummonCreature(NPC_LERYSSA, 3749.654541, 3614.959717, 473.323486, 4.524959, TEMPSUMMON_CORPSE_TIMED_DESPAWN,120000))
                    {
                        pLeryssa->AddUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                        pLeryssa->SetReactState(REACT_PASSIVE);
                        pLeryssa->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        pLeryssa->GetMotionMaster()->MovePoint(0, 3741.969971, 3571.439941, 477.441010);
                    }
                    uiPhase_Timer = 2000;
                    uiPhase = 0;
                    break;

                case 7:
                    DoScriptText(SAY_THASSARIAN_2, m_creature);
                    uiPhase_Timer = 5000;
                    ++uiPhase;
                    break;

                case 8:
                    if (pArthas && pTalbot)
                    {
                        pArthas->SetInFront(m_creature); //The client doesen't update with the new orientation :l
                        pTalbot->SetStandState(UNIT_STAND_STATE_STAND);
                        DoScriptText(SAY_LICH_2, pArthas);
                    }
                    uiPhase_Timer = 5000;
                    uiPhase = 9;
                    break;

               case 9:
                    DoScriptText(SAY_THASSARIAN_3, m_creature);
                    uiPhase_Timer = 5000;
                    uiPhase = 10;
                    break;

               case 10:
                    if (pTalbot)
                        DoScriptText(SAY_TALBOT_3, pTalbot);
                    uiPhase_Timer = 5000;
                    uiPhase = 11;
                    break;

               case 11:
                    if (pArthas)
                        DoScriptText(SAY_LICH_3, pArthas);
                    uiPhase_Timer = 5000;
                    uiPhase = 12;
                    break;

                case 12:
                    if (pTalbot)
                        DoScriptText(SAY_TALBOT_4, pTalbot);
                    uiPhase_Timer = 2000;
                    uiPhase = 13;
                    break;

                case 13:
                    if (pArthas)
                        pArthas->RemoveFromWorld();
                    ++uiPhase;
                    break;

                case 14:
                    m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    if (pTalbot)
                    {
                        pTalbot->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        pTalbot->SetReactState(REACT_AGGRESSIVE);
                        pTalbot->CastSpell(m_creature, SPELL_SHADOW_BOLT, false);
                    }
                    uiPhase_Timer = 1500;
                    ++uiPhase;
                    break;

                case 15:
                    m_creature->SetReactState(REACT_AGGRESSIVE);
                    m_creature->AI()->AttackStart(pTalbot);
                    uiPhase = 0;
                    break;

                case 16:
                    m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                    uiPhase_Timer = 20000;
                    ++uiPhase;
                    break;

               case 17:
                    if (pLeryssa)
                        pLeryssa->RemoveFromWorld();
                    if (pArlos)
                        pArlos->RemoveFromWorld();
                    if (pTalbot)
                        pTalbot->RemoveFromWorld();
                    m_creature->RemoveStandFlags(UNIT_STAND_STATE_SIT);
                    SetEscortPaused(false);
                    uiPhase_Timer = 0;
                    uiPhase = 0;
            }
        } else uiPhase_Timer -= uiDiff;

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* pKiller)
    {
        if (pTalbot)
            pTalbot->RemoveFromWorld();
        if (pLeryssa)
            pLeryssa->RemoveFromWorld();
        if (pArlos)
            pArlos->RemoveFromWorld();
        if (pArthas)
            pArthas->RemoveFromWorld();
    }
};

bool GossipHello_npc_thassarian(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (pPlayer->GetQuestStatus(QUEST_LAST_RITES) == QUEST_STATUS_INCOMPLETE && pCreature->GetAreaId() == 4125)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_T, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

    return true;
}

bool GossipSelect_npc_thassarian(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch (uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            CAST_AI(npc_escortAI, (pCreature->AI()))->Start(true, false, pPlayer->GetGUID());
            CAST_AI(npc_escortAI, (pCreature->AI()))->SetMaxPlayerDistance(200.0f);
            break;
    }
    return true;
}

CreatureAI* GetAI_npc_thassarian(Creature *pCreature)
{
    return new npc_thassarianAI (pCreature);
}

/*######
## npc_image_lich_king
######*/

struct npc_image_lich_kingAI : public ScriptedAI
{
    npc_image_lich_kingAI(Creature* pCreature) : ScriptedAI(pCreature) {}

    void Reset()
    {
        m_creature->RestoreFaction();
    }

    void MovementInform(uint32 uiType, uint32 uiId)
    {
        if (uiType != POINT_MOTION_TYPE)
            return;

        if (m_creature->isSummon())
            if (Unit* pSummoner = CAST_SUM(m_creature)->GetSummoner())
                CAST_AI(npc_thassarianAI,CAST_CRE(pSummoner)->AI())->bArthasInPosition = true;
    }
};

CreatureAI* GetAI_npc_image_lich_king(Creature* pCreature)
{
    return new npc_image_lich_kingAI (pCreature);
}

/*######
## npc_general_arlos
######*/

struct npc_general_arlosAI : public ScriptedAI
{
    npc_general_arlosAI(Creature* pCreature) : ScriptedAI(pCreature) {}

    void MovementInform(uint32 uiType, uint32 uiId)
    {
        if (uiType != POINT_MOTION_TYPE)
            return;

        m_creature->addUnitState(UNIT_STAT_STUNNED);
        m_creature->CastSpell(m_creature, SPELL_STUN, true);
        if (m_creature->isSummon())
            if (Unit* pSummoner = CAST_SUM(m_creature)->GetSummoner())
                CAST_AI(npc_thassarianAI,CAST_CRE(pSummoner)->AI())->bArlosInPosition = true;
    }
};

CreatureAI* GetAI_npc_general_arlos(Creature *pCreature)
{
    return new npc_general_arlosAI (pCreature);
}

/*######
## npc_counselor_talbot
######*/

enum eCounselotTalbot
{
    SPELL_DEFLECTION    = 51009,
    SPELL_SOUL_BLAST    = 50992,
};

struct npc_counselor_talbotAI : public ScriptedAI
{
    npc_counselor_talbotAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pCreature->RestoreFaction();
    }

    Creature* pLeryssa;
    Creature* pArlos;

    bool bCheck;

    uint32 uiShadowBoltTimer;
    uint32 uiDeflectionTimer;
    uint32 uiSoulBlastTimer;

    void Reset()
    {
        pLeryssa             = NULL;
        pArlos               = NULL;
        bCheck              = false;
        uiShadowBoltTimer   = urand(5000,12000);
        uiDeflectionTimer   = urand(20000,25000);
        uiSoulBlastTimer    = urand (12000,18000);
    }
    void MovementInform(uint32 uiType, uint32 uiId)
    {
        if(uiType != POINT_MOTION_TYPE)
            return;

        if (m_creature->isSummon())
            if (Unit* pSummoner = CAST_SUM(m_creature)->GetSummoner())
                CAST_AI(npc_thassarianAI,CAST_CRE(pSummoner)->AI())->bTalbotInPosition = true;
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (bCheck)
        {
            pLeryssa = m_creature->FindNearestCreature(NPC_LERYSSA, 50.0f, true);
            pArlos   = m_creature->FindNearestCreature(NPC_GENERAL_ARLOS, 50.0f, true);
            bCheck  = false;
        }

        if (!UpdateVictim())
            return;

        if (m_creature->GetAreaId() == 4125)
        {
            if (uiShadowBoltTimer <= uiDiff)
            {
                DoCast(m_creature->getVictim(), SPELL_SHADOW_BOLT);
                uiShadowBoltTimer = urand(5000,12000);
            } else uiShadowBoltTimer -= uiDiff;

            if (uiDeflectionTimer <= uiDiff)
            {
                DoCast(m_creature->getVictim(), SPELL_DEFLECTION);
                uiDeflectionTimer = urand(20000,25000);
            } else uiDeflectionTimer -= uiDiff;

            if (uiSoulBlastTimer <= uiDiff)
            {
                DoCast(m_creature->getVictim(), SPELL_SOUL_BLAST);
                uiSoulBlastTimer  = urand (12000,18000);
            } else uiSoulBlastTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }

        DoMeleeAttackIfReady();
   }

   void JustDied(Unit* pKiller)
   {
        if (!pArlos || !pLeryssa)
            return;

        DoScriptText(SAY_ARLOS_1, pArlos);
        DoScriptText(SAY_ARLOS_2, pArlos);
        DoScriptText(SAY_LERYSSA_1, pLeryssa);
        pArlos->Kill(pArlos, false);
        pLeryssa->RemoveAura(SPELL_STUN);
        pLeryssa->clearUnitState(UNIT_STAT_STUNNED);
        pLeryssa->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
        pLeryssa->GetMotionMaster()->MovePoint(0,3722.114502, 3564.201660, 477.441437);

        if (pKiller->GetTypeId() == TYPEID_PLAYER)
            CAST_PLR(pKiller)->RewardPlayerAndGroupAtEvent(NPC_PRINCE_VALANAR, 0);
    }
};

CreatureAI* GetAI_npc_counselor_talbot(Creature* pCreature)
{
    return new npc_counselor_talbotAI (pCreature);
}

/*######
## npc_leryssa
######*/

struct npc_leryssaAI : public ScriptedAI
{
    npc_leryssaAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        bDone = false;
        Phase = 0;
        Phase_Timer = 0;

        pCreature->RemoveStandFlags(UNIT_STAND_STATE_SIT);
    }

    bool bDone;

    uint32 Phase;
    uint32 Phase_Timer;

    void MovementInform(uint32 uiType, uint32 uiId)
    {
        if(uiType != POINT_MOTION_TYPE)
            return;

        if (!bDone)
        {
            if (Creature* pTalbot = m_creature->FindNearestCreature(NPC_PRINCE_VALANAR, 50.0f, true))
                CAST_AI(npc_counselor_talbotAI, pTalbot->AI())->bCheck = true;

            m_creature->addUnitState(UNIT_STAT_STUNNED);
            m_creature->CastSpell(m_creature, SPELL_STUN, true);

            if (m_creature->isSummon())
                if (Unit* pSummoner = CAST_SUM(m_creature)->GetSummoner())
                    CAST_AI(npc_thassarianAI,CAST_CRE(pSummoner)->AI())->bLeryssaInPosition = true;
            bDone = true;
        }
        else
        {
            m_creature->SetStandState(UNIT_STAND_STATE_SIT);
            if (m_creature->isSummon())
                if (Unit* pSummoner = CAST_SUM(m_creature)->GetSummoner())
                pSummoner->SetStandState(UNIT_STAND_STATE_SIT);
            Phase_Timer = 1500;
            Phase = 1;
        }
    }

    void UpdateAI(const uint32 uiDiff)
    {
        ScriptedAI::UpdateAI(uiDiff);

        if (Phase_Timer <= uiDiff)
        {
            switch (Phase)
            {
                case 1:
                    if (m_creature->isSummon())
                        if (Unit* pThassarian = CAST_SUM(m_creature)->GetSummoner())
                            DoScriptText(SAY_THASSARIAN_4, pThassarian);
                    Phase_Timer = 5000;
                    ++Phase;
                    break;
                case 2:
                    DoScriptText(SAY_LERYSSA_2, m_creature);
                    Phase_Timer = 5000;
                    ++Phase;
                    break;
                case 3:
                    if (m_creature->isSummon())
                        if (Unit* pThassarian = CAST_SUM(m_creature)->GetSummoner())
                            DoScriptText(SAY_THASSARIAN_5, pThassarian);
                    Phase_Timer = 5000;
                    ++Phase;
                    break;
                case 4:
                    DoScriptText(SAY_LERYSSA_3, m_creature);
                    Phase_Timer = 5000;
                    ++Phase;
                    break;
                case 5:
                    if (m_creature->isSummon())
                        if (Unit* pThassarian = CAST_SUM(m_creature)->GetSummoner())
                    DoScriptText(SAY_THASSARIAN_6, pThassarian);
                    Phase_Timer = 5000;
                    ++Phase;
                    break;

                case 6:
                    DoScriptText(SAY_LERYSSA_4, m_creature);
                    Phase_Timer = 5000;
                    ++Phase;
                    break;
                case 7:
                    if (m_creature->isSummon())
                        if (Unit* pThassarian = CAST_SUM(m_creature)->GetSummoner())
                        {
                            DoScriptText(SAY_THASSARIAN_7, pThassarian);
                            CAST_AI(npc_thassarianAI,CAST_CRE(pThassarian)->AI())->uiPhase = 16;
                        }
                    Phase_Timer = 5000;
                    Phase = 0;
                    break;
            }
        } else Phase_Timer -= uiDiff;

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_leryssa(Creature *pCreature)
{
    return new npc_leryssaAI (pCreature);
}

/*######
## npc_beryl_sorcerer
######*/

enum eBerylSorcerer
{
    NPC_CAPTURED_BERLY_SORCERER         = 25474,
    NPC_LIBRARIAN_DONATHAN              = 25262,

    SPELL_ARCANE_CHAINS                 = 45611,
    SPELL_COSMETIC_CHAINS               = 54324,
    SPELL_COSMETIC_ENSLAVE_CHAINS_SELF  = 45631
};

struct npc_beryl_sorcererAI : public FollowerAI
{
    npc_beryl_sorcererAI(Creature* pCreature) : FollowerAI(pCreature) {}

    bool bEnslaved;

    void Reset()
    {
        m_creature->SetReactState(REACT_AGGRESSIVE);
        bEnslaved = false;
    }

    void EnterCombat(Unit* pWho)
    {
        if (m_creature->canAttack(pWho))
            m_creature->AI()->AttackStart(pWho);
    }

    void SpellHit(Unit* pCaster, const SpellEntry* pSpell)
    {
        if (pSpell->Id == SPELL_ARCANE_CHAINS && pCaster->GetTypeId() == TYPEID_PLAYER && m_creature->GetHealth()*100 / m_creature->GetMaxHealth() <= 50 && !bEnslaved)
        {
            EnterEvadeMode(); //We make sure that the npc is not attacking the player!
            m_creature->SetReactState(REACT_PASSIVE);
            if (npc_beryl_sorcererAI* pBerylAI = CAST_AI(npc_beryl_sorcererAI, m_creature->AI()))
                pBerylAI->StartFollow(CAST_PLR(pCaster), NULL, NULL);
            m_creature->UpdateEntry(NPC_CAPTURED_BERLY_SORCERER, TEAM_NEUTRAL);
            DoCast(m_creature, SPELL_COSMETIC_ENSLAVE_CHAINS_SELF, true);
            CAST_PLR(pCaster)->KilledMonsterCredit(NPC_CAPTURED_BERLY_SORCERER, 0);
            bEnslaved = true;
        }
    }

    void MoveInLineOfSight(Unit* pWho)
    {
        FollowerAI::MoveInLineOfSight(pWho);

        if (pWho->GetEntry() == NPC_LIBRARIAN_DONATHAN && m_creature->IsWithinDistInMap(pWho, INTERACTION_DISTANCE))
        {
            SetFollowComplete();
            m_creature->DisappearAndDie();
        }
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_beryl_sorcerer(Creature* pCreature)
{
    return new npc_beryl_sorcererAI(pCreature);
}

/*######
## npc_imprisoned_beryl_sorcerer
######*/

enum eImprisionedBerylSorcerer
{
    SPELL_NEURAL_NEEDLE             = 45634,

    NPC_IMPRISONED_BERYL_SORCERER   = 25478,

    SAY_IMPRISIONED_BERYL_1         = -1571024,
    SAY_IMPRISIONED_BERYL_2         = -1571025,
    SAY_IMPRISIONED_BERYL_3         = -1571026,
    SAY_IMPRISIONED_BERYL_4         = -1571027,
    SAY_IMPRISIONED_BERYL_5         = -1571028,
    SAY_IMPRISIONED_BERYL_6         = -1571029,
    SAY_IMPRISIONED_BERYL_7         = -1571030,
};

struct npc_imprisoned_beryl_sorcererAI : public ScriptedAI
{
    npc_imprisoned_beryl_sorcererAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pCaster = NULL;
    }

    Player *pCaster;

    uint32  uiStep;
    uint32  uiPhase;

    void Reset()
    {
        uiStep = 1;
        uiPhase = 0;
    }

    void EnterCombat(Unit* pWho)
    {
        return;
    }

    void SpellHit(Unit* pCaster, const SpellEntry* pSpell)
    {
        if (pSpell->Id == SPELL_NEURAL_NEEDLE && pCaster->GetTypeId() == TYPEID_PLAYER)
        {
            ++uiPhase;
            pCaster = CAST_PLR(pCaster);
        }
    }

    void UpdateAI(const uint32 uiDiff)
    {
        ScriptedAI::UpdateAI(uiDiff);

        if (!m_creature->HasAura(SPELL_COSMETIC_ENSLAVE_CHAINS_SELF))
            DoCast(m_creature, SPELL_COSMETIC_ENSLAVE_CHAINS_SELF);

        if (m_creature->GetReactState() != REACT_PASSIVE)
            m_creature->SetReactState(REACT_PASSIVE);

        switch (uiPhase)
        {
            case 1:
                if (uiStep == 1)
                {
                    DoScriptText(SAY_IMPRISIONED_BERYL_1, m_creature);
                    uiStep = 2;
                }
                break;

            case 2:
                if (uiStep == 2)
                {
                    DoScriptText(SAY_IMPRISIONED_BERYL_2, m_creature);
                    uiStep = 3;
                }
                break;

            case 3:
                if (uiStep == 3)
                {
                    DoScriptText(SAY_IMPRISIONED_BERYL_3, m_creature);
                    uiStep = 4;
                }
                break;

            case 4:
                if (uiStep == 4)
                {
                    DoScriptText(SAY_IMPRISIONED_BERYL_4, m_creature);
                    uiStep = 5;
                }
                break;

            case 5:
                if (uiStep == 5)
                {
                    if (pCaster)
                    {
                        DoScriptText(SAY_IMPRISIONED_BERYL_5, m_creature);
                        pCaster->KilledMonsterCredit(25478,0);
                        uiStep = 6;
                    }
                }
                break;

            case 6:
                if (uiStep == 6)
                {
                    DoScriptText(SAY_IMPRISIONED_BERYL_6, m_creature);
                    uiStep = 7;
                }
                break;

            case 7:
                if (uiStep == 7)
                {
                    DoScriptText(SAY_IMPRISIONED_BERYL_7, m_creature);
                    uiStep  = 1;
                    uiPhase = 0;
                }
                break;
        }

        if (!UpdateVictim())
            return;
    }
};

CreatureAI* GetAI_npc_imprisoned_beryl_sorcerer(Creature* pCreature)
{
    return new npc_imprisoned_beryl_sorcererAI(pCreature);
}

/*######
## npc_mootoo_the_younger
######*/
enum Script_Texts_Mootoo_the_Younger
{
    SAY_1                    =-1750040,
    SAY_2                    =-1750041,
    SAY_3                    =-1750042,
    SAY_4                    =-1750043,
    SAY_5                    =-1750044
};
enum Mootoo_the_Younger_Entries
{
    NPC_MOOTOO_THE_YOUNGER          =25504,
    QUEST_ESCAPING_THE_MIST         =11664
};
bool QuestAccept_npc_mootoo_the_younger(Player* pPlayer, Creature* pCreature, Quest const* quest)
{
    if (quest->GetQuestId()==QUEST_ESCAPING_THE_MIST)
    {
        switch (pPlayer->GetTeam())
        {
        case ALLIANCE:
            pCreature->setFaction(FACTION_ESCORTEE_A);
            break;
        case HORDE:
            pCreature->setFaction(FACTION_ESCORTEE_H);
            break;
        }
        DoScriptText(SAY_1, pCreature);
        CAST_AI(npc_escortAI, (pCreature->AI()))->Start(true, false, pPlayer->GetGUID());
    }
    return true;
}
struct npc_mootoo_the_youngerAI : public npc_escortAI
{
    npc_mootoo_the_youngerAI(Creature *c) : npc_escortAI(c) {}

    void Reset()
    {
        SetDespawnAtFar(false);
    }

    void JustDied(Unit* killer)
    {
        if (Player* pPlayer=GetPlayerForEscort())
            pPlayer->FailQuest(QUEST_ESCAPING_THE_MIST);
    }

    void WaypointReached(uint32 i)
    {
        Player* pPlayer = GetPlayerForEscort();

        if (!pPlayer)
            return;

        switch(i)
        {
        case 10:
            m_creature->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
            DoScriptText(SAY_2, m_creature);
            break;
        case 12:
            DoScriptText(SAY_3, m_creature);
            m_creature->HandleEmoteCommand(EMOTE_ONESHOT_LOOT);
            break;
        case 16:
            DoScriptText(SAY_4, m_creature);
            m_creature->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
            break;
        case 20:
            me->SetPhaseMask(1,true);
            DoScriptText(SAY_5, m_creature);
            m_creature->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
            if (pPlayer)
                pPlayer->GroupEventHappens(QUEST_ESCAPING_THE_MIST, m_creature);
            SetRun(true);
            break;
        }
    }
};
CreatureAI* GetAI_npc_mootoo_the_younger(Creature* pCreature)
{
    return new npc_mootoo_the_youngerAI(pCreature);
}

/*######
## npc_bonker_togglevolt
######*/

enum Bonker_Togglevolt_Entries
{
    NPC_BONKER_TOGGLEVOLT           =25589,
    QUEST_GET_ME_OUTA_HERE          =11673
};
enum Script_Texts_Bonker_Togglevolt
{
    SAY_bonker_1                    =-1700002,
    SAY_bonker_2                    =-1700003
};

bool QuestAccept_npc_bonker_togglevolt(Player* pPlayer, Creature* pCreature, Quest const* quest)
{
    if (quest->GetQuestId()==QUEST_GET_ME_OUTA_HERE)
    {
        switch (pPlayer->GetTeam())
        {
        case ALLIANCE:
                pCreature->setFaction(FACTION_ESCORTEE_A);
                break;
        case HORDE:
                pCreature->setFaction(FACTION_ESCORTEE_H);
                break;
        }
        DoScriptText(SAY_bonker_2, pCreature, pPlayer);
        CAST_AI(npc_escortAI, (pCreature->AI()))->Start(true, true, pPlayer->GetGUID());
    }
    return true;
}
struct npc_bonker_togglevoltAI : public npc_escortAI
{
    npc_bonker_togglevoltAI(Creature *c) : npc_escortAI(c) {}
    uint32 Bonker_agro;

    void Reset()
    {
    Bonker_agro=0;
    SetDespawnAtFar(false);
    }

    void JustDied(Unit* killer)
    {
        if (Player* pPlayer = GetPlayerForEscort())
            pPlayer->FailQuest(QUEST_ESCAPING_THE_MIST);
    }

    void UpdateEscortAI(const uint32 diff)
    {
        if (GetAttack() && UpdateVictim())
        {
            if(Bonker_agro==0)
            {
                DoScriptText(SAY_bonker_1,m_creature);
                Bonker_agro++;
            }
            DoMeleeAttackIfReady();
        }
        else Bonker_agro=0;
    }

    void WaypointReached(uint32 i)
    {
        Player* pPlayer = GetPlayerForEscort();

        if (!pPlayer)
            return;

        switch(i)
        {
        case 29:
            if (pPlayer)
                pPlayer->GroupEventHappens(QUEST_GET_ME_OUTA_HERE, m_creature);
            break;
        }
    }
};

CreatureAI* GetAI_npc_bonker_togglevolt(Creature* pCreature)
{
    return new npc_bonker_togglevoltAI(pCreature);
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
    newscript->Name = "npc_fezzix_geartwist";
    newscript->GetAI = &GetAI_npc_fezzix_geartwist;
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

    newscript = new Script;
    newscript->Name = "npc_thassarian";
    newscript->GetAI = &GetAI_npc_thassarian;
    newscript->pGossipHello = &GossipHello_npc_thassarian;
    newscript->pGossipSelect = &GossipSelect_npc_thassarian;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_image_lich_king";
    newscript->GetAI = &GetAI_npc_image_lich_king;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_counselor_talbot";
    newscript->GetAI = &GetAI_npc_counselor_talbot;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_leryssa";
    newscript->GetAI = &GetAI_npc_leryssa;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_general_arlos";
    newscript->GetAI = &GetAI_npc_general_arlos;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_beryl_sorcerer";
    newscript->GetAI = &GetAI_npc_beryl_sorcerer;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_imprisoned_beryl_sorcerer";
    newscript->GetAI = &GetAI_npc_imprisoned_beryl_sorcerer;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_mootoo_the_younger";
    newscript->GetAI = &GetAI_npc_mootoo_the_younger;
    newscript->pQuestAccept=&QuestAccept_npc_mootoo_the_younger;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_bonker_togglevolt";
    newscript->GetAI = &GetAI_npc_bonker_togglevolt;
    newscript->pQuestAccept=&QuestAccept_npc_bonker_togglevolt;
    newscript->RegisterSelf();
}
