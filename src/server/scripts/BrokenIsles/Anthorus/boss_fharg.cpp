/*
 * This file is part of the AshamaneCore Project. See AUTHORS file for Copyright information
 * Copyright (C) 2018+ MagicStormProject <https://github.com/MagicStormTeam>
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "ObjectAccessor.h"
#include "antorus_the_burning_throne.h"
#include "Log.h"

enum Spells
{
    SPELL_DESTROYERS_BOON = 244049,
    SPELL_SARGERAS_BLESSING = 246057,
    SPELL_FEL_IMBUEMENT = 253602,
    SPELL_TRAMPLE = 252044,

    SPELL_DECAY = 245098,
    SPELL_CORRUPTING_MAW = 251447,
    SPELL_CORRUPTING_MAW_DAMAGE = 254760,
    SPELL_SIPHONED = 248819,
    SPELL_CONSUMING_SPHERE = 244131,


    SPELL_BURNING_MAW = 254747,
    SPELL_DESOLATE_GAZE = 244768,

    //hero
    SPELL_WEIGHT_OF_DARKNESS = 244071,
    SPELL_MOLTEN_TOUCH = 244086,
};


struct boss_shatug_fhargAI : public BossAI
{
    boss_shatug_fhargAI(Creature* creature) : BossAI(creature, DATA_FHARG)
    {
        Initialize();
        instance = creature->GetInstanceScript();
    }

    void Initialize()
    {
        me->RemoveAurasDueToSpell(SPELL_DESTROYERS_BOON);
        DoCastSelf(SPELL_TRAMPLE);
    }

    InstanceScript* instance;

    virtual bool IAmShatug() = 0;
    virtual void Reset() override = 0;

    void TwinReset()
    {
        Initialize();
        me->ClearUnitState(UNIT_STATE_STUNNED);
    }

    void TwinDistanceAura()
    {
        if (!me->IsAlive())
            return;

        Creature* pOtherBoss = GetOtherBoss();
        if (!pOtherBoss)
            return;
        if (me->GetDistance(pOtherBoss->GetPosition()) <= 40.0f)
        {
            //crash now
            //DoCastSelf(SPELL_SARGERAS_BLESSING);
            //pOtherBoss->AI()->DoCastSelf(SPELL_SARGERAS_BLESSING);
            me->RemoveAurasDueToSpell(SPELL_FEL_IMBUEMENT);
            pOtherBoss->RemoveAurasDueToSpell(SPELL_FEL_IMBUEMENT);

        }
        else
        {
           //SPELL_FEL_IMBUEMENT
            DoCastSelf(SPELL_FEL_IMBUEMENT);
            pOtherBoss->AI()->DoCastSelf(SPELL_FEL_IMBUEMENT);
            me->RemoveAurasDueToSpell(SPELL_SARGERAS_BLESSING);
            pOtherBoss->RemoveAurasDueToSpell(SPELL_SARGERAS_BLESSING);
        }
    }

    Creature* GetOtherBoss()
    {
        return  IAmShatug() ? me->FindNearestCreature(NPC_FHARG, 500.0f) : me->FindNearestCreature(DATA_SHATUG, 500.0f);
        //return ObjectAccessor::GetCreature(*me, instance->GetGuidData(IAmShatug() ? DATA_SHATUG : DATA_FHARG));
    }

    void DamageTaken(Unit* /*done_by*/, uint32 &damage) override
    {
        Unit* pOtherBoss = GetOtherBoss();
        if (pOtherBoss)
        {
            uint64 ohealth = pOtherBoss->GetHealth() - damage;
            pOtherBoss->SetHealth(ohealth > 0 ? ohealth : 0);

            if (ohealth <= 0)
            {
                pOtherBoss->setDeathState(JUST_DIED);
                pOtherBoss->SetDynamicFlags(UNIT_DYNFLAG_LOOTABLE);
            }

        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Creature* pOtherBoss = GetOtherBoss();
        if (pOtherBoss)
        {
            pOtherBoss->SetHealth(0);
            pOtherBoss->setDeathState(JUST_DIED);
            pOtherBoss->SetDynamicFlags(UNIT_DYNFLAG_LOOTABLE);
        }
        me->SummonCreature(128289, Position(-3224.603f, 10388.73f, -155.3857f, 1.190612f), TEMPSUMMON_MANUAL_DESPAWN);
        //if (instance)
            //instance->DoPlayConversation(5523);
    }

    void EnterCombat(Unit* who) override
    {
        _EnterCombat();
        Creature* pOtherBoss = GetOtherBoss();
        if (pOtherBoss)
        {
            /// @todo we should activate the other boss location so he can start attackning even if nobody
            // is near I dont know how to do that
            if (!pOtherBoss->IsInCombat())
            {
                CreatureAI* otherAI =  pOtherBoss->AI();
                otherAI->AttackStart(who);
                otherAI->DoZoneInCombat();
            }
        }
    }

};

