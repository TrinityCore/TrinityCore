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

#include "CellImpl.h"
#include "GameObject.h"
#include "GridNotifiersImpl.h"
#include "InstanceScript.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "aberrus_the_shadowed_crucible.h"

enum KazzaraSpells
{
    // Sundered NPCs
    SPELL_FEAR                  = 220540,

    // Kazzara
    SPELL_DREAD_LANDING         = 411872,
    SPELL_KAZZARA_INTRO         = 410541
};

enum KazzaraEvents
{
    EVENT_REMOVE_FLAGS          = 1
};

class CastFearEvent : public BasicEvent
{
    public:
        CastFearEvent(Unit* caster) : _caster(caster) { }

        bool Execute(uint64 /*execTime*/, uint32 /*diff*/) override
        {
            if (!_caster->IsAlive() || _caster->IsInCombat())
                return false;

            _caster->CastSpell(_caster, SPELL_FEAR, TRIGGERED_FULL_MASK);
            return true;
        }

    private:
        Unit* _caster;
};

// 201261 - Kazzara the Hellforged
struct boss_kazzara_the_hellforged : public BossAI
{
    boss_kazzara_the_hellforged(Creature* creature) : BossAI(creature, DATA_KAZZARA_THE_HELLFORGED) { }

    void JustAppeared() override
    {
        me->SetUninteractible(true);
        me->SetImmuneToAll(true);
        me->SetVisible(false);
    }

    void DoAction(int32 actionId) override
    {
        switch (actionId)
        {
            case ACTION_START_INTRO:
            {
                if (GameObject* gate = instance->GetGameObject(DATA_KAZZARA_GATE))
                {
                    gate->SetFlag(GO_FLAG_IN_USE);
                    gate->SetGoState(GO_STATE_READY);
                }

                me->SetVisible(true);

                DoCast(SPELL_DREAD_LANDING);
                DoCast(SPELL_KAZZARA_INTRO);

                std::vector<Creature*> sunderedMobs;
                GetCreatureListWithOptionsInGrid(sunderedMobs, me, 50.0f, FindCreatureOptions().SetStringId("sundered_mob"));

                if (sunderedMobs.empty())
                    return;

                for (Creature* sunderedMob : sunderedMobs)
                    sunderedMob->m_Events.AddEventAtOffset(new CastFearEvent(sunderedMob), Milliseconds(1500));

                scheduler.Schedule(10s, [this](TaskContext /*context*/)
                {
                    me->SetUninteractible(false);
                    me->SetImmuneToAll(false);
                });
                break;
            }
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);
    }
};

void AddSC_boss_kazzara_the_hellforged()
{
    RegisterAberrusTheShadowedCrucibleCreatureAI(boss_kazzara_the_hellforged);
}
