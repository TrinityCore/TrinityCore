-- Quest 62 The Fargodeep Mine should not be shown if player is holding quest 54 Report to Goldshire (which is autocompleted)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` =19  AND `SourceEntry` = 62 AND `ConditionTypeOrReference` = 28;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(19, 0, 62, 0, 0, 28, 0, 54, 0, 0, '', 1, 0, 0, '', 'The Fargodeep Mine quest not visible if Report to Goldshire is Complete');

-- Add missing areatrigger_involvedrelation for quest credit in upper Fargodeep Mine
DELETE FROM `areatrigger_involvedrelation` WHERE `id` = 197 AND `quest` = 62;
INSERT INTO `areatrigger_involvedrelation` (`id`, `quest`) VALUES 
(197, 62);
