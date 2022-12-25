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

#include "antorus.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum eSays
{
    //Admiral
    SAY_AGGRO = 0,
    //Trigger "Admiral in Capsule"
    SAY_FUSILLADE = 0,
    //Trigger "Engineer in Capsule"
    SAY_ENTROPIC_MINE = 0,
    //Trigger "General in Capsule"
    SAY_SUMMON_REINFORCEMENTS = 0,
    //Capsule
    SAY_LEAVE_CAPSULE = 0,
    SAY_WARN_PLAYER = 1,
    //Cruiser
    SAY_WARN_FUSILLADE = 0,
};

enum Spells
{
    SPELL_OUTRO_CONV = 249154,
    SPELL_HOLOGRAM_SPAWN_VISUAL = 253589,
    SPELL_POD_SPAWN_COSMETIC_FILTER = 245785,
    SPELL_POD_SPAWN_COSMETIC = 245777,
    SPELL_POD_RETREAT_COSMETIC = 245793, //Visual Back to Capsule
    SPELL_BOSS_VISUAL_SPAWN = 232302,
    SPELL_ZERO_ENERGY_REGEN = 72242,
    SPELL_ENERGY_FILL = 258032,
    SPELL_SHARED_HEALTH = 244103,
    SPELL_ASSUME_COMMAND = 245227,
    SPELL_HIDE_MODEL = 245212,
    SPELL_ENERGY_DRAIN = 258033,
    SPELL_DAILY_ESSENCE_ANTORAN = 305309,
    //Bosses
    SPELL_EXPLOIT_WEAKNESS = 244892,
    SPELL_SUMMON_SHADOW_AT = 256436,
    SPELL_SHOCK_GRENADE_FILTER = 244722, //Mythic
    SPELL_SHOCK_GRENADE = 244729,
    SPELL_SHOCK_GRENADE_MARK = 244737,
    SPELL_SHOCKED = 244748,
    //Engineer
    SPELL_ENTROPIC_MINE_FILTER = 245304,
    SPELL_ENTROPIC_MINE_MISSILE = 245159,
    SPELL_ENTROPIC_MINE_VIS_SPAWN = 257262,
    SPELL_ENTROPIC_MINE_VISUAL = 246601,
    SPELL_ENTROPIC_BLAST = 245121,
    SPELL_ENTROPIC_BLAST_DOT = 253290,
    //General
    SPELL_SUMMON_REINFORCEMENTS = 245546,
    SPELL_SPAWN_VISUAL = 254363,
    SPELL_PYROBLAST_FILTER = 246507,
    SPELL_PYROBLAST = 246505,
    SPELL_DEMONIC_CHARGE_FILTER = 253036,
    SPELL_DEMONIC_CHARGE = 253040,
    SPELL_BLADESTORM = 253038,
    //Capsule
    SPELL_ENTER_VEH_CAPSULE = 244141, //Ride veh
    SPELL_PSYCHIC_ASSAULT = 244172,
    SPELL_PSYCHIC_SCARRING = 244388, //Heroic - 3min
    SPELL_PSYCHIC_SCARRING_PERM = 253306, //Mythic - permanent
    SPELL_WITHERING_FIRE_MISSILE = 245033,
    SPELL_WITHERING_FIRE_VISUAL = 245085,
    SPELL_PLR_CHAOS_PULSE_MISSILE = 244419,
    SPELL_FELSHIELD_EMITTER = 255140,
    SPELL_FELSHIELD_EMITTER_SUM = 244902,
    SPELL_ACTIVATE_FELSHIELD = 244907,
    SPELL_FELSHIELD_AT = 244909,
    SPELL_DISRUPTOR_BEACON = 255147,
    SPELL_DISRUPTOR_BEACON_SUM = 245174,
    SPELL_DISRUPTION_FIELD = 254771,
    SPELL_EXTRACT_INTERLOPER = 254130, //Mythic
    SPELL_SUMMON_MYTHIC_BATS_PERIODIC = 254133,
    //Trigger generic in Capsule
    SPELL_CHAOS_PULSE_FILTER = 257976,
    SPELL_CHAOS_PULSE_MARK = 257977,
    SPELL_CHAOS_PULSE_MISSILE = 257973,
    //Admiral in Capsule
    SPELL_CRUISER_FUSILLADE = 244625,
    SPELL_CRUISER_FUSILLADE_MISSILE = 244626,
    SPELL_CRUISER_FUSILLADE_DMG = 244627,
    SPELL_ADMIRAL_FUSILLADE = 257257,
    SPELL_ZEROING_IN = 244696,
};

