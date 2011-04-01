/* Dalaran Books */
SET @Gossip = 21255; -- Set by TDB Team (gossip_menu.entry - need 2)
SET @Guid = 151794; -- Set by TDB Team (gameobject.guid - need 35)
SET @Pool = 5691; -- Set by TDB Team (pool_template.entry - need 8)
SET @GoDespawnTime = 10800; -- Three hours

-- Spawns
DELETE FROM `gameobject` WHERE `id` IN (192708,192706,192871,192905,192710,192886,192869,192880,192895,192713,192889,192890,192894,192884,192866,192891,192872,192881,192709,192883,192651,192888,192711,192653,192887,192652,192865,192874,192868,192870,192885,192867,192882,192707,192896);
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
-- Introduction
(@Guid+0,192708,571,1,1,5814.522,582.1118,652.7509,0.244345576,0,0,0,0,@GoDespawnTime,0,1), -- The Schools of Arcane Magic - Introduction
(@Guid+1,192706,571,1,1,5814.522,582.1118,652.7509,0.244345576,0,0,0,0,@GoDespawnTime,0,1), -- The Worst Mage in Dalaran: A Children's Book
(@Guid+2,192871,571,1,1,5814.522,582.1118,652.7509,0.244345576,0,0,0,0,@GoDespawnTime,0,1), -- The Archmage Antonidas - Part II
(@Guid+3,192905,571,1,1,5814.522,582.1118,652.7509,0.244345576,0,0,0,0,@GoDespawnTime,0,1), -- The Old Wizard's Almanac
-- Conjuration
(@Guid+4,192710,571,1,1,5812.64,797.223,662.57,-2.86234,0,0,0,0,@GoDespawnTime,0,1), -- The Schools of Arcane Magic - Conjuration
(@Guid+5,192886,571,1,1,5812.64,797.223,662.57,-2.86234,0,0,0,0,@GoDespawnTime,0,1), -- In Time, the Arcane Corrupts All!
(@Guid+6,192869,571,1,1,5812.64,797.223,662.57,-2.86234,0,0,0,0,@GoDespawnTime,0,1), -- LAVA BLAST - by Pyroco
(@Guid+7,192880,571,1,1,5812.64,797.223,662.57,-2.86234,0,0,0,0,@GoDespawnTime,0,1), -- Journal of Archmage Antonidas
(@Guid+8,192895,571,1,1,5812.64,797.223,662.57,-2.86234,0,0,0,0,@GoDespawnTime,0,1), -- Kirin Tor Monthly (March Issue)
-- Enchantment
(@Guid+9,192713,571,1,1,5808.22,691.076,658.715,2.179470,0,0,0,0,@GoDespawnTime,0,1), -- The Schools of Arcane Magic - Enchantment
(@Guid+10,192889,571,1,1,5808.22,691.076,658.715,2.179470,0,0,0,0,@GoDespawnTime,0,1), -- Kirin Tor Monthly (November Issue)
(@Guid+11,192890,571,1,1,5808.22,691.076,658.715,2.179470,0,0,0,0,@GoDespawnTime,0,1), -- STAY OUT!!!
(@Guid+12,192894,571,1,1,5808.22,691.076,658.715,2.179470,0,0,0,0,@GoDespawnTime,0,1), -- Remedial Magic 101: Tips from the Pros
(@Guid+13,192884,571,1,1,5808.22,691.076,658.715,2.179470,0,0,0,0,@GoDespawnTime,0,1), -- Portals are NOT Garbage Bins!
-- Necromancy
(@Guid+14,192866,571,1,1,5850.57,664.754,659.569,-1.93732,0,0,0,0,@GoDespawnTime,0,1), -- The Schools of Arcane Magic - Necromancy
(@Guid+15,192891,571,1,1,5850.57,664.754,659.569,-1.93732,0,0,0,0,@GoDespawnTime,0,1), -- To Do Today
(@Guid+16,192872,571,1,1,5850.57,664.754,659.569,-1.93732,0,0,0,0,@GoDespawnTime,0,1), -- The Archmage Antonidas - Part III
(@Guid+17,192881,571,1,1,5850.57,664.754,659.569,-1.93732,0,0,0,0,@GoDespawnTime,0,1), -- Thinking with Portals - A Memorandum on Proper Portal Usage
-- Abjuration
(@Guid+18,192709,571,1,1,5763.5,618.08,650.092,3.49199,0,0,0,0,@GoDespawnTime,0,1), -- The Schools of Arcane Magic - Abjuration
(@Guid+19,192883,571,1,1,5763.5,618.08,650.092,3.49199,0,0,0,0,@GoDespawnTime,0,1), -- Blinking Rules & Regulations
(@Guid+20,192651,571,1,1,5763.5,618.08,650.092,3.49199,0,0,0,0,@GoDespawnTime,0,1), -- Damaged Apprentice Journal
(@Guid+21,192888,571,1,1,5763.5,618.08,650.092,3.49199,0,0,0,0,@GoDespawnTime,0,1), -- Bundle of Romantic Correspondences
-- Divination
(@Guid+22,192711,571,1,1,5778.18,832.302,680.268,0.0283899,0,0,0,0,@GoDespawnTime,0,1), -- The Schools of Arcane Magic - Divination
(@Guid+23,192653,571,1,1,5778.18,832.302,680.268,0.0283899,0,0,0,0,@GoDespawnTime,0,1), -- On the Virtues of Magic
(@Guid+24,192887,571,1,1,5778.18,832.302,680.268,0.0283899,0,0,0,0,@GoDespawnTime,0,1), -- Losses of the Third War
(@Guid+25,192652,571,1,1,5778.18,832.302,680.268,0.0283899,0,0,0,0,@GoDespawnTime,0,1), -- Kirin Tor Monthly (May Issue)
-- Illusion
(@Guid+26,192865,571,1,1,5776.88,517.79,653.911,0.401425,0,0,0,0,@GoDespawnTime,0,1), -- The Schools of Arcane Magic - Illusion
(@Guid+27,192874,571,1,1,5776.88,517.79,653.911,0.401425,0,0,0,0,@GoDespawnTime,0,1), -- The Fluffy Bunny
(@Guid+28,192868,571,1,1,5776.88,517.79,653.911,0.401425,0,0,0,0,@GoDespawnTime,0,1), -- The Dangers of Magic Abuse
(@Guid+29,192870,571,1,1,5776.88,517.79,653.911,0.401425,0,0,0,0,@GoDespawnTime,0,1), -- The Archmage Antonidas - Part I
(@Guid+30,192885,571,1,1,5776.88,517.79,653.911,0.401425,0,0,0,0,@GoDespawnTime,0,1), -- The Fate of Apprentice Argoly
-- Transmutation
(@Guid+31,192867,571,1,1,5844.61328,664.541,649.3733,-0.3316107,0,0,0,0,@GoDespawnTime,0,1), -- The Schools of Arcane Magic - Transmutation
(@Guid+32,192882,571,1,1,5844.61328,664.541,649.3733,-0.3316107,0,0,0,0,@GoDespawnTime,0,1), -- Polymorphic Rules & Regulations
(@Guid+33,192707,571,1,1,5844.61328,664.541,649.3733,-0.3316107,0,0,0,0,@GoDespawnTime,0,1), -- Weathered Diary - Dates from the Third War
(@Guid+34,192896,571,1,1,5844.61328,664.541,649.3733,-0.3316107,0,0,0,0,@GoDespawnTime,0,1); -- Excerpts from the Journal of Archmage Vargoth

