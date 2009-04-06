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
SDName: Undercity
SD%Complete: 95
SDComment: Quest support: 6628, 9180(post-event).
SDCategory: Undercity
EndScriptData */

/* ContentData
npc_lady_sylvanas_windrunner
npc_highborne_lamenter
npc_parqual_fintallas
EndContentData */

#include "precompiled.h"

/*######
## npc_lady_sylvanas_windrunner
######*/

#define SAY_LAMENT_END              -1000357
#define EMOTE_LAMENT_END            -1000358

#define SOUND_CREDIT                10896
#define ENTRY_HIGHBORNE_LAMENTER    21628
#define ENTRY_HIGHBORNE_BUNNY       21641

#define SPELL_HIGHBORNE_AURA        37090
#define SPELL_SYLVANAS_CAST         36568
#define SPELL_RIBBON_OF_SOULS       34432                   //the real one to use might be 37099

float HighborneLoc[4][3]=
{
    {1285.41, 312.47, 0.51},
    {1286.96, 310.40, 1.00},
    {1289.66, 309.66, 1.52},
    {1292.51, 310.50, 1.99},
};

#define HIGHBORNE_LOC_Y             -61.00
#define HIGHBORNE_LOC_Y_NEW         -55.50

struct TRINITY_DLL_DECL npc_lady_sylvanas_windrunnerAI : public ScriptedAI
{
    npc_lady_sylvanas_windrunnerAI(Creature *c) : ScriptedAI(c) {}

    uint32 LamentEvent_Timer;
    bool LamentEvent;
    uint64 targetGUID;

    float myX;
    float myY;
    float myZ;

    void Reset()
    {
        myX = m_creature->GetPositionX();
        myY = m_creature->GetPositionY();
        myZ = m_creature->GetPositionZ();

        LamentEvent_Timer = 5000;
        LamentEvent = false;
        targetGUID = 0;
    }

    void Aggro(Unit *who) {}

