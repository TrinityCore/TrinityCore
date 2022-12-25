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

#include "AreaTriggerAI.h"
#include "tomb_of_sargeras.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    //Engine of Souls
    SAY_ENGINE_AGGRO = 0,
    SAY_TORMENTED_CRIES = 0, //Trigger Talk
    SAY_WARN_SPEAR_OF_ANGUISH = 1,

    //The Desolate Host
    SAY_HOST_AGGRO = 0,
    SAY_HOST_DEATH = 1,

    //Soul Queen Dejahna
    SAY_QUEEN_AGGRO = 0,
    SAY_SOULBIND = 1,
    SAY_WARN_SOULBIND = 2,
    SAY_WARN_WAILING_SOULS = 3,
    SAY_WAILING_SOULS = 4,
    SAY_QUEEN_DEATH = 5,

    //Generic owner
    SAY_PHASE_2 = 0,
};

enum Spells
{
    SPELL_SPIRITUAL_FONT_REAL = 241576,
    SPELL_SPIRITUAL_FONT_SPIRIT = 241577,
    SPELL_SOUL_TRANSFER = 240851,
    SPELL_SPIRITUAL_BARRIER_VIS_REAL = 235113, //Only has trash and pets player in Real world
    SPELL_SPIRITUAL_BARRIER_VIS_SPIRIT = 235620, //Only has trash and pets player in Spirit world
    SPELL_SPIRITUAL_BARRIER_SPIRIT_REALM = 235732, //Spirit world - Phase 8308
    SPELL_SPIRITUAL_BARRIER_REAL_REALM = 235734, //Real world - Phase 8309
    SPELL_SPIRIT_REALM = 235621,
    SPELL_SWIRLING_SOULS_VISUAL = 241645,
    SPELL_SHARED_HEALTH = 236963,
    SPELL_CORPOREAL_REALM_REMOVE = 235590,
    SPELL_SPIRIT_PRESENCE_AT = 235589,
    SPELL_BERSERK = 47008,

    SPELL_QUIETUS = 236595,
    SPELL_QUIETUS_DMG = 236507,
    SPELL_QUIETUS_MOD = 236678,

    //Heroic+
    SPELL_DISSONANCE_REAL_FILTER = 239014,
    SPELL_DISSONANCE_SPIRIT_FILTER = 239015,
    SPELL_DISSONANCE_REAL = 239006,
    SPELL_DISSONANCE_SPIRIT = 239007,

    //Mythic
    SPELL_BOUND_ESSENCE_AURA = 236351,
    SPELL_BOUND_ESSENCE_MISSILE = 238580,

    //Engine of Souls
    SPELL_BONE_SHARDS = 236142,
    SPELL_COLLAPSING_FISSURE_FILTER = 235885,
    SPELL_COLLAPSING_FISSURE_MISSILE = 235889,
    SPELL_COLLAPSING_FISSURE_AT = 235890,
    SPELL_TORMENTED_CRIES_CHANNEL = 238570,
    SPELL_TORMENTED_CRIES_SUMMON = 236065,
    SPELL_TORMENTED_CRIES_MARK = 238018,
    SPELL_TORMENTED_CRIES_FILTER = 235988,
    SPELL_TORMENTED_CRIES_AT = 235989,
    SPELL_SPEAR_OF_ANGUISH_FILTER = 235923, //Heroic+
    SPELL_SPEAR_OF_ANGUISH_MARK = 235924,
    SPELL_SPEAR_OF_ANGUISH_HEAL_ABSORB = 238442,

    //Reanimated Templar
    SPELL_RUPTURING_SLAM_AT = 235927,
    SPELL_BONECAGE_ARMOR = 236513,

    //Ghastly Bonewarden
    SPELL_SHADOW_CHANNELLING = 173746,
    SPELL_GRASPING_DARKNESS = 235968,

    //Soul Queen Dejahna
    SPELL_CRUSH_MIND = 241566,
    SPELL_SOULBIND = 236449,
    SPELL_SOULBIND_DUMMY = 236459,
    SPELL_SOULBIND_FIND_PLAYER = 236465,
    SPELL_SOULBIND_DMG = 236464,
    SPELL_SOULBIND_VISUAL_FIND_SPIRIT = 245611, //Find player on the Spirit world
    SPELL_SOULBIND_VISUAL_FIND_REAL = 245612, //Find player on the Real world
    SPELL_WAILING_SOULS = 236072,
    SPELL_WITHER = 236131, //Heroic+
    SPELL_WITHER_2 = 236138,

    //Fallen Priestess
    SPELL_SOUL_REND = 229231,
    SPELL_SHATTERING_SCREAM = 235969,
    SPELL_SHATTERING_SCREAM_EXPLOSION = 236772,
    SPELL_SPIRIT_CHAINS = 236361,

    //Soul Residue
    SPELL_FIXATE = 238459,
    SPELL_SOUL_ROT_AT = 236235,
    SPELL_SOUL_ERUPTION = 236158,
    SPELL_SOUL_ERUPTION_TRANSFORM = 236160, //Change model
    SPELL_UNRELENTING = 221419,

    //The Desolate Host
    SPELL_SUNDERING_DOOM = 236542,
    SPELL_DOOMED_SUNDERING = 236544,
    SPELL_TORMENT = 236548,
};

enum eEvents
{
    //Engine of Souls
    EVENT_COLLAPSING_FISSURE = 1,
    EVENT_TORMENTED_CRIES = 2,
    EVENT_SPEAR_OF_ANGUISH = 3, //Heroic+

    //Soul Queen Dejahna
    EVENT_WAILING_SOULS = 1,
    EVENT_SOULBIND = 2,
    EVENT_WITHER = 3,
    EVENT_WITHER_2 = 4,

    //The Desolate Host
    EVENT_SUNDERING_DOOM = 1,
    EVENT_DOOMED_SUNDERING = 2,
};

enum eMisc
{
    //SMSG_PLAY_SPELL_VISUAL_KIT
    VISUAL_KIT_1 = 82907,
    VISUAL_KIT_2 = 64342,
};

uint32 const bossEntry[3] =
{
    NPC_ENGINE_OF_SOULS,
    NPC_SOUL_QUEEN_DEJAHNA,
    NPC_DESOLATE_HOST
};

Position const centrPos = { 6438.45f, -1089.73f, 2881.52f };

Position const BossPos[3] =
{
    {6456.64f, -1105.83f, 2881.60f, 2.50f}, //118460 - NPC_ENGINE_OF_SOULS
    {6461.07f, -1088.02f, 2881.60f, 2.73f}, //118462 - NPC_SOUL_QUEEN_DEJAHNA
    {6447.46f, -1099.68f, 2881.60f, 2.49f}  //119072 - NPC_DESOLATE_HOST
};

enum Misc
{
    ACTION_1 = 1,
    ACTION_2,
    ACTION_3,
    ACTION_4,
    ACTION_5,

    EVENT_1,
    EVENT_2,
};

void AddSC_boss_desolate_host()
{
   
}
