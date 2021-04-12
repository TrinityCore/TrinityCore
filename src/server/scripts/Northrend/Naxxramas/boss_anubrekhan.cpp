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
#include "ObjectAccessor.h"
#include "naxxramas.h"
#include "Player.h"
#include "ScriptedCreature.h"

enum AnubSays
{
    SAY_AGGRO           = 0,
    SAY_GREET           = 1,
    SAY_SLAY            = 2,

    EMOTE_LOCUST        = 3
};

enum GuardSays
{
    EMOTE_FRENZY        = 0,
    EMOTE_SPAWN         = 1,
    EMOTE_SCARAB        = 2
};

enum Events
{
    EVENT_IMPALE                    = 1,        // Cast Impale on a random target
    EVENT_LOCUST,                               // Begin channeling Locust Swarm
    EVENT_LOCUST_ENDS,                          // Locust swarm dissipates
    EVENT_SPAWN_GUARD,                          // 10-man only - crypt guard has delayed spawn; also used for the locust swarm crypt guard in both modes
    EVENT_SCARABS,                              // spawn corpse scarabs
    EVENT_BERSERK                               // Berserk
};

enum Spells
{
    SPELL_IMPALE                    = 28783,    // 25-man: 56090
    SPELL_LOCUST_SWARM              = 28785,    // 25-man: 54021
    SPELL_SUMMON_CORPSE_SCARABS_PLR = 29105,    // This spawns 5 corpse scarabs on top of player
    SPELL_SUMMON_CORPSE_SCARABS_MOB = 28864,   // This spawns 10 corpse scarabs on top of dead guards
    SPELL_BERSERK                   = 27680
};

enum SpawnGroups
{
    GROUP_INITIAL_25M       = 1,
    GROUP_SINGLE_SPAWN      = 2
};

enum Misc
{
    ACHIEV_TIMED_START_EVENT                      = 9891
};

enum Phases
{
    PHASE_NORMAL    = 1,
    PHASE_SWARM
};

struct boss_anubrekhan : public BossAI
{
    boss_anubrekhan(Creature* creature) : BossAI(creature, BOSS_ANUBREKHAN) { }

    void SummonGuards()
    {
        if (Is25ManRaid())
            me->SummonCreatureGroup(GROUP_INITIAL_25M);
    }

    void InitializeAI() override
    {
        if (!me->isDead() && instance->GetBossState(BOSS_ANUBREKHAN) != DONE)
        {
            Reset();
            SummonGuards();
        }
    }

    void Reset() override
    {
        _Reset();
        guardCorpses.clear();
    }

    void JustReachedHome() override
    {
        _JustReachedHome();
        SummonGuards();
    }

    void JustSummoned(Creature* summon) override
    {
        BossAI::JustSummoned(summon);

        if (me->IsInCombat())
            if (summon->GetEntry() == NPC_CRYPT_GUARD)
                summon->AI()->Talk(EMOTE_SPAWN, me);
    }

    void SummonedCreatureDies(Creature* summon, Unit* killer) override
    {
        BossAI::SummonedCreatureDies(summon, killer);

        if (summon->GetEntry() == NPC_CRYPT_GUARD)
            guardCorpses.insert(summon->GetGUID());
    }

    void SummonedCreatureDespawn(Creature* summon) override
    {
        BossAI::SummonedCreatureDespawn(summon);

        if (summon->GetEntry() == NPC_CRYPT_GUARD)
            guardCorpses.erase(summon->GetGUID());
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            victim->CastSpell(victim, SPELL_SUMMON_CORPSE_SCARABS_PLR, me->GetGUID());

        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();

        // start achievement timer (kill Maexna within 20 min)
        instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);

        summons.DoZoneInCombat();

        events.SetPhase(PHASE_NORMAL);
        events.ScheduleEvent(EVENT_IMPALE, randtime(Seconds(10), Seconds(20)), 0, PHASE_NORMAL);
        events.ScheduleEvent(EVENT_SCARABS, randtime(Seconds(20), Seconds(30)), 0, PHASE_NORMAL);
        events.ScheduleEvent(EVENT_LOCUST, Minutes(1)+randtime(Seconds(40), Seconds(60)), 0, PHASE_NORMAL);
        events.ScheduleEvent(EVENT_BERSERK, 10min);

        if (!Is25ManRaid())
            events.ScheduleEvent(EVENT_SPAWN_GUARD, randtime(Seconds(15), Seconds(20)));
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
                case EVENT_IMPALE:
                    if (events.GetTimeUntilEvent(EVENT_LOCUST) < 5s)
                        break; // don't chain impale tank -> locust swarm
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_IMPALE);
                    else
                        EnterEvadeMode();

                    events.Repeat(randtime(Seconds(10), Seconds(20)));
                    break;
                case EVENT_SCARABS:
                    if (!guardCorpses.empty())
                    {
                        if (ObjectGuid target = Trinity::Containers::SelectRandomContainerElement(guardCorpses))
                            if (Creature* creatureTarget = ObjectAccessor::GetCreature(*me, target))
                            {
                                creatureTarget->CastSpell(creatureTarget, SPELL_SUMMON_CORPSE_SCARABS_MOB, me->GetGUID());
                                creatureTarget->AI()->Talk(EMOTE_SCARAB);
                                creatureTarget->DespawnOrUnsummon();
                            }
                    }
                    events.Repeat(randtime(Seconds(40), Seconds(60)));
                    break;
                case EVENT_LOCUST:
                    Talk(EMOTE_LOCUST);
                    events.SetPhase(PHASE_SWARM);
                    DoCast(me, SPELL_LOCUST_SWARM);

                    events.ScheduleEvent(EVENT_SPAWN_GUARD, 3s);
                    events.ScheduleEvent(EVENT_LOCUST_ENDS, RAID_MODE(Seconds(19), Seconds(23)));
                    events.Repeat(Minutes(1)+Seconds(30));
                    break;
                case EVENT_LOCUST_ENDS:
                    events.SetPhase(PHASE_NORMAL);
                    events.ScheduleEvent(EVENT_IMPALE, randtime(Seconds(10), Seconds(20)), 0, PHASE_NORMAL);
                    events.ScheduleEvent(EVENT_SCARABS, randtime(Seconds(20), Seconds(30)), 0, PHASE_NORMAL);
                    break;
                case EVENT_SPAWN_GUARD:
                    me->SummonCreatureGroup(GROUP_SINGLE_SPAWN);
                    break;
                case EVENT_BERSERK:
                    DoCast(me, SPELL_BERSERK, true);
                    events.ScheduleEvent(EVENT_BERSERK, 10min);
                    break;
            }
        }

        if (events.IsInPhase(PHASE_NORMAL))
            DoMeleeAttackIfReady();
    }
    private:
        GuidSet guardCorpses;
};

class at_anubrekhan_entrance : public OnlyOnceAreaTriggerScript
{
    public:
        at_anubrekhan_entrance() : OnlyOnceAreaTriggerScript("at_anubrekhan_entrance") { }

        bool TryHandleOnce(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
        {
            InstanceScript* instance = player->GetInstanceScript();
            if (!instance || instance->GetBossState(BOSS_ANUBREKHAN) != NOT_STARTED)
                return true;

            if (Creature* anub = ObjectAccessor::GetCreature(*player, instance->GetGuidData(DATA_ANUBREKHAN)))
                anub->AI()->Talk(SAY_GREET);

            return true;
        }
};

void AddSC_boss_anubrekhan()
{
    RegisterNaxxramasCreatureAI(boss_anubrekhan);

    new at_anubrekhan_entrance();
}
