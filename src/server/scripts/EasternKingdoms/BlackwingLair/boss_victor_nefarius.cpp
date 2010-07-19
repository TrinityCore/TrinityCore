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
SDName: Boss_Victor_Nefarius
SD%Complete: 75
SDComment: Missing some text, Vael beginning event, and spawns Nef in wrong place
SDCategory: Blackwing Lair
EndScriptData */

#include "ScriptPCH.h"

#define SAY_GAMESBEGIN_1        -1469004
#define SAY_GAMESBEGIN_2        -1469005
#define SAY_VAEL_INTRO          -1469006                    //when he corrupts Vaelastrasz

#define GOSSIP_ITEM_1           "I've made no mistakes."
#define GOSSIP_ITEM_2           "You have lost your mind, Nefarius. You speak in riddles."
#define GOSSIP_ITEM_3           "Please do."

#define CREATURE_BRONZE_DRAKANOID       14263
#define CREATURE_BLUE_DRAKANOID         14261
#define CREATURE_RED_DRAKANOID          14264
#define CREATURE_GREEN_DRAKANOID        14262
#define CREATURE_BLACK_DRAKANOID        14265

#define CREATURE_CHROMATIC_DRAKANOID    14302
#define CREATURE_NEFARIAN               11583

#define ADD_X1 -7591.151855
#define ADD_X2 -7514.598633
#define ADD_Y1 -1204.051880
#define ADD_Y2 -1150.448853
#define ADD_Z1 476.800476
#define ADD_Z2 476.796570

#define NEF_X   -7445
#define NEF_Y   -1332
#define NEF_Z   536

#define HIDE_X  -7592
#define HIDE_Y  -1264
#define HIDE_Z  481

#define SPELL_SHADOWBOLT        21077
#define SPELL_FEAR              26070

//This script is complicated
//Instead of morphing Victor Nefarius we will have him control phase 1
//And then have him spawn "Nefarian" for phase 2
//When phase 2 starts Victor Nefarius will go into hiding and stop attacking
//If Nefarian despawns because he killed the players then this guy will EnterEvadeMode
//and allow players to start the event over
//If nefarian dies then he will kill himself then he will kill himself in his hiding place
//To prevent players from doing the event twice

struct boss_victor_nefariusAI : public ScriptedAI
{
    boss_victor_nefariusAI(Creature *c) : ScriptedAI(c)
    {
        NefarianGUID = 0;
        switch (urand(0,19))
        {
            case 0:
                DrakType1 = CREATURE_BRONZE_DRAKANOID;
                DrakType2 = CREATURE_BLUE_DRAKANOID;
                break;
            case 1:
                DrakType1 = CREATURE_BRONZE_DRAKANOID;
                DrakType2 = CREATURE_RED_DRAKANOID;
                break;
            case 2:
                DrakType1 = CREATURE_BRONZE_DRAKANOID;
                DrakType2 = CREATURE_GREEN_DRAKANOID;
                break;
            case 3:
                DrakType1 = CREATURE_BRONZE_DRAKANOID;
                DrakType2 = CREATURE_BLACK_DRAKANOID;
                break;
            case 4:
                DrakType1 = CREATURE_BLUE_DRAKANOID;
                DrakType2 = CREATURE_BRONZE_DRAKANOID;
                break;
            case 5:
                DrakType1 = CREATURE_BLUE_DRAKANOID;
                DrakType2 = CREATURE_RED_DRAKANOID;
                break;
            case 6:
                DrakType1 = CREATURE_BLUE_DRAKANOID;
                DrakType2 = CREATURE_GREEN_DRAKANOID;
                break;
            case 7:
                DrakType1 = CREATURE_BLUE_DRAKANOID;
                DrakType2 = CREATURE_BLACK_DRAKANOID;
                break;
            case 8:
                DrakType1 = CREATURE_RED_DRAKANOID;
                DrakType2 = CREATURE_BRONZE_DRAKANOID;
                break;
            case 9:
                DrakType1 = CREATURE_RED_DRAKANOID;
                DrakType2 = CREATURE_BLUE_DRAKANOID;
                break;
            case 10:
                DrakType1 = CREATURE_RED_DRAKANOID;
                DrakType2 = CREATURE_GREEN_DRAKANOID;
                break;
            case 11:
                DrakType1 = CREATURE_RED_DRAKANOID;
                DrakType2 = CREATURE_BLACK_DRAKANOID;
                break;
            case 12:
                DrakType1 = CREATURE_GREEN_DRAKANOID;
                DrakType2 = CREATURE_BRONZE_DRAKANOID;
                break;
            case 13:
                DrakType1 = CREATURE_GREEN_DRAKANOID;
                DrakType2 = CREATURE_BLUE_DRAKANOID;
                break;
            case 14:
                DrakType1 = CREATURE_GREEN_DRAKANOID;
                DrakType2 = CREATURE_RED_DRAKANOID;
                break;
            case 15:
                DrakType1 = CREATURE_GREEN_DRAKANOID;
                DrakType2 = CREATURE_BLACK_DRAKANOID;
                break;
            case 16:
                DrakType1 = CREATURE_BLACK_DRAKANOID;
                DrakType2 = CREATURE_BRONZE_DRAKANOID;
                break;
            case 17:
                DrakType1 = CREATURE_BLACK_DRAKANOID;
                DrakType2 = CREATURE_BLUE_DRAKANOID;
                break;
            case 18:
                DrakType1 = CREATURE_BLACK_DRAKANOID;
                DrakType2 = CREATURE_GREEN_DRAKANOID;
                break;
            case 19:
                DrakType1 = CREATURE_BLACK_DRAKANOID;
                DrakType2 = CREATURE_RED_DRAKANOID;
                break;
        }
    }

