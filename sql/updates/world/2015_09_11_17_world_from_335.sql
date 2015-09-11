-- 
DELETE FROM `creature` WHERE `guid`=126052;
DELETE FROM `creature_addon` WHERE `guid`=126052;
DELETE FROM `linked_respawn` WHERE `guid`=126052 AND `linkedGuid`=126103;
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (26668, 30810);
UPDATE `smart_scripts` SET `action_param6`=2 WHERE `entryorguid`=-126160 AND `id`=0;

UPDATE `creature_template` SET `RegenHealth`=0 WHERE `entry`=12423;

-- Spawn some missing 'Ghostclaw Ravager' and 'Greater Spindleweb' in Ghostlands
SET @CGUID := 130434;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID AND @CGUID+23;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 16349, 530, 1, 1, 6949.108, -6818.657, 48.41008, 2.161509, 120, 5, 1), -- 16349 (Area: 3433)
(@CGUID+1, 16352, 530, 1, 1, 6933.826, -6715.566, 23.84517, 3.122064, 120, 5, 1), -- 16352 (Area: 3433)
(@CGUID+2, 16352, 530, 1, 1, 6968.374, -6953.108, 51.54251, 2.980778, 120, 5, 1), -- 16352 (Area: 3433)
(@CGUID+3, 16352, 530, 1, 1, 6890.797, -6722.461, 39.58191, 2.24407, 120, 5, 1), -- 16352 (Area: 3433)
(@CGUID+4, 16352, 530, 1, 1, 6853.69, -6851.976, 69.60109, 2.738199, 120, 5, 1), -- 16352 (Area: 3433)
(@CGUID+5, 16349, 530, 1, 1, 6950.041, -6888.719, 49.80816, 3.477853, 120, 5, 1), -- 16349 (Area: 3433)
(@CGUID+6, 16352, 530, 1, 1, 6878.636, -6864.466, 62.72943, 2.882877, 120, 5, 1), -- 16352 (Area: 3433)
(@CGUID+7, 16349, 530, 1, 1, 6895.033, -6912.371, 47.20905, 4.118551, 120, 5, 1), -- 16349 (Area: 3433)
(@CGUID+8, 16349, 530, 1, 1, 6922.021, -7040.709, 43.90837, 4.415325, 120, 5, 1), -- 16349 (Area: 3433)
(@CGUID+9, 16352, 530, 1, 1, 6885.669, -7022.219, 48.7115, 1.793493, 120, 5, 1), -- 16352 (Area: 3433)
(@CGUID+10, 16349, 530, 1, 1, 6897.135, -6971.594, 47.17694, 2.724053, 120, 5, 1), -- 16349 (Area: 3433)
(@CGUID+11, 16352, 530, 1, 1, 6978.319, -7000.734, 51.0767, 4.078644, 120, 5, 1), -- 16352 (Area: 3433)
(@CGUID+12, 16352, 530, 1, 1, 6942.256, -7020.499, 45.66068, 0.1648275, 120, 5, 1), -- 16352 (Area: 3433)
(@CGUID+13, 16349, 530, 1, 1, 6984.509, -7047.863, 51.65011, 1.124614, 120, 5, 1), -- 16349 (Area: 3433)
(@CGUID+14, 16349, 530, 1, 1, 6963.142, -7082.294, 49.01252, 6.261704, 120, 5, 1), -- 16349 (Area: 3433)
(@CGUID+15, 16352, 530, 1, 1, 6890.896, -7106.758, 45.10302, 1.95221, 120, 5, 1), -- 16352 (Area: 3433)
(@CGUID+16, 16349, 530, 1, 1, 6836.949, -6998.213, 89.5099, 3.035898, 120, 5, 1), -- 16349 (Area: 3433)
(@CGUID+17, 16349, 530, 1, 1, 6963.359, -7153.403, 47.53667, 3.969122, 120, 5, 1), -- 16349 (Area: 3433)
(@CGUID+18, 16352, 530, 1, 1, 6966.125, -7145.214, 49.57573, 5.950935, 120, 5, 1), -- 16352 (Area: 3433)
(@CGUID+19, 16349, 530, 1, 1, 7039.774, -6724.048, 31.42106, 0.8247696, 120, 5, 1), -- 16349 (Area: 3433)
(@CGUID+20, 16349, 530, 1, 1, 6894.136, -6637.756, 22.16779, 4.740626, 120, 5, 1), -- 16349 (Area: 3433)
(@CGUID+21, 16352, 530, 1, 1, 6892.136, -6687.743, 33.33307, 6.265609, 120, 5, 1), -- 16352 (Area: 3433)
(@CGUID+22, 16349, 530, 1, 1, 6862.79, -6653.266, 29.21497, 0.1569574, 120, 5, 1), -- 16349 (Area: 3433)
(@CGUID+23, 16349, 530, 1, 1, 6795.933, -6674.067, 43.69128, 2.761438, 120, 5, 1); -- 16349 (Area: 3433)

-- Set all of these creatures to roam 5 yards, and random movement type
UPDATE `creature` SET `spawndist`=5, `MovementType`=1 WHERE id IN (16349,16352);

UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `id`=9369;

UPDATE `creature_template` SET `unit_flags`=537166656, `unit_flags2`=2048 WHERE `entry` IN (26737);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26737) AND `source_type`=0 AND `id`=6;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26737,0,6,0,6,0,100,0,0,0,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crazed Mana-Surge - On Just Died - Remove unit flag immune to pc");

UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=10161;
