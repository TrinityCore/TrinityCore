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

#include "ScriptMgr.h"
#include "blackwing_lair.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "TemporarySummon.h"

enum Events
{
    // Victor Nefarius
    EVENT_SPAWN_ADD            = 1,
    EVENT_SHADOW_BOLT          = 2,
    EVENT_FEAR                 = 3,
    EVENT_MIND_CONTROL         = 4,
    // Nefarian
    EVENT_SHADOWFLAME          = 5,
    EVENT_VEILOFSHADOW         = 6,
    EVENT_CLEAVE               = 7,
    EVENT_TAILLASH             = 8,
    EVENT_CLASSCALL            = 9,
    // UBRS
    EVENT_CHAOS_1              = 10,
    EVENT_CHAOS_2              = 11,
    EVENT_PATH_2               = 12,
    EVENT_PATH_3               = 13,
    EVENT_SUCCESS_1            = 14,
    EVENT_SUCCESS_2            = 15,
    EVENT_SUCCESS_3            = 16,
};

enum Says
{
    // Nefarius
    // UBRS
    SAY_CHAOS_SPELL            = 9,
    SAY_SUCCESS                = 10,
    SAY_FAILURE                = 11,
    // BWL
    SAY_GAMESBEGIN_1           = 12,
    SAY_GAMESBEGIN_2           = 13,
 // SAY_VAEL_INTRO             = 14, Not used - when he corrupts Vaelastrasz

    // Nefarian
    SAY_RANDOM                 = 0,
    SAY_RAISE_SKELETONS        = 1,
    SAY_SLAY                   = 2,
    SAY_DEATH                  = 3,

    SAY_MAGE                   = 4,
    SAY_WARRIOR                = 5,
    SAY_DRUID                  = 6,
    SAY_PRIEST                 = 7,
    SAY_PALADIN                = 8,
    SAY_SHAMAN                 = 9,
    SAY_WARLOCK                = 10,
    SAY_HUNTER                 = 11,
    SAY_ROGUE                  = 12,
    SAY_DEATH_KNIGHT           = 13
};

enum Gossip
{
   GOSSIP_ID                   = 6045,
   GOSSIP_OPTION_ID            = 0
};

enum Paths
{
    NEFARIUS_PATH_2            = 1379671,
    NEFARIUS_PATH_3            = 1379672
};

enum GameObjects
{
    GO_PORTCULLIS_ACTIVE       = 164726,
    GO_PORTCULLIS_TOBOSSROOMS  = 175186
};

enum Creatures
{
    NPC_BRONZE_DRAKANOID       = 14263,
    NPC_BLUE_DRAKANOID         = 14261,
    NPC_RED_DRAKANOID          = 14264,
    NPC_GREEN_DRAKANOID        = 14262,
    NPC_BLACK_DRAKANOID        = 14265,
    NPC_CHROMATIC_DRAKANOID    = 14302,
    NPC_BONE_CONSTRUCT         = 14605,
    // UBRS
    NPC_GYTH                   = 10339
};

enum Spells
{
    // Victor Nefarius
    // UBRS Spells
    SPELL_CHROMATIC_CHAOS       = 16337, // Self Cast hits 10339
    SPELL_VAELASTRASZZ_SPAWN    = 16354, // Self Cast Depawn one sec after
    // BWL Spells
    SPELL_SHADOWBOLT            = 22677,
    SPELL_SHADOWBOLT_VOLLEY     = 22665,
    SPELL_SHADOW_COMMAND        = 22667,
    SPELL_FEAR                  = 22678,

    SPELL_NEFARIANS_BARRIER     = 22663,

    // Nefarian
    SPELL_SHADOWFLAME_INITIAL   = 22992,
    SPELL_SHADOWFLAME           = 22539,
    SPELL_BELLOWINGROAR         = 22686,
    SPELL_VEILOFSHADOW          = 7068,
    SPELL_CLEAVE                = 20691,
    SPELL_TAILLASH              = 23364,

    SPELL_MAGE                  = 23410,     // wild magic
    SPELL_WARRIOR               = 23397,     // beserk
    SPELL_DRUID                 = 23398,     // cat form
    SPELL_PRIEST                = 23401,     // corrupted healing
    SPELL_PALADIN               = 23418,     // syphon blessing
    SPELL_SHAMAN                = 23425,     // totems
    SPELL_WARLOCK               = 23427,     // infernals
    SPELL_HUNTER                = 23436,     // bow broke
    SPELL_ROGUE                 = 23414,     // Paralise
    SPELL_DEATH_KNIGHT          = 49576      // Death Grip

// 19484
// 22664
// 22674
// 22666
};

