/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "SpellScript.h"
#include "SpellAuraEffects.h"
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
    SPELL_FREEZE_SLASH          = 66012,
    SPELL_PENETRATING_COLD      = 66013,
    SPELL_LEECHING_SWARM        = 66118,
    SPELL_LEECHING_SWARM_HEAL   = 66125,
    SPELL_LEECHING_SWARM_DMG    = 66240,
    SPELL_MARK                  = 67574,
    SPELL_SPIKE_CALL            = 66169,
    SPELL_SUBMERGE_ANUBARAK     = 65981,
    SPELL_CLEAR_ALL_DEBUFFS     = 34098,
    SPELL_EMERGE_ANUBARAK       = 65982,
    SPELL_SUMMON_BEATLES        = 66339,
    SPELL_SUMMON_BURROWER       = 66332,

    // Burrow
    SPELL_CHURNING_GROUND       = 66969,

    // Scarab
    SPELL_DETERMINATION         = 66092,
    SPELL_ACID_MANDIBLE         = 65774, //Passive - Triggered

    // Burrower
    SPELL_SPIDER_FRENZY         = 66128,
    SPELL_EXPOSE_WEAKNESS       = 67720, //Passive - Triggered
    SPELL_SHADOW_STRIKE         = 66134,
    SPELL_SUBMERGE_EFFECT       = 68394,
    SPELL_AWAKENED              = 66311,
    SPELL_EMERGE_EFFECT         = 65982,

    SPELL_PERSISTENT_DIRT       = 68048,

    SUMMON_SCARAB               = NPC_SCARAB,
    SUMMON_FROSTSPHERE          = NPC_FROST_SPHERE,
    SPELL_BERSERK               = 26662,

    //Frost Sphere
    SPELL_FROST_SPHERE          = 67539,
    SPELL_PERMAFROST            = 66193,
    SPELL_PERMAFROST_VISUAL     = 65882,
    SPELL_PERMAFROST_MODEL      = 66185,

    //Spike
    SPELL_SUMMON_SPIKE          = 66169,
    SPELL_SPIKE_SPEED1          = 65920,
    SPELL_SPIKE_TRAIL           = 65921,
    SPELL_SPIKE_SPEED2          = 65922,
    SPELL_SPIKE_SPEED3          = 65923,
    SPELL_SPIKE_FAIL            = 66181,
    SPELL_SPIKE_TELE            = 66170
};

#define SPELL_PERMAFROST_HELPER RAID_MODE<uint32>(66193, 67855, 67856, 67857)

enum SummonActions
{
    ACTION_SHADOW_STRIKE    = 0,
    ACTION_SCARAB_SUBMERGE  = 1
};

