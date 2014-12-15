SET @Pentarus:=28160; -- Archmage Pentarus
SET @Machine:=28192;
SET @AirPatrol:=28229;
SET @MonteMuzzleshot:=27987;

SET @SPELL_MACHINE:=50860;  	-- Summon Machine 28192
SET @SPELL_PATROL:=51036; 		-- Summon Venture Co. Air Patrol 28229
SET @SPELL_FLIGHT:=50859;		-- Spell: Flight to Sholazar
SET @SPELL_TELEPORT:=50987;		-- Spell: Teleport to Sholazar
SET @SPELL_RIDE:=46598;			-- Spell: Ride Vehicle Hardcoded
SET @SPELL_PARACHUTE=61360;		-- Spell: Parachute (Aura)
SET @SPELL_EJECT=50630;			-- Spell: Eject all Passengers

SET @PORTAL_X:=5832.702637;
SET @PORTAL_Y:=436.761108;
SET @PORTAL_Z:=669.141174;
SET @PORTAL_O:=1.612513;

SET @TELE_ENTRY_X:=5071.356973; 
SET @TELE_ENTRY_Y:=4642.547471;
SET @TELE_ENTRY_Z:=72.164;
SET @TELE_ENTRY_O:=1.656960;

-- Force valid setup to creatures/objects
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=@Pentarus;
UPDATE `creature_template` SET `npcflag`=16777216,`InhabitType`=4,`AIName`='SmartAI',`VehicleId`=220 WHERE `entry`=@Machine;
UPDATE `creature_template` SET `InhabitType`=4,`AIName`='SmartAI'  WHERE `entry`=@AirPatrol;
UPDATE `creature_template` SET InhabitType=4,`AIName`='SmartAI' WHERE entry=@MonteMuzzleshot;
UPDATE `creature_template` SET `npcflag`=50331648,`unit_flags`=150994944,`dynamicflags`=8,`type`=9,`MovementType`=0,`speed_walk`=1.8660,`speed_run`=1.8660 WHERE `entry`=@Machine;
UPDATE `creature_template` SET `speed_walk`=2.8860,`speed_run`=2.8860 WHERE `entry`=@AirPatrol;

-- Cleanup records
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@Pentarus;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@Pentarus*100;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@Machine;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@Machine*100;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@Machine;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@Machine*100+1;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@Machine*100+2;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@AirPatrol;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@AirPatrol*100;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@MonteMuzzleshot*100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@MonteMuzzleshot AND `source_type`=0;

