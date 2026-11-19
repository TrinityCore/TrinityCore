-- Remove empty addons
DELETE FROM `creature_template_addon` WHERE `entry` IN (20864,20866,20867,20881,20883,20896,20897,20901,20902,20906,20978,21030,21346,21436,21437,21438,21439,21440,21702,21395);

-- Missing auras
UPDATE `creature_template_addon` SET `auras` = "21789" WHERE `entry` = 20865; -- Protean Horror
UPDATE `creature_template_addon` SET `auras` = "31261 11838 36716" WHERE `entry` = 20869; -- Arcatraz Sentinel
UPDATE `creature_template_addon` SET `auras` = "31261 11838 38828" WHERE `entry` = 21586; -- Arcatraz Sentinel
UPDATE `creature_template_addon` SET `auras` = "19818" WHERE `entry` = 20873; -- Negaton Warp-Master
UPDATE `creature_template_addon` SET `auras` = "36733" WHERE `entry` = 20875; -- Negaton Screamer
UPDATE `creature_template_addon` SET `auras` = "27987 36788" WHERE `entry` = 20880; -- Eredar Deathbringer
UPDATE `creature_template_addon` SET `auras` = "38844 38847" WHERE `entry` = 21594; -- Eredar Deathbringer
UPDATE `creature_template_addon` SET `auras` = "16380" WHERE `entry` = 20882; -- Skulking Witch
UPDATE `creature_template_addon` SET `auras` = "16380" WHERE `entry` = 21613; -- Skulking Witch
UPDATE `creature_template_addon` SET `auras` = "19818" WHERE `entry` = 20885; -- Dalliah the Doomsayer
UPDATE `creature_template_addon` SET `auras` = "19818" WHERE `entry` = 21590; -- Dalliah the Doomsayer
UPDATE `creature_template_addon` SET `auras` = "36051" WHERE `entry` = 20886; -- Wrath-Scryer Soccothrates
UPDATE `creature_template_addon` SET `auras` = "39007" WHERE `entry` = 21624; -- Wrath-Scryer Soccothrates
UPDATE `creature_template_addon` SET `auras` = "36120" WHERE `entry` = 21101; -- Unbound Void Zone
UPDATE `creature_template_addon` SET `auras` = "39003" WHERE `entry` = 21620; -- Unbound Void Zone

DELETE FROM `creature_template_addon` WHERE `entry` IN (21607,21605,21604,20879,21595,21603);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(21607,0,0,0,1,0,0,"21789"), -- Protean Horror
(21605,0,0,0,1,0,0,"19818"), -- Negaton Warp-Master
(21604,0,0,0,1,0,0,"36733"), -- Negaton Screamer
(20879,0,0,0,1,0,0,"36784"), -- Eredar Soul-Eater
(21595,0,0,0,1,0,0,"36784"), -- Eredar Soul-Eater
(21603,0,0,0,1,0,0,"38833"); -- Negaton Field

-- Add CREATURE_FLAG_EXTRA_NO_COMBAT to all creatures in instance with that flag in CreatureDifficulty
UPDATE `creature_template` SET `flags_extra` = `flags_extra` | 0x00002000 WHERE `entry` IN (20978,21030,21101,21186,21290,21414,21436,21437,21438,21439,21440,21584,21603,21620,21625,21761);

-- Update levels & flags of Arcane Explosion from CreatureDifficulty. For some reason create object packet is not sent
UPDATE `creature_template` SET `minlevel` = 72, `maxlevel` = 72, `unit_flags` = 256 + 33554432 WHERE `entry` IN (21290,21584);

-- Intro event
-- Whole event should be sniffed again because the warders seems to be overpowered and positions, waypoints
-- and actions of temp summons may be incomplete & slighly incorrect. Spawn rates too may be wrong

