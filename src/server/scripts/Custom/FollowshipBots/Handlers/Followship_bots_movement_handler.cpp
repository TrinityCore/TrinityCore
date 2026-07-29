/*
 * This file is part of the Stefal WoW Project.
 * It is designed to work exclusively with the TrinityCore framework.
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
 * This code is provided for personal and educational use within the
 * Stefal WoW Project. It is not intended for commercial distribution,
 * resale, or any form of monetization.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "DBCEnums.h"
#include "Log.h"
#include "Map.h"

#include "Followship_bots_ai_base.h"
#include "Followship_bots_mgr.h"
#include "Followship_bots_utils.h"

#include "Followship_bots_battleground_handler.h"
#include "Followship_bots_events_handler.h"
#include "Followship_bots_movement_handler.h"
#include "Followship_bots_spells_handler.h"
#include "Followship_bots_warsong_gulch.h"
#include "Followship_bots_arathi_basin.h"

namespace FSBMovement
{
    void StopFollow(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return;

        if (bot->HasUnitState(UNIT_STATE_FOLLOW))
            bot->GetMotionMaster()->Remove(FOLLOW_MOTION_TYPE);

        baseAI->botMoveState = FSB_MOVE_STATE_STAY;
        bot->StopMoving();
        bot->GetMotionMaster()->Clear();
    }

    void ResumeFollow(Creature* bot, float followDistance, float followAngle)
    {
        if (!bot || !bot->IsAlive())
            return;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return;

        Player* player = FSBMgr::Get()->GetBotOwner(bot);

        if (!player)
            return;

        baseAI->botMoveState = FSB_MOVE_STATE_FOLLOWING;
        bot->GetMotionMaster()->Clear();
        bot->GetMotionMaster()->MoveFollow(player, followDistance, followAngle);
    }

    FSB_MovementStates GetBotMoveState(Creature* bot)
    {
        if (!bot || !bot->IsBot())
            return FSB_MOVE_STATE_IDLE;


        if (FSB_BaseAI* ai = dynamic_cast<FSB_BaseAI*>(bot->AI()))
            return ai->botMoveState;


        return FSB_MOVE_STATE_IDLE;
    }

    MovementGeneratorType GetMovementType(Unit* me)
    {
        if (!me)
            return IDLE_MOTION_TYPE;

        MotionMaster* mm = me->GetMotionMaster();
        if (!mm)
            return IDLE_MOTION_TYPE;

        return mm->GetCurrentMovementGeneratorType();
    }

    void HandleBattlegroundMovement(Creature* bot, uint32 type, uint32 id)
    {
        if (!bot || !bot->GetMap()->IsBattleground())
            return;

        FSB_BaseAI* ai = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!ai)
            return;

        if (ai->botHired)
            return;

        FSB_BattlegroundData* bgData = ai->GetBattlegroundData();
        if (!bgData)
            return;

        if (bgData->bgTypeId == BATTLEGROUND_WS || bgData->bgTypeId == BATTLEGROUND_WG_CTF)
        {
            FSBBattleground::WarsongGulch::OnMovementInform(bot, bgData, type, id);
        }
        else if (bgData->bgTypeId == BATTLEGROUND_AB || bgData->bgTypeId == BATTLEGROUND_DOM_AB || bgData->bgTypeId == BATTLEGROUND_AB_CS || bgData->bgTypeId == BATTLEGROUND_BRAWL_AB2)
        {
            FSBBattleground::ArathiBasin::OnMovementInform(bot, bgData, type, id);
        }
    }

    void BotSetMountedState(Creature* bot, bool& botMounted)
    {
        if (!bot || !bot->IsAlive())
            return;

        if (bot->HasUnitState(UNIT_STATE_CASTING))
            return;

        Player* player = FSBMgr::Get()->GetBotOwner(bot);

        if (!player)
            return;

        FSB_Class cls = FSBMgr::Get()->GetBotClassForEntry(bot->GetEntry());

        if (player->HasAuraType(SPELL_AURA_MOUNTED) && !botMounted)
        {
            uint32 randomSpell = FSBSpellsUtils::GetRandomMountSpellForBot(bot);
            
            if (cls == FSB_Class::Warlock)
            {
                std::vector<uint32> warlockMounts =
                {
                    randomSpell,
                    SPELL_WARLOCK_FELSTEED,
                    SPELL_WARLOCK_DREADSTEED
                };

                uint32 spellId = warlockMounts[urand(0, warlockMounts.size() - 1)];
                if (FSBSpells::BotCastSpell(bot, spellId, bot))
                    botMounted = true;
            }
            else if (cls == FSB_Class::Paladin)
            {
                std::vector<uint32> paladinMounts =
                {
                    randomSpell,
                    SPELL_PALADIN_CHARGER,
                    SPELL_PALADIN_WARHORSE
                };

                uint32 spellId = paladinMounts[urand(0, paladinMounts.size() - 1)];
                if (FSBSpells::BotCastSpell(bot, spellId, bot))
                {
                    botMounted = true;
                    FSBEvents::ScheduleBotEvent(bot, FSB_EVENT_HIRED_MOUNT_AURA, 3s, 5s);
                }
            }
            else if (cls == FSB_Class::Druid)
            {
                std::vector<uint32> druidMounts =
                {
                    randomSpell,
                    SPELL_DRUID_TRAVEL
                };

                bot->RemoveAurasByType(SPELL_AURA_MOD_SHAPESHIFT);

                uint32 spellId = druidMounts[urand(0, druidMounts.size() - 1)];
                if (FSBSpells::BotCastSpell(bot, spellId, bot))
                {
                    botMounted = true;
                    if (spellId == SPELL_DRUID_TRAVEL)
                    {
                        //bot->SetDisplayId(65133, false);
                    }
                }
            }
            else
            {
                if (cls == FSB_Class::Shaman && bot->HasAura(SPELL_SHAMAN_GHOST_WOLF))
                    bot->RemoveAurasDueToSpell(SPELL_SHAMAN_GHOST_WOLF);

                if (FSBSpellsUtils::CastRandomMountLevelSpell(bot))
                    botMounted = true;
            } 
        }
        else if (!player->HasAuraType(SPELL_AURA_MOUNTED) && botMounted)
        {
            botMounted = false;
            bot->Dismount();
            bot->RemoveAurasByType(SPELL_AURA_MOUNTED);
            bot->RemoveAurasDueToSpell(SPELL_PALADIN_CRUSADER_AURA);
            if(cls == FSB_Class::Druid)
            {
                auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
                bot->RemoveAurasByType(SPELL_AURA_MOD_SHAPESHIFT);
                bot->RemoveAurasDueToSpell(SPELL_DRUID_TRAVEL);
                baseAI->botRole = FSB_ROLE_NONE;

            }
        }
    }

    void BotHandleReturnMovement(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return;

        Player* owner = FSBMgr::Get()->GetBotOwner(bot);

        if (!baseAI->botHired || !owner)
        {
            bot->GetMotionMaster()->Clear();
            bot->ClearUnitState(UNIT_STATE_FOLLOW | UNIT_STATE_CHASE | UNIT_STATE_ROAMING);

            TC_LOG_DEBUG("scripts.fsb.movement", "FSB: BotHandleReturnMovement bot {} does not have owner so it is set to Idle", bot->GetName());
            return;
        }

        if (baseAI->botMoveState != FSB_MOVE_STATE_STAY)
        {
            if (bot->HasUnitState(UNIT_STATE_CHASE))
                bot->GetMotionMaster()->Remove(CHASE_MOTION_TYPE);

            bot->GetMotionMaster()->Clear();
            bot->GetMotionMaster()->MoveFollow(owner, baseAI->botFollowDistance, baseAI->botFollowAngle);

            TC_LOG_DEBUG("scripts.fsb.movement", "FSB: BotHandleReturnMovement bot {} has owner so it is set to Follow", bot->GetName());

        }
    }

    bool EnsureInRange(Creature* bot, Unit* target)
    {
        if (!bot || !target || !target->IsAlive())
            return false;

        // STAY mode bots should only attack if already in range - do not chase
        if (auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI()))
        {
            if (baseAI->botMoveState == FSB_MOVE_STATE_STAY)
                return false;

            if (baseAI->botGenericData.pauseCombatChase)
                return false;
        }

        MotionMaster* mm = bot->GetMotionMaster();
        if (!mm)
            return false;

        // If already chasing, nothing to do
        if (mm->GetCurrentMovementGeneratorType() == CHASE_MOTION_TYPE)
            return true;

        float requiredRange = FSBCombatUtils::GetBotChaseDistance(bot);

        mm->Clear();
        bot->ClearUnitState(UNIT_STATE_FOLLOW | UNIT_STATE_CHASE);

        // Bots with ranged attacks should not care about the chase angle at all.
        float angle = requiredRange == 2.f ? float(M_PI) : frand(-2.f, 2.f);
        float tolerance = requiredRange == 0.f ? float(M_PI_4) : float(M_PI * 2);
        mm->MoveChase(target, ChaseRange(0.f, requiredRange), ChaseAngle(angle, tolerance));

        TC_LOG_DEBUG("scripts.fsb.movement", "FSB: EnsureInRange Bot {} chase resumed for {} @ {:.1f} yd", bot->GetName(), target->GetName(), requiredRange);

        return true;
    }

    bool EnsureInRange(Creature* bot, Unit* target, float range)
    {
        if (!bot || !target || !target->IsAlive())
            return false;

        // STAY mode bots should only attack if already in range - do not chase
        if (auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI()))
        {
            if (baseAI->botMoveState == FSB_MOVE_STATE_STAY)
                return false;

            if (baseAI->botGenericData.pauseCombatChase)
                return false;
        }

        MotionMaster* mm = bot->GetMotionMaster();
        if (!mm)
            return false;

        // If already chasing, nothing to do
        if (mm->GetCurrentMovementGeneratorType() == CHASE_MOTION_TYPE)
            return true;

        mm->Clear();
        bot->ClearUnitState(UNIT_STATE_FOLLOW | UNIT_STATE_CHASE);

        // Bots with ranged attacks should not care about the chase angle at all.
        float angle = range == 2.f ? float(M_PI) : frand(-2.f, 2.f);
        float tolerance = range == 0.f ? float(M_PI_4) : float(M_PI * 2);
        mm->MoveChase(target, ChaseRange(0.f, range), ChaseAngle(angle, tolerance));

        TC_LOG_DEBUG("scripts.fsb.movement", "FSB: EnsureInRange for spell Bot {} chase resumed for {} @ {:.1f} yd", bot->GetName(), target->GetName(), range);

        return true;
    }
}
