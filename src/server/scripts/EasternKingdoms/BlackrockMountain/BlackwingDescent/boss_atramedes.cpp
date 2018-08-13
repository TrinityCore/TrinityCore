#include "ScriptMgr.h"
#include "blackwing_descent.h"
#include "Vehicle.h"
#include "Unit.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CombatAI.h"
#include "PassiveAI.h"
#include "ObjectMgr.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "Vehicle.h"
#include "VehicleDefines.h"
#include "Spell.h"
#include "Player.h"
#include "Map.h"
#include "InstanceScript.h"

/*
Atramedes pre-event
20091 - Ah, Maloriak! How gracious of you to finally appear from that quarantine you call a laboratory. What have you got this time?
19860 - My sincerest apologies for the disturbance, my liege. But I believe I have something you may be very interested in!
20092 - By all means, enlighten me.
19861 - Yes, yes!
19862 - By extracting agents from the blood of various dragonflights I have created a salve that bestow the wearer sight beyond sight!
19863 - Sense beyond this realm of mortality!
19864 - Atramedes! Your master beckons.
19865 - I present to you experiment number 25463-D!
20093 - It appears as though your experiment has failed. That whelp has gone completely blind! Look at him.
20156 - LOOK AT HIM!
19866 - How could this be!? I will dispose of him immediately!
20094 - No, not yet.
20095 - This object of your chagrin may still prove... valuable... to me.
20096 - Leave now, pathetic alchemist. I anxiously await your next failure.
19867 - Yes, my lord...

dissappear all three plus throne, players fight the 8 gnomes, then bang the big bell (401937 id) and atramedes flies in, melting it (activate).

Atramedes Heroic Nefarian yells
23357 - You should have been disposed of long time ago. // Death
23358 - These shields are proving quite the nuissance. // Shield
23359 - Atramedes! The heroes are right there! // Air phase
23360 - Atramedes... Are you going deaf aswell as blind? hurry up and kill them all! // Intro
*/

enum Events
{
    // Ground phase
    EVENT_SONAR_PULSE = 1,
    EVENT_MODULATION,
    EVENT_SONIC_BREATH,
    EVENT_SEARING_FLAMES,
    EVENT_SONAR_BOMB,
    EVENT_LIFTOFF,

    EVENT_REMOVE_TRACKING, // unused solo
    EVENT_FLIGHT, // unused solo
    EVENT_AIR, // unused solo

    // Air phase
    EVENT_ROARING_FLAME_SUMMON,
    EVENT_DESTROY_GONG,
    EVENT_LAND,

    EVENT_ROARING_FLAME, // unused solo
    EVENT_RETURN, //unused solo
    EVENT_GROUND, //unused solo

    EVENT_FIEND, // heroic
    EVENT_AGGRO_NEF
};

enum Phases
{
    PHASE_NULL = 0,
    PHASE_GROUND,
    PHASE_FLIGHT
};

enum Spells
{
    // Pre Event
    SPELL_GLOW_ORANGE          = 80857,
    SPELL_BLIND_WHELP          = 81214,
    SPELL_GHOST_VISUAL         = 91218,

    // Boss Fight

    // Sound Bar
    SPELL_SOUND_AURA           = 88824,

    // Ground phase - 80 sec.
    SPELL_TRACKING             = 78092, // Used with Sonic Breath, must be removed from player as has infinite duration.
    SPELL_SONIC_BREATH         = 78098, // The channeled spell, 78100 every 2 sec - works. Only 1 target.
    SPELL_SONIC_BREATH_SUMMON  = 78091, // Summons Tracking Flame. Idk what tracking flame does, maybe summoned at location of player periodically and makes boss turn towards him?

    SPELL_SEARING_FLAMES       = 77840, // Summons huge number of roaring flames and 20k damage to player. Roaring flames cast 77974 on self for 6 sec damage and fire incr aura.
    SPELL_SF_AURA              = 77974, // Cast by roaring flame on self.

    SPELL_SONAR_BOMB_N         = 92553, // damage only, optional, no need.
    SPELL_SONAR_BOMB_H         = 92556, // damage only, optional, no need.
    SPELL_SONAR_BOMB           = 92557, // visual and damage.

    SPELL_MODULATION           = 77612,

