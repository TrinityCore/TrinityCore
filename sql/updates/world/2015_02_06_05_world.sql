-- Commander Hogarth SAI
SET @ENTRY := 19937;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,33900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Hogarth - On Respawn - Cast 'Shroud of Death' (No Repeat)"),
(@ENTRY,0,1,2,20,0,100,0,10258,0,0,0,12,20117,6,0,0,0,0,8,0,0,0,-1186.95,2608.81,27.702,5.38523,"Commander Hogarth - On Quest 'Honor the Fallen' Finished - Summon Creature 'Vengeful Unyielding Knight'"),
(@ENTRY,0,2,3,61,0,100,0,10258,0,0,0,12,19863,6,0,0,0,0,8,0,0,0,-1192.14,2602.7,29.2625,0.0820243,"Commander Hogarth - On Quest 'Honor the Fallen' Finished - Summon Creature 'Vengeful Unyielding'"),
(@ENTRY,0,3,4,61,0,100,0,10258,0,0,0,12,20117,6,0,0,0,0,8,0,0,0,-1181.95,2611.13,27.3004,4.61566,"Commander Hogarth - On Quest 'Honor the Fallen' Finished - Summon Creature 'Vengeful Unyielding Knight'"),
(@ENTRY,0,4,5,61,0,100,0,10258,0,0,0,12,19863,6,0,0,0,0,8,0,0,0,-1183.65,2603.66,29.4927,6.09219,"Commander Hogarth - On Quest 'Honor the Fallen' Finished - Summon Creature 'Vengeful Unyielding'"),
(@ENTRY,0,5,6,61,0,100,0,10258,0,0,0,12,19863,6,0,0,0,0,8,0,0,0,-1184.48,2609.26,27.7192,5.01103,"Commander Hogarth - On Quest 'Honor the Fallen' Finished - Summon Creature 'Vengeful Unyielding'"),
(@ENTRY,0,6,7,61,0,100,0,10258,0,0,0,12,19863,6,0,0,0,0,8,0,0,0,-1175.39,2607.4,28.853,3.63473,"Commander Hogarth - On Quest 'Honor the Fallen' Finished - Summon Creature 'Vengeful Unyielding'"),
(@ENTRY,0,7,8,61,0,100,0,10258,0,0,0,12,19863,6,0,0,0,0,8,0,0,0,-1178.36,2609.96,27.8814,4.12375,"Commander Hogarth - On Quest 'Honor the Fallen' Finished - Summon Creature 'Vengeful Unyielding'"),
(@ENTRY,0,8,9,61,0,100,0,10258,0,0,0,12,19863,6,0,0,0,0,8,0,0,0,-1182.51,2608.35,28.1201,4.67383,"Commander Hogarth - On Quest 'Honor the Fallen' Finished - Summon Creature 'Vengeful Unyielding'"),
(@ENTRY,0,9,10,61,0,100,0,10258,0,0,0,12,19863,6,0,0,0,0,8,0,0,0,-1189.12,2601.88,29.6988,0.242659,"Commander Hogarth - On Quest 'Honor the Fallen' Finished - Summon Creature 'Vengeful Unyielding'"),
(@ENTRY,0,10,11,61,0,100,0,10258,0,0,0,12,19863,6,0,0,0,0,8,0,0,0,-1179.46,2606.03,29.0216,3.81031,"Commander Hogarth - On Quest 'Honor the Fallen' Finished - Summon Creature 'Vengeful Unyielding'"),
(@ENTRY,0,11,12,61,0,100,0,10258,0,0,0,12,19863,6,0,0,0,0,8,0,0,0,-1180.6,2598.15,35.2317,1.94692,"Commander Hogarth - On Quest 'Honor the Fallen' Finished - Summon Creature 'Vengeful Unyielding'"),
(@ENTRY,0,12,13,61,0,100,0,10258,0,0,0,12,20117,6,0,0,0,0,8,0,0,0,-1190.87,2607.06,27.9991,5.86898,"Commander Hogarth - On Quest 'Honor the Fallen' Finished - Summon Creature 'Vengeful Unyielding Knight'"),
(@ENTRY,0,13,14,61,0,100,0,10258,0,0,0,12,19863,6,0,0,0,0,8,0,0,0,-1179.81,2603.43,29.8027,3.12637,"Commander Hogarth - On Quest 'Honor the Fallen' Finished - Summon Creature 'Vengeful Unyielding'"),
(@ENTRY,0,14,15,61,0,100,0,10258,0,0,0,12,19863,6,0,0,0,0,8,0,0,0,-1184.47,2606.9,28.4442,5.18881,"Commander Hogarth - On Quest 'Honor the Fallen' Finished - Summon Creature 'Vengeful Unyielding'"),
(@ENTRY,0,15,16,61,0,100,0,10258,0,0,0,12,19863,6,0,0,0,0,8,0,0,0,-1186.63,2605.58,28.7169,5.79079,"Commander Hogarth - On Quest 'Honor the Fallen' Finished - Summon Creature 'Vengeful Unyielding'"),
(@ENTRY,0,16,17,61,0,100,0,10258,0,0,0,12,19863,6,0,0,0,0,8,0,0,0,-1189.03,2604.6,28.8694,6.10697,"Commander Hogarth - On Quest 'Honor the Fallen' Finished - Summon Creature 'Vengeful Unyielding'"),
(@ENTRY,0,17,18,61,0,100,0,10258,0,0,0,12,19863,6,0,0,0,0,8,0,0,0,-1185.68,2603.39,29.4476,5.18881,"Commander Hogarth - On Quest 'Honor the Fallen' Finished - Summon Creature 'Vengeful Unyielding'"),
(@ENTRY,0,18,0,61,0,100,0,10258,0,0,0,12,19863,6,0,0,0,0,8,0,0,0,-1181.97,2605.76,28.9476,4.40683,"Commander Hogarth - On Quest 'Honor the Fallen' Finished - Summon Creature 'Vengeful Unyielding'");

DELETE FROM `creature_template_addon` WHERE `entry` IN (20117, 19863);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(20117, 0, 0, 0, 0, 0, '33900'),
(19863, 0, 0, 0, 0, 0, '33900');

-- Vengeful Unyielding Knight SAI
SET @ENTRY := 20117;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,41,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vengeful Unyielding Knight - On Just Summoned - Despawn In 15000 ms"),
(@ENTRY,0,1,0,54,0,100,0,0,0,0,0,5,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vengeful Unyielding Knight - On Just Summoned - Play Emote 2");

-- Vengeful Unyielding SAI
SET @ENTRY := 19863;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,41,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vengeful Unyielding - On Just Summoned - Despawn In 15000 ms"),
(@ENTRY,0,1,0,54,0,100,0,0,0,0,0,5,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vengeful Unyielding - On Just Summoned - Play Emote 2");
