-- Editing the SmartAI script of [Creature] ENTRY 129110 (name: Gentle Goat)

-- Table creature_template
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 129110;

-- Table smart_scripts
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 129110);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(129110, 0, 0, 0, 8, 0, 100, 0, 256323, 0, 0, 0, '', 56, 155681, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Gentle Goat - On Spellhit \'256323\' - Add Item \'155681\'  1 Time');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = '17' AND `SourceGroup` = '0' AND `SourceEntry` = '256323' AND `SourceId` = '0' AND `ElseGroup` = '0' AND `ConditionTypeOrReference` = '1' AND `ConditionTarget` = '1' AND `ConditionValue1` = '260134' AND `ConditionValue2` = '0' AND `ConditionValue3` = '0'; 
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
('17','0','256323','0','0','1','1','260134','0','0','1','0','0','',NULL);
