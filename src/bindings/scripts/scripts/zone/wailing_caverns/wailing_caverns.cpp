/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/* ScriptData
SDName: Wailing Caverns
SD%Complete: 80
SDComment: Need some more polishing and in the event the druids should fly away not just morph and dissapear
SDCategory: Wailing Caverns
EndScriptData */

/* ContentData
EndContentData */

#include "precompiled.h"
#include "../../npc/npc_escortAI.h"
#include "def_wailing_caverns.h"

/*######
## npc_disciple_of_naralex
######*/

enum
{
    //say
    SAY_MAKE_PREPARATIONS         = -1043001,
    SAY_TEMPLE_OF_PROMISE         = -1043002,
    SAY_MUST_CONTINUE             = -1043003,
    SAY_BANISH_THE_SPIRITS        = -1043004,
    SAY_CAVERNS_PURIFIED          = -1043005,
    SAY_BEYOND_THIS_CORRIDOR      = -1043006,
    SAY_EMERALD_DREAM             = -1043007,
    SAY_MUTANUS_THE_DEVOURER      = -1043012,
    SAY_NARALEX_AWAKES            = -1043014,
    SAY_THANK_YOU                 = -1043015,
    SAY_FAREWELL                  = -1043016,
    SAY_ATTACKED                  = -1043017,
    //yell
    SAY_AT_LAST                   = -1043000,
    SAY_I_AM_AWAKE                = -1043013,
    //emote
    EMOTE_AWAKENING_RITUAL        = -1043008,
    EMOTE_TROUBLED_SLEEP          = -1043009,
    EMOTE_WRITHE_IN_AGONY         = -1043010,
    EMOTE_HORRENDOUS_VISION       = -1043011,
    //spell
    SPELL_MARK_OF_THE_WILD_RANK_2 = 5232,
    SPELL_SERPENTINE_CLEANSING    = 6270,
    SPELL_NATURE_CHANNELING       = 13236,
    SPELL_NARALEXS_AWAKENING      = 6271,
    SPELL_FLIGHT_FROM             = 33943,
    //npc entry
    NPC_DEVIATE_RAVAGER           = 3636,
    NPC_DEVIATE_VIPER             = 5755,
    NPC_DEVIATE_MOCCASIN          = 5762,
    NPC_NIGHTMARE_ECTOPLASM       = 5763,
    NPC_MUTANUS_THE_DEVOURER      = 3654,
};

#define GOSSIP_ID_START_1       698  //Naralex sleeps again!
#define GOSSIP_ID_START_2       699  //The fanglords are dead!
#define GOSSIP_ITEM_NARALEX     "Let the event begin!"
#define ACHIEVEMENT_WAILING_CAVERNS 630

