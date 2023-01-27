-- worgen chain Quest
UPDATE `creature_template` SET `npcflag` = 0 WHERE `entry` = 34884; -- not questgiver
DELETE FROM `creature_queststarter` WHERE `id`  IN (34884);

UPDATE `quest_template_addon` SET `ExclusiveGroup` = -14093, `NextQuestID`=14099 WHERE `ID` IN (14098, 14093);
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID`=14099;
