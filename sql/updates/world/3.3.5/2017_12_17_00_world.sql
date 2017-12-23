-- 
DELETE FROM `creature_queststarter` WHERE `quest`=10901;
DELETE FROM `quest_template_addon` WHERE `ID` IN (13431, 10900);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `PrevQuestID`, `ExclusiveGroup`) VALUES (13431, 70, 10900, 13431), (10900, 70, 0, 0);
UPDATE `quest_template_addon` SET `ExclusiveGroup`=13431 WHERE `ID`=10901;
