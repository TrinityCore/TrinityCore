--
-- General fixes for YTDB and TDB
--

-- Fix Summon Infernal spell. Thanks inordon fod idea
UPDATE `creature_template` SET flags_extra = 0 WHERE `entry` = 89; 

-- Leeeeeeeeroy! achievement fix
UPDATE `instance_template` SET `script`='instance_blackrock_spire' WHERE `map`=229;
UPDATE `creature_template` SET `ScriptName`='npc_rookey_whelp' WHERE entry=10161;
UPDATE `gameobject_template` SET `ScriptName`='go_rookey_egg' WHERE entry=175124;

-- Nature's Grasp fix
DELETE FROM `spell_proc_event` WHERE `entry` IN (16689,16810,16811,16812,16813,17329,27009,53312);
INSERT INTO `spell_proc_event` (`entry`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`procFlags`,`procEx`,`ppmRate`,`CustomChance`,`Cooldown`) VALUES
(16689,0,0,0,0,0,0,0,0,100,1), -- Nature's Grasp (Rank 1)
(16810,0,0,0,0,0,0,0,0,100,1), -- Nature's Grasp (Rank 2)
(16811,0,0,0,0,0,0,0,0,100,1), -- Nature's Grasp (Rank 3)
(16812,0,0,0,0,0,0,0,0,100,1), -- Nature's Grasp (Rank 4)
(16813,0,0,0,0,0,0,0,0,100,1), -- Nature's Grasp (Rank 5)
(17329,0,0,0,0,0,0,0,0,100,1), -- Nature's Grasp (Rank 6)
(27009,0,0,0,0,0,0,0,0,100,1), -- Nature's Grasp (Rank 7)
(53312,0,0,0,0,0,0,0,0,100,1);-- Nature's Grasp (Rank 8)

-- fix Reign of the Unliving (normal and heroic) proc only from crit
DELETE FROM `spell_proc_event` WHERE entry IN (67712, 67758);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
('67712','0','0','0','0','0','0','2','0','0','2'),
('67758','0','0','0','0','0','0','2','0','0','2');

-- ICC weapons procs
-- (71845) Item - Icecrown 25 Normal Caster Weapon Proc 
DELETE FROM `spell_proc_event` WHERE `entry` IN (71845); 
INSERT INTO `spell_proc_event` VALUES (71845, 0x01, 0x00, 0x00000000, 0x00000000, 0x00000000, 0x00010000, 0x00000000, 0, 2, 40); 
-- (71845) Item - Icecrown 25 Normal Caster Weapon Proc 
DELETE FROM `spell_proc_event` WHERE `entry` IN (71845); 
INSERT INTO `spell_proc_event` VALUES (71845, 0x01, 0x00, 0x00000000, 0x00000000, 0x00000000, 0x00010000, 0x00000000, 0, 2, 45);
-- (71865) Item - Icecrown 25 Normal Healer Weapon Proc 
DELETE FROM `spell_proc_event` WHERE `entry` IN (71865); 
INSERT INTO `spell_proc_event` VALUES (71865, 0x01, 0x0A, 0x00000000, 0x00000000, 0x00000000, 0x00044000, 0x00000018, 0, 1, 0); 
-- (71868) Item - Icecrown 25 Heroic Healer Weapon Proc 
DELETE FROM `spell_proc_event` WHERE `entry` IN (71868); 
INSERT INTO `spell_proc_event` VALUES (71868, 0x01, 0x0A, 0x00000000, 0x00000000, 0x00000000, 0x00044000, 0x00000018, 0, 1, 0); 

-- Fizzcrank Recon Pilot
DELETE FROM `creature_ai_scripts` WHERE creature_id = 25841;
UPDATE `creature_template` SET IconName = 'Speak', npcflag = 1, gossip_menu_id = 0, AIName = '', ScriptName = 'npc_recon_pilot', unit_flags = 0x00000000, flags_extra = 2, dynamicflags = 36  WHERE entry = 25841;
DELETE FROM `creature_template_addon` WHERE entry = 25841;
INSERT INTO `creature_template_addon` VALUES (25841, 0, 0, 7, 0, 65, '');

-- Open Halls of Reflection without quest
UPDATE `access_requirement` set `quest_done_A`=0, `quest_done_H`=0 where `mapId` = 668;

-- Item - Hunter T10 Survival 2P Bonus
DELETE FROM `spell_proc_event` WHERE `entry` = 70727;
INSERT INTO `spell_proc_event` VALUES (70727, 0, 9, 0, 0, 0, 64, 0, 0, 5, 0); 
-- Item - Hunter T10 Survival 4P Bonus
DELETE FROM `spell_proc_event` WHERE `entry` = 70730;
INSERT INTO `spell_proc_event` VALUES (70730, 0, 9, 16384, 4096, 0, 262144, 0, 0, 5, 0);  

-- fix Magister Hathorel and Arcanist Tybalin scriptname
UPDATE `creature_template` SET `ScriptName` = 'npc_magister_hathorel' WHERE `entry` = 36670;
UPDATE `creature_template` SET `ScriptName` = 'npc_arcanist_tybalin' WHERE `entry` = 36669;

-- set visible intendants of The Sons of Hodir and Knights of the Ebon Blade
UPDATE `creature` SET phaseMask=65535 WHERE `id` in (32538,32540);

-- Open access to heroic ICC without achievement
UPDATE `access_requirement` SET `completed_achievement`=0 WHERE `mapId`=631 and `difficulty` in (2,3);

-- [Dungeon Finder] Fix Drak'Tharon Keep reward for DF
UPDATE `instance_encounters` SET `creditType` = '0', `creditEntry` = '26632' WHERE `entry` IN ('376', '375');
-- [Dungeon Finder] Fix reward for Utgarde Keep.
UPDATE `instance_encounters` SET `creditEntry` = '23980' WHERE `entry` IN ('575', '576');
-- [Dungeon Finder] Fix CoS reward
UPDATE `instance_encounters` SET `creditType`=0, `creditEntry`=26533 WHERE `entry` IN (296, 300);

-- fix for YTDB after "guards don't evade..." commit
UPDATE `creature_template` SET `Unit_flags` = 36864 WHERE `entry` = 3296;

-- another fix for YTDB for unit_flags 
UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` = 16844;
UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` = 16857;
UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` = 16968;
UPDATE `creature_template` SET `unit_flags` = 32768 WHERE `entry` = 25760;
UPDATE `creature_template` SET `Unit_flags` = 36864 WHERE `entry` = 3296;
UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` = 26076;
UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` = 26073;

-- fix flag for Sunreaver Agent NPC.
UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` = 36776;

