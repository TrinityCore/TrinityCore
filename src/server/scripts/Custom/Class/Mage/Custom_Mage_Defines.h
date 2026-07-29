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

namespace Scripts::Custom::Mage
{
    namespace Spells
    {
        static constexpr uint32 ArcaneExplosion = 1449;
        static constexpr uint32 ArcaneMissiles = 5143;
        static constexpr uint32 ConcentrationBuff = 384379;

        static constexpr uint32 Frostbolt = 116;
        static constexpr uint32 FrostboltDamage = 228597;

        static constexpr uint32 FingersOfFrost = 44544;

        static constexpr uint32 FrozenOrb = 84714;
        static constexpr uint32 FrozenOrbDamage = 84721;

        static constexpr uint32 FrostfireBolt = 431044;

        static constexpr uint32 BrainFreeze = 190447;
        static constexpr uint32 BrainFreezeBuff = 190446;

        static constexpr uint32 Chilled = 205708;
        static constexpr uint32 ConeOfCold = 120;

        static constexpr uint32 IciclesBuff = 205473;
        static constexpr uint32 IciclesPassive = 1246832;
        static constexpr uint32 IciclesVisual1 = 214124;
        static constexpr uint32 IciclesVisual2 = 214125;
        static constexpr uint32 IciclesVisual3 = 214126;
        static constexpr uint32 IciclesVisual4 = 214127;
        static constexpr uint32 IciclesVisual5 = 214130;
        static constexpr uint32 IciclesTransform = 1222865;

        static constexpr uint32 GlacialSpike = 199786;
        static constexpr uint32 GlacialSpikeDamage = 228600;

        static constexpr uint32 Flurry = 44614;
        static constexpr uint32 FlurryDamage = 228596;
        static constexpr uint32 FlurryMissileDamage = 228354;

        static constexpr uint32 FingersOfFrostPassive = 112965;
        static constexpr uint32 FrostbitePassive = 1248825;
        static constexpr uint32 Freezing = 1221389;
        static constexpr uint32 FrostNova = 122;

        static constexpr uint32 IceBarrier = 11426;
        static constexpr uint32 IceBlock = 45438;
        static constexpr uint32 IceCold = 414658;

        static constexpr uint32 MasteryFreezeShatter = 1246752;
        static constexpr uint32 PiercingCold = 378919;
        static constexpr uint32 FrozenTouch = 205030;
        static constexpr uint32 EverlastingFrost = 385167;
        static constexpr uint32 PermafrostLances = 460590;
        static constexpr uint32 PermafrostLancesBuff = 455122;

        static constexpr uint32 RayOfFrostBonus = 208141;
        static constexpr uint32 RayOfFrostFingersOfFrost = 269748;

        static constexpr uint32 ShatterDamage = 1246949;
        static constexpr uint32 ShatterPassive = 1246769;

    }
}
