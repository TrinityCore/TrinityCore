/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2009-2011 MaNGOSZero <https://github.com/mangos/zero>
 * Copyright (C) 2011-2016 Nostalrius <https://nostalrius.org>
 * Copyright (C) 2016-2017 Elysium Project <https://github.com/elysium-project>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef MANGOS_DBCSTRUCTURE_H
#define MANGOS_DBCSTRUCTURE_H

#include "Common.h"
#include "DBCEnums.h"
#include "Path.h"
#include "SpellClassMask.h"

#include <map>
#include <set>
#include <vector>
#include <array>

// Structures using to access raw DBC data and required packing to portability

// GCC have alternative #pragma pack(N) syntax and old gcc version not support pack(push,N), also any gcc version not support it at some platform
#if defined(__GNUC__)
#pragma pack(1)
#else
#pragma pack(push,1)
#endif

struct AreaTriggerEntry
{
    uint32    id;                                           // 0
    uint32    mapid;                                        // 1
    float     x;                                            // 2
    float     y;                                            // 3
    float     z;                                            // 4
    float     radius;                                       // 5
    float     box_x;                                        // 6 extent x edge
    float     box_y;                                        // 7 extent y edge
    float     box_z;                                        // 8 extent z edge
    float     box_orientation;                              // 9 extent rotation by about z axis
};

struct AuctionHouseEntry
{
    uint32    houseId;                                      // 0        m_ID
    uint32    faction;                                      // 1        m_factionID
    uint32    depositPercent;                               // 2        m_depositRate
    uint32    cutPercent;                                   // 3        m_consignmentRate
    //char*     name[8];                                    // 4-11     m_name_lang
                                                            // 12 string flags
};

struct BankBagSlotPricesEntry
{
    uint32  ID;                                             // 0        m_ID
    uint32  price;                                          // 1        m_Cost
};

/*struct Cfg_CategoriesEntry
{
    uint32 Id1;                                             // 1        Unk id, diff from post-1.x
    uint32 Id2;                                             //          Unk id, diff from post-1.x
    char *categoryName[8];                                  //          m_name_lang
    uint32 categoryNameFlags;
}*/

/*struct Cfg_ConfigsEntry
{
    uint32 Id;                                              //          m_ID
    uint32 Type;                                            //          m_realmType (sent in RealmList packet)
    uint32 IsPvp;                                           //          m_playerKillingAllowed
    uint32 IsRp;                                            //          m_roleplaying
};*/

struct ChatChannelsEntry
{
    uint32  ChannelID;                                      // 0        m_ID
    uint32  flags;                                          // 1        m_flags
                                                            // 2        m_factionGroup
    char*   pattern[8];                                     // 3-10     m_name_lang
                                                            // 11 string flags
    //char*       name[8];                                  // 12-19    m_shortcut_lang
                                                            // 20 string flag
};

struct CharacterFacialHairStylesEntry
{
    uint32 RaceID;                                          // 0
    uint32 SexID;                                           // 1
    uint32 VariationID;                                     // 2
  //uint32 Geoset[6];                                       // 3-8
};

enum CharSectionFlags
{
    SECTION_FLAG_UNAVAILABLE = 0x01,
};

enum CharSectionType
{
    SECTION_TYPE_SKIN = 0,
    SECTION_TYPE_FACE = 1,
    SECTION_TYPE_FACIAL_HAIR = 2,
    SECTION_TYPE_HAIR = 3,
    SECTION_TYPE_UNDERWEAR = 4
};

struct CharSectionsEntry
{
    //uint32 Id;
    uint32 Race;
    uint32 Gender;
    uint32 BaseSection;
    uint32 VariationIndex;
    uint32 ColorIndex;
    //char* TexturePath[3];
    uint32 Flags;
    inline bool HasFlag(CharSectionFlags flag) const { return (Flags & flag) != 0; }
};