    SPELL_SONAR_PULSE          = 77672, //only cast visual, no eff.
    SPELL_SONAR_PULSE_SUMMON   = 77673, //summons mob - not used.
    SPELL_SONAR_PULSE_N        = 77674, // only sound and damage once, used by mob.
    SPELL_SONAR_PULSE_H        = 77674, // aura periodic, used by mob. TODO: get correctly spell who triggered 92418

    // Air phase - 40 sec chase a player, or until someone rings a gong. If gong is rung, 8 sec pause then chase the player which used it, after destroying the gong.
    // boss summons roaring flame target which chase player -> cast 78221 on roaring flame t -> roaring flame t does summon every 500 ms for reverberating -> reverberating casts periodic on self. Player in range -> damage.
    SPELL_ROARING_FLAME_BREATH_DUMMY    = 78221, // Visual, cast on player as he runs.
    SPELL_ROARING_FLAME_BREATH_DAMAGE   = 78353, // Damage of visual, integrated already. Needs radius.
    SPELL_ROARING_FLAME_PERIODIC        = 78018, // Roaring flame npc casts this on self after being summoned.
    SPELL_ROARING_FLAME_SUMMON          = 78555, // Summons Reverberating Flame and damage plus sound 8 y range.

    // Gongs
    SPELL_RESONATING_DRAGON             = 77611, // interr cast boss
    SPELL_VERTIGO                       = 77717, // On boss when hit by one above
    // all these three beneath on player at gong ring.
    SPELL_RESONATING_PLAYER             = 78168, // dummy
    SPELL_RESONATING_PLAYER_POWER       = 77709, // power -100
    SPELL_NOISY                         = 78897, // at 100 sound or when gong ringed by player air phase.

    SPELL_CANNOT_TURN                   = 95544,

   // Obnoxious Fiend
    SPELL_OBNOXIOUS                     = 92677,
    SPELL_PHASESHIFT                    = 92681
};

enum Npc
{
//Sonic Breath (Groundphase)
  NPC_TRACKING_FLAMES         = 41879, // Has Tracking ability wtf? stupid wowhead.

//Searing Flame (Groundphase)
  NPC_ROARING_FLAMES          = 41807, // Summoned by the spell, adds aura on self when summoned. All players get this.

//Sonar Pulse (Groundphase)
  NPC_SONAR_PULSE_TARGET      = 49679, // Summ at targets on which sp is cast.
  NPC_SONAR_PULSES            = 41546, // Npc summ by spell.

// Roaring Flame (Airphase)
  NPC_ROARING_FLAME_TARGET    = 42121, // RFB, this is summoned where player is, spell cast on it, then npc reverberating is summ.
  NPC_REVERBERATING_FLAME     = 42001, // summ by 78555 - Roaring Flame.

// Dwarven Shield (Gong) - has 77611 spell on click.
  NPC_GONG                    = 42949
};

enum ScriptTexts
{
    SAY_EVENT        = -1851029,
    SAY_AGGRO        = 0,    // I have no need for eyes to see my enemies. Your clumsy footsteps and foul stench give you away!
    SAY_KILL_1       = 1,   // Sighted, but blind to the truth. Embrace the finality of it all!
    SAY_KILL_2       = 2,   // Death waits in the darkness!
    SAY_DEATH        = 3,    // This miserable existence finally ends.
    SAY_SEARING      = 6,  // You cannot hide from searing flame!
    SAY_AIR_PHASE    = 7 // Yes, run! With every step your heart quickens. The beating, loud and thunderous... Almost deafening. You cannot escape!
};

