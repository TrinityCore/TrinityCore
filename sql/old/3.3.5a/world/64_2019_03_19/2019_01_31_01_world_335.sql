-- 
DELETE FROM `creature` WHERE `guid` IN (97398,97402,97403,97404,97405);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(97398, 11552, 1, 1, 1, 0, 0, 6959.36, -2078, 611.066, 0.015, 300, 7, 0, 0, 0, 1),
(97402, 11552, 1, 1, 1, 0, 0, 7317.06, -2174, 542.848, 4.836, 300, 7, 0, 0, 0, 1),
(97403, 11552, 1, 1, 1, 0, 0, 7003.58, -2069.16, 608.559, 6.24575, 300, 0, 0, 0, 0, 0),
(97404, 11552, 1, 1, 1, 0, 0, 7100.42, -2141.84, 574.864, 5.01792, 300, 5, 0, 0, 0, 1),
(97405, 11552, 1, 1, 1, 0, 0, 6929.25, -2271.2, 590.0940, 3.94088, 300, 5, 0, 0, 0, 1);

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (11552); 
DELETE FROM `smart_scripts` WHERE `entryorguid`=11552 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11552,0,0,0,0,0,100,0,1000,2000,3000,6000,0,11,10946,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Timbermaw Mystic - IC - Cast Mind Blast"),
(11552,0,1,0,0,0,100,0,4000,6000,4000,8000,0,11,10934,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Timbermaw Mystic - IC - Cast Smite");
