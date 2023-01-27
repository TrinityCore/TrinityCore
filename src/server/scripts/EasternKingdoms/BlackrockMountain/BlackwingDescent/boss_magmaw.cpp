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
#include "blackwing_descent.h"
#include "Map.h"
#include "Vehicle.h"
#include "MoveSplineInit.h"

enum Spells
{
    SPELL_LAVA_SPEW                 = 77839,
    SPELL_MAGMA_SPIT                = 78068,
    SPELL_PILLAR_OF_FLAME           = 78006,
    SPELL_PILLAR_OF_FLAME_SUMMON    = 77998,
    SPELL_BERSERK                   = 26662,
    SPELL_MANGLE                    = 89773,
    SPELL_MANGLE_PERIODIC           = 78412,
    SPELL_IMPALE_SELF               = 77907,
    SPELL_MASSIVE_CRASH             = 88253,
    SPELL_QUEST_INVIS_5             = 95478,
    SPELL_POINT_OF_VULNERABILITY    = 79010,
    SPELL_POINT_OF_VULNERABILITY2   = 79011,
    SPELL_LOCATION_MARKER           = 88458,
    SPELL_CHAIN_R                   = 77929,
    SPELL_CHAIN_L                   = 77940,
    SPELL_BLAZING_INFERNO           = 92153,
    SPELL_SHADOWFLAME_BARRAGE       = 78621,
    SPELL_MASSIVE_CRASH_DMG         = 88287,

    // Trash
    SPELL_CHAIN_VISUAL              = 79025,
    SPELL_WHIRLWIND                 = 79973,
    SPELL_THUNDERCLAP               = 79604,
    SPELL_DRAKONID_RUSH             = 79630,
    SPELL_VENGEFUL_RAGE             = 80035,
    SPELL_LAUNCH_HOOK_R             = 77917,
    SPELL_LAUNCH_HOOK_L             = 77941,
    SPELL_PILLAR_OF_FLAME_PRE       = 78017,
    SPELL_PILLAR_OF_FLAME_PERIODIC  = 77970,
    SPELL_FIERY_SLASH               = 92144,
    SPELL_ARMAGEDDON                = 92177,
    SPELL_IGNITION_AURA             = 92131,
    SPELL_IGNITION_SUMMON           = 92129
};

enum Events
{
    EVENT_LAVA_SPEW                 = 1,
    EVENT_MAGMA_SPIT,
    EVENT_PILLAR_OF_FLAME,
    EVENT_MANGLE,
    EVENT_IGNITION,
    EVENT_MASSIVE_CRASH,
    EVENT_MASSIVE_CRASH_END,
    EVENT_IMPALE_END,
    EVENT_EJECT,
    EVENT_BLAZING_INFERNO,
    EVENT_SHADOWFLAME_BARRAGE
};

enum Phases
{
    PHASE_NORMAL                    = 1,
    PHASE_HEAD,
};

enum Quotes
{
    EMOTE_CRASH,
    EMOTE_IMPALE,
    EMOTE_PILLAR,
    EMOTE_CHANNEL    = 468,
};

enum Misc
{
    DATA_CHAINS                     = 1,
    DATA_BELOW_30                   = 2,
    NPC_HEROIC_NEFARIAN             = 49427
};

static const Position polygonPts[2][4] =
{
    {
        {-352.638092f, -26.385580f, 212.051483f, 0.0f}, // pt1
        {-352.118378f, -93.673981f, 214.040604f, 0.0f}, // pt2
        {-307.451660f, -37.038906f, 211.607224f, 0.0f}, // start
        {-356.105591f, -58.072796f, 216.568405f, 0.0f}, // center
    },
    {
        {-291.826904f, -50.995594f, 212.465195f, 0.0f}, // pt1
        {-352.118378f, -93.673981f, 214.040604f, 0.0f}, // pt2
        {-307.451660f, -37.038906f, 211.607224f, 0.0f}, // start
        {-295.610260f, -92.390831f, 213.878601f, 0.0f}, // center
    }
};

static const Position ejectPos = {-317.484100f, -55.254810f, 212.445892f, 0.0f};
static const Position nefarianPos = {-419.323914f, 13.946201f, 231.422546f, 0.0f};
static const Position movePos = {-286.590424f, 0.089617f, 245.260162f, 4.6f};