    void JustSummoned(Creature *summoned)
    {
        if( summoned->GetEntry() == ENTRY_HIGHBORNE_BUNNY )
        {
            if( Unit* target = Unit::GetUnit(*summoned,targetGUID) )
            {
                target->SendMonsterMove(target->GetPositionX(), target->GetPositionY(), myZ+15.0,0);
                target->Relocate(target->GetPositionX(), target->GetPositionY(), myZ+15.0);
                summoned->CastSpell(target, SPELL_RIBBON_OF_SOULS, false);
            }

            summoned->AddUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT);
            targetGUID = summoned->GetGUID();
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if( LamentEvent )
        {
            if( LamentEvent_Timer < diff )
            {
                float raX = myX;
                float raY = myY;
                float raZ = myZ;

                m_creature->GetRandomPoint(myX, myY, myZ, 20.0, raX, raY, raZ);
                m_creature->SummonCreature(ENTRY_HIGHBORNE_BUNNY, raX, raY, myZ, 0, TEMPSUMMON_TIMED_DESPAWN, 3000);

                LamentEvent_Timer = 2000;
                if( !m_creature->HasAura(SPELL_SYLVANAS_CAST))
                {
                    DoScriptText(SAY_LAMENT_END, m_creature);
                    DoScriptText(EMOTE_LAMENT_END, m_creature);
                    LamentEvent = false;
                }
            }else LamentEvent_Timer -= diff;
        }

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_npc_lady_sylvanas_windrunner(Creature *_Creature)
{
    return new npc_lady_sylvanas_windrunnerAI (_Creature);
}

bool ChooseReward_npc_lady_sylvanas_windrunner(Player *player, Creature *_Creature, const Quest *_Quest, uint32 slot)
{
    if( _Quest->GetQuestId() == 9180 )
    {
        ((npc_lady_sylvanas_windrunnerAI*)_Creature->AI())->LamentEvent = true;
        ((npc_lady_sylvanas_windrunnerAI*)_Creature->AI())->DoPlaySoundToSet(_Creature,SOUND_CREDIT);
        _Creature->CastSpell(_Creature,SPELL_SYLVANAS_CAST,false);

        for( uint8 i = 0; i < 4; ++i)
            _Creature->SummonCreature(ENTRY_HIGHBORNE_LAMENTER, HighborneLoc[i][0], HighborneLoc[i][1], HIGHBORNE_LOC_Y, HighborneLoc[i][2], TEMPSUMMON_TIMED_DESPAWN, 160000);
    }

    return true;
}

/*######
## npc_highborne_lamenter
######*/

struct TRINITY_DLL_DECL npc_highborne_lamenterAI : public ScriptedAI
{
    npc_highborne_lamenterAI(Creature *c) : ScriptedAI(c) {}

    uint32 EventMove_Timer;
    uint32 EventCast_Timer;
    bool EventMove;
    bool EventCast;

    void Reset()
    {
        EventMove_Timer = 10000;
        EventCast_Timer = 17500;
        EventMove = true;
        EventCast = true;
    }

    void Aggro(Unit *who) {}

    void UpdateAI(const uint32 diff)
    {
        if( EventMove )
        {
            if( EventMove_Timer < diff )
            {
                m_creature->AddUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT | MOVEMENTFLAG_LEVITATING);
                m_creature->SendMonsterMoveWithSpeed(m_creature->GetPositionX(),m_creature->GetPositionY(),HIGHBORNE_LOC_Y_NEW,5000);
                m_creature->GetMap()->CreatureRelocation(m_creature,m_creature->GetPositionX(),m_creature->GetPositionY(),HIGHBORNE_LOC_Y_NEW,m_creature->GetOrientation());
                EventMove = false;
            }else EventMove_Timer -= diff;
        }
        if( EventCast )
        {
            if( EventCast_Timer < diff )
            {
                DoCast(m_creature,SPELL_HIGHBORNE_AURA);
                EventCast = false;
            }else EventCast_Timer -= diff;
        }
    }
};
CreatureAI* GetAI_npc_highborne_lamenter(Creature *_Creature)
{
    return new npc_highborne_lamenterAI (_Creature);
}

/*######
## npc_parqual_fintallas
######*/

#define SPELL_MARK_OF_SHAME 6767

#define GOSSIP_HPF1 "Gul'dan"
#define GOSSIP_HPF2 "Kel'Thuzad"
#define GOSSIP_HPF3 "Ner'zhul"

bool GossipHello_npc_parqual_fintallas(Player *player, Creature *_Creature)
{
    if (_Creature->isQuestGiver())
        player->PrepareQuestMenu( _Creature->GetGUID() );

    if (player->GetQuestStatus(6628) == QUEST_STATUS_INCOMPLETE && !player->HasAura(SPELL_MARK_OF_SHAME) )
    {
        player->ADD_GOSSIP_ITEM( 0, GOSSIP_HPF1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        player->ADD_GOSSIP_ITEM( 0, GOSSIP_HPF2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        player->ADD_GOSSIP_ITEM( 0, GOSSIP_HPF3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
        player->SEND_GOSSIP_MENU(5822, _Creature->GetGUID());
    }
    else
        player->SEND_GOSSIP_MENU(5821, _Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_parqual_fintallas(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    if (action == GOSSIP_ACTION_INFO_DEF+1)
    {
        player->CLOSE_GOSSIP_MENU();
        _Creature->CastSpell(player,SPELL_MARK_OF_SHAME,false);
    }
    if (action == GOSSIP_ACTION_INFO_DEF+2)
    {
        player->CLOSE_GOSSIP_MENU();
        player->AreaExploredOrEventHappens(6628);
    }
    return true;
}

/*######
## AddSC
######*/

void AddSC_undercity()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="npc_lady_sylvanas_windrunner";
    newscript->GetAI = &GetAI_npc_lady_sylvanas_windrunner;
    newscript->pChooseReward = &ChooseReward_npc_lady_sylvanas_windrunner;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_highborne_lamenter";
    newscript->GetAI = &GetAI_npc_highborne_lamenter;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_parqual_fintallas";
    newscript->pGossipHello = &GossipHello_npc_parqual_fintallas;
    newscript->pGossipSelect = &GossipSelect_npc_parqual_fintallas;
    newscript->RegisterSelf();
}

