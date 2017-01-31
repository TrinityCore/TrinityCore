-- Reanimated Frost Wyrm SAI
SET @ENTRY := 26841;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,5000,7000,11,47425,64,0,0,0,0,2,0,0,0,0,0,0,0,"Reanimated Frost Wyrm - In Combat CMC - Cast 'Frost Breath'");

UPDATE `waypoint_data` SET `move_type`=1 WHERE `id` IN (1169630, 1169640, 1169650, 1169660, 1169670, 1169680, 1169740, 1169750, 1169760, 1169770, 1169780, 1169790, 1169800, 1169810, 1169820, 1169910, 1169920, 1169930, 1170010, 1170020, 1170030, 1170040, 1170050, 1170060, 1170070, 1170190, 1170220, 1170230, 1170480, 1170490, 1170500, 1170510, 1170520, 1170530, 1170550, 1170560);
UPDATE `waypoint_data` SET `move_type`=1 WHERE `id` IN (1311770, 1311780, 1099150, 1099160, 1099270, 1158790);
UPDATE `waypoint_data` SET `move_type`=1 WHERE `id` IN (1081500, 1081510, 1081520, 1081550, 1081560, 1081580);
UPDATE `waypoint_data` SET `move_type`=1 WHERE `id` IN (971330, 971340, 971350, 971390, 971400, 1076260);
UPDATE `waypoint_data` SET `move_type`=1 WHERE `id` IN (1181900, 1181890, 1181860, 1181850, 1181880);
UPDATE `waypoint_data` SET `move_type`=1 WHERE `id` IN (404970, 404980, 404990, 405000, 405010, 405020, 405030, 405040, 405050, 1124010);
UPDATE `waypoint_data` SET `move_type`=1 WHERE `id` IN (1033880, 1033910, 1033940, 1033960, 1033980, 1034000, 1034030, 1034110);
UPDATE `waypoint_data` SET `move_type`=1 WHERE `id` IN (1311770,1311780);

UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE id IN (26175);

UPDATE `creature_addon` SET bytes1=50331648 WHERE `guid`=118406;
UPDATE `creature_template_addon` SET bytes1=0, bytes2=1 WHERE `entry` IN (728, 731, 3862, 9696, 10200, 11361, 30219);

DELETE FROM `creature_equip_template` WHERE `entry`=27361;
INSERT INTO `creature_equip_template` (`entry`,`id`,`itemEntry1`,`itemEntry2`,`itemEntry3`,`VerifiedBuild`) VALUES
(27361, 1, 35312, 0, 0, 12340),
(27361, 2, 1903, 0, 0, 12340);
