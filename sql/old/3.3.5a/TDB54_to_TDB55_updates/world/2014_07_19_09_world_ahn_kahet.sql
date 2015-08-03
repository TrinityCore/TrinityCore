UPDATE `creature_template` SET `AIName`='PassiveAI', `ScriptName`='', `flags_extra`=0 WHERE `entry` IN (30172,30173);
DELETE FROM `spell_script_names` WHERE `ScriptName` LIKE 'spell_elder_nadox_guardian';

DELETE FROM `spell_script_names` WHERE `spell_id`=56159;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(56159,'spell_ahn_kahet_swarm');

DELETE FROM `creature_template_addon` WHERE `entry` IN (30176,30178,30338,31441,31448,31447);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(30176, 0, 0x0, 0x1, '56151'),
(30178, 0, 0x0, 0x1, '56158'),
(30338, 0, 0x0, 0x1, '56158'),
(31441, 0, 0x0, 0x1, '56151'),
(31448, 0, 0x0, 0x1, '56158'),
(31447, 0, 0x0, 0x1, '56158');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=56159;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,56159,0,0,31,0,3,30178,0,0,0,0,'','Swarm can only target Ahn''kahar Swarmer'),
(13,1,56159,0,1,31,0,3,30338,0,0,0,0,'','Swarm can only target Ahn''kahar Swarmer');

DELETE FROM `smart_scripts` WHERE `entryorguid`=30338 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30338,0,0,0,0,0,100,0,1000,1000,35000,45000,11,56354,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ahn''kahar Swarmer - In Combat - Cast ''Sprint''');
