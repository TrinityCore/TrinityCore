-- Fix closed door (180636) in Temple of Ahn'Qiraj after first boss
UPDATE `gameobject_template` SET `AIName` = 'SmartGameObjectAI' WHERE `entry` = 15263;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `action_type`, `target_type`, `target_param1`, `target_param2`, `comment`) VALUES 
(15263, 0, 0, 0, 6, 0, 100, 0, 15263, 9, 14, 101339, 180636, 'Door - open the door');

-- Fix duration of Mysterious Egg - real time
UPDATE `item_template` SET `duration` = -590400 WHERE `entry` = 39878; 

-- Fix duration of Disgusting Jar - real time
UPDATE `item_template` SET `duration` = -590400 WHERE `entry` = 44718;
