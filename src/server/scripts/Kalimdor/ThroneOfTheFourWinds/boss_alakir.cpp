/*
* Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "throne_of_the_four_winds.h"
#include "GameObject.h"
#include "ObjectMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "Spell.h"

enum Spells
{
    // Al'Akir
    SPELL_WIND_BURST                    = 87770,
    SPELL_LIGHTNING_STRIKE_TARGETING    = 91327,
};

enum Events
{
    // Al'Akir
    EVENT_WIND_BURST = 1,
    EVENT_LIGHTNING_STRIKE,

};

enum Phases
{
    PHASE_ONE   = 1,
    PHASE_TWO   = 2,
    PHASE_THREE = 3
};

enum Actions
{
};

enum Texts
{
    SAY_CONCLAVE_OF_WIND_DEFEATED   = 0,
    SAY_AGGRO                       = 1,
    SAY_ANNOUNCE_WIND_BURST         = 2,
};

enum SummonGroups
{
    SUMMON_GROUP_SLIPSTREAM = 0
};

struct boss_alakir : public BossAI
{
    boss_alakir(Creature* creature) : BossAI(creature, DATA_ALAKIR)
    {
        Initialize();
    }

    void Initialize()
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void JustEngagedWith(Unit* who) override
    {
        _JustEngagedWith();
        Talk(SAY_AGGRO);
        me->SetReactState(REACT_AGGRESSIVE);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

        events.SetPhase(PHASE_ONE);
        events.ScheduleEvent(EVENT_WIND_BURST, 23s, 0, PHASE_ONE);
    }

    void Reset()
    {
        _Reset();
        if (instance->GetBossState(DATA_CONCLAVE_OF_WIND) == DONE)
            me->SummonCreatureGroup(SUMMON_GROUP_SLIPSTREAM);
    }

    void KilledUnit(Unit* killed) override
    {
        //if (killed->GetTypeId() == TYPEID_PLAYER)
        //    Talk(SAY_SLAY);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        _EnterEvadeMode();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        summons.DespawnAll();
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_CONCLAVE_DEFEATED:
                Talk(SAY_CONCLAVE_OF_WIND_DEFEATED);
                me->SummonCreatureGroup(SUMMON_GROUP_SLIPSTREAM);
                break;
            default:
                break;
        }
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
    }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
    {
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);

        switch (summon->GetEntry())
        {
            case NPC_SLIPSTREAM:
                summon->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                break;
            default:
                break;
        }
    }

    uint32 GetData(uint32 type) const override
    {
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
                case EVENT_WIND_BURST:
                    Talk(SAY_ANNOUNCE_WIND_BURST);
                    DoCastAOE(SPELL_WIND_BURST);
                    events.Repeat(26s, 29s);
                default:
                    break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

void AddSC_boss_alakir()
{
    RegisterThroneOfTheFourWindsCreatureAI(boss_alakir);
}
