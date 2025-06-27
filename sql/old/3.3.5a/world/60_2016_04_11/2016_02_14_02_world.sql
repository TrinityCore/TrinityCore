-- Free at Last 

UPDATE `smart_scripts` SET `action_type`=45, `action_param1`=1, `action_param2`=1, `target_type`=1, `comment`='Runed Giant - On Script - Set Data Self' WHERE  `entryorguid`=2641700 AND `source_type`=9 AND `id`=2 AND `link`=0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=26417 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(26417, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 11, 47329, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Runed Giant - On Spellhit \'Gavrock\'s Runebreaker\' - Run Script (No Repeat)'),
(26417, 0, 1, 0, 38, 0, 100, 0, 1, 1, 0, 0, 33, 26783, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Runed Giant - On Script - Quest Credit \'Free at Last\''),    
(26417, 0, 2, 3, 8, 0, 25, 0, 47604, 0, 10000, 10000, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Runed Giant - On Spell Hit - Store Target List'),
(26417, 0, 3, 0, 61, 0, 0, 0, 0, 0, 10000, 10000, 80, 2641700, 2, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Runed Giant - On Spell Hit - Start Script for Free At Last');
    
-- Put on Your Best Face for Loken
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE  `entry`=27212;    

-- Send them Packing
UPDATE `smart_scripts` SET  `event_flags`=1 WHERE  `entryorguid`=23977 AND `source_type`=0 AND `id`=0 AND `link`=0;
