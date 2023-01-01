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
#include "InstanceScript.h"
#include "naxxramas.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"

enum Yells
{
    SAY_GREET           = 0,
    SAY_AGGRO           = 1,
    SAY_SLAY            = 2,
    SAY_DEATH           = 3,

    EMOTE_WIDOW_EMBRACE = 4,
    EMOTE_FRENZY        = 5

};

enum Spells
{
    SPELL_POISON_BOLT_VOLLEY    = 28796,
    SPELL_RAIN_OF_FIRE          = 28794,
    SPELL_FRENZY                = 28798,
    SPELL_WIDOWS_EMBRACE        = 28732,

    SPELL_ADD_FIREBALL          = 54095     // 25-man: 54096
};

#define SPELL_WIDOWS_EMBRACE_HELPER RAID_MODE<uint32>(28732, 54097)

enum Events
{
    EVENT_POISON    = 1,
    EVENT_FIRE      = 2,
    EVENT_FRENZY    = 3
};

enum SummonGroups
{
    SUMMON_GROUP_WORSHIPPERS    = 1,
    SUMMON_GROUP_FOLLOWERS      = 2
};

enum Misc
{
    DATA_FRENZY_DISPELS         = 1
};

struct boss_faerlina : public BossAI
{
    boss_faerlina(Creature* creature) : BossAI(creature, BOSS_FAERLINA), _frenzyDispels(0) { }

    void SummonAdds()
    {
        me->SummonCreatureGroup(SUMMON_GROUP_WORSHIPPERS);
        if (Is25ManRaid())
            me->SummonCreatureGroup(SUMMON_GROUP_FOLLOWERS);
    }

    void InitializeAI() override
    {
        if (!me->isDead() && instance->GetBossState(BOSS_FAERLINA) != DONE)
        {
            Reset();
            SummonAdds();
        }
    }

    void JustReachedHome() override
    {
        _JustReachedHome();
        SummonAdds();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        summons.DoZoneInCombat();
        events.ScheduleEvent(EVENT_POISON, randtime(Seconds(10), Seconds(15)));
        events.ScheduleEvent(EVENT_FIRE, randtime(Seconds(6), Seconds(18)));
        events.ScheduleEvent(EVENT_FRENZY, Minutes(1)+randtime(0s, Seconds(20)));
    }

    void Reset() override
    {
        _Reset();
        _frenzyDispels = 0;
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

    void SpellHit(WorldObject* caster, SpellInfo const* spellInfo) override
    {
        Unit* unitCaster = caster->ToUnit();
        if (!unitCaster)
            return;

        if (spellInfo->Id == SPELL_WIDOWS_EMBRACE_HELPER)
        {
            ++_frenzyDispels;
            Talk(EMOTE_WIDOW_EMBRACE, caster);
            Unit::Kill(me, unitCaster);
        }
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == DATA_FRENZY_DISPELS)
            return _frenzyDispels;

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
                case EVENT_POISON:
                    if (!me->HasAura(SPELL_WIDOWS_EMBRACE_HELPER))
                        DoCastAOE(SPELL_POISON_BOLT_VOLLEY);
                    events.Repeat(randtime(Seconds(8), Seconds(15)));
                    break;
                case EVENT_FIRE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_RAIN_OF_FIRE);
                    events.Repeat(randtime(Seconds(6), Seconds(18)));
                    break;
                case EVENT_FRENZY:
                    if (Aura* widowsEmbrace = me->GetAura(SPELL_WIDOWS_EMBRACE_HELPER))
                        events.ScheduleEvent(EVENT_FRENZY, Milliseconds(widowsEmbrace->GetDuration()+1));
                    else
                    {
                        DoCast(SPELL_FRENZY);
                        Talk(EMOTE_FRENZY);
                        events.Repeat(Minutes(1) + randtime(0s, Seconds(20)));
                    }
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    uint32 _frenzyDispels;
};

struct npc_faerlina_add : public ScriptedAI
{
    npc_faerlina_add(Creature* creature) : ScriptedAI(creature),
        _instance(creature->GetInstanceScript())
    {
    }

    void Reset() override
    {
        if (!Is25ManRaid()) {
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_BIND, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
        }
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        if (Creature* faerlina = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_FAERLINA)))
            faerlina->AI()->DoZoneInCombat();
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (!Is25ManRaid())
            if (Creature* faerlina = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_FAERLINA)))
                DoCast(faerlina, SPELL_WIDOWS_EMBRACE);
    }

    void UpdateAI(uint32 /*diff*/) override
    {
        if (!UpdateVictim())
            return;
        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        DoCastVictim(SPELL_ADD_FIREBALL);
        DoMeleeAttackIfReady(); // this will only happen if the fireball cast fails for some reason
    }

private:
    InstanceScript* const _instance;
};

class achievement_momma_said_knock_you_out : public AchievementCriteriaScript
{
    public:
        achievement_momma_said_knock_you_out() : AchievementCriteriaScript("achievement_momma_said_knock_you_out") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            return target && !target->GetAI()->GetData(DATA_FRENZY_DISPELS);
        }
};

class at_faerlina_entrance : public OnlyOnceAreaTriggerScript
{
    public:
        at_faerlina_entrance() : OnlyOnceAreaTriggerScript("at_faerlina_entrance") { }

        bool TryHandleOnce(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
        {
            InstanceScript* instance = player->GetInstanceScript();
            if (!instance || instance->GetBossState(BOSS_FAERLINA) != NOT_STARTED)
                return true;

            if (Creature* faerlina = ObjectAccessor::GetCreature(*player, instance->GetGuidData(DATA_FAERLINA)))
                faerlina->AI()->Talk(SAY_GREET);

            return true;
        }
};

void AddSC_boss_faerlina()
{
    RegisterNaxxramasCreatureAI(boss_faerlina);
    RegisterNaxxramasCreatureAI(npc_faerlina_add);
    new at_faerlina_entrance();
    new achievement_momma_said_knock_you_out();
}
