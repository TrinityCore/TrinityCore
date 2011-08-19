-- Demented Druid Spirit SAI
SET @ENTRY   := 15260; -- NPC entry
SET @SPELL1  := 6726;  -- Silence
SET @SPELL2  := 16247; -- Curse of Thorns
SET @SPELL3  := 21669; -- Moonfire
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=@ENTRY; -- Set SAI as AI. Remove cpp ScriptName if one exist
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY; -- Remove EAI if exist
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2500,2500,10000,15000,11,@SPELL1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Demented Druid Spirit - Combat - Cast Silence on victim'),
(@ENTRY,0,1,0,0,0,100,0,15000,15000,15000,20000,11,@SPELL2,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Demented Druid Spirit - Combat - Cast Curse of Thorns on victim'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,15000,20000,11,@SPELL3,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Demented Druid Spirit - Combat - Cast Moonfire on victim');

-- Shade of Taerar SAI
SET @ENTRY   := 15302; -- NPC entry
SET @SPELL1  := 24840; -- Poison Cloud
SET @SPELL2  := 20667; -- Corrosive Acid Breath
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=@ENTRY; -- Set SAI as AI. Remove cpp ScriptName if one exist
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY; -- Remove EAI if exist
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,12000,12000,10000,14000,11,@SPELL1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Shade of Taerar - Combat - Cast Poison Cloud on victim'),
(@ENTRY,0,1,0,0,0,100,0,30000,30000,25000,30000,11,@SPELL2,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Shade of Taerar - Combat - Cast Corrosive Acid Breath on victim');
