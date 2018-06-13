-- Blacksmith's Anvil
SET @GUID := 1508;
DELETE FROM `gameobject` WHERE `guid`=@GUID;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `ScriptName`, `VerifiedBuild`) VALUES
(@GUID,1684,1,1657,1657,1,1,9920.39,2308.9,1330.78,3.32399,-0,-0,-0.995844,0.0910739,300,255,1,"",0);

-- Mathiel
DELETE FROM `creature_text` WHERE `CreatureID`=6142;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(6142,0,0,"%s begins crafting...",16,0,100,0,0,0,2306,0,"Mathiel"),
(6142,1,0,"It is done.  I have your weapon, $n.",12,0,100,1,0,0,2307,0,"Mathiel");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6142;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6142 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=614200 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6142,0,0,0,20,0,100,0,1692,0,0,0,80,614200,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mathiel - On Quest 'Smith Mathiel' Finished - Run Script"),
(614200,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mathiel - On Script - Remove Npc Flag Questgiver"),
(614200,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.166394,"Mathiel - On Script - Set Orientation"),
(614200,9,2,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mathiel - On Script - Say Line 0"),
(614200,9,3,0,0,0,100,0,0,0,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mathiel - On Script - Set Emote State 233"),
(614200,9,4,0,0,0,100,0,20000,20000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mathiel - On Script - Set Emote State 0"),
(614200,9,5,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.71042,"Mathiel - On Script - Set Orientation"),
(614200,9,6,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mathiel - On Script - Say Line 2"),
(614200,9,7,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mathiel - On Script - Add Npc Flag Questgiver");
