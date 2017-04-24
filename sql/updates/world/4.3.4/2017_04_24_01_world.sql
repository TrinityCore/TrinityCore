DROP TABLE IF EXISTS `quest_template_locale`;
CREATE TABLE IF NOT EXISTS `quest_template_locale` (
  `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `locale` VARCHAR(4) NOT NULL,
  `Title` TEXT,
  `Details` TEXT,
  `Objectives` TEXT,
  `OfferRewardText` TEXT,
  `RequestItemsText` TEXT,
  `EndText` TEXT,
  `CompletedText` TEXT,
  `ObjectiveText1` TEXT,
  `ObjectiveText2` TEXT,
  `ObjectiveText3` TEXT,
  `ObjectiveText4` TEXT,
  `QuestGiverTextWindow` TEXT,
  `QuestGiverTargetName` TEXT,
  `QuestTurnTextWindow` TEXT,
  `QuestTurnTargetName` TEXT,
  `VerifiedBuild` SMALLINT(5) DEFAULT '0',
  PRIMARY KEY (`ID`, `locale`)
) ENGINE=MYISAM DEFAULT CHARSET=utf8;

-- koKR
INSERT INTO `quest_template_locale` (`ID`, `locale`, `Title`, `Details`, `Objectives`, `OfferRewardText`, `RequestItemsText`, `EndText`, `CompletedText`, `ObjectiveText1`, `ObjectiveText2`, `ObjectiveText3`, `ObjectiveText4`, `QuestGiverTextWindow`, `QuestGiverTargetName`, `QuestTurnTextWindow`, `QuestTurnTargetName`, `VerifiedBuild`)
  (SELECT `Id`, "koKR", `Title_loc1`, `Details_loc1`, `Objectives_loc1`, `OfferRewardText_loc1`, `RequestItemsText_loc1`, `EndText_loc1`, `CompletedText_loc1`, `ObjectiveText1_loc1`, `ObjectiveText2_loc1`, `ObjectiveText3_loc1`, `ObjectiveText4_loc1`, `QuestGiverTextWindow_loc1`, `QuestGiverTargetName_loc1`, `QuestTurnTextWindow_loc1`, `QuestTurnTargetName_loc1`, `VerifiedBuild`
   FROM `locales_quest` WHERE LENGTH(Title_loc1) > 0);

-- frFR
INSERT INTO `quest_template_locale` (`ID`, `locale`, `Title`, `Details`, `Objectives`, `OfferRewardText`, `RequestItemsText`, `EndText`, `CompletedText`, `ObjectiveText1`, `ObjectiveText2`, `ObjectiveText3`, `ObjectiveText4`, `QuestGiverTextWindow`, `QuestGiverTargetName`, `QuestTurnTextWindow`, `QuestTurnTargetName`, `VerifiedBuild`)
  (SELECT `Id`, "frFR", `Title_loc2`, `Details_loc2`, `Objectives_loc2`, `OfferRewardText_loc2`, `RequestItemsText_loc2`, `EndText_loc2`, `CompletedText_loc2`, `ObjectiveText1_loc2`, `ObjectiveText2_loc2`, `ObjectiveText3_loc2`, `ObjectiveText4_loc2`, `QuestGiverTextWindow_loc2`, `QuestGiverTargetName_loc2`, `QuestTurnTextWindow_loc2`, `QuestTurnTargetName_loc2`, `VerifiedBuild`
   FROM `locales_quest` WHERE LENGTH(Title_loc2) > 0);

-- deDE
INSERT INTO `quest_template_locale` (`ID`, `locale`, `Title`, `Details`, `Objectives`, `OfferRewardText`, `RequestItemsText`, `EndText`, `CompletedText`, `ObjectiveText1`, `ObjectiveText2`, `ObjectiveText3`, `ObjectiveText4`, `QuestGiverTextWindow`, `QuestGiverTargetName`, `QuestTurnTextWindow`, `QuestTurnTargetName`, `VerifiedBuild`)
  (SELECT `Id`, "deDE", `Title_loc3`, `Details_loc3`, `Objectives_loc3`, `OfferRewardText_loc3`, `RequestItemsText_loc3`, `EndText_loc3`, `CompletedText_loc3`, `ObjectiveText1_loc3`, `ObjectiveText2_loc3`, `ObjectiveText3_loc3`, `ObjectiveText4_loc3`, `QuestGiverTextWindow_loc3`, `QuestGiverTargetName_loc3`, `QuestTurnTextWindow_loc3`, `QuestTurnTargetName_loc3`, `VerifiedBuild`
   FROM `locales_quest` WHERE LENGTH(Title_loc3) > 0);

-- zhCN
INSERT INTO `quest_template_locale` (`ID`, `locale`, `Title`, `Details`, `Objectives`, `OfferRewardText`, `RequestItemsText`, `EndText`, `CompletedText`, `ObjectiveText1`, `ObjectiveText2`, `ObjectiveText3`, `ObjectiveText4`, `QuestGiverTextWindow`, `QuestGiverTargetName`, `QuestTurnTextWindow`, `QuestTurnTargetName`, `VerifiedBuild`)
  (SELECT `Id`, "zhCN", `Title_loc4`, `Details_loc4`, `Objectives_loc4`, `OfferRewardText_loc4`, `RequestItemsText_loc4`, `EndText_loc4`, `CompletedText_loc4`, `ObjectiveText1_loc4`, `ObjectiveText2_loc4`, `ObjectiveText3_loc4`, `ObjectiveText4_loc4`, `QuestGiverTextWindow_loc4`, `QuestGiverTargetName_loc4`, `QuestTurnTextWindow_loc4`, `QuestTurnTargetName_loc4`, `VerifiedBuild`
   FROM `locales_quest` WHERE LENGTH(Title_loc4) > 0);

-- zhTW
INSERT INTO `quest_template_locale` (`ID`, `locale`, `Title`, `Details`, `Objectives`, `OfferRewardText`, `RequestItemsText`, `EndText`, `CompletedText`, `ObjectiveText1`, `ObjectiveText2`, `ObjectiveText3`, `ObjectiveText4`, `QuestGiverTextWindow`, `QuestGiverTargetName`, `QuestTurnTextWindow`, `QuestTurnTargetName`, `VerifiedBuild`)
  (SELECT `Id`, "zhTW", `Title_loc5`, `Details_loc5`, `Objectives_loc5`, `OfferRewardText_loc5`, `RequestItemsText_loc5`, `EndText_loc5`, `CompletedText_loc5`, `ObjectiveText1_loc5`, `ObjectiveText2_loc5`, `ObjectiveText3_loc5`, `ObjectiveText4_loc5`, `QuestGiverTextWindow_loc5`, `QuestGiverTargetName_loc5`, `QuestTurnTextWindow_loc5`, `QuestTurnTargetName_loc5`, `VerifiedBuild`
   FROM `locales_quest` WHERE LENGTH(Title_loc5) > 0);

-- esES
INSERT INTO `quest_template_locale` (`ID`, `locale`, `Title`, `Details`, `Objectives`, `OfferRewardText`, `RequestItemsText`, `EndText`, `CompletedText`, `ObjectiveText1`, `ObjectiveText2`, `ObjectiveText3`, `ObjectiveText4`, `QuestGiverTextWindow`, `QuestGiverTargetName`, `QuestTurnTextWindow`, `QuestTurnTargetName`, `VerifiedBuild`)
  (SELECT `Id`, "esES", `Title_loc6`, `Details_loc6`, `Objectives_loc6`, `OfferRewardText_loc6`, `RequestItemsText_loc6`, `EndText_loc6`, `CompletedText_loc6`, `ObjectiveText1_loc6`, `ObjectiveText2_loc6`, `ObjectiveText3_loc6`, `ObjectiveText4_loc6`, `QuestGiverTextWindow_loc6`, `QuestGiverTargetName_loc6`, `QuestTurnTextWindow_loc6`, `QuestTurnTargetName_loc6`, `VerifiedBuild`
   FROM `locales_quest` WHERE LENGTH(Title_loc6) > 0);

-- esMX
INSERT INTO `quest_template_locale` (`ID`, `locale`, `Title`, `Details`, `Objectives`, `OfferRewardText`, `RequestItemsText`, `EndText`, `CompletedText`, `ObjectiveText1`, `ObjectiveText2`, `ObjectiveText3`, `ObjectiveText4`, `QuestGiverTextWindow`, `QuestGiverTargetName`, `QuestTurnTextWindow`, `QuestTurnTargetName`, `VerifiedBuild`)
  (SELECT `Id`, "esMX", `Title_loc7`, `Details_loc7`, `Objectives_loc7`, `OfferRewardText_loc7`, `RequestItemsText_loc7`, `EndText_loc7`, `CompletedText_loc7`, `ObjectiveText1_loc7`, `ObjectiveText2_loc7`, `ObjectiveText3_loc7`, `ObjectiveText4_loc7`, `QuestGiverTextWindow_loc7`, `QuestGiverTargetName_loc7`, `QuestTurnTextWindow_loc7`, `QuestTurnTargetName_loc7`, `VerifiedBuild`
   FROM `locales_quest` WHERE LENGTH(Title_loc7) > 0);

-- ruRU
INSERT INTO `quest_template_locale` (`ID`, `locale`, `Title`, `Details`, `Objectives`, `OfferRewardText`, `RequestItemsText`, `EndText`, `CompletedText`, `ObjectiveText1`, `ObjectiveText2`, `ObjectiveText3`, `ObjectiveText4`, `QuestGiverTextWindow`, `QuestGiverTargetName`, `QuestTurnTextWindow`, `QuestTurnTargetName`, `VerifiedBuild`)
  (SELECT `Id`, "ruRU", `Title_loc8`, `Details_loc8`, `Objectives_loc8`, `OfferRewardText_loc8`, `RequestItemsText_loc8`, `EndText_loc8`, `CompletedText_loc8`, `ObjectiveText1_loc8`, `ObjectiveText2_loc8`, `ObjectiveText3_loc8`, `ObjectiveText4_loc8`, `QuestGiverTextWindow_loc8`, `QuestGiverTargetName_loc8`, `QuestTurnTextWindow_loc8`, `QuestTurnTargetName_loc8`, `VerifiedBuild`
   FROM `locales_quest` WHERE LENGTH(Title_loc8) > 0);

DROP TABLE IF EXISTS `locales_quest`;
