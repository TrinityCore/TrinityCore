/*
* Copyright 2021 OriginsCore
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

#include "Conversation.h"
#include "Creature.h"
#include "DatabaseEnv.h"
#include "DBCEnums.h"
#include "MapManager.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptedGossip.h"
#include "ScriptMgr.h"
#include "World.h"
#include "WorldSession.h"
#include "Chat.h"
#include "SharedDefines.h"
#include "SpellAuras.h"

class playerscript_recruiter : public PlayerScript
{
public:
    playerscript_recruiter() : PlayerScript("playerscript_recruiter") {}

    void OnLevelChanged(Player* player, uint8 /*oldLevel*/) override
    {
        if (player->GetLevel() != MAX_LEVEL)
            return;

        QueryResult result = LoginDatabase.PQuery("SELECT recruiter, recruiter_rewarded FROM account WHERE id = %u", player->GetSession()->GetAccountId());
        if (!result)
            return;

        Field* fields           = result->Fetch();
        uint32 recruiter        = fields[0].GetUInt32();
        bool recruiterRewarded  = fields[1].GetBool();

        if (recruiterRewarded)
            return;

        result = CharacterDatabase.PQuery("SELECT guid, NAME FROM characters WHERE account = %u ORDER BY totaltime DESC LIMIT 1", recruiter);
        if (!result)
            return;

        fields = result->Fetch();
        uint64 recruiterCharacterGUID = fields[0].GetUInt64();

        if (!recruiterCharacterGUID)
            return;

        result = LoginDatabase.PQuery("SELECT COUNT(*) FROM account WHERE recruiter = %u AND recruiter_rewarded = 1", recruiter);
        if (!result)
            return;

        fields = result->Fetch();
        uint32 recruiterRewardCount = fields[0].GetUInt32();
        uint32 rewardItem = 0;

        switch (++recruiterRewardCount)
        {
            case 1: rewardItem = 54860;     break; // X-53 Touring Rocket
            case 2: rewardItem = 37719;     break; // Swift Zhevra
            case 5: rewardItem = 106246;    break; // Emerald Hippogryph
            default: break;
        }

        if (rewardItem)
        {
            CharacterDatabase.PExecute("INSERT INTO character_shop (guid, type, itemId, itemCount) VALUES (" UI64FMTD ", 0, %u, 1)", recruiterCharacterGUID, rewardItem);
            LoginDatabase.PExecute("UPDATE account SET recruiter_rewarded = 1 WHERE id = %u", player->GetSession()->GetAccountId());
        }
    }
};

// TODO : this script is temp fix for expansion start questlines.
class OnArrival : public PlayerScript
{
public:
    OnArrival() : PlayerScript("OnArrival") { }

    enum
    {
        // Legion
/*        QUEST_BLINK_OF_AN_EYE                  = 44663, // lvl 10
        SPELL_LEGION_7_2_PATCH_QUEST_LAUNCH    = 239624,
        SPELL_LEGION_LAUNCH_PATCH_QUEST_LAUNCH = 258792,
        SPELL_MAGE_LEARN_GUARDIAN_HALL_TP      = 204287,
        SPELL_WAR_LEARN_JUMP_TO_SKYHOLD        = 192084,
        SPELL_DRUID_CLASS_HALL_TP              = 204874,
        SPELL_CREATE_CLASS_HALL_ALLIANCE       = 185506,
        SPELL_CREATE_CLASS_HALL_HORDE          = 192191,
        CONVERSATION_KHADGAR_BLINK_OF_EYE      = 3827,
*/
        // Allied Races
        QUEST_CALL_FOR_ALLIES_A  = 49929, // lvl 45
        QUEST_CALL_FOR_ALLIES_H  = 49930, // lvl 45

        // Battle For Azeroth
        QUEST_WOLFSOFFENSIVE_A          = 56031, // lvl 50
        QUEST_WARCHIEFSORDER_H          = 56030, // lvl 50
        SPELL_CREATE_WAR_CAMPAIGN_H     = 273381,
        SPELL_CREATE_WAR_CAMPAIGN_A     = 273382,