Position const DrakeSpawnLoc[2] = // drakonid
{
    {-7591.151855f, -1204.051880f, 476.800476f, 3.0f},
    {-7514.598633f, -1150.448853f, 476.796570f, 3.0f}
};

Position const NefarianLoc[2] =
{
    {-7449.763672f, -1387.816040f, 526.783691f, 3.0f}, // nefarian spawn
    {-7535.456543f, -1279.562500f, 476.798706f, 3.0f}  // nefarian move
};

uint32 const Entry[5] = {NPC_BRONZE_DRAKANOID, NPC_BLUE_DRAKANOID, NPC_RED_DRAKANOID, NPC_GREEN_DRAKANOID, NPC_BLACK_DRAKANOID};

class boss_victor_nefarius : public CreatureScript
{
public:
    boss_victor_nefarius() : CreatureScript("boss_victor_nefarius") { }

    struct boss_victor_nefariusAI : public BossAI
    {
        boss_victor_nefariusAI(Creature* creature) : BossAI(creature, DATA_NEFARIAN)
        {
            Initialize();
        }

        void Initialize()
        {
            SpawnedAdds = 0;
        }

        void Reset() override
        {
            Initialize();

            if (me->GetMapId() == 469)
            {
                if (!me->FindNearestCreature(NPC_NEFARIAN, 1000.0f, true))
                    _Reset();

                me->SetVisible(true);
                me->SetPhaseMask(1, true);
                me->SetUInt32Value(UNIT_NPC_FLAGS, 1);
                me->SetFaction(FACTION_FRIENDLY);
                me->SetStandState(UNIT_STAND_STATE_SIT_HIGH_CHAIR);
                me->RemoveAura(SPELL_NEFARIANS_BARRIER);
            }
        }

        void JustReachedHome() override
        {
            Reset();
        }

        void BeginEvent(Player* target)
        {
            _JustEngagedWith(target);

            Talk(SAY_GAMESBEGIN_2);

            me->SetFaction(FACTION_DRAGONFLIGHT_BLACK);
            me->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_NONE);
            DoCast(me, SPELL_NEFARIANS_BARRIER);
            me->SetStandState(UNIT_STAND_STATE_STAND);
            me->SetImmuneToPC(false);
            AttackStart(target);
            events.ScheduleEvent(EVENT_SHADOW_BOLT, 3s, 10s);
            events.ScheduleEvent(EVENT_FEAR, 10s, 20s);
            //events.ScheduleEvent(EVENT_MIND_CONTROL, 30s, 35s);
            events.ScheduleEvent(EVENT_SPAWN_ADD, 10s);
        }

        void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
        {
            if (summon->GetEntry() != NPC_NEFARIAN)
            {
                summon->UpdateEntry(NPC_BONE_CONSTRUCT);
                summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                summon->SetReactState(REACT_PASSIVE);
                summon->SetStandState(UNIT_STAND_STATE_DEAD);
            }
        }

        void JustSummoned(Creature* /*summon*/) override { }