    uint32 SpawnedAdds;
    uint32 AddSpawnTimer;
    uint32 ShadowBoltTimer;
    uint32 FearTimer;
    uint32 MindControlTimer;
    uint32 ResetTimer;
    uint32 DrakType1;
    uint32 DrakType2;
    uint64 NefarianGUID;
    uint32 NefCheckTime;

    void Reset()
    {
        SpawnedAdds = 0;
        AddSpawnTimer = 10000;
        ShadowBoltTimer = 5000;
        FearTimer = 8000;
        ResetTimer = 900000;                                //On official it takes him 15 minutes(900 seconds) to reset. We are only doing 1 minute to make testing easier
        NefarianGUID = 0;
        NefCheckTime = 2000;

        me->SetUInt32Value(UNIT_NPC_FLAGS,1);
        me->setFaction(35);
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
    }

    void BeginEvent(Player *pTarget)
    {
        DoScriptText(SAY_GAMESBEGIN_2, me);

        //Trinity::Singleton<MapManager>::Instance().GetMap(me->GetMapId(), me)->GetPlayers().begin();
        /*
        list <Player*>::const_iterator i = sMapMgr.GetMap(me->GetMapId(), me)->GetPlayers().begin();

        for (i = sMapMgr.GetMap(me->GetMapId(), me)->GetPlayers().begin(); i != sMapMgr.GetMap(me->GetMapId(), me)->GetPlayers().end(); ++i)
        {
        AttackStart((*i));
        }
        */
        me->SetUInt32Value(UNIT_NPC_FLAGS,0);
        me->setFaction(103);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        AttackStart(pTarget);
    }

    void EnterCombat(Unit * /*who*/)
    {
    }

