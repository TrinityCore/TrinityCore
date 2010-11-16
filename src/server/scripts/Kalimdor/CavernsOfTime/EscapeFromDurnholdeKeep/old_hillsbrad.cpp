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
SDName: Old_Hillsbrad
SD%Complete: 40
SDComment: Quest support: 10283, 10284. All friendly NPC's. Thrall waypoints fairly complete, missing many details, but possible to complete escort.
SDCategory: Caverns of Time, Old Hillsbrad Foothills
EndScriptData */

/* ContentData
npc_erozion
npc_thrall_old_hillsbrad
npc_taretha
EndContentData */

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"
#include "old_hillsbrad.h"

#define QUEST_ENTRY_HILLSBRAD   10282
#define QUEST_ENTRY_DIVERSION   10283
#define QUEST_ENTRY_ESCAPE      10284
#define QUEST_ENTRY_RETURN      10285
#define ITEM_ENTRY_BOMBS        25853

#define GOSSIP_HELLO_EROZION1   "I need a pack of Incendiary Bombs."
#define GOSSIP_HELLO_EROZION2   "[PH] Teleport please, i'm tired."

/*######
## npc_erozion
######*/

class npc_erozion : public CreatureScript
{
public:
    npc_erozion() : CreatureScript("npc_erozion") { }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
        {
            ItemPosCountVec dest;
            uint8 msg = pPlayer->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, ITEM_ENTRY_BOMBS, 1);
            if (msg == EQUIP_ERR_OK)
            {
                 pPlayer->StoreNewItem(dest, ITEM_ENTRY_BOMBS, true);
            }
            pPlayer->SEND_GOSSIP_MENU(9515, pCreature->GetGUID());
        }
        if (uiAction == GOSSIP_ACTION_INFO_DEF+2)
        {
            pPlayer->CLOSE_GOSSIP_MENU();
        }
        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        InstanceScript* pInstance = pCreature->GetInstanceScript();
        if (pInstance && pInstance->GetData(TYPE_BARREL_DIVERSION) != DONE && !pPlayer->HasItemCount(ITEM_ENTRY_BOMBS,1))
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_EROZION1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        if (!pPlayer->GetQuestRewardStatus(QUEST_ENTRY_RETURN) && pPlayer->GetQuestStatus(QUEST_ENTRY_RETURN) == QUEST_STATUS_COMPLETE)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_EROZION2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);

        pPlayer->SEND_GOSSIP_MENU(9778, pCreature->GetGUID());

        return true;
    }

};


/*######
## npc_thrall_old_hillsbrad
######*/

//Thrall texts
#define SAY_TH_START_EVENT_PART1    -1560023
#define SAY_TH_ARMORY               -1560024
#define SAY_TH_SKARLOC_MEET         -1560025
#define SAY_TH_SKARLOC_TAUNT        -1560026
#define SAY_TH_START_EVENT_PART2    -1560027
#define SAY_TH_MOUNTS_UP            -1560028
#define SAY_TH_CHURCH_END           -1560029
#define SAY_TH_MEET_TARETHA         -1560030
#define SAY_TH_EPOCH_WONDER         -1560031
#define SAY_TH_EPOCH_KILL_TARETHA   -1560032
#define SAY_TH_EVENT_COMPLETE       -1560033

#define SAY_TH_RANDOM_LOW_HP1       -1560034
#define SAY_TH_RANDOM_LOW_HP2       -1560035

#define SAY_TH_RANDOM_DIE1          -1560036
#define SAY_TH_RANDOM_DIE2          -1560037

#define SAY_TH_RANDOM_AGGRO1        -1560038
#define SAY_TH_RANDOM_AGGRO2        -1560039
#define SAY_TH_RANDOM_AGGRO3        -1560040
#define SAY_TH_RANDOM_AGGRO4        -1560041

#define SAY_TH_RANDOM_KILL1         -1560042
#define SAY_TH_RANDOM_KILL2         -1560043
#define SAY_TH_RANDOM_KILL3         -1560044

#define SAY_TH_LEAVE_COMBAT1        -1560045
#define SAY_TH_LEAVE_COMBAT2        -1560046
#define SAY_TH_LEAVE_COMBAT3        -1560047

