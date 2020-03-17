-- 
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry`=36212;
DELETE FROM `creature` WHERE `guid` IN (127436,127437,127450,127472);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(127436, 36212, 33, 0, 0, 1, 1, 0, 0, -240.156, 2160.68, 90.5662, 0, 180, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(127437, 36212, 33, 0, 0, 1, 1, 0, 0, -166.3907, 2219.9748, 81.1539, 3.514658, 180, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(127450, 36212, 33, 0, 0, 1, 1, 0, 0, -215.5313, 2240.8679, 79.7662, 1.881030, 180, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(127472, 36212, 33, 0, 0, 1, 1, 0, 0, -177.6394, 2224.131, 79.3472, 4.857682, 180, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `game_event_creature` WHERE `guid` IN (127436,127437,127450,127472);
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(8,127436),(8,127437),
(8,127450),(8,127472);

UPDATE `creature_template` SET `exp`=2, `AIName`='SmartAI' WHERE  `entry`=36568;
DELETE FROM `smart_scripts` WHERE `entryorguid`=36568 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`,  `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(36568, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 18, 100, 0, 0, 0, 0, 0,  0, 'Crazed Apothecary - On Just Summoned - Attack player'),
(36568, 0, 1, 0, 26, 0, 100, 0, 0, 3, 0, 0, 0, 11, 68957, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,  0, 'Crazed Apothecary - IC LOS - Cast Unstable Reaction'),
(36568, 0, 2, 0, 7, 0, 100, 0, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,  0, 'Crazed Apothecary - On evade - Despawn');
