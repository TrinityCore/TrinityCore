SET @CGUID := 536; -- 4.x
SET @OGUID := 1769; -- 4.x

UPDATE `gameobject` SET `spawntimesecs`=120, `animprogress`=255 WHERE `id`=188464;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+21;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+00, 188464, 571, 1, 1, 4781.308, -4865.809, 26.53011, 0.8377575, 0, 0, 0.4067364, 0.9135455, 120, 255, 1),
(@OGUID+01, 188464, 571, 1, 1, 4753.355, -4830.314, 26.04058, 5.532695, 0, 0, -0.3665009, 0.9304177, 120, 255, 1),
(@OGUID+02, 188464, 571, 1, 1, 4758.613, -4824.151, 25.96103, 5.550147, 0, 0, -0.3583679, 0.9335805, 120, 255, 1),
(@OGUID+03, 188464, 571, 1, 1, 4764.173, -4818.161, 25.88273, 5.550147, 0, 0, -0.3583679, 0.9335805, 120, 255, 1),
(@OGUID+04, 188464, 571, 1, 1, 4785.614, -4793.256, 26.12138, 5.550147, 0, 0, -0.3583679, 0.9335805, 120, 255, 1),
(@OGUID+05, 188464, 571, 1, 1, 4848.127, -4827.709, 25.96146, 2.408554, 0, 0, 0.9335804, 0.358368, 120, 255, 1),
(@OGUID+06, 188464, 571, 1, 1, 4790.917, -4787.033, 26.19655, 5.550147, 0, 0, -0.3583679, 0.9335805, 120, 255, 1),
(@OGUID+07, 188464, 571, 1, 1, 4796.205, -4780.994, 26.19833, 5.567601, 0, 0, -0.3502073, 0.9366722, 120, 255, 1),
(@OGUID+08, 188464, 571, 1, 1, 4829.167, -4799.646, 25.96292, 3.961899, 0, 0, -0.9170599, 0.3987495, 120, 255, 1),
(@OGUID+09, 188464, 571, 1, 1, 4775.307, -4860.43, 26.52502, 0.8377575, 0, 0,  0.4067364, 0.9135455, 120, 255, 1),
(@OGUID+10, 188499, 571, 1, 1, 4783.06, -4870.042, 26.63436, 5.567601, 0, 0, -0.3502073, 0.9366722, 300, 255, 1),
(@OGUID+11, 188499, 571, 1, 1, 4776.997, -4864.7, 26.76528, 5.67232, 0, 0, -0.3007059, 0.9537169, 300, 255, 1),
(@OGUID+12, 188499, 571, 1, 1, 4804.492, -4880.459, 25.95016, 0.9250238, 0, 0, 0.4461975, 0.8949345, 300, 255, 1),
(@OGUID+13, 188499, 571, 1, 1, 4754.443, -4825.909, 26.1786, 4.01426, 0, 0, -0.9063072, 0.4226195, 300, 255, 1),
(@OGUID+14, 188499, 571, 1, 1, 4797.431, -4776.76, 26.2836, 3.979355, 0, 0, -0.9135447, 0.4067384, 300, 255, 1),
(@OGUID+15, 188499, 571, 1, 1, 4792.048, -4782.723, 26.41635, 4.049168, 0, 0, -0.8987932, 0.4383728, 300, 255, 1),
(@OGUID+16, 188499, 571, 1, 1, 4806.47, -4775.945, 26.30708, 2.373644, 0, 0,  0.9271832, 0.3746083, 300, 255, 1),
(@OGUID+17, 188499, 571, 1, 1, 4809.335, -4874.765, 26.06562, 0.8377575, 0, 0, 0.4067364, 0.9135455, 300, 255, 1),
(@OGUID+18, 188499, 571, 1, 1, 4819.935, -4862.525, 26.05573, 0.8203033, 0, 0,  0.3987484, 0.9170604, 300, 255, 1),
(@OGUID+19, 188499, 571, 1, 1, 4786.889, -4788.973, 26.3336, 4.049168, 0, 0, -0.8987932, 0.4383728, 300, 255, 1),
(@OGUID+20, 188499, 571, 1, 1, 4852.343, -4826.055, 26.06636, 0.8552105, 0, 0, 0.4146929, 0.9099615, 300, 255, 1),
(@OGUID+21, 188499, 571, 1, 1, 4845.617, -4811.589, 26.17898, 2.391098, 0, 0, 0.9304171, 0.3665025, 300, 255, 1);

