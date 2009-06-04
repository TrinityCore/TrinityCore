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
SDName: Terokkar_Forest
SD%Complete: 80
SDComment: Quest support: 9889, 10009, 10873, 10896, 11096, 10052, 10051. Skettis->Ogri'la Flight
SDCategory: Terokkar Forest
EndScriptData */

/* ContentData
mob_unkor_the_ruthless
mob_infested_root_walker
mob_rotting_forest_rager
mob_netherweb_victim
npc_floon
npc_isla_starmane
EndContentData */

#include "precompiled.h"
#include "../../npc/npc_escortAI.h"

/*######
## mob_unkor_the_ruthless
######*/

#define SAY_SUBMIT                      -1000351

#define FACTION_HOSTILE                 45
#define FACTION_FRIENDLY                35
#define QUEST_DONTKILLTHEFATONE         9889

#define SPELL_PULVERIZE                 2676
//#define SPELL_QUID9889                32174

struct TRINITY_DLL_DECL mob_unkor_the_ruthlessAI : public ScriptedAI
{
    mob_unkor_the_ruthlessAI(Creature* c) : ScriptedAI(c) {}

    bool CanDoQuest;
    uint32 UnkorUnfriendly_Timer;
    uint32 Pulverize_Timer;

    void Reset()
    {
        CanDoQuest = false;
        UnkorUnfriendly_Timer = 0;
        Pulverize_Timer = 3000;
        m_creature->SetStandState(UNIT_STAND_STATE_STAND);
        m_creature->setFaction(FACTION_HOSTILE);
    }

    void EnterCombat(Unit *who) {}

    void DoNice()
    {
        DoScriptText(SAY_SUBMIT, m_creature);
        m_creature->setFaction(FACTION_FRIENDLY);
        m_creature->SetStandState(UNIT_STAND_STATE_SIT);
        m_creature->RemoveAllAuras();
        m_creature->DeleteThreatList();
        m_creature->CombatStop();
        UnkorUnfriendly_Timer = 60000;
    }

