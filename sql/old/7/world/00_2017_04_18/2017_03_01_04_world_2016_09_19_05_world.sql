--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=35460;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 35460, 0, 0, 31, 1, 3, 19354, 0, 0, 0, 0, "", "Spell 'Fury of the Dreghood Elders' can only be used on NPC 'Arzeth the Merciless'");

UPDATE `smart_scripts` SET `action_type`=1, `action_param1`=0 WHERE `entryorguid`=19354 AND `id`=4;
UPDATE `creature_text` SET `groupid`=0 WHERE `entry`=20680;
DELETE FROM `smart_scripts` WHERE `entryorguid`=19354 AND `id`=5;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(19354, 0, 5, 0, 25, 0, 100, 0, 0, 0, 0, 0, 36, 19354, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Arzeth the Merciless - On Reset - Update Template To 'Arzeth the Merciless'");
