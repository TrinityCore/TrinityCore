/*
 * Copyright (C) 2022 BfaCore Reforged
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "SpellScript.h"
#include "SpellMgr.h"
#include "Scenario.h"
#include "InstanceScenario.h"
#include "Player.h"
#include "QuestPackets.h"
#include "ScenePackets.h"
#include "GameObjectAI.h"
#include "ObjectAccessor.h"
#include "SpellAuras.h"
#include "LFGMgr.h"
#include "MotionMaster.h"
#include "ObjectMgr.h"
#include "InstanceScript.h"
#include "CriteriaHandler.h"
#include "SceneMgr.h"
#include "Creature.h"
#include "GameObject.h"
#include "PhasingHandler.h"
#include "Log.h"
#include "Object.h"
enum
{
    NPC_THRALL_91731 = 91731,
    NPC_THRALL_RING = 965270,
    NPC_THRALL_RINGS = 965271,
    NPC_MILRA_STORMCALLER = 113709,
    QUEST_A_RING_UNBROKEN = 39746,
    SPELL_CAST_GOB = 11789,
    SPELL_CAST_ART = 209685,
    SPELL_CAST_ARTY = 209684,
    SPELL_ADEL_STAFF = 221207,
    ADEll_STAFF = 111102,
    NPC_ERANAK_STONSPEAK = 1028267,
    NPC_REGAL_KING = 966541,
    GO_PORTAL = 278434,
};

struct npc_trall_91731 : public ScriptedAI
{
    npc_trall_91731(Creature* creature) : ScriptedAI(creature) { SayHi = false; }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld())
            return;
        if (!me->IsWithinDist(who, 75.0f, false))
            return;

        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();

        if (!player)
            return;
        if (TempSummon* personalCreature = player->SummonCreature(_insideNpc, _positon, TEMPSUMMON_TIMED_DESPAWN, 60000, 0, true))
        {
            personalCreature->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, personalCreature->GetFollowAngle());
        }
    }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_A_RING_UNBROKEN)
        {
            Talk(1, player);
            me->DespawnOrUnsummon(5000);
        }
    }
private:
    bool SayHi;
    uint32 _insideNpc;
    Position _positon;
};

// Quest39746
class npc_portal_1970193 : public CreatureScript
{
public:
    npc_portal_1970193() : CreatureScript("npc_portal_1970193") { }
    struct npc_portal_1970193AI : public ScriptedAI
    {
        npc_portal_1970193AI(Creature* creature) : ScriptedAI(creature) { }
        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
            {
                if (player->GetQuestStatus(39746) == QUEST_STATUS_INCOMPLETE)
                {
                    if (player->IsInDist(me, 65.0f))
                    {
                        if (!me->FindNearestCreature(104681, 70.0f))
                        {
                            player->SummonCreature(104681, Position(-826.172f, 4260.53f, 746.251f, 1.75139f), TEMPSUMMON_MANUAL_DESPAWN);
                        }
                    }
                }
            }
        }
    };
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_portal_1970193AI(creature);
    }
};

struct npc_stormbeak_104681 : public ScriptedAI
{
    npc_stormbeak_104681(Creature* creature) : ScriptedAI(creature) { me->SetAIAnimKitId(0); }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
        {

            if (player->GetQuestStatus(39746) == QUEST_STATUS_INCOMPLETE)
            {
                me->SetAIAnimKitId(4061);
                player->KilledMonsterCredit(103728);
                player->AddConversationDelayedTeleport(1800, 1325, 1572, Position(827.552f, 1037.688f, 48.341f, 5.8136f));
            }
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
            }
        }
    }
};


struct npc_sturmschnabel_98383 : public ScriptedAI
{
    npc_sturmschnabel_98383(Creature* creature) : ScriptedAI(creature) { me->SetAIAnimKitId(0); }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
        {

            {
                me->SetAIAnimKitId(4061);
                player->AddConversationDelayedTeleport(1800, 1325, 646, Position(1029.35f, 668.829f, 156.672f, 4.37562f));
            }

            if (player->GetQuestStatus(42931) == QUEST_STATUS_INCOMPLETE)
            {
                me->SetAIAnimKitId(4061);
                player->KilledMonsterCredit(99067);
                player->AddConversationDelayedTeleport(1800, 1325, 646, Position(1029.35f, 668.829f, 156.672f, 4.37562f));
            }
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
            }
        }
    }
};

// Quest40224
class npc_portal_1970191 : public CreatureScript
{
public:
    npc_portal_1970191() : CreatureScript("npc_portal_1970191") { }
    struct npc_portal_1970191AI : public ScriptedAI
    {
        npc_portal_1970191AI(Creature* creature) : ScriptedAI(creature) { }
        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
            {
                if (player->GetQuestStatus(40224) == QUEST_STATUS_INCOMPLETE)
                {
                    if (player->IsInDist(me, 54.0f))
                    {
                        if (!me->FindNearestGameObject(251961, 70.0f))
                        {
                            player->SummonGameObject(251961, 2371.68f, 179.208f, 181.966f, 0.0188644f, QuaternionData(), 0);
                        }
                    }
                }
            }
        }
    };
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_portal_1970191AI(creature);
    }
};

enum Spells
{
    SPELL_SHATTERING_AXE = 199169,
    SPELL_FEL_SPIKES = 199094,
};

enum Events
{
    EVENT_SHATTERING_AXE = 1,
    EVENT_FEL_SPIKES = 2,
};

class npc_gethzun_98379 : public CreatureScript
{
public:
    npc_gethzun_98379() : CreatureScript("npc_gethzun_98379") { }

    struct npc_gethzun_98379AI : public WorldBossAI
    {
        npc_gethzun_98379AI(Creature* creature) : WorldBossAI(creature) { }

        void Reset() override
        {
            _Reset();
            me->SetFullHealth();
            me->CombatStop(true);
            me->GetMotionMaster()->MoveTargetedHome();
            events.Reset();
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            Reset();
        }

        void EnterCombat(Unit* who) override
        {
            if (!who)
                return;

            me->setActive(true);
            DoZoneInCombat();
            me->SetFullHealth();
            events.ScheduleEvent(EVENT_SHATTERING_AXE, 6000);
            events.ScheduleEvent(EVENT_FEL_SPIKES, 13000);
        }

        void UpdateAI(uint32 diff) override
        {
            UpdateVictim();

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            if (me->IsInCombat())
            {
                if (events.Empty())
                {
                    events.ScheduleEvent(EVENT_SHATTERING_AXE, 6000);
                    events.ScheduleEvent(EVENT_FEL_SPIKES, 13000);
                }
            }
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SHATTERING_AXE:
                {
                    Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0.0f, 10.0f, true);
                    if (!target)
                        break;

                    DoCast(target, SPELL_SHATTERING_AXE);
                    events.ScheduleEvent(EVENT_SHATTERING_AXE, 6000);
                    break;
                }
                case EVENT_FEL_SPIKES:
                {
                    Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0.0, 0.0, true);
                    if (!target)
                        break;
                    DoCast(target, SPELL_FEL_SPIKES, false);
                    events.ScheduleEvent(EVENT_FEL_SPIKES, 13000);
                    break;
                }
                }
            }

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* who/*killer*/) override
        {
            if (Player* player = who->ToPlayer())
            {
                player->KilledMonsterCredit(54240);
                if (instance)
                    instance->DoPlayScenePackageIdOnPlayers(1491);
            }
        }

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_gethzun_98379AI(creature);
    }
};

