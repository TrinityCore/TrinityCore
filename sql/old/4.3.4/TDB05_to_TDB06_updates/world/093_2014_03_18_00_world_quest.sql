-- The Splintered Throne
UPDATE `quest_template` SET `NextQuestId`=24912 WHERE `Id`=24548;

-- Shadowmourne...
UPDATE `quest_template` SET `PrevQuestId`=24912 WHERE `Id`=24549;

-- Empowerment
UPDATE `quest_template` SET `PrevQuestId`=24548, `NextQuestId`=24549 WHERE `Id`=24912;

DELETE FROM `creature_queststarter` WHERE `quest`=24912;
INSERT INTO `creature_queststarter`(`id`,`quest`) VALUE
(37120,24912);

DELETE FROM `creature_questender` WHERE `quest`=24912;
INSERT INTO `creature_questender`(`id`,`quest`) VALUE
(37120,24912);

-- Highlord Darion Mograine
UPDATE `creature_template` SET `AIName`='' WHERE `entry`=37120;
DELETE FROM `smart_scripts` WHERE `entryorguid`=37120 AND `source_type`=0;
