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
SDName: Old_Hillsbrad
SD%Complete: 40
SDComment: Quest support: 10283, 10284. All friendly NPC's. Thrall waypoints fairly complete, missing many details, but possible to complete escort.
SDCategory: Caverns of Time, Old Hillsbrad Foothills
EndScriptData */

/* ContentData
npc_brazen
npc_erozion
npc_thrall_old_hillsbrad
npc_taretha
EndContentData */

#include "precompiled.h"
#include "../../../npc/npc_escortAI.h"
#include "def_old_hillsbrad.h"

#define QUEST_ENTRY_HILLSBRAD   10282
#define QUEST_ENTRY_DIVERSION   10283
#define QUEST_ENTRY_ESCAPE      10284
#define QUEST_ENTRY_RETURN      10285
#define ITEM_ENTRY_BOMBS        25853

/*######
## npc_brazen
######*/

bool GossipHello_npc_brazen(Player *player, Creature *_Creature)
{
    player->ADD_GOSSIP_ITEM(0, "I am ready to go to Durnholde Keep.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
    player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(), _Creature->GetGUID());
    return true;
}

bool GossipSelect_npc_brazen(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    if (action == GOSSIP_ACTION_INFO_DEF+1)
    {
        if( !player->HasItemCount(ITEM_ENTRY_BOMBS,1) )
            player->SEND_GOSSIP_MENU(9780, _Creature->GetGUID());
        else
        {
            player->CLOSE_GOSSIP_MENU();

            std::vector<uint32> nodes;

            nodes.resize(2);
            nodes[0] = 115;                                 //from brazen
            nodes[1] = 116;                                 //end outside durnholde
            player->ActivateTaxiPathTo(nodes);              //TaxiPath 534
        }
    }
    return true;
}

/*######
## npc_erozion
######*/

