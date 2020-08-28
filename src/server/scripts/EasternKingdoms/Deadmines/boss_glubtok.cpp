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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "MoveSplineInit.h"
#include "Player.h"
#include "Vehicle.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "MotionMaster.h"
#include "deadmines.h"

enum Spells
{
    // Glubtok
    SPELL_BLINK                     = 87925,
    SPELL_FISTS_OF_FROST            = 87861,
    SPELL_FISTS_OF_FLAME            = 87859,
    SPELL_TELEPORT                  = 88002,
    SPELL_EMOTE_TALK                = 79506,
    SPELL_EMOTE_ROAR                = 48350,
    SPELL_ARCANE_POWER              = 88009,
    SPELL_ARCANE_FIRE_BEAM          = 88072,
    SPELL_ARCANE_FROST_BEAM         = 88093,
    SPELL_STUN_SELF                 = 88040,
    SPELL_BLOSSOM_TARGETING         = 88140,
    SPELL_FROST_BLOSSOM             = 88169,
    SPELL_FROST_BLOSSOM_VISUAL      = 88165,
    SPELL_FIRE_BLOSSOM              = 88129,
    SPELL_FIRE_BLOSSOM_VISUAL       = 88164,
    SPELL_ARCANE_OVERLOAD           = 88183,
    SPELL_TRANSITION_INVISIBILITY   = 90424,
    SPELL_ARCANE_OVERLOAD_INSTAKILL = 88185,

    // Fire Wall Platter
    SPELL_FIRE_WALL                 = 91398,

    // General Purpose Bunny JMF
    SPELL_ARCANE_OVERLOAD_EXPLOSION = 90520
};

enum Events
{
    EVENT_BLINK = 1,
    EVENT_ELEMENTAL_FISTS,
    EVENT_PHASE_TWO_INTRO_1,
    EVENT_PHASE_TWO_INTRO_2,
    EVENT_ARCANE_POWER,
    EVENT_STUN_SELF,
    EVENT_ANNOUNCE_FIRE_WALL,
    EVENT_FIRE_WALL,
    EVENT_BLOSSOM_TARGETING,
    EVENT_KILL_SELF
};

enum Phases
{
    PHASE_1 = 1,
    PHASE_2 = 2
};

enum Texts
{
    SAY_AGGRO               = 0,
    SAY_FISTS_OF_FLAME      = 1,
    SAY_FISTS_OF_FROST      = 2,
    SAY_PHASE_TWO_INTRO_1   = 3,
    SAY_PHASE_TWO_INTRO_2   = 4,
    SAY_ARCANE_POWER        = 5,
    SAY_ANNOUNCE_FIRE_WALL  = 6,
    SAY_DEATH               = 7
};

enum Fists
{
    FISTS_OF_FLAME = 0,
    FISTS_OF_FROST = 1
};

enum Data
{
    DATA_CURRENT_BLOSSOM = 1
};

Position const leftSideDistanceCheck = { -210.840f, -443.449f, 61.179f };
Position const FirewallPlatterSummonPos = { -193.4054f, -441.5011f, 54.57029f, 1.833041f };

static constexpr uint32 const FirewallPlatterCyclicPathSize = 9;
Position const FirewallPlatterCyclicPath[FirewallPlatterCyclicPathSize] =
{
    { -193.2778f, -442.0017f, 53.70924f },
    { -193.4514f, -441.0169f, 55.70924f },
    { -192.7042f, -441.1826f, 55.70924f },
    { -192.293f,  -441.8281f, 55.70924f },
    { -192.4586f, -442.5753f, 55.70924f },
    { -193.1041f, -442.9865f, 55.70924f },
    { -193.8514f, -442.8209f, 55.70924f },
    { -194.2626f, -442.1754f, 55.70924f },
    { -194.0969f, -441.4282f, 55.70924f }
};

struct boss_glubtok : public BossAI
{
    boss_glubtok(Creature* creature) : BossAI(creature, DATA_GLUBTOK),
        _defeated(false), _lastFists(FISTS_OF_FLAME), _nextBlossomBunny(NPC_FIRE_BLOSSOM_BUNNY) { }

    void Reset() override
    {
        _Reset();
        me->SetCanDualWield(true);
    }

