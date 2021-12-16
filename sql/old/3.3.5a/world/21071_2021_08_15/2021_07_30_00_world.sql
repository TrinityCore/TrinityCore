--
UPDATE `creature_template` SET `unit_flags` = `unit_flags`|256 WHERE `entry` = 27439;
UPDATE `smart_scripts` SET `action_param6` = 3 WHERE `entryorguid` IN (-85827,-85825,-81121,-81120,-81118,-81117,27886,27932,29050,30331,31087,31157,31432,33519,37828,34102,27482) AND `source_type` = 0 AND `action_type` = 53;
UPDATE `smart_scripts` SET `action_param6` = 3 WHERE `entryorguid` IN (952000,1093600,2485200,2545109,3027400,3033100,3173700,3183300,3188100,3222500,3801700) AND `source_type` = 9 AND `action_type` = 53;
UPDATE `smart_scripts` SET `action_param6` = 3 WHERE `entryorguid` IN (-78647,-78644,-78643,-78642,14325,15491,17875,17953,24238,25456,25729,25783,27102,27229,27383,27439,27693,11832,28244) AND `source_type` = 0 AND `action_type` = 53;
UPDATE `smart_scripts` SET `action_param6` = 3 WHERE `entryorguid` IN (1183201,2576600,12557800) AND `source_type` = 9 AND `action_type` = 53;

UPDATE `smart_scripts` SET `action_param6` = 3 WHERE `entryorguid` IN (2822900) AND `source_type` = 9 AND `action_type` = 53;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 28229 AND `source_type` = 0 AND `id` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(28229,0,2,0,37,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Venture Co. Pilot - On AI Initialize - Set Reactstate Passive");

UPDATE `smart_scripts` SET `action_param6` = 3 WHERE `entryorguid` IN (2967700,2990300) AND `source_type` = 9 AND `action_type` = 53;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 29677 AND `source_type` = 0 AND `id` = 7;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 29903 AND `source_type` = 0 AND `id` = 8;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(29677,0,7,0,37,0,100,512,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Frosthound - On AI Initialize - Set Reactstate Passive"),
(29903,0,8,0,37,0,100,512,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Frost Bite - On AI Initialize - Set Reactstate Passive");

UPDATE `smart_scripts` SET `action_param6` = 3 WHERE `entryorguid` IN (1620600,1620800,1620900) AND `source_type` = 9 AND `action_type` = 53;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1620600,1620800,1620900) AND `source_type` = 9 AND `id` = 6;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1620600,9,6,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Apprentice Varnis - On Script - Set Reactstate Passive"),
(1620800,9,6,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Apothecary Enith - On Script - Set Reactstate Passive"),
(1620900,9,6,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ranger Vedoran - On Script - Set Reactstate Passive");

UPDATE `smart_scripts` SET `action_param6` = 3 WHERE `entryorguid` IN (2179701,2762600,2866900) AND `source_type` = 9 AND `action_type` = 53;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2179701 AND `source_type` = 9 AND `id` = 5;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2762600 AND `source_type` = 9 AND `id` = 1;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2866900 AND `source_type` = 9 AND `id` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2179701,9,5,0,0,0,100,512,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ancient Shadowmoon Spirit - On Script 2 - Set Reactstate Passive"),
(2762600,9,1,0,0,0,100,512,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tatjana's Horse - On Script - Set Reactstate Passive"),
(2866900,9,1,0,0,0,100,512,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Flying Fiend - On Script - Set Reactstate Passive");

UPDATE `smart_scripts` SET `action_param6` = 3 WHERE `entryorguid` IN (30393,30461) AND `source_type` = 0 AND `action_type` = 53;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 30393 AND `source_type` = 0 AND `id` = 3;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 30461 AND `source_type` = 0 AND `id` = 6;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(30393,0,3,0,37,0,100,512,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Veranus - On AI Initialize - Set Reactstate Passive"),
(30461,0,6,0,37,0,100,512,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Veranus - On AI Initialize - Set Reactstate Passive");
