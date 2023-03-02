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

#include "blackrock_foundry.h"
#include "SpellAuraEffects.h"
Position const g_EncounterAddSpawns[2][3] =
{
    /// Left side
    {
        {127.299f, 3496.977f, 246.085f, 0.7516f},
        {127.599f, 3504.188f, 246.085f, 0.0054f},
        {130.231f, 3515.183f, 245.085f, 0.0368f}
    },
    /// Right side
    {
        {265.278f, 3515.901f, 246.551f, 2.2870f},
        {265.739f, 3520.793f, 246.551f, 3.0881f},
        {265.634f, 3527.234f, 246.551f, 3.2569f}
    }
};

Position const g_BellowsOperatorSpawns[2] =
{
    {272.4757f, 3591.769f, 246.4359f, 3.071f},
    {123.9306f, 3592.554f, 246.4359f, 0.106f}
};

Position const g_PrimalElementalistsSpawns[eFoundryDatas::MaxPrimalElementalists] =
{
    {195.6962f, 3423.204f, 267.0585f, 1.581610f},
    {202.3524f, 3422.990f, 267.0098f, 1.581610f},
    {242.0573f, 3459.246f, 266.6673f, 3.206762f},
    {149.9497f, 3461.144f, 267.3971f, 0.0f}
};

Position const g_PrimalElementalistsMoves[eFoundryDatas::MaxPrimalElementalists] =
{
    {181.700f, 3542.40f, 217.517f, 0.0f},
    {181.884f, 3519.69f, 217.381f, 0.0f},
    {211.403f, 3516.13f, 217.492f, 0.0f},
    {217.771f, 3546.35f, 217.408f, 0.0f}
};

Position const g_SecurityGuardSecondPhaseSpwan  = { 199.382f, 3467.203f, 266.286f, 1.619f };
Position const g_SecurityGuardSecondPhaseJump   = { 197.372f, 3498.752f, 217.844f, 1.552f };