        // Shadowlands
        QUEST_A_CHILLING_SUMMONS_A  = 60545, // lvl 50
        QUEST_A_CHILLING_SUMMONS_H  = 61874, // lvl 50
    };

    void OnLevelChanged(Player* player, uint8 /*oldLevel*/) override
    {
        // Legion
        // remove when Legion start quests are properly fixed
/*        if (player->GetLevel() >= 10)
            LegionArrival(player);
*/
        // AlliedRaces
        if (player->GetLevel() >= 45)
            AlliedRacesArrival(player);

        // Battle For Azeroth
        // remove when Bfa start quests are properly fixed
        if (player->GetLevel() >= 50)
            BfaArrival(player);

        // Shadowlands
        if (player->GetLevel() >= 50)
            ShadowlandsArrival(player);
    }

    void OnLogin(Player* player, bool /*firstLogin*/) override
    {
        // Legion map grids - do we really need these? -Varjgard
/*        if (Map* map = sMapMgr->FindMap(0, 0))
            map->LoadGrid(-11099.8f, -2212.36f);

        if (Map* map = sMapMgr->FindMap(1669, 0))
        {
            map->LoadGrid(459.02f, 1450.02f);
            map->LoadGrid(4682.5f, 9851.57f);
            map->LoadGrid(-2624.08f, 8654.29f);
        }
        // Legion map grids end


        // Legion
        // remove when Legion start quests are properly fixed
        if (player->GetLevel() >= 10)
            LegionArrival(player);
*/
        // AlliedRaces
        if (player->GetLevel() >= 45)
            AlliedRacesArrival(player);

        // Battle For Azeroth
        // remove when Bfa start quests are properly fixed
        if (player->GetLevel() >= 50)
            BfaArrival(player);

        // Shadowlands
        if (player->GetLevel() >= 50)
            ShadowlandsArrival(player);
    }

/*    void OnQuestComplete(Player* player, Quest const* quest) override
    {
        // Legion
        if (quest->GetQuestId() == QUEST_BLINK_OF_AN_EYE)
            HandleGetAfterBlinkOfAnEye(player);
    }
*/
/*    void HandleGetAfterBlinkOfAnEye(Player* player)
    {
        // Legion
        if (uint32 artifact_knowledge = sWorld->getIntConfig(CONFIG_CURRENCY_START_ARTIFACT_KNOWLEDGE))
        {
            if (artifact_knowledge > 10)
                player->CompletedAchievement(10852);
            if (artifact_knowledge > 24)
                player->CompletedAchievement(10853);
        }

        player->CastSpell(player, player->IsInAlliance() ? SPELL_CREATE_CLASS_HALL_ALLIANCE : SPELL_CREATE_CLASS_HALL_HORDE, true);

        if (player->GetQuestStatus(QUEST_BLINK_OF_AN_EYE) == QUEST_STATUS_COMPLETE || player->GetQuestStatus(QUEST_BLINK_OF_AN_EYE) == QUEST_STATUS_REWARDED)
        {
            switch (player->GetClass())
            {
                case CLASS_WARRIOR:
                    player->CastSpell(player, 198182, true);
                    break;
                case CLASS_PALADIN:
                    player->CastSpell(player, 181009, true);
                    break;
                case CLASS_HUNTER:
                    player->CastSpell(player, 203376, true);
                    break;
                case CLASS_ROGUE:
                    player->CastSpell(player, 235468, true);
                    break;
                case CLASS_PRIEST:
                    player->CastSpell(player, 219764, true);
                    break;
                case CLASS_DEATH_KNIGHT:
                    player->CastSpell(player, 191521, true);
                    break;
                case CLASS_SHAMAN:
                    player->CastSpell(player, 211710, true);
                    break;
                case CLASS_MAGE:
                    player->CastSpell(player, 217305, true);
                    break;
                case CLASS_WARLOCK:
                    player->CastSpell(player, 201163, true);
                    break;
                case CLASS_MONK:
                    player->CastSpell(player, 234265, true);
                    break;
                case CLASS_DRUID:
                    player->CastSpell(player, 210357, true);
                    break;
                case CLASS_DEMON_HUNTER:
                    player->CastSpell(player, player->IsInAlliance() ? 188249 : 215133, true);
                    break;
                default:
                    break;
            }
        }
        player->CastSpell(player, 164608, true);
    }

    void LegionArrival(Player* player)
    {
        player->CastSpell(player, SPELL_LEGION_LAUNCH_PATCH_QUEST_LAUNCH, true);
        player->CastSpell(player, SPELL_LEGION_7_2_PATCH_QUEST_LAUNCH, true);

        switch (player->GetClass())
        {
            case CLASS_MAGE:
                player->CastSpell(player, SPELL_MAGE_LEARN_GUARDIAN_HALL_TP, true);
                break;
            case CLASS_WARRIOR:
                player->CastSpell(player, SPELL_WAR_LEARN_JUMP_TO_SKYHOLD, true);
                break;
            case CLASS_DRUID:
                player->CastSpell(player, SPELL_DRUID_CLASS_HALL_TP, true);
                break;
            case CLASS_HUNTER:
                player->m_taxi.SetTaximaskNode(1848); // Hunter Class Hall
                break;
            default:
                break;
        }

        if (player->GetQuestStatus(QUEST_BLINK_OF_AN_EYE) == QUEST_STATUS_NONE)
        {
            Conversation::CreateConversation(CONVERSATION_KHADGAR_BLINK_OF_EYE, player, player->GetPosition(), { player->GetGUID() });
            player->AddQuest(sObjectMgr->GetQuestTemplate(QUEST_BLINK_OF_AN_EYE), nullptr);
        }
        
        if (player->GetQuestStatus(QUEST_BLINK_OF_AN_EYE) == QUEST_STATUS_REWARDED)
            HandleGetAfterBlinkOfAnEye(player);
    }
*/
    void AlliedRacesArrival(Player* player)
    {
        if ((player->GetQuestStatus(QUEST_CALL_FOR_ALLIES_A) == QUEST_STATUS_NONE) && (player->IsInAlliance()))
            player->AddQuest(sObjectMgr->GetQuestTemplate(QUEST_CALL_FOR_ALLIES_A), nullptr);

        if ((player->GetQuestStatus(QUEST_CALL_FOR_ALLIES_H) == QUEST_STATUS_NONE) && (player->IsInHorde()))
            player->AddQuest(sObjectMgr->GetQuestTemplate(QUEST_CALL_FOR_ALLIES_H), nullptr);
    }

