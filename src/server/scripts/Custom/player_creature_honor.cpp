#include "ScriptMgr.h"
#include "Player.h"
#include "Creature.h"
#include "Config.h"
#include "Chat.h"
#include "WorldPacket.h"
#include "Formulas.h"
#include "Mail.h"

class player_creature_honor : public PlayerScript
{
    public:
        player_creature_honor() : PlayerScript("player_creature_honor")
        {
            // Init Config Settings

            // General
            creatureHonorScriptEnabled = sConfigMgr->GetBoolDefault("CreatureHonor.Enabled", false);
            allowAchievementGain = sConfigMgr->GetBoolDefault("CreatureHonor.Allow.Achievement", false);
            
            // Levels
            playerMinLevel = sConfigMgr->GetIntDefault("CreatureHonor.Player.Minlevel", 10);

            if (playerMinLevel < 1)
                playerMinLevel = 1; // Characters can't be lower than level 1 anyway...

            creatureBonusLevelDiff = sConfigMgr->GetIntDefault("CreatureHonor.Creature.BonusLevelDiff", 5);
            penaltyLevelDiff = sConfigMgr->GetIntDefault("CreatureHonor.Creature.PenaltyLevelDiff", false);

            // Rates - Base
            rateNormal = sConfigMgr->GetIntDefault("CreatureHonor.Rate.Normal", 3);
            rateElite = sConfigMgr->GetIntDefault("CreatureHonor.Rate.Elite", 5);

            // Rates - Bonuses
            rateGuardBonus = sConfigMgr->GetIntDefault("CreatureHonor.Rate.GuardBonus", 2);
            rateLevelDiffBonus = sConfigMgr->GetIntDefault("CreatureHonor.Rate.LevelDiffBonus", 5);
            rateRareEliteBonus = sConfigMgr->GetIntDefault("CreatureHonor.Rate.RareEliteBonus", 2);
            rateRacialLeaderBonus = sConfigMgr->GetIntDefault("CreatureHonor.Rate.RacialLeaderBonus", 5);
            rateWorldBossBonus = sConfigMgr->GetIntDefault("CreatureHonor.Rate.WorldBossBonus", 5);

            // Rules - General
            onlyInInstances = sConfigMgr->GetBoolDefault("CreatureHonor.Allow.InstancesOnly", false);
            requireXP = sConfigMgr->GetBoolDefault("CreatureHonor.Require.XP", true);
            honorFromNeutral = sConfigMgr->GetBoolDefault("CreatureHonor.Allow.Neutral", true);
            requirePlayerPvP = sConfigMgr->GetBoolDefault("CreatureHonor.Require.PlayerPvP", true);
            requireCreaturePvP = sConfigMgr->GetBoolDefault("CreatureHonor.Require.CreaturePvP", true);

            // Rules - Creature Types
            allowBeast = sConfigMgr->GetBoolDefault("CreatureHonor.Allow.Beast", false);
            allowDragonkin = sConfigMgr->GetBoolDefault("CreatureHonor.Allow.Dragonkin", true);
            allowDemon = sConfigMgr->GetBoolDefault("CreatureHonor.Allow.Demon", true);
            allowElemental = sConfigMgr->GetBoolDefault("CreatureHonor.Allow.Elemental", false);
            allowGiant = sConfigMgr->GetBoolDefault("CreatureHonor.Allow.Giant", true);
            allowHumanoid = sConfigMgr->GetBoolDefault("CreatureHonor.Allow.Humanoid", true);
            allowMechanical = sConfigMgr->GetBoolDefault("CreatureHonor.Allow.Mechanical", false);
            allowUndead = sConfigMgr->GetBoolDefault("CreatureHonor.Allow.Undead", true);

            // Messaging - General
            creatureHonorLvlReachedMsg = sConfigMgr->GetStringDefault("CreatureHonor.Message.Chat.LevelReachedMessage", "@@Congratulations, you are now able to earn honor@@from NPC kills. Good hunting!");

            // Messaging - Rules message
            creatureHonorRulesMsg.append("* Honor from NPC kills:\n");

            if (allowBeast)
                creatureHonorRulesMsg.append("\n  Beast");
            if (allowDragonkin)
                creatureHonorRulesMsg.append("\n  Dragonkin");
            if (allowDemon)
                creatureHonorRulesMsg.append("\n  Demon");
            if (allowElemental)
                creatureHonorRulesMsg.append("\n  Elemental");
            if (allowGiant)
                creatureHonorRulesMsg.append("\n  Giant");
            if (allowUndead)
                creatureHonorRulesMsg.append("\n  Undead");
            if (allowHumanoid)
                creatureHonorRulesMsg.append("\n  Humanoid");
            if (allowMechanical)
                creatureHonorRulesMsg.append("\n  Mechanical");
            
            creatureHonorRulesMsg.append("\n");

            if (requirePlayerPvP)
                creatureHonorRulesMsg.append("\n* You must be flagged for PvP");
            if (requireCreaturePvP)
                creatureHonorRulesMsg.append("\n* NPC must be flagged for PvP");
            if (requireXP)
                creatureHonorRulesMsg.append("\n* NPC must reward XP");
            if (onlyInInstances)
                creatureHonorRulesMsg.append("\n* NPC must be in an instance");
            if (!honorFromNeutral)
                creatureHonorRulesMsg.append("\n* NPC can not be neutral");
            if (penaltyLevelDiff > 0)
                creatureHonorRulesMsg.append("\n* NPC can't be more than " + std::to_string(penaltyLevelDiff) + "\n  levels below you");

        }

