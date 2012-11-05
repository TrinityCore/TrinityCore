/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2010 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

// Known bugs:
// Anubarak - underground phase partially not worked
//          - tele after impale hit a permafrost doesn't work (the entire tele spell should be better)
// Scarab   - Kill credit isn't crediting?

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "trial_of_the_crusader.h"
#include <limits>

enum Yells
{
    SAY_INTRO               = 0,
    SAY_AGGRO               = 1,
    EMOTE_SUBMERGE          = 2,
    EMOTE_BURROWER          = 3,
    SAY_EMERGE              = 4,
    SAY_LEECHING_SWARM      = 5,
    EMOTE_LEECHING_SWARM    = 6,
    SAY_KILL_PLAYER         = 7,
    SAY_DEATH               = 8,

    EMOTE_SPIKE             = 0
};

enum Summons
{
    NPC_FROST_SPHERE     = 34606,
    NPC_BURROW           = 34862,
    NPC_BURROWER         = 34607,
    NPC_SCARAB           = 34605,
    NPC_SPIKE            = 34660
};

enum BossSpells
{
    SPELL_FREEZE_SLASH      = 66012,
    SPELL_PENETRATING_COLD  = 66013,
    SPELL_LEECHING_SWARM    = 66118,
    SPELL_LEECHING_HEAL     = 66125,
    SPELL_LEECHING_DAMAGE   = 66240,
    SPELL_MARK              = 67574,
    SPELL_SPIKE_CALL        = 66169,
    SPELL_SUBMERGE_ANUBARAK = 65981,
    SPELL_CLEAR_ALL_DEBUFFS = 34098,
    SPELL_EMERGE_ANUBARAK   = 65982,
    SPELL_SUMMON_BEATLES    = 66339,
    SPELL_SUMMON_BURROWER   = 66332,

    // Burrow
    SPELL_CHURNING_GROUND   = 66969,

    // Scarab
    SPELL_DETERMINATION     = 66092,
    SPELL_ACID_MANDIBLE     = 65774, //Passive - Triggered

    // Burrower
    SPELL_SPIDER_FRENZY     = 66128,
    SPELL_EXPOSE_WEAKNESS   = 67720, //Passive - Triggered
    SPELL_SHADOW_STRIKE     = 66134,
    SPELL_SUBMERGE_EFFECT   = 53421,
    SPELL_EMERGE_EFFECT     = 66947,

    SUMMON_SCARAB           = NPC_SCARAB,
    SUMMON_FROSTSPHERE      = NPC_FROST_SPHERE,
    SPELL_BERSERK           = 26662,

    //Frost Sphere
    SPELL_FROST_SPHERE      = 67539,
    SPELL_PERMAFROST        = 66193,
    SPELL_PERMAFROST_VISUAL = 65882,

    //Spike
    SPELL_SUMMON_SPIKE      = 66169,
    SPELL_SPIKE_SPEED1      = 65920,
    SPELL_SPIKE_TRAIL       = 65921,
    SPELL_SPIKE_SPEED2      = 65922,
    SPELL_SPIKE_SPEED3      = 65923,
    SPELL_SPIKE_FAIL        = 66181,
    SPELL_SPIKE_TELE        = 66170
};

#define SPELL_PERMAFROST_HELPER RAID_MODE<uint32>(66193, 67855, 67856, 67857)

enum SummonActions
{
    ACTION_SCARAB_SUBMERGE  = 0
};

enum MovementPoints
{
    POINT_FALL_GROUND           = 1
};

enum PursuingSpikesPhases
{
    PHASE_NO_MOVEMENT       = 0,
    PHASE_IMPALE_NORMAL     = 1,
    PHASE_IMPALE_MIDDLE     = 2,
    PHASE_IMPALE_FAST       = 3
};

