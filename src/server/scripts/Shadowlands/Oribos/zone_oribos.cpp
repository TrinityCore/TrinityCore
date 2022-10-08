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

enum Oribos
{
    QUEST_INTO_THE_MAW = 59181,
    SCENE_ORIBOS_JUMP_INTO_MAW_PRK = 3000,
    SCENE_ORIBOS_TO_THE_MAW_SKYJUMP = 2812,
};

struct IntoTheMaw : public PlayerScript
{
public:
    IntoTheMaw() : PlayerScript("IntoTheMaw") { }

private:
    bool IntoMaw;

    void OnUpdate(Player* player, uint32 diff) override
    {
        if (!player->HasQuest(QUEST_INTO_THE_MAW) || player->getLevel() != 60)
            return;

        IntoMaw = false;

        if (player->IsFalling() && player->GetPositionZ() <= 5416.469f && player->GetAreaId() == 13499 && !IntoMaw)
        {
            IntoMaw = true;
            player->TeleportTo(2222, 4597.563f, 6775.574f, 4864.918f, 1.496f);
            //player->GetSceneMgr().PlaySceneByPackageId(SCENE_ORIBOS_JUMP_INTO_MAW_PRK);
        }
    }

    void OnUpdateArea(Player* player, uint32 /*newArea*/, uint32 /*oldArea*/)
    {
        if (player->GetAreaId() == 13437) //Ve'nari's Refuge
            if (player->GetQuestStatus(QUEST_INTO_THE_MAW) == QUEST_STATUS_INCOMPLETE)
            {
                player->ForceCompleteQuest(QUEST_INTO_THE_MAW);
                player->GetSceneMgr().PlaySceneByPackageId(SCENE_ORIBOS_TO_THE_MAW_SKYJUMP);
            }
    }
};

void AddSC_zone_oribos()
{
    RegisterPlayerScript(IntoTheMaw);
}
