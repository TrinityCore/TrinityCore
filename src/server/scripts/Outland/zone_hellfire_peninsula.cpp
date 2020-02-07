/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
SDName: Hellfire_Peninsula
SD%Complete: 100
SDComment: Quest support: 9375, 9410, 9418, 10129, 10146, 10162, 10163, 10340, 10346, 10347, 10382 (Special flight paths) "Needs update"
SDCategory: Hellfire Peninsula
EndScriptData */

/* ContentData
npc_aeranas
npc_ancestral_wolf
npc_wounded_blood_elf
npc_fel_guard_hound
EndContentData */

#include "ScriptMgr.h"
#include "CellImpl.h"
#include "GridNotifiersImpl.h"
#include "Log.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "TemporarySummon.h"
#include "WorldSession.h"

/*######
## npc_aeranas
######*/

enum Aeranas
{
    SAY_SUMMON                  = 0,
    SAY_FREE                    = 1,
    SPELL_ENVELOPING_WINDS      = 15535,
    SPELL_SHOCK                 = 12553
};

class npc_aeranas : public CreatureScript
{
public:
    npc_aeranas() : CreatureScript("npc_aeranas") { }

    struct npc_aeranasAI : public ScriptedAI
    {
        npc_aeranasAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            faction_Timer = 8000;
            envelopingWinds_Timer = 9000;
            shock_Timer = 5000;
        }

        void Reset() override
        {
            Initialize();

            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
            me->SetFaction(FACTION_FRIENDLY);

            Talk(SAY_SUMMON);
        }

        void UpdateAI(uint32 diff) override
        {
            if (faction_Timer)
            {
                if (faction_Timer <= diff)
                {
                    me->SetFaction(FACTION_MONSTER_2);
                    faction_Timer = 0;
                } else faction_Timer -= diff;
            }

            if (!UpdateVictim())
                return;

            if (HealthBelowPct(30))
            {
                me->SetFaction(FACTION_FRIENDLY);
                me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                me->RemoveAllAuras();
                me->CombatStop(true);
                EngagementOver();
                Talk(SAY_FREE);
                return;
            }

            if (shock_Timer <= diff)
            {
                DoCastVictim(SPELL_SHOCK);
                shock_Timer = 10000;
            } else shock_Timer -= diff;

            if (envelopingWinds_Timer <= diff)
            {
                DoCastVictim(SPELL_ENVELOPING_WINDS);
                envelopingWinds_Timer = 25000;
            } else envelopingWinds_Timer -= diff;

            DoMeleeAttackIfReady();
        }

    private:
        uint32 faction_Timer;
        uint32 envelopingWinds_Timer;
        uint32 shock_Timer;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_aeranasAI(creature);
    }
};

/*######
## npc_ancestral_wolf
######*/

enum AncestralWolf
{
    EMOTE_WOLF_LIFT_HEAD        = 0,
    EMOTE_WOLF_HOWL             = 1,
    SAY_WOLF_WELCOME            = 0,
    SPELL_ANCESTRAL_WOLF_BUFF   = 29938,
    NPC_RYGA                    = 17123
};

class npc_ancestral_wolf : public CreatureScript
{
public:
    npc_ancestral_wolf() : CreatureScript("npc_ancestral_wolf") { }

    struct npc_ancestral_wolfAI : public EscortAI
    {
        npc_ancestral_wolfAI(Creature* creature) : EscortAI(creature) { }

        void InitializeAI() override
        {
            if (me->GetOwner() && me->GetOwner()->GetTypeId() == TYPEID_PLAYER)
            {
                EscortAI::Start(false, false, me->GetOwner()->GetGUID());

                me->SetSpeedRate(MOVE_WALK, 1.5f);

                if (TempSummon* tempSummon = me->ToTempSummon())
                    tempSummon->SetCanFollowOwner(false);
            }
            else
                TC_LOG_ERROR("scripts", "TRINITY: npc_ancestral_wolf can not obtain owner or owner is not a player.");
        }

        void Reset() override
        {
        }

        // Override Evade Mode event, recast buff that was removed by standard handler
        void EnterEvadeMode(EvadeReason why) override
        {
            EscortAI::EnterEvadeMode(why);
            DoCast(me, SPELL_ANCESTRAL_WOLF_BUFF, true);
        }

