-- 
DELETE FROM `creature_text` WHERE `entry` = 33686;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextId`) VALUES
(33686, 0, 0, 'I was constructed to serve as a repository for essential information regarding this complex. My primary functions include communicating the status of the frontal defense systems and assessing the status of the entity that this complex was built to imprison.', 12, 0, 0, 0, 0, 0, 'Norgannon SAY_EVENT_1', 33703),
(33686, 1, 0, 'Access to the interior of the complex is currently restricted. Primary defensive emplacements are active. Secondary systems are currently non-active.', 12, 0, 0, 0, 0, 0, 'Norgannon SAY_EVENT_2', 33705),
(33686, 2, 0, 'Compromise of complex detected, security override enabled - query permitted.', 12, 0, 0, 0, 0, 0, 'Norgannon SAY_EVENT_3', 33707),
(33686, 3, 0, 'Primary defensive emplacements consist of iron constructs and Storm Beacons, which will generate additional constructs as necessary. Secondary systems consist of orbital defense emplacements.', 12, 0, 0, 0, 0, 0, 'Norgannon SAY_EVENT_4', 33712),
(33686, 4, 0, 'Entity designate: Yogg-Saron. Security has been compromised. Prison operational status unknown. Unable to contact Watchers for notification purposes.', 12, 0, 0, 0, 0, 0, 'Norgannon SAY_EVENT_5', 33711);

DELETE FROM `smart_scripts` WHERE `entryorguid`IN(3370100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3370100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Say Line 0'),
(3370100, 9, 1, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 33686, 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Say Line 0 (Lore Keeper of Norgannon)'),
(3370100, 9, 2, 0, 0, 0, 100, 0, 13000, 13000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Say Line 1'),
(3370100, 9, 3, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 33686, 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Say Line 1 (Lore Keeper of Norgannon)'),
(3370100, 9, 4, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Say Line 2'),
(3370100, 9, 5, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 33686, 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Say Line 2 (Lore Keeper of Norgannon)'),
(3370100, 9, 6, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, 33686, 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Say Line 3 (Lore Keeper of Norgannon)'),
(3370100, 9, 7, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Say Line 3'),
(3370100, 9, 8, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Say Line 4'),
(3370100, 9, 9, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Say Line 5'),
(3370100, 9, 10, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 33696, 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Set Data to Archmage Rhydian'),
(3370100, 9, 11, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 19, 33686 , 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Say Line 4 (Lore Keeper of Norgannon)'),
(3370100, 9, 12, 0, 0, 0, 100, 0, 13000, 13000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Say Line 6');
