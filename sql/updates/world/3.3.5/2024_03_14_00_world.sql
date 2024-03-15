-- Cast aura 70193 on player if one of the following conditions are meet
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 17 AND `SourceGroup` = 0 AND `SourceEntry` = 70193;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 70193, 0, 1, 8, 0, 24480, 0, 0, 0, 0, 0, '', "Cast aura 70193 on player only if quest The Halls Of Reflection Alliance rewarded"),
(17, 0, 70193, 0, 2, 47, 0, 24522, 74, 0, 0, 0, 0, '', "Cast aura 70193 on player only if quest Journey To The Sunwell Alliance progress, completed or rewarded"),
(17, 0, 70193, 0, 3, 47, 0, 24535, 74, 0, 0, 0, 0, '', "Cast aura 70193 on player only if quest Thalorien Dawnseeker Alliance progress, completed or rewarded"),
(17, 0, 70193, 0, 4, 8, 0, 24561, 0, 0, 0, 0, 0, '', "Cast aura 70193 on player only if quest The Halls Of Reflection Horde rewarded"),
(17, 0, 70193, 0, 5, 47, 0, 24562, 74, 0, 0, 0, 0, '', "Cast aura 70193 on player only if quest Journey To The Sunwell Horde progress, completed or rewarded"),
(17, 0, 70193, 0, 6, 47, 0, 24563, 74, 0, 0, 0, 0, '', "Cast aura 70193 on player only if quest Thalorien Dawnseeker Horde progress, completed or rewarded");

--
DELETE FROM `spell_area` WHERE `spell`=70193 AND `quest_start` IN (24535,24563);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(70193, 4092, 24535, 24535, 0, 0, 2, 1, 75, 75),
(70193, 4092, 24563, 24563, 0, 0, 2, 1, 75, 75);

--
UPDATE `spell_area` SET `quest_start_status`=75,`quest_end_status`=75 WHERE `spell`=70193 AND `area`=4094;
