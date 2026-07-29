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

#include "Config.h"

#include "BattlegroundMgr.h"
#include "Followship_bots_config.h"
#include "GenAI_provider.h"


bool  FollowshipBotsConfig::configFSBEnabled = false;
bool  FollowshipBotsConfig::configFSBOverrideBattlegroundRequirements = false;
int64 FollowshipBotsConfig::configFSBPricePerLevel = 10;
int64 FollowshipBotsConfig::configFSBPermanentPricePerLevel = 10000;
int32 FollowshipBotsConfig::configFSBHireDuration1 = 1;
int32 FollowshipBotsConfig::configFSBHireDuration2 = 2;
int32 FollowshipBotsConfig::configFSBHireDuration3 = 3;

bool  FollowshipBotsConfig::configFSBUseOOCActions = true;
bool  FollowshipBotsConfig::configFSBUseICPotions = true;
bool  FollowshipBotsConfig::configFSBUseAFKActions = true;
bool  FollowshipBotsConfig::configFSBUseCustomRegen = true;
bool  FollowshipBotsConfig::configFSBUseChatChannels = true;

uint32 FollowshipBotsConfig::configFSBAFKInterval = 30000;
uint32 FollowshipBotsConfig::configFSBAFKChance = 40;

uint32 FollowshipBotsConfig::configFSBChatterRate = 10;
uint32 FollowshipBotsConfig::configFSBChatChannelsRate = 10;
int64 FollowshipBotsConfig::configFSBChatChannelsInterval = 10000;

bool FollowshipBotsConfig::configFSBGeneralReplyEnabled = true;
uint32 FollowshipBotsConfig::configFSBGeneralReplyChance = 10;
uint32 FollowshipBotsConfig::configFSBGeneralReplyCooldownMs = 30000;
uint32 FollowshipBotsConfig::configFSBBotChatMemorySize = 10;

bool FollowshipBotsConfig::configFSBAllowGold = true;
uint32 FollowshipBotsConfig::configFSBMaxGoldAmount = 50000;
uint32 FollowshipBotsConfig::configFSBGoldMailDelay = 300;

float FollowshipBotsConfig::configFSBHealthRate = 1.f;
float FollowshipBotsConfig::configFSBPowerRate = 1.f;
float FollowshipBotsConfig::configFSBDamageRate = 1.f;
float FollowshipBotsConfig::configFSBArmorRate = 0.4f;
float FollowshipBotsConfig::configFSBHealthRegenRate = 1.f;
float FollowshipBotsConfig::configFSBPowerRegenRate = 1.f;

bool  FollowshipBotsConfig::configFSBGenAIEnabled = false;
uint8 FollowshipBotsConfig::configFSBGenAIProvider = 0;
bool  FollowshipBotsConfig::configFSBGenAIOverridePreset = false;
std::string FollowshipBotsConfig::configFSBGenAIHost = "127.0.0.1";
int32 FollowshipBotsConfig::configFSBGenAIPort = 8080;
std::string FollowshipBotsConfig::configFSBGenAIEndpoint = "v1/chat/completions";
std::string FollowshipBotsConfig::configFSBGenAIModel = "Qwen3-4B-Q4_K_M.gguf";
std::string FollowshipBotsConfig::configFSBGenAIApiKey = "";
std::string FollowshipBotsConfig::configFSBGenAIApiKeyHeader = "Authorization";
std::string FollowshipBotsConfig::configFSBGenAIApiKeyPrefix = "Bearer ";
bool  FollowshipBotsConfig::configFSBGenAIUseSSL = false;
std::string FollowshipBotsConfig::configFSBGenAIRequestHeader = "";
int32 FollowshipBotsConfig::configFSBGenAITimeoutMs = 5000;
int32 FollowshipBotsConfig::configFSBGenAIMaxTokens = 50;
int32 FollowshipBotsConfig::configFSBGenAIMailMaxTokens = 150;
float FollowshipBotsConfig::configFSBGenAITemperature = 0.9f;
float FollowshipBotsConfig::configFSBGenAITopP = 0.95f;
float FollowshipBotsConfig::configFSBGenAIFrequencyPenalty = 0.8f;
float FollowshipBotsConfig::configFSBGenAIPresencePenalty = 0.6f;
bool  FollowshipBotsConfig::configFSBGenAIAutoStartQuest = false;

