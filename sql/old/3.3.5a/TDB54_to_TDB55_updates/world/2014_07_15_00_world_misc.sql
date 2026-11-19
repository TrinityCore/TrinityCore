SET @CGuid := 76311; -- Needs 3 for the 3 permament spawns of living poison which never activate or move but are used to spawn the 

-- Living poison sets immune to pc on spawn and moves forward, if any player comes within 1 yard range it will then remove immune to pc flags
-- and cast explosion spell, it must allow pc at this point otherwise the spell only kills the living poison
-- must set immune to pc on spawn as otherwise instead of moving in straight line will agro and move to players which is wrong behavior

UPDATE `creature_template` SET `AIName`= 'SmartAI',`speed_run`=1.428571 WHERE `entry`=16027;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16027 AND `source_type`=0;

DELETE FROM `creature_template_addon` WHERE `entry`=16027;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(16027, 0, 0x0, 0x1, '18950'); -- 16027 - 18950

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(16027, 0, 0, 1, 10, 1, 100, 1, 0, 1, 0, 0, 19, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Living Poison - OOC LOS - Remove Unit Flags Immune to PC (Phase 1)'),
(16027, 0, 1, 0, 61, 1, 100, 1, 0, 0, 0, 0, 11, 28433, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Living Poison - OOC LOS - Cast Explode (Phase 1)'),
(16027, 0, 2, 3, 54, 0, 100, 1, 0, 0, 0, 0, 18, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Living Poison - On Just Summoned - Set Unit Flags Immune to PC'),
(16027, 0, 3, 4, 61, 0, 100, 1, 0, 0, 0, 0, 46, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Living Poison - On Just Summoned - Move Forward'),
(16027, 0, 4, 0, 61, 0, 100, 1, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Living Poison - On Just Summoned - Set Phase 1');

-- We will use 3 living poison (from sniff) with sai per guid to spawn the moving living poison
-- the living poison spawned by these have sai on creature template but only executes sai on just summoned (event 54)
-- the 3 instances of the npc spawned for this purpose only the ones summoned by the sai on these run the script to move
-- and cast the explosion spell on self if player gets in range resulting in both the living poison and any players in range dying

-- Creature Data taken from 15354_2012-03-16_10-04-38_raids.pkt

DELETE FROM `creature` WHERE `guid` IN (@CGuid, @CGuid+1, @CGuid+2) AND `id`=16027;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID,   16027, 533, 3, 1, 3128.499, -3131.24,  294.0653, 4.725505, 7200, 0, 0),
(@CGUID+1, 16027, 533, 3, 1, 3151.244, -3137.117, 294.0628, 4.456693, 7200, 0, 0),
(@CGUID+2, 16027, 533, 3, 1, 3169.886, -3145.452, 294.0555, 4.244928, 7200, 0, 0);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(-@CGuid,-@CGuid-1,-@CGuid-2) AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-@CGuid, 0, 0, 0, 1, 0, 100, 0, 0, 0, 3333, 3333, 12, 16027, 1, 8000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Living Poison - OOC - Spawn Living Poison'),
(-@CGuid-1, 0, 0, 0, 1, 0, 100, 0, 0, 0, 3333, 3333, 12, 16027, 1, 8000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Living Poison - OOC - Spawn Living Poison'),
(-@CGuid-2, 0, 0, 0, 1, 0, 100, 0, 0, 0, 3333, 3333, 12, 16027, 1, 8000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Living Poison - OOC - Spawn Living Poison'),
(-@CGuid, 0, 1, 2, 11, 0, 100, 0, 0, 0, 0, 0, 18, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Living Poison - On Spawn - Set Unit Flags Immune to PC'),
(-@CGuid-1, 0, 1, 2, 11, 0, 100, 0, 0, 0, 0, 0, 18, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Living Poison - On Spawn - Set Unit Flags Immune to PC'),
(-@CGuid-2, 0, 1, 2, 11, 0, 100, 0, 0, 0, 0, 0, 18, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Living Poison - On Spawn - Set Unit Flags Immune to PC'),
(-@CGuid, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Living Poison - On Spawn - Set Invisible'),
(-@CGuid-1, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Living Poison - On Spawn - Set Invisible'),
(-@CGuid-2, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Living Poison - On Spawn - Set Invisible');
