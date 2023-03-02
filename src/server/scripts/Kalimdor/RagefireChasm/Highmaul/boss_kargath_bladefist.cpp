/*
 * Copyright 2023 AzgathCore
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

#include "highmaul.h"
#include "Vehicle.h"

Position const g_TrashsSpawnPos = { 3427.1f, 7530.21f, 55.3383f, 0.965533f };
Position const g_VulgorMovePos = { 3449.81f, 7557.01f, 55.304f, 0.8995f };

Position const g_SorcererPos[2] =
{
    { 3452.08f, 7550.25f, 55.304f, 0.8995f },
    { 3441.68f, 7558.45f, 55.304f, 0.8995f }
};

Position const g_SorcererSecondPos[2] =
{
    { 3445.23f, 7575.57f, 55.30f, 0.235625f },
    { 3468.69f, 7557.72f, 55.30f, 1.708251f }
};

Position const g_ArenaStandsPos = { 3507.99f, 7629.20f, 65.43f, 2.466646f };

Position const g_HighmaulSweeperMoves[eHighmaulDatas::HighmaulSweeperCount][eHighmaulDatas::HighmaulSweeperMovesCount] =
{
    /// Right of Mar'gok
    {
        { 3448.05f, 7517.22f, 65.45f, 6.157836f },
        { 3465.95f, 7520.59f, 65.15f, 0.196663f },
        { 3487.64f, 7532.83f, 65.44f, 0.554020f },
        { 3503.33f, 7548.39f, 65.44f, 0.777640f },
        { 3513.44f, 7564.58f, 65.44f, 1.017186f },
        { 3521.71f, 7590.66f, 65.09f, 1.241025f },
        { 3521.19f, 7607.86f, 65.44f, 1.598777f },
        { 3514.75f, 7623.96f, 65.44f, 1.932571f },
        { 3507.99f, 7629.20f, 65.43f, 2.466646f }
    },
    /// Left of Mar'gok
    {
        { 3411.12f, 7546.78f, 65.44f, 1.558138f },
        { 3410.64f, 7564.97f, 65.01f, 1.559507f },
        { 3418.62f, 7590.24f, 65.45f, 1.241420f },
        { 3429.80f, 7608.05f, 65.44f, 1.025436f },
        { 3444.61f, 7621.95f, 65.42f, 0.774108f },
        { 3464.96f, 7634.39f, 65.44f, 0.538489f },
        { 3483.57f, 7637.60f, 65.44f, 0.157571f },
        { 3500.82f, 7634.95f, 65.44f, 6.122672f },
        { 3507.86f, 7629.08f, 65.41f, 5.608234f }
    }
};

Position const g_SweeperJumpPos[eHighmaulDatas::HighmaulSweeperCount][2] =
{
    /// Right of Mar'gok
    {
        { 3476.025f, 7551.327f, 55.2557f, float(M_PI) },
        { 3498.104f, 7575.722f, 55.2557f, float(M_PI) }
    },
    /// Left of Mar'gok
    {
        { 3436.589f, 7581.993f, 55.2557f, float(M_PI) },
        { 3457.199f, 7607.632f, 55.2557f, float(M_PI) }
    }
};

Position const g_DrunkenBileslingerSpawns[2] =
{
    { 3499.293f, 7642.336f, 67.58533f, 4.473204f },
    { 3512.144f, 7574.136f, 63.50087f, 2.765742f }
};

uint32 const g_CrowdEmotes[8] =
{
    Emote::EMOTE_ONESHOT_CHEER,     Emote::EMOTE_ONESHOT_EXCLAMATION,   Emote::EMOTE_ONESHOT_RUDE,  Emote::EMOTE_ONESHOT_ROAR,
    Emote::EMOTE_ONESHOT_CHICKEN,   Emote::EMOTE_ONESHOT_SHOUT,         Emote::EMOTE_ONESHOT_POINT, Emote::EMOTE_ONESHOT_SALUTE
};

Position const g_NewInstancePortalPos = { 3441.737f, 7547.819f, 55.30566f, 0.8291928f };

float const g_InArenaZ = 60.0f;
float const g_ArenaFloor = 55.30f;

void ResetAllPlayersFavor(Creature* source)
{
    if (source == nullptr)
        return;

    Map::PlayerList const& players = source->GetMap()->GetPlayers();
    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
    {
        if (Player* player = itr->GetSource())
            player->SetPower(Powers::POWER_ALTERNATE_POWER, 0);
    }
}

void AddSC_boss_kargath_bladefist()
{
   
}
