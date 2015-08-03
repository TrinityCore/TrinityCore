-- Hut Fire SAI Quest: This Just In: Fire Still Hot! "Now looks more like Offi"
SET @ENTRY := 29692;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,59000,59000,11,55049,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Hut Fire - OOC - Cast Torch on Self'),
(@ENTRY,0,1,0,8,0,100,0,55037,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Hut Fire - On Spell Hit - Despawn');
