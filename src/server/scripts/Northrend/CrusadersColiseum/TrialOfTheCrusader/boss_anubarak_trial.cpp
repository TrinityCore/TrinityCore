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

// Known bugs:
// Anubarak - underground phase partially not worked
//          - tele after impale hit a permafrost doesn't work (the entire tele spell should be better)
// Scarab   - Kill credit isn't crediting?

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "trial_of_the_crusader.h"

enum Yells
{
    SAY_INTRO               = 0,
    SAY_AGGRO               = 1,
    EMOTE_SUBMERGE          = 2,
    EMOTE_BURROWER          = 3,
    EMOTE_EMERGE            = 4,
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
            boss_anubarak_trialAI(Creature* creature) : BossAI(creature, DATA_ANUBARAK)
            {
                Initialize();
            }

            void Initialize()
            {
                _intro = true;
                _reachedPhase3 = false;
            }

            void Reset() override
            {
                _Reset();
                events.SetPhase(PHASE_MELEE);
                events.ScheduleEvent(EVENT_FREEZE_SLASH, 15s, 0, PHASE_MELEE);
                events.ScheduleEvent(EVENT_PENETRATING_COLD, 20s, PHASE_MELEE);
                events.ScheduleEvent(EVENT_SUMMON_NERUBIAN, 10s, 0, PHASE_MELEE);
                events.ScheduleEvent(EVENT_SUBMERGE, 80s, 0, PHASE_MELEE);
                events.ScheduleEvent(EVENT_BERSERK, 10min);
                if (IsHeroic())
                    events.ScheduleEvent(EVENT_NERUBIAN_SHADOW_STRIKE, 30s, 0, PHASE_MELEE);

                if (!IsHeroic())
                    events.ScheduleEvent(EVENT_SUMMON_FROST_SPHERE, 20s);

                Initialize();
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                // clean up spawned Frost Spheres
                std::list<Creature*> FrostSphereList;
                me->GetCreatureListWithEntryInGrid(FrostSphereList, NPC_FROST_SPHERE, 150.0f);
                if (!FrostSphereList.empty())
                    for (std::list<Creature*>::iterator itr = FrostSphereList.begin(); itr != FrostSphereList.end(); ++itr)
                        (*itr)->DespawnOrUnsummon();

                _burrowGUID.clear();
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL_PLAYER);
            }

            void MoveInLineOfSight(Unit* /*who*/) override
            {
                if (!_intro)
                {
                    Talk(SAY_INTRO);
                    _intro = false;
                }
            }

            void JustReachedHome() override
            {
                instance->SetBossState(DATA_ANUBARAK, FAIL);
                //Summon Scarab Swarms neutral at random places
                for (int i = 0; i < 10; i++)
                    if (Creature* scarab = me->SummonCreature(NPC_SCARAB, AnubarakLoc[1].GetPositionX()+urand(0, 50)-25, AnubarakLoc[1].GetPositionY()+urand(0, 50)-25, AnubarakLoc[1].GetPositionZ()))
                    {
                        scarab->SetFaction(FACTION_PREY);
                        scarab->GetMotionMaster()->MoveRandom(10);
                    }
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                Talk(SAY_DEATH);

                // despawn frostspheres and Burrowers on death
                std::list<Creature*> AddList;
                me->GetCreatureListWithEntryInGrid(AddList, NPC_FROST_SPHERE, 150.0f);
                me->GetCreatureListWithEntryInGrid(AddList, NPC_BURROWER, 150.0f);
                if (!AddList.empty())
                    for (std::list<Creature*>::iterator itr = AddList.begin(); itr != AddList.end(); ++itr)
                        (*itr)->DespawnOrUnsummon();
            }

            void JustSummoned(Creature* summoned) override
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
                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true))
                        {
                            summoned->EngageWithTarget(target);
                            Talk(EMOTE_SPIKE, target);
                        }
                        break;
                    default:
                        break;
                }
                summons.Summon(summoned);
            }

            void JustEngagedWith(Unit* who) override
            {
                BossAI::JustEngagedWith(who);
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

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FREEZE_SLASH:
                            DoCastVictim(SPELL_FREEZE_SLASH);
                            events.ScheduleEvent(EVENT_FREEZE_SLASH, 15s, 0, PHASE_MELEE);
                            return;
                        case EVENT_PENETRATING_COLD:
                        {
                            CastSpellExtraArgs args;
                            args.AddSpellMod(SPELLVALUE_MAX_TARGETS, RAID_MODE(2, 5, 2, 5));
                            me->CastSpell(nullptr, SPELL_PENETRATING_COLD, args);
                            events.ScheduleEvent(EVENT_PENETRATING_COLD, 20s, 0, PHASE_MELEE);
                            return;
                        }
                        case EVENT_SUMMON_NERUBIAN:
                            if (IsHeroic() || !_reachedPhase3)
                            {
                                CastSpellExtraArgs args;
                                args.AddSpellMod(SPELLVALUE_MAX_TARGETS, RAID_MODE(1, 2, 2, 4));
                                me->CastSpell(nullptr, SPELL_SUMMON_BURROWER, args);
                            }
                            events.ScheduleEvent(EVENT_SUMMON_NERUBIAN, 45s, 0, PHASE_MELEE);
                            return;
                        case EVENT_NERUBIAN_SHADOW_STRIKE:
                        {
                            EntryCheckPredicate pred(NPC_BURROWER);
                            summons.DoAction(ACTION_SHADOW_STRIKE, pred);
                            events.ScheduleEvent(EVENT_NERUBIAN_SHADOW_STRIKE, 30s, 0, PHASE_MELEE);
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
                                events.ScheduleEvent(EVENT_PURSUING_SPIKE, 2s, 0, PHASE_SUBMERGED);
                                events.ScheduleEvent(EVENT_SUMMON_SCARAB, 4s, 0, PHASE_SUBMERGED);
                                events.ScheduleEvent(EVENT_EMERGE, 60s, 0, PHASE_SUBMERGED);
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
                            GuidList::iterator i = _burrowGUID.begin();
                            uint32 at = urand(0, _burrowGUID.size()-1);
                            for (uint32 k = 0; k < at; k++)
                                ++i;
                            if (Creature* pBurrow = ObjectAccessor::GetCreature(*me, *i))
                                pBurrow->CastSpell(pBurrow, 66340, false);

                            events.ScheduleEvent(EVENT_SUMMON_SCARAB, 4s, 0, PHASE_SUBMERGED);

                            /*It seems that this spell have something more that needs to be taken into account
                            //Need more sniff info
                            DoCast(SPELL_SUMMON_BEATLES);
                            // Just to make sure it won't happen again in this phase
                            m_uiSummonScarabTimer = 90*IN_MILLISECONDS;*/
                            break;
                        }
                        case EVENT_EMERGE:
                            DoCast(SPELL_SPIKE_TELE);
                            summons.DespawnEntry(NPC_SPIKE);
                            me->RemoveAurasDueToSpell(SPELL_SUBMERGE_ANUBARAK);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                            DoCast(me, SPELL_EMERGE_ANUBARAK);
                            Talk(EMOTE_EMERGE);
                            events.SetPhase(PHASE_MELEE);
                            events.ScheduleEvent(EVENT_FREEZE_SLASH, 15s, 0, PHASE_MELEE);
                            events.ScheduleEvent(EVENT_PENETRATING_COLD, 20s, PHASE_MELEE);
                            events.ScheduleEvent(EVENT_SUMMON_NERUBIAN, 10s, 0, PHASE_MELEE);
                            events.ScheduleEvent(EVENT_SUBMERGE, 80s, 0, PHASE_MELEE);
                            if (IsHeroic())
                                events.ScheduleEvent(EVENT_NERUBIAN_SHADOW_STRIKE, 30s, 0, PHASE_MELEE);
                            return;
                        case EVENT_SUMMON_FROST_SPHERE:
                        {
                            uint8 startAt = urand(0, 5);
                            uint8 i = startAt;
                            do
                            {
                                if (Unit* pSphere = ObjectAccessor::GetCreature(*me, _sphereGUID[i]))
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
                            events.ScheduleEvent(EVENT_SUMMON_FROST_SPHERE, 20s, 30s);
                            break;
                        }
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK);
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
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
                GuidList _burrowGUID;
                ObjectGuid _sphereGUID[6];
                bool _intro;
                bool _reachedPhase3;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetTrialOfTheCrusaderAI<boss_anubarak_trialAI>(creature);
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
                Initialize();
                _instance = creature->GetInstanceScript();
            }

            void Initialize()
            {
                _determinationTimer = urand(5 * IN_MILLISECONDS, 60 * IN_MILLISECONDS);
            }

            void Reset() override
            {
                me->SetCorpseDelay(0);
                Initialize();
                DoCast(me, SPELL_ACID_MANDIBLE);
                DoZoneInCombat();
                if (me->IsInCombat())
                    if (Creature* anubarak = _instance->GetCreature(DATA_ANUBARAK))
                        anubarak->AI()->JustSummoned(me);
            }

            void DoAction(int32 actionId) override
            {
                switch (actionId)
                {
                    case ACTION_SCARAB_SUBMERGE:
                        DoCast(SPELL_SUBMERGE_EFFECT);
                        me->DespawnOrUnsummon(1s);
                        break;
                    default:
                        break;
                }
            }

            void JustDied(Unit* killer) override
            {
                if (killer)
                    DoCast(killer, SPELL_TRAITOR_KING);
            }

            void UpdateAI(uint32 diff) override
            {
                if (_instance->GetBossState(DATA_ANUBARAK) != IN_PROGRESS)
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

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetTrialOfTheCrusaderAI<npc_swarm_scarabAI>(creature);
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
                Initialize();
                _instance = creature->GetInstanceScript();
            }

            void Initialize()
            {
                _submergeTimer = 30 * IN_MILLISECONDS;
            }

            void Reset() override
            {
                me->SetCorpseDelay(10);
                Initialize();
                DoCast(me, SPELL_EXPOSE_WEAKNESS);
                DoCast(me, SPELL_SPIDER_FRENZY);
                DoCast(me, SPELL_AWAKENED);
                DoZoneInCombat();
                if (me->IsInCombat())
                    if (Creature* anubarak = _instance->GetCreature(DATA_ANUBARAK))
                        anubarak->AI()->JustSummoned(me);
            }

            void DoAction(int32 actionId) override
            {
                switch (actionId)
                {
                    case ACTION_SHADOW_STRIKE:
                        if (!me->HasAura(SPELL_AWAKENED))
                            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                                DoCast(target, SPELL_SHADOW_STRIKE);
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (_instance->GetBossState(DATA_ANUBARAK) != IN_PROGRESS)
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

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetTrialOfTheCrusaderAI<npc_nerubian_burrowerAI>(creature);
        };
};

