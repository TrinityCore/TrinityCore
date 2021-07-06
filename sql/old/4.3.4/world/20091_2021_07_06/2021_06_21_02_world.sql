ALTER TABLE `quest_template_addon` 
ADD COLUMN `AllowableRaces` MEDIUMINT UNSIGNED NOT NULL DEFAULT 0 AFTER `SpecialFlags`,
ADD COLUMN `TimeAllowed` INT UNSIGNED NOT NULL DEFAULT 0 AFTER `AllowableRaces`;

INSERT IGNORE INTO `quest_template_addon` (`ID`) (SELECT `ID` FROM `quest_template` WHERE `AllowableRaces` != 0 OR `TimeAllowed` != 0);

UPDATE `quest_template_addon` AS qta
INNER JOIN `quest_template` AS qt ON (qta.ID = qt.ID)
SET qta.AllowableRaces = qt.AllowableRaces, qta.TimeAllowed = qt.TimeAllowed;

ALTER TABLE `quest_template`
DROP COLUMN `AllowableRaces`,
DROP COLUMN `TimeAllowed`;