    void JustAppeared() override
    {
        if (Creature* platter = DoSummon(NPC_GLUBTOK_FIREWALL_PLATTER, FirewallPlatterSummonPos, 0, TEMPSUMMON_MANUAL_DESPAWN))
        {
            platter->m_Events.AddEventAtOffset([platter]()
            {
                platter->GetMotionMaster()->MoveCyclicPath(FirewallPlatterCyclicPath, FirewallPlatterCyclicPathSize, false, true, 0.25f);
            }, 1s);
        }
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        events.SetPhase(PHASE_1);
        events.ScheduleEvent(EVENT_BLINK, 16s, 18s, 0, PHASE_1);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        summons.DespawnAll();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _DespawnAtEvade();
    }

    void JustSummoned(Creature* summon) override
    {
        switch (summon->GetEntry())
        {
            case NPC_FIREWALL_PLATTER_2A:
            case NPC_FIREWALL_PLATTER_2B:
            case NPC_FIREWALL_PLATTER_2C:
                _firewallDummyGUIDs.push_back(summon->GetGUID());
                break;
            default:
                break;
        }
        summons.Summon(summon);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthBelowPctDamaged(50, damage) && !events.IsInPhase(PHASE_2) && !_defeated)
        {
            events.SetPhase(PHASE_2);
            me->SetReactState(REACT_PASSIVE);
            me->AttackStop();
            me->InterruptNonMeleeSpells(true);
            DoCastSelf(SPELL_TELEPORT, true);
            me->StopMoving();
            me->NearTeleportTo(me->GetHomePosition());
            events.ScheduleEvent(EVENT_PHASE_TWO_INTRO_1, 3s + 800ms, 0, PHASE_2);
        }

        if (damage >= me->GetHealth())
        {
            damage = me->GetHealth() - 1;
            if (!_defeated)
            {
                _defeated = true;
                Talk(SAY_DEATH);
                events.Reset();
                DoCastSelf(SPELL_ARCANE_OVERLOAD);
                events.ScheduleEvent(EVENT_KILL_SELF, 4s + 800ms);

                // We really need this here because there are more of those triggers in the instance...
                std::list<Creature*> units;
                GetCreatureListWithEntryInGrid(units, me, NPC_GENERAL_PURPOSE_BUNNY_L2, 30.0f);
                if (!units.empty())
                {
                    for (auto itr = units.begin(); itr != units.end(); ++itr)
                    {
                        if ((*itr)->GetHomePosition().GetExactDist(leftSideDistanceCheck) <= 20.0f)
                            (*itr)->CastSpell((*itr), SPELL_ARCANE_FROST_BEAM);
                        else
                            (*itr)->CastSpell((*itr), SPELL_ARCANE_FIRE_BEAM);
                    }
                }
            }
        }
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == DATA_CURRENT_BLOSSOM)
            return _nextBlossomBunny;
        return 0;
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
                case EVENT_BLINK:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true, true))
                    {
                        DoCast(target, SPELL_BLINK);
                        if (IsHeroic())
                            me->GetThreatManager().ResetAllThreat();

                        events.ScheduleEvent(EVENT_ELEMENTAL_FISTS, 800ms, 0, PHASE_1);
                        events.Repeat(13s, 14s);
                    }
                    break;
                case EVENT_ELEMENTAL_FISTS:
                    Talk(_lastFists == FISTS_OF_FLAME ? SAY_FISTS_OF_FROST : SAY_FISTS_OF_FLAME);
                    DoCastSelf(_lastFists == FISTS_OF_FLAME ? SPELL_FISTS_OF_FROST : SPELL_FISTS_OF_FLAME);
                    _lastFists = _lastFists == FISTS_OF_FLAME ? FISTS_OF_FROST : FISTS_OF_FLAME;
                    break;
                case EVENT_PHASE_TWO_INTRO_1:
                    Talk(SAY_PHASE_TWO_INTRO_1);
                    DoCastSelf(SPELL_EMOTE_TALK, true);
                    events.ScheduleEvent(EVENT_PHASE_TWO_INTRO_2, 2s + 400ms, 0, PHASE_2);
                    break;
                case EVENT_PHASE_TWO_INTRO_2:
                    Talk(SAY_PHASE_TWO_INTRO_2);
                    DoCastSelf(SPELL_EMOTE_ROAR, true);
                    events.ScheduleEvent(EVENT_ARCANE_POWER, 2s + 400ms, 0, PHASE_2);
                    break;
                case EVENT_ARCANE_POWER:
                {
                    Talk(SAY_ARCANE_POWER);
                    DoCastSelf(SPELL_ARCANE_POWER);
                    me->SetDisableGravity(true);
                    me->SendSetPlayHoverAnim(true);

                    Movement::MoveSplineInit init(me);
                    init.MoveTo(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 2.0f, false);
                    init.SetWalk(true);
                    init.SetVelocity(0.8f);
                    init.Launch();

                    // We really need this here because there are more of those triggers in other rooms...
                    std::list<Creature*> units;
                    GetCreatureListWithEntryInGrid(units, me, NPC_GENERAL_PURPOSE_BUNNY_L2, 30.0f);
                    if (!units.empty())
                    {
                        for (auto itr = units.begin(); itr != units.end(); ++itr)
                        {
                            if ((*itr)->GetHomePosition().GetExactDist(leftSideDistanceCheck) <= 20.0f)
                                (*itr)->CastSpell((*itr), SPELL_ARCANE_FROST_BEAM);
                            else
                                (*itr)->CastSpell((*itr), SPELL_ARCANE_FIRE_BEAM);
                        }
                    }
                    events.ScheduleEvent(EVENT_STUN_SELF, 2s + 200ms, 0, PHASE_2);
                    events.ScheduleEvent(EVENT_BLOSSOM_TARGETING, 6s, 0, PHASE_2);
                    break;
                }
                case EVENT_STUN_SELF:
                    DoCastSelf(SPELL_STUN_SELF);
                    if (IsHeroic())
                        events.ScheduleEvent(EVENT_ANNOUNCE_FIRE_WALL, 1s + 500ms, 0, PHASE_2);
                    break;
                case EVENT_ANNOUNCE_FIRE_WALL:
                    Talk(SAY_ANNOUNCE_FIRE_WALL);
                    events.ScheduleEvent(EVENT_FIRE_WALL, 1s + 400ms, 0, PHASE_2);
                    break;
                case EVENT_FIRE_WALL:
                    for (ObjectGuid guid : _firewallDummyGUIDs)
                    {
                        if (Creature* firewallDummy = ObjectAccessor::GetCreature(*me, guid))
                            firewallDummy->CastSpell(firewallDummy, SPELL_FIRE_WALL);
                    }
                    break;
                case EVENT_BLOSSOM_TARGETING:
                    _nextBlossomBunny = _nextBlossomBunny == NPC_FIRE_BLOSSOM_BUNNY ? NPC_FROST_BLOSSOM_BUNNY : NPC_FIRE_BLOSSOM_BUNNY;
                    DoCastAOE(SPELL_BLOSSOM_TARGETING, true);
                    events.Repeat(2s + 400ms);
                    break;
                case EVENT_KILL_SELF:
                {
                    me->KillSelf();
                    Creature* creature = me;
                    me->m_Events.AddEventAtOffset([creature]()
                    {
                        creature->CastSpell(creature, SPELL_TRANSITION_INVISIBILITY);
                        creature->CastSpell(creature, SPELL_ARCANE_OVERLOAD_INSTAKILL);
                        if (Creature* bunny = creature->FindNearestCreature(NPC_GENERAL_PURPOSE_DUMMY_JMF, 5.0f, true))
                            bunny->CastSpell(bunny, SPELL_ARCANE_OVERLOAD_EXPLOSION);
                    }, 1s + 600ms);
                    break;
                }
                default:
                    break;
            }
        }
        DoMeleeAttackIfReady();
    }