class boss_magmaw : public CreatureScript
{
    struct boss_magmawAI : public BossAI
    {
        boss_magmawAI(Creature * c) : BossAI(c, DATA_MAGMAW)
        {
            me->AddUnitMovementFlag(MOVEMENTFLAG_DISABLE_GRAVITY);
            me->SetHoverHeight(213.f);
            me->ApplySpellImmune(0, IMMUNITY_ID, 80035, true); // immune to vengeful rage
        }

        void Reset() override
        {
            below30 = false;
            enrageTimer = 600000;
            me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
            me->SetReactState(REACT_AGGRESSIVE);
            SetPincers(false);
            veh = me->GetVehicleKit();
            if(Unit * head = veh->GetPassenger(4))
            {
                head->ToCreature()->AI()->EnterEvadeMode();
                me->CastSpell(head, SPELL_POINT_OF_VULNERABILITY, true);
            }
            if(IsHeroic())
                if(Creature * nefarian = ObjectAccessor::GetCreature(*me, nefarianGUID))
                    nefarian->DespawnOrUnsummon();
            _Reset();
        }

        void PassengerBoarded(Unit* /*who*/, int8 seatId, bool apply) override
        {
            if(seatId == 2 && apply)
            {
                //who->ClearUnitState(UNIT_STATE_ONVEHICLE);
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
            me->AddDynamicFlag(UNIT_DYNFLAG_LOOTABLE);
            _JustDied();
        }

        void SetIdle()
        {
            me->SetReactState(REACT_PASSIVE);
            me->GetMotionMaster()->Clear();
            me->GetMotionMaster()->MoveIdle();
            me->SetTarget(ObjectGuid::Empty);
        }

        void DoAction(const int32 action) override
        {
            if(action == DATA_CHAINS)
            {
                SetIdle();
                SetPincers(false);
                Talk(EMOTE_IMPALE);
                events.SetPhase(PHASE_HEAD);
                Movement::MoveSplineInit init(me);
                init.SetFacing(me->GetHomePosition().GetOrientation());
                me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);

                if(Unit * passenger = veh->GetPassenger(2)) // Eject the tank
                {
                    passenger->ExitVehicle(&ejectPos);
                    passenger->RemoveAurasDueToSpell(SPELL_MANGLE);
                    passenger->RemoveAurasDueToSpell(SPELL_MANGLE_PERIODIC);
                }
                if(Unit * head = veh->GetPassenger(4)) // Make the head Visible
                {
                    head->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                    head->RemoveAurasDueToSpell(SPELL_QUEST_INVIS_5);
                    if(!head->IsInCombat())
                        if(Unit * victim = me->GetVictim())
                            head->SetInCombatWith(victim);
                    me->CastSpell(head, SPELL_POINT_OF_VULNERABILITY, true);
                    head->SetHealth(me->GetHealth());
                }
                if(Unit * stalker = me->FindNearestCreature(NPC_SPIKE_STALKER, 100.0f)) // Cast Arrow Visual
                    me->CastSpell(stalker, SPELL_LOCATION_MARKER, true);

                DoCast(SPELL_IMPALE_SELF);
                events.CancelEvent(EVENT_EJECT);
                events.DelayEvents(36000);
                events.ScheduleEvent(EVENT_IMPALE_END, 36000);
            }
        }

        void JustSummoned(Creature* summon) override
        {
            switch(summon->GetEntry())
            {
            case NPC_HEROIC_NEFARIAN:
                nefarianGUID = summon->GetGUID();
                return;
            case NPC_MAGMAWS_HEAD2:
                me->CastSpell(summon, SPELL_POINT_OF_VULNERABILITY, true);
                summon->SetBoundingRadius(50.0f);
                summon->SetCombatReach(50.0f);
                break;
            case NPC_MAGMAWS_HEAD:
            case NPC_MAGMAWS_PINCER:
            case NPC_MAGMAWS_PINCER2:
                break;
            default:
                BossAI::JustSummoned(summon);
                break;
            }
        }

