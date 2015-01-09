-- Disclosure (12710)
SET @MALMORTIS      := 28948;  -- Malmortis
SET @TRIGG_BUNNY    := 28617;  -- Drakuramas Teleport Bunny 01
SET @LOW_TRIG_B     := 114831; -- Lower Trigger Bunny Guid
SET @TRIGGER1       := 5080;   -- Lower Teleport Trigger
SET @UP_TRIG_B      := 114829; -- Upper Trigger Bunny guid
SET @TRIGGER2       := 5061;   -- Upper Teleport Trigger
SET @SCEPT_AURA     := 52678;  -- Teleporter Scepter Aura
SET @ESCORT_A       := 52839;  -- Summon Escort Aura
SET @T_SCRIPT       := 52676;  -- Drakuramas Teleport Script 03
SET @TELEPORT3      := 52677;  -- Drakuramas Teleport 03
SET @SUM_MAL        := 52775;  -- Summon Malmortis
SET @HEARTBEAT      := 61707;  -- Malmortis Heartbeat
SET @KILLCREDIT     := 53101;  -- Kill Credit
SET @T_SCRIPT2      := 52089;  -- Drakuramas Teleport Script 01
SET @TELEPORT1      := 52091;  -- Drakuramas Teleport 01

-- Drakuramas Teleport 03 position
DELETE FROM `spell_target_position` WHERE `id`=@TELEPORT3;
INSERT INTO `spell_target_position` (`id`,`target_map`,`target_position_x`,`target_position_y`,`target_position_z`,`target_orientation`) VALUES
(@TELEPORT3,571,6252.58, -1965.86, 484.782, 3.7);

-- Drakuramas Teleport Script 01 position
DELETE FROM `spell_target_position` WHERE `id`=@TELEPORT1;
INSERT INTO `spell_target_position` (`id`,`target_map`,`target_position_x`,`target_position_y`,`target_position_z`,`target_orientation`) VALUES
(@TELEPORT1,571,6165.262, -2001.812, 408.167, 2.2);

DELETE FROM `areatrigger_scripts` WHERE `entry` = @TRIGGER1;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(@TRIGGER1,'SmartTrigger');

DELETE FROM `smart_scripts` WHERE `entryorguid` =@TRIGGER1 AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@TRIGGER1,2,0,0,46,0,100,0,@TRIGGER1,0,0,0,45,1,1,0,0,0,0,10,@LOW_TRIG_B,@TRIGG_BUNNY,0,0,0,0,0,'');

DELETE FROM `areatrigger_scripts` WHERE `entry` = @TRIGGER2;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(@TRIGGER2,'SmartTrigger');