        void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
        {
            switch (waypointId)
            {
                case 0:
                    Talk(EMOTE_WOLF_LIFT_HEAD);
                    break;
                case 2:
                    Talk(EMOTE_WOLF_HOWL);
                    DoCast(me, SPELL_ANCESTRAL_WOLF_BUFF, true);
                    break;
                // Move Ryga into position
                case 48:
                    if (Creature* ryga = me->FindNearestCreature(NPC_RYGA, 70.0f))
                    {
                        if (ryga->IsAlive() && !ryga->IsInCombat())
                        {
                            ryga->SetWalk(true);
                            ryga->SetSpeedRate(MOVE_WALK, 1.5f);
                            ryga->GetMotionMaster()->MovePoint(0, 517.340698f, 3885.03975f, 190.455978f, true);
                        }
                    }
                    break;
                // Ryga Kneels and welcomes spirit wolf
                case 50:
                    if (Creature* ryga = me->FindNearestCreature(NPC_RYGA, 70.0f))
                    {
                        if (ryga->IsAlive() && !ryga->IsInCombat())
                        {
                            ryga->SetFacingTo(0.776773f);
                            ryga->SetStandState(UNIT_STAND_STATE_KNEEL);
                            ryga->AI()->Talk(SAY_WOLF_WELCOME);
                        }
                    }
                    break;
                // Ryga returns to spawn point
                case 51:
                    if (Creature* ryga = me->FindNearestCreature(NPC_RYGA, 70.0f))
                    {
                        if (ryga->IsAlive() && !ryga->IsInCombat())
                        {
                            float fRetX, fRetY, fRetZ, fRetO;
                            ryga->GetRespawnPosition(fRetX, fRetY, fRetZ, &fRetO);
                            ryga->SetHomePosition(fRetX, fRetY, fRetZ, fRetO);
                            ryga->SetStandState(UNIT_STAND_STATE_STAND);
                            ryga->GetMotionMaster()->MoveTargetedHome();
                        }
                    }
                    break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_ancestral_wolfAI(creature);
    }
};

/*######
## npc_wounded_blood_elf
######*/

enum WoundedBloodElf
{
    SAY_ELF_START               = 0,
    SAY_ELF_SUMMON1             = 1,
    SAY_ELF_RESTING             = 2,
    SAY_ELF_SUMMON2             = 3,
    SAY_ELF_COMPLETE            = 4,
    SAY_ELF_AGGRO               = 5,
    QUEST_ROAD_TO_FALCON_WATCH  = 9375,
    NPC_HAALESHI_WINDWALKER     = 16966,
    NPC_HAALESHI_TALONGUARD     = 16967
};

class npc_wounded_blood_elf : public CreatureScript
{
public:
    npc_wounded_blood_elf() : CreatureScript("npc_wounded_blood_elf") { }

    struct npc_wounded_blood_elfAI : public EscortAI
    {
        npc_wounded_blood_elfAI(Creature* creature) : EscortAI(creature) { }

        void Reset() override { }

        void JustEngagedWith(Unit* /*who*/) override
        {
            if (HasEscortState(STATE_ESCORT_ESCORTING))
                Talk(SAY_ELF_AGGRO);
        }

        void JustSummoned(Creature* summoned) override
        {
            summoned->AI()->AttackStart(me);
        }

        void QuestAccept(Player* player, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_ROAD_TO_FALCON_WATCH)
            {
                me->SetFaction(FACTION_ESCORTEE_H_PASSIVE);
                EscortAI::Start(true, false, player->GetGUID());
            }
        }