-- fix flag for Silver Covenant Agent
UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` = 36774; 

-- DB/Achievements: Fix achievement "Lonely?"
UPDATE `gameobject_template` SET `data10`=45123 WHERE `entry`=187267;

-- Dangerous Love achievement
-- Alliance
UPDATE quest_template SET prevQuestId = 0 where ExclusiveGroup = 24638;
-- Horde
UPDATE quest_template SET prevQuestId = 0 where ExclusiveGroup = 24658;
-- Alliance
UPDATE quest_template SET prevQuestId = 24576 where ExclusiveGroup = 24638;
-- Horde
UPDATE quest_template SET prevQuestId = 24657 where ExclusiveGroup = 24658;

-- Cinderglacier
UPDATE `spell_proc_event` SET `SpellFamilyName` = '15', `SpellFamilyMask0` = 0x42002, `SpellFamilyMask1` = 0x6, `SpellFamilyMask2` = 0x80 WHERE `entry` = 53386;

-- Druid Berserk fix
DELETE FROM `spell_script_names` WHERE `spell_id`=50334 AND `ScriptName`='spell_dru_berserk';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(50334, 'spell_dru_berserk');

-- Fix spell 66926 for quest "They Grow Up So Fast"
DELETE FROM `spell_script_names` WHERE `spell_id`=66926;
INSERT INTO `spell_script_names` VALUES
(66926, 'spell_gen_venomhide_check');

-- fix some quests in Borean Tundra
UPDATE creature_template SET scriptname = 'vehicle_wyrmrest_skytalon' WHERE entry = 32535;

-- Add script for Archmage Vargoth NPC(19481)
UPDATE creature_template SET scriptname = 'npc_archmage_vargoth' WHERE entry = 19481;

-- Add scripts for some NPC in Dragon Blight
UPDATE creature_template SET scriptname = 'vehicle_forsaken_blight_spreader' WHERE entry = 26523;
UPDATE creature_template SET scriptname = 'npc_warsong_battle_standard' WHERE entry = 26678;
UPDATE creature_template SET scriptname = 'npc_emissary_brighthoof' WHERE entry = 26181;
UPDATE creature_template SET scriptname = 'npc_wintergarde_mine_bomb' WHERE entry = 27435;
UPDATE creature_template SET scriptname = 'npc_devout_bodyguard' WHERE entry = 27247;
UPDATE creature_template SET scriptname = 'npc_high_abbot_landgren' WHERE entry = 27245;
UPDATE creature_template SET scriptname = 'npc_agent_skully' WHERE entry = 27350;
UPDATE creature_template SET scriptname = 'npc_7th_legion_siege_engineer' WHERE entry = 27163;
UPDATE creature_template SET scriptname = 'vehicle_alliance_steamtank' WHERE entry = 27587;
UPDATE creature_template SET scriptname = 'mob_woodlands_walker' WHERE entry = 26421;

-- Fix Koralon's Meteor Fists
DELETE FROM spell_script_names WHERE spell_id = 66765;
INSERT INTO spell_script_names VALUES 
(66765, "spell_koralon_meteor_fists");

DELETE FROM `creature_model_info` WHERE (`modelid`=29524);
INSERT INTO `creature_model_info` (`modelid`, `bounding_radius`, `combat_reach`, `gender`, `modelid_other_gender`) VALUES (29524, 0.45, 8, 2, 0);

-- Fix Battleground Demolisher (http://www.wowhead.com/npc=28781) HP
UPDATE `creature_template` SET `exp` = 0 WHERE `entry` = 32796;

-- Bloodworm AI
DELETE FROM `creature_ai_scripts` WHERE `creature_id` = 28017;
INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`) VALUES
(2801700, 28017, 4, 0, 100, 0, 0, 0, 0, 0, 11, 50453, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Bloodworm - Health Leech');

-- ARGENT SQUIRE/GRUNTLING
DELETE FROM `spell_script_names` WHERE `spell_id` = 67039;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUE (67039, 'spell_gen_mounting_check');
-- Gossip flag
UPDATE `creature_template` SET `npcflag` = 0x81, `gossip_menu_id` = 50000, `ScriptName` = 'npc_argent_squire' WHERE `entry` = 33238;
UPDATE `creature_template` SET `npcflag` = 0x81, `gossip_menu_id` = 50001, `ScriptName` = 'npc_argent_squire' WHERE `entry` = 33239;

DELETE FROM `gossip_menu` WHERE `entry` IN (50000, 50001);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(50000, 14324),
(50001, 14372);

DELETE FROM `spell_linked_spell` WHERE `spell_effect` = 67401;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`, `type`, `comment`) VALUES
(-67368, 67401, 0, 'Argent Squire - Bank'),
(-67377, 67401, 0, 'Argent Squire - Shop'),
(-67376, 67401, 0, 'Argent Squire - Mail');

DELETE FROM `npc_vendor` WHERE `entry` IN (33238, 33239);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`) VALUES
-- Squire
(33238, 1, 3775, 0, 0, 0),
(33238, 2, 5237, 0, 0, 0),
(33238, 3, 5565, 0, 0, 0),
(33238, 4, 16583, 0, 0, 0),
(33238, 5, 17020, 0, 0, 0),
(33238, 6, 17030, 0, 0, 0),
(33238, 7, 17031, 0, 0, 0),
(33238, 8, 17032, 0, 0, 0),
(33238, 9, 17033, 0, 0, 0),
(33238, 10, 21177, 0, 0, 0),
(33238, 11, 37201, 0, 0, 0),
(33238, 12, 41584, 0, 0, 0),
(33238, 13, 41586, 0, 0, 0),
(33238, 14, 43231, 0, 0, 0),
(33238, 15, 43233, 0, 0, 0),
(33238, 16, 43235, 0, 0, 0),
(33238, 17, 43237, 0, 0, 0),
(33238, 18, 44605, 0, 0, 0),
(33238, 19, 44614, 0, 0, 0),
(33238, 20, 44615, 0, 0, 0),

(33238, 21, 33449, 0, 0, 0),
(33238, 22, 33451, 0, 0, 0),
(33238, 23, 33454, 0, 0, 0),
(33238, 24, 33443, 0, 0, 0),
(33238, 25, 35949, 0, 0, 0),
(33238, 26, 35952, 0, 0, 0),
(33238, 27, 35953, 0, 0, 0),
(33238, 28, 35951, 0, 0, 0),
(33238, 29, 35948, 0, 0, 0),
(33238, 30, 35950, 0, 0, 0),

