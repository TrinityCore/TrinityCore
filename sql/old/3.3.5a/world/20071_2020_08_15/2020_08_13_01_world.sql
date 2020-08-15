-- Kel'Thuzad SAI (Source: Sniffs & https://www.youtube.com/watch?v=VxdTm9lL0C8 & https://www.youtube.com/watch?v=p8aHRRpF8ZM)
SET @ID := 25465;
UPDATE `creature_template` SET `unit_flags` = `unit_flags`|768 WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID*100+0 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,1,0,100,0,25000,25000,25000,25000,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kel'Thuzad - Out of Combat - Run Script"),
(@ID,0,1,0,10,0,100,0,0,10,10000,10000,1,11,50319,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Kel'Thuzad - Within 0-10 Range Out of Combat LoS - Cast 'Soul Flay'"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kel'Thuzad - On Script - Say Line 0"),
(@ID*100+0,9,1,0,0,0,100,0,5000,5000,0,0,0,11,50312,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kel'Thuzad - On Script - Cast 'Unholy Frenzy'");

-- First emote shown in https://www.youtube.com/watch?v=RQWNsM2pxtI
DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"%s cackles maniacally.
",16,0,100,0,0,8818,13022,0,"Kel'Thuzad"),
(@ID,1,0,"You only delay the inevitable! The dread citadel rises in the east as the armies of the dead march from the heart of Icecrown!",14,0,100,0,0,0,26163,0,"Kel'Thuzad");

-- Stitched Warsong Horror & Undying Aggressor respawns fastly, corpse despawns in 3 sec, one spawn is missing
UPDATE `creature` SET `spawntimesecs` = 60 WHERE `id` IN (25332,25333);
DELETE FROM `creature` WHERE `guid` = 86717 AND `id` = 25333;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`wander_distance`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`,`VerifiedBuild`) VALUES
(86717,25333,571,0,0,1,1,0,0,2449.73095,6550.7241,41.1757,4.694935,60,0,0,0,0,0,0,0,0,11159);

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` IN (25332,25333);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25332,25333) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25332,0,0,0,11,0,100,0,0,0,0,0,0,116,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stitched Warsong Horror - On Respawn - Set Corpse Delay"),
(25333,0,0,0,11,0,100,0,0,0,0,0,0,116,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Undying Aggressor - On Respawn - Set Corpse Delay");