class npc_frost_sphere : public CreatureScript
{
    public:
        npc_frost_sphere() : CreatureScript("npc_frost_sphere") { }

        struct npc_frost_sphereAI : public ScriptedAI
        {
            npc_frost_sphereAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override
            {
                me->SetReactState(REACT_PASSIVE);
                DoCast(SPELL_FROST_SPHERE);
                me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
                me->GetMotionMaster()->MoveRandom(20.0f);
            }

            void DamageTaken(Unit* /*who*/, uint32& damage) override
            {
                if (me->GetHealth() <= damage)
                {
                    damage = 0;
                    float floorZ = me->GetPositionZ();
                    me->UpdateGroundPositionZ(me->GetPositionX(), me->GetPositionY(), floorZ);
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

            void MovementInform(uint32 type, uint32 pointId) override
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

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetTrialOfTheCrusaderAI<npc_frost_sphereAI>(creature);
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
                Initialize();
            }

            void Initialize()
            {
                _phase = PHASE_NO_MOVEMENT;
                _phaseSwitchTimer = 1;
            }

            void Reset() override
            {
                Initialize();
                // make sure the spike has everyone on threat list
                DoZoneInCombat();
            }

            bool CanAIAttack(Unit const* victim) const override
            {
                return victim->GetTypeId() == TYPEID_PLAYER;
            }

            void JustEngagedWith(Unit* who) override
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true))
                {
                    StartChase(target);
                    Talk(EMOTE_SPIKE, who);
                }
            }

            void DamageTaken(Unit* /*who*/, uint32& uiDamage) override
            {
                uiDamage = 0;
            }

            void UpdateAI(uint32 diff) override
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
                                if (Unit* target2 = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true))
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

            void MoveInLineOfSight(Unit* pWho) override
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

                    pWho->ToCreature()->DespawnOrUnsummon(3s);

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
                me->SetSpeedRate(MOVE_RUN, 0.5f);
                // make sure the Spine will really follow the one he should
                me->GetThreatManager().ResetAllThreat();
                DoZoneInCombat();
                AddThreat(who, 1000000.0f);
                AttackStart(who);
            }

            private:
                uint32 _phaseSwitchTimer;
                PursuingSpikesPhases _phase;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetTrialOfTheCrusaderAI<npc_anubarak_spikeAI>(creature);
        };
};

