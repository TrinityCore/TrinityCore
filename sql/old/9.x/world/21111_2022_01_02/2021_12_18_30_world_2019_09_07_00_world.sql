-- 
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=13381;
DELETE FROM `quest_template_addon` WHERE `ID` IN (13404, 13382);
INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`, `SpecialFlags`) VALUES
(13404, 13380,1),
(13382, 13381,1);
UPDATE `quest_template_addon` SET `PrevQuestID`=13374  WHERE `id`=13376;
DELETE FROM `player_factionchange_quests` WHERE `alliance_id`=13404;
INSERT INTO `player_factionchange_quests` (`alliance_id`, `horde_id`) VALUES
(13404, 13406);
