-- Unused yet: 
-- Wintergrasp is under attack!
-- Wintergrasp Fortress is under attack!
-- Winter's Edge Tower is under attack!
-- Eastern Bridge is under attack!
-- Western Bridge is under attack!
-- Westspark Bridge is under attack!
-- Flamewatch Tower is under attack!

-- 'You have reached Rank 1: Corporal' Sent to player by raid leader
-- 'You have reached Rank 2: First Lieutenant' Sent to player by raid leader

-- Wintergrasp coreside texts
DELETE FROM trinity_string WHERE entry BETWEEN 12050 AND 12072;
INSERT INTO `trinity_string` (`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`)VALUES
(12050, '%s has been captured by %s ', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12051, '%s is under attack by %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12052, 'The Broken Temple siege workshop', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12053, 'Eastspark siege workshop', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12054, 'Westspark siege workshop', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12055, 'The Sunken Ring siege workshop', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12057, 'Alliance', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12056, 'Horde', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12058, 'The battle for Wintergrasp is about to begin!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12059, 'You have reached Rank 1: Corporal', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12060, 'You have reached Rank 2: First Lieutenant', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12061, 'The south-eastern keep tower', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12062, 'The north-eastern keep tower', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12063, 'The south-western keep tower', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12064, 'The north-western keep tower', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12065, '%s has been damaged !', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12066, '%s has been destroyed!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12067, 'The battle for Wintergrasp begin!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12068, '%s has successfully defended the Wintergrasp fortress!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12069, 'The southern tower', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12070, 'The eastern tower', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12071, 'The western tower', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12072, 'The Wintergrasp fortress has been captured by %s !', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),

-- Wintergrasp script texts
DELETE FROM `script_texts` WHERE entry BETWEEN -1850500 AND -1850507;
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`,`sound`,`type`,`language`,`emote`,`comment`)VALUES
(0, -1850500, 'Guide me to the Fortress Graveyard.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, ''),
(0, -1850501, 'Guide me to the Sunken Ring Graveyard.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, ''),
(0, -1850502, 'Guide me to the Broken Temple Graveyard.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, ''),
(0, -1850503, 'Guide me to the Westspark Graveyard.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, ''),
(0, -1850504, 'Guide me to the Eastspark Graveyard.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, ''),
(0, -1850505, 'Guide me back to the Horde landing camp.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, ''),
(0, -1850506, 'Guide me back to the Alliance landing camp.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, ''),
(0, -1850507, 'Se mettre dans la file pour le Joug-d''hiver.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, ''); -- (Needs proper english text)

-- Wintergrasp queue template NPCs
UPDATE `creature_template` SET `ScriptName`= 'npc_wg_dalaran_queue' WHERE `entry` IN (32169,32170,35599,35596,35600,35601,35598,35603,35602,35597,35612,35611);

--  54640 Teleport (Teleports defenders behind the walls on the Isle of Ulduran, Strand of the Ancients) - FIX THIS?
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=54640;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES (54640,54643,0, 'WG teleporter');

-- ???
DELETE FROM `gameobject` WHERE `id` IN (194162,192951,192273,192274,192277,192280,192283,192289,192290,192338,192339,192406,192407,192414,192417,192418,192429,192433,192434,192435,192458,192459,192460,192461,192819,190475,190487,194959,194962,192829,190219,190220,191795,191796,191799,191800,191801,191802,191803,191804,191806,191807,191808,191809,190369,190370,190371,190372,190374,190376,190221,190373,190377,190378,191797,191798,191805,190356,190357,190358,190375,191810,        192488,192501,192374,192416,192375,192336,192255,192269,192254,192349,192366,192367,192364,192370,192369,192368,192362,192363,192379,192378,192355,192354,192358,192359,192284,192285,192371,192372,192373,192360,192361,192356,192352,192353,192357,192350,192351,190763,192501,192488,192269,192278) AND `map`=571;
DELETE FROM `creature` WHERE `id` IN (30739,30740,31102,31841,31151,31153,32296,31051,31106,31108,31109,31053,30489,39172,31107,32294,31101,30499,31842,31036,31091,39173,31052,30400,31054) AND `map`=571;

-- ???
UPDATE `creature_template` SET `InhabitType`=7 WHERE `entry`=27852;

-- Wintergrasp spiritguide NPC script
UPDATE `creature_template` SET `ScriptName`= 'npc_wg_spiritguide' WHERE `entry` IN (31841,31842);

-- Wintergrasp demolisher engineer NPC script
UPDATE `creature_template` SET `ScriptName`= 'npc_demolisher_engineerer' WHERE `entry` IN (30400,30499);

-- 58730 Restricted Flight Area (Wintergrasp Eject)
DELETE FROM `spell_area` WHERE `spell`=58730;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_start_active`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`)VALUES
(58730,4581,0,0,0,0,0,2,1),
(58730,4539,0,0,0,0,0,2,1),
(58730,4197,0,0,0,0,0,2,1),
(58730,4585,0,0,0,0,0,2,1),
(58730,4612,0,0,0,0,0,2,1),
(58730,4582,0,0,0,0,0,2,1),
(58730,4583,0,0,0,0,0,2,1),
(58730,4589,0,0,0,0,0,2,1),
(58730,4575,0,0,0,0,0,2,1),
(58730,4538,0,0,0,0,0,2,1),
(58730,4577,0,0,0,0,0,2,1);

-- 57940 Essence of Wintergrasp
DELETE FROM `spell_area` WHERE `spell`=57940;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_start_active`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`)VALUES
(57940,65,0,0,0,0,0,2,1),
(57940,66,0,0,0,0,0,2,1),
(57940,67,0,0,0,0,0,2,1),
(57940,206,0,0,0,0,0,2,1),
(57940,210,0,0,0,0,0,2,1),
(57940,394,0,0,0,0,0,2,1),
(57940,395,0,0,0,0,0,2,1),
(57940,1196,0,0,0,0,0,2,1),
(57940,2817,0,0,0,0,0,2,1),
(57940,3456,0,0,0,0,0,2,1),
(57940,3477,0,0,0,0,0,2,1),
(57940,3537,0,0,0,0,0,2,1),
(57940,3711,0,0,0,0,0,2,1),
(57940,4100,0,0,0,0,0,2,1),
(57940,4196,0,0,0,0,0,2,1),
(57940,4228,0,0,0,0,0,2,1),
(57940,4264,0,0,0,0,0,2,1),
(57940,4265,0,0,0,0,0,2,1),
(57940,4272,0,0,0,0,0,2,1),
(57940,4273,0,0,0,0,0,2,1),
(57940,4395,0,0,0,0,0,2,1),
(57940,4415,0,0,0,0,0,2,1),
(57940,4416,0,0,0,0,0,2,1),
(57940,4493,0,0,0,0,0,2,1),
(57940,4494,0,0,0,0,0,2,1),
(57940,4603,0,0,0,0,0,2,1);

-- Wintergrasp Cannons (Spell 51421 : Fire Cannon)
UPDATE `creature_template` SET `faction_A`=1732,`faction_H`=1735,`spell1`=51421 WHERE `entry`=28366; -- *** WRONG ****
UPDATE `creature_template` SET `faction_A`=1732,`faction_H`=1732 WHERE `entry` IN (30499,30740, 28319); -- Alliance
UPDATE `creature_template` SET `faction_A`=1735,`faction_H`=1735 WHERE `entry` IN (30400,30739, 32629); -- Horde

-- Added by Malcrom
UPDATE `creature_template` SET `faction_A`=1732,`faction_H`=1732 WHERE `entry` IN (28312); -- Alliance
UPDATE `creature_template` SET `faction_A`=1735,`faction_H`=1735 WHERE `entry` IN (32627); -- Horde

-- New support-commands for battlefield class
DELETE FROM `command` WHERE name IN ('bf start', 'bf stop', 'bf enable', 'bf switch', 'bf timer');
INSERT INTO `command` (`name`,`security`,`help`) VALUES ('bf start',3,'Syntaxe: .bf start #battleid');
INSERT INTO `command` (`name`,`security`,`help`) VALUES ('bf stop',3,'Syntaxe: .bf stop #battleid');
INSERT INTO `command` (`name`,`security`,`help`) VALUES ('bf enable',3,'Syntaxe: .bf enable #battleid');
INSERT INTO `command` (`name`,`security`,`help`) VALUES ('bf switch',3,'Syntaxe: .bf switch #battleid');
INSERT INTO `command` (`name`,`security`,`help`) VALUES ('bf timer',3,'Syntaxe: .bf timer #battleid #timer');

-- 49899 Activate Robotic Arms
DELETE FROM `spell_scripts` WHERE `id`=49899;
INSERT INTO `spell_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(49899,0,1,406,0,0,0,0,0,0);

-- Wintergrasp creature addon cleanups
DELETE FROM `creature_addon` WHERE `guid` BETWEEN 131258 AND 131322;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN 131326 AND 131328;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN 131350 AND 131353;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN 131376 AND 131380;
DELETE FROM `creature_addon` WHERE `guid`=131392;
DELETE FROM `creature_addon` WHERE `guid`=131437;
DELETE FROM `creature_addon` WHERE `guid`=131458;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN 131631 AND 131634;
DELETE FROM `creature_addon` WHERE `guid`=131706;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN 131727 AND 131731;

-- Wintergrasp vehicle teleport
UPDATE `gameobject_template` SET `ScriptName`= 'go_wintergrasp_teleporter' WHERE `entry`=192951;

-- Wintergrasp Quests - Horde
UPDATE `quest_template` SET `ExclusiveGroup`=13180 WHERE `entry` IN (13180, 13178);
UPDATE `quest_template` SET `ExclusiveGroup`=13185 WHERE `entry` IN (13185, 13223);
UPDATE `quest_template` SET `ExclusiveGroup`=13192 WHERE `entry` IN (13192, 13202);
UPDATE `quest_template` SET `ExclusiveGroup`=13199 WHERE `entry` IN (13193, 13199);
UPDATE `quest_template` SET `ExclusiveGroup`=13200 WHERE `entry` IN (13200, 13191);
UPDATE `quest_template` SET `ExclusiveGroup`=13201 WHERE `entry` IN (13201, 13194);

-- Wintergrasp Quests - Alliance
UPDATE `quest_template` SET `ExclusiveGroup`=13179 WHERE `entry` IN (13179, 13177);
UPDATE `quest_template` SET `ExclusiveGroup`=13186 WHERE `entry` IN (13186, 13222);
UPDATE `quest_template` SET `ExclusiveGroup`=13195 WHERE `entry` IN (13195, 13156);
UPDATE `quest_template` SET `ExclusiveGroup`=13196 WHERE `entry` IN (13196, 13154);
UPDATE `quest_template` SET `ExclusiveGroup`=13198 WHERE `entry` IN (13198, 13153);

-- Wintergrasp Questgiver NPCs - requires binding to Wintergrasp questgiver script
UPDATE `creature_template` SET `ScriptName`= 'npc_wintergrasp_quest_giver' WHERE `entry` IN (31054, 31052, 31091, 31036, 31101, 31107, 31053, 31051, 31153, 31151, 31102, 31106);

-- Wintergrasp Catapult speed adjustments
UPDATE `creature_template` SET `speed_walk`=2.8,`speed_run`=1.6 WHERE `entry`=27881;

-- Add Missing Horde Spirt Healer options Wintergrasp
DELETE FROM `gossip_menu_option` WHERE `menu_id`=10129 AND `id` IN (2,4);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(10129,2,0, 'Guide me to the Broken Temple Graveyard.',1,1,0,0,0,0,0, ''),
(10129,4,0, 'Guide me to the Eastspark Graveyard.',1,1,0,0,0,0,0, '');

-- Add Spell Target position for Wintergrasp Graveyard spells
DELETE FROM `spell_target_position` WHERE `id` IN (59760,59762,59763,59765,59766,59767,59769);
INSERT INTO `spell_target_position` (`id`,`target_map`,`target_position_x`,`target_position_y`,`target_position_z`,`target_orientation`) VALUES
(59760,571,5537.986,2897.493,517.057,4.819249), -- Teleport: Fortress Graveyard 
(59762,571,5104.750,2300.940,368.579,0.733038), -- Teleport: Sunken Ring "area 4538"
(59763,571,5099.120,3466.036,368.484,5.317802), -- Teleport: Broken Temple "area 4539 & 4589"
(59765,571,5032.454,3711.382,372.468,3.971623), -- Teleport: Horde Landing Zone
(59766,571,4331.716,3235.695,390.251,0.008500), -- Teleport: Westspark Factory Graveyard "area 4611"
(59767,571,4314.648,2408.522,392.642,6.268125), -- Teleport: Eastspark Factory Graveyard "area 4612"
(59769,571,5140.790,2179.120,390.950,1.972220); -- Teleport: Alliance Landing Zone

-- Add scripts to Wintergrasp spirit guide gossip 
UPDATE `gossip_menu_option` SET `action_script_id`=1012800 WHERE `menu_id` IN (10128,10129) AND `id`=0;
UPDATE `gossip_menu_option` SET `action_script_id`=1012801 WHERE `menu_id` IN (10128,10129) AND `id`=1;
UPDATE `gossip_menu_option` SET `action_script_id`=1012802 WHERE `menu_id` IN (10128,10129) AND `id`=2;
UPDATE `gossip_menu_option` SET `action_script_id`=1012803 WHERE `menu_id` IN (10128,10129) AND `id`=3;
UPDATE `gossip_menu_option` SET `action_script_id`=1012804 WHERE `menu_id` IN (10128,10129) AND `id`=4;
UPDATE `gossip_menu_option` SET `action_script_id`=1012805 WHERE `menu_id`=10128 AND `id`=5;
UPDATE `gossip_menu_option` SET `action_script_id`=1012806 WHERE `menu_id`=10129 AND `id`=5;

-- Add Teleport graveyard Spells to gossip scripts
DELETE FROM `gossip_scripts` WHERE `id` IN (1012800,1012801,1012802,1012803,1012804,1012805,1012806);
INSERT INTO `gossip_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`) VALUES
(1012800,0,33,0,0),(1012800,0,15,59760,1),
(1012801,0,33,0,0),(1012801,0,15,59762,1),
(1012802,0,33,0,0),(1012802,0,15,59763,1),
(1012803,0,33,0,0),(1012803,0,15,59766,1),
(1012804,0,33,0,0),(1012804,0,15,59767,1),
(1012805,0,33,0,0),(1012805,0,15,59769,1),
(1012806,0,33,0,0),(1012806,0,15,59765,1);