//Taretha texts
#define SAY_TA_FREE                 -1560048
#define SAY_TA_ESCAPED              -1560049

//Misc for Thrall
#define SPELL_STRIKE                14516
#define SPELL_SHIELD_BLOCK          12169
#define SPELL_SUMMON_EROZION_IMAGE  33954                   //if thrall dies during escort?

#define SPEED_WALK              (0.5f)
#define SPEED_RUN               (1.0f)
#define SPEED_MOUNT             (1.6f)

#define THRALL_WEAPON_MODEL     22106
#define THRALL_WEAPON_INFO      218169346
#define THRALL_SHIELD_MODEL     18662
#define THRALL_SHIELD_INFO      234948100
#define THRALL_MODEL_UNEQUIPPED 17292
#define THRALL_MODEL_EQUIPPED   18165

//Misc Creature entries
#define ENTRY_ARMORER               18764
#define ENTRY_SCARLOC               17862

#define MOB_ENTRY_RIFLE         17820
#define MOB_ENTRY_WARDEN        17833
#define MOB_ENTRY_VETERAN       17860
#define MOB_ENTRY_WATCHMAN      17814
#define MOB_ENTRY_SENTRY        17815

#define MOB_ENTRY_BARN_GUARDSMAN    18092
#define MOB_ENTRY_BARN_PROTECTOR    18093
#define MOB_ENTRY_BARN_LOOKOUT      18094

#define MOB_ENTRY_CHURCH_GUARDSMAN  23175
#define MOB_ENTRY_CHURCH_PROTECTOR  23179
#define MOB_ENTRY_CHURCH_LOOKOUT    23177

#define MOB_ENTRY_INN_GUARDSMAN     23176
#define MOB_ENTRY_INN_PROTECTOR     23180
#define MOB_ENTRY_INN_LOOKOUT       23178

#define SKARLOC_MOUNT           18798
#define SKARLOC_MOUNT_MODEL     18223
#define EROZION_ENTRY           18723
#define ENTRY_EPOCH                 18096

//gossip items
#define GOSSIP_ID_START         9568
#define GOSSIP_ID_SKARLOC1      9614                        //I'm glad Taretha is alive. We now must find a way to free her...
#define GOSSIP_ITEM_SKARLOC1    "Taretha cannot see you, Thrall."
#define GOSSIP_ID_SKARLOC2      9579                        //What do you mean by this? Is Taretha in danger?
#define GOSSIP_ITEM_SKARLOC2    "The situation is rather complicated, Thrall. It would be best for you to head into the mountains now, before more of Blackmoore's men show up. We'll make sure Taretha is safe."
#define GOSSIP_ID_SKARLOC3      9580

#define GOSSIP_ID_TARREN        9597                        //tarren mill is beyond these trees
#define GOSSIP_ITEM_TARREN      "We're ready, Thrall."

#define GOSSIP_ID_COMPLETE      9578                        //Thank you friends, I owe my freedom to you. Where is Taretha? I hoped to see her

#define GOSSIP_ITEM_WALKING     "[PH] Start walking."

class npc_thrall_old_hillsbrad : public CreatureScript
{
public:
    npc_thrall_old_hillsbrad() : CreatureScript("npc_thrall_old_hillsbrad") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_thrall_old_hillsbradAI(pCreature);
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        InstanceScript* pInstance = pCreature->GetInstanceScript();
        switch(uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                pPlayer->CLOSE_GOSSIP_MENU();
                if (pInstance)
                {
                    pInstance->SetData(TYPE_THRALL_EVENT,IN_PROGRESS);
                    pInstance->SetData(TYPE_THRALL_PART1,IN_PROGRESS);
                }

                DoScriptText(SAY_TH_START_EVENT_PART1, pCreature);

                if (npc_escortAI* pEscortAI = CAST_AI(npc_thrall_old_hillsbrad::npc_thrall_old_hillsbradAI, pCreature->AI()))
                    pEscortAI->Start(true, true, pPlayer->GetGUID());

                CAST_AI(npc_escortAI, (pCreature->AI()))->SetMaxPlayerDistance(100.0f);//not really needed, because it will not despawn if player is too far
                CAST_AI(npc_escortAI, (pCreature->AI()))->SetDespawnAtEnd(false);
                CAST_AI(npc_escortAI, (pCreature->AI()))->SetDespawnAtFar(false);
                break;

            case GOSSIP_ACTION_INFO_DEF+2:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_SKARLOC2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+20);
                pPlayer->SEND_GOSSIP_MENU(GOSSIP_ID_SKARLOC2, pCreature->GetGUID());
                break;

