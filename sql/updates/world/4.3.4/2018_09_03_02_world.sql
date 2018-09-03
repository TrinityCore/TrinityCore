-- 
UPDATE `smart_scripts` SET `action_param2`=294149 WHERE `entryorguid`=2362200 AND `source_type`=9 AND `id`=3;
DELETE FROM `creature` WHERE guid IN (294223,294457,294714);
DELETE FROM `creature_addon` WHERE `guid` IN (294223,294457,294714);
DELETE FROM `spawn_group` WHERE `spawnId` IN (294223,294457,294714) AND `spawnType`=0;
UPDATE `smart_scripts` SET `action_param1`=120 WHERE `entryorguid`=7750 AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=44614 AND `source_type`=0 AND `id` IN (7);
DELETE FROM `smart_scripts` WHERE `entryorguid`=44794 AND `source_type`=0 AND `id` IN (5);
UPDATE `creature` SET `spawntimesecs`=2 WHERE `id` IN (44614,44794);
UPDATE `smart_scripts` SET `target_type`=12, target_param1=1 WHERE `entryorguid`=37988 AND `source_type`=0 AND `id` IN (5,6);
DELETE FROM `smart_scripts` WHERE `entryorguid`=3798800 AND `source_type`=9 AND `id`=4;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3798800,9,4,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Zuni Lvl 1 - Script - store target");
DELETE FROM `smart_scripts` WHERE `entryorguid`=40927 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(40927,0,0,0,8,0,100,1,43671,0,0,0,0,11,89877,0,0,0,0,0,7,0,0,0,0,0,0,0,"On spell 43671 hit - Self: Cast spell 89877 on Action invoker");
UPDATE `smart_scripts` SET `target_type`=23 WHERE `entryorguid`=44586 AND `source_type`=0 AND `id` IN (1);
DELETE FROM `smart_scripts` WHERE `entryorguid`=48092 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(48092,0,0,0,8,0,100,0,93970,0,0,0,0,11,85016,2,0,0,0,0,7,0,0,0,0,0,0,0,"On spell 93970 hit  - Self: Cast spell 85016 on Action invoker");