class boss_atramedes : public CreatureScript
{
public:
    boss_atramedes() : CreatureScript("boss_atramedes") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_atramedesAI(creature);
    }

    struct boss_atramedesAI : public BossAI
    {
        boss_atramedesAI(Creature* creature) : BossAI(creature, DATA_ATRAMEDES)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        Phases phase;
        uint32 m_uiPowerTimer;

        void Reset() override
        {
            phase = PHASE_NULL;

            if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() == POINT_MOTION_TYPE)
                me->GetMotionMaster()->MovementExpired();

            if(Creature* nefarianHelperheroic = me->FindNearestCreature(NPC_NEFARIAN_HELPER_HEROIC, 150.0f, true))
                nefarianHelperheroic->DespawnOrUnsummon(100);

            // Gongs respawn
            std::list<Creature*> gongs;
            me->GetCreatureListWithEntryInGrid(gongs, NPC_GONG, 200.0f);
            for (std::list<Creature*>::iterator itr = gongs.begin(); itr != gongs.end(); ++itr)
                if (!(*itr)->IsAlive())
                    (*itr)->Respawn();

            if (instance)
            {
                instance->SetBossState(DATA_ATRAMEDES, NOT_STARTED);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_NOISY);
            }

            me->RemoveByteFlag(UNIT_FIELD_BYTES_1, 3, 0x02);
            me->RemoveUnitMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_FLYING);

            _Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            EnterPhaseGround();
            applySound();
            Talk(SAY_AGGRO);
            m_uiPowerTimer = 1000;

            if(me->GetMap()->IsHeroic())
            {
                me->SummonCreature(NPC_NEFARIAN_HELPER_HEROIC, 154.228f, -250.653f, 74.944f, 1.377f, TEMPSUMMON_MANUAL_DESPAWN);
                events.ScheduleEvent(EVENT_AGGRO_NEF, 8000, PHASE_GROUND);
            }

            if (instance)
            {
                instance->SetBossState(DATA_ATRAMEDES, IN_PROGRESS);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me); // Add
            }

            _EnterCombat();
        }

        void initEvents(bool onGround = true)
        {
            events.Reset();

            if(onGround)
            {
                events.ScheduleEvent(EVENT_SONAR_PULSE, 5000, PHASE_GROUND);
                events.ScheduleEvent(EVENT_MODULATION, 20000, PHASE_GROUND);
                events.ScheduleEvent(EVENT_SONIC_BREATH, 20000, PHASE_GROUND);
                events.ScheduleEvent(EVENT_SEARING_FLAMES, 20000, PHASE_GROUND);
                events.ScheduleEvent(EVENT_LIFTOFF, 78000, PHASE_GROUND);
                if(me->GetMap()->IsHeroic())
                    events.ScheduleEvent(EVENT_FIEND, 38500, PHASE_GROUND);
            }else
            {
                events.ScheduleEvent(EVENT_SONAR_BOMB, 4000, PHASE_FLIGHT);
                events.ScheduleEvent(EVENT_ROARING_FLAME_SUMMON, 5000, PHASE_FLIGHT);
                events.ScheduleEvent(EVENT_LAND, 38500, PHASE_FLIGHT);
            }
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            Reset();
            removeSound();

            me->GetMotionMaster()->MoveTargetedHome();

            if (instance)
            {
                instance->SetBossState(DATA_ATRAMEDES, FAIL);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove
            }

            _EnterEvadeMode();
        }

        void EnterPhaseGround()
        {
            phase = PHASE_GROUND;
            me->SetReactState(REACT_AGGRESSIVE);
            me->SetDisableGravity(false);
            me->RemoveByteFlag(UNIT_FIELD_BYTES_1, 3, 0x02);
            me->RemoveUnitMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_FLYING);
            events.SetPhase(PHASE_GROUND);
            initEvents(true);
        }

        void EnterPhaseAir()
        {
            phase = PHASE_FLIGHT;
            me->SetReactState(REACT_PASSIVE);
            me->SetDisableGravity(true);
            me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, 0x02);
            me->AddUnitMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_FLYING);
            events.SetPhase(PHASE_FLIGHT);
            initEvents(false);
        }

        void applySound()
        {
            if(instance)
               instance->DoAddAuraOnPlayers(SPELL_SOUND_AURA);
        }

        void removeSound()
        {
            if(instance)
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SOUND_AURA);
        }

        void JustSummoned(Creature* summon) override
        {
            summon->AI()->DoZoneInCombat();

            if(summon->GetEntry() == NPC_SONAR_PULSES)
            {
                summon->SetSpeed(MOVE_WALK, 0.75f);
                summon->SetSpeed(MOVE_RUN, 0.75f);
                summon->CastSpell(summon, SPELL_SONAR_PULSE_H, true); // add aura
            }

            if(summon->GetEntry() == NPC_ROARING_FLAME_TARGET)
            {
                if (me->GetMap()->IsHeroic())
                {
                    summon->SetSpeed(MOVE_WALK, 0.95f);
                    summon->SetSpeed(MOVE_RUN, 0.95f);
                }
                else
                {
                    summon->SetSpeed(MOVE_WALK, 0.87f);
                    summon->SetSpeed(MOVE_RUN, 0.87f);
                }

                if(Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0, 50.0f, true))
                    summon->GetMotionMaster()->MoveChase(target);
            }

            if(summon->GetEntry() == NPC_OBNOXIOUS_FIEND)
            {
                if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                    summon->AI()->AttackStart(target);
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            removeSound();

            if (instance)
            {
                instance->SetBossState(DATA_ATRAMEDES, DONE);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_NOISY);
            }

            if (Creature* nefarianHelperheroic = me->FindNearestCreature(NPC_NEFARIAN_HELPER_HEROIC, 150.0f, true))
            {
                nefarianHelperheroic->RemoveAllAuras();
                nefarianHelperheroic->AI()->Talk(25);
                nefarianHelperheroic->DespawnOrUnsummon(9000);
            }

            _JustDied();
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(RAND(SAY_KILL_1, SAY_KILL_2));
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (!phase)
                return;

            if (m_uiPowerTimer <= diff)
            {
                /*if(instance)
                   instance->NormaliseAltPower();*/
            }
            else m_uiPowerTimer -= diff;

            events.Update(diff);

            if (phase == PHASE_GROUND) // Ground phase
            {
                ThreatContainer::StorageType m_threatlist = me->getThreatManager().getThreatList();

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_AGGRO_NEF:
                            if (Creature* nefarianHelperheroic = me->FindNearestCreature(NPC_NEFARIAN_HELPER_HEROIC, 150.0f, true))
                            nefarianHelperheroic->AI()->Talk(28);
                            return;

                        case EVENT_SONAR_PULSE:
                            DoCast(me, SPELL_SONAR_PULSE);
                            me->SummonCreature(NPC_SONAR_PULSES, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 1.5f, TEMPSUMMON_TIMED_DESPAWN, 30000);
                            me->SummonCreature(NPC_SONAR_PULSES, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 3.0f, TEMPSUMMON_TIMED_DESPAWN, 30000);
                            me->SummonCreature(NPC_SONAR_PULSES, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 4.5f, TEMPSUMMON_TIMED_DESPAWN, 30000);
                            me->SummonCreature(NPC_SONAR_PULSES, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 6.0f, TEMPSUMMON_TIMED_DESPAWN, 30000);
                            events.ScheduleEvent(EVENT_SONAR_PULSE, 50000);
                            break;

                        case EVENT_MODULATION:
                            DoCast(me, SPELL_MODULATION);
                            for (std::list<HostileReference*>::const_iterator i = m_threatlist.begin(); i!= m_threatlist.end(); ++i)
                                if (Unit* unit = ObjectAccessor::GetUnit(*me, (*i)->getUnitGuid()))
                                    unit->SetPower(POWER_ALTERNATE_POWER, unit->GetPower(POWER_ALTERNATE_POWER) + 7);

                            events.ScheduleEvent(EVENT_MODULATION, 20000);
                            break;

                        case EVENT_SONIC_BREATH:
                             if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                            {
                                target->AddAura(SPELL_TRACKING, target);
                                DoCast(target, SPELL_SONIC_BREATH);
                            }
                            events.ScheduleEvent(EVENT_REMOVE_TRACKING, 8500);
                            events.ScheduleEvent(EVENT_SONIC_BREATH, 40000);
                            break;

                        case EVENT_REMOVE_TRACKING:
                            if(instance)
                                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TRACKING);
                            return;

                        case EVENT_SEARING_FLAMES:
                            Talk(SAY_SEARING);
                            DoCast(me, SPELL_SEARING_FLAMES);
                            events.ScheduleEvent(EVENT_SEARING_FLAMES, 50000);
                            break;

                        case EVENT_LIFTOFF:
                            Talk(SAY_AIR_PHASE);
                            me->HandleEmoteCommand(EMOTE_ONESHOT_LIFTOFF);
                            me->SetDisableGravity(true);
                            events.ScheduleEvent(EVENT_FLIGHT, 1500);
                            events.ScheduleEvent(EVENT_AIR, 2000);
                            return;

                        case EVENT_FLIGHT:
                            me->SetReactState(REACT_PASSIVE);
                            me->AttackStop();
                            me->GetMotionMaster()->MovePoint(1, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 40.0f);
                            return;

                        case EVENT_AIR:
                            EnterPhaseAir();
                            return;

                        case EVENT_FIEND:
                            me->SummonCreature(NPC_OBNOXIOUS_FIEND, 93.767f, -224.105f, 74.911f, 6.26f, TEMPSUMMON_CORPSE_DESPAWN, 3000);
                            if (Creature* nefarianHelperheroic = me->FindNearestCreature(NPC_NEFARIAN_HELPER_HEROIC, 150.0f, true))
                                nefarianHelperheroic->AI()->Talk(27);
                            events.ScheduleEvent(EVENT_FIEND, 38500);
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
            else if (phase == PHASE_FLIGHT) // Air phase
            {
                std::list<Unit*> targets;
                ThreatContainer::StorageType m_threatlist = me->getThreatManager().getThreatList();

                // if has vertigo, remove all roaring flame npc's wait 8 sec then get player who rang gong.
                if (me->HasAura(SPELL_VERTIGO))
                    events.ScheduleEvent(EVENT_ROARING_FLAME_SUMMON, 8000, PHASE_FLIGHT);

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ROARING_FLAME_SUMMON:
                            for (std::list<HostileReference*>::const_iterator i = m_threatlist.begin(); i!= m_threatlist.end(); ++i)
                            {
                                Unit* unit = ObjectAccessor::GetUnit(*me, (*i)->getUnitGuid());
                                if (unit && unit->HasAura(SPELL_NOISY)) // You rang? :)
                                {
                                    me->SummonCreature(NPC_ROARING_FLAME_TARGET, unit->GetPositionX(), unit->GetPositionY(), unit->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 30000);
                                }
                                else
                                {
                                     if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                        me->SummonCreature(NPC_ROARING_FLAME_TARGET, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 30000);
                                }
                            }
                            events.ScheduleEvent(EVENT_ROARING_FLAME, 500);
                            return;

                        case EVENT_ROARING_FLAME:
                            if (Unit* roaring = me->FindNearestCreature(NPC_ROARING_FLAME_TARGET, 100.0f))
                                DoCast(roaring, SPELL_ROARING_FLAME_BREATH_DUMMY);
                            return;

                        case EVENT_SONAR_BOMB:
                            SelectTargetList(targets, RAID_MODE(3, 6), SELECT_TARGET_RANDOM, 100.0f, true);
                            if (!targets.empty())
                                for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                                    DoCast(*itr, SPELL_SONAR_BOMB);
                            events.ScheduleEvent(EVENT_SONAR_BOMB, 18000);
                            break;

                        case EVENT_LAND:
                            me->HandleEmoteCommand(EMOTE_ONESHOT_LAND);
                            me->SetDisableGravity(false);
                            events.ScheduleEvent(EVENT_RETURN, 1000);
                            events.ScheduleEvent(EVENT_GROUND, 1500);
                            return;

                        case EVENT_RETURN:
                            me->SetReactState(REACT_PASSIVE);
                            me->AttackStop();
                            me->GetMotionMaster()->MovePoint(1, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() - 20.0f);
                            return;

                        case EVENT_GROUND:
                            EnterPhaseGround();
                            return;
                    }
                }
            }
        }

    private:
    };
};

