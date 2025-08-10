-- Gameobject
UPDATE `gameobject_template_addon` SET `flags`=65572 WHERE `entry`=210986; -- Edict of Temperance
UPDATE `gameobject_template` SET `ScriptName`='go_edict_of_temperance' WHERE `entry`=210986; -- Edict of Temperance
UPDATE `gameobject` SET `zoneId`=5736, `areaId`=5834, `spawntimesecs`=5, `VerifiedBuild`=53441 WHERE `id` = 210986; -- Edict of Temperance

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=122484 AND `ConditionTypeOrReference`=51 AND `ConditionValue2`=210986;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 122484, 0, 0, 51, 0, 8, 210986, 0, '', 0, 0, 0, '', 'Forced Open Edict of Temperance can only target Edict of Temperance');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 34 AND `SourceEntry` = 15642);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(34, 0, 15642, 0, 0, 47, 0, 29408, 8, 0, 0, 0, 0, '', 'Satisfy PlayerCondition 15642 if quest 29408 is in progress');

-- Areatrigger
DELETE FROM `areatrigger_scripts` WHERE `entry` = 8085;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(8085, 'SmartTrigger');

DELETE FROM `smart_scripts` WHERE `source_type` = 2 AND `entryOrGuid` = 8085;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8085, 2, 0, 0, 46, 0, 100, 0, 0, 0, 0, 0, 85, 122486, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On trigger - self: Cast spell 122486 on Invoker');

-- Trigger Condition
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 8085);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 8085, 2, 0, 47, 0, 29408, 8, 0, 0, 0, 0, '', 'SAI AreaTrigger needs Quest 29408 in Progress'),
(22, 1, 8085, 2, 0, 48, 0, 252345, 0, 0, 0, 0, 1, '', 'SAI AreaTrigger needs Objective 252345 not rewarded');
