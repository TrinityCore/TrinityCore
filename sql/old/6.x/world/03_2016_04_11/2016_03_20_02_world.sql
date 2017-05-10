-- Charscale Invoker SAI
SET @ENTRY := 40417;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,6000,8000,8000,11,75419,0,0,0,0,0,2,0,0,0,0,0,0,0,"Charscale Invoker - In Combat - Cast 'Scorch'"),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,20000,11,75413,0,0,0,0,0,1,0,0,0,0,0,0,0,"Charscale Invoker - In Combat - Cast 'Flame Wave'");

-- Charscale Assaulter SAI
SET @ENTRY := 40419;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,6000,7000,7000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Charscale Assaulter - In Combat - Cast 'Cleave'"),
(@ENTRY,0,1,0,0,0,100,0,14000,14000,14000,14000,11,75418,0,0,0,0,0,1,0,0,0,0,0,0,0,"Charscale Assaulter - In Combat - Cast 'Shockwave'");

-- Charscale Commander SAI
SET @ENTRY := 40423;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,0,0,100,0,8000,8000,40000,40000,11,75414,0,0,0,0,0,1,0,0,0,0,0,0,0,"Charscale Commander - In Combat - Cast 'Rallying Shout'"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Charscale Commander - In Combat - Say Line 0"),
(@ENTRY,0,2,0,0,0,100,0,15000,15000,14000,14000,11,13737,0,0,0,0,0,2,0,0,0,0,0,0,0,"Charscale Commander - In Combat - Cast 'Mortal Strike'");

-- Charscale Commander Text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(@ENTRY, 0, 0, '%s rallies the other combatants with a battle roar!', 41, 0, 100, 0, 0, 0, 40420, 'Charscale Commander');

-- Charscale Elite SAI
SET @ENTRY := 40421;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,12000,12000,11000,11000,11,15621,0,0,0,0,0,2,0,0,0,0,0,0,0,"Charscale Elite - In Combat - Cast 'Skull Crack'");

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_ruby_sanctum_rallying_shout';
INSERT INTO `spell_script_names` VALUE
(75415, 'spell_ruby_sanctum_rallying_shout');