    void DamageTaken(Unit *done_by, uint32 &damage)
    {
        if( done_by->GetTypeId() == TYPEID_PLAYER )
            if( (m_creature->GetHealth()-damage)*100 / m_creature->GetMaxHealth() < 30 )
        {
            if( Group* pGroup = CAST_PLR(done_by)->GetGroup() )
            {
                for(GroupReference *itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
                {
                    Player *pGroupie = itr->getSource();
                    if( pGroupie &&
                        pGroupie->GetQuestStatus(QUEST_DONTKILLTHEFATONE) == QUEST_STATUS_INCOMPLETE &&
                        pGroupie->GetReqKillOrCastCurrentCount(QUEST_DONTKILLTHEFATONE, 18260) == 10 )
                    {
                        pGroupie->AreaExploredOrEventHappens(QUEST_DONTKILLTHEFATONE);
                        if( !CanDoQuest )
                            CanDoQuest = true;
                    }
                }
            } else
            if( CAST_PLR(done_by)->GetQuestStatus(QUEST_DONTKILLTHEFATONE) == QUEST_STATUS_INCOMPLETE &&
                CAST_PLR(done_by)->GetReqKillOrCastCurrentCount(QUEST_DONTKILLTHEFATONE, 18260) == 10 )
            {
                CAST_PLR(done_by)->AreaExploredOrEventHappens(QUEST_DONTKILLTHEFATONE);
                CanDoQuest = true;
            }
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if( CanDoQuest )
        {
            if( !UnkorUnfriendly_Timer )
            {
                //DoCast(m_creature,SPELL_QUID9889);        //not using spell for now
                DoNice();
            }
            else
            {
                if( UnkorUnfriendly_Timer < diff )
                {
                    EnterEvadeMode();
                    return;
                }else UnkorUnfriendly_Timer -= diff;
            }
        }

        if(!UpdateVictim())
            return;

        if( Pulverize_Timer < diff )
        {
            DoCast(m_creature,SPELL_PULVERIZE);
            Pulverize_Timer = 9000;
        }else Pulverize_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_unkor_the_ruthless(Creature *_Creature)
{
    return new mob_unkor_the_ruthlessAI (_Creature);
}

/*######
## mob_infested_root_walker
######*/

struct TRINITY_DLL_DECL mob_infested_root_walkerAI : public ScriptedAI
{
    mob_infested_root_walkerAI(Creature *c) : ScriptedAI(c) {}

    void Reset() { }
    void EnterCombat(Unit *who) { }

    void DamageTaken(Unit *done_by, uint32 &damage)
    {
        if (done_by && done_by->GetTypeId() == TYPEID_PLAYER)
            if (m_creature->GetHealth() <= damage)
                if (rand()%100 < 75)
                    //Summon Wood Mites
                    m_creature->CastSpell(m_creature,39130,true);
    }
};
CreatureAI* GetAI_mob_infested_root_walker(Creature *_Creature)
{
    return new mob_infested_root_walkerAI (_Creature);
}

/*######
## mob_rotting_forest_rager
######*/

struct TRINITY_DLL_DECL mob_rotting_forest_ragerAI : public ScriptedAI
{
    mob_rotting_forest_ragerAI(Creature *c) : ScriptedAI(c) {}

    void Reset() { }
    void EnterCombat(Unit *who) { }

    void DamageTaken(Unit *done_by, uint32 &damage)
    {
        if (done_by->GetTypeId() == TYPEID_PLAYER)
            if (m_creature->GetHealth() <= damage)
                if (rand()%100 < 75)
                    //Summon Lots of Wood Mights
                    m_creature->CastSpell(m_creature,39134,true);
    }
};
CreatureAI* GetAI_mob_rotting_forest_rager(Creature *_Creature)
{
    return new mob_rotting_forest_ragerAI (_Creature);
}

/*######
## mob_netherweb_victim
######*/

#define QUEST_TARGET        22459
//#define SPELL_FREE_WEBBED   38950

const uint32 netherwebVictims[6] =
{
    18470, 16805, 21242, 18452, 22482, 21285
};
struct TRINITY_DLL_DECL mob_netherweb_victimAI : public ScriptedAI
{
    mob_netherweb_victimAI(Creature *c) : ScriptedAI(c) {}

    void Reset() { }
    void EnterCombat(Unit *who) { }
    void MoveInLineOfSight(Unit *who) { }

    void JustDied(Unit* Killer)
    {
        if( Killer->GetTypeId() == TYPEID_PLAYER )
        {
            if( CAST_PLR(Killer)->GetQuestStatus(10873) == QUEST_STATUS_INCOMPLETE )
            {
                if( rand()%100 < 25 )
                {
                    DoSpawnCreature(QUEST_TARGET,0,0,0,0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,60000);
                    CAST_PLR(Killer)->KilledMonster(QUEST_TARGET, m_creature->GetGUID());
                }else
                DoSpawnCreature(netherwebVictims[rand()%6],0,0,0,0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,60000);

                if( rand()%100 < 75 )
                    DoSpawnCreature(netherwebVictims[rand()%6],0,0,0,0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,60000);
                DoSpawnCreature(netherwebVictims[rand()%6],0,0,0,0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,60000);
            }
        }
    }
};
CreatureAI* GetAI_mob_netherweb_victim(Creature *_Creature)
{
    return new mob_netherweb_victimAI (_Creature);
}

/*######
## npc_floon
######*/

#define GOSSIP_FLOON1           "You owe Sim'salabim money. Hand them over or die!"
#define GOSSIP_FLOON2           "Hand over the money or die...again!"

#define SAY_FLOON_ATTACK        -1000352

#define FACTION_HOSTILE_FL      1738
#define FACTION_FRIENDLY_FL     35

#define SPELL_SILENCE           6726
#define SPELL_FROSTBOLT         9672
#define SPELL_FROST_NOVA        11831

struct TRINITY_DLL_DECL npc_floonAI : public ScriptedAI
{
    npc_floonAI(Creature* c) : ScriptedAI(c) {}

    uint32 Silence_Timer;
    uint32 Frostbolt_Timer;
    uint32 FrostNova_Timer;

    void Reset()
    {
        Silence_Timer = 2000;
        Frostbolt_Timer = 4000;
        FrostNova_Timer = 9000;
        m_creature->setFaction(FACTION_FRIENDLY_FL);
    }

    void EnterCombat(Unit *who) {}

    void UpdateAI(const uint32 diff)
    {
        if(!UpdateVictim())
            return;

        if( Silence_Timer < diff )
        {
            DoCast(m_creature->getVictim(),SPELL_SILENCE);
            Silence_Timer = 30000;
        }else Silence_Timer -= diff;

        if( FrostNova_Timer < diff )
        {
            DoCast(m_creature,SPELL_FROST_NOVA);
            FrostNova_Timer = 20000;
        }else FrostNova_Timer -= diff;

        if( Frostbolt_Timer < diff )
        {
            DoCast(m_creature->getVictim(),SPELL_FROSTBOLT);
            Frostbolt_Timer = 5000;
        }else Frostbolt_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_npc_floon(Creature *_Creature)
{
    return new npc_floonAI (_Creature);
}

bool GossipHello_npc_floon(Player *player, Creature *_Creature )
{
    if( player->GetQuestStatus(10009) == QUEST_STATUS_INCOMPLETE )
        player->ADD_GOSSIP_ITEM(1, GOSSIP_FLOON1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

    player->SEND_GOSSIP_MENU(9442, _Creature->GetGUID());
    return true;
}

bool GossipSelect_npc_floon(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    if( action == GOSSIP_ACTION_INFO_DEF )
    {
        player->ADD_GOSSIP_ITEM(1, GOSSIP_FLOON2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        player->SEND_GOSSIP_MENU(9443, _Creature->GetGUID());
    }
    if( action == GOSSIP_ACTION_INFO_DEF+1 )
    {
        player->CLOSE_GOSSIP_MENU();
        _Creature->setFaction(FACTION_HOSTILE_FL);
        DoScriptText(SAY_FLOON_ATTACK, _Creature, player);
        ((npc_floonAI*)_Creature->AI())->AttackStart(player);
    }
    return true;
}

/*######
## npc_isla_starmane
######*/

#define SAY_PROGRESS_1  -1000353
#define SAY_PROGRESS_2  -1000354
#define SAY_PROGRESS_3  -1000355
#define SAY_PROGRESS_4  -1000356

#define QUEST_EFTW_H    10052
#define QUEST_EFTW_A    10051
#define GO_CAGE         182794
#define SPELL_CAT       32447

struct TRINITY_DLL_DECL npc_isla_starmaneAI : public npc_escortAI
{
    npc_isla_starmaneAI(Creature* c) : npc_escortAI(c) {}

    bool Completed;

    void WaypointReached(uint32 i)
    {
        Player* player = Unit::GetPlayer(PlayerGUID);

        if(!player)
            return;

        switch(i)
        {
        case 0:
            {
            GameObject* Cage = me->FindNearestGameObject(GO_CAGE, 10);
            if(Cage)
                Cage->SetGoState(GO_STATE_ACTIVE);
            }break;
        case 2: DoScriptText(SAY_PROGRESS_1, m_creature, player); break;
        case 5: DoScriptText(SAY_PROGRESS_2, m_creature, player); break;
        case 6: DoScriptText(SAY_PROGRESS_3, m_creature, player); break;
        case 29:DoScriptText(SAY_PROGRESS_4, m_creature, player);
            if (player)
            {
                if(CAST_PLR(player)->GetTeam() == ALLIANCE)
                    CAST_PLR(player)->GroupEventHappens(QUEST_EFTW_A, m_creature);
                else if(CAST_PLR(player)->GetTeam() == HORDE)
                    CAST_PLR(player)->GroupEventHappens(QUEST_EFTW_H, m_creature);
            } Completed = true;
            m_creature->SetInFront(player); break;
        case 30: m_creature->HandleEmoteCommand(EMOTE_ONESHOT_WAVE); break;
        case 31: DoCast(m_creature, SPELL_CAT);
            m_creature->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE); break;
        }
    }

    void Reset()
    {
        Completed = false;
        m_creature->setFaction(1660);
    }

    void EnterCombat(Unit* who){}

    void JustDied(Unit* killer)
    {
        if (PlayerGUID)
        {
            Player* player = Unit::GetPlayer(PlayerGUID);
            if (player && !Completed)
            {
                if(CAST_PLR(player)->GetTeam() == ALLIANCE)
                    CAST_PLR(player)->FailQuest(QUEST_EFTW_A);
                else if(CAST_PLR(player)->GetTeam() == HORDE)
                    CAST_PLR(player)->FailQuest(QUEST_EFTW_H);
            }
        }
    }

    void UpdateAI(const uint32 diff)
    {
        npc_escortAI::UpdateAI(diff);
    }
};

bool QuestAccept_npc_isla_starmane(Player* player, Creature* creature, Quest const* quest)
{
    if (quest->GetQuestId() == QUEST_EFTW_H || quest->GetQuestId() == QUEST_EFTW_A)
    {
        ((npc_escortAI*)(creature->AI()))->Start(true, true, false, player->GetGUID());
        creature->setFaction(113);
    }
    return true;
}

CreatureAI* GetAI_npc_isla_starmaneAI(Creature *_Creature)
{
    npc_isla_starmaneAI* thisAI = new npc_isla_starmaneAI(_Creature);

    thisAI->AddWaypoint(0, -2265.21, 3091.14, 13.91);
    thisAI->AddWaypoint(1, -2266.80, 3091.33, 13.82, 1000);
    thisAI->AddWaypoint(2, -2268.20, 3091.14, 13.82, 7000);//progress1
    thisAI->AddWaypoint(3, -2278.32, 3098.98, 13.82);
    thisAI->AddWaypoint(4, -2294.82, 3110.59, 13.82);
    thisAI->AddWaypoint(5, -2300.71, 3114.60, 13.82, 20000);//progress2
    thisAI->AddWaypoint(6, -2300.71, 3114.60, 13.82, 3000);//progress3
    thisAI->AddWaypoint(7, -2307.36, 3122.76, 13.79);
    thisAI->AddWaypoint(8, -2312.83, 3130.55, 12.04);
    thisAI->AddWaypoint(9, -2345.02, 3151.00, 8.38);
    thisAI->AddWaypoint(10, -2351.97, 3157.61, 6.27);
    thisAI->AddWaypoint(11, -2360.35, 3171.48, 3.31);
    thisAI->AddWaypoint(12, -2371.44, 3185.41, 0.89);
    thisAI->AddWaypoint(13, -2371.21, 3197.92, -0.96);
    thisAI->AddWaypoint(14, -2380.35, 3210.45, -1.08);
    thisAI->AddWaypoint(15, -2384.74, 3221.25, -1.17);
    thisAI->AddWaypoint(16, -2386.15, 3233.39, -1.29);
    thisAI->AddWaypoint(17, -2383.45, 3247.79, -1.32);
    thisAI->AddWaypoint(18, -2367.50, 3265.64, -1.33);
    thisAI->AddWaypoint(19, -2354.90, 3273.30, -1.50);
    thisAI->AddWaypoint(20, -2348.88, 3280.58, -0.09);
    thisAI->AddWaypoint(21, -2349.06, 3295.86, -0.95);
    thisAI->AddWaypoint(22, -2350.43, 3328.27, -2.10);
    thisAI->AddWaypoint(23, -2346.76, 3356.27, -2.82);
    thisAI->AddWaypoint(24, -2340.56, 3370.68, -4.02);
    thisAI->AddWaypoint(25, -2318.84, 3384.60, -7.61);
    thisAI->AddWaypoint(26, -2313.99, 3398.61, -10.40);
    thisAI->AddWaypoint(27, -2320.85, 3414.49, -11.49);
    thisAI->AddWaypoint(28, -2338.26, 3426.06, -11.46);
    thisAI->AddWaypoint(29, -2342.67, 3439.44, -11.32, 12000);//progress4
    thisAI->AddWaypoint(30, -2342.67, 3439.44, -11.32, 7000);//emote bye
    thisAI->AddWaypoint(31, -2342.67, 3439.44, -11.32, 5000);//cat form
    thisAI->AddWaypoint(32, -2344.60, 3461.27, -10.44);
    thisAI->AddWaypoint(33, -2396.81, 3517.17, -3.55);
    thisAI->AddWaypoint(34, -2439.23, 3523.00, -1.05);

    return (CreatureAI*)thisAI;
}

/*######
## go_skull_pile
######*/
#define GOSSIP_S_DARKSCREECHER_AKKARAI         "Summon Darkscreecher Akkarai"
#define GOSSIP_S_KARROG         "Summon Karrog"
#define GOSSIP_S_GEZZARAK_THE_HUNTRESS         "Summon Gezzarak the Huntress"
#define GOSSIP_S_VAKKIZ_THE_WINDRAGER         "Summon Vakkiz the Windrager"

bool GossipHello_go_skull_pile(Player *player, GameObject* _GO)
{
    if ((player->GetQuestStatus(11885) == QUEST_STATUS_INCOMPLETE) || player->GetQuestRewardStatus(11885))
    {
        player->ADD_GOSSIP_ITEM(0, GOSSIP_S_DARKSCREECHER_AKKARAI, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        player->ADD_GOSSIP_ITEM(0, GOSSIP_S_KARROG, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
        player->ADD_GOSSIP_ITEM(0, GOSSIP_S_GEZZARAK_THE_HUNTRESS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
        player->ADD_GOSSIP_ITEM(0, GOSSIP_S_VAKKIZ_THE_WINDRAGER, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
    }

    player->SEND_GOSSIP_MENU(_GO->GetGOInfo()->questgiver.gossipID, _GO->GetGUID());
    return true;
}

void SendActionMenu_go_skull_pile(Player *player, GameObject* _GO, uint32 action)
{
    switch(action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:
              player->CastSpell(player,40642,false);
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:
              player->CastSpell(player,40640,false);
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:
              player->CastSpell(player,40632,false);
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:
              player->CastSpell(player,40644,false);
            break;
    }
}

bool GossipSelect_go_skull_pile(Player *player, GameObject* _GO, uint32 sender, uint32 action )
{
    switch(sender)
    {
        case GOSSIP_SENDER_MAIN:    SendActionMenu_go_skull_pile(player, _GO, action); break;
    }
    return true;
}

void AddSC_terokkar_forest()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="mob_unkor_the_ruthless";
    newscript->GetAI = &GetAI_mob_unkor_the_ruthless;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_infested_root_walker";
    newscript->GetAI = &GetAI_mob_infested_root_walker;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_rotting_forest_rager";
    newscript->GetAI = &GetAI_mob_rotting_forest_rager;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_netherweb_victim";
    newscript->GetAI = &GetAI_mob_netherweb_victim;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_floon";
    newscript->pGossipHello =  &GossipHello_npc_floon;
    newscript->pGossipSelect = &GossipSelect_npc_floon;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name= "npc_isla_starmane";
    newscript->GetAI = &GetAI_npc_isla_starmaneAI;
    newscript->pQuestAccept = &QuestAccept_npc_isla_starmane;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="go_skull_pile";
    newscript->pGOHello  = &GossipHello_go_skull_pile;
    newscript->pGOSelect = &GossipSelect_go_skull_pile;
    newscript->RegisterSelf();

}

