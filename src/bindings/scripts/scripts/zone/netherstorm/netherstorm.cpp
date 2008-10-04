/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Netherstorm
SD%Complete: 75
SDComment: Quest support: 10438, 10652 (special flight paths), 10299,10321,10322,10323,10329,10330,10338,10365(Shutting Down Manaforge)
SDCategory: Netherstorm
EndScriptData */

/* ContentData
npc_manaforge_control_console
go_manaforge_control_console
npc_protectorate_nether_drake
npc_veronia
EndContentData */

#include "precompiled.h"

/*######
## npc_manaforge_control_console
######*/

#define EMOTE_START     "Warning! Emergency shutdown process initiated by $N. Shutdown will complete in two minutes."
#define EMOTE_60        "Emergency shutdown will complete in one minute."
#define EMOTE_30        "Emergency shutdown will complete in thirty seconds."
#define EMOTE_10        "Emergency shutdown will complete in ten seconds."
#define EMOTE_COMPLETE  "Emergency shutdown complete."
#define EMOTE_ABORT     "Emergency shutdown aborted."

#define ENTRY_BNAAR_C_CONSOLE   20209
#define ENTRY_CORUU_C_CONSOLE   20417
#define ENTRY_DURO_C_CONSOLE    20418
#define ENTRY_ARA_C_CONSOLE     20440

#define ENTRY_SUNFURY_TECH      20218
#define ENTRY_SUNFURY_PROT      20436

#define ENTRY_ARA_TECH          20438
#define ENTRY_ARA_ENGI          20439
#define ENTRY_ARA_GORKLONN      20460

#define SPELL_DISABLE_VISUAL    35031
#define SPELL_INTERRUPT_1       35016                       //ACID mobs should cast this
#define SPELL_INTERRUPT_2       35176                       //ACID mobs should cast this (Manaforge Ara-version)

struct MANGOS_DLL_DECL npc_manaforge_control_consoleAI : public ScriptedAI
{
    npc_manaforge_control_consoleAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 Event_Timer;
    uint32 Wave_Timer;
    uint32 Phase;
    bool Wave;
    uint64 someplayer;
    uint64 goConsole;
    Creature* add;

    void Reset()
    {
        Event_Timer = 3000;
        Wave_Timer = 0;
        Phase = 1;
        Wave = false;
        someplayer = 0;
        goConsole = 0;
        Creature* add = NULL;
    }

    void Aggro(Unit *who) { return; }

    /*void SpellHit(Unit *caster, const SpellEntry *spell)
    {
        //we have no way of telling the creature was hit by spell -> got aura applied after 10-12 seconds
        //then no way for the mobs to actually stop the shutdown as intended.
        if( spell->Id == SPELL_INTERRUPT_1 )
            DoSay("Silence! I kill you!",LANG_UNIVERSAL, NULL);
    }*/

    void JustDied(Unit* killer)
    {
        DoTextEmote(EMOTE_ABORT, NULL);

        if( someplayer )
        {
            Unit* p = Unit::GetUnit((*m_creature),someplayer);
            if( p && p->GetTypeId() == TYPEID_PLAYER )
            {
                switch( m_creature->GetEntry() )
                {
                    case ENTRY_BNAAR_C_CONSOLE:
                        ((Player*)p)->FailQuest(10299);
                        ((Player*)p)->FailQuest(10329);
                        break;
                    case ENTRY_CORUU_C_CONSOLE:
                        ((Player*)p)->FailQuest(10321);
                        ((Player*)p)->FailQuest(10330);
                        break;
                    case ENTRY_DURO_C_CONSOLE:
                        ((Player*)p)->FailQuest(10322);
                        ((Player*)p)->FailQuest(10338);
                        break;
                    case ENTRY_ARA_C_CONSOLE:
                        ((Player*)p)->FailQuest(10323);
                        ((Player*)p)->FailQuest(10365);
                        break;
                }
            }
        }

        if( goConsole )
        {
            if( GameObject* go = GameObject::GetGameObject((*m_creature),goConsole) )
                go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
        }
    }

