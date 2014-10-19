/*
-- Balizar the Umbrage SAI
SET @ENTRY := 3899;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,2000,10000,15000,11,14868,0,0,0,0,0,2,0,0,0,0,0,0,0,"Balizar the Umbrage - In Combat - Cast 'Curse of Agony'"),
(@ENTRY,0,1,0,0,0,100,0,3000,4000,11000,16000,11,11980,0,0,0,0,0,2,0,0,0,0,0,0,0,"Balizar the Umbrage - In Combat - Cast 'Curse of Weakness'"),
(@ENTRY,0,2,0,0,0,100,0,7000,8000,7000,8000,11,20791,0,0,0,0,0,2,0,0,0,0,0,0,0,"Balizar the Umbrage - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,3,0,54,0,100,0,0,0,0,0,18,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Balizar the Umbrage - On Just Summoned - Set Unit Flags - Immune to NPC/NPC"),
(@ENTRY,0,4,5,38,0,100,0,1,1,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Balizar the Umbrage - On Data Set - Remove Unit Flags - Immune to NPC/NPC"),
(@ENTRY,0,5,6,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,3900,0,0,0,0,0,0,"Balizar the Umbrage - On Data Set - Set Data Caedakar the Vicious"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,3898,0,0,0,0,0,0,"Balizar the Umbrage - On Data Set - Set Data Aligar the Tormentor");

-- Dark Strand Forsaken Scout SAI
SET @ENTRY := 3893;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,18,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Forsaken Scout - On Just Summoned - Set Unit Flags - Immune to NPC/NPC"),
(@ENTRY,0,1,0,38,0,100,0,1,1,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Forsaken Scout - On Data Set - Remove Unit Flags - Immune to NPC/NPC");


-- Dark Strand Assassin SAI
SET @ENTRY := 3879;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,5000,11000,18000,11,3405,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Strand Assassin - IC - Cast Soul Rend"),
(@ENTRY,0,1,0,0,0,100,0,5000,9000,15000,21000,11,11675,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Strand Assassin - IC - Cast Drain Soul"),
(@ENTRY,0,2,0,54,0,100,0,0,0,0,0,18,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Assassin - On Just Summoned - Set Unit Flags - Immune to NPC/NPC"),
(@ENTRY,0,3,0,38,0,100,0,1,1,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Strand Assassin - On Data Set - Remove Unit Flags - Immune to NPC/NPC");

-- Caedakar the Vicious SAI
SET @ENTRY := 3900;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,1,0,0,0,0,11,7165,2,0,0,0,0,1,0,0,0,0,0,0,0,"Caedakar the Vicious - On Just Summoned - Cast 'Battle Stance' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4000,9000,11000,16000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Caedakar the Vicious - In Combat - Cast 'Hamstring'"),
(@ENTRY,0,2,0,0,0,100,1,3000,4000,8000,15000,11,25712,0,0,0,0,0,2,0,0,0,0,0,0,0,"Caedakar the Vicious - In Combat - Cast 'Heroic Strike' (No Repeat)"),
(@ENTRY,0,3,0,54,0,100,0,0,0,0,0,18,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caedakar the Vicious - On Just Summoned - Set Unit Flags - Immune to NPC/NPC"),
(@ENTRY,0,4,0,38,0,100,0,1,1,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caedakar the Vicious - On Data Set - Remove Unit Flags - Immune to NPC/NPC");

-- Aligar the Tormentor SAI
SET @ENTRY := 3898;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,1,0,0,0,0,11,7165,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aligar the Tormentor - On Just Summoned - Cast 'Battle Stance' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,3000,4000,5000,6000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Aligar the Tormentor - In Combat - Cast 'Hamstring'"),
(@ENTRY,0,2,0,0,0,100,1,6000,7000,6000,7000,11,25712,0,0,0,0,0,2,0,0,0,0,0,0,0,"Aligar the Tormentor - In Combat - Cast 'Heroic Strike' (No Repeat)"),
(@ENTRY,0,3,0,54,0,100,0,0,0,0,0,18,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aligar the Tormentor - On Just Summoned - Set Unit Flags - Immune to NPC/NPC"),
(@ENTRY,0,4,0,38,0,100,0,1,1,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aligar the Tormentor - On Data Set - Remove Unit Flags - Immune to NPC/NPC");

UPDATE `creature_template` SET `ScriptName`='',`AIName`="SmartAI" WHERE `entry`=4484;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4484 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=448400 AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4484,0,0,1,19,0,100,1,976,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Feero Ironhand - On Quest Accept (Supplies to Aubderdine) - Store Targetlist '),
(4484,0,1,2,61,0,100,1,0,0,0,0,2,774,0,0,0,0,0,1,0,0,0,0,0,0,0,'Feero Ironhand - On Quest Accept (Supplies to Aubderdine) - Set Faction'),
(4484,0,2,3,61,0,100,1,0,0,0,0,19,512,0,0,0,0,0,1,0,0,0,0,0,0,0,'Feero Ironhand - On Quest Accept (Supplies to Aubderdine) - Remove Unit Flags'),
(4484,0,3,0,61,0,100,1,0,0,0,0,1,7,5000,0,0,0,0,1,0,0,0,0,0,0,0,'Feero Ironhand - On Quest Accept (Supplies to Aubderdine) - Say Line 7'),
(4484,0,4,0,7,0,100,0,0,0,0,0,19,512,0,0,0,0,0,1,0,0,0,0,0,0,0,'Feero Ironhand - On Evade - Remove Unit Flags'),
(4484,0,5,6,40,0,100,1,18,4484,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,'Feero Ironhand - On Reached WP18 - Say Line 0'),
(4484,0,6,7,61,0,100,1,0,0,0,0,107,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Feero Ironhand - On Reached WP18 - Summon Summon Group 0'),
(4484,0,7,0,61,0,100,1,0,0,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Feero Ironhand - On Reached WP18 - Pause WP (2 Seconds)'),
(4484,0,8,0,40,0,100,1,19,4484,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Feero Ironhand - On Reached WP19 - Say Line 1'),
(4484,0,9,10,40,0,100,1,27,4484,0,0,1,2,5000,0,0,0,0,1,0,0,0,0,0,0,0,'Feero Ironhand - On Reached WP27 - Say'),
(4484,0,10,11,61,0,100,1,0,0,0,0,107,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Feero Ironhand - On Reached 27 - Summon Summon Group 1'),
(4484,0,11,0,61,0,100,1,0,0,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Feero Ironhand - On Reached WP27 - Pause WP (5 Seconds)'),
(4484,0,12,0,40,0,100,1,28,4484,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Feero Ironhand - On Reached WP28 - Say Line 3'),
(4484,0,13,14,40,0,100,1,41,4484,0,0,1,4,5000,0,0,0,0,1,0,0,0,0,0,0,0,'Feero Ironhand - On Reached WP41 - Say Line 4'),
(4484,0,14,15,61,0,100,1,0,0,0,0,107,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Feero Ironhand - On Reached WP41 - Summon Summon Group 2'),
(4484,0,15,0,61,0,100,1,0,0,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Feero Ironhand - On Reached WP41 - Pause WP (10 Seconds)'),
(4484,0,16,17,40,0,100,1,43,4484,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'Feero Ironhand - On Reached WP43 - Say Line 5'),
(4484,0,17,18,61,0,100,1,0,0,0,0,15,976,0,0,0,0,0,12,1,0,0,0,0,0,0,'Feero Ironhand - On Reached 43 - Call Areaexploredoreventhappens'),
(4484,0,18,19,61,0,100,1,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Feero Ironhand - On Reached 43 - Set Run'),
(4484,0,19,0,61,0,100,1,0,0,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Feero Ironhand - On Reached WP43 - Pause WP (5 Seconds)'),
(4484,0,20,0,40,0,100,1,45,4484,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Feero Ironhand - On Reached WP45 - Despawn'),
(4484,0,21,0,6,0,100,1,0,0,0,0,6,976,0,0,0,0,0,12,1,0,0,0,0,0,0,'Feero Ironhand - On Death - Fail Quest'),
(4484,0,22,0,52,0,100,1,2,4484,0,0,45,1,1,0,0,0,0,9,3893,0,100,0,0,0,0,'Feero Ironhand - On Text Over line 2 - Set Data Forsaken Scout'),
(4484,0,23,0,52,0,100,1,4,4484,0,0,1,0,5000,0,0,0,0,19,3899,0,0,0,0,0,0,'Feero Ironhand - On Text Over line 4 - Say Line 0 (Balizar the Umbrage)'),
(4484,0,24,25,52,0,100,1,0,3899,0,0,1,5,5000,0,0,0,0,1,0,0,0,0,0,0,0,'Feero Ironhand - On Text Over line 0 (Balizar the Umbrage) - Say Line 5'),
(4484,0,25,0,61,0,100,1,0,0,0,0,45,1,1,0,0,0,0,19,3899,0,0,0,0,0,0,'Feero Ironhand - On Text Over line 0 (Balizar the Umbrage) - Set Data (Balizar the Umbrage)'),
(4484,0,26,0,52,0,100,1,7,4484,0,0,53,0,4484,0,976,0,1,1,0,0,0,0,0,0,0,'Feero Ironhand - On Text Over Line 7 - Start WP'),
(4484,0,27,0,52,0,100,1,0,4484,0,0,45,1,1,0,0,0,0,9,3879,0,100,0,0,0,0,'Feero Ironhand - On Text Over line 0 - Set Data Dark Strand assasin');

DELETE FROM `creature_summon_groups` WHERE `summonerId`=4484;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES 
(4484, 0, 0, 3879, 3491.09, 214.76, 11.36, 3.30, 1, 30000), 
(4484, 0, 0, 3879, 3491.18, 212.28, 11.25, 3.03, 1, 30000), 
(4484, 0, 0, 3879, 3490.74, 210.59, 11.32, 3.03, 1, 30000), 
(4484, 0, 0, 3879, 3490.46, 208.78, 11.39, 2.93, 1, 30000), 
(4484, 0, 1, 3893, 3782.51, 145.57, 8.54, 2.93, 1, 30000), 
(4484, 0, 1, 3893, 3778.84, 143.46, 8.41, 2.93, 1, 30000), 
(4484, 0, 1, 3893, 3782.26, 149.61, 8.34, 2.93, 1, 30000), 
(4484, 0, 2, 3900, 4108.34, 53.69, 26.18, 2.93, 1, 30000), 
(4484, 0, 2, 3898, 4114.55, 54.48, 27.21, 2.93, 1, 30000),
(4484, 0, 2, 3899, 4116.81, 50.14, 26.15, 2.93, 1, 30000);

DELETE FROM `creature_text` WHERE `entry` IN(4484,3899);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES 
(4484, 0, 0, 'It looks like we''re in trouble. Look lively, here they come!', 12, 7, 100, 0, 0, 0, 'Feero', 1372),
(4484, 1, 0, 'Assassins from that cult you found... Let''s get moving before someone else finds us out here.', 12, 7, 100, 0, 0, 0, 'Feero', 1294),
(4484, 2, 0, 'Hold! I sense an evil presence... Undead!', 12, 7, 100, 0, 0, 0, 'Feero',1373),
(4484, 3, 0, 'They''re coming out of the woodwork today. Let''s keep moving or we may find more things that want me dead.', 12, 7, 100, 0, 0, 0, 'Feero', 1310),
(4484, 4, 0, 'These three again?', 12, 7, 100, 0, 0, 0, 'Feero',1374),
(4484, 5, 0, 'I''ll finish you off for good this time!', 12, 0, 100, 0, 0, 0, 'Feero', 1499),
(4484, 6, 0, 'Well done! I should be fine on my own from here. Remember to talk to Delgren when you return to Maestra''s Post in Ashenvale.', 12, 7, 100, 0, 0, 0, 'Feero', 1315),
(4484, 7, 0, 'We must move quickly. Auberdine isn''t too far away, but many enemies lurk in the forest.', 12, 7, 100, 0, 0, 0, 'Feero', 1292),
(3899, 0, 0, 'Not quite so sure of yourself without the Purifier, hm?', 12, 0, 100, 0, 0, 0, 'Balizar the Umbrage',1313);

DELETE FROM `waypoints` WHERE `entry`=4484;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(4484, 1, 3175.930908, 193.541306, 3.483540, ''),
(4484, 2, 3187.917969, 197.117691, 4.699296, ''),
(4484, 3, 3203.483643, 192.349060, 5.908475 , ''),
(4484, 4, 3219.118408, 182.236420, 6.588406, ''),
(4484, 5, 3229.847412, 191.230438, 7.494555, ''),
(4484, 6, 3225.035156, 199.438843, 7.096720, ''),
(4484, 7, 3227.651855, 210.760071, 8.629334, ''),
(4484, 8, 3232.935303, 223.724869, 10.052238 , ''),
(4484, 9, 3263.071777, 225.984848, 10.645896 , ''),
(4484, 10, 3284.759521, 220.414124, 10.950543, ''),
(4484, 11, 3315.646973, 210.198044, 11.967686, ''),
(4484, 12, 3341.024414, 214.290497, 13.320419, ''),
(4484, 13, 3367.133789, 224.587524, 11.867117, ''),
(4484, 14, 3409.073242, 226.385315, 9.215232, ''),
(4484, 15, 3432.292236, 225.396271, 10.028325, ''),
(4484, 16, 3454.865723, 219.339172, 12.593150, ''),
(4484, 17, 3470.463867, 214.818161, 13.264424, ''),
(4484, 18, 3481.416992, 212.556610, 12.354552, 'say_1'),
(4484, 19, 3500.315674, 210.936295, 10.226085, 'say_death_1'),
(4484, 20, 3532.806641, 215.041473, 8.372272, ''),
(4484, 21, 3565.314209, 217.748749, 5.300299, ''),
(4484, 22, 3601.654297, 217.771378, 1.299005, ''),
(4484, 23, 3638.605713, 212.525879, 1.433142 , ''),
(4484, 24, 3680.757324, 200.308197, 3.385010, ''),
(4484, 25, 3725.670410, 180.395966, 6.314014, ''),
(4484, 26, 3762.346924, 159.685959, 7.388617, ''),
(4484, 27, 3774.541260, 151.170029, 7.799640, 'say_2'),
(4484, 28, 3789.697754, 140.396774, 9.062237, 'say_death_2'),
(4484, 29, 3821.424072, 111.609528, .258650, ''),
(4484, 30, 3850.376465, 84.710922, 13.941991, ''),
(4484, 31, 3875.349121, 60.388409, 14.988914 , ''),
(4484, 32, 3908.238525, 35.209225, 15.332011, ''),
(4484, 33, 3942.200928, 14.888245, 16.969385, ''),
(4484, 34, 3976.427246, -0.073566, 16.968657, ''),
(4484, 35, 4008.343750, -6.628914, 16.464090, ''),
(4484, 36, 4029.483643, -6.640755, 16.549721, ''),
(4484, 37, 4050.055908, 1.488156, 15.746178, ''),
(4484, 38, 4083.412109, 14.085828, 15.851171, ''),
(4484, 39, 4098.462891, 20.032930, 17.252523, ''),
(4484, 40, 4105.861816, 34.792000, 20.284599, ''),
(4484, 41, 4110.536133, 45.538300, 23.154394, 'say_3_A'),
(4484, 42, 4112.863281, 51.454445, 26.165501, 'say_3_B'),
(4484, 43, 4126.177246, 53.689651, 26.399027, 'say_death_3'),
(4484, 44, 4149.127441, 46.833157, 24.660984, ''),
(4484, 45, 4164.439941, 55.935448, 26.793362, 'despawn');
*/
