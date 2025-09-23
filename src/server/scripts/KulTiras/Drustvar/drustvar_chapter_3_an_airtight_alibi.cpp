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
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum SaveWhoWeCanData
{
    // Creature
    NPC_FRIGHTEND_WOODSMAN              = 126159,

    // Text
    SAY_FRIGHTENDED_WOODSMAN_RALLIED    = 0,

    // Path
    PATH_FRIGHTEND_WOODSMAN_RALLIED     = 12615900,

    // Spells
    SPELL_DRUSTVAR_WOODSMAN_RALLYING    = 251542
};

// 126159 - Frightend Woodsman
struct npc_drustvar_frightend_woodsman : public ScriptedAI
{
    npc_drustvar_frightend_woodsman(Creature* creature) : ScriptedAI(creature) {}

    void SpellHit(WorldObject* caster, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_DRUSTVAR_WOODSMAN_RALLYING)
        {
            Player* player = caster->ToPlayer();
            if (!player)
                return;

            player->KilledMonsterCredit(NPC_FRIGHTEND_WOODSMAN);
            if (Creature* woodsmanObject = player->FindNearestCreatureWithOptions(10.0f, { .CreatureId = NPC_FRIGHTEND_WOODSMAN, .IgnorePhases = true }))
                woodsmanObject->SummonPersonalClone(woodsmanObject->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, player);
        }
    }
};

// 126159 - Frightend Woodsman
struct npc_drustvar_frightend_woodsman_private : public ScriptedAI
{
    npc_drustvar_frightend_woodsman_private(Creature* creature) : ScriptedAI(creature) {}

    uint32 GetPathId() const
    {
        if (me->HasStringId("CosmeticWoodmansPath0"))
            return PATH_FRIGHTEND_WOODSMAN_RALLIED + 0;
        else if (me->HasStringId("CosmeticWoodmansPath1"))
            return PATH_FRIGHTEND_WOODSMAN_RALLIED + 1;
        else if (me->HasStringId("CosmeticWoodmansPath2"))
            return PATH_FRIGHTEND_WOODSMAN_RALLIED + 2;
        else if (me->HasStringId("CosmeticWoodmansPath3"))
            return PATH_FRIGHTEND_WOODSMAN_RALLIED + 3;
        else if (me->HasStringId("CosmeticWoodmansPath4"))
            return PATH_FRIGHTEND_WOODSMAN_RALLIED + 4;
        else if (me->HasStringId("CosmeticWoodmansPath5"))
            return PATH_FRIGHTEND_WOODSMAN_RALLIED + 5;
        else if (me->HasStringId("CosmeticWoodmansPath6"))
            return PATH_FRIGHTEND_WOODSMAN_RALLIED + 6;
        else if (me->HasStringId("CosmeticWoodmansPath7"))
            return PATH_FRIGHTEND_WOODSMAN_RALLIED + 7;
        else if (me->HasStringId("CosmeticWoodmansPath8"))
            return PATH_FRIGHTEND_WOODSMAN_RALLIED + 8;
        else if (me->HasStringId("CosmeticWoodmansPath9"))
            return PATH_FRIGHTEND_WOODSMAN_RALLIED + 9;
        else if (me->HasStringId("CosmeticWoodmansPath10"))
            return PATH_FRIGHTEND_WOODSMAN_RALLIED + 10;
        return 0;
    }

    void JustAppeared() override
    {
        me->SetUninteractible(true);
        me->SetImmuneToAll(true);

        _scheduler.Schedule(1s, [this](TaskContext /*task*/)
        {
            me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
            Talk(SAY_FRIGHTENDED_WOODSMAN_RALLIED);
        });

        _scheduler.Schedule(3s, [this](TaskContext /*task*/)
        {
            me->GetMotionMaster()->MovePath(GetPathId(), false);
        });
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 /*pathId*/) override
    {
        me->DespawnOrUnsummon(3s);
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

CreatureAI* FrightendWoodsmanAISelector(Creature* creature)
{
    if (creature->IsPrivateObject())
        return new npc_drustvar_frightend_woodsman_private(creature);
    return new npc_drustvar_frightend_woodsman(creature);
};

void AddSC_drustvar_chapter_3_an_airtight_alibi()
{
    // AISelector
    new FactoryCreatureScript<CreatureAI, &FrightendWoodsmanAISelector>("npc_drustvar_frightend_woodsman_private");
}
