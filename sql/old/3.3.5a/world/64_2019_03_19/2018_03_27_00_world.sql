-- 
UPDATE `quest_template_addon` SET `PrevQuestID`=10956 WHERE `ID`=10968;
DELETE FROM `creature_queststarter` WHERE `quest` IN (10968);
DELETE FROM `game_event_creature_quest` WHERE `quest` IN (10968);
INSERT INTO `game_event_creature_quest` (`eventEntry`, `id`, `quest`) VALUES
(10,17538,10968);