private:
    bool _defeated;
    uint8 _lastFists;
    uint32 _nextBlossomBunny;
    GuidVector _firewallDummyGUIDs;
};

class spell_glubtok_blossom_targeting : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        if (Unit* caster = GetCaster())
        {
            if (Creature* creature = caster->ToCreature())
            {
                if (creature->IsAIEnabled)
                {
                    uint32 currentBlossomEntry = creature->AI()->GetData(DATA_CURRENT_BLOSSOM);
                    targets.remove_if([currentBlossomEntry](WorldObject const* obj)->bool
                    {
                        return obj->GetTypeId() != TYPEID_UNIT || obj->GetEntry() != currentBlossomEntry;
                    });
                }
            }
        }

        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleBlossomEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        if (Unit* caster = GetCaster())
        {
            caster->CastSpell(target, target->GetEntry() == NPC_FIRE_BLOSSOM_BUNNY ? SPELL_FIRE_BLOSSOM : SPELL_FROST_BLOSSOM, true);
            target->CastSpell(target, target->GetEntry() == NPC_FIRE_BLOSSOM_BUNNY ? SPELL_FIRE_BLOSSOM_VISUAL : SPELL_FROST_BLOSSOM_VISUAL, true);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_glubtok_blossom_targeting::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget.Register(&spell_glubtok_blossom_targeting::HandleBlossomEffect, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

void AddSC_boss_glubtok()
{
    RegisterDeadminesCreatureAI(boss_glubtok);
    RegisterSpellScript(spell_glubtok_blossom_targeting);
}