DELETE FROM `smart_scripts` WHERE `entryorguid` =@TRIGGER2 AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@TRIGGER2,2,0,0,46,0,100,0,@TRIGGER2,0,0,0,45,1,1,0,0,0,0,10,@UP_TRIG_B,@TRIGG_BUNNY,0,0,0,0,0,'');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-@LOW_TRIG_B,-@UP_TRIG_B) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`)VALUES
(-@LOW_TRIG_B,0,0,0,38,0,100,0,1,1,0,0,11,@T_SCRIPT2,0,0,0,0,0,21,5,0,0,0,0,0,0,'Drakuramas Teleport Bunny 01 - On Data Set - Tele Player'),
--
(-@UP_TRIG_B,0,0,0,38,0,100,0,1,1,0,0,11,@T_SCRIPT,0,0,0,0,0,21,5,0,0,0,0,0,0,'Drakuramas Teleport Bunny 01 - On Data Set - Tele Player');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (@T_SCRIPT,@T_SCRIPT2,@ESCORT_A);
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(@ESCORT_A,@SUM_MAL,1,'Summon Malmortis'),
(@T_SCRIPT,@TELEPORT3,1,'Teleport'),
(@T_SCRIPT2,@TELEPORT1,1,'Teleport');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (@TRIGGER1,@TRIGGER2);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,@TRIGGER1,2,0,1,0,@SCEPT_AURA,0,0,0,0,'','SAI areatrigger triggers only if player has aura Teleporter Scepter Aura'),
(22,1,@TRIGGER2,2,0,1,0,@SCEPT_AURA,0,0,0,0,'','SAI areatrigger triggers only if player has aura Teleporter Scepter Aura');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (@T_SCRIPT,@T_SCRIPT2);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, @T_SCRIPT, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Spell only hits player'),
(13, 1, @T_SCRIPT2, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Spell only hits player');

UPDATE `gameobject_template` SET `size`=2 WHERE `entry` IN (190948,190949); -- Musty Coffin
DELETE FROM `gameobject` WHERE `id` IN (190949,190948);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(9253, 190949, 571, 1, 1, 6260.489, -1960.045, 484.7818, 3.787367, 0, 0, 0, 1, 120, 255, 1), -- Musty Coffin (Area: Reliquary of Pain)
(9254, 190948, 571, 1, 1, 6260.482, -1960.039, 484.7818, 3.787367, 0, 0, 0, 1, 120, 255, 1); -- Musty Coffin (Area: Reliquary of Pain)

-- Template updates for creature 28948 (Malmortis)
UPDATE `creature_template` SET `minlevel`=85,`maxlevel`=85,`unit_flags`=`unit_flags`|264,`speed_walk`=2.4,`speed_run`=0 WHERE `entry`=@MALMORTIS; -- Malmortis
-- Model data 8055 (creature 28948 (Malmortis))
UPDATE `creature_model_info` SET `bounding_radius`=2,`combat_reach`=3,`gender`=0 WHERE `modelid`=8055; -- Malmortis
-- Addon data for creature 28948 (Malmortis)
DELETE FROM `creature_template_addon` WHERE `entry`=@MALMORTIS;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@MALMORTIS,0,0,1,0,''); -- Malmortis

UPDATE `creature_template` SET AIName='SmartAI' WHERE `entry` IN (@MALMORTIS,@TRIGGER1,@TRIGGER2,@TRIGG_BUNNY);
DELETE FROM `smart_scripts` WHERE `entryorguid`IN (@MALMORTIS,@MALMORTIS*100) AND `source_type`IN (0,9);
DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (@MALMORTIS);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`)VALUES
(@MALMORTIS,0,0,1,54,0,100,0,0,0,0,0,80,@MALMORTIS*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Malmortis - On Respawn - Start Timed Action Script'),
(@MALMORTIS,0,1,0,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Malmortis - On Respawn - Set Orientation To Invoker'),
-- 47
(@MALMORTIS,0,2,0,40,0,100,1,8,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Malmortis - On WP Reached - Say 3'),
(@MALMORTIS,0,3,0,40,0,100,1,18,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Malmortis - On WP Reached- Say 4'),
(@MALMORTIS,0,4,5,40,0,100,1,47,0,0,0,1,5,7000,0,0,0,0,1,0,0,0,0,0,0,0,'Malmortis - On WP Reached - Say'),
(@MALMORTIS,0,5,0,61,0,100,0,0,0,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Malmortis - On Link - Pause WP'),
(@MALMORTIS,0,6,0,52,0,100,1,5,@MALMORTIS,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'Malmortis - On Text Over 5 - Say 6'),
-- 121
(@MALMORTIS,0,6,7,40,0,100,1,80,0,0,0,1,7,0,0,0,0,0,1,0,10,0,0,0,0,0,'Malmortis - On WP Reached - Say 7'),
(@MALMORTIS,0,7,0,61,0,100,0,0,0,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Malmortis - On Link - Pause WP'),
(@MALMORTIS,0,8,9,40,0,100,1,81,0,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Malmortis - On WP Reached - Say 8'),
(@MALMORTIS,0,9,0,61,0,100,0,0,0,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Malmortis - On Link - Pause WP'),
-- 128
(@MALMORTIS,0,10,11,40,0,100,1,86,0,0,0,1,9,3000,0,0,0,0,1,0,0,0,0,0,0,0,'Malmortis - On WP Reached - Say 9'),
(@MALMORTIS,0,11,0,61,0,100,0,0,0,0,0,54,23000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Malmortis - On Link - Pause WP'),
(@MALMORTIS,0,12,0,52,0,100,1,9,@MALMORTIS,0,0,1,10,7000,0,0,0,0,1,0,0,0,0,0,0,0,'Malmortis - On Text Over 9 - Say 10'),
(@MALMORTIS,0,13,0,52,0,100,1,10,@MALMORTIS,0,0,1,11,7000,0,0,0,0,1,0,0,0,0,0,0,0,'Malmortis - On Text Over 10 - Say 11'),
(@MALMORTIS,0,14,0,52,0,100,1,11,@MALMORTIS,0,0,1,12,7000,0,0,0,0,1,0,0,0,0,0,0,0,'Malmortis - On Text Over 11 - Say 12'),
-- 137 
(@MALMORTIS,0,15,0,40,0,100,1,93,0,0,0,1,13,5000,0,0,0,0,1,0,0,0,0,0,0,0,'Malmortis - On WP Reached - Say 13'),
(@MALMORTIS,0,16,17,52,0,100,1,13,@MALMORTIS,0,0,1,14,7000,0,0,0,0,1,0,0,0,0,0,0,0,'Malmortis - On Text Over 13 - Say 14'),
(@MALMORTIS,0,17,18,61,0,100,0,0,0,0,0,11,@T_SCRIPT,2,0,0,0,0,1,0,0,0,0,0,0,0,'Malmortis - On Link - Cast on self'),
(@MALMORTIS,0,18,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Malmortis - On Link - Despawn'),
-- 
(@MALMORTIS*100,9,0,0,0,0,100,0,3000,3000,3000,3000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Malmortis - On Script - Say 0'),
(@MALMORTIS*100,9,1,0,0,0,100,0,5000,5000,5000,5000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Malmortis - On Script - Say 1'),
(@MALMORTIS*100,9,2,0,0,0,100,0,5000,5000,5000,5000,53,0,@MALMORTIS,0,0,0,0,1,0,0,0,0,0,0,0,'Malmortis - On Script - Start WP movement'),
-- It's weird that credit is given here, but hey, we're Blizzard, we can do it wherever we want.
(@MALMORTIS*100,9,3,0,0,0,100,0,1000,1000,1000,1000,11,@KILLCREDIT,2,0,0,0,0,7,0,0,0,0,0,0,0,'Malmortis - On Script - Cast Q Credit to Invoker');


DELETE FROM `creature_text` WHERE `entry`=28948;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES 
(28948, 0, 0, 'Ahh... there you are. The master told us you''d be arriving soon.', 12, 0, 100, 0, 0, 0, 'Malmortis say'),
(28948, 1, 0, 'Please, follow me, $N. There is much for you to see...', 12, 0, 100, 0, 0, 0, 'Malmortis say'),
(28948, 2, 0, 'Ever since his arrival from Drak''Tharon, the master has spoken of the time you would be joining him here.', 12, 0, 100, 0, 0, 0, 'Malmortis say'),
(28948, 3, 0, 'You should feel honored. You are the first of the master''s prospects to be shown our operation.', 12, 0, 100, 0, 0, 0, 'Malmortis say'),
(28948, 4, 0, 'The things I show you now must never be spoken of outside Voltarus. The world shall come to know our secret soon enough!', 12, 0, 100, 0, 0, 0, 'Malmortis say'),
(28948, 5, 0, 'Here lie our stores of blight crystal, without which our project would be impossible.', 12, 0, 100, 0, 0, 0, 'Malmortis say'),
(28948, 6, 0, 'I understand that you are to thank for the bulk of our supply.', 12, 0, 100, 0, 0, 0, 'Malmortis say'),
(28948, 7, 0, 'These trolls are among those you exposed on the battlefield. Masterfully done, indeed....', 12, 0, 100, 0, 0, 0, 'Malmortis say'),
(28948, 8, 0, 'We feel it best to position them here, where they might come in terms with their impending fate.', 12, 0, 100, 0, 0, 0, 'Malmortis say'),
(28948, 9, 0, 'This is their destiny....', 12, 0, 100, 0, 0, 0, 'Malmortis say'),
(28948, 10, 0, 'The blight slowly seeps into their bodies, gradually preparing them for their conversion.', 12, 0, 100, 0, 0, 0, 'Malmortis say'),
(28948, 11, 0, 'This special preparation grants them unique powers far greater than they would otherwise know.', 12, 0, 100, 0, 0, 0, 'Malmortis say'),
(28948, 12, 0, 'Soon, the master will grant them the dark gift, making them fit to server the Lich King for eternity!', 12, 0, 100, 0, 0, 0, 'Malmortis say'),
(28948, 13, 0, 'Stay for as long as you like, $N. Glory in the fruits of your labor!', 12, 0, 100, 0, 0, 0, 'Malmortis say'),
(28948, 14, 0, 'Your service has been invaluable in fulfilling the master''s plan. May you forever grow in power....', 12, 0, 100, 0, 0, 0, 'Malmortis say');


DELETE FROM `waypoints` WHERE entry = @MALMORTIS;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(@MALMORTIS, 1,  6246.076, -1959.903, 484.7817, ''),
(@MALMORTIS, 2,  6239.468, -1963.94, 484.5479,  ''),
(@MALMORTIS, 3,  6235.218, -1964.69, 484.5479,  ''),
(@MALMORTIS, 4,  6232.341, -1965.397, 484.7817, ''),
(@MALMORTIS, 5,  6229.812, -1960.545, 484.832,  ''),
(@MALMORTIS, 6,  6229.805, -1960.542, 484.832,  ''),
(@MALMORTIS, 7,  6225.805, -1959.542, 484.832,  ''),
(@MALMORTIS, 8,  6218.658, -1962.031, 484.8823, ''), -- Say 3
(@MALMORTIS, 9,  6213.883, -1954.917, 484.6498, ''),
(@MALMORTIS, 10, 6211.883, -1951.667, 484.6498, ''),
(@MALMORTIS, 11, 6205.607, -1941.303, 484.9172, ''),
(@MALMORTIS, 12, 6192.572, -1931.705, 484.9854, ''),
(@MALMORTIS, 13, 6178.136, -1937.173, 484.6558, ''),
(@MALMORTIS, 14, 6175.831, -1938.89,  484.9104, ''),
(@MALMORTIS, 15, 6171.331, -1943.14,  484.6604, ''),
(@MALMORTIS, 16, 6163.581, -1951.14, 484.9104,  ''),
(@MALMORTIS, 17, 6157.331, -1952.89, 484.6604,  ''),
(@MALMORTIS, 18, 6156.749, -1953.028, 484.9022, ''), -- Say 4
(@MALMORTIS, 19, 6149.743, -1957.582, 484.655,  ''),
(@MALMORTIS, 20, 6147.993, -1958.832, 484.905,  ''),
(@MALMORTIS, 21, 6144.993, -1960.832, 484.905,  ''),
(@MALMORTIS, 22, 6140.993, -1963.332, 484.905,  ''),
(@MALMORTIS, 23, 6137.743, -1965.332, 484.905,  ''),
(@MALMORTIS, 24, 6132.743, -1968.582, 484.905,  ''), 
(@MALMORTIS, 25, 6128.993, -1970.832, 484.905,  ''), 
(@MALMORTIS, 26, 6125.993, -1972.832, 484.905,  ''),
(@MALMORTIS, 27, 6123.243, -1974.332, 484.655,  ''),
(@MALMORTIS, 28, 6119.237, -1976.635, 484.9079, ''),
(@MALMORTIS, 29, 6116.115, -1977.373, 484.6002,  ''),
(@MALMORTIS, 30, 6112.615, -1979.373, 484.6002,  ''),
(@MALMORTIS, 31, 6103.115, -1984.623, 484.6002,  ''),
(@MALMORTIS, 32, 6096.115, -1989.123, 484.6002,  ''),
(@MALMORTIS, 33, 6094.615, -1990.123, 484.8502,  ''),
(@MALMORTIS, 34, 6093.954, -1990.445, 484.918,  ''),
(@MALMORTIS, 35, 6089.347, -2014.297, 484.8763, ''),
(@MALMORTIS, 36, 6099.82, -2021.594, 484.9467,  ''),
(@MALMORTIS, 37, 6102.82, -2024.344, 484.9467,  ''),
(@MALMORTIS, 38, 6105.32, -2027.094, 484.9467,  ''),
(@MALMORTIS, 39, 6114.07, -2034.844, 484.9467,  ''),
(@MALMORTIS, 40, 6113.57, -2037.844, 484.9467,  ''),
(@MALMORTIS, 41, 6112.82, -2040.594, 484.6967,  ''),
(@MALMORTIS, 42, 6113.093, -2041.11, 484.8785,  ''),
(@MALMORTIS, 43, 6103.914, -2049.32, 484.8252,  ''),
(@MALMORTIS, 44, 6103.414, -2052.07, 484.8252,  ''),
(@MALMORTIS, 45, 6102.664, -2054.57, 484.5752,  ''),
(@MALMORTIS, 46, 6103.664, -2055.57, 484.5752,  ''),
(@MALMORTIS, 47, 6108.405, -2060.931, 484.7817, ''), -- say 5 & say 6
(@MALMORTIS, 48, 6111.582, -2063.279, 484.5828, ''),
(@MALMORTIS, 49, 6117.082, -2066.779, 484.5828, ''),
(@MALMORTIS, 50, 6118.082, -2067.279, 484.8328, ''),
(@MALMORTIS, 51, 6122.082, -2069.779, 484.8328, ''),
(@MALMORTIS, 52, 6127.582, -2073.529, 484.8328, ''), 
(@MALMORTIS, 53, 6129.582, -2074.779, 484.8328, ''), 
(@MALMORTIS, 54, 6136.759, -2078.627, 484.8839, ''),
(@MALMORTIS, 55, 6135.021, -2082.232, 484.9813, ''),
(@MALMORTIS, 56, 6137.021, -2085.232, 484.7313, ''),
(@MALMORTIS, 57, 6143.271, -2093.232, 484.9813, ''),
(@MALMORTIS, 58, 6145.771, -2097.232, 484.9813, ''),
(@MALMORTIS, 59, 6149.521, -2102.232, 484.9813, ''),
(@MALMORTIS, 60, 6152.771, -2104.482, 484.9813, ''),
(@MALMORTIS, 61, 6157.708, -2107.487, 485.1209, ''),
(@MALMORTIS, 62, 6152.734, -2117.464, 484.878, ''),
(@MALMORTIS, 63, 6155.484, -2121.714, 485.1281, ''),
(@MALMORTIS, 64, 6146.211, -2124.778, 485.1514, ''),
(@MALMORTIS, 65, 6145.211, -2124.778, 485.1514, ''),
(@MALMORTIS, 66, 6140.628, -2128.341, 485.3621, ''),
(@MALMORTIS, 67, 6126.711, -2123.778, 473.1514, ''),
(@MALMORTIS, 68, 6125.211, -2123.778, 473.1514, ''),
(@MALMORTIS, 69, 6119.711, -2123.278, 473.4014,  ''),
(@MALMORTIS, 70, 6118.48, -2123.076, 473.5551, ''),
(@MALMORTIS, 71, 6120.804, -2116.018, 473.4532, ''),
(@MALMORTIS, 72, 6121.228, -2108.079, 473.5628, ''),
(@MALMORTIS, 73, 6123.12, -2108.537, 473.5413, ''),
(@MALMORTIS, 74, 6124.12, -2108.537, 473.5413, ''),
(@MALMORTIS, 75, 6128.12, -2108.787, 473.2913, ''),
(@MALMORTIS, 76, 6137.730, -2111.003, 465.857, ''),
(@MALMORTIS, 77, 6143.918, -2112.493, 461.311, ''),
(@MALMORTIS, 78, 6152.609, -2110.294, 461.309, ''),
(@MALMORTIS, 79, 6156.999, -2110.611, 461.3106, ''),
(@MALMORTIS, 80, 6157.26, -2087.746, 461.0578,  ''), -- Say 7
(@MALMORTIS, 81, 6148.678, -2072.781, 461.3044, ''), -- Say 8 
(@MALMORTIS, 82, 6154.87, -2058.052, 461.2998,  ''),
(@MALMORTIS, 83, 6146.364, -2056.77, 460.8798,  ''),
(@MALMORTIS, 84, 6145.364, -2055.52, 460.8798,  ''),
(@MALMORTIS, 85, 6141.864, -2051.27, 460.8798,  ''),
(@MALMORTIS, 86, 6139.778, -2046.457, 461.3102, ''), -- say 9 & say 10 & say 11 & say 12
(@MALMORTIS, 87, 6143.079, -2043.717, 461.6264, ''),
(@MALMORTIS, 88, 6150.579, -2037.467, 461.6264, ''),
(@MALMORTIS, 89, 6156.329, -2032.717, 459.6264, ''),
(@MALMORTIS, 90, 6158.579, -2031.217, 458.8764, ''),
(@MALMORTIS, 91, 6161.379, -2028.978, 458.9426, ''),
(@MALMORTIS, 92, 6168.36, -2022.986, 454.9367,  ''),
(@MALMORTIS, 93, 6172.36, -2019.708, 455.1223,  ''); -- Say 13 & 14
