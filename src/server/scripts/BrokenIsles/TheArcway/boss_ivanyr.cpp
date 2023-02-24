/*
 * Copyright 2023 AzgathCore
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
#include "ScriptedCreature.h"
#include "the_arcway.h"

enum Says
{
    SAY_AGGRO = 1,
    SAY_MAGIC = 2,
    SAY_DEATH = 3,
};

enum Spells
{
    SPELL_SPAWN_VISUAL = 202679, //Hit npc 98734
    SPELL_ARCANE_BLAST = 196357,
    SPELL_VOLATILE_MAGIC = 196562,
    SPELL_OVERCHARGE_MANA = 196392,
    SPELL_OVERCHARGE = 196396,
    SPELL_NETHER_LINK = 196804,
    SPELL_WITHERING_CONSUMPTION = 196549,
    SPELL_CONSUME_ESSENCE = 196877,
    SPELL_CHARGED_BOLT = 220581,
    SPELL_CHARGED_BOLT_AT = 220569,
};

enum eEvents
{
    EVENT_VOLATILE_MAGIC = 1,
    EVENT_OVERCHARGE_MANA = 2,
    EVENT_NETHER_LINK = 3,
    EVENT_WITHERING_CONSUMPTION = 4,
    EVENT_CONSUME_ESSENCE = 5,

    DATA_OVERCHARGE,
};

enum Achieve
{
    ACHIEVEMENTDATA,
};

//98203
class boss_ivanyr : public CreatureScript
{
public:
    boss_ivanyr() : CreatureScript("boss_ivanyr") {}

    struct boss_ivanyrAI : public BossAI
    {
        boss_ivanyrAI(Creature* creature) : BossAI(creature, DATA_IVANYR)
        {
            DoCast(me, SPELL_SPAWN_VISUAL, true);
            introDone = false;
            notspellhited = true;
        }

        bool phaseLowMana;
        bool introDone;
        bool notspellhited;
        uint8 overChargeCount;
        uint32 CheckTimer;

        void Reset() override
        {
            _Reset();
            phaseLowMana = false;
            notspellhited = true;
            overChargeCount = 0;
            me->SetReactState(REACT_AGGRESSIVE);
            me->RemoveAurasDueToSpell(SPELL_WITHERING_CONSUMPTION);
            me->RemoveAurasDueToSpell(SPELL_OVERCHARGE);
            me->SummonCreature(NPC_NIGHT_CRYSTAL, 3137.53f, 5135.01f, 623.28f, 5.2f);
        }

        void Initialize()
        {
            CheckTimer = 1000;
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO); //Stay back! It's mine!
            _JustEngagedWith();

            events.RescheduleEvent(EVENT_VOLATILE_MAGIC, 8000);
            events.RescheduleEvent(EVENT_OVERCHARGE_MANA, 28000);
            events.RescheduleEvent(EVENT_NETHER_LINK, 56000);
            events.RescheduleEvent(EVENT_WITHERING_CONSUMPTION, 2000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            _JustDied();
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (!introDone && me->IsWithinDistInMap(who, 130.0f))
            {
                introDone = true;
                Talk(0);
            }
        }

        void JustReachedHome() override
        {
            if (!me->IsInCombat())
                DoCast(me, SPELL_SPAWN_VISUAL, true);
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (id == 1)
            {
                overChargeCount++;
                DoCast(me, SPELL_OVERCHARGE_MANA, true);
                me->SetReactState(REACT_AGGRESSIVE);
            }
        }

        uint32 GetData(uint32 type) const override
        {
            if (type == ACHIEVEMENTDATA)
                return notspellhited ? 1 : 0;

            switch (type)
            {
            case DATA_OVERCHARGE:
                return overChargeCount;
            }
            return 0;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (me->GetDistance(me->GetHomePosition()) >= 60.0f)
            {
                EnterEvadeMode();
                return;
            }

            if (CheckTimer <= diff)
            {
                if (me->IsInCombat() && (me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC || me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_KEYSTONE))
                {
                    Map::PlayerList const& players = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        if (Player* player = itr->GetSource())
                            if (player->HasAura(220597))
                                notspellhited = false;
                }
                CheckTimer = 1000;
            }
            else CheckTimer -= diff;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_VOLATILE_MAGIC:
                    DoCast(SPELL_VOLATILE_MAGIC);
                    Talk(SAY_MAGIC);
                    events.RescheduleEvent(EVENT_VOLATILE_MAGIC, 24000);
                    break;
                case EVENT_OVERCHARGE_MANA:
                    me->AttackStop();
                    me->GetMotionMaster()->MovePoint(1, me->GetHomePosition());
                    events.RescheduleEvent(EVENT_OVERCHARGE_MANA, 40000);
                    break;
                case EVENT_NETHER_LINK:
                    DoCast(SPELL_NETHER_LINK);
                    events.RescheduleEvent(EVENT_NETHER_LINK, 56000);
                    break;
                case EVENT_WITHERING_CONSUMPTION:
                    if (me->GetPower(POWER_MANA) > 0)
                        events.RescheduleEvent(EVENT_NETHER_LINK, 2000);
                    else
                    {
                        events.Reset();
                        DoCast(SPELL_WITHERING_CONSUMPTION);
                        events.RescheduleEvent(EVENT_CONSUME_ESSENCE, 8000);
                    }
                    break;
                case EVENT_CONSUME_ESSENCE:
                    DoCast(SPELL_CONSUME_ESSENCE);
                    events.RescheduleEvent(EVENT_CONSUME_ESSENCE, 16000);
                    break;
                }
            }
            if (me->HasAura(SPELL_WITHERING_CONSUMPTION))
                DoMeleeAttackIfReady();
            else
                DoSpellAttackIfReady(SPELL_ARCANE_BLAST);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_ivanyrAI(creature);
    }
};

//196392
class spell_ivanyr_overcharge_mana : public SpellScriptLoader
{
public:
    spell_ivanyr_overcharge_mana() : SpellScriptLoader("spell_ivanyr_overcharge_mana") { }

    class spell_ivanyr_overcharge_mana_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_ivanyr_overcharge_mana_AuraScript);

        uint16 tickTimer = 1000;

        void OnTick(AuraEffect const* aurEff)
        {
            if (!GetCaster() || !GetTarget())
                return;

            if (tickTimer <= 0)
            {
                GetCaster()->CastSpell(GetCaster(), SPELL_OVERCHARGE, true);
                tickTimer = 1000;
            }
            else
                tickTimer -= 100;
        }

        void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            if (GetTarget() && !GetTarget()->HasAura(SPELL_CHARGED_BOLT))
                GetTarget()->CastSpell(GetTarget(), SPELL_CHARGED_BOLT, true);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_ivanyr_overcharge_mana_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            OnEffectApply += AuraEffectApplyFn(spell_ivanyr_overcharge_mana_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_ivanyr_overcharge_mana_AuraScript();
    }
};

//220581
class spell_ivanyr_charged_bolt : public SpellScriptLoader
{
public:
    spell_ivanyr_charged_bolt() : SpellScriptLoader("spell_ivanyr_charged_bolt") { }

    class spell_ivanyr_charged_bolt_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_ivanyr_charged_bolt_AuraScript);

        uint8 chargeCount = 0;

        void OnTick(AuraEffect const* aurEff)
        {
            if (Unit* target = GetTarget())
            {
                if (target->GetOwner())
                    if (Unit* owner = target->GetOwner())
                        chargeCount = owner->GetAI()->GetData(DATA_OVERCHARGE);

                for (uint8 i = 0; i < chargeCount; i++)
                    target->CastSpell(target, SPELL_CHARGED_BOLT_AT, true);
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_ivanyr_charged_bolt_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_ivanyr_charged_bolt_AuraScript();
    }
};

//31372
class achievement_arcanic_cling : public AchievementCriteriaScript
{
public:
    achievement_arcanic_cling() : AchievementCriteriaScript("achievement_arcanic_cling") {}

    bool OnCheck(Player* /*player*/, Unit* target) override
    {
        if (!target)
            return false;

        if (auto ivanyr = target->ToCreature())
            if (ivanyr->IsAIEnabled && ivanyr->AI()->GetData(ACHIEVEMENTDATA))
                return true;

        return false;
    }
};

void AddSC_boss_ivanyr()
{
    new boss_ivanyr();
    new spell_ivanyr_overcharge_mana();
    new spell_ivanyr_charged_bolt();
    new achievement_arcanic_cling();
}
