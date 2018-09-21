-- 
DELETE FROM `creature_queststarter` WHERE `quest`=10888;

DELETE FROM `quest_template_addon` WHERE `ID` IN (10888, 13430);
INSERT INTO `quest_template_addon` (`ID`, `ExclusiveGroup`) VALUES
(10888, 10888),
(13430, 10888);

UPDATE `quest_template_addon` SET `NextQuestID`=13430 WHERE `ID` IN (10884, 10885, 10886);