    void MoveInLineOfSight(Unit *who)
    {
        //We simply use this function to find players until we can use pMap->GetPlayers()

        if (who && who->GetTypeId() == TYPEID_PLAYER && me->IsHostileTo(who))
        {
            //Add them to our threat list
            me->AddThreat(who, 0.0f);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //Only do this if we haven't spawned nef yet
        if (SpawnedAdds < 42)
        {
            //ShadowBoltTimer
            if (ShadowBoltTimer <= diff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(pTarget, SPELL_SHADOWBOLT);

                ShadowBoltTimer = urand(3000,10000);
            } else ShadowBoltTimer -= diff;

            //FearTimer
            if (FearTimer <= diff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(pTarget, SPELL_FEAR);

                FearTimer = 10000 + (rand()%10000);
            } else FearTimer -= diff;

            //Add spawning mechanism
            if (AddSpawnTimer <= diff)
            {
                //Spawn 2 random types of creatures at the 2 locations
                uint32 CreatureID;
                Creature* Spawned = NULL;
                Unit *pTarget = NULL;

                //1 in 3 chance it will be a chromatic
                if (urand(0,2) == 0)
                    CreatureID = CREATURE_CHROMATIC_DRAKANOID;
                else
                    CreatureID = DrakType1;

                ++SpawnedAdds;

                //Spawn Creature and force it to start attacking a random target
                Spawned = me->SummonCreature(CreatureID,ADD_X1,ADD_Y1,ADD_Z1,5.000,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);
                if (pTarget && Spawned)
                {
                    Spawned->AI()->AttackStart(pTarget);
                    Spawned->setFaction(103);
                }

                //1 in 3 chance it will be a chromatic
                if (urand(0,2) == 0)
                    CreatureID = CREATURE_CHROMATIC_DRAKANOID;
                else
                    CreatureID = DrakType2;

                ++SpawnedAdds;

                Spawned = me->SummonCreature(CreatureID,ADD_X2,ADD_Y2,ADD_Z2,5.000,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);
                if (pTarget && Spawned)
                {
                    Spawned->AI()->AttackStart(pTarget);
                    Spawned->setFaction(103);
                }

                //Begin phase 2 by spawning Nefarian and what not
                if (SpawnedAdds >= 42)
                {
                    //Teleport Victor Nefarius way out of the map
                    //sMapMgr.GetMap(me->GetMapId(), me)->CreatureRelocation(me,0,0,-5000,0);

                    //Interrupt any spell casting
                    me->InterruptNonMeleeSpells(false);

                    //Root self
                    DoCast(me, 33356);

                    //Make super invis
                    DoCast(me, 8149);

                    //Teleport self to a hiding spot (this causes errors in the Trinity log but no real issues)
                    DoTeleportTo(HIDE_X,HIDE_Y,HIDE_Z);
                    me->addUnitState(UNIT_STAT_FLEEING);

                    //Spawn nef and have him attack a random target
                    Creature* Nefarian = me->SummonCreature(CREATURE_NEFARIAN,NEF_X,NEF_Y,NEF_Z,0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,120000);
                    pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);
                    if (pTarget && Nefarian)
                    {
                        Nefarian->AI()->AttackStart(pTarget);
                        Nefarian->setFaction(103);
                        NefarianGUID = Nefarian->GetGUID();
                    }
                    else sLog.outError("TSCR: Blackwing Lair: Unable to spawn nefarian properly.");
                }

                AddSpawnTimer = 4000;
            } else AddSpawnTimer -= diff;
        }
        else if (NefarianGUID)
        {
            if (NefCheckTime <= diff)
            {
                Unit* Nefarian = Unit::GetCreature((*me),NefarianGUID);

                //If nef is dead then we die to so the players get out of combat
                //and cannot repeat the event
                if (!Nefarian || !Nefarian->isAlive())
                {
                    NefarianGUID = 0;
                    me->ForcedDespawn();
                }

                NefCheckTime = 2000;
            } else NefCheckTime -= diff;
        }
    }
};

CreatureAI* GetAI_boss_victor_nefarius(Creature* pCreature)
{
    return new boss_victor_nefariusAI (pCreature);
}

bool GossipHello_boss_victor_nefarius(Player* pPlayer, Creature* pCreature)
{
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_1 , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
    pPlayer->SEND_GOSSIP_MENU(7134, pCreature->GetGUID());
    return true;
}

bool GossipSelect_boss_victor_nefarius(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    switch (uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
            pPlayer->SEND_GOSSIP_MENU(7198, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
            pPlayer->SEND_GOSSIP_MENU(7199, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+3:
            pPlayer->CLOSE_GOSSIP_MENU();
            DoScriptText(SAY_GAMESBEGIN_1, pCreature);
            CAST_AI(boss_victor_nefariusAI, pCreature->AI())->BeginEvent(pPlayer);
            break;
    }
    return true;
}

void AddSC_boss_victor_nefarius()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_victor_nefarius";
    newscript->GetAI = &GetAI_boss_victor_nefarius;
    newscript->pGossipHello = &GossipHello_boss_victor_nefarius;
    newscript->pGossipSelect = &GossipSelect_boss_victor_nefarius;
    newscript->RegisterSelf();
}