struct ChrClassesEntry
{
    uint32  ClassID;                                        // 0        m_ID
    //uint32 unk1;                                          // 1 unknown, all 1
    //uint32 flags;                                         // 2 unknown
    uint32  powerType;                                      // 3        m_DisplayPower
                                                            // 4        m_petNameToken
    char const* name[8];                                    // 5-12     m_name_lang
                                                            // 13 string flags
                                                            // 14       m_filename
    uint32  spellfamily;                                    // 15       m_spellClassSet
    //uint32 flags2;                                        // 16       m_flags (0x1 HasRelicSlot)
};

enum ChrRacesFlags
{
    CHRRACES_FLAGS_NOT_PLAYABLE = 0x01,
    CHRRACES_FLAGS_BARE_FEET    = 0x02,
    CHRRACES_FLAGS_CAN_MOUNT    = 0x04
};

struct ChrRacesEntry
{
    uint32      RaceID;                                     // 0        m_Id
    uint32      Flags;                                      // 1        m_flags
    uint32      FactionID;                                  // 2        m_factionId
                                                            // 3        m_ExplorationSoundId
    uint32      model_m;                                    // 4        m_MaleDisplayId
    uint32      model_f;                                    // 5        m_FemaleDisplayId
                                                            // 6        m_ClientPrefix
                                                            // 7        unused
    uint32      TeamID;                                     // 8        m_BaseLanguage (7-Alliance 1-Horde)
    uint32      creatureType;                               // 9        m_creatureType (blizzlike always 7-humanoid)
                                                            // 10       unused, all 836
                                                            // 11       unused, all 1604
    uint32      resSicknessSpellId;                         // 12       m_ResSicknessSpellId (blizzlike always 15007)
                                                            // 13       m_SplashSoundID
    uint32      startingTaxiMask;                           // 14
                                                            // 15       m_clientFileString
    uint32      CinematicSequence;                          // 16       m_cinematicSequenceId
    char*       name[8];                                    // 17-24    m_name_lang used for DBC language detection/selection
                                                            // 25 string flags
                                                            // 26-27    m_facialHairCustomization[2]
                                                            // 28       m_hairCustomization

    inline bool HasFlag(ChrRacesFlags flag) const { return !!(Flags & flag); }
};

/*struct CinematicCameraEntry
{
    uint32      id;                                         // 0        m_ID
    char*       filename;                                   // 1        m_model
    uint32      soundid;                                    // 2        m_soundID
    float       start_x;                                    // 3        m_originX
    float       start_y;                                    // 4        m_originY
    float       start_z;                                    // 5        m_originZ
    float       unk6;                                       // 6        m_originFacing
};*/

struct CinematicSequencesEntry
{
    uint32      Id;                                         // 0        m_ID
    //uint32      unk1;                                     // 1        m_soundID
    //uint32      cinematicCamera;                          // 2        m_camera[8]
};

struct CreatureDisplayInfoEntry
{
    uint32      Displayid;                                  // 0        m_ID
    uint32      ModelId;                                    // 1        m_modelID
                                                            // 2        m_soundID
    uint32      ExtendedDisplayInfoID;                      // 3        m_extendedDisplayInfoID -> CreatureDisplayInfoExtraEntry::DisplayExtraId
    float       scale;                                      // 4        m_creatureModelScale
                                                            // 5        m_creatureModelAlpha
                                                            // 6-8      m_textureVariation[3]
                                                            // 9        m_portraitTextureName
                                                            // 10       m_bloodID
                                                            // 11       m_NPCSoundID
};

