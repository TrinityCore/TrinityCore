-- 
UPDATE `creature` SET `spawndist`=2 WHERE `guid` IN (108910, 108911, 108912, 108913);

UPDATE `creature_template` SET `AIName`="SmartAI", `unit_flags`=`unit_flags`|256 WHERE `entry`=24547;
UPDATE `creature` SET `position_x`=-49.74284, `position_y`=-3393.537, `position_z`=-8.100207, `orientation`=3.70 WHERE `guid`=117725;
DELETE FROM `creature_template_addon` WHERE `entry`=24547;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(24547, 0, 0, 3, 0, 0, "");

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (24742, 24547, 2454700, 2474200) AND `source_type` IN (0, 9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24742, 0, 0, 0, 0, 0, 100, 0, 0, 15000, 15000, 30000, 0, 11, 50188, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "\"Mad\" Jonah Sterling - IC - Cast Wildly Flailing"),
(24742, 0, 1, 2, 34, 0, 100, 0, 8, 1, 0, 0, 0, 97, 20, 20, 0, 0, 0, 0, 1, 0, 0, 0, -37.5049, -3421.69, -14.2464, 0, "\"Mad\" Jonah Sterling - On MovementInform PointID 1 - Jump to Hozzer"),
(24742, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 24547, 0, 0, 0, 0, 0, 0, "\"Mad\" Jonah Sterling - On WP 1 Reached - Set Data 1 1 Hozzer"),
(24742, 0, 3, 0, 2, 0, 100, 513, 0, 25, 0, 0, 0, 80, 2474200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "\"Mad\" Jonah Sterling - On 25% Hp - Run Script"),
(24547, 0, 0, 0, 0, 0, 100, 0, 5000, 10000, 15000, 20000, 0, 11, 34298, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Hozzer - In Combat - Cast Maul"),
(24547, 0, 1, 2, 38, 0, 100, 0, 1, 1, 0, 0, 0, 53, 1, 24547, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Hozzer - On Data 1 1 Set - Start Waypoint"),
(24547, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 91, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Hozzer - On Data 1 1 Set - Remove Standstate Sleep"),
(24547, 0, 3, 0, 40, 0, 100, 0, 3, 24547, 0, 0, 0, 80, 2454700, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Hozzer - On Waypoint 3 Reached - Run Script"),
(2454700, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Hozzer - On Script - Talk 0"),
(2454700, 9, 1, 0, 0, 0, 100, 0, 200, 200, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 24742, 0, 0, 0, 0, 0, 0, "Hozzer - On Script - Talk 1 (\"Mad\" Jonah Sterling)"),
(2454700, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 44458, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Hozzer - On Script - Cast Hozzer Feeds"),
(2454700, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, 24742, 0, 0, 0, 0, 0, 0, "Hozzer - On Script - Despawn \"Mad\" Jonah Sterling"),
(2454700, 9, 4, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 19, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Hozzer - On Script - Remove Flag IMMUNE_TO_PC"),
(2454700, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Hozzer - On Script - Set ReactState Aggressive"),
(2474200, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 117, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "\"Mad\" Jonah Sterling - On Script - Disable Evade"),
(2474200, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 102, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "\"Mad\" Jonah Sterling - On Script - Set HP Regen Off"),
(2474200, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "\"Mad\" Jonah Sterling - On Script - Stop Combat"),
(2474200, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 89, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "\"Mad\" Jonah Sterling - On Script - Disable Random Move"),
(2474200, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 69, 1, 0, 0, 0, 0, 0, 8, 0, 0, 0, -36.1289, -3425.64, 4.99862, 0, "\"Mad\" Jonah Sterling - On Script - Move To Pos"),
(2474200, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 18, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "\"Mad\" Jonah Sterling - On Script - Set Unit Flag IMMUNE_TO_PC"),
(2474200, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "\"Mad\" Jonah Sterling - On Script - Say Line 1");

DELETE FROM `waypoints` WHERE `entry` IN (24547, 24742);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(24547, 1, -31.82427, -3401.094, -14.61846, "Hozzer"),
(24547, 2, -30.87391, -3411.618, -15.25708, "Hozzer"),
(24547, 3, -35.8712, -3419.122, -14.47846, "Hozzer");
