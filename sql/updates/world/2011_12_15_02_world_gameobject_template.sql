-- Black Guard Swordsmith summon from Blacksmithing Plans fix by nelegalno
-- Closes https://github.com/TrinityCore/TrinityCore/issues/4218

UPDATE `gameobject_template` SET `AIName` = 'SmartGameObjectAI' WHERE `entry` = 176327;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=176325 AND `source_type`=1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(176327, 1, 0, 0, 64, 0, 100, 1, 0, 0, 0, 0, 12, 11121, 6, 60000, 0, 0, 0, 8, 0, 0, 0, 3818.4, -3693.32, 144.242, 0.261799, 'Blacksmithing Plans - summon Black Guard Swordsmith');