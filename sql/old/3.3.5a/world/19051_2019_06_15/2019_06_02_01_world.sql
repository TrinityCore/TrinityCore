-- Add some missing gobs
DELETE FROM `gameobject` WHERE `guid` IN (8982,8984);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(8982, 184488, 530, 3483, 3539, 1, 1, 4245.323, 2171.133, 137.6776, 5.270896, 0, 0, -0.4848089, 0.8746201, 120, 255, 1, 15595), -- 184488 (Area: 3539 - Difficulty: 0)
(8984, 184998, 530, 3483, 3539, 1, 1, 4245.323, 2171.133, 137.6776, 5.270896, 0, 0, -0.4848089, 0.8746201, 120, 255, 1, 15595); -- 184998 (Area: 3539 - Difficulty: 0)
UPDATE `gameobject_template_addon` SET `flags`=`flags`|16  WHERE `entry` IN (184488);

-- Add missing emotes for quest "A Mission of Mercy"
UPDATE `quest_details` SET `Emote2`=1, `Emote3`=1 WHERE `ID`=10970;

-- Commander Ameer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=20448;
DELETE FROM `smart_scripts` WHERE `entryorguid`=20448 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2044800,2044801) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(20448,0,0,0,20,0,100,0,10970,0,0,0,80,2044800,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Ameer - On Quest 'A Mission of Mercy' Finished - Run Script"),
(20448,0,1,0,40,0,100,0,1,20448,0,0,80,2044801,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Ameer - On Waypoint 1 Reached - Run Script"),
(20448,0,2,3,40,0,100,0,2,20448,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.09956,"Commander Ameer - On Waypoint 2 Reached - Set Orientarion"),
(20448,0,3,0,61,0,100,0,0,0,0,0,81,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Ameer - On Waypoint 2 Reached - Set npc flag"),
(2044800,9,0,0,0,0,100,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Ameer - On Script - Remove npc flag"),
(2044800,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Ameer - On Script - Say Line 0"),
(2044800,9,2,0,0,0,100,0,5000,5000,0,0,53,0,20448,0,0,0,2,1,0,0,0,0,0,0,0,"Commander Ameer - On Script - Start Waypoint"),
(2044801,9,0,0,0,0,100,0,0,0,0,0,54,35000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Ameer - On Script - Pause Waypoint"),
(2044801,9,1,0,0,0,100,0,1000,1000,0,0,17,28,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Ameer - On Script - Set Emote State 'work SHEATHED'"),
(2044801,9,2,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Ameer - On Script - Say Line 1"),
(2044801,9,3,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Ameer - On Script - Set Emote State 'None'"),
(2044801,9,4,0,0,0,100,0,0,0,0,0,9,0,0,0,0,0,0,14,8982,184488,0,0,0,0,0,"Commander Ameer - On Script - Activate Gameobject 'Salvaged Ethereum Prison'"),
(2044801,9,5,0,0,0,100,0,0,0,0,0,12,22900,6,3000,0,0,0,8,0,0,0,4245.25,2171.18,138.03,5.66752,"Commander Ameer - On Script - Summon Creature 'Tortured Protectorate Vanguard'"),
(2044801,9,6,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,19,22900,0,0,0,0,0,0,"Commander Ameer - On Script - Say Line 0 (Tortured Protectorate Vanguard)"),
(2044801,9,7,0,0,0,100,0,15000,15000,0,0,51,0,0,0,0,0,0,19,22900,0,0,0,0,0,0,"Commander Ameer - On Script - Kill Creature 'Tortured Protectorate Vanguard'"),
(2044801,9,8,0,0,0,100,0,2000,2000,0,0,9,0,0,0,0,0,0,14,8982,184488,0,0,0,0,0,"Commander Ameer - On Script - Activate Gameobject 'Salvaged Ethereum Prison'"),
(2044801,9,9,0,0,0,100,0,3000,3000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Ameer - On Script - Say Line 2");

DELETE FROM `waypoints` WHERE `entry`=20448;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`) VALUES
(20448, 1, 4248.49, 2169, 137.678),
(20448, 2, 4252.65, 2166.07, 137.783);

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (20448, 22900);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(20448,0,0,"Stand back, $n. This may be an Ethereum trap.",12,0,100,1,0,0,20539,0,"Commander Ameer"),
(20448,1,0,"%s uses the Ethereum prison key on the salvaged Ethereum prison.",16,0,100,0,0,0,20540,0,"Commander Ameer"),
(20448,2,0,"Those fools! What have they done! What horrors do they hold? And for what purpose? I will need your help again, hero. Help us. Help your people.",12,0,100,1,0,0,20544,0,"Commander Ameer"),
(22900,0,0,"Commander... I am not long for this world... Taken to a holding pen... hundreds... thousands... beings from other worlds... Imprisoned... Imprisoned by Ethereum. Many of them our allies. Must... Must save the others... It... It's not too late...",12,0,100,1,0,0,20542,0,"Tortured Protectorate Vanguard");
