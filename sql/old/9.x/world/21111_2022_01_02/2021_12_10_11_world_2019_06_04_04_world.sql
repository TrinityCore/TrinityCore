UPDATE `event_scripts` SET `datalong`=27939, `datalong2`=300000, `x`=2839.433, `y`=7150.816, `z`=-0.4185546, `o`=4.246748 WHERE `id`=16889;

UPDATE `creature_template` SET `unit_flags`=33554432, `VehicleId`=311, `AIName`="SmartAI" WHERE `entry`=27939;
UPDATE `creature_template` SET `unit_flags`=768, `AIName`="SmartAI" WHERE `entry` IN (32576, 32577, 32578, 32579, 32580);
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|64 WHERE `entry` IN (32577, 32578, 32579, 32580);

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (27939, 32576, 32577, 32578, 32579, 32580);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Flight`) VALUES
(27939, 0, 1),
(32576, 1, 0),
(32577, 1, 0),
(32578, 1, 0),
(32579, 1, 0),
(32580, 1, 0);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=27939;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(27939, 46598, 1, 0);

DELETE FROM `smart_scripts` WHERE `entryorguid`=27939;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (32576, 3257600, 3257601, 32578, 3257800, 32577, 3257700, 32580, 3258000, 32579, 3257900);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(27939, 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "The Helmsman's Ship - On Reset - Set Active On"),
(27939, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 1, 27939, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "The Helmsman's Ship - On Reset - Start Waypoint"),
(27939, 0, 2, 3, 40, 0, 100, 0, 3, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 32576, 0, 0, 0, 0, 0, 0, "The Helmsman's Ship - On WP 3 Reached - Set Data 1 1 (Orabus the Helmsman)"),
(27939, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "The Helmsman's Ship - On WP 3 Reached - Set Active Off"),
(27939, 0, 4, 0, 38, 0, 100, 0, 1, 1, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "The Helmsman's Ship - On Data 1 1 Set - Despawn"),
(32576, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Orabus the Helmsman - On Respawn - Say Line 0"),
(32576, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 27939, 0, 0, 0, 0, 0, 0, "Orabus the Helmsman - On Death - Set Data 1 1 (The Helmsman's Ship)"),
(32576, 0, 2, 0, 38, 0, 100, 0, 1, 1, 0, 0, 80, 3257600, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Orabus the Helmsman - On Data 1 1 Set - Run Script"),
(32576, 0, 3, 0, 38, 0, 100, 0, 2, 2, 0, 0, 80, 3257601, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Orabus the Helmsman - On Data 2 2 Set - Run Script"),
(3257600, 9, 0, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 32578, 0, 0, 0, 0, 0, 0, "Orabus the Helmsman - On Script - Set Data 1 1 (Kvaldir Crewman)"),
(3257601, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Orabus the Helmsman - On Script - Say Line 1"),
(3257601, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 28, 46598, 0, 1, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "Orabus the Helmsman - On Script - Exit Vehicle"),
(3257601, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 19, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Orabus the Helmsman - On Script - Remove Immune To PC"),
(3257601, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Orabus the Helmsman - On Script - Set ReactState Aggressive"),
(3257601, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 1, 32578, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, "Orabus the Helmsman - On Script - Start Waypoint"),
(32578, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 80, 3257800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Kvaldir Crewman - On Data 1 1 Set - Run Script"),
(32578, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 32577, 0, 0, 0, 0, 0, 0, "Kvaldir Crewman - On Death - Set Data 1 1 (Kvaldir Crewman)"),
(3257800, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 32576, 0, 0, 0, 0, 0, 0, "Kvaldir Crewman - On Script - Say Line 2 (Orabus the Helmsman)"),
(3257800, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Kvaldir Crewman - On Script - Say Line 0"),
(3257800, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 28, 46598, 0, 1, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "Kvaldir Crewman - On Script - Exit Vehicle"),
(3257800, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 19, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Kvaldir Crewman - On Script - Remove Immune To PC"),
(3257800, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Kvaldir Crewman - On Script - Set ReactState Aggressive"),
(3257800, 9, 5, 0, 0, 0, 100, 0, 1500, 1500, 0, 0, 5, 15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Kvaldir Crewman - On Script - Emote 'Roar'"),
(3257800, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 1, 32578, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, "Kvaldir Crewman - On Script - Start Waypoint"),
(32577, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 80, 3257700, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Kvaldir Crewman - On Data 1 1 Set - Run Script"),
(32577, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 32580, 0, 0, 0, 0, 0, 0, "Kvaldir Crewman - On Death - Set Data 1 1 (Kvaldir Crewman)"),
(3257700, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 32576, 0, 0, 0, 0, 0, 0, "Kvaldir Crewman - On Script - Say Line 2 (Orabus the Helmsman)"),
(3257700, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Kvaldir Crewman - On Script - Say Line 0"),
(3257700, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 28, 46598, 0, 1, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "Kvaldir Crewman - On Script - Exit Vehicle"),
(3257700, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 19, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Kvaldir Crewman - On Script - Remove Immune To PC"),
(3257700, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Kvaldir Crewman - On Script - Set ReactState Aggressive"),
(3257700, 9, 5, 0, 0, 0, 100, 0, 1500, 1500, 0, 0, 5, 15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Kvaldir Crewman - On Script - Emote 'Roar'"),
(3257700, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 1, 32578, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, "Kvaldir Crewman - On Script - Start Waypoint"),
(32580, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 80, 3258000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Kvaldir Crewman - On Data 1 1 Set - Run Script"),
(32580, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 32579, 0, 0, 0, 0, 0, 0, "Kvaldir Crewman - On Death - Set Data 1 1 (Kvaldir Crewman)"),
(3258000, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 32576, 0, 0, 0, 0, 0, 0, "Kvaldir Crewman - On Script - Say Line 2 (Orabus the Helmsman)"),
(3258000, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Kvaldir Crewman - On Script - Say Line 0"),
(3258000, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 28, 46598, 0, 1, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "Kvaldir Crewman - On Script - Exit Vehicle"),
(3258000, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 19, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Kvaldir Crewman - On Script - Remove Immune To PC"),
(3258000, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Kvaldir Crewman - On Script - Set ReactState Aggressive"),
(3258000, 9, 5, 0, 0, 0, 100, 0, 1500, 1500, 0, 0, 5, 15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Kvaldir Crewman - On Script - Emote 'Roar'"),
(3258000, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 1, 32578, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, "Kvaldir Crewman - On Script - Start Waypoint"),
(32579, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 80, 3257900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Kvaldir Crewman - On Data 1 1 Set - Run Script"),
(32579, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 32576, 0, 0, 0, 0, 0, 0, "Kvaldir Crewman - On Death - Set Data 2 2 (Orabus the Helmsman)"),
(3257900, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 32576, 0, 0, 0, 0, 0, 0, "Kvaldir Crewman - On Script - Say Line 2 (Orabus the Helmsman)"),
(3257900, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Kvaldir Crewman - On Script - Say Line 0"),
(3257900, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 28, 46598, 0, 1, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "Kvaldir Crewman - On Script - Exit Vehicle"),
(3257900, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 19, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Kvaldir Crewman - On Script - Remove Immune To PC"),
(3257900, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Kvaldir Crewman - On Script - Set ReactState Aggressive"),
(3257900, 9, 5, 0, 0, 0, 100, 0, 1500, 1500, 0, 0, 5, 15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Kvaldir Crewman - On Script - Emote 'Roar'"),
(3257900, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 1, 32578, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, "Kvaldir Crewman - On Script - Start Waypoint");

DELETE FROM `creature_text` WHERE `CreatureID` IN (32577, 32578, 32579, 32580);
DELETE FROM `creature_text` WHERE `CreatureID`=32576 AND `GroupID`=2;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(32577, 0, 0, "Aye, captain!", 14, 0, 100, 0, 0, 0, 24843, 0, "Kvaldir Crewman"),
(32578, 0, 0, "Aye, captain!", 14, 0, 100, 0, 0, 0, 24843, 0, "Kvaldir Crewman"),
(32579, 0, 0, "Aye, captain!", 14, 0, 100, 0, 0, 0, 24843, 0, "Kvaldir Crewman"),
(32580, 0, 0, "Aye, captain!", 14, 0, 100, 0, 0, 0, 24843, 0, "Kvaldir Crewman"),
(32576, 2, 0, "A child has found a new toy! Crewman, take this infant's toy away!", 14, 0, 100, 0, 0, 0, 24840, 0, "Orabus the Helmsman"),
(32576, 2, 1, "Crewman, show this ant the might of the Kvaldir!", 14, 0, 100, 0, 0, 0, 24841, 0, "Orabus the Helmsman"),
(32576, 2, 2, "Crewman, tear this land walker apart!", 14, 0, 100, 0, 0, 0, 24842, 0, "Orabus the Helmsman");

DELETE FROM `waypoints` WHERE `entry` IN (27939, 32578);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(27939, 1, 2811.375, 7094.439, 0.181869, "The Helmsman's Ship"),
(27939, 2, 2812.334, 7051.673, 0.126313, "The Helmsman's Ship"),
(27939, 3, 2812.334, 7051.673, 0.126313, "The Helmsman's Ship"),
(32578, 1, 2792.823, 7047.637, -0.427784, "Kvaldir Crewman"),
(32578, 2, 2791.925, 7034.168, -0.552784, "Kvaldir Crewman");

DELETE FROM `vehicle_template_accessory` WHERE `entry`=27939;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(27939, 32580, 0, 0, "Kvaldir Crewman", 4, 300000),
(27939, 32579, 1, 0, "Kvaldir Crewman", 4, 300000),
(27939, 32577, 2, 0, "Kvaldir Crewman", 4, 300000),
(27939, 32578, 3, 0, "Kvaldir Crewman", 4, 300000),
(27939, 32576, 4, 0, "Orabus the Helmsman", 4, 300000);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=45703;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 45703, 0, 0, 29, 0, 27939, 200, 0, 1, 0, 0, "", "Spell 'Call of the Ancient Mariner' can only be used if NPC 'The Helmsman's Ship' is NOT within 200 yards");
