/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
SDName: Mulgore
SD%Complete: 100
SDComment: Support for quest: 11129, 772
SDCategory: Mulgore
EndScriptData */

/* ContentData
npc_skorn_whitecloud
npc_kyle_frenzied
npc_plains_vision
EndContentData */

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"

/*######
# npc_skorn_whitecloud
######*/

#define GOSSIP_SW "Tell me a story, Skorn."

class npc_skorn_whitecloud : public CreatureScript
{
public:
    npc_skorn_whitecloud() : CreatureScript("npc_skorn_whitecloud") { }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        if (uiAction == GOSSIP_ACTION_INFO_DEF)
            pPlayer->SEND_GOSSIP_MENU(523, pCreature->GetGUID());

        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        if (!pPlayer->GetQuestRewardStatus(770))
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SW, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

        pPlayer->SEND_GOSSIP_MENU(522, pCreature->GetGUID());

        return true;
    }

};


/*#####
# npc_kyle_frenzied
######*/

enum eKyleFrenzied
{
    //emote signed for 7780 but propably thats wrong id.
    EMOTE_SEE_LUNCH         = -1000340,
    EMOTE_EAT_LUNCH         = -1000341,
    EMOTE_DANCE             = -1000342,

    SPELL_LUNCH             = 42222,
    NPC_KYLE_FRENZIED       = 23616,
    NPC_KYLE_FRIENDLY       = 23622,
    POINT_ID                = 1
};

class npc_kyle_frenzied : public CreatureScript
{
public:
    npc_kyle_frenzied() : CreatureScript("npc_kyle_frenzied") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_kyle_frenziedAI (pCreature);
    }

    struct npc_kyle_frenziedAI : public ScriptedAI
    {
        npc_kyle_frenziedAI(Creature *c) : ScriptedAI(c) {}

        bool bEvent;
        bool m_bIsMovingToLunch;
        uint64 uiPlayerGUID;
        uint32 uiEventTimer;
        uint8 uiEventPhase;

        void Reset()
        {
            bEvent = false;
            m_bIsMovingToLunch = false;
            uiPlayerGUID = 0;
            uiEventTimer = 5000;
            uiEventPhase = 0;

            if (me->GetEntry() == NPC_KYLE_FRIENDLY)
                me->UpdateEntry(NPC_KYLE_FRENZIED);
        }

        void SpellHit(Unit* pCaster, SpellEntry const* pSpell)
        {
            if (!me->getVictim() && !bEvent && pSpell->Id == SPELL_LUNCH)
            {
                if (pCaster->GetTypeId() == TYPEID_PLAYER)
                    uiPlayerGUID = pCaster->GetGUID();

                if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() == WAYPOINT_MOTION_TYPE)
                {
                    me->GetMotionMaster()->MovementExpired();
                    me->GetMotionMaster()->MoveIdle();
                    me->StopMoving();
                }

                bEvent = true;
                DoScriptText(EMOTE_SEE_LUNCH, me);
                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_CREATURE_SPECIAL);
            }
        }

        void MovementInform(uint32 uiType, uint32 uiPointId)
        {
            if (uiType != POINT_MOTION_TYPE || !bEvent)
                return;

            if (uiPointId == POINT_ID)
                m_bIsMovingToLunch = false;
        }

        void UpdateAI(const uint32 diff)
        {
            if (bEvent)
            {
                if (m_bIsMovingToLunch)
                    return;

                if (uiEventTimer <= diff)
                {
                    uiEventTimer = 5000;
                    ++uiEventPhase;

                    switch(uiEventPhase)
                    {
                        case 1:
                            if (Unit* pUnit = Unit::GetUnit(*me,uiPlayerGUID))
                            {
                                if (GameObject* pGo = pUnit->GetGameObject(SPELL_LUNCH))
                                {
                                    m_bIsMovingToLunch = true;
                                    me->GetMotionMaster()->MovePoint(POINT_ID, pGo->GetPositionX(), pGo->GetPositionY(), pGo->GetPositionZ());
                                }
                            }
                            break;
                        case 2:
                            DoScriptText(EMOTE_EAT_LUNCH, me);
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_USESTANDING);
                            break;
                        case 3:
                            if (Player* pUnit = Unit::GetPlayer(*me, uiPlayerGUID))
                                pUnit->TalkedToCreature(me->GetEntry(), me->GetGUID());

                            me->UpdateEntry(NPC_KYLE_FRIENDLY);
                            break;
                        case 4:
                            uiEventTimer = 30000;
                            DoScriptText(EMOTE_DANCE, me);
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_DANCESPECIAL);
                            break;
                        case 5:
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_NONE);
                            Reset();
                            me->GetMotionMaster()->Clear();
                            break;
                    }
                }
                else
                    uiEventTimer -= diff;
            }
        }
    };

};