    void BfaArrival(Player* player)
    {
        if(player->IsInAlliance())
            player->CastSpell(player, SPELL_CREATE_WAR_CAMPAIGN_A, true);

        if(player->IsInHorde())
            player->CastSpell(player, SPELL_CREATE_WAR_CAMPAIGN_H, true);

        if ((player->GetQuestStatus(QUEST_WOLFSOFFENSIVE_A) == QUEST_STATUS_NONE) && (player->IsInAlliance()))
            player->AddQuest(sObjectMgr->GetQuestTemplate(QUEST_WOLFSOFFENSIVE_A), nullptr);

        if ((player->GetQuestStatus(QUEST_WARCHIEFSORDER_H) == QUEST_STATUS_NONE) && (player->IsInHorde()))
            player->AddQuest(sObjectMgr->GetQuestTemplate(QUEST_WARCHIEFSORDER_H), nullptr);
    }

    void ShadowlandsArrival(Player* player)
    {
        if ((player->GetQuestStatus(QUEST_A_CHILLING_SUMMONS_A) == QUEST_STATUS_NONE) && (player->IsInAlliance()))
            player->AddQuest(sObjectMgr->GetQuestTemplate(QUEST_A_CHILLING_SUMMONS_A), nullptr);

        if ((player->GetQuestStatus(QUEST_A_CHILLING_SUMMONS_H) == QUEST_STATUS_NONE) && (player->IsInHorde()))
            player->AddQuest(sObjectMgr->GetQuestTemplate(QUEST_A_CHILLING_SUMMONS_H), nullptr);
    }
};

