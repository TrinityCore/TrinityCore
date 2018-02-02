/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "old_hillsbrad.h"
#include "Map.h"
#include "Player.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"

enum Erozion
{
    QUEST_ENTRY_HILLSBRAD   = 10282,
    QUEST_ENTRY_DIVERSION   = 10283,
    QUEST_ENTRY_ESCAPE      = 10284,
    QUEST_ENTRY_RETURN      = 10285,
    ITEM_ENTRY_BOMBS        = 25853
};
#define GOSSIP_HELLO_EROZION1   "I need a pack of Incendiary Bombs."
#define GOSSIP_HELLO_EROZION2   "[PH] Teleport please, i'm tired."

/*######
## npc_erozion
######*/

class npc_erozion : public CreatureScript
{
public:
    npc_erozion() : CreatureScript("npc_erozion") { }

    struct npc_erozionAI : public ScriptedAI
    {
        npc_erozionAI(Creature* creature) : ScriptedAI(creature), instance(creature->GetInstanceScript()) { }

        InstanceScript* instance;

        bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            ClearGossipMenuFor(player);
            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                ItemPosCountVec dest;
                uint8 msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, ITEM_ENTRY_BOMBS, 1);
                if (msg == EQUIP_ERR_OK)
                {
                    player->StoreNewItem(dest, ITEM_ENTRY_BOMBS, true);
                }
                SendGossipMenuFor(player, 9515, me->GetGUID());
            }
            if (action == GOSSIP_ACTION_INFO_DEF + 2)
                CloseGossipMenuFor(player);
            return true;
        }

        bool GossipHello(Player* player) override
        {
            if (me->IsQuestGiver())
                player->PrepareQuestMenu(me->GetGUID());

            if (instance->GetData(TYPE_BARREL_DIVERSION) != DONE && !player->HasItemCount(ITEM_ENTRY_BOMBS))
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_HELLO_EROZION1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

            if (player->GetQuestStatus(QUEST_ENTRY_RETURN) == QUEST_STATUS_COMPLETE)
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_HELLO_EROZION2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

            SendGossipMenuFor(player, 9778, me->GetGUID());

            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetOldHillsbradAI<npc_erozionAI>(creature);
    }
};

/*######
## npc_thrall_old_hillsbrad
######*/

//Thrall texts
enum ThrallOldHillsbrad
{
    SAY_TH_START_EVENT_PART1    = 0,
    SAY_TH_ARMORY               = 1,
    SAY_TH_SKARLOC_MEET         = 2,
    SAY_TH_SKARLOC_TAUNT        = 3,
    SAY_TH_START_EVENT_PART2    = 4,
    SAY_TH_MOUNTS_UP            = 5,
    SAY_TH_CHURCH_END           = 6,
    SAY_TH_MEET_TARETHA         = 7,
    SAY_TH_EPOCH_WONDER         = 8,
    SAY_TH_EPOCH_KILL_TARETHA   = 9,
    SAY_TH_EVENT_COMPLETE       = 10,

    SAY_TH_RANDOM_LOW_HP        = 11,
    SAY_TH_RANDOM_DIE           = 12,
    SAY_TH_RANDOM_AGGRO         = 13,
    SAY_TH_RANDOM_KILL          = 14,
    SAY_TH_LEAVE_COMBAT         = 15,

    //Taretha texts
    SAY_TA_FREE                 = 0,
    SAY_TA_ESCAPED              = 1,

    //Misc for Thrall
    SPELL_STRIKE                = 14516,
    SPELL_SHIELD_BLOCK          = 12169,
    SPELL_SUMMON_EROZION_IMAGE  = 33954,                   //if thrall dies during escort?

    THRALL_WEAPON_ITEM          = 927,
    THRALL_WEAPON_INFO          = 218169346,
    THRALL_SHIELD_ITEM          = 2129,
    THRALL_SHIELD_INFO          = 234948100,
    THRALL_MODEL_UNEQUIPPED     = 17292,
    THRALL_MODEL_EQUIPPED       = 18165,

    //Misc Creature entries
    ENTRY_ARMORER               = 18764,
    ENTRY_SCARLOC               = 17862,

