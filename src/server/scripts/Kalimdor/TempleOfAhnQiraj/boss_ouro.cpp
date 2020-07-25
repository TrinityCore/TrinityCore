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

#include "temple_of_ahnqiraj.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "GameObject.h"

enum Spells
{
    // Ouro
    SPELL_BIRTH             = 26586,
    SPELL_GROUND_RUPTURE    = 26100,
};

enum Misc
{
    CUSTOM_ANIM_CREATE = 0
};

QuaternionData sandwormBaseRotation = { 0.f, 0.f, -0.3987484f, 0.9170604f };

struct boss_ouro : public BossAI
{
    boss_ouro(Creature* creature) : BossAI(creature, DATA_OURO) { }

    void JustAppeared() override
    {
        if (GameObject* sandwormBase = me->SummonGameObject(GO_SANDWORM_BASE, me->GetPosition(), sandwormBaseRotation, 0, GO_SUMMON_TIMED_OR_CORPSE_DESPAWN))
            sandwormBase->SendCustomAnim(CUSTOM_ANIM_CREATE);
        DoCastSelf(SPELL_BIRTH);
        DoZoneInCombat();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        BossAI::EnterEvadeMode(why);
        summons.DespawnAll();
        _DespawnAtEvade();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        /*
        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                default:
                    break;
            }
        }
        */

        DoMeleeAttackIfReady();
    }
};

struct npc_ouro_spawner : public ScriptedAI
{
    npc_ouro_spawner(Creature* creature) : ScriptedAI(creature) { }

    void JustEngagedWith(Unit* /*who*/) override
    {
        DoSummon(BOSS_OURO, me->GetPosition());
        me->DespawnOrUnsummon();
    }

    void AttackStart(Unit* /*victim*/) override { }
    void UpdateAI(uint32 /*diff*/) override { }
};

void AddSC_boss_ouro()
{
    RegisterTempleOfAhnqirajhCreatureAI(boss_ouro);
    RegisterTempleOfAhnqirajhCreatureAI(npc_ouro_spawner);
}
