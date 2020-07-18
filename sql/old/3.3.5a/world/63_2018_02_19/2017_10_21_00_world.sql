DELETE FROM `smart_scripts` WHERE `entryorguid`=26452 AND `id` IN (3, 4) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(26452, 0, 3, 0, 25, 0, 100, 512, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0,  0, 0, 0, 0, 0, "Leviroth - On Reset - Add Unit flags (Immune to NPC and PC)"),
(26452, 0, 4, 0, 0, 0, 100, 0, 5000, 10000, 7000, 9000, 11, 19643, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Leviroth - In Combat - Cast 'Mortal Strike'");

UPDATE `item_template` SET `ScriptName`="" WHERE `entry`=35850;
UPDATE `creature_template` SET `InhabitType`=2 WHERE `entry`=26452;

DELETE FROM `conditions` WHERE `SourceEntry`=47170 AND `SourceTypeOrReferenceId`=17;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `comment`) VALUES
(17, 0, 47170, 0, 0, 29, 0, 26452, 8, 0, 0, 0, 0, "", "Spell Impale Leviroth can only be used within 8 yards of NPC Leviroth");