struct CreatureDisplayInfoExtraEntry
{
    uint32      DisplayExtraId;                             // 0        m_ID CreatureDisplayInfoEntry::m_extendedDisplayInfoID
    uint32      Race;                                       // 1        m_DisplayRaceID
    //uint32    Gender;                                     // 2        m_DisplaySexID
    //uint32    SkinColor;                                  // 3        m_SkinID
    //uint32    FaceType;                                   // 4        m_FaceID
    //uint32    HairType;                                   // 5        m_HairStyleID
    //uint32    HairStyle;                                  // 6        m_HairColorID
    //uint32    BeardStyle;                                 // 7        m_FacialHairID
    //uint32    Equipment[10];                              // 8-17     m_NPCItemDisplay equipped static items EQUIPMENT_SLOT_HEAD..EQUIPMENT_SLOT_HANDS, client show its by self
    //char*                                                 // 18       m_BakeName CreatureDisplayExtra-*.blp
};

enum CreatureModelDataFlags
{
    CREATURE_MODEL_DATA_FLAGS_CAN_MOUNT = 0x00000080
};

struct CreatureModelDataEntry
{
    uint32_t ID;                                            // 0        m_ID
    uint32_t flags;                                         // 1        m_flags
    char* modelName;                                        // 2        m_modelName
    //uint32 sizeClass;                                     // 3        m_sizeClass
    float modelScale;                                       // 4        m_modelScale
    //uint32 blood;                                         // 5        m_blood
    //uint32 footprintTexture;                              // 6        m_footprintTexture
    //float footprintTextureLength;                         // 7        m_footprintTextureLength
    //float footprintTextureWidth;                          // 8        m_footprintTextureWidth
    //float footprintTextureScale;                          // 9        m_footprintTextureScale
    //uint32 foleyMaterial;                                 // 10       m_foleyMaterial
    //uint32 footstepShakeSize;                             // 11       m_footstepShakeSize
    //uint32 deathThudShakeSize;                            // 12       m_deathThudShakeSize
    //uint32 creatureSoundId                                // 13       m_soundId
    //float collisionWidth;                                 // 14       m_collisionWidth
    float collisionHeight;                                  // 15       m_collisionHeight

    inline bool HasFlag(CreatureModelDataFlags flag) const { return !!(flags & flag); }
};

struct CreatureFamilyEntry
{
    uint32    ID;                                           // 0
    float     minScale;                                     // 1
    uint32    minScaleLevel;                                // 2 0/1
    float     maxScale;                                     // 3
    uint32    maxScaleLevel;                                // 4 0/60
    uint32    skillLine[2];                                 // 5-6
    uint32    petFoodMask;                                  // 7
    char*     Name[8];
};

#define MAX_CREATURE_SPELL_DATA_SLOT 4

struct CreatureSpellDataEntry
{
    uint32    ID;                                           // 0        m_ID
    uint32    spellId[MAX_CREATURE_SPELL_DATA_SLOT];        // 1-4      m_spells[4]
    //uint32    availability[MAX_CREATURE_SPELL_DATA_SLOT]; // 4-7      m_availability[4]
};

enum CreatureTypeEntryFlags
{
    CREATURE_TYPE_ENTRY_FLAGS_IGNORED_TAB_TARGETING = 0x01 // Means do not include in tab targeting.
};

struct CreatureTypeEntry
{
    uint32    ID;                                           // 0        m_ID
    //char*   Name[8];                                      // 1-8      m_name_lang
                                                            // 9 string flags
    //uint32    flags;                                      // 10       m_flags

    //inline bool HasFlag(CreatureTypeEntryFlags flag) const { return !!(flags & flag); }
};

struct DurabilityCostsEntry
{
    uint32    Itemlvl;                                      // 0        m_ID
    uint32    multiplier[29];                               // 1-29     m_weaponSubClassCost m_armorSubClassCost
};

struct DurabilityQualityEntry
{
    uint32    Id;                                           // 0        m_ID
    float     quality_mod;                                  // 1        m_data
};

struct EmotesEntry
{
    uint32  Id;                                             // 0        m_ID
    //char*   Name;                                         // 1        m_EmoteSlashCommand
    //uint32  AnimationId;                                  // 2        m_AnimID
    uint32  Flags;                                          // 3        m_EmoteFlags
    uint32  EmoteType;                                      // 4        m_EmoteSpecProc (determine how emote are shown)
    uint32  UnitStandState;                                 // 5        m_EmoteSpecProcParam
    //uint32  SoundId;                                      // 6        m_EventSoundID
};

