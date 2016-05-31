--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=49859;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 49859, 0, 0, 31, 1, 3, 23725, 0, 0, 0, 0, '', NULL);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=43546;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 43546, 0, 0, 31, 0, 3, 24336, 0, 0, 0, 0, '', 'Runed Orb Targets Orb Target');

UPDATE `creature` SET `MovementType`=0 WHERE  `guid` IN (97715,97748);

UPDATE `creature_template` SET AIName='SmartAI' WHERE `entry`=24335;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=24335 AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(24335, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 11, 43546, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Runed Orb - On Spawn - Cast Runed Orb");

UPDATE `creature_template` SET AIName='SmartAI' WHERE `entry`=23725;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=23725 AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(23725, 0, 0, 1, 8, 0, 100, 0, 49859, 0, 0, 0, 11, 43564, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Stone Giant - On Spellhit - Cast Captive Stone Giant Kill Credit"),
(23725, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Stone Giant - On Spellhit - Evade");

UPDATE `creature_template` SET AIName='SmartAI' WHERE `entry`=24345;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=24345 AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(24345, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 11, 43312, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Captive Stone Giant - On Spawn - Cast Elemental Prison (Cosmetic)");

UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry`=24336;
