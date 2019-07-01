--
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1636400, 1636401, 1636402, 1636403, 1636404, 1636405, 1636406, 1636407, 1636408) AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23837 AND `source_type`=0 AND `id` IN (3, 4);
DELETE FROM `smart_scripts` WHERE `entryorguid`=16364 AND `source_type`=0 AND `id`=5;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23837, 0, 3, 0, 38, 0, 100, 512, 30, 30, 0, 0, 0, 80, 1636401, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "ELM General Purpose Bunny - On Data Set - Run ActionList"),
(23837, 0, 4, 0, 38, 0, 100, 512, 31, 31, 0, 0, 0, 80, 1636402, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "ELM General Purpose Bunny - On Data Set - Run ActionList"),
(1636400, 9, 0, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 45, 30, 30, 0, 0, 0, 0, 19, 23837, 0, 0, 0, 0, 0, 0, 0, "Infused Crystal - Script - Set Data ELM General Purpose Bunny"),
(1636400, 9, 1, 0, 0, 0, 100, 0, 30000, 30000, 0, 0, 0, 45, 31, 31, 0, 0, 0, 0, 19, 23837, 0, 0, 0, 0, 0, 0, 0, "Infused Crystal - Script - Set Data ELM General Purpose Bunny"),
(1636400, 9, 2, 0, 0, 0, 100, 0, 27000, 27000, 0, 0, 0, 33, 16364, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 0, "Infused Crystal - Script - Complete quest (Powering our Defenses)"),
(1636400, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Infused Crystal - Script - Say"),
(1636400, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Infused Crystal - Script - Despawn"),
(1636401, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 12, 17086, 6, 60000, 0, 0, 0, 8, 0, 0, 0, 0, 8318.2246, -7213.9136, 140.2572, 3.07977, "Infused Crystal - On Script - Spawn Enraged Wraith"),
(1636401, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 12, 17086, 6, 60000, 0, 0, 0, 8, 0, 0, 0, 0, 8268.6064, -7174.1279, 137.0559, 5.03934, "Infused Crystal - On Script - Spawn Enraged Wraith"),
(1636401, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 12, 17086, 6, 60000, 0, 0, 0, 8, 0, 0, 0, 0, 8250.7012, -7247.7314, 139.5843, 0.76284, "Infused Crystal - On Script - Spawn Enraged Wraith"),
(1636402, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 12, 17086, 6, 60000, 0, 0, 0, 8, 0, 0, 0, 0, 8300.4414, -7247.9800, 139.8134, 2.05089, "Infused Crystal - On Script - Spawn Enraged Wraith"),
(1636402, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 12, 17086, 6, 60000, 0, 0, 0, 8, 0, 0, 0, 0, 8290.9619, -7176.1738, 137.3834, 4.45421, "Infused Crystal - On Script - Spawn Enraged Wraith"),
(1636402, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 12, 17086, 6, 60000, 0, 0, 0, 8, 0, 0, 0, 0, 8236.4082, -7213.2451, 138.9022, 6.24885, "Infused Crystal - On Script - Spawn Enraged Wraith");
