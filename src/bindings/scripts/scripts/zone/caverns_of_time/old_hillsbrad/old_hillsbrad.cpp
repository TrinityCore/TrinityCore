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
                m_creature->AddUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                m_creature->SummonCreature(18764,2181.87,112.46,89.45,0.26,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                break;
            case 9:
                DoScriptText(SAY_TH_ARMORY, m_creature);
                m_creature->AddUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                m_creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_DISPLAY, THRALL_WEAPON_MODEL);
                m_creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO, THRALL_WEAPON_INFO);
                m_creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO+1, 781);
                m_creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_DISPLAY+1, THRALL_SHIELD_MODEL);
                m_creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO+2, THRALL_SHIELD_INFO);
                m_creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO+3, 1038);
                break;
            case 10:
                m_creature->SetUInt32Value(UNIT_FIELD_DISPLAYID, THRALL_MODEL_EQUIPPED);
                break;
            case 11:
                m_creature->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
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
                m_creature->AddUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                break;
            case 31:
                DoScriptText(SAY_TH_MOUNTS_UP, m_creature);
                m_creature->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                DoMount();
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
                break;
            case 60:
                m_creature->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                //make horsie run off
                IsOnHold = true;
                m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                pInstance->SetData(TYPE_THRALL_PART2, DONE);
                break;
            case 64:
                m_creature->AddUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                break;
            case 68:
                m_creature->SummonCreature(MOB_ENTRY_BARN_PROTECTOR,2500.22,692.60,55.50,2.84,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                m_creature->SummonCreature(MOB_ENTRY_BARN_LOOKOUT,2500.13,696.55,55.51,3.38,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                m_creature->SummonCreature(MOB_ENTRY_BARN_GUARDSMAN,2500.55,693.64,55.50,3.14,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                m_creature->SummonCreature(MOB_ENTRY_BARN_GUARDSMAN,2500.94,695.81,55.50,3.14,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                break;
            case 71:
                m_creature->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                break;
            case 81:
                m_creature->AddUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                break;
            case 83:
                m_creature->SummonCreature(MOB_ENTRY_CHURCH_PROTECTOR,2627.33,646.82,56.03,4.28,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,5000);
                m_creature->SummonCreature(MOB_ENTRY_CHURCH_LOOKOUT,2624.14,648.03,56.03,4.50,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,5000);
                m_creature->SummonCreature(MOB_ENTRY_CHURCH_GUARDSMAN,2625.32,649.60,56.03,4.38,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,5000);
                m_creature->SummonCreature(MOB_ENTRY_CHURCH_GUARDSMAN,2627.22,649.00,56.03,4.34,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,5000);
                break;
            case 84:
                DoScriptText(SAY_TH_CHURCH_END, m_creature);
                break;
            case 91:
                m_creature->AddUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                break;
            case 93:
                m_creature->SummonCreature(MOB_ENTRY_INN_PROTECTOR,2652.71,660.31,61.93,1.67,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                m_creature->SummonCreature(MOB_ENTRY_INN_LOOKOUT,2648.96,662.59,61.93,0.79,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                m_creature->SummonCreature(MOB_ENTRY_INN_GUARDSMAN,2657.36,662.34,61.93,2.68,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                m_creature->SummonCreature(MOB_ENTRY_INN_GUARDSMAN,2656.39,659.77,61.93,2.61,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,5000);
                break;
            case 94:
                m_creature->AddUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
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
                 m_creature->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                break;
            case 97:
                DoScriptText(SAY_TH_EPOCH_KILL_TARETHA, m_creature);
                m_creature->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                m_creature->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
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
            m_creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_DISPLAY, 0);
            m_creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO, 0);
            m_creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO+1, 0);
            m_creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_DISPLAY+1, 0);
            m_creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO+2, 0);
            m_creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO+3, 0);
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
        m_creature->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
    }
    void DoUnmount()
    {
        m_creature->Unmount();
        m_creature->SetSpeed(MOVE_RUN,SPEED_RUN);
    }
    void Aggro(Unit* who)
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

    thrall_walkAI->AddWaypoint(0, 2230.91, 118.765, 82.2947,5000);
    thrall_walkAI->AddWaypoint(1, 2230.33, 114.980, 82.2946);
    thrall_walkAI->AddWaypoint(2, 2233.36, 111.057, 82.2996);
    thrall_walkAI->AddWaypoint(3, 2231.17, 108.486, 82.6624);
    thrall_walkAI->AddWaypoint(4, 2220.22, 114.605, 89.4264);
    thrall_walkAI->AddWaypoint(5, 2215.23, 115.990, 89.4549);
    thrall_walkAI->AddWaypoint(6, 2210.00, 106.849, 89.4549);
    thrall_walkAI->AddWaypoint(7, 2205.66, 105.234, 89.4549);
                                                            //spawn armorer
    thrall_walkAI->AddWaypoint(8, 2192.26, 112.618, 89.4549);

                                                            //get weapon
    thrall_walkAI->AddWaypoint(9, 2181.28, 118.612, 89.4549,8000);
                                                            //get armor
    thrall_walkAI->AddWaypoint(10, 2181.62, 120.385, 89.4549,5000);

    thrall_walkAI->AddWaypoint(11, 2189.44, 113.922, 89.4549);
    thrall_walkAI->AddWaypoint(12, 2195.63, 110.584, 89.4549);
    thrall_walkAI->AddWaypoint(13, 2201.09, 115.115, 89.4549);
    thrall_walkAI->AddWaypoint(14, 2204.34, 121.036, 89.4355);
                                                            //first ambush
    thrall_walkAI->AddWaypoint(15, 2208.66, 129.127, 87.9560);
    thrall_walkAI->AddWaypoint(16, 2193.09, 137.940, 88.2164);
    thrall_walkAI->AddWaypoint(17, 2173.39, 149.064, 87.9227);
    thrall_walkAI->AddWaypoint(18, 2164.25, 137.965, 85.0595);
    thrall_walkAI->AddWaypoint(19, 2149.31, 125.645, 77.0858);
    thrall_walkAI->AddWaypoint(20, 2142.78, 127.173, 75.5954);
                                                            //second ambush
    thrall_walkAI->AddWaypoint(21, 2139.28, 133.952, 73.6386);
    thrall_walkAI->AddWaypoint(22, 2139.54, 155.235, 67.1269);
    thrall_walkAI->AddWaypoint(23, 2145.38, 167.551, 64.8974);
    thrall_walkAI->AddWaypoint(24, 2134.28, 175.304, 67.9446);
    thrall_walkAI->AddWaypoint(25, 2118.08, 187.387, 68.8141);
                                                            //third ambush
    thrall_walkAI->AddWaypoint(26, 2105.88, 195.461, 65.1854);
    thrall_walkAI->AddWaypoint(27, 2096.77, 196.939, 65.2117);
    thrall_walkAI->AddWaypoint(28, 2083.90, 209.395, 64.8736);
                                                            //in front of keeps gate, meeting scarloc
    thrall_walkAI->AddWaypoint(29, 2067.84, 224.376, 64.8022,30000);

                                                            //ref point after skarloc fight
    thrall_walkAI->AddWaypoint(30, 2055.40, 242.90, 63.3418);

                                                            //mount up!
    thrall_walkAI->AddWaypoint(31, 2039.20, 266.460, 63.0182,10000);
    thrall_walkAI->AddWaypoint(32, 2011.77, 278.478, 65.3388);
    thrall_walkAI->AddWaypoint(33, 2005.08, 289.676, 66.1179);
    thrall_walkAI->AddWaypoint(34, 2033.11, 337.450, 66.0948);
    thrall_walkAI->AddWaypoint(35, 2070.30, 416.208, 66.0893);
    thrall_walkAI->AddWaypoint(36, 2086.76, 469.768, 65.9182);
                                                            //possible road ambush
    thrall_walkAI->AddWaypoint(37, 2101.70, 497.955, 61.7881);

    thrall_walkAI->AddWaypoint(38, 2133.39, 530.933, 55.3700,5000);
    thrall_walkAI->AddWaypoint(39, 2157.91, 559.635, 48.5157);
    thrall_walkAI->AddWaypoint(40, 2167.34, 586.191, 42.4394);
    thrall_walkAI->AddWaypoint(41, 2174.17, 637.643, 33.9002);
    thrall_walkAI->AddWaypoint(42, 2179.31, 656.053, 34.723);
    thrall_walkAI->AddWaypoint(43, 2183.65, 670.941, 34.0318);
    thrall_walkAI->AddWaypoint(44, 2201.50, 668.616, 36.1236);
    thrall_walkAI->AddWaypoint(45, 2221.56, 652.747, 36.6153);
    thrall_walkAI->AddWaypoint(46, 2238.97, 640.125, 37.2214);
    thrall_walkAI->AddWaypoint(47, 2251.17, 620.574, 40.1473);
    thrall_walkAI->AddWaypoint(48, 2261.98, 595.303, 41.4117);
    thrall_walkAI->AddWaypoint(49, 2278.67, 560.172, 38.9090);
    thrall_walkAI->AddWaypoint(50, 2336.72, 528.327, 40.9369);
    thrall_walkAI->AddWaypoint(51, 2381.04, 519.612, 37.7312);
    thrall_walkAI->AddWaypoint(52, 2412.20, 515.425, 39.2068);
    thrall_walkAI->AddWaypoint(53, 2452.39, 516.174, 42.9387);
    thrall_walkAI->AddWaypoint(54, 2467.38, 539.389, 47.4992);
    thrall_walkAI->AddWaypoint(55, 2470.70, 554.333, 46.6668);
    thrall_walkAI->AddWaypoint(56, 2478.07, 575.321, 55.4549);
    thrall_walkAI->AddWaypoint(57, 2480.00, 585.408, 56.6921);
    thrall_walkAI->AddWaypoint(58, 2482.67, 608.817, 55.6643);
                                                            //demount
    thrall_walkAI->AddWaypoint(59, 2485.62, 626.061, 58.0132,2000);
                                                            //scare the shit out of horse, so it'll run off
    thrall_walkAI->AddWaypoint(60, 2486.91, 626.356, 58.0761);

    thrall_walkAI->AddWaypoint(61, 2488.58, 660.940, 57.3913);
    thrall_walkAI->AddWaypoint(62, 2502.56, 686.059, 55.6252);
    thrall_walkAI->AddWaypoint(63, 2502.08, 694.360, 55.5083);
    thrall_walkAI->AddWaypoint(64, 2491.46, 694.321, 55.7163);
    thrall_walkAI->AddWaypoint(65, 2491.10, 703.300, 55.7630);
    thrall_walkAI->AddWaypoint(66, 2485.64, 702.992, 55.7917);

    thrall_walkAI->AddWaypoint(67, 2479.10, 695.291, 55.7901,10000);
                                                            //spawn mobs
    thrall_walkAI->AddWaypoint(68, 2476.75, 693.689, 55.7960);
    thrall_walkAI->AddWaypoint(69, 2475.39, 695.983, 55.8146);
    thrall_walkAI->AddWaypoint(70, 2477.75, 694.473, 55.7945);
                                                            //meet mobs in doorway
    thrall_walkAI->AddWaypoint(71, 2481.27, 697.747, 55.7910);

    thrall_walkAI->AddWaypoint(72, 2486.31, 703.131, 55.7861,5000);
    thrall_walkAI->AddWaypoint(73, 2490.76, 703.511, 55.7662);
    thrall_walkAI->AddWaypoint(74, 2491.30, 694.792, 55.7195);
    thrall_walkAI->AddWaypoint(75, 2518.69, 693.876, 55.1383);
    thrall_walkAI->AddWaypoint(76, 2531.33, 681.914, 55.1383);
    thrall_walkAI->AddWaypoint(77, 2568.25, 682.654, 55.1778);
    thrall_walkAI->AddWaypoint(78, 2589.61, 689.981, 55.1421);
    thrall_walkAI->AddWaypoint(79, 2634.74, 679.833, 54.6613);
    thrall_walkAI->AddWaypoint(80, 2630.41, 661.464, 54.2761);
    thrall_walkAI->AddWaypoint(81, 2629.00, 656.982, 56.0651);
                                                            //stop in church
    thrall_walkAI->AddWaypoint(82, 2620.84, 633.007, 56.0300,3000);
                                                            //summon
    thrall_walkAI->AddWaypoint(83, 2622.99, 639.178, 56.0300);

    thrall_walkAI->AddWaypoint(84, 2628.73, 656.693, 56.0610,5000);
    thrall_walkAI->AddWaypoint(85, 2630.34, 661.135, 54.2738);
    thrall_walkAI->AddWaypoint(86, 2635.38, 672.243, 54.4508);
    thrall_walkAI->AddWaypoint(87, 2644.13, 668.158, 55.3797);
    thrall_walkAI->AddWaypoint(88, 2646.82, 666.740, 56.9898);
    thrall_walkAI->AddWaypoint(89, 2658.22, 665.432, 57.1725);
    thrall_walkAI->AddWaypoint(90, 2661.88, 674.849, 57.1725);
    thrall_walkAI->AddWaypoint(91, 2656.23, 677.208, 57.1725);

    thrall_walkAI->AddWaypoint(92, 2652.28, 670.270, 61.9353);
                                                            //summon inn
    thrall_walkAI->AddWaypoint(93, 2650.79, 664.290, 61.9302);
    thrall_walkAI->AddWaypoint(94, 2658.19, 660.454, 61.9320,5000);
                                                            //speak with Taretha
    thrall_walkAI->AddWaypoint(95, 2660.57, 659.173, 61.9370);

                                                            //epoch calls
    thrall_walkAI->AddWaypoint(96, 2658.19, 660.454, 61.9320,5000);
                                                            //taretha "dies"
    thrall_walkAI->AddWaypoint(97, 2659.84, 659.482, 61.9361,5000);

    thrall_walkAI->AddWaypoint(98, 2654.28, 662.722, 61.9313);
    thrall_walkAI->AddWaypoint(99, 2652.37, 670.561, 61.9368);
    thrall_walkAI->AddWaypoint(100, 2656.05, 676.761, 57.1727);
    thrall_walkAI->AddWaypoint(101, 2658.49, 677.166, 57.1727);
    thrall_walkAI->AddWaypoint(102, 2659.28, 667.117, 57.1727);
    thrall_walkAI->AddWaypoint(103, 2649.71, 665.387, 57.1727);
                                                            //he's outside inn here
    thrall_walkAI->AddWaypoint(104, 2634.79, 672.964, 54.4577);

                                                            //getting ready here, must start attack before 30secs up
    thrall_walkAI->AddWaypoint(105, 2635.06, 673.892, 54.4713,30000);

                                                            //ref point, will move here when all dead and meet Taretha
    thrall_walkAI->AddWaypoint(106, 2634.79, 672.964, 54.4577,60000);

                                                            //run off
    thrall_walkAI->AddWaypoint(107, 2631.72, 665.629, 54.2923);
    thrall_walkAI->AddWaypoint(108, 2647.40, 640.530, 55.7634);

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
            if(pInstance)
            {
                pInstance->SetData(TYPE_THRALL_EVENT,IN_PROGRESS);
                pInstance->SetData(TYPE_THRALL_PART1,IN_PROGRESS);
            }

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
            if(pInstance)
                pInstance->SetData(TYPE_THRALL_PART2,IN_PROGRESS);

            DoScriptText(SAY_TH_START_EVENT_PART2, _Creature);

            ((npc_thrall_old_hillsbradAI*)_Creature->AI())->StartWP();
            break;

        case GOSSIP_ACTION_INFO_DEF+3:
            player->CLOSE_GOSSIP_MENU();
            if(pInstance)
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
    void Aggro(Unit* who) {}

    void UpdateAI(const uint32 diff)
    {
        npc_escortAI::UpdateAI(diff);
    }
};
CreatureAI* GetAI_npc_taretha(Creature *_Creature)
{
    npc_tarethaAI* taretha_walkAI = new npc_tarethaAI(_Creature);

    taretha_walkAI->AddWaypoint(0, 2650.06, 665.473, 61.9305);
    taretha_walkAI->AddWaypoint(1, 2652.44, 670.761, 61.9370);
    taretha_walkAI->AddWaypoint(2, 2655.96, 676.913, 57.1725);
    taretha_walkAI->AddWaypoint(3, 2659.40, 677.317, 57.1725);
    taretha_walkAI->AddWaypoint(4, 2651.75, 664.482, 57.1725);
    taretha_walkAI->AddWaypoint(5, 2647.49, 666.595, 57.0824);
    taretha_walkAI->AddWaypoint(6, 2644.37, 668.167, 55.4182);
    taretha_walkAI->AddWaypoint(7, 2640.96, 669.890, 54.7567,60000);

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
            if(pInstance)
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