        void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
        {
            Player* player = GetPlayerForEscort();
            if (!player)
                return;

            switch (waypointId)
            {
                case 0:
                    Talk(SAY_ELF_START, player);
                    break;
                case 9:
                    Talk(SAY_ELF_SUMMON1, player);
                    // Spawn two Haal'eshi Talonguard
                    DoSpawnCreature(NPC_HAALESHI_TALONGUARD, -15, -15, 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    DoSpawnCreature(NPC_HAALESHI_TALONGUARD, -17, -17, 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    break;
                case 13:
                    Talk(SAY_ELF_RESTING, player);
                    break;
                case 14:
                    Talk(SAY_ELF_SUMMON2, player);
                    // Spawn two Haal'eshi Windwalker
                    DoSpawnCreature(NPC_HAALESHI_WINDWALKER, -15, -15, 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    DoSpawnCreature(NPC_HAALESHI_WINDWALKER, -17, -17, 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    break;
                case 27:
                    Talk(SAY_ELF_COMPLETE, player);
                    // Award quest credit
                    player->GroupEventHappens(QUEST_ROAD_TO_FALCON_WATCH, me);
                    break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_wounded_blood_elfAI(creature);
    }
};

/*######
## npc_fel_guard_hound
######*/

enum FelGuard
{
    SPELL_SUMMON_POO     = 37688,
    SPELL_FAKE_BLOOD     = 37692,
    NPC_DERANGED_HELBOAR = 16863,

    EVENT_SEARCH_HELBOAR = 1,
    EVENT_HELBOAR_FOUND  = 2,
    EVENT_SUMMON_POO     = 3,
    EVENT_FOLLOW_PLAYER  = 4
};

class npc_fel_guard_hound : public CreatureScript
{
public:
    npc_fel_guard_hound() : CreatureScript("npc_fel_guard_hound") { }

    struct npc_fel_guard_houndAI : public ScriptedAI
    {
        npc_fel_guard_houndAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            helboarGUID.Clear();
            _events.ScheduleEvent(EVENT_SEARCH_HELBOAR, 3s);
        }

        void Reset() override
        {
            Initialize();
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE || id != 1)
                return;

            if (Creature* helboar = ObjectAccessor::GetCreature(*me, helboarGUID))
            {
                _events.CancelEvent(EVENT_SEARCH_HELBOAR);
                me->HandleEmoteCommand(EMOTE_ONESHOT_ATTACK_UNARMED);
                me->CastSpell(helboar, SPELL_FAKE_BLOOD);
                _events.ScheduleEvent(EVENT_HELBOAR_FOUND, 2s);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SEARCH_HELBOAR:
                        if (Creature* helboar = me->FindNearestCreature(NPC_DERANGED_HELBOAR, 10.0f, false))
                        {
                            if (helboar->GetGUID() != helboarGUID && me->GetMotionMaster()->GetCurrentMovementGeneratorType() != POINT_MOTION_TYPE && !me->FindCurrentSpellBySpellId(SPELL_SUMMON_POO))
                            {
                                helboarGUID = helboar->GetGUID();
                                me->SetWalk(true);
                                me->GetMotionMaster()->MovePoint(1, helboar->GetPositionX(), helboar->GetPositionY(), helboar->GetPositionZ());
                                helboar->DespawnOrUnsummon(Seconds(10));
                            }
                        }
                        _events.Repeat(Seconds(3));
                        break;
                    case EVENT_HELBOAR_FOUND:
                        if (Creature* helboar = ObjectAccessor::GetCreature(*me, helboarGUID))
                        {
                            me->HandleEmoteCommand(EMOTE_ONESHOT_ATTACK_UNARMED);
                            me->CastSpell(helboar, SPELL_FAKE_BLOOD);
                            _events.ScheduleEvent(EVENT_SUMMON_POO, 1s);
                        }
                        break;
                    case EVENT_SUMMON_POO:
                        DoCast(SPELL_SUMMON_POO);
                        _events.ScheduleEvent(EVENT_FOLLOW_PLAYER, 2s);
                        break;
                    case EVENT_FOLLOW_PLAYER:
                        me->SetWalk(false);
                        if (Player* owner = me->GetCharmerOrOwnerPlayerOrPlayerItself())
                            me->GetMotionMaster()->MoveFollow(owner, 0.0f, 0.0f);
                        _events.ScheduleEvent(EVENT_SEARCH_HELBOAR, 3s);
                        break;
                }
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;
        ObjectGuid helboarGUID;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_fel_guard_houndAI(creature);
    }
};

enum ExorcismSpells
{
    SPELL_JULES_GOES_PRONE     = 39283,
    SPELL_JULES_THREATENS_AURA = 39284,
    SPELL_JULES_GOES_UPRIGHT   = 39294,
    SPELL_JULES_VOMITS_AURA    = 39295,

    SPELL_BARADAS_COMMAND      = 39277,
    SPELL_BARADA_FALTERS       = 39278,
};

enum ExorcismTexts
{
    SAY_BARADA_1 = 0,
    SAY_BARADA_2 = 1,
    SAY_BARADA_3 = 2,
    SAY_BARADA_4 = 3,
    SAY_BARADA_5 = 4,
    SAY_BARADA_6 = 5,
    SAY_BARADA_7 = 6,
    SAY_BARADA_8 = 7,

    SAY_JULES_1  = 0,
    SAY_JULES_2  = 1,
    SAY_JULES_3  = 2,
    SAY_JULES_4  = 3,
    SAY_JULES_5  = 4,
};

Position const exorcismPos[11] =
{
    { -707.123f, 2751.686f, 101.592f, 4.577416f }, //Barada Waypoint-1      0
    { -710.731f, 2749.075f, 101.592f, 1.513286f }, //Barada Cast position   1
    { -710.332f, 2754.394f, 102.948f, 3.207566f }, //Jules                  2
    { -714.261f, 2747.754f, 103.391f, 0.0f },      //Jules Waypoint-1       3
    { -713.113f, 2750.194f, 103.391f, 0.0f },      //Jules Waypoint-2       4
    { -710.385f, 2750.896f, 103.391f, 0.0f },      //Jules Waypoint-3       5
    { -708.309f, 2750.062f, 103.391f, 0.0f },      //Jules Waypoint-4       6
    { -707.401f, 2747.696f, 103.391f, 0.0f },      //Jules Waypoint-5       7
    { -708.591f, 2745.266f, 103.391f, 0.0f },      //Jules Waypoint-6       8
    { -710.597f, 2744.035f, 103.391f, 0.0f },      //Jules Waypoint-7       9
    { -713.089f, 2745.302f, 103.391f, 0.0f },      //Jules Waypoint-8      10
};

enum ExorcismMisc
{
    NPC_DARKNESS_RELEASED               = 22507,
    NPC_FOUL_PURGE                      = 22506,
    NPC_COLONEL_JULES                   = 22432,

    BARADAS_GOSSIP_MESSAGE              = 10683,

    QUEST_THE_EXORCISM_OF_COLONEL_JULES = 10935,

    ACTION_START_EVENT                  = 1,
    ACTION_JULES_HOVER                  = 2,
    ACTION_JULES_FLIGHT                 = 3,
    ACTION_JULES_MOVE_HOME              = 4,
};

enum ExorcismEvents
{
    EVENT_BARADAS_TALK = 1,
    EVENT_RESET        = 2,

    //Colonel Jules
    EVENT_SUMMON_SKULL = 1,
};

/*######
## npc_colonel_jules
######*/

class npc_colonel_jules : public CreatureScript
{
public:
    npc_colonel_jules() : CreatureScript("npc_colonel_jules") { }

    struct npc_colonel_julesAI : public ScriptedAI
    {
        npc_colonel_julesAI(Creature* creature) : ScriptedAI(creature), summons(me)
        {
            Initialize();
        }

        void Initialize()
        {
            point = 3;
            wpreached = false;
            success = false;
        }

        void Reset() override
        {
            events.Reset();

            summons.DespawnAll();
            Initialize();
        }

        bool success;

        void DoAction(int32 action) override
        {
            switch (action)
            {
            case ACTION_JULES_HOVER:
                me->AddAura(SPELL_JULES_GOES_PRONE, me);
                me->AddAura(SPELL_JULES_THREATENS_AURA, me);

                me->SetCanFly(true);
                me->SetSpeedRate(MOVE_RUN, 0.2f);

                me->SetFacingTo(3.207566f);
                me->GetMotionMaster()->MoveJump(exorcismPos[2], 2.0f, 2.0f);

                success = false;

                events.ScheduleEvent(EVENT_SUMMON_SKULL, 10s);
                break;
            case ACTION_JULES_FLIGHT:
                me->RemoveAura(SPELL_JULES_GOES_PRONE);

                me->AddAura(SPELL_JULES_GOES_UPRIGHT, me);
                me->AddAura(SPELL_JULES_VOMITS_AURA, me);

                wpreached = true;
                me->GetMotionMaster()->MovePoint(point, exorcismPos[point]);
                break;
            case ACTION_JULES_MOVE_HOME:
                wpreached = false;
                me->SetSpeedRate(MOVE_RUN, 1.0f);
                me->GetMotionMaster()->MovePoint(11, exorcismPos[2]);

                events.CancelEvent(EVENT_SUMMON_SKULL);
                break;
            }
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);
            summon->GetMotionMaster()->MoveRandom(10.0f);
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (id < 10)
                wpreached = true;

            if (id == 8)
            {
                for (uint8 i = 0; i < 2; i++)
                    DoSummon(NPC_FOUL_PURGE, exorcismPos[8]);
            }

            if (id == 10)
            {
                wpreached = true;
                point = 3;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (wpreached)
            {
                me->GetMotionMaster()->MovePoint(point, exorcismPos[point]);
                point++;
                wpreached = false;
            }

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SUMMON_SKULL:
                    uint8 summonCount = urand(1, 3);

                    for (uint8 i = 0; i < summonCount; i++)
                        me->SummonCreature(NPC_DARKNESS_RELEASED, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 1.5f, 0, TEMPSUMMON_MANUAL_DESPAWN);

                    events.ScheduleEvent(EVENT_SUMMON_SKULL, 10s, 15s);
                    break;
                }
            }
        }

        bool GossipHello(Player* player) override
        {
            if (success)
                player->KilledMonsterCredit(NPC_COLONEL_JULES, ObjectGuid::Empty);

            SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
            return true;
        }

    private:
        EventMap events;
        SummonList summons;

        uint8 point;

        bool wpreached;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_colonel_julesAI(creature);
    }
};

/*######
## npc_barada
######*/

class npc_barada : public CreatureScript
{
public:
    npc_barada() : CreatureScript("npc_barada") { }

    struct npc_baradaAI : public ScriptedAI
    {
        npc_baradaAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            step = 0;
        }

        void Reset() override
        {
            events.Reset();
            Initialize();

            playerGUID.Clear();
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED);
        }

        bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            ClearGossipMenuFor(player);
            switch (gossipListId)
            {
                case 1:
                    player->PlayerTalkClass->SendCloseGossip();
                    me->AI()->Talk(SAY_BARADA_1);
                    me->AI()->DoAction(ACTION_START_EVENT);
                    break;
                default:
                    break;
            }
            return false;
        }