const Position SphereSpawn[6] =
{
    {779.8038f, 150.6580f, 158.1426f, 0},
    {736.0243f, 113.4201f, 158.0226f, 0},
    {712.5712f, 160.9948f, 158.4368f, 0},
    {701.4271f, 126.4740f, 158.0205f, 0},
    {747.9202f, 155.0920f, 158.0613f, 0},
    {769.6285f, 121.1024f, 158.0504f, 0},
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

enum Events
{
    // Anub'arak
    EVENT_FREEZE_SLASH              = 1,
    EVENT_PENETRATING_COLD          = 2,
    EVENT_SUMMON_NERUBIAN           = 3,
    EVENT_NERUBIAN_SHADOW_STRIKE    = 4,
    EVENT_SUBMERGE                  = 5,
    EVENT_EMERGE                    = 6,
    EVENT_PURSUING_SPIKE            = 7,
    EVENT_SUMMON_SCARAB             = 8,
    EVENT_SUMMON_FROST_SPHERE       = 9,
    EVENT_BERSERK                   = 10
};

enum Phases
{
    // Anub'arak
    PHASE_MELEE                 = 1,
    PHASE_SUBMERGED             = 2
};

class boss_anubarak_trial : public CreatureScript
{
    public:
        boss_anubarak_trial() : CreatureScript("boss_anubarak_trial") { }

        struct boss_anubarak_trialAI : public BossAI
        {
            boss_anubarak_trialAI(Creature* creature) : BossAI(creature, BOSS_ANUBARAK)
            {
            }

            void Reset() OVERRIDE
            {
                _Reset();
                events.SetPhase(PHASE_MELEE);
                events.ScheduleEvent(EVENT_FREEZE_SLASH, 15*IN_MILLISECONDS, 0, PHASE_MELEE);
                events.ScheduleEvent(EVENT_PENETRATING_COLD, 20*IN_MILLISECONDS, PHASE_MELEE);
                events.ScheduleEvent(EVENT_SUMMON_NERUBIAN, 10*IN_MILLISECONDS, 0, PHASE_MELEE);
                events.ScheduleEvent(EVENT_SUBMERGE, 80*IN_MILLISECONDS, 0, PHASE_MELEE);
                events.ScheduleEvent(EVENT_BERSERK, 10*MINUTE*IN_MILLISECONDS);
                if (IsHeroic())
                    events.ScheduleEvent(EVENT_NERUBIAN_SHADOW_STRIKE, 30*IN_MILLISECONDS, 0, PHASE_MELEE);

                if (!IsHeroic())
                    events.ScheduleEvent(EVENT_SUMMON_FROST_SPHERE, 20*IN_MILLISECONDS);

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

            void KilledUnit(Unit* who) OVERRIDE
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                {
                    Talk(SAY_KILL_PLAYER);
                    instance->SetData(DATA_TRIBUTE_TO_IMMORTALITY_ELIGIBLE, 0);
                }
            }

            void MoveInLineOfSight(Unit* /*who*/) OVERRIDE

            {
                if (!_intro)
                {
                    Talk(SAY_INTRO);
                    _intro = false;
                }
            }

            void JustReachedHome() OVERRIDE
            {
                instance->SetBossState(BOSS_ANUBARAK, FAIL);
                //Summon Scarab Swarms neutral at random places
                for (int i = 0; i < 10; i++)
                    if (Creature* temp = me->SummonCreature(NPC_SCARAB, AnubarakLoc[1].GetPositionX()+urand(0, 50)-25, AnubarakLoc[1].GetPositionY()+urand(0, 50)-25, AnubarakLoc[1].GetPositionZ()))
                    {
                        temp->setFaction(31);
                        temp->GetMotionMaster()->MoveRandom(10);
                    }
            }

            void JustDied(Unit* /*killer*/) OVERRIDE
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

            void JustSummoned(Creature* summoned) OVERRIDE
            {
                switch (summoned->GetEntry())
                {
                    case NPC_BURROW:
                        _burrowGUID.push_back(summoned->GetGUID());
                        summoned->SetReactState(REACT_PASSIVE);
                        summoned->CastSpell(summoned, SPELL_CHURNING_GROUND, false);
                        summoned->SetDisplayId(summoned->GetCreatureTemplate()->Modelid2);
                        break;
                    case NPC_SPIKE:
                        summoned->SetDisplayId(summoned->GetCreatureTemplate()->Modelid1);
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        {
                            summoned->CombatStart(target);
                            Talk(EMOTE_SPIKE, target);
                        }
                        break;
                    default:
                        break;
                }
                summons.Summon(summoned);
            }

            void EnterCombat(Unit* /*who*/) OVERRIDE
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
                    if (Unit* summoned = me->SummonCreature(NPC_FROST_SPHERE, SphereSpawn[i]))
                        _sphereGUID[i] = summoned->GetGUID();
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

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
                        case EVENT_NERUBIAN_SHADOW_STRIKE:
                        {
                            EntryCheckPredicate pred(NPC_BURROWER);
                            summons.DoAction(ACTION_SHADOW_STRIKE, pred);
                            events.ScheduleEvent(EVENT_NERUBIAN_SHADOW_STRIKE, 30*IN_MILLISECONDS, 0, PHASE_MELEE);
                            break;
                        }
                        case EVENT_SUBMERGE:
                            if (!_reachedPhase3 && !me->HasAura(SPELL_BERSERK))
                            {
                                DoCast(me, SPELL_SUBMERGE_ANUBARAK);
                                DoCast(me, SPELL_CLEAR_ALL_DEBUFFS);
                                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                                Talk(EMOTE_BURROWER);
                                events.SetPhase(PHASE_SUBMERGED);
                                events.ScheduleEvent(EVENT_PURSUING_SPIKE, 2*IN_MILLISECONDS, 0, PHASE_SUBMERGED);
                                events.ScheduleEvent(EVENT_SUMMON_SCARAB, 4*IN_MILLISECONDS, 0, PHASE_SUBMERGED);
                                events.ScheduleEvent(EVENT_EMERGE, 1*MINUTE*IN_MILLISECONDS, 0, PHASE_SUBMERGED);
                            }
                            break;
                        case EVENT_PURSUING_SPIKE:
                            DoCast(SPELL_SPIKE_CALL);
                            break;
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
                            break;
                        }
                        case EVENT_EMERGE:
                            events.ScheduleEvent(EVENT_SUBMERGE, 80*IN_MILLISECONDS, 0, PHASE_MELEE);
                            DoCast(SPELL_SPIKE_TELE);
                            summons.DespawnEntry(NPC_SPIKE);
                            me->RemoveAurasDueToSpell(SPELL_SUBMERGE_ANUBARAK);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                            DoCast(me, SPELL_EMERGE_ANUBARAK);
                            events.SetPhase(PHASE_MELEE);
                            events.ScheduleEvent(EVENT_FREEZE_SLASH, 15*IN_MILLISECONDS, 0, PHASE_MELEE);
                            events.ScheduleEvent(EVENT_PENETRATING_COLD, 20*IN_MILLISECONDS, PHASE_MELEE);
                            events.ScheduleEvent(EVENT_SUMMON_NERUBIAN, 10*IN_MILLISECONDS, 0, PHASE_MELEE);
                            events.ScheduleEvent(EVENT_SUBMERGE, 80*IN_MILLISECONDS, 0, PHASE_MELEE);
                            if (IsHeroic())
                                events.ScheduleEvent(EVENT_NERUBIAN_SHADOW_STRIKE, 30*IN_MILLISECONDS, 0, PHASE_MELEE);
                            return;
                        case EVENT_SUMMON_FROST_SPHERE:
                        {
                            uint8 startAt = urand(0, 5);
                            uint8 i = startAt;
                            do
                            {
                                if (Unit* pSphere = Unit::GetCreature(*me, _sphereGUID[i]))
                                {
                                    if (!pSphere->HasAura(SPELL_FROST_SPHERE))
                                    {
                                        if (Creature* summon = me->SummonCreature(NPC_FROST_SPHERE, SphereSpawn[i]))
                                            _sphereGUID[i] = summon->GetGUID();
                                        break;
                                    }
                                }
                                i = (i + 1) % 6;
                            }
                            while
                                (i != startAt);
                            events.ScheduleEvent(EVENT_SUMMON_FROST_SPHERE, urand(20*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                            break;
                        }
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK);
                            break;
                        default:
                            break;
                    }

                }

                if (HealthBelowPct(30) && events.IsInPhase(PHASE_MELEE) && !_reachedPhase3)
                {
                    _reachedPhase3 = true;
                    DoCastAOE(SPELL_LEECHING_SWARM);
                    Talk(EMOTE_LEECHING_SWARM);
                    Talk(SAY_LEECHING_SWARM);
                }

                if (events.IsInPhase(PHASE_MELEE))
                    DoMeleeAttackIfReady();
            }

            private:
                std::list<uint64> _burrowGUID;
                uint64 _sphereGUID[6];
                bool _intro;
                bool _reachedPhase3;
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetInstanceAI<boss_anubarak_trialAI>(creature);
        };
};

