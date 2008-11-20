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
SDName: Terokkar_Forest
SD%Complete: 80
SDComment: Quest support: 9889(test script only, sql inside script), 10009, 10873, 10896, 11096. Skettis->Ogri'la Flight
SDCategory: Terokkar Forest
EndScriptData */

/* ContentData
mob_unkor_the_ruthless
mob_infested_root_walker
mob_rotting_forest_rager
mob_netherweb_victim
npc_floon
npc_skyguard_handler_deesak
EndContentData */

#include "precompiled.h"

/*######
## mob_unkor_the_ruthless
######*/

/*
UPDATE `creature_template` SET `ScriptName`='mob_unkor_the_ruthless' WHERE `entry`=18262;
*/

#define SAY_SUBMIT                      "I give up! Please don't kill me!"

#define FACTION_HOSTILE                 45
#define FACTION_FRIENDLY                35
#define QUEST_DONTKILLTHEFATONE         9889

#define SPELL_PULVERIZE                 2676
//#define SPELL_QUID9889                32174

struct TRINITY_DLL_DECL mob_unkor_the_ruthlessAI : public ScriptedAI
{
    mob_unkor_the_ruthlessAI(Creature* c) : ScriptedAI(c) { Reset(); }

    bool CanDoQuest;
    uint32 UnkorUnfriendly_Timer;
    uint32 Pulverize_Timer;

    void Reset()
    {
        CanDoQuest = false;
        UnkorUnfriendly_Timer = 0;
        Pulverize_Timer = 3000;
        m_creature->SetUInt32Value(UNIT_FIELD_BYTES_1, PLAYER_STATE_NONE);
        m_creature->setFaction(FACTION_HOSTILE);
    }

    void Aggro(Unit *who) {}

    void DoNice()
    {
        DoSay(SAY_SUBMIT,LANG_UNIVERSAL,NULL);
        m_creature->setFaction(FACTION_FRIENDLY);
        m_creature->SetUInt32Value(UNIT_FIELD_BYTES_1, PLAYER_STATE_SIT);
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
            if( Group* pGroup = ((Player*)done_by)->GetGroup() )
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
            if( ((Player*)done_by)->GetQuestStatus(QUEST_DONTKILLTHEFATONE) == QUEST_STATUS_INCOMPLETE &&
                ((Player*)done_by)->GetReqKillOrCastCurrentCount(QUEST_DONTKILLTHEFATONE, 18260) == 10 )
            {
                ((Player*)done_by)->AreaExploredOrEventHappens(QUEST_DONTKILLTHEFATONE);
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
                }else UnkorUnfriendly_Timer -= diff;
            }
        }

        if(!m_creature->SelectHostilTarget() || !m_creature->getVictim())
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
    mob_infested_root_walkerAI(Creature *c) : ScriptedAI(c) {Reset();}

    void Reset() { }
    void Aggro(Unit *who) { }

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
    mob_rotting_forest_ragerAI(Creature *c) : ScriptedAI(c) {Reset();}

    void Reset() { }
    void Aggro(Unit *who) { }

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
    mob_netherweb_victimAI(Creature *c) : ScriptedAI(c) {Reset();}

    void Reset() { }
    void Aggro(Unit *who) { }
    void MoveInLineOfSight(Unit *who) { }

    void JustDied(Unit* Killer)
    {
        if( Killer->GetTypeId() == TYPEID_PLAYER )
        {
            if( ((Player*)Killer)->GetQuestStatus(10873) == QUEST_STATUS_INCOMPLETE )
            {
                if( rand()%100 < 25 )
                {
                    DoSpawnCreature(QUEST_TARGET,0,0,0,0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,60000);
                    ((Player*)Killer)->KilledMonster(QUEST_TARGET, m_creature->GetGUID());
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
#define SAY_FLOON_ATTACK        "I choose the third option: KILLING YOU!"

#define FACTION_HOSTILE_FL      1738
#define FACTION_FRIENDLY_FL     35

#define SPELL_SILENCE           6726
#define SPELL_FROSTBOLT         9672
#define SPELL_FROST_NOVA        11831

struct TRINITY_DLL_DECL npc_floonAI : public ScriptedAI
{
    npc_floonAI(Creature* c) : ScriptedAI(c) { Reset(); }

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

    void Aggro(Unit *who) {}

    void UpdateAI(const uint32 diff)
    {
        if(!m_creature->SelectHostilTarget() || !m_creature->getVictim())
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
        ((npc_floonAI*)_Creature->AI())->DoSay(SAY_FLOON_ATTACK,LANG_UNIVERSAL,player);
        ((npc_floonAI*)_Creature->AI())->AttackStart(player);
    }
    return true;
}

/*######
## npc_skyguard_handler_deesak
######*/

#define GOSSIP_SKYGUARD "Fly me to Ogri'la please"

bool GossipHello_npc_skyguard_handler_deesak(Player *player, Creature *_Creature )
{
    if (_Creature->isQuestGiver())
        player->PrepareQuestMenu( _Creature->GetGUID() );

    if (player->GetReputationRank(1031) >= REP_HONORED)
        player->ADD_GOSSIP_ITEM( 2, GOSSIP_SKYGUARD, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(), _Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_skyguard_handler_deesak(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    if (action == GOSSIP_ACTION_INFO_DEF+1)
    {
        player->CLOSE_GOSSIP_MENU();
        player->CastSpell(player,41279,true);               //TaxiPath 705 (Taxi - Skettis to Skyguard Outpost)
    }
    return true;
}

/*######
## AddSC
######*/

void AddSC_terokkar_forest()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="mob_unkor_the_ruthless";
    newscript->GetAI = GetAI_mob_unkor_the_ruthless;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_infested_root_walker";
    newscript->GetAI = GetAI_mob_infested_root_walker;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_rotting_forest_rager";
    newscript->GetAI = GetAI_mob_rotting_forest_rager;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_netherweb_victim";
    newscript->GetAI = GetAI_mob_netherweb_victim;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_floon";
    newscript->pGossipHello =  &GossipHello_npc_floon;
    newscript->pGossipSelect = &GossipSelect_npc_floon;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_skyguard_handler_deesak";
    newscript->pGossipHello =  &GossipHello_npc_skyguard_handler_deesak;
    newscript->pGossipSelect = &GossipSelect_npc_skyguard_handler_deesak;
    newscript->RegisterSelf();
}