-- Taunka Spirit Guide SAI
SET @ENTRY := 31841;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=@ENTRY);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,58729,0,0,0,0,0,1,0,0,0,0,0,0,0, 'on spawn aura self'),
(@ENTRY,0,1,0,1,0,100,0,0,0,30000,30000,11,22011,0,0,0,0,0,1,0,0,0,0,0,0,0, 'cast Spirit Heal Channel every 30 sec');
-- Dwarven Spirit Guide SAI
SET @ENTRY := 31842;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=@ENTRY);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,58729,0,0,0,0,0,1,0,0,0,0,0,0,0, 'on spawn aura self'),
(@ENTRY,0,1,0,1,0,100,0,0,0,30000,30000,11,22011,0,0,0,0,0,1,0,0,0,0,0,0,0, 'cast Spirit Heal Channel every 30 sec');

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=9904 AND `text_id`=13759;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9904,13759);
DELETE FROM `gossip_menu` WHERE `entry`=9904 AND `text_id`=13761;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9904,13761);
DELETE FROM `gossip_menu` WHERE `entry`=9923 AND `text_id`=14172;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9923,14172);
DELETE FROM `gossip_menu` WHERE `entry`=10229 AND `text_id`=14221;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (10229,14221);

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=9904 WHERE `entry`=30400;
UPDATE `creature_template` SET `gossip_menu_id`=10229 WHERE `entry`=31091;
-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (9904);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(9904,0,0, 'I would like to build a catapult.',1,1,0,0,0,0,0, ''),
(9904,1,0, 'I would like to build a demolisher.',1,1,0,0,0,0,0, ''),
(9904,2,0, 'I would like to build a siege engine.',1,1,0,0,0,0,0, '');
-- Add gossip_menu condition for 9904 Horde
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=9904;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`) VALUES
(14,9904,13759,0,1,33280), -- Must have Rank 1: Corporal
(14,9904,13759,1,1,55629), -- Or must have Rank 2: First Lieutenant
(14,9904,13761,0,11,33280), -- Must not have Rank 1: Corporal
(14,9904,13761,0,11,55629); -- Must not have Rank 2: First Lieutenant
-- Add gossip_menu condition for 9923 Alliance
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=9923;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`) VALUES
(14,9923,13798,0,1,33280), -- Must have Rank 1: Corporal
(14,9923,13798,1,1,55629), -- Or must have Rank 2: First Lieutenant
(14,9923,14172,0,11,33280), -- Must not have Rank 1: Corporal
(14,9923,14172,0,11,55629); -- Must not have Rank 2: First Lieutenant
-- Add conditions to gossip options horde
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9904;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`) VALUES
(15,9904,0,0,1,33280,0), -- Must have reached Rank 1: Corporal
(15,9904,0,1,1,55629,0), -- Or must have reached Rank 2: First Lieutenant
(15,9904,1,0,1,55629,0), -- Must have reached Rank 2: First Lieutenant
(15,9904,2,0,1,55629,0); -- Must have reached Rank 2: First Lieutenant
-- Add conditions to gossip options alliance
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9923;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`) VALUES
(15,9923,0,0,1,33280,0), -- Must have reached Rank 1: Corporal
(15,9923,0,1,1,55629,0), -- Or must have reached Rank 2: First Lieutenant
(15,9923,1,0,1,55629,0), -- Must have reached Rank 2: First Lieutenant
(15,9923,2,0,1,55629,0); -- Must have reached Rank 2: First Lieutenant