struct npc_thrall_965270 : public CreatureScript
{
public:
    npc_thrall_965270() : CreatureScript("npc_thrall_965270") { }

    struct npc_thrall_965270AI : public ScriptedAI
    {
        npc_thrall_965270AI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        void Reset()
        {
            say = false;
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (Creature* Thrall = me->FindNearestCreature(NPC_THRALL_RING, 10.0f, true))
            {
                if (!say)
                {
                    say = true;
                    Thrall->GetScheduler().Schedule(2s, [Thrall](TaskContext context)
                    {
                        Thrall->AI()->Talk(0);
                    });
                    Thrall->GetScheduler().Schedule(7s, [Thrall](TaskContext context)
                    {
                        Thrall->AI()->Talk(1);
                    });
                    return;
                }
            }
        }
    private:
        bool say;

    };
    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_thrall_965270AI(creature);
    }
};

struct npc_milra_113709 : public CreatureScript
{
public:
    npc_milra_113709() : CreatureScript("npc_milra_113709") { }

    struct npc_milra_113709AI : public ScriptedAI
    {
        npc_milra_113709AI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        void Reset()
        {
            say = false;
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (Creature* Milra = me->FindNearestCreature(NPC_MILRA_STORMCALLER, 7.0f, true))
            {
                if (!say)
                {
                    say = true;
                    Milra->GetScheduler().Schedule(2s, [Milra](TaskContext context)
                    {
                        Milra->AI()->Talk(0);
                    });
                    Milra->GetScheduler().Schedule(7s, [Milra](TaskContext context)
                    {
                        Milra->AI()->Talk(1);
                    });
                    return;
                }
            }
        }
    private:
        bool say;

    };
    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_milra_113709AI(creature);
    }
};