-- Gruntling
(33239, 1, 3775, 0, 0, 0),
(33239, 2, 5237, 0, 0, 0),
(33239, 3, 5565, 0, 0, 0),
(33239, 4, 16583, 0, 0, 0),
(33239, 5, 17020, 0, 0, 0),
(33239, 6, 17030, 0, 0, 0),
(33239, 7, 17031, 0, 0, 0),
(33239, 8, 17032, 0, 0, 0),
(33239, 9, 17033, 0, 0, 0),
(33239, 10, 21177, 0, 0, 0),
(33239, 11, 37201, 0, 0, 0),
(33239, 12, 41584, 0, 0, 0),
(33239, 13, 41586, 0, 0, 0),
(33239, 14, 43231, 0, 0, 0),
(33239, 15, 43233, 0, 0, 0),
(33239, 16, 43235, 0, 0, 0),
(33239, 17, 43237, 0, 0, 0),
(33239, 18, 44605, 0, 0, 0),
(33239, 19, 44614, 0, 0, 0),
(33239, 20, 44615, 0, 0, 0),

(33239, 21, 33449, 0, 0, 0),
(33239, 22, 33451, 0, 0, 0),
(33239, 23, 33454, 0, 0, 0),
(33239, 24, 33443, 0, 0, 0),
(33239, 25, 35949, 0, 0, 0),
(33239, 26, 35952, 0, 0, 0),
(33239, 27, 35953, 0, 0, 0),
(33239, 28, 35951, 0, 0, 0),
(33239, 29, 35948, 0, 0, 0),
(33239, 30, 35950, 0, 0, 0);

-- Onyxia eggs cooldown
UPDATE `gameobject_template` SET `data5` = 15 WHERE `entry` = 176511;

-- Spinning pain strike scriptname
DELETE FROM `spell_script_names` WHERE `spell_id` IN (66316,67100,67101,67102) AND `ScriptName`='spell_spinning_pain_strike';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(66316, 'spell_spinning_pain_strike'),
(67100, 'spell_spinning_pain_strike'),
(67101, 'spell_spinning_pain_strike'),
(67102, 'spell_spinning_pain_strike');

-- Fix Holy Concentration proc from Empowerd Renew
DELETE FROM `spell_proc_event` WHERE `entry` IN (34753, 34859, 34860);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES 
(34753, 0, 6, 6144, 4, 4096, 0, 2, 0, 0, 0), -- rank1
(34859, 0, 6, 6144, 4, 4096, 0, 2, 0, 0, 0), -- rank2
(34860, 0, 6, 6144, 4, 4096, 0, 2, 0, 0, 0); -- rank3

-- Fixed spell Wyvern Sting
DELETE FROM `spell_linked_spell` WHERE `comment` = 'Wyvern Sting';

-- Fixed talent Threat of Thassarian of Death Knights
UPDATE `spell_proc_event` SET `SpellFamilyMask0`=`SpellFamilyMask0`|0x00000001 WHERE `entry` IN (66192,66191,65661);

-- Fix a bug when pets chasing target even if it's invisible
DELETE FROM `spell_linked_spell` WHERE `spell_effect` = 54661 AND `spell_trigger` IN (32612,5215,1784);
INSERT INTO `spell_linked_spell` VALUES
(32612,54661,0,'Invisibility Sanctuary Effect'),
(5215,54661,0,'Prowl Sanctuary Effect'),
(1784,54661,0,'Stealth Sanctuary Effect');

-- Fixed shaman's talent Elemental Focus
UPDATE `spell_proc_event` SET `SpellFamilyMask0` = `SpellFamilyMask0` &~ 192 WHERE `entry` = 16164;

-- Fix bug with cannons movement in Strange of Ancients
UPDATE `creature_template` SET `speed_run` = 0  WHERE `entry` in (27894, 32795);

-- Fixed spell Anti-Magic Zone
UPDATE `creature_template` SET `modelid1` = 11686, `unit_flags` = 33554432 WHERE `modelid1` = 4590 AND `entry` = 28306;

-- Fix Druid Enrage spell
DELETE FROM `spell_ranks` WHERE `first_spell_id` = 1178;
INSERT INTO `spell_ranks` VALUES (1178,1178,1),(1178,9635,2);

-- Fixed warlock's talent Empowered Imp
UPDATE `spell_proc_event` set `procFlags` = 0x00010004 WHERE `entry` = 54278;

-- Fixed talent Scent of Blood for death knights
DELETE FROM `spell_proc_event` WHERE `entry` IN (49004,49508,49509);
INSERT INTO `spell_proc_event` (`entry`,`procEx`) VALUES
(49004,0x00000033),
(49508,0x00000033),
(49509,0x00000033);

-- Fixed paladin's talent Blessing of Sanctuary
DELETE FROM `spell_dbc` WHERE `id` = 20912;
INSERT INTO `spell_dbc` (`Id`,`CastingTimeIndex`,`DurationIndex`,`RangeIndex`,`Effect1`,`EffectBasePoints1`,`EffectImplicitTargetA1`,`EffectApplyAuraName1`,`EffectMiscValue1`,`SpellFamilyName`,`Comment`) VALUES
(20912,1,21,1,6,-3,1,87,127,10,'Blessing of Sanctuary Helper (SERVERSIDE)');
-- Blessing of Sanctuary vs Vigilance
UPDATE `spell_group` SET `spell_id` = 68066 WHERE `id` = 1091 and `spell_id` = 47930;
UPDATE `spell_group` SET `spell_id` = 20912 WHERE `id` = 1092 and `spell_id` = 20911;

-- Fixed mage's talent Hot Streak
UPDATE `spell_proc_event` SET `SpellFamilyMask1`=`SpellFamilyMask1`|0x00010000 WHERE `entry` IN (44445,44446,44448);

-- Fix Spring Fling achievement
UPDATE `creature_template` SET `ScriptName` = 'npc_spring_rabbit' WHERE `entry` = 32791;
UPDATE achievement_criteria_data SET value1='186' WHERE (criteria_id='9199') AND (type='6');

