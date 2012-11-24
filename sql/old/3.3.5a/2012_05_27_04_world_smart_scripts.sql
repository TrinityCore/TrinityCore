-- Reconstructed Wyrm SAI
SET @ENTRY  := 27693;
SET @SPELL1 := 49386; -- Not in dbc
SET @SPELL2 := 49343; -- Frost Breath Strafe
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,11,@SPELL2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reconstructed Wyrm - On spawn - cast aura'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,53,0,@ENTRY,0,0,0,0,1,0,0,0,0,0,0,0,'Reconstructed Wyrm - On spawn - Load Path');
-- waypoints for Reconstructed Wyrm
DELETE FROM `waypoints` WHERE `entry` IN (@ENTRY);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,4685.845,1130.759,150.1177, 'Reconstructed Wyrm'),
(@ENTRY,2,4686.284,1131.658,150.1177, 'Reconstructed Wyrm'),
(@ENTRY,3,4688.699,1166.089,161.2737, 'Reconstructed Wyrm'),
(@ENTRY,4,4702.308,1212.668,161.2737, 'Reconstructed Wyrm'),
(@ENTRY,5,4733.535,1260.209,169.6348, 'Reconstructed Wyrm'),
(@ENTRY,6,4751.818,1293.699,175.9404, 'Reconstructed Wyrm'),
(@ENTRY,7,4794.479,1345.154,199.5372, 'Reconstructed Wyrm'),
(@ENTRY,8,4812.264,1373.523,219.8613, 'Reconstructed Wyrm');
-- Fix spawns
UPDATE `creature` SET `position_x`=4685.845,`position_y`=1130.759,`position_z`=150.1177,`spawntimesecs`=120,`spawndist`=0,`MovementType`=0 WHERE `guid`=100211;
DELETE FROM `creature` WHERE `guid` IN (100256,133240,133241);
DELETE FROM `creature_addon` WHERE `guid` IN (100256,133240,133241);
