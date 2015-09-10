ALTER TABLE `quest_template`
  CHANGE COLUMN `LimitTime`             `TimeAllowed`         INT(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `PointOption`,
  CHANGE COLUMN `RequiredRaces`         `RequiredRaces`       SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `TimeAllowed`,
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
