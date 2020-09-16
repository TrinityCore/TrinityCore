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

#include "shadowfang_keep.h"
#include "GameEventMgr.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "Player.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"

enum Texts
{
    SAY_AGGRO_ALLIANCE              = 0,
    SAY_AGGRO_HORDE                 = 1,
    SAY_SLAY                        = 2,
    SAY_ANNOUNCE_PISTOL_BARRAGE     = 3,
    SAY_DEATH                       = 4
};

enum Events
{
    // Lord Godfrey
    EVENT_CURSED_BULLETS = 1,
    EVENT_MORTAL_WOUND,
    EVENT_SUMMON_BLOODTHIRSTY_GHOULS,
    EVENT_PISTOL_BARRAGE,
    EVENT_PISTOL_BARRAGE_CAST,

    // Bloodthirsty Ghoul
    EVENT_ATTACK
};

enum Spells
{
    SPELL_CURSED_BULLETS                            = 93629,
    SPELL_CURSED_BULLETS_HC                         = 93761,
    SPELL_MORTAL_WOUND                              = 93675,
    SPELL_SUMMON_BLOODTHIRSTY_GHOULS                = 93707,
    SPELL_SUMMON_BLOODTHIRSTY_GHOULS_TRIGGERED_1    = 93709,
    SPELL_SUMMON_BLOODTHIRSTY_GHOULS_TRIGGERED_2    = 93714,
    SPELL_WEAR_CHRISTMAS_HAT_GREEN_SELF_DND         = 61401,

    SPELL_PISTOL_BARRAGE_AOE                        = 96344,
    SPELL_PISTOL_BARRAGE                            = 93520,
    SPELL_BULLET_TIME_CREDIT                        = 95929,
    SPELL_BULLET_TIME_RESET_CREDIT                  = 95930,

    SPELL_PISTOL_BARRAGE_PERIODIC                   = 93566,
    SPELL_PISTOL_BARRAGE_MISSILE_1                  = 93557,
    SPELL_PISTOL_BARRAGE_MISSILE_2                  = 93558
};

enum Misc
{
    GAME_EVENT_WINTER_VEIL = 2
};

struct boss_lord_godfrey : public BossAI
{
    boss_lord_godfrey(Creature* creature) : BossAI(creature, DATA_LORD_GODFREY) { }

    void JustAppeared() override
    {
        if (sGameEventMgr->IsActiveEvent(GAME_EVENT_WINTER_VEIL))
            DoCastSelf(SPELL_WEAR_CHRISTMAS_HAT_GREEN_SELF_DND);
    }

    void Reset() override
    {
        _Reset();
        me->MakeInterruptable(false);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE ? SAY_AGGRO_ALLIANCE : SAY_AGGRO_HORDE);
        DoCastAOE(SPELL_BULLET_TIME_RESET_CREDIT);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        events.ScheduleEvent(EVENT_MORTAL_WOUND, 3s, 4s);
        events.ScheduleEvent(EVENT_SUMMON_BLOODTHIRSTY_GHOULS, 6s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _JustDied();
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);