// Ground phase

class mob_sonar_pulse : public CreatureScript // 41546
{
public:
    mob_sonar_pulse() : CreatureScript("mob_sonar_pulse") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_sonar_pulseAI (creature);
    }

    struct mob_sonar_pulseAI : public ScriptedAI
    {
        mob_sonar_pulseAI(Creature* creature) : ScriptedAI(creature)
        {
            timerMove = 1000;
            timerDespawn = 20000;
            creature->SetReactState(REACT_PASSIVE);
            if (me->GetMap()->IsHeroic())
                me->AddAura(SPELL_SONAR_PULSE_H,me);
            else
                me->AddAura(SPELL_SONAR_PULSE_N,me);
        }

        uint32 timerMove;
        uint32 timerDespawn;

        void UpdateAI(uint32 diff) override
        {
            if (timerMove <= diff) // move forward
            {
                DoCast(me,77675);
                DoCast(me, SPELL_CANNOT_TURN);
                float x, y, z;
                me->GetClosePoint(x, y, z, me->GetObjectSize() / 3, 100.0f);
                me->GetMotionMaster()->MovePoint(1, x, y, z);
            } else timerMove -= diff;

            if (timerDespawn <= diff)
            {
                me->DespawnOrUnsummon();
            } else timerDespawn -= diff;
        }
    };
};

