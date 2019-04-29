DROP TABLE IF EXISTS `quest_offer_reward_locale`;
CREATE TABLE `quest_offer_reward_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `RewardText` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
);

DROP TABLE IF EXISTS `quest_request_items_locale`;
CREATE TABLE `quest_request_items_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `CompletionText` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
);

INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) SELECT `ID`, `locale`, `RequestItemsText`, `VerifiedBuild` from `quest_template_locale` WHERE `RequestItemsText` != ""; -- Migrate data to new table
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) SELECT `ID`, `locale`, `OfferRewardText`, `VerifiedBuild` from `quest_template_locale` WHERE `OfferRewardText` != ""; -- Migrate data to new table

ALTER TABLE `quest_template_locale`
  DROP COLUMN `RequestItemsText`,
  DROP COLUMN `OfferRewardText`;
