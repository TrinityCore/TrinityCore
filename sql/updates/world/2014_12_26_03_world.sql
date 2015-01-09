-- SMSG_QUESTGIVER_QUEST_LIST
DROP TABLE IF EXISTS `quest_creature_greeting`;
CREATE TABLE `quest_creature_greeting` (
    `CreatureID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
    `GreetEmoteType` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0',
    `GreetEmoteDelay` INT(10) UNSIGNED NOT NULL DEFAULT '0',
    `Greeting` TEXT,
    `VerifiedBuild` SMALLINT(5) NOT NULL DEFAULT '0',
    PRIMARY KEY (`CreatureID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;


-- SMSG_QUESTGIVER_QUEST_DETAILS
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

INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`)
SELECT `ID`, `DetailsEmote1`, `DetailsEmote2`, `DetailsEmote3`, `DetailsEmote4`, `DetailsEmoteDelay1`, `DetailsEmoteDelay2`, `DetailsEmoteDelay3`, `DetailsEmoteDelay4` FROM `quest_template`
WHERE `DetailsEmote1`!=0 OR `DetailsEmote2`!=0 OR `DetailsEmote3`!=0 OR `DetailsEmote4`!=0 OR `DetailsEmoteDelay1`!=0 OR `DetailsEmoteDelay2`!=0 OR `DetailsEmoteDelay3`!=0 OR `DetailsEmoteDelay4`!=0;


-- SMSG_QUESTGIVER_REQUEST_ITEMS
DROP TABLE IF EXISTS `quest_request_items`;
CREATE TABLE `quest_request_items` (
    `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
    `EmoteOnComplete` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0',
    `EmoteOnIncomplete` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0',
    `EmoteOnCompleteDelay` INT(10) UNSIGNED NOT NULL DEFAULT '0',
    `EmoteOnIncompleteDelay` INT(10) UNSIGNED NOT NULL DEFAULT '0',
    `CompletionText` TEXT,
    `VerifiedBuild` SMALLINT(5) NOT NULL DEFAULT '0',
    PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `CompletionText`)
SELECT `ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `RequestItemsText` FROM `quest_template`
WHERE `EmoteOnComplete`!=0 OR `EmoteOnIncomplete`!=0 OR `RequestItemsText`!='';


-- SMSG_QUESTGIVER_OFFER_REWARD
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

INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`)
SELECT `ID`, `OfferRewardEmote1`, `OfferRewardEmote2`, `OfferRewardEmote3`, `OfferRewardEmote4`, `OfferRewardEmoteDelay1`, `OfferRewardEmoteDelay2`, `OfferRewardEmoteDelay3`, `OfferRewardEmoteDelay4`, `OfferRewardText` FROM `quest_template`
WHERE `OfferRewardEmote1`!=0 OR `OfferRewardEmote2`!=0 OR `OfferRewardEmote3`!=0 OR `OfferRewardEmote4`!=0 OR `OfferRewardEmoteDelay1`!=0 OR `OfferRewardEmoteDelay2`!=0 OR `OfferRewardEmoteDelay3`!=0 OR `OfferRewardEmoteDelay4`!=0 OR `OfferRewardText`!='';

/*
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
  DROP `OfferRewardEmote1`,
  DROP `OfferRewardEmote2`,
  DROP `OfferRewardEmote3`,
  DROP `OfferRewardEmote4`,
  DROP `OfferRewardEmoteDelay1`,
  DROP `OfferRewardEmoteDelay2`,
  DROP `OfferRewardEmoteDelay3`,
  DROP `OfferRewardEmoteDelay4`,
  DROP `RequestItemsText`,
  DROP `OfferRewardText`;
*/