            case GOSSIP_ACTION_INFO_DEF+20:
                pPlayer->SEND_GOSSIP_MENU(GOSSIP_ID_SKARLOC3, pCreature->GetGUID());
                pCreature->SummonCreature(SKARLOC_MOUNT,2038.81f,270.26f,63.20f,5.41f,TEMPSUMMON_TIMED_DESPAWN,12000);
                if (pInstance)
                    pInstance->SetData(TYPE_THRALL_PART2,IN_PROGRESS);

                DoScriptText(SAY_TH_START_EVENT_PART2, pCreature);

                CAST_AI(npc_thrall_old_hillsbrad::npc_thrall_old_hillsbradAI, pCreature->AI())->StartWP();
                break;

            case GOSSIP_ACTION_INFO_DEF+3:
                pPlayer->CLOSE_GOSSIP_MENU();
                if (pInstance)
                    pInstance->SetData(TYPE_THRALL_PART3,IN_PROGRESS);
                CAST_AI(npc_thrall_old_hillsbrad::npc_thrall_old_hillsbradAI, pCreature->AI())->StartWP();
                break;
        }
        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
        {
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());
            pPlayer->SendPreparedQuest(pCreature->GetGUID());
        }

        InstanceScript* pInstance = pCreature->GetInstanceScript();
        if (pInstance)
        {
            if (pInstance->GetData(TYPE_BARREL_DIVERSION) == DONE && !pInstance->GetData(TYPE_THRALL_EVENT))
            {
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_WALKING, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                pPlayer->SEND_GOSSIP_MENU(GOSSIP_ID_START, pCreature->GetGUID());
            }

            if (pInstance->GetData(TYPE_THRALL_PART1) == DONE && !pInstance->GetData(TYPE_THRALL_PART2))
            {
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_SKARLOC1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                pPlayer->SEND_GOSSIP_MENU(GOSSIP_ID_SKARLOC1, pCreature->GetGUID());
            }

            if (pInstance->GetData(TYPE_THRALL_PART2) == DONE && !pInstance->GetData(TYPE_THRALL_PART3))
            {
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_TARREN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
                pPlayer->SEND_GOSSIP_MENU(GOSSIP_ID_TARREN, pCreature->GetGUID());
            }
        }
        return true;
    }

    struct npc_thrall_old_hillsbradAI : public npc_escortAI
    {
        npc_thrall_old_hillsbradAI(Creature *c) : npc_escortAI(c)
        {
            pInstance = c->GetInstanceScript();
            HadMount = false;
            me->setActive(true);
        }

        InstanceScript *pInstance;

        uint64 TarethaGUID;

        bool LowHp;
        bool HadMount;

        void WaypointReached(uint32 i)
        {
            if (!pInstance)
                return;

            switch(i)
            {
                case 8:
                    SetRun(false);
                    me->SummonCreature(18764,2181.87f,112.46f,89.45f,0.26f,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                    break;
                case 9:
                    DoScriptText(SAY_TH_ARMORY, me);
                    me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, THRALL_WEAPON_MODEL);
                    //me->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO, THRALL_WEAPON_INFO);
                    //me->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO+1, 781);
                    me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID+1, THRALL_SHIELD_MODEL);
                    //me->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO+2, THRALL_SHIELD_INFO);
                    //me->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO+3, 1038);
                    break;
                case 10:
                    me->SetDisplayId(THRALL_MODEL_EQUIPPED);
                    break;
                case 11:
                    SetRun();
                    break;
                case 15:
                    me->SummonCreature(MOB_ENTRY_RIFLE,2200.28f,137.37f,87.93f,5.07f,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                    me->SummonCreature(MOB_ENTRY_WARDEN,2197.44f,131.83f,87.93f,0.78f,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                    me->SummonCreature(MOB_ENTRY_VETERAN,2203.62f,135.40f,87.93f,3.70f,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                    me->SummonCreature(MOB_ENTRY_VETERAN,2200.75f,130.13f,87.93f,1.48f,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                    break;
                case 21:
                    me->SummonCreature(MOB_ENTRY_RIFLE,2135.80f,154.01f,67.45f,4.98f,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                    me->SummonCreature(MOB_ENTRY_WARDEN,2144.36f,151.87f,67.74f,4.46f,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                    me->SummonCreature(MOB_ENTRY_VETERAN,2142.12f,154.41f,67.12f,4.56f,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                    me->SummonCreature(MOB_ENTRY_VETERAN,2138.08f,155.38f,67.24f,4.60f,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                    break;
                case 25:
                    me->SummonCreature(MOB_ENTRY_RIFLE,2102.98f,192.17f,65.24f,6.02f,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                    me->SummonCreature(MOB_ENTRY_WARDEN,2108.48f,198.75f,65.18f,5.15f,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                    me->SummonCreature(MOB_ENTRY_VETERAN,2106.11f,197.29f,65.18f,5.63f,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                    me->SummonCreature(MOB_ENTRY_VETERAN,2104.18f,194.82f,65.18f,5.75f,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                    break;
                case 29:
                    DoScriptText(SAY_TH_SKARLOC_MEET, me);
                    me->SummonCreature(ENTRY_SCARLOC,2036.48f,271.22f,63.43f,5.27f,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,30000);
                    //temporary,skarloc should rather be triggered to walk up to thrall
                    break;
                case 30:
                    SetEscortPaused(true);
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    SetRun(false);
                    break;
                case 31:
                    DoScriptText(SAY_TH_MOUNTS_UP, me);
                    DoMount();
                    SetRun();
                    break;
                case 37:
                    //possibly regular patrollers? If so, remove this and let database handle them
                    me->SummonCreature(MOB_ENTRY_WATCHMAN,2124.26f,522.16f,56.87f,3.99f,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                    me->SummonCreature(MOB_ENTRY_WATCHMAN,2121.69f,525.37f,57.11f,4.01f,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                    me->SummonCreature(MOB_ENTRY_SENTRY,2124.65f,524.55f,56.63f,3.98f,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                    break;
                case 59:
                    me->SummonCreature(SKARLOC_MOUNT,2488.64f,625.77f,58.26f,4.71f,TEMPSUMMON_TIMED_DESPAWN,10000);
                    DoUnmount();
                    HadMount = false;
                    SetRun(false);
                    break;
                case 60:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                    //make horsie run off
                    SetEscortPaused(true);
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    pInstance->SetData(TYPE_THRALL_PART2, DONE);
                    SetRun();
                    break;
                case 64:
                    SetRun(false);
                    break;
                case 68:
                    me->SummonCreature(MOB_ENTRY_BARN_PROTECTOR,2500.22f,692.60f,55.50f,2.84f,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                    me->SummonCreature(MOB_ENTRY_BARN_LOOKOUT,2500.13f,696.55f,55.51f,3.38f,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                    me->SummonCreature(MOB_ENTRY_BARN_GUARDSMAN,2500.55f,693.64f,55.50f,3.14f,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                    me->SummonCreature(MOB_ENTRY_BARN_GUARDSMAN,2500.94f,695.81f,55.50f,3.14f,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                    break;
                case 71:
                    SetRun();
                    break;
                case 81:
                    SetRun(false);
                    break;
                case 83:
                    me->SummonCreature(MOB_ENTRY_CHURCH_PROTECTOR,2627.33f,646.82f,56.03f,4.28f,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,5000);
                    me->SummonCreature(MOB_ENTRY_CHURCH_LOOKOUT,2624.14f,648.03f,56.03f,4.50f,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,5000);
                    me->SummonCreature(MOB_ENTRY_CHURCH_GUARDSMAN,2625.32f,649.60f,56.03f,4.38f,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,5000);
                    me->SummonCreature(MOB_ENTRY_CHURCH_GUARDSMAN,2627.22f,649.00f,56.03f,4.34f,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,5000);
                    break;
                case 84:
                    DoScriptText(SAY_TH_CHURCH_END, me);
                    SetRun();
                    break;
                case 91:
                    me->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                    SetRun(false);
                    break;
                case 93:
                    me->SummonCreature(MOB_ENTRY_INN_PROTECTOR,2652.71f,660.31f,61.93f,1.67f,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                    me->SummonCreature(MOB_ENTRY_INN_LOOKOUT,2648.96f,662.59f,61.93f,0.79f,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                    me->SummonCreature(MOB_ENTRY_INN_GUARDSMAN,2657.36f,662.34f,61.93f,2.68f,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                    me->SummonCreature(MOB_ENTRY_INN_GUARDSMAN,2656.39f,659.77f,61.93f,2.61f,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                    break;
                case 94:
                    if (uint64 TarethaGUID = pInstance->GetData64(DATA_TARETHA))
                    {
                        if (Unit* Taretha = Unit::GetUnit((*me), TarethaGUID))
                            DoScriptText(SAY_TA_ESCAPED, Taretha, me);
                    }
                    break;
                case 95:
                    DoScriptText(SAY_TH_MEET_TARETHA, me);
                    pInstance->SetData(TYPE_THRALL_PART3,DONE);
                    SetEscortPaused(true);
                    break;
                case 96:
                    DoScriptText(SAY_TH_EPOCH_WONDER, me);
                    break;
                case 97:
                    DoScriptText(SAY_TH_EPOCH_KILL_TARETHA, me);
                    SetRun();
                    break;
                case 98:
                    //trigger epoch Yell("Thrall! Come outside and face your fate! ....")
                    //from here, thrall should not never be allowed to move to point 106 which he currently does.
                    break;

                case 106:
                    {
                        //trigger taretha to run down outside
                        if (Creature* Taretha = pInstance->instance->GetCreature(pInstance->GetData64(DATA_TARETHA)))
                        {
                            if (Player* pPlayer = GetPlayerForEscort())
                                CAST_AI(npc_escortAI, (Taretha->AI()))->Start(false, true, pPlayer->GetGUID());
                        }

                        //kill credit Creature for quest
                        Map* pMap = me->GetMap();
                        Map::PlayerList const& players = pMap->GetPlayers();
                        if (!players.isEmpty() && pMap->IsDungeon())
                        {
                            for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                            {
                                if (Player* pPlayer = itr->getSource())
                                    pPlayer->KilledMonsterCredit(20156, 0);
                            }
                        }

                        //alot will happen here, thrall and taretha talk, erozion appear at spot to explain
                        me->SummonCreature(EROZION_ENTRY,2646.47f,680.416f,55.38f,4.16f,TEMPSUMMON_TIMED_DESPAWN,120000);
                    }
                    break;
                case 108:
                    //last waypoint, just set Thrall invisible, respawn is turned off
                    me->SetVisible(false);
                    break;
            }
        }

        void Reset()
        {
            LowHp = false;

            if (HadMount)
                DoMount();

            if (!HasEscortState(STATE_ESCORT_ESCORTING))
            {
                DoUnmount();
                HadMount = false;
                me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, 0);
                me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID+1, 0);
                me->SetDisplayId(THRALL_MODEL_UNEQUIPPED);
            }
            if (HasEscortState(STATE_ESCORT_ESCORTING))
            {
                DoScriptText(RAND(SAY_TH_LEAVE_COMBAT1,SAY_TH_LEAVE_COMBAT2,SAY_TH_LEAVE_COMBAT3), me);
            }
        }
        void StartWP()
        {
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            SetEscortPaused(false);
        }
        void DoMount()
        {
            me->Mount(SKARLOC_MOUNT_MODEL);
            me->SetSpeed(MOVE_RUN,SPEED_MOUNT);
        }
        void DoUnmount()
        {
            me->Unmount();
            me->SetSpeed(MOVE_RUN,SPEED_RUN);
        }
        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(RAND(SAY_TH_RANDOM_AGGRO1,SAY_TH_RANDOM_AGGRO2,SAY_TH_RANDOM_AGGRO3,SAY_TH_RANDOM_AGGRO4), me);
            if (me->IsMounted())
            {
                DoUnmount();
                HadMount = true;
            }
        }

        void JustSummoned(Creature* summoned)
        {
             switch(summoned->GetEntry())
             {
            //TODO: make Scarloc start into event instead, and not start attack directly
             case MOB_ENTRY_BARN_GUARDSMAN:
             case MOB_ENTRY_BARN_PROTECTOR:
             case MOB_ENTRY_BARN_LOOKOUT:
             case SKARLOC_MOUNT:
             case EROZION_ENTRY:
                 break;
             default:
                 summoned->AI()->AttackStart(me);
                 break;
             }
        }

        void KilledUnit(Unit * /*victim*/)
        {
            DoScriptText(RAND(SAY_TH_RANDOM_KILL1,SAY_TH_RANDOM_KILL2,SAY_TH_RANDOM_KILL3), me);
        }
        void JustDied(Unit *slayer)
        {
            if (pInstance)
                pInstance->SetData(TYPE_THRALL_EVENT,FAIL);

            // Don't do a yell if he kills self (if player goes too far or at the end).
            if (slayer == me)
                return;

            DoScriptText(RAND(SAY_TH_RANDOM_DIE1,SAY_TH_RANDOM_DIE2), me);
        }

        void UpdateAI(const uint32 diff)
        {
            npc_escortAI::UpdateAI(diff);

            if (!UpdateVictim())
                return;

                 //TODO: add his abilities'n-crap here
                if (!LowHp && HealthBelowPct(20))
                {
                    DoScriptText(RAND(SAY_TH_RANDOM_LOW_HP1,SAY_TH_RANDOM_LOW_HP2), me);
                    LowHp = true;
                }
        }
    };

};




/*######
## npc_taretha
######*/

#define GOSSIP_ID_EPOCH1        9610                        //Thank you for helping Thrall escape, friends. Now I only hope
#define GOSSIP_ITEM_EPOCH1      "Strange wizard?"
#define GOSSIP_ID_EPOCH2        9613                        //Yes, friends. This man was no wizard of
#define GOSSIP_ITEM_EPOCH2      "We'll get you out. Taretha. Don't worry. I doubt the wizard would wander too far away."

class npc_taretha : public CreatureScript
{
public:
    npc_taretha() : CreatureScript("npc_taretha") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_tarethaAI(pCreature);
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        InstanceScript* pInstance = pCreature->GetInstanceScript();
        if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_EPOCH2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_ID_EPOCH2, pCreature->GetGUID());
        }
        if (uiAction == GOSSIP_ACTION_INFO_DEF+2)
        {
            pPlayer->CLOSE_GOSSIP_MENU();

            if (pInstance && pInstance->GetData(TYPE_THRALL_EVENT) == IN_PROGRESS)
            {
                pInstance->SetData(TYPE_THRALL_PART4,IN_PROGRESS);
                if (pInstance->GetData64(DATA_EPOCH) == 0)
                     pCreature->SummonCreature(ENTRY_EPOCH,2639.13f,698.55f,65.43f,4.59f,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,120000);

                 if (uint64 ThrallGUID = pInstance->GetData64(DATA_THRALL))
                 {
                     Creature* Thrall = (Unit::GetCreature((*pCreature), ThrallGUID));
                     if (Thrall)
                         CAST_AI(npc_thrall_old_hillsbrad::npc_thrall_old_hillsbradAI, Thrall->AI())->StartWP();
                 }
            }
        }
        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        InstanceScript* pInstance = pCreature->GetInstanceScript();
        if (pInstance && pInstance->GetData(TYPE_THRALL_PART3) == DONE && pInstance->GetData(TYPE_THRALL_PART4) == NOT_STARTED)
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_EPOCH1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_ID_EPOCH1, pCreature->GetGUID());
        }
        return true;
    }

    struct npc_tarethaAI : public npc_escortAI
    {
        npc_tarethaAI(Creature *c) : npc_escortAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript *pInstance;

        void WaypointReached(uint32 i)
        {
            switch(i)
            {
                case 6:
                    DoScriptText(SAY_TA_FREE, me);
                    break;
                case 7:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_CHEER);
                    break;
            }
        }
        void Reset() {}
        void EnterCombat(Unit* /*who*/) {}

        void UpdateAI(const uint32 diff)
        {
            npc_escortAI::UpdateAI(diff);
        }
    };

};



/*######
## AddSC
######*/

void AddSC_old_hillsbrad()
{
    new npc_erozion();
    new npc_thrall_old_hillsbrad();
    new npc_taretha();
}
