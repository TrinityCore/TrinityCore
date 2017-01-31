UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=4721;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4721 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=472100 AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4721, 0, 0, 0,68, 0, 100, 0, 25, 0, 0, 0, 53, 0, 4721, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zangen Stonehoof - On Event Start - Start WP'),
(4721, 0, 1, 2,40, 0, 100, 0, 1, 4721, 0, 0, 54, 25000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zangen Stonehoof - On Reached WP1 - Pause WP'),
(4721, 0, 2, 3,61, 0, 100, 0, 0, 0, 0, 0, 80, 472100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zangen Stonehoof - Linked with Previous Event - Run Script'),
(4721, 0, 3, 0,61, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zangen Stonehoof - Linked with Previous Event - Set Phase 2'),
(4721, 0, 4, 5,40, 0, 100, 0, 2, 4721, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 4.74729, 'Zangen Stonehoof - On Reached WP2 - Set Orientation'),
(4721, 0, 5, 0,61, 0, 100, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zangen Stonehoof - Linked with Previous Event - Set Phase 1'),
(4721, 0, 6, 0,1, 2, 100, 0, 0, 0, 3125, 3125, 4, 6675, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zangen Stonehoof - OOC (Phase 2) - Play Sound'),
(472100, 9, 0, 0,0, 0, 100, 0, 7000, 7000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zangen Stonehoof - Script - Say'),
(472100, 9, 1, 0,0, 0, 100, 0, 3000, 3000, 0, 0, 11, 21392, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zangen Stonehoof - Script - Cast Fire Channeling'),
(472100, 9, 2, 0,0, 0, 100, 0, 11000, 11000, 0, 0, 9, 0, 0, 0, 0, 0, 0, 14, 20556, 178571, 0, 0, 0, 0, 0, 'Zangen Stonehoof - Script - Activate Bonfire'),
(472100, 9, 3, 0,0, 0, 100, 0, 1000, 1000, 0, 0, 28, 21392, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zangen Stonehoof - Script - Remove Aura Fire Channeling');

DELETE FROM `creature_text` WHERE `entry`=4721;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(4721, 0, 0, 'The Earth Mother watch over us; under cover of the night as in the day. Let this fire illuminate both our bodies and spirits and remind us of our honored ancestors, who are ever present and guiding our way.', 12, 3, 100, 1, 0, 0, 'Zangen Stonehoof', 8677);

DELETE FROM `waypoints` WHERE `entry` =4721;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(4721, 1, -1207.747, -59.47412, 158.3598, 'Zangen Stonehoof'),
(4721, 2, -1207.755, -57.32731, 158.6144, 'Zangen Stonehoof');
