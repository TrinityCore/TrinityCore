/*
* Copyright 2021 ShadowCore
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
    SPELL_BROOD_ASSASINS = 332313,
    SPELL_WEB_WRAP_ROOT = 336306,
    SPELL_SHADOW_AMBUSH_MARK = 333353,
    SPELL_SHADOW_AMBUSH_DAMAGE = 331818,
    SPELL_SHROUD_WEB_DECREASE_SPEED = 332397,
    SPELL_ASSASINATE = 333406,
};

//164266
struct boss_domina_venomblade : public BossAI
{
    boss_domina_venomblade(Creature* creature) : BossAI(creature, DATA_DOMINA_VENOMBLADE) { }

    void Reset() override
    {
        BossAI::Reset();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        Talk(0);
        events.ScheduleEvent(SPELL_BROOD_ASSASINS, 1s);
        events.ScheduleEvent(SPELL_SHADOW_AMBUSH_MARK, 5s);
    }

    void JustSummoned(Creature* summon) override
    {
        switch (summon->GetEntry())
        {
        case NPC_BROOD_ASSASIN:
            summon->SetFaction(14);
            summon->SetLevel(60);
            summon->AddAura(SPELL_SHROUD_WEB_DECREASE_SPEED);
            SetCombatMovement(false);
            break;
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {         
        switch (eventId)
        {
        case SPELL_BROOD_ASSASINS:
        {
            Position broodAssasinsPos = me->GetRandomNearPosition(urand(30, 40));
            for (uint8 i = 0; i < 4; i++)
            {
                me->SummonCreature(NPC_BROOD_ASSASIN, broodAssasinsPos, TEMPSUMMON_MANUAL_DESPAWN);
            }
            events.Repeat(30s, 35s);
            break;
        }          

        case SPELL_SHADOW_AMBUSH_MARK:
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
            {
                me->AddAura(SPELL_SHADOW_AMBUSH_MARK, target);
                me->GetScheduler().Schedule(5100ms, [this, target](TaskContext /*context*/)
                {
                    if (!target)
                        return;

                    Position targetPos = target->GetPosition();
                    me->NearTeleportTo(targetPos);
                    me->CastSpell(targetPos, SPELL_SHADOW_AMBUSH_DAMAGE, true);
                });
            }
            events.Repeat(20s, 25s);
            break;
        }
    }

    void EnterEvadeMode(EvadeReason why) override
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

void AddSC_boss_domina_venomblade()
{
    RegisterCreatureAI(boss_domina_venomblade);
}
