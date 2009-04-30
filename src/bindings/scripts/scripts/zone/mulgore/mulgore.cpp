/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

#include "precompiled.h"
#include "../../npc/npc_escortAI.h"

/*######
# npc_skorn_whitecloud
######*/

#define GOSSIP_SW "Tell me a story, Skorn."

bool GossipHello_npc_skorn_whitecloud(Player *player, Creature *_Creature)
{
    if (_Creature->isQuestGiver())
        player->PrepareQuestMenu( _Creature->GetGUID() );

    if (!player->GetQuestRewardStatus(770))
        player->ADD_GOSSIP_ITEM( 0, GOSSIP_SW, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF );

    player->SEND_GOSSIP_MENU(522,_Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_skorn_whitecloud(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    if (action == GOSSIP_ACTION_INFO_DEF)
        player->SEND_GOSSIP_MENU(523,_Creature->GetGUID());

    return true;
}

/*#####
# npc_kyle_frenzied
######*/

struct TRINITY_DLL_DECL npc_kyle_frenziedAI : public ScriptedAI
{
    npc_kyle_frenziedAI(Creature *c) : ScriptedAI(c) {}

    int STATE;
    uint32 wait;
    uint64 player;

    void Reset()
    {
        STATE = 0;
        m_creature->SetDefaultMovementType(WAYPOINT_MOTION_TYPE);
        m_creature->GetMotionMaster()->Initialize();
    }
    void Aggro(Unit* who){}

    void SpellHit(Unit *caster, const SpellEntry* spell)
    {   // we can feed him without any quest
        if(spell->Id == 42222 && caster->GetTypeId() == TYPEID_PLAYER && ((Player*)caster)->GetTeam() == HORDE)
        {
            STATE = 1;
            player = caster->GetGUID();
            float x, y, z, z2;
            caster->GetPosition(x, y, z);
            x = x + 3.7*cos(caster->GetOrientation());
            y = y + 3.7*sin(caster->GetOrientation());
            z2 = m_creature->GetBaseMap()->GetHeight(x,y,z,false);
            z = (z2 <= INVALID_HEIGHT) ? z : z2;
            m_creature->SetDefaultMovementType(IDLE_MOTION_TYPE);       //there is other way to stop waypoint movement?
            m_creature->GetMotionMaster()->Initialize();
            m_creature->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
            m_creature->GetMotionMaster()->MovePoint(0,x, y, z);
        }
    }

    void MovementInform(uint32 type, uint32 id)
    {
        if(type == POINT_MOTION_TYPE)
        {
            switch(STATE)
            {
            case 1:
                {
                Unit *plr = Unit::GetUnit((*m_creature),player);
                if(plr)
                    m_creature->SetOrientation(m_creature->GetAngle(plr));
                m_creature->HandleEmoteCommand(EMOTE_STATE_USESTANDING);    //eat
                WorldPacket data;
                m_creature->BuildHeartBeatMsg(&data);
                m_creature->SendMessageToSet(&data,true);
                wait = 3000;
                STATE = 2;
                break;
                }
            case 4:
                m_creature->setDeathState(JUST_DIED);
                m_creature->Respawn();
                break;
            }
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (!STATE || STATE == 4)
            return;
        if(wait < diff)
        {
            switch(STATE)
            {
            case 2:
                STATE = 3; wait = 7000;
                m_creature->UpdateEntry(23622,HORDE);
                m_creature->HandleEmoteCommand(EMOTE_ONESHOT_DANCE);
                break;
            case 3:
                STATE = 4;  //go home
                Unit *plr = Unit::GetUnit((*m_creature),player);
                    if(plr && ((Player*)plr)->GetQuestStatus(11129) == QUEST_STATUS_INCOMPLETE)
                        ((Player*)plr)->CompleteQuest(11129);
                float x, y, z, z2, angle;
                angle = m_creature->GetAngle(-2146, -430);
                m_creature->GetPosition(x,y,z);
                x = x + 40*cos(angle);
                y = y + 40*sin(angle);
                z2 = m_creature->GetBaseMap()->GetHeight(x,y,MAX_HEIGHT,false);
                z = (z2 <= INVALID_HEIGHT) ? z : z2;
                m_creature->GetMotionMaster()->MovePoint(0,x,y,z);
                break;
            }
        }else wait -= diff;
    }
};

CreatureAI* GetAI_npc_kyle_frenzied(Creature *_Creature)
{
    return new npc_kyle_frenziedAI (_Creature);
}

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

struct TRINITY_DLL_DECL npc_plains_visionAI  : public ScriptedAI
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

    void Aggro(Unit* who){}

    void MovementInform(uint32 type, uint32 id)
    {
        if(type != POINT_MOTION_TYPE)
            return;

        if (id < amountWP)
        {
            ++WayPointId;
            newWaypoint = true;
        }
        else
        {
            m_creature->setDeathState(JUST_DIED);
            m_creature->RemoveCorpse();
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (newWaypoint)
        {
            m_creature->GetMotionMaster()->MovePoint(WayPointId, wp_plain_vision[WayPointId][0], wp_plain_vision[WayPointId][1], wp_plain_vision[WayPointId][2]);
            newWaypoint = false;
        }
    }
};

CreatureAI* GetAI_npc_plains_vision(Creature *_Creature)
{
      return new npc_plains_visionAI (_Creature);
}

/*#####
#
######*/

void AddSC_mulgore()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="npc_skorn_whitecloud";
    newscript->pGossipHello = &GossipHello_npc_skorn_whitecloud;
    newscript->pGossipSelect = &GossipSelect_npc_skorn_whitecloud;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_kyle_frenzied";
    newscript->GetAI = &GetAI_npc_kyle_frenzied;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_plains_vision";
    newscript->GetAI = &GetAI_npc_plains_vision;
    newscript->RegisterSelf();
}