        void OnCreatureKill(Player* killer, Creature* killed) override
        {
            if (creatureHonorScriptEnabled)
                RewardHonor(killer, killed);
        }

        void OnCreate(Player* pl) override
        {
            // Create a DB entry for this character if script is enabled

            if (creatureHonorScriptEnabled)
            {
                SQLTransaction trans = CharacterDatabase.BeginTransaction();
                PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CREATUREHONOR_MESSAGE);
                stmt->setUInt32(0, pl->GetGUIDLow());
                stmt->setUInt32(1, 0);
                trans->Append(stmt);
                CharacterDatabase.CommitTransaction(trans);
            }
        }

        void OnDelete(ObjectGuid guid, uint32 accountId) override
        {
            // Delete message record when character is deleted, even if script is disabled.

            if (guid.IsPlayer())
            {
                SQLTransaction trans = CharacterDatabase.BeginTransaction();
                PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CREATUREHONOR_MESSAGE);
                stmt->setUInt32(0, guid.GetLow()); // GUID of player, same as player->GetGUIDLow()
                trans->Append(stmt);
                CharacterDatabase.CommitTransaction(trans);
            }
        }

        void OnLogin(Player* pl, bool firstLogin) override
        {
            // Checks if logged in character needs to have messages sent.
            // Admins can force this by setting the DB value to 0
            // Useful for existing characters (prior to the script implementation) or when CONF is changed

            if (creatureHonorScriptEnabled && (pl->getLevel() >= playerMinLevel))
            {
                uint32 msgSent = 0;

                PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CREATUREHONOR_MESSAGE);
                stmt->setUInt32(0, pl->GetGUIDLow());
                PreparedQueryResult result = CharacterDatabase.Query(stmt);

                if (result)
                {
                    // Check if message has already been sent
                    Field* fields = result->Fetch();
                    msgSent = fields[0].GetUInt32();
                }
                else
                {
                    // DB Record didn't exist. Most likely old character created before this script was written.
                    this->OnCreate(pl);
                }

                // Send messages to player if needed
                if (msgSent == 0)
                    SendMessagesToPlayer(pl);
            }

        }

        void OnLevelChanged(Player* pl, uint8 oldLevel) override
        {
            // Sends chat and mail messages based on CONF options

            if (creatureHonorScriptEnabled && (pl->getLevel() == playerMinLevel))
            {
                SendMessagesToPlayer(pl);
            }

        }

    private:

        // General
        bool creatureHonorScriptEnabled;
        bool allowAchievementGain;
        bool onlyInInstances;
        bool requireXP;
        bool honorFromNeutral;
        bool requirePlayerPvP;
        bool requireCreaturePvP;
        std::string creatureHonorLvlReachedMsg;
        std::string creatureHonorRulesMsg;

        // Levels
        uint32 playerMinLevel = 0;
        uint32 creatureBonusLevelDiff = 0;
        uint32 penaltyLevelDiff = 0;

        // Base rates
        uint32 rateNormal = 0;
        uint32 rateElite = 0;

        // Rate bonuses
        uint32 rateGuardBonus = 0;
        uint32 rateLevelDiffBonus = 0;
        uint32 rateRareEliteBonus = 0;
        uint32 rateRacialLeaderBonus = 0;
        uint32 rateWorldBossBonus = 0;

        // Honor flags
        bool allowBeast;
        bool allowDragonkin;
        bool allowDemon;
        bool allowElemental;
        bool allowGiant;
        bool allowUndead;
        bool allowHumanoid;
        bool allowMechanical;

        void SendMessagesToPlayer(Player* pl)
        {
            // Sends messages and updates the message tracker DB table

            // Chat - General notify message
            SendMessageToChat(pl, creatureHonorLvlReachedMsg);

            // Mail - Rules List
            SendMessageToMail(pl, "Honor From NPC Kills", creatureHonorRulesMsg);

            // Update DB to indicate messages have been sent
            SQLTransaction trans = CharacterDatabase.BeginTransaction();
            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CREATUREHONOR_MESSAGE);
            stmt->setUInt32(0, 1);
            stmt->setUInt32(1, pl->GetGUIDLow());
            trans->Append(stmt);
            CharacterDatabase.CommitTransaction(trans);
        }

        void SendMessageToMail(Player* receiver, std::string mailSubject, std::string mailMsg)
        {
            // Sends mail to the player. Mail sender is the class trainer from the player's
            //  starting zone which is looked up by using CinematicCamera.dbc. If for some
            //  reason that NPC is not found, sender is the reciver itself.

            if (!receiver)
                return;

            uint32 mailSenderID;
            uint32 cinematicSequenceID;

            MailMessageType mailType;
            std::string msgFinal;
            float x = 0.0f;
            float y = 0.0f;
            float z = 0.0f;
            CinematicCameraEntry const* cinematicCamera;

            // ChrRaces.dbc contains a key to CinematicSequences.dbc which in turn contains
            //  a key to CinematicCamera.dbc. It is in CinematicCamera.dbc where we can find
            //  the XYZ necessary to query the creature table.
            //
            // In case of Deathknight, race is not tied to cinematic but class is

            if (ChrClassesEntry const* classEntry = sChrClassesStore.LookupEntry(receiver->getClass()))
            {
                if (classEntry->CinematicSequence)
                    cinematicSequenceID = classEntry->CinematicSequence;
                else if (ChrRacesEntry const* raceEntry = sChrRacesStore.LookupEntry(receiver->getRace()))
                    cinematicSequenceID = raceEntry->CinematicSequence;
            }

            if (CinematicSequencesEntry const* cinematicSequence = sCinematicSequencesStore.LookupEntry(cinematicSequenceID))
                cinematicCamera = sCinematicCameraStore.LookupEntry(cinematicSequence->cinematicCamera);

            if (cinematicCamera)
            {
                x = cinematicCamera->end_x;
                y = cinematicCamera->end_y;
                z = cinematicCamera->end_z;
            }

            // Pick the class trainer that is located in the starting zone closest to
            //  where the intro cinematic camera stops
            PreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_CREATUREHONOR_MAILSENDER);
            stmt->setUInt32(0, receiver->getClass());
            stmt->setFloat(1, x);
            stmt->setFloat(2, x);
            stmt->setFloat(3, y);
            stmt->setFloat(4, y);
            stmt->setFloat(5, z);
            stmt->setFloat(6, z);
            PreparedQueryResult result = WorldDatabase.Query(stmt);

            if (result)
            {
                Field* fields = result->Fetch();

                // Use the found creature as mail sender instead of the receiver itself
                mailSenderID = fields[0].GetInt32();
                mailType = MAIL_CREATURE;

                // Add some flavor text to the message
                msgFinal.append("Greetings " + receiver->GetName() + ", I hope this\nletter finds you in good health.\n\n");
                msgFinal.append("I have received word that you have\nreached level " + std::to_string(receiver->getLevel()) + ", well done!\n\n");
                msgFinal.append("You will now receive honor for NPC\nkills if you follow these rules:\n\n");
                msgFinal.append(mailMsg);
                msgFinal.append("\n\nGood Hunting!\n\n");
                msgFinal.append(fields[1].GetString() + ",\n" + fields[2].GetString()); // fields[2] is 'subname', for Deathknight this is blank
            }
            else
            {
                mailSenderID = receiver->GetGUIDLow();
                mailType = MAIL_NORMAL;
                msgFinal = mailMsg;
            }

            // Send the mail. Receiver can choose to "make a copy" through the client
            SQLTransaction trans = CharacterDatabase.BeginTransaction();
            MailDraft(mailSubject, msgFinal).SendMailTo(trans, receiver, MailSender(mailType, mailSenderID, MAIL_STATIONERY_DEFAULT), MAIL_CHECK_MASK_HAS_BODY);
            CharacterDatabase.CommitTransaction(trans);

        }

        void SendMessageToChat(Player* receiver, std::string msg)
        {
            // Sends a chat message to the player

            if (!receiver)
                return;

            if (msg.empty())
                return;

            WorldPacket data;

            // Split string on custom delimiter for newline and send each line to
            //  the chat system

            char* buf = strdup(msg.c_str()); // duplicate the string for work to avoid corruption
            char* line;
            char* delim = "@@";

            line = strtok(buf, delim);
            while (line != NULL)
            {
                ChatHandler::BuildChatPacket(data, CHAT_MSG_SYSTEM, LANG_UNIVERSAL, NULL, NULL, line);
                receiver->GetSession()->SendPacket(&data);
                line = strtok(NULL, delim);
            }

            free(buf);

        }

        int32 CalcHonor(Player* thePlayer, Creature* target)
        {
            // Determines the amount of honor the target gives based on config options

            int32 tempHonor = 0;
            uint32 targetLevel = target->getLevel();
            uint32 playerLevel = thePlayer->getLevel();

            // Get base honor
            if (target->isElite())
                tempHonor = rateElite;
            else
                tempHonor = rateNormal;

            // Bonus for level difference. Creature level must be at least creatureBonusLevelDiff greater than player
            if ((creatureBonusLevelDiff > 0) && (targetLevel >= playerLevel + creatureBonusLevelDiff))
                tempHonor += rateLevelDiffBonus;

            // Bonus if guard
            if (target->IsGuard())
                tempHonor += rateGuardBonus;

            // Bonus if rare elite
            if (target->GetCreatureTemplate()->rank == CREATURE_ELITE_RARE)
                tempHonor += rateRareEliteBonus;

            // Bonus for faction leader
            if (target->IsRacialLeader())
                tempHonor += rateRacialLeaderBonus;

            // Bonus for world boss
            if (target->isWorldBoss())
                tempHonor += rateWorldBossBonus;

            // Penalty for level diff. This MUST come last because it is designed to
            // subtract the honor that would have been earned
            if ((penaltyLevelDiff > 0) && (targetLevel < playerLevel - penaltyLevelDiff))
            {
                // Check if player has enough honor to support the penalty without
                // going negative

                uint32 currentHonor = thePlayer->GetHonorPoints();

                if (currentHonor - tempHonor < 0)
                    tempHonor = -currentHonor; // will set honor to zero by removing current honor to prevent going negative
                else
                    tempHonor = -tempHonor; // remove honor earned for this kill because of penalty
            }

            return tempHonor;
        }

        bool CanRewardXP(uint8 playerLevel, uint8 targetLevel)
        {
            // Determines if a creature can reward XP based on level

            // Returns TRUE if target is at least "GREEN"
            return targetLevel > Trinity::XP::GetGrayLevel(playerLevel);
        }

        void RewardHonor(Player* thePlayer, Creature* victim)
        {
            if (!IsHonorEnabled(thePlayer, victim))
                return;

            int32 honor = CalcHonor(thePlayer, victim);

            // Only count kill and achievement if honor is gained, not when
            // CreatureHonor.Creature.PenaltyLevelDiff is enabled
            if (honor > 0)
            {
                // need call before fields update to have chance move yesterday data to appropriate fields before today data change.
                thePlayer->UpdateHonorFields();

                // count the number of kills in one day
                thePlayer->ApplyModUInt32Value(PLAYER_FIELD_KILLS, 1, true);

                // and those in a lifetime
                thePlayer->ApplyModUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS, 1, true);

                if (allowAchievementGain)
                {
                    thePlayer->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_EARN_HONORABLE_KILL);
                    thePlayer->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_HONORABLE_KILL, 1, 0, victim);
                }
            }

            // Apply honor points
            // Note: Subtracting honor makes the "coin" sound at the client, similar to when you buy items. This is a client "feature".
            thePlayer->ModifyHonorPoints(honor);
            thePlayer->ApplyModUInt32Value(PLAYER_FIELD_TODAY_CONTRIBUTION, honor, true);

            // Send honor message to client (chat log). Last two parameters are victim_guid
            // and victim_rank which would print the name and rank in the chat log and floating
            // text. Since NPCs have no rank, setting them to zero prevents the client from
            // displaying an empty "HK:"
            WorldPacket data(SMSG_PVP_CREDIT, 4 + 8 + 4);
            data << int32(honor);
            data << uint64(0);
            data << uint32(0);

            thePlayer->GetSession()->SendPacket(&data);

        }

        bool IsHonorEnabled(Player* thePlayer, Creature* target)
        {
            // Checks if the honor should be rewarded based on CONF options

            // Instance requirement
            if (onlyInInstances && (target->GetInstanceId() == 0))
                return false;

            // XP requirement
            if (requireXP && !CanRewardXP(thePlayer->getLevel(), target->getLevel()))
                return false;

            // Neutral requirement
            if (!honorFromNeutral && (target->GetReactionTo(thePlayer) == REP_NEUTRAL))
                return false;

            // PvP (Player) requirement
            if (requirePlayerPvP && !thePlayer->IsPvP())
                return false;

            // PvP (Creature) requirement
            if (requireCreaturePvP && !target->IsPvP())
                return false;

            // Creature type
            uint32 creatureType = target->GetCreatureType();

            switch (creatureType)
            {
                case CREATURE_TYPE_BEAST:
                    return allowBeast;
                case CREATURE_TYPE_DEMON:
                    return allowDemon;
                case CREATURE_TYPE_DRAGONKIN:
                    return allowDragonkin;
                case CREATURE_TYPE_ELEMENTAL:
                    return allowElemental;
                case CREATURE_TYPE_GIANT:
                    return allowGiant;
                case CREATURE_TYPE_HUMANOID:
                    return allowHumanoid;
                case CREATURE_TYPE_MECHANICAL:
                    return allowMechanical;
                case CREATURE_TYPE_UNDEAD:
                    return allowUndead;
                default:
                    return false;
            }
        }
};

void AddSC_player_creature_honor()
{
    new player_creature_honor();
}
