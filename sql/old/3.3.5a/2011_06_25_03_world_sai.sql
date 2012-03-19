-- Ice Heart Jormungar Feeder SAI
SET @ENTRY   := 26358; -- NPC entry
SET @SPELL1  := 47447; -- Corrosive Spit
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,11000,20000,26000,11,@SPELL1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Ice Heart Jormungar Feeder - Combat - Cast Corrosive Spit');

-- SAI for Fulgorge
SET @ENTRY := 18678;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
UPDATE `creature` SET `spawndist`=20,`MovementType`=1 WHERE `id`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,11,34038,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fulgorge - OOC - Cast Submerge Visual'),
(@ENTRY,0,1,0,61,0,100,1,0,0,0,0,18,33554434,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fulgorge - OOC - Set Unselectable and Unattackable Flags'),
(@ENTRY,0,2,3,0,0,100,1,0,0,0,0,28,34038,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fulgorge - On Aggro - Remove Submerge Visual'),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,19,33554434,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fulgorge - On Aggro - Remove Unselectable and Unattackable Flags'),
(@ENTRY,0,4,5,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fulgorge - On Aggro - Prevent Combat Movement'),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fulgorge - On Aggro - Set Phase 1'),
(@ENTRY,0,6,7,0,1,100,0,1000,1000,2100,4500,11,31747,1,0,0,0,0,2,0,0,0,0,0,0,0,'Fulgorge - Combat - Cast Poison (Phase 1)'),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fulgorge - Combat - Prevent Combat Movement (Phase 1)'),
(@ENTRY,0,8,0,0,1,100,0,20400,20400,45000,50000,11,32738,1,0,0,0,0,2,0,0,0,0,0,0,0,'Fulgorge - Combat - Cast Bore (Phase 1)'),
(@ENTRY,0,9,10,9,1,100,0,20,60,0,0,11,34038,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fulgorge - At 20 - 60 Yards Range - Cast Submerge Visual (Phase 1)'),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fulgorge - At 20 - 60 Yards Range - Set Phase 2 (Phase 1)'),
(@ENTRY,0,11,12,9,2,100,0,0,8,0,0,28,34038,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fulgorge - At 0 - 8 Yards - Remove Submerge Visual (Phase 2)'),
(@ENTRY,0,12,13,61,2,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fulgorge - Combat - Prevent Combat Movement (Phase 2)'),
(@ENTRY,0,13,14,61,2,100,0,0,8,0,0,19,33554434,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fulgorge - At 0 - 8 Yards - Remove Unselectable and Unattackable Flags (Phase 2)'),
(@ENTRY,0,14,0,61,2,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fulgorge - At 20 - 60 Yards Range - Set Phase 1 (Phase 2)');

-- Deranged Helboar SAI
SET @ENTRY  := 16863; -- NPC entry
SET @SPELL1 := 33908; -- Burning Spikes
SET @SPELL2 := 8599;  -- Enrage
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,@SPELL1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Deranged Helboar - On spawn - Cast Burning Spikes on self'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,@SPELL2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Deranged Helboar - On Health level - Cast Enrage When Below 30% HP');

-- Stonescythe Alpha SAI
SET @ENTRY  := 16929; -- NPC entry
SET @SPELL1 := 33911; -- Tear Armor
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,50,0,3000,3000,8000,8000,11,@SPELL1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Stonescythe Alpha - Combat - Cast Tear Armor');