struct EmotesTextEntry
{
    uint32  Id;                                             //          m_ID
                                                            //          m_name
    uint32  textid;                                         //          m_emoteID
                                                            //          m_emoteText
};

struct FactionEntry
{
    uint32      ID;                                         // 0        m_ID
    int32       reputationListID;                           // 1        m_reputationIndex
    uint32      BaseRepRaceMask[4];                         // 2-5      m_reputationRaceMask
    uint32      BaseRepClassMask[4];                        // 6-9      m_reputationClassMask
    int32       BaseRepValue[4];                            // 10-13    m_reputationBase
    uint32      ReputationFlags[4];                         // 14-17    m_reputationFlags
    uint32      team;                                       // 18       m_parentFactionID
    std::string name[8];

    //char*       name[8];                                  // 19-26    m_name_lang
                                                            // 27 string flags
    //char*     description[8];                             // 28-35    m_description_lang
                                                            // 36 string flags

    // helpers

    int GetIndexFitTo(uint32 raceMask, uint32 classMask) const
    {
        for (int i = 0; i < 4; ++i)
        {
            if ((BaseRepRaceMask[i] == 0 || (BaseRepRaceMask[i] & raceMask)) &&
                (BaseRepClassMask[i] == 0 || (BaseRepClassMask[i] & classMask)))
                return i;
        }

        return -1;
    }

    bool CanHaveReputation() const
    {
        return reputationListID >= 0;
    }
};

struct FactionTemplateEntry
{
    uint32      ID;                                         // 0
    uint32      faction;                                    // 1
    uint32      factionFlags;                               // 2 specific flags for that faction
    uint32      ourMask;                                    // 3 if mask set (see FactionMasks) then faction included in masked team
    uint32      friendlyMask;                               // 4 if mask set (see FactionMasks) then faction friendly to masked team
    uint32      hostileMask;                                // 5 if mask set (see FactionMasks) then faction hostile to masked team
    uint32      enemyFaction[4];                            // 6-9
    uint32      friendFaction[4];                           // 10-13
    //-------------------------------------------------------  end structure

    // helpers
    bool IsFriendlyTo(FactionTemplateEntry const& entry) const
    {
        if (entry.faction)
        {
            for(uint32 i : enemyFaction)
                if (i  == entry.faction)
                    return false;
            for(uint32 i : friendFaction)
                if (i == entry.faction)
                    return true;
        }
        return (friendlyMask & entry.ourMask) || (ourMask & entry.friendlyMask);
    }
    bool IsHostileTo(FactionTemplateEntry const& entry) const
    {
        if (entry.faction)
        {
            for(uint32 i : enemyFaction)
                if (i  == entry.faction)
                    return true;
            for(uint32 i : friendFaction)
                if (i == entry.faction)
                    return false;
        }
        return (hostileMask & entry.ourMask) != 0;
    }
    bool IsHostileToPlayers() const { return (hostileMask & FACTION_MASK_PLAYER) !=0; }
    bool IsNeutralToAll() const
    {
        for(uint32 i : enemyFaction)
            if (i != 0)
                return false;
        return hostileMask == 0 && friendlyMask == 0;
    }
    bool IsContestedGuardFaction() const { return (factionFlags & FACTION_TEMPLATE_FLAG_CONTESTED_GUARD)!=0; }
};

struct GameObjectDisplayInfoEntry
{
    uint32      Displayid;                                  // 0        m_ID
    char* filename;                                         // 1        m_modelName
                                                            // 2-11     m_Sound
};

// All Gt* DBC store data for 100 levels, some by 100 per class/race
#define GT_MAX_LEVEL    100