-- Arcane Explosion SAI
SET @ID := 21290;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,1,54,0,100,0,0,0,0,0,0,11,36514,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Arcane Explosion - On Just Summoned - Cast 'Energy'"),
(@ID,0,1,0,61,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Arcane Explosion - On Link - Despawn Instant");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 36514;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,36514,0,0,31,0,3,20864,0,0,0,0,"","Group 0: Spell 'Energy' (Effect 0) targets creature 'Protean Nightmare'"),
(13,1,36514,0,1,31,0,3,20865,0,0,0,0,"","Group 1: Spell 'Energy' (Effect 0) targets creature 'Protean Horror'");

-- Arcatraz Defender
-- Seems like they should not use spell Infected Blood, not shown in sniffs & videos
UPDATE `creature_template` SET `AIName` = "" WHERE `entry` = 20857;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 20857 AND `source_type` = 0;
-- Fix sheath state
UPDATE `creature_template_addon` SET `bytes2` = 1 WHERE `entry` IN (20857,21585);
-- Add conditions for Protean Subdual spells
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 17 AND `SourceEntry` IN (36288,40449);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,36288,0,0,31,1,3,20864,0,0,0,0,"","Group 0: Spell 'Protean Subdual' (Effect 0) targets creature 'Protean Nightmare'"),
(17,0,36288,0,1,31,1,3,20865,0,0,0,0,"","Group 1: Spell 'Protean Subdual' (Effect 0) targets creature 'Protean Horror'"),
(17,0,40449,0,0,31,1,3,20864,0,0,0,0,"","Group 0: Spell 'Protean Subdual' (Effect 0) targets creature 'Protean Nightmare'"),
(17,0,40449,0,1,31,1,3,20865,0,0,0,0,"","Group 1: Spell 'Protean Subdual' (Effect 0) targets creature 'Protean Horror'");

