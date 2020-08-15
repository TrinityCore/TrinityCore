--
SET @CGUID := 142219;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=27047;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=31702;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+7 AND `id`IN(27047,31731);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`,  `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 31731, 571, 0, 0, 1, 1, 0, 0, 7899.34814453125, 896.13922119140625, 454.79254150390625, 1.954768776893615722, 300, 0, 0, 0, 0, 0, 0, 0, 0, 14007), -- 31731 (Area: -1 - Difficulty: 0)
(@CGUID+1, 31731, 571, 0, 0, 1, 1, 0, 0, 7907.4541015625, 910.4288330078125, 454.8382568359375, 3.193952560424804687, 300, 0, 0, 0, 0, 0, 0, 0, 0, 14007), -- 31731 (Area: -1 - Difficulty: 0)
(@CGUID+2, 31731, 571, 0, 0, 1, 1, 0, 0, 7885.07275390625, 897.81597900390625, 453.8397216796875, 0.942477762699127197, 300, 0, 0, 0, 0, 0, 0, 0, 0, 14007), -- 31731 (Area: -1 - Difficulty: 0)
(@CGUID+3, 31731, 571, 0, 0, 1, 1, 0, 0, 7885.8046875, 923.5858154296875, 453.180999755859375, 5.201081275939941406, 300, 0, 0, 0, 0, 0, 0, 0, 0, 14007), -- 31731 (Area: -1 - Difficulty: 0)
(@CGUID+4, 31731, 571, 0, 0, 1, 1, 0, 0, 7878.15380859375, 911.84918212890625, 453.214508056640625, 6.143558979034423828, 300, 0, 0, 0, 0, 0, 0, 0, 0, 14007), -- 31731 (Area: -1 - Difficulty: 0)
(@CGUID+5, 27047, 571, 0, 0, 1, 1, 0, 0, 7891.8447265625, 910.00311279296875, 451.374847412109375, 3.420845270156860351, 300, 0, 0, 0, 0, 0, 0, 0, 0, 14007), -- 27047 (Area: -1 - Difficulty: 0)
(@CGUID+6, 27047, 571, 0, 0, 1, 1, 0, 0, 7885.470703125, 910.68682861328125, 451.404388427734375, 0.767944872379302978, 300, 0, 0, 0, 0, 0, 0, 0, 0, 14007), -- 27047 (Area: -1 - Difficulty: 0)
(@CGUID+7, 27047, 571, 0, 0, 1, 1, 0, 0, 7896.4130859375, 902.90802001953125, 451.40155029296875, 5.98647928237915039, 300, 0, 0, 0, 0, 0, 0, 0, 0, 14007); -- 27047 (Area: -1 - Difficulty: 0)

DELETE FROM `smart_scripts` WHERE `entryorguid`=31731 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=31702 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3170200 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(-123663,-123665,-123667,-123662,-123669,-123666,-123668,-123660,-@CGUID-5,-@CGUID-6,-@CGUID-7) AND `source_type`=0;

DELETE FROM `creature_template_addon` WHERE `entry`=31702;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`, `visibilityDistanceType`) VALUES
(31702, 0, 0, 50331648, 1, 0, NULL,  0);

DELETE FROM `disables` WHERE `sourceType`=0 AND `entry`=59661;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(0, 59661, 64, '', '', 'Icecrown Purple Beam (Ignore Los)');

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(31731, 0, 0, 0, 0, 0, 100, 0, 5000, 9000, 15000, 15000, 11, 32063, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Wyrm Reanimator - IC - Cast Corruption'),
(31731, 0, 1, 0, 0, 0, 100, 0, 1000, 1000, 3000, 4000, 11, 9613, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Wyrm Reanimator - IC CMC - Cast Shadowbolt'),
(31731, 0, 2, 0, 0, 0, 100, 0, 4000, 7000, 16000, 22000, 11, 11443, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Wyrm Reanimator - IC - Cast Cripple'),
(31731, 0, 3, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 59661, 0, 0, 0, 0, 0, 19, 27047, 0, 0, 0, 0, 0, 0, 'Wyrm Reanimator - On Reset - Cast Icecrown Purple Beam'),
(31731, 0, 4, 5, 38, 0, 100, 0, 1, 1, 0, 0, 92, 0, 59661, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wyrm Reanimator - On Data Set - Interupt Cast'),
(31731, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 52385, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wyrm Reanimator - On Data Set - Cast Periodic Cower Effect'),
(31702, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 19, 31731, 0, 0, 0, 0, 0, 0, 'Frost Brood Spawn - On Just Summoned - Store Target'),
(31702, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 60, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Frost Brood Spawn - On Just Summoned - Disable Gravity'),
(31702, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 3170200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Frost Brood Spawn - On Just Summoned - Run Script'),
(31702, 0, 4, 5, 34, 0, 100, 0, 0, 1, 0, 0, 11, 36380, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Frost Brood Spawn - On Movement Inform - Cast Special Unarmed'),
(31702, 0, 5, 6, 61, 0, 100, 0, 0, 1, 0, 0, 86, 52391, 2, 12, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Frost Brood Spawn - On Movement Inform - Cross Cast Ride Vehicle'),
(31702, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 7326.43, 1289.52, 611.652, 0, 'Frost Brood Spawn - On Movement Inform - Move to Position'),
(3170200, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Frost Brood Spawn - Script - Set Data 1 1'),
(3170200, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Frost Brood Spawn - Script - Set Active'),
(3170200, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 69, 1, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Frost Brood Spawn - Script - Move to positiom'),
(3170200, 9, 4, 0, 0, 0, 100, 0, 15000, 15000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Frost Brood Spawn - Script - Despawn Wyrm reanimator'),
(3170200, 9, 5, 0, 0, 0, 100, 0, 110000, 110000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Frost Brood Spawn - Script - Despawn'),
(-@CGUID-6, 0, 0, 0, 1, 0, 100, 0, 180000, 300000, 660000, 900000, 12, 31702, 1, 120000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Invisible Stalker (Floating Only) - OOC - Summon Frost Brood Spawn'),
(-123660, 0, 0, 0, 1, 0, 100, 0, 180000, 300000, 660000, 900000, 12, 31702, 1, 120000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Invisible Stalker (Floating Only) - OOC - Summon Frost Brood Spawn'),
(-123669, 0, 0, 0, 1, 0, 100, 0, 180000, 300000, 660000, 900000, 12, 31702, 1, 120000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Invisible Stalker (Floating Only) - OOC - Summon Frost Brood Spawn'),
(-123663, 0, 0, 0, 1, 0, 100, 0, 180000, 300000, 660000, 900000, 12, 31702, 1, 120000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Invisible Stalker (Floating Only) - OOC - Summon Frost Brood Spawn');