/*#####
# npc_plains_vision
######*/

float wp_plain_vision[50][3] =
{
    {-2226.32,  -408.095,   -9.36235},
    {-2203.04,  -437.212,   -5.72498},
    {-2163.91,  -457.851,   -7.09049},
    {-2123.87,  -448.137,   -9.29591},
    {-2104.66,  -427.166,   -6.49513},
    {-2101.48,  -422.826,   -5.3567},
    {-2097.56,  -417.083,   -7.16716},
    {-2084.87,  -398.626,   -9.88973},
    {-2072.71,  -382.324,   -10.2488},
    {-2054.05,  -356.728,   -6.22468},
    {-2051.8,   -353.645,   -5.35791},
    {-2049.08,  -349.912,   -6.15723},
    {-2030.6,   -310.724,   -9.59302},
    {-2002.15,  -249.308,   -10.8124},
    {-1972.85,  -195.811,   -10.6316},
    {-1940.93,  -147.652,   -11.7055},
    {-1888.06,  -81.943,    -11.4404},
    {-1837.05,  -34.0109,   -12.258},
    {-1796.12,  -14.6462,   -10.3581},
    {-1732.61,  -4.27746,   -10.0213},
    {-1688.94,  -0.829945,  -11.7103},
    {-1681.32,  13.0313,    -9.48056},
    {-1677.04,  36.8349,    -7.10318},
    {-1675.2,   68.559,     -8.95384},
    {-1676.57,  89.023,     -9.65104},
    {-1678.16,  110.939,    -10.1782},
    {-1677.86,  128.681,    -5.73869},
    {-1675.27,  144.324,    -3.47916},
    {-1671.7,   163.169,    -1.23098},
    {-1666.61,  181.584,    5.26145},
    {-1661.51,  196.154,    8.95252},
    {-1655.47,  210.811,    8.38727},
    {-1647.07,  226.947,    5.27755},
    {-1621.65,  232.91,     2.69579},
    {-1600.23,  237.641,    2.98539},
    {-1576.07,  242.546,    4.66541},
    {-1554.57,  248.494,    6.60377},
    {-1547.53,  259.302,    10.6741},
    {-1541.7,   269.847,    16.4418},
    {-1539.83,  278.989,    21.0597},
    {-1540.16,  290.219,    27.8247},
    {-1538.99,  298.983,    34.0032},
    {-1540.38,  307.337,    41.3557},
    {-1536.61,  314.884,    48.0179},
    {-1532.42,  323.277,    55.6667},
    {-1528.77,  329.774,    61.1525},
    {-1525.65,  333.18,     63.2161},
    {-1517.01,  350.713,    62.4286},
    {-1511.39,  362.537,    62.4539},
    {-1508.68,  366.822,    62.733}
};

class npc_plains_vision : public CreatureScript
{
public:
    npc_plains_vision() : CreatureScript("npc_plains_vision") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
          return new npc_plains_visionAI (pCreature);
    }

    struct npc_plains_visionAI  : public ScriptedAI
    {
        npc_plains_visionAI(Creature *c) : ScriptedAI(c) {}

        bool newWaypoint;
        uint8 WayPointId;
        uint8 amountWP;

        void Reset()
        {
            WayPointId = 0;
            newWaypoint = true;
            amountWP  = 49;
        }

        void EnterCombat(Unit* /*who*/){}

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (id < amountWP)
            {
                ++WayPointId;
                newWaypoint = true;
            }
            else
            {
                me->setDeathState(JUST_DIED);
                me->RemoveCorpse();
            }
        }

        void UpdateAI(const uint32 /*diff*/)
        {
            if (newWaypoint)
            {
                me->GetMotionMaster()->MovePoint(WayPointId, wp_plain_vision[WayPointId][0], wp_plain_vision[WayPointId][1], wp_plain_vision[WayPointId][2]);
                newWaypoint = false;
            }
        }
    };

};


/*#####
#
######*/

void AddSC_mulgore()
{
    new npc_skorn_whitecloud();
    new npc_kyle_frenzied();
    new npc_plains_vision();
}
