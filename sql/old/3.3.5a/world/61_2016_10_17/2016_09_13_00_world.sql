--
SET @ENTRY := 27924;
UPDATE `creature_template` SET `AIName`="SmartAI", `InhabitType`=4, `speed_run`=5 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY, 0, 0, 1, 54, 0, 100, 512, 0, 0, 0, 0, 53, 1, 27924, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dragonflayer Harpoon - On Summoned - Start Waypoint"),
(@ENTRY, 0, 1, 2, 61, 0, 100, 512, 0, 0, 0, 0, 54, 2000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dragonflayer Harpoon - On Summoned - Pause Waypoint for 2 seconds"),
(@ENTRY, 0, 2, 0, 61, 0, 100, 512, 0, 0, 0, 0, 11, 50011, 0, 0, 0, 0, 0, 1,0,0,0,0,0,0,0,"Dragonflayer Harpoon - On Summoned - Cast 'Dragonflayer Harpoon Sounds' on self"),
(@ENTRY, 0, 3, 4, 40, 0, 100, 512, 5, 27924, 0, 0, 15, 11436, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "Dragonflayer Harpoon - On Waypoint 5 Reached - Quest Credit 'Let's Go Surfing Now'"),
(@ENTRY, 0, 4, 0, 61, 0, 100, 512, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dragonflayer Harpoon - On Waypoint 5 Reached - Despawn");

DELETE FROM `waypoints` WHERE `entry`=27924;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(@ENTRY, 1, 803.085, -5333.39, 191.903, "Dragonflayer Harpoon"),
(@ENTRY, 2, 761.183, -5268.77, 152.492, "Dragonflayer Harpoon"),
(@ENTRY, 3, 695.561, -5155.04, 81.2906, "Dragonflayer Harpoon"),
(@ENTRY, 4, 647.533, -5073.72, 29.9669, "Dragonflayer Harpoon"),
(@ENTRY, 5, 621.608, -5027.49, 2.03123, "Dragonflayer Harpoon");

DELETE FROM `creature_template_addon` WHERE `entry`=27924;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@ENTRY, 0, 0, 0x1000000|0x2000000, 0x1, 0, "");
UPDATE `creature` SET `MovementType`=0, `spawndist`=0 WHERE `guid`=107391;

DELETE FROM `spell_target_position` WHERE `ID`=50007;
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `VerifiedBuild`) VALUES
(50007, 0, 571, 803.878, -5338.85, 193.281, 2.0246, 12340);
