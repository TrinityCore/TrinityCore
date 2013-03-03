-- Jean Pierre Poulain SAI
SET @ENTRY  := 34244;
SET @GOSSIP := 10478;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,@GOSSIP,0,0,0,11,64795,1,0,0,0,0,7,0,0,0,0,0,0,0, 'Jean Pierre Poulain - On gossip option select - cast spell');
-- Cleanup gossip
UPDATE `gossip_menu_option` SET `action_script_id`=0 WHERE `menu_id`=@GOSSIP;
DELETE FROM `gossip_scripts` WHERE `id` IN (1047800);

-- Fizzcrank Fullthrottle SAI
SET @ENTRY  := 25590;
SET @GOSSIP := 9182;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,@GOSSIP,0,0,0,15,11708,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Fizzcrank Fullthrottle - On gossip option select - quest complete'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Fizzcrank Fullthrottle - On gossip option select - close gossip');
-- Cleanup gossip
UPDATE `gossip_menu_option` SET `action_script_id`=0 WHERE `menu_id`=@GOSSIP;
DELETE FROM `gossip_scripts` WHERE `id` IN (918200);

-- Keeper Remulos SAI
SET @ENTRY  := 11832;
SET @GOSSIP := 10215;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,@GOSSIP,0,0,0,11,57413,1,0,0,0,0,7,0,0,0,0,0,0,0, 'Keeper Remulos - On gossip option select - cast spell'),
(@ENTRY,0,1,2,62,0,100,0,@GOSSIP,1,0,0,11,57670,1,0,0,0,0,7,0,0,0,0,0,0,0, 'Keeper Remulos - On gossip option select - cast spell'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Keeper Remulos - On gossip option select - close gossip');
-- Cleanup gossip
UPDATE `gossip_menu_option` SET `action_script_id`=0 WHERE `menu_id`=@GOSSIP;
DELETE FROM `gossip_scripts` WHERE `id` IN (1021500,1021501);

-- Fizzcrank Recon Pilot SAI
SET @ENTRY  := 25841;
SET @GOSSIP := 21248;
SET @SCRIPT := 212481;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,@GOSSIP,0,0,0,11,46362,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Fizzcrank Recon Pilot - On gossip option select - cast spell'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Fizzcrank Recon Pilot - On gossip option select - close gossip'),
(@ENTRY,0,2,0,11,0,100,0,0,0,0,0,81,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Recon Pilot - On spawn - set gossip flag'),
(@ENTRY,0,3,4,8,0,100,0,46362,0,0,0,11,46362,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Fizzcrank Recon Pilot - On spellhit - cast spell on envoker'),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Recon Pilot - On spellhit - set phase 1'),
(@ENTRY,0,5,0,1,1,100,0,3000,3000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Recon Pilot - OOC - wait 3 sec despawn (Phase 1)');
-- Cleanup EAI
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
-- Cleanup gossip
UPDATE `gossip_menu_option` SET `action_script_id`=0 WHERE `menu_id`=@GOSSIP AND `id`=0;
DELETE FROM `gossip_scripts` WHERE `id`=@SCRIPT;

-- Glodrak Huntsniper SAI
SET @ENTRY  := 24657;
SET @GOSSIP := 10603;
SET @SCRIPT := 1060400;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,@GOSSIP,0,0,0,11,66592,1,0,0,0,0,7,0,0,0,0,0,0,0, 'Glodrak Huntsniper - On gossip option select - cast spell'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Glodrak Huntsniper - On gossip option select - close gossip');
-- Cleanup gossip
UPDATE `gossip_menu_option` SET `action_script_id`=0 WHERE `menu_id`=@GOSSIP AND `id`=0;
DELETE FROM `gossip_scripts` WHERE `id`=@SCRIPT;
-- Goldark Snipehunter SAI
SET @ENTRY  := 23486;
SET @GOSSIP := 10604;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,@GOSSIP,0,0,0,11,66592,1,0,0,0,0,7,0,0,0,0,0,0,0, 'Goldark Snipehunter - On gossip option select - cast spell'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Goldark Snipehunter - On gossip option select - close gossip');
-- Cleanup gossip
UPDATE `gossip_menu_option` SET `action_script_id`=0 WHERE `menu_id`=@GOSSIP AND `id`=0;

-- Pol Amberstill & Driz Tumblequick SAI
SET @ENTRY   := 24468;
SET @ENTRY1  := 24510;
SET @GOSSIP  := 8958;
SET @GOSSIP1 := 8960;
SET @SCRIPT  := 895800;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN (@ENTRY,@ENTRY1);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY1);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Pol Amberstill
(@ENTRY,0,0,1,62,0,100,0,@GOSSIP,6,0,0,11,44262,1,0,0,0,0,7,0,0,0,0,0,0,0, 'Pol Amberstill - On gossip option select - cast spell'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Pol Amberstill - On gossip option select - close gossip'),
(@ENTRY,0,2,3,62,0,100,0,@GOSSIP1,0,0,0,11,44262,1,0,0,0,0,7,0,0,0,0,0,0,0, 'Pol Amberstill - On gossip option select - cast spell'),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Pol Amberstill - On gossip option select - close gossip'),
-- Driz Tumblequick
(@ENTRY1,0,0,1,62,0,100,0,@GOSSIP,6,0,0,11,44262,1,0,0,0,0,7,0,0,0,0,0,0,0, 'Driz Tumblequick - On gossip option select - cast spell'),
(@ENTRY1,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Driz Tumblequick - On gossip option select - close gossip'),
(@ENTRY1,0,2,3,62,0,100,0,@GOSSIP1,0,0,0,11,44262,1,0,0,0,0,7,0,0,0,0,0,0,0, 'Driz Tumblequick - On gossip option select - cast spell'),
(@ENTRY1,0,3,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Driz Tumblequick - On gossip option select - close gossip');
-- Ckeanup gossip
UPDATE `gossip_menu_option` SET `action_script_id`=0 WHERE `menu_id`=@GOSSIP AND `id`=6;
UPDATE `gossip_menu_option` SET `action_script_id`=0 WHERE `menu_id`=@GOSSIP1 AND `id`=0;
DELETE FROM `gossip_scripts` WHERE `id`=@SCRIPT;

-- Steel Gate Chief Archaeologist SAI
SET @ENTRY  := 24399;
SET @GOSSIP := 8953;
SET @SCRIPT := 895300;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,@GOSSIP,0,0,0,11,43533,1,0,0,0,0,7,0,0,0,0,0,0,0, 'Steel Gate Chief Archaeologist - On gossip option select - cast spell'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Steel Gate Chief Archaeologist - On gossip option select - close gossip');
-- Cleanup gossip
UPDATE `gossip_menu_option` SET `action_script_id`=0 WHERE `menu_id`=@GOSSIP AND `id`=0;
DELETE FROM `gossip_scripts` WHERE `id`=@SCRIPT;

-- Drakuru SAI
SET @ENTRY := 26423;
SET @GOSSIP := 21249;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,@GOSSIP,0,0,0,33,27921,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Drakuru - On gossip option select - killcredit'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Drakuru - On gossip option select - close gossip');
-- Cleanup gossip
UPDATE `gossip_menu_option` SET `action_script_id`=0 WHERE `menu_id`=@GOSSIP AND `id`=0;
DELETE FROM `gossip_scripts` WHERE `id`=@GOSSIP;

-- Dread Captain DeMeza SAI
SET @ENTRY := 28048;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,9647,0,0,0,11,50517,1,0,0,0,0,7,0,0,0,0,0,0,0, 'Dread Captain DeMeza - On gossip option select - cast spell'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Dread Captain DeMeza - On gossip option select - close gossip');
-- Cleanup gossip
UPDATE `gossip_menu_option` SET `action_script_id`=0 WHERE `menu_id`=9647 AND `id`=0;
DELETE FROM `gossip_scripts` WHERE `id`=9647;
