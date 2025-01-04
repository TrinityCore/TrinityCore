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

/*
 * Comment: MAYBE need more improve the "Raptor Call".
 */

#include "ScriptMgr.h"
#include "drak_tharon_keep.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_BELLOWING_ROAR                          = 22686, // fears the group, can be resisted/dispelled
    SPELL_GRIEVOUS_BITE                           = 48920,
    SPELL_MANGLING_SLASH                          = 48873, // cast on the current tank, adds debuf
    SPELL_FEARSOME_ROAR                           = 48849,
    SPELL_PIERCING_SLASH                          = 48878, // debuff --> Armor reduced by 75%
    SPELL_RAPTOR_CALL                             = 59416, // dummy
    SPELL_GUT_RIP                                 = 49710,
    SPELL_REND                                    = 13738
};

enum Misc
{
    ACTION_RAPTOR_KILLED                          = 1,
    DATA_RAPTORS_KILLED                           = 2
};

enum Events
{
    EVENT_BELLOWING_ROAR                          = 1,
    EVENT_GRIEVOUS_BITE,
    EVENT_MANGLING_SLASH,
    EVENT_FEARSOME_ROAR,
    EVENT_PIERCING_SLASH,
    EVENT_RAPTOR_CALL
};

struct boss_king_dred : public BossAI
{
    boss_king_dred(Creature* creature) : BossAI(creature, DATA_KING_DRED)
    {
        Initialize();
    }

    void Initialize()
    {
        raptorsKilled = 0;
    }

    void Reset() override
    {
        Initialize();
        _Reset();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_BELLOWING_ROAR, 33s);
        events.ScheduleEvent(EVENT_GRIEVOUS_BITE, 20s);
        events.ScheduleEvent(EVENT_MANGLING_SLASH, 18500ms);
        events.ScheduleEvent(EVENT_FEARSOME_ROAR, 10s, 20s);
        events.ScheduleEvent(EVENT_PIERCING_SLASH, 15s);
        events.ScheduleEvent(EVENT_RAPTOR_CALL, 20s, 25s);
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_RAPTOR_KILLED)
            ++raptorsKilled;
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == DATA_RAPTORS_KILLED)
            return raptorsKilled;

        return 0;
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
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
                case EVENT_BELLOWING_ROAR:
                    DoCastAOE(SPELL_BELLOWING_ROAR);
                    events.ScheduleEvent(EVENT_BELLOWING_ROAR, 33s);
                    break;
                case EVENT_GRIEVOUS_BITE:
                    DoCastVictim(SPELL_GRIEVOUS_BITE);
                    events.ScheduleEvent(EVENT_GRIEVOUS_BITE, 20s);
                    break;
                case EVENT_MANGLING_SLASH:
                    DoCastVictim(SPELL_MANGLING_SLASH);
                    events.ScheduleEvent(EVENT_MANGLING_SLASH, 18500ms);
                    break;
                case EVENT_FEARSOME_ROAR:
                    DoCastAOE(SPELL_FEARSOME_ROAR);
                    events.ScheduleEvent(EVENT_FEARSOME_ROAR, 10s, 20s);
                    break;
                case EVENT_PIERCING_SLASH:
                    DoCastVictim(SPELL_PIERCING_SLASH);
                    events.ScheduleEvent(EVENT_PIERCING_SLASH, 15s);
                    break;
                case EVENT_RAPTOR_CALL:
                    DoCastVictim(SPELL_RAPTOR_CALL);

                    float x, y, z;

                    me->GetClosePoint(x, y, z, me->GetCombatReach() / 3, 10.0f);
                    me->SummonCreature(RAND(NPC_DRAKKARI_GUTRIPPER, NPC_DRAKKARI_SCYTHECLAW), x, y, z, 0, TEMPSUMMON_DEAD_DESPAWN, 1s);
                    events.ScheduleEvent(EVENT_RAPTOR_CALL, 20s, 25s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    uint8 raptorsKilled;
};

struct npc_drakkari_gutripper : public ScriptedAI
{
    npc_drakkari_gutripper(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
        instance = me->GetInstanceScript();
    }

    void Initialize()
    {
        GutRipTimer = urand(10000, 15000);
    }

    InstanceScript* instance;

    uint32 GutRipTimer;

    void Reset() override
    {
        Initialize();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (GutRipTimer <= diff)
        {
            DoCastVictim(SPELL_GUT_RIP, false);
            GutRipTimer = urand(10000, 15000);
        }
        else
            GutRipTimer -= diff;
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* Dred = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_KING_DRED)))
            Dred->AI()->DoAction(ACTION_RAPTOR_KILLED);
    }
};

struct npc_drakkari_scytheclaw : public ScriptedAI
{
    npc_drakkari_scytheclaw(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
        instance = me->GetInstanceScript();
    }

    void Initialize()
    {
        uiRendTimer = urand(10000, 15000);
    }

    InstanceScript* instance;

    uint32 uiRendTimer;

    void Reset() override
    {
        Initialize();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (uiRendTimer <= diff)
        {
            DoCastVictim(SPELL_REND, false);
            uiRendTimer = urand(10000, 15000);
        }
        else
            uiRendTimer -= diff;
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* Dred = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_KING_DRED)))
            Dred->AI()->DoAction(ACTION_RAPTOR_KILLED);
    }
};

class achievement_king_dred : public AchievementCriteriaScript
{
    public:
        achievement_king_dred() : AchievementCriteriaScript("achievement_king_dred")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            if (!target)
                return false;

            if (Creature* Dred = target->ToCreature())
                if (Dred->AI()->GetData(DATA_RAPTORS_KILLED) >= 6)
                    return true;

            return false;
        }
};

void AddSC_boss_king_dred()
{
    RegisterDrakTharonKeepCreatureAI(boss_king_dred);
    RegisterDrakTharonKeepCreatureAI(npc_drakkari_gutripper);
    RegisterDrakTharonKeepCreatureAI(npc_drakkari_scytheclaw);
    new achievement_king_dred();
}
