--
DELETE FROM `quest_template_addon` WHERE `ID`=25172;
INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`) VALUES
(25172, 25126);
UPDATE `quest_template` SET `AllowableRaces`=-1 WHERE `ID`=25126;
DELETE FROM `creature_queststarter` WHERE `id` IN (3098, 39317);
UPDATE `creature_template` SET `npcflag`=`npcflag` &~2 WHERE `entry` IN (3098, 39317);
