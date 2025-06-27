-- Support for 'The Soul Cannon of Reth'hedron'
-- Source: Sniffs & https://www.youtube.com/watch?v=OmVPTSE6eJ4
SET @CGUID := 86779; -- Need 1

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 8725;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,8725,0,0,0,9,0,11089,0,0,0,0,0,"","Group 0: Show Gossip Option 0 if player has taken quest 'The Soul Cannon of Reth'hedron'");

DELETE FROM `spell_target_position` WHERE `ID` = 40164;
INSERT INTO `spell_target_position` (`ID`,`EffectIndex`,`MapID`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`VerifiedBuild`) VALUES
(40164,0,530,-2466.6,4699.98,156.65,0,0);

DELETE FROM `event_scripts` WHERE `id` IN (/*14856,*/14857,14858,14859,14860);
INSERT INTO `event_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
-- (14856,6,10,23096,120000,0,-2482.2688,4661.7217,161.50037,0.94247), -- Acolyte of Air
(14857,6,10,23097,120000,0,-2443.984,4634.1143,158.27632,1.04719), -- Acolyte of Water
(14858,6,10,23098,120000,0,-2385.025,4552.593,165.76314,2.14675), -- Acolyte of Earth
(14859,6,10,23099,120000,0,-2425.9739,4444.5195,167.24365,1.88495), -- Acolyte of Fire
(14860,0,10,23100,120000,0,-2470.5989,4700.025,155.98538,3.15904); -- Flawless Arcane Elemental

-- Terokkar Trigger
UPDATE `creature` SET `orientation` = 4.64257 WHERE `guid` = 40263;
UPDATE `creature` SET `orientation` = 1.91986 WHERE `guid` = 40265;
UPDATE `creature` SET `position_x` = -2466.6154, `position_y` = 4699.977, `position_z` = 156.7335, `orientation` = 3.14159 WHERE `guid` = 40264;
UPDATE `creature` SET `spawntimesecs` = 300 WHERE `id` = 23102;

DELETE FROM `creature` WHERE `guid` = @CGUID+0 AND `id` = 23102;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`) VALUES
(@CGUID+0, 23102, 530, 1, 1, 0, -2384.9758, 4552.5883, 165.7732, 0.24434, 300, 0, 0);

-- Default values
UPDATE `creature_template` SET `unit_flags` = 256 WHERE `entry` = 23100;

