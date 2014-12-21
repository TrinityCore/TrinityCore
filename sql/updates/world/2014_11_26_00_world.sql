UPDATE `smart_scripts` SET `target_type`=23 WHERE  `entryorguid`=24981 AND `source_type`=0 AND `id`=1 AND `link`=2;
UPDATE `smart_scripts` SET `target_type`=23 WHERE  `entryorguid`=24981 AND `source_type`=0 AND `id`=0 AND `link`=1;

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry`=24972;
DELETE FROM `smart_scripts` WHERE `entryorguid`=24972 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24972,0,0,0,8,0,100,0,44997,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Erratic Sentry - On Spellhit (Converting Sentry) - Despawn');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=44997;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 44997, 0, 0, 31, 1, 3, 24972, 0, 0, 0, 0, '', 'Converting Sentry Effect #1 targets Erratic Sentry');
