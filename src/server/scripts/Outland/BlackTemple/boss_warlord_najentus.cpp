/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "black_temple.h"
#include "Player.h"
#include "SpellInfo.h"

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
    SPELL_NEEDLE_SPINE              = 39992,
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

enum EventGroups
{
    GCD_CAST                        = 1,
    GCD_YELL                        = 2
};

class boss_najentus : public CreatureScript
{
public:
    boss_najentus() : CreatureScript("boss_najentus") { }

    struct boss_najentusAI : public BossAI
    {
        boss_najentusAI(Creature* creature) : BossAI(creature, DATA_HIGH_WARLORD_NAJENTUS)
        {
            SpineTargetGUID = 0;
        }

        void Reset() override
        {
            _Reset();
            SpineTargetGUID = 0;
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(SAY_SLAY);
            events.DelayEvents(5000, GCD_YELL);
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
                DoCast(me, SPELL_TIDAL_BURST, true);
                ResetTimer();
            }
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            Talk(SAY_AGGRO);
            events.ScheduleEvent(EVENT_BERSERK, 480000, GCD_CAST);
            events.ScheduleEvent(EVENT_YELL, 45000 + (rand32() % 76) * 1000, GCD_YELL);
            ResetTimer();
        }

        bool RemoveImpalingSpine()
        {
            if (!SpineTargetGUID)
                return false;

            Unit* target = ObjectAccessor::GetUnit(*me, SpineTargetGUID);
            if (target && target->HasAura(SPELL_IMPALING_SPINE))
                target->RemoveAurasDueToSpell(SPELL_IMPALING_SPINE);
            SpineTargetGUID=0;
            return true;
        }

        void ResetTimer(uint32 inc = 0)
        {
            events.RescheduleEvent(EVENT_NEEDLE, 10000 + inc, GCD_CAST);
            events.RescheduleEvent(EVENT_SPINE, 20000 + inc, GCD_CAST);
            events.RescheduleEvent(EVENT_SHIELD, 60000 + inc);
        }

        void ExecuteEvent(uint32 eventId) override
        {
            switch (eventId)
            {
                case EVENT_SHIELD:
                    DoCast(me, SPELL_TIDAL_SHIELD, true);
                    ResetTimer(45000);
                    break;
                case EVENT_BERSERK:
                    Talk(SAY_ENRAGE);
                    DoCast(me, SPELL_BERSERK, true);
                    events.DelayEvents(15000, GCD_YELL);
                    break;
                case EVENT_SPINE:
                {
                    Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1);

                    if (!target)
                        target = me->GetVictim();

                    if (target)
                    {
                        DoCast(target, SPELL_IMPALING_SPINE, true);
                        SpineTargetGUID = target->GetGUID();
                        //must let target summon, otherwise you cannot click the spine
                        target->SummonGameObject(GO_NAJENTUS_SPINE, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), me->GetOrientation(), 0, 0, 0, 0, 30);
                        Talk(SAY_NEEDLE);
                        events.DelayEvents(1500, GCD_CAST);
                        events.DelayEvents(15000, GCD_YELL);
                    }
                    events.ScheduleEvent(EVENT_SPINE, 21000, GCD_CAST);
                    return;
                }
                case EVENT_NEEDLE:
                    {
                        //DoCast(me, SPELL_NEEDLE_SPINE, true);
                        std::list<Unit*> targets;
                        SelectTargetList(targets, 3, SELECT_TARGET_RANDOM, 80, true);
                        for (std::list<Unit*>::const_iterator i = targets.begin(); i != targets.end(); ++i)
                            DoCast(*i, 39835, true);
                        events.ScheduleEvent(EVENT_NEEDLE, urand(15000, 25000), GCD_CAST);
                        events.DelayEvents(1500, GCD_CAST);
                        return;
                    }
                case EVENT_YELL:
                    Talk(SAY_SPECIAL);
                    events.ScheduleEvent(EVENT_YELL, urand(25000, 100000), GCD_YELL);
                    events.DelayEvents(15000, GCD_YELL);
                    break;
                default:
                    break;
            }
        }

    private:
        uint64 SpineTargetGUID;
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

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (InstanceScript* instance = go->GetInstanceScript())
            if (Creature* Najentus = ObjectAccessor::GetCreature(*go, instance->GetData64(DATA_HIGH_WARLORD_NAJENTUS)))
                if (ENSURE_AI(boss_najentus::boss_najentusAI, Najentus->AI())->RemoveImpalingSpine())
                {
                    player->CastSpell(player, SPELL_CREATE_NAJENTUS_SPINE, true);
                    go->Delete();
                }
        return true;
    }

};

void AddSC_boss_najentus()
{
    new boss_najentus();
    new go_najentus_spine();
}
