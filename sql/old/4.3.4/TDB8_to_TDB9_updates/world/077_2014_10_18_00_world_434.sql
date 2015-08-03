-- Fear No Evil quest updates
-- Set Health Random spell script
DELETE FROM `spell_script_names` WHERE `spell_id` = 53034;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(53034, 'spell_q28813_set_health_random');

-- More accurate times, added random emote script, corrected target_type field to face player.
DELETE FROM `smart_scripts` WHERE `entryorguid` = 5004700 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5004700, 9, 0, 0, 0, 0, 100, 1, 1000, 1000, 0, 0, 91, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Injured Stormwind Infantry - Actionlist - Stand up'),
(5004700, 9, 1, 0, 0, 0, 100, 0, 1200, 1200, 0, 0, 66, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Injured Stormwind Infantry - Actionlist - Face Player'),
(5004700, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 10, 4, 5, 22, 25, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Injured Stormwind Infantry - Actionlist - Random Emote'),
(5004700, 9, 3, 0, 0, 0, 100, 1, 200, 200, 0, 0, 1, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Injured Stormwind Infantry - Actionlist - Say line 0 (random)'),
(5004700, 9, 4, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 59, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Injured Stormwind Infantry - Actionlist - Set Run'),
(5004700, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 1, 50047, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Injured Stormwind Infantry - Actionlist - Start WP movement');

-- BroadcastTextIds
UPDATE `creature_text` SET `BroadcastTextId`=49916 WHERE `entry`=50047 AND `groupid`=0 AND `id`=0;
UPDATE `creature_text` SET `BroadcastTextId`=49918 WHERE `entry`=50047 AND `groupid`=0 AND `id`=1;
UPDATE `creature_text` SET `BroadcastTextId`=49919 WHERE `entry`=50047 AND `groupid`=0 AND `id`=2;
UPDATE `creature_text` SET `BroadcastTextId`=49917 WHERE `entry`=50047 AND `groupid`=0 AND `id`=3;
UPDATE `creature_text` SET `BroadcastTextId`=49922 WHERE `entry`=50047 AND `groupid`=0 AND `id`=4;
UPDATE `creature_text` SET `BroadcastTextId`=49915 WHERE `entry`=50047 AND `groupid`=0 AND `id`=5;