        void EnterCombat(Unit* who) override
        {
            events.SetPhase(PHASE_NORMAL);
            events.ScheduleEvent(EVENT_LAVA_SPEW, urand(5000, 8000));
            events.ScheduleEvent(EVENT_MAGMA_SPIT, urand(8000, 10000));
            events.ScheduleEvent(EVENT_PILLAR_OF_FLAME, urand(12000, 15000));
            events.ScheduleEvent(EVENT_MANGLE, urand(25000, 30000));

            if(IsHeroic())
            {
                if(Creature * nefarian = me->SummonCreature(NPC_HEROIC_NEFARIAN, nefarianPos))
                {
                    nefarian->SetCanFly(true);
                    nefarian->SetReactState(REACT_PASSIVE);
                    nefarian->SetHomePosition(movePos);
                    nefarian->AI()->EnterEvadeMode();
                }
                events.ScheduleEvent(EVENT_BLAZING_INFERNO, 15000);
            }

            BossAI::EnterCombat(who);
        }

        void MoveInLineOfSight(Unit* /*who*/) override {}

        void AttackStart(Unit* target) override
        {
            if (me->Attack(target, true))
                DoStartNoMovement(target);
        }

        void DamageTaken(Unit* /*done_by*/, uint32&damage) override
        {
            if(!below30 && me->HealthBelowPctDamaged(30, damage))
            {
                below30 = true;
                events.CancelEvent(EVENT_BLAZING_INFERNO);
                events.ScheduleEvent(EVENT_SHADOWFLAME_BARRAGE, 2000);
            }
        }

        void SetPincers(bool on)
        {
            if(Vehicle * veh = me->GetVehicleKit())
            {
                for(int8 i=0; i<=1; ++i)
                {
                    Unit * pincer = veh->GetPassenger(i);
                    if(pincer && on)
                    {
                        pincer->SetDisplayId(34532);
                        pincer->SetBoundingRadius(50.0f);
                        pincer->SetCombatReach(50.0f);
                        pincer->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE));
                    }
                    else if(pincer)
                    {
                        if (Vehicle* pincerVehicle = pincer->GetVehicleKit())
                            if (Unit* passenger = pincerVehicle->GetPassenger(0))
                                passenger->ExitVehicle(&ejectPos);
                        pincer->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE));
                    }
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if(!UpdateVictim())
                return;

            events.Update(diff);

            if(enrageTimer <= diff)
            {
                DoCast(SPELL_BERSERK);
                enrageTimer = 600000;
            }else enrageTimer -= diff;

            if(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_LAVA_SPEW:
                        DoCast(me, SPELL_LAVA_SPEW);
                        events.ScheduleEvent(EVENT_LAVA_SPEW, urand(15000, 20000), 0, PHASE_NORMAL);
                        break;
                    case EVENT_MAGMA_SPIT:
                        if(Unit * victim = me->GetVictim())
                        {
                            float dist = me->GetDistance(victim);
                            if(dist >= 60.0f)
                                EnterEvadeMode();
                            else if(dist >= INTERACTION_DISTANCE)
                                DoCast(victim, SPELL_MAGMA_SPIT, true);
                        }
                        events.ScheduleEvent(EVENT_MAGMA_SPIT, urand(3000, 5000), 0, PHASE_NORMAL);
                        break;
                    case EVENT_PILLAR_OF_FLAME:
                        {
                            Unit * target = SelectTarget(SELECT_TARGET_RANDOM, 0, -15.0f, true);
                            if(!target)
                                target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true);
                            if(target)
                                me->SummonCreature(NPC_PILLAR_OF_FLAME_TRIGGER, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN, 20000);
                            Talk(EMOTE_PILLAR);
                            DoCast(me, SPELL_PILLAR_OF_FLAME);
                            events.ScheduleEvent(EVENT_PILLAR_OF_FLAME, 30000, 0, PHASE_NORMAL);
                        }
                        break;
                    case EVENT_MANGLE:
                        DoCastVictim(SPELL_MANGLE, true);
                        SetIdle();