class boss_anubarak_trial : public CreatureScript
{
    enum Events
    {
        EVENT_FREEZE_SLASH          = 1,
        EVENT_PENETRATING_COLD      = 2,
        EVENT_SUMMON_NERUBIAN       = 3,
        EVENT_SUBMERGE              = 4,
        EVENT_EMERGE                = 5,
        EVENT_PURSUING_SPIKE        = 6,
        EVENT_SUMMON_SCARAB         = 7
    };

    enum Phases
    {
        PHASE_MELEE         = 1,
        PHASE_SUBMERGING    = 2,
        PHASE_SUBMERGED     = 3,
        PHASE_EMERGING      = 4
    };

    public:
        boss_anubarak_trial() : CreatureScript("boss_anubarak_trial") { }

        struct boss_anubarak_trialAI : public BossAI
        {
            boss_anubarak_trialAI(Creature* creature) : BossAI(creature, BOSS_ANUBARAK)
            {
            }

            void Reset()
            {
                _Reset();
                _phase = PHASE_MELEE;
                events.ScheduleEvent(EVENT_FREEZE_SLASH, 15*IN_MILLISECONDS, 0, PHASE_MELEE);
                events.ScheduleEvent(EVENT_PENETRATING_COLD, 20*IN_MILLISECONDS, PHASE_MELEE);
                events.ScheduleEvent(EVENT_SUMMON_NERUBIAN, 10*IN_MILLISECONDS, 0, PHASE_MELEE);
                events.ScheduleEvent(EVENT_SUBMERGE, 80*IN_MILLISECONDS, 0, PHASE_MELEE);
                _berserkTimer = 10*MINUTE*IN_MILLISECONDS;

                if (!IsHeroic())
                    _frostSphereTimer = 20*IN_MILLISECONDS;

                _intro = true;
                _reachedPhase3 = false;
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                // clean up spawned Frost Spheres
                std::list<Creature*> FrostSphereList;
                me->GetCreatureListWithEntryInGrid(FrostSphereList, NPC_FROST_SPHERE, 150.0f);
                if (!FrostSphereList.empty())
                    for (std::list<Creature*>::iterator itr = FrostSphereList.begin(); itr != FrostSphereList.end(); itr++)
                        (*itr)->DespawnOrUnsummon();

                _burrowGUID.clear();
            }

            void KilledUnit(Unit* who)
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                {
                    Talk(SAY_KILL_PLAYER);
                    if (instance)
                        instance->SetData(DATA_TRIBUTE_TO_IMMORTALITY_ELEGIBLE, 0);
                }
            }

            void MoveInLineOfSight(Unit* /*who*/)
            {
                if (!_intro)
                {
                    Talk(SAY_INTRO);
                    _intro = false;
                }
            }

            void JustReachedHome()
            {
                if (instance)
                    instance->SetBossState(BOSS_ANUBARAK, FAIL);
                //Summon Scarab Swarms neutral at random places
                for (int i = 0; i < 10; i++)
                    if (Creature* temp = me->SummonCreature(NPC_SCARAB, AnubarakLoc[1].GetPositionX()+urand(0, 50)-25, AnubarakLoc[1].GetPositionY()+urand(0, 50)-25, AnubarakLoc[1].GetPositionZ()))
                        temp->setFaction(31);
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
                Talk(SAY_DEATH);

                // despawn frostspheres and Burrowers on death
                std::list<Creature*> AddList;
                me->GetCreatureListWithEntryInGrid(AddList, NPC_FROST_SPHERE, 150.0f);
                me->GetCreatureListWithEntryInGrid(AddList, NPC_BURROWER, 150.0f);
                if (!AddList.empty())
                    for (std::list<Creature*>::iterator itr = AddList.begin(); itr != AddList.end(); itr++)
                        (*itr)->DespawnOrUnsummon();
            }

