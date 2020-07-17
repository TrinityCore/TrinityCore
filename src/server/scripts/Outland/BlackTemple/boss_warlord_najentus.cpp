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

#include "ScriptMgr.h"
#include "GameObjectAI.h"
#include "black_temple.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "GridNotifiers.h"

enum Texts
{
    SAY_AGGRO                       = 0,
    SAY_NEEDLE                      = 1,
    SAY_SLAY                        = 2,
    SAY_SPECIAL                     = 3,
    SAY_ENRAGE                      = 4,
    SAY_DEATH                       = 5
};

enum Spells
{
    SPELL_NEEDLE_SPINE_TARGETING    = 39992,
    SPELL_NEEDLE_SPINE              = 39835,
    SPELL_TIDAL_BURST               = 39878,
    SPELL_TIDAL_SHIELD              = 39872,
    SPELL_IMPALING_SPINE            = 39837,
    SPELL_CREATE_NAJENTUS_SPINE     = 39956,
    SPELL_HURL_SPINE                = 39948,
    SPELL_BERSERK                   = 26662

};

enum Events
{
    EVENT_BERSERK                   = 1,
    EVENT_YELL                      = 2,
    EVENT_NEEDLE                    = 3,
    EVENT_SPINE                     = 4,
    EVENT_SHIELD                    = 5
};

class boss_najentus : public CreatureScript
{
public:
    boss_najentus() : CreatureScript("boss_najentus") { }

    struct boss_najentusAI : public BossAI
    {
        boss_najentusAI(Creature* creature) : BossAI(creature, DATA_HIGH_WARLORD_NAJENTUS) { }

        void Reset() override
        {
            _Reset();
            SpineTargetGUID.Clear();
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
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

        void SpellHit(Unit* /*caster*/, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_HURL_SPINE && me->HasAura(SPELL_TIDAL_SHIELD))
            {
                me->RemoveAurasDueToSpell(SPELL_TIDAL_SHIELD);
                DoCastSelf(SPELL_TIDAL_BURST, true);
                events.RescheduleEvent(EVENT_SPINE, Seconds(2));
            }
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            Talk(SAY_AGGRO);
            events.ScheduleEvent(EVENT_NEEDLE, Seconds(2));
            events.ScheduleEvent(EVENT_SHIELD, Seconds(60));
            events.ScheduleEvent(EVENT_SPINE, Seconds(30));
            events.ScheduleEvent(EVENT_BERSERK, Seconds(480));
            events.ScheduleEvent(EVENT_YELL, Seconds(45), Seconds(100));
        }

        bool RemoveImpalingSpine()
        {
            if (!SpineTargetGUID)
                return false;

            Unit* target = ObjectAccessor::GetUnit(*me, SpineTargetGUID);
            if (target && target->HasAura(SPELL_IMPALING_SPINE))
                target->RemoveAurasDueToSpell(SPELL_IMPALING_SPINE);
            SpineTargetGUID.Clear();
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
                        SpineTargetGUID = target->GetGUID();
                        //must let target summon, otherwise you cannot click the spine
                        target->SummonGameObject(GO_NAJENTUS_SPINE, *target, QuaternionData::fromEulerAnglesZYX(target->GetOrientation(), 0.0f, 0.0f), 30);
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
        ObjectGuid SpineTargetGUID;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackTempleAI<boss_najentusAI>(creature);
    }
};

class go_najentus_spine : public GameObjectScript
{
public:
    go_najentus_spine() : GameObjectScript("go_najentus_spine") { }

    struct go_najentus_spineAI : public GameObjectAI
    {
        go_najentus_spineAI(GameObject* go) : GameObjectAI(go), instance(go->GetInstanceScript()) { }

        InstanceScript* instance;

        bool GossipHello(Player* player) override
        {
            if (Creature* najentus = instance->GetCreature(DATA_HIGH_WARLORD_NAJENTUS))
            {
                if (ENSURE_AI(boss_najentus::boss_najentusAI, najentus->AI())->RemoveImpalingSpine())
                {
                    me->CastSpell(player, SPELL_CREATE_NAJENTUS_SPINE, true);
                    me->Delete();
                }
            }
            return true;
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return GetBlackTempleAI<go_najentus_spineAI>(go);
    }
};

// 39992 - Needle Spine Targeting
class spell_najentus_needle_spine : public SpellScriptLoader
{
    public:
        spell_najentus_needle_spine() : SpellScriptLoader("spell_najentus_needle_spine") { }

        class spell_najentus_needle_spine_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_najentus_needle_spine_SpellScript);

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
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_najentus_needle_spine_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_najentus_needle_spine_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_najentus_needle_spine_SpellScript();
        }
};

void AddSC_boss_najentus()
{
    new boss_najentus();
    new go_najentus_spine();
    new spell_najentus_needle_spine();
}