-- Fix drop for Damaged Necklace item (43297)
DELETE FROM `creature_loot_template` WHERE `item` = 43297;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(25801, 43297, 0.027, 1, 0, 1, 1),
(26828, 43297, 0.1, 1, 0, 1, 1),
(26862, 43297, 0.1, 1, 0, 1, 1),
(26943, 43297, 0.1, 1, 0, 1, 1),
(27105, 43297, 0.0898, 1, 0, 1, 1),
(27210, 43297, 0.033, 1, 0, 1, 1),
(27860, 43297, 0.0802, 1, 0, 1, 1),
(28022, 43297, 0.024, 1, 0, 1, 1),
(28026, 43297, 0.0167, 1, 0, 1, 1),
(28035, 43297, 0.0197, 1, 0, 1, 1),
(28036, 43297, 0.0138, 1, 0, 1, 1),
(28068, 43297, 0.0493, 1, 0, 1, 1),
(28080, 43297, 0.0341, 1, 0, 1, 1),
(28081, 43297, 0.0194, 1, 0, 1, 1),
(28101, 43297, 0.0366, 1, 0, 1, 1),
(28108, 43297, 0.0161, 1, 0, 1, 1),
(28123, 43297, 0.0201, 1, 0, 1, 1),
(28124, 43297, 0.0127, 1, 0, 1, 1),
(28158, 43297, 0.0142, 1, 0, 1, 1),
(28186, 43297, 0.0456, 1, 0, 1, 1),
(28255, 43297, 0.0392, 1, 0, 1, 1),
(28257, 43297, 0.0272, 1, 0, 1, 1),
(28303, 43297, 0.014, 1, 0, 1, 1),
(28373, 43297, 0.0249, 1, 0, 1, 1),
(28388, 43297, 0.0176, 1, 0, 1, 1),
(28402, 43297, 0.0118, 1, 0, 1, 1),
(28403, 43297, 0.0113, 1, 0, 1, 1),
(28412, 43297, 0.0282, 1, 0, 1, 1),
(28417, 43297, 0.0109, 1, 0, 1, 1),
(28418, 43297, 0.01, 1, 0, 1, 1),
(28443, 43297, 0.0433, 1, 0, 1, 1),
(28465, 43297, 0.0254, 1, 0, 1, 1),
(28494, 43297, 0.0383, 1, 0, 1, 1),
(28504, 43297, 0.0117, 1, 0, 1, 1),
(28538, 43297, 0.0171, 1, 0, 1, 1),
(28565, 43297, 0.0127, 1, 0, 1, 1),
(28575, 43297, 0.0159, 1, 0, 1, 1),
(28600, 43297, 0.022, 1, 0, 1, 1),
(28641, 43297, 0.0176, 1, 0, 1, 1),
(28659, 43297, 0.0471, 1, 0, 1, 1),
(28747, 43297, 0.0079, 1, 0, 1, 1),
(28748, 43297, 0.0192, 1, 0, 1, 1),
(28802, 43297, 0.0259, 1, 0, 1, 1),
(28861, 43297, 0.1, 1, 0, 1, 1),
(28917, 43297, 0.02, 1, 0, 1, 1),
(29323, 43297, 0.0066, 1, 0, 1, 1),
(29329, 43297, 0.0098, 1, 0, 1, 1),
(29330, 43297, 0.016, 1, 0, 1, 1),
(29333, 43297, 0.0107, 1, 0, 1, 1),
(29338, 43297, 0.0191, 1, 0, 1, 1),
(29369, 43297, 0.0263, 1, 0, 1, 1),
(29370, 43297, 0.0107, 1, 0, 1, 1),
(29374, 43297, 0.0345, 1, 0, 1, 1),
(29377, 43297, 0.0074, 1, 0, 1, 1),
(29404, 43297, 0.0239, 1, 0, 1, 1),
(29407, 43297, 0.0083, 1, 0, 1, 1),
(29413, 43297, 0.0193, 1, 0, 1, 1),
(29426, 43297, 0.0135, 1, 0, 1, 1),
(29427, 43297, 0.0348, 1, 0, 1, 1),
(29449, 43297, 0.0136, 1, 0, 1, 1),
(29451, 43297, 0.0161, 1, 0, 1, 1),
(29518, 43297, 0.0159, 1, 0, 1, 1),
(29553, 43297, -2, 1, 0, 1, 1),
(29554, 43297, 0.0098, 1, 0, 1, 1),
(29569, 43297, 0.0121, 1, 0, 1, 1),
(29622, 43297, 0.0244, 1, 0, 1, 1),
(29623, 43297, 0.0232, 1, 0, 1, 1),
(29652, 43297, 0.0127, 1, 0, 1, 1),
(29654, 43297, 0.013, 1, 0, 1, 1),
(29656, 43297, 0.0049, 1, 0, 1, 1),
(29695, 43297, 0.0162, 1, 0, 1, 1),
(29696, 43297, 0.0353, 1, 0, 1, 1),
(29699, 43297, 0.0254, 1, 0, 1, 1),
(29719, 43297, 0.0298, 1, 0, 1, 1),
(29792, 43297, 0.0106, 1, 0, 1, 1),
(29793, 43297, 0.0183, 1, 0, 1, 1),
(29843, 43297, 0.0203, 1, 0, 1, 1),
(29875, 43297, 0.0153, 1, 0, 1, 1),
(29880, 43297, 0.0084, 1, 0, 1, 1),
(29974, 43297, -2, 1, 0, 1, 1),
(30037, 43297, 0.0137, 1, 0, 1, 1),
(30135, 43297, -2, 1, 0, 1, 1),
(30144, 43297, -2, 1, 0, 1, 1),
(30146, 43297, 0.0136, 1, 0, 1, 1),
(30204, 43297, 0.014, 1, 0, 1, 1),
(30205, 43297, 0.0106, 1, 0, 1, 1),
(30208, 43297, 0.0094, 1, 0, 1, 1),
(30222, 43297, -2, 1, 0, 1, 1),
(30243, 43297, 0.0103, 1, 0, 1, 1),
(30250, 43297, 0.013, 1, 0, 1, 1),
(30409, 43297, 0.0171, 1, 0, 1, 1),
(30541, 43297, 0.0278, 1, 0, 1, 1),
(30543, 43297, 0.0104, 1, 0, 1, 1),
(30597, 43297, 0.015, 1, 0, 1, 1),
(30632, 43297, 0.0138, 1, 0, 1, 1),
(30687, 43297, 0.0088, 1, 0, 1, 1),
(30696, 43297, 0.0168, 1, 0, 1, 1),
(30698, 43297, -2, 1, 0, 1, 1),
(30701, 43297, 0.011, 1, 0, 1, 1),
(30725, 43297, 0.0085, 1, 0, 1, 1),
(30751, 43297, 0.0101, 1, 0, 1, 1),
(30831, 43297, 0.0427, 1, 0, 1, 1),
(30856, 43297, 0.0325, 1, 0, 1, 1),
(30860, 43297, 0.012, 1, 0, 1, 1),
(30863, 43297, 0.0149, 1, 0, 1, 1),
(30864, 43297, 0.0261, 1, 0, 1, 1),
(30894, 43297, 0.0496, 1, 0, 1, 1),
(30921, 43297, -1, 1, 0, 1, 1),
(30922, 43297, 0.0142, 1, 0, 1, 1),
(30951, 43297, 0.0555, 1, 0, 1, 1),
(30958, 43297, 0.0362, 1, 0, 1, 1),
(31037, 43297, 0.0397, 1, 0, 1, 1),
(31039, 43297, 0.0367, 1, 0, 1, 1),
(31043, 43297, 0.0284, 1, 0, 1, 1),
(31140, 43297, 0.0113, 1, 0, 1, 1),
(31145, 43297, 0.0222, 1, 0, 1, 1),
(31150, 43297, 0.0454, 1, 0, 1, 1),
(31152, 43297, 0.0186, 1, 0, 1, 1),
(31155, 43297, 0.0129, 1, 0, 1, 1),
(31226, 43297, 0.0545, 1, 0, 1, 1),
(31231, 43297, 0.0185, 1, 0, 1, 1),
(31258, 43297, 0.0091, 1, 0, 1, 1),
(31262, 43297, 0.0124, 1, 0, 1, 1),
(31267, 43297, 0.0094, 1, 0, 1, 1),
(31326, 43297, 0.2, 1, 0, 1, 1),
(31396, 43297, 0.0085, 1, 0, 1, 1),
(31399, 43297, 0.0249, 1, 0, 1, 1),
(31413, 43297, -2, 1, 0, 1, 1),
(31691, 43297, 0.0187, 1, 0, 1, 1),
(31693, 43297, 0.0196, 1, 0, 1, 1),
(31718, 43297, 0.0097, 1, 0, 1, 1),
(31731, 43297, 0.0081, 1, 0, 1, 1),
(31738, 43297, 0.0184, 1, 0, 1, 1),
(31746, 43297, 0.0103, 1, 0, 1, 1),
(31783, 43297, 0.0188, 1, 0, 1, 1),
(31843, 43297, 0.034, 1, 0, 1, 1),
(31847, 43297, 0.0126, 1, 0, 1, 1),
(32149, 43297, 0.0103, 1, 0, 1, 1),
(32164, 43297, 0.0414, 1, 0, 1, 1),
(32181, 43297, 0.0154, 1, 0, 1, 1),
(32236, 43297, 0.0232, 1, 0, 1, 1),
(32238, 43297, 0.008, 1, 0, 1, 1),
(32257, 43297, 0.0168, 1, 0, 1, 1),
(32259, 43297, 0.0096, 1, 0, 1, 1),
(32263, 43297, 0.0472, 1, 0, 1, 1),
(32279, 43297, 0.0353, 1, 0, 1, 1),
(32289, 43297, -1, 1, 0, 1, 1),
(32290, 43297, -1, 1, 0, 1, 1),
(32297, 43297, -1, 1, 0, 1, 1),
(32300, 43297, 0.1, 1, 0, 1, 1),
(16167, 43297, 0.3, 1, 0, 1, 1),
(16154, 43297, 0.1, 1, 0, 1, 1),
(16215, 43297, 0.1, 1, 0, 1, 1),
(30284, 43297, 0.1, 1, 0, 1, 1),
(27732, 43297, 0.1177, 1, 0, 1, 1),
(15980, 43297, 0.1118, 1, 0, 1, 1),
(16168, 43297, 0.0935, 1, 0, 1, 1),
(16194, 43297, 0.0836, 1, 0, 1, 1),
(28837, 43297, 0.0824, 1, 0, 1, 1),
(16034, 43297, 0.0813, 1, 0, 1, 1),
(30453, 43297, 0.0804, 1, 0, 1, 1),
(16145, 43297, 0.0729, 1, 0, 1, 1),
(30682, 43297, 0.0729, 1, 0, 1, 1),
(16297, 43297, 0.0725, 1, 0, 1, 1),
(30680, 43297, 0.0688, 1, 0, 1, 1),
(27966, 43297, 0.0676, 1, 0, 1, 1),
(28965, 43297, 0.0675, 1, 0, 1, 1),
(16216, 43297, 0.065, 1, 0, 1, 1),
(16037, 43297, 0.064, 1, 0, 1, 1),
(16146, 43297, 0.0624, 1, 0, 1, 1),
(27639, 43297, 0.0617, 1, 0, 1, 1),
(26555, 43297, 0.0584, 1, 0, 1, 1),
(27729, 43297, 0.0584, 1, 0, 1, 1),
(16021, 43297, 0.0583, 1, 0, 1, 1),
(29931, 43297, 0.0581, 1, 0, 1, 1),
(26553, 43297, 0.0562, 1, 0, 1, 1),
(16022, 43297, 0.0561, 1, 0, 1, 1),
(29822, 43297, 0.0548, 1, 0, 1, 1),
(29829, 43297, 0.0546, 1, 0, 1, 1),
(28249, 43297, 0.0531, 1, 0, 1, 1),
(28579, 43297, 0.0522, 1, 0, 1, 1),
(27969, 43297, 0.0521, 1, 0, 1, 1),
(27962, 43297, 0.0515, 1, 0, 1, 1),
(27963, 43297, 0.0513, 1, 0, 1, 1),
(27965, 43297, 0.0496, 1, 0, 1, 1),
(26670, 43297, 0.0496, 1, 0, 1, 1),
(16018, 43297, 0.0489, 1, 0, 1, 1),
(29836, 43297, 0.0485, 1, 0, 1, 1),
(26734, 43297, 0.0477, 1, 0, 1, 1),
(26735, 43297, 0.0476, 1, 0, 1, 1),
(26637, 43297, 0.0473, 1, 0, 1, 1),
(26550, 43297, 0.0468, 1, 0, 1, 1),
(29832, 43297, 0.0458, 1, 0, 1, 1),
(29335, 43297, 0.0457, 1, 0, 1, 1),
(30319, 43297, 0.0446, 1, 0, 1, 1),
(29819, 43297, 0.0446, 1, 0, 1, 1),
(29874, 43297, 0.0443, 1, 0, 1, 1),
(30893, 43297, 0.0442, 1, 0, 1, 1),
(30287, 43297, 0.044, 1, 0, 1, 1),
(30660, 43297, 0.0423, 1, 0, 1, 1),
(26554, 43297, 0.0419, 1, 0, 1, 1),
(16017, 43297, 0.0418, 1, 0, 1, 1),
(26669, 43297, 0.0416, 1, 0, 1, 1),
(28578, 43297, 0.0416, 1, 0, 1, 1),
(16036, 43297, 0.041, 1, 0, 1, 1),
(16244, 43297, 0.0406, 1, 0, 1, 1),
(30278, 43297, 0.0402, 1, 0, 1, 1),
(15981, 43297, 0.0391, 1, 0, 1, 1),
(28582, 43297, 0.0389, 1, 0, 1, 1),
(26803, 43297, 0.0388, 1, 0, 1, 1),
(30668, 43297, 0.038, 1, 0, 1, 1),
(28581, 43297, 0.0376, 1, 0, 1, 1),
(30667, 43297, 0.0374, 1, 0, 1, 1),
(23961, 43297, 0.0365, 1, 0, 1, 1),
(30695, 43297, 0.0364, 1, 0, 1, 1),
(27743, 43297, 0.0361, 1, 0, 1, 1),
(26635, 43297, 0.0361, 1, 0, 1, 1),
(16165, 43297, 0.1, 1, 0, 1, 1),
(30286, 43297, 0.0358, 1, 0, 1, 1),
(26830, 43297, 0.0344, 1, 0, 1, 1),
(16164, 43297, 0.0338, 1, 0, 1, 1),
(26696, 43297, 0.0337, 1, 0, 1, 1),
(28838, 43297, 0.0328, 1, 0, 1, 1),
(26626, 43297, 0.0318, 1, 0, 1, 1),
(26621, 43297, 0.0317, 1, 0, 1, 1),
(26636, 43297, 0.0317, 1, 0, 1, 1),
(30414, 43297, 0.0309, 1, 0, 1, 1),
(26728, 43297, 0.0306, 1, 0, 1, 1),
(16163, 43297, 0.0306, 1, 0, 1, 1),
(26729, 43297, 0.0303, 1, 0, 1, 1),
(27960, 43297, 0.0302, 1, 0, 1, 1),
(29820, 43297, 0.0301, 1, 0, 1, 1),
(26722, 43297, 0.0298, 1, 0, 1, 1),
(27736, 43297, 0.0297, 1, 0, 1, 1),
(27633, 43297, 0.0292, 1, 0, 1, 1),
(28836, 43297, 0.0286, 1, 0, 1, 1),
(27871, 43297, 0.0284, 1, 0, 1, 1),
(26716, 43297, 0.0281, 1, 0, 1, 1),
(24069, 43297, 0.028, 1, 0, 1, 1),
(26799, 43297, 0.0272, 1, 0, 1, 1),
(30681, 43297, 0.0265, 1, 0, 1, 1),
(24080, 43297, 0.0262, 1, 0, 1, 1),
(27742, 43297, 0.026, 1, 0, 1, 1),
(30666, 43297, 0.0257, 1, 0, 1, 1),
(24082, 43297, 0.0255, 1, 0, 1, 1),
(27734, 43297, 0.0251, 1, 0, 1, 1),
(30283, 43297, 0.0243, 1, 0, 1, 1),
(26623, 43297, 0.0242, 1, 0, 1, 1),
(28199, 43297, 0.0241, 1, 0, 1, 1),
(16243, 43297, 0.024, 1, 0, 1, 1),
(30285, 43297, 0.0236, 1, 0, 1, 1),
(27640, 43297, 0.0235, 1, 0, 1, 1),
(26641, 43297, 0.023, 1, 0, 1, 1),
(26805, 43297, 0.0223, 1, 0, 1, 1),
(28580, 43297, 0.0223, 1, 0, 1, 1),
(26694, 43297, 0.0217, 1, 0, 1, 1),
(30892, 43297, 0.0215, 1, 0, 1, 1),
(30111, 43297, 0.021, 1, 0, 1, 1),
(32191, 43297, 0.0209, 1, 0, 1, 1),
(16029, 43297, 0.0203, 1, 0, 1, 1),
(29838, 43297, 0.02, 1, 0, 1, 1),
(23960, 43297, 0.0195, 1, 0, 1, 1),
(26727, 43297, 0.0188, 1, 0, 1, 1),
(30277, 43297, 0.0182, 1, 0, 1, 1),
(24078, 43297, 0.0181, 1, 0, 1, 1),
(30179, 43297, 0.0181, 1, 0, 1, 1),
(24085, 43297, 0.0178, 1, 0, 1, 1),
(27635, 43297, 0.0167, 1, 0, 1, 1),
(24071, 43297, 0.0167, 1, 0, 1, 1),
(31015, 43297, -2, 1, 0, 1, 1),
(33537, 43297, 0.0417, 1, 0, 1, 1),
(34196, 43297, 0.1, 1, 0, 1, 1),
(34190, 43297, 0.1, 1, 0, 1, 1),
(34015, 43297, 0.2049, 1, 0, 1, 1),
(34137, 43297, 0.1319, 1, 0, 1, 1),
(34069, 43297, 0.3, 1, 0, 1, 1),
(26926, 43297, 0.0423, 1, 0, 1, 1),
(28442, 43297, 0.042, 1, 0, 1, 1),
(29409, 43297, 0.0311, 1, 0, 1, 1),
(29614, 43297, 0.0297, 1, 0, 1, 1),
(30829, 43297, 0.0325, 1, 0, 1, 1),
(31137, 43297, 0.2, 1, 0, 1, 1),
(31159, 43297, 0.0626, 1, 0, 1, 1),
(31411, 43297, 0.0252, 1, 0, 1, 1),
(32250, 43297, 0.024, 1, 0, 1, 1),
(32285, 43297, 0.0308, 1, 0, 1, 1),
(33430, 43297, 0.1, 1, 0, 1, 1),
(33355, 43297, 0.1, 1, 0, 1, 1),
(34135, 43297, 0.1, 1, 0, 1, 1),
(33527, 43297, 0.1, 1, 0, 1, 1),
(33354, 43297, 0.1, 1, 0, 1, 1),
(34267, 43297, 0.1, 1, 0, 1, 1),
(34085, 43297, 0.1, 1, 0, 1, 1),
(29834, 43297, 0.1, 1, 0, 1, 1),
(33528, 43297, 0.1, 1, 0, 1, 1),
(16020, 43297, 0.0292, 1, 0, 1, 1),
(16025, 43297, 0.0338, 1, 0, 1, 1),
(16193, 43297, 0.0305, 1, 0, 1, 1),
(26624, 43297, 0.0342, 1, 0, 1, 1),
(26800, 43297, 0.0306, 1, 0, 1, 1),
(26801, 43297, 0.0238, 1, 0, 1, 1),
(27744, 43297, 0.0259, 1, 0, 1, 1),
(28732, 43297, 0.0507, 1, 0, 1, 1),
(28734, 43297, 0.0563, 1, 0, 1, 1),
(28920, 43297, 0.0508, 1, 0, 1, 1),
(29450, 43297, 0.0278, 1, 0, 1, 1),
(29503, 43297, 0.0428, 1, 0, 1, 1),
(29920, 43297, 0.0431, 1, 0, 1, 1),
(30071, 43297, 0.0482, 1, 0, 1, 1),
(32353, 43297, 0.0684, 1, 0, 1, 1),
(33431, 43297, 0.0681, 1, 0, 1, 1),
(33525, 43297, 0.1174, 1, 0, 1, 1),
(33699, 43297, 0.0241, 1, 0, 1, 1),
(33722, 43297, 0.0245, 1, 0, 1, 1),
(33754, 43297, 0.0309, 1, 0, 1, 1),
(33755, 43297, 0.0317, 1, 0, 1, 1),
(33818, 43297, 0.0633, 1, 0, 1, 1),
(33819, 43297, 0.0313, 1, 0, 1, 1),
(33822, 43297, 0.0809, 1, 0, 1, 1),
(33823, 43297, 0.2285, 1, 0, 1, 1),
(34086, 43297, 0.0482, 1, 0, 1, 1),
(34197, 43297, 0.0947, 1, 0, 1, 1),
(34198, 43297, 0.0553, 1, 0, 1, 1),
(34199, 43297, 0.0505, 1, 0, 1, 1),
(34269, 43297, 0.097, 1, 0, 1, 1),
(34271, 43297, 0.086, 1, 0, 1, 1),
(34273, 43297, 0.0354, 1, 0, 1, 1),
(34728, 43297, 0.0097, 1, 0, 1, 1),
(34734, 43297, 0.0163, 1, 0, 1, 1),
(34838, 43297, 0.0167, 1, 0, 1, 1),
(35305, 43297, 0.0233, 1, 0, 1, 1),
(35307, 43297, 0.0789, 1, 0, 1, 1),
(35309, 43297, 0.054, 1, 0, 1, 1),
(36829, 43297, 0.8, 1, 0, 1, 1),
(38090, 43297, 1.6949, 1, 0, 1, 1);

