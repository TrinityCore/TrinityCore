/*
 * Copyright (C) 2009 - 2011 by WarHead (United Worlds of MaNGOS)
 * Copyright (C) 2008 - 2009 Trinity <http://www.trinitycore.org/>
 *
 * Patch supported by ChaosUA & TCRU community http://trinity-core.ru/
 *
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

#include "ScriptPCH.h"
#include "OutdoorPvPWG.h"
#include "OutdoorPvPMgr.h"

#define GOSSIP_HELLO_DEMO1  "Baue ein Katapult."
#define GOSSIP_HELLO_DEMO2  "Baue einen Verwüster."
#define GOSSIP_HELLO_DEMO3  "Baue eine Belagerungsmaschine."
#define GOSSIP_HELLO_DEMO4  "Ich kann im Moment nicht mehr bauen!"

enum NPC_TW_MISC_EVENTS
{
    EVENT_STRIKE = 1,
    EVENT_ARCANE_MISSILES,
    EVENT_SLOW,
    EVENT_HEALING_WAVE,
    EVENT_LIGHTNING_BOLT,
    EVENT_QUICK_FLAME_WARD,
    EVENT_MORTAL_STRIKE,
    EVENT_HEAL,
    EVENT_HOLY_NOVA,
    EVENT_CLEAVE,
    EVENT_WASSERCHECK,
    EVENT_SCHLAFCHECK,
    EVENT_TELEPORTCHECK
};

enum NPC_TW_MISC_SPELLS
{
    SPELL_STRIKE                = 11976,    // TW_NPC_WACHE + TW_NPC_CHAMPION
    SPELL_SLEEPING_SLEEP        = 42648,    // TW_NPC_CHAMPION
    SPELL_ARCANE_MISSILES       = 31743,    // TW_NPC_VERZAUBERER_A
    SPELL_SLOW                  = 31741,    // TW_NPC_VERZAUBERER_A
    SPELL_HEALING_WAVE          = 11986,    // TW_NPC_VERZAUBERER_H
    SPELL_LIGHTNING_BOLT        = 9532,     // TW_NPC_VERZAUBERER_H
    SPELL_QUICK_FLAME_WARD      = 4979,     // TW_NPC_VERZAUBERER_H
    SPELL_MORTAL_STRIKE         = 15708,    // TW_NPC_QUESTGEBER_1 + TW_NPC_QUESTGEBER_2 + TW_NPC_QUESTGEBER_3 + TW_NPC_QUESTGEBER_4
    SPELL_HEAL                  = 34945,    // TW_NPC_QUESTGEBER_5_A
    SPELL_HOLY_NOVA             = 34944,    // TW_NPC_QUESTGEBER_5_A
    SPELL_POWER_WORD_SHIELD     = 17139,    // TW_NPC_QUESTGEBER_5_A
    SPELL_CLEAVE                = 15284     // TW_NPC_QUESTGEBER_5_H + TW_NPC_QUESTGEBER_6
};

enum TW_NPC_IDS
{
    TW_NPC_WACHE_A                  = 32308,
    TW_NPC_WACHE_H                  = 32307,
    TW_NPC_CHAMPION_A               = 30740,
    TW_NPC_CHAMPION_H               = 30739,
    TW_NPC_RUESTMEISTER_1_A         = 32294,
    TW_NPC_RUESTMEISTER_1_H         = 32296,
    TW_NPC_RUESTMEISTER_2_A         = 39172,
    TW_NPC_RUESTMEISTER_2_H         = 39173,
    TW_NPC_GEISTERFUEHRER_A         = 31842,
    TW_NPC_GEISTERFUEHRER_H         = 31841,
    TW_NPC_GEISTHEILER_A            = 6491,
    TW_NPC_GEISTHEILER_H            = 6491,
    TW_NPC_VERWUESTERINGENIEUR_A    = 30499,
    TW_NPC_VERWUESTERINGENIEUR_H    = 30400,
    TW_NPC_VERZAUBERER_A            = 31051,
    TW_NPC_VERZAUBERER_H            = 31101,
    TW_NPC_QUESTGEBER_1_A           = 31052,
    TW_NPC_QUESTGEBER_1_H           = 31102,
    TW_NPC_QUESTGEBER_2_A           = 31109,
    TW_NPC_QUESTGEBER_2_H           = 31107,
    TW_NPC_QUESTGEBER_3_A           = 31153,
    TW_NPC_QUESTGEBER_3_H           = 31151,
    TW_NPC_QUESTGEBER_4_A           = 31108,
    TW_NPC_QUESTGEBER_4_H           = 31106,
    TW_NPC_QUESTGEBER_5_A           = 31054,
    TW_NPC_QUESTGEBER_5_H           = 31053,
    TW_NPC_QUESTGEBER_6_A           = 31036,
    TW_NPC_QUESTGEBER_6_H           = 31091,
    TW_NPC_QUESTGEBER_PVP_1_A       = 15351,
    TW_NPC_QUESTGEBER_PVP_1_H       = 15350,
    TW_NPC_QUESTGEBER_PVP_2_A       = 32626,
    TW_NPC_QUESTGEBER_PVP_2_H       = 32615,
    TW_NPC_BELAGERUNGSMASCHINE_A    = 28312,
    TW_NPC_BELAGERUNGSMASCHINE_H    = 32627,
    TW_NPC_BELAGERUNGSTURM_A        = 28319,
    TW_NPC_BELAGERUNGSTURM_H        = 32629,
    TW_NPC_KATAPULT_A               = 27881,
    TW_NPC_KATAPULT_H               = 27881,
    TW_NPC_VERWUESTER_A             = 28094,
    TW_NPC_VERWUESTER_H             = 28094,
    TW_NPC_TURMKANONE_A             = 28366,
    TW_NPC_TURMKANONE_H             = 28366,
    TW_NPC_FLUGMEISTER_A            = 30869,
    TW_NPC_FLUGMEISTER_H            = 30870,
    TW_NPC_WAFFENKONTROLLE_A        = 27852,
    TW_NPC_WAFFENKONTROLLE_H        = 27852,
    TW_NPC_ENTDECKUNGSEINHEIT       = 27869,
    // Elementare
    TW_NPC_LEBENDER_PEITSCHER       = 30845,
    TW_NPC_AUSGEWACHSENER_PEITSCHER = 34300,
    TW_NPC_WANDERNDER_SCHATTEN      = 30842,
    TW_NPC_SCHATTENKLAGEGEIST       = 30872,
    TW_NPC_EISZEITLICHER_GEIST      = 30846,
    TW_NPC_WASSERKLAGEGEIST         = 30877,
    TW_NPC_KUEHLER_ERDELEMENTAR     = 30849,
    TW_NPC_ERDKLAGEGEIST            = 30876,
    TW_NPC_FLUESTERNDER_WIND        = 30848,
    TW_NPC_STURMKLAGEGEIST          = 30875,
    TW_NPC_TOBENDE_FLAMME           = 30847,
    TW_NPC_FEUERKLAGEGEIST          = 30873,
    // Quest Kill Credit NPCs
    TW_NPC_PVP_KILL_ALLIANCE        = 31086,
    TW_NPC_PVP_KILL_HORDE           = 39019,
    TW_NPC_PVP_KILL_VEHICLE         = 31093,
    TW_NPC_PVP_KILL_FIRE            = 31071,
    TW_NPC_PVP_KILL_WATER           = 31072,
    TW_NPC_PVP_KILL_SHADOW          = 31073,
    TW_NPC_PVP_KILL_LIFE            = 31074,
    TW_NPC_PVP_KILL_TOWER           = 31156,
    TW_NPC_PVP_KILL_STRUCTURE       = 31244,
    TW_NPC_PVP_KILL_BRIDGE          = 31286,
    TW_NPC_PVP_KILL_WALL            = 31287,
    TW_NPC_PVP_KILL_WORKSHOP        = 31288,
    TW_NPC_PVP_KILL_GATE            = 31289,
    TW_NPC_PVP_KILL_SOUTHERN_TOWER  = 35074,
    TW_NPC_VEHICLE_PROTECTED        = 31284
};

class npc_demolisher_engineerer : public CreatureScript
{
public:
    npc_demolisher_engineerer() : CreatureScript("npc_demolisher_engineerer") { }


bool OnGossipHello(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if(pPlayer->isGameMaster() || pCreature->GetZoneScript() && pCreature->GetZoneScript()->GetData(pCreature->GetDBTableGUIDLow()))
    {
        if (pPlayer->HasAura(SPELL_CORPORAL))
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_DEMO1, GOSSIP_SENDER_MAIN,   GOSSIP_ACTION_INFO_DEF);
        else if (pPlayer->HasAura(SPELL_LIEUTENANT))
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_DEMO1, GOSSIP_SENDER_MAIN,   GOSSIP_ACTION_INFO_DEF);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_DEMO2, GOSSIP_SENDER_MAIN,   GOSSIP_ACTION_INFO_DEF+1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_DEMO3, GOSSIP_SENDER_MAIN,   GOSSIP_ACTION_INFO_DEF+2);
        }
    }
    else
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_DEMO4, GOSSIP_SENDER_MAIN,   GOSSIP_ACTION_INFO_DEF+9);

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
    return true;
}

bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    pPlayer->CLOSE_GOSSIP_MENU();
    if(pPlayer->isGameMaster() || pCreature->GetZoneScript() && pCreature->GetZoneScript()->GetData(pCreature->GetDBTableGUIDLow()))
    {
        switch(uiAction - GOSSIP_ACTION_INFO_DEF)
        {
            case 0: pPlayer->CastSpell(pPlayer, 56663, false, NULL, NULL, pCreature->GetGUID()); break;
            case 1: pPlayer->CastSpell(pPlayer, 56575, false, NULL, NULL, pCreature->GetGUID()); break;
            case 2: pPlayer->CastSpell(pPlayer, pPlayer->GetTeamId() ? 61408 : 56661, false, NULL, NULL, pCreature->GetGUID()); break;
        }
    }

    return true;
}

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_demolisher_engineererAI(pCreature);
    }

    struct npc_demolisher_engineererAI : public ScriptedAI
    {
        npc_demolisher_engineererAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            me->SetReactState(REACT_PASSIVE);
        }
    };

};

enum eWintergraspBattleMage
{
    SPELL_PORTAL_VISUAL        = 60223,
    GO_WINTERGRASP_PORTAL    = 193772
};

class npc_wg_ally_battle_mage : public CreatureScript
{
public:
    npc_wg_ally_battle_mage() : CreatureScript("npc_wg_ally_battle_mage") { }

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_wg_ally_battle_mageAI(creature);
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (!sWorld->getBoolConfig(CONFIG_OUTDOORPVP_WINTERGRASP_ENABLED))
            return false;

        if (OutdoorPvPWG *pvpWG = (OutdoorPvPWG*)sOutdoorPvPMgr->GetOutdoorPvPToZoneId(4197))
        {
            if (pvpWG->isWarTime())
            {
                if (pvpWG->getDefenderTeam() == TEAM_HORDE)
                    pPlayer->SEND_GOSSIP_MENU(14777, pCreature->GetGUID());
                else
                    pPlayer->SEND_GOSSIP_MENU(14781, pCreature->GetGUID());
            }
            else
            {
                if (pvpWG->getDefenderTeam() == TEAM_HORDE)
                    pPlayer->SEND_GOSSIP_MENU(14775, pCreature->GetGUID());
                else
                    pPlayer->SEND_GOSSIP_MENU(14782, pCreature->GetGUID());
            }
        }
        return true;
    }

    struct npc_wg_ally_battle_mageAI : public ScriptedAI
    {
        npc_wg_ally_battle_mageAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            uiPortalTimer = 0;
            uiPortalPhase = 0;
            Check = true;
        }

        uint32 uiPortalTimer;
        uint8 uiPortalPhase;
        GameObject* WintergraspPortal;
        bool Player;
        bool Check;
        bool Check2;

        void UpdateAI(const uint32 diff)
        {
            // If WG is disabled, don't do anything.
            if (!sWorld->getBoolConfig(CONFIG_OUTDOORPVP_WINTERGRASP_ENABLED))
                return;

            if (OutdoorPvPWG *pvpWG = (OutdoorPvPWG*)sOutdoorPvPMgr->GetOutdoorPvPToZoneId(4197))
            {
                // Get playerlist if there is.
                if (pvpWG->isWarTime() && Check == true)
                {
                    Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    {
                        if (!PlayerList.isEmpty())
                        {
                            if (i->getSource()->GetDistance2d(me) <= 75)
                            {
                                Player = true;
                                Check = false;
                            }
                            else
                            {
                                Player = false;
                                Check = false;
                                Check2 = true;
                            }
                        }
                        else
                        {
                            Player = false;
                            Check = false;
                            Check2 = true;
                        }
                    }
                }

                if (pvpWG->m_changeAlly != true) // If wg is switching (.wg switch)
                {
                    if (pvpWG->isWarTime())
                    {
                        if (Player == true) //(false) If there isn't any player, then, don't cast the portal spell. Just summon gameobject.
                        {
                            if (uiPortalTimer <= diff)
                            {
                                switch (uiPortalPhase)
                                {
                                case 0:
                                    me->SetOrientation(4.037271f);
                                    me->SendMovementFlagUpdate();
                                    ++uiPortalPhase;
                                    uiPortalTimer = 100;
                                    break;
                                case 1:
                                    me->AI()->DoCast(SPELL_PORTAL_VISUAL);
                                    ++uiPortalPhase;
                                    uiPortalTimer = 900;
                                    break;
                                case 2:
                                    WintergraspPortal = me->SummonGameObject(GO_WINTERGRASP_PORTAL, 5686.974609f, 773.303711f, 647.753235f, 5.572729f, 0, 0, 0.324484f, -0.945891f, 0);
                                    me->SetOrientation(5.515240f);
                                    me->SendMovementFlagUpdate();
                                    me->MonsterYell("Reinforcements are needed on the Wintergrasp battlefield! I have opened a portal for quick travel to the battle at The Silver Enclave.", LANG_UNIVERSAL, 0);
                                    ++uiPortalPhase;
                                    uiPortalTimer = 1000;
                                    break;
                                }
                            }else uiPortalTimer -= diff;
                        }
                        else
                        {
                            if (Check2 == true) // If the portal isn't exist
                            {
                                WintergraspPortal = me->SummonGameObject(GO_WINTERGRASP_PORTAL, 5686.974609f, 773.303711f, 647.753235f, 5.572729f, 0, 0, 0.324484f, -0.945891f, 0);
                                Check2 = false;
                            }
                        }
                    }
                    else
                    {
                        if (pvpWG->getDefenderTeam() == TEAM_ALLIANCE)
                        {
                            if (pvpWG->m_timer <= 3600000) // An hour before battle begin, the portal will disappear.
                            {
                                uiPortalTimer = 0;
                                uiPortalPhase = 0;
                                Check = true;
                                Check2 = false;
                                if (GameObject* WintergraspPortal = me->FindNearestGameObject(GO_WINTERGRASP_PORTAL, 5.0f)) // If the portal is exist
                                    WintergraspPortal->RemoveFromWorld();
                            }
                        }
                        else
                        {
                            uiPortalTimer = 0;
                            uiPortalPhase = 0;
                            Check = true;
                            Check2 = false;
                            if (GameObject* WintergraspPortal = me->FindNearestGameObject(GO_WINTERGRASP_PORTAL, 5.0f)) // If the portal is exist
                                WintergraspPortal->RemoveFromWorld();
                        }
                    }
                }
            }
        }
    };
};

class npc_wg_horde_battle_mage : public CreatureScript
{
public:
    npc_wg_horde_battle_mage() : CreatureScript("npc_wg_horde_battle_mage") { }

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_wg_horde_battle_mageAI(creature);
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (!sWorld->getBoolConfig(CONFIG_OUTDOORPVP_WINTERGRASP_ENABLED))
            return false;

        if (OutdoorPvPWG *pvpWG = (OutdoorPvPWG*)sOutdoorPvPMgr->GetOutdoorPvPToZoneId(4197))
        {
            if (pvpWG->isWarTime())
            {
                if (pvpWG->getDefenderTeam() == TEAM_HORDE)
                    pPlayer->SEND_GOSSIP_MENU(14777, pCreature->GetGUID());
                else
                    pPlayer->SEND_GOSSIP_MENU(14781, pCreature->GetGUID());
            }
            else
            {
                if (pvpWG->getDefenderTeam() == TEAM_HORDE)
                    pPlayer->SEND_GOSSIP_MENU(14775, pCreature->GetGUID());
                else
                    pPlayer->SEND_GOSSIP_MENU(14782, pCreature->GetGUID());
            }
        }
        return true;
    }

    struct npc_wg_horde_battle_mageAI : public ScriptedAI
    {
        npc_wg_horde_battle_mageAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            uiPortalTimer = 0;
            uiPortalPhase = 0;
            Check = true;
        }

        uint32 uiPortalTimer;
        uint8 uiPortalPhase;
        GameObject* WintergraspPortal;
        bool Player;
        bool Check;
        bool Check2;

        void UpdateAI(const uint32 diff)
        {
            // If WG is disabled, don't do anything.
            if (!sWorld->getBoolConfig(CONFIG_OUTDOORPVP_WINTERGRASP_ENABLED))
                return;

            if (OutdoorPvPWG *pvpWG = (OutdoorPvPWG*)sOutdoorPvPMgr->GetOutdoorPvPToZoneId(4197))
            {
                // Get playerlist if there is.
                if (pvpWG->isWarTime() && Check == true)
                {
                    Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    {
                        if (!PlayerList.isEmpty())
                        {
                            if (i->getSource()->GetDistance2d(me) <= 75)
                            {
                                Player = true;
                                Check = false;
                            }
                            else
                            {
                                Player = false;
                                Check = false;
                                Check2 = true;
                            }
                        }
                        else
                        {
                            Player = false;
                            Check = false;
                            Check2 = true;
                        }
                    }
                }

                if (pvpWG->m_changeHorde != true) // If wg is switching (.wg switch)
                {
                    if (pvpWG->isWarTime())
                    {
                        if (Player == true) //(false) If there isn't any player, then, don't cast the portal spell. Just summon gameobject.
                        {
                            if (uiPortalTimer <= diff)
                            {
                                switch (uiPortalPhase)
                                {
                                case 0:
                                    me->SetOrientation(4.356160f);
                                    me->SendMovementFlagUpdate();
                                    ++uiPortalPhase;
                                    uiPortalTimer = 100;
                                    break;
                                case 1:
                                    me->AI()->DoCast(SPELL_PORTAL_VISUAL);
                                    ++uiPortalPhase;
                                    uiPortalTimer = 900;
                                    break;
                                case 2:
                                    WintergraspPortal = me->SummonGameObject(GO_WINTERGRASP_PORTAL, 5924.042969f, 570.354492f, 661.087280f, 5.930885f, 0, 0, 0.324484f, -0.945891f, 0);
                                    me->SetOrientation(6.003930f);
                                    me->SendMovementFlagUpdate();
                                    ++uiPortalPhase;
                                    uiPortalTimer = 1000;
                                    break;
                                }
                            }else uiPortalTimer -= diff;
                        }
                        else
                        {
                            if (Check2 == true) // If the portal isn't exist
                            {
                                WintergraspPortal = me->SummonGameObject(GO_WINTERGRASP_PORTAL, 5686.974609f, 773.303711f, 647.753235f, 5.572729f, 0, 0, 0.324484f, -0.945891f, 0);
                                Check2 = false;
                            }
                        }
                    }
                    else
                    {
                        if (pvpWG->getDefenderTeam() == TEAM_HORDE)
                        {
                            if (pvpWG->m_timer <= 3600000) // An hour before battle begin, the portal will disappear.
                            {
                                uiPortalTimer = 0;
                                uiPortalPhase = 0;
                                Check = true;
                                Check2 = false;
                                if (GameObject* WintergraspPortal = me->FindNearestGameObject(GO_WINTERGRASP_PORTAL, 5.0f)) // If the portal is exist
                                    WintergraspPortal->RemoveFromWorld();
                            }
                        }
                        else
                        {
                            uiPortalTimer = 0;
                            uiPortalPhase = 0;
                            Check = true;
                            Check2 = false;
                            if (GameObject* WintergraspPortal = me->FindNearestGameObject(GO_WINTERGRASP_PORTAL, 5.0f)) // If the portal is exist
                                WintergraspPortal->RemoveFromWorld();
                        }
                    }
                }
            }
        }
    };
};

class npc_tausendwinter_diverse : public CreatureScript
{
public:
    npc_tausendwinter_diverse() : CreatureScript("npc_tausendwinter_diverse") { }

    struct npc_tausendwinter_diverseAI : public ScriptedAI
    {
        npc_tausendwinter_diverseAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pTW = NULL;
        }

        EventMap events;
        EventMap eventsOOC;
        OutdoorPvPWG * pTW;

        void Reset()
        {
            if (!pTW)
                pTW = const_cast<OutdoorPvPWG*> ((OutdoorPvPWG*)sOutdoorPvPMgr->GetOutdoorPvPToZoneId(NORDEND_TAUSENDWINTER));

            events.Reset();
            eventsOOC.Reset();

            switch(me->GetEntry())
            {
                case TW_NPC_VERZAUBERER_A:
                    // Standard Entfernung
                    me->m_isCaster = true;
                    break;
                case TW_NPC_VERZAUBERER_H:
                case TW_NPC_QUESTGEBER_5_A:
                    me->m_isCaster = true;
                    me->m_CasterDefaultMaxCombatRange = 39;
                    break;
            }
            eventsOOC.ScheduleEvent(EVENT_SCHLAFCHECK, urand(5000, 30000));
        }

        void JustReachedHome()
        {
            switch(me->GetEntry())
            {
                case TW_NPC_CHAMPION_A:
                case TW_NPC_CHAMPION_H:
                    if (pTW && !pTW->isWarTime())
                        eventsOOC.RescheduleEvent(EVENT_SCHLAFCHECK, urand(5000, 30000));
                    break;
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_STRIKE, 5000);
            events.ScheduleEvent(EVENT_ARCANE_MISSILES, 500);
            events.ScheduleEvent(EVENT_SLOW, 100);
            events.ScheduleEvent(EVENT_HEALING_WAVE, 5000);
            events.ScheduleEvent(EVENT_LIGHTNING_BOLT, 500);
            events.ScheduleEvent(EVENT_QUICK_FLAME_WARD, 100);
            events.ScheduleEvent(EVENT_MORTAL_STRIKE, 5000);
            events.ScheduleEvent(EVENT_HEAL, 5000);
            events.ScheduleEvent(EVENT_HOLY_NOVA, 4000);
            events.ScheduleEvent(EVENT_CLEAVE, 5000);

            switch(me->GetEntry())
            {
                case TW_NPC_QUESTGEBER_5_A:
                    DoCast(me, SPELL_POWER_WORD_SHIELD);
                    break;
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            eventsOOC.Update(uiDiff);

            switch(me->GetEntry())
            {
                case TW_NPC_CHAMPION_A:
                case TW_NPC_CHAMPION_H:
                    if (EVENT_SCHLAFCHECK == eventsOOC.ExecuteEvent())
                        if (pTW)
                            if (pTW->isWarTime())
                            {
                                if (me->HasAura(SPELL_SLEEPING_SLEEP))
                                    me->RemoveAurasDueToSpell(SPELL_SLEEPING_SLEEP);
                            }
                            else
                            {
                                if (!me->HasAura(SPELL_SLEEPING_SLEEP))
                                    DoCast(me, SPELL_SLEEPING_SLEEP);
                            }
                    eventsOOC.RescheduleEvent(EVENT_SCHLAFCHECK, urand(5000,30000));
                    break;
            }

            if (!UpdateVictim())
                return;

            events.Update(uiDiff);

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            uint32 eventId = events.ExecuteEvent();
            switch(eventId)
            {
                case EVENT_STRIKE:
                    switch(me->GetEntry())
                    {
                        case TW_NPC_WACHE_A:
                        case TW_NPC_WACHE_H:
                        case TW_NPC_CHAMPION_A:
                        case TW_NPC_CHAMPION_H:
                            DoCastVictim(SPELL_STRIKE);
                            events.RescheduleEvent(EVENT_STRIKE, 5000);
                            break;
                    }
                case EVENT_ARCANE_MISSILES:
                    switch(me->GetEntry())
                    {
                        case TW_NPC_VERZAUBERER_A:
                            DoCastVictim(SPELL_ARCANE_MISSILES);
                            events.RescheduleEvent(EVENT_ARCANE_MISSILES, 5000);
                            break;
                    }
                case EVENT_SLOW:
                    switch(me->GetEntry())
                    {
                        case TW_NPC_VERZAUBERER_A:
                            DoCastVictim(SPELL_SLOW);
                            events.RescheduleEvent(EVENT_SLOW, 15000);
                            break;
                    }
                case EVENT_HEALING_WAVE:
                    switch(me->GetEntry())
                    {
                        case TW_NPC_VERZAUBERER_H:
                            if (HealthBelowPct(50))
                                DoCast(me, SPELL_HEALING_WAVE);
                            events.RescheduleEvent(EVENT_HEALING_WAVE, 3000);
                            break;
                    }
                case EVENT_LIGHTNING_BOLT:
                    switch(me->GetEntry())
                    {
                        case TW_NPC_VERZAUBERER_H:
                            DoCastVictim(SPELL_LIGHTNING_BOLT);
                            events.RescheduleEvent(EVENT_LIGHTNING_BOLT, 5000);
                            break;
                    }
                case EVENT_QUICK_FLAME_WARD:
                    switch(me->GetEntry())
                    {
                        case TW_NPC_VERZAUBERER_H:
                            DoCast(me, SPELL_QUICK_FLAME_WARD);
                            events.RescheduleEvent(EVENT_QUICK_FLAME_WARD, 10000);
                            break;
                    }
                case EVENT_MORTAL_STRIKE:
                    switch(me->GetEntry())
                    {
                        case TW_NPC_QUESTGEBER_1_A:
                        case TW_NPC_QUESTGEBER_1_H:
                        case TW_NPC_QUESTGEBER_2_A:
                        case TW_NPC_QUESTGEBER_2_H:
                        case TW_NPC_QUESTGEBER_3_A:
                        case TW_NPC_QUESTGEBER_3_H:
                        case TW_NPC_QUESTGEBER_4_A:
                        case TW_NPC_QUESTGEBER_4_H:
                            DoCastVictim(SPELL_MORTAL_STRIKE);
                            events.RescheduleEvent(EVENT_MORTAL_STRIKE, 10000);
                            break;
                    }
                case EVENT_HEAL:
                    switch(me->GetEntry())
                    {
                        case TW_NPC_QUESTGEBER_5_A:
                            if (HealthBelowPct(50))
                                DoCast(me, SPELL_HEAL);
                            events.RescheduleEvent(EVENT_HEAL, 5000);
                            break;
                    }
                case EVENT_HOLY_NOVA:
                    switch(me->GetEntry())
                    {
                        case TW_NPC_QUESTGEBER_5_A:
                            DoCast(me, SPELL_HOLY_NOVA);
                            events.RescheduleEvent(EVENT_HOLY_NOVA, 8000);
                            break;
                    }
                case EVENT_CLEAVE:
                    switch(me->GetEntry())
                    {
                        case TW_NPC_QUESTGEBER_5_H:
                        case TW_NPC_QUESTGEBER_6_A:
                        case TW_NPC_QUESTGEBER_6_H:
                            DoCastVictim(SPELL_CLEAVE);
                            events.RescheduleEvent(EVENT_CLEAVE, 10000);
                            break;
                    }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_tausendwinter_diverseAI (pCreature);
    }
};

void AddSC_wintergrasp()
{
    new npc_demolisher_engineerer();
    new npc_wg_ally_battle_mage();
    new npc_wg_horde_battle_mage();
    new npc_tausendwinter_diverse();
}