class mob_searing_flame : public CreatureScript // 41807
{
public:
    mob_searing_flame() : CreatureScript("mob_searing_flame") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_searing_flameAI (creature);
    }

    struct mob_searing_flameAI : public ScriptedAI
    {
        mob_searing_flameAI(Creature* creature) : ScriptedAI(creature)
        {
            timerDespawn = 7500;
            timerPeriodic = 1500;
            creature->SetReactState(REACT_PASSIVE);
        }

        uint32 timerPeriodic;
        uint32 timerDespawn;

        void UpdateAI(uint32 diff) override
        {
            if (timerPeriodic <= diff)
            {
                DoCast(me, SPELL_SF_AURA);
            } else timerPeriodic -= diff;

            if (timerDespawn <= diff)
            {
                me->DespawnOrUnsummon();
            } else timerDespawn -= diff;
        }
    };
};


class mob_obnoxious_fiend : public CreatureScript // 49740
{
public:
    mob_obnoxious_fiend() : CreatureScript("mob_obnoxious_fiend") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_obnoxious_fiendAI (creature);
    }

    struct mob_obnoxious_fiendAI : public ScriptedAI
    {
        mob_obnoxious_fiendAI(Creature* creature) : ScriptedAI(creature)
        {
            DoCast(me, SPELL_PHASESHIFT);
            timerCast = 10000;
            timerRemoveAura = 7000;
        }

        uint32 timerRemoveAura;
        uint32 timerCast;

        void UpdateAI(uint32 diff) override
        {
            if (timerCast <= diff)
            {
                DoCast(me->GetVictim(), SPELL_OBNOXIOUS);
                timerCast = 3000;
            } else timerCast -= diff;

            if (timerRemoveAura <= diff && me->HasAura(SPELL_PHASESHIFT))
            {
                me->RemoveAura(SPELL_PHASESHIFT);
            } else timerRemoveAura -= diff;
        }
    };
};

