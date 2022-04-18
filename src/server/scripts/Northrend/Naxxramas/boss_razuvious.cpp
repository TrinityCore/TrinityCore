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
#include "MotionMaster.h"
#include "naxxramas.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"

enum Yells
{
    SAY_AGGRO = 0,
    SAY_SLAY = 1,
    SAY_TAUNTED = 2,
    SAY_DEATH = 3
};

enum Spells
{
    SPELL_UNBALANCING_STRIKE        = 26613,
    SPELL_DISRUPTING_SHOUT          = 29107,
    SPELL_JAGGED_KNIFE              = 55550,
    SPELL_HOPELESS                  = 29125,
    SPELL_UNDERSTUDY_TAUNT          = 29060,
    SPELL_UNDERSTUDY_BLOOD_STRIKE   = 61696,
    SPELL_FORCE_OBEDIENCE           = 55479
};

enum Events
{
    EVENT_ATTACK = 1,
    EVENT_STRIKE,
    EVENT_SHOUT,
    EVENT_KNIFE
};

enum SummonGroups
{
    SUMMON_GROUP_10MAN = 1,
    SUMMON_GROUP_25MAN = 2
};

struct boss_razuvious : public BossAI
{
    boss_razuvious(Creature* creature) : BossAI(creature, BOSS_RAZUVIOUS) { }

    void SummonAdds()
    {
        me->SummonCreatureGroup(SUMMON_GROUP_10MAN);
        if (Is25ManRaid())
            me->SummonCreatureGroup(SUMMON_GROUP_25MAN);
    }

    void InitializeAI() override
    {
        if (!me->isDead() && instance->GetBossState(BOSS_RAZUVIOUS) != DONE)
        {
            Reset();
            SummonAdds();
        }
    }

    void JustReachedHome() override
    {
        _JustReachedHome();
        SummonAdds();
        me->GetMotionMaster()->Initialize();
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER || (victim->GetTypeId() == TYPEID_UNIT && victim->GetEntry() == NPC_DK_UNDERSTUDY))
            Talk(SAY_SLAY);
    }

    void SpellHit(WorldObject* caster, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_UNDERSTUDY_TAUNT)
            Talk(SAY_TAUNTED, caster);
    }

    void JustDied(Unit* /*killer*/) override
    {
        for (ObjectGuid summonGuid : summons)
            if (Creature* summon = ObjectAccessor::GetCreature(*me, summonGuid))
                summon->RemoveCharmAuras();
        Talk(SAY_DEATH);
        DoCastAOE(SPELL_HOPELESS, true);

        events.Reset();
        instance->SetBossState(BOSS_RAZUVIOUS, DONE);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        me->StopMoving();
        summons.DoZoneInCombat();
        Talk(SAY_AGGRO);
        events.ScheduleEvent(EVENT_ATTACK, 7s);
        events.ScheduleEvent(EVENT_STRIKE, 21s);
        events.ScheduleEvent(EVENT_SHOUT, 16s);
        events.ScheduleEvent(EVENT_KNIFE, 10s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ATTACK:
                    SetCombatMovement(true);
                    if (Unit* victim = me->GetVictim())
                        me->GetMotionMaster()->MoveChase(victim);
                    break;
                case EVENT_STRIKE:
                    DoCastVictim(SPELL_UNBALANCING_STRIKE);
                    events.Repeat(Seconds(6));
                    return;
                case EVENT_SHOUT:
                    DoCastAOE(SPELL_DISRUPTING_SHOUT);
                    events.Repeat(Seconds(16));
                    return;
                case EVENT_KNIFE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 45.0f))
                        DoCast(target, SPELL_JAGGED_KNIFE);
                    events.Repeat(randtime(Seconds(10), Seconds(15)));
                    return;
            }
        }

        DoMeleeAttackIfReady();
    }

    void Reset() override
    {
        SetCombatMovement(false);
        _Reset();
    }
};

struct npc_dk_understudy : public ScriptedAI
{
    npc_dk_understudy(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()), bloodStrikeTimer(0)
    {
        creature->LoadEquipment(1);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        me->SetEmoteState(EMOTE_ONESHOT_NONE);
        if (Creature* razuvious = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_RAZUVIOUS)))
            razuvious->AI()->DoZoneInCombat();
    }

    void JustReachedHome() override
    {
        if (_instance->GetBossState(BOSS_RAZUVIOUS) == DONE)
            me->DespawnOrUnsummon();
        else
            ScriptedAI::JustReachedHome();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!me->isPossessedByPlayer() && !UpdateVictim())
            return;

        if (!me->isPossessedByPlayer())
        {
            if (diff < bloodStrikeTimer)
                bloodStrikeTimer -= diff;
            else
                DoCastVictim(SPELL_UNDERSTUDY_BLOOD_STRIKE);
        }

        DoMeleeAttackIfReady();
    }

    void OnCharmed(bool isNew) override
    {
        if (me->IsCharmed() && !me->IsEngaged())
            JustEngagedWith(nullptr);
        ScriptedAI::OnCharmed(isNew);
    }
private:
    InstanceScript* const _instance;
    ObjectGuid _charmer;
    uint32 bloodStrikeTimer;
};

void AddSC_boss_razuvious()
{
    RegisterNaxxramasCreatureAI(boss_razuvious);
    RegisterNaxxramasCreatureAI(npc_dk_understudy);
}