class npc_swarm_scarab : public CreatureScript
{
    public:
        npc_swarm_scarab() : CreatureScript("npc_swarm_scarab") { }

        struct npc_swarm_scarabAI : public ScriptedAI
        {
            npc_swarm_scarabAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = creature->GetInstanceScript();
            }

            void Reset() OVERRIDE
            {
                me->SetCorpseDelay(0);
                _determinationTimer = urand(5*IN_MILLISECONDS, 60*IN_MILLISECONDS);
                DoCast(me, SPELL_ACID_MANDIBLE);
                me->SetInCombatWithZone();
                if (me->IsInCombat())
                    if (Creature* Anubarak = ObjectAccessor::GetCreature(*me, _instance->GetData64(NPC_ANUBARAK)))
                        Anubarak->AI()->JustSummoned(me);
            }

            void DoAction(int32 actionId) OVERRIDE
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

            void JustDied(Unit* killer) OVERRIDE
            {
                DoCast(killer, RAID_MODE(SPELL_TRAITOR_KING_10, SPELL_TRAITOR_KING_25));
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (_instance && _instance->GetBossState(BOSS_ANUBARAK) != IN_PROGRESS)
                    me->DisappearAndDie();

                if (!UpdateVictim())
                    return;

                /* Bosskillers don't recognize */
                if (_determinationTimer <= diff)
                {
                    DoCast(me, SPELL_DETERMINATION);
                    _determinationTimer = urand(10*IN_MILLISECONDS, 60*IN_MILLISECONDS);
                }
                else
                    _determinationTimer -= diff;

                DoMeleeAttackIfReady();
            }