-- Arcatraz Warder SAI
SET @ID := 20859;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,1,0,100,0,0,20000,5000,20000,0,11,36327,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Arcatraz Warder - Out of Combat - Cast 'Shoot Arcane Explosion Arrow'"),
(@ID,0,1,0,1,0,100,0,20000,25000,20000,25000,0,11,36293,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Arcatraz Warder - Out of Combat - Cast 'Arcane Shot'"),
(@ID,0,2,0,0,0,100,2,0,0,2000,3000,0,11,15620,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Arcatraz Warder - In Combat CMC - Cast 'Shoot' (Normal Dungeon)"),
(@ID,0,3,0,0,0,100,4,0,0,2000,3000,0,11,22907,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Arcatraz Warder - In Combat CMC - Cast 'Shoot' (Heroic Dungeon)"),
(@ID,0,4,0,0,0,100,2,5000,10000,7000,10000,0,11,36609,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Arcatraz Warder - In Combat CMC - Cast 'Arcane Shoot' (Normal Dungeon)"),
(@ID,0,5,0,0,0,100,4,5000,10000,7000,10000,0,11,38807,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Arcatraz Warder - In Combat CMC - Cast 'Arcane Shoot' (Heroic Dungeon)");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 36293;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 20859 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,36293,0,0,31,0,3,20864,0,0,0,0,"","Group 0: Spell 'Arcane Shot' (Effect 0) targets creature 'Protean Nightmare'"),
(13,1,36293,0,1,31,0,3,20865,0,0,0,0,"","Group 1: Spell 'Arcane Shot' (Effect 0) targets creature 'Protean Horror'"),
(22,1,20859,0,0,29,1,20864,50,0,0,0,0,"","Group 0: Execute SAI (Action 0) if alive creature 'Protean Nightmare' is within 50 yards"),
(22,1,20859,0,1,29,1,20865,50,0,0,0,0,"","Group 1: Execute SAI (Action 0) if alive creature 'Protean Horror' is within 50 yards"),
(22,2,20859,0,0,29,1,20864,50,0,0,0,0,"","Group 0: Execute SAI (Action 1) if alive creature 'Protean Nightmare' is within 50 yards"),
(22,2,20859,0,1,29,1,20865,50,0,0,0,0,"","Group 1: Execute SAI (Action 1) if alive creature 'Protean Horror' is within 50 yards");

-- 36327 (Shoot Arcane Explosion Arrow) triggers 36521 (Summon Arcane Explosion), Arcane Explosion casts 36514 and deals 50000 damage
DELETE FROM `spell_scripts` WHERE `id` = 36327;
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`,`Comment`) VALUES
(36327,0,0,15,36521,2,0,0,0,0,0,"Shoot Arcane Explosion Arrow - On Effect Hit (Dummy) - Target Cast 'Summon Arcane Explosion'");

-- Protean Nightmare SAI (ACID)
SET @ID := 20864;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID*100+0 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,2,16900,17600,19300,26500,0,11,36617,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Protean Nightmare - In Combat - Cast 'Gaping Maw' (Normal Dungeon)"),
(@ID,0,1,0,0,0,100,4,16900,17600,19300,26500,0,11,38810,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Protean Nightmare - In Combat - Cast 'Gaping Maw' (Heroic Dungeon)"),
(@ID,0,2,0,0,0,100,2,22900,26300,10800,22900,0,11,36619,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Protean Nightmare - In Combat - Cast 'Infectious Poison (Normal Dungeon)"),
(@ID,0,3,0,0,0,100,4,22900,26300,10800,22900,0,11,38811,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Protean Nightmare - In Combat - Cast 'Infectious Poison (Heroic Dungeon)"),
(@ID,0,4,0,0,0,100,0,15200,21700,10900,22900,0,11,36622,32,0,0,0,0,5,0,0,0,0,0,0,0,0,"Protean Nightmare - In Combat - Cast 'Incubation'"),
(@ID,0,5,0,54,0,100,0,0,0,0,0,0,80,2086400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Protean Nightmare - On Just Summoned - Run Script"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,116,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Protean Nightmare - On Script - Set Corpse Delay"),
(@ID*100+0,9,1,0,0,0,100,0,2000,2000,0,0,0,53,1,20864,0,0,0,2,1,0,0,0,0,0,0,0,0,"Protean Nightmare - On Script - Start Waypoint");

-- Protean Horror SAI
SET @ID := 20865;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID*100+0 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,5000,15000,10000,15000,0,11,36612,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Protean Horror - In Combat - Cast 'Toothy Bite'"),
(@ID,0,1,0,54,0,100,0,0,0,0,0,0,80,2086500,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Protean Horror - On Just Summoned - Run Script"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,116,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Protean Horror - On Script - Set Corpse Delay"),
(@ID*100+0,9,1,0,0,0,100,0,2000,2000,0,0,0,53,0,20865,0,0,0,2,1,0,0,0,0,0,0,0,0,"Protean Horror - On Script - Start Waypoint");

-- May be incomplete or may be assigned to unique spawn and not to all of them
DELETE FROM `waypoints` WHERE `entry` IN (20864,20865);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(20864,1,171.48091,-0.35282707,-10.107819,0,0,"Protean Nightmare"),
(20864,2,147.41817,0.380315,-10.101913,0,0,"Protean Nightmare"),
(20864,3,118.42155,0.256821,-10.136737,0,0,"Protean Nightmare"),
(20864,4,107.80615,1.4212953,-10.160327,0,0,"Protean Nightmare"),
(20865,1,174.29192,0.464094,-10.101754,0,0,"Protean Horror"),
(20865,2,157.84132,0.62546,-10.102133,0,0,"Protean Horror"),
(20865,3,140.85771,0.796949,-10.101937,0,0,"Protean Horror"),
(20865,4,123.21317,0.05694,-10.102104,0,0,"Protean Horror"),
(20865,5,88.4931,0.287307,-11.026913,0,0,"Protean Horror");

-- Arcane Warder Target
-- Better to move it to instance script
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-79409) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 2118600 AND 2118604 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-79409,0,0,0,1,0,100,0,0,0,3000,3000,0,87,2118600,2118604,0,0,0,0,1,0,0,0,0,0,0,0,0,"Arcane Warder Target - Out of Combat - Run Random Script"),
(-79409,0,1,0,1,0,100,0,0,0,20000,20000,0,12,20864,4,60000,0,0,0,8,0,0,0,0,184.87,-9.74919,-10.105,2.11241,"Arcane Warder Target - Out of Combat - Summon Creature 'Protean Nightmare'"),

(2118600,9,0,0,0,0,100,0,0,0,0,0,0,12,20865,4,60000,0,0,0,8,0,0,0,0,176.218,-8.04078,-10.0188,4.01426,"Arcane Warder Target - On Script - Summon Creature 'Protean Horror'"),
(2118601,9,0,0,0,0,100,0,0,0,0,0,0,12,20865,4,60000,0,0,0,8,0,0,0,0,191.813,-17.5303,-10.0188,3.28122,"Arcane Warder Target - On Script - Summon Creature 'Protean Horror'"),
(2118602,9,0,0,0,0,100,0,0,0,0,0,0,12,20865,4,60000,0,0,0,8,0,0,0,0,182.292,-18.7345,-10.0594,1.96563,"Arcane Warder Target - On Script - Summon Creature 'Protean Horror'"),
(2118603,9,0,0,0,0,100,0,0,0,0,0,0,12,20865,4,60000,0,0,0,8,0,0,0,0,182.746,18.8279,-10.0725,3.41135,"Arcane Warder Target - On Script - Summon Creature 'Protean Horror'"),
(2118604,9,0,0,0,0,100,0,0,0,0,0,0,12,20865,4,60000,0,0,0,8,0,0,0,0,189.86,12.663,-10.0084,3.03687,"Arcane Warder Target - On Script - Summon Creature 'Protean Horror'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` IN (-79409) AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
-- Not sure but seems like Protean Horrors are summoned only if at least one Arcatraz Warder is alive
(22,1,-79409,0,0,29,1,20859,100,0,0,0,0,"","Group 0: Execute SAI (Action 0) if alive creature 'Arcatraz Warder' is within 100 yards"),
-- Not sure but seems like Protean Nightmares are summoned only if at least one Arcatraz Defender is alive
(22,2,-79409,0,0,29,1,20857,100,0,0,0,0,"","Group 0: Execute SAI (Action 1) if alive creature 'Arcatraz Defender' is within 100 yards");

-- Other creatures

-- Sightless Eye SAI
-- Despawns if owner dies
SET @ID := 21346;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(21346,0,0,0,0,0,100,2,0,0,1000,3000,0,11,36646,32,0,0,0,0,2,0,0,0,0,0,0,0,0,"Sightless Eye - In Combat - Cast 'Sightless Touch' (Normal Dungeon)"),
(21346,0,1,0,0,0,100,4,0,0,1000,3000,0,11,38815,32,0,0,0,0,2,0,0,0,0,0,0,0,0,"Sightless Eye - In Combat - Cast 'Sightless Touch' (Heroic Dungeon)");

-- Soul Devourer SAI
SET @ID := 20866;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,10000,15000,15000,20000,0,11,33958,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Soul Devourer - In Combat - Cast 'Enrage'"),
(@ID,0,1,0,0,0,100,0,5000,15000,25000,25000,0,11,36644,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Soul Devourer - In Combat - Cast 'Sightless Eye'"),
(@ID,0,2,0,0,0,100,2,15000,20000,15000,20000,0,11,36654,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Soul Devourer - In Combat - Cast 'Fel Breath' (Normal Dungeon)"),
(@ID,0,3,0,0,0,100,4,15000,20000,15000,20000,0,11,38813,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Soul Devourer - In Combat - Cast 'Fel Breath' (Heroic Dungeon)");

-- Death Watcher SAI
SET @ID := 20867;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,2,5000,10000,10000,15000,0,11,36664,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Death Watcher - In Combat - Cast 'Tentacle Cleave' (Normal Dungeon)"),
(@ID,0,1,0,0,0,100,4,5000,10000,10000,15000,0,11,38816,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Death Watcher - In Combat - Cast 'Tentacle Cleave' (Heroic Dungeon)"),
(@ID,0,2,0,2,0,100,2,0,70,15000,15000,0,11,36655,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Death Watcher - Between 0-70% Health - Cast 'Drain Life' (Normal Dungeon)"),
(@ID,0,3,0,2,0,100,4,0,70,15000,15000,0,11,38817,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Death Watcher - Between 0-70% Health - Cast 'Drain Life' (Heroic Dungeon)"),
(@ID,0,4,0,2,0,100,3,0,50,0,0,0,11,36657,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Death Watcher - Between 0-50% Health - Cast 'Death Count' (Normal Dungeon) (No Repeat)"),
(@ID,0,5,0,2,0,100,5,0,50,0,0,0,11,38818,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Death Watcher - Between 0-50% Health - Cast 'Death Count' (Heroic Dungeon) (No Repeat)"),
(@ID,0,6,0,6,0,100,2,0,0,0,0,0,11,36660,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Death Watcher - On Death - Cast 'Death Count' (Normal Dungeon)"),
(@ID,0,7,0,6,0,100,4,0,0,0,0,0,11,38820,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Death Watcher - On Death - Cast 'Death Count' (Heroic Dungeon)"),
-- Should be replaced by scripts for auras above
(@ID,0,8,0,6,0,100,2,0,0,0,0,0,28,36657,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Death Watcher - On Death - Remove Aura 'Death Count' (Normal Dungeon)"),
(@ID,0,9,0,6,0,100,4,0,0,0,0,0,28,38818,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Death Watcher - On Death - Remove Aura 'Death Count' (Heroic Dungeon)");

-- Entropic Eye SAI
SET @ID := 20868;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,5000,10000,10000,10000,0,11,36677,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Entropic Eye - In Combat - Cast 'Chaos Breath'"),
(@ID,0,1,0,0,0,100,2,5000,10000,10000,15000,0,11,36664,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Entropic Eye - In Combat - Cast 'Tentacle Cleave' (Normal Dungeon)"),
(@ID,0,2,0,0,0,100,4,5000,10000,10000,15000,0,11,38816,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Entropic Eye - In Combat - Cast 'Tentacle Cleave' (Heroic Dungeon)");

-- Arcatraz Sentinel SAI
-- HP should be changed to 60% of total HP / 46107 in normal / 62315 in heroic
SET @ID := 20869;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- There should be another way to make them aggro. Calling start attack on fixed distance LoS
-- is not correct because they follows generic aggro rules, high level characters can avoid them
(@ID,0,0,1,10,0,100,1,0,15,0,0,1,28,31261,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Arcatraz Sentinel - Within 0-15 Range Out of Combat LoS - Remove Aura 'Permanent Feign Death (Root)'"),
(@ID,0,1,0,61,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,21,20,0,0,0,0,0,0,0,"Arcatraz Sentinel - On Link - Start Attack"),
(@ID,0,2,0,2,0,100,1,0,10,0,0,0,11,36719,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Arcatraz Sentinel - Between 0-10% Health - Cast 'Explode' (No Repeat)"),
(@ID,0,3,0,6,0,100,0,0,0,0,0,0,11,37394,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Arcatraz Sentinel - On Death - Cast 'Summon Destroyed Sentinel'");

-- Negaton Warp-Master SAI
SET @ID := 20873;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,1,0,0,100,0,15000,22000,15000,22000,0,11,36813,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Negaton Warp-Master - In Combat - Cast 'Summon Negaton Field'"),
(@ID,0,1,0,61,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Negaton Warp-Master - On Link - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"Void energy gathers at the base of the %s!",16,0,100,0,0,0,19392,0,"Negaton Warp-Master");

-- Eredar Soul-Eater SAI
SET @ID := 20879;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,2,9000,12000,15000,17000,0,11,36786,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Eredar Soul-Eater - In Combat - Cast 'Soul Chill' (Normal Dungeon)"),
(@ID,0,1,0,0,0,100,4,9000,12000,15000,17000,0,11,38843,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Eredar Soul-Eater - In Combat - Cast 'Soul Chill' (Heroic Dungeon)"),
(@ID,0,2,0,0,0,100,0,15000,17000,14000,21000,0,11,36778,32,0,0,0,0,2,0,0,0,0,0,0,0,0,"Eredar Soul-Eater - In Combat - Cast 'Soul Steal'"),
(@ID,0,3,0,31,0,100,0,36778,0,0,0,0,11,36782,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Eredar Soul-Eater - On Target Spellhit 'Soul Steal' - Cast 'Soul Steal'");

-- Eredar Deathbringer SAI
SET @ID := 20880;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,2,8000,11000,10000,16000,0,11,36787,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Eredar Deathbringer - In Combat - Cast 'Forceful Cleave' (Normal Dungeon)"),
(@ID,0,1,0,0,0,100,4,8000,11000,10000,16000,0,11,38846,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Eredar Deathbringer - In Combat - Cast 'Forceful Cleave' (Heroic Dungeon)");

-- Unbound Devastator SAI
SET @ID := 20881;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,2,3000,7000,17000,24000,0,11,36887,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Unbound Devastator - In Combat - Cast 'Deafening Roar' (Normal Dungeon)"),
(@ID,0,1,0,0,0,100,4,3000,7000,17000,24000,0,11,38850,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Unbound Devastator - In Combat - Cast 'Deafening Roar' (Heroic Dungeon)"),
(@ID,0,2,0,0,0,100,2,10000,17000,27000,35000,0,11,36891,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Unbound Devastator - In Combat - Cast 'Devastate' (Normal Dungeon)"),
(@ID,0,3,0,0,0,100,4,10000,17000,27000,35000,0,11,38849,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Unbound Devastator - In Combat - Cast 'Devastate' (Heroic Dungeon)");

-- Skulking Witch SAI
SET @ID := 20882;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN @ID*100+0 AND @ID*100+3 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,10000,15000,10000,15000,0,11,36862,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Skulking Witch - In Combat - Cast 'Gouge'"),
(@ID,0,1,0,0,0,100,2,2000,5000,8000,11000,0,87,@ID*100+0,@ID*100+2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Skulking Witch - In Combat - Run Random Script (Normal Dungeon)"),
(@ID,0,2,0,0,0,100,4,2000,5000,8000,11000,0,87,@ID*100+1,@ID*100+3,0,0,0,0,1,0,0,0,0,0,0,0,0,"Skulking Witch - In Combat - Run Random Script (Heroic Dungeon)"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,11,36863,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Skulking Witch - On Script - Cast 'Chastise'"),
(@ID*100+1,9,0,0,0,0,100,0,0,0,0,0,0,11,38851,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Skulking Witch - On Script - Cast 'Chastise'"),
(@ID*100+2,9,0,0,0,0,100,0,0,0,0,0,0,11,36864,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Skulking Witch - On Script - Cast 'Lash of Pain'"),
(@ID*100+3,9,0,0,0,0,100,0,0,0,0,0,0,11,38852,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Skulking Witch - On Script - Cast 'Lash of Pain'");

-- Spiteful Temptress SAI
SET @ID := 20883;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,10000,15000,17000,25000,0,11,36866,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Spiteful Temptress - In Combat - Cast 'Domination'"),
(@ID,0,1,0,0,0,100,0,6000,11000,14000,17000,0,11,36886,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Spiteful Temptress - In Combat - Cast 'Spiteful Fury'"),
(@ID,0,2,0,0,0,100,2,8000,15000,10000,15000,0,11,36868,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Spiteful Temptress - In Combat - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ID,0,3,0,0,0,100,4,8000,15000,10000,15000,0,11,38892,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Spiteful Temptress - In Combat - Cast 'Shadow Bolt' (Heroic Dungeon)");

-- Ethereum Slayer SAI
SET @ID := 20896;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,8000,15000,20000,25000,0,11,15087,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ethereum Slayer - In Combat - Cast 'Evasion'"),
(@ID,0,1,0,0,0,100,0,5000,10000,8000,13000,0,11,36839,32,0,0,0,0,2,0,0,0,0,0,0,0,0,"Ethereum Slayer - In Combat - Cast 'Impairing Poison'"),
(@ID,0,2,0,0,0,100,2,10000,15000,10000,15000,0,11,36838,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Ethereum Slayer - In Combat - Cast 'Slaying Strike' (Normal Dungeon)"),
(@ID,0,3,0,0,0,100,4,10000,15000,10000,15000,0,11,38894,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Ethereum Slayer - In Combat - Cast 'Slaying Strike' (Heroic Dungeon)");

-- Ethereum Wave-Caster SAI
SET @ID := 20897;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,2,10000,15000,19000,25000,0,11,36840,32,0,0,0,0,6,0,0,0,0,0,0,0,0,"Ethereum Wave-Caster - In Combat - Cast 'Polymorph' (Normal Dungeon)"),
(@ID,0,1,0,0,0,100,4,10000,15000,14000,21000,0,11,38896,32,0,0,0,0,6,0,0,0,0,0,0,0,0,"Ethereum Wave-Caster - In Combat - Cast 'Polymorph' (Heroic Dungeon)"),
(@ID,0,2,0,0,0,100,0,10000,20000,10000,20000,0,11,32693,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ethereum Wave-Caster - In Combat - Cast 'Arcane Haste'"),
(@ID,0,3,0,0,0,100,0,15000,19000,15000,19000,0,11,38897,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Ethereum Wave-Caster - In Combat - Cast 'Sonic Boom'");

-- Gargantuan Abyssal SAI
SET @ID := 20898;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,2,4000,6000,10000,12000,0,11,38855,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gargantuan Abyssal - In Combat - Cast 'Fire Shield' (Normal Dungeon)"),
(@ID,0,1,0,0,0,100,4,4000,6000,10000,12000,0,11,38901,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gargantuan Abyssal - In Combat - Cast 'Fire Shield' (Heroic Dungeon)"),
(@ID,0,2,0,0,0,100,2,7000,9000,12000,17000,0,11,36837,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Gargantuan Abyssal - In Combat - Cast 'Meteor' (Normal Dungeon)"),
(@ID,0,3,0,0,0,100,4,7000,9000,12000,17000,0,11,38903,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Gargantuan Abyssal - In Combat - Cast 'Meteor' (Heroic Dungeon)");

-- Unchained Doombringer SAI
SET @ID := 20900;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,2,12000,15000,24000,27000,0,11,36835,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Unchained Doombringer - In Combat - Cast 'War Stomp' (Normal Dungeon)"),
(@ID,0,1,0,0,0,100,4,12000,15000,24000,27000,0,11,38911,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Unchained Doombringer - In Combat - Cast 'War Stomp' (Heroic Dungeon)"),
(@ID,0,2,0,0,0,100,0,10000,13000,23000,30000,0,11,36833,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Unchained Doombringer - In Combat - Cast 'Berserker Charge'"),
(@ID,0,3,0,0,0,100,0,7000,9000,13000,16000,0,11,36836,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Unchained Doombringer - In Combat - Cast 'Agonizing Armor'");

-- Sargeron Archer SAI
SET @ID := 20901;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN @ID*100+0 AND @ID*100+5 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,2,0,0,2400,4800,0,11,22907,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Sargeron Archer - In Combat CMC - Cast 'Shoot' (Normal Dungeon)"),
(@ID,0,1,0,0,0,100,4,0,0,2400,4800,0,11,38940,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Sargeron Archer - In Combat CMC - Cast 'Shoot' (Heroic Dungeon)"),
(@ID,0,2,0,0,0,100,2,12000,18000,15000,20000,0,11,36827,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Sargeron Archer - In Combat - Cast 'Hooked Net' (Normal Dungeon)"),
(@ID,0,3,0,0,0,100,4,12000,18000,15000,20000,0,11,38912,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Sargeron Archer - In Combat - Cast 'Hooked Net' (Heroic Dungeon)"),
(@ID,0,4,0,0,0,100,2,12000,15000,17000,23000,0,87,@ID*100+0,@ID*100+2,@ID*100+4,0,0,0,1,0,0,0,0,0,0,0,0,"Sargeron Archer - In Combat - Run Random Script (Normal Dungeon)"),
(@ID,0,5,0,0,0,100,4,12000,15000,17000,23000,0,87,@ID*100+1,@ID*100+3,@ID*100+5,0,0,0,1,0,0,0,0,0,0,0,0,"Sargeron Archer - In Combat - Run Random Script (Heroic Dungeon)"),
(@ID,0,6,0,0,0,100,0,13000,16000,18000,22000,0,11,23601,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Sargeron Archer - In Combat - Cast 'Scatter Shot'"),
(@ID,0,7,0,2,0,100,0,0,30,23000,30000,0,11,36828,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sargeron Archer - Between 0-30% Health - Cast 'Rapid Fire'"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,11,35964,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Sargeron Archer - On Script - Cast 'Frost Arrow' (Normal Dungeon)"),
(@ID*100+1,9,0,0,0,0,100,0,0,0,0,0,0,11,38942,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Sargeron Archer - On Script - Cast 'Frost Arrow' (Heroic Dungeon)"),
(@ID*100+2,9,0,0,0,0,100,0,0,0,0,0,0,11,35932,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Sargeron Archer - On Script - Cast 'Immolation Arrow' (Normal Dungeon)"),
(@ID*100+3,9,0,0,0,0,100,0,0,0,0,0,0,11,38943,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Sargeron Archer - On Script - Cast 'Immolation Arrow' (Heroic Dungeon)"),
(@ID*100+4,9,0,0,0,0,100,0,0,0,0,0,0,11,36984,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Sargeron Archer - On Script - Cast 'Serpent Sting' (Normal Dungeon)"),
(@ID*100+5,9,0,0,0,0,100,0,0,0,0,0,0,11,38914,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Sargeron Archer - On Script - Cast 'Serpent Sting' (Heroic Dungeon)");

-- Sargeron Hellcaller SAI
SET @ID := 20902;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,2,7000,10000,13000,20000,0,11,36829,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Sargeron Hellcaller - In Combat - Cast 'Hell Rain' (Normal Dungeon)"),
(@ID,0,1,0,0,0,100,4,7000,10000,13000,20000,0,11,38917,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Sargeron Hellcaller - In Combat - Cast 'Hell Rain' (Heroic Dungeon)"),
(@ID,0,2,0,0,0,100,2,8000,13000,11000,15000,0,11,36832,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Sargeron Hellcaller - In Combat - Cast 'Incinerate' (Normal Dungeon)"),
(@ID,0,3,0,0,0,100,4,8000,13000,11000,15000,0,11,38918,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Sargeron Hellcaller - In Combat - Cast 'Incinerate' (Heroic Dungeon)"),
(@ID,0,4,0,0,0,100,0,7000,10000,16000,21000,0,11,36831,32,0,0,0,0,5,0,0,0,0,0,0,0,0,"Sargeron Hellcaller - In Combat - Cast 'Curse of the Elements'");

-- Protean Spawn SAI
SET @ID := 21395;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,1,54,0,100,0,0,0,0,0,0,11,36588,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Protean Spawn - On Just Summoned - Cast 'Bloody Explosion'"),
(@ID,0,1,0,61,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,21,20,0,0,0,0,0,0,0,"Protean Spawn - On Link - Start Attack"),
(@ID,0,2,0,0,0,100,0,10000,10000,5000,5000,0,11,36796,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Protean Spawn - In Combat - Cast 'Acidic Bite'");

-- Defender Corpse / Warder Corpse
UPDATE `smart_scripts` SET `comment` = "Defender Corpse - On Aggro - Run Script" WHERE `entryorguid` = 21303 AND `source_type` = 0 AND `id` = 0;
UPDATE `smart_scripts` SET `comment` = "Defender Corpse - Within 0-10 Range Out of Combat LoS - Run Script" WHERE `entryorguid` = 21303 AND `source_type` = 0 AND `id` = 1;
UPDATE `smart_scripts` SET `comment` = "Warder Corpse - On Aggro - Run Script" WHERE `entryorguid` = 21304 AND `source_type` = 0 AND `id` = 0;
UPDATE `smart_scripts` SET `comment` = "Warder Corpse - Within 0-10 Range Out of Combat LoS - Run Script" WHERE `entryorguid` = 21304 AND `source_type` = 0 AND `id` = 1;
UPDATE `smart_scripts` SET `comment` = "Warder Corpse - On Script - Cast 'Bloody Explosion'" WHERE `entryorguid` = 2130400 AND `source_type` = 9 AND `id` = 0;
UPDATE `smart_scripts` SET `event_param1` = 0, `event_param2` = 0, `action_param2` = 0, `comment` = "Warder Corpse - On Script - Cast 'Corpse Burst'" WHERE `entryorguid` = 2130400 AND `source_type` = 9 AND `id` = 1;
UPDATE `smart_scripts` SET `comment` = "Warder Corpse - On Script - Despawn Instant" WHERE `entryorguid` = 2130400 AND `source_type` = 9 AND `id` = 2;

-- Ethereum Life-Binder SAI
SET @ID := 21702;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,2,5000,10000,15000,15000,0,11,37480,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ethereum Life-Binder - In Combat - Cast 'Bind' (Normal Dungeon)"),
(@ID,0,1,0,0,0,100,4,5000,10000,15000,15000,0,11,38900,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ethereum Life-Binder - In Combat - Cast 'Bind' (Heroic Dungeon)"),
(@ID,0,2,0,0,0,100,2,8000,15000,10000,10000,0,11,15654,32,0,0,0,0,5,0,0,0,0,0,0,0,0,"Ethereum Life-Binder - In Combat - Cast 'Shadow Word: Pain' (Normal Dungeon)"),
(@ID,0,3,0,0,0,100,4,8000,15000,10000,10000,0,11,34941,32,0,0,0,0,5,0,0,0,0,0,0,0,0,"Ethereum Life-Binder - In Combat - Cast 'Shadow Word: Pain' (Heroic Dungeon)"),
(@ID,0,4,0,74,0,100,2,0,40,5000,10000,40,11,37479,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Ethereum Life-Binder - On Friendly Between 0-40% Health - Cast 'Shadow Mend' (Normal Dungeon)"),
(@ID,0,5,0,74,0,100,4,0,40,5000,10000,40,11,38899,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Ethereum Life-Binder - On Friendly Between 0-40% Health - Cast 'Shadow Mend' (Heroic Dungeon)");

-- Destroyed Sentinel SAI (Despawns before summontime)
SET @ID := 21761;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,60,0,100,1,15000,15000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Destroyed Sentinel - On Update - Despawn Instant (No Repeat)");

-- Unbound Void Zone
UPDATE `creature_template` SET `ScriptName` = "" WHERE `entry` = 21101;
