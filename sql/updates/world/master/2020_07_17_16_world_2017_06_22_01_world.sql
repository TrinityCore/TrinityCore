-- 
DELETE FROM `smart_scripts` WHERE `entryorguid`=34925 AND `source_type`=0 AND `id`>6;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(34925, 0, 7, 0, 1, 1, 100, 0, 3000, 4000, 5000, 9000, 11, 66514, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "North Sea Kraken - OOC - Cast Frost Breath"),
(34925, 0, 8, 0, 1, 1, 100, 0, 10000, 15000, 10000, 15000, 11, 66511, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Northsea Kraken - OOC - Cast Whirl"),
(34925, 0, 9, 0, 1, 1, 100, 1, 32000, 32000, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Northsea Kraken - OOC - Set event phase"),
(34925, 0, 10, 0, 1, 0, 100, 1, 33000, 33000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Northsea Kraken - OOC - despawn"),
(34925, 0, 11, 0, 36, 0, 100, 0, 0, 0, 0, 0, 70, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Northsea Kraken - on corpse removed - Respawn"),
(34925, 0, 12, 0, 1, 0, 100, 1, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Northsea Kraken - OOC - Set event phase"),
(34925, 0, 13, 0, 1, 0, 100, 1, 32000, 32000, 0, 0, 92, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Northsea Kraken - OOC - Inturreput cast");

DELETE FROM `creature` WHERE `guid` IN (80432);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(80432, 34925, 571, 0, 0, '0', 0, 0, 0, 0, 0, 9488.415, 1161.303, -2.197, 2.454109, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `pool_template` WHERE `entry`=385;
INSERT INTO pool_template (`entry`,`max_limit`,`description`) VALUES
(385,1, 'North Sea Kraken (1 out 4)');

DELETE FROM `pool_creature` WHERE `pool_entry`=385;
INSERT INTO pool_creature(`guid`,`pool_entry`,`chance`,`description`) VALUES
(80432,385,0, 'North Sea Kraken 1'),
(53835,385,0, 'North Sea Kraken 2'),
(53836,385,0, 'North Sea Kraken 3'),
(53871,385,0, 'North Sea Kraken 4');

UPDATE `creature` SET `spawntimesecs`=5 WHERE `id`=34925;