enum RacialSpellsWor
{
    SPELL_RUNNING_WILD_LEARN = 94098,
};
/* Worgen Running Wild spell */
class WorgenRunningWild : public PlayerScript
{
public:
    WorgenRunningWild() : PlayerScript("WorgenRunningWild") { }

    void OnLevelChanged(Player* player, uint8 /*oldLevel*/) override
    {
        if (player->GetRace() == RACE_WORGEN && player->GetLevel() == 20)
            player->CastSpell(player, SPELL_RUNNING_WILD_LEARN);
    }
};

/* Dual Wield fix */
class DualWieldFix : public PlayerScript
{
public:
    DualWieldFix() : PlayerScript("DualWieldFix") { }

    void OnLogin(Player* player, bool /* firstLogin */) override
    {
        if ((player->GetClass() == CLASS_WARRIOR     ) ||
            (player->GetClass() == CLASS_HUNTER      ) ||
            (player->GetClass() == CLASS_ROGUE       ) ||
            (player->GetClass() == CLASS_DEATH_KNIGHT) ||
            (player->GetClass() == CLASS_MONK        ) ||
            (player->GetClass() == CLASS_DRUID       ) ||
            (player->GetClass() == CLASS_DEMON_HUNTER) )
            {
                if (!player->HasSpell(674))
                    player->LearnSpell(674, false, 0, true);
            }
    }

    void OnLevelChanged(Player* player, uint8 /*oldLevel*/) override
    {
        if ((player->GetClass() == CLASS_WARRIOR     ) ||
            (player->GetClass() == CLASS_HUNTER      ) ||
            (player->GetClass() == CLASS_ROGUE       ) ||
            (player->GetClass() == CLASS_DEATH_KNIGHT) ||
            (player->GetClass() == CLASS_MONK        ) ||
            (player->GetClass() == CLASS_DRUID       ) ||
            (player->GetClass() == CLASS_DEMON_HUNTER) )
            {
                if (!player->HasSpell(674))
                    player->LearnSpell(674, false, 0, true);
            }
    }
};

/* tempfix for "you cant speak that language" */
class chat_temp_fix : public PlayerScript
{
public:
    chat_temp_fix() : PlayerScript("chat_temp_fix") { }

    void OnLogin(Player* player, bool /* firstLogin */) override
    {
        if ((player->GetTeam() == ALLIANCE) && (!player->HasSpell(668)))
        {
            player->LearnSpell(668, false, true);
        }
        else if ((player->GetTeam() == HORDE) && (!player->HasSpell(669)))
        {
            player->LearnSpell(669, false, true);
        }
    }
};

/* Save all players on logout */
// fixes bug where players are rolled back to previous level on logout
class PlayerSavingOnLogoutFix : public PlayerScript
{
public:
    PlayerSavingOnLogoutFix() : PlayerScript("PlayerSavingOnLogoutFix") { }

    void OnLogout(Player* /*player*/) override
    {
        ObjectAccessor::SaveAllPlayers();
    }
};

/* DemonHunter talent choosing tempfix */
// TEMP FIX! remove when playerchoice has been fixed properly.
class DemonHunterTalentTempFix : public PlayerScript
{
public:
    DemonHunterTalentTempFix() : PlayerScript("DemonHunterTalentTempFix") { }

    void OnLogin(Player* player, bool /* firstLogin */) override
    {
        if (player->GetClass() == CLASS_DEMON_HUNTER && !player->HasSpell(200749))
            player->LearnSpell(200749, false);
    }