void FollowshipBotsConfig::Load()
{
    configFSBEnabled =
        sConfigMgr->GetBoolDefault("Followship.Bots.Enabled", false);

    configFSBOverrideBattlegroundRequirements =
        sConfigMgr->GetBoolDefault("Followship.Bots.OverrideBattlegroundRequirements", false);

    configFSBUseChatChannels =
        sConfigMgr->GetBoolDefault("Followship.Bots.UseChatChannels", true);

    configFSBPricePerLevel =
        sConfigMgr->GetInt64Default("Followship.Bots.BaseCostPerLevel", 10);

    configFSBPermanentPricePerLevel =
        sConfigMgr->GetInt64Default("Followship.Bots.PermanentCostPerLevel", 10000);

    configFSBHireDuration1 =
        sConfigMgr->GetIntDefault("Followship.Bot.HireDuration1", 1);

    configFSBHireDuration2 =
        sConfigMgr->GetIntDefault("Followship.Bot.HireDuration2", 2);

    configFSBHireDuration3 =
        sConfigMgr->GetIntDefault("Followship.Bot.HireDuration3", 3);

    configFSBUseCustomRegen =
        sConfigMgr->GetBoolDefault("Followship.Bots.UseCustomRegen", true);

    configFSBUseOOCActions =
        sConfigMgr->GetBoolDefault("Followship.Bots.UseOOCActions", true);

    configFSBUseAFKActions =
        sConfigMgr->GetBoolDefault("Followship.Bots.UseAFKActions", true);

    configFSBAFKInterval =
        sConfigMgr->GetIntDefault("Followship.Bots.AFKIntervalMs", 30000);

    configFSBAFKChance =
        sConfigMgr->GetIntDefault("Followship.Bots.AFKChance", 40);

    configFSBUseICPotions =
        sConfigMgr->GetBoolDefault("Followship.Bots.UseICPotions", true);

    configFSBChatterRate =
        sConfigMgr->GetIntDefault("Followship.Bots.ChatterRate", 10);

    configFSBChatChannelsInterval =
        sConfigMgr->GetInt64Default("Followship.Bots.ChatChannelsInterval", 10000);

    configFSBChatChannelsRate =
        sConfigMgr->GetIntDefault("Followship.Bots.ChatChannelsRate", 10);

    configFSBGeneralReplyEnabled =
        sConfigMgr->GetBoolDefault("Followship.Bots.GeneralReplyEnabled", true);

    configFSBGeneralReplyChance =
        sConfigMgr->GetIntDefault("Followship.Bots.GeneralReplyChance", 10);

    configFSBGeneralReplyCooldownMs =
        sConfigMgr->GetIntDefault("Followship.Bots.GeneralReplyCooldownMs", 30000);

    configFSBBotChatMemorySize =
        sConfigMgr->GetIntDefault("Followship.Bots.ChatMemorySize", 10);

    configFSBAllowGold =
        sConfigMgr->GetBoolDefault("Followship.Bots.AllowGold", true);

    configFSBMaxGoldAmount =
        sConfigMgr->GetIntDefault("Followship.Bots.MaxGoldAmount", 50000);

    configFSBGoldMailDelay =
        sConfigMgr->GetIntDefault("Followship.Bots.GoldMailDelay", 300);

    configFSBArmorRate =
        sConfigMgr->GetFloatDefault("Followship.Bots.ArmorRate", 0.4f);

    configFSBHealthRate =
        sConfigMgr->GetFloatDefault("Followship.Bots.HealthRate", 1.f);

    configFSBPowerRate =
        sConfigMgr->GetFloatDefault("Followship.Bots.PowerRate", 1.f);

    configFSBDamageRate =
        sConfigMgr->GetFloatDefault("Followship.Bots.DamageRate", 1.f);

    configFSBHealthRegenRate =
        sConfigMgr->GetFloatDefault("Followship.Bots.HealthRegenRate", 1.f);

    configFSBPowerRegenRate =
        sConfigMgr->GetFloatDefault("Followship.Bots.PowerRegenRate", 1.f);

    configFSBGenAIEnabled =
        sConfigMgr->GetBoolDefault("Followship.Bots.GenAI.Enabled", false);

    configFSBGenAIProvider = static_cast<uint8>(
        sConfigMgr->GetIntDefault("Followship.Bots.GenAI.Provider", 0));

    configFSBGenAIOverridePreset =
        sConfigMgr->GetBoolDefault("Followship.Bots.GenAI.OverridePreset", false);

    auto const& preset = FSBGenAI::GetPreset(static_cast<FSBGenAI::GenAIProvider>(configFSBGenAIProvider));

    if (!configFSBGenAIOverridePreset && configFSBGenAIProvider != 0)
    {
        configFSBGenAIHost = preset.host;
        configFSBGenAIEndpoint = preset.endpoint;
        configFSBGenAIPort = preset.port;
        configFSBGenAIUseSSL = preset.useSSL;
        configFSBGenAIApiKeyHeader = preset.apiKeyHeader;
        configFSBGenAIApiKeyPrefix = preset.apiKeyPrefix;
        configFSBGenAIRequestHeader = preset.versionHeader;
    }
    else
    {
        configFSBGenAIHost =
            sConfigMgr->GetStringDefault("Followship.Bots.GenAI.Host", "127.0.0.1");

        configFSBGenAIPort =
            sConfigMgr->GetIntDefault("Followship.Bots.GenAI.Port", 8080);

        configFSBGenAIEndpoint =
            sConfigMgr->GetStringDefault("Followship.Bots.GenAI.Endpoint", "v1/chat/completions");

        configFSBGenAIUseSSL =
            sConfigMgr->GetBoolDefault("Followship.Bots.GenAI.UseSSL", false);

        configFSBGenAIApiKeyHeader =
            sConfigMgr->GetStringDefault("Followship.Bots.GenAI.ApiKeyHeader", "Authorization");

        configFSBGenAIApiKeyPrefix =
            sConfigMgr->GetStringDefault("Followship.Bots.GenAI.ApiKeyPrefix", "Bearer ");

        configFSBGenAIRequestHeader =
            sConfigMgr->GetStringDefault("Followship.Bots.GenAI.RequestHeader", "");
    }

    configFSBGenAIModel =
        sConfigMgr->GetStringDefault("Followship.Bots.GenAI.Model", "Qwen3-4B-Q4_K_M.gguf");

    configFSBGenAIApiKey =
        sConfigMgr->GetStringDefault("Followship.Bots.GenAI.ApiKey", "");

    configFSBGenAITimeoutMs =
        sConfigMgr->GetIntDefault("Followship.Bots.GenAI.TimeoutMs", 5000);

    configFSBGenAIMaxTokens =
        sConfigMgr->GetIntDefault("Followship.Bots.GenAI.MaxTokens", 50);

    configFSBGenAIMailMaxTokens =
        sConfigMgr->GetIntDefault("Followship.Bots.GenAI.MailMaxTokens", 150);

    configFSBGenAITemperature =
        sConfigMgr->GetFloatDefault("Followship.Bots.GenAI.Temperature", 0.9f);

    configFSBGenAITopP =
        sConfigMgr->GetFloatDefault("Followship.Bots.GenAI.TopP", 0.95f);

    configFSBGenAIFrequencyPenalty =
        sConfigMgr->GetFloatDefault("Followship.Bots.GenAI.FrequencyPenalty", 0.8f);

    configFSBGenAIPresencePenalty =
        sConfigMgr->GetFloatDefault("Followship.Bots.GenAI.PresencePenalty", 0.6f);

    configFSBGenAIAutoStartQuest =
        sConfigMgr->GetBoolDefault("Followship.Bots.GenAI.AutoStartQuestFromChat", false);

    sBattlegroundMgr->SetFSBOverrideEnabled(configFSBOverrideBattlegroundRequirements);
}