struct npc_thrall_965271 : public CreatureScript
{
public:
    npc_thrall_965271() : CreatureScript("npc_thrall_965271") { }

    struct npc_thrall_965271AI : public ScriptedAI
    {
        npc_thrall_965271AI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        void Reset()
        {
            say = false;
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (Creature* Thralls = me->FindNearestCreature(NPC_THRALL_RINGS, 30.0f, true))
            {
                if (!say)
                {
                    say = true;
                    Thralls->GetScheduler().Schedule(2s, [Thralls](TaskContext context)
                    {
                        Thralls->AI()->Talk(0);
                    });
                    Thralls->GetScheduler().Schedule(6s, [Thralls](TaskContext context)
                    {
                        Thralls->AI()->Talk(1);
                    });
                    return;
                }
            }
        }
    private:
        bool say;

    };
    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_thrall_965271AI(creature);
    }
};

struct npc_bubble_112142 : public ScriptedAI
{
    npc_bubble_112142(Creature* creature) : ScriptedAI(creature) { me->SetAIAnimKitId(0); }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
        {
            if (player->GetQuestStatus(43644) == QUEST_STATUS_INCOMPLETE)
            {
                me->SetAIAnimKitId(4061);
                player->KilledMonsterCredit(105805);
                player->AddConversationDelayedTeleport(1800, 1325, 0, Position(-6796.7f, 4565.75f, -605.263f, 3.01229f));
                player->CastSpell(player, SPELL_CAST_GOB, true);
            }
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
            }
        }
    }
};

enum CriteriaTrees
{
    CRITERIA_TREE_HEAL_AND_RECRUIT_THE_BELEAGUERED_SEA_GIANT = 47120,
    CRITERIA_TREE_FIND_AND_FREE_THE_MISSING_SHAMAN_WAVESPEAKER_ADELEE = 47122,
    CRITERIA_TREE_DEFEAT_KRA_LISS = 47126,
    CRITERIA_TREE_ASCEND_TO_THE_UPPER_LEVEL_AND_LEAD_YOUR_PARTY_THROUGH_THE_WAVES = 47130,
    CRITERIA_TREE_DEFEAT_LADY_ZITHREEN = 47132,
    CRITERIA_TREE_PICK_UP_SHARAS_DAL = 47134,
};

class go_sharas_dal_249342 : public GameObjectScript
{
public:
    go_sharas_dal_249342() : GameObjectScript("go_sharas_dal_249342")
    {
        isloot = false;
    }

