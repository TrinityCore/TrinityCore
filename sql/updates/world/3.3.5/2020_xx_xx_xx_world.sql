-- Deathbound Ward Aura
DELETE FROM `creature_template_addon` WHERE `entry` = 37007;

-- Deathbound Ward Guid
SET @DW_GUID_FIRST := 200987;
SET @DW_GUID_SECOND := 201043;
SET @DW_GUID_THIRD := 201108;
SET @DW_GUID_FOURTH := 201130;

-- Deathbound Ward Waypoints
SET @DW_WAYPOINT_FIRST := 3700700;
SET @DW_WAYPOINT_SECOND := 3700701;
SET @DW_WAYPOINT_THIRD := 3700702;
SET @DW_WAYPOINT_FOURTH := 3700703;

DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` IN(-@DW_GUID_FIRST, -@DW_GUID_SECOND, -@DW_GUID_THIRD, -@DW_GUID_FOURTH);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-@DW_GUID_FIRST, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 0, 75, 70733, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Deathbound Ward - On Respawn - Add Aura \'Stoneform\''),
(-@DW_GUID_FIRST, 0, 1, 0, 0, 0, 100, 0, 3000, 6000, 6000, 8000, 0, 11, 71021, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Deathbound Ward - In Combat - Cast \'Saber Lash\''),
(-@DW_GUID_FIRST, 0, 2, 0, 0, 0, 100, 0, 6000, 8000, 6000, 12000, 0, 11, 71022, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Deathbound Ward - In Combat - Cast \'Disrupting Shout\''),
(-@DW_GUID_FIRST, 0, 3, 0, 38, 0, 100, 0, 1, 1, 0, 0, 0, 53, 0, @DW_WAYPOINT_FIRST, 1, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Deathbound Ward - On Data Set 1 1 - Start Waypoint'),

(-@DW_GUID_SECOND, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 0, 75, 70733, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Deathbound Ward - On Respawn - Add Aura \'Stoneform\''),
(-@DW_GUID_SECOND, 0, 1, 0, 0, 0, 100, 0, 3000, 6000, 6000, 8000, 0, 11, 71021, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Deathbound Ward - In Combat - Cast \'Saber Lash\''),
(-@DW_GUID_SECOND, 0, 2, 0, 0, 0, 100, 0, 6000, 8000, 6000, 12000, 0, 11, 71022, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Deathbound Ward - In Combat - Cast \'Disrupting Shout\''),
(-@DW_GUID_SECOND, 0, 3, 0, 38, 0, 100, 0, 1, 1, 0, 0, 0, 53, 0, @DW_WAYPOINT_SECOND, 1, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Deathbound Ward - On Data Set 1 1 - Start Waypoint'),

(-@DW_GUID_THIRD, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 0, 75, 70733, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Deathbound Ward - On Respawn - Add Aura \'Stoneform\''),
(-@DW_GUID_THIRD, 0, 1, 0, 0, 0, 100, 0, 3000, 6000, 6000, 8000, 0, 11, 71021, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Deathbound Ward - In Combat - Cast \'Saber Lash\''),
(-@DW_GUID_THIRD, 0, 2, 0, 0, 0, 100, 0, 6000, 8000, 6000, 12000, 0, 11, 71022, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Deathbound Ward - In Combat - Cast \'Disrupting Shout\''),
(-@DW_GUID_THIRD, 0, 3, 0, 38, 0, 100, 0, 1, 1, 0, 0, 0, 53, 0, @DW_WAYPOINT_THIRD, 1, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Deathbound Ward - On Data Set 1 1 - Start Waypoint'),

(-@DW_GUID_FOURTH, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 0, 75, 70733, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Deathbound Ward - On Respawn - Add Aura \'Stoneform\''),
(-@DW_GUID_FOURTH, 0, 1, 0, 0, 0, 100, 0, 3000, 6000, 6000, 8000, 0, 11, 71021, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Deathbound Ward - In Combat - Cast \'Saber Lash\''),
(-@DW_GUID_FOURTH, 0, 2, 0, 0, 0, 100, 0, 6000, 8000, 6000, 12000, 0, 11, 71022, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Deathbound Ward - In Combat - Cast \'Disrupting Shout\''),
(-@DW_GUID_FOURTH, 0, 3, 0, 38, 0, 100, 0, 1, 1, 0, 0, 0, 53, 0, @DW_WAYPOINT_FOURTH, 1, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Deathbound Ward - On Data Set 1 1 - Start Waypoint');

DELETE FROM `waypoints` WHERE `entry` IN (@DW_WAYPOINT_FIRST, @DW_WAYPOINT_SECOND, @DW_WAYPOINT_THIRD, @DW_WAYPOINT_FOURTH);
INSERT INTO `waypoints`(`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(@DW_WAYPOINT_FIRST, 1, -194.583, 2159.04, 37.9852, NULL),
(@DW_WAYPOINT_FIRST, 2, -172.52, 2178.91, 37.9852, NULL),
(@DW_WAYPOINT_FIRST, 3, -173.356, 2244.59, 37.9851, NULL),
(@DW_WAYPOINT_FIRST, 4, -191.483, 2259.81, 37.9851, NULL),
(@DW_WAYPOINT_FIRST, 5, -233.296, 2241.13, 37.9851, NULL),
(@DW_WAYPOINT_FIRST, 6, -242.451, 2222.78, 42.5646, NULL),
(@DW_WAYPOINT_FIRST, 7, -242.6, 2201.63, 42.5646, NULL),
(@DW_WAYPOINT_FIRST, 8, -233.272, 2183.1, 37.9851, NULL),
(@DW_WAYPOINT_FIRST, 9, -194.583, 2159.04, 37.9852, NULL),
(@DW_WAYPOINT_SECOND, 1, -191.483, 2259.81, 37.9851, NULL),
(@DW_WAYPOINT_SECOND, 2, -233.296, 2241.13, 37.9851, NULL),
(@DW_WAYPOINT_SECOND, 3, -242.451, 2222.78, 42.5646, NULL),
(@DW_WAYPOINT_SECOND, 4, -242.6, 2201.63, 42.5646, NULL),
(@DW_WAYPOINT_SECOND, 5, -233.272, 2183.1, 37.9851, NULL),
(@DW_WAYPOINT_SECOND, 6, -194.583, 2159.04, 37.9852, NULL),
(@DW_WAYPOINT_SECOND, 7, -172.52, 2178.91, 37.9852, NULL),
(@DW_WAYPOINT_SECOND, 8, -173.356, 2244.59, 37.9851, NULL),
(@DW_WAYPOINT_SECOND, 9, -191.483, 2259.81, 37.9851, NULL),
(@DW_WAYPOINT_THIRD, 1, -276.016, 2211.87, 42.5645, NULL),
(@DW_WAYPOINT_THIRD, 2, -239.08, 2211.49, 42.5645, NULL),
(@DW_WAYPOINT_THIRD, 3, -213.092, 2211.63, 35.2335, NULL),
(@DW_WAYPOINT_THIRD, 4, -239.08, 2211.49, 42.5645, NULL),
(@DW_WAYPOINT_THIRD, 5, -350.122, 2211.61, 42.4406, NULL),
(@DW_WAYPOINT_THIRD, 6, -276.016, 2211.87, 42.5645, NULL),
(@DW_WAYPOINT_FOURTH, 1, -301.121, 2212.05, 42.0128, NULL),
(@DW_WAYPOINT_FOURTH, 2, -350.122, 2211.61, 42.4406, NULL),
(@DW_WAYPOINT_FOURTH, 3, -245.857, 2211.23, 42.5645, NULL),
(@DW_WAYPOINT_FOURTH, 4, -301.121, 2212.05, 42.0128, NULL);