        void DoAction(int32 action) override
        {
            if (action == ACTION_START_EVENT)
            {
                if (Creature* jules = me->FindNearestCreature(NPC_COLONEL_JULES, 20.0f, true))
                {
                    julesGUID = jules->GetGUID();
                    jules->AI()->Talk(SAY_JULES_1);
                }

                me->GetMotionMaster()->MovePoint(0, exorcismPos[1]);
                Talk(SAY_BARADA_2);

                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED);
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (id == 0)
                me->GetMotionMaster()->MovePoint(1, exorcismPos[1]);

            if (id == 1)
                events.ScheduleEvent(EVENT_BARADAS_TALK, 2s);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (Creature* jules = ObjectAccessor::GetCreature(*me, julesGUID))
            {
                jules->AI()->DoAction(ACTION_JULES_MOVE_HOME);
                jules->RemoveAllAuras();
            }
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_BARADAS_TALK:
                        switch (step)
                        {
                            case 0:
                                me->SetFacingTo(1.513286f);

                                me->HandleEmoteCommand(EMOTE_ONESHOT_KNEEL);
                                events.ScheduleEvent(EVENT_BARADAS_TALK, 3s);
                                step++;
                                break;
                            case 1:
                                DoCast(SPELL_BARADAS_COMMAND);
                                events.ScheduleEvent(EVENT_BARADAS_TALK, 5s);
                                step++;
                                break;
                            case 2:
                                Talk(SAY_BARADA_3);
                                events.ScheduleEvent(EVENT_BARADAS_TALK, 7s);
                                step++;
                                break;
                            case 3:
                                if (Creature* jules = ObjectAccessor::GetCreature(*me, julesGUID))
                                    jules->AI()->Talk(SAY_JULES_2);

                                events.ScheduleEvent(EVENT_BARADAS_TALK, 18s);
                                step++;
                                break;
                            case 4:
                                DoCast(SPELL_BARADA_FALTERS);
                                me->HandleEmoteCommand(EMOTE_STAND_STATE_NONE);

                                if (Creature* jules = ObjectAccessor::GetCreature(*me, julesGUID))
                                    jules->AI()->DoAction(ACTION_JULES_HOVER);

                                events.ScheduleEvent(EVENT_BARADAS_TALK, 11s);
                                step++;
                                break;
                            case 5:
                                if (Creature* jules = ObjectAccessor::GetCreature(*me, julesGUID))
                                    jules->AI()->Talk(SAY_JULES_3);

                                events.ScheduleEvent(EVENT_BARADAS_TALK, 13s);
                                step++;
                                break;
                            case 6:
                                Talk(SAY_BARADA_4);
                                events.ScheduleEvent(EVENT_BARADAS_TALK, 5s);
                                step++;
                                break;
                            case 7:
                                if (Creature* jules = ObjectAccessor::GetCreature(*me, julesGUID))
                                    jules->AI()->Talk(SAY_JULES_3);

                                events.ScheduleEvent(EVENT_BARADAS_TALK, 13s);
                                step++;
                                break;
                            case 8:
                                Talk(SAY_BARADA_4);
                                events.ScheduleEvent(EVENT_BARADAS_TALK, 12s);
                                step++;
                                break;
                            case 9:
                                if (Creature* jules = ObjectAccessor::GetCreature(*me, julesGUID))
                                    jules->AI()->Talk(SAY_JULES_4);

                                events.ScheduleEvent(EVENT_BARADAS_TALK, 12s);
                                step++;
                                break;
                            case 10:
                                Talk(SAY_BARADA_4);
                                events.ScheduleEvent(EVENT_BARADAS_TALK, 5s);
                                step++;
                                break;
                            case 11:
                                if (Creature* jules = ObjectAccessor::GetCreature(*me, julesGUID))
                                    jules->AI()->DoAction(ACTION_JULES_FLIGHT);

                                events.ScheduleEvent(EVENT_BARADAS_TALK, 10s);
                                step++;
                                break;
                            case 12:
                                if (Creature* jules = ObjectAccessor::GetCreature(*me, julesGUID))
                                    jules->AI()->Talk(SAY_JULES_4);

                                events.ScheduleEvent(EVENT_BARADAS_TALK, 8s);
                                step++;
                                break;
                            case 13:
                                Talk(SAY_BARADA_5);
                                events.ScheduleEvent(EVENT_BARADAS_TALK, 10s);
                                step++;
                                break;
                            case 14:
                                if (Creature* jules = ObjectAccessor::GetCreature(*me, julesGUID))
                                    jules->AI()->Talk(SAY_JULES_4);

                                events.ScheduleEvent(EVENT_BARADAS_TALK, 10s);
                                step++;
                                break;
                            case 15:
                                Talk(SAY_BARADA_6);
                                events.ScheduleEvent(EVENT_BARADAS_TALK, 10s);
                                step++;
                                break;
                            case 16:
                                if (Creature* jules = ObjectAccessor::GetCreature(*me, julesGUID))
                                    jules->AI()->Talk(SAY_JULES_5);

                                events.ScheduleEvent(EVENT_BARADAS_TALK, 10s);
                                step++;
                                break;
                            case 17:
                                Talk(SAY_BARADA_7);
                                events.ScheduleEvent(EVENT_BARADAS_TALK, 10s);
                                step++;
                                break;
                            case 18:
                                if (Creature* jules = ObjectAccessor::GetCreature(*me, julesGUID))
                                    jules->AI()->Talk(SAY_JULES_3);

                                events.ScheduleEvent(EVENT_BARADAS_TALK, 10s);
                                step++;
                                break;
                            case 19:
                                Talk(SAY_BARADA_7);
                                events.ScheduleEvent(EVENT_BARADAS_TALK, 10s);
                                step++;
                                break;
                            case 20:
                                if (Creature* jules = ObjectAccessor::GetCreature(*me, julesGUID))
                                {
                                    jules->AI()->DoAction(ACTION_JULES_MOVE_HOME);
                                    jules->RemoveAura(SPELL_JULES_VOMITS_AURA);
                                }

                                events.ScheduleEvent(EVENT_BARADAS_TALK, 10s);
                                step++;
                                break;
                            case 21:
                                //End
                                if (Creature* jules = ObjectAccessor::GetCreature(*me, julesGUID))
                                {
                                    ENSURE_AI(npc_colonel_jules::npc_colonel_julesAI, jules->AI())->success = true;
                                    jules->RemoveAllAuras();
                                }

                                me->RemoveAura(SPELL_BARADAS_COMMAND);
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED);

                                Talk(SAY_BARADA_8);
                                me->GetMotionMaster()->MoveTargetedHome();
                                EnterEvadeMode();
                                events.ScheduleEvent(EVENT_RESET, 2min);
                                break;
                        }
                        break;
                    case EVENT_RESET:
                        if (Creature* jules = ObjectAccessor::GetCreature(*me, julesGUID))
                            ENSURE_AI(npc_colonel_jules::npc_colonel_julesAI, jules->AI())->success = false;
                        break;
                }
            }
        }

        private:
            EventMap events;
            uint8 step;
            ObjectGuid julesGUID;
            ObjectGuid playerGUID;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_baradaAI(creature);
    }
};

