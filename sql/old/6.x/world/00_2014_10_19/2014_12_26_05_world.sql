DROP TABLE IF EXISTS `quest_template_addon`;
CREATE TABLE `quest_template_addon` (
    `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
    `MaxLevel` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
    `AllowableClasses` INT(10) UNSIGNED NOT NULL DEFAULT '0',
    `SourceSpellID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
    `PrevQuestID` MEDIUMINT(8) NOT NULL DEFAULT '0',
    `NextQuestID` MEDIUMINT(8) NOT NULL DEFAULT '0',
    `ExclusiveGroup` MEDIUMINT(8) NOT NULL DEFAULT '0',
    `RewardMailTemplateID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
    `RewardMailDelay` INT(10) UNSIGNED NOT NULL DEFAULT '0',
    `ProvidedItemCount` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
    `SpecialFlags` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
    PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `SourceSpellID`, `SpecialFlags`, `MaxLevel`, `AllowableClasses`, `ProvidedItemCount`) 
SELECT `ID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateId`, `RewardMailDelay`, `SourceSpellID`, `SpecialFlags`, `MaxLevel`, `RequiredClasses`, `SourceItemCount` FROM `quest_template` 
WHERE `PrevQuestID`!=0 OR `NextQuestID`!=0 OR `ExclusiveGroup`!=0 OR `RewardMailTemplateId`!=0 OR `RewardMailDelay`!=0 OR `SourceSpellID`!=0 OR `SpecialFlags`!=0 OR `MaxLevel`!=0 OR `RequiredClasses`!=0 OR `SourceItemCount`!=0;


/*
ALTER TABLE `quest_template`
  DROP `PrevQuestID`,
  DROP `NextQuestID`,
  DROP `ExclusiveGroup`,
  DROP `RewardMailTemplateId`,
  DROP `RewardMailDelay`,
  DROP `SourceSpellID`,
  DROP `SpecialFlags`,
  DROP `MaxLevel`,
  DROP `RequiredClasses`,
  DROP `MinimapTargetMark`,
  DROP `SourceItemCount`;
*/