struct ItemBagFamilyEntry
{
    uint32   ID;                                            // 0        m_ID
    //char*     name[8]                                     // 1-8      m_name_lang
    //                                                      // 9        name flags
};

struct ItemDisplayInfoEntry
{
    uint32      ID;
    uint32      randomPropertyChance;
};

struct ItemRandomPropertiesEntry
{
    uint32    ID;                                           // 0        m_ID
    char*     internalName;                                 // 1        m_Name
    uint32    enchant_id[3];                                // 2-4      m_Enchantment
                                                            // 5-6 unused, 0 only values, reserved for additional enchantments
    char*     nameSuffix[8];                                // 7-14     m_name_lang
                                                            // 15 string flags
};

struct ItemSetEntry
{
    //uint32    id                                          // 0        m_ID
    char*     name[8];                                      // 1-8      m_name_lang
                                                            // 9 string flags
    //uint32    itemId[17];                                 // 10-26    m_itemID
    uint32    spells[8];                                    // 27-34    m_setSpellID
    uint32    items_to_triggerspell[8];                     // 35-42    m_setThreshold
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_6_1
    uint32    required_skill_id;                            // 43       m_requiredSkill
    uint32    required_skill_value;                         // 44       m_requiredSkillRank
#endif
};

struct LiquidTypeEntry
{
    LiquidTypeEntry(uint32 id, uint32 liquidid, uint32 type, uint32 spellid) : Id(id), LiquidId(liquidid), Type(type), SpellId(spellid) {}
    LiquidTypeEntry() = default;
    uint32 Id;
    uint32 LiquidId;                                        // 23: Water; 29: Ocean; 35: Magma; 41: Slime; 47: Naxxramas - Slime.
    uint32 Type;                                            // 0: Magma; 2: Slime; 3: Water
    uint32 SpellId;
};

#define MAX_LOCK_CASE 8

struct LockEntry
{
    uint32      ID;                                         // 0        m_ID
    uint32      Type[MAX_LOCK_CASE];                        // 1-5      m_Type
    uint32      Index[MAX_LOCK_CASE];                       // 9-16     m_Index
    uint32      Skill[MAX_LOCK_CASE];                       // 17-24    m_Skill
    //uint32      Action[MAX_LOCK_CASE];                    // 25-32    m_Action
};

struct MailTemplateEntry
{
    uint32      ID;                                         // 0        m_ID
    char*       subject[8];                                 // 1-8      m_subject_lang
                                                            // 9 string flags
};

struct NamesProfanityEntry
{
    //uint32    ID;                                         // 0
    char const* Name;                                       // 1
};

struct NamesReservedEntry
{
    //uint32    ID;                                         // 0
    char const* Name;                                       // 1
};

struct QuestSortEntry
{
    uint32      id;                                         // 0        m_ID
    //char*       name[8];                                  // 1-8      m_SortName_lang
                                                            // 9 string flags
};

/*struct SkillLineCategoryEntry
{
    uint32    id;                                           // 0        m_ID
    char*     name[8];                                      // 1-8      m_name_lang
                                                            // 9 string flags
    uint32    displayOrder;                                 // 10       m_sortIndex
};*/

struct SkillRaceClassInfoEntry
{
    //uint32    id;                                         // 0        m_ID
    uint32    skillId;                                      // 1        m_skillID
    uint32    raceMask;                                     // 2        m_raceMask
    uint32    classMask;                                    // 3        m_classMask
    uint32    flags;                                        // 4        m_flags
    uint32    reqLevel;                                     // 5        m_minLevel
    //uint32    skillTierId;                                // 6        m_skillTierID
    //uint32    skillCostID;                                // 7        m_skillCostIndex
};

/*struct SkillTiersEntry{
    uint32    id;                                           // 0        m_ID
    uint32    skillValue[16];                               // 1-17     m_cost
    uint32    maxSkillValue[16];                            // 18-3     m_valueMax
};*/

