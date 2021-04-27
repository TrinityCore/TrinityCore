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

#include "InstanceScript.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Object.h"
#include "Map.h"
#include "MotionMaster.h"
#include "PassiveAI.h"
#include "Player.h"
#include "SpellMgr.h"
#include "VMapFactory.h"
#include "VMapManager2.h"
#include "bastion_of_twilight.h"

#include <vector>

enum PhaseTwist
{
    // Events
    EVENT_REGISTER_TWISTERS = 1,
    EVENT_CHECK_TWISTERS,
    EVENT_PHASE_BURN,

    // Spells
    SPELL_PHASED_BURN = 85799
};

struct npc_bot_invisible_stalker_phase_twist final : public NullCreatureAI
{
    npc_bot_invisible_stalker_phase_twist(Creature* creature) : NullCreatureAI(creature) { }

    void JustAppeared() override
    {
        _events.ScheduleEvent(EVENT_REGISTER_TWISTERS, 1s);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_REGISTER_TWISTERS:
                    me->GetCreatureListWithEntryInGrid(_phaseTwisterVector, NPC_TWILIGHT_PHASE_SHIFTER, 10.f);
                    if (_phaseTwisterVector.empty()) // if the twister have not been added to the grid yet, keep searching
                        _events.Repeat(1s);
                    else
                    {
                        _events.ScheduleEvent(EVENT_CHECK_TWISTERS, 1s);
                        _events.ScheduleEvent(EVENT_PHASE_BURN, 1s);
                    }
                    break;
                case EVENT_CHECK_TWISTERS:
                {
                    uint8 deadTwisters = 0;
                    for (Unit const* twister : _phaseTwisterVector)
                    {
                        if (!twister || twister->isDead())
                            ++deadTwisters;
                    }

                    if (deadTwisters == _phaseTwisterVector.size())
                    {
                        _events.Reset();
                        me->InterruptNonMeleeSpells(true);
                        me->RemoveAllAuras();
                        me->DespawnOrUnsummon(4s);
                    }
                    else
                        _events.Repeat(1s);
                    break;
                }
                case EVENT_PHASE_BURN:
                    if (Unit* target = me->SelectNearestTarget(40.f, true))
                    {
                        DoCast(target, SPELL_PHASED_BURN);
                        _events.Repeat(8s);
                    }
                    else
                        _events.Repeat(1s);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    std::vector<Creature*> _phaseTwisterVector;
};

enum ChogallEvent
{
    // Texts
    SAY_HALFUS_INTRO = 0,
    SAY_HALFUS_DEAD  = 1
};

struct npc_bot_chogall final : public NullCreatureAI
{
    npc_bot_chogall(Creature* creature) : NullCreatureAI(creature) { }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_TALK_HALFUS_WYRMBREAKER_INTRO:
                Talk(SAY_HALFUS_INTRO);
                break;
            case ACTION_TALK_HALFUS_WYRMBREAKER_DEAD:
                Talk(SAY_HALFUS_DEAD);
                break;
            default:
                break;
        }
    }
};

enum EvolvedDrakonaar
{
    EVENT_CLEAVE = 1,
    EVENT_TWILIGHT_RUPTURE,
    EVENT_BLADE_TEMPEST,

    SPELL_CLEAVE            = 40504,
    SPELL_TWILIGHT_RUPTURE  = 93377,
    SPELL_BLADE_TEMPEST     = 93373,
};

struct npc_bot_evolved_drakonaar : public ScriptedAI
{
    npc_bot_evolved_drakonaar(Creature * creature) : ScriptedAI(creature) { }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_CLEAVE, 9s);
        _events.ScheduleEvent(EVENT_TWILIGHT_RUPTURE, 10s);
        _events.ScheduleEvent(EVENT_BLADE_TEMPEST, 18s);

        // The Drakonaar in the corner starts moving along the same path as the moving one when engaging the moving one
        if (me->GetWaypointPath())
            if (Creature* drakonaar = me->FindNearestCreature(me->GetEntry(), 200.f))
                if (drakonaar->GetMotionMaster()->GetCurrentSlot() == MOTION_SLOT_IDLE && drakonaar->GetMotionMaster()->GetCurrentMovementGeneratorType() != WAYPOINT_MOTION_TYPE)
                    drakonaar->GetMotionMaster()->MovePath(me->GetWaypointPath(), true);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        ScriptedAI::EnterEvadeMode(why);
        _events.Reset();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CLEAVE:
                    DoCastVictim(SPELL_CLEAVE);
                    _events.Repeat(20s, 21s);
                    break;
                case EVENT_TWILIGHT_RUPTURE:
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 45.f, true, false))
                        DoCast(target, SPELL_TWILIGHT_RUPTURE);
                    else
                        DoCastVictim(SPELL_TWILIGHT_RUPTURE);
                    _events.Repeat(24s, 25s);
                    break;
                }
                case EVENT_BLADE_TEMPEST:
                    DoCastSelf(SPELL_BLADE_TEMPEST);
                    _events.Repeat(22s, 23s);
                    break;
                default:
                    break;
            }
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
};

static constexpr uint32 const SPELL_WYVERN_STING_PERIODIC = 24336;

