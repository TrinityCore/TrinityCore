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
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "well_of_eternity.h"

enum PerotharnSpells
{
    // Intro
    SPELL_CAMOUFLAGE       = 105341,
    SPELL_CORRUPTING_TOUCH = 104939
};

enum PerotharnIntroPaths
{
    PATH_DREADLORD_DEFENDER_1 = 5565600,
    PATH_DREADLORD_DEFENDER_2 = 5565601,
    PATH_CORRUPTED_ARCANIST   = 5565400,
    PATH_LEGION_DEMON         = 5550300
};

enum PerotharnTexts
{
    // Intro
    SAY_INTRO_0 = 0,
    SAY_INTRO_1 = 1,
    SAY_INTRO_2 = 2
};

// 55085 - Peroth'arn
struct boss_peroth_arn : public BossAI
{
    boss_peroth_arn(Creature* creature) : BossAI(creature, BOSS_PEROTHARN) { }

    void DoAction(int32 actionId) override
    {
        switch (actionId)
        {
            case ACTION_PEROTHARN_INTRO:
            {
                if (instance->GetData(DATA_PEROTHARN_INTRO) != DONE)
                {
                    Talk(SAY_INTRO_0);
                    scheduler.Schedule(5s + 659ms, [this](TaskContext context)
                    {
                        Creature* legionDemon = me->FindNearestCreatureWithOptions(20.0f, { .StringId = "legion_demon_woe_intro" });

                        if (!legionDemon)
                            return;

                        me->SetFacingToObject(legionDemon);
                        Talk(SAY_INTRO_1);
                        legionDemon->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE_NO_SHEATH);
                        context.Schedule(3s + 622ms, [this](TaskContext context)
                        {
                            
                            Creature* dreadlordDefender1 = me->FindNearestCreatureWithOptions(30.0f, { .StringId = "dreadlord_defender_woe_intro_1" });
                            Creature* dreadlordDefender2 = me->FindNearestCreatureWithOptions(30.0f, { .StringId = "dreadlord_defender_woe_intro_2" });
                            Creature* corruptedArcanist = me->FindNearestCreatureWithOptions(30.0f, { .StringId = "corrupted_arcanist_woe_intro" });

                            if (!dreadlordDefender1 || !dreadlordDefender2 || !corruptedArcanist)
                                return;

                            me->SetFacingToObject(corruptedArcanist);
                            Talk(SAY_INTRO_2);

                            dreadlordDefender1->GetMotionMaster()->MovePath(PATH_DREADLORD_DEFENDER_1, false);
                            dreadlordDefender1->DespawnOrUnsummon(15s);

                            dreadlordDefender2->GetMotionMaster()->MovePath(PATH_DREADLORD_DEFENDER_2, false);
                            dreadlordDefender2->DespawnOrUnsummon(15s);

                            corruptedArcanist->GetMotionMaster()->MovePath(PATH_CORRUPTED_ARCANIST, false);
                            corruptedArcanist->DespawnOrUnsummon(15s);

                            context.Schedule(3s + 449ms, [this](TaskContext context)
                            {
                                Creature* legionDemon = me->FindNearestCreatureWithOptions(20.0f, { .StringId = "legion_demon_woe_intro" });

                                if (!legionDemon)
                                    return;

                                DoCast(SPELL_CAMOUFLAGE);
                                me->RemoveAurasDueToSpell(SPELL_CORRUPTING_TOUCH);
                                legionDemon->GetMotionMaster()->MovePath(PATH_LEGION_DEMON, false);
                                context.Schedule(6s + 301ms, [this](TaskContext /*context*/)
                                {
                                    me->DespawnOrUnsummon();
                                });
                            });
                        });
                    });
                    instance->SetData(DATA_PEROTHARN_INTRO, DONE);
                    break;
                }
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

void AddSC_boss_peroth_arn()
{
    RegisterWellOfEternityCreatureAI(boss_peroth_arn);
}
