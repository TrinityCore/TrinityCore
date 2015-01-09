-- Priest of Rhunok SAI
SET @ENTRY   := 28417; -- NPC entry
SET @CHANNEL := 51616; -- Priest of Rhunok: Channel to Prophet
SET @TARGET  := 28442; -- Prophet of Rhunok
SET @SPELL1  := 9734;  -- Holy Smite
SET @SPELL2  := 54518; -- Penance
SET @SPELL3  := 37274; -- Power Infusion
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,11,@CHANNEL,0,0,0,0,0,11,@TARGET,90,0,0,0,0,0, 'Priest of Rhunok - On spawn & reset - Priest of Rhunok: Channel to Prophet'),
(@ENTRY,0,1,0,0,0,100,0,2000,5000,10000,18000,11,@SPELL1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Priest of Rhunok - Combat - Cast Holy Smite on victim'),
(@ENTRY,0,2,0,0,0,100,0,17000,26000,17000,20000,11,@SPELL2,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Priest of Rhunok - Combat - Cast Penance on victim'),
(@ENTRY,0,3,0,0,0,100,0,12000,16000,60000,60000,11,@SPELL3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Priest of Rhunok - Combat - Cast Power Infusion on self');
-- Fix Spell condition for Spell 51616 to only target Prophet of Rhunok
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=51616;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,51616,0,18,1,28442,0,0,'','Spell 51616 targets only Prophet of Rhunok');
