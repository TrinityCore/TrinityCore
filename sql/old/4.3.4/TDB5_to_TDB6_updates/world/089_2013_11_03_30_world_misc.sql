UPDATE `creature_template` SET `ainame`='SmartAI',`scriptname`='' WHERE `entry`=17768;
DELETE FROM `smart_scripts` WHERE `entryorguid`=17768 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1776800 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17768,0,0,0,8,0,100,0,31225,0,0,0,80,1776800,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blood Knight Stillblade - On Spell Hit - Call Timed Action List'),
(1776800,9,0,0,0,0,100,0,0,0,0,0,33,17768,0,0,0,0,0,7,0,0,0,0,0,0,0,'Action 0 - Give Quest Credit'),
(1776800,9,1,0,0,0,100,0,0,0,0,0,11,32343,0,0,0,0,0,1,0,0,0,0,0,0,0,'Action 1 - Cast Revive Self'),
(1776800,9,2,0,0,0,100,0,0,0,0,0,91,7,0,0,0,0,0,1,0,0,0,0,0,0,0,'Action 2 - Remove Unit Field Bytes 1'),
(1776800,9,3,0,0,0,100,0,0,0,0,0,96,40,0,0,0,0,0,1,0,0,0,0,0,0,0,'Action 3 - Remove Dynamic Flags'),
(1776800,9,4,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Action 4 - Talk'),
(1776800,9,5,0,0,0,100,0,120000,120000,0,0,94,40,0,0,0,0,0,1,0,0,0,0,0,0,0,'Action 5 - Restore Dynamic Flags'),
(1776800,9,6,0,0,0,100,0,0,0,0,0,90,7,0,0,0,0,0,1,0,0,0,0,0,0,0,'Action 6 - Restore Unit Field Bytes 1');