/*
-- SAI prototype: Despawn after use FIXME: SAI can't despawn GOs
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (xxx);
DELETE FROM `smart_scripts` WHERE `source_type`=1 AND `id`=0 AND `entryorguid` IN (xxx);
INSERT INTO `smart_scripts`(`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(xxx,1,0,0,64,0,100,0,0,0,0,0,41,180000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dalaran Books: Despawn after 3 mins on gossip_hello');
*/

-- Pooling
DELETE FROM `pool_template` WHERE `entry` BETWEEN @Pool+0 AND @Pool+7;
INSERT INTO `pool_template` (`entry`,`max_limit`,`description`) VALUES
(@Pool+0,1, 'Dalaran Books: Violet Gate'),
(@Pool+1,1, 'Dalaran Books: Violet Citadel Lower'),
(@Pool+2,1, 'Dalaran Books: Threads of Fate'),
(@Pool+3,1, 'Dalaran Books: Ledgerdemain Lounge Upstairs'),
(@Pool+4,1, 'Dalaran Books: Visitor’s Center'),
(@Pool+5,1, 'Dalaran Books: Violet Citadel Upstairs'),
(@Pool+6,1, 'Dalaran Books: Violet Hold'),
(@Pool+7,1, 'Dalaran Books: Ledgerdemain Lounge Lower');