    void OnLevelChanged(Player* player, uint8 /*oldLevel*/) override
    {
        if (player->GetClass() == CLASS_DEMON_HUNTER && !player->HasSpell(200749))
            player->LearnSpell(200749, false);
    }
};


enum GenericMissingPlayerSpells
{
    // Warrior
    SPELL_GEN_WARRIOR_TAUNT = 355,
    SPELL_GEN_WARRIOR_EXECUTE = 163201,

    // Warlock
    SPELL_GEN_WARLOCK_SHADOW_BOLT = 686,
    SPELL_GEN_WARLOCK_CORRUPTION = 172,
    SPELL_GEN_WARLOCK_SUMMON_IMP = 688,
    SPELL_GEN_WARLOCK_SUMMON_FELHUNTER = 691,
    SPELL_GEN_WARLOCK_EYE_OF_KILROGG = 126,
    SPELL_GEN_WARLOCK_SUMMON_SUCCUBUS = 712,
    SPELL_GEN_WARLOCK_SUMMON_VOID_WALKER = 697,
    SPELL_GEN_WARLOCK_RITUAL_OF_SUMMONING = 698,
    SPELL_GEN_WARLOCK_CURSE_OF_WEAKNESS = 702,
    SPELL_GEN_WARLOCK_DEMONIC_CIRCLE_TELEPORT = 48020,
    SPELL_GEN_WARLOCK_BANISH = 710,
    SPELL_GEN_WARLOCK_DEMONIC_CIRCLE_BASE = 48018,

    // Hunter
    SPELL_GEN_HUNTER_BEAST_LORE = 1462,
    SPELL_GEN_HUNTER_CALL_PET_1 = 883, 
    SPELL_GEN_HUNTER_CALL_PET_2 = 83242,
    SPELL_GEN_HUNTER_DISMISS_PET = 2641,
    SPELL_GEN_HUNTER_FEED_PET = 6991,
    SPELL_GEN_HUNTER_MEND_PET = 136,
    SPELL_GEN_HUNTER_REVIVE_PET = 982,//猎人复活宠物技能
    SPELL_GEN_HUNTER_TAME_BEAST = 1515,
    SPELL_GEN_HUNTER_FREEZING_TRAP = 187650,

    // Mage
    SPELL_GEN_MAGE_POLYMORH = 118,
    SPELL_GEN_MAGE_FROSTBOLT = 116,
    SPELL_GEN_MAGE_FROST_NOVA = 122,
    SPELL_GEN_MAGE_SLOW_FALL = 130,
    SPELL_GEN_MAGE_REMOVE_CUSE = 475,
    SPELL_GEN_MAGE_INVISIBILITY = 66,

    // Rogue
    SPELL_GEN_ROGUE_KIDNEY_SHOT = 408,
    SPELL_GEN_ROGUE_INSTANT_POISON = 315584,

    // Priest
    SPELL_GEN_PRIEST_FADE_RANK_1 = 586,
    SPELL_GEN_PRIEST_SMITE = 585,
    SPELL_GEN_PRIEST_SHADOW_WORD_PAIN = 589,
    SPELL_GEN_PRIEST_POWER_WORD_SHIELD = 17,
    SPELL_GEN_PRIEST_DISPEL_MAGIC = 528,
    SPELL_GEN_PRIEST_MIND_SOOTHE = 453,
    SPELL_GEN_PRIEST_MIND_CONTROL = 605,
    SPELL_GEN_PRIEST_RESSURECTION = 2006,
    SPELL_GEN_PRIEST_FADE_RANK_2 = 327821,
    SPELL_GEN_PRIEST_MASS_DISPEL_RANK_2 = 327830,

    // Monk
    SPELL_GEN_MONK_TOUCH_OF_DEATH = 322109,

    // Shaman
    SPELL_GEN_SHAMAN_GHOST_WOLF = 2645,
    SPELL_GEN_SHAMAN_ASTRAL_RECALL = 556,
    SPELL_GEN_SHAMAN_WATER_WALKING = 546,
    SPELL_GEN_SHAMAN_PURGE = 370,

