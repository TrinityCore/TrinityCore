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
#include "Player.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "InstanceScript.h"
#include "SpellAuras.h"
#include "plaguefall.h"

enum Spells
{
    SPELL_SLIME_INJECTION = 329110,
    SPELL_SLIME_INJECTION_SUMMON = 321320,
    SPELL_SLIME_LUNGE_CAST = 329215,
    SPELL_SLIME_LUNGE_JUMP = 329216,
    SPELL_SLIME_LUNGE_DAMAGE = 329217,
};

//164967
struct boss_doctor_ickus : public BossAI
{
    boss_doctor_ickus(Creature* creature) : BossAI(creature, DATA_DOCTOR_ICKUS) { }

    void Reset() override
    {
        BossAI::Reset();
    }

    void EnterCombat(Unit* /*who*/)
    {
        Talk(0);
        events.ScheduleEvent(SPELL_SLIME_INJECTION, 5s);
        //events.ScheduleEvent(, 10s); PB
        events.ScheduleEvent(SPELL_SLIME_LUNGE_CAST, 15s);
    }

    void ExecuteEvent(uint32 eventId) override
    {         
        switch (eventId)
        {
        case SPELL_SLIME_INJECTION:
            DoCastVictim(SPELL_SLIME_INJECTION, false);
            events.Repeat(30s, 35s);
            break;

        case SPELL_SLIME_LUNGE_CAST:
            me->CastSpell(nullptr, SPELL_SLIME_LUNGE_CAST, false);
            events.Repeat(20s, 25s);
            break;
        }
    }

    void OnSpellFinished(SpellInfo const* spellInfo)
    {
        switch (spellInfo->Id)
        {
        case SPELL_SLIME_LUNGE_CAST:
            {
            }
            break;
        }
    };

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _JustReachedHome();
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*who*/) override
    {
        _JustDied();
        Talk(4);
        me->RemoveAllAreaTriggers();
    }
};

void AddSC_boss_doctor_ickus()
{
    RegisterCreatureAI(boss_doctor_ickus);
}