struct boss_shatug : public boss_shatug_fhargAI
{
    bool IAmShatug() override { return true; }
    boss_shatug(Creature* creature) : boss_shatug_fhargAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
    }

    void Reset() override
    {
        TwinReset();
        Initialize();
    }

    void ScheduleTasks() override
    {
        if (instance)
            //instance->DoPlayConversation(5522);
        events.ScheduleEvent(SPELL_SARGERAS_BLESSING, 1s);
        //
        events.ScheduleEvent(SPELL_DECAY, 5s);
        events.ScheduleEvent(SPELL_CORRUPTING_MAW, 5s);
        events.ScheduleEvent(SPELL_CORRUPTING_MAW_DAMAGE, 5s);
        events.ScheduleEvent(SPELL_SIPHONED, 5s);
        events.ScheduleEvent(SPELL_CONSUMING_SPHERE, 5s);
        if (me->GetMap()->IsHeroic() || me->GetMap()->IsMythic())
            events.ScheduleEvent(SPELL_WEIGHT_OF_DARKNESS, 30s, 40s);
    }

    void ExecuteEvent(uint32 eventId) override
    {

        switch (eventId)
        {
        case SPELL_SARGERAS_BLESSING:
        {
            TwinDistanceAura();
            events.Repeat(1s);
            break;
        }
        case SPELL_DECAY:
        {
            DoCast(SPELL_DECAY);
            events.Repeat(5s);
            break;
        }
        case SPELL_CORRUPTING_MAW:
        {
            DoCast(SPELL_CORRUPTING_MAW);
            events.Repeat(5s);
            break;
        }
        case SPELL_CORRUPTING_MAW_DAMAGE:
        {
            DoCast(SPELL_CORRUPTING_MAW_DAMAGE);
            events.Repeat(5s);
            break;
        }
        case SPELL_SIPHONED:
        {
            //random
            if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                me->CastSpell(target1, SPELL_SIPHONED, false);
            events.Repeat(10s, 15s);
            break;
        }
        case SPELL_CONSUMING_SPHERE:
        {
            //random
            if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                me->CastSpell(target1, SPELL_CONSUMING_SPHERE, false);
            events.Repeat(10s, 15s);
            break;
        }
        case SPELL_WEIGHT_OF_DARKNESS:
        {
            if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                me->CastSpell(target1, SPELL_WEIGHT_OF_DARKNESS, false);
            events.Repeat(30s, 45s);
            break;
        }
        default:
            break;
        }
    }
};

struct boss_fharg : public boss_shatug_fhargAI
{
    bool IAmShatug() override { return false; }
    boss_fharg(Creature* creature) : boss_shatug_fhargAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
    }

    void Reset() override
    {
        TwinReset();
        Initialize();
    }

    void ScheduleTasks() override
    {
        events.ScheduleEvent(SPELL_SARGERAS_BLESSING, 1s);
        events.ScheduleEvent(SPELL_CORRUPTING_MAW, 5s);
        events.ScheduleEvent(SPELL_DESOLATE_GAZE, 5s);

        events.ScheduleEvent(SPELL_CONSUMING_SPHERE, 5s);
        if (me->GetMap()->IsHeroic() || me->GetMap()->IsMythic())
            events.ScheduleEvent(SPELL_MOLTEN_TOUCH, 30s, 40s);
    }

    void ExecuteEvent(uint32 eventId) override
    {

        switch (eventId)
        {
        case SPELL_SARGERAS_BLESSING:
        {
            TwinDistanceAura();
            events.Repeat(1s);
            break;
        }
        case SPELL_CORRUPTING_MAW:
        {
            DoCast(SPELL_CORRUPTING_MAW);
            events.Repeat(5s);
            break;
        }
        case SPELL_DESOLATE_GAZE:
        {
            DoCast(SPELL_DESOLATE_GAZE);
            events.Repeat(5s);
            break;
        }
        case SPELL_CONSUMING_SPHERE:
        {
            //random
            if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                me->CastSpell(target1, SPELL_CONSUMING_SPHERE, false);
            events.Repeat(10s, 15s);
            break;
        }
        case SPELL_MOLTEN_TOUCH:
        {
            if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                me->CastSpell(target1, SPELL_MOLTEN_TOUCH, false);
            events.Repeat(30s, 45s);
            break;
        }
        default:
            break;
        }
    }
};
/* 128289
[29] Position: X: -3224.603 Y: 10388.73 Z: -155.3857
[29] Orientation: 1.190612
*/
enum
{
    //SPELL_GATEWAY = 254464,
    SPELL_GATEWAY = 253773,
};

struct npc_lightforged_teleport_pod_128289 : public ScriptedAI
{
    npc_lightforged_teleport_pod_128289(Creature* creature) : ScriptedAI(creature) { }

    Position const Path01[4] =
    {
        { -3211.96f, 10384.4f, -155.4712f },
        { -3191.431f, 10370.25f, -108.6854f },
        { -3111.775879f, 10468.264648f, -76.464317f },
        { -3084.96582f, 10496.886719f, -110.809273f }
    };
    using Path01Size = std::extent<decltype(Path01)>;

    void IsSummonedBy(Unit* summoner) override
    {
        me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
    }
    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
        {
            player->CastSpell(player, SPELL_GATEWAY, true);
            player->GetMotionMaster()->MoveSmoothPath(1, Path01, Path01Size::value, false, true);
            me->GetScheduler().Schedule(Milliseconds(4000), [player](TaskContext context)
            {
                player->CastSpell(player, SPELL_GATEWAY, true);
                if (context.GetRepeatCounter() < 4)
                    context.Repeat(4s);
            });
            //if (instance)
                //instance->DoDelayedConversation(8000, 5524);
        }
    }
};
void AddSC_boss_fharg()
{
    RegisterCreatureAI(boss_shatug);
    RegisterCreatureAI(boss_fharg);
    RegisterCreatureAI(npc_lightforged_teleport_pod_128289);
}
