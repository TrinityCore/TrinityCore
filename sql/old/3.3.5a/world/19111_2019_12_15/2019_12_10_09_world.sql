-- 
DELETE FROM `creature` WHERE `guid` IN (60772,63093,120645,120646,120647,120672,120673,120674);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(60772, 35097, 571, 1, 1, 0, 0, 8462.0263, 1606.0546, 671.071, 3.353651, 180, 0, 0, 0, 0, 0),
(63093, 35097, 571, 1, 1, 0, 0, 8462.08, 1570.52, 670.028, 2.70526, 180, 0, 0, 0, 0, 0),
(120645, 35097, 571, 1, 1, 0, 0, 8459.2, 1611.21, 670.028, 1.91986, 180, 0, 0, 0, 0, 0),
(120646, 34728, 571, 1, 1, 0, 1, 8465.8388, 1606.368, 669.9461, 0.164148, 300, 0, 0, 0, 0, 0),
(120647, 34728, 571, 1, 1, 0, 1, 8462.0595, 1633.897, 671.2108, 5.337571, 300, 0, 0, 0, 0, 0),
(120672, 34734, 571, 1, 1, 0, 1, 8543.9501, 1504.7854, 642.151, 1.068919, 300, 0, 0, 0, 0, 0),
(120673, 35444, 571, 1, 1, 0, 1, 8464.755, 1588.085, 673.1536, 0.1745329, 300, 0, 0, 0, 0, 0),
(120674, 38751, 571, 1, 1, 0, 0, 8464.708, 1587.946, 670.0728, 0, 120, 0, 0, 0, 0, 0);

UPDATE `creature_template_addon` SET `auras`=66763  WHERE `entry`=38751;
DELETE FROM `creature_template_addon` WHERE `entry`=35444;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(35444, 0, 0, 8, 1, 0, '');

DELETE FROM `creature_template_movement` WHERE `CreatureID` IN (38751);
INSERT INTO `creature_template_movement` (`CreatureId`, `Flight`) VALUES (38751,1);

UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `id` IN (35106,34810);
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|768 WHERE `entry` IN (35444);
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=35106;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (34734) AND `source_type`=0 AND `id`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (34808) AND `source_type`=0 AND `id`=3;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-56281,-56218) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(34734, 0, 2, 0, 23, 0, 100, 1, 67040, 1, 0, 0, 0, 11, 67040, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Ritualist - Has Aura - Cast Spell'),
(34808, 0, 3, 0, 1, 0, 100, 0, 1000, 2000, 15000, 17000, 0, 11, 66256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Ritualist - Ooc - Cast Spell Eye Channel'),
(-56281, 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 5000, 7000, 0, 11, 60857, 64, 0, 0, 0, 0, 10, 60772, 35097, 0, 0, 0, 0, 0, 'Black Knight Caster - On reset - Cast Spell Drain Soul Visual'),
(-56218, 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 5000, 7000, 0, 11, 60857, 64, 0, 0, 0, 0, 10, 54610, 35097, 0, 0, 0, 0, 0, 'Black Knight Caster - On reset - Cast Spell Drain Soul Visual');

UPDATE `creature` SET `modelid`=0, `MovementType`=0, `spawndist`=0 WHERE `id`=35097;
DELETE FROM `creature_addon` WHERE `guid` IN (54536,120672,60772,63093,120645,120646,120647,120672);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(120672, 0, 0, 0, 1, 0, '67040'),
(120646, 0, 0, 0, 1, 375, ''),
(120647, 0, 0, 0, 1, 375, '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=66256;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition` ,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,66256,0,0,31,0,3,34810,0,0,0,'','Eye Channel');
