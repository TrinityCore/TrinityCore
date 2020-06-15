DELETE FROM `disables` WHERE `entry`=5209 AND `sourceType`=1;

UPDATE `quest_template` SET `Flags`=1024 WHERE `id`=5209;

DELETE FROM `quest_template_addon` WHERE `ID` IN (5382);
INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`) VALUES
(5382, 5209);

UPDATE `smart_scripts` SET `action_param1`=5209, `action_param2`=1 WHERE `entryorguid` IN(11216) AND `source_type`=0 AND `id`=3;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (3310) AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 3310, 0, 0, 0, 8, 0, 5209, 0, 0, 1, 0, 0, '', 'Gossip Option requires 5209 not rewarded');