enum Aledis
{
    SAY_CHALLENGE = 0,
    SAY_DEFEATED = 1,
    EVENT_TALK = 1,
    EVENT_ATTACK = 2,
    EVENT_EVADE = 3,
    EVENT_FIREBALL = 4,
    EVENT_FROSTNOVA = 5,
    SPELL_FIREBALL = 20823,
    SPELL_FROSTNOVA = 11831
};

class npc_magister_aledis : public CreatureScript
{
public:
    npc_magister_aledis() : CreatureScript("npc_magister_aledis") { }

    struct npc_magister_aledisAI : public ScriptedAI
    {
        npc_magister_aledisAI(Creature* creature) : ScriptedAI(creature) { }

        void StartFight(Player* player)
        {
            me->Dismount();
            me->SetFacingToObject(player);
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            _playerGUID = player->GetGUID();
            _events.ScheduleEvent(EVENT_TALK, 2s);
        }

        void Reset() override
        {
            me->RestoreFaction();
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            me->SetImmuneToPC(true);
        }

        void DamageTaken(Unit* /*attacker*/, uint32 &damage) override
        {
            if (damage > me->GetHealth() || me->HealthBelowPctDamaged(20, damage))
            {
                damage = 0;

                _events.Reset();
                me->RestoreFaction();
                me->RemoveAllAuras();
                me->CombatStop(true);
                EngagementOver();
                me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                me->SetImmuneToPC(true);
                Talk(SAY_DEFEATED);

                _events.ScheduleEvent(EVENT_EVADE, 1min);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_TALK:
                    Talk(SAY_CHALLENGE);
                    _events.ScheduleEvent(EVENT_ATTACK, 2s);
                    break;
                case EVENT_ATTACK:
                    me->SetImmuneToPC(false);
                    me->SetFaction(FACTION_MONSTER_2);
                    me->EngageWithTarget(ObjectAccessor::GetPlayer(*me, _playerGUID));
                    _events.ScheduleEvent(EVENT_FIREBALL, 1);
                    _events.ScheduleEvent(EVENT_FROSTNOVA, 5s);
                    break;
                case EVENT_FIREBALL:
                    DoCast(SPELL_FIREBALL);
                    _events.ScheduleEvent(EVENT_FIREBALL, 10s);
                    break;
                case EVENT_FROSTNOVA:
                    DoCastAOE(SPELL_FROSTNOVA);
                    _events.ScheduleEvent(EVENT_FROSTNOVA, 20s);
                    break;
                case EVENT_EVADE:
                    EnterEvadeMode();
                    break;
                }
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) override
        {
            CloseGossipMenuFor(player);
            me->StopMoving();
            StartFight(player);
            return true;
        }

