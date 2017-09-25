/*
-- Stranglethorn Fever 
DELETE FROM `smart_scripts` WHERE `entryorguid`=1449 AND `source_type`=0 AND `id` BETWEEN 1 AND 6;
DELETE FROM `smart_scripts` WHERE `entryorguid`=144900 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1449, 0, 1, 2, 38, 0, 100, 0, 1, 1, 0, 0, 2, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Witch Doctor Unbagwa - On Data 1 1 Set - Restore Faction"),
(1449, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 82, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Witch Doctor Unbagwa - On Data 1 1 Set - Add Questgiver Flag"),
(1449, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Witch Doctor Unbagwa - On Data 1 1 Set - Set Phase 1"),
(1449, 0, 4, 5, 25, 1, 100, 0, 0, 0, 0, 0, 5, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Witch Doctor Unbagwa - On Reset - Play Emote 'Cheer' (Phase 1)"),
(1449, 0, 5, 6, 61, 1, 100, 0, 0, 0, 0, 0, 4, 2859, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Witch Doctor Unbagwa - On Reset - Play Sound (Phase 1)"),
(1449, 0, 6, 0, 61, 1, 100, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Witch Doctor Unbagwa - On Reset - Set Phase 0 (Phase 1)"),
(144900, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 83, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Witch Doctor Unbagwa - On Script - Remove Questgiver Flag"),
(144900, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 2, 495, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Witch Doctor Unbagwa - On Script - Change Faction"),
(144900, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 11, 12380, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Witch Doctor Unbagwa - On Script - Cast 'Shadow Channeling'"),
(144900, 9, 3, 0, 0, 0, 100, 0, 15000, 15000, 0, 0, 12, 1511, 3, 300000, 1, 0, 0, 8, 0, 0, 0, -13813.45, 8.700467, 27.33867, 6.063402, "Witch Doctor Unbagwa - On Script - Summon Creature 'Enraged Silverback Gorilla'"),
(144900, 9, 4, 0, 0, 0, 100, 0, 20000, 20000, 0, 0, 12, 1516, 3, 300000, 1, 0, 0, 8, 0, 0, 0, -13813.45, 8.700467, 27.33867, 6.063402, "Witch Doctor Unbagwa - On Script - Summon Creature 'Konda'"),
(144900, 9, 5, 0, 0, 0, 100, 0, 20000, 20000, 0, 0, 12, 1514, 3, 300000, 1, 0, 0, 8, 0, 0, 0, -13813.45, 8.700467, 27.33867, 6.063402, "Witch Doctor Unbagwa - On Script - Summon Creature 'Mokk the Savage'"),
(144900, 9, 6, 0, 0, 0, 100, 0, 60000, 60000, 0, 0, 82, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Witch Doctor Unbagwa - On Script - Add Questgiver Flag"),
(144900, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Witch Doctor Unbagwa - On Script - Restore Faction");

UPDATE `creature_template` SET `AIName`="SmartAI", `flags_extra`=64 WHERE `entry` IN (1511, 1516, 1514);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1511, 1516, 1514) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1511, 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 53, 1, 1511, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Enraged Silverback Gorilla - On Spawn - Start Waypoint"),
(1511, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Enraged Silverback Gorilla - On Spawn - Set Reactstate Aggressive"),
(1511, 0, 2, 3, 2, 0, 100, 1, 0, 30, 0, 0, 11, 8269, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Enraged Silverback Gorilla - Between 0-30% Health - Cast 'Frenzy' (No Repeat)"),
(1511, 0, 3, 0, 61, 0, 100, 0, 0, 30, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Enraged Silverback Gorilla - Between 0-30% Health - Say Line 0"),
(1511, 0, 4, 0, 7, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Enraged Silverback Gorilla - On evade - despawn"), 
(1516, 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 53, 1, 1516, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Konda - On Spawn - Start Waypoint"),
(1516, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Konda - On Spawn - Set Reactstate Aggressive"),
(1516, 0, 2, 3, 2, 0, 100, 1, 0, 30, 0, 0, 11, 8269, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Konda - Between 0-30% Health - Cast 'Frenzy' (No Repeat)"),
(1516, 0, 3, 0, 61, 0, 100, 0, 0, 30, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Konda - Between 0-30% Health - Say Line 0"),
(1516, 0, 4, 0, 7, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Konda - On evade - despawn"), 
(1514, 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 53, 1, 1514, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Mokk the Savage - On Spawn - Start Waypoint"),
(1514, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Mokk the Savage - On Spawn - Set Reactstate Aggressive"),
(1514, 0, 2, 3, 2, 0, 100, 1, 0, 30, 0, 0, 11, 8269, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Mokk the Savage - Between 0-30% Health - Cast 'Frenzy' (No Repeat)"),
(1514, 0, 3, 0, 61, 0, 100, 0, 0, 30, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Mokk the Savage - Between 0-30% Health - Say Line 0"),
(1514, 0, 4, 0, 6, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 1449, 0, 0, 0, 0, 0, 0, "Mokk the Savage - On Death - Set Data 1 1 (Witch Doctor Unbagwa)"),
(1514, 0, 5, 0, 7, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Mokk the Savage - On evade - despawn");

DELETE FROM `creature_text` WHERE `CreatureID` IN (1511, 1516, 1514);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1511, 0, 0, "%s goes into a frenzy!", 16, 0, 100, 0, 0, 0, 1191, 0, "Enraged Silverback Gorilla"),
(1516, 0, 0, "%s goes into a frenzy!", 16, 0, 100, 0, 0, 0, 1191, 0, "Konda"),
(1514, 0, 0, "%s goes into a frenzy!", 16, 0, 100, 0, 0, 0, 1191, 0, "Mokk the Savage");

DELETE FROM `waypoints` WHERE `entry` IN (1511, 1516, 1514);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(1511, 1, -13789.04, 3.232422, 34.39908, "Enraged Silverback Gorilla"),
(1511, 2, -13777.5, -2.928819, 39.94799, "Enraged Silverback Gorilla"),
(1511, 3, -13771.6, -6.586046, 42.69799, "Enraged Silverback Gorilla"),
(1511, 4, -13763.38, -11.97613, 44.95544, "Enraged Silverback Gorilla"),
(1511, 5, -13743.7, -23.97, 45.14, "Enraged Silverback Gorilla"),
(1516, 1, -13789.04, 3.232422, 34.39908, "Konda"),
(1516, 2, -13777.5, -2.928819, 39.94799, "Konda"),
(1516, 3, -13771.6, -6.586046, 42.69799, "Konda"),
(1516, 4, -13763.38, -11.97613, 44.95544, "Konda"),
(1516, 5, -13743.7, -23.97, 45.14, "Konda"),
(1514, 1, -13789.04, 3.232422, 34.39908, "Mokk the Savage"),
(1514, 2, -13777.5, -2.928819, 39.94799, "Mokk the Savage"),
(1514, 3, -13771.6, -6.586046, 42.69799, "Mokk the Savage"),
(1514, 4, -13763.38, -11.97613, 44.95544, "Mokk the Savage"),
(1514, 5, -13743.7, -23.97, 45.14, "Mokk the Savage");

UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=1 WHERE `ID`=349;
*/
