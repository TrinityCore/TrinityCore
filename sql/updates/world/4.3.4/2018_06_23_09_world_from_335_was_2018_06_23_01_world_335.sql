/*
-- Forlorn Spirit
DELETE FROM `smart_scripts` WHERE `entryorguid`=2044 AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=204400 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2044,0,0,0,11,0,100,0,0,0,0,0,0,80,204400,2,0,0,0,0,1,0,0,0,0,0,0,0,"Forlorn Spirit - On Respawn - Run Script"),
(204400,9,0,0,0,0,100,0,2000,2000,0,0,0,1,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"Forlorn Spirit - On Script - Say Line 0"),
(204400,9,1,0,0,0,100,0,2000,2000,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"Forlorn Spirit - On Script - Start Attacking");
-- Old Footlocker
UPDATE `smart_scripts` SET `target_type`=8, `target_x`=-10951.4, `target_y`=1568.86, `target_z`=46.9779, `target_o`=3.75142 WHERE `entryorguid`=3643 AND `source_type`=1 AND `id`=0;

-- Sealed Crate
UPDATE `smart_scripts` SET `target_x`=-8841.93, `target_y`=985.171, `target_z`=98.6999, `target_o`=6.00926 WHERE `entryorguid`=1561 AND `source_type`=1 AND `id`=0;

-- Marshal Haggard's Chest
UPDATE `event_scripts` SET `delay`=0, `x`=-9553.53, `y`=-1432.44, `z`=62.2943, `o`=5.28835 WHERE `id`=264;
*/
