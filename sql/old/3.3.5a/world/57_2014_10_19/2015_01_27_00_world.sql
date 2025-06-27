UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(18230,18237);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(18230,18237) AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(18230, 0, 0, 0, 1, 0, 100, 0, 0, 0, 500, 500, 29, 0, 0, 0, 0, 0, 0, 19, 18237, 0, 0, 0, 0, 0, 0, 'Trayanise - OOC - Follow Tiny Arcane Construct'),
(18230, 0, 1, 0, 1, 0, 100, 0, 0, 60000, 180000, 300000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Trayanise - OOC - Say Line 0'),
(18237, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 53, 1, 18237, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tiny Arcane Construct - On Spawn - Start WP');

UPDATE `creature_template` SET `speed_run`=1.142857 WHERE  `entry`=18230;
UPDATE `creature_template` SET `speed_run`=2.142857 WHERE  `entry`=18237;

DELETE FROM `creature_addon` WHERE `guid` IN(65501,65505);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(65501, 0, 0, 0x0, 0x1, 0, NULL),
(65505, 0, 0, 0x0, 0x1, 0, NULL);

DELETE FROM `creature_template_addon` WHERE `entry` IN(18230,18237);

DELETE FROM `creature` WHERE `guid` IN(65501,65505);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(65501, 18230, 530, 1, 1,  9891.047, -7180.686, 31.02935, 2.363085, 120, 0, 0), -- 18230 (Area: 3487)
(65505, 18237, 530, 1, 1,  9886.445, -7179.344, 31.03508, 2.353462, 120, 0, 0); -- 18237 (Area: 3487)


DELETE FROM `waypoint_data` WHERE `id` IN(655010,655050);

DELETE FROM `waypoints` WHERE `entry` IN(18230,18237);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(18237, 1, 9854.372, -7131.53, 30.8774,  'Tiny Arcane Construct'),
(18237, 2, 9848.939, -7149.687, 30.88104,  'Tiny Arcane Construct'),
(18237, 3, 9853.528, -7164.35, 30.94116,  'Tiny Arcane Construct'),
(18237, 4, 9873.93, -7174.143, 31.04511,  'Tiny Arcane Construct'),
(18237, 5, 9890.317, -7171.364, 32.04652,  'Tiny Arcane Construct'),
(18237, 6, 9893.691, -7182.642, 31.02659,  'Tiny Arcane Construct'),
(18237, 7, 9906.294, -7211.048, 30.9103,  'Tiny Arcane Construct'),
(18237, 8, 9914.21, -7215.013, 30.81886,  'Tiny Arcane Construct'),
(18237, 9, 9930.763, -7214.394, 30.86104,  'Tiny Arcane Construct'),
(18237, 10, 9954.362, -7211.773, 30.87779,  'Tiny Arcane Construct'),
(18237, 11, 9953.68, -7204.061, 30.87768,  'Tiny Arcane Construct'),
(18237, 12, 9941.922, -7198.434, 30.87755,  'Tiny Arcane Construct'),
(18237, 13, 9915.126, -7188.168, 30.9569,  'Tiny Arcane Construct'),
(18237, 14, 9897.4, -7190.357, 31.03786,  'Tiny Arcane Construct'),
(18237, 15, 9885.156, -7178.048, 31.03413,  'Tiny Arcane Construct'),
(18237, 16, 9874.851, -7163.025, 30.99726,  'Tiny Arcane Construct'),
(18237, 17, 9867.523, -7139.578, 30.87733,  'Tiny Arcane Construct');

DELETE FROM `creature_text` WHERE `entry`=18230;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(18230, 0, 0, 'The magister''s going to kill me...', 12, 1, 100, 0, 0, 0, 15011, 'Trayanise'),
(18230, 0, 1, 'No, no, no! Come back here!', 12, 1, 100, 0, 0, 0, 15010, 'Trayanise'),
(18230, 0, 2, 'Argh. They told me those crystals would work properly!', 12, 1, 100, 0, 0, 0, 15013, 'Trayanise'),
(18230, 0, 3, 'When I catch you, I''m going to disenchant your components, so help me...', 12, 1, 100, 0, 0, 0, 15015, 'Trayanise'),
(18230, 0, 4, 'Get back here, you little...', 12, 1, 100, 0, 0, 0, 15012, 'Trayanise'),
(18230, 0, 5, 'You stay out of the regent lord''s way! I mean it!', 12, 1, 100, 0, 0, 0, 15014, 'Trayanise');