                        events.ScheduleEvent(EVENT_MANGLE, 95000);
                        events.ScheduleEvent(EVENT_IGNITION, 2000);
                        events.SetPhase(PHASE_HEAD);
                        break;
                    case EVENT_IGNITION:
                    {
                        bool pos = urand(0, 1);
                        Movement::MoveSplineInit init(me);
                        init.SetFacing(pos ? 4.7f : 3.47f);

                        std::list<Position> summonPos;
                          for (uint8 i = 0; i < 8; i++)
                            me->SummonCreature(NPC_IGNITION_TRIGGER, me->GetPositionX() + i, me->GetPositionY() + i, me->GetPositionZ(), 1.5f, TEMPSUMMON_TIMED_DESPAWN, 65100);
                            summonPos.clear();
                        events.DelayEvents(10000);
                        events.ScheduleEvent(EVENT_MASSIVE_CRASH, 3000);
                        events.ScheduleEvent(EVENT_EJECT, 40000);
                        break;
                    }
                    case EVENT_MASSIVE_CRASH:
                        Talk(EMOTE_CRASH);
                        DoCast(SPELL_MASSIVE_CRASH);
                        me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                        SetPincers(true);
                        events.ScheduleEvent(EVENT_MASSIVE_CRASH_END, 10000);
                        break;
                    case EVENT_IMPALE_END:
                        if(Unit * head = veh->GetPassenger(4)) // make the head unattackable
                        {
                            head->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                            head->CastSpell(head, SPELL_QUEST_INVIS_5, true);
                        }
                        me->RemoveAurasDueToSpell(SPELL_CHAIN_R);
                        me->RemoveAurasDueToSpell(SPELL_CHAIN_L);
                        events.RescheduleEvent(EVENT_MAGMA_SPIT, 5000);
                        events.RescheduleEvent(EVENT_LAVA_SPEW, 8000);
                        events.RescheduleEvent(EVENT_MAGMA_SPIT, urand(8000, 10000));
                        events.RescheduleEvent(EVENT_PILLAR_OF_FLAME, urand(8000, 12000));
                        events.RescheduleEvent(EVENT_MANGLE, urand(25000, 30000));
                    case EVENT_MASSIVE_CRASH_END:
                        me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                        me->SetReactState(REACT_AGGRESSIVE);
                        events.SetPhase(PHASE_NORMAL);
                        if(Unit * victim = me->GetVictim()) // resume combat
                        {
                            DoStartNoMovement(victim);
                            me->SetTarget(victim->GetGUID());
                        }
                        break;
                    case EVENT_EJECT:
                        // Tank in seat 3 will be dead by then
                        SetPincers(false);
                        break;
                    case EVENT_BLAZING_INFERNO:
                        if(Creature * nefarian = ObjectAccessor::GetCreature(*me, nefarianGUID))
                            if(Unit * target = SelectTarget(SELECT_TARGET_RANDOM, 0, -5.0f, true))
                                nefarian->CastSpell(target, SPELL_BLAZING_INFERNO, true);
                        events.ScheduleEvent(EVENT_BLAZING_INFERNO, urand(20000, 25000));
                        break;
                    case EVENT_SHADOWFLAME_BARRAGE:
                        if(Creature * nefarian = ObjectAccessor::GetCreature(*me, nefarianGUID))
                        {
                            if(nefarian->HasUnitState(UNIT_STATE_CASTING))
                                events.ScheduleEvent(EVENT_SHADOWFLAME_BARRAGE, 200);
                            else
                            {
                                nefarian->CastSpell(nefarian, SPELL_SHADOWFLAME_BARRAGE, false);
                                events.ScheduleEvent(EVENT_SHADOWFLAME_BARRAGE, 2100);
                            }
                        }
                        break;
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
        private:
            bool below30;
            ObjectGuid nefarianGUID;
            Vehicle * veh;
            uint32 enrageTimer;
    };
public:
    boss_magmaw() : CreatureScript("boss_magmaw") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_magmawAI(creature);
    }
};

class npc_spike_stalker : public CreatureScript
{
    struct npc_spike_stalkerAI : public ScriptedAI
    {
        npc_spike_stalkerAI(Creature * creature) : ScriptedAI(creature) {}

        void SpellHit(Unit* /*caster*/, const SpellInfo* spell) override
        {
            if((spell->Id == SPELL_LAUNCH_HOOK_R && me->HasAura(SPELL_LAUNCH_HOOK_L)) ||
                (spell->Id == SPELL_LAUNCH_HOOK_L && me->HasAura(SPELL_LAUNCH_HOOK_R)))
            {
                if(Creature * magmaw = me->FindNearestCreature(BOSS_MAGMAW, 100.0f))
                {
                    magmaw->AI()->DoAction(DATA_CHAINS);
                    DoCast(me, SPELL_CHAIN_R, true);
                    DoCast(me, SPELL_CHAIN_L, true);
                }
            }
        }