struct SkillLineEntry
{
    uint32    id;                                           // 0        m_ID
    int32     categoryId;                                   // 1        m_categoryID
    //uint32    skillCostID;                                // 2        m_skillCostsID
    char*     name[8];                                      // 3-10     m_displayName_lang
                                                            // 11 string flags
    //char*     description[8];                             // 12-19    m_description_lang
                                                            // 20 string flags
    uint32    spellIcon;                                    // 21       m_spellIconID
};

struct SkillLineAbilityEntry
{
    uint32    id;                                           // 0, INDEX
    uint32    skillId;                                      // 1
    uint32    spellId;                                      // 2
    uint32    racemask;                                     // 3
    uint32    classmask;                                    // 4
    //uint32    racemaskNot;                                // 5 always 0 in 2.4.2
    //uint32    classmaskNot;                               // 6 always 0 in 2.4.2
    uint32    req_skill_value;                              // 7 for trade skill.not for training.
    uint32    forward_spellid;                              // 8
    uint32    learnOnGetSkill;                              // 9 can be 1 or 2 for spells learned on get skill
    uint32    max_value;                                    // 10
    uint32    min_value;                                    // 11
                                                            // 12-13, unknown, always 0
    uint32    reqtrainpoints;                               // 14
};

#define MAX_SPELL_REAGENTS 8
#define MAX_SPELL_TOTEMS 2

struct SpellCastTimesEntry
{
    uint32    ID;                                           // 0        m_ID
    int32     CastTime;                                     // 1        m_base
    //float     CastTimePerLevel;                           // 2        m_perLevel
    //int32     MinCastTime;                                // 3        m_minimum
};

struct SpellFocusObjectEntry
{
    uint32    ID;                                           // 0        m_ID
    //char*     Name[8];                                    // 1-8      m_name_lang
                                                            // 9 string flags
};

struct SpellCategoryEntry
{
    uint32    ID;                                           //          m_ID
    uint32    Flags;                                        //          m_flags
};

struct SpellRadiusEntry
{
    uint32    ID;                                           //          m_ID
    float     Radius;                                       //          m_radius
                                                            //          m_radiusPerLevel
    //float     RadiusMax;                                  //          m_radiusMax
};

struct SpellRangeEntry
{
    uint32    ID;                                           // 0        m_ID
    float     minRange;                                     // 1        m_rangeMin
    float     maxRange;                                     // 2        m_rangeMax
    //uint32  Flags;                                        // 3        m_flags
    //char*  Name[8];                                       // 4-11     m_displayName_lang
    //uint32 NameFlags;                                     // 12 string flags
    //char*  ShortName[8];                                  // 13-20    m_displayNameShort_lang
    //uint32 NameFlags;                                     // 21 string flags
};

struct SpellShapeshiftFormEntry
{
    uint32 ID;                                              // 0        m_ID
    //uint32 buttonPosition;                                // 1        m_bonusActionBar
    //char*  Name[8];                                       // 2-9      m_name_lang
    //uint32 NameFlags;                                     // 10 string flags
    uint32 flags1;                                          // 11       m_flags
    int32  creatureType;                                    // 12       m_creatureType <=0 humanoid, other normal creature types
    //uint32 unk1;                                          // 13       m_attackIconID
};

struct SpellDurationEntry
{
    uint32    ID;                                           //          m_ID
    int32     Duration[3];                                  //          m_duration, m_durationPerLevel, m_maxDuration
};

struct SpellItemEnchantmentEntry
{
    uint32      ID;                                         // 0        m_ID
    uint32      type[3];                                    // 1-3      m_effect[3]
    uint32      amount[3];                                  // 4-6      m_effectPointsMin[3]
    //uint32      amount2[3]                                // 7-9      m_effectPointsMax[3]
    uint32      spellid[3];                                 // 10-12    m_effectArg[3]
    char*       description[8];                             // 13-20    m_name_lang[8]
                                                            // 21 string flags
    uint32      aura_id;                                    // 22       m_itemVisual
    uint32      slot;                                       // 23       m_flags
};