            void JustSummoned(Creature* summoned)
            {
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true);
                switch (summoned->GetEntry())
                {
                    case NPC_BURROW:
                        _burrowGUID.push_back(summoned->GetGUID());
                        summoned->SetReactState(REACT_PASSIVE);
                        summoned->CastSpell(summoned, SPELL_CHURNING_GROUND, false);
                        summoned->SetDisplayId(summoned->GetCreatureTemplate()->Modelid2);
                        break;
                    case NPC_SPIKE:
                        summoned->CombatStart(target);
                        summoned->SetDisplayId(summoned->GetCreatureTemplate()->Modelid1);
                        Talk(EMOTE_SPIKE, target->GetGUID());
                        break;
                    default:
                        break;
                }
                summons.Summon(summoned);
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                Talk(SAY_AGGRO);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);

                // Despawn Scarab Swarms neutral
                EntryCheckPredicate pred(NPC_SCARAB);
                summons.DoAction(ACTION_SCARAB_SUBMERGE, pred);

                // Spawn Burrow
                for (int i = 0; i < 4; i++)
                    me->SummonCreature(NPC_BURROW, AnubarakLoc[i + 2]);

                // Spawn 6 Frost Spheres at start
                for (int i = 0; i < 6; i++)
                    SummonFrostSphere();
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(uiDiff);

                switch (_phase)
                {
                    case PHASE_MELEE:
                        while (uint32 eventId = events.ExecuteEvent())
                        {
                            switch (eventId)
                            {
                                case EVENT_FREEZE_SLASH:
                                    DoCastVictim(SPELL_FREEZE_SLASH);
                                    events.ScheduleEvent(EVENT_FREEZE_SLASH, 15*IN_MILLISECONDS, 0, PHASE_MELEE);
                                    return;
                                case EVENT_PENETRATING_COLD:
                                    me->CastCustomSpell(SPELL_PENETRATING_COLD, SPELLVALUE_MAX_TARGETS, RAID_MODE(2, 5, 2, 5));
                                    events.ScheduleEvent(EVENT_PENETRATING_COLD, 20*IN_MILLISECONDS, 0, PHASE_MELEE);
                                    return;
                                case EVENT_SUMMON_NERUBIAN:
                                    if (IsHeroic() || !_reachedPhase3)
                                        me->CastCustomSpell(SPELL_SUMMON_BURROWER, SPELLVALUE_MAX_TARGETS, RAID_MODE(1, 2, 2, 4));
                                    events.ScheduleEvent(EVENT_SUMMON_NERUBIAN, 45*IN_MILLISECONDS, 0, PHASE_MELEE);
                                    return;
                                case EVENT_SUBMERGE:
                                    if (!_reachedPhase3 && !me->HasAura(SPELL_BERSERK))
                                        _phase = PHASE_SUBMERGING;
                                    return;
                                default:
                                    return;
                            }
                        }
                        break;
                    case PHASE_SUBMERGING:
                        DoCast(me, SPELL_SUBMERGE_ANUBARAK);
                        DoCast(me, SPELL_CLEAR_ALL_DEBUFFS);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        Talk(EMOTE_BURROWER);
                        _phase = PHASE_SUBMERGED;
                        events.ScheduleEvent(EVENT_PURSUING_SPIKE, 2*IN_MILLISECONDS, 0, PHASE_SUBMERGED);
                        events.ScheduleEvent(EVENT_SUMMON_SCARAB, 4*IN_MILLISECONDS, 0, PHASE_SUBMERGED);
                        events.ScheduleEvent(EVENT_EMERGE, 1*MINUTE*IN_MILLISECONDS);
                        break;
                    case PHASE_SUBMERGED:
                        while (uint32 eventId = events.ExecuteEvent())
                        {
                            switch (eventId)
                            {
                                case EVENT_PURSUING_SPIKE:
                                    DoCast(SPELL_SPIKE_CALL);
                                    return;
                                case EVENT_SUMMON_SCARAB:
                                {
                                    /* WORKAROUND
                                     * - The correct implementation is more likely the comment below but it needs spell knowledge
                                     */
                                    std::list<uint64>::iterator i = _burrowGUID.begin();
                                    uint32 at = urand(0, _burrowGUID.size()-1);
                                    for (uint32 k = 0; k < at; k++)
                                        ++i;
                                    if (Creature* pBurrow = Unit::GetCreature(*me, *i))
                                        pBurrow->CastSpell(pBurrow, 66340, false);

                                    events.ScheduleEvent(EVENT_SUMMON_SCARAB, 4*IN_MILLISECONDS, 0, PHASE_SUBMERGED);

                                    /*It seems that this spell have something more that needs to be taken into account
                                    //Need more sniff info
                                    DoCast(SPELL_SUMMON_BEATLES);
                                    // Just to make sure it won't happen again in this phase
                                    m_uiSummonScarabTimer = 90*IN_MILLISECONDS;*/
                                    return;
                                }
                                case EVENT_EMERGE:
                                    _phase = PHASE_EMERGING;
                                    events.ScheduleEvent(EVENT_SUBMERGE, 80*IN_MILLISECONDS, 0, PHASE_MELEE);
                                    return;
                                default:
                                    return;
                            }
                        }
                        break;
                    case PHASE_EMERGING:
                        _phase = PHASE_MELEE;
                        DoCast(SPELL_SPIKE_TELE);
                        summons.DespawnEntry(NPC_SPIKE);
                        me->RemoveAurasDueToSpell(SPELL_SUBMERGE_ANUBARAK);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        DoCast(me, SPELL_EMERGE_ANUBARAK);
                        events.ScheduleEvent(EVENT_FREEZE_SLASH, 15*IN_MILLISECONDS, 0, PHASE_MELEE);
                        events.ScheduleEvent(EVENT_PENETRATING_COLD, 20*IN_MILLISECONDS, PHASE_MELEE);
                        events.ScheduleEvent(EVENT_SUMMON_NERUBIAN, 10*IN_MILLISECONDS, 0, PHASE_MELEE);
                        events.ScheduleEvent(EVENT_SUBMERGE, 80*IN_MILLISECONDS, 0, PHASE_MELEE);
                        break;
                    default:
                        break;
                }

                if (!IsHeroic() && _frostSphereTimer <= uiDiff)
                {
                    SummonFrostSphere();
                    _frostSphereTimer = urand(15*IN_MILLISECONDS, 25*IN_MILLISECONDS);
                }
                else
                    _frostSphereTimer -= uiDiff;

                if (_berserkTimer <= uiDiff && !me->HasAura(SPELL_BERSERK))
                    DoCast(me, SPELL_BERSERK);
                else
                    _berserkTimer -= uiDiff;

                if (HealthBelowPct(30) && _phase == PHASE_MELEE && !_reachedPhase3)
                {
                    _reachedPhase3 = true;
                    DoCastAOE(SPELL_LEECHING_SWARM);
                    Talk(EMOTE_LEECHING_SWARM);
                    Talk(SAY_LEECHING_SWARM);
                }

                DoMeleeAttackIfReady();
            }

            void SummonFrostSphere()
            {
                float x = frand(700.f, 780.f);
                float y = frand(105.f, 165.f);
                float z = 155.6f;
                me->SummonCreature(NPC_FROST_SPHERE, x, y, z);
            }

            private:
                std::list<uint64> _burrowGUID;
                bool _intro;
                bool _reachedPhase3;
                Phases _phase;
                uint32 _frostSphereTimer;
                uint32 _berserkTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_anubarak_trialAI(creature);
        };
};