// Air phase

class mob_roaring_flame_target : public CreatureScript // 42121
{
public:
    mob_roaring_flame_target() : CreatureScript("mob_roaring_flame_target") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_roaring_flame_targetAI (creature);
    }

    struct mob_roaring_flame_targetAI : public ScriptedAI
    {
        mob_roaring_flame_targetAI(Creature* creature) : ScriptedAI(creature)
        {
            timerSummonFlame = 500;
            timerDespawn = 30000;
        }

        uint32 timerSummonFlame;
        uint32 timerDespawn;

        void UpdateAI(uint32 diff) override
        {
            if (timerSummonFlame <= diff)
            {
                DoCast(me, SPELL_ROARING_FLAME_SUMMON);
                timerSummonFlame = 500;
            } else timerSummonFlame -= diff;

            if (timerDespawn <= diff)
            {
                me->DespawnOrUnsummon();
            } else timerDespawn -= diff;
        }
    };
};

class mob_roaring_flame : public CreatureScript // 42001
{
public:
    mob_roaring_flame() : CreatureScript("mob_roaring_flame") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_roaring_flameAI (creature);
    }

    struct mob_roaring_flameAI : public ScriptedAI
    {
        mob_roaring_flameAI(Creature* creature) : ScriptedAI(creature)
        {
            timerDespawn = 30000;
            timerPeriodic = 1000;
            creature->SetReactState(REACT_PASSIVE);
        }

        uint32 timerPeriodic;
        uint32 timerDespawn;

        void UpdateAI(uint32 diff) override
        {
            if (timerPeriodic <= diff)
            {
                DoCast(me, SPELL_ROARING_FLAME_PERIODIC);
            } else timerPeriodic -= diff;

            if (timerDespawn <= diff)
            {
                me->DespawnOrUnsummon();
            } else timerDespawn -= diff;
        }
    };
};

