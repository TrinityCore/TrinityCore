SET @CGUID   := 106855; 

UPDATE `creature_template` SET `unit_flags`=33536 WHERE  `entry`=31029;
UPDATE `creature_template` SET `unit_flags`=33088 WHERE  `entry`=31016;
UPDATE `creature_template` SET  `unit_flags`=768 WHERE  `entry`=31083;
UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry` IN(31050,31030,31029,31087);
UPDATE `creature_template` SET `unit_flags`=256 WHERE  `entry`=31050;
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE  `entry`=31077;
UPDATE `creature_template_addon` SET `auras`='0' WHERE  `entry`=31083;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN(4020);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 4020, 0, 0, 31, 0, 3, 31077, 0, 0, 0, 0, '', '');

DELETE FROM `creature` WHERE `id`=31077;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+23 AND `id` IN(31030,31077);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 31030, 571, 1, 1, 7108.229, 4428.539, 837.9857, 4.782202, 120, 0, 0), -- 31030 (Area: 210) (Auras: 4366 - 4366) (possible waypoints or random movement)
(@CGUID+1, 31030, 571, 1, 1, 7092.146, 4431.81, 836.628, 4.590216, 120, 0, 0), -- 31030 (Area: 210) (Auras: 4366 - 4366) (possible waypoints or random movement)
(@CGUID+2, 31030, 571, 1, 1, 7118.42, 4432.598, 837.9554, 4.869469, 120, 0, 0), -- 31030 (Area: 210) (Auras: 4366 - 4366) (possible waypoints or random movement)
(@CGUID+3, 31030, 571, 1, 1, 7083.883, 4438.466, 834.9834, 4.572762, 120, 0, 0), -- 31030 (Area: 210) (Auras: 4366 - 4366) (possible waypoints or random movement)
(@CGUID+4, 31030, 571, 1, 1, 7111.272, 4445.171, 838.5065, 4.834562, 120, 0, 0), -- 31030 (Area: 210) (Auras: 4366 - 4366) (possible waypoints or random movement)
(@CGUID+5, 31030, 571, 1, 1, 7090.73, 4446.96, 837.0818, 3.402185, 120, 0, 0), -- 31030 (Area: 210) (Auras: 4366 - 4366)
(@CGUID+6, 31077, 571, 1, 1, 7081.854, 4311.559, 871.1456, 0.8552113, 120, 0, 0), -- 31077 (Area: 210)
(@CGUID+7, 31077, 571, 1, 1, 7097.221, 4343.909, 871.829, 4.24115, 120, 0, 0), -- 31077 (Area: 210)
(@CGUID+8, 31077, 571, 1, 1, 7073.036, 4321.123, 871.2318, 4.118977, 120, 0, 0), -- 31077 (Area: 210)
(@CGUID+9, 31077, 571, 1, 1, 7058.097, 4318.563, 871.0363, 2.216568, 120, 0, 0), -- 31077 (Area: 210)
(@CGUID+10, 31077, 571, 1, 1, 7069.263, 4307.413, 870.969, 3.769911, 120, 0, 0), -- 31077 (Area: 210)
(@CGUID+11, 31077, 571, 1, 1, 7091.653, 4324.766, 871.4558, 6.161012, 120, 0, 0), -- 31077 (Area: 210)
(@CGUID+12, 31077, 571, 1, 1, 7105.507, 4331.751, 871.8961, 5.270895, 120, 0, 0), -- 31077 (Area: 210)
(@CGUID+13, 31077, 571, 1, 1, 7081.499, 4355.459, 871.8806, 3.089233, 120, 0, 0), -- 31077 (Area: 210)
(@CGUID+14, 31077, 571, 1, 1, 7107.956, 4349.756, 872.166, 3.316126, 120, 0, 0), -- 31077 (Area: 210)
(@CGUID+15, 31077, 571, 1, 1, 7060.825, 4333.478, 871.3121, 2.565634, 120, 0, 0), -- 31077 (Area: 210)
(@CGUID+16, 31077, 571, 1, 1, 7077.684, 4338.44, 871.5625, 1.710423, 120, 0, 0), -- 31077 (Area: 210)
(@CGUID+17, 31077, 571, 1, 1, 7103.35, 4365.286, 872.2496, 2.792527, 120, 0, 0), -- 31077 (Area: 210)
(@CGUID+18, 31077, 571, 1, 1, 7069.498, 4374.775, 872.0762, 3.700098, 120, 0, 0), -- 31077 (Area: 210)
(@CGUID+19, 31077, 571, 1, 1, 7056.396, 4366.188, 871.9349, 4.415683, 120, 0, 0), -- 31077 (Area: 210)
(@CGUID+20, 31077, 571, 1, 1, 7088.755, 4385.249, 872.4426, 0.4014257, 120, 0, 0), -- 31077 (Area: 210)
(@CGUID+21, 31077, 571, 1, 1, 7084.891, 4370.708, 872.1652, 3.525565, 120, 0, 0), -- 31077 (Area: 210)
(@CGUID+22, 31077, 571, 1, 1, 7065.018, 4353.726, 871.6901, 5.899213, 120, 0, 0), -- 31077 (Area: 210)
(@CGUID+23, 31077, 571, 1, 1, 7048.843, 4346.518, 871.6175, 2.984513, 120, 0, 0); -- 31077 (Area: 210)

DELETE FROM `vehicle_template_accessory` WHERE `entry`=31050;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(31050, 31016, 0, 0, '31050 - 31016', 6, 30000); -- 31050 - 31016

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=31050;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(31050, 46598, 1, 0);

DELETE FROM `spell_group` WHERE `id`=4307;

DELETE FROM `spell_group_stack_rules` WHERE `group_id`=4307;

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+5;
INSERT INTO `creature_addon` (`guid`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(@CGUID+0, 26882, 0x3000000, 0x1, '4366'), -- 31030 - 4366 - 4366 0xF130793600719D57
(@CGUID+1, 26882, 0x3000000, 0x1, '4366'), -- 31030 - 4366 - 4366 0xF130793600719D58
(@CGUID+2, 26882, 0x3000000, 0x1, '4366'), -- 31030 - 4366 - 4366 0xF130793600719D59
(@CGUID+3, 26882, 0x3000000, 0x1, '4366'), -- 31030 - 4366 - 4366 0xF130793600719D5A
(@CGUID+4, 26882, 0x3000000, 0x1, '4366'), -- 31030 - 4366 - 4366 0xF130793600719D5B
(@CGUID+5, 26882, 0x3000000, 0x1, '4366'); -- 31030 - 4366 - 4366 0xF130793600719D5C

DELETE FROM `creature_template_addon` WHERE `entry` IN(31016,31083,31029,31050);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(31016, 0, 0x0, 0x1, '61081'), -- 31016 - 61081
(31083, 0, 0x0, 0x1, '34427'), -- 31083 - 34427
(31029, 0, 0x3000000, 0x1, '58102'), -- 31029 - 58102
(31050, 0, 0x3000000, 0x1, ''); -- 31050 - 4366

DELETE FROM `event_scripts` WHERE `id`=20108;
INSERT INTO `event_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(20108,0,10,31029,1800000,0,7116.824,4308.362,883.3842,2.46227),  -- Possessed Vardmadra 0xF130793500719D55
(20108,0,16,14969,0,0,0,0,0,0);  

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE  `entry`=193028;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`IN(31016,31029,31030,31050,31083,31087,31077);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`IN(31016,31029,31030,31050,31083,31087,31077);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` BETWEEN -@CGUID-5 AND -@CGUID-0;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`IN(3105000,3105001,3101600,3108300,3108301,19302800);
DELETE FROM `smart_scripts` WHERE `source_type`=1 AND `entryorguid`IN(193028);

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(31077, 0, 0, 0, 8, 0, 100, 0, 4020, 0, 0, 0, 11, 4307, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Safirdrangs Chill target - On Spell Hit Safirdrangs Chill - Cast Safirdrangs Chill'),
(31077, 0, 1, 2, 25, 0, 100, 0, 0, 0, 0, 0, 19, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Safirdrangs Chill target - On Reset - Set Unit Flags'),
(31077, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 2, 14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Safirdrangs Chill target - On Reset - Set Faction'),
(193028, 1, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 32, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'War Horn of Jotunheim - On Data Set - Reset Go'),
(31083, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, 3108300, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - On Just Summoned Run Script'),
(31083, 0, 1, 0, 38, 0, 100, 0, 1, 1, 0, 0, 53, 0, 3108300, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - On Data Set - Start WP (Path 2)'),
(31083, 0, 2, 0, 40, 0, 100, 0, 1, 3108300, 0, 0, 80, 3108301, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - On Reached WP1 (Path 2) - Run Script 2'),
(31083, 0, 3, 0, 40, 0, 100, 0, 4, 31083, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 4.468043, 'The Lich King - On Reached WP4 (Path 1) - Set Orientation'),
(31083, 0, 4, 5, 40, 0, 100, 0, 2, 31083, 0, 0, 54, 35600, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - On Reached WP2 (Path 1) - Set Pause WP'),
(31083, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 31029, 0, 0, 0, 0, 0, 0, 'The Lich King - On Reached WP2 (Path 1) - Face Possessed Vardmadra'),
(3108300, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 34427, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Cast Ethereal Teleport'), 
(3108300, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 45, 3, 3, 0, 0, 0, 0, 10, @CGUID+0, 31030, 0, 0, 0, 0, 0, 'The Lich King - Script - Despawn Balargarde Elite'), 
(3108300, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 10, @CGUID+1, 31030, 0, 0, 0, 0, 0, 'The Lich King - Script - Despawn Balargarde Elite'), 
(3108300, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 10, @CGUID+2, 31030, 0, 0, 0, 0, 0, 'The Lich King - Script - Despawn Balargarde Elite'), 
(3108300, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 10, @CGUID+3, 31030, 0, 0, 0, 0, 0, 'The Lich King - Script - Despawn Balargarde Elite'), 
(3108300, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 10, @CGUID+4, 31030, 0, 0, 0, 0, 0, 'The Lich King - Script - Despawn Balargarde Elite'), 
(3108300, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 10, @CGUID+5, 31030, 0, 0, 0, 0, 0, 'The Lich King - Script - Despawn Balargarde Elite'), 
(3108300, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 53274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Cast Icebound Visage'), 
(3108300, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 31029, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Face Possessed Vardmadra'), 
(3108300, 9, 9, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Say Line 0 '), 
(3108300, 9, 10, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 45, 3, 3, 0, 0, 0, 0, 19, 31029, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Set Data on Possessed Vardmadra'), 
(3108300, 9, 11, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Say Line 1 '), 
(3108300, 9, 12, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, 31083, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Start WP '), 
(3108300, 9, 13, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 31029, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Say Line 2 on Possessed Vardmadra '), 
(3108300, 9, 14, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Say Line 2 '), 
(3108300, 9, 15, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 11, 42904, 0, 0, 0, 0, 0, 19, 31029, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Cast Cosmetic - Combat Special Attack 2H (Whirlwind SFX) '), 
(3108300, 9, 16, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 31029, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Set Data on Possessed Vardmadra '), 
(3108300, 9, 17, 0, 0, 0, 100, 0, 600, 600, 0, 0, 45, 5, 5, 0, 0, 0, 0, 19, 31029, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Set Data on Possessed Vardmadra '), 
(3108300, 9, 18, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 4, 15714, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Play sound 15714'), 
(3108300, 9, 19, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Say Line 3 '), 
(3108300, 9, 20, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 31016, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Face Overthane Balargarde <Master of Jotunheim>'), 
(3108300, 9, 21, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 19, 31016, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Say Line 6 on Overthane Balargarde <Master of Jotunheim> '), 
(3108300, 9, 22, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Say Line 4 '), 
(3108300, 9, 23, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 7, 0, 0, 0, 0, 0, 19, 31016, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Say Line 7 on Overthane Balargarde <Master of Jotunheim> '), 
(3108300, 9, 24, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 45, 3, 3, 0, 0, 0, 0, 19, 31016, 0, 0, 0, 0, 0, 0, 'The Lich King - Script - Set Data on Overthane Balargarde <Master of Jotunheim> '), 
(3108301, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 4, 4, 0, 0, 0, 0, 19, 31050, 0, 0, 0, 0, 0, 0, 'The Lich King - Script 2 - Set Data on Safirdrang '), 
(3108301, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 21, 100, 0, 0, 0, 0, 0, 0, 'The Lich King - Script 2 - Face Player'), 
(3108301, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script 2 - Say Line 5'), 
(3108301, 9, 3, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script 2 - Say Line 6'), 
(3108301, 9, 4, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 11, 34427, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script 2 - Cast Ethereal Teleport'), 
(3108301, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, @CGUID+0, 31030, 0, 0, 0, 0, 0, 'The Lich King - Script 2 - Despawn Balargarde Elite'), 
(3108301, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, @CGUID+1, 31030, 0, 0, 0, 0, 0, 'The Lich King - Script 2 - Despawn Balargarde Elite'), 
(3108301, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, @CGUID+2, 31030, 0, 0, 0, 0, 0, 'The Lich King - Script 2 - Despawn Balargarde Elite'), 
(3108301, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, @CGUID+3, 31030, 0, 0, 0, 0, 0, 'The Lich King - Script 2 - Despawn Balargarde Elite'), 
(3108301, 9, 9, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, @CGUID+4, 31030, 0, 0, 0, 0, 0, 'The Lich King - Script 2 - Despawn Balargarde Elite'), 
(3108301, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, @CGUID+5, 31030, 0, 0, 0, 0, 0, 'The Lich King - Script 2 - Despawn Balargarde Elite'), 
(3108301, 9, 11, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 31050, 0, 0, 0, 0, 0, 0, 'The Lich King - Script 2 - Despawn Safirdrang'), 
(3108301, 9, 12, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, 31087, 0, 0, 0, 0, 0, 0, 'The Lich King - Script 2 - Despawn Lady Nightswood'), 
(3108301, 9, 13, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script 2 - Despawn'), 
(31087, 0, 0, 0, 1, 0, 100, 1, 20000, 20000, 0, 0, 53, 1, 31087, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - OOC (No repeat) - Start WP'),
(31087, 0, 1, 0, 40, 0, 100, 0, 3, 31087, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Reached WP3 - Despawn'),
(31087, 0, 2, 0, 54, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 31083, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Just Summoned - Face The Lich King'),
(31016, 0, 1, 2, 38, 0, 100, 0, 1, 1, 0, 0, 19, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overthane Balargarde <Master of Jotunheim> - On Data Set - Remove Flags Immune to PC'),
(31016, 0, 2, 3, 61, 0, 100, 0, 1, 1, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overthane Balargarde <Master of Jotunheim> - On Data Set - Set Home Position'),
(31016, 0, 3, 0, 61, 0, 100, 0, 1, 1, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 100, 0, 0, 0, 0, 0, 0, 'Overthane Balargarde <Master of Jotunheim> - On Data Set - Start Attack'),
(31016, 0, 4, 18, 4, 0, 100, 0, 0, 0, 0, 0, 42, 0, 49, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overthane Balargarde <Master of Jotunheim> - On Agro - Set Invincibility HP'),
(31016, 0, 5, 6, 7, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 31050, 0, 0, 0, 0, 0, 0, 'Overthane Balargarde <Master of Jotunheim>  - On Evade - Set Data Safirdrang'),
(31016, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, @CGUID+0, 31030, 0, 0, 0, 0, 0, 'Overthane Balargarde <Master of Jotunheim> - On Evade - Set Data Balargarde Elite'),
(31016, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, @CGUID+1, 31030, 0, 0, 0, 0, 0, 'Overthane Balargarde <Master of Jotunheim> - On Evade - Set Data Balargarde Elite'),
(31016, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, @CGUID+2, 31030, 0, 0, 0, 0, 0, 'Overthane Balargarde <Master of Jotunheim> - On Evade - Set Data Balargarde Elite'),
(31016, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, @CGUID+3, 31030, 0, 0, 0, 0, 0, 'Overthane Balargarde <Master of Jotunheim> - On Evade - Set Data Balargarde Elite'),
(31016, 0, 10, 11, 61, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, @CGUID+4, 31030, 0, 0, 0, 0, 0, 'Overthane Balargarde <Master of Jotunheim> - On Evade - Set Data Balargarde Elite'),
(31016, 0, 11, 12, 61, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, @CGUID+5, 31030, 0, 0, 0, 0, 0, 'Overthane Balargarde <Master of Jotunheim> - On Evade - Set Data Balargarde Elite'),
(31016, 0, 12, 22, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, 31029, 0, 0, 0, 0, 0, 0, 'Overthane Balargarde <Master of Jotunheim> - Evade - Despawn'),
(31016, 0, 13, 0, 38, 0, 100, 0, 2, 2, 0, 0, 28, 4366, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overthane Balargarde <Master of Jotunheim> - On Data Set - Set Visible'),
(31016,0,14,0,0,3,100,0,20000,30000,25000,32000,11,60108,0,0,0,0,0,5,0,0,0,0,0,0,0,"Overthane Balargarde - In Combat (Phase 1 & 2) - Cast 'Heroic Leap'"),
(31016,0,15,0,9,3,100,0,0,5,60000,90000,11,61076,0,0,0,0,0,1,0,0,0,0,0,0,0,"Overthane Balargarde - On Range (Phase 1 & 2) - Cast 'Whirlwind'"),
(31016,0,16,0,0,3,100,0,20000,25000,25000,30000,11,15043,0,0,0,0,0,2,0,0,0,0,0,0,0,"Overthane Balargarde - In Combat (Phase 1 & 2) - Cast 'Frostbolt'"),
(31016,0,17,0,0,3,100,0,15000,25000,25000,35000,11,61085,0,0,0,0,0,5,0,0,0,0,0,0,0,"Overthane Balargarde - In Combat (Phase 1 & 2) - Cast 'Blizzard'"),
(31016, 0, 18, 0, 61, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overthane Balargarde <Master of Jotunheim> - On Agro - Set Phase 1'),
(31016, 0, 19, 20, 2, 0, 100, 1, 0, 80, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overthane Balargarde <Master of Jotunheim> - At 80% HP - Say Line 4'),
(31016, 0, 20, 0, 61, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overthane Balargarde <Master of Jotunheim> - At 80% HP - Set Phase 2'),
(31016, 0, 21, 0, 2, 0, 100, 1, 0, 50, 0, 0, 80, 3101600, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overthane Balargarde <Master of Jotunheim> - At 50% HP - Run Script'),
(31016, 0, 22, 28, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, 31083, 0, 0, 0, 0, 0, 0, 'Overthane Balargarde <Master of Jotunheim> - On Agro - Set Phase 1'),
(31016, 0, 23, 24, 38, 0, 100, 0, 3, 3, 0, 0, 20, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overthane Balargarde <Master of Jotunheim> - On Data Set - Enable Attack'),
(31016, 0, 24, 25, 61, 0, 100, 0, 0, 0, 0, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overthane Balargarde <Master of Jotunheim> - On Data Set - Enable Comabt Movement'),
(31016, 0, 25, 26, 61, 0, 100, 0, 0, 0, 0, 0, 42, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overthane Balargarde <Master of Jotunheim> - On Data Set - Turn Invincebility HP Off'),
(31016, 0, 26, 33, 61, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overthane Balargarde <Master of Jotunheim> - On Data Set - Set Phase 1'),
(31016, 0, 27, 29, 6, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 31083, 0, 0, 0, 0, 0, 0, 'Overthane Balargarde <Master of Jotunheim> - On Death - Set Data on the Lich King'),
(31016, 0, 28, 29, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, 31087, 0, 0, 0, 0, 0, 0, 'Overthane Balargarde <Master of Jotunheim> - On Agro - Set Phase 1'),
(31016, 0, 29, 32, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 14, 62011, 193028, 0, 0, 0, 0, 0, 'Overthane Balargarde <Master of Jotunheim> - Link - Set Data on War Horn of Jotunheim'),
(31016,0,31,0,0,2,100,0,3000,5000,13000,14000,45,3,3,0,0,0,0,19,31050,0,0,0,0,0,0,"Overthane Balargarde - In Combat (Phase 2) - Set Data on Safirdrang"),
(31016, 0, 32, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overthane Balargarde <Master of Jotunheim> - On Agro - Set Phase 1'),
(31016, 0, 33, 0, 61, 0, 100, 0, 0, 0, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overthane Balargarde <Master of Jotunheim> - Script - Remove Bytes 1'), 
(31016, 0, 34, 0, 0, 4, 100, 0, 1000, 1000, 1000, 1000, 66, 0, 0, 0, 0, 0, 0, 19, 31083, 0, 0, 0, 0, 0, 0, 'Overthane Balargarde <Master of Jotunheim> - IC (Phase 3) - Face the Lich King'), 
(3101600, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overthane Balargarde <Master of Jotunheim> - Script - Set Phase 3'), 
(3101600, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overthane Balargarde <Master of Jotunheim> - Script - Stop Attack'), 
(3101600, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overthane Balargarde <Master of Jotunheim> - Script - Disable Combat Movement'), 
(3101600, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overthane Balargarde <Master of Jotunheim> - Script - Say Line 5'), 
(3101600, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 31083, 8, 0, 0, 0, 0, 8, 0, 0, 0, 7088.768, 4385.59, 872.4484, 4.468043, 'Overthane Balargarde <Master of Jotunheim> - Script - Summon The Lich King'), 
(3101600, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 18, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overthane Balargarde <Master of Jotunheim> - Script - Add Unit Flags UNIT_FLAG_NOT_SELECTABLE'), 
(3101600, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overthane Balargarde <Master of Jotunheim> - Script - Set Bytes 1'), 
(3101600, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 31083, 0, 0, 0, 0, 0, 0, 'Overthane Balargarde <Master of Jotunheim> - Script - Face the Lich King'), 
(3101600, 9, 8, 0, 0, 0, 100, 0, 100, 100, 0, 0, 19, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overthane Balargarde <Master of Jotunheim> - Script - Remove Unit Flags UNIT_FLAG_NOT_SELECTABLE'), 
(31029, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 53, 1, 31029, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Possessed Vardmadra - On Just Summoned - Start WP'),
(31029, 0, 1, 2, 40, 0, 100, 0, 4, 31029, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, @CGUID+0, 31030, 0, 0, 0, 0, 0, 'Possessed Vardmadra - On Reached WP4 - Set Data Balargarde Elite'),
(31029, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, @CGUID+1, 31030, 0, 0, 0, 0, 0, 'Possessed Vardmadra - On Reached WP4 - Set Data Balargarde Elite'),
(31029, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, @CGUID+2, 31030, 0, 0, 0, 0, 0, 'Possessed Vardmadra - On Reached WP4 - Set Data Balargarde Elite'),
(31029, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, @CGUID+3, 31030, 0, 0, 0, 0, 0, 'Possessed Vardmadra - On Reached WP4 - Set Data Balargarde Elite'),
(31029, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, @CGUID+4, 31030, 0, 0, 0, 0, 0, 'Possessed Vardmadra - On Reached WP4 - Set Data Balargarde Elite'),
(31029, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, @CGUID+5, 31030, 0, 0, 0, 0, 0, 'Possessed Vardmadra - On Reached WP4 - Set Data Balargarde Elite'),
(31029, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 31016, 0, 0, 0, 0, 0, 0, 'Possessed Vardmadra - On Just Summoned - Set Data Balargarde Elite'),
(31029, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 12, 31050, 8, 0, 0, 0, 0, 8, 0, 0, 0, 7097.292,4416.581,831.8486,4.485496, 'Possessed Vardmadra - On Data Set - Start WP Path 2'),
(31029, 0, 9, 10, 38, 0, 100, 0, 1, 1, 0, 0, 11, 58359, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Possessed Vardmadra - On Data Set - Cast Banshees Revenge: Summon Lady Nightswood'),
(31029, 0, 10, 16, 61, 0, 100, 0, 0, 0, 0, 0, 11, 51744, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Possessed Vardmadra - On Data Set - Cast Suicide (No Log)'),
(31029, 0, 12, 13, 38, 0, 100, 0, 3, 3, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Possessed Vardmadra - On Data Set - Set Bytes 1'),
(31029, 0, 13, 14, 61, 0, 100, 0, 0, 0, 0, 0, 53, 1, 3102900, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Possessed Vardmadra - On Data Set - Start WP (Path 2)'),
(31029, 0, 14, 0, 61, 0, 100, 0, 0, 0, 0, 0, 60, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Possessed Vardmadra - On Data Set - Turn Fly Off'),
(31029, 0, 15, 0, 40, 0, 100, 0, 4, 31029, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Possessed Vardmadra - On Reached WP4 - Say Line 0'),
(31029, 0, 16, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 15000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Possessed Vardmadra - On Data Set - Despawn after 15 seconds'),
(31029, 0, 17, 0, 38, 0, 100, 0, 5, 5, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Possessed Vardmadra - On Data Set - Say Line 3'),
(31050, 0, 0, 3, 54, 0, 100, 0, 0, 0, 0, 0, 53, 1, 31050, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Safirdrang - On Data Set - Start WP'),
(31050, 0, 1, 0, 40, 0, 100, 0, 6, 31050, 0, 0, 80, 3105000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Safirdrang - On Reached WP6 - Run Script'),
(31050, 0, 2, 0, 38, 0, 100, 0, 2, 2, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Safirdrang - On Data Set - Despawn'),
(31050, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 28, 4366, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Safirdrang - On Data Set - Set Visible'),
(31050, 0, 4, 0, 38, 0, 100, 0, 3, 3, 0, 0, 80, 3105001, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Safirdrang - On Data Set - Run Script'),
(31050, 0, 5, 0, 38, 0, 100, 0, 4, 4, 0, 0, 53, 1, 3105000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Safirdrang - On Data Set - Start WP (Path 2)'),
(31050, 0, 6, 0, 40, 0, 100, 0, 4, 3105000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Safirdrang - On Reached WP4 (Path 2) - Despawn'),
(3105001, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 21, 100, 0, 0, 0, 0, 0, 0, 'Safirdrang - Script 2 - Face Player'),
(3105001, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 4020, 0, 0, 0, 0, 0, 21, 100, 0, 0, 0, 0, 0, 0, 'Safirdrang - Script 2 - Cast Safirdrangs Chill'),
(3105001, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 21, 100, 0, 0, 0, 0, 0, 0, 'Safirdrang - Script 2 - Face Player'),
(3105000, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 31016, 0, 0, 0, 0, 0, 0, 'Safirdrang - Script - Say Line 1 on Overthane Balargarde'), -- 20:05:22.766
(3105000, 9, 1, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 31029, 0, 0, 0, 0, 0, 0, 'Safirdrang - Script - Say Line 1 on Possessed Vardmadra'), -- 20:05:28.375
(3105000, 9, 2, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 31016, 0, 0, 0, 0, 0, 0, 'Safirdrang - Script - Say Line 2 on Overthane Balargarde'), -- 20:05:34.422
(3105000, 9, 3, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, 31016, 0, 0, 0, 0, 0, 0, 'Safirdrang - Script - Say Line 3 on Overthane Balargarde'), -- 20:05:40.828
(3105000, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 46598, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Safirdrang - Script - Eject Overthane Balargarde'), -- 20:05:22.766
(3105000, 9, 5, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 31016, 0, 0, 0, 0, 0, 0, 'Safirdrang - Script - Eject Overthane Balargarde'), -- 20:05:22.766
(3105000, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Safirdrang - Script - Set Home Position'), -- 20:05:22.766
(-@CGUID-0, 0, 0, 3, 38, 0, 100, 0, 1, 1, 0, 0, 53, 1, 3103001, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - On Data Set - Start WP'),
(-@CGUID-1, 0, 0, 3, 38, 0, 100, 0, 1, 1, 0, 0, 53, 1, 3103002, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - On Data Set - Start WP'),
(-@CGUID-2, 0, 0, 3, 38, 0, 100, 0, 1, 1, 0, 0, 53, 1, 3103003, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - On Data Set - Start WP'),
(-@CGUID-3, 0, 0, 3, 38, 0, 100, 0, 1, 1, 0, 0, 53, 1, 3103004, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - On Data Set - Start WP'),
(-@CGUID-4, 0, 0, 3, 38, 0, 100, 0, 1, 1, 0, 0, 53, 1, 3103005, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - On Data Set - Start WP'),
(-@CGUID-5, 0, 0, 3, 38, 0, 100, 0, 1, 1, 0, 0, 53, 1, 3103006, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - On Data Set - Start WP'),
(-@CGUID-0, 0, 1, 0, 40, 0, 100, 0, 5, 3103001, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - On Reached WP5 - Set Phase 1'),
(-@CGUID-1, 0, 1, 0, 40, 0, 100, 0, 5, 3103002, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - On Reached WP5 - Set Phase 1'),
(-@CGUID-2, 0, 1, 0, 40, 0, 100, 0, 5, 3103003, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - On Reached WP5 - Set Phase 1'),
(-@CGUID-3, 0, 1, 0, 40, 0, 100, 0, 6, 3103004, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - On Reached WP6 - Set Phase 1'),
(-@CGUID-4, 0, 1, 0, 40, 0, 100, 0, 5, 3103005, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - On Reached WP5 - Set Phase 1'),
(-@CGUID-5, 0, 1, 0, 40, 0, 100, 0, 8, 3103006, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - On Reached WP8 - Set Phase 1'),
(-@CGUID-0, 0, 2, 0, 38, 0, 100, 0, 2, 2, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - On Data Set - Evade'),
(-@CGUID-1, 0, 2, 0, 38, 0, 100, 0, 2, 2, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - On Data Set - Evade'),
(-@CGUID-2, 0, 2, 0, 38, 0, 100, 0, 2, 2, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - On Data Set - Evade'),
(-@CGUID-3, 0, 2, 0, 38, 0, 100, 0, 2, 2, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - On Data Set - Evade'),
(-@CGUID-4, 0, 2, 0, 38, 0, 100, 0, 2, 2, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - On Data Set - Evade'),
(-@CGUID-5, 0, 2, 0, 38, 0, 100, 0, 2, 2, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - On Data Set - Evade'),
(-@CGUID-0, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 28, 4366, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - On Data Set - Remove Aura'),
(-@CGUID-1, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 28, 4366, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - On Data Set - Remove Aura'),
(-@CGUID-2, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 28, 4366, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - On Data Set - Remove Aura'),
(-@CGUID-3, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 28, 4366, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - On Data Set - Remove Aura'),
(-@CGUID-4, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 28, 4366, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - On Data Set - Remove Aura'),
(-@CGUID-5, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 28, 4366, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - On Data Set - Remove Aura'),
(-@CGUID-0, 0, 4, 0, 38, 0, 100, 0, 3, 3, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - On Data Set - Set Phase 2'),
(-@CGUID-1, 0, 4, 0, 38, 0, 100, 0, 3, 3, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - On Data Set - Set Phase 2'),
(-@CGUID-2, 0, 4, 0, 38, 0, 100, 0, 3, 3, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - On Data Set - Set Phase 2'),
(-@CGUID-3, 0, 4, 0, 38, 0, 100, 0, 3, 3, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - On Data Set - Set Phase 2'),
(-@CGUID-4, 0, 4, 0, 38, 0, 100, 0, 3, 3, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - On Data Set - Set Phase 2'),
(-@CGUID-5, 0, 4, 0, 38, 0, 100, 0, 3, 3, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - On Data Set - Set Phase 2'),
(-@CGUID-0, 0, 5, 0, 1, 1, 100, 0, 1000, 1000, 1000, 1000, 66, 0, 0, 0, 0, 0, 0, 19, 31029, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - OOC (Phase 1) - Face Possessed Vardmadra'),
(-@CGUID-1, 0, 5, 0, 1, 1, 100, 0, 1000, 1000, 1000, 1000, 66, 0, 0, 0, 0, 0, 0, 19, 31029, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - OOC (Phase 1) - Face Possessed Vardmadra'),
(-@CGUID-2, 0, 5, 0, 1, 1, 100, 0, 1000, 1000, 1000, 1000, 66, 0, 0, 0, 0, 0, 0, 19, 31029, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - OOC (Phase 1) - Face Possessed Vardmadra'),
(-@CGUID-3, 0, 5, 0, 1, 1, 100, 0, 1000, 1000, 1000, 1000, 66, 0, 0, 0, 0, 0, 0, 19, 31029, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - OOC (Phase 1) - Face Possessed Vardmadra'),
(-@CGUID-4, 0, 5, 0, 1, 1, 100, 0, 1000, 1000, 1000, 1000, 66, 0, 0, 0, 0, 0, 0, 19, 31029, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - OOC (Phase 1) - Face Possessed Vardmadra'),
(-@CGUID-5, 0, 5, 0, 1, 1, 100, 0, 1000, 1000, 1000, 1000, 66, 0, 0, 0, 0, 0, 0, 19, 31029, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - OOC (Phase 1) - Face Possessed Vardmadra'),
(-@CGUID-0, 0, 6, 0, 1, 2, 100, 0, 1000, 1000, 1000, 1000, 66, 0, 0, 0, 0, 0, 0, 19, 31083, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - OOC (Phase 2) - Face The Lich King'),
(-@CGUID-1, 0, 6, 0, 1, 2, 100, 0, 1000, 1000, 1000, 1000, 66, 0, 0, 0, 0, 0, 0, 19, 31083, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - OOC (Phase 2) - Face The Lich King'),
(-@CGUID-2, 0, 6, 0, 1, 2, 100, 0, 1000, 1000, 1000, 1000, 66, 0, 0, 0, 0, 0, 0, 19, 31083, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - OOC (Phase 2) - Face The Lich King'),
(-@CGUID-3, 0, 6, 0, 1, 2, 100, 0, 1000, 1000, 1000, 1000, 66, 0, 0, 0, 0, 0, 0, 19, 31083, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - OOC (Phase 2) - Face The Lich King'),
(-@CGUID-4, 0, 6, 0, 1, 2, 100, 0, 1000, 1000, 1000, 1000, 66, 0, 0, 0, 0, 0, 0, 19, 31083, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - OOC (Phase 2) - Face The Lich King'),
(-@CGUID-5, 0, 6, 0, 1, 2, 100, 0, 1000, 1000, 1000, 1000, 66, 0, 0, 0, 0, 0, 0, 19, 31083, 0, 0, 0, 0, 0, 0, 'Balargarde Elite - OOC (Phase 2) - Face The Lich King');

-- Texts
DELETE FROM `creature_text` WHERE `entry` IN(31016,31029,31083);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(31016, 1, 0, 'You dare to challenge me? You haven''t earned the right!', 14, 0, 100, 25, 0, 15633, 31597, 'Overthane Balargarde to Safirdrang'),
(31016, 2, 0, 'Vardmadra?! Did the Lich King send you personally?', 14, 0, 100, 66, 0, 15634, 31599, 'Overthane Balargarde to Possessed Vardmadra'),
(31016, 3, 0, 'Very well. I will dispatch these creatures. It is only an inconvenience. Prepare to die!', 14, 0, 100, 0, 0, 15635, 31600, 'Overthane Balargarde to Possessed Vardmadra'),
(31016, 4, 0, 'Safirdrang, let them feel the chill of Icecrown!', 14, 0, 100, 0, 0, 15636, 31601, 'Overthane Balargarde to 0'),
(31016, 5, 0, 'STOP! Kneel you fools, it''s the Lich King!', 14, 0, 100, 0, 0, 15637, 31627, 'Overthane Balargarde to The Lich King'),
(31016, 6, 0, 'But, my lord...?', 14, 0, 100, 0, 0, 15638, 31635, 'Overthane Balargarde to The Lich King'),
(31016, 7, 0, 'DIE DOGS!', 14, 0, 100, 0, 0, 15639, 31637, 'Overthane Balargarde to The Lich King'),
(31029, 0, 0, 'He''s on his way!', 14, 0, 100, 457, 0, 15643, 31595, 'Possessed Vardmadra to Player'),
(31029, 1, 0, 'Wrong, Balargarde. You WILL accept this challenge!', 14, 0, 100, 457, 0, 15644, 31598, 'Possessed Vardmadra to Overthane Balargarde'),
(31029, 2, 0, 'My lord.', 14, 0, 100, 457, 0, 15645, 31631, 'Possessed Vardmadra to The Lich King'),
(31029, 3, 0, 'But...!', 14, 0, 100, 0, 0, 15646, 31633, 'Possessed Vardmadra to The Lich King'),
(31083, 0, 0, 'Honor guard stay where you are.', 14, 0, 100, 1, 0, 15600, 31628, 'The Lich King to 0'),
(31083, 1, 0, 'Vardmadra. I''d wondered where you disappeared to. How is Iskalder?', 14, 0, 100, 6, 0, 15601, 31629, 'The Lich King to 0'),
(31083, 2, 0, 'I see through your disguise, Lady Nightswood. YOU THINK THAT YOU CAN FOOL ME?!', 14, 0, 100, 5, 0, 15602, 31632, 'The Lich King to 0'),
(31083, 3, 0, 'You may continue your combat, overthane.', 14, 0, 100, 25, 0, 15603, 31634, 'The Lich King to 0'),
(31083, 4, 0, 'But nothing! Finish them! DO NOT FAIL ME, BALARGARDE!', 14, 0, 100, 5, 0, 15604, 31636, 'The Lich King to Overthane Balargarde'),
(31083, 5, 0, 'You have bested one of my finest, but your efforts are for naught.', 14, 0, 100, 1, 0, 15605, 31693, 'The Lich King to 0'),
(31083, 6, 0, 'The frozen heart of Icecrown awaits....', 14, 0, 100, 1, 0, 15606, 31695, 'The Lich King to 0');

-- Waypoints
DELETE FROM `waypoints` WHERE `entry` IN(31029,31050,3103001,3103002,3103003,3103004,3103005,3103006,31087,3105000,31083,3108300,3102900);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(31029, 1, 7119.714 , 4305.82 , 883.7371, 'Possessed Vardmadra'),
(31029, 2, 7119.045 , 4306.563 , 883.7371, 'Possessed Vardmadra'),
(31029, 3, 7094.592 , 4326.246 , 879.7935, 'Possessed Vardmadra'),
(31029, 4, 7094.592 , 4326.246 , 879.7935, 'Possessed Vardmadra'),
(3102900, 1, 7094.592, 4326.246, 871.4232, 'Possessed Vardmadra (Path 2)'),
(31087, 1, 7079.599, 4301.017, 874.3533, 'Lady Nightswood'),
(31087, 2, 7082.374, 4283.685, 878.2528, 'Lady Nightswood'),
(31087, 3, 7093.269, 4251.247, 855.1418, 'Lady Nightswood'),
(31050, 1, 7097.518 ,4417.555 ,831.8486, 'Safirdrang'),
(31050, 2, 7097.292 ,4416.581 ,831.8486, 'Safirdrang'),
(31050, 3, 7097.876 ,4416.293 ,832.2352, 'Safirdrang'),
(31050, 4, 7096.67 ,4412.85 ,892.0963, 'Safirdrang'),
(31050, 5, 7083.72 ,4365.534 ,886.1511, 'Safirdrang'),
(31050, 6, 7083.72 ,4365.534 ,886.1511, 'Safirdrang'),
(3105000, 1, 7053.937, 4377.317, 901.5513, 'Safirdrang (Path 2)'),
(3105000, 2, 7020.913, 4415.733, 938.7733, 'Safirdrang (Path 2)'),
(3105000, 3, 7014.491, 4475.228, 933.1346, 'Safirdrang (Path 2)'),
(3105000, 4, 7053.163, 4507.731, 899.1902, 'Safirdrang (Path 2)'),
(3103001, 1, 7108.212 ,4429.457 ,837.8948, 'Balargarde Elite Path 1'),
(3103001, 2, 7108.282 ,4428.459 ,837.8948, 'Balargarde Elite Path 1'),
(3103001, 3, 7106.677 ,4418.644 ,890.2556, 'Balargarde Elite Path 1'),
(3103001, 4, 7105.132 ,4316.933 ,890.2556, 'Balargarde Elite Path 1'),
(3103001, 5, 7105.132 ,4316.933 ,890.2556, 'Balargarde Elite Path 1'),
(3103002, 1, 7092.335 ,4432.937 ,836.562, 'Balargarde Elite Path 2'),
(3103002, 2, 7092.213 ,4431.944 ,836.562, 'Balargarde Elite Path 2'),
(3103002, 3, 7088.707 ,4422.627 ,890.4507, 'Balargarde Elite Path 2'),
(3103002, 4, 7042.402 ,4334.195 ,890.4507, 'Balargarde Elite Path 2'),
(3103002, 5, 7042.402 ,4334.195 ,890.4507, 'Balargarde Elite Path 2'),
(3103003, 1, 7118.292 ,4433.163 ,837.6826, 'Balargarde Elite Path 3'),
(3103003, 2, 7118.448 ,4432.175 ,837.6826, 'Balargarde Elite Path 3'),
(3103003, 3, 7118.339 ,4415.652 ,891.2397, 'Balargarde Elite Path 3'),
(3103003, 4, 7116.423 ,4360.689 ,891.2397, 'Balargarde Elite Path 3'),
(3103003, 5, 7116.423 ,4360.689 ,891.2397, 'Balargarde Elite Path 3'),
(3103004, 1, 7084.022 ,4439.456 ,834.9834, 'Balargarde Elite Path 4'),
(3103004, 2, 7083.883 ,4438.466 ,834.9834, 'Balargarde Elite Path 4'),
(3103004, 3, 7084.125 ,4439.286 ,835.0841, 'Balargarde Elite Path 4'),
(3103004, 4, 7078.116 ,4422.103 ,891.0005, 'Balargarde Elite Path 4'),
(3103004, 5, 7052.648 ,4376.112 ,891.0005, 'Balargarde Elite Path 4'),
(3103004, 6, 7052.648 ,4376.112 ,891.0005, 'Balargarde Elite Path 4'),
(3103005, 1, 7111.17 ,4446.118 ,838.3093, 'Balargarde Elite Path 5'),
(3103005, 2, 7111.292 ,4445.125 ,838.3093, 'Balargarde Elite Path 5'),
(3103005, 3, 7097.193 ,4415.753 ,886.4199, 'Balargarde Elite Path 5'),
(3103005, 4, 7091.205 ,4393.473 ,886.4199, 'Balargarde Elite Path 5'),
(3103005, 5, 7091.205 ,4393.473 ,886.4199, 'Balargarde Elite Path 5'),
(3103006, 1, 7095.478 ,4449.356 ,836.9002, 'Balargarde Elite Path 6'),
(3103006, 2, 7095.443 ,4448.357 ,836.9002, 'Balargarde Elite Path 6'),
(3103006, 3, 7052.521 ,4434.108 ,838.8722, 'Balargarde Elite Path 6'),
(3103006, 4, 7003.175 ,4398.929 ,844.0392, 'Balargarde Elite Path 6'),
(3103006, 5, 6988.518 ,4335.11 ,856.9001, 'Balargarde Elite Path 6'),
(3103006, 6, 7018.119 ,4279.629 ,875.7885, 'Balargarde Elite Path 6'),
(3103006, 7, 7067.475 ,4300.513 ,892.5076, 'Balargarde Elite Path 6'),
(3103006, 8, 7067.475 ,4300.513 ,892.5076, 'Balargarde Elite Path 6'),
(31083, 1, 7092.936, 4343.906, 871.9753, 'The Lich King'), 
(31083, 2, 7094.104, 4331.222, 871.5023, 'The Lich King'), 
(31083, 3, 7092.936, 4343.906, 871.9331, 'The Lich King'),
(31083, 4, 7088.768, 4385.59, 872.3639, 'The Lich King'), 
(3108300, 1, 7091.374, 4344.362, 871.9679, 'The Lich King Path 2');