struct StableSlotPricesEntry
{
    uint32 Slot;                                            //          m_ID
    uint32 Price;                                           //          m_cost
};

#define MAX_TALENT_RANK 5

struct TalentEntry
{
    uint32    TalentID;                                     // 0        m_ID
    uint32    TalentTab;                                    // 1        m_tabID (TalentTab.dbc)
    uint32    Row;                                          // 2        m_tierID
    uint32    Col;                                          // 3        m_columnIndex
    uint32    RankID[MAX_TALENT_RANK];                      // 4-8      m_spellRank
                                                            // 9-12 part of prev field
    uint32    DependsOn;                                    // 13       m_prereqTalent (Talent.dbc)
                                                            // 14-15 part of prev field
    uint32    DependsOnRank;                                // 16       m_prereqRank
                                                            // 17-18 part of prev field
    //uint32  needAddInSpellBook;                           // 19       m_flags also need disable higest ranks on reset talent tree
    uint32    DependsOnSpell;                               // 20       m_requiredSpellID req.spell
};

struct TalentTabEntry
{
    uint32  TalentTabID;                                    // 0        m_ID
    //char* name[8];                                        // 1-8      m_name_lang
    //uint32  nameFlags;                                    // 9 string flags
    //unit32  spellicon;                                    // 10       m_spellIconID
                                                            // 11       m_raceMask
    uint32  ClassMask;                                      // 12       m_classMask
    uint32  tabpage;                                        // 13       m_orderIndex
    //char* internalname;                                   // 14       m_backgroundFile
};

struct TaxiNodesEntry
{
    uint32    ID;                                           // 0        m_ID
    uint32    map_id;                                       // 1        m_ContinentID
    float     x;                                            // 2        m_x
    float     y;                                            // 3        m_y
    float     z;                                            // 4        m_z
    std::array<std::string, MAX_DBC_LOCALE> name{};         // 5-12     m_Name_lang
                                                            // 13 string flags
    uint32    MountCreatureID[2];                           // 14-15    m_MountCreatureID[2] horde[14]-alliance[15]
};

struct TaxiPathEntry
{
    uint32    ID;
    uint32    from;
    uint32    to;
    uint32    price;
};

struct TaxiPathNodeEntry
{
                                                            // 0        m_ID
    uint32    path;                                         // 1        m_PathID
    uint32    index;                                        // 2        m_NodeIndex
    uint32    mapid;                                        // 3        m_ContinentID
    float     x;                                            // 4        m_LocX
    float     y;                                            // 5        m_LocY
    float     z;                                            // 6        m_LocZ
    uint32    actionFlag;                                   // 7        m_flags
    uint32    delay;                                        // 8        m_delay
};

struct TransportAnimationEntry
{
    //uint32  Id;
    uint32  TransportEntry;
    uint32  TimeSeg;
    float   X;
    float   Y;
    float   Z;
    //uint32  MovementId;
};

struct WMOAreaTableEntry
{
    uint32 Id;                                              // 0        m_ID index
    int32 rootId;                                           // 1        m_WMOID used in root WMO
    int32 adtId;                                            // 2        m_NameSetID used in adt file
    int32 groupId;                                          // 3        m_WMOGroupID used in group WMO
    //uint32 field4;                                        // 4        m_SoundProviderPref
    //uint32 field5;                                        // 5        m_SoundProviderPrefUnderwater
    //uint32 field6;                                        // 6        m_AmbienceID
    //uint32 field7;                                        // 7        m_ZoneMusic
    //uint32 field8;                                        // 8        m_IntroSound
    uint32 Flags;                                           // 9        m_flags (used for indoor/outdoor determination)
    uint32 areaId;                                          // 10       m_AreaTableID (AreaTable.dbc)
    //char *Name[8];                                        //          m_AreaName_lang
    //uint32 nameFlags;
};

