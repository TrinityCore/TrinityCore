UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='',`faction`=775 WHERE `entry` IN(16364);

DELETE FROM `smart_scripts` WHERE `entryorguid` =16364 and `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` =23837 and `source_type`=0 AND `id` IN(3,4);

DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 1636400 AND 1636408 AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16364, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Infused Crystal - on spawn - Store Targetlist'),
(16364, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 12, 23837, 1, 60000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infused Crystal - on spawn - Spawn ELM General Purpose Bunny'),
(16364, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infused Crystal - on spawn - Disable auto attack'),
(16364, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infused Crystal - on spawn - Disable combat movement'),
(16364, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 1636400, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infused Crystal - on spawn - run script'),
(16364, 0, 5, 0, 6, 0, 100, 0, 0, 0, 0, 0, 6, 8490, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Infused Crystal - On Death - Fail quest (Powering our defenses)'),
(1636400, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 31, 31, 0, 0, 0, 0, 19, 23837, 0, 0, 0, 0, 0, 0, 'Infused Crystal - Script - Set Data ELM General Purpose Bunny'),
(1636400, 9, 1, 0, 0, 0, 100, 0, 15000, 15000, 0, 0, 45, 30, 30, 0, 0, 0, 0, 19, 23837, 0, 0, 0, 0, 0, 0, 'Infused Crystal - Script - Set Data ELM General Purpose Bunny'),
(1636400, 9, 2, 0, 0, 0, 100, 0, 15000, 15000, 0, 0, 45, 31, 31, 0, 0, 0, 0, 19, 23837, 0, 0, 0, 0, 0, 0, 'Infused Crystal - Script - Set Data ELM General Purpose Bunny'),
(1636400, 9, 3, 0, 0, 0, 100, 0, 15000, 15000, 0, 0, 45, 30, 30, 0, 0, 0, 0, 19, 23837, 0, 0, 0, 0, 0, 0, 'Infused Crystal - Script - Set Data ELM General Purpose Bunny'),
(1636400, 9, 4, 0, 0, 0, 100, 0, 15000, 15000, 0, 0, 33, 16364, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Infused Crystal - Script - Complete quest (Powering our defenses)'),
(1636400, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infused Crystal - Script - Say'),
(1636400, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infused Crystal - Script - Despawn'),

(1636401, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 17086, 6, 60000, 0, 0, 0, 8, 0, 0, 0, 8270.68, -7188.53, 139.619, 4.93306, 'Infused Crystal - Script - Spawn Enraged Wraith'),
(1636402, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 17086, 6, 60000, 0, 0, 0, 8, 0, 0, 0, 8284.27, -7187.78, 139.603, 4.43198, 'Infused Crystal - Script - Spawn Enraged Wraith'),
(1636403, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 17086, 6, 60000, 0, 0, 0, 8, 0, 0, 0, 8297.43, -7193.53, 139.603, 3.93325, 'Infused Crystal - Script - Spawn Enraged Wraith'),
(1636404, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 17086, 6, 60000, 0, 0, 0, 8, 0, 0, 0, 8303.5, -7201.96, 139.577, 3.60417, 'Infused Crystal - Script - Spawn Enraged Wraith'),
(1636405, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 17086, 6, 60000, 0, 0, 0, 8, 0, 0, 0, 8273.22, -7241.82, 139.382, 1.49851, 'Infused Crystal - Script - Spawn Enraged Wraith'),
(1636406, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 17086, 6, 60000, 0, 0, 0, 8, 0, 0, 0, 8254.89, -7222.12, 139.603, 0.635359, 'Infused Crystal - Script - Spawn Enraged Wraith'),
(1636407, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 17086, 6, 60000, 0, 0, 0, 8, 0, 0, 0, 8278.51, -7242.13, 139.162, 1.73178, 'Infused Crystal - Script - Spawn Enraged Wraith'),
(1636408, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 17086, 6, 60000, 0, 0, 0, 8, 0, 0, 0, 8278.51, -7242.13, 139.162, 1.73178, 'Infused Crystal - Script - Spawn Enraged Wraith'),

(23837, 0, 3, 0, 38, 0, 100, 0, 31, 31, 0, 0, 87, 1636401, 1636403, 1636404, 1636406, 1636407, 1636408, 1, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny - On Data Set - Run Random Script'),
(23837, 0, 4, 0, 38, 0, 100, 0, 30, 30, 0, 0, 87, 1636401, 1636402, 1636403, 1636405, 1636406, 1636408, 1, 0, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny - On Data Set - Run Random Script');

DELETE FROM `creature` WHERE `id`=17086;

DELETE FROM `smart_scripts` WHERE `entryorguid`=17086 AND `id`>1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(17086, 0, 2, 0, 54, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 16364, 0, 0, 0, 0, 0, 0, 'Enraged Wraith - On Just Summoned - Attack infused crystal'),
(17086, 0, 3, 0, 7, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Enraged Wraith - On Evade Despawn');

DELETE FROM `creature_text` WHERE `entry`=16364;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(16364, 0, 0, '%s releases the last of its energies into the nearby runestone, successfully reactivating it.', 16, 0, 100, 0, 0, 0, 'Infused Crystal',12272);