    // Paladin
    SPELL_GEN_PALADIN_DEVOTION_AURA = 465,
    SPELL_GEN_PALADIN_DIVINE_SHIELD = 642,

    // Demon Hunter
    SPELL_GEN_DEMON_HUNTER_IMMOLATION_AURA = 258920,
    SPELL_GEN_DEMON_HUNTER_THROW_GLAIVE = 185123,

    // Druid
    SPELL_GEN_DRUID_TRAVEL_FORM = 783,
    SPELL_GEN_DRUID_ENTANGLING_ROOTS = 339,
};

struct SpellCheckData
{
    uint32 spell_entry;
    uint32 level_id;
};

static SpellCheckData _spellData[11][12] =
{
    {
    { SPELL_GEN_WARRIOR_EXECUTE, 10},
    { SPELL_GEN_WARRIOR_TAUNT, 8},
    },

    {
    {SPELL_GEN_WARLOCK_BANISH, 46},
    {SPELL_GEN_WARLOCK_DEMONIC_CIRCLE_BASE, 41},
    {SPELL_GEN_WARLOCK_DEMONIC_CIRCLE_TELEPORT, 41},
    {SPELL_GEN_WARLOCK_CURSE_OF_WEAKNESS, 6},
    {SPELL_GEN_WARLOCK_RITUAL_OF_SUMMONING, 33},
    {SPELL_GEN_WARLOCK_SUMMON_VOID_WALKER, 10},
    {SPELL_GEN_WARLOCK_SUMMON_SUCCUBUS, 19},
    {SPELL_GEN_WARLOCK_EYE_OF_KILROGG, 17},
    {SPELL_GEN_WARLOCK_SUMMON_FELHUNTER, 23},
    {SPELL_GEN_WARLOCK_SUMMON_IMP, 3},
    {SPELL_GEN_WARLOCK_CORRUPTION, 2},
    {SPELL_GEN_WARLOCK_SHADOW_BOLT, 1},
    },

    {
    {SPELL_GEN_HUNTER_BEAST_LORE, 5},
    {SPELL_GEN_HUNTER_CALL_PET_1, 5},
    {SPELL_GEN_HUNTER_CALL_PET_2, 10},
    {SPELL_GEN_HUNTER_DISMISS_PET, 5},
    {SPELL_GEN_HUNTER_FEED_PET, 5},
    {SPELL_GEN_HUNTER_MEND_PET, 5},
    {SPELL_GEN_HUNTER_REVIVE_PET, 5},
    {SPELL_GEN_HUNTER_TAME_BEAST, 5},
    {SPELL_GEN_HUNTER_FREEZING_TRAP, 10},
    },

    {
    {SPELL_GEN_MAGE_POLYMORH, 10},
    {SPELL_GEN_MAGE_FROSTBOLT, 1},
    {SPELL_GEN_MAGE_FROST_NOVA, 3},
    {SPELL_GEN_MAGE_SLOW_FALL, 9},
    {SPELL_GEN_MAGE_REMOVE_CUSE, 28},
    {SPELL_GEN_MAGE_INVISIBILITY, 34},
    },

    {
    {SPELL_GEN_ROGUE_KIDNEY_SHOT, 13},
    {SPELL_GEN_ROGUE_INSTANT_POISON, 10},
    },

    {
    {SPELL_GEN_MONK_TOUCH_OF_DEATH, 10},
    },

    {
    {SPELL_GEN_PALADIN_DEVOTION_AURA, 28},
    {SPELL_GEN_PALADIN_DIVINE_SHIELD, 10},
    },

    {
    {SPELL_GEN_DEMON_HUNTER_IMMOLATION_AURA, 14},
    {SPELL_GEN_DEMON_HUNTER_THROW_GLAIVE, 19},
    },

    {
    {SPELL_GEN_DRUID_TRAVEL_FORM, 10},
    {SPELL_GEN_DRUID_ENTANGLING_ROOTS, 4},
    },

    {
    {SPELL_GEN_PRIEST_FADE_RANK_1, 9},
    {SPELL_GEN_PRIEST_SMITE, 1},
    {SPELL_GEN_PRIEST_SHADOW_WORD_PAIN, 2},
    {SPELL_GEN_PRIEST_POWER_WORD_SHIELD, 4},
    {SPELL_GEN_PRIEST_DISPEL_MAGIC, 24},
    {SPELL_GEN_PRIEST_MIND_SOOTHE, 52},
    {SPELL_GEN_PRIEST_MIND_CONTROL, 34},
    {SPELL_GEN_PRIEST_RESSURECTION, 10},
    {SPELL_GEN_PRIEST_FADE_RANK_2, 17},
    {SPELL_GEN_PRIEST_MASS_DISPEL_RANK_2, 50},
    },

    {
    {SPELL_GEN_SHAMAN_GHOST_WOLF, 10},
    {SPELL_GEN_SHAMAN_ASTRAL_RECALL, 32},
    {SPELL_GEN_SHAMAN_PURGE, 39},
    {SPELL_GEN_SHAMAN_WATER_WALKING, 33},
    },
};