// Gongs
class mob_atramedes_gong : public CreatureScript // 42949
{
public:
    mob_atramedes_gong() : CreatureScript("mob_atramedes_gong")
    {
    }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (creature->GetMap()->IsHeroic())
        {
            uint32 gongCounter = 0;

            if (Creature* nefarianHelperheroic = creature->FindNearestCreature(NPC_NEFARIAN_HELPER_HEROIC, 150.0f, true))
                nefarianHelperheroic->AI()->Talk(26);

            if (Creature* gong = creature->FindNearestCreature(42949, 20.0f))
                if(gongCounter < 3)
                {
                    creature->Kill(gong);
                    gongCounter++;
                }
        }

        if(Creature* atramedes = creature->FindNearestCreature(BOSS_ATRAMEDES, 200.0f))
        {
            creature->CastSpell(atramedes, SPELL_RESONATING_DRAGON, true);
            creature->AddAura(SPELL_VERTIGO, atramedes);

            creature->AddAura(SPELL_NOISY, player);
            creature->CastSpell(player, SPELL_RESONATING_PLAYER, true);

          /*  Map::PlayerList const &PlayerList = creature->GetMap()->GetPlayers();

            if (!PlayerList.isEmpty())
              for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                if (Player* playr = i->GetSource())*/
            creature->GetInstanceScript()->DoRemoveAurasDueToSpellOnPlayers(SPELL_SOUND_AURA);
            creature->GetInstanceScript()->DoAddAuraOnPlayers(SPELL_SOUND_AURA);

            creature->setDeathState(JUST_DIED);
        }
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_atramedes_gongAI (creature);
    }

    struct mob_atramedes_gongAI : public ScriptedAI
    {
        mob_atramedes_gongAI(Creature* creature) : ScriptedAI(creature){ }

        void UpdateAI(uint32 /*diff*/) override
        {
            // Don't use gongs out of combat
            if (Creature* atramedes = me->FindNearestCreature(BOSS_ATRAMEDES, 200.0f))
            {
                if (!atramedes->IsInCombat())
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                else
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            }
        }
    };
};

uint16 const times[16] =
{
    0, 10000, 10000, 5000, 5000, 10000, 5000, 7500,
    5000, 8000, 5000, 7500, 3000, 8000, 9000, 5000
};

class mob_maloriak_atramedes_event : public CreatureScript
{
public:
    mob_maloriak_atramedes_event() : CreatureScript("mob_maloriak_atramedes_event") { }

    struct mob_maloriak_atramedes_eventAI : public ScriptedAI
    {
        mob_maloriak_atramedes_eventAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        uint32 timer;
        uint8 eventStep;

        Creature* nefarian;
        Creature* atramedes;
        Creature* maloriak;

        bool eventProcessed;

        void Reset() override
        {
            timer = 1000;
            eventStep = 0;
            eventProcessed = false;

            DespawnCreatures(NPC_PRE_NEFARIAN);
            DespawnCreatures(NPC_PRE_MALORIAK);
            DespawnCreatures(NPC_PRE_ATRAMEDES);
            me->SummonCreature(NPC_PRE_NEFARIAN, 127.802f, -234.484f, 75.453453f, 2.046f, TEMPSUMMON_CORPSE_DESPAWN, 3000);
            me->SummonCreature(NPC_PRE_MALORIAK, 122.799f, -216.601f, 75.453453f, 5.011f, TEMPSUMMON_CORPSE_DESPAWN, 3000);
            me->SummonCreature(NPC_PRE_ATRAMEDES, 117.386f, -219.943f, 75.453453f, 5.305f, TEMPSUMMON_CORPSE_DESPAWN, 3000);
            me->SummonGameObject(GOB_NEFARIANS_THRONE, 129.937f, -236.88f, 75.4534f, 2.274f, QuaternionData(), 0);
        };

        void DespawnCreatures(uint32 entry)
        {
            std::list<Creature*> creatures;
               GetCreatureListWithEntryInGrid(creatures, me, entry, 1000.0f);

            if (creatures.empty())
               return;

            for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                 (*iter)->DespawnOrUnsummon();
        }

