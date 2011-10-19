/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Felmyst
SD%Complete: 0
SDComment:
EndScriptData */

#include "ScriptPCH.h"
#include "sunwell_plateau.h"

enum Yells
{
    YELL_BIRTH                                    = -1580036,
    YELL_KILL1                                    = -1580037,
    YELL_KILL2                                    = -1580038,
    YELL_BREATH                                   = -1580039,
    YELL_TAKEOFF                                  = -1580040,
    YELL_BERSERK                                  = -1580041,
    YELL_DEATH                                    = -1580042,
    YELL_KALECGOS                                 = -1580043, // after felmyst's death spawned and say this
};

enum Spells
{
    //Aura
    AURA_SUNWELL_RADIANCE                         = 45769,
    AURA_NOXIOUS_FUMES                            = 47002,

    //Land phase
    SPELL_CLEAVE                                  = 19983,
    SPELL_CORROSION                               = 45866,
    SPELL_GAS_NOVA                                = 45855,
    SPELL_ENCAPSULATE_CHANNEL                     = 45661,
    // SPELL_ENCAPSULATE_EFFECT                      = 45665,
    // SPELL_ENCAPSULATE_AOE                         = 45662,

    //Flight phase
    SPELL_VAPOR_SELECT                            = 45391,   // fel to player, force cast 45392, 50000y selete target
    SPELL_VAPOR_SUMMON                            = 45392,   // player summon vapor, radius around caster, 5y,
    SPELL_VAPOR_FORCE                             = 45388,   // vapor to fel, force cast 45389
    SPELL_VAPOR_CHANNEL                           = 45389,   // fel to vapor, green beam channel
    SPELL_VAPOR_TRIGGER                           = 45411,   // linked to 45389, vapor to self, trigger 45410 and 46931
    SPELL_VAPOR_DAMAGE                            = 46931,   // vapor damage, 4000
    SPELL_TRAIL_SUMMON                            = 45410,   // vapor summon trail
    SPELL_TRAIL_TRIGGER                           = 45399,   // trail to self, trigger 45402
    SPELL_TRAIL_DAMAGE                            = 45402,   // trail damage, 2000 + 2000 dot
    SPELL_DEAD_SUMMON                             = 45400,   // summon blazing dead, 5min
    SPELL_DEAD_PASSIVE                            = 45415,
    SPELL_FOG_BREATH                              = 45495,   // fel to self, speed burst
    SPELL_FOG_TRIGGER                             = 45582,   // fog to self, trigger 45782
    SPELL_FOG_FORCE                               = 45782,   // fog to player, force cast 45714
    SPELL_FOG_INFORM                              = 45714,   // player let fel cast 45717, script effect
    SPELL_FOG_CHARM                               = 45717,   // fel to player
    SPELL_FOG_CHARM2                              = 45726,   // link to 45717

    SPELL_TRANSFORM_TRIGGER                       = 44885,   // madrigosa to self, trigger 46350
    SPELL_TRANSFORM_VISUAL                        = 46350,   // 46411stun?
    SPELL_TRANSFORM_FELMYST                       = 45068,   // become fel
    SPELL_FELMYST_SUMMON                          = 45069,

    //Other
    SPELL_BERSERK                                 = 45078,
    SPELL_CLOUD_VISUAL                            = 45212,
    SPELL_CLOUD_SUMMON                            = 45884,
};

enum PhaseFelmyst
{
    PHASE_NONE,
    PHASE_GROUND,
    PHASE_FLIGHT,
};

enum EventFelmyst
{
    EVENT_NONE,
    EVENT_BERSERK,

    EVENT_CLEAVE,
    EVENT_CORROSION,
    EVENT_GAS_NOVA,
    EVENT_ENCAPSULATE,
    EVENT_FLIGHT,

    EVENT_FLIGHT_SEQUENCE,
    EVENT_SUMMON_DEAD,
    EVENT_SUMMON_FOG,
};