// 65920 - Pursuing Spikes
// 65922 - Pursuing Spikes
// 65923 - Pursuing Spikes
class spell_pursuing_spikes : public AuraScript
{
    PrepareAuraScript(spell_pursuing_spikes);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PERMAFROST, SPELL_SPIKE_FAIL });
    }

    bool Load() override
    {
        return InstanceHasScript(GetUnitOwner(), ToCrScriptName);
    }

    void PeriodicTick(AuraEffect const* /*aurEff*/)
    {
        Unit* permafrostCaster = nullptr;
        if (Aura* permafrostAura = GetTarget()->GetAura(sSpellMgr->GetSpellIdForDifficulty(SPELL_PERMAFROST, GetTarget())))
            permafrostCaster = permafrostAura->GetCaster();

        if (permafrostCaster)
        {
            PreventDefaultAction();

            if (Creature* permafrostCasterCreature = permafrostCaster->ToCreature())
                permafrostCasterCreature->DespawnOrUnsummon(3s);

            GetTarget()->CastSpell(nullptr, SPELL_SPIKE_FAIL);
            GetTarget()->RemoveAllAuras();
            if (Creature* targetCreature = GetTarget()->ToCreature())
                targetCreature->DisappearAndDie();
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_pursuing_spikes::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 65919 - Impale
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
                    PreventHitDamage();
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_impale_SpellScript::HandleDamageCalc, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_impale_SpellScript();
        }
};

