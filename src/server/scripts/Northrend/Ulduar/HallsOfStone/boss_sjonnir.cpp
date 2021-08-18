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
#include "halls_of_stone.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_LIGHTING_RING                               = 51849, // Periodic Trigger (interval 2s) spell = 50841
    SPELL_LIGHTING_RING_1                             = 50840, // Periodic Trigger (interval 2s) spell = 50841
    SPELL_STATIC_CHARGE                               = 50834, // Periodic Trigger 2s interval, spell =50835
    SPELL_CHAIN_LIGHTING                              = 50830,
    SPELL_LIGHTING_SHIELD                             = 50831,
    SPELL_FRENZY                                      = 28747
};

enum Yells
{
    SAY_AGGRO                                         = 0,
    SAY_SLAY                                          = 1,
    SAY_DEATH                                         = 2
};

enum SjonnirCreatures
{
    NPC_FORGED_IRON_TROGG                             = 27979,
    NPC_MALFORMED_OOZE                                = 27981,
    NPC_FORGED_IRON_DWARF                             = 27982,
    NPC_IRON_SLUDGE                                   = 28165,
    NPC_EARTHEN_DWARF                                 = 27980
};

enum Misc
{
    ACTION_OOZE_DEAD                                  = 1,
    DATA_ABUSE_THE_OOZE                               = 2
};

enum Events
{
    EVENT_CHAIN_LIGHTNING                             = 1,
    EVENT_LIGHTNING_SHIELD,
    EVENT_STATIC_CHARGE,
    EVENT_LIGHTNING_RING,
    EVENT_SUMMON,
    EVENT_FRENZY,
};

Position const PipeLocations[] =
{
    { 1295.44f, 734.07f, 200.3f, 0.0f }, // left
    { 1297.7f,  595.6f,  199.9f, 0.0f }  // right
};

Position const CenterPoint = { 1295.21f, 667.157f, 189.691f, 0.0f };

struct boss_sjonnir : public BossAI
{
    boss_sjonnir(Creature* creature) : BossAI(creature, DATA_SJONNIR)
    {
        Initialize();
    }

    void Initialize()
    {
        abuseTheOoze = 0;
    }

    void Reset() override
    {
        _Reset();
        Initialize();
    }

    void JustEngagedWith(Unit* who) override
    {
        if (!instance->CheckRequiredBosses(DATA_SJONNIR, who->ToPlayer()))
        {
            EnterEvadeMode();
            return;
        }

        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 3s, 8s);
        events.ScheduleEvent(EVENT_LIGHTNING_SHIELD, 20s, 25s);
        events.ScheduleEvent(EVENT_STATIC_CHARGE, 20s, 25s);
        events.ScheduleEvent(EVENT_LIGHTNING_RING, 30s, 35s);
        events.ScheduleEvent(EVENT_SUMMON, 5s);
        events.ScheduleEvent(EVENT_FRENZY, 5min);
    }

    void JustSummoned(Creature* summon) override
    {
        summon->GetMotionMaster()->MovePoint(0, CenterPoint);
        /*if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100, true))
            summon->AI()->AttackStart(target);*/
        summons.Summon(summon);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_OOZE_DEAD)
            ++abuseTheOoze;
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == DATA_ABUSE_THE_OOZE)
            return abuseTheOoze;

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
                case EVENT_CHAIN_LIGHTNING:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100, true))
                        DoCast(target, SPELL_CHAIN_LIGHTING);
                    events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 10s, 15s);
                    break;
                case EVENT_LIGHTNING_SHIELD:
                    DoCast(me, SPELL_LIGHTING_SHIELD);
                    break;
                case EVENT_STATIC_CHARGE:
                    DoCastVictim(SPELL_STATIC_CHARGE);
                    events.ScheduleEvent(EVENT_STATIC_CHARGE, 20s, 25s);
                    break;
                case EVENT_LIGHTNING_RING:
                    DoCast(me, SPELL_LIGHTING_RING);
                    events.ScheduleEvent(EVENT_LIGHTNING_RING, 30s, 35s);
                    break;
                case EVENT_SUMMON:
                {
                    uint8 summonPipe = urand(0, 1);
                    if (HealthAbovePct(75))
                        me->SummonCreature(NPC_FORGED_IRON_DWARF, PipeLocations[summonPipe], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30s);
                    else if (HealthAbovePct(50))
                        me->SummonCreature(NPC_FORGED_IRON_TROGG, PipeLocations[summonPipe], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30s);
                    else if (HealthAbovePct(25))
                        me->SummonCreature(NPC_MALFORMED_OOZE, PipeLocations[summonPipe], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30s);
                    else
                        me->SummonCreature(NPC_EARTHEN_DWARF, PipeLocations[summonPipe], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30s);

                    events.ScheduleEvent(EVENT_SUMMON, 20s);
                    break;
                }
                case EVENT_FRENZY:
                    /// @todo: add emote
                    DoCast(me, SPELL_FRENZY, true);
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
        uint8 abuseTheOoze;
};

struct npc_malformed_ooze : public ScriptedAI
{
    npc_malformed_ooze(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        _mergeTimer = 10000;
    }

    void Reset() override
    {
        Initialize();
    }

    void UpdateAI(uint32 diff) override
    {
        if (_mergeTimer <= diff)
        {
            if (Creature* temp = me->FindNearestCreature(NPC_MALFORMED_OOZE, 3.0f, true))
            {
                DoSpawnCreature(NPC_IRON_SLUDGE, 0, 0, 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 20s);
                temp->DisappearAndDie();
                me->DisappearAndDie();
            }
            _mergeTimer = 3000;
        }
        else
            _mergeTimer -= diff;

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

private:
    uint32 _mergeTimer;
};

struct npc_iron_sludge : public ScriptedAI
{
    npc_iron_sludge(Creature* creature) : ScriptedAI(creature)
    {
        instance = creature->GetInstanceScript();
    }

    InstanceScript* instance;

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* sjonnir = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_SJONNIR)))
            sjonnir->AI()->DoAction(ACTION_OOZE_DEAD);
    }
};

class achievement_abuse_the_ooze : public AchievementCriteriaScript
{
    public:
        achievement_abuse_the_ooze() : AchievementCriteriaScript("achievement_abuse_the_ooze")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            if (!target)
                return false;

            if (Creature* Sjonnir = target->ToCreature())
                if (Sjonnir->AI()->GetData(DATA_ABUSE_THE_OOZE) >= 5)
                    return true;

            return false;
        }
};

void AddSC_boss_sjonnir()
{
    RegisterHallsOfStoneCreatureAI(boss_sjonnir);
    RegisterHallsOfStoneCreatureAI(npc_malformed_ooze);
    RegisterHallsOfStoneCreatureAI(npc_iron_sludge);
    new achievement_abuse_the_ooze();
}
