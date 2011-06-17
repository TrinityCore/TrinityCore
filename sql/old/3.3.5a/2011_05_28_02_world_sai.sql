-- Smart AI for Baltarhus the Warborn Clone
SET @ENTRY   := 39899; -- NPC entry
SET @SPELL1  := 40504;  -- Cleave
SET @SPELL2  := 75125; -- Blade Tempest
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,10000,24000,24000,11,@SPELL1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Baltarhus the Warborn Clone - Combat - Cast Cleave on victim'),
(@ENTRY,0,1,0,0,0,100,0,18000,25000,24000,26000,11,@SPELL2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Baltarhus the Warborn Clone - Cast Blade Tempest on self');
