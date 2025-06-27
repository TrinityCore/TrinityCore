-- 
SET @ENTRY := 37230;
SET @CGUID := 45827;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, @ENTRY, 631, 3, 1, -368.000, 2316.687, 234.047, 2.792558, 7200, 0, 0),
(@CGUID+1, @ENTRY, 631, 3, 1, -511.493, 2318.217, 234.045, 0.483487, 7200, 0, 0),
(@CGUID+2, @ENTRY, 631, 3, 1, -516.336, 2108.577, 234.049, 5.733871, 7200, 0, 0),
(@CGUID+3, @ENTRY, 631, 3, 1, -353.894, 2111.659, 234.043, 3.711472, 7200, 0, 0);

UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (@ENTRY, 38444);
DELETE FROM `creature_template_addon` WHERE `entry` IN (@ENTRY, 38444);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(@ENTRY, 0, 0x3000000, 0x1, ''),
(38444, 0, 0x3000000, 0x1, '');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,30,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spire Frostwyrm - on Reset - Set invisible"),
(@ENTRY,0,1,2,10,0,100,31,0,100,1000,1000,47,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spire Frostwyrm - OOC_LOS - SET visible"),
(@ENTRY,0,2,0,61,0,100,31,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Spire Frostwyrm - OOC_LOS - Start Attack"),
(@ENTRY,0,3,0,4,0,100,30,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spire Frostwyrm - On aggro - Say text"),
(@ENTRY,0,4,0,33,0,100,31,100,30000,0,0,91,2,3,0,0,0,0,1,0,0,0,0,0,0,0,"Spire Frostwyrm - On target damaged - Remove Flag Hover"),
(@ENTRY,0,5,0,0,0,100,30,10000,13000,13000,16000,11,70362,0,0,0,0,0,5,0,0,0,0,0,0,0,"Spire Frostwyrm - IC - Cast Blizzard"), 
(@ENTRY,0,6,0,0,0,100,30,8000,10000,3000,6000,11,70361,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spire Frostwyrm - IC - Cast Cleave"),
(@ENTRY,0,7,0,0,0,100,30,13000,15000,6000,9000,11,70116,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spire Frostwyrm - IC - Cast Frost Breath");

DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `TextRange`, `comment`) VALUES
(@ENTRY, 0, 0, 'A screeching cry pierces the air above!', 41, 0, 100, 0, 0, 0, 37161, 1, 'Spire Frostwyrm to Player');
