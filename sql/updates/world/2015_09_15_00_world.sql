-- RewardItem(s) and RewardAmount(s) [4x2 fields]
ALTER TABLE `quest_template`
  CHANGE COLUMN `RewardAmount1` `RewardAmount1` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `RewardItem1`,
  CHANGE COLUMN `RewardAmount2` `RewardAmount2` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `RewardItem2`,
  CHANGE COLUMN `RewardAmount3` `RewardAmount3` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `RewardItem3`,
  CHANGE COLUMN `RewardAmount4` `RewardAmount4` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `RewardItem4`;

-- RewardChoiceItemID(s) and RewardChoiceItemQuantity(s) [6x2 fields]
ALTER TABLE `quest_template`
  CHANGE COLUMN `RewardChoiceItemQuantity1` `RewardChoiceItemQuantity1` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `RewardChoiceItemID1`,
  CHANGE COLUMN `RewardChoiceItemQuantity2` `RewardChoiceItemQuantity2` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `RewardChoiceItemID2`,
  CHANGE COLUMN `RewardChoiceItemQuantity3` `RewardChoiceItemQuantity3` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `RewardChoiceItemID3`,
  CHANGE COLUMN `RewardChoiceItemQuantity4` `RewardChoiceItemQuantity4` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `RewardChoiceItemID4`,
  CHANGE COLUMN `RewardChoiceItemQuantity5` `RewardChoiceItemQuantity5` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `RewardChoiceItemID5`,
  CHANGE COLUMN `RewardChoiceItemQuantity6` `RewardChoiceItemQuantity6` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `RewardChoiceItemID6`;

-- RewardFactionID(s), RewardFactionValue(s) and RewardFactionOverride(s) [5x3 fields]
ALTER TABLE `quest_template`
  CHANGE COLUMN `RewardFactionValue1`     `RewardFactionValue1`     MEDIUMINT(8) NOT NULL DEFAULT '0' AFTER `RewardFactionID1`,
  CHANGE COLUMN `RewardFactionOverride1`  `RewardFactionOverride1`  MEDIUMINT(8) NOT NULL DEFAULT '0' AFTER `RewardFactionValue1`,
  CHANGE COLUMN `RewardFactionValue2`     `RewardFactionValue2`     MEDIUMINT(8) NOT NULL DEFAULT '0' AFTER `RewardFactionID2`,
  CHANGE COLUMN `RewardFactionOverride2`  `RewardFactionOverride2`  MEDIUMINT(8) NOT NULL DEFAULT '0' AFTER `RewardFactionValue2`,
  CHANGE COLUMN `RewardFactionValue3`     `RewardFactionValue3`     MEDIUMINT(8) NOT NULL DEFAULT '0' AFTER `RewardFactionID3`,
  CHANGE COLUMN `RewardFactionOverride3`  `RewardFactionOverride3`  MEDIUMINT(8) NOT NULL DEFAULT '0' AFTER `RewardFactionValue3`,
  CHANGE COLUMN `RewardFactionValue4`     `RewardFactionValue4`     MEDIUMINT(8) NOT NULL DEFAULT '0' AFTER `RewardFactionID4`,
  CHANGE COLUMN `RewardFactionOverride4`  `RewardFactionOverride4`  MEDIUMINT(8) NOT NULL DEFAULT '0' AFTER `RewardFactionValue4`,
  CHANGE COLUMN `RewardFactionValue5`     `RewardFactionValue5`     MEDIUMINT(8) NOT NULL DEFAULT '0' AFTER `RewardFactionID5`,
  CHANGE COLUMN `RewardFactionOverride5`  `RewardFactionOverride5`  MEDIUMINT(8) NOT NULL DEFAULT '0' AFTER `RewardFactionValue5`;

  -- quest_details
DROP TABLE IF EXISTS `quest_details`;
CREATE TABLE `quest_details` (
    `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
    `Emote1` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0',
    `Emote2` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0',
    `Emote3` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0',
    `Emote4` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0',
    `EmoteDelay1` INT(10) UNSIGNED NOT NULL DEFAULT '0',
    `EmoteDelay2` INT(10) UNSIGNED NOT NULL DEFAULT '0',
    `EmoteDelay3` INT(10) UNSIGNED NOT NULL DEFAULT '0',
    `EmoteDelay4` INT(10) UNSIGNED NOT NULL DEFAULT '0',
    `VerifiedBuild` SMALLINT(5) NOT NULL DEFAULT '0',
    PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`)