// 66118, 67630, 68646, 68647 - Leeching Swarm
class spell_anubarak_leeching_swarm : public SpellScriptLoader
{
    public:
        spell_anubarak_leeching_swarm() : SpellScriptLoader("spell_anubarak_leeching_swarm") { }

        class spell_anubarak_leeching_swarm_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_anubarak_leeching_swarm_AuraScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_LEECHING_SWARM_DMG, SPELL_LEECHING_SWARM_HEAL });
            }

            void HandleEffectPeriodic(AuraEffect const* aurEff)
            {
                Unit* caster = GetCaster();
                if (Unit* target = GetTarget())
                {
                    int32 lifeLeeched = target->CountPctFromCurHealth(aurEff->GetAmount());
                    if (lifeLeeched < 250)
                        lifeLeeched = 250;
                    CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                    args.AddSpellMod(SPELLVALUE_BASE_POINT0, lifeLeeched);
                    // Damage
                    caster->CastSpell(target, SPELL_LEECHING_SWARM_DMG, args);
                    // Heal
                    caster->CastSpell(caster, SPELL_LEECHING_SWARM_HEAL, args);
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_anubarak_leeching_swarm_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
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

    RegisterSpellScript(spell_pursuing_spikes);
    new spell_impale();
    new spell_anubarak_leeching_swarm();
}