class spell_bot_wyvern_sting : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WYVERN_STING_PERIODIC });
    }

    void HandleAfterRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetTarget(), SPELL_WYVERN_STING_PERIODIC, CastSpellExtraArgs(true).AddSpellBP0(aurEff->GetAmount()));
    }

    void Register() override
    {
        AfterEffectRemove.Register(&spell_bot_wyvern_sting::HandleAfterRemove, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};

static constexpr uint32 const SPELL_TWILIGHT_RUPTURE_MISSILE = 93378;

class spell_bot_twilight_rupture : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TWILIGHT_RUPTURE_MISSILE });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        float angleVariance = 0.15f;
        float currentAngle = caster->GetOrientation();
        bool left = true;
        for (int32 i = 0; i < GetEffectValue(); ++i)
        {
            float forward = 1.f * i;
            if (i >= 3 && !((i - 3) % 5))
                left = !left;

            currentAngle = left ? (currentAngle + angleVariance) : (currentAngle - angleVariance);

            // Sniffs indicate that they use pathfinding for every single destination but we are not going to do so because of performance.
            float destX = caster->GetPositionX() + std::cos(currentAngle) * forward;
            float destY = caster->GetPositionY() + std::sin(currentAngle) * forward;
            float destZ = caster->GetPositionZ();

            bool col = VMAP::VMapFactory::createOrGetVMapManager()->getObjectHitPos(caster->GetMapId(),
                caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ() + 0.5f,
                destX, destY, destZ + 0.5f,
                destX, destY, destZ, -0.5f);

            destZ -= 0.5f;

            // Collided with static LOS object, move back to collision point
            if (col)
            {
                destX -= 2.f * std::cos(currentAngle);
                destY -= 2.f * std::sin(currentAngle);
            }

            caster->CastSpell({ destX, destY, destZ }, SPELL_TWILIGHT_RUPTURE_MISSILE);
        }
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_bot_twilight_rupture::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

enum AscendantCouncilElementals
{
    SPELL_RENDING_GALE      = 93277,
    SPELL_ENTOMB            = 93327,
    SPELL_BURNING_REPRISAL  = 93352,
    SPELL_COLD_TOUCHED      = 93381,
    SPELL_ICY_SHROUD        = 93335
};

class spell_bot_cancel_aura : public SpellScript
{
public:
    spell_bot_cancel_aura(uint32 spellId) : _spellId(spellId) { }

    void HandleAuraCancel(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->RemoveAurasDueToSpell(sSpellMgr->GetSpellIdForDifficulty(_spellId, GetHitUnit()));
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_bot_cancel_aura::HandleAuraCancel, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
private:
    uint32 _spellId;
};

class spell_bot_ward_of_combustion : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_BURNING_REPRISAL,
                SPELL_COLD_TOUCHED
            });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        return (eventInfo.GetDamageInfo() && eventInfo.GetActor() && !eventInfo.GetActor()->HasAura(SPELL_COLD_TOUCHED));
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(eventInfo.GetActor(), SPELL_BURNING_REPRISAL, CastSpellExtraArgs(aurEff).AddSpellBP0(eventInfo.GetDamageInfo()->GetDamage()));
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_bot_ward_of_combustion::CheckProc);
        OnEffectProc.Register(&spell_bot_ward_of_combustion::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

class spell_bot_flame_strike : public SpellScript
{
    void HandleAuraCancel(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->RemoveAurasDueToSpell(SPELL_ICY_SHROUD);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_bot_flame_strike::HandleAuraCancel, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

class at_bot_intro_events final : public OnlyOnceAreaTriggerScript
{
public:
    at_bot_intro_events(char const* scriptName, uint32 dataType) : OnlyOnceAreaTriggerScript(scriptName), _dataType(dataType) { }

    bool _OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
    {
        if (InstanceScript* instance = player->GetInstanceScript())
            instance->SetData(_dataType, IN_PROGRESS);
        return true;
    }
private:
    uint32 _dataType;
};

void AddSC_bastion_of_twilight()
{
    RegisterBastionOfTwilightCreatureAI(npc_bot_invisible_stalker_phase_twist);
    RegisterBastionOfTwilightCreatureAI(npc_bot_chogall);
    RegisterBastionOfTwilightCreatureAI(npc_bot_evolved_drakonaar);
    RegisterSpellScript(spell_bot_wyvern_sting);
    RegisterSpellScript(spell_bot_twilight_rupture);
    RegisterSpellScriptWithArgs(spell_bot_cancel_aura, "spell_bot_rending_gale", SPELL_ENTOMB);
    RegisterSpellScriptWithArgs(spell_bot_cancel_aura, "spell_bot_entomb", SPELL_RENDING_GALE);
    RegisterSpellScript(spell_bot_ward_of_combustion);
    RegisterSpellScript(spell_bot_flame_strike);
    new at_bot_intro_events("at_halfus_wyrmbreaker_intro", DATA_AT_HALFUS_WYRMBREAKER_INTRO);
    new at_bot_intro_events("at_theralion_and_valiona_intro", DATA_AT_THERALION_AND_VALIONA_INTRO);
    new at_bot_intro_events("at_ascendant_council_intro_1", DATA_AT_ASCENDANT_COUNCIL_INTRO_1);
    new at_bot_intro_events("at_ascendant_council_intro_2", DATA_AT_ASCENDANT_COUNCIL_INTRO_2);
    new at_bot_intro_events("at_ascendant_council_intro_3", DATA_AT_ASCENDANT_COUNCIL_INTRO_3);
    new at_bot_intro_events("at_chogall_intro", DATA_AT_CHOGALL_INTRO);
}