            private:
                InstanceScript* _instance;
                uint32 _determinationTimer;
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetInstanceAI<npc_swarm_scarabAI>(creature);
        };
};

class npc_nerubian_burrower : public CreatureScript
{
    public:
        npc_nerubian_burrower() : CreatureScript("npc_nerubian_burrower") { }

        struct npc_nerubian_burrowerAI : public ScriptedAI
        {
            npc_nerubian_burrowerAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = creature->GetInstanceScript();
            }

            void Reset() OVERRIDE
            {
                me->SetCorpseDelay(10);
                _submergeTimer = 30*IN_MILLISECONDS;
                DoCast(me, SPELL_EXPOSE_WEAKNESS);
                DoCast(me, SPELL_SPIDER_FRENZY);
                DoCast(me, SPELL_AWAKENED);
                me->SetInCombatWithZone();
                if (me->IsInCombat())
                    if (Creature* Anubarak = ObjectAccessor::GetCreature(*me, _instance->GetData64(NPC_ANUBARAK)))
                        Anubarak->AI()->JustSummoned(me);
            }

            void DoAction(int32 actionId) OVERRIDE
            {
                switch (actionId)
                {
                    case ACTION_SHADOW_STRIKE:
                        if (!me->HasAura(SPELL_AWAKENED))
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_SHADOW_STRIKE);
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (_instance && _instance->GetBossState(BOSS_ANUBARAK) != IN_PROGRESS)
                    me->DisappearAndDie();

                if (!UpdateVictim() && !me->HasAura(SPELL_SUBMERGE_EFFECT))
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if ((_submergeTimer <= diff) && HealthBelowPct(80))
                {
                    if (me->HasAura(SPELL_SUBMERGE_EFFECT))
                    {
                        me->RemoveAurasDueToSpell(SPELL_SUBMERGE_EFFECT);
                        DoCast(me, SPELL_EMERGE_EFFECT);
                        DoCast(me, SPELL_AWAKENED);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    }
                    else
                    {
                        if (!me->HasAura(SPELL_PERMAFROST_HELPER))
                        {
                            DoCast(me, SPELL_SUBMERGE_EFFECT);
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            DoCast(me, SPELL_PERSISTENT_DIRT, true);
                        }
                    }
                    _submergeTimer = 20*IN_MILLISECONDS;
                }
                else
                    _submergeTimer -= diff;

                DoMeleeAttackIfReady();
            }

            private:
                uint32 _submergeTimer;
                EventMap _events;
                InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetInstanceAI<npc_nerubian_burrowerAI>(creature);
        };
};

class npc_frost_sphere : public CreatureScript
{
    public:
        npc_frost_sphere() : CreatureScript("npc_frost_sphere") { }

        struct npc_frost_sphereAI : public ScriptedAI
        {
            npc_frost_sphereAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void Reset() OVERRIDE
            {
                me->SetReactState(REACT_PASSIVE);
                DoCast(SPELL_FROST_SPHERE);
                me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
                me->GetMotionMaster()->MoveRandom(20.0f);
            }