        void SetData(uint32 type, uint32 data) override
        {
            if ( type == 1 && data == 1)
            {
                me->StopMoving();
                events.ScheduleEvent(EVENT_PATH_2, 9s);
            }

            if (type == 1 && data == 2)
                events.ScheduleEvent(EVENT_SUCCESS_1, 5s);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_PATH_2:
                            me->GetMotionMaster()->MovePath(NEFARIUS_PATH_2, false);
                            events.ScheduleEvent(EVENT_CHAOS_1, 7s);
                            break;
                        case EVENT_CHAOS_1:
                            if (Creature* gyth = me->FindNearestCreature(NPC_GYTH, 75.0f, true))
                            {
                                me->SetFacingToObject(gyth);
                                Talk(SAY_CHAOS_SPELL);
                            }
                            events.ScheduleEvent(EVENT_CHAOS_2, 2s);
                            break;
                        case EVENT_CHAOS_2:
                            DoCast(SPELL_CHROMATIC_CHAOS);
                            me->SetFacingTo(1.570796f);
                            break;
                        case EVENT_SUCCESS_1:
                            if (Unit* player = me->SelectNearestPlayer(60.0f))
                            {
                                me->SetFacingToObject(player);
                                Talk(SAY_SUCCESS);
                                if (GameObject* portcullis1 = me->FindNearestGameObject(GO_PORTCULLIS_ACTIVE, 65.0f))
                                    portcullis1->SetGoState(GO_STATE_ACTIVE);
                                if (GameObject* portcullis2 = me->FindNearestGameObject(GO_PORTCULLIS_TOBOSSROOMS, 80.0f))
                                    portcullis2->SetGoState(GO_STATE_ACTIVE);
                            }
                            events.ScheduleEvent(EVENT_SUCCESS_2, 4s);
                            break;
                        case EVENT_SUCCESS_2:
                            DoCast(me, SPELL_VAELASTRASZZ_SPAWN);
                            me->DespawnOrUnsummon(1s);
                            break;
                        case EVENT_PATH_3:
                            me->GetMotionMaster()->MovePath(NEFARIUS_PATH_3, false);
                            break;
                        default:
                            break;
                    }
                }
                return;
            }

            // Only do this if we haven't spawned nefarian yet
            if (UpdateVictim() && SpawnedAdds <= 42)
            {
                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SHADOW_BOLT:
                            switch (urand(0, 1))
                            {
                                case 0:
                                    DoCastVictim(SPELL_SHADOWBOLT_VOLLEY);
                                    break;
                                case 1:
                                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 40, true))
                                        DoCast(target, SPELL_SHADOWBOLT);
                                    break;
                            }
                            ResetThreatList();
                            events.ScheduleEvent(EVENT_SHADOW_BOLT, 3s, 10s);
                            break;
                        case EVENT_FEAR:
                            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 40, true))
                                DoCast(target, SPELL_FEAR);
                            events.ScheduleEvent(EVENT_FEAR, 10s, 20s);
                            break;
                        case EVENT_MIND_CONTROL:
                            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 40, true))
                                DoCast(target, SPELL_SHADOW_COMMAND);
                            events.ScheduleEvent(EVENT_MIND_CONTROL, 30s, 35s);
                            break;
                        case EVENT_SPAWN_ADD:
                            for (uint8 i=0; i<2; ++i)
                            {
                                uint32 CreatureID;
                                if (urand(0, 2) == 0)
                                    CreatureID = NPC_CHROMATIC_DRAKANOID;
                                else
                                    CreatureID = Entry[urand(0, 4)];
                                if (Creature* dragon = me->SummonCreature(CreatureID, DrakeSpawnLoc[i]))
                                {
                                    dragon->SetFaction(FACTION_DRAGONFLIGHT_BLACK);
                                    dragon->AI()->AttackStart(me->GetVictim());
                                }

                                if (++SpawnedAdds >= 42)
                                {
                                    if (Creature* nefarian = me->SummonCreature(NPC_NEFARIAN, NefarianLoc[0]))
                                    {
                                        nefarian->setActive(true);
                                        nefarian->SetFarVisible(true);
                                        nefarian->SetCanFly(true);
                                        nefarian->SetDisableGravity(true);
                                        nefarian->CastSpell(nullptr, SPELL_SHADOWFLAME_INITIAL);
                                        nefarian->GetMotionMaster()->MovePoint(1, NefarianLoc[1]);
                                    }
                                    events.CancelEvent(EVENT_MIND_CONTROL);
                                    events.CancelEvent(EVENT_FEAR);
                                    events.CancelEvent(EVENT_SHADOW_BOLT);
                                    me->SetVisible(false);
                                    return;
                                }
                            }
                            events.ScheduleEvent(EVENT_SPAWN_ADD, 4s);
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }
            }
        }

        bool OnGossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override
        {
            if (menuId == GOSSIP_ID && gossipListId == GOSSIP_OPTION_ID)
            {
                CloseGossipMenuFor(player);
                Talk(SAY_GAMESBEGIN_1);
                BeginEvent(player);
            }
            return false;
        }

        private:
            uint32 SpawnedAdds;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackwingLairAI<boss_victor_nefariusAI>(creature);
    }
};

class boss_nefarian : public CreatureScript
{
public:
    boss_nefarian() : CreatureScript("boss_nefarian") { }

    struct boss_nefarianAI : public BossAI
    {
        boss_nefarianAI(Creature* creature) : BossAI(creature, DATA_NEFARIAN)
        {
            Initialize();
        }

        void Initialize()
        {
            Phase3 = false;
            canDespawn = false;
            DespawnTimer = 30000;
        }

        void Reset() override
        {
            Initialize();
        }

        void JustReachedHome() override
        {
            canDespawn = true;
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_SHADOWFLAME, 12s);
            events.ScheduleEvent(EVENT_FEAR, 25s, 35s);
            events.ScheduleEvent(EVENT_VEILOFSHADOW, 25s, 35s);
            events.ScheduleEvent(EVENT_CLEAVE, 7s);
            //events.ScheduleEvent(EVENT_TAILLASH, 10s);
            events.ScheduleEvent(EVENT_CLASSCALL, 30s, 35s);
            Talk(SAY_RANDOM);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            Talk(SAY_DEATH);
        }

