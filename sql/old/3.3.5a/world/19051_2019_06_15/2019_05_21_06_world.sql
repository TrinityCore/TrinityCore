-- 
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (20397);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (20397) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(20397, 0, 0, 0, 0, 0, 100, 0, 4000, 4000, 8000, 8000, 11, 31361, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Overseer Seylanna - Ic - Cast Bomb Target"),
(20397, 0, 1, 0, 0, 0, 100, 0, 4000, 4000, 8000, 8000, 11, 36179, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Overseer Seylanna - Ic - Cast Crystal Charge"),
(20397, 0, 2, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 34062, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Overseer Seylanna - On reset - Cast Arcane Repair");
DELETE FROM `creature`  WHERE `id` =20218;
DELETE FROM `creature_addon` WHERE `guid` IN (71669,71668,71670);
DELETE FROM `creature`  WHERE `id` =20136 AND `guid` IN (71669,71668,71670);
DELETE FROM `spawn_group` WHERE `spawnType`=0 AND `spawnId` IN (71668,71669,71670);
