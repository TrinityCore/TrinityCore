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

#include "CreatureAI.h"
#include "CreatureAIImpl.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ObjectAccessor.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "TemporarySummon.h"

enum WitchHuntData
{
    NPC_HELENA_GENTLE_HUMAN     = 124922,
    NPC_HEXBOUND_SNARLER        = 128347,

    SAY_HELENA_AGGRO            = 0,
    SAY_HELENA_HALF_LIFE        = 1,
    SAY_HELENA_DEATH            = 2,

    EVENT_HELENA_RUINED_BOLT    = 1,
    EVENT_HELENA_SUMMON_ALIVE,
    EVENT_HELENA_SUMMON_ATTACK,

    SPELL_TAKE_A_SEAT_CURSED    = 248423,
    SPELL_HELENA_EMPOWERING     = 257877,
    SPELL_HELENA_RUINED_BOLT    = 256865
};

constexpr Position HelenaPetSummonPos = { 181.513885f, 1987.2222f, 101.9137f, 1.667730f };

// 124953 - Helena Gentle
struct npc_helena_gentle_witch_hunt : public ScriptedAI
{
    npc_helena_gentle_witch_hunt(Creature* creature) : ScriptedAI(creature), _helenaHalfLife(false) { }

    void JustAppeared() override
    {
        if (me->FindNearestCreatureWithOptions(50.0f, { .CreatureId = NPC_HEXBOUND_SNARLER, .StringId = "Summon", .IsAlive = FindCreatureAliveState::Alive }))
            _oocScheduler.Schedule(1s, [this](TaskContext context)
            {
                if (me->FindNearestCreatureWithOptions(50.0f, { .CreatureId = NPC_HEXBOUND_SNARLER, .StringId = "Summon", .IsAlive = FindCreatureAliveState::Alive }))
                    context.Repeat(500ms);
                else
                    HelenaSummonPet();
            });
        else
            HelenaSummonPet();
    }

    void HelenaSummonPet()
    {
        if (TempSummon* summon = me->SummonCreature(NPC_HEXBOUND_SNARLER, HelenaPetSummonPos))
        {
            me->CastSpell(summon, SPELL_HELENA_EMPOWERING);

            _hexboundSnarlerGuid = summon->GetGUID();
            summon->SetScriptStringId("Summon");
            summon->SetAIAnimKitId(730);
            summon->SetReactState(REACT_PASSIVE);
            summon->SetImmuneToAll(true);
            summon->SetUninteractible(true);
        }
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        Talk(SAY_HELENA_AGGRO);
        _events.ScheduleEvent(EVENT_HELENA_RUINED_BOLT, 9s);
        _events.ScheduleEvent(EVENT_HELENA_SUMMON_ALIVE, 1s);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_helenaHalfLife && me->HealthBelowPctDamaged(50, damage))
        {
            Talk(SAY_HELENA_HALF_LIFE);
            _helenaHalfLife = true;
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        me->DespawnOrUnsummon();

        if (Creature* hexboundSnarler = ObjectAccessor::GetCreature(*me, _hexboundSnarlerGuid))
            hexboundSnarler->DespawnOrUnsummon();
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_HELENA_DEATH);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
        {
            _oocScheduler.Update(diff);
            return;
        }

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_HELENA_RUINED_BOLT:
                    DoCastVictim(SPELL_HELENA_RUINED_BOLT);
                    _events.ScheduleEvent(EVENT_HELENA_RUINED_BOLT, 9s);
                    break;
                case EVENT_HELENA_SUMMON_ALIVE:
                    if (Creature* hexboundSnarler = ObjectAccessor::GetCreature(*me, _hexboundSnarlerGuid))
                    {
                        hexboundSnarler->SetAIAnimKitId(0);
                        hexboundSnarler->PlayOneShotAnimKitId(1099);
                        _events.ScheduleEvent(EVENT_HELENA_SUMMON_ATTACK, 2s);
                    }
                    break;
                case EVENT_HELENA_SUMMON_ATTACK:
                    if (Creature* hexboundSnarler = ObjectAccessor::GetCreature(*me, _hexboundSnarlerGuid))
                    {
                        hexboundSnarler->SetImmuneToAll(false);
                        hexboundSnarler->SetUninteractible(false);
                        hexboundSnarler->SetReactState(REACT_AGGRESSIVE);
                    }
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    TaskScheduler _oocScheduler;
    ObjectGuid _hexboundSnarlerGuid;
    bool _helenaHalfLife;
};

void AddSC_chapter_drustvar_the_final_effigy()
{
    // Creature
    RegisterCreatureAI(npc_helena_gentle_witch_hunt);
}