class sl_playerscript_add_missing_spells_generic : public PlayerScript
{
public:
    sl_playerscript_add_missing_spells_generic() : PlayerScript("sl_playerscript_add_missing_spells_generic") { }

    void OnLevelChanged(Player* player, uint8 /*oldLevel*/)
    {
        SpellCheckData* data = new SpellCheckData();

        switch (player->GetClass())
        {
        case CLASS_WARRIOR:
        {
            for (int i = 0; i < 2; ++i)
            {
                data->spell_entry = _spellData[0][i].spell_entry;
                data->level_id = _spellData[0][i].level_id;

                if (player->GetLevel() >= data->level_id && !player->HasSpell(data->spell_entry))
                    player->LearnSpell(data->spell_entry, false);
            }
            break;
        }
        case CLASS_WARLOCK:
        {
            for (int i = 0; i < 12; ++i)
            {
                data->spell_entry = _spellData[1][i].spell_entry;
                data->level_id = _spellData[1][i].level_id;

                if (player->GetLevel() >= data->level_id && !player->HasSpell(data->spell_entry))
                    player->LearnSpell(data->spell_entry, false);
            }
            break;
        }
        case CLASS_HUNTER:
        {
            for (int i = 0; i < 9; ++i)
            {
                data->spell_entry = _spellData[2][i].spell_entry;
                data->level_id = _spellData[2][i].level_id;

                if (player->GetLevel() >= data->level_id && !player->HasSpell(data->spell_entry))
                    player->LearnSpell(data->spell_entry, false);
            }
            break;
        }
        case CLASS_PRIEST:
        {
            for (int i = 0; i < 10; ++i)
            {
                data->spell_entry = _spellData[9][i].spell_entry;
                data->level_id = _spellData[9][i].level_id;

                if (player->GetLevel() >= data->level_id && !player->HasSpell(data->spell_entry))
                    player->LearnSpell(data->spell_entry, false);
            }
            break;
        }
        case CLASS_MAGE:
        {
            for (int i = 0; i < 6; ++i)
            {
                data->spell_entry = _spellData[3][i].spell_entry;
                data->level_id = _spellData[3][i].level_id;

                if (player->GetLevel() >= data->level_id && !player->HasSpell(data->spell_entry))
                    player->LearnSpell(data->spell_entry, false);
            }
            break;
        }
        case CLASS_DEMON_HUNTER:
        {
            for (int i = 0; i < 2; ++i)
            {
                data->spell_entry = _spellData[7][i].spell_entry;
                data->level_id = _spellData[7][i].level_id;

                if (player->GetLevel() >= data->level_id && !player->HasSpell(data->spell_entry))
                    player->LearnSpell(data->spell_entry, false);
            }
            break;
        }
        case CLASS_PALADIN:
        {
            for (int i = 0; i < 2; ++i)
            {
                data->spell_entry = _spellData[6][i].spell_entry;
                data->level_id = _spellData[6][i].level_id;

                if (player->GetLevel() >= data->level_id && !player->HasSpell(data->spell_entry))
                    player->LearnSpell(data->spell_entry, false);
            }
            break;
        }
        case CLASS_SHAMAN:
        {
            for (int i = 0; i < 4; ++i)
            {
                data->spell_entry = _spellData[10][i].spell_entry;
                data->level_id = _spellData[10][i].level_id;

                if (player->GetLevel() >= data->level_id && !player->HasSpell(data->spell_entry))
                    player->LearnSpell(data->spell_entry, false);
            }
            break;
        }
        case CLASS_MONK:
        {
            for (int i = 0; i < 1; ++i)
            {
                data->spell_entry = _spellData[5][i].spell_entry;
                data->level_id = _spellData[5][i].level_id;

                if (player->GetLevel() >= data->level_id && !player->HasSpell(data->spell_entry))
                    player->LearnSpell(data->spell_entry, false);
            }
            break;
        }
        case CLASS_DRUID:
        {
            for (int i = 0; i < 2; ++i)
            {
                data->spell_entry = _spellData[8][i].spell_entry;
                data->level_id = _spellData[8][i].level_id;

                if (player->GetLevel() >= data->level_id && !player->HasSpell(data->spell_entry))
                    player->LearnSpell(data->spell_entry, false);
            }
            break;
        }
        case CLASS_ROGUE:
        {
            for (int i = 0; i < 2; ++i)
            {
                data->spell_entry = _spellData[4][i].spell_entry;
                data->level_id = _spellData[4][i].level_id;

                if (player->GetLevel() >= data->level_id && !player->HasSpell(data->spell_entry))
                    player->LearnSpell(data->spell_entry, false);
            }
            break;
        }
        }
    }
};