    void OnLootStateChanged(GameObject* go, uint32 state, Unit* unit)
    {
        if (state == GO_ACTIVATED && unit && !isloot)
        {
            isloot = true;
            go->GetScheduler().Schedule(5s, [this, go, unit](TaskContext /*context*/)
            {
                if (InstanceScript* instance = go->GetInstanceScript())
                {
                    instance->DoKilledMonsterCredit(40341, 105787);
                    instance->DoCastSpellOnPlayers(209685);
                    instance->DoCastSpellOnPlayers(209684);
                    instance->DoSendScenarioEvent(49820);
                    if (Creature* weapon = go->FindNearestCreature(105787, 25.0f))
                        weapon->DespawnOrUnsummon();
                    //209743

                    //192191 DISCOVER_TAXI 1774
                    uint32 nodeid = 1774;
                    //if (sTaxiNodesStore.LookupEntry(nodeid))
                        //if (Player* player = unit->ToPlayer())
                            //player->GetSession()->SendDiscoverNewTaxiNode(nodeid);
                }
            });
        }
    }
    bool isloot;
};

class go_highborne_203213 : public GameObjectScript
{
public:
    go_highborne_203213() : GameObjectScript("go_highborne_203213") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        go->UseDoorOrButton();
        if (player->GetQuestStatus(43645) == QUEST_STATUS_INCOMPLETE)
        {
            player->KilledMonsterCredit(252304);
            return true;
        }
        return false;
    }
};

class go_highborne_203218 : public GameObjectScript
{
public:
    go_highborne_203218() : GameObjectScript("go_highborne_203218") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        go->UseDoorOrButton();
        if (player->GetQuestStatus(43645) == QUEST_STATUS_INCOMPLETE)
        {
            player->KilledMonsterCredit(111104);
            return true;
        }
        return false;
    }
};

class go_highborne_203212 : public GameObjectScript
{
public:
    go_highborne_203212() : GameObjectScript("go_highborne_203212") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        go->UseDoorOrButton();
        if (player->GetQuestStatus(43645) == QUEST_STATUS_INCOMPLETE)
        {
            player->KilledMonsterCredit(111102);
            return true;
        }
        return false;
    }
};

class npc_adelees_staff_111102 : public CreatureScript
{
public:
    npc_adelees_staff_111102() : CreatureScript("npc_adelees_staff_111102") { }
    struct npc_adelees_staff_111102AI : public ScriptedAI
    {
        npc_adelees_staff_111102AI(Creature* creature) : ScriptedAI(creature) { }
        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
            {
                if (player->GetQuestStatus(43645) == QUEST_STATUS_INCOMPLETE)
                {
                    if (player->IsInDist(me, 95.0f))
                    {
                        me->CastSpell(ADEll_STAFF, SPELL_ADEL_STAFF, true);
                        me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
                    }
                }
            }
        }

        void OnSpellClick(Unit* clicker, bool& /*result*/)
        {
            if (Player* player = clicker->ToPlayer())
            {
                if (player->GetQuestStatus(43645) == QUEST_STATUS_INCOMPLETE)
                    player->KilledMonsterCredit(111102);
            }
        }
    };
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_adelees_staff_111102AI(creature);
    }
};

class npc_tele_40341 : public CreatureScript
{
public:
    npc_tele_40341() : CreatureScript("npc_tele_40341") { }
    struct npc_tele_40341AI : public ScriptedAI
    {
        npc_tele_40341AI(Creature* creature) : ScriptedAI(creature) { }
        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
            {
                if (player->GetQuestStatus(40341) == QUEST_STATUS_INCOMPLETE)
                {
                    if (player->IsInDist(me, 35.0f))
                    {
                        player->AddConversationDelayedTeleport(1800, 1325, 1600, Position(-629.42f, 808.68f, 247.67f, 6.25976f));
                    }
                }
            }
        }
    };
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_tele_40341AI(creature);
    }
};

class npc_quesr_40341 : public CreatureScript
{
public:
    npc_quesr_40341() : CreatureScript("npc_quesr_40341") { }
    struct npc_quesr_40341AI : public ScriptedAI
    {
        npc_quesr_40341AI(Creature* creature) : ScriptedAI(creature) { }
        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
            {
                if (player->GetQuestStatus(40341) == QUEST_STATUS_INCOMPLETE)
                {
                    if (player->IsInDist(me, 45.0f))
                    {
                        player->KilledMonsterCredit(105805);
                        player->KilledMonsterCredit(111286);
                    }
                }
            }
        }
    };
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_quesr_40341AI(creature);
    }
};