class mob_swarm_scarab : public CreatureScript
{
    public:
        mob_swarm_scarab() : CreatureScript("mob_swarm_scarab") { }

        struct mob_swarm_scarabAI : public ScriptedAI
        {
            mob_swarm_scarabAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = creature->GetInstanceScript();
            }

            void Reset()
            {
                me->SetCorpseDelay(0);
                _determinationTimer = urand(5*IN_MILLISECONDS, 60*IN_MILLISECONDS);
                DoCast(me, SPELL_ACID_MANDIBLE);
                me->SetInCombatWithZone();
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                    me->AddThreat(target, 20000.0f);
                if (!me->isInCombat())
                    me->DisappearAndDie();
            }

            void DoAction(const int32 actionId)
            {
                switch (actionId)
                {
                    case ACTION_SCARAB_SUBMERGE:
                        DoCast(SPELL_SUBMERGE_EFFECT);
                        me->DespawnOrUnsummon(1*IN_MILLISECONDS);
                        break;
                    default:
                        break;
                }
            }

            void JustDied(Unit* killer)
            {
                DoCast(killer, RAID_MODE(SPELL_TRAITOR_KING_10, SPELL_TRAITOR_KING_25));
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (_instance && _instance->GetBossState(BOSS_ANUBARAK) != IN_PROGRESS)
                    me->DisappearAndDie();

                if (!UpdateVictim())
                    return;

                /* Bosskillers don't recognize */
                if (_determinationTimer <= uiDiff)
                {
                    DoCast(me, SPELL_DETERMINATION);
                    _determinationTimer = urand(10*IN_MILLISECONDS, 60*IN_MILLISECONDS);
                }
                else
                    _determinationTimer -= uiDiff;

                DoMeleeAttackIfReady();
            }

