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

#include "ScriptMgr.h"
#include "GameObject.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PetAI.h"
#include "razorfen_kraul.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"

enum SnufflenoseGopher
{
    NPC_SNUFFLENOSE_GOPHER       = 4781,
    GO_BLUELEAF_TUBBER           = 20920,
    ACTION_FIND_NEW_TUBBER       = 0,
    POINT_TUBBER                 = 0
};

struct npc_snufflenose_gopher : public CreatureScript
{
public:
    npc_snufflenose_gopher() : CreatureScript("npc_snufflenose_gopher") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetRazorfenKraulAI<npc_snufflenose_gopherAI>(creature);
    }

    struct npc_snufflenose_gopherAI : public PetAI
    {
        npc_snufflenose_gopherAI(Creature* creature) : PetAI(creature)
        {
            IsMovementActive = false;
        }

        void Reset() override
        {
            IsMovementActive = false;
            TargetTubberGUID.Clear();
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == POINT_MOTION_TYPE && id == POINT_TUBBER)
            {
                if (GameObject* go = ObjectAccessor::GetGameObject(*me, TargetTubberGUID))
                {
                    go->SetRespawnTime(5 * MINUTE);
                    go->Refresh();
                    go->RemoveFlag(GO_FLAG_INTERACT_COND);
                }

                IsMovementActive = false;
            }
            else
                PetAI::MovementInform(type, id);
        }

        void DoFindNewTubber()
        {
            std::list<GameObject*> tubbersInRange;
            GetGameObjectListWithEntryInGrid(tubbersInRange, me, GO_BLUELEAF_TUBBER, 40.0f);

            if (tubbersInRange.empty())
                return;

            tubbersInRange.remove_if([](GameObject* go)
            {
                return go->isSpawned() || !go->HasFlag(GO_FLAG_INTERACT_COND);
            });

            tubbersInRange.sort(Trinity::ObjectDistanceOrderPred(me));

            GameObject* nearestTubber = tubbersInRange.front();
            if (!nearestTubber)
                return;

            TargetTubberGUID = nearestTubber->GetGUID();

            // XFurry was wrong...
            me->GetMotionMaster()->MovePoint(POINT_TUBBER, nearestTubber->GetPositionX(),
                                                           nearestTubber->GetPositionY(),
                                                           nearestTubber->GetPositionZ());
            IsMovementActive = true;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!IsMovementActive)
                PetAI::UpdateAI(diff);
        }

        void DoAction(int32 action) override
        {
            if (action == ACTION_FIND_NEW_TUBBER)
                DoFindNewTubber();
        }

        bool IsMovementActive;
        ObjectGuid TargetTubberGUID;
    };
};

class spell_snufflenose_command : public SpellScriptLoader
{
    public:
        spell_snufflenose_command() : SpellScriptLoader("spell_snufflenose_command") { }

        class spell_snufflenose_commandSpellScript : public SpellScript
        {
            void HandleEffect(SpellEffIndex /*effIndex*/)
            {
                if (Creature* target = GetHitCreature())
                    if (target->GetEntry() == NPC_SNUFFLENOSE_GOPHER)
                        target->AI()->DoAction(ACTION_FIND_NEW_TUBBER);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_snufflenose_commandSpellScript::HandleEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_snufflenose_commandSpellScript();
        }
};

void AddSC_razorfen_kraul()
{
    new npc_snufflenose_gopher();
    new spell_snufflenose_command();
}
