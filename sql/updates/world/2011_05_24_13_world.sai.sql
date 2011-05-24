-- Iron Rune-Weaver SAI
SET @ENTRY   := 26820; -- NPC entry
SET @CHANNEL := 47463; -- Rune-Weaver Channel
SET @TARGET  := 26785; -- Directional Rune
SET @SPELL1  := 52713; -- Rune Weaving
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,11,@CHANNEL,2,0,0,0,0,11,@TARGET,30,0,0,0,0,0, 'Iron Rune-Weaver - On spawn & reset - Channel Rune-Weaver Channel on Directional Rune'),
(@ENTRY,0,1,0,0,0,100,0,4000,7000,10000,16000,11,@SPELL1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Iron Rune-Weaver - Combat - Cast Rune Weaving on victim');
-- Fix Spell condition for Spell 47463 to only target Directional Rune
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=47463;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,47463,0,18,1,26785,0,0,'','Spell 47463 targets only Directional Rune');