            private:
                InstanceScript* _instance;
                uint32 _determinationTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_swarm_scarabAI(creature);
        };
};

class mob_nerubian_burrower : public CreatureScript
{
    enum Phases
    {
        PHASE_GROUND    = 0,
        PHASE_SUBMERGED = 1
    };

    enum Events
    {
        EVENT_SUBMERGE          = 1,
        EVENT_SHADOW_STRIKE     = 2
    };

    public:
        mob_nerubian_burrower() : CreatureScript("mob_nerubian_burrower") { }

        struct mob_nerubian_burrowerAI : public ScriptedAI
        {
            mob_nerubian_burrowerAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = creature->GetInstanceScript();
            }

            void Reset()
            {
                me->SetCorpseDelay(0);
                _events.ScheduleEvent(EVENT_SUBMERGE, 30*IN_MILLISECONDS, 0, PHASE_GROUND);
                if (IsHeroic())
                    _events.ScheduleEvent(EVENT_SHADOW_STRIKE, urand(15*IN_MILLISECONDS, 25*IN_MILLISECONDS), 0, PHASE_GROUND);
                DoCast(me, SPELL_EXPOSE_WEAKNESS);
                DoCast(me, SPELL_SPIDER_FRENZY);
                me->SetInCombatWithZone();
                _phase = PHASE_GROUND;
                if (!me->isInCombat())
                    me->DisappearAndDie();
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (_instance && _instance->GetBossState(BOSS_ANUBARAK) != IN_PROGRESS)
                    me->DisappearAndDie();

                if (!UpdateVictim() && !me->HasAura(SPELL_SUBMERGE_EFFECT))
                    return;

                _events.Update(uiDiff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SUBMERGE:
                            if (me->HasAura(SPELL_SUBMERGE_EFFECT))
                            {
                                me->RemoveAurasDueToSpell(SPELL_SUBMERGE_EFFECT);
                                DoCast(me, SPELL_EMERGE_EFFECT);
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE);
                                me->CombatStart(me->SelectNearestTarget());
                                if (IsHeroic())
                                    _events.ScheduleEvent(EVENT_SHADOW_STRIKE, 20*IN_MILLISECONDS, 0, PHASE_GROUND);
                                _phase = PHASE_GROUND;
                            }
                            else
                            {
                                if (!me->HasAura(SPELL_PERMAFROST_HELPER))
                                {
                                    DoCast(me, SPELL_SUBMERGE_EFFECT);
                                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE);
                                    me->CombatStop();
                                    _phase = PHASE_SUBMERGED;
                                }
                            }
                            _events.ScheduleEvent(EVENT_SUBMERGE, 20*IN_MILLISECONDS);
                            return;
                        case EVENT_SHADOW_STRIKE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                DoCast(target, SPELL_SHADOW_STRIKE);
                            _events.ScheduleEvent(EVENT_SHADOW_STRIKE, 20*IN_MILLISECONDS, 0, PHASE_GROUND);
                            return;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            private:
                Phases _phase;
                EventMap _events;
                InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_nerubian_burrowerAI(creature);
        };
};