// SPELL_AZERITE_RESIDUE = 260738
class ps_spell_azerite_residue : public PlayerScript
{
public:
    ps_spell_azerite_residue() : PlayerScript("ps_spell_azerite_residue") { }

    // Called when a player kills another player
    void OnPVPKill(Player* /*killer*/, Player* killed) override
    {
        if (killed->HasAura(SPELL_AZERITE_RESIDUE))
        {
            if (Aura* aura = killed->GetAura(SPELL_AZERITE_RESIDUE))
            {
                //uint8 count = aura->GetStackAmount();
                aura->SetStackAmount(1);
                /*if (InstanceScript* instance = killer->GetInstanceScript())
                    instance->GiveIslandAzeriteXpGain(killer, killed->GetGUID(), count);*/
            }
        }
    }

    // Called when a player kills a creature
    void OnCreatureKill(Player* /*killer*/, Creature* killed) override
    {
        if (killed->HasAura(SPELL_AZERITE_RESIDUE))
        {
            if (Aura* aura = killed->GetAura(SPELL_AZERITE_RESIDUE))
            {
                //uint8 count = aura->GetStackAmount();
                aura->SetStackAmount(1);
               /* if (InstanceScript* instance = killer->GetInstanceScript())
                    instance->GiveIslandAzeriteXpGain(killer, killed->GetGUID(), count);*/
            }
        }
    }
};


void AddSC_custom_player_script()
{
    RegisterPlayerScript(playerscript_recruiter);
    RegisterPlayerScript(OnArrival);                // TEMP FIX! remove when expansion starting quests are properly fixed.
    RegisterPlayerScript(WorgenRunningWild);
    RegisterPlayerScript(DualWieldFix);
    RegisterPlayerScript(chat_temp_fix);
    RegisterPlayerScript(PlayerSavingOnLogoutFix);
    RegisterPlayerScript(DemonHunterTalentTempFix); // TEMP FIX! remove when playerchoice has been fixed properly.
    RegisterPlayerScript(sl_playerscript_add_missing_spells_generic);
    new ps_spell_azerite_residue();
}