enum eEvents
{
    //Event Manager
    EVENT_CHAOS_PULSE = 1,
    EVENT_ENTROPIC_MINE = 2,
    EVENT_SUMMON_REINFORCEMENTS = 3,
    EVENT_CRUISER_FUSILLADE = 4,
    //Bosses
    EVENT_EXPLOIT_WEAKNESS = 1,
    EVENT_SHOCK_GRENADE = 2,
    EVENT_CHECK_VICTIM = 3
};

enum eActions
{
    ACTION_ENCOUNTERS_SUMMON = 1,
    ACTION_ENCOUNTERS_RESTART,
    ACTION_ENCOUNTERS_ENTER_COMBAT,
    ACTION_SWITCH_STAGE,
    ACTION_ACTIVATE_BOSS_EVENTS,
    ACTION_ACTIVATE_CAPSULE = 1,
    ACTION_DEACTIVATE_CAPSULE = 2
};

enum eMisc
{
    STAGE_ADMIRAL = 0,
    STAGE_ENGINEER = 1,
    STAGE_GENERAL = 2,
    INVISIBLE_MODEL = 27823,
    //SMSG_SET_AI_ANIM_KIT
    ANIM_OPEN_CAPSULE = 8810,
    ANIM_CLOSE_CAPSULE = 0
};

uint32 const commandEntry[9] =
{
    //Bosses
    NPC_ADMIRAL_SVIRAX,
    NPC_CHIEF_ENGINEER_ISHKAR,
    NPC_GENERAL_ERODUS,
    //Capsule
    NPC_ADMIRAL_POD,
    NPC_ENGINEER_POD,
    NPC_GENERAL_POD,
    //Trigger Boss in Capsule
    NPC_ADMIRAL_SVIRAX_IN_POD,
    NPC_ENGINEER_ISHKAR_IN_POD,
    NPC_GENERAL_ERODUS_IN_POD
};

Position const commandPos[9] =
{
    //Bosses
    {-2810.50f, 10880.8f, 139.57f, 4.09f}, //Admiral
    {-2809.74f, 10829.3f, 139.75f, 2.05f}, //Engineer
    {-2859.64f, 10864.8f, 139.74f, 5.93f}, //General
    //Capsule
    {-2797.72f, 10898.5f, 139.47f, 4.08f}, //Admiral capsule
    {-2798.11f, 10812.0f, 139.38f, 2.16f}, //Engineer capsule
    {-2880.24f, 10870.2f, 139.75f, 6.02f}, //General capsule
    //Trigger Bosses in Capsule
    {-2796.28f, 10901.6f, 155.90f, 4.10f}, //Trigger Admiral in capsule
    {-2796.91f, 10809.7f, 155.90f, 2.13f}, //Trigger Engineer in capsule
    {-2883.30f, 10870.7f, 155.90f, 6.06f}  //Trigger General in capsule
};

Position const fusilladePos[12] =
{
    {-2787.93f, 10830.80f, 139.62f},
    {-2819.56f, 10822.47f, 139.62f},
    {-2796.53f, 10862.35f, 139.62f},
    {-2839.66f, 10834.07f, 139.62f},
    {-2828.15f, 10854.02f, 139.62f},
    {-2816.64f, 10873.96f, 139.62f},
    {-2805.12f, 10893.90f, 139.62f},
    {-2859.77f, 10845.68f, 139.62f},
    {-2848.26f, 10865.63f, 139.62f},
    {-2836.74f, 10885.57f, 139.62f},
    {-2879.88f, 10857.29f, 139.62f},
    {-2868.36f, 10877.23f, 139.62f}
};

enum Miscs
{
    EVENT_1 = 1,
    EVENT_2,
    EVENT_3,
};

void AddSC_boss_antoran()
{
   
}