class mob_frost_sphere : public CreatureScript
{
    public:
        mob_frost_sphere() : CreatureScript("mob_frost_sphere") { }

        struct mob_frost_sphereAI : public ScriptedAI
        {
            mob_frost_sphereAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void Reset()
            {
                _isFalling = false;
                me->SetReactState(REACT_PASSIVE);
                //! Confirmed sniff 3.3.5.a
                me->SetDisableGravity(true);
                me->SetByteValue(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                //! end
                me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
                me->SetSpeed(MOVE_FLIGHT, 0.5f, false);
                me->CombatStop(true);
                me->GetMotionMaster()->MoveRandom(20.0f);
                DoCast(SPELL_FROST_SPHERE);
            }

            void DamageTaken(Unit* /*who*/, uint32& damage)
            {
                if (me->GetHealth() <= damage)
                {
                    damage = 0;
                    if (!_isFalling)
                    {
                        _isFalling = true;
                        me->GetMotionMaster()->MoveIdle();
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        //At hit the ground
                        me->HandleEmoteCommand(EMOTE_ONESHOT_FLYDEATH);
                        me->GetMotionMaster()->MoveFall(POINT_FALL_GROUND);
                        me->SetDisplayId(11686);
                    }
                }
            }

            void MovementInform(uint32 type, uint32 pointId)
            {
                if (type != EFFECT_MOTION_TYPE)
                    return;

                switch (pointId)
                {
                    case POINT_FALL_GROUND:
                        me->RemoveAurasDueToSpell(SPELL_FROST_SPHERE);
                        DoCast(SPELL_PERMAFROST_VISUAL);
                        DoCast(SPELL_PERMAFROST);
                        me->SetObjectScale(2.0f);
                        break;
                    default:
                        break;
                }
            }

            private:
                bool _isFalling;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_frost_sphereAI(creature);
        };
};

class mob_anubarak_spike : public CreatureScript
{
    public:
        mob_anubarak_spike() : CreatureScript("mob_anubarak_spike") { }

        struct mob_anubarak_spikeAI : public ScriptedAI
        {
            mob_anubarak_spikeAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void Reset()
            {
                _phase = PHASE_NO_MOVEMENT;
                _phaseSwitchTimer = 1;
                // make sure the spike has everyone on threat list
                me->SetInCombatWithZone();
            }

            bool CanAIAttack(Unit const* victim) const
            {
                return victim->GetTypeId() == TYPEID_PLAYER;
            }

            void EnterCombat(Unit* who)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                {
                    StartChase(target);
                    Talk(EMOTE_SPIKE, who->GetGUID());
                }
            }

