-- Removing unnecessary requirement:
-- Player should be able to get @QUEST_MURDER_WAS_THE_CASE_THEY_GAVE_ME without having to complete
-- @QUEST_HEROS_CALL_WESTFALL_OBTAINED_FROM_NPC or @QUEST_HEROS_CALL_WESTFALL_OBTAINED_FROM_HCB

UPDATE `quest_template` SET `RewardNextQuest` = 0 WHERE `id` IN ( 26378, 28562 );
UPDATE `quest_template_addon` SET `NextQuestId` = 0 WHERE `id` IN ( 26378, 28562 );

-- But Player should NOT be able to get either quest if he has already completed the quest 'Murder Was The Case They Gave Me'
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry` IN (26378, 28562);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
( 19, 0, 26378, 0, 0, 8, 0, 26209, 0, 0, 1, 0, 0, '', 'Checks if Player has not been rewarded quest' ),
( 19, 0, 28562, 0, 0, 8, 0, 26209, 0, 0, 1, 0, 0, '', 'Checks if Player has not been rewarded quest' );

-- Fixing QuestType which was set incorrectly to '1' thus disabling the quest
UPDATE `quest_template` SET `QuestType` = 2 WHERE `id` = 28562;

-- Removing unnecessary requirement. Player should be able to get the quests
-- @QUEST_THE_FORSAKEN_FROM_NPC and @QUEST_THE_FORSAKEN_FROM_WCB without having to complete @QUEST_WARCHIEFS_COMMAND_GHOSTLANDS beforehand.

UPDATE `quest_template` SET `RewardNextQuest` = 0 WHERE `id` = 28560;
UPDATE `quest_template_addon` SET `PrevQuestId` = 0 WHERE `id` IN (9327, 9329);

-- But the Player should NOT be able to get the quest @QUEST_WARCHIEFS_COMMAND_GHOSTLANDS
-- if he has already completed @QUEST_THE_FORSAKEN_FROM_NPC or @QUEST_THE_FORSAKEN_FROM_WCB
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry` IN (28560);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 28560, 0, 0, 8, 0, 9327, 0, 0, 1, 0, 0, '', 'Makes quest available if-and-only-if Player has not completed another quest beforehand' ),
(19, 0, 28560, 0, 1, 8, 0, 9329, 0, 0, 1, 0, 0, '', 'Makes quest available if-and-only-if Player has not completed another quest beforehand' );
