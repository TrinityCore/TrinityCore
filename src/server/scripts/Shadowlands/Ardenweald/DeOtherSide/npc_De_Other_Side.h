
/*
 * Copyright 2021 Thordekk
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
#include "Player.h"
#include "InstanceScript.h"
#include "objects_De_Other_Side.h"
#include "boss_dealer_xyexa.cpp"
#include "boss_hakkar_the_soulflayer_os.cpp"
#include "boss_muehzala.cpp"
#include "boss_the_manastorms.cpp"

enum Creatures
{

 NPC_Hakkar_the_Soulflayer             = 166473,
 NPC_Millificent_Manastorm             = 101976,
 NPC_Muehzala                          = 169769,
 NPC_4.RF_4.RF                         = 167964,
 NPC_Ancient_Kodo                      = 151843,
 NPC_Ancient_Swoop                     = 151846,
 NPC_Atalai_Deathwalker                = 170480,
 NPC_Atalai_Deathwalkers_Spirit        = 170483,
 NPC_Atalai_Devoted                    = 170486,171333,
 NPC_Atalai_High_Priest                = 170490,
 NPC_Atalai_Hoodoo_Hexxer              = 170572,
 NPC_Bladebeak_Hatchling               = 171341,
 NPC_Bladebeak_Matriarch               = 171343,
 NPC_Bwonsamdi                         = 166281,168141,171472,
 NPC_Dealer_Xyexa                      = 164450,
 NPC_Death_Speaker                     = 168942,
 NPC_Defunct_Dental_Drill              = 167962,
 NPC_Doomguard                         = 168932,
 NPC_Enraged_Mask                      = 169912,
 NPC_Enraged_Spirit                    = 168934,
 NPC_Ethereal_Transmorpher             = 149596,
 NPC_Experimental_Sludge               = 167966,
 NPC_Felguard                          = 169421,
 NPC_Felhound                          = 169425,
 NPC_Fleeting_Memory                   = 175581,
 NPC_Gormling                          = 175665,
 NPC_Gravid_Devourer_Mite              = 175692,
 NPC_Hakkar_the_Soulflayer             = 164558,
 NPC_Headless_Client                   = 167963,
 NPC_Infernal                          = 169426,
 NPC_Juvenile_Runestag                 = 171342,
 NPC_Lubricator                        = 167965,
 NPC_Manifestation_of_Pride            = 173729,
 NPC_Mask_of_Bwonsamdi                 = 174327,
 NPC_Meikothe_Clutch_Guardian          = 173458,
 NPC_Merchant_Maku                     = 142668,
 NPC_Millhouse Manastorm               = 164556,
 NPC_Millificent_Manastorm             = 164555,
 NPC_Muehzala                          = 166608,
 NPC_Mythresh_Skys_Talons              = 171184,
 NPC_Nathrian_Inquisitor               = 175513,
 NPC_Risen_Bonesoldier                 = 168949,
 NPC_Risen_Cultist                     = 168992,
 

