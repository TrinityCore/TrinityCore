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