struct WorldMapAreaEntry
{
    //uint32  ID;                                           // 0        m_ID
    uint32  map_id;                                         // 1        m_mapID
    uint32  area_id;                                        // 2        m_areaID index (continent 0 areas ignored)
    //char* internal_name                                   // 3        m_areaName
    float   y1;                                             // 4        m_locLeft
    float   y2;                                             // 5        m_locRight
    float   x1;                                             // 6        m_locTop
    float   x2;                                             // 7        m_locBottom
};


#define MAX_WORLD_MAP_OVERLAY_AREA_IDX 4
// to implement [?]
struct WorldMapOverlayEntry
{
    uint32    ID;                                           // 0        m_ID
    //uint32    worldMapAreaId;                             // 1        m_mapAreaID (WorldMapArea.dbc)
    uint32    areatableID[MAX_WORLD_MAP_OVERLAY_AREA_IDX];  // 2-5      m_areaID
                                                            // 6        m_mapPointX
                                                            // 7        m_mapPointY
    //char* internal_name                                   // 8        m_textureName
                                                            // 9        m_textureWidth
                                                            // 10       m_textureHeight
                                                            // 11       m_offsetX
                                                            // 12       m_offsetY
                                                            // 13       m_hitRectTop
                                                            // 14       m_hitRectLeft
                                                            // 15       m_hitRectBottom
                                                            // 16       m_hitRectRight
};

struct WorldSafeLocsEntry
{
    uint32    ID;                                           // 0        m_ID
    uint32    map_id;                                       // 1        m_continent
    float     x;                                            // 2        m_locX
    float     y;                                            // 3        m_locY
    float     z;                                            // 4        m_locZ
    //char*   name[8]                                       // 5-12     m_AreaName_lang
                                                            // 13 string flags
};

// GCC have alternative #pragma pack() syntax and old gcc version not support pack(pop), also any gcc version not support it at some platform
#if defined(__GNUC__)
#pragma pack()
#else
#pragma pack(pop)
#endif

typedef std::set<uint32> SpellCategorySet;
typedef std::map<uint32,SpellCategorySet > SpellCategoriesStore;
typedef std::set<uint32> PetFamilySpellsSet;
typedef std::map<uint32,PetFamilySpellsSet > PetFamilySpellsStore;

// Structures not used for casting to loaded DBC data and not required then packing
struct TalentSpellPos
{
    TalentSpellPos() : talent_id(0), rank(0) {}
    TalentSpellPos(uint16 _talent_id, uint8 _rank) : talent_id(_talent_id), rank(_rank) {}

    uint16 talent_id;
    uint8  rank;
};

typedef std::map<uint32,TalentSpellPos> TalentSpellPosMap;

struct TaxiPathBySourceAndDestination
{
    TaxiPathBySourceAndDestination() : ID(0),price(0) {}
    TaxiPathBySourceAndDestination(uint32 _id,uint32 _price) : ID(_id),price(_price) {}

    uint32    ID;
    uint32    price;
};
typedef std::map<uint32,TaxiPathBySourceAndDestination> TaxiPathSetForSource;
typedef std::map<uint32,TaxiPathSetForSource> TaxiPathSetBySource;

struct TaxiPathNodePtr
{
    TaxiPathNodePtr() : i_ptr(nullptr) {}
    TaxiPathNodePtr(TaxiPathNodeEntry const* ptr) : i_ptr(ptr) {}

    TaxiPathNodeEntry const* i_ptr;

    operator TaxiPathNodeEntry const& () const { return *i_ptr; }
};

typedef Path<TaxiPathNodePtr,TaxiPathNodeEntry const> TaxiPathNodeList;
typedef std::vector<TaxiPathNodeList> TaxiPathNodesByPath;

#define TaxiMaskSize 8
typedef uint32 TaxiMask[TaxiMaskSize];
#endif
