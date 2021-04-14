--
SET @GHOST := 85732;

UPDATE `creature_template` SET  `AIName`='SmartAI' WHERE `entry`=6492;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (6492, 649200);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6492, 0, 1, 2, 8, 0, 100, 0, 9095, 0, 0, 0, 28, 34426, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rift Spawn - On Spellhit - Remove Aura'),
(6492, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 28, 9095, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rift Spawn - On Spellhit - Remove Aura'),
(6492, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 11, 9096, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rift Spawn - On Spellhit - Cast Rift Spawn Manifestation'),
(6492, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Rift Spawn - On Spellhit - Attack ActionInvoker'),
(6492, 0, 5, 6, 11, 0, 100, 0, 0, 0, 0, 0, 11, 34426, 19, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rift Spawn - on spawn - add aura'),
(6492, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 19, 33685508, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rift Spawn - On spawn - remove Flag'),
(6492, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 2, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rift Spawn - on spawn - set faction'),
(6492, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rift Spawn - on Spawn - Set Invincible HP'),
(6492, 0, 9, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 34426, 19, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rift Spawn - on reset - add aura'),
(6492, 0, 10, 11, 2, 0, 100, 1, 0, 1, 0, 0, 2, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rift Spawn - on 1% Hp - set faction'),
(6492, 0, 11, 12, 61, 0, 100, 0, 0, 0, 0, 0, 18, 33685508, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rift Spawn - on 1% HP - add flag'),
(6492, 0, 12, 13, 61, 0, 100, 0, 0, 0, 0, 0, 11, 9032, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rift Spawn - On On 1% HP - Cast Self Stun - 30 seconds'),
(6492, 0, 13, 14, 61, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rift Spawn - On 1% HP - Set Phase 2'),
(6492, 0, 14, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 31000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rift Spawn - On 1% HP - despawn'),
(6492, 0, 15, 16, 38, 0, 100, 0, 1, 1, 0, 0, 12, 23837, 1, 15000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rift Spawn - on data 1|1 - Spawn ELM General Purpose Bunny'),
(6492, 0, 16, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 32, 32, 0, 0, 0, 0, 19, 23837, 0, 0, 0, 0, 0, 0, 'Rift Spawn - On 1% HP - Set Data ELM General Purpose Bunny'),
(6492, 0, 17, 0, 38, 0, 100, 0, 2, 2, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rift Spawn - on data 2|2 - Set Invisible'),
(6492, 0, 18, 19, 25, 0, 100, 0, 0, 0, 0, 0, 2, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rift Spawn - on reset - set faction'),
(6492, 0, 19, 0, 61, 0, 100, 0, 0, 0, 0, 0, 19, 33685508, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rift Spawn - on reset - remove aura'),
(6492, 0, 20, 0, 4, 0, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rift Spawn - On Aggro - Say Line 0'),
(6492, 0, 21, 0, 7, 2, 100, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rift Spawn - On Evade (Phase 2)  - Say line 1');

DELETE FROM `creature_text` WHERE `entry`=6492;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES 
(6492, 0, 0, '%s is angered and attacks!', 16, 0, 100, 0, 0, 0, 'Rift Spawn', 3074),
(6492, 1, 0, '%s escapes into the void!', 16, 0, 100, 0, 0, 0, 'Rift Spawn', 2564);

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=122088;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (122088, 12208800);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(122088, 1, 0, 0, 1, 0, 100, 1, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 6492, 1, 0, 0, 0, 0, 0, 'Containment Coffer - On reset - Set data to Rift Spawn'),
(122088, 1, 1, 0, 1, 0, 100, 1, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 6492, 1, 0, 0, 0, 0, 0, 'Containment Coffer - On reset - Set data to Rift Spawn'),
(122088, 1, 2, 0, 1, 0, 100, 1, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Containment Coffer - On reset - activate self'),
(122088, 1, 3, 0, 1, 0, 100, 1, 4000, 4000, 4000, 4000, 44, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Containment Coffer - On reset - set phasemask');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=6492;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 16, 6492, 0, 0, 38, 1, 1, 4, 0, 0, 0, 0, '', 'Rift Spawn - Only run SAI if Rift Spawn hp at 1% or lower'),
(22, 18, 6492, 0, 0, 38, 1, 1, 4, 0, 0, 0, 0, '', 'Rift Spawn - Only run SAI if Rift Spawn hp at 1% or lower'),
(22, 16, 6492, 0, 0, 1, 1, 9032, 0, 0, 0, 0, 0, '', 'Rift Spawn - Only run SAI if Rift Spawn is stuned'),
(22, 18, 6492, 0, 0, 1, 1, 9032, 0, 0, 0, 0, 0, '', 'Rift Spawn - Only run SAI if Rift Spawn is stuned');

DELETE FROM `smart_scripts` WHERE `entryorguid`=23837 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(23837, 0, 2, 0, 38, 0, 100, 1, 32, 32, 0, 0, 11, 9010, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny - On Data Set - Cast Create Filled Containment Coffer');

DELETE FROM `disables` WHERE `sourceType`=0 AND `entry`=9095;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES 
(0, 9095, 64, '', '', 'Ignore LOS on  Cantation of Manifestation');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=9082;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(17, 0, 9082, 0, 0, 29, 0, 6492, 10, 0, 0, 0, 0, '', 'Create Containment Coffer can only be cast if there is rift spawn near');

DELETE FROM `creature` WHERE `id`=6492 AND `guid` BETWEEN @GHOST AND @GHOST+7;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
-- Undercity
(@GHOST, 6492, 0, 1, 1, 0, 0, 1414.51, 365.095, -66.0066, 4.99293, 300, 0, 0, 386, 0, 0, 0, 0, 0),
(@GHOST+1, 6492, 0, 1, 1, 0, 0, 1406.47, 369.853, -66.0231, 5.29334, 300, 0, 0, 356, 0, 0, 0, 0, 0),
(@GHOST+2, 6492, 0, 1, 1, 0, 0, 1400.28, 366.915, -66.0388, 5.57844, 300, 0, 0, 386, 0, 0, 0, 0, 0),
(@GHOST+3, 6492, 0, 1, 1, 0, 0, 1399.22, 362.385, -66.0382, 5.77244, 300, 0, 0, 386, 0, 0, 0, 0, 0),
-- Stormwind (Quest removed on cata, no sniffs)
(@GHOST+4, 6492, 0, 1, 1, 0, 0, -9090.36, 838.109, 115.667, 0.231248, 300, 0, 0, 356, 0, 0, 0, 0, 0),
(@GHOST+5, 6492, 0, 1, 1, 0, 0, -9081.7, 817.472, 115.667, 0.394612, 300, 0, 0, 386, 0, 0, 0, 0, 0),
(@GHOST+6, 6492, 0, 1, 1, 0, 0, -9090.38, 818.76, 115.667, 0.456658, 300, 0, 0, 386, 0, 0, 0, 0, 0),
(@GHOST+7, 6492, 0, 1, 1, 0, 0, -9094.42, 828.962, 115.667, 0.270519, 300, 0, 0, 386, 0, 0, 0, 0, 0);