-- Archmage Pentarus SAI
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Pentarus,0,0,1,62,0,100,0,10024,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Archmage Pentarus - On Gossip Option 0 Selected - Close Gossip"),
(@Pentarus,0,1,2,61,0,100,0,10024,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Pentarus - On Gossip Option 0 Selected - Say Line 0"),
(@Pentarus,0,2,3,61,0,100,0,10024,0,0,0,50,190488,19,0,0,0,0,8,0,0,0,@PORTAL_X,@PORTAL_Y,@PORTAL_Z,@PORTAL_O,"Archmage Pentarus - On Gossip Option 0 Selected - Summon Gameobject 'Pentarus' Portal to Sholazar Basin'"),
(@Pentarus,0,3,0,61,0,100,0,10024,0,0,0,85,@SPELL_FLIGHT,0,0,0,0,0,7,0,0,0,0,0,0,0,"Archmage Pentarus - On Gossip Option 0 Selected - Invoker Cast 'Flight to Sholazar'");

-- Archmage Pentarus Flying Machine SAI
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Machine,0,0,1,54,0,100,0,0,0,0,0,60,1,1,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Pentarus' Flying Machine - On Just Summoned - Set Fly On"),
(@Machine,0,1,2,61,0,100,0,0,0,0,0,86,@SPELL_RIDE,2,22,0,0,0,23,0,0,0,0,0,0,0,"Archmage Pentarus' Flying Machine - On Just Summoned - Cross Cast 'Ride Vehicle Hardcoded'"),
(@Machine,0,2,0,61,0,100,0,0,0,0,0,69,1,0,0,0,0,0,8,0,0,0,@PORTAL_X,@PORTAL_Y,@PORTAL_Z,0.612513,"Archmage Pentarus' Flying Machine - On Just Summoned - Move To Position"),
(@Machine,0,3,4,34,0,100,0,0,1,0,0,11,@SPELL_TELEPORT,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Pentarus' Flying Machine - On Reached Point 1 - Cast 'Teleport to Sholazar'"),
(@Machine,0,4,5,61,0,100,0,0,1,0,0,97,2,0,0,0,0,0,8,0,0,0,@TELE_ENTRY_X,@TELE_ENTRY_Y,@TELE_ENTRY_Z,@TELE_ENTRY_O,"Archmage Pentarus' Flying Machine - On Reached Point 1 - Jump To Pos"),
(@Machine,0,5,0,61,0,100,0,0,1,0,0,53,1,28192,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Pentarus' Flying Machine - On Reached Point 1 - Start Waypoint"),
(@Machine,0,7,8,40,0,100,0,2,28192,0,0,11,@SPELL_PATROL,0,0,0,0,0,7,0,0,0,0,0,0,0,"Archmage Pentarus' Flying Machine - On Waypoint 2 Reached - Cast 'Summon Venture Co. Air Patrol'"),
(@Machine,0,8,0,61,0,100,0,2,28192,0,0,80,@MonteMuzzleshot*100,2,0,0,0,0,10,103289,27987,0,0,0,0,0,"Archmage Pentarus' Flying Machine - On Waypoint 2 Reached - Run Script"),
(@Machine,0,9,0,40,0,100,0,3,28192,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Pentarus' Flying Machine - On Waypoint 3 Reached - Say Line 0"),
(@Machine,0,10,11,40,0,100,0,6,28192,0,0,11,@SPELL_EJECT,0,0,0,0,0,7,0,0,0,0,0,0,0,"Archmage Pentarus' Flying Machine - On Waypoint 6 Reached - Cast 'Eject All Passengers'"),
(@Machine,0,11,0,61,0,100,0,6,28192,0,0,75,@SPELL_PARACHUTE,0,0,0,0,0,7,0,0,0,0,0,0,0,"Archmage Pentarus' Flying Machine - On Waypoint 6 Reached - Add Aura 'Parachute'");

-- Air Patrol SAI
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@AirPatrol,0,0,0,54,0,100,0,0,0,0,0,80,@AirPatrol*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'@AirPatrol - On spawn - Action List'),
(@AirPatrol*100,9,0,0,0,0,100,0,0,0,0,0,60,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'@AirPatrol - Action List - Set Fly ON'),
(@AirPatrol*100,9,1,0,0,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'@AirPatrol - Action List - Set react passif'),
(@AirPatrol*100,9,2,0,0,0,100,0,0,0,0,0,29,5,45,0,0,0,0,19,@Machine,60,0,0,0,0,0,'@AirPatrol - Action List - follow target'),
(@AirPatrol*100,9,3,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'@AirPatrol - Action List - Talk'),
(@AirPatrol*100,9,4,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,19,@Machine,30,0,0,0,0,0,'@AirPatrol - Action List - Talk'),
(@AirPatrol*100,9,5,0,0,0,100,0,5000,5000,0,0,11,50878,0,0,0,0,0,19,@Machine,30,0,0,0,0,0,'@AirPatrol - Action List - Cast'),
(@AirPatrol*100,9,6,0,0,0,100,0,2000,2000,0,0,11,50878,0,0,0,0,0,19,@Machine,30,0,0,0,0,0,'@AirPatrol - Action List - Cast'),
(@AirPatrol*100,9,7,0,0,0,100,0,2000,2000,0,0,11,50878,0,0,0,0,0,19,@Machine,30,0,0,0,0,0,'@AirPatrol - Action List - Cast'),
(@AirPatrol*100,9,8,0,0,0,100,0,2000,2000,0,0,11,50878,0,0,0,0,0,19,@Machine,30,0,0,0,0,0,'@AirPatrol - Action List - Cast'),
(@AirPatrol*100,9,9,0,0,0,100,0,2000,2000,0,0,11,50878,0,0,0,0,0,19,@Machine,30,0,0,0,0,0,'@AirPatrol - Action List - Cast'),
(@AirPatrol*100,9,10,0,0,0,100,0,2000,2000,0,0,11,50878,0,0,0,0,0,19,@Machine,30,0,0,0,0,0,'@AirPatrol - Action List - Cast'),
(@AirPatrol*100,9,11,0,0,0,100,0,2000,2000,0,0,11,50892,0,0,0,0,0,19,@Machine,30,0,0,0,0,0,'@AirPatrol - Action List - Cast'),
(@AirPatrol*100,9,12,0,0,0,100,0,2000,2000,0,0,11,50892,0,0,0,0,0,19,@Machine,30,0,0,0,0,0,'@AirPatrol - Action List - Cast'),
(@AirPatrol*100,9,13,0,0,0,100,0,2000,2000,0,0,11,50892,0,0,0,0,0,19,@Machine,30,0,0,0,0,0,'@AirPatrol - Action List - Cast'),
(@AirPatrol*100,9,14,0,0,0,100,0,2000,2000,0,0,11,50892,0,0,0,0,0,19,@Machine,30,0,0,0,0,0,'@AirPatrol - Action List - Cast'),
(@AirPatrol*100,9,15,0,0,0,100,0,2000,2000,0,0,11,50892,0,0,0,0,0,19,@Machine,30,0,0,0,0,0,'@AirPatrol - Action List - Cast');

-- Monte Muzzleshot SAI
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@MonteMuzzleshot,0,0,0,25,0,100,0,0,0,0,0,60,1,0,0,0,0,0,1,0,0,0,0,0,0,0,' @MonteMuzzleshot - On spawn - set fly on'),
(@MonteMuzzleshot*100,9,0,0,0,0,100,0,10000,10000,0,0,1,0,0,0,0,0,0,21,40,0,0,0,0,0,0,"Archmage Pentarus' Flying Machine - On Script - Say Line 0");

-- Waypoints for Archmage Pentarus Flying Machine (used for events too)
DELETE FROM `waypoints` WHERE `entry` IN(@Machine);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@Machine, 1, @TELE_ENTRY_X, @TELE_ENTRY_Y, @TELE_ENTRY_Z, 'Archimage Pentarus Flying Machine'),
(@Machine, 2, 5460.360840, 4747.393066, @TELE_ENTRY_Z, 'Archimage Pentarus Flying Machine'),
(@Machine, 3, 5478.141113, 4971.844238, @TELE_ENTRY_Z, 'Archimage Pentarus Flying Machine'),
(@Machine, 4, 5491.016113, 5010.193848, @TELE_ENTRY_Z, 'Archimage Pentarus Flying Machine'),
(@Machine, 5, 5593.686035, 5187.787109, @TELE_ENTRY_Z, 'Archimage Pentarus Flying Machine'),
(@Machine, 6, 5647.750488, 5229.604004, @TELE_ENTRY_Z, 'Archimage Pentarus Flying Machine');

-- Some texts for NPCs
DELETE FROM `creature_text` WHERE `entry`in (@AirPatrol,@MonteMuzzleshot,@Machine,@Pentarus);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextID`) VALUES
(@Pentarus,0,0,'I''ll send you on my flying machine. Keep your eyes peeled for clues about what might''ve happened to Hemet!',12,0,100,25,0,0,'Archmage Pentarus',27620),
(@AirPatrol,0,0,'More intruders? You''ll soon learn,no one messes with the Venture Company!',14,0,100,0,0,0,'Venture Co. Air Patrol',27611),
(@MonteMuzzleshot,0,0,'Over here,to the southeast. I see they got you too...',14,0,100,0,0,0,'Monte Muzzleshot',27610),
(@Machine,0,0,'WARNING: Missile lock detected. Engaging evasive maneuvers.',12,0,100,0,0,0,'Archimage Pentarus Flying Machine',27621);

-- Spell targets
DELETE FROM `spell_target_position` WHERE `id` in (@SPELL_TELEPORT,@SPELL_FLIGHT); 
INSERT INTO `spell_target_position` (`id`,`target_map`,`target_position_x`,`target_position_y`,`target_position_z`,`target_orientation`) VALUES
-- Teleport to Sholazar
(@SPELL_TELEPORT, 571, @TELE_ENTRY_X, @TELE_ENTRY_Y, @TELE_ENTRY_Z, @TELE_ENTRY_O),
-- Flight to Sholazar
(@SPELL_FLIGHT, 571, 5832.892, 482.8708, 658.2753, 0.9121326);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=@Machine;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(@Machine,46598,1,0);  -- Archmage Pentarus' Flying Machine - Ride Vehicle Hardcoded

DELETE FROM `creature_addon` WHERE `guid`=103289; -- Monte Muzzleshot
INSERT INTO `creature_addon` (`guid`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`)VALUES
(103289,0,0,1,0,'50544'); -- Monte Muzzleshot,aura: Cosmetic - Parachute Stuck

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10024;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,10024,0,0,28,12521,0,0,0,'','Show gossip option if player has quest Where in the World is Hemet Nesingwary?');

DELETE FROM `gossip_menu_option` WHERE `menu_id`=10024 AND `id`=1;
DELETE from `conditions` where `SourceTypeOrReferenceId`=13 AND `SourceEntry`in (50878,50892);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,50892,0,31,3,@Machine,0,0,'','Only petrus flying machine is the target for the rockets'),
(13,1,50878,0,31,3,@Machine,0,0,'','Only petrus flying machine is the target for the rockets');

UPDATE `creature_template` SET `DamageModifier`=5 WHERE  `entry`=28468;