class boss_felmyst : public CreatureScript
{
public:
    boss_felmyst() : CreatureScript("boss_felmyst") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_felmystAI(creature);
    }

    struct boss_felmystAI : public ScriptedAI
    {
        boss_felmystAI(Creature* c) : ScriptedAI(c)
        {
            instance = c->GetInstanceScript();
        }

        InstanceScript* instance;
        PhaseFelmyst phase;
        EventMap events;

        uint32 uiFlightCount;
        uint32 uiBreathCount;

        float breathX, breathY;

        void Reset()
        {
            phase = PHASE_NONE;

            events.Reset();

            uiFlightCount = 0;

            me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
            me->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 10);
            me->SetFloatValue(UNIT_FIELD_COMBATREACH, 10);

            DespawnSummons(MOB_VAPOR_TRAIL);
            me->setActive(false);

            if (instance)
                instance->SetData(DATA_FELMYST_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_BERSERK, 600000);

            me->setActive(true);
            DoZoneInCombat();
            DoCast(me, AURA_SUNWELL_RADIANCE, true);
            DoCast(me, AURA_NOXIOUS_FUMES, true);
            EnterPhase(PHASE_GROUND);

            if (instance)
                instance->SetData(DATA_FELMYST_EVENT, IN_PROGRESS);
        }

        void AttackStart(Unit* who)
        {
            if (phase != PHASE_FLIGHT)
                ScriptedAI::AttackStart(who);
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (phase != PHASE_FLIGHT)
                ScriptedAI::MoveInLineOfSight(who);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            DoScriptText(RAND(YELL_KILL1, YELL_KILL2), me);
        }

        void JustRespawned()
        {
            DoScriptText(YELL_BIRTH, me);
        }

        void JustDied(Unit* /*Killer*/)
        {
            DoScriptText(YELL_DEATH, me);

            if (instance)
                instance->SetData(DATA_FELMYST_EVENT, DONE);
        }

        void SpellHit(Unit* caster, const SpellInfo* spell)
        {
            // workaround for linked aura
            /*if (spell->Id == SPELL_VAPOR_FORCE)
            {
                caster->CastSpell(caster, SPELL_VAPOR_TRIGGER, true);
            }*/
            // workaround for mind control
            if (spell->Id == SPELL_FOG_INFORM)
            {
                float x, y, z;
                caster->GetPosition(x, y, z);
                if (Unit* summon = me->SummonCreature(MOB_DEAD, x, y, z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000))
                {
                    summon->SetMaxHealth(caster->GetMaxHealth());
                    summon->SetHealth(caster->GetMaxHealth());
                    summon->CastSpell(summon, SPELL_FOG_CHARM, true);
                    summon->CastSpell(summon, SPELL_FOG_CHARM2, true);
                }
                me->DealDamage(caster, caster->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
            }
        }

        void JustSummoned(Creature* summon)
        {
            if (summon->GetEntry() == MOB_DEAD)
            {
                summon->AI()->AttackStart(SelectTarget(SELECT_TARGET_RANDOM));
                DoZoneInCombat(summon);
                summon->CastSpell(summon, SPELL_DEAD_PASSIVE, true);
            }
        }

        void MovementInform(uint32, uint32)
        {
            if (phase == PHASE_FLIGHT)
                events.ScheduleEvent(EVENT_FLIGHT_SEQUENCE, 1);
        }

        void DamageTaken(Unit*, uint32 &damage)
        {
            if (phase != PHASE_GROUND && damage >= me->GetHealth())
                damage = 0;
        }

        void EnterPhase(PhaseFelmyst NextPhase)
        {
            switch (NextPhase)
            {
            case PHASE_GROUND:
                me->CastStop(SPELL_FOG_BREATH);
                me->RemoveAurasDueToSpell(SPELL_FOG_BREATH);
                me->SetUnitMovementFlags(MOVEMENTFLAG_NONE);
                me->SetSpeed(MOVE_RUN, 2.0f);

                events.ScheduleEvent(EVENT_CLEAVE, urand(5000, 10000));
                events.ScheduleEvent(EVENT_CORROSION, urand(10000, 20000));
                events.ScheduleEvent(EVENT_GAS_NOVA, urand(15000, 20000));
                events.ScheduleEvent(EVENT_ENCAPSULATE, urand(20000, 25000));
                events.ScheduleEvent(EVENT_FLIGHT, 60000);
                break;
            case PHASE_FLIGHT:
                me->SetUnitMovementFlags(MOVEMENTFLAG_LEVITATING);
                events.ScheduleEvent(EVENT_FLIGHT_SEQUENCE, 1000);
                uiFlightCount = 0;
                uiBreathCount = 0;
                break;
            default:
                break;
            }
            phase = NextPhase;
        }

        void HandleFlightSequence()
        {
            switch (uiFlightCount)
            {
            case 0:
                //me->AttackStop();
                me->GetMotionMaster()->Clear(false);
                me->HandleEmoteCommand(EMOTE_ONESHOT_LIFTOFF);
                me->StopMoving();
                DoScriptText(YELL_TAKEOFF, me);
                events.ScheduleEvent(EVENT_FLIGHT_SEQUENCE, 2000);
                break;
            case 1:
                me->GetMotionMaster()->MovePoint(0, me->GetPositionX()+1, me->GetPositionY(), me->GetPositionZ()+10);
                break;
            case 2:
            {
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 150, true);
                if (!target)
                    target = Unit::GetUnit(*me, instance ? instance->GetData64(DATA_PLAYER_GUID) : 0);

                if (!target)
                {
                    EnterEvadeMode();
                    return;
                }

                Creature* Vapor = me->SummonCreature(MOB_VAPOR, target->GetPositionX()-5+rand()%10, target->GetPositionY()-5+rand()%10, target->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 9000);
                if (Vapor)
                {
                    Vapor->AI()->AttackStart(target);
                    me->InterruptNonMeleeSpells(false);
                    DoCast(Vapor, SPELL_VAPOR_CHANNEL, false); // core bug
                    Vapor->CastSpell(Vapor, SPELL_VAPOR_TRIGGER, true);
                }

                events.ScheduleEvent(EVENT_FLIGHT_SEQUENCE, 10000);
                break;
            }
            case 3:
            {
                DespawnSummons(MOB_VAPOR_TRAIL);
                //DoCast(me, SPELL_VAPOR_SELECT); need core support

                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 150, true);
                if (!target)
                    target = Unit::GetUnit(*me, instance ? instance->GetData64(DATA_PLAYER_GUID) : 0);

                if (!target)
                {
                    EnterEvadeMode();
                    return;
                }

                //target->CastSpell(target, SPELL_VAPOR_SUMMON, true); need core support
                Creature* pVapor = me->SummonCreature(MOB_VAPOR, target->GetPositionX()-5+rand()%10, target->GetPositionY()-5+rand()%10, target->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 9000);
                if (pVapor)
                {
                    if (pVapor->AI())
                        pVapor->AI()->AttackStart(target);
                    me->InterruptNonMeleeSpells(false);
                    DoCast(pVapor, SPELL_VAPOR_CHANNEL, false); // core bug
                    pVapor->CastSpell(pVapor, SPELL_VAPOR_TRIGGER, true);
                }

                events.ScheduleEvent(EVENT_FLIGHT_SEQUENCE, 10000);
                break;
            }
            case 4:
                DespawnSummons(MOB_VAPOR_TRAIL);
                events.ScheduleEvent(EVENT_FLIGHT_SEQUENCE, 1);
                break;
            case 5:
            {
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 150, true);
                if (!target)
                    target = Unit::GetUnit(*me, instance ? instance->GetData64(DATA_PLAYER_GUID) : 0);

                if (!target)
                {
                    EnterEvadeMode();
                    return;
                }

                breathX = target->GetPositionX();
                breathY = target->GetPositionY();
                float x, y, z;
                target->GetContactPoint(me, x, y, z, 70);
                me->GetMotionMaster()->MovePoint(0, x, y, z+10);
                break;
            }
            case 6:
                me->SetOrientation(me->GetAngle(breathX, breathY));
                me->StopMoving();
                //DoTextEmote("takes a deep breath.", NULL);
                events.ScheduleEvent(EVENT_FLIGHT_SEQUENCE, 10000);
                break;
            case 7:
            {
                DoCast(me, SPELL_FOG_BREATH, true);
                float x, y, z;
                me->GetPosition(x, y, z);
                x = 2 * breathX - x;
                y = 2 * breathY - y;
                me->GetMotionMaster()->MovePoint(0, x, y, z);
                events.ScheduleEvent(EVENT_SUMMON_FOG, 1);
                break;
            }
            case 8:
                me->CastStop(SPELL_FOG_BREATH);
                me->RemoveAurasDueToSpell(SPELL_FOG_BREATH);
                ++uiBreathCount;
                events.ScheduleEvent(EVENT_FLIGHT_SEQUENCE, 1);
                if (uiBreathCount < 3)
                    uiFlightCount = 4;
                break;
            case 9:
                if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                    DoStartMovement(target);
                else
                {
                    EnterEvadeMode();
                    return;
                }
                break;
            case 10:
                me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                me->HandleEmoteCommand(EMOTE_ONESHOT_LAND);
                EnterPhase(PHASE_GROUND);
                AttackStart(SelectTarget(SELECT_TARGET_TOPAGGRO));
                break;
            }
            ++uiFlightCount;
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
            {
                if (phase == PHASE_FLIGHT && !me->IsInEvadeMode())
                    EnterEvadeMode();
                return;
            }

            events.Update(diff);

            if (me->IsNonMeleeSpellCasted(false))
                return;

            if (phase == PHASE_GROUND)
            {
                switch (events.ExecuteEvent())
                {
                    case EVENT_BERSERK:
                        DoScriptText(YELL_BERSERK, me);
                        DoCast(me, SPELL_BERSERK, true);
                        events.ScheduleEvent(EVENT_BERSERK, 10000);
                        break;
                    case EVENT_CLEAVE:
                        DoCast(me->getVictim(), SPELL_CLEAVE, false);
                        events.ScheduleEvent(EVENT_CLEAVE, urand(5000, 10000));
                        break;
                    case EVENT_CORROSION:
                        DoCast(me->getVictim(), SPELL_CORROSION, false);
                        events.ScheduleEvent(EVENT_CORROSION, urand(20000, 30000));
                        break;
                    case EVENT_GAS_NOVA:
                        DoCast(me, SPELL_GAS_NOVA, false);
                        events.ScheduleEvent(EVENT_GAS_NOVA, urand(20000, 25000));
                        break;
                    case EVENT_ENCAPSULATE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 150, true))
                            DoCast(target, SPELL_ENCAPSULATE_CHANNEL, false);
                        events.ScheduleEvent(EVENT_ENCAPSULATE, urand(25000, 30000));
                        break;
                    case EVENT_FLIGHT:
                        EnterPhase(PHASE_FLIGHT);
                        break;
                    default:
                        DoMeleeAttackIfReady();
                        break;
                }
            }

            if (phase == PHASE_FLIGHT)
            {
                switch (events.ExecuteEvent())
                {
                    case EVENT_BERSERK:
                        DoScriptText(YELL_BERSERK, me);
                        DoCast(me, SPELL_BERSERK, true);
                        break;
                    case EVENT_FLIGHT_SEQUENCE:
                        HandleFlightSequence();
                        break;
                    case EVENT_SUMMON_FOG:
                        {
                            float x, y, z;
                            me->GetPosition(x, y, z);
                            me->UpdateGroundPositionZ(x, y, z);
                            if (Creature* Fog = me->SummonCreature(MOB_VAPOR_TRAIL, x, y, z, 0, TEMPSUMMON_TIMED_DESPAWN, 10000))
                            {
                                Fog->RemoveAurasDueToSpell(SPELL_TRAIL_TRIGGER);
                                Fog->CastSpell(Fog, SPELL_FOG_TRIGGER, true);
                                me->CastSpell(Fog, SPELL_FOG_FORCE, true);
                            }
                        }
                        events.ScheduleEvent(EVENT_SUMMON_FOG, 1000);
                        break;
                }
            }
        }

        void DespawnSummons(uint32 entry)
        {
            std::list<Creature*> templist;
            float x, y, z;
            me->GetPosition(x, y, z);

            CellCoord pair(Trinity::ComputeCellCoord(x, y));
            Cell cell(pair);
            cell.SetNoCreate();

            Trinity::AllCreaturesOfEntryInRange check(me, entry, 100);
            Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange> searcher(me, templist, check);
            TypeContainerVisitor<Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange>, GridTypeMapContainer> cSearcher(searcher);
            cell.Visit(pair, cSearcher, *(me->GetMap()), *me, me->GetGridActivationRange());

            for (std::list<Creature*>::const_iterator i = templist.begin(); i != templist.end(); ++i)
            {
                if (entry == MOB_VAPOR_TRAIL && phase == PHASE_FLIGHT)
                {
                    (*i)->GetPosition(x, y, z);
                    me->SummonCreature(MOB_DEAD, x, y, z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                }
                (*i)->SetVisible(false);
                (*i)->setDeathState(JUST_DIED);
                if ((*i)->getDeathState() == CORPSE)
                    (*i)->RemoveCorpse();
            }
        }
    };

};