-- Grizzly Hills Outdoor PVP script
delete from outdoorpvp_template where typeid in (8);
INSERT INTO `outdoorpvp_template` VALUES
(8,'outdoorpvp_gh','Grizzly Hills');
update creature set spawnMask = 0 where id in (27748, 27708, 29253, 27730, 29251, 27758, 27759, 29252,27760, 29250);
DELETE FROM `trinity_string` WHERE entry BETWEEN 12001 AND 12004;
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES
(12001, 'The Horde has taken the Venture Bay Lighthouse!', NULL, '', NULL, NULL, NULL, NULL, NULL, NULL),
(12002, 'The Alliance has taken the Venture Bay Lighthouse!', NULL, '', NULL, NULL, NULL, NULL, NULL, NULL),
(12003, 'The Horde lost the Venture Bay Lighthouse!', NULL, '', NULL, NULL, NULL, NULL, NULL, NULL),
(12004, 'The Alliance lost the Venture Bay Lighthouse!', NULL, '', NULL, NULL, NULL, NULL, NULL, NULL);   

-- Dalaran Severs arena
UPDATE `gameobject_template` SET `flags` = '36' WHERE `gameobject_template`.`entry` =192642 LIMIT 1 ;
UPDATE `gameobject_template` SET `flags` = '36' WHERE `gameobject_template`.`entry` =192643 LIMIT 1 ;
UPDATE `battleground_template` SET `MinPlayersPerTeam` = '0', `MaxPlayersPerTeam` = '2' WHERE `battleground_template`.`id` =10 LIMIT 1 ;
-- DELETE FROM `disables` WHERE `entry` = 10 ;