    NPC_RIFLE                   = 17820,
    NPC_WARDEN                  = 17833,
    NPC_VETERAN                 = 17860,
    NPC_WATCHMAN                = 17814,
    NPC_SENTRY                  = 17815,

    NPC_BARN_GUARDSMAN          = 18092,
    NPC_BARN_PROTECTOR          = 18093,
    NPC_BARN_LOOKOUT            = 18094,

    NPC_CHURCH_GUARDSMAN        = 23175,
    NPC_CHURCH_PROTECTOR        = 23179,
    NPC_CHURCH_LOOKOUT          = 23177,

    NPC_INN_GUARDSMAN           = 23176,
    NPC_INN_PROTECTOR           = 23180,
    NPC_INN_LOOKOUT             = 23178,

    SKARLOC_MOUNT               = 18798,
    SKARLOC_MOUNT_MODEL         = 18223,
    EROZION_ENTRY               = 18723,
    ENTRY_EPOCH                 = 18096,

    GOSSIP_ID_START             = 9568,
    GOSSIP_ID_SKARLOC1          = 9614,                        //I'm glad Taretha is alive. We now must find a way to free her...
    GOSSIP_ID_SKARLOC2          = 9579,                        //What do you mean by this? Is Taretha in danger?
    GOSSIP_ID_SKARLOC3          = 9580,
    GOSSIP_ID_TARREN            = 9597,                        //tarren mill is beyond these trees
    GOSSIP_ID_COMPLETE          = 9578                         //Thank you friends, I owe my freedom to you. Where is Taretha? I hoped to see her
};

#define SPEED_WALK              (0.5f)
#define SPEED_RUN               (1.0f)
#define SPEED_MOUNT             (1.6f)

//gossip items
#define GOSSIP_ITEM_SKARLOC1    "Taretha cannot see you, Thrall."
#define GOSSIP_ITEM_SKARLOC2    "The situation is rather complicated, Thrall. It would be best for you to head into the mountains now, before more of Blackmoore's men show up. We'll make sure Taretha is safe."
#define GOSSIP_ITEM_TARREN      "We're ready, Thrall."
#define GOSSIP_ITEM_WALKING     "[PH] Start walking."

class npc_thrall_old_hillsbrad : public CreatureScript
{
public:
    npc_thrall_old_hillsbrad() : CreatureScript("npc_thrall_old_hillsbrad") { }

    struct npc_thrall_old_hillsbradAI : public EscortAI
    {
        npc_thrall_old_hillsbradAI(Creature* creature) : EscortAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
            HadMount = false;
            me->setActive(true);
        }

        void Initialize()
        {
            LowHp = false;
        }

        InstanceScript* instance;

        bool LowHp;
        bool HadMount;