        void UpdateAI(uint32 /*diff*/) override
        {
        }
    };

public:
    npc_spike_stalker() : CreatureScript("npc_spike_stalker") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_spike_stalkerAI(creature);
    }
};

class npc_pillar_of_flame : public CreatureScript
{
    struct npc_pillar_of_flameAI : public ScriptedAI
    {
        npc_pillar_of_flameAI(Creature * creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            DoCast(SPELL_PILLAR_OF_FLAME_PRE);
            done = false;
            actionTimer = 3000;
        }

        void UpdateAI(uint32 diff) override
        {
            if(!done)
            {
                if(actionTimer <= diff)
                {
                    done = true;
                    DoCast(SPELL_PILLAR_OF_FLAME_PERIODIC);
                }else actionTimer -= diff;
            }
        }

    private:
        bool done;
        uint32 actionTimer;
    };

public:
    npc_pillar_of_flame() : CreatureScript("npc_pillar_of_flame") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_pillar_of_flameAI(creature);
    }
};

class npc_lava_parasite : public CreatureScript
{
    enum
    {
        SPELL_PARASITIC_INFECTION       = 78097,
    };

    struct npc_lava_parasiteAI : public ScriptedAI
    {
        npc_lava_parasiteAI(Creature * creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            checkTimer = 3000;
        }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            DoZoneInCombat();
            if(Creature * magmaw = me->FindNearestCreature(BOSS_MAGMAW, 200.0f))
                magmaw->AI()->JustSummoned(me);
        }

        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
        {
            if(spell->Id == SPELL_PARASITIC_INFECTION)
            {
                if(Unit * victim = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true, -SPELL_PARASITIC_INFECTION))
                {
                    me->getThreatManager().modifyThreatPercent(target, -100);
                    me->AddThreat(victim, 5000.0f);
                    AttackStart(victim);
                }
            }
        }
    private:
        uint32 checkTimer;
    };

public:
    npc_lava_parasite() : CreatureScript("npc_lava_parasite") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_lava_parasiteAI(creature);
    }
};

class npc_drakonid_drudge : public CreatureScript
{
    struct npc_drakonid_drudgeAI : public ScriptedAI
    {
        npc_drakonid_drudgeAI(Creature * creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            DoCast(SPELL_CHAIN_VISUAL);
            me->SetEmoteState(EMOTE_STATE_SPELL_CHANNEL_OMNI);
            chargeTimer = 20000;
            thunderclapTimer = 10000;
            whirlwindTimer = 30000;
            whirlwind = false;
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (Unit * drudge = me->FindNearestCreature(me->GetEntry(), 100.0f))
                me->CastSpell(drudge, SPELL_VENGEFUL_RAGE, true);

            if (InstanceScript * instance = me->GetInstanceScript())
            {
                instance->SetData(DATA_DRAKONID, 0);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_VENGEFUL_RAGE);
            }
        }

        void EnterCombat(Unit* who) override
        {
            me->SetEmoteState(EMOTE_ONESHOT_NONE);
            if(Unit * magmaw = me->FindNearestCreature(BOSS_MAGMAW, 100.0f))
                magmaw->RemoveAurasDueToSpell(SPELL_CHAIN_VISUAL);
            DoStartMovement(who);
        }

        void UpdateAI(uint32 diff) override
        {
            if(!UpdateVictim())
                return;

            if(chargeTimer <= diff)
            {
                if(Unit * target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 80.0f, true))
                {
                    me->getThreatManager().resetAllAggro();
                    me->TauntApply(target);
                    me->AddThreat(target, 20000.0f);
                    DoCast(target, SPELL_DRAKONID_RUSH, true);
                    whirlwindTimer = 6000;
                    whirlwind = true;
                }
                chargeTimer = 20000;
            }else chargeTimer -= diff;

            if(whirlwind)
            {
                if(whirlwindTimer <= diff)
                {
                    DoCast(SPELL_WHIRLWIND);
                    whirlwind = false;
                }else whirlwindTimer -= diff;
            }

