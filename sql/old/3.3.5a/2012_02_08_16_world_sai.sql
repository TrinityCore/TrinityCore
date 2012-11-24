-- Chillmaw
SET @ENTRY := 33687;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,10000,11000,20000,23000,11,65248,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Chillmaw - Combat - Cast Frost Breath"),
(@ENTRY,0,1,0,2,0,100,1,0,35,0,0,11,65260,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Chillmaw - @35% health - Cast Wing Buffet"),
(@ENTRY,0,2,0,2,0,100,1,0,25,0,0,11,60603,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Chillmaw - @25% health - Cast Eject Passenger 1"),
(@ENTRY,0,3,0,2,0,100,1,0,50,0,0,11,62539,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Chillmaw - @50% health - Cast Eject Passenger 2"),
(@ENTRY,0,4,0,2,0,100,1,0,75,0,0,11,52205,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Chillmaw - @75% health - Cast Eject Passenger 3");
-- Cultist Bombardier SAI
SET @ENTRY   := 33695; -- NPC entry
SET @SPELL1  := 65128; -- Throw Dynamite
SET @SPELL2  := 65130; -- Time Bomb
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,6000,7000,8000,11,@SPELL1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Cultist Bombardier - Combat - Cast Throw Dynamite'),
(@ENTRY,0,1,0,0,0,100,0,18000,20000,6000,7000,11,@SPELL2,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Cultist Bombardier - Combat - Cast Time Bomb'),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Cultist Bombardier - On Aggro - Set Phase 1'),
(@ENTRY,0,3,0,1,1,100,1,0,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Cultist Bombardier - OOC - Despawn (Phase 1)');