        void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
        {
            switch (waypointId)
            {
                case 8:
                    SetRun(false);
                    me->SummonCreature(18764, 2181.87f, 112.46f, 89.45f, 0.26f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    break;
                case 9:
                    Talk(SAY_TH_ARMORY);
                    me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, THRALL_WEAPON_ITEM);
                    //me->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO, THRALL_WEAPON_INFO);
                    //me->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO+1, 781);
                    me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID+1, THRALL_SHIELD_ITEM);
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
                    me->SummonCreature(NPC_RIFLE, 2200.28f, 137.37f, 87.93f, 5.07f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    me->SummonCreature(NPC_WARDEN, 2197.44f, 131.83f, 87.93f, 0.78f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    me->SummonCreature(NPC_VETERAN, 2203.62f, 135.40f, 87.93f, 3.70f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    me->SummonCreature(NPC_VETERAN, 2200.75f, 130.13f, 87.93f, 1.48f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    break;
                case 21:
                    me->SummonCreature(NPC_RIFLE, 2135.80f, 154.01f, 67.45f, 4.98f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    me->SummonCreature(NPC_WARDEN, 2144.36f, 151.87f, 67.74f, 4.46f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    me->SummonCreature(NPC_VETERAN, 2142.12f, 154.41f, 67.12f, 4.56f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    me->SummonCreature(NPC_VETERAN, 2138.08f, 155.38f, 67.24f, 4.60f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    break;
                case 25:
                    me->SummonCreature(NPC_RIFLE, 2102.98f, 192.17f, 65.24f, 6.02f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    me->SummonCreature(NPC_WARDEN, 2108.48f, 198.75f, 65.18f, 5.15f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    me->SummonCreature(NPC_VETERAN, 2106.11f, 197.29f, 65.18f, 5.63f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    me->SummonCreature(NPC_VETERAN, 2104.18f, 194.82f, 65.18f, 5.75f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    break;
                case 29:
                    Talk(SAY_TH_SKARLOC_MEET);
                    me->SummonCreature(ENTRY_SCARLOC, 2036.48f, 271.22f, 63.43f, 5.27f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                    //temporary, skarloc should rather be triggered to walk up to thrall
                    break;
                case 30:
                    SetEscortPaused(true);
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    SetRun(false);
                    break;
                case 31:
                    Talk(SAY_TH_MOUNTS_UP);
                    DoMount();
                    SetRun();
                    break;
                case 37:
                    //possibly regular patrollers? If so, remove this and let database handle them
                    me->SummonCreature(NPC_WATCHMAN, 2124.26f, 522.16f, 56.87f, 3.99f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    me->SummonCreature(NPC_WATCHMAN, 2121.69f, 525.37f, 57.11f, 4.01f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    me->SummonCreature(NPC_SENTRY, 2124.65f, 524.55f, 56.63f, 3.98f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    break;
                case 59:
                    me->SummonCreature(SKARLOC_MOUNT, 2488.64f, 625.77f, 58.26f, 4.71f, TEMPSUMMON_TIMED_DESPAWN, 10000);
                    DoUnmount();
                    HadMount = false;
                    SetRun(false);
                    break;
                case 60:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                    //make horsie run off
                    SetEscortPaused(true);
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    instance->SetData(TYPE_THRALL_PART2, DONE);
                    SetRun();
                    break;
                case 64:
                    SetRun(false);
                    break;
                case 68:
                    me->SummonCreature(NPC_BARN_PROTECTOR, 2500.22f, 692.60f, 55.50f, 2.84f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    me->SummonCreature(NPC_BARN_LOOKOUT, 2500.13f, 696.55f, 55.51f, 3.38f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    me->SummonCreature(NPC_BARN_GUARDSMAN, 2500.55f, 693.64f, 55.50f, 3.14f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    me->SummonCreature(NPC_BARN_GUARDSMAN, 2500.94f, 695.81f, 55.50f, 3.14f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    break;
                case 71:
                    SetRun();
                    break;
                case 81:
                    SetRun(false);
                    break;
                case 83:
                    me->SummonCreature(NPC_CHURCH_PROTECTOR, 2627.33f, 646.82f, 56.03f, 4.28f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 5000);
                    me->SummonCreature(NPC_CHURCH_LOOKOUT, 2624.14f, 648.03f, 56.03f, 4.50f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 5000);
                    me->SummonCreature(NPC_CHURCH_GUARDSMAN, 2625.32f, 649.60f, 56.03f, 4.38f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 5000);
                    me->SummonCreature(NPC_CHURCH_GUARDSMAN, 2627.22f, 649.00f, 56.03f, 4.34f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 5000);
                    break;
                case 84:
                    Talk(SAY_TH_CHURCH_END);
                    SetRun();
                    break;
                case 91:
                    me->SetWalk(true);
                    SetRun(false);
                    break;
                case 93:
                    me->SummonCreature(NPC_INN_PROTECTOR, 2652.71f, 660.31f, 61.93f, 1.67f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    me->SummonCreature(NPC_INN_LOOKOUT, 2648.96f, 662.59f, 61.93f, 0.79f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    me->SummonCreature(NPC_INN_GUARDSMAN, 2657.36f, 662.34f, 61.93f, 2.68f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    me->SummonCreature(NPC_INN_GUARDSMAN, 2656.39f, 659.77f, 61.93f, 2.61f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    break;
                case 94:
                    if (Creature* Taretha = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_TARETHA)))
                        Taretha->AI()->Talk(SAY_TA_ESCAPED, me);
                    break;
                case 95:
                    Talk(SAY_TH_MEET_TARETHA);
                    instance->SetData(TYPE_THRALL_PART3, DONE);
                    SetEscortPaused(true);
                    break;
                case 96:
                    Talk(SAY_TH_EPOCH_WONDER);
                    break;
                case 97:
                    Talk(SAY_TH_EPOCH_KILL_TARETHA);
                    SetRun();
                    break;
                case 98:
                    //trigger epoch Yell("Thrall! Come outside and face your fate! ....")
                    //from here, thrall should not never be allowed to move to point 106 which he currently does.
                    break;
                case 106:
                    {
                        //trigger taretha to run down outside
                        if (Creature* Taretha = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_TARETHA)))
                        {
                            if (Player* player = GetPlayerForEscort())
                                ENSURE_AI(EscortAI, (Taretha->AI()))->Start(false, true, player->GetGUID());
                        }

                        //kill credit Creature for quest
                        Map::PlayerList const& players = me->GetMap()->GetPlayers();
                        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        {
                            if (Player* player = itr->GetSource())
                                player->KilledMonsterCredit(20156);
                        }

                        //alot will happen here, thrall and taretha talk, erozion appear at spot to explain
                        me->SummonCreature(EROZION_ENTRY, 2646.47f, 680.416f, 55.38f, 4.16f, TEMPSUMMON_TIMED_DESPAWN, 120000);
                    }
                    break;
                case 108:
                    //last waypoint, just set Thrall invisible, respawn is turned off
                    me->SetVisible(false);
                    break;
            }
        }

        void Reset() override
        {
            Initialize();

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
                Talk(SAY_TH_LEAVE_COMBAT);
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
            me->SetSpeedRate(MOVE_RUN, SPEED_MOUNT);
        }
        void DoUnmount()
        {
            me->Dismount();
            me->SetSpeedRate(MOVE_RUN, SPEED_RUN);
        }
        void JustEngagedWith(Unit* /*who*/) override
        {
            Talk(SAY_TH_RANDOM_AGGRO);
            if (me->IsMounted())
            {
                DoUnmount();
                HadMount = true;
            }
        }

        void JustSummoned(Creature* summoned) override
        {
             switch (summoned->GetEntry())
             {
            /// @todo make Scarloc start into event instead, and not start attack directly
             case NPC_BARN_GUARDSMAN:
             case NPC_BARN_PROTECTOR:
             case NPC_BARN_LOOKOUT:
             case SKARLOC_MOUNT:
             case EROZION_ENTRY:
                 break;
             default:
                 summoned->AI()->AttackStart(me);
                 break;
             }
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(SAY_TH_RANDOM_KILL);
        }
        void JustDied(Unit* slayer) override
        {
            instance->SetData(TYPE_THRALL_EVENT, FAIL);

            // Don't do a yell if he kills self (if player goes too far or at the end).
            if (slayer == me)
                return;

            Talk(SAY_TH_RANDOM_DIE);
        }

        void UpdateAI(uint32 diff) override
        {
            EscortAI::UpdateAI(diff);

            if (!UpdateVictim())
                return;

            /// @todo add his abilities'n-crap here
            if (!LowHp && HealthBelowPct(20))
            {
                Talk(SAY_TH_RANDOM_LOW_HP);
                LowHp = true;
            }
        }

        bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            ClearGossipMenuFor(player);
            switch (action)
            {
                case GOSSIP_ACTION_INFO_DEF + 1:
                    CloseGossipMenuFor(player);
                    instance->SetData(TYPE_THRALL_EVENT, IN_PROGRESS);
                    instance->SetData(TYPE_THRALL_PART1, IN_PROGRESS);

                    Talk(SAY_TH_START_EVENT_PART1);

                    Start(true, true, player->GetGUID());

                    SetMaxPlayerDistance(100.0f);//not really needed, because it will not despawn if player is too far
                    SetDespawnAtEnd(false);
                    SetDespawnAtFar(false);
                    break;

                case GOSSIP_ACTION_INFO_DEF + 2:
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_SKARLOC2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 20);
                    SendGossipMenuFor(player, GOSSIP_ID_SKARLOC2, me->GetGUID());
                    break;

                case GOSSIP_ACTION_INFO_DEF + 20:
                    SendGossipMenuFor(player, GOSSIP_ID_SKARLOC3, me->GetGUID());
                    me->SummonCreature(SKARLOC_MOUNT, 2038.81f, 270.26f, 63.20f, 5.41f, TEMPSUMMON_TIMED_DESPAWN, 12000);
                    instance->SetData(TYPE_THRALL_PART2, IN_PROGRESS);

                    Talk(SAY_TH_START_EVENT_PART2);

                    StartWP();
                    break;

                case GOSSIP_ACTION_INFO_DEF + 3:
                    CloseGossipMenuFor(player);
                    instance->SetData(TYPE_THRALL_PART3, IN_PROGRESS);
                    StartWP();
                    break;
            }
            return true;
        }

        bool GossipHello(Player* player) override
        {
            if (me->IsQuestGiver())
            {
                player->PrepareQuestMenu(me->GetGUID());
                player->SendPreparedQuest(me->GetGUID());
            }

            if (instance->GetData(TYPE_BARREL_DIVERSION) == DONE && !instance->GetData(TYPE_THRALL_EVENT))
            {
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_WALKING, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                SendGossipMenuFor(player, GOSSIP_ID_START, me->GetGUID());
            }

            if (instance->GetData(TYPE_THRALL_PART1) == DONE && !instance->GetData(TYPE_THRALL_PART2))
            {
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_SKARLOC1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                SendGossipMenuFor(player, GOSSIP_ID_SKARLOC1, me->GetGUID());
            }

            if (instance->GetData(TYPE_THRALL_PART2) == DONE && !instance->GetData(TYPE_THRALL_PART3))
            {
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_TARREN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                SendGossipMenuFor(player, GOSSIP_ID_TARREN, me->GetGUID());
            }
            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetOldHillsbradAI<npc_thrall_old_hillsbradAI>(creature);
    }
};

/*######
## npc_taretha
######*/
enum Taretha
{
    GOSSIP_ID_EPOCH1        = 9610,                        //Thank you for helping Thrall escape, friends. Now I only hope
    GOSSIP_ID_EPOCH2        = 9613                        //Yes, friends. This man was no wizard of
};

#define GOSSIP_ITEM_EPOCH1      "Strange wizard?"
#define GOSSIP_ITEM_EPOCH2      "We'll get you out. Taretha. Don't worry. I doubt the wizard would wander too far away."

class npc_taretha : public CreatureScript
{
public:
    npc_taretha() : CreatureScript("npc_taretha") { }

    struct npc_tarethaAI : public EscortAI
    {
        npc_tarethaAI(Creature* creature) : EscortAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
        {
            switch (waypointId)
            {
                case 6:
                    Talk(SAY_TA_FREE);
                    break;
                case 7:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_CHEER);
                    break;
            }
        }

        void Reset() override { }
        void JustEngagedWith(Unit* /*who*/) override { }

        void UpdateAI(uint32 diff) override
        {
            EscortAI::UpdateAI(diff);
        }

        bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            ClearGossipMenuFor(player);

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_EPOCH2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                SendGossipMenuFor(player, GOSSIP_ID_EPOCH2, me->GetGUID());
            }
            if (action == GOSSIP_ACTION_INFO_DEF + 2)
            {
                CloseGossipMenuFor(player);

                if (instance->GetData(TYPE_THRALL_EVENT) == IN_PROGRESS)
                {
                    instance->SetData(TYPE_THRALL_PART4, IN_PROGRESS);
                    if (instance->GetGuidData(DATA_EPOCH).IsEmpty())
                        me->SummonCreature(ENTRY_EPOCH, 2639.13f, 698.55f, 65.43f, 4.59f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 120000);

                    if (Creature* thrall = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_THRALL)))
                        ENSURE_AI(npc_thrall_old_hillsbrad::npc_thrall_old_hillsbradAI, thrall->AI())->StartWP();
                }
            }
            return true;
        }

        bool GossipHello(Player* player) override
        {
            if (instance->GetData(TYPE_THRALL_PART3) == DONE && instance->GetData(TYPE_THRALL_PART4) == NOT_STARTED)
            {
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_EPOCH1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                SendGossipMenuFor(player, GOSSIP_ID_EPOCH1, me->GetGUID());
            }
            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetOldHillsbradAI<npc_tarethaAI>(creature);
    }
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