        void KilledUnit(Unit* victim) override
        {
            if (rand32() % 5)
                return;

            Talk(SAY_SLAY, victim);
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (id == 1)
            {
                DoZoneInCombat();
                if (me->GetVictim())
                    AttackStart(me->GetVictim());
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (canDespawn && DespawnTimer <= diff)
            {
                instance->SetBossState(DATA_NEFARIAN, FAIL);

                std::list<Creature*> constructList;
                me->GetCreatureListWithEntryInGrid(constructList, NPC_BONE_CONSTRUCT, 500.0f);
                for (std::list<Creature*>::const_iterator itr = constructList.begin(); itr != constructList.end(); ++itr)
                    (*itr)->DespawnOrUnsummon();

            } else DespawnTimer -= diff;

            if (!UpdateVictim())
                return;

            if (canDespawn)
                canDespawn = false;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SHADOWFLAME:
                        DoCastVictim(SPELL_SHADOWFLAME);
                        events.ScheduleEvent(EVENT_SHADOWFLAME, 12s);
                        break;
                    case EVENT_FEAR:
                        DoCastVictim(SPELL_BELLOWINGROAR);
                        events.ScheduleEvent(EVENT_FEAR, 25s, 35s);
                        break;
                    case EVENT_VEILOFSHADOW:
                        DoCastVictim(SPELL_VEILOFSHADOW);
                        events.ScheduleEvent(EVENT_VEILOFSHADOW, 25s, 35s);
                        break;
                    case EVENT_CLEAVE:
                        DoCastVictim(SPELL_CLEAVE);
                        events.ScheduleEvent(EVENT_CLEAVE, 7s);
                        break;
                    case EVENT_TAILLASH:
                        // Cast NYI since we need a better check for behind target
                        DoCastVictim(SPELL_TAILLASH);
                        events.ScheduleEvent(EVENT_TAILLASH, 10s);
                        break;
                    case EVENT_CLASSCALL:
                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true))
                            switch (target->GetClass())
                        {
                            case CLASS_MAGE:
                                Talk(SAY_MAGE);
                                DoCast(me, SPELL_MAGE);
                                break;
                            case CLASS_WARRIOR:
                                Talk(SAY_WARRIOR);
                                DoCast(me, SPELL_WARRIOR);
                                break;
                            case CLASS_DRUID:
                                Talk(SAY_DRUID);
                                DoCast(target, SPELL_DRUID);
                                break;
                            case CLASS_PRIEST:
                                Talk(SAY_PRIEST);
                                DoCast(me, SPELL_PRIEST);
                                break;
                            case CLASS_PALADIN:
                                Talk(SAY_PALADIN);
                                DoCast(me, SPELL_PALADIN);
                                break;
                            case CLASS_SHAMAN:
                                Talk(SAY_SHAMAN);
                                DoCast(me, SPELL_SHAMAN);
                                break;
                            case CLASS_WARLOCK:
                                Talk(SAY_WARLOCK);
                                DoCast(me, SPELL_WARLOCK);
                                break;
                            case CLASS_HUNTER:
                                Talk(SAY_HUNTER);
                                DoCast(me, SPELL_HUNTER);
                                break;
                            case CLASS_ROGUE:
                                Talk(SAY_ROGUE);
                                DoCast(me, SPELL_ROGUE);
                                break;
                            case CLASS_DEATH_KNIGHT:
                                Talk(SAY_DEATH_KNIGHT);
                                DoCast(me, SPELL_DEATH_KNIGHT);
                                break;
                            default:
                                break;
                        }
                        events.ScheduleEvent(EVENT_CLASSCALL, 30s, 35s);
                        break;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }

            // Phase3 begins when health below 20 pct
            if (!Phase3 && HealthBelowPct(20))
            {
                std::list<Creature*> constructList;
                me->GetCreatureListWithEntryInGrid(constructList, NPC_BONE_CONSTRUCT, 500.0f);
                for (std::list<Creature*>::const_iterator itr = constructList.begin(); itr != constructList.end(); ++itr)
                    if ((*itr) && !(*itr)->IsAlive())
                    {
                        (*itr)->Respawn();
                        DoZoneInCombat((*itr));
                        (*itr)->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        (*itr)->SetReactState(REACT_AGGRESSIVE);
                        (*itr)->SetStandState(UNIT_STAND_STATE_STAND);
                    }

                Phase3 = true;
                Talk(SAY_RAISE_SKELETONS);
            }

            DoMeleeAttackIfReady();
        }

    private:
        bool canDespawn;
        uint32 DespawnTimer;
        bool Phase3;

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackwingLairAI<boss_nefarianAI>(creature);
    }
};

void AddSC_boss_nefarian()
{
    new boss_victor_nefarius();
    new boss_nefarian();
}