-- Add scripts to Wintergrasp engineers
UPDATE `gossip_menu_option` SET `action_script_id`=990400 WHERE `menu_id` IN (9904,9923) AND `id`=0;
UPDATE `gossip_menu_option` SET `action_script_id`=990401 WHERE `menu_id` IN (9904,9923) AND `id`=1;
UPDATE `gossip_menu_option` SET `action_script_id`=990402 WHERE `menu_id` IN (9904) AND `id`=2;
UPDATE `gossip_menu_option` SET `action_script_id`=990403 WHERE `menu_id` IN (9923) AND `id`=2;
-- Add create vehicle Spells to gossip scripts
-- already done by engineer's script
/*DELETE FROM `gossip_scripts` WHERE `id` IN (990400,990401,990402);
INSERT INTO `gossip_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`) VALUES
(990400,0,33,0,0),(990400,0,15,56663,1),
(990401,0,33,0,0),(990401,0,15,56575,1),
(990402,0,33,0,0),(990402,0,15,61408,1),
(990403,0,33,0,0),(990403,0,15,56661,1);*/

-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry`=15214 AND `groupid` BETWEEN 0 AND 30;
DELETE FROM `creature_text` WHERE `entry` IN (31036,31091) AND `groupid` BETWEEN 0 AND 3;
DELETE FROM `creature_text` WHERE `entry` IN (31108,31109,34924) AND `groupid`=0;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(15214,0,0, 'Let the battle begin!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,1,0, 'The southern tower has been damaged!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,2,0, 'The southern tower has been destroyed!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,3,0, 'The eastern tower has been damaged!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,4,0, 'The eastern tower has been destroyed!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,5,0, 'The western tower has been damaged!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,6,0, 'The western tower has been destroyed!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,7,0, 'The north-western keep tower has been damaged!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,8,0, 'The north-western keep tower has been destroyed!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,9,0, 'The south-eastern keep tower has been damaged!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,10,0, 'The south-eastern keep tower has been destroyed!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,11,0, 'The Broken Temple siege workshop has been attacked by the Alliance!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,12,0, 'The Broken Temple siege workshop has been captured by the Alliance!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,13,0, 'The Broken Temple siege workshop has been attacked by the Horde!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,14,0, 'The Broken Temple siege workshop has been captured by the Horde!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,15,0, 'The Eastspark siege workshop has been attacked by the Alliance!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,16,0, 'The Eastspark siege workshop has been captured by the Alliance!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,17,0, 'The Eastspark siege workshop has been attacked by the Horde!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,18,0, 'The Eastspark siege workshop has been captured by the Horde!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,19,0, 'The Sunken Ring siege workshop has been attacked by the Alliance!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,20,0, 'The Sunken Ring siege workshop has been captured by the Alliance!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,21,0, 'The Sunken Ring siege workshop has been attacked by the Horde!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,22,0, 'The Sunken Ring siege workshop has been captured by the Horde!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,23,0, 'The Westspark siege workshop has been attacked by the Alliance!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,24,0, 'The Westspark siege workshop has been captured by the Alliance!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,25,0, 'The Westspark siege workshop has been attacked by the Horde!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,26,0, 'The Westspark siege workshop has been captured by the Horde!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,27,0, 'The Alliance has defended Wintergrasp Fortress!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,28,0, 'The Alliance has captured Wintergrasp Fortress!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,29,0, 'The Horde has defended Wintergrasp Fortress!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,30,0, 'The Horde has captured Wintergrasp Fortress!',3,0,100,0,0,0, 'Invisible Stalker'),
-- Not sure if all Alliance text is here, need horde text
(31036,0,0, 'The first of the Horde towers has fallen! Destroy all three and we will hasten their retreat!',1,7,100,0,0,0, 'Commander Zanneth'),
(31036,1,0, 'The second tower has fallen! Destroy the final tower and we will hasten their retreat!',1,7,100,0,0,0, 'Commander Zanneth'),
(31036,2,0, 'The Horde towers have fallen! We have forced their hand. Finish off the remaining forces!',1,7,100,0,0,0, 'Commander Zanneth'),
(31036,3,0, 'Show those animals no mercy, $n!',0,7,100,0,0,0, 'Commander Zanneth'),
(31091,0,0, 'The first of the Alliance towers has fallen! Destroy all three and we will hasten their retreat!',1,7,100,0,0,0, 'Commander Dardosh'),
(31091,1,0, 'Lok''tar! The second tower falls! Destroy the final tower and we will hasten their retreat!',1,7,100,0,0,0, 'Commander Dardosh'),
(31091,2,0, 'The Alliance towers have fallen! We have forced their hand. Finish off the remaining forces!',1,7,100,0,0,0, 'Commander Dardosh'),
(31091,3,0, 'Show those animals no mercy, $n!',0,7,100,0,0,0, 'Commander Dardosh'), -- ???
(31108,0,0, 'Stop the Horde from retrieving the embers, $n. We cannot risk them having the advantage when the battle resumes!',0,7,100,0,0,0, 'Siege Master Stouthandle'),
(31109,0,0, 'Destroy their foul machines of war, $n!',0,7,100,0,0,0, 'Senior Demolitionist Legoso'),
(34924,0,0, 'The gates have been breached! Defend the keep!',1,0,100,0,0,0, 'High Commander Halford Wyrmbane');
