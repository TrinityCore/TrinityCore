-- 
-- North Fleet Sailor (23866)
DELETE FROM `smart_scripts` WHERE `entryorguid`=23866 AND `source_type`=0 AND `id` IN (1,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23866,0,1,0,0,0,100,0,5000,7000,8000,10000,0,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"North Fleet Sailor - In Combat - Cast 'Cleave'"),
(23866,0,2,0,0,0,100,0,6000,10000,11000,15000,0,11,49863,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"North Fleet Sailor - In Combat - Cast 'Shield Slam'");

-- Vengeance Bringer (23865)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=23865;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23865 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23865,0,0,0,0,0,100,0,1000,1000,60000,60000,0,11,32064,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Vengeance Bringer - In Combat - Cast 'Battle Shout'"),
(23865,0,1,0,0,0,100,0,3000,6000,7000,10000,0,11,32736,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Vengeance Bringer - In Combat - Cast 'Mortal Strike'");

-- North Fleet Medic (23794)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=23794;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23794 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23794,0,0,0,0,0,100,0,0,0,3000,5000,0,11,9734,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"North Fleet Medic - In Combat - Cast 'Holy Smite'"),
(23794,0,1,0,2,0,100,0,0,75,8000,9000,0,11,11640,33,0,0,0,0,1,0,0,0,0,0,0,0,0,"North Fleet Medic - Between 0-75% Health - Cast 'Renew'"),
(23794,0,2,0,74,0,100,0,0,75,8000,9000,0,11,11640,33,0,0,0,0,11,0,15,0,0,0,0,0,0,"North Fleet Medic - On Friendly Between 0-75% Health - Cast 'Renew'");

-- Winterskorn Scout (24116)
DELETE FROM `smart_scripts` WHERE `entryorguid`=-200011 AND `source_type`=0 AND `id` IN (4,5);
DELETE FROM `smart_scripts` WHERE `entryorguid`=-200012 AND `source_type`=0 AND `id` IN (1,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-200011,0,4,0,0,0,100,0,3000,5000,5000,7000,0,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Winterskorn Scout - In Combat - Cast 'Cleave'"),
(-200011,0,5,0,0,0,100,0,5000,10000,10000,15000,0,11,18812,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Winterskorn Scout - In Combat - Cast 'Knockdown'"),
(-200012,0,1,0,0,0,100,0,3000,5000,5000,7000,0,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Winterskorn Scout - In Combat - Cast 'Cleave'"),
(-200012,0,2,0,0,0,100,0,5000,10000,10000,15000,0,11,18812,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Winterskorn Scout - In Combat - Cast 'Knockdown'");