struct npc_eranak_1028267 : public CreatureScript
{
public:
    npc_eranak_1028267() : CreatureScript("npc_eranak_1028267") { }

    struct npc_eranak_1028267AI : public ScriptedAI
    {
        npc_eranak_1028267AI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        void Reset()
        {
            say = false;
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (Creature* Eranak = me->FindNearestCreature(NPC_ERANAK_STONSPEAK, 7.0f, true))
            {
                if (!say)
                {
                    say = true;
                    Eranak->GetScheduler().Schedule(2s, [Eranak](TaskContext context)
                    {
                        Eranak->AI()->Talk(0);
                    });
                    Eranak->GetScheduler().Schedule(7s, [Eranak](TaskContext context)
                    {
                        Eranak->AI()->Talk(1);
                    });
                    Eranak->GetScheduler().Schedule(8s, [Eranak](TaskContext context)
                    {
                        Eranak->SummonCreature(1121423, Position(-214.111f, 807.373f, 264.208f, 3.12209f), TEMPSUMMON_MANUAL_DESPAWN);
                    });
                    return;
                }
            }
        }
    private:
        bool say;

    };
    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_eranak_1028267AI(creature);
    }
};

struct npc_bubble_1121423 : public ScriptedAI
{
    npc_bubble_1121423(Creature* creature) : ScriptedAI(creature) { me->SetAIAnimKitId(0); }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
        {
            if (player->GetQuestStatus(40341) == QUEST_STATUS_INCOMPLETE)
            {
                me->SetAIAnimKitId(4061);
                player->AddConversationDelayedTeleport(1800, 1325, 1600, Position(-184.989f, 802.404f, 796.645f, 6.25583f));
                player->CastSpell(player, SPELL_CAST_GOB, true);
            }
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
            }
        }
    }
};

struct npc_bubble_222143 : public ScriptedAI
{
    npc_bubble_222143(Creature* creature) : ScriptedAI(creature) { me->SetAIAnimKitId(0); }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
        {
            if (player->GetQuestStatus(40341) == QUEST_STATUS_INCOMPLETE)
            {
                me->SetAIAnimKitId(4061);
                player->CastSpell(player, SPELL_CAST_ART, true);
                player->CastSpell(player, SPELL_CAST_ARTY, true);
                player->KilledMonsterCredit(105806);
                player->AddConversationDelayedTeleport(1800, 1325, 1469, Position(824.465f, 1036.18f, 48.26f, 1.46014f));
                player->RemoveSpell(SPELL_CAST_GOB, true);
            }
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
            }
        }
    }
};

struct npc_graddoc_113354 : public ScriptedAI
{
    npc_graddoc_113354(Creature* creature) : ScriptedAI(creature) { me->SetAIAnimKitId(0); }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
        {

            if (player->GetQuestStatus(43334) == QUEST_STATUS_INCOMPLETE)
            {
                me->SetAIAnimKitId(4061);
                player->KilledMonsterCredit(103863);
                player->AddConversationDelayedTeleport(1800, 1325, 870, Position(3265.64f, 656.921f, 538.276f, 5.49793f));
            }
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
            }
        }
    }
};

// Quest43338
class npc_quest_1970194 : public CreatureScript
{
public:
    npc_quest_1970194() : CreatureScript("npc_quest_1970194") { }
    struct npc_quest_1970194AI : public ScriptedAI
    {
        npc_quest_1970194AI(Creature* creature) : ScriptedAI(creature) { }
        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
            {
                if (player->GetQuestStatus(43338) == QUEST_STATUS_INCOMPLETE)
                {
                    if (player->IsInDist(me, 15.0f))
                    {
                        player->KilledMonsterCredit(110802);
                    }
                }
            }
        }
    };
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_quest_1970194AI(creature);
    }
};