DELETE FROM `pool_gameobject` WHERE `pool_entry` BETWEEN @Pool+0 AND @Pool+7;
INSERT INTO `pool_gameobject` (`guid`,`pool_entry`,`chance`,`description`) VALUES
-- Introduction
(@Guid+0,@Pool+0,0, 'The Schools of Arcane Magic - Introduction'),
(@Guid+1,@Pool+0,0, 'The Worst Mage in Dalaran: A Children''s Book'),
(@Guid+2,@Pool+0,0, 'The Archmage Antonidas - Part II'),
(@Guid+3,@Pool+0,0, 'The Old Wizard''s Almanac'),
-- Conjuration
(@Guid+4,@Pool+1,0, 'The Schools of Arcane Magic - Conjuration'),
(@Guid+5,@Pool+1,0, 'In Time, the Arcane Corrupts All!'),
(@Guid+6,@Pool+1,0, 'LAVA BLAST - by Pyroco'),
(@Guid+7,@Pool+1,0, 'Journal of Archmage Antonidas'),
(@Guid+8,@Pool+1,0, 'Kirin Tor Monthly (March Issue)'),
-- Enchantment
(@Guid+9,@Pool+2,0, 'The Schools of Arcane Magic - Enchantment'),
(@Guid+10,@Pool+2,0, 'Kirin Tor Monthly (November Issue)'),
(@Guid+11,@Pool+2,0, 'STAY OUT!!!'),
(@Guid+12,@Pool+2,0, 'Remedial Magic 101: Tips from the Pros'),
(@Guid+13,@Pool+2,0, 'Portals are NOT Garbage Bins!'),
-- Necromancy
(@Guid+14,@Pool+3,0, 'The Schools of Arcane Magic - Necromancy'),
(@Guid+15,@Pool+3,0, 'To Do Today'),
(@Guid+16,@Pool+3,0, 'The Archmage Antonidas - Part III'),
(@Guid+17,@Pool+3,0, 'Thinking with Portals - A Memorandum on Proper Portal Usage'),
-- Abjuration
(@Guid+18,@Pool+4,0, 'The Schools of Arcane Magic - Abjuration'),
(@Guid+19,@Pool+4,0, 'Blinking Rules & Regulations'),
(@Guid+20,@Pool+4,0, 'Damaged Apprentice Journal'),
(@Guid+21,@Pool+4,0, 'Bundle of Romantic Correspondences'),
-- Divination
(@Guid+22,@Pool+5,0, 'The Schools of Arcane Magic - Divination'),
(@Guid+23,@Pool+5,0, 'On the Virtues of Magic'),
(@Guid+24,@Pool+5,0, 'Losses of the Third War'),
(@Guid+25,@Pool+5,0, 'Kirin Tor Monthly (May Issue)'),
-- Illusion
(@Guid+26,@Pool+6,0, 'The Schools of Arcane Magic - Illusion'),
(@Guid+27,@Pool+6,0, 'The Fluffy Bunny'),
(@Guid+28,@Pool+6,0, 'The Dangers of Magic Abuse'),
(@Guid+29,@Pool+6,0, 'The Archmage Antonidas - Part I'),
(@Guid+30,@Pool+6,0, 'The Fate of Apprentice Argoly'),
-- Transmutation
(@Guid+31,@Pool+7,0, 'The Schools of Arcane Magic - Transmutation'),
(@Guid+32,@Pool+7,0, 'Polymorphic Rules & Regulations'),
(@Guid+33,@Pool+7,0, 'Weathered Diary - Dates from the Third War'),
(@Guid+34,@Pool+7,0, 'Excerpts from the Journal of Archmage Vargoth');

UPDATE `creature_template` SET `gossip_menu_id`=@Gossip+0,`AIName`='SmartAI' WHERE `entry`=19481; -- Archmage Vargoth
UPDATE `creature_model_info` SET `bounding_radius`=0.306,`combat_reach`=1,`gender`=0 WHERE `modelid`=19284; -- Archmage Vargoth
UPDATE `creature` SET `npcflag`=1 WHERE `guid`=98174; -- Archmage Vargoth
DELETE FROM `creature_template_addon` WHERE `entry`=19481;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(19481,0,0,1,0, NULL); -- Archmage Vargoth
-- Gossip for Archmage Vargoth
DELETE FROM `gossip_menu` WHERE `text_id` IN (14192,14194);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(@Gossip+0,14192),
(@Gossip+1,14194);
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (@Gossip+0,@Gossip+1) AND `id`=0;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@Gossip+0,0,0, 'I have a book that might interest you. Would you like to take a look?',1,1,@Gossip+1,0,0,0,0,NULL),
(@Gossip+1,0,0, 'Thank you! I''ll be sure to notify you if I find anything else.',1,1,0,0,0,0,0,NULL); -- SAI script
DELETE FROM `creature_template_addon` WHERE `entry`=32643;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(32643,0,0,0,3,0,'61478 0'); -- companion pet aura (arcane explosions)

DELETE FROM `smart_scripts` WHERE `entryorguid`=-98174 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(-98174,0,0,0,62,0,100,0,@Gossip+1,0,0,0,11,61457,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Archmage Vargoth (Dalaran) - On gossip select cast Kirin Tor Familiar on invoker');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=@Gossip+0 AND `SourceEntry`=14192;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@Gossip+0 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@Gossip+0,14192,0,4,4395,0,0,0, '', 'Archmage Vargoth - Gossip: zone restriction to Dalaran'),
(15,@Gossip+0,0,0,4,4395,0,0,0, '', 'Archmage Vargoth - Gossip option: zone restriction to Dalaran'),
(15,@Gossip+0,0,0,26,44738,1,0,0, '', 'Archmage Vargoth - Gossip option: player should not have item 44738'),
(15,@Gossip+0,0,0,17,1956,0,0,0, '', 'Archmage Vargoth - Gossip option: player should have achiev 1956');
-- FIXME: add a gossip option condition: player should not have spell 61472
