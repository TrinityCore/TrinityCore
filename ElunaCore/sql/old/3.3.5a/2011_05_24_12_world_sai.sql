-- Shadow Adept <Cult of the Damned> SAI
SET @ENTRY   := 31145; -- NPC entry
SET @CHANNEL := 58847; -- Spell to cast
SET @TARGET  := 31245; -- Target creature entry
SET @SPELL1  := 60646; -- Shadow Blast
SET @SPELL2  := 17238; -- Drain Life
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,11,@CHANNEL,2,0,0,0,0,11,@TARGET,30,0,0,0,0,0, 'Shadow Adept - On spawn & reset - Channel Green Cultist Beam on target'),
(@ENTRY,0,1,0,0,0,100,0,4000,7000,6000,9000,11,@SPELL1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Shadow Adept - Combat - Cast Shadow Blast on victim'),
(@ENTRY,0,2,0,2,0,100,0,0,80,20000,30000,11,@SPELL2,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Shadow Adept - Combat - Cast Drain Life on victim');
-- Invisible Ooze Stalker Fixup and set as trigger
UPDATE `creature` SET `modelid`=0,`spawndist`=0,`MovementType`=0 WHERE `id`=31245;
UPDATE `creature_template` SET `InhabitType`=7,`flags_extra`=`flags_extra`|128 WHERE `entry`=31245;