struct TRINITY_DLL_DECL npc_disciple_of_naralexAI : public npc_escortAI
{
    npc_disciple_of_naralexAI(Creature *c) : npc_escortAI(c)
    {
        pInstance = c->GetInstanceData();
        eventTimer = 0;
        currentEvent = 0;
        eventProgress = 0;
        m_creature->setActive(true);
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_2);
    }

    uint32 eventTimer;
    uint32 currentEvent;
    uint32 eventProgress;
    ScriptedInstance *pInstance;

    void WaypointReached(uint32 i)
    {
        if (!pInstance)
            return;

        switch ( i )
        {
            case 4:
                eventProgress = 1;
                currentEvent = TYPE_NARALEX_PART1;
                pInstance->SetData(TYPE_NARALEX_PART1, IN_PROGRESS);
            break;
            case 5:
                DoScriptText(SAY_MUST_CONTINUE, m_creature);
                pInstance->SetData(TYPE_NARALEX_PART1, DONE);
            break;
            case 11:
                eventProgress = 1;
                currentEvent = TYPE_NARALEX_PART2;
                pInstance->SetData(TYPE_NARALEX_PART2, IN_PROGRESS);
            break;
            case 19:
                DoScriptText(SAY_BEYOND_THIS_CORRIDOR, m_creature);
            break;
            case 24:
                eventProgress = 1;
                currentEvent = TYPE_NARALEX_PART3;
                pInstance->SetData(TYPE_NARALEX_PART3, IN_PROGRESS);
            break;
        }
    }

    void Reset()
    {
        
    }

    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_ATTACKED, m_creature, who);
    }

    void JustDied(Unit *slayer)
    {
        if (pInstance)
        {
            pInstance->SetData(TYPE_NARALEX_EVENT, FAIL);
            pInstance->SetData(TYPE_NARALEX_PART1, FAIL);
            pInstance->SetData(TYPE_NARALEX_PART2, FAIL);
            pInstance->SetData(TYPE_NARALEX_PART3, FAIL);
        }
    }

    void JustSummoned(Creature* summoned)
    {
         summoned->AI()->AttackStart(m_creature);
    }

    void EnterEvadeMode()
    {        
        m_creature->RemoveAllAuras();
        m_creature->DeleteThreatList();
        m_creature->CombatStop(false);//do not interrupt channeling
        m_creature->SetLootRecipient(NULL);        
        if (GetIsBeingEscorted())
        {
            SetReturning(true);
            ReturnToLastPoint();
            debug_log("TSCR: EscortAI (EnterEvadeMode() Override) has left combat and is now returning to last point");
        }
        else
            m_creature->GetMotionMaster()->MoveTargetedHome();        
    }

    void UpdateAI(const uint32 diff)
    {
        if(currentEvent != TYPE_NARALEX_PART3)
            npc_escortAI::UpdateAI(diff);

        if (!pInstance)
            return;
        if(eventTimer <= diff)
        {
            eventTimer = 0;
            if (pInstance->GetData(currentEvent) == IN_PROGRESS)
            {
                switch (currentEvent)
                {
                    case TYPE_NARALEX_PART1:
                        if (eventProgress == 1)
                        {
                            eventProgress++;
                            DoScriptText(SAY_TEMPLE_OF_PROMISE, m_creature);
                            m_creature->SummonCreature(NPC_DEVIATE_RAVAGER, -82.1763, 227.874, -93.3233, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                            m_creature->SummonCreature(NPC_DEVIATE_RAVAGER, -72.9506, 216.645, -93.6756, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                        }
                    break;
                    case TYPE_NARALEX_PART2:
                        if (eventProgress == 1)
                        {
                            eventProgress++;
                            DoScriptText(SAY_BANISH_THE_SPIRITS, m_creature);
                            DoCast(m_creature, SPELL_SERPENTINE_CLEANSING);        
                            ((npc_escortAI*)m_creature->AI())->SetCanDefend(false);
                            eventTimer = 30000;
                            m_creature->SummonCreature(NPC_DEVIATE_VIPER, -61.5261, 273.676, -92.8442, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                            m_creature->SummonCreature(NPC_DEVIATE_VIPER, -58.4658, 280.799, -92.8393, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                            m_creature->SummonCreature(NPC_DEVIATE_VIPER, -50.002,  278.578, -92.8442, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                        }
                        else
                        if (eventProgress == 2)
                        {
                            ((npc_escortAI*)m_creature->AI())->SetCanDefend(true);
                            DoScriptText(SAY_CAVERNS_PURIFIED, m_creature);
                            pInstance->SetData(TYPE_NARALEX_PART2, DONE);
                            if (m_creature->HasAura(SPELL_SERPENTINE_CLEANSING))
                                m_creature->RemoveAura(SPELL_SERPENTINE_CLEANSING);
                        }
                    break;
                    case TYPE_NARALEX_PART3:
                        if (eventProgress == 1)
                        {
                            eventProgress++;
                            eventTimer = 15000;
                            m_creature->SetStandState(UNIT_STAND_STATE_KNEEL);
                            DoScriptText(SAY_EMERALD_DREAM, m_creature);
                            ((npc_escortAI*)m_creature->AI())->SetCanDefend(false);
                            if (Creature* naralex = pInstance->instance->GetCreature(pInstance->GetData64(DATA_NARALEX)))
                                m_creature->CastSpell(naralex, SPELL_NATURE_CHANNELING, true);
                            DoScriptText(EMOTE_AWAKENING_RITUAL, m_creature);
                        }
                        else
                        if (eventProgress == 2)
                        {
                            eventProgress++;
                            eventTimer = 15000;
                            if (Creature* naralex = pInstance->instance->GetCreature(pInstance->GetData64(DATA_NARALEX)))
                                DoScriptText(EMOTE_TROUBLED_SLEEP, naralex);
                            m_creature->SummonCreature(NPC_DEVIATE_MOCCASIN, 135.943, 199.701, -103.529, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 15000);
                            m_creature->SummonCreature(NPC_DEVIATE_MOCCASIN, 151.08,  221.13,  -103.609, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 15000);
                            m_creature->SummonCreature(NPC_DEVIATE_MOCCASIN, 128.007, 227.428, -97.421, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 15000);
                        }
                        else
                        if (eventProgress == 3)
                        {
                            eventProgress++;
                            eventTimer = 30000;
                            if (Creature* naralex = pInstance->instance->GetCreature(pInstance->GetData64(DATA_NARALEX)))
                                DoScriptText(EMOTE_WRITHE_IN_AGONY, naralex);
                            m_creature->SummonCreature(NPC_NIGHTMARE_ECTOPLASM, 133.413, 207.188, -102.469, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 15000);
                            m_creature->SummonCreature(NPC_NIGHTMARE_ECTOPLASM, 142.857, 218.645, -102.905, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 15000);
                            m_creature->SummonCreature(NPC_NIGHTMARE_ECTOPLASM, 105.102, 227.211, -102.752, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 15000);
                            m_creature->SummonCreature(NPC_NIGHTMARE_ECTOPLASM, 153.372, 235.149, -102.826, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 15000);
                            m_creature->SummonCreature(NPC_NIGHTMARE_ECTOPLASM, 149.524, 251.113, -102.558, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 15000);
                            m_creature->SummonCreature(NPC_NIGHTMARE_ECTOPLASM, 136.208, 266.466, -102.977, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 15000);
                            m_creature->SummonCreature(NPC_NIGHTMARE_ECTOPLASM, 126.167, 274.759, -102.962, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 15000);
                        }
                        else
                        if (eventProgress == 4)
                        {
                            eventProgress++;
                            if (Creature* naralex = pInstance->instance->GetCreature(pInstance->GetData64(DATA_NARALEX)))
                            {
                                DoScriptText(EMOTE_HORRENDOUS_VISION, naralex);
                                m_creature->CastSpell(naralex, SPELL_NARALEXS_AWAKENING, false);
                            }
                            m_creature->SummonCreature(NPC_MUTANUS_THE_DEVOURER, 150.872, 262.905, -103.503, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
                            DoScriptText(SAY_MUTANUS_THE_DEVOURER, m_creature);
                            pInstance->SetData(TYPE_MUTANUS_THE_DEVOURER, IN_PROGRESS);
                        }
                        else
                        if (eventProgress == 5 && pInstance->GetData(TYPE_MUTANUS_THE_DEVOURER) == DONE)
                        {
                            eventProgress++;
                            eventTimer = 3000;
                            if (Creature* naralex = pInstance->instance->GetCreature(pInstance->GetData64(DATA_NARALEX)))
                            {
                                AchievementEntry const *AchievWC = GetAchievementStore()->LookupEntry(ACHIEVEMENT_WAILING_CAVERNS);
                                if(AchievWC)
                                {
                                    Map *map = m_creature->GetMap();
                                    if(map && map->IsDungeon())
                                    {
                                        Map::PlayerList const &players = map->GetPlayers();
                                        for(Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                                            itr->getSource()->CompletedAchievement(AchievWC);
                                    }            
                                }
                                if (naralex->HasAura(SPELL_NATURE_CHANNELING))
                                    naralex->RemoveAura(SPELL_NATURE_CHANNELING);
                                if (m_creature->HasAura(SPELL_NARALEXS_AWAKENING))
                                    m_creature->RemoveAura(SPELL_NARALEXS_AWAKENING);
                                naralex->SetStandState(UNIT_STAND_STATE_STAND);
                                DoScriptText(SAY_I_AM_AWAKE, naralex);
                            }
                            DoScriptText(SAY_NARALEX_AWAKES, m_creature);
                        }
                        else
                        if (eventProgress == 6)
                        {
                            eventProgress++;
                            eventTimer = 6000;
                            if (Creature* naralex = pInstance->instance->GetCreature(pInstance->GetData64(DATA_NARALEX)))
                                DoScriptText(SAY_THANK_YOU, naralex);
                        }
                        else
                        if (eventProgress == 7)
                        {
                            eventProgress++;
                            eventTimer = 8000;
                            if (Creature* naralex = pInstance->instance->GetCreature(pInstance->GetData64(DATA_NARALEX)))
                            {
                                DoScriptText(SAY_FAREWELL, naralex);
                                naralex->AddAura(SPELL_FLIGHT_FROM,naralex);
                            }
                            m_creature->AddAura(SPELL_FLIGHT_FROM,m_creature);
                            m_creature->SetStandState(UNIT_STAND_STATE_STAND);
                        }
                        else
                        if (eventProgress == 8)
                        {
                            pInstance->SetData(TYPE_NARALEX_PART3, DONE);
                            if (Creature* naralex = pInstance->instance->GetCreature(pInstance->GetData64(DATA_NARALEX)))
                                naralex->SetVisibility(VISIBILITY_OFF);
                            m_creature->SetVisibility(VISIBILITY_OFF);
                        }
                    break;
                }
            }
        }else eventTimer -= diff;
    }
};

CreatureAI* GetAI_npc_disciple_of_naralex(Creature *_Creature)
{
    npc_disciple_of_naralexAI *disciple_of_naralexAI = new npc_disciple_of_naralexAI(_Creature);

    disciple_of_naralexAI->FillPointMovementListForCreature();

    return disciple_of_naralexAI;
}

bool GossipHello_npc_disciple_of_naralex(Player *player, Creature *_Creature)
{
    ScriptedInstance *pInstance = (_Creature->GetInstanceData());

    if (pInstance)
    {
        _Creature->CastSpell(player, SPELL_MARK_OF_THE_WILD_RANK_2, true);
        if ((pInstance->GetData(TYPE_LORD_COBRAHN) == DONE) && (pInstance->GetData(TYPE_LORD_PYTHAS) == DONE) &&
            (pInstance->GetData(TYPE_LADY_ANACONDRA) == DONE) && (pInstance->GetData(TYPE_LORD_SERPENTIS) == DONE))
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_NARALEX, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->SEND_GOSSIP_MENU(GOSSIP_ID_START_2, _Creature->GetGUID());

            DoScriptText(SAY_AT_LAST, _Creature);
        }
        else
        {
            player->SEND_GOSSIP_MENU(GOSSIP_ID_START_1, _Creature->GetGUID());
        }
    }
    return true;
}

bool GossipSelect_npc_disciple_of_naralex(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    ScriptedInstance *pInstance = (_Creature->GetInstanceData());
    if (action == GOSSIP_ACTION_INFO_DEF + 1)
    {
        player->CLOSE_GOSSIP_MENU();
        if (pInstance)pInstance->SetData(TYPE_NARALEX_EVENT, IN_PROGRESS);

        DoScriptText(SAY_MAKE_PREPARATIONS, _Creature);

        CAST_AI(npc_escortAI, (_Creature->AI()))->Start(false, true, false, player->GetGUID());
        CAST_AI(npc_escortAI, (_Creature->AI()))->SetDespawnAtFar(false);
        CAST_AI(npc_escortAI, (_Creature->AI()))->SetDespawnAtEnd(false);
    }
    return true;
}

void AddSC_wailing_caverns()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "npc_disciple_of_naralex";
    newscript->pGossipHello =  &GossipHello_npc_disciple_of_naralex;
    newscript->pGossipSelect = &GossipSelect_npc_disciple_of_naralex;
    newscript->GetAI = &GetAI_npc_disciple_of_naralex;
    newscript->RegisterSelf();
}