            if(thunderclapTimer <= diff)
            {
                DoCast(SPELL_THUNDERCLAP);
                thunderclapTimer = urand(10000, 12000);
            }else thunderclapTimer -= diff;

            DoMeleeAttackIfReady();
        }
    private:
        uint32 chargeTimer;
        uint32 thunderclapTimer;
        bool whirlwind;
        uint32 whirlwindTimer;
    };

public:
    npc_drakonid_drudge() : CreatureScript("npc_drakonid_drudge") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_drakonid_drudgeAI(creature);
    }
};

class npc_magmaws_pincer : public VehicleScript
{
public:
    npc_magmaws_pincer() : VehicleScript("npc_magmaws_pincer") { }

    void OnAddPassenger(Vehicle* veh, Unit* /*passenger*/, int8 /*seatId*/) override
    {
        if (Unit* unit = veh->GetBase())
        {
            unit->SetDisplayId(11686);
            unit->SetBoundingRadius(0.5f);
            unit->SetCombatReach(0.5f);
        }
    }
};

class npc_blazing_bone_construct : public CreatureScript
{
    struct npc_blazing_bone_constructAI : public ScriptedAI
    {
        npc_blazing_bone_constructAI(Creature * creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            armageddon = false;
            slashTimer = 5000;
            summonTimer = 5000;
        }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            if(Creature * magmaw = me->FindNearestCreature(BOSS_MAGMAW, 200.0f))
                magmaw->AI()->JustSummoned(me);
            Position pos;
            for(int i=0; i<=7; ++i)
            {
                pos = me->GetRandomNearPosition(5.0f);
                me->SummonCreature(NPC_IGNITION_TRIGGER, pos, TEMPSUMMON_TIMED_DESPAWN, 45000);
            }
        }

        void JustSummoned(Creature* summon) override
        {
            if(summon->GetEntry() == NPC_IGNITION_TRIGGER)
            {
                summon->RemoveAllAuras();
                summon->CastSpell(summon, SPELL_IGNITION_AURA, true);
                summon->GetMotionMaster()->MoveRandom(20.0f);
            }

            if(Creature * magmaw = me->FindNearestCreature(BOSS_MAGMAW, 200.0f))
                magmaw->AI()->JustSummoned(summon);
        }

        void DamageTaken(Unit* /*done_by*/, uint32&damage) override
        {
            if(!armageddon && me->HealthBelowPctDamaged(20, damage))
            {
                armageddon = true;
                DoCast(SPELL_ARMAGEDDON);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if(!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if(summonTimer <= diff)
            {
                DoCast(me, SPELL_IGNITION_SUMMON, true);
                summonTimer = 1000;
            }else summonTimer -= diff;

            if(slashTimer <= diff)
            {
                DoCast(me, SPELL_FIERY_SLASH, true);
                slashTimer = urand(8000, 10000);
            }else slashTimer -= diff;

            DoMeleeAttackIfReady();
        }
    private:
        uint32 slashTimer;
        uint32 summonTimer;
        bool armageddon;
    };

public:
    npc_blazing_bone_construct() : CreatureScript("npc_blazing_bone_construct") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_blazing_bone_constructAI(creature);
    }
};

class spell_magmaw_massive_crash : public SpellScriptLoader // 88253.
{
public:
    spell_magmaw_massive_crash() : SpellScriptLoader("spell_magmaw_massive_crash") { }

    class spell_magmaw_massive_crashSpellScript : public SpellScript
    {
        PrepareSpellScript(spell_magmaw_massive_crashSpellScript);

        /*bool Validate(SpellEntry const* spellEntry)
        {
            return true;
        }*/

        bool Load() override
        {
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
                caster->CastSpell(caster, SPELL_MASSIVE_CRASH_DMG, true);
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_magmaw_massive_crashSpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_magmaw_massive_crashSpellScript();
    }
};

void AddSC_boss_magmaw()
{
    new boss_magmaw();
    new npc_pillar_of_flame();
    new npc_lava_parasite();
    new npc_spike_stalker();
    new npc_drakonid_drudge();
    new npc_magmaws_pincer();
    new npc_blazing_bone_construct();
    new spell_magmaw_massive_crash();
};