-- Sar'this SAI
SET @ID := 23093;
UPDATE `creature_template` SET `AIName` = "SmartAI", `flags_extra` = `flags_extra`|512 WHERE `entry` = @ID;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` IN (23094,23096,23097,23098,23099,23100,23102);
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN @ID*100+0 AND @ID*100+10 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (23096,23097,23098,23099,23100,23102) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2310000 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,62,0,100,0,8725,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Gossip Option 0 Selected - Run Script"),
(@ID,0,1,0,40,0,100,0,6,0,0,0,80,@ID*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Waypoint 6 Reached - Run Script"),
(@ID,0,2,0,40,0,100,0,9,0,0,0,80,@ID*100+2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Waypoint 9 Reached - Run Script"),
(@ID,0,3,0,40,0,100,0,12,0,0,0,80,@ID*100+3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Waypoint 12 Reached - Run Script"),
(@ID,0,4,0,40,0,100,0,21,0,0,0,80,@ID*100+4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Waypoint 21 Reached - Run Script"),
(@ID,0,5,0,40,0,100,0,27,0,0,0,80,@ID*100+5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Waypoint 27 Reached - Run Script"),
(@ID,0,6,0,40,0,100,0,47,0,0,0,80,@ID*100+6,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Waypoint 47 Reached - Run Script"),
(@ID,0,7,0,40,0,100,0,48,0,0,0,80,@ID*100+7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Waypoint 48 Reached - Run Script"),
(@ID,0,8,0,38,0,100,0,0,1,0,0,80,@ID*100+8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Data Set 0 1 - Run Script"),
(@ID,0,9,0,82,0,100,0,0,0,0,0,80,@ID*100+9,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Summoned Unit Dies - Run Script"),
(@ID,0,10,0,59,0,100,0,1,0,0,0,80,@ID*100+10,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Timed Event - Run Script"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Sar'this - On Script - Store Targetlist"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,83,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Remove NPC Flags Gossip"),
(@ID*100+0,9,2,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Sar'this - On Script - Say Line 0"),
(@ID*100+0,9,3,0,0,0,100,0,2000,2000,0,0,53,0,23093,0,0,0,2,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Start Waypoint"),

(@ID*100+1,9,0,0,0,0,100,0,0,0,0,0,54,7000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Pause Waypoint"),
(@ID*100+1,9,1,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Say Line 1"),
(@ID*100+1,9,2,0,0,0,100,0,2000,2000,0,0,11,40164,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Cast 'Summon Fetish'"),

(@ID*100+2,9,0,0,0,0,100,0,0,0,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Pause Waypoint"),
(@ID*100+2,9,1,0,0,0,100,0,0,0,0,0,67,1,60000,60000,0,0,100,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Create Timed Event 1"),
(@ID*100+2,9,2,0,0,0,100,0,0,0,0,0,11,40129,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Cast 'Summon Air Elemental'"), -- 01:58:10.081
(@ID*100+2,9,3,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Sar'this - On Script - Say Line 2"), -- 01:58:10.206
-- Must be handled in event script 14856 (Spell 40129 Summon Air Elemental)
(@ID*100+2,9,4,0,0,0,100,0,3000,3000,0,0,86,40136,0,19,23102,15,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Cross Cast 'Lightning Cloud' (Terokkar Trigger)"), -- 01:58:13.185
(@ID*100+2,9,5,0,0,0,100,0,6000,6000,0,0,12,23096,4,120000,0,0,0,8,0,0,0,0,0,0,0,0,"Sar'this - On Script - Summon Creature 'Acolyte of Air'"),

(@ID*100+3,9,0,0,0,0,100,0,0,0,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Pause Waypoint"),
(@ID*100+3,9,1,0,0,0,100,0,0,0,0,0,67,1,60000,60000,0,0,100,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Create Timed Event 1"),
(@ID*100+3,9,2,0,0,0,100,0,0,0,0,0,11,40130,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Cast 'Summon Water Elemental'"), -- 01:58:36.601
(@ID*100+3,9,3,0,0,0,100,0,0,0,0,0,1,4,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Sar'this - On Script - Say Line 4"), -- 01:58:36.710
-- Must be handled in event script 14857 (Spell 40130 Summon Water Elemental)
(@ID*100+3,9,4,0,0,0,100,0,3000,3000,0,0,86,40141,0,19,23102,15,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Cross Cast 'Water Spout' (Terokkar Trigger)"), -- 01:58:39.581
(@ID*100+3,9,5,0,0,0,100,0,2000,2000,0,0,86,40141,0,19,23102,15,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Cross Cast 'Water Spout' (Terokkar Trigger)"), -- 01:58:41.453
(@ID*100+3,9,6,0,0,0,100,0,1000,1000,0,0,86,40141,0,19,23102,15,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Cross Cast 'Water Spout' (Terokkar Trigger)"), -- 01:58:42.623
(@ID*100+3,9,7,0,0,0,100,0,1000,1000,0,0,86,40141,0,19,23102,15,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Cross Cast 'Water Spout' (Terokkar Trigger)"), -- 01:58:43.730
(@ID*100+3,9,8,0,0,0,100,0,1000,1000,0,0,86,40141,0,19,23102,15,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Cross Cast 'Water Spout' (Terokkar Trigger)"), -- 01:58:45.041

(@ID*100+4,9,0,0,0,0,100,0,0,0,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Pause Waypoint"),
(@ID*100+4,9,1,0,0,0,100,0,0,0,0,0,67,1,60000,60000,0,0,100,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Create Timed Event 1"),
(@ID*100+4,9,2,0,0,0,100,0,0,0,0,0,11,40132,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Cast 'Summon Earth Elemental'"), -- 01:59:24.837
(@ID*100+4,9,3,0,0,0,100,0,0,0,0,0,1,5,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Sar'this - On Script - Say Line 5"), -- 01:59:24.899
-- Must be handled in event script 14858 (Spell 40132 Summon Earth Elemental)
(@ID*100+4,9,4,0,0,0,100,0,3000,3000,0,0,86,40147,0,19,23102,15,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Cross Cast 'Rock Torrent' (Terokkar Trigger)"), -- 01:59:27.832
(@ID*100+4,9,5,0,0,0,100,0,2000,2000,0,0,86,40147,0,19,23102,15,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Cross Cast 'Rock Torrent' (Terokkar Trigger)"), -- 01:59:30.016
(@ID*100+4,9,6,0,0,0,100,0,1000,1000,0,0,86,40147,0,19,23102,15,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Cross Cast 'Rock Torrent' (Terokkar Trigger)"), -- 01:59:31.233
(@ID*100+4,9,7,0,0,0,100,0,1000,1000,0,0,86,40147,0,19,23102,15,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Cross Cast 'Rock Torrent' (Terokkar Trigger)"), -- 01:59:32.450
(@ID*100+4,9,8,0,0,0,100,0,1000,1000,0,0,86,40147,0,19,23102,15,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Cross Cast 'Rock Torrent' (Terokkar Trigger)"), -- 01:59:33.635

(@ID*100+5,9,0,0,0,0,100,0,0,0,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Pause Waypoint"),
(@ID*100+5,9,1,0,0,0,100,0,0,0,0,0,67,1,60000,60000,0,0,100,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Create Timed Event 1"),
(@ID*100+5,9,2,0,0,0,100,0,0,0,0,0,11,40133,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Cast 'Summon Fire Elemental'"), -- 02:00:04.539
(@ID*100+5,9,3,0,0,0,100,0,0,0,0,0,1,6,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Sar'this - On Script - Say Line 6"), -- 02:00:04.695
-- Must be handled in event script 14859 (Spell 40133 Summon Fire Elemental)
(@ID*100+5,9,4,0,0,0,100,0,3000,3000,0,0,86,40148,0,11,23102,40,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Cross Cast 'Immolation' (Terokkar Trigger)"), -- 02:00:07.550
(@ID*100+5,9,5,0,0,0,100,0,0,0,0,0,45,0,1,0,0,0,0,11,23102,40,0,0,0,0,0,0,"Sar'this - On Script - Set Data 0 1 (Terokkar Trigger)"), -- 02:00:07.550

(@ID*100+6,9,0,0,0,0,100,0,0,0,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Pause Waypoint"),
(@ID*100+6,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,6.20857,"Sar'this - On Script - Set Orientation"),
(@ID*100+6,9,2,0,0,0,100,0,0,0,0,0,11,40134,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Cast 'Summon Arcane Elemental'"), -- 02:01:34.801
(@ID*100+6,9,3,0,0,0,100,0,0,0,0,0,1,7,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Sar'this - On Script - Say Line 7"), -- 02:01:34.895

(@ID*100+7,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,3.15904,"Sar'this - On Script - Set Orientation"),
(@ID*100+7,9,1,0,0,0,100,0,0,0,0,0,41,2000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Despawn (2000)"),

(@ID*100+8,9,0,0,0,0,100,0,0,0,0,0,65,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Resume Waypoint"),
(@ID*100+8,9,1,0,0,0,100,0,0,0,0,0,60,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Set Fly On"),

-- Called after player killed acolyte
(@ID*100+9,9,0,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Sar'this - On Script - Say Line 3"),
(@ID*100+9,9,1,0,0,0,100,0,0,0,0,0,74,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Remove Timed Event 1"),
(@ID*100+9,9,2,0,0,0,100,0,2000,2000,0,0,65,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Resume Waypoint"),

-- Called when player didn't killed the summoned acolyte after one minute
-- Despawns all summoned acolytes and evades minions
-- Probably it should evade only minions which moved to the event epilogue position
(@ID*100+10,9,0,0,0,0,100,0,0,0,0,0,45,0,1,0,0,0,0,11,23094,500,0,0,0,0,0,0,"Sar'this - On Script - Set Data 0 1 (Minion of Sar'this)"),
(@ID*100+10,9,1,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,19,23096,0,0,0,0,0,0,0,"Sar'this - On Script - Despawn (0) (Acolyte of Air)"),
(@ID*100+10,9,2,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,19,23097,0,0,0,0,0,0,0,"Sar'this - On Script - Despawn (0) (Acolyte of Water)"),
(@ID*100+10,9,3,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,19,23098,0,0,0,0,0,0,0,"Sar'this - On Script - Despawn (0) (Acolyte of Earth)"),
(@ID*100+10,9,4,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,19,23099,0,0,0,0,0,0,0,"Sar'this - On Script - Despawn (0) (Acolyte of Fire)"),
(@ID*100+10,9,5,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sar'this - On Script - Despawn (0)"),

-- Flawless Arcane Elemental
(23100,0,0,0,63,0,100,0,0,0,0,0,80,2310000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Flawless Arcane Elemental - On Just Created - Run Script"), -- 02:01:38.046
-- Reset involved creatures on death and if creature wasn't killed
(23100,0,1,2,1,0,100,1,60000,60000,0,0,92,0,0,0,0,0,0,11,23094,50,0,0,0,0,0,0,"Flawless Arcane Elemental - Out of Combat - Interrupt Spell (Minion of Sar'this) (No Repeat)"),
(23100,0,2,3,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,11,23094,50,0,0,0,0,0,0,"Flawless Arcane Elemental - On Link - Set Data 0 1 (Minion of Sar'this)"),
(23100,0,3,4,61,0,100,0,0,0,0,0,45,0,3,0,0,0,0,11,23102,50,0,0,0,0,0,0,"Flawless Arcane Elemental - On Link - Set Data 0 3 (Terokkar Trigger)"),
(23100,0,4,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Flawless Arcane Elemental - On Link - Despawn (0)"),

(23100,0,5,6,6,0,100,0,0,0,0,0,92,0,0,0,0,0,0,11,23094,50,0,0,0,0,0,0,"Flawless Arcane Elemental - On Death - Interrupt Spell (Minion of Sar'this)"),
(23100,0,6,7,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,11,23094,50,0,0,0,0,0,0,"Flawless Arcane Elemental - On Link - Set Data 0 1 (Minion of Sar'this)"),
(23100,0,7,8,61,0,100,0,0,0,0,0,45,0,3,0,0,0,0,11,23102,50,0,0,0,0,0,0,"Flawless Arcane Elemental - On Link - Set Data 0 3 (Terokkar Trigger)"),
(23100,0,8,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Flawless Arcane Elemental - On Link - Despawn (0)"),

(2310000,9,0,0,0,0,100,0,0,0,0,0,11,34166,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Flawless Arcane Elemental - On Script - Cast 'Coalesce'"), -- 02:01:38.046
(2310000,9,1,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,20,185856,0,0,0,0,0,0,0,"Flawless Arcane Elemental - On Script - Despawn 'Fetish of Sar'this'"), -- 02:01:38.436
(2310000,9,2,0,0,0,100,0,0,0,0,0,28,0,0,0,0,0,0,11,23094,50,0,0,0,0,0,0,"Flawless Arcane Elemental - On Script - Remove All Auras (Minion of Sar'this)"),
(2310000,9,3,0,0,0,100,0,1000,1000,0,0,45,0,2,0,0,0,0,19,23102,15,0,0,0,0,0,0,"Flawless Arcane Elemental - On Script - Set Data 0 2 (Terokkar Trigger)"), -- 02:01:39.622
(2310000,9,4,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Flawless Arcane Elemental - On Script - Say Line 0"), -- 02:01:40.495
(2310000,9,5,0,0,0,100,0,3000,3000,0,0,11,35519,0,0,0,0,0,19,23093,0,0,0,0,0,0,0,"Flawless Arcane Elemental - On Script - Cast 'White Beam'"), -- 02:01:43.615
(2310000,9,6,0,0,0,100,0,0,0,0,0,1,8,0,0,0,0,0,19,23093,0,0,0,0,0,0,0,"Flawless Arcane Elemental - On Script - Say Line 8 (Sar'this)"), -- 02:01:43.740
(2310000,9,7,0,0,0,100,0,0,0,0,0,45,0,1,0,0,0,0,19,23093,0,0,0,0,0,0,0,"Flawless Arcane Elemental - On Script - Set Data 0 1 (Sar'this)"), -- 02:01:44.426
(2310000,9,8,0,0,0,100,0,3000,3000,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Flawless Arcane Elemental - On Script - Remove Flag Immune To Players"), -- 02:01:47.203
(2310000,9,9,0,0,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,0,"Flawless Arcane Elemental - On Script - Start Attacking Closest Player"),

-- Acolytes
(23096,0,0,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,0,"Acolyte of Air - On Just Summoned - Start Attacking Closest Player"),
(23096,0,1,0,6,0,100,0,0,0,0,0,11,40156,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Acolyte of Air - On Death - Cast 'Essence of Wind'"),

(23097,0,0,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,0,"Acolyte of Water - On Just Summoned - Start Attacking Closest Player"),
(23097,0,1,0,6,0,100,0,0,0,0,0,11,40187,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Acolyte of Water - On Death - Cast 'Essence of Water'"),

(23098,0,0,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,0,"Acolyte of Earth - On Just Summoned - Start Attacking Closest Player"),
(23098,0,1,0,6,0,100,0,0,0,0,0,11,40189,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Acolyte of Earth - On Death - Cast 'Essence of Earth'"),

(23099,0,0,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,0,"Acolyte of Fire - On Just Summoned - Start Attacking Closest Player"),
(23099,0,1,0,6,0,100,0,0,0,0,0,11,40190,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Acolyte of Fire - On Death - Cast 'Essence of Fire'"),

(23102,0,0,0,11,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Terokkar Trigger - On Respawn - Set Run Off"),
(23102,0,1,0,38,0,100,0,0,1,0,0,69,1,0,0,0,0,0,8,0,0,0,0,-2425.9895,4444.47,167.17252,0,"Terokkar Trigger - On Data Set 0 1 - Move To Position"),
(23102,0,2,0,38,0,100,0,0,2,0,0,62,530,0,0,0,0,0,1,0,0,0,0,-2470.03,4700.03,161,0,"Terokkar Trigger - On Data Set 0 2 - Teleport To Position"),
(23102,0,3,0,38,0,100,0,0,3,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Terokkar Trigger - On Data Set 0 3 - Evade"),
(23102,0,4,0,34,0,100,0,8,1,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Terokkar Trigger - On Reached Point 1 - Despawn (0)");

DELETE FROM `creature_text` WHERE `CreatureID` IN (@ID,23100);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"So my blood was not a sufficient payment, eh? Fine, let us recover your arcane essence. After this, I owe Balthas nothing.",12,0,100,1,0,0,20913,0,"Sar'this"),
(@ID,1,0,"%s places a fetish at the ritual pile.",16,0,100,16,0,0,20914,0,"Sar'this"),
(@ID,2,0,"The process is arduous. We must first summon forth acolytes of the elements. You must then destroy these acolytes so that my minions can make preparations.",12,0,100,0,0,0,20915,0,"Sar'this"),
(@ID,3,0,"Well done!  Let's continue.",12,0,100,1,0,0,20916,0,"Sar'this"),
(@ID,4,0,"Prepare yourself! The acolyte of water is soon to come...",12,0,100,0,0,0,20917,0,"Sar'this"),
(@ID,5,0,"Come forth, acolyte of earth!",12,0,100,0,0,0,20918,0,"Sar'this"),
(@ID,6,0,"Fire, show yourself!",12,0,100,0,0,0,20919,0,"Sar'this"),
(@ID,7,0,"Now we call forth the arcane acolyte.",12,0,100,0,0,0,20920,0,"Sar'this"),
(@ID,8,0,"It is yours my Lord!",12,0,100,0,0,0,20971,0,"Sar'this"),
(23100,0,0,"I require your life essence to maintain my existence in this realm.",12,0,100,0,0,0,20970,0,"Flawless Arcane Elemental");

DELETE FROM `waypoints` WHERE `entry` = 23093;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(23093,1,-2528.15,4661.22,170.58,"Sar'this"),
(23093,2,-2520.11,4665.68,170.382,"Sar'this"),
(23093,3,-2501.86,4675.29,161.372,"Sar'this"),
(23093,4,-2487.58,4686.76,155.028,"Sar'this"),
(23093,5,-2474.83,4698.74,155.344,"Sar'this"),
(23093,6,-2474.83,4698.74,155.344,"Sar'this"),
(23093,7,-2480.65,4685.96,155.49,"Sar'this"),
(23093,8,-2481.49,4672.65,158.966,"Sar'this"),
(23093,9,-2480.16,4665.24,160.284,"Sar'this"),
(23093,10,-2455.65,4662.22,159.951,"Sar'this"),
(23093,11,-2436.2,4646.31,160.228,"Sar'this"),
(23093,12,-2439.97,4639.62,158.027,"Sar'this"),
(23093,13,-2436.58,4646.84,160.297,"Sar'this"),
(23093,14,-2425.2,4648.12,160.448,"Sar'this"),
(23093,15,-2411.43,4634.77,160.39,"Sar'this"),
(23093,16,-2407.81,4627.84,160.568,"Sar'this"),
(23093,17,-2415.99,4589.04,160.548,"Sar'this"),
(23093,18,-2399.42,4581.89,164.871,"Sar'this"),
(23093,19,-2391.28,4576.64,166.057,"Sar'this"),
(23093,20,-2388.56,4568.29,164.933,"Sar'this"),
(23093,21,-2388.36,4560.49,165.417,"Sar'this"),
(23093,22,-2393.32,4546.13,165.565,"Sar'this"),
(23093,23,-2409.52,4532.03,166.061,"Sar'this"),
(23093,24,-2422.16,4505.4,166.642,"Sar'this"),
(23093,25,-2424.31,4496.46,165.468,"Sar'this"),
(23093,26,-2428.53,4482.27,167.103,"Sar'this"),
(23093,27,-2429.68,4462.26,166.145,"Sar'this"),
(23093,28,-2429.66,4482.22,167.088,"Sar'this"),
(23093,29,-2424.99,4494.94,165.455,"Sar'this"),
(23093,30,-2416.78,4520.28,166.428,"Sar'this"),
(23093,31,-2408.74,4532.46,166.077,"Sar'this"),
(23093,32,-2391.15,4550.27,165.63,"Sar'this"),
(23093,33,-2390.8,4573.16,165.876,"Sar'this"),
(23093,34,-2397.56,4580.46,165.298,"Sar'this"),
(23093,35,-2403.85,4584.2,163.669,"Sar'this"),
(23093,36,-2410.81,4584.86,160.288,"Sar'this"),
(23093,37,-2415.9,4591.78,160.632,"Sar'this"),
(23093,38,-2408.04,4624.59,160.607,"Sar'this"),
(23093,39,-2410.98,4634.52,160.351,"Sar'this"),
(23093,40,-2428.67,4652.83,160.572,"Sar'this"),
(23093,41,-2441.28,4659.46,160.626,"Sar'this"),
(23093,42,-2463.44,4662.78,159.543,"Sar'this"),
(23093,43,-2472.09,4667.23,159.414,"Sar'this"),
(23093,44,-2479.66,4675.25,158.05,"Sar'this"),
(23093,45,-2479.86,4694.21,154.879,"Sar'this"),
(23093,46,-2478.81,4698.33,154.796,"Sar'this"),
(23093,47,-2475.14,4700.05,155.206,"Sar'this"),
(23093,48,-2470.6914,4700.032,160.24997,"Sar'this");

-- Minions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (40156,40187,40189,40190);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,40156,0,0,31,0,3,23094,96675,0,0,0,"","Group 0: Spell 'Essence of Wind' targets creature 'Minion of Sar'this'"),
(13,1,40187,0,0,31,0,3,23094,96676,0,0,0,"","Group 0: Spell 'Essence of Water' targets creature 'Minion of Sar'this'"),
(13,1,40189,0,0,31,0,3,23094,96677,0,0,0,"","Group 0: Spell 'Essence of Earth' targets creature 'Minion of Sar'this'"),
(13,1,40190,0,0,31,0,3,23094,96678,0,0,0,"","Group 0: Spell 'Essence of Fire' targets creature 'Minion of Sar'this'");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 23094 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23094,0,0,1,8,0,100,0,40156,0,0,0,127,0,300000,0,0,0,0,1,0,0,0,0,0,0,0,0,"Minion of Sar'this - On Spellhit 'Essence of Wind' - Pause Movement"),
(23094,0,1,0,61,0,100,0,0,0,0,0,69,1,0,0,0,0,0,8,0,0,0,0,-2473.62,4706.47,155.42299,4.54675,"Minion of Sar'this - On Link - Move To Position"),
(23094,0,2,0,34,0,100,0,8,1,0,0,11,40193,0,0,0,0,0,19,23102,15,0,0,0,0,0,0,"Minion of Sar'this - On Reached Point 1 - Cast 'White Beam'"),
(23094,0,3,4,8,0,100,0,40187,0,0,0,127,0,300000,0,0,0,0,1,0,0,0,0,0,0,0,0,"Minion of Sar'this - On Spellhit 'Essence of Water' - Pause Movement"),
(23094,0,4,0,61,0,100,0,0,0,0,0,69,2,0,0,0,0,0,8,0,0,0,0,-2476.07,4702.61,155.1288,1.33125,"Minion of Sar'this - On Link - Move To Position"),
(23094,0,5,0,34,0,100,0,8,2,0,0,11,40225,0,0,0,0,0,19,23102,15,0,0,0,0,0,0,"Minion of Sar'this - On Reached Point 2 - Cast 'Blue Beam'"),
(23094,0,6,7,8,0,100,0,40189,0,0,0,127,0,300000,0,0,0,0,1,0,0,0,0,0,0,0,0,"Minion of Sar'this - On Spellhit 'Essence of Earth' - Pause Movement"),
(23094,0,7,0,61,0,100,0,0,0,0,0,69,3,0,0,0,0,0,8,0,0,0,0,-2477.52,4696.75,155.09833,1.45414,"Minion of Sar'this - On Link - Move To Position"),
(23094,0,8,0,34,0,100,0,8,3,0,0,11,40227,0,0,0,0,0,19,23102,15,0,0,0,0,0,0,"Minion of Sar'this - On Reached Point 3 - Cast 'Green Beam'"),
(23094,0,9,10,8,0,100,0,40190,0,0,0,127,0,300000,0,0,0,0,1,0,0,0,0,0,0,0,0,"Minion of Sar'this - On Spellhit 'Essence of Fire' - Pause Movement"),
(23094,0,10,0,61,0,100,0,0,0,0,0,69,4,0,0,0,0,0,8,0,0,0,0,-2472.25,4694.06,155.88092,0.80424,"Minion of Sar'this - On Link - Move To Position"),
(23094,0,11,0,34,0,100,0,8,4,0,0,11,40228,0,0,0,0,0,19,23102,15,0,0,0,0,0,0,"Minion of Sar'this - On Reached Point 4 - Cast 'Red Beam'"),

(23094,0,12,0,38,0,100,0,0,1,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Minion of Sar'this - On Data Set 0 1 - Evade"),
-- Needed to resume paused waypoint
(23094,0,13,0,38,0,100,0,0,1,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Minion of Sar'this - On Data Set 0 1 - Reset All Scripts");