DELETE FROM `creature` WHERE `id` IN (26811,26812);
DELETE FROM `creature` WHERE `guid` IN (113208,113209);
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+00 AND @CGUID+14;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+00, 26811, 571, 1, 1, 4733.245, -4857.637, 26.4931, 2.617994, 300, 5, 1),
(@CGUID+01, 26812, 571, 1, 1, 4796.549, -4846.317, 25.50747, 4.249843, 300, 5, 1),
(@CGUID+02, 26811, 571, 1, 1, 4766.232, -4820.333, 25.69218, 2.329675, 300, 5, 1),
(@CGUID+03, 26811, 571, 1, 1, 4823.353, -4839.751, 25.7641, 1.145746, 300, 5, 1),
(@CGUID+04, 26812, 571, 1, 1, 4797.967, -4783.413, 25.99624, 4.269053, 300, 5, 1),
(@CGUID+05, 26812, 571, 1, 1, 4759.746, -4835.385, 25.90628, 3.535823, 300, 5, 1),
(@CGUID+06, 26812, 571, 1, 1, 4782.295, -4858.29, 26.10907, 4.433136, 300, 5, 1),
(@CGUID+07, 26811, 571, 1, 1, 4795.084, -4869.773, 25.85341, 3.63068, 300, 5, 1),
(@CGUID+08, 26812, 571, 1, 1, 4758.876, -4857.517, 25.89942, 3.830702, 300, 5, 1),
(@CGUID+09, 26811, 571, 1, 1, 4809.717, -4858.999, 25.77467, 4.760717, 300, 5, 1),
(@CGUID+10, 26811, 571, 1, 1, 4801.294, -4802.357, 25.66738, 5.655887, 300, 5, 1),
(@CGUID+11, 26812, 571, 1, 1, 4831.968, -4810.053, 25.6752, 4.12599, 300, 5, 1),
(@CGUID+12, 26811, 571, 1, 1, 4845.415, -4821.253, 25.65237, 4.234284, 300, 5, 1),
(@CGUID+13, 26806, 571, 1, 1, 4668.349, -4849.098, 35.56351, 3.106686, 300, 0, 0),
(@CGUID+14, 26806, 571, 1, 1, 4669.264, -4869.123, 35.5635, 3.263766, 300, 0, 0);

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (26591,26811,26812);
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=188464;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26591,26811,26812) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=188464 AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=26812*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26591,0,0,0,38,0,100,0,0,1,0,0,11,47798,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Pacer Bunny - Drak Theron Exterior - On data set 0 1 - Spellcast Summon Mummy Remnants'),
(26811,0,0,1,8,0,100,0,47778,0,0,0,11,47795,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Warmonger - On spellhit Blow Snow - Spellcast Cold Cleanse'),
(26811,0,1,2,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Warmonger - On spellhit Blow Snow - Set event phase 1'),
(26811,0,2,3,61,0,100,0,0,0,0,0,18,33555200,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Warmonger - On spellhit Blow Snow - Set unit_flags IMMUNE_TO_PC, IMMUNE_TO_NPC, NOT_SELECTABLE'),
(26811,0,3,4,61,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Warmonger - On spellhit Blow Snow - Set run'),
(26811,0,4,0,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Warmonger - On spellhit Blow Snow - Stop combat movement'),
(26811,0,5,6,23,1,100,1,47795,0,0,0,69,1,0,0,0,0,0,20,188464,40,0,0,0,0,0, 'Ancient Drakkari Warmonger - On spellfade Cold Cleanse - Move to position Ancient Troll Mummy'),
(26811,0,6,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Warmonger - On spellfade Cold Cleanse - Say line'),
(26811,0,7,0,34,0,100,0,0,1,0,0,80,26812*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Warmonger - On movement inform - Run script'),
(26811,0,8,0,11,0,100,0,0,0,0,0,91,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Warmonger - On spawn - Remove unit_field_bytes1 (sleep)'),
(26812,0,0,1,8,0,100,0,47778,0,0,0,11,47795,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Soothsayer - On spellhit Blow Snow - Spellcast Cold Cleanse'),
(26812,0,1,2,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Soothsayer - On spellhit Blow Snow - Set event phase 1'),
(26812,0,2,3,61,0,100,0,0,0,0,0,18,33555200,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Soothsayer - On spellhit Blow Snow - Set unit_flags IMMUNE_TO_PC, IMMUNE_TO_NPC, NOT_SELECTABLE'),
(26812,0,3,4,61,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Soothsayer - On spellhit Blow Snow - Set run'),
(26812,0,4,0,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Soothsayer - On spellhit Blow Snow - Stop combat movement'),
(26812,0,5,6,23,1,100,1,47795,0,0,0,69,1,0,0,0,0,0,20,188464,40,0,0,0,0,0, 'Ancient Drakkari Soothsayer - On spellfade Cold Cleanse - Move to position Ancient Troll Mummy'),
(26812,0,6,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Soothsayer - On spellfade Cold Cleanse - Say line'),
(26812,0,7,0,34,0,100,0,0,1,0,0,80,26812*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Soothsayer - On movement inform - Run script'),
(26812,0,8,0,11,0,100,0,0,0,0,0,91,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari Soothsayer - On spawn - Remove unit_field_bytes1 (sleep)'),

(188464,1,0,0,38,0,100,0,0,1,0,0,99,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Troll Mummy - On data set 0 1 - Change state (deactivated)'),
(188464,1,1,0,70,0,100,0,2,0,0,0,70,120,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Troll Mummy - On state changed - Despawn'),

(26812*100,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,19,26591,5,0,0,0,0,0, 'Ancient Drakkari script - Turn to Pacer Bunny - Drak Theron Exterior'),
(26812*100,9,1,0,0,0,100,0,50,50,0,0,90,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari script - Set unit_field_bytes1 (sleep)'),
(26812*100,9,2,0,0,0,100,0,2000,2000,0,0,19,33555200,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari script - Remove unit_flags IMMUNE_TO_PC, IMMUNE_TO_NPC, NOT_SELECTABLE'),
(26812*100,9,3,0,0,0,100,0,0,0,0,0,45,0,1,0,0,0,0,19,26591,5,0,0,0,0,0, 'Ancient Drakkari script - Set data 0 1 Pacer Bunny - Drak Theron Exterior'),
(26812*100,9,4,0,0,0,100,0,0,0,0,0,45,0,1,0,0,0,0,20,188464,5,0,0,0,0,0, 'Ancient Drakkari script - Set data 0 1 Ancient Troll Mummy'),
(26812*100,9,5,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ancient Drakkari script - Despawn');

DELETE FROM `creature_text` WHERE `entry` IN (26811,26812);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(26811,0,0,'I could sleep forever, mon....',12,0,100,0,0,0,'Ancient Drakkari Warmonger'),
(26811,0,1,'Finally, I can be restin''...',12,0,100,0,0,0,'Ancient Drakkari Warmonger'),
(26811,0,2,'Free at last, mon.',12,0,100,0,0,0,'Ancient Drakkari Warmonger'),
(26811,0,3,'Where''s mah mummy?',12,0,100,0,0,0,'Ancient Drakkari Warmonger'),
(26812,0,0,'I could sleep forever, mon....',12,0,100,0,0,0,'Ancient Drakkari Soothsayer'),
(26812,0,1,'Finally, I can be restin''...',12,0,100,0,0,0,'Ancient Drakkari Soothsayer'),
(26812,0,2,'Free at last, mon.',12,0,100,0,0,0,'Ancient Drakkari Soothsayer'),
(26812,0,3,'Where''s mah mummy?',12,0,100,0,0,0,'Ancient Drakkari Soothsayer');
