UPDATE `creature` SET `spawntimesecs`=60 WHERE `id` IN (19565,20899);
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=20933;
DELETE FROM `smart_scripts` WHERE `entryorguid`=20933 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=20899 AND `source_type`=0 AND `id` IN (3,4);
DELETE FROM `smart_scripts` WHERE `entryorguid`=2093300 AND `source_type`=9;
UPDATE `smart_scripts` SET `link`='3' WHERE  `entryorguid`=20899 AND `source_type`=0 AND `id`=2 AND `link`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(20899, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 9, 20933, 0, 100, 0, 0, 0, 0, 0, 'Void Conduit - On Death - Set Data'),
(20899, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, 19565, 40, 0, 0, 0, 0, 0, 0, 'Void Conduit - On Death - Kill npc'),
(20933, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 0, 11, 35761, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Camera Shakers Manaforge Ultris - On Data Set - Cast Ultris Explosion'),
(20933, 0, 1, 0, 61, 0, 100, 0, 1, 1, 0, 0, 0, 80, 2093300, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Camera Shakers Manaforge Ultris - On Data Set - Run Script'),
(2093300, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 11, 35763, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Camera Shakers Manaforge Ultris - Script - Cast Ultris Explosion'),
(2093300, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 11, 35763, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Camera Shakers Manaforge Ultris - Script - Cast Ultris Explosion'),
(2093300, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 11, 35763, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Camera Shakers Manaforge Ultris - Script - Cast Ultris Explosion'),
(2093300, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 11, 35763, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Camera Shakers Manaforge Ultris - Script - Cast Ultris Explosion'),
(2093300, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 11, 35763, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Camera Shakers Manaforge Ultris - Script - Cast Ultris Explosion');
