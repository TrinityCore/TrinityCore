-- Darkweb Victim SAI
-- To Fix 12037  Search and Rescue

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` =27909;

DELETE FROM `smart_scripts` WHERE `entryorguid` =27909 and `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(2790900,2790901,2790902) and `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(27909, 0, 0, 0, 11,  0, 100, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darkweb Victim - On Spawn - Set Invincibility Hp'),
(27909, 0, 1, 0, 2,  0, 100, 1, 0, 1, 0, 0, 87, 2790900, 2790901, 2790902, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darkweb Victim - On 1% HP - Set Random script'),
(2790900, 9, 0, 0, 0,  0, 100, 0, 0, 0, 0, 0, 11, 49952, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darkweb Victim - Script 1 - Cast Summon Kurzel'),
(2790900, 9, 1, 0, 0,  0, 100, 0, 0, 0, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darkweb Victim - Script 1 - Die'),
(2790901, 9, 0, 0, 0,  0, 100, 0, 0, 0, 0, 0, 11, 49958, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darkweb Victim - Script 2 - Cast Summon Drakkari Shaman'),
(2790901, 9, 1, 0, 0,  0, 100, 0, 0, 0, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darkweb Victim - Script 2 - Die'),
(2790902, 9, 0, 0, 0,  0, 100, 0, 0, 0, 0, 0, 11, 49959, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darkweb Victim - Script 3 - Cast Summon Drakkari Guardian'),
(2790902, 9, 1, 0, 0,  0, 100, 0, 0, 0, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darkweb Victim - Script 3 - Die');
