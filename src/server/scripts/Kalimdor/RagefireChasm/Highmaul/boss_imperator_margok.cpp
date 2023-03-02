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

# include "highmaul.h"
#include "CreatureTextMgr.h"

Position const g_GorianReaverPos = { 4026.755f, 8584.76f, 572.6546f, 3.138298f };

/// For position Z periodical check
float const g_MinAllowedZ = 560.0f;

Position const g_CenterPos = { 3917.63f, 8590.89f, 565.341f, 0.0f };

Position const g_VolatileAnomalyPos[eHighmaulDatas::MaxIntervalles] =
{
    { 3885.65f, 8557.80f, 565.34f, 0.747137f }, ///< Rune of Fortification
    { 3890.47f, 8628.17f, 565.34f, 5.375480f }  ///< Rune of Replication
};

Position const g_ChogallEventsPos[] =
{
    { 3986.499023f, 8590.89f,   568.160156f,    3.1415627f },   ///< Cho'gall spawn pos
    { 3953.253662f, 8590.89f,   565.339722f,    3.1415627f },   ///< Cho'gall end pos
    { 3917.63f,     8590.89f,   575.341f,       0.0f },         ///< Mar'gok levitating pos
    { 3921.533203f, 8664.4102f, 565.555603f,    4.554723f },     ///< Adds Spawn right
    { 3912.581543f, 8517.3955f, 565.555603f,    1.523083f },     ///< Adds Spawn left
};

void AddSC_boss_imperator_margok()
{
   
}