            void DamageTaken(Unit* /*who*/, uint32& damage) OVERRIDE
            {
                if (me->GetHealth() <= damage)
                {
                    damage = 0;
                    float floorZ = me->GetMap()->GetHeight(me->GetPhaseMask(), me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
                    if (fabs(me->GetPositionZ() - floorZ) < 0.1f)
                    {
                        // we are close to the ground
                        me->GetMotionMaster()->MoveIdle();
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        me->RemoveAurasDueToSpell(SPELL_FROST_SPHERE);
                        DoCast(SPELL_PERMAFROST_MODEL);
                        DoCast(SPELL_PERMAFROST);
                        me->SetObjectScale(2.0f);
                    }
                    else
                    {
                        // we are in air
                        me->GetMotionMaster()->MoveIdle();
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        //At hit the ground
                        me->HandleEmoteCommand(EMOTE_ONESHOT_FLYDEATH);
                        me->GetMotionMaster()->MoveFall(POINT_FALL_GROUND);
                    }
                }
            }

            void MovementInform(uint32 type, uint32 pointId) OVERRIDE
            {
                if (type != EFFECT_MOTION_TYPE)
                    return;

                switch (pointId)
                {
                    case POINT_FALL_GROUND:
                        me->RemoveAurasDueToSpell(SPELL_FROST_SPHERE);
                        DoCast(SPELL_PERMAFROST_MODEL);
                        DoCast(SPELL_PERMAFROST_VISUAL);
                        DoCast(SPELL_PERMAFROST);
                        me->SetObjectScale(2.0f);
                        break;
                    default:
                        break;
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new npc_frost_sphereAI(creature);
        };
};

class npc_anubarak_spike : public CreatureScript
{
    public:
        npc_anubarak_spike() : CreatureScript("npc_anubarak_spike") { }

        struct npc_anubarak_spikeAI : public ScriptedAI
        {
            npc_anubarak_spikeAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void Reset() OVERRIDE
            {
                _phase = PHASE_NO_MOVEMENT;
                _phaseSwitchTimer = 1;
                // make sure the spike has everyone on threat list
                me->SetInCombatWithZone();
            }

            bool CanAIAttack(Unit const* victim) const OVERRIDE
            {
                return victim->GetTypeId() == TYPEID_PLAYER;
            }

            void EnterCombat(Unit* who) OVERRIDE
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                {
                    StartChase(target);
                    Talk(EMOTE_SPIKE, who);
                }
            }

            void DamageTaken(Unit* /*who*/, uint32& uiDamage) OVERRIDE
            {
                uiDamage = 0;
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (!UpdateVictim())
                {
                    me->DisappearAndDie();
                    return;
                }

                if (_phaseSwitchTimer)
                {
                    if (_phaseSwitchTimer <= diff)
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
                                    Talk(EMOTE_SPIKE, target2);
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
                        _phaseSwitchTimer -= diff;
                }
            }

            void MoveInLineOfSight(Unit* pWho) OVERRIDE

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

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new npc_anubarak_spikeAI(creature);
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

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_impale_SpellScript::HandleDamageCalc, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_impale_SpellScript();
        }
};

class spell_anubarak_leeching_swarm : public SpellScriptLoader
{
    public:
        spell_anubarak_leeching_swarm() : SpellScriptLoader("spell_anubarak_leeching_swarm") { }

        class spell_anubarak_leeching_swarm_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_anubarak_leeching_swarm_AuraScript);

            bool Validate(SpellInfo const* /*spell*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_LEECHING_SWARM_DMG) || !sSpellMgr->GetSpellInfo(SPELL_LEECHING_SWARM_HEAL))
                    return false;
                return true;
            }

            void HandleEffectPeriodic(AuraEffect const* aurEff)
            {
                Unit* caster = GetCaster();
                if (Unit* target = GetTarget())
                {
                    int32 lifeLeeched = target->CountPctFromCurHealth(aurEff->GetAmount());
                    if (lifeLeeched < 250)
                        lifeLeeched = 250;
                    // Damage
                    caster->CastCustomSpell(target, SPELL_LEECHING_SWARM_DMG, &lifeLeeched, 0, 0, false);
                    // Heal
                    caster->CastCustomSpell(caster, SPELL_LEECHING_SWARM_HEAL, &lifeLeeched, 0, 0, false);
                }
            }

            void Register() OVERRIDE
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_anubarak_leeching_swarm_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_anubarak_leeching_swarm_AuraScript();
        }
};

void AddSC_boss_anubarak_trial()
{
    new boss_anubarak_trial();
    new npc_swarm_scarab();
    new npc_nerubian_burrower();
    new npc_anubarak_spike();
    new npc_frost_sphere();

    new spell_impale();
    new spell_anubarak_leeching_swarm();
}
