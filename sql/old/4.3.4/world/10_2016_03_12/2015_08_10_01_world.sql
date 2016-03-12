--
UPDATE `creature` SET `position_x`=10442.9, `position_y`=783.989, `position_z`=1337.37, `orientation`=3.42085 WHERE `id`=3587;
UPDATE `creature` SET `position_x`=10437,   `position_y`=797.762, `position_z`=1322.79, `orientation`=4.27606 WHERE `id`=3588;
UPDATE `creature` SET `position_x`=10450.9, `position_y`=786.436, `position_z`=1322.77, `orientation`=4.53786 WHERE `id`=3589;
UPDATE `creature` SET `position_x`=10438.1, `position_y`=787.295, `position_z`=1337.37, `orientation`=4.29351 WHERE `id`=3590;
UPDATE `creature` SET `position_x`=10450.6, `position_y`=783.988, `position_z`=1322.76, `orientation`=1.39626 WHERE `id`=3591;
UPDATE `creature` SET `position_x`=10430,   `position_y`=765.778, `position_z`=1322.75, `orientation`=2.14675 WHERE `id`=3592;
UPDATE `creature` SET `position_x`=10526.6, `position_y`=778.086, `position_z`=1329.68, `orientation`=2.47837 WHERE `id`=3593;
UPDATE `creature` SET `position_x`=10519.2, `position_y`=778.014, `position_z`=1329.68, `orientation`=1.53589 WHERE `id`=3594;
UPDATE `creature` SET `position_x`=10458.8, `position_y`=801.623, `position_z`=1346.84, `orientation`=3.75246 WHERE `id`=3595;
UPDATE `creature` SET `position_x`=10448.1, `position_y`=777.997, `position_z`=1322.75, `orientation`=2.23402 WHERE `id`=3596;
UPDATE `creature` SET `position_x`=10441,   `position_y`=773.028, `position_z`=1322.75, `orientation`=2.16421 WHERE `id`=6091;
UPDATE `creature` SET `position_x`=10456.3, `position_y`=804.882, `position_z`=1346.84, `orientation`=4.04916 WHERE `id`=43006;
UPDATE `creature` SET `position_x`=10436.3, `position_y`=769.769, `position_z`=1322.75, `orientation`=3.07178 WHERE `guid`=313269;
 
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=44617;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (44617) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(44617, 0, 0, 0, 8, 0, 100, 0, 774, 0, 0, 0, 33, 44175, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Wounded Sentinel - On spell hit - Kill credit'),
(44617,0,1,0,8,0,100,0,2061,0,0,0,33,44175,0,0,0,0,0,7,0,0,0,0,0,0,0,"Wounded Sentinel- On spell hit - Credit kill");