    void DoWaveSpawnForCreature(Creature *creature)
    {
        switch( creature->GetEntry() )
        {
            case ENTRY_BNAAR_C_CONSOLE:
                if( rand()%2 )
                {
                    add = m_creature->SummonCreature(ENTRY_SUNFURY_TECH,2933.68,4162.55,164.00,1.60,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                    if( add ) add->GetMotionMaster()->MovePoint(0,2927.36,4212.97,164.00);
                }
                else
                {
                    add = m_creature->SummonCreature(ENTRY_SUNFURY_TECH,2927.36,4212.97,164.00,4.94,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                    if( add ) add->GetMotionMaster()->MovePoint(0,2933.68,4162.55,164.00);
                }
                Wave_Timer = 30000;
                break;
            case ENTRY_CORUU_C_CONSOLE:
                add = m_creature->SummonCreature(ENTRY_SUNFURY_TECH,2445.21,2765.26,134.49,3.93,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                if( add ) add->GetMotionMaster()->MovePoint(0,2424.21,2740.15,133.81);
                add = m_creature->SummonCreature(ENTRY_SUNFURY_TECH,2429.86,2731.85,134.53,1.31,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                if( add ) add->GetMotionMaster()->MovePoint(0,2435.37,2766.04,133.81);
                Wave_Timer = 20000;
                break;
            case ENTRY_DURO_C_CONSOLE:
                add = m_creature->SummonCreature(ENTRY_SUNFURY_TECH,2986.80,2205.36,165.37,3.74,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                if( add ) add->GetMotionMaster()->MovePoint(0,2985.15,2197.32,164.79);
                add = m_creature->SummonCreature(ENTRY_SUNFURY_TECH,2952.91,2191.20,165.32,0.22,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                if( add ) add->GetMotionMaster()->MovePoint(0,2060.01,2185.27,164.67);
                Wave_Timer = 15000;
                break;
            case ENTRY_ARA_C_CONSOLE:
                if( rand()%2 )
                {
                    add = m_creature->SummonCreature(ENTRY_ARA_TECH,4035.11,4038.97,194.27,2.57,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                    if( add ) add->GetMotionMaster()->MovePoint(0,4003.42,4040.19,193.49);
                    add = m_creature->SummonCreature(ENTRY_ARA_TECH,4033.66,4036.79,194.28,2.57,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                    if( add ) add->GetMotionMaster()->MovePoint(0,4003.42,4040.19,193.49);
                    add = m_creature->SummonCreature(ENTRY_ARA_TECH,4037.13,4037.30,194.23,2.57,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                    if( add ) add->GetMotionMaster()->MovePoint(0,4003.42,4040.19,193.49);
                }
                else
                {
                    add = m_creature->SummonCreature(ENTRY_ARA_TECH,3099.59,4049.30,194.22,0.05,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                    if( add ) add->GetMotionMaster()->MovePoint(0,4028.01,4035.17,193.59);
                    add = m_creature->SummonCreature(ENTRY_ARA_TECH,3999.72,4046.75,194.22,0.05,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                    if( add ) add->GetMotionMaster()->MovePoint(0,4028.01,4035.17,193.59);
                    add = m_creature->SummonCreature(ENTRY_ARA_TECH,3996.81,4048.26,194.22,0.05,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                    if( add ) add->GetMotionMaster()->MovePoint(0,4028.01,4035.17,193.59);
                }
                Wave_Timer = 15000;
                break;
        }
    }
    void DoFinalSpawnForCreature(Creature *creature)
    {
        switch( creature->GetEntry() )
        {
            case ENTRY_BNAAR_C_CONSOLE:
                add = m_creature->SummonCreature(ENTRY_SUNFURY_TECH,2946.52,4201.42,163.47,3.54,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                if( add ) add->GetMotionMaster()->MovePoint(0,2927.49,4192.81,163.00);
                break;
            case ENTRY_CORUU_C_CONSOLE:
                add = m_creature->SummonCreature(ENTRY_SUNFURY_TECH,2453.88,2737.85,133.27,2.59,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                if( add ) add->GetMotionMaster()->MovePoint(0,2433.96,2751.53,133.85);
                add = m_creature->SummonCreature(ENTRY_SUNFURY_TECH,2441.62,2735.32,134.49,1.97,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                if( add ) add->GetMotionMaster()->MovePoint(0,2433.96,2751.53,133.85);
                add = m_creature->SummonCreature(ENTRY_SUNFURY_TECH,2450.73,2754.50,134.49,3.29,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                if( add ) add->GetMotionMaster()->MovePoint(0,2433.96,2751.53,133.85);
                break;
            case ENTRY_DURO_C_CONSOLE:
                add = m_creature->SummonCreature(ENTRY_SUNFURY_TECH,2956.18,2202.85,165.32,5.45,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                if( add ) add->GetMotionMaster()->MovePoint(0,2972.27,2193.22,164.48);
                add = m_creature->SummonCreature(ENTRY_SUNFURY_TECH,2975.30,2211.50,165.32,4.55,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                if( add ) add->GetMotionMaster()->MovePoint(0,2972.27,2193.22,164.48);
                add = m_creature->SummonCreature(ENTRY_SUNFURY_PROT,2965.02,2217.45,164.16,4.96,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                if( add ) add->GetMotionMaster()->MovePoint(0,2972.27,2193.22,164.48);
                break;
            case ENTRY_ARA_C_CONSOLE:
                add = m_creature->SummonCreature(ENTRY_ARA_ENGI,3994.51,4020.46,192.18,0.91,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                if( add ) add->GetMotionMaster()->MovePoint(0,4008.35,4035.04,192.70);
                add = m_creature->SummonCreature(ENTRY_ARA_GORKLONN,4021.56,4059.35,193.59,4.44,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000);
                if( add ) add->GetMotionMaster()->MovePoint(0,4016.62,4039.89,193.46);
                break;
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if( Event_Timer < diff )
        {
            switch(Phase)
            {
                case 1:
                    if( someplayer )
                    {
                        Unit* u = Unit::GetUnit((*m_creature),someplayer);
                        if( u && u->GetTypeId() == TYPEID_PLAYER ) DoTextEmote(EMOTE_START, u);
                    }
                    Event_Timer = 60000;
                    Wave = true;
                    ++Phase;
                    break;
                case 2:
                    DoTextEmote(EMOTE_60, NULL);
                    Event_Timer = 30000;
                    ++Phase;
                    break;
                case 3:
                    DoTextEmote(EMOTE_30, NULL);
                    Event_Timer = 20000;
                    DoFinalSpawnForCreature(m_creature);
                    ++Phase;
                    break;
                case 4:
                    DoTextEmote(EMOTE_10, NULL);
                    Event_Timer = 10000;
                    Wave = false;
                    ++Phase;
                    break;
                case 5:
                    DoTextEmote(EMOTE_COMPLETE, NULL);
                    if( someplayer )
                    {
                        Unit* u = Unit::GetUnit((*m_creature),someplayer);
                        if( u && u->GetTypeId() == TYPEID_PLAYER )
                            ((Player*)u)->KilledMonster(m_creature->GetEntry(),m_creature->GetGUID());
                        DoCast(m_creature,SPELL_DISABLE_VISUAL);
                    }
                    if( goConsole )
                    {
                        if( GameObject* go = GameObject::GetGameObject((*m_creature),goConsole) )
                            go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
                    }
                    ++Phase;
                    break;
                default:
                    break;
            }
        } else Event_Timer -= diff;

        if( Wave )
        {
            if( Wave_Timer < diff )
            {
                DoWaveSpawnForCreature(m_creature);
            } else Wave_Timer -= diff;
        }
    }
};
CreatureAI* GetAI_npc_manaforge_control_console(Creature *_Creature)
{
    return new npc_manaforge_control_consoleAI (_Creature);
}

/*######
## go_manaforge_control_console
######*/

//TODO: clean up this workaround when mangos adds support to do it properly (with gossip selections instead of instant summon)
bool GOHello_go_manaforge_control_console(Player *player, GameObject* _GO)
{
    if (_GO->GetGoType() == GAMEOBJECT_TYPE_QUESTGIVER)
    {
        player->PrepareQuestMenu(_GO->GetGUID());
        player->SendPreparedQuest(_GO->GetGUID());
    }

    Creature* manaforge;
    manaforge = NULL;

    switch( _GO->GetAreaId() )
    {
        case 3726:                                          //b'naar
            if( (player->GetQuestStatus(10299) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(10329) == QUEST_STATUS_INCOMPLETE) &&
                player->HasItemCount(29366,1))
                manaforge = player->SummonCreature(ENTRY_BNAAR_C_CONSOLE,2918.95,4189.98,161.88,0.34,TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN,125000);
            break;
        case 3730:                                          //coruu
            if( (player->GetQuestStatus(10321) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(10330) == QUEST_STATUS_INCOMPLETE) &&
                player->HasItemCount(29396,1))
                manaforge = player->SummonCreature(ENTRY_CORUU_C_CONSOLE,2426.77,2750.38,133.24,2.14,TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN,125000);
            break;
        case 3734:                                          //duro
            if( (player->GetQuestStatus(10322) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(10338) == QUEST_STATUS_INCOMPLETE) &&
                player->HasItemCount(29397,1))
                manaforge = player->SummonCreature(ENTRY_DURO_C_CONSOLE,2976.48,2183.29,163.20,1.85,TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN,125000);
            break;
        case 3722:                                          //ara
            if( (player->GetQuestStatus(10323) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(10365) == QUEST_STATUS_INCOMPLETE) &&
                player->HasItemCount(29411,1))
                manaforge = player->SummonCreature(ENTRY_ARA_C_CONSOLE,4013.71,4028.76,192.10,1.25,TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN,125000);
            break;
    }

    if( manaforge )
    {
        ((npc_manaforge_control_consoleAI*)manaforge->AI())->someplayer = player->GetGUID();
        ((npc_manaforge_control_consoleAI*)manaforge->AI())->goConsole = _GO->GetGUID();
        _GO->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
    }
    return true;
}

/*######
## npc_protectorate_nether_drake
######*/

bool GossipHello_npc_protectorate_nether_drake(Player *player, Creature *_Creature)
{
    //On Nethery Wings
    if (player->GetQuestStatus(10438) == QUEST_STATUS_INCOMPLETE && player->HasItemCount(29778,1) )
        player->ADD_GOSSIP_ITEM(0, "Fly me to Ultris", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(), _Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_protectorate_nether_drake(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    if (action == GOSSIP_ACTION_INFO_DEF+1)
    {
        player->CLOSE_GOSSIP_MENU();

        std::vector<uint32> nodes;

        nodes.resize(2);
        nodes[0] = 152;                                     //from drake
        nodes[1] = 153;                                     //end at drake
        player->ActivateTaxiPathTo(nodes);                  //TaxiPath 627 (possibly 627+628(152->153->154->155) )
    }
    return true;
}

/*######
## npc_veronia
######*/

bool GossipHello_npc_veronia(Player *player, Creature *_Creature)
{
    if (_Creature->isQuestGiver())
        player->PrepareQuestMenu( _Creature->GetGUID() );

    //Behind Enemy Lines
    if (player->GetQuestStatus(10652) && !player->GetQuestRewardStatus(10652))
        player->ADD_GOSSIP_ITEM(0, "Fly me to Manaforge Coruu please", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

    player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(), _Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_veronia(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    if (action == GOSSIP_ACTION_INFO_DEF)
    {
        player->CLOSE_GOSSIP_MENU();
        player->CastSpell(player,34905,true);               //TaxiPath 606
    }
    return true;
}

/*######
##
######*/

void AddSC_netherstorm()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="go_manaforge_control_console";
    newscript->pGOHello = &GOHello_go_manaforge_control_console;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="npc_manaforge_control_console";
    newscript->GetAI = GetAI_npc_manaforge_control_console;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="npc_protectorate_nether_drake";
    newscript->pGossipHello =   &GossipHello_npc_protectorate_nether_drake;
    newscript->pGossipSelect =  &GossipSelect_npc_protectorate_nether_drake;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="npc_veronia";
    newscript->pGossipHello =   &GossipHello_npc_veronia;
    newscript->pGossipSelect =  &GossipSelect_npc_veronia;
    m_scripts[nrscripts++] = newscript;
}
