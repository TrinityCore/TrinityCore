-- Fix [Qs] Words of Power /11640/11942/{A/H}
-- 10x to Subv for giving me idea how to fix it
SET @BEAM := 47848;
SET @NECRO := 25378;
SET @NECROguid := 300100;
SET @NAFERSET := 26076;
SET @Blast := 15587;
SET @Renew:= 11640;
SET @Corruption := 32063;
SET @Shadow := 9613;
-- Add spawns for the three necromancers
DELETE FROM `creature` WHERE `guid` IN (@NECROguid,@NECROguid+1,@NECROguid+2);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `MovementType`) VALUES
(@NECROguid, 25378, 571, 1, 3, 4101.931641, 3761.125000, 92.664742, 4.909590, 180, 0, 0, 0),
(@NECROguid+1, 25378, 571, 1, 3, 4133.339355, 3743.313721, 92.670166, 3.474295, 180, 0, 0, 0),
(@NECROguid+2, 25378, 571, 1, 3, 4121.242676, 3708.384766, 92.665283, 1.864472, 180, 0, 0, 0);
-- Add SAI for En"kilah Necromancer
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@NECRO;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@NECRO;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@NECRO;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NECRO,0,0,0,1,0,100,0,10000,20000,180000,200000,11,@BEAM,0,0,0,0,0,11,@NAFERSET,30,0,0,0,0,0,' En"kilah Necromancer - OOC - Cast spell Purple Beam on Naferset'),
(@NECRO,0,1,0,6,0,100,0,0,0,0,0,45,0,1,0,0,0,0,11,@NAFERSET,50,0,0,0,0,0,' En"kilah Necromancer - on death - Data set 0 1 on Hight Priest Nafarset'),
(@NECRO,0,2,0,0,0,100,0,2000,3000,15000,16000,11,@Corruption,0,0,0,0,0,2,0,0,0,0,0,0,0,' En"kilah Necromancer - IC - Corruption'),
(@NECRO,0,3,0,0,0,100,0,4000,6000,2000,6500,11,@Shadow,32,0,0,0,0,2,0,0,0,0,0,0,0, 'En"kilah Necromancer - Ic - Shadow Bolt');
--  Add SAI for Hight Priest Naferset
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@NAFERSET;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@NAFERSET;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NAFERSET,0,0,0,38,0,100,0,0,1,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,' Hight Priest Nafarset - On Data set 0 1 - Increment event phase by 1'),
(@NAFERSET,0,1,2,60,4,100,1,1000,2000,1000,2000,1,0,1000,0,0,0,0,1,0,0,0,0,0,0,0, 'Hight Priest Nafarset - On Event update /in event phase 3/ - Say text 0'),
(@NAFERSET,0,2,3,61,4,100,0,0,0,0,0,19,33555200,0,0,0,0,0,1,0,0,0,0,0,0,0,' Hight Priest Nafarset - Linked with event 1 - Set field flags to 0'),
(@NAFERSET,0,3,0,61,4,100,0,0,0,0,0,49,0,0,0,0,0,0,21,20,0,0,0,0,0,0,' Hight Priest Nafarset - Linked with event 2 - Attack start on closest player'),
(@NAFERSET,0,4,0,0,4,100,0,4000,6000,5000,8000,11,@Blast,0,0,0,0,0,2,0,0,0,0,0,0,0,' Hight Priest Nafarset - IC - Cast spell Mind Blast'),
(@NAFERSET,0,5,0,0,4,100,0,8000,12000,10000,15000,11,@Renew,0,0,0,0,0,1,0,0,0,0,0,0,0,' Hight Priest Nafarset - IC - Cast spell Renew on self'),
(@NAFERSET,0,6,7,6,0,100,0,0,0,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0,' Hight Priest Nafarset - On death - Data set 0 0'),
(@NAFERSET,0,7,0,61,0,100,0,0,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,' Hight Priest Nafarset - Linked with event 6 - Reset');
-- Hight Priest Naferset's Text
DELETE FROM `creature_text` WHERE `entry`=@NAFERSET;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@NAFERSET,0,0,'What is the meaning of this?! I have not yet finished my feast!',14,0,100,1,1000,0,'Nafarset on activation');