        void UpdateAI(uint32 diff) override
        {
            if (timer <= diff)
            {

                if(eventStep == 0)
                {
                    timer = times[eventStep];

                    if (Player* target = me->SelectNearestPlayer(40.0f))
                        if (target && target->GetDistance(me) < 35.0f  && !eventProcessed)
                        {
                            atramedes = me->FindNearestCreature(NPC_PRE_ATRAMEDES, 100.0f, true);
                            eventStep = 1;
                            eventProcessed = true;
                            nefarian = me->FindNearestCreature(NPC_PRE_NEFARIAN, 100.0f, true);
                            maloriak = me->FindNearestCreature(NPC_PRE_MALORIAK, 100.0f, true);
                            // Ghost visual.
                            atramedes->AddAura(SPELL_GHOST_VISUAL, atramedes);
                            nefarian->AddAura(SPELL_GHOST_VISUAL, nefarian);
                            maloriak->AddAura(SPELL_GHOST_VISUAL, maloriak);
                        }
                }else
                {
                    switch(eventStep)
                    {
                        // Nefarian
                    case 1:   nefarian->AI()->Talk(0);  break;
                    case 3:   nefarian->AI()->Talk(1);  break;
                    case 9:   nefarian->AI()->Talk(2);  break;
                    case 10:  nefarian->AI()->Talk(3);  break;
                    case 12:  nefarian->AI()->Talk(4);  break;
                    case 13:  nefarian->AI()->Talk(5);  break;
                    case 14:  nefarian->AI()->Talk(6);  break;

                        // Maloriak
                    case 2:   maloriak->AI()->Talk(0);  break;
                    case 4:   maloriak->AI()->Talk(1);  break;
                    case 5:   maloriak->AI()->Talk(2);  break;
                    case 6:   maloriak->AI()->Talk(3);  break;
                    case 7:   maloriak->AI()->Talk(4);  break;

                    case 8:
                        atramedes->AddAura(SPELL_GLOW_ORANGE, atramedes);
                        atramedes->AddAura(SPELL_BLIND_WHELP, atramedes);
                        atramedes->GetMotionMaster()->MovePoint(0,121.493f, -225.428f, 75.4535f);
                        maloriak->AI()->Talk(5);
                        break;
                    case 11:
                        maloriak->AI()->Talk(6);
                        break;
                    case 15:
                        atramedes->RemoveAura(SPELL_GLOW_ORANGE);
                        atramedes->RemoveAura(SPELL_BLIND_WHELP);
                        maloriak->AI()->Talk(7);
                        break;

                    // Both
                    case 16:
                        atramedes->DespawnOrUnsummon();
                        nefarian->DespawnOrUnsummon();
                        maloriak->DespawnOrUnsummon();

                        if(GameObject* throne = me->FindNearestGameObject(GOB_NEFARIANS_THRONE, 100.0f))
                            throne->Delete();

                        me->DespawnOrUnsummon(100);
                        break;
                    }

                    timer = times[eventStep];

                    if(eventStep<16)
                        eventStep++;
                }

            } else timer -= diff;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_maloriak_atramedes_eventAI(creature);
    }
};

class spell_atramedes_sonic_breath : public SpellScriptLoader
{
    public:
        spell_atramedes_sonic_breath() : SpellScriptLoader("spell_atramedes_sonic_breath") { }

        class spell_atramedes_sonic_breath_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_atramedes_sonic_breath_SpellScript);

            void CalculateDamage(SpellEffIndex /*effIndex*/)
            {
                if (!GetHitUnit())
                    return;

                if (!GetHitUnit()->isInFront(GetCaster(), GetCaster()->GetObjectSize() / 3))
                    SetHitDamage(0);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_atramedes_sonic_breath_SpellScript::CalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
                OnEffectHitTarget += SpellEffectFn(spell_atramedes_sonic_breath_SpellScript::CalculateDamage, EFFECT_1, SPELL_EFFECT_ENERGIZE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_atramedes_sonic_breath_SpellScript();
        }
};

void AddSC_boss_atramedes()
{
    new boss_atramedes();
    new mob_sonar_pulse();
    new mob_atramedes_gong();
    new mob_roaring_flame();
    new mob_roaring_flame_target();
    new mob_searing_flame();
    new mob_obnoxious_fiend();

    new mob_maloriak_atramedes_event();
    new spell_atramedes_sonic_breath();
}