    private:
        EventMap _events;
        ObjectGuid _playerGUID;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_magister_aledisAI(creature);
    }
};

enum WatchCommanderLeonus
{
    SAY_COVER = 0,

    EVENT_START = 1,
    EVENT_CAST  = 2,
    EVENT_END   = 3,

    NPC_INFERNAL_RAIN   = 18729,
    NPC_FEAR_CONTROLLER = 19393,
    SPELL_INFERNAL_RAIN = 33814,
    SPELL_FEAR          = 33815  // Serverside spell
};

struct npc_watch_commander_leonus : public ScriptedAI
{
    npc_watch_commander_leonus(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        ScriptedAI::JustAppeared();

        _events.Reset();
        _events.ScheduleEvent(EVENT_START, 2min, 10min);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_START:
                {
                    Talk(SAY_COVER);
                    me->HandleEmoteCommand(EMOTE_ONESHOT_SHOUT);

                    std::list<Creature*> dummies;
                    for (uint32 entry : { NPC_INFERNAL_RAIN, NPC_FEAR_CONTROLLER })
                    {
                        Trinity::AllCreaturesOfEntryInRange pred(me, entry);
                        Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange> searcher(me, dummies, pred);
                        Cell::VisitAllObjects(me, searcher, 500.0f);
                    }

                    for (Creature* dummy : dummies)
                        if (dummy->GetCreatureData()->movementType == 0)
                            dummy->AI()->SetData(EVENT_START, 0);

                    _events.Repeat(1h);
                    break;
                }
            }
        }

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
};

