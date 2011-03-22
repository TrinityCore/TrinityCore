-- Necro Overlord Mezhen SAI
SET @GUID   := 95036; -- 1 Required for ELM General Purpose Bunny
SET @ENTRY   := 24018; -- NPC entry
SET @CHANNEL := 43151; -- Necrolord: Purple Beam
SET @TARGET  := 24021; -- ELM General Purpose Bunny (scale x0.01)
SET @SPELL1  := 32862; -- Drain Soul
SET @SPELL2  := 43559; -- Raise Dead
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,11,@CHANNEL,2,0,0,0,0,11,@TARGET,30,0,0,0,0,0, 'Necro Overlord Mezhen - On spawn & reset - Channel Necrolord: Purple Beam');

-- Fix Spell condition for Spell 43151 to only target ELM General Purpose Bunny (scale x0.01)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=43151;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,43151,0,18,1,24021,0,0,'','Spell 43151 targets only ELM General Purpose Bunny (scale x0.01)');
-- Add missing ELM General Purpose Bunny (scale x0.01)
DELETE FROM `creature` WHERE `guid`=@GUID; 
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`) VALUES
(@GUID,24021,571,1,1,0,0,2597.148,-3735.499,261.9468,0.2094395,120,0,0,1,0,0,0);
-- ELM General Purpose Bunny (scale x0.01) fix InhabitType
UPDATE `creature_template` SET `InhabitType`=7 WHERE entry=24021;