class mob_felmyst_vapor : public CreatureScript
{
public:
    mob_felmyst_vapor() : CreatureScript("mob_felmyst_vapor") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_felmyst_vaporAI(creature);
    }

    struct mob_felmyst_vaporAI : public ScriptedAI
    {
        mob_felmyst_vaporAI(Creature* c) : ScriptedAI(c)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetSpeed(MOVE_RUN, 0.8f);
        }
        void Reset() {}
        void EnterCombat(Unit* /*who*/)
        {
            DoZoneInCombat();
            //DoCast(me, SPELL_VAPOR_FORCE, true); core bug
        }
        void UpdateAI(const uint32 /*diff*/)
        {
            if (!me->getVictim())
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    AttackStart(target);
        }
    };

};

class mob_felmyst_trail : public CreatureScript
{
public:
    mob_felmyst_trail() : CreatureScript("mob_felmyst_trail") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_felmyst_trailAI(creature);
    }

    struct mob_felmyst_trailAI : public ScriptedAI
    {
        mob_felmyst_trailAI(Creature* c) : ScriptedAI(c)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            DoCast(me, SPELL_TRAIL_TRIGGER, true);
            me->SetTarget(me->GetGUID());
            me->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 0.01f); // core bug
        }
        void Reset() {}
        void EnterCombat(Unit* /*who*/) {}
        void AttackStart(Unit* /*who*/) {}
        void MoveInLineOfSight(Unit* /*who*/) {}
        void UpdateAI(const uint32 /*diff*/) {}
    };

};

void AddSC_boss_felmyst()
{
    new boss_felmyst();
    new mob_felmyst_vapor();
    new mob_felmyst_trail();
}
