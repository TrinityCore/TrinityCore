--
DELETE FROM `smart_scripts` WHERE `entryorguid`=13716 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(1371600,1371601,1371602) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(13716, 0, 0, 0, 62, 0, 100, 0, 5349, 1, 0, 0, 80, 1371600, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Celebras the Redeemed - On Gossip Option Selected - Run Script'),
(13716, 0, 1, 0, 40, 0, 100, 0, 2, 13716, 0, 0, 80, 1371601, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Celebras the Redeemed - On Reached WP2 - Run Script'),
(13716, 0, 2, 0, 40, 0, 100, 0, 3, 13716, 0, 0, 80, 1371602, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Celebras the Redeemed - On Waypoint 3 Reached - Run Script'),
(13716, 0, 3, 0, 40, 0, 100, 0, 4, 13716, 0, 0, 54, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Celebras the Redeemed - On Waypoint 4 Reached - Pause WP'),
(13716, 0, 4, 5, 38, 0, 100, 0, 0, 1, 0, 0, 65, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Celebras the Redeemed - On Data Set 0 1 - Resume Waypoint'),
(13716, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Celebras the Redeemed - On Data Set 0 1 - Say Line 6'),
(13716, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 84, 6, 0, 0, 0, 0, 0, 21, 20, 0, 0, 0, 0, 0, 0, 'Celebras the Redeemed - On Data Set 0 1 - Say Line 6'),
(13716, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 50, 178964, 2000, 0, 0, 0, 0, 8, 0, 0, 0, 650.98, 74.45, -86.86, 0, 'Celebras the Redeemed - On Data Set 0 1 - Summon Gameobject \'Celebras Blue Aura\'.'),
(13716, 0, 8, 9, 40, 0, 100, 0, 8, 13716, 0, 0, 1, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Celebras the Redeemed - On Waypoint 8 Reached - Say Line 7'),
(13716, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 54, 2000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Celebras the Redeemed - On Waypoint 8 Reached - Pause Waypoint'),
(13716, 0, 10, 0, 40, 0, 100, 0, 11, 13716, 0, 0, 82, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Celebras the Redeemed - On Waypoint 11 Reached - Add Npc Flag Questgiver'),
(13716, 0, 11, 0, 38, 0, 100, 0, 0, 1, 0, 0, 28, 21916, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Celebras the Redeemed - On Data Set 0 1 - Remove Aura \'Celebras Waiting\''),
(13716, 0, 12, 0, 19, 0, 100, 0, 7046, 0, 0, 0, 1, 8, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Celebras the Redeemed - On Quest \'The Scepter of Celebras\' Taken - Say Line 8'),
(13716, 0, 14, 0, 56, 0, 100, 0, 2, 13716, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Celebras the Redeemed - On Waypoint Resumed - Say Line 2'),
(13716, 0, 15, 0, 40, 0, 100, 0, 11, 13716, 0, 0, 15, 7046, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Celebras the Redeemed - On Waypoint Reached - Complete Quest'),
(13716, 0, 16, 0, 20, 0, 100, 0, 7046, 0, 0, 0, 41, 300000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Celebras the Redeemed - On Quest Rewarded - delayed despawn'),

(1371600, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0, 'Celebras the Redeemed - Scrpt  - Store Target'),
(1371600, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 83, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Celebras the Redeemed - Scrpt  - Remove NPC Flag'),
(1371600, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Celebras the Redeemed - Script - Say Line 0'),
(1371600, 9, 3, 0, 0, 0, 100, 0, 2500, 2500, 0, 0, 53, 0, 13716, 0, 0, 0, 3, 1, 0, 0, 0, 0, 0, 0, 0, 'Celebras the Redeemed - Script - Start Waypoint'),
(1371601, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Celebras the Redeemed - Script - Say Line 1'),
(1371601, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 54, 4000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Celebras the Redeemed - Script - Pause Waypoint'),
(1371602, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Celebras the Redeemed - Script - Say Line 3'),
(1371602, 9, 1, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Celebras the Redeemed - Script - Text Emote Line 4'),
(1371602, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 32994, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Celebras the Redeemed - Script - Cast \'Rejuvenation Impact Visual\'.'),
(1371602, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 50, 178965, 30000, 0, 0, 0, 0, 8, 0, 0, 0, 652, 73.5, -85.34, 0, 'Celebras the Redeemed - Script - Summon Gameobject \'Incantation of Celebras\'.'),
(1371602, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 21916, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Celebras the Redeemed - Script - Cast \'Celebras Waiting\'.'),
(1371602, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Celebras the Redeemed - Script - Say Line 5');
