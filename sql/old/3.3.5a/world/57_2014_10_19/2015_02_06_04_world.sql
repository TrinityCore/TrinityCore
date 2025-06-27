-- Areatrigger SAI
SET @ENTRY := 1447;
DELETE FROM `areatrigger_scripts` WHERE `entry`=@ENTRY;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES (@ENTRY,"SmartTrigger");
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,2,0,0,46,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,81519,8127,0,0,0,0,0,"Areatrigger - On Trigger - Set Data 1 1");

-- Antu'sul SAI
SET @ENTRY := 8127;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,0,0,50,2,11600,11600,13300,21700,11,8376,0,0,0,0,0,1,0,0,0,0,0,0,0,"Antu'sul - In Combat - Cast 'Earthgrab Totem' (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,50,3,11600,11600,13300,21700,11,11899,0,0,0,0,0,1,0,0,0,0,0,0,0,"Antu'sul - In Combat - Cast 'Healing Ward' (Normal Dungeon)"),
(@ENTRY,0,2,6,4,0,100,3,0,0,0,0,11,11894,0,0,0,0,0,1,0,0,0,0,0,0,0,"Antu'sul - On Aggro - Cast 'Antu'sul's Minion' (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,3,0,2,0,100,3,0,20,0,0,11,11895,0,0,0,0,0,1,0,0,0,0,0,0,0,"Antu'sul - Between 0-20% Health - Cast 'Healing Wave of Antu'sul' (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,4,5,2,0,100,3,0,25,0,0,11,11894,0,0,0,0,0,1,0,0,0,0,0,0,0,"Antu'sul - Between 0-25% Health - Cast 'Antu'sul's Minion' (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,5,0,61,0,100,3,0,25,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Antu'sul - Between 0-25% Health - Say Line 0 (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,6,0,61,0,100,3,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Antu'sul - On Aggro - Say Line 1 (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,7,8,2,0,100,3,0,75,0,0,11,11894,0,0,0,0,0,1,0,0,0,0,0,0,0,"Antu'sul - Between 0-75% Health - Cast 'Antu'sul's Minion' (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,8,0,61,0,100,3,0,75,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Antu'sul - Between 0-75% Health - Say Line 2 (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,9,0,0,0,100,2,5000,5000,12000,14000,11,16006,0,0,0,0,0,5,0,0,0,0,0,0,0,"Antu'sul - In Combat - Cast 'Chain Lightning' (Normal Dungeon)"),
(@ENTRY,0,10,0,0,0,100,2,3000,3000,9000,11000,11,15501,0,0,0,0,0,2,0,0,0,0,0,0,0,"Antu'sul - In Combat - Cast 'Earth Shock' (Normal Dungeon)"),
(@ENTRY,0,11,0,38,0,100,0,1,1,0,0,49,0,0,0,0,0,0,21,100,0,0,0,0,0,0,"Antu'sul - On Data Set 1 1 - Start Attacking");

SET @ENTRY := 8127;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(@ENTRY,0,0, 'The children of Sul will protect their master. Rise once more Sul\'lithuz!',14,0,100,0,0,0, 4178, 0, 'Antu\'sul'),
(@ENTRY,1,0, 'Lunch has arrived, my beautiful children. Tear them to pieces!',14,0,100,0,0,0, 4166, 0, 'Antu\'sul'),
(@ENTRY,2,0, 'Rise and defend your master!',14,0,100,0,0,0, 4177, 0, 'Antu\'sul');
