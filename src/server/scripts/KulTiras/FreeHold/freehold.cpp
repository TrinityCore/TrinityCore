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

#include "Creature.h"
#include "Player.h"
#include "ScriptedGossip.h"
#include "ScriptMgr.h"
#include "World.h"
#include "freehold.h"

enum FreeHoldTrashSpells
{
    ///Irontide Enforcer
    BrutalBackhand = 257246,
    ShateringToss = 274860,
    ///Irontide Mastiff
    CripplingBite = 257478,
    BestialWrath = 257476,
    ///Irontide Corsair
    PoisoningStrike = 257436,
    ///Irontide Crackshot
    AzeriteGranade = 258672,
    ///Irontide Bonesaw
    FilthyBlade = 258321,
    InfectedWound = 258323,
    HealingBalm = 257397,
    ///Blacktooth Brute
    EarthShaker = 257747,
    ///Cutwater Duelist
    DuelistDash = 274400,
    ///Irontide Oarsman
    SeaSpout = 258777,
    ///Bilge Rat Padfoot
    PlagueStep = 257775,
    ///Cutwater Knife Juggler
    RicochetingThrow = 272402,
    ///Vermin Trapper
    RatTraps = 274383,
    ///Soggy Shiprat
    ScabrousBite = 274555,
    ///BlacktoothKnuckleduster
    ShatteringBellow = 257732,
    ///Blacktooth Scrapper
    BlindRage = 257739,
    ///Cutwater Harpooner
    DraggingHarpoon = 272413, ///Casted by Irontide Crusher to
    ///Irontide Crusher
    BoulderThrow = 258181,
    GroundShatter = 258199,
    ///Irontide Officer
    OiledBlade = 257908,
    ///Irontide Ravager
    PainfulMotivation = 257899,
    LightningBolt = 259092,
    ///Irontide Stormcaller
    ThunderingSquall = 257736,
    ///Irontide Buccaneers
    BladeBarrage = 257870,
};

void AddSC_freehold()
{

}
