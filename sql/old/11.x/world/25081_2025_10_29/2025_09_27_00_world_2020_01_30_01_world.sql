DELETE FROM `creature` WHERE `guid` IN (290983, 276237, 275702, 275704, 275497, 275496, 275274, 275275, 275809, 308009, 280400);
DELETE FROM `creature_addon` WHERE `guid` IN (290983, 276237, 275702, 275704, 275497, 275496, 275274, 275275, 275809, 308009, 280400);

-- Creature Overloaded Harvest Golem 42381 SAI
SET @ENTRY := 42381;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 3000, 6000, 3500, 6000, 11, 79084, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 3000 and 6000 ms (and later repeats every 3500 and 6000 ms) - Self: Cast spell Unbound Energy (79084) on Self // ");

DELETE FROM `conditions` WHERE `SourceEntry`= 79084 AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 79084, 0, 0, 31, 0, 3, 42381, 0, 0, 0, '', 'Unbound Energy - Target Overloaded Harvest Golem');

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_westfall_unbound_energy';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(79084, 'spell_westfall_unbound_energy');
