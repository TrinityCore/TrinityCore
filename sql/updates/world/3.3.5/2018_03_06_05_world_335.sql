-- Quest "A Fine Mess"
-- Pooling for Kernobee
SET @GUID := 64977;
SET @POOL := 385;
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID+0 AND @GUID+6;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@GUID+0,7850,90,0,0,1,1,0,0,-637.053,101.836,-194.48,4.76023,7200,0,0,896,0,0,0,0,0,"",0),
(@GUID+1,7850,90,0,0,1,1,0,0,-577.696,28.5626,-197.735,4.76023,7200,0,0,896,0,0,0,0,0,"",0),
(@GUID+2,7850,90,0,0,1,1,0,0,-618.832,153.15,-199.654,6.25451,7200,0,0,896,0,0,0,0,0,"",0),
(@GUID+3,7850,90,0,0,1,1,0,0,-600.079,15.9729,-179.679,5.47311,7200,0,0,896,0,0,0,0,0,"",0),
(@GUID+4,7850,90,0,0,1,1,0,0,-540.499,21.528,-179.737,1.53634,7200,0,0,896,0,0,0,0,0,"",0),
(@GUID+5,7850,90,0,0,1,1,0,0,-533.081,34.7292,-199.0739,1.89563,7200,0,0,896,0,0,0,0,0,"",0),
(@GUID+6,7850,90,0,0,1,1,0,0,-621.389,51.785,-199.647,5.47311,7200,0,0,896,0,0,0,0,0,"",0);

DELETE FROM `pool_template` WHERE `entry`=@POOL;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(@POOL,1,"Kernobee");

DELETE FROM `pool_creature` WHERE `pool_entry`=@POOL;
INSERT INTO `pool_creature` (`guid`, `pool_entry`, `chance`, `description`) VALUES
(@GUID+0,@POOL,0,"Kernobee (7850) - Spawn 1"),
(@GUID+1,@POOL,0,"Kernobee (7850) - Spawn 2"),
(@GUID+2,@POOL,0,"Kernobee (7850) - Spawn 3"),
(@GUID+3,@POOL,0,"Kernobee (7850) - Spawn 4"),
(@GUID+4,@POOL,0,"Kernobee (7850) - Spawn 5"),
(@GUID+5,@POOL,0,"Kernobee (7850) - Spawn 6"),
(@GUID+6,@POOL,0,"Kernobee (7850) - Spawn 7"),
(30135,@POOL,0,"Kernobee (7850) - Spawn 8");

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (7850,7897);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(7850,0,0,"I see the exit! Hurry, hurry!",12,0,100,5,0,0,3948,0,"Kernobee"),
(7850,1,0,"%s cheers!",16,0,100,4,0,0,3928,0,"Kernobee"),
(7850,2,0,"Thank you for rescuing me! Word of your deed will not go unnoticed.",12,0,100,0,0,0,3929,0,"Kernobee"),
(7850,3,0,"%s waves goodbye to everyone.",16,0,100,3,0,0,3930,0,"Kernobee"),
(7850,4,0,"Uh oh....",12,0,100,0,0,0,3953,0,"Kernobee"),
(7850,5,0,"Get me out of here!",12,0,100,5,0,0,3881,0,"Kernobee"),
(7897,0,0,"%s activates!",14,0,100,0,0,0,3926,0,"Alarm-a-bomb 2600"),
(7897,1,0,"Self-destruct sequence activated.",14,0,100,0,0,0,3927,0,"Alarm-a-bomb 2600"),
(7897,2,0,"Anti-escape countermeasures activated. Self-destruct in t-minus 20 seconds....",14,0,100,0,0,0,3949,0,"Alarm-a-bomb 2600"),
(7897,3,0,"Alarm-a-bomb unit 2600 has failed. Self-destruct override [ACTIVE]. Cooldown [ACTIVE].",14,0,100,0,0,0,3950,0,"Alarm-a-bomb 2600");

-- Kernobee
DELETE FROM `creature_addon` WHERE `guid`=30135;

UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName`="" WHERE `entry`=7850;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7850 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=785000 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7850,0,0,1,19,0,100,0,2904,0,0,0,29,2,180,0,0,0,0,7,0,0,0,0,0,0,0,"Kernobee - On Quest 'A Fine Mess' Taken - Start Follow Player"),
(7850,0,1,2,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,16,0,0,0,0,0,0,0,"Kernobee - On Quest 'A Fine Mess' Taken - Store Targetlist"),
(7850,0,2,3,61,0,100,0,0,0,0,0,91,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kernobee - On Quest 'A Fine Mess' Taken - Remove Flag Standstate 'Dead'"),
(7850,0,3,4,61,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kernobee - On Quest 'A Fine Mess' Taken - Remove Npc Flag Questgiver"),
(7850,0,4,5,61,0,100,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kernobee - On Quest 'A Fine Mess' Taken - Remove Unit Flag 'Immune To NPCs' & 'Immune To Players'"),
(7850,0,5,6,61,0,100,0,0,0,0,0,2,250,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kernobee - On Quest 'A Fine Mess' Taken - Set Faction 250"),
(7850,0,6,7,61,0,100,0,0,0,0,0,1,5,0,0,0,0,0,12,1,0,0,0,0,0,0,"Kernobee - On Quest 'A Fine Mess' Taken - Say Line 5"),
(7850,0,7,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,30134,7897,0,0,0,0,0,"Kernobee - On Quest 'A Fine Mess' Taken - Set Data to Alarm-a-bomb 2600"),
(7850,0,8,0,6,0,100,0,0,0,0,0,6,2904,0,0,0,0,0,12,1,0,0,0,0,0,0,"Kernobee - On Death - Fail Quest 'A Fine Mess'"),
(7850,0,9,0,11,0,100,0,0,0,0,0,90,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kernobee - On Respawn - Add Flag Standstate 'Dead'"),
(7850,0,10,11,38,0,100,1,1,1,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Kernobee - On Data Set - Say Line 0"),
(7850,0,11,12,61,0,100,0,0,0,0,0,29,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kernobee - On Data Set - Stop Follow"),
(7850,0,12,13,61,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-337.215,-0.165544,-152.847,0,"Kernobee - On Data Set - Move to Position"),
(7850,0,13,0,61,0,100,0,0,0,0,0,80,785000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kernobee - On Data Set - Run Script"),
(785000,9,0,0,0,0,100,0,11000,11000,0,0,15,2904,0,0,0,0,0,12,1,0,0,0,0,0,0,"Kernobee - On Script - Quest Credit 'A Fine Mess'"),
(785000,9,1,0,0,0,100,0,0,0,0,0,45,3,3,0,0,0,0,19,7897,0,0,0,0,0,0,"Kernobee - On Script - Set Data to Alarm-a-bomb 2600"),
(785000,9,2,0,0,0,100,0,500,500,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,"Kernobee - On Script - Say Line 1"),
(785000,9,3,0,0,0,100,0,4000,4000,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Kernobee - On Script - Set Orientation"),
(785000,9,4,0,0,0,100,0,1000,1000,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,"Kernobee - On Script - Say Line 2"),
(785000,9,5,0,0,0,100,0,5000,5000,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0,"Kernobee - On Script - Say Line 3"),
(785000,9,6,0,0,0,100,0,3000,3000,0,0,69,0,0,0,0,0,0,8,0,0,0,-297.319,-7.321,-152.849,0,"Kernobee - On Script - Move to Position"),
(785000,9,7,0,0,0,100,0,2000,2000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kernobee - On Script - Despawn");

-- Alarm-a-bomb 2600
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7897;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7897 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (789700,789701) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7897,0,0,0,38,0,100,0,1,1,0,0,80,789700,2,0,0,0,0,1,0,0,0,0,0,0,0,"Alarm-a-bomb 2600 - On Data Set - Run Script"),
(7897,0,1,0,38,0,100,1,1,1,0,0,29,2,270,0,0,0,0,19,7850,200,0,0,0,0,0,"Alarm-a-bomb 2600 - On Data Set - Start Follow Kernobee"),
(7897,0,2,0,38,1,100,1,2,2,0,0,45,1,1,0,0,0,0,19,7850,0,0,0,0,0,0,"Alarm-a-bomb 2600 - On Data Set - Set Data to Kernobee (Phase 1)"),
(7897,0,3,0,38,1,100,1,3,3,0,0,80,789701,2,0,0,0,0,1,0,0,0,0,0,0,0,"Alarm-a-bomb 2600 - On Data Set - Run Script (Phase 1)"),
(789700,9,0,0,0,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alarm-a-bomb 2600 - On Script - Set Event Phase 1"),
(789700,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alarm-a-bomb 2600 - On Script - Say Line 0"),
(789700,9,2,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alarm-a-bomb 2600 - On Script - Say Line 1"),
(789700,9,3,0,0,0,100,0,276000,276000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alarm-a-bomb 2600 - On Script - Say Line 2"),
(789700,9,4,0,0,0,100,0,6000,6000,0,0,1,4,0,0,0,0,0,19,7850,0,0,0,0,0,0,"Alarm-a-bomb 2600 - On Script - Say Line 4 (Kernobee)"),
(789700,9,5,0,0,0,100,0,14000,14000,0,0,11,9874,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alarm-a-bomb 2600 - On Script - Cast 'Self Destruct'"),
(789700,9,6,0,0,0,100,0,500,500,0,0,51,0,0,0,0,0,0,19,7850,0,0,0,0,0,0,"Alarm-a-bomb 2600 - On Script - Kill Kernobee"),
(789700,9,7,0,0,0,100,0,0,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alarm-a-bomb 2600 - On Script - Kill Self"),
(789701,9,0,0,0,0,100,0,0,0,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alarm-a-bomb 2600 - On Script - Set Rooted On"),
(789701,9,1,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alarm-a-bomb 2600 - On Script - Say Line 3"),
(789701,9,2,0,0,0,100,0,12000,12000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alarm-a-bomb 2600 - On Script - Despawn");

-- Areatrigger
DELETE FROM `areatrigger_scripts` WHERE `entry`=1105;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(1105,"SmartTrigger");

DELETE FROM `smart_scripts` WHERE `entryorguid`=1105 AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1105,2,0,0,46,0,100,0,1105,0,0,0,45,2,2,0,0,0,0,10,30134,7897,0,0,0,0,0,"Areatrigger - On Trigger - Set Data to Alarm-a-bomb 2600");