        switch (summon->GetEntry())
        {
            case NPC_PISTOL_BARRAGE_DUMMY:
                _pistolBarrageDummyGUID = summon->GetGUID();
                events.ScheduleEvent(EVENT_PISTOL_BARRAGE_CAST, 500ms);
                break;
            case NPC_BLOODTHIRSTY_GHOUL:
                summon->SetReactState(REACT_PASSIVE);
                summon->m_Events.AddEventAtOffset([summon]()
                {
                    if (summon->IsAIEnabled)
                        summon->AI()->DoZoneInCombat();
                }, 1s + 300ms);

                summon->m_Events.AddEventAtOffset([summon]()
                {
                    summon->SetReactState(REACT_AGGRESSIVE);
                }, 5s);
                break;
            default:
                break;
        }
    }


    void SummonedCreatureDies(Creature* summon, Unit* killer) override
    {
        switch (summon->GetEntry())
        {
            case NPC_BLOODTHIRSTY_GHOUL:
                if (killer->GetEntry() == BOSS_LORD_GODFREY && IsHeroic())
                {
                    DoCastAOE(SPELL_BULLET_TIME_CREDIT, true);
                    _killedGhoulCounter++;
                }
                break;
            default:
                break;
        }
    }

    void KilledUnit(Unit* target) override
    {
        if (target->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        summons.DespawnAll();
        me->SetReactState(REACT_AGGRESSIVE);
        instance->SetBossState(DATA_LORD_GODFREY, FAIL);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _DespawnAtEvade();
    }

    void OnSpellCastFinished(SpellInfo const* spell, SpellFinishReason /*reason*/) override
    {
        switch (spell->Id)
        {
            case SPELL_CURSED_BULLETS:
            case SPELL_CURSED_BULLETS_HC:
                me->MakeInterruptable(false);
                break;
            default:
                break;
        }
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
                case EVENT_CURSED_BULLETS:
                    me->MakeInterruptable(true);
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
                        DoCast(target, SPELL_CURSED_BULLETS);
                    events.Repeat(12s);
                    break;
                case EVENT_MORTAL_WOUND:
                    DoCastVictim(SPELL_MORTAL_WOUND);
                    events.Repeat(5s);
                    break;
                case EVENT_SUMMON_BLOODTHIRSTY_GHOULS:
                    me->StopMoving();
                    DoCastSelf(SPELL_SUMMON_BLOODTHIRSTY_GHOULS);
                    events.Repeat(30s);

                    // Bloodthirsty summon casts re-allign the other basic abilities
                    events.RescheduleEvent(EVENT_CURSED_BULLETS, 7s);
                    events.RescheduleEvent(EVENT_MORTAL_WOUND, 5s);

                    if (IsHeroic())
                        events.ScheduleEvent(EVENT_PISTOL_BARRAGE, 5s);
                    break;
                case EVENT_PISTOL_BARRAGE:
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    DoCastAOE(SPELL_PISTOL_BARRAGE_AOE);
                    events.RescheduleEvent(EVENT_MORTAL_WOUND, 8s + 500ms);

                    break;
                case EVENT_PISTOL_BARRAGE_CAST:
                    if (Creature* target = ObjectAccessor::GetCreature(*me, _pistolBarrageDummyGUID))
                    {
                        Talk(SAY_ANNOUNCE_PISTOL_BARRAGE);
                        me->SetFacingToObject(target);
                        DoCastSelf(SPELL_PISTOL_BARRAGE);
                    }
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    ObjectGuid _pistolBarrageDummyGUID;
    uint8 _killedGhoulCounter;
};

class spell_godfrey_summon_bloodthirsty_ghouls : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_SUMMON_BLOODTHIRSTY_GHOULS_TRIGGERED_1,
                SPELL_SUMMON_BLOODTHIRSTY_GHOULS_TRIGGERED_2
            });
    }

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        uint32 spellId = _useLeftGun ? SPELL_SUMMON_BLOODTHIRSTY_GHOULS_TRIGGERED_1 : SPELL_SUMMON_BLOODTHIRSTY_GHOULS_TRIGGERED_2;
        _useLeftGun = _useLeftGun ? false : true;
        GetTarget()->CastSpell(GetTarget(), spellId, true);
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_godfrey_summon_bloodthirsty_ghouls::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
private:
    bool _useLeftGun = true;
};

class spell_godfrey_pistol_barrage : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PISTOL_BARRAGE_PERIODIC,
                SPELL_PISTOL_BARRAGE_MISSILE_1,
                SPELL_PISTOL_BARRAGE_MISSILE_2
            });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_PISTOL_BARRAGE_PERIODIC, true);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->RemoveAurasDueToSpell(SPELL_PISTOL_BARRAGE_PERIODIC);

        if (target->ToCreature())
            target->ToCreature()->SetReactState(REACT_AGGRESSIVE);
    }

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();
        float maxOffset = float(M_PI / 6);
        float offset = _useLeftGun ? frand(0.f, maxOffset) : frand(--maxOffset, 0.f);
        uint32 spellId = _useLeftGun ? SPELL_PISTOL_BARRAGE_MISSILE_1 : SPELL_PISTOL_BARRAGE_MISSILE_2;

        float ori = target->GetOrientation() + offset;
        float posX = target->GetPositionX() + cos(ori) * 60;
        float posY = target->GetPositionY() + sin(ori) * 60;
        float posZ = target->GetPositionZ();
        target->CastSpell({ posX, posY, posZ }, spellId, true);
        _useLeftGun = _useLeftGun ? false : true;
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_godfrey_pistol_barrage::AfterApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove.Register(&spell_godfrey_pistol_barrage::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        OnEffectPeriodic.Register(&spell_godfrey_pistol_barrage::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
private:
    bool _useLeftGun = true;
};

class spell_godfrey_pistol_barrage_aoe : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Trinity::Containers::RandomResize(targets, 1);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_godfrey_pistol_barrage_aoe::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class spell_godfrey_cursed_bullets : public AuraScript
{
    void OnPeriodic(AuraEffect const* aurEff)
    {
        if (aurEff->GetTickNumber() == 1)
            _baseDamage = aurEff->GetAmount();

        GetEffect(EFFECT_1)->ChangeAmount(_baseDamage * aurEff->GetTickNumber());
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_godfrey_cursed_bullets::OnPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE);
    }
private:
    uint32 _baseDamage = 0;
};

void AddSC_boss_lord_godfrey()
{
    RegisterShadowfangKeepCreatureAI(boss_lord_godfrey);
    RegisterSpellScript(spell_godfrey_summon_bloodthirsty_ghouls);
    RegisterSpellScript(spell_godfrey_pistol_barrage);
    RegisterSpellScript(spell_godfrey_pistol_barrage_aoe);
    RegisterSpellScript(spell_godfrey_cursed_bullets);
}
