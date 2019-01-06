/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "black_temple.h"
#include "GameObjectAI.h"
#include "GridNotifiers.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum Texts
{
    SAY_AGGRO   = 0,
    SAY_NEEDLE  = 1,
    SAY_SLAY    = 2,
    SAY_SPECIAL = 3,
    SAY_ENRAGE  = 4,
    SAY_DEATH   = 5
};

enum Spells
{
    SPELL_NEEDLE_SPINE_TARGETING = 39992,
    SPELL_NEEDLE_SPINE           = 39835,
    SPELL_TIDAL_BURST            = 39878,
    SPELL_TIDAL_SHIELD           = 39872,
    SPELL_IMPALING_SPINE         = 39837,
    SPELL_CREATE_NAJENTUS_SPINE  = 39956,
    SPELL_HURL_SPINE             = 39948,
    SPELL_BERSERK                = 26662
};

enum Events
{
    EVENT_BERSERK = 1,
    EVENT_YELL    = 2,
    EVENT_NEEDLE  = 3,
    EVENT_SPINE   = 4,
    EVENT_SHIELD  = 5
};

enum Misc
{
    DATA_REMOVE_IMPALING_SPINE   = 1,
    ACTION_RESET_IMPALING_TARGET = 2
};

struct boss_najentus : public BossAI
{
    boss_najentus(Creature* creature) : BossAI(creature, DATA_HIGH_WARLORD_NAJENTUS) { }

    void Reset() override
    {
        _Reset();
        _spineTargetGUID.Clear();
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
    }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_HURL_SPINE && me->HasAura(SPELL_TIDAL_SHIELD))
        {
            me->RemoveAurasDueToSpell(SPELL_TIDAL_SHIELD);
            DoCastSelf(SPELL_TIDAL_BURST, true);
            events.RescheduleEvent(EVENT_SPINE, Seconds(2));
        }
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _JustEngagedWith();
        Talk(SAY_AGGRO);
        events.ScheduleEvent(EVENT_NEEDLE, 2s);
        events.ScheduleEvent(EVENT_SHIELD, 1min);
        events.ScheduleEvent(EVENT_SPINE, 30s);
        events.ScheduleEvent(EVENT_BERSERK, 480s);
        events.ScheduleEvent(EVENT_YELL, 45s, 100s);
    }

    uint32 GetData(uint32 data) const override
    {
        if (data == DATA_REMOVE_IMPALING_SPINE)
            return RemoveImpalingSpine() ? 1 : 0;
        return 0;
    }

    void DoAction(int32 actionId) override
    {
        if (actionId == ACTION_RESET_IMPALING_TARGET)
            _spineTargetGUID.Clear();
    }

    bool RemoveImpalingSpine() const
    {
        if (!_spineTargetGUID)
            return false;

        Unit* target = ObjectAccessor::GetUnit(*me, _spineTargetGUID);
        if (target && target->HasAura(SPELL_IMPALING_SPINE))
            target->RemoveAurasDueToSpell(SPELL_IMPALING_SPINE);
        return true;
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_SHIELD:
                DoCastSelf(SPELL_TIDAL_SHIELD, true);
                events.RescheduleEvent(EVENT_SPINE, Seconds(50));
                events.Repeat(Seconds(55), Seconds(60));
                break;
            case EVENT_BERSERK:
                Talk(SAY_ENRAGE);
                DoCastSelf(SPELL_BERSERK, true);
                break;
            case EVENT_SPINE:
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 200.0f, true))
                {
                    DoCast(target, SPELL_IMPALING_SPINE, true);
                    _spineTargetGUID = target->GetGUID();
                    //must let target summon, otherwise you cannot click the spine
                    target->SummonGameObject(GO_NAJENTUS_SPINE, *target, QuaternionData(), 30);
                    Talk(SAY_NEEDLE);
                }
                events.Repeat(Seconds(20), Seconds(25));
                break;
            case EVENT_NEEDLE:
                DoCastSelf(SPELL_NEEDLE_SPINE_TARGETING, true);
                events.Repeat(Seconds(2));
                break;
            case EVENT_YELL:
                Talk(SAY_SPECIAL);
                events.Repeat(Seconds(25), Seconds(100));
                break;
            default:
                break;
        }
    }

private:
    ObjectGuid _spineTargetGUID;
};

struct go_najentus_spine : public GameObjectAI
{
    go_najentus_spine(GameObject* go) : GameObjectAI(go), _instance(go->GetInstanceScript()) { }

    bool GossipHello(Player* player) override
    {
        if (!_instance)
            return false;

        if (Creature* najentus = _instance->GetCreature(DATA_HIGH_WARLORD_NAJENTUS))
            if (najentus->AI()->GetData(DATA_REMOVE_IMPALING_SPINE))
            {
                najentus->AI()->DoAction(ACTION_RESET_IMPALING_TARGET);
                me->CastSpell(player, SPELL_CREATE_NAJENTUS_SPINE, true);
                me->Delete();
            }
        return true;
    }
private:
    InstanceScript* _instance;
};

// 39992 - Needle Spine Targeting
class spell_najentus_needle_spine : public SpellScript
{
    PrepareSpellScript(spell_najentus_needle_spine);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_NEEDLE_SPINE });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_IMPALING_SPINE));
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_NEEDLE_SPINE, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_najentus_needle_spine::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_najentus_needle_spine::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_boss_najentus()
{
    RegisterBlackTempleCreatureAI(boss_najentus);
    RegisterGameObjectAI(go_najentus_spine);
    RegisterSpellScript(spell_najentus_needle_spine);
}
