UPDATE `creature` SET `movementtype`=0, `spawndist`=0 WHERE `id`=32264;
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=32264;
DELETE FROM `smart_scripts` WHERE `entryorguid`=32262 AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(32262, 0, 3, 0, 1, 0, 100, 1, 0, 0, 0, 0, 11, 60309, 0, 0, 0, 0, 0, 19, 32264, 30, 0, 0, 0, 0, 0, 'Shadow Channeler - OOC - Cast Channel Souls');

SET @guid=120996;
DELETE FROM `creature` WHERE `guid` IN (@guid+0, @guid+1);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(@guid+0, 32262, 571, 0, 0, 1, 1, 10631, 1, 8138.115, 2063.47, 550.596, 5.449381, 300, 0, 0, 9740, 8636, 0, 0, 0, 0),
(@guid+1, 32262, 571, 0, 0, 1, 1, 10631, 1, 8163.586, 2059.63, 550.596, 3.768629, 300, 0, 0, 9740, 8636, 0, 0, 0, 0);

UPDATE `creature_addon` SET `emote`=396 WHERE `guid`IN (121534,121535,121532);
