-- Tunnel Rat Scout SAI
SET @ENTRY := 1173;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tunnel Rat Scout - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2300,2700,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Tunnel Rat Scout - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tunnel Rat Scout - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Deatholme Necromancer SAI
SET @ENTRY := 16317;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,300000,300000,11,29066,1,0,0,0,0,1,0,0,0,0,0,0,0,"Deatholme Necromancer - Out of Combat - Cast 'Summon Dreadbone Skeleton'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4800,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Deatholme Necromancer - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,2,0,2,0,100,0,0,20,8000,12000,11,29067,1,0,0,0,0,1,0,0,0,0,0,0,0,"Deatholme Necromancer - Between 0-20% Health - Cast 'Slave Drain'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deatholme Necromancer - Between 0-15% Health - Flee For Assist (No Repeat)");
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=16317) AND `emote`=0;

DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=18453);

-- Shattered Hand Warlock SAI
SET @ENTRY := 19411;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,13787,1,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Warlock - Out of Combat - Cast 'Demon Armor'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2400,3800,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Warlock - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,2,0,0,0,85,0,5800,11800,16000,22000,11,11962,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Warlock - In Combat - Cast 'Immolate'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Warlock - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,4,0,6,0,10,0,0,0,0,0,11,38879,7,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Warlock - On Just Died - Cast 'Soul Burden'");
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=19411) AND `bytes1`=0;
UPDATE `creature_addon`  SET `auras`= '' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=19411);

DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=10504);
DELETE FROM `creature_template_addon` WHERE `entry`=10504;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (10504,0,4097,0, '');