            void DamageTaken(Unit* /*who*/, uint32& uiDamage)
            {
                uiDamage = 0;
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                {
                    me->DisappearAndDie();
                    return;
                }

                if (_phaseSwitchTimer)
                {
                    if (_phaseSwitchTimer <= uiDiff)
                    {
                        switch (_phase)
                        {
                            case PHASE_NO_MOVEMENT:
                                DoCast(me, SPELL_SPIKE_SPEED1);
                                DoCast(me, SPELL_SPIKE_TRAIL);
                                _phase = PHASE_IMPALE_NORMAL;
                                if (Unit* target2 = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                {
                                    StartChase(target2);
                                    Talk(EMOTE_SPIKE, target2->GetGUID());
                                }
                                _phaseSwitchTimer = 7*IN_MILLISECONDS;
                                return;
                            case PHASE_IMPALE_NORMAL:
                                DoCast(me, SPELL_SPIKE_SPEED2);
                                _phase = PHASE_IMPALE_MIDDLE;
                                _phaseSwitchTimer = 7*IN_MILLISECONDS;
                                return;
                            case PHASE_IMPALE_MIDDLE:
                                DoCast(me, SPELL_SPIKE_SPEED3);
                                _phase = PHASE_IMPALE_FAST;
                                _phaseSwitchTimer = 0;
                                return;
                            default:
                                return;
                        }
                    }
                    else
                        _phaseSwitchTimer -= uiDiff;
                }
            }

            void MoveInLineOfSight(Unit* pWho)
            {
                if (!pWho)
                    return;

                if (pWho->GetEntry() != NPC_FROST_SPHERE)
                    return;

                if (_phase == PHASE_NO_MOVEMENT)
                    return;

                if (me->IsWithinDist(pWho, 7.0f))
                {
                    switch (_phase)
                    {
                        case PHASE_IMPALE_NORMAL:
                            me->RemoveAurasDueToSpell(SPELL_SPIKE_SPEED1);
                            break;
                        case PHASE_IMPALE_MIDDLE:
                            me->RemoveAurasDueToSpell(SPELL_SPIKE_SPEED2);
                            break;
                        case PHASE_IMPALE_FAST:
                            me->RemoveAurasDueToSpell(SPELL_SPIKE_SPEED3);
                            break;
                        default:
                            break;
                    }

                    me->CastSpell(me, SPELL_SPIKE_FAIL, true);

                    pWho->ToCreature()->DespawnOrUnsummon(3*IN_MILLISECONDS);

                    // After the spikes hit the icy surface they can't move for about ~5 seconds
                    _phase = PHASE_NO_MOVEMENT;
                    _phaseSwitchTimer = 5*IN_MILLISECONDS;
                    SetCombatMovement(false);
                    me->GetMotionMaster()->MoveIdle();
                    me->GetMotionMaster()->Clear();
                }
            }

            void StartChase(Unit* who)
            {
                DoCast(who, SPELL_MARK);
                me->SetSpeed(MOVE_RUN, 0.5f);
                // make sure the Spine will really follow the one he should
                me->getThreatManager().clearReferences();
                me->SetInCombatWithZone();
                me->getThreatManager().addThreat(who, std::numeric_limits<float>::max());
                me->GetMotionMaster()->Clear(true);
                me->GetMotionMaster()->MoveChase(who);
                me->TauntApply(who);
            }

            private:
                uint32 _phaseSwitchTimer;
                PursuingSpikesPhases _phase;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_anubarak_spikeAI(creature);
        };
};

class spell_impale : public SpellScriptLoader
{
    public:
        spell_impale() : SpellScriptLoader("spell_impale") { }

        class spell_impale_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_impale_SpellScript);

            void HandleDamageCalc(SpellEffIndex /*effIndex*/)
            {
                Unit* target = GetHitUnit();
                uint32 permafrost = sSpellMgr->GetSpellIdForDifficulty(SPELL_PERMAFROST, target);

                // make sure Impale doesnt do damage if we are standing on permafrost
                if (target && target->HasAura(permafrost))
                    SetHitDamage(0);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_impale_SpellScript::HandleDamageCalc, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_impale_SpellScript();
        }
};

void AddSC_boss_anubarak_trial()
{
    new boss_anubarak_trial();
    new mob_swarm_scarab();
    new mob_nerubian_burrower();
    new mob_anubarak_spike();
    new mob_frost_sphere();

    new spell_impale();
}