bool GossipHello_npc_erozion(Player *player, Creature *_Creature)
{
    if( _Creature->isQuestGiver() )
        player->PrepareQuestMenu( _Creature->GetGUID() );

    ScriptedInstance* pInstance = ((ScriptedInstance*)_Creature->GetInstanceData());
    if( pInstance && pInstance->GetData(TYPE_BARREL_DIVERSION) != DONE && !player->HasItemCount(ITEM_ENTRY_BOMBS,1) )
        player->ADD_GOSSIP_ITEM( 0, "I need a pack of Incendiary Bombs.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    if( !player->GetQuestRewardStatus(QUEST_ENTRY_RETURN) && player->GetQuestStatus(QUEST_ENTRY_RETURN) == QUEST_STATUS_COMPLETE )
        player->ADD_GOSSIP_ITEM( 0, "[PH] Teleport please, i'm tired.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);

    player->SEND_GOSSIP_MENU(9778, _Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_erozion(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    if( action == GOSSIP_ACTION_INFO_DEF+1 )
    {
        ItemPosCountVec dest;
        uint8 msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, ITEM_ENTRY_BOMBS, 1);
        if( msg == EQUIP_ERR_OK )
        {
             player->StoreNewItem(dest, ITEM_ENTRY_BOMBS, true);
        }
        player->SEND_GOSSIP_MENU(9515, _Creature->GetGUID());
    }
    if( action == GOSSIP_ACTION_INFO_DEF+2 )
    {
        player->CLOSE_GOSSIP_MENU();
    }
    return true;
}

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

//Misc creature entries
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

struct TRINITY_DLL_DECL npc_thrall_old_hillsbradAI : public npc_escortAI
{
    npc_thrall_old_hillsbradAI(Creature *c) : npc_escortAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        m_creature->setActive(true);
    }

    ScriptedInstance *pInstance;

    uint64 TarethaGUID;

    bool LowHp;
    bool HadMount;

    void WaypointReached(uint32 i)
    {
        if (!pInstance)
            return;

        switch( i )
        {
            case 8:
                SetRun(false);
                m_creature->SummonCreature(18764,2181.87,112.46,89.45,0.26,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                break;
            case 9:
                DoScriptText(SAY_TH_ARMORY, m_creature);
                m_creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, THRALL_WEAPON_MODEL);
                //m_creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO, THRALL_WEAPON_INFO);
                //m_creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO+1, 781);
                m_creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID+1, THRALL_SHIELD_MODEL);
                //m_creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO+2, THRALL_SHIELD_INFO);
                //m_creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO+3, 1038);
                break;
            case 10:
                m_creature->SetUInt32Value(UNIT_FIELD_DISPLAYID, THRALL_MODEL_EQUIPPED);
                break;
            case 11:
                SetRun();
                break;
            case 15:
                m_creature->SummonCreature(MOB_ENTRY_RIFLE,2200.28,137.37,87.93,5.07,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                m_creature->SummonCreature(MOB_ENTRY_WARDEN,2197.44,131.83,87.93,0.78,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                m_creature->SummonCreature(MOB_ENTRY_VETERAN,2203.62,135.40,87.93,3.70,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                m_creature->SummonCreature(MOB_ENTRY_VETERAN,2200.75,130.13,87.93,1.48,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                break;
            case 21:
                m_creature->SummonCreature(MOB_ENTRY_RIFLE,2135.80,154.01,67.45,4.98,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                m_creature->SummonCreature(MOB_ENTRY_WARDEN,2144.36,151.87,67.74,4.46,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                m_creature->SummonCreature(MOB_ENTRY_VETERAN,2142.12,154.41,67.12,4.56,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                m_creature->SummonCreature(MOB_ENTRY_VETERAN,2138.08,155.38,67.24,4.60,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                break;
            case 25:
                m_creature->SummonCreature(MOB_ENTRY_RIFLE,2102.98,192.17,65.24,6.02,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                m_creature->SummonCreature(MOB_ENTRY_WARDEN,2108.48,198.75,65.18,5.15,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                m_creature->SummonCreature(MOB_ENTRY_VETERAN,2106.11,197.29,65.18,5.63,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                m_creature->SummonCreature(MOB_ENTRY_VETERAN,2104.18,194.82,65.18,5.75,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                break;
            case 29:
                DoScriptText(SAY_TH_SKARLOC_MEET, m_creature);
                m_creature->SummonCreature(17862,2036.48,271.22,63.43,5.27,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,30000);
                //temporary,skarloc should rather be triggered to walk up to thrall
                break;
            case 30:
                IsOnHold = true;
                m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                SetRun(false);
                break;
            case 31:
                DoScriptText(SAY_TH_MOUNTS_UP, m_creature);
                DoMount();
                SetRun();
                break;
            case 37:
                //possibly regular patrollers? If so, remove this and let database handle them
                m_creature->SummonCreature(MOB_ENTRY_WATCHMAN,2124.26,522.16,56.87,3.99,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                m_creature->SummonCreature(MOB_ENTRY_WATCHMAN,2121.69,525.37,57.11,4.01,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                m_creature->SummonCreature(MOB_ENTRY_SENTRY,2124.65,524.55,56.63,3.98,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                break;
            case 59:
                m_creature->SummonCreature(SKARLOC_MOUNT,2488.64,625.77,58.26,4.71,TEMPSUMMON_TIMED_DESPAWN,10000);
                DoUnmount();
                HadMount = false;
                SetRun(false);
                break;
            case 60:
                m_creature->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                //make horsie run off
                IsOnHold = true;
                m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                pInstance->SetData(TYPE_THRALL_PART2, DONE);
                SetRun();
                break;
            case 64:
                SetRun(false);
                break;
            case 68:
                m_creature->SummonCreature(MOB_ENTRY_BARN_PROTECTOR,2500.22,692.60,55.50,2.84,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                m_creature->SummonCreature(MOB_ENTRY_BARN_LOOKOUT,2500.13,696.55,55.51,3.38,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                m_creature->SummonCreature(MOB_ENTRY_BARN_GUARDSMAN,2500.55,693.64,55.50,3.14,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                m_creature->SummonCreature(MOB_ENTRY_BARN_GUARDSMAN,2500.94,695.81,55.50,3.14,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                break;
            case 71:
                SetRun();
                break;
            case 81:
                SetRun(false);
                break;
            case 83:
                m_creature->SummonCreature(MOB_ENTRY_CHURCH_PROTECTOR,2627.33,646.82,56.03,4.28,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,5000);
                m_creature->SummonCreature(MOB_ENTRY_CHURCH_LOOKOUT,2624.14,648.03,56.03,4.50,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,5000);
                m_creature->SummonCreature(MOB_ENTRY_CHURCH_GUARDSMAN,2625.32,649.60,56.03,4.38,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,5000);
                m_creature->SummonCreature(MOB_ENTRY_CHURCH_GUARDSMAN,2627.22,649.00,56.03,4.34,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,5000);
                break;
            case 84:
                DoScriptText(SAY_TH_CHURCH_END, m_creature);
                SetRun();
                break;
            case 91:
                m_creature->AddUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                SetRun(false);
                break;
            case 93:
                m_creature->SummonCreature(MOB_ENTRY_INN_PROTECTOR,2652.71,660.31,61.93,1.67,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                m_creature->SummonCreature(MOB_ENTRY_INN_LOOKOUT,2648.96,662.59,61.93,0.79,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                m_creature->SummonCreature(MOB_ENTRY_INN_GUARDSMAN,2657.36,662.34,61.93,2.68,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                m_creature->SummonCreature(MOB_ENTRY_INN_GUARDSMAN,2656.39,659.77,61.93,2.61,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                break;
            case 94:
                if (uint64 TarethaGUID = pInstance->GetData64(DATA_TARETHA))
                {
                    if (Unit* Taretha = Unit::GetUnit((*m_creature), TarethaGUID))
                        DoScriptText(SAY_TA_ESCAPED, Taretha, m_creature);
                }
                break;
            case 95:
                DoScriptText(SAY_TH_MEET_TARETHA, m_creature);
                pInstance->SetData(TYPE_THRALL_PART3,DONE);
                IsOnHold = true;
                break;
            case 96:
                DoScriptText(SAY_TH_EPOCH_WONDER, m_creature);
                break;
            case 97:
                DoScriptText(SAY_TH_EPOCH_KILL_TARETHA, m_creature);
                SetRun();
                break;
            case 98:
                //trigger epoch Yell("Thrall! Come outside and face your fate! ....")
                //from here, thrall should not never be allowed to move to point 106 which he currently does.
                break;

            case 106:
                {
                    if (!PlayerGUID)
                        break;

                    //trigger taretha to run down outside
                    if (uint64 TarethaGUID = pInstance->GetData64(DATA_TARETHA))
                    {
                        if (Creature* Taretha = (Unit::GetCreature(*m_creature, TarethaGUID)))
                            ((npc_escortAI*)(Taretha->AI()))->Start(false, false, true, PlayerGUID);
                    }

                    //kill credit creature for quest
                    Map *map = m_creature->GetMap();
                    Map::PlayerList const& players = map->GetPlayers();
                    if (!players.isEmpty() && map->IsDungeon())
                    {
                        for(Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        {
                            if (Player* pPlayer = itr->getSource())
                                pPlayer->KilledMonster(20156,m_creature->GetGUID());
                        }
                    }

                    //alot will happen here, thrall and taretha talk, erozion appear at spot to explain
                    m_creature->SummonCreature(EROZION_ENTRY,2646.47,680.416,55.38,4.16,TEMPSUMMON_TIMED_DESPAWN,120000);
                }
                break;
            case 108:
                //last waypoint, just set Thrall invisible, respawn is turned off
                m_creature->SetVisibility(VISIBILITY_OFF);
                break;
        }
    }


    void Reset()
    {
        LowHp = false;

        if( HadMount )
            DoMount();

        if( !IsBeingEscorted )
        {
            DoUnmount();
            HadMount = false;
            m_creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, 0);
            m_creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID+1, 0);
            m_creature->SetUInt32Value(UNIT_FIELD_DISPLAYID, THRALL_MODEL_UNEQUIPPED);
        }
        if( IsBeingEscorted )
        {
            switch(rand()%3)
            {
            case 0: DoScriptText(SAY_TH_LEAVE_COMBAT1, m_creature); break;
            case 1: DoScriptText(SAY_TH_LEAVE_COMBAT2, m_creature); break;
            case 2: DoScriptText(SAY_TH_LEAVE_COMBAT3, m_creature); break;
            }
        }
    }
    void StartWP()
    {
        m_creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        IsOnHold = false;
    }
    void DoMount()
    {
        m_creature->Mount(SKARLOC_MOUNT_MODEL);
        m_creature->SetSpeed(MOVE_RUN,SPEED_MOUNT);
    }
    void DoUnmount()
    {
        m_creature->Unmount();
        m_creature->SetSpeed(MOVE_RUN,SPEED_RUN);
    }
    void EnterCombat(Unit* who)
    {
        switch(rand()%4)
        {
        case 0: DoScriptText(SAY_TH_RANDOM_AGGRO1, m_creature); break;
        case 1: DoScriptText(SAY_TH_RANDOM_AGGRO2, m_creature); break;
        case 2: DoScriptText(SAY_TH_RANDOM_AGGRO3, m_creature); break;
        case 3: DoScriptText(SAY_TH_RANDOM_AGGRO4, m_creature); break;
        }
        if( m_creature->IsMounted() )
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
             summoned->AI()->AttackStart(m_creature);
             break;
         }
    }

    void KilledUnit(Unit *victim)
    {
        switch(rand()%3)
        {
        case 0: DoScriptText(SAY_TH_RANDOM_KILL1, m_creature); break;
        case 1: DoScriptText(SAY_TH_RANDOM_KILL2, m_creature); break;
        case 2: DoScriptText(SAY_TH_RANDOM_KILL3, m_creature); break;
        }
    }
    void JustDied(Unit *slayer)
    {
        if (pInstance)
            pInstance->SetData(TYPE_THRALL_EVENT,FAIL);

        // Don't do a yell if he kills self (if player goes too far or at the end).
        if(slayer == m_creature)
            return;

        switch(rand()%2)
        {
        case 0: DoScriptText(SAY_TH_RANDOM_DIE1, m_creature); break;
        case 1: DoScriptText(SAY_TH_RANDOM_DIE2, m_creature); break;
        }
    }

    void UpdateAI(const uint32 diff)
    {
        npc_escortAI::UpdateAI(diff);

        if (!UpdateVictim())
            return;

             //TODO: add his abilities'n-crap here
            if( !LowHp && ((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 20) )
            {
                switch(rand()%2)
                {
                case 0: DoScriptText(SAY_TH_RANDOM_LOW_HP1, m_creature); break;
                case 1: DoScriptText(SAY_TH_RANDOM_LOW_HP2, m_creature); break;
                }
                LowHp = true;
            }
    }
};

CreatureAI* GetAI_npc_thrall_old_hillsbrad(Creature *_Creature)
{
    npc_thrall_old_hillsbradAI* thrall_walkAI = new npc_thrall_old_hillsbradAI(_Creature);

    thrall_walkAI->FillPointMovementListForCreature();

    return (CreatureAI*)thrall_walkAI;
}

bool GossipHello_npc_thrall_old_hillsbrad(Player *player, Creature *_Creature)
{
    if( _Creature->isQuestGiver() )
    {
        player->PrepareQuestMenu( _Creature->GetGUID() );
        player->SendPreparedQuest(_Creature->GetGUID());
    }

    ScriptedInstance* pInstance = ((ScriptedInstance*)_Creature->GetInstanceData());
    if( pInstance )
    {
        if (pInstance->GetData(TYPE_BARREL_DIVERSION) == DONE && !pInstance->GetData(TYPE_THRALL_EVENT))
        {
            player->ADD_GOSSIP_ITEM( 0, "[PH] Start walking.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            player->SEND_GOSSIP_MENU(GOSSIP_ID_START, _Creature->GetGUID());
        }

        if( pInstance->GetData(TYPE_THRALL_PART1) == DONE && !pInstance->GetData(TYPE_THRALL_PART2) )
        {
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_ITEM_SKARLOC1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
            player->SEND_GOSSIP_MENU(GOSSIP_ID_SKARLOC1, _Creature->GetGUID());
        }

        if( pInstance->GetData(TYPE_THRALL_PART2) == DONE && !pInstance->GetData(TYPE_THRALL_PART3) )
        {
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_ITEM_TARREN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
            player->SEND_GOSSIP_MENU(GOSSIP_ID_TARREN, _Creature->GetGUID());
        }
    }
    return true;
}

bool GossipSelect_npc_thrall_old_hillsbrad(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    ScriptedInstance* pInstance = ((ScriptedInstance*)_Creature->GetInstanceData());
    switch( action )
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            player->CLOSE_GOSSIP_MENU();
            pInstance->SetData(TYPE_THRALL_EVENT,IN_PROGRESS);
            pInstance->SetData(TYPE_THRALL_PART1,IN_PROGRESS);

            DoScriptText(SAY_TH_START_EVENT_PART1, _Creature);

            ((npc_escortAI*)(_Creature->AI()))->Start(true, true, true, player->GetGUID());
            ((npc_escortAI*)(_Creature->AI()))->SetMaxPlayerDistance(100.0f);//not really needed, because it will not despawn if player is too far
            ((npc_escortAI*)(_Creature->AI()))->SetDespawnAtEnd(false);
            ((npc_escortAI*)(_Creature->AI()))->SetDespawnAtFar(false);
            break;

        case GOSSIP_ACTION_INFO_DEF+2:
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_ITEM_SKARLOC2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+20);
            player->SEND_GOSSIP_MENU(GOSSIP_ID_SKARLOC2, _Creature->GetGUID());
            break;

        case GOSSIP_ACTION_INFO_DEF+20:
            player->SEND_GOSSIP_MENU(GOSSIP_ID_SKARLOC3, _Creature->GetGUID());
            _Creature->SummonCreature(SKARLOC_MOUNT,2038.81,270.26,63.20,5.41,TEMPSUMMON_TIMED_DESPAWN,12000);
            pInstance->SetData(TYPE_THRALL_PART2,IN_PROGRESS);

            DoScriptText(SAY_TH_START_EVENT_PART2, _Creature);

            ((npc_thrall_old_hillsbradAI*)_Creature->AI())->StartWP();
            break;

        case GOSSIP_ACTION_INFO_DEF+3:
            player->CLOSE_GOSSIP_MENU();
            pInstance->SetData(TYPE_THRALL_PART3,IN_PROGRESS);
            ((npc_thrall_old_hillsbradAI*)_Creature->AI())->StartWP();
            break;
    }
    return true;
}

/*######
## npc_taretha
######*/

#define GOSSIP_ID_EPOCH1        9610                        //Thank you for helping Thrall escape, friends. Now I only hope
#define GOSSIP_ITEM_EPOCH1      "Strange wizard?"
#define GOSSIP_ID_EPOCH2        9613                        //Yes, friends. This man was no wizard of
#define GOSSIP_ITEM_EPOCH2      "We'll get you out. Taretha. Don't worry. I doubt the wizard would wander too far away."

struct TRINITY_DLL_DECL npc_tarethaAI : public npc_escortAI
{
    npc_tarethaAI(Creature *c) : npc_escortAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
    }

    ScriptedInstance *pInstance;

    void WaypointReached(uint32 i)
    {
        switch( i )
        {
            case 6:
                DoScriptText(SAY_TA_FREE, m_creature);
                break;
            case 7:
                m_creature->HandleEmoteCommand(EMOTE_ONESHOT_CHEER);
                break;
        }
    }
    void Reset() {}
    void EnterCombat(Unit* who) {}

    void UpdateAI(const uint32 diff)
    {
        npc_escortAI::UpdateAI(diff);
    }
};
CreatureAI* GetAI_npc_taretha(Creature *_Creature)
{
    npc_tarethaAI* taretha_walkAI = new npc_tarethaAI(_Creature);

    taretha_walkAI->FillPointMovementListForCreature();

    return (CreatureAI*)taretha_walkAI;
}

bool GossipHello_npc_taretha(Player *player, Creature *_Creature)
{
    ScriptedInstance* pInstance = ((ScriptedInstance*)_Creature->GetInstanceData());
    if( pInstance && pInstance->GetData(TYPE_THRALL_PART3) == DONE && pInstance->GetData(TYPE_THRALL_PART4) == NOT_STARTED)
    {
        player->ADD_GOSSIP_ITEM( 0, GOSSIP_ITEM_EPOCH1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        player->SEND_GOSSIP_MENU(GOSSIP_ID_EPOCH1, _Creature->GetGUID());
    }
    return true;
}

bool GossipSelect_npc_taretha(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    ScriptedInstance* pInstance = ((ScriptedInstance*)_Creature->GetInstanceData());
    if( action == GOSSIP_ACTION_INFO_DEF+1 )
    {
        player->ADD_GOSSIP_ITEM( 0, GOSSIP_ITEM_EPOCH2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
        player->SEND_GOSSIP_MENU(GOSSIP_ID_EPOCH2, _Creature->GetGUID());
    }
    if( action == GOSSIP_ACTION_INFO_DEF+2 )
    {
        player->CLOSE_GOSSIP_MENU();

        if( pInstance->GetData(TYPE_THRALL_EVENT) == IN_PROGRESS )
        {
            pInstance->SetData(TYPE_THRALL_PART4,IN_PROGRESS);
            if(pInstance->GetData64(DATA_EPOCH) == 0)
                 _Creature->SummonCreature(ENTRY_EPOCH,2639.13,698.55,65.43,4.59,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,120000);

             if (uint64 ThrallGUID = pInstance->GetData64(DATA_THRALL))
             {
                 Creature* Thrall = (Unit::GetCreature((*_Creature), ThrallGUID));
                 if(Thrall)
                     ((npc_thrall_old_hillsbradAI*)Thrall->AI())->StartWP();
             }
        }
    }
    return true;
}

/*######
## AddSC
######*/

void AddSC_old_hillsbrad()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="npc_brazen";
    newscript->pGossipHello =   &GossipHello_npc_brazen;
    newscript->pGossipSelect =  &GossipSelect_npc_brazen;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_erozion";
    newscript->pGossipHello =   &GossipHello_npc_erozion;
    newscript->pGossipSelect =  &GossipSelect_npc_erozion;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_thrall_old_hillsbrad";
    newscript->pGossipHello =  &GossipHello_npc_thrall_old_hillsbrad;
    newscript->pGossipSelect = &GossipSelect_npc_thrall_old_hillsbrad;
    newscript->GetAI = &GetAI_npc_thrall_old_hillsbrad;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_taretha";
    newscript->pGossipHello =   &GossipHello_npc_taretha;
    newscript->pGossipSelect =  &GossipSelect_npc_taretha;
    newscript->GetAI = &GetAI_npc_taretha;
    newscript->RegisterSelf();
}

