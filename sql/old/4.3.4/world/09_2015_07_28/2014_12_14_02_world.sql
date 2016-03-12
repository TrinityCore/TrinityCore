SET @Pentarus := 28160; -- Archmage Pentarus
SET @SPELL := 50860;  -- Summon Machine 28192
Set @Machine:= 28192;
Set @Spell2 := 51036; -- Summon Summon Venture Co. Air Patrol 28229
Set @AirPatrol:= 28229;
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=@Pentarus;
UPDATE `creature_template` SET `npcflag`= 16777216, `InhabitType`=4, `AIName`='SmartAI', `VehicleId`=220 WHERE `entry`=@Machine;
UPDATE `creature_template` SET `InhabitType`=4, `AIName`='SmartAI'  WHERE `entry`=@AirPatrol;
UPDATE creature_template SET InhabitType=4, `AIName`='SmartAI' WHERE entry=27987;
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
(@Pentarus*100,9,1,0,0,0,100,0,0,0,0,0,85,@SPELL,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Archmage Pentarus - Script - Cast Flight to Sholazar on player'),
(@Pentarus*100,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Archmage Pentarus - Script - say 0'), 
(@Pentarus*100,9,3,0,0,0,100,0,0,0,0,0,50,190488,19,0,0,0,0,8,0,0,0,5832.702637, 436.761108, 669.141174, 1.612513, 'Archmage Pentarus - Script - spawn portal'),
(@Machine, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, @Machine*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Machine - On summon - Action List'),
(@Machine*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 60, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Machine - Action List - Set Fly ON'),
(@Machine*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 85, 46598, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Machine - Action List - CrossCast'),
(@Machine*100, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 5832.702637, 436.761108, 669.141174, 0.612513, 'Machine - Action List - InvokerCast'),
(@Machine*100, 9, 3, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 11, 50987, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Machine - Action List - cast teleportation'),
(@Machine*100, 9, 4, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 53, 1, @Machine, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Machine - Action List - Start wp'),
(@Machine, 0, 1, 0, 40, 0, 100, 0, 1, 0, 0, 0, 80, @Machine*100+1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Machine - on wp end - ActionList'),
(@Machine*100+1, 9, 0, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 11, @Spell2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Machine - Action List - cast spell to invok AirPatrol'),
(@AirPatrol, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, @AirPatrol*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '@AirPatrol - On spawn - Action List'),
(@AirPatrol*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 60, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '@AirPatrol - Action List - Set Fly ON'),
(@AirPatrol*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '@AirPatrol - Action List - Set react passif'),
(@AirPatrol*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 29, 5, 45, 0, 0, 0, 0, 19, @Machine, 60, 0, 0, 0, 0, 0, '@AirPatrol - Action List - follow target'),
(@AirPatrol*100, 9, 3, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '@AirPatrol - Action List - Talk'),
(@AirPatrol*100, 9, 4, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, @Machine, 30, 0, 0, 0, 0, 0, '@AirPatrol - Action List - Talk'),
(@AirPatrol*100, 9, 5, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 11, 50878, 0, 0, 0, 0, 0, 19, @Machine, 30, 0, 0, 0, 0, 0, '@AirPatrol - Action List - Cast'),
(@AirPatrol*100, 9, 6, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 50878, 0, 0, 0, 0, 0, 19, @Machine, 30, 0, 0, 0, 0, 0, '@AirPatrol - Action List - Cast'),
(@AirPatrol*100, 9, 7, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 50878, 0, 0, 0, 0, 0, 19, @Machine, 30, 0, 0, 0, 0, 0, '@AirPatrol - Action List - Cast'),
(@AirPatrol*100, 9, 8, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 50878, 0, 0, 0, 0, 0, 19, @Machine, 30, 0, 0, 0, 0, 0, '@AirPatrol - Action List - Cast'),
(@AirPatrol*100, 9, 9, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 50878, 0, 0, 0, 0, 0, 19, @Machine, 30, 0, 0, 0, 0, 0, '@AirPatrol - Action List - Cast'),
(@AirPatrol*100, 9, 10, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 50878, 0, 0, 0, 0, 0, 19, @Machine, 30, 0, 0, 0, 0, 0, '@AirPatrol - Action List - Cast'),
(@AirPatrol*100, 9, 11, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 50892, 0, 0, 0, 0, 0, 19, @Machine, 30, 0, 0, 0, 0, 0, '@AirPatrol - Action List - Cast'),
(@AirPatrol*100, 9, 12, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 50892, 0, 0, 0, 0, 0, 19, @Machine, 30, 0, 0, 0, 0, 0, '@AirPatrol - Action List - Cast'),
(@AirPatrol*100, 9, 13, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 50892, 0, 0, 0, 0, 0, 19, @Machine, 30, 0, 0, 0, 0, 0, '@AirPatrol - Action List - Cast'),
(@AirPatrol*100, 9, 14, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 50892, 0, 0, 0, 0, 0, 19, @Machine, 30, 0, 0, 0, 0, 0, '@AirPatrol - Action List - Cast'),
(@AirPatrol*100, 9, 15, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 50892, 0, 0, 0, 0, 0, 19, @Machine, 30, 0, 0, 0, 0, 0, '@AirPatrol - Action List - Cast'),
(@Machine, 0, 2, 0, 40, 0, 100, 0, 2, 0, 0, 0, 80, 27987*100, 2, 0, 0, 0, 0, 10, 103289, 27987, 0, 0, 0, 0, 0, '@Machine - On WP2 - Actionlist'),
(27987*100, 9, 0, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 21, 40, 0, 0, 0, 0, 0, 0, '27987 - Action List - talk'),
(@Machine, 0, 3, 0, 40, 0, 100, 0, 3, 0, 0, 0, 80, @Machine*100+2, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '@Machine - On spellHit - Actionlist'),
(@Machine*100+2, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 75, 61360, 0, 0, 0, 0, 0, 21, 10, 0, 0, 0, 0, 0, 0, '@Machine - Actionlist - Add parachute'),
(@Machine*100+2, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 50630, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '@Machine - Actionlist - Eject passenger'),
(27987, 0, 0, 1, 25, 0, 100, 0, 0, 0, 0, 0, 60, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, ' 27987 - On spawn - set fly on');
DELETE FROM `waypoints` WHERE `entry` IN(@Machine);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(@Machine, 1, 5478.141113, 4971.844238, -22.431667, 'Archimage Pentarus Flying Machine'),
(@Machine, 2, 5593.686035, 5187.787109, -72.69004, 'Archimage Pentarus Flying Machine'),
(@Machine, 3, 5647.750488, 5229.604004, -72.69004, 'Archimage Pentarus Flying Machine');
DELETE FROM `creature_text` WHERE `entry`in (@AirPatrol, 27987, @Machine, 28160);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextID`) VALUES
(28160,0,0, 'I''ll send you on my flying machine. Keep your eyes peeled for clues about what might''ve happened to Hemet!',12,0,100,25,0,0, 'Archmage Pentarus',27620),
(@AirPatrol,0,0, 'More intruders? You''ll soon learn, no one messes with the Venture Company!',14,0,100,0,0,0, 'Venture Co. Air Patrol',27611),
(27987,0,0, 'Over here, to the southeast. I see they got you too...',14,0,100,0,0,0, 'Monte Muzzleshot',27610),
(@Machine,0,0, 'WARNING: Missile lock detected. Engaging evasive maneuvers.',12,0,100,0,0,0, 'Archimage Pentarus Flying Machine',27621);
DELETE FROM `spell_target_position` WHERE `id` in (50987, 50859); 
INSERT INTO `spell_target_position` (`id`,`target_map`,`target_position_x`,`target_position_y`,`target_position_z`,`target_orientation`) VALUES
(50987, 571, 5071.35, 4642.54, 72.164, 0.878587),-- Teleport to Sholazar
(50859,571, 5832.892, 482.8708, 658.2753, 0.9121326);
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=@Machine;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(@Machine,46598,1,0);  -- Archmage Pentarus' Flying Machine - Ride Vehicle Hardcoded
DELETE FROM `creature_addon` WHERE `guid`=103289; -- Monte Muzzleshot
INSERT INTO `creature_addon` (`guid`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`)VALUES
(103289,0,0,1,0, '50544'); -- Monte Muzzleshot, aura: Cosmetic - Parachute Stuck
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10024;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,10024,0,0,28,12521,0,0,0,'','Show gossip option if player has quest Where in the World is Hemet Nesingwary?');
DELETE FROM `gossip_menu_option` WHERE `menu_id`=10024 AND `id`=1;
Delete from `conditions` where `SourceTypeOrReferenceId`=13 AND `SourceEntry`in (50878, 50892);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 50892, 0, 31, 3, @Machine, 0, 0, '', 'Only petrus flying machine is the target for the rockets'),
(13, 1, 50878, 0, 31, 3, @Machine, 0, 0, '', 'Only petrus flying machine is the target for the rockets');

UPDATE `creature_template` SET `DamageModifier`=5 WHERE  `entry`=28468;

