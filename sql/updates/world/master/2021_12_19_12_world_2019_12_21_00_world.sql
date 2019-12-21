-- 
SET @Pentarus := 28160; -- Archmage Pentarus
SET @SPELL := 50859;  -- Summon Machine 28192
Set @Machine:= 28192;
Set @AirPatrol:= 28229;

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@Pentarus;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@Pentarus*100;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@Machine;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@Machine*100;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@Machine;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@Machine*100+1;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@Machine*100+2;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@AirPatrol;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@AirPatrol*100;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=27987*100;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 27987 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Pentarus,0,0,0,62,0,100,0,10024,0,0,0,80,@Pentarus*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Archmage Pentarus - On gossip option select  - run script'),
(@Pentarus*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Archmage Pentarus - Actionlist - Close gossip'),
(@Pentarus*100,9,1,0,0,0,100,0,0,0,0,0,11,@SPELL,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Archmage Pentarus - Script - Cast Flight to Sholazar on player'),
(@Pentarus*100,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Archmage Pentarus - Script - say 0'),
(@Pentarus*100,9,3,0,0,0,100,0,0,0,0,0,50,190488,19,0,0,0,0,8,0,0,0,5828.639, 427.1178, 670.0963, 0.8203033, 'Archmage Pentarus - Script - spawn portal'),
(@Machine, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, @Machine*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Machine - On summon - Action List'),
(@Machine*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 51076, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Machine - Action List - Cast Flight to Sholazar (Trigger Warning)'),
(@Machine*100, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 69, 1, 0, 0, 0, 0, 0, 8, 0, 0, 0, 5828.688, 428.0959, 669.89274, 0.612513, 'Machine - Action List - Move to Pos'),
(@Machine, 0, 1, 0, 34, 0, 100, 0, 8, 1, 0, 0, 11, 50987, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Machine - On movement informer - cast teleportation'),
(@Machine, 0, 2, 0, 8, 0, 100, 1, 50987, 0, 0, 0, 80, @Machine*100+1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Machine - On spell hit - Action List'),
(@Machine*100+1, 9, 0, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 53, 1, @Machine, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Machine - Action List - Start wp'),
(@Machine, 0, 3, 0, 40, 0, 100, 0, 11, 0, 0, 0, 80, @Machine*100+2, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '@Machine - On wp 11- Actionlist'),
(@Machine*100+2, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 75, 45472, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, '@Machine - Actionlist - Add parachute'),
(@Machine*100+2, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 53119, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '@Machine - Actionlist - Cast Cosmetic Flame Dart'),
(@Machine*100+2, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 27987, 90, 0, 0, 0, 0, 0, '@Machine - Action List - talk'),
(@Machine*100+2, 9, 4, 0, 0, 0, 100, 0, 500, 500, 0, 0, 11, 50630, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '@Machine - Actionlist - cast Eject passenger'),
(@Machine*100+2, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 2, 0, 0, 0, 0, 0, 8, 0, 0, 0, 5637.412, 5301.54, -109.5869, 0, '@Machine - Actionlist - Cast Cosmetic Flame Dart'),
(@Machine, 0, 4, 5, 34, 0, 100, 0, 8, 2, 0, 0, 11, 53119, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Machine - On movement informer  - Cast Cosmetic Flame Dart'),
(@Machine, 0, 5, 0, 61, 0, 100, 0, 8, 2, 0, 0, 41, 500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Machine - On movement informer  - Despawns'),
(@AirPatrol, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, @AirPatrol*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '@AirPatrol - On Just summoned - Action List'),
(@AirPatrol*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '@AirPatrol - Action List - Set active'),
(@AirPatrol*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 1, @AirPatrol, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '@AirPatrol - Action List - Start WP'),
(@AirPatrol*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 51044, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '@AirPatrol - Action List - Cast Venture Co. Air Patrol Rockets'),
(@AirPatrol*100, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 51043, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '@AirPatrol - Action List - CastVenture Co. Air Patrol Periodic (Kill Shot)'),
(@AirPatrol*100, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '@AirPatrol - Action List - Talk'),
(@AirPatrol, 0, 1, 0, 40, 0, 100, 0, 11, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '@AirPatrol - On wp 11- Despawns');

DELETE FROM `waypoints` WHERE `entry` IN (@Machine,@AirPatrol);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(@Machine, 1, 5142.877, 4676.631, 73.46826, 'Archimage Pentarus Flying Machine'),
(@Machine, 2, 5199.205, 4727.144, 72.46811, 'Archimage Pentarus Flying Machine'),
(@Machine, 3, 5264.490, 4794.450, 69.96814, 'Archimage Pentarus Flying Machine'),
(@Machine, 4, 5309.754, 4842.058, 59.27339, 'Archimage Pentarus Flying Machine'),
(@Machine, 5, 5339.674, 4877.889, 46.18986, 'Archimage Pentarus Flying Machine'),
(@Machine, 6, 5403.426, 4944.932, 15.16180, 'Archimage Pentarus Flying Machine'),
(@Machine, 7, 5455.626, 5002.442, -3.115965, 'Archimage Pentarus Flying Machine'),
(@Machine, 8, 5529.638, 5085.854, -31.67146, 'Archimage Pentarus Flying Machine'),
(@Machine, 9, 5599.572, 5174.957, -62.56064, 'Archimage Pentarus Flying Machine'),
(@Machine, 10, 5622.023, 5202.662, -68.72743, 'Archimage Pentarus Flying Machine'),
(@Machine, 11, 5635.875, 5225.561, -75.11644, 'Archimage Pentarus Flying Machine'),
(@AirPatrol, 1, 5420.977, 4942.308, 16.00475, "AirPatrol"),
(@AirPatrol, 2, 5421.660, 4943.039, 16.00475, "AirPatrol"),
(@AirPatrol, 3, 5508.881, 4993.853, -26.99996, "AirPatrol"),
(@AirPatrol, 4, 5527.892, 5024.440, -33.16645, "AirPatrol"),
(@AirPatrol, 5, 5555.948, 5055.017, -40.5555, "AirPatrol"),
(@AirPatrol, 6, 5573.230, 5081.368, -46.41664, "AirPatrol"),
(@AirPatrol, 7, 5596.792, 5120.542, -60.86132, "AirPatrol"),
(@AirPatrol, 8, 5616.421, 5169.335, -73.94473, "AirPatrol"),
(@AirPatrol, 9, 5639.541, 5246.319, -82.02806, "AirPatrol"),
(@AirPatrol, 10, 5649.434, 5336.935, -80.61153, "AirPatrol"),
(@AirPatrol, 11, 5649.434, 5336.935, -80.61153, "AirPatrol");

UPDATE `creature_template_movement` SET `Swim`=0 WHERE `CreatureID`  IN (28192,28229);
UPDATE `creature_template` SET `speed_walk`=6, `speed_run`=3.14286 WHERE `entry` IN (28192,28229);
UPDATE `creature_template_addon` SET `auras`="48602" WHERE `entry`=28229;
DELETE FROM `creature_template_addon` WHERE `entry`=28192;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(28192,0,0,1,0, "48602");

DELETE FROM `spell_scripts` WHERE `id` IN (51071);
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(51071,0,0,0,0,0,27621,0,0,0,0);