// Quest39771
class npc_quest_1970195 : public CreatureScript
{
public:
    npc_quest_1970195() : CreatureScript("npc_quest_1970195") { }
    struct npc_quest_1970195AI : public ScriptedAI
    {
        npc_quest_1970195AI(Creature* creature) : ScriptedAI(creature) { }
        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
            {
                if (player->GetQuestStatus(39771) == QUEST_STATUS_INCOMPLETE)
                {
                    if (player->IsInDist(me, 35.0f))
                    {
                        player->KilledMonsterCredit(97131);
                    }
                }
            }
        }
    };
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_quest_1970195AI(creature);
    }
};

struct npc_regar_966541 : public CreatureScript
{
public:
    npc_regar_966541() : CreatureScript("npc_regar_966541") { }

    struct npc_regar_966541AI : public ScriptedAI
    {
        npc_regar_966541AI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        void Reset()
        {
            say = false;
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
            {
                if (player->GetQuestStatus(39771) == QUEST_STATUS_INCOMPLETE)
                {
                    if (Creature* Regal = me->FindNearestCreature(NPC_REGAL_KING, 10.0f, true))
                    {
                        if (!say)
                        {
                            say = true;
                            Regal->GetScheduler().Schedule(2s, [Regal](TaskContext context)
                            {
                                Regal->AI()->Talk(0);
                            });
                            Regal->GetScheduler().Schedule(7s, [Regal](TaskContext context)
                            {
                                Regal->AI()->Talk(1);
                            });
                            return;
                        }
                    }
                }
            }
        }
    private:
        bool say;

    };
    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_regar_966541AI(creature);
    }
};

class lord_kravos105183 : public CreatureScript
{
public:
    lord_kravos105183() : CreatureScript("lord_kravos105183") { }

    struct lord_kravos105183AI : public WorldBossAI
    {
        lord_kravos105183AI(Creature* creature) : WorldBossAI(creature) { }

        void Reset() override
        {
            _Reset();
            me->SetFullHealth();
            me->CombatStop(true);
            me->GetMotionMaster()->MoveTargetedHome();
            events.Reset();
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            Reset();
        }

        void EnterCombat(Unit* who) override
        {
            if (!who)
                return;

            me->setActive(true);
            DoZoneInCombat();
            me->SetFullHealth();
        }

        void UpdateAI(uint32 diff) override
        {
            UpdateVictim();

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            if (me->IsInCombat())
            {
                if (events.Empty())
                {
                }
            }

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/ who) override

        {
            if (Player* player = who->ToPlayer())

            {
                if (player->GetQuestStatus(39771) == QUEST_STATUS_INCOMPLETE)
                {
                    if (who->GetTypeId() == TYPEID_PLAYER)
                    {
                        player->KilledMonsterCredit(53726);
                        who->ToPlayer()->AddItem(128935, 1);
                        player->SummonGameObject(278434, 3792.25f, 533.892f, 639.007f, 3.02942f, QuaternionData(), 0);
                        player->SummonCreature(96541, Position(835.073f, 1042.62f, 48.512f, 3.86797f), TEMPSUMMON_MANUAL_DESPAWN);
                    }
                }
            }
        }

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new lord_kravos105183AI(creature);
    }
};

void AddSC_class_hall_shaman()
{
    RegisterCreatureAI(npc_stormbeak_104681);
    RegisterCreatureAI(npc_sturmschnabel_98383);
    RegisterCreatureAI(npc_trall_91731);
    new npc_portal_1970193();
    new npc_portal_1970191();
    new npc_thrall_965270();
    new npc_thrall_965271();
    new npc_milra_113709();
      new npc_gethzun_98379();
    new go_sharas_dal_249342();
    RegisterCreatureAI(npc_bubble_112142);
    new go_highborne_203213();
    new go_highborne_203218();
    new go_highborne_203212();
    new npc_adelees_staff_111102();
    new npc_tele_40341();
    new npc_quesr_40341();
    new npc_eranak_1028267();
    RegisterCreatureAI(npc_bubble_1121423);
    RegisterCreatureAI(npc_bubble_222143);
    RegisterCreatureAI(npc_graddoc_113354);
    new npc_quest_1970194();
    new npc_quest_1970195();
    new npc_regar_966541();
    new lord_kravos105183();
}
