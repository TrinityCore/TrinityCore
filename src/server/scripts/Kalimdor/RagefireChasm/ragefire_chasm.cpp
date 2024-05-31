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

#include "MotionMaster.h"
#include "Player.h"
#include "Position.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "ragefire_chasm.h"

enum RFCMisc
{
    PATH_RESCUED_1 = 6178805,
    PATH_RESCUED_2 = 6178806,
    PATH_RESCUED_3 = 6178807,

    POINT_INTRO    = 0
};

constexpr Position AdolescentFlameHoundIntro[4] =
{
    { -34.332058f, -53.474606f, -21.372412f },
    { -33.650555f, -53.704865f, -21.371508f },
    { -30.366037f, -39.565018f, -21.747667f },
    { -34.273827f, -37.673744f, -21.493523f }
};

// Areatrigger - 7966
struct at_rfc_cosmetic_intro : OnlyOnceAreaTriggerScript
{
public:
    at_rfc_cosmetic_intro() : OnlyOnceAreaTriggerScript("at_rfc_cosmetic_intro") { }

    bool TryHandleOnce(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
    {
        if (player->IsGameMaster())
            return false;

        Creature* adolescentFlameHound1 = player->FindNearestCreatureWithOptions(80.0f, { .StringId = "npc_adolescent_flame_hound_1" });
        Creature* adolescentFlameHound2 = player->FindNearestCreatureWithOptions(80.0f, { .StringId = "npc_adolescent_flame_hound_2" });
        Creature* adolescentFlameHound3 = player->FindNearestCreatureWithOptions(80.0f, { .StringId = "npc_adolescent_flame_hound_3" });
        Creature* adolescentFlameHound4 = player->FindNearestCreatureWithOptions(80.0f, { .StringId = "npc_adolescent_flame_hound_4" });

        if (!adolescentFlameHound1 || !adolescentFlameHound2 || !adolescentFlameHound3 || !adolescentFlameHound4)
            return false;

        adolescentFlameHound1->GetMotionMaster()->MovePoint(POINT_INTRO, AdolescentFlameHoundIntro[0]);
        adolescentFlameHound2->GetMotionMaster()->MovePoint(POINT_INTRO, AdolescentFlameHoundIntro[1]);
        adolescentFlameHound3->GetMotionMaster()->MovePoint(POINT_INTRO, AdolescentFlameHoundIntro[2]);
        adolescentFlameHound4->GetMotionMaster()->MovePoint(POINT_INTRO, AdolescentFlameHoundIntro[3]);

        return true;
    }
};

// 101163 - General Trigger 221 to Self
class spell_ragefire_chasm_general_trigger_221_to_self : public SpellScript
{
    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (GetCaster()->ToCreature()->HasStringId("npc_rescued_cage_1"))
            GetCaster()->ToCreature()->GetMotionMaster()->MovePath(PATH_RESCUED_1, false);
        else if (GetCaster()->ToCreature()->HasStringId("npc_rescued_cage_2"))
            GetCaster()->ToCreature()->GetMotionMaster()->MovePath(PATH_RESCUED_2, false);
       else if (GetCaster()->ToCreature()->HasStringId("npc_rescued_cage_3"))
            GetCaster()->ToCreature()->GetMotionMaster()->MovePath(PATH_RESCUED_3, false);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_ragefire_chasm_general_trigger_221_to_self::HandleDummy, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_ragefire_chasm()
{
    new at_rfc_cosmetic_intro();
    RegisterSpellScript(spell_ragefire_chasm_general_trigger_221_to_self);
}