-- Mutated Abomination abilities
UPDATE `creature_template` SET `spell1` = 70360, `spell2` = 70539, `spell3` = 70542, `spell4` = 0, `spell5` = 0, `spell6` = 71516, `spell7` = 0, `spell8` = 0 WHERE `entry` IN (37672, 38605, 38786, 38787);
UPDATE `creature_template` SET `spell1` = 72527, `spell2` = 72457, `spell3` = 70542, `spell4` = 0, `spell5` = 0, `spell6` = 71516, `spell7` = 0, `spell8` = 0 WHERE `entry` IN (38285, 38788, 38789, 38790);

-- Fix achievement Ribbon Pole Dance
-- Serverside Spells
DELETE FROM `spell_dbc` WHERE `Id` IN (29710,58934);
INSERT INTO `spell_dbc` (`Id`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `Stances`, `StancesNot`, `Targets`, `CastingTimeIndex`, `AuraInterruptFlags`, `ProcFlags`, `ProcChance`, `ProcCharges`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `Effect1`, `Effect2`, `Effect3`, `EffectDieSides1`, `EffectDieSides2`, `EffectDieSides3`, `EffectRealPointsPerLevel1`, `EffectRealPointsPerLevel2`, `EffectRealPointsPerLevel3`, `EffectBasePoints1`, `EffectBasePoints2`, `EffectBasePoints3`, `EffectMechanic1`, `EffectMechanic2`, `EffectMechanic3`, `EffectImplicitTargetA1`, `EffectImplicitTargetA2`, `EffectImplicitTargetA3`, `EffectImplicitTargetB1`, `EffectImplicitTargetB2`, `EffectImplicitTargetB3`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectRadiusIndex3`, `EffectApplyAuraName1`, `EffectApplyAuraName2`, `EffectApplyAuraName3`, `EffectAmplitude1`, `EffectAmplitude2`, `EffectAmplitude3`, `EffectMultipleValue1`, `EffectMultipleValue2`, `EffectMultipleValue3`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectMiscValue3`, `EffectMiscValueB1`, `EffectMiscValueB2`, `EffectMiscValueB3`, `EffectTriggerSpell1`, `EffectTriggerSpell2`, `EffectTriggerSpell3`, `EffectSpellClassMaskA1`, `EffectSpellClassMaskA2`, `EffectSpellClassMaskA3`, `EffectSpellClassMaskB1`, `EffectSpellClassMaskB2`, `EffectSpellClassMaskB3`, `EffectSpellClassMaskC1`, `EffectSpellClassMaskC2`, `EffectSpellClassMaskC3`, `MaxTargetLevel`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `MaxAffectedTargets`, `DmgClass`, `PreventionType`, `DmgMultiplier1`, `DmgMultiplier2`, `DmgMultiplier3`, `AreaGroupId`, `SchoolMask`, `Comment`) VALUES
('29710','0','0','256','0','0','0','0','0','0','0','0','1','0','0','101','0','0','0','0','0','1','0','-1','0','0','140','0','0','0','0','0','0','0','0','0','0','0','0','0','0','25','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','29531','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','1','1','0','1','Ribbon Pole - Force Cast Ribbon Pole Channel'),
('58934','0','0','536870912','0','0','0','0','0','0','0','0','1','0','0','101','0','0','0','0','0','1','0','-1','0','0','3','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','0','28','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','Burning Hot Pole Dance credit marker');
-- Link Dancer Check Aura and Visual to Ribbon Pole Channel
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (29531,45390);
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(29531,45390,0, 'Ribbon Pole - Dancer Check Aura'),
(45390,45406,2, 'Ribbon Pole - Periodic Visual');
-- Spell Script
DELETE FROM `spell_script_names` WHERE `spell_id`=45390;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(45390, 'spell_gen_ribbon_pole_dancer_check');

