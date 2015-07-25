-- 
-- A Flawless Plan
UPDATE `event_scripts` SET `x`=6447.573, `y`=-1728.755, `z`=480.7186, `o`=5.66264 WHERE `id`=19455;

-- Tormar Frostgut SAI
SET @ENTRY := 29626;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tormar Frostgut - On Spawn - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,61,0,100,1,0,0,0,0,53,0,@ENTRY,0,0,0,2,1,0,0,0,0,0,0,0,"Tormar Frostgut - On Respawn - Start Waypoint (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,3000,6000,12000,15000,11,50410,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tormar Frostgut - In Combat - Cast 'Tusk Strike'"),
(@ENTRY,0,3,0,0,0,100,0,7000,9000,15000,18000,11,11876,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tormar Frostgut - In Combat - Cast 'War Stomp'"),
(@ENTRY,0,4,5,6,0,100,0,0,0,0,0,75,55486,0,0,0,0,0,18,10,0,0,0,0,0,0,"Tormar Frostgut - On Just Died - Add Aura 'Collapsing Cave'"),
(@ENTRY,0,5,6,61,0,100,0,0,0,0,0,50,191794,50000,0,0,0,0,8,0,0,0,6447.813,-1755.094,456.6544,0.05235888,"Tormar Frostgut - On Just Died - Summon Gameobject 'Falling Rocks'"),
(@ENTRY,0,6,7,61,0,100,0,0,0,0,0,50,191794,50000,0,0,0,0,8,0,0,0,6481.777, -1752.007, 458.7755, 0.1396245,"Tormar Frostgut - On Just Died - Summon Gameobject 'Falling Rocks'"),
(@ENTRY,0,7,8,61,0,100,0,0,0,0,0,50,191794,50000,0,0,0,0,8,0,0,0,6467.791, -1748.995, 511.3322, 0,"Tormar Frostgut - On Just Died - Summon Gameobject 'Falling Rocks'"),
(@ENTRY,0,8,9,61,0,100,0,0,0,0,0,50,191794,50000,0,0,0,0,8,0,0,0,6491.699, -1745.516, 542.3831, 0.4537851,"Tormar Frostgut - On Just Died - Summon Gameobject 'Falling Rocks'"),
(@ENTRY,0,9,10,61,0,100,0,0,0,0,0,50,191794,50000,0,0,0,0,8,0,0,0,6520.108, -1734.326, 461.0402, 4.171338,"Tormar Frostgut - On Just Died - Summon Gameobject 'Falling Rocks'"),
(@ENTRY,0,10,11,61,0,100,0,0,0,0,0,50,191794,50000,0,0,0,0,8,0,0,0,6421.026, -1716.979, 500.0077, 5.829401,"Tormar Frostgut - On Just Died - Summon Gameobject 'Falling Rocks'"),
(@ENTRY,0,11,12,61,0,100,0,0,0,0,0,50,191794,50000,0,0,0,0,8,0,0,0,6529.01, -1723.248, 457.2287, 1.274088,"Tormar Frostgut - On Just Died - Summon Gameobject 'Falling Rocks'"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,50,191794,50000,0,0,0,0,8,0,0,0,6440.159, -1688.635, 453.0173, 5.253442,"Tormar Frostgut - On Just Died - Summon Gameobject 'Falling Rocks'"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,50,191794,50000,0,0,0,0,8,0,0,0,6451.857, -1721.448, 457.9259, 5.113817,"Tormar Frostgut - On Just Died - Summon Gameobject 'Falling Rocks'"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,50,191794,50000,0,0,0,0,8,0,0,0,6525.827, -1670.884, 481.5853, 1.710422,"Tormar Frostgut - On Just Died - Summon Gameobject 'Falling Rocks'"),
(@ENTRY,0,15,16,61,0,100,0,0,0,0,0,50,191794,50000,0,0,0,0,8,0,0,0,6449.62, -1726.283, 508.1216, 5.532695,"Tormar Frostgut - On Just Died - Summon Gameobject 'Falling Rocks'"),
(@ENTRY,0,16,17,61,0,100,0,0,0,0,0,50,191794,50000,0,0,0,0,8,0,0,0,6479.444, -1707.681, 521.955, 2.373644,"Tormar Frostgut - On Just Died - Summon Gameobject 'Falling Rocks'"),
(@ENTRY,0,17,18,61,0,100,0,0,0,0,0,50,191794,50000,0,0,0,0,8,0,0,0,6501.444, -1691.474, 520.4632, 3.194002,"Tormar Frostgut - On Just Died - Summon Gameobject 'Falling Rocks'"),
(@ENTRY,0,18,19,61,0,100,0,0,0,0,0,50,191794,50000,0,0,0,0,8,0,0,0,6438.672, -1691.771, 496, 4.450591,"Tormar Frostgut - On Just Died - Summon Gameobject 'Falling Rocks'"),
(@ENTRY,0,19,20,61,0,100,0,0,0,0,0,50,191794,50000,0,0,0,0,8,0,0,0,6452.118, -1674.29, 459.9882, 4.939284,"Tormar Frostgut - On Just Died - Summon Gameobject 'Falling Rocks'"),
(@ENTRY,0,20,21,61,0,100,0,0,0,0,0,50,191794,50000,0,0,0,0,8,0,0,0,6427.761, -1708.688, 460.3108, 5.951575,"Tormar Frostgut - On Just Died - Summon Gameobject 'Falling Rocks'"),
(@ENTRY,0,21,22,61,0,100,0,0,0,0,0,50,191794,50000,0,0,0,0,8,0,0,0,6550.207, -1673.569, 472.539, 2.635444,"Tormar Frostgut - On Just Died - Summon Gameobject 'Falling Rocks'"),
(@ENTRY,0,22,23,61,0,100,0,0,0,0,0,50,191794,50000,0,0,0,0,8,0,0,0,6462.897, -1652.708, 483.0869, 3.804818,"Tormar Frostgut - On Just Died - Summon Gameobject 'Falling Rocks'"),
(@ENTRY,0,23,24,61,0,100,0,0,0,0,0,50,191794,50000,0,0,0,0,8,0,0,0,6501.737, -1642.168, 481.7906, 3.455756,"Tormar Frostgut - On Just Died - Summon Gameobject 'Falling Rocks'"),
(@ENTRY,0,24,25,61,0,100,0,0,0,0,0,50,191794,50000,0,0,0,0,8,0,0,0,6417.866, -1645.066, 464.6994, 0.2443456,"Tormar Frostgut - On Just Died - Summon Gameobject 'Falling Rocks'"),
(@ENTRY,0,25,26,61,0,100,0,0,0,0,0,50,191794,50000,0,0,0,0,8,0,0,0,6489.943, -1626.269, 452.8661, 4.118979,"Tormar Frostgut - On Just Died - Summon Gameobject 'Falling Rocks'"),
(@ENTRY,0,26,27,61,0,100,0,0,0,0,0,50,191794,50000,0,0,0,0,8,0,0,0,6487.299, -1645.281, 453.6305, 3.560473,"Tormar Frostgut - On Just Died - Summon Gameobject 'Falling Rocks'"),
(@ENTRY,0,27,28,61,0,100,0,0,0,0,0,50,191794,50000,0,0,0,0,8,0,0,0,6439.751, -1622.467, 450.6702, 5.846854,"Tormar Frostgut - On Just Died - Summon Gameobject 'Falling Rocks'"),
(@ENTRY,0,28,29,61,0,100,0,0,0,0,0,50,191794,50000,0,0,0,0,8,0,0,0,6529.01, -1723.248, 457.2287, 1.274088,"Tormar Frostgut - On Just Died - Summon Gameobject 'Falling Rocks'"),
(@ENTRY,0,29,30,61,0,100,0,0,0,0,0,50,191794,50000,0,0,0,0,8,0,0,0,6421.026, -1716.979, 500.0077, 5.829401,"Tormar Frostgut - On Just Died - Summon Gameobject 'Falling Rocks'"),
(@ENTRY,0,30,31,61,0,100,0,0,0,0,0,50,191794,50000,0,0,0,0,8,0,0,0,6501.737, -1642.168, 481.7906, 3.455756,"Tormar Frostgut - On Just Died - Summon Gameobject 'Falling Rocks'"),
(@ENTRY,0,31,32,61,0,100,0,0,0,0,0,50,191794,50000,0,0,0,0,8,0,0,0,6397.639, -1619.929, 454.296, 5.829401,"Tormar Frostgut - On Just Died - Summon Gameobject 'Falling Rocks'"),
(@ENTRY,0,32,33,61,0,100,0,0,0,0,0,50,191794,50000,0,0,0,0,8,0,0,0,6373.41, -1612.911, 446.194, 5.916668,"Tormar Frostgut - On Just Died - Summon Gameobject 'Falling Rocks'"),
(@ENTRY,0,33,34,61,0,100,0,0,0,0,0,50,191794,50000,0,0,0,0,8,0,0,0,6381.69, -1637.165, 439.9731, 0,"Tormar Frostgut - On Just Died - Summon Gameobject 'Falling Rocks'"),
(@ENTRY,0,34,35,61,0,100,0,0,0,0,0,50,191794,50000,0,0,0,0,8,0,0,0,6440.159, -1688.635, 453.0173, 5.253442,"Tormar Frostgut - On Just Died - Summon Gameobject 'Falling Rocks'"),
(@ENTRY,0,35,36,61,0,100,0,0,0,0,0,50,191794,50000,0,0,0,0,8,0,0,0,6451.857, -1721.448, 457.9259, 5.113817,"Tormar Frostgut - On Just Died - Summon Gameobject 'Falling Rocks'"),
(@ENTRY,0,36,0,61,0,100,0,0,0,0,0,11,59383,2,0,0,0,0,1,0,0,0,0,0,0,0,"Tormar Frostgut - On Just Died - Cast 'Falling Rocks'");

DELETE FROM `creature_text` WHERE `entry`=29626;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES 
(29626, 0, 0, 'Delicious morsels have come to visit! Shall I use your bombs to cook you?', 14, 0, 0, 0, 0, 0, 'Tormar Frostgut', 30593);

-- Cave Explosion Bunny SAI
SET @ENTRY := 29999;
UPDATE `creature_template` SET `InhabitType`=4 AND `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,3000,3000,3000,3000,28,55486,0,0,0,0,0,21,20,0,0,0,0,0,0,"Cave Explosion Bunny - Out of Combat - Remove Aura 'Collapsing Cave'");

DELETE FROM `waypoints` WHERE `entry`=29626;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(29626, 1, 6450.068, -1730.539, 481.0719, 'Tormar Frostgut'),
(29626, 2, 6454.975, -1734.046, 481.8981, 'Tormar Frostgut'),
(29626, 3, 6459.588, -1737.343, 484.043, 'Tormar Frostgut'),
(29626, 4, 6461.15, -1738.459, 484.4799, 'Tormar Frostgut');

UPDATE `creature_template` SET `flags_extra`=128 WHERE `entry`=29999;

SET @GUID := 48245; -- needs 6
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID +0 AND @GUID +8;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES 
(@GUID +0, 29999, 571, 0, 0, 1, 1, 0, 0, 6355.28, -1590.16, 427.92, 4.2237, 300, 0, 0, 484, 0, 0, 0, 0, 0, 0),
(@GUID +1, 29999, 571, 0, 0, 1, 1, 0, 0, 6507.73, -1742.65, 490.971, 5.96903, 300, 0, 0, 484, 0, 0, 0, 0, 0, 0),
(@GUID +2, 29999, 571, 0, 0, 1, 1, 0, 0, 6514.17, -1752.01, 498.858, 4.90438, 300, 0, 0, 484, 0, 0, 0, 0, 0, 0),
(@GUID +3, 29999, 571, 0, 0, 1, 1, 0, 0, 6511, -1756.26, 495.54, 1.46608, 300, 0, 0, 484, 0, 0, 0, 0, 0, 0),
(@GUID +4, 29999, 571, 0, 0, 1, 1, 0, 0, 6502.11, -1733.94, 490.455, 5.55015, 300, 0, 0, 484, 0, 0, 0, 0, 0, 0),
(@GUID +5, 29999, 571, 0, 0, 1, 1, 0, 0, 6500.87, -1746.74, 490.478, 6.0912, 300, 0, 0, 484, 0, 0, 0, 0, 0, 0);