struct npc_infernal_rain_hellfire : public ScriptedAI
{
    npc_infernal_rain_hellfire(Creature* creature) : ScriptedAI(creature) { }

    void SetData(uint32 type, uint32 /*data*/) override
    {
        if (type != EVENT_START)
            return;

        RebuildTargetList();
        _events.ScheduleEvent(EVENT_CAST, 0s, 1s);
        _events.ScheduleEvent(EVENT_END, 1min);
    }

    void RebuildTargetList()
    {
        _targets.clear();

        std::vector<Creature*> others;
        Trinity::AllCreaturesOfEntryInRange pred(me, NPC_INFERNAL_RAIN);
        Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange> searcher(me, others, pred);
        Cell::VisitAllObjects(me, searcher, 500.0f);
        for (Creature* other : others)
            if (other->GetCreatureData()->movementType == 2)
                _targets.push_back(other->GetGUID());
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CAST:
                {
                    if (Creature* target = ObjectAccessor::GetCreature(*me, Trinity::Containers::SelectRandomContainerElement(_targets)))
                    {
                        CastSpellExtraArgs args;
                        args.AddSpellMod(SPELLVALUE_MAX_TARGETS, 1);
                        me->CastSpell(target, SPELL_INFERNAL_RAIN, args);
                    }

                    _events.Repeat(1s, 2s);
                    break;
                }
                case EVENT_END:
                    _events.Reset();
                    break;
            }
        }
    }

    private:
        EventMap _events;
        std::vector<ObjectGuid> _targets;
};

struct npc_fear_controller : public ScriptedAI
{
    npc_fear_controller(Creature* creature) : ScriptedAI(creature) { }

    void SetData(uint32 type, uint32 /*data*/) override
    {
        if (type != EVENT_START)
            return;

        _events.ScheduleEvent(EVENT_CAST, 0s, 1s);
        _events.ScheduleEvent(EVENT_END, 1min);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CAST:
                    DoCastAOE(SPELL_FEAR);
                    _events.Repeat(10s);
                    break;
                case EVENT_END:
                    _events.Reset();
                    break;
            }
        }
    }

    private:
        EventMap _events;
};

void AddSC_hellfire_peninsula()
{
    new npc_aeranas();
    new npc_ancestral_wolf();
    new npc_wounded_blood_elf();
    new npc_fel_guard_hound();
    new npc_colonel_jules();
    new npc_barada();
    new npc_magister_aledis();
    RegisterCreatureAI(npc_watch_commander_leonus);
    RegisterCreatureAI(npc_infernal_rain_hellfire);
    RegisterCreatureAI(npc_fear_controller);
}