-- Add cooldown for Sacred Shield after remove effect as expected
DELETE FROM `spell_script_names` WHERE `spell_id` = 58597;
INSERT INTO `spell_script_names` VALUES
(58597, 'spell_pal_sacred_shield');

-- Typo fix sor scriptname
DELETE FROM `spell_script_names` WHERE `spell_id`= 47496;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(47496, 'spell_dk_ghoul_explode');

-- Scripts/UtgardePinnacle: Fixed harpoon
DELETE FROM `conditions` WHERE `SourceEntry` = 56578 AND `ConditionValue2` = 26693;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`) VALUES 
(13, 56578, 18, 1, 26693);

-- Fixed spells 71871 & 71873
DELETE FROM `spell_proc_event` WHERE `entry` IN (71871); 
DELETE FROM `spell_proc_event` WHERE `entry` IN (71873); 

-- prevent bagouse +300spd for players from this mob http://www.wowhead.com/npc=26828
DELETE FROM `disables` WHERE `sourceType`=0 and `entry` = 51804;
INSERT INTO `disables` (`sourceType` , `entry` , `flags` , `comment`) VALUES 
('0', '51804', '8', 'Power Siphon'); 

-- Fix Paladin Righteous Defense spell (28.10.2011)
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pal_righteous_defense';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(31789,'spell_pal_righteous_defense');

-- Fix Achievement: Bros. Before Ho Ho Ho's(1685) (20.12.2011)
UPDATE item_template SET Flags=0x40 WHERE entry=21519;
UPDATE creature_template SET unit_flags=unit_flags&~0x100, type_flags=type_flags|0x4000000 WHERE entry IN (739,927,1182,1351,1444,5484,5489,5661,8140,12336,26044);
UPDATE creature SET spawntimesecs=20 WHERE id IN (739,927,1182,1351,1444,5484,5489,5661,8140,12336,26044);

-- Revenge of Dalaran squirrel
DELETE FROM `creature_template` WHERE `entry` IN (666666,666667);
INSERT INTO `creature_template` (`entry`, `modelid1`, `name`, `minlevel`, `maxlevel`, `faction_A`, `faction_H`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `type`, `type_flags`, `MovementType`, `InhabitType`, `Health_mod`, `Armor_mod`, `RegenHealth`, `mechanic_immune_mask`, `ScriptName`, `WDBVerified`) VALUES
('666666', '134', 'Squirrel', '1', '1', '7', '7', '1', '0.8', '1', '0', '2000', '2000', '0', '2000', '4.6', '2000', '1', '0', '0', '0', '1', '0', '1', '1', '500', '500', '1', '650886911', 'npc_dalaran_squirrel', '12340'),
('666667', '134', 'Squirrel', '1', '1', '7', '7', '1', '0.8', '1', '0', '2000', '2000', '0', '2000', '4.6', '2000', '1', '0', '0', '0', '1', '0', '1', '1', '500', '500', '1', '650886911', '', '12340');

-- Fix Ogre Pinata item (http://www.wowhead.com/item=46780)
-- Ogre Pinata NPC (http://www.wowhead.com/npc=34632) correct data
UPDATE `creature_template` SET `exp`=2, `faction_A`=7, `faction_H`=7, `mindmg`=420, `maxdmg`=630, `attackpower`=157, `dmg_multiplier`=1.4, `rangeattacktime`=2000, `minrangedmg`=336, `maxrangedmg`=504, `rangedattackpower`=126 WHERE `entry`=34632;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=34632;
-- Ogre Pinata NPC (http://www.wowhead.com/npc=34632) SAI
DELETE FROM `creature_ai_scripts` WHERE `creature_id` = 34632;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=34632 AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(34632, 0, 0, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 65788, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Ogre Pinata - Summon Pie of Candy');

-- Core/Chat: Implement `.banlist playeraccount` and `baninfo playeraccount` commands (04.06.2011)
DELETE FROM `command` WHERE `name` IN ('baninfo playeraccount', 'banlist playeraccount');
INSERT INTO `command` VALUES
('baninfo playeraccount', 3, 'Syntax: .baninfo playeraccount $playerName\r\nWatch full information about a specific ban.'),
('banlist playeraccount', 3, 'Syntax: .banlist playeraccount [$Name]\r\nSearches the banlist for accounts according to a character name pattern.');

-- Implement npc for sale mount for low level. Thanks Easy (20.01.2011)
REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) VALUES (100002, 0, 0, 0, 0, 0, 27153, 0, 0, 0, 'World of Warcraft Transports, Inc.', 'Mount Service', '', 0, 80, 80, 0, 35, 35, 1, 0.75, 2, 1755, 1755, 0, 1504, 1000, 1500, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 'npc_mount');