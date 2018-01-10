-- 
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-82874,-60777,-60792, -82906, -82903, -52640) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (16318) AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16318, 0, 3, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 28729, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,"Deatholme Darkmage - On reset - Cast Ribbon of Souls"),
(-82906, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 28729, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,"Deatholme Necromancer - On reset - Cast Ribbon of Souls"),
(-82906, 0, 1, 0, 0, 0, 100, 0, 0, 0, 3400, 4800, 11, 9613, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Deatholme Necromancer - In Combat CMC - Cast 'Shadow Bolt'"),
(-82906, 0, 2, 0, 2, 0, 100, 0, 0, 20, 8000, 12000, 11, 29067, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Deatholme Necromancer - Between 0-20% Health - Cast 'Slave Drain'"),
(-82906, 0, 3, 0, 2, 0, 100, 1, 0, 15, 0, 0, 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Deatholme Necromancer - Between 0-15% Health - Flee For Assist (No Repeat)"),
(-82903, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 28729, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,"Deatholme Necromancer - On reset - Cast Ribbon of Souls"),
(-82903, 0, 1, 0, 0, 0, 100, 0, 0, 0, 3400, 4800, 11, 9613, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Deatholme Necromancer - In Combat CMC - Cast 'Shadow Bolt'"),
(-82903, 0, 2, 0, 2, 0, 100, 0, 0, 20, 8000, 12000, 11, 29067, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Deatholme Necromancer - Between 0-20% Health - Cast 'Slave Drain'"),
(-82903, 0, 3, 0, 2, 0, 100, 1, 0, 15, 0, 0, 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Deatholme Necromancer - Between 0-15% Health - Flee For Assist (No Repeat)"),
(-82874, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 28729, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,"Deatholme Necromancer - On reset - Cast Ribbon of Souls"),
(-82874, 0, 1, 0, 0, 0, 100, 0, 0, 0, 3400, 4800, 11, 9613, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Deatholme Necromancer - In Combat CMC - Cast 'Shadow Bolt'"),
(-82874, 0, 2, 0, 2, 0, 100, 0, 0, 20, 8000, 12000, 11, 29067, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Deatholme Necromancer - Between 0-20% Health - Cast 'Slave Drain'"),
(-82874, 0, 3, 0, 2, 0, 100, 1, 0, 15, 0, 0, 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Deatholme Necromancer - Between 0-15% Health - Flee For Assist (No Repeat)"),
(-52640, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 28729, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,"Deatholme Necromancer - On reset - Cast Ribbon of Souls"),
(-52640, 0, 1, 0, 0, 0, 100, 0, 0, 0, 3400, 4800, 11, 9613, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Deatholme Necromancer - In Combat CMC - Cast 'Shadow Bolt'"),
(-52640, 0, 2, 0, 2, 0, 100, 0, 0, 20, 8000, 12000, 11, 29067, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Deatholme Necromancer - Between 0-20% Health - Cast 'Slave Drain'"),
(-52640, 0, 3, 0, 2, 0, 100, 1, 0, 15, 0, 0, 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Deatholme Necromancer - Between 0-15% Health - Flee For Assist (No Repeat)"),
(-60777, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 28729, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,"Deatholme Necromancer - On reset - Cast Ribbon of Souls"),
(-60777, 0, 1, 0, 0, 0, 100, 0, 0, 0, 3400, 4800, 11, 9613, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Deatholme Necromancer - In Combat CMC - Cast 'Shadow Bolt'"),
(-60777, 0, 2, 0, 2, 0, 100, 0, 0, 20, 8000, 12000, 11, 29067, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Deatholme Necromancer - Between 0-20% Health - Cast 'Slave Drain'"),
(-60777, 0, 3, 0, 2, 0, 100, 1, 0, 15, 0, 0, 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Deatholme Necromancer - Between 0-15% Health - Flee For Assist (No Repeat)"),
(-60792, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 28729, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,"Deatholme Necromancer - On reset - Cast Ribbon of Souls"),
(-60792, 0, 1, 0, 0, 0, 100, 0, 0, 0, 3400, 4800, 11, 9613, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Deatholme Necromancer - In Combat CMC - Cast 'Shadow Bolt'"),
(-60792, 0, 2, 0, 2, 0, 100, 0, 0, 20, 8000, 12000, 11, 29067, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Deatholme Necromancer - Between 0-20% Health - Cast 'Slave Drain'"),
(-60792, 0, 3, 0, 2, 0, 100, 1, 0, 15, 0, 0, 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Deatholme Necromancer - Between 0-15% Health - Flee For Assist (No Repeat)");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (28731);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,28731,0,0, 31,0,3,10415,0,0,0,'','Ribbon of Souls');

UPDATE `creature` SET `position_x`=6317.244141, `position_y`=-6241.477051 WHERE `guid`=60792 AND `id`=16317; 
UPDATE `creature` SET `position_x`=6302.362793, `position_y`=-6241.597168 WHERE `guid`=60777 AND `id`=16317; 
UPDATE `creature` SET `position_x`=6302.773438, `position_y`=-6255.696289 WHERE `guid`=52640 AND `id`=16317; 
UPDATE `creature` SET `position_x`=6311.409668, `position_y`=-6472.390625 WHERE `guid`=82906 AND `id`=16317; 
UPDATE `creature` SET `position_x`=6297.720703, `position_y`=-6471.333008 WHERE `guid`=82903 AND `id`=16317; 
UPDATE `creature` SET `position_x`=6298.272949, `position_y`=-6457.236328 WHERE `guid`=82874 AND `id`=16317; 
UPDATE `creature` SET `position_x`=7220.31, `position_y`=-6406.11, `position_z`=56.1661, `orientation`=4.77281, spawndist=0, MovementType=0 WHERE `guid`=82656 AND `id`=16318; 
UPDATE `creature` SET `position_x`=7216.75, `position_y`=-6415.47, `position_z`=59.2486, `orientation`=0.10472, spawndist=0, MovementType=0 WHERE `guid`=82657 AND `id`=16318; 
UPDATE `creature` SET `position_x`=7229.53, `position_y`=-6415.04, `position_z`=56.1660, `orientation`=3.16177, spawndist=0, MovementType=0 WHERE `guid`=82658 AND `id`=16318; 
UPDATE `creature` SET `position_x`=7220.87, `position_y`=-6424.45, `position_z`=56.1659, `orientation`=1.64359, spawndist=0, MovementType=0 WHERE `guid`=82665 AND `id`=16318; 
UPDATE `creature` SET `position_x`=7161.33, `position_y`=-6612.54, `position_z`=60.6584, `orientation`=6.04004, spawndist=0, MovementType=0 WHERE `guid`=82741 AND `id`=16318; 
UPDATE `creature` SET `position_x`=7171.98, `position_y`=-6606.72, `position_z`=60.6584, `orientation`=4.43751, spawndist=0, MovementType=0 WHERE `guid`=82742 AND `id`=16318; 
UPDATE `creature` SET `position_x`=7173.00, `position_y`=-6615.81, `position_z`=63.7428, `orientation`=2.95281, spawndist=0, MovementType=0 WHERE `guid`=82743 AND `id`=16318; 
UPDATE `creature` SET `position_x`=7167.75, `position_y`=-6623.78, `position_z`=60.6587, `orientation`=1.37635, spawndist=0, MovementType=0 WHERE `guid`=82770 AND `id`=16318; 
UPDATE `creature` SET `position_x`=7207.989258, `position_y`=-6662.287109, `position_z`=48.618168 WHERE `guid`=82767; 