SELECT `ID`, `DetailsEmote1`, `DetailsEmote2`, `DetailsEmote3`, `DetailsEmote4`, `DetailsEmoteDelay1`, `DetailsEmoteDelay2`, `DetailsEmoteDelay3`, `DetailsEmoteDelay4`, `VerifiedBuild` FROM `quest_template`
WHERE `DetailsEmote1`!=0 OR `DetailsEmote2`!=0 OR `DetailsEmote3`!=0 OR `DetailsEmote4`!=0 OR `DetailsEmoteDelay1`!=0 OR `DetailsEmoteDelay2`!=0 OR `DetailsEmoteDelay3`!=0 OR `DetailsEmoteDelay4`!=0;


-- quest_request_items
DROP TABLE IF EXISTS `quest_request_items`;
CREATE TABLE `quest_request_items` (
    `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
    `EmoteOnComplete` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0',
    `EmoteOnIncomplete` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0',
    `CompletionText` TEXT,
    `VerifiedBuild` SMALLINT(5) NOT NULL DEFAULT '0',
    PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `CompletionText`, `VerifiedBuild`)
SELECT `ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `RequestItemsText`, `VerifiedBuild` FROM `quest_template`
WHERE `EmoteOnComplete`!=0 OR `EmoteOnIncomplete`!=0 OR `RequestItemsText`!='';


-- quest_offer_reward
DROP TABLE IF EXISTS `quest_offer_reward`;
CREATE TABLE `quest_offer_reward` (
    `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
    `Emote1` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0',
    `Emote2` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0',
    `Emote3` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0',
    `Emote4` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0',
    `EmoteDelay1` INT(10) UNSIGNED NOT NULL DEFAULT '0',
    `EmoteDelay2` INT(10) UNSIGNED NOT NULL DEFAULT '0',
    `EmoteDelay3` INT(10) UNSIGNED NOT NULL DEFAULT '0',
    `EmoteDelay4` INT(10) UNSIGNED NOT NULL DEFAULT '0',
    `RewardText` TEXT,
    `VerifiedBuild` SMALLINT(5) NOT NULL DEFAULT '0',
    PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`)
SELECT `ID`, `OfferRewardEmote1`, `OfferRewardEmote2`, `OfferRewardEmote3`, `OfferRewardEmote4`, `OfferRewardEmoteDelay1`, `OfferRewardEmoteDelay2`, `OfferRewardEmoteDelay3`, `OfferRewardEmoteDelay4`, `OfferRewardText`, `VerifiedBuild` FROM `quest_template`
WHERE `OfferRewardEmote1`!=0 OR `OfferRewardEmote2`!=0 OR `OfferRewardEmote3`!=0 OR `OfferRewardEmote4`!=0 OR `OfferRewardEmoteDelay1`!=0 OR `OfferRewardEmoteDelay2`!=0 OR `OfferRewardEmoteDelay3`!=0 OR `OfferRewardEmoteDelay4`!=0 OR `OfferRewardText`!='';

-- delete old fields
ALTER TABLE `quest_template`
  DROP `DetailsEmote1`,
  DROP `DetailsEmote2`,
  DROP `DetailsEmote3`,
  DROP `DetailsEmote4`,
  DROP `DetailsEmoteDelay1`,
  DROP `DetailsEmoteDelay2`,
  DROP `DetailsEmoteDelay3`,
  DROP `DetailsEmoteDelay4`,
  DROP `EmoteOnIncomplete`,
  DROP `EmoteOnComplete`,
  DROP `RequestItemsText`,
  DROP `OfferRewardEmote1`,
  DROP `OfferRewardEmote2`,
  DROP `OfferRewardEmote3`,
  DROP `OfferRewardEmote4`,
  DROP `OfferRewardEmoteDelay1`,
  DROP `OfferRewardEmoteDelay2`,
  DROP `OfferRewardEmoteDelay3`,
  DROP `OfferRewardEmoteDelay4`,
  DROP `OfferRewardText`;
  
  
ALTER TABLE `quest_template`
  CHANGE COLUMN `Method`    `QuestType`   TINYINT(3)  UNSIGNED NOT NULL DEFAULT '2' AFTER `ID`,
  CHANGE COLUMN `QuestType` `QuestInfoID` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `QuestSortID`;
  
  ALTER TABLE `quest_template`
  CHANGE COLUMN `LimitTime`             `TimeAllowed`         INT(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `PointOption`,
  CHANGE COLUMN `RequiredRaces`         `RequiredRaces`       MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0' AFTER `TimeAllowed`,
  CHANGE COLUMN `NextQuestIdChain`      `RewardNextQuest`     MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0' AFTER `RequiredFactionValue2`,
  CHANGE COLUMN `RewardXPId`            `RewardXPDifficulty`  TINYINT(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `RewardNextQuest`,
  CHANGE COLUMN `RewardOrRequiredMoney` `RewardMoney`         INT(11) NOT NULL DEFAULT '0' AFTER `RewardXPDifficulty`,
  CHANGE COLUMN `RewardMoneyMaxLevel`   `RewardBonusMoney`    INT(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `RewardMoney`,
  CHANGE COLUMN `RewardSpell`           `RewardDisplaySpell`  MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0' AFTER `RewardBonusMoney`,
  CHANGE COLUMN `RewardSpellCast`       `RewardSpell`         INT(11) NOT NULL DEFAULT '0' AFTER `RewardDisplaySpell`,
  CHANGE COLUMN `RewardHonorMultiplier` `RewardKillHonor`     FLOAT NOT NULL DEFAULT '0' AFTER `RewardHonor`,
  CHANGE COLUMN `SourceItemId`          `StartItem`           MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0' AFTER `RewardKillHonor`,
  CHANGE COLUMN `RewardTitle`           `RewardTitle`         TINYINT(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `RewardChoiceItemQuantity6`,
  CHANGE COLUMN `RewardTalents`         `RewardTalents`       TINYINT(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `RewardTitle`,
  CHANGE COLUMN `RewardArenaPoints`     `RewardArenaPoints`   SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `RewardTalents`;
-- split needed to avoid import errors
ALTER TABLE `quest_template`
  CHANGE COLUMN `PointMapId`            `POIContinent`        SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `RewardChoiceItemQuantity6`,
  CHANGE COLUMN `PointX`                `POIx`                FLOAT NOT NULL DEFAULT '0' AFTER `POIContinent`,
  CHANGE COLUMN `PointY`                `POIy`                FLOAT NOT NULL DEFAULT '0' AFTER `POIx`,
  CHANGE COLUMN `PointOption`           `POIPriority`         MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0' AFTER `POIy`,
  CHANGE COLUMN `EndText`               `AreaDescription`     TEXT NULL AFTER `QuestDescription`;
  
ALTER TABLE `quest_template`
  CHANGE COLUMN `RequiredRaces`            `AllowableRaces`    MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0' AFTER `TimeAllowed`,
  CHANGE COLUMN `RequiredSourceItemId1`    `ItemDrop1`         MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0' AFTER `RewardAmount4`,
  CHANGE COLUMN `RequiredSourceItemCount1` `ItemDropQuantity1` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `ItemDrop1`,
  CHANGE COLUMN `RequiredSourceItemId2`    `ItemDrop2`         MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0' AFTER `ItemDropQuantity1`,
  CHANGE COLUMN `RequiredSourceItemCount2` `ItemDropQuantity2` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `ItemDrop2`,
  CHANGE COLUMN `RequiredSourceItemId3`    `ItemDrop3`         MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0' AFTER `ItemDropQuantity2`,
  CHANGE COLUMN `RequiredSourceItemCount3` `ItemDropQuantity3` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `ItemDrop3`,
  CHANGE COLUMN `RequiredSourceItemId4`    `ItemDrop4`         MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0' AFTER `ItemDropQuantity3`,
  CHANGE COLUMN `RequiredSourceItemCount4` `ItemDropQuantity4` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `ItemDrop4`;
