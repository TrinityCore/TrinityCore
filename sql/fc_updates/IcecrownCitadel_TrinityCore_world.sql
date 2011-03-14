DELETE FROM `creature_template` WHERE `entry`=36672;
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `Ainame`, `MovementType`, `inhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES('36672','0','0','0','0','0','1126','11686','0','0','Coldflame','','','0','80','80','0','21','21','0','1','1.14286','1','0','2','2','0','24','1','0','0','1','33554432','8','0','0','0','0','0','1','1','0','10','1024','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','0','3','1','1','1','0','0','0','0','0','0','0','0','1','0','0','128','npc_coldflame','12340');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (72705, 69147, 69140);
INSERT INTO `spell_script_names` VALUES
('72705', 'spell_marrowgar_coldflame'),
('69147', 'spell_marrowgar_coldflame_trigger'),
('69140', 'spell_marrowgar_coldflame');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (69075, 70834, 70835, 70836);
INSERT INTO `spell_script_names` VALUES 
(69075, 'spell_marrowgar_bone_storm'),
(70834,    'spell_marrowgar_bone_storm'),
(70835,    'spell_marrowgar_bone_storm'),
(70836,    'spell_marrowgar_bone_storm');

-- UPDATEs for Lady Deathwhisper

UPDATE `creature_template` SET `ScriptName`='boss_lady_deathwhisper' WHERE `entry`=36855;
UPDATE `creature_template` SET `ScriptName`='npc_cult_fanatic' WHERE `entry` IN (37890,38009,38135);
UPDATE `creature_template` SET `ScriptName`='npc_cult_adherent' WHERE `entry` IN(37949,38010,38136);
UPDATE `creature_template` SET `ScriptName`='npc_vengeful_shade' WHERE `entry`=38222;

DELETE FROM `spell_script_names` WHERE `spell_id` IN (70903,71236) AND `ScriptName`='spell_cultist_dark_martyrdom';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(70903,'spell_cultist_dark_martyrdom'),
(71236,'spell_cultist_dark_martyrdom');

-- Unused spell scripts for Festergut's Pungent Blight are removed
DELETE FROM `spell_script_names` WHERE `spell_id` IN (69195, 71219, 73031, 73032);

-- DELETE FROM `creature` WHERE `id` = 37824;
REPLACE INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES('201165','37824','631','15','1','0','0','4388.1','3213.29','408.74','3.83972','86400','0','0','25200','0','0','0','0','0','0');
REPLACE INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES('201508','37824','631','15','1','11686','0','4388.1','3213.29','408.74','3.83972','86400','0','0','25200','0','0','0','0','0','0');
REPLACE INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES('201304','37824','631','15','1','11686','0','4324.28','3215.04','408.705','5.58505','86400','0','0','25200','0','0','0','0','0','0');

-- Correct script names for Blood prince council event IN Icecrown Citadel
UPDATE `creature_template` SET `ScriptName` = 'boss_prince_keleseth_icc' WHERE `entry` = 37972;
UPDATE `creature_template` SET `ScriptName` = 'boss_prince_valanar_icc' WHERE `entry` = 37970;
UPDATE `creature_template` SET `ScriptName` = 'boss_prince_taldaram_icc' WHERE `entry` = 37973;

-- Fix Blood Prince Council immunities
UPDATE `creature_template` SET `mechanic_immune_mask`=650854399 WHERE `entry` IN (37970, 37972, 37973, 38401, 38784, 38785, 38399, 38769, 38770, 38400, 38771, 38772);

-- Blood Prince Council update
UPDATE `creature_template` SET `ScriptName` = 'npc_shock_vortex' WHERE `entry` = 38422;
DELETE FROM `creature` WHERE `id` = 38557;
UPDATE `creature_template` SET `ScriptName` = 'npc_kinetic_bomb_target' WHERE `entry` = 38458;
UPDATE `creature_template` SET `lootid`='37970' WHERE `entry`=37973;
UPDATE `creature_template` SET `lootid`='37970' WHERE `entry`=37972;
UPDATE `creature_template` SET `lootid`='38401' WHERE `entry`=38400;
UPDATE `creature_template` SET `lootid`='38401' WHERE `entry`=38399;
UPDATE `creature_template` SET `lootid`='38784' WHERE `entry`=38771;
UPDATE `creature_template` SET `lootid`='38784' WHERE `entry`=38769;
UPDATE `creature_template` SET `lootid`='38785' WHERE `entry`=38772;
UPDATE `creature_template` SET `lootid`='38785' WHERE `entry`=38770;
UPDATE `creature_template` SET `dynamicflags`='9' WHERE `entry` IN (37973, 37972, 38400, 38399, 38771, 38769, 38772, 38770);

-- Blood Queen Lana'thel 
UPDATE `creature_template` SET `ScriptName` = 'boss_blood_queen_lana_thel' WHERE `entry` = 37955;

-- Valithria Dreamwalker
UPDATE `creature_template` SET `unit_flags` = 33554432 WHERE `entry` IN (38186, 38429);
UPDATE `creature_template` SET `faction_A` = 35, `faction_H` = 35 WHERE `entry` = 38429;
UPDATE `creature_template` SET `faction_A` = 14, `faction_H` = 14 WHERE `entry` = 37985;
UPDATE `creature_template` SET `ScriptName` = 'npc_dreamcloud_icc' WHERE `entry` = 38421;
DELETE FROM `spell_script_names` WHERE `spell_id` IN (71301, 71977);
INSERT INTO `spell_script_names` VALUES (71301, 'spell_valithria_summon_portal'), (71977, 'spell_valithria_summon_portal');
DELETE FROM `spell_script_names` WHERE `spell_id` IN (70873, 71941);
INSERT INTO `spell_script_names` VALUES (70873, 'spell_valithria_vigor'), (71941, 'spell_valithria_vigor');
DELETE FROM `spell_script_names` WHERE `spell_id` IN (71157, 29306);
INSERT INTO `spell_script_names` VALUES (71157,  'spell_rotface_plagued_zombie_infected_wound'), (29306, 'spell_rotface_plagued_zombie_infected_wound');
UPDATE `creature` SET `spawntimesecs` = 604800 WHERE `id` IN (38008, 38752);
-- DELETE FROM `creature` WHERE `id` = 38752 AND NOT (`guid` = 10718);
UPDATE `creature` SET `spawntimesecs` = 604800 WHERE `guid` = 10718;
DELETE FROM `creature_template` WHERE `entry` = 38752;
INSERT INTO `creature_template` VALUES (38752, 0, 0, 0, 0, 0, 26623, 0, 0, 0, 'Green Dragon Combat Trigger', '', '', 0, 80, 
80, 2, 16, 16, 0, 1, 1.14286, 1, 1, 1, 2, 0, 1, 1, 2000, 2000, 1, 32832, 8, 0, 0, 0, 0, 0, 1, 2, 126, 7, 8, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, '', 0, 3, 1.35, 1, 1, 0, 0, 0, 0, 0, 0, 0,  0, 1, 358, 803160063, 0, 'npc_icc_combat_stalker', 12340);
REPLACE INTO `spell_script_names` VALUES (70766, 'spell_dream_state');

-- Valithria Dreamwalker UPDATEs
UPDATE `creature_template` SET `ScriptName` = 'npc_column_of_frost_icc' WHERE `entry` = 37918;
UPDATE `creature_template` SET `ScriptName` = 'npc_icc_valithria_gluttonous_abomination' WHERE `entry` = 37886;
UPDATE `creature_template` SET `ScriptName` = 'npc_icc_valithria_rot_worm' WHERE `entry` = 37907;
DELETE FROM `spell_script_names` WHERE `spell_id` IN (70912, 70913, 70914, 70915, 70916);
INSERT INTO `spell_script_names` VALUES
(70912,'spell_valithria_summon_adds'),
(70913,'spell_valithria_summon_adds'),
(70914,'spell_valithria_summon_adds'),
(70915,'spell_valithria_summon_adds'),
(70916,'spell_valithria_summon_adds');
UPDATE `creature_template` SET `ScriptName` = 'npc_icc_valithria_blistering_zombie' WHERE `entry` = 37934;
UPDATE `creature_template` SET `Scriptname` = 'npc_icc_valithria_supressor' WHERE `entry` = 37863;
UPDATE `creature_template` SET `ScriptName` = 'npc_icc_valithria_risen_archmage' WHERE `entry` = 37868;
UPDATE `creature_template` SET `spell1` = 0, `spell2` = 0, `Ainame` = '' WHERE `entry` IN (37868, 37863, 37934);
UPDATE `creature_template` SET `Ainame` = '' WHERE `entry` IN (37868, 37934, 37886, 37863);
UPDATE `creature_template` SET `ScriptName` = 'npc_icc_valithria_blazing_skeleton' WHERE `entry` = 36791;

-- Valithria Dreamwalker UPDATEs
UPDATE `creature_template` SET `ScriptName` = 'npc_column_of_frost_icc' WHERE `entry` = 37918;
UPDATE `creature_template` SET `ScriptName` = 'npc_icc_valithria_gluttonous_abomination' WHERE `entry` = 37886;
UPDATE `creature_template` SET `ScriptName` = 'npc_icc_valithria_mana_void' WHERE `entry` = 38068;
UPDATE `creature_template` SET `ScriptName` = 'npc_icc_valithria_rot_worm' WHERE `entry` = 37907;
DELETE FROM `spell_script_names` WHERE `spell_id` IN (70912, 70913, 70914, 70915, 70916);
INSERT INTO `spell_script_names` VALUES
(70912,'spell_valithria_summon_adds'),
(70913,'spell_valithria_summon_adds'),
(70914,'spell_valithria_summon_adds'),
(70915,'spell_valithria_summon_adds'),
(70916,'spell_valithria_summon_adds');
UPDATE `creature_template` SET `ScriptName` = 'npc_icc_valithria_blistering_zombie' WHERE `entry` = 37934;
UPDATE `creature_template` SET `Scriptname` = 'npc_icc_valithria_supressor' WHERE `entry` = 37863;
UPDATE `creature_template` SET `ScriptName` = 'npc_icc_valithria_risen_archmage' WHERE `entry` = 37868;
UPDATE `creature_template` SET `spell1` = 0, `spell2` = 0, `Ainame` = '' WHERE `entry` IN (37868, 37863, 37934);
UPDATE `creature_template` SET `Ainame` = '' WHERE `entry` IN (37868, 37934, 37886, 37863);
UPDATE `creature_template` SET `ScriptName` = 'npc_icc_valithria_blazing_skeleton' WHERE `entry` = 36791;

-- Sindragosa UPDATEs
-- Rimefang and Spinestalker positions are corrected according to http://www.youtube.com/watch?v=OtprVV-3q1w
-- Creature templates
UPDATE `creature_template` SET `difficulty_entry_1`=38139 WHERE `entry`=37531;
UPDATE `creature_template` SET `difficulty_entry_1`=38151 WHERE `entry`=37532;
UPDATE `creature_template` SET `difficulty_entry_2`=0,`difficulty_entry_3`=0 WHERE `entry`=37533;
UPDATE `creature_template` SET `difficulty_entry_2`=0,`difficulty_entry_3`=0 WHERE `entry`=37534;
UPDATE `creature_template` SET `difficulty_entry_1`=38320,`difficulty_entry_2`=38321,`difficulty_entry_3`=38322 WHERE `entry`=36980;
UPDATE `creature_template` SET `minlevel`=82,`maxlevel`=82,`unit_class`=1,`faction_A`=14,`faction_H`=14,`unit_flags`=`unit_flags`|33554432,`baseattacktime`=2000,`flags_extra`=`flags_extra`|128 WHERE `entry`=38223; -- Icy Blast
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`unit_class`=1,`faction_A`=2209,`faction_H`=2209,`dynamicflags`=8,`baseattacktime`=2000,`equipment_id`=523,`speed_walk`=1,`speed_run`=1.42857 WHERE `entry` IN (37531,38139); -- Frostwarden Handler
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`unit_class`=2,`faction_A`=16,`faction_H`=16,`dynamicflags`=8,`baseattacktime`=2000,`speed_run`=1 WHERE `entry` IN (37532,38151); -- Frostwing Whelp
UPDATE `creature_template` SET `minlevel`=82,`maxlevel`=82,`unit_class`=2,`faction_A`=21,`faction_H`=21,`unit_flags`=`unit_flags`|64,`baseattacktime`=2000,`speed_walk`=2,`speed_run`=1.5873,`MovementType`=2,`InhabitType`=5 WHERE `entry` IN (37533,38220); -- Rimefang
UPDATE `creature_template` SET `minlevel`=82,`maxlevel`=82,`unit_class`=2,`faction_A`=21,`faction_H`=21,`unit_flags`=`unit_flags`|64,`baseattacktime`=2000,`speed_walk`=2,`speed_run`=1.5873,`MovementType`=2,`InhabitType`=5 WHERE `entry` IN (37534,38219); -- Spinestalker
UPDATE `creature_template` SET `minlevel`=83,`maxlevel`=83,`unit_class`=1,`faction_A`=2068,`faction_H`=2068,`unit_flags`=0,`baseattacktime`=1500,`speed_walk`=4.8,`speed_run`=4.28571 WHERE `entry` IN (36853,38265,38266,38267); -- Sindragosa
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`unit_class`=2,`faction_A`=14,`faction_H`=14,`unit_flags`=`unit_flags`|33554944,`baseattacktime`=2000,`flags_extra`=`flags_extra`|128 WHERE `entry`=37186; -- Frost Bomb
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`unit_class`=1,`faction_A`=14,`faction_H`=14,`baseattacktime`=2000,`speed_run`=1 WHERE `entry` IN (36980,38320,38321,38322); -- Ice Tomb
UPDATE `creature_template` SET `RegenHealth`=0 WHERE `entry` IN (36980,38320,38321,38322); -- Ice Tomb health regen

-- Linked respawns
-- SET @GUID := 151761;
-- SET @SPINESTALKER := 207211;
-- SET @RIMEFANG := 207210;
-- DELETE FROM `linked_respawn` WHERE guid IN (@SPINESTALKER,@RIMEFANG) OR `guid` BETWEEN @GUID+22 AND @GUID+51;
-- INSERT INTO `linked_respawn` (`guid`,`linkedGuid`,`linkType`) VALUES
-- (@SPINESTALKER,@SPINESTALKER,0), -- Spinestalker
-- (@RIMEFANG,@RIMEFANG,0), -- Rimefang
-- (@GUID+22,@SPINESTALKER,0), --  Frostwarden Handler
-- (@GUID+23,@RIMEFANG,0), --  Frostwarden Handler
-- (@GUID+24,@SPINESTALKER,0), --  Frostwing Whelp
-- (@GUID+25,@SPINESTALKER,0), --  Frostwing Whelp
-- (@GUID+26,@SPINESTALKER,0), --  Frostwing Whelp
-- (@GUID+27,@SPINESTALKER,0), --  Frostwing Whelp
-- (@GUID+28,@SPINESTALKER,0), --  Frostwing Whelp
-- (@GUID+29,@SPINESTALKER,0), --  Frostwing Whelp
-- (@GUID+30,@SPINESTALKER,0), --  Frostwing Whelp
-- (@GUID+31,@SPINESTALKER,0), --  Frostwing Whelp
-- @GUID+32,@RIMEFANG,0), --  Frostwing Whelp
-- (@GUID+33,@RIMEFANG,0), --  Frostwing Whelp
-- (@GUID+34,@RIMEFANG,0), --  Frostwing Whelp
-- (@GUID+35,@SPINESTALKER,0), --  Frostwing Whelp
-- (@GUID+36,@SPINESTALKER,0), --  Frostwing Whelp
-- (@GUID+37,@RIMEFANG,0), --  Frostwing Whelp
-- (@GUID+38,@RIMEFANG,0), --  Frostwing Whelp
-- (@GUID+39,@RIMEFANG,0), --  Frostwing Whelp
-- (@GUID+40,@SPINESTALKER,0), --  Frostwing Whelp
-- (@GUID+41,@RIMEFANG,0), --  Frostwing Whelp
-- (@GUID+42,@SPINESTALKER,0), --  Frostwing Whelp
-- (@GUID+43,@SPINESTALKER,0), --  Frostwing Whelp
-- (@GUID+44,@SPINESTALKER,0), --  Frostwing Whelp
-- (@GUID+45,@RIMEFANG,0), --  Frostwing Whelp
-- (@GUID+46,@RIMEFANG,0), --  Frostwing Whelp
-- (@GUID+47,@RIMEFANG,0), --  Frostwing Whelp
-- (@GUID+48,@RIMEFANG,0), --  Frostwing Whelp
-- (@GUID+49,@RIMEFANG,0), --  Frostwing Whelp
-- (@GUID+50,@RIMEFANG,0), --  Frostwing Whelp
-- (@GUID+51,@RIMEFANG,0); --  Frostwing Whelp

-- Creature addon
UPDATE `creature_addon` SET `bytes1`=0 WHERE `guid` IN (@SPINESTALKER,@RIMEFANG);

-- Creature model data
UPDATE `creature_model_info` SET `gender`=1 WHERE `modelid`=30362;

-- Gameobject templates
UPDATE `gameobject_template` SET `flags`=33,`faction`=114 WHERE `entry`=202396; -- Ice Wall
UPDATE `gameobject_template` SET `flags`=32,`faction`=114 WHERE `entry`=201722; -- Ice Block

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `id`=202396;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(121712,202396,631,15,1,4309.686,2491.27441,211.170792,0.209439442,0,0,0,0,120,0,0); -- Ice Wall

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=70598;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`Comment`) VALUES
(13,70598,18,1, 'Sindragosa''s Fury - player targets');
-- Fragment of the Nightmare's Corruption drops 100% as of patch 3.0.2
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=-100 WHERE `item` IN (21146,21147,21148,21149);
-- Insert loot for Gently Shaken Gift
DELETE FROM `item_loot_template` WHERE `entry`=21271;
INSERT INTO `item_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(21271,21241,100,1,0,5,5);

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (12822,12996,12972,12989,12758,12955,13049,13060,13102,13133,13134,13135);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
(12822,11,0,0, 'achievement_all_you_can_eat'), -- All You Can Eat (10 player)
(12822,12,0,0, ''), -- All You Can Eat (10 player)
(12996,11,0,0, 'achievement_all_you_can_eat'), -- All You Can Eat (10 player) Heroic
(12996,12,2,0, ''), -- All You Can Eat (10 player) Heroic
(12972,11,0,0, 'achievement_all_you_can_eat'), -- All You Can Eat (25 player)
(12972,12,1,0, ''), -- All You Can Eat (25 player)
(12989,11,0,0, 'achievement_all_you_can_eat'), -- All You Can Eat (25 player) Heroic
(12989,12,3,0, ''), -- All You Can Eat (25 player) Heroic
(12758,12,0,0, ''), -- The Frostwing Halls (10 player) Sindragosa
(12955,12,1,0, ''), -- The Frostwing Halls (25 player) Sindragosa
(13049,12,2,0, ''), -- Heroic: The Frostwing Halls (10 player) Sindragosa
(13060,12,3,0, ''), -- Heroic: The Frostwing Halls (25 player) Sindragosa
(13102,12,0,0, ''), -- Sindragosa kills (Icecrown 10 player)
(13133,12,1,0, ''), -- Sindragosa kills (Icecrown 25 player)
(13134,12,2,0, ''), -- Sindragosa kills (Heroic Icecrown 10 player)
(13135,12,3,0, ''); -- Sindragosa kills (Heroic Icecrown 25 player)
DELETE FROM `areatrigger_scripts` WHERE `entry` IN (5604,5698,5649);
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(5604,'at_sindragosa_lair'),
(5698, 'at_icc_saurfang_portal'),
(5649, 'at_icc_shutdown_traps');

DELETE FROM `creature_text` WHERE `entry`=36853;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(36853,0,0, 'You are fools to have come to this place! The icy winds of Northrend will consume your souls!',1,0,0,0,0,17007, 'Sindragosa - SAY_AGGRO'),
(36853,1,0, 'Suffer, mortals, as your pathetic magic betrays you!',1,0,0,0,0,17014, 'Sindragosa - SAY_UNCHAINED_MAGIC'),
(36853,2,0, '%s prepares to unleash a wave of blistering cold!',3,0,0,0,0,0, 'Sindragosa - EMOTE_WARN_BLISTERING_COLD'),
(36853,3,0, 'Can you feel the cold hand of death upon your heart?',1,0,0,0,0,17013, 'Sindragosa - SAY_BLISTERING_COLD'),
(36853,4,0, 'Aaah! It burns! What sorcery is this?!',1,0,0,0,0,17015, 'Sindragosa - SAY_RESPITE_FOR_A_TORMENTED_SOUL'),
(36853,5,0, 'Your incursion ends here! None shall survive!',1,0,0,0,0,17012, 'Sindragosa - SAY_AIR_PHASE'),
(36853,6,0, 'Now feel my master''s limitless power and despair!',1,0,0,0,0,17016, 'Sindragosa - SAY_PHASE_2'),
(36853,7,0, '%s fires a frozen orb towards $N!',3,0,0,0,0,0, 'Sindragosa - EMOTE_WARN_FROZEN_ORB'),
(36853,8,0, 'Perish!',1,0,0,0,0,17008, 'Sindragosa - SAY_KILL 1'),
(36853,8,1, 'A flaw of mortality...',1,0,0,0,0,17009, 'Sindragosa - SAY_KILL 2'),
(36853,9,0, 'Enough! I tire of these games!',1,0,0,0,0,17011, 'Sindragosa - SAY_BERSERK'),
(36853,10,0, 'Free...at last...',1,0,0,0,0,17010, 'Sindragosa - SAY_DEATH');
UPDATE `creature_template` SET `ScriptName`='boss_sindragosa' WHERE `entry`=36853;
UPDATE `creature_template` SET `ScriptName`='npc_ice_tomb' WHERE `entry`=36980;
UPDATE `creature_template` SET `ScriptName`='npc_spinestalker' WHERE `entry`=37534;
UPDATE `creature_template` SET `ScriptName`='npc_rimefang_icc' WHERE `entry`=37533;
UPDATE `creature_template` SET `ScriptName`='npc_sindragosa_trash' WHERE `entry` IN (37531,37532);
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (70117,70157);
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(70117,70122,1, 'Sindragosa - Icy Grip'),
(70157,69700,2, 'Sindragosa - Ice Tomb resistance');
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_frostwarden_handler_order_whelp';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_frostwarden_handler_focus_fire';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_rimefang_icy_blast';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sindragosa_s_fury';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sindragosa_unchained_magic';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sindragosa_instability';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sindragosa_frost_beacon';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sindragosa_ice_tomb';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sindragosa_ice_tomb_dummy';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sindragosa_ice_tomb_trap';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sindragosa_collision_filter';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(71357,'spell_frostwarden_handler_order_whelp'),
(71350,'spell_frostwarden_handler_focus_fire'),
(71376,'spell_rimefang_icy_blast'),
(70598,'spell_sindragosa_s_fury'),
(69762,'spell_sindragosa_unchained_magic'),
(69766,'spell_sindragosa_instability'),
(70126,'spell_sindragosa_frost_beacon'),
(69712,'spell_sindragosa_ice_tomb'),
(69675,'spell_sindragosa_ice_tomb_dummy'),
(70157,'spell_sindragosa_ice_tomb_trap'),
(69845,'spell_sindragosa_collision_filter'),
(71053,'spell_sindragosa_collision_filter'),
(71054,'spell_sindragosa_collision_filter'),
(71055,'spell_sindragosa_collision_filter'),
(70127,'spell_sindragosa_collision_filter'),
(72528,'spell_sindragosa_collision_filter'),
(72529,'spell_sindragosa_collision_filter'),
(72530,'spell_sindragosa_collision_filter'),
(70117,'spell_sindragosa_collision_filter');

-- Teleports
DELETE FROM `npc_text` WHERE `id` BETWEEN 800000 AND 800006;
INSERT INTO `npc_text` (`id`, `text0_0`) VALUES
(800000, 'Teleport to the Light\'s Hammer'),
(800001, 'Teleport to the Oratory of the Damned.'), 
(800002, 'Teleport to the Rampart of Skulls.'),
(800003, 'Teleport to the Deathbringer\'s Rise.'),
(800004, 'Teleport to the Upper Spire.'),
(800005, 'Teleport to the Sindragosa\'s Lair'),
(800006, 'Teleport to The Frozen Throne');
DELETE FROM `locales_npc_text` WHERE `entry` BETWEEN 800000 AND 800006;
INSERT INTO `locales_npc_text` (`entry`, `Text0_0_loc8`) VALUES
(800000, 'Молот света'),
(800001, 'Молельня проклятых'),
(800002, 'Черепной вал'),
(800003, 'Подъем смертоносного'),
(800004, 'Шпиль'),
(800005, 'Логово Королевы Льда'),
(800006, 'Ледяной трон');

-- Traps
UPDATE `gameobject_template` SET `ScriptName` = 'go_icc_spirit_alarm' WHERE `entry` IN (201814, 201815, 201816, 201817);
DELETE FROM `creature_addon` WHERE `guid` IN (93950, 101906, 101936, 101937, 101939, 101951, 101995, 101996, 115554, 115555, 115742, 115743);
DELETE FROM `waypoint_scripts` WHERE `dataint` = 38879;
DELETE FROM `waypoint_data` WHERE `action` IN (716, 717, 718, 719, 70, 721, 722, 747, 748, 749, 750);

DELETE FROM `spell_script_names` WHERE `spell_id` IN (70536, 70545, 70546, 70547);
INSERT INTO `spell_script_names` VALUES
(70546, 'spell_icc_spirit_alarm'),
(70536, 'spell_icc_spirit_alarm'),
(70545, 'spell_icc_spirit_alarm'),
(70547, 'spell_icc_spirit_alarm');
REPLACE INTO `spell_script_names` VALUES (70461, 'spell_coldflame_trap');
UPDATE `gameobject_template` SET `ScriptName` = 'go_icc_plagueworks_valve' WHERE `entry` IN (201615, 201616);

DELETE FROM `spell_script_names` WHERE `spell_id` IN (70536, 70545, 70546, 70547);
INSERT INTO `spell_script_names` VALUES
(70546, 'spell_icc_spirit_alarm'),
(70536, 'spell_icc_spirit_alarm'),
(70545, 'spell_icc_spirit_alarm'),
(70547, 'spell_icc_spirit_alarm');
REPLACE INTO `spell_script_names` VALUES (70461, 'spell_coldflame_trap');
UPDATE `gameobject_template` SET `ScriptName` = 'go_icc_plagueworks_valve' WHERE `entry` IN (201615, 201616);

-- The Lich King
DELETE FROM `areatrigger_teleport` WHERE `id` = 5718;
UPDATE `creature_template` SET `ScriptName` = 'npc_shambling_horror_icc' WHERE `entry` = 37698;
UPDATE `creature_template` SET `ScriptName` = 'npc_raging_spirit_icc' WHERE `entry` = 36701;
REPLACE INTO `spell_script_names` VALUES
(72743, 'spell_lich_king_defile'),
(72429, 'spell_lich_king_tirion_mass_resurrection'),
(74115, 'spell_lich_king_pain_and_suffering'),
(70501, 'spell_vile_spirit_target_search'),
(68576, 'spell_valkyr_eject_passenger'),
(69030, 'spell_valkyr_target_search'),
(72133, 'spell_lich_king_pain_and_suffering_effect'),
(73789, 'spell_lich_king_pain_and_suffering_effect'),
(73788, 'spell_lich_king_pain_and_suffering_effect'),
(73790, 'spell_lich_king_pain_and_suffering_effect'),
(70498, 'spell_lich_king_vile_spirit_summon'),
(70500, 'spell_lich_king_vile_spirit_summon_visual'),
(68980, 'spell_lich_king_harvest_soul'),
(74325, 'spell_lich_king_harvest_soul');
UPDATE `creature_template` SET `ScriptName` = 'npc_ice_sphere_icc' WHERE `entry` = 36633;
UPDATE `creature_template` SET `ScriptName` = 'npc_defile_icc' WHERE `entry` = 38757;
UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` IN (36609, 39120, 39121, 39122);
UPDATE `creature_template` SET `vehicleid` = 533 WHERE `entry` IN (36609, 39120, 39121, 39122);
UPDATE `creature` SET `position_z` = 1040 WHERE `id` = 22515 AND `map` = 631;
UPDATE `creature_template` SET `modelid1` = 11686 WHERE `entry` IN (36633, 39305, 39306, 39307);
-- Make Invisible Stalker really invisible
UPDATE `creature_template` SET `modelid1` = 11686 WHERE `entry` = 15214;
-- Add Frostmourne platform
REPLACE INTO `gameobject` VALUES (512171,202161,631,15,1,  495.708,-2523.75,1045.95,  3.14159, 7.7568, 0,0,0,604800,100,1);
UPDATE `creature` SET `id` = 36823, `modelid` = 0, `curhealth` = 0, `spawntimesecs` = '604800' WHERE `guid` = 86812;
UPDATE `creature` SET `id` = 36824, `modelid` = 0, `curhealth` = 0, `spawntimesecs` = '604800' WHERE `guid` = 86813;
UPDATE `creature_template` SET `ScriptName` = 'npc_terenas_fighter_icc' WHERE `entry` = 36823;
UPDATE `creature_template` SET `ScriptName` = 'npc_spirit_warden_icc' WHERE `entry` = 36824;
UPDATE `creature_template` SET `dmg_multiplier` = 52 WHERE `entry` = 36824; -- Spirit Warden
UPDATE `creature_template` SET `dmg_multiplier` = 35 WHERE `entry` = 36823; -- Terenas Menethil
-- Achievement criteria for The Lich King
-- Bane of the Fallen King (10 player heroic) 
-- Realm First! Fall of the Lich King (25 player heroic) 
-- The Frozen Throne (10 player) 
-- The Frozen Throne (25 player) 
-- The Light of Dawn (25 player heroic)
DELETE FROM `achievement_criteria_data` where `criteria_id` IN (12825,12818,12764,12909,12826);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(12825, 12, 2, 0, ''),
(12818, 12, 3, 0, ''),
(12764, 12, 0, 0, ''),
(12909, 12, 1, 0, ''),
(12826, 12, 3, 0, '');

-- Blood Prince entries FROM TrinityCore
DELETE FROM `creature_template` WHERE `entry` IN (37970, 37972, 37973, 38401, 38784, 38785, 38399, 38769, 38770, 38400, 38771, 38772);
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `Ainame`, `MovementType`, `inhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) values('37970','38401','38784','38785','0','0','30858','0','0','0','Prince Valanar','','','0','83','83','2','16','16','0','1.6','1.42857','1','3','509','683','0','805','35','0','0','1','536904000','8','0','0','0','0','0','371','535','135','6','108','37970','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','0','3','405','1','1','0','0','0','0','0','0','0','150','0','10092','0','1','boss_prince_valanar_icc','12340');
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `Ainame`, `MovementType`, `inhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) values('37972','38399','38769','38770','0','0','30857','0','0','0','Prince Keleseth','','','0','83','83','2','16','16','0','1.6','1.42857','1','3','509','683','0','805','35','0','0','1','536904000','8','0','0','0','0','0','371','535','135','6','108','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','0','3','405','1','1','0','0','0','0','0','0','0','150','0','10077','0','1','boss_prince_keleseth_icc','12340');
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `Ainame`, `MovementType`, `inhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) values('37973','38400','38771','38772','0','0','30856','0','0','0','Prince Taldaram','','','0','83','83','2','16','16','0','1.6','1.42857','1','3','509','683','0','805','35','0','0','1','536904000','8','0','0','0','0','0','371','535','135','6','108','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','0','3','405','1','1','0','0','0','0','0','0','0','150','0','10091','0','1','boss_prince_taldaram_icc','12340');
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `Ainame`, `MovementType`, `inhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) values('38399','0','0','0','0','0','30857','0','0','0','Prince Keleseth (1)','','','0','83','83','2','16','16','0','1.6','1.42857','1','3','509','683','0','805','70','0','0','1','536904000','8','0','0','0','0','0','371','535','135','6','108','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','0','3','1620','1','1','0','0','0','0','0','0','0','150','0','10077','0','1','','12340');
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `Ainame`, `MovementType`, `inhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) values('38400','0','0','0','0','0','30856','0','0','0','Prince Taldaram (1)','','','0','83','83','2','16','16','0','1.6','1.42857','1','3','509','683','0','805','70','0','0','1','536904000','8','0','0','0','0','0','371','535','135','6','108','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','0','3','1620','1','1','0','0','0','0','0','0','0','150','0','10091','0','1','','12340');
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `Ainame`, `MovementType`, `inhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) values('38401','0','0','0','0','0','30858','0','0','0','Prince Valanar (1)','','','0','83','83','2','16','16','0','1.6','1.42857','1','3','509','683','0','805','35','2000','2000','1','536904000','8','0','0','0','0','0','371','535','100','6','108','38401','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','0','3','1620','1','1','0','0','0','0','0','0','0','150','0','10092','0','1','','12340');
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `Ainame`, `MovementType`, `inhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) values('38769','0','0','0','0','0','30857','0','0','0','Prince Keleseth (2)','','','0','83','83','2','16','16','0','1.6','1.42857','1','3','509','683','0','805','35','0','0','1','536904000','8','0','0','0','0','0','371','535','135','6','108','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','0','3','546.75','1','1','0','0','0','0','0','0','0','150','0','10077','0','1','','12340');
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `Ainame`, `MovementType`, `inhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) values('38770','0','0','0','0','0','30857','0','0','0','Prince Keleseth (3)','','','0','83','83','2','16','16','0','1.6','1.42857','1','3','509','683','0','805','35','0','0','1','536904000','8','0','0','0','0','0','371','535','135','6','108','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','0','3','2187','1','1','0','0','0','0','0','0','0','150','0','10077','0','1','','12340');
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `Ainame`, `MovementType`, `inhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) values('38771','0','0','0','0','0','30856','0','0','0','Prince Taldaram (2)','','','0','83','83','2','16','16','0','1.6','1.42857','1','3','509','683','0','805','35','0','0','1','536904000','8','0','0','0','0','0','371','535','135','6','108','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','0','3','546.75','1','1','0','0','0','0','0','0','0','150','0','10091','0','1','','12340');
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `Ainame`, `MovementType`, `inhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) values('38772','0','0','0','0','0','30856','0','0','0','Prince Taldaram (3)','','','0','83','83','2','16','16','0','1.6','1.42857','1','3','509','683','0','805','35','0','0','1','536904000','8','0','0','0','0','0','371','535','135','6','108','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','0','3','2187','1','1','0','0','0','0','0','0','0','150','0','10091','0','1','','12340');
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `Ainame`, `MovementType`, `inhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) values('38784','0','0','0','0','0','30858','0','0','0','Prince Valanar (2)','','','0','83','83','2','16','16','0','1.6','1.42857','1','3','509','683','0','805','35','2000','2000','1','536904000','8','0','0','0','0','0','371','535','100','6','108','38784','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','0','3','546.75','1','1','0','0','0','0','0','0','0','150','0','10092','0','1','','12340');
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `Ainame`, `MovementType`, `inhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) values('38785','0','0','0','0','0','30858','0','0','0','Prince Valanar (3)','','','0','83','83','2','16','16','0','1.6','1.42857','1','3','509','683','0','805','35','2000','2000','1','536904000','8','0','0','0','0','0','371','535','100','6','108','38785','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','0','3','2187','1','1','0','0','0','0','0','0','0','150','0','10092','0','1','','12340');

-- DELETE FROM `creature` WHERE `id` IN (37970, 37972, 37973);
REPLACE INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) values('201577','37970','631','15','1','0','0','4680.29','2769.24','364.17','3.14159','86400','0','0','1','0','0','0','0','0','0');
REPLACE INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) values('201493','37972','631','15','1','0','0','4682.73','2783.42','364.17','3.14159','86400','0','0','1','0','0','0','0','0','0');
REPLACE INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) values('201286','37973','631','15','1','0','0','4682.89','2755.11','364.17','3.14159','86400','0','0','1','0','0','0','0','0','0');

-- Implement equipment_id fixes
UPDATE `creature_template` set `equipment_id` = 0 WHERE `Entry` IN (37970,37972,37973,38399,38400,38401,38769,38770,38771,38772,38784,38785); 
-- DELETE FROM `creature_addon` WHERE `GUID` IN (82289,88387,95000,138237,13828,138239,138287,138288,138289); 
-- DELETE FROM `conditions` WHERE `SourceEntry` IN (62912,62910,62297,62907,65667,63475,62549,62546);

-- Icecrown Citadel trash
UPDATE `creature_template` SET `ScriptName` = 'npc_deathspeaker_high_priest' WHERE `entry` = 36829;
UPDATE `creature_template` SET `ScriptName` = 'npc_val_kyr_herald' WHERE `entry` = 37098;
UPDATE `creature_template` SET `ScriptName` = 'npc_severed_essence' WHERE `entry` = 38410;
REPLACE INTO `spell_script_names` VALUES (69483, 'spell_icc_dark_reckoning');
UPDATE `creature_template` SET `ScriptName` = 'npc_the_damned' WHERE `entry` = 37011;
UPDATE `creature_template` SET `ScriptName` = 'npc_servant_of_the_throne' WHERE `entry` = 36724;
UPDATE `creature_template` SET `ScriptName` = 'npc_blighted_abomination' WHERE `entry` = 37022;
UPDATE `creature_template` SET `ScriptName` = 'npc_plague_scientist' WHERE `entry` = 37023;
UPDATE `creature_template` SET `ScriptName` = 'npc_decaying_colossus' WHERE `entry` = 36880;
UPDATE `creature_template` SET `ScriptName` = 'npc_pustulating_horror' WHERE `entry` = 10404;
UPDATE `creature_template` SET `ScriptName` = 'npc_ancient_skeletal_soldier' WHERE `entry` = 37012;
REPLACE INTO `spell_script_names` VALUES (70964, 'spell_valithria_vigor'); -- Just to ensure that auras stack
-- Set immunes on Spinestalker, Rimefang, Stinky, Precious, Decaying Colossus, Sister Svalna, Deathbound Ward
UPDATE `creature_template` SET `mechanic_immune_mask` = 667631615 WHERE `entry` IN (37533, 37534, 38219, 38220, 37217, 38103, 37025, 38064, 36880, 37655, 37126, 38258, 37007, 38031);
-- Setting current health of Princes
UPDATE `creature` SET `curhealth` = 1 WHERE `id` IN (37970, 38401, 38784, 38785, 37972, 38399, 38769, 37973, 38400, 38771);

-- Putricide Mutated Abomination spell fix for 10h, 25n and 25h modes
UPDATE `creature_template` SET `spell1` = 70360, `spell2`= 72457, `spell3`= 70542, `VehicleId` = 591 WHERE `entry` = 38788;
UPDATE `creature_template` SET `spell1` = 70360, `spell2`= 72875, `spell3`= 70542, `VehicleId` = 591 WHERE `entry` = 38789;
UPDATE `creature_template` SET `spell1` = 70360, `spell2`= 72876, `spell3`= 70542, `VehicleId` = 591 WHERE `entry` = 38790;

-- Deathbringer Saurfang from TrinityCore
REPLACE INTO `spell_script_names` VALUES
( 72202, 'spell_deathbringer_blood_link'),
( 72178, 'spell_deathbringer_blood_link_aura'),
( 72371, 'spell_deathbringer_blood_power'),
( 72409, 'spell_deathbringer_rune_of_blood'),
( 72447, 'spell_deathbringer_rune_of_blood'),
( 72448, 'spell_deathbringer_rune_of_blood'),
( 72449, 'spell_deathbringer_rune_of_blood'),
( 72380, 'spell_deathbringer_blood_nova'),
( 72438, 'spell_deathbringer_blood_nova'),
( 72439, 'spell_deathbringer_blood_nova'),
( 72440, 'spell_deathbringer_blood_nova');
UPDATE `creature_template` SET `ScriptName`='boss_deathbringer_saurfang' WHERE `entry`=37813;
UPDATE `creature_template` SET `ScriptName`='npc_high_overlord_saurfang_icc' WHERE `entry`=37187;
UPDATE `creature_template` SET `ScriptName`='npc_muradin_bronzebeard_icc' WHERE `entry`=37200;
UPDATE `creature_template` SET `ScriptName`='npc_saurfang_event' WHERE `entry` IN (37920,37830);
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (12778,13036,13035,13037) AND `type` IN (0,11);
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (12778,13036,13035,13037) AND `type` IN (0,11);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
(12778,11,0,0, 'achievement_ive_gone_and_made_a_mess'),
(13036,11,0,0, 'achievement_ive_gone_and_made_a_mess'),
(13035,11,0,0, 'achievement_ive_gone_and_made_a_mess'),
(13037,11,0,0, 'achievement_ive_gone_and_made_a_mess');
-- [10468] ICC texts (Shauren)
DELETE FROM `creature_text` WHERE `entry` IN (36612,36626,36627,36678,36855,37187,37188,37200,37813,37879,37970,37972,37973,38004);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`sound`,`language`,`probability`,`emote`,`duration`,`comment`) VALUES
(36612,0,0,'This is the beginning AND the end, mortals. None may enter the master''s sanctum!',1,16950,0,0,0,0,'Lord Marrowgar - SAY_ENTER_ZONE'),
(36612,1,0,'The Scourge will wash over this world as a swarm of death and destruction!',1,16941,0,0,0,0,'Lord Marrowgar - SAY_AGGRO'),
(36612,2,0,'BONE STORM!',1,16946,0,0,0,0,'Lord Marrowgar - SAY_BONE_STORM'),
(36612,3,0,'Bound by bone!',1,16947,0,0,0,0,'Lord Marrowgar - SAY_BONESPIKE_1'),
(36612,3,1,'Stick Around!',1,16948,0,0,0,0,'Lord Marrowgar - SAY_BONESPIKE_2'),
(36612,3,2,'The only escape is death!',1,16949,0,0,0,0,'Lord Marrowgar - SAY_BONESPIKE_3'),
(36612,4,0,'More bones for the offering!',1,16942,0,0,0,0,'Lord Marrowgar - SAY_KILL_1'),
(36612,4,1,'Languish in damnation!',1,16943,0,0,0,0,'Lord Marrowgar - SAY_KILL_2'),
(36612,5,0,'I see... only darkness...',1,16944,0,0,0,0,'Lord Marrowgar - SAY_DEATH'),
(36612,6,0,'THE MASTER''S RAGE COURSES THROUGH ME!',1,16945,0,0,0,0,'Lord Marrowgar - SAY_BERSERK'),
(36612,7,0,'Lord Marrowgar creates a whirling storm of bone!',3,0,0,0,0,0,'Lord Marrowgar - SAY_BONE_STORM_EMOTE'),
(36626,0,0,'NOOOO! You kill Stinky! You pay!',1,16907,0,0,0,0,'Festergut - SAY_STINKY_DEAD'),
(36626,1,0,'Fun time!',1,16901,0,0,0,0,'Festergut - SAY_AGGRO'),
(36626,2,0,'%s farts.',2,16911,0,0,0,0,'Festergut - EMOTE_GAS_SPORE'),
(36626,3,0,'%s releases Gas Spores!',3,0,0,0,0,0,'Festergut - EMOTE_WARN_GAS_SPORE'),
(36626,4,0,'Gyah! Uhhh, I not feel so good...',1,16906,0,0,0,0,'Festergut - SAY_PUNGENT_BLIGHT'),
(36626,5,0,'%s begins to cast |cFFFF7F00Pungent Blight!|r',3,0,0,0,0,0,'Festergut - EMOTE_WARN_PUNGENT_BLIGHT'),
(36626,6,0,'%s vomits.',2,0,0,0,0,0,'Festergut - EMOTE_PUNGENT_BLIGHT'),
(36626,7,0,'Daddy, I did it!',1,16902,0,0,0,0,'Festergut - SAY_KILL_1'),
(36626,7,1,'Dead, dead, dead!',1,16903,0,0,0,0,'Festergut - SAY_KILL_2'),
(36626,8,0,'Fun time over!',1,16905,0,0,0,0,'Festergut - SAY_BERSERK'),
(36626,9,0,'Da ... Ddy...',1,16904,0,0,0,0,'Festergut - SAY_DEATH'),
(36627,0,0,'What? Precious? Noooooooooo!!!',1,16993,0,0,0,0,'Rotface - SAY_PRECIOUS_DIES'),
(36627,1,0,'WEEEEEE!',1,16986,0,0,0,0,'Rotface - SAY_AGGRO'),
(36627,2,0,'%s begins to cast Slime Spray!',3,0,0,0,0,0,'Rotface - EMOTE_SLIME_SPRAY'),
(36627,3,0,'Icky sticky.',1,16991,0,0,0,0,'Rotface - SAY_SLIME_SPRAY'),
(36627,4,0,'|TInterfaceIconsspell_shadow_unstableaffliction_2.blp:16|t%s begins to cast |cFFFF0000Unstable Ooze Explosion!|r',3,0,0,0,0,0,'Rotface - EMOTE_UNSTABLE_EXPLOSION'),
(36627,5,0,'I think I made an angry poo-poo. It gonna blow!',1,16992,0,0,0,0,'Rotface - SAY_UNSTABLE_EXPLOSION'),
(36627,6,0,'Daddy make toys out of you!',1,16988,0,0,0,0,'Rotface - SAY_KILL_1'),
(36627,6,1,'I brokes-ded it...',1,16987,0,0,0,0,'Rotface - SAY_KILL_2'),
(36627,7,0,'Sleepy Time!',1,16990,0,0,0,0,'Rotface - SAY_BERSERK'),
(36627,8,0,'Bad news daddy...',1,16989,0,0,0,0,'Rotface - SAY_DEATH'),
(36678,0,0,'Just an ordinary gas cloud. But watch out, because that''s no ordinary gas cloud!',1,17119,0,0,432,0,'Professor Putricide - SAY_GASEOUS_BLIGHT'),
(36678,1,0,'Oh, Festergut. You were always my favorite. Next to Rotface. The good news is you left behind so much gas, I can practically taste it!',1,17124,0,0,0,0,'Professor Putricide - SAY_FESTERGUT_DEATH'),
(36678,2,0,'Great news, everyone! The slime is flowing again!',1,17126,0,0,1,0,'Professor Putricide - SAY_ROTFACE_OOZE_FLOOD1'),
(36678,2,1,'Good news, everyone! I''ve fixed the poison slime pipes!',1,17123,0,0,1,0,'Professor Putricide - SAY_ROTFACE_OOZE_FLOOD2'),
(36678,3,0,'Terrible news, everyone, Rotface is dead! But great news everyone, he left behind plenty of ooze for me to use! Whaa...? I''m a poet, and I didn''t know it? Astounding!',1,17146,0,0,0,0,'Professor Putricide - SAY_ROTFACE_DEATH'),
(36678,4,0,'Good news, everyone! I think I perfected a plague that will destroy all life on Azeroth!',1,17114,0,0,0,0,'Professor Putricide - SAY_AGGRO'),
(36678,5,0,'%s begins to cast Unstable Experiment!',3,0,0,0,0,0,'Professor Putricide - EMOTE_UNSTABLE_EXPERIMENT'),
(36678,6,0,'Two oozes, one room! So many delightful possibilities...',1,17122,0,0,0,0,'Professor Putricide - SAY_PHASE_TRANSITION_HEROIC'),
(36678,7,0,'Hmm. I don''t feel a thing. Whaa...? Where''d those come from?',1,17120,0,0,15,0,'Professor Putricide - SAY_TRANSFORM_1'),
(36678,8,0,'Tastes like... Cherry! Oh! Excuse me!',1,17121,0,0,15,0,'Professor Putricide - SAY_TRANSFORM_2'),
(36678,9,0,'|TInterfaceIconsinv_misc_herb_evergreenmoss.blp:16|t%s cast |cFF00FF00Malleable Goo!|r',3,0,0,0,0,0,'Professor Putricide - EMOTE_MALLEABLE_GOO'),
(36678,10,0,'%s cast |cFFFF7F00Choking Gas Bomb!|r',3,0,0,0,0,0,'Professor Putricide - EMOTE_CHOKING_GAS_BOMB'),
(36678,11,0,'Hmm... Interesting...',1,17115,0,0,0,0,'Professor Putricide - SAY_KILL_1'),
(36678,11,1,'That was unexpected!',1,17116,0,0,0,0,'Professor Putricide - SAY_KILL_2'),
(36678,12,0,'Great news, everyone!',1,17118,0,0,0,0,'Professor Putricide - SAY_BERSERK'),
(36678,13,0,'Bad news, everyone! I don''t think I''m going to make it.',1,17117,0,0,0,0,'Professor Putricide - SAY_DEATH'),
(36855,0,0,'You have found your way here, because you are among the few gifted with true vision in a world cursed with blindness.',1,17272,0,0,0,0,'Lady Deathwhisper - SAY_INTRO_1'),
(36855,1,0,'You can see through the fog that hangs over this world like a shroud, and grasp where true power lies.',1,17273,0,0,0,0,'Lady Deathwhisper - SAY_INTRO_2'),
(36855,2,0,'Fix your eyes upon your crude hands: the sinew, the soft meat, the dark blood coursing within.',1,16878,0,0,0,0,'Lady Deathwhisper - SAY_INTRO_3'),
(36855,3,0,'It is a weakness; a crippling flaw.... A joke played by the Creators upon their own creations.',1,17268,0,0,0,0,'Lady Deathwhisper - SAY_INTRO_4'),
(36855,4,0,'The sooner you come to accept your condition as a defect, the sooner you will find yourselves in a position to transcend it.',1,17269,0,0,0,0,'Lady Deathwhisper - SAY_INTRO_5'),
(36855,5,0,'Through our Master, all things are possible. His power is without limit, and his will unbending.',1,17270,0,0,0,0,'Lady Deathwhisper - SAY_INTRO_6'),
(36855,6,0,'Those who oppose him will be destroyed utterly, and those who serve -- who serve wholly, unquestioningly, with utter devotion of mind and soul -- elevated to heights beyond your ken.',1,17271,0,0,0,0,'Lady Deathwhisper - SAY_INTRO_7'),
(36855,7,0,'What is this disturbance?! You dare trespass upon this hallowed ground? This shall be your final resting place.',1,16868,0,0,0,0,'Lady Deathwhisper - SAY_AGGRO'),
(36855,8,0,'Enough! I see I must take matters into my own hands!',1,16877,0,0,0,0,'Lady Deathwhisper - SAY_PHASE_2'),
(36855,9,0,'%s''s Mana Barrier shimmers and fades away!',3,0,0,0,0,0,'Lady Deathwhisper - SAY_PHASE_2_EMOTE'),
(36855,10,0,'You are weak, powerless to resist my will!',1,16876,0,0,0,0,'Lady Deathwhisper - SAY_DOMINATE_MIND'),
(36855,11,0,'Take this blessing and show these intruders a taste of our master''s power.',1,16873,0,0,0,0,'Lady Deathwhisper - SAY_DARK_EMPOWERMENT'),
(36855,12,0,'I release you from the curse of flesh!',1,16874,0,0,0,0,'Lady Deathwhisper - SAY_DARK_TRANSFORMATION'),
(36855,13,0,'Arise and exult in your pure form!',1,16875,0,0,0,0,'Lady Deathwhisper - SAY_ANIMATE_DEAD'),
(36855,14,0,'Do you yet grasp of the futility of your actions?',1,16869,0,0,0,0,'Lady Deathwhisper - SAY_KILL_1'),
(36855,14,1,'Embrace the darkness... Darkness eternal!',1,16870,0,0,0,0,'Lady Deathwhisper - SAY_KILL_2'),
(36855,15,0,'This charade has gone on long enough.',1,16872,0,0,0,0,'Lady Deathwhisper - SAY_BERSERK'),
(36855,16,0,'All part of the masters plan! Your end is... inevitable!',1,16871,0,0,0,0,'Lady Deathwhisper - SAY_DEATH'),
(37187,0,0,'Kor''kron, move out! Champions, watch your backs. The Scourge have been...',1,17103,0,0,22,0,'High Overlord Saurfang - SAY_INTRO_HORDE_1'),
(37187,1,0,'My boy died at the Wrath Gate. I am here only to collect his body.',0,17097,0,0,397,0,'High Overlord Saurfang - SAY_INTRO_HORDE_3'),
(37187,2,0,'We named him Dranosh. It means \"Heart of Draenor\" in orcish. I would not let the warlocks take him. My boy would be safe, hidden away by the elders of Garadar.',0,17098,0,0,1,0,'High Overlord Saurfang - SAY_INTRO_HORDE_5'),
(37187,3,0,'I made a promise to his mother before she died; that I would cross the Dark Portal alone - whether I lived or died, my son would be safe. Untainted...',0,17099,0,0,1,0,'High Overlord Saurfang - SAY_INTRO_HORDE_6'),
(37187,4,0,'Today, I fulfill that promise.',0,17100,0,0,397,0,'High Overlord Saurfang - SAY_INTRO_HORDE_7'),
(37187,5,0,'High Overlord Saurfang charges!',2,17104,0,0,53,0,'High Overlord Saurfang - SAY_INTRO_HORDE_8'),
(37187,6,0,'Behind you lies the body of my only son. Nothing will keep me from him.',0,17094,0,0,0,0,'High Overlord Saurfang - SAY_OUTRO_ALLIANCE_8'),
(37187,7,0,'High Overlord Saurfang walks over to his son and kneels before his son''s body.',2,0,0,0,0,0,'High Overlord Saurfang - SAY_OUTRO_ALLIANCE_12'),
(37187,8,0,'[Orcish] No''ku kil zil''nok ha tar.',0,17096,0,0,0,0,'High Overlord Saurfang - SAY_OUTRO_ALLIANCE_13'),
(37187,9,0,'Higher Overlord Saurfang picks up the body of his son and walks over towards Varian',2,0,0,0,0,0,'High Overlord Saurfang - SAY_OUTRO_ALLIANCE_14'),
(37187,10,0,'I will not forget this... kindness. I thank you, Highness',0,17095,0,0,0,0,'High Overlord Saurfang - SAY_OUTRO_ALLIANCE_15'),
(37187,11,0,'%s coughs.',2,17105,0,0,0,0,'High Overlord Saurfang - SAY_OUTRO_HORDE_1'),
(37187,12,0,'%s weeps over the corpse of his son.',2,17106,0,0,15,0,'High Overlord Saurfang - SAY_OUTRO_HORDE_2'),
(37187,13,0,'You will have a proper ceremony in Nagrand next to the pyres of your mother and ancestors.',0,17101,0,0,0,0,'High Overlord Saurfang - SAY_OUTRO_HORDE_3'),
(37187,14,0,'Honor, young heroes... no matter how dire the battle... Never forsake it!',0,17102,0,0,0,0,'High Overlord Saurfang - SAY_OUTRO_HORDE_4'),
(37188,0,0,'%s cries.',2,16651,0,0,18,0,'Lady Jaina Proudmoore - SAY_OUTRO_ALLIANCE_17'),
(37188,1,0,'It was nothing, your majesty. Just... I''m proud of my king.',0,16652,0,0,0,0,'Lady Jaina Proudmoore - SAY_OUTRO_ALLIANCE_19'),
(37200,0,0,'Let''s get a move on then! Move ou...',1,16974,0,0,0,0,'Muradin Bronzebeard - SAY_INTRO_ALLIANCE_1'),
(37200,1,0,'A lone orc against the might of the Alliance???',1,16970,0,0,0,0,'Muradin Bronzebeard - SAY_INTRO_ALLIANCE_4'),
(37200,2,0,'Charge!!!',1,16971,0,0,0,0,'Muradin Bronzebeard - SAY_INTRO_ALLIANCE_5'),
(37200,3,0,'%s gasps for air.',2,16975,0,0,0,0,'Muradin Bronzebeard - SAY_OUTRO_ALLIANCE_1'),
(37200,4,0,'That was Saurfang''s boy - the Horde commander at the Wrath Gate. Such a tragic end...',0,16976,0,0,0,0,'Muradin Bronzebeard - SAY_OUTRO_ALLIANCE_2'),
(37200,5,0,'What in the... There, in the distance!',0,16977,0,0,0,0,'Muradin Bronzebeard - SAY_OUTRO_ALLIANCE_3'),
(37200,6,0,'A Horde Zeppelin flies up to the rise.',2,0,0,0,0,0,'Muradin Bronzebeard - SAY_OUTRO_ALLIANCE_4'),
(37200,7,0,'Soldiers, fall in! Looks like the Horde are comin'' to take another shot!',1,16978,0,0,0,0,'Muradin Bronzebeard - SAY_OUTRO_ALLIANCE_5'),
(37200,8,0,'The Zeppelin docks, and High Overlord Saurfang hops out, confronting the Alliance soldiers and Muradin',2,0,0,0,0,0,'Muradin Bronzebeard - SAY_OUTRO_ALLIANCE_6'),
(37200,9,0,'Don''t force me hand, orc. We can''t let ye pass.',0,16972,0,0,0,0,'Muradin Bronzebeard - SAY_OUTRO_ALLIANCE_7'),
(37200,10,0,'I... I can''t do it. Get back on yer ship and we''ll spare yer life.',0,16973,0,0,0,0,'Muradin Bronzebeard - SAY_OUTRO_ALLIANCE_9'),
(37200,11,0,'A mage portal from Stormwind appears between the two and Varian Wrynn and Jaina Proudmoore emerge.',2,0,0,0,0,0,'Muradin Bronzebeard - SAY_OUTRO_ALLIANCE_10'),
(37200,12,0,'Right away, yer majesty!',0,16979,0,0,0,0,'Muradin Bronzebeard - SAY_OUTRO_ALLIANCE_21'),
(37813,0,0,'For every Horde soldier that you killed -- for every Alliance dog that fell, the Lich King''s armies grew. Even now the val''kyr work to raise your fallen as Scourge.',1,16701,0,0,0,0,'Deathbringer Saurfang - SAY_INTRO_ALLIANCE_2'),
(37813,1,0,'Things are about to get much worse. Come, taste the power that the Lich King has bestowed upon me!',1,16702,0,0,0,0,'Deathbringer Saurfang - SAY_INTRO_ALLIANCE_3'),
(37813,2,0,'Dwarves...',1,16703,0,0,0,0,'Deathbringer Saurfang - SAY_INTRO_ALLIANCE_6'),
(37813,3,0,'%s immobilizes Muradin and his guards.',2,0,0,0,0,0,'Deathbringer Saurfang - SAY_INTRO_ALLIANCE_7'),
(37813,4,0,'Join me, father. Join me and we will crush this world in the name of the Scourge -- for the glory of the Lich King!',1,16704,0,0,0,0,'Deathbringer Saurfang - SAY_INTRO_HORDE_2'),
(37813,5,0,'Stubborn and old. What chance do you have? I am stronger, and more powerful than you ever were.',1,16705,0,0,5,0,'Deathbringer Saurfang - SAY_INTRO_HORDE_4'),
(37813,6,0,'Pathetic old orc. Come then heroes. Come and face the might of the Scourge!',1,16706,0,0,15,0,'Deathbringer Saurfang - SAY_INTRO_HORDE_9'),
(37813,7,0,'BY THE MIGHT OF THE LICH KING!',1,16694,0,0,0,0,'Deathbringer Saurfang - SAY_AGGRO'),
(37813,8,0,'The ground runs red with your blood!',1,16699,0,0,0,0,'Deathbringer Saurfang - SAY_MARK_OF_THE_FALLEN_CHAMPION'),
(37813,9,0,'Feast, my minions!',1,16700,0,0,0,0,'Deathbringer Saurfang - SAY_BLOOD_BEASTS'),
(37813,10,0,'You are nothing!',1,16695,0,0,0,0,'Deathbringer Saurfang - SAY_KILL_1'),
(37813,10,1,'Your soul will find no redemption here!',1,16696,0,0,0,0,'Deathbringer Saurfang - SAY_KILL_2'),
(37813,11,0,'%s goes into frenzy!',3,0,0,0,0,0,'Deathbringer Saurfang - SAY_FRENZY'),
(37813,12,0,'I have become...DEATH!',1,16698,0,0,0,0,'Deathbringer Saurfang - SAY_BERSERK'),
(37813,13,0,'I... Am... Released.',1,16697,0,0,0,0,'Deathbringer Saurfang - SAY_DEATH'),
(37879,0,0,'Stand down, Muradin. Let a grieving father pass.',0,16690,0,0,0,0,'King Varian Wrynn - SAY_OUTRO_ALLIANCE_11'),
(37879,1,0,'I... I was not at the Wrath Gate, but the soldiers who survived told me much of what happened. Your son fought with honor. He died a hero''s death. He deserves a hero''s burial.',0,16691,0,0,0,0,'King Varian Wrynn - SAY_OUTRO_ALLIANCE_16'),
(37879,2,0,'Jaina? Why are you crying?',0,16692,0,0,0,0,'King Varian Wrynn - SAY_OUTRO_ALLIANCE_18'),
(37879,3,0,'Bah! Muradin, secure the deck and prepare our soldiers for an assault on the upper citadel. I''ll send out another regiment from Stormwind.',0,16693,0,0,0,0,'King Varian Wrynn - SAY_OUTRO_ALLIANCE_20'),
(37970,0,0,'Naxxanar was merely a setback! With the power of the orb, Valanar will have his vengeance!',1,16685,0,0,0,0,'Prince Valanar - SAY_VALANAR_INVOCATION'),
(37970,1,0,'Invocation of Blood jumps to Prince Valanar!',3,0,0,0,0,0,'Prince Valanar - EMOTE_VALANAR_INVOCATION'),
(37970,2,0,'My cup runneth over.',1,16686,0,0,0,0,'Prince Valanar - SAY_VALANAR_SPECIAL'),
(37970,3,0,'%s begins casting Empowered Schock Vortex!',3,0,0,0,0,0,'Prince Valanar - EMOTE_VALANAR_SHOCK_VORTEX'),
(37970,4,0,'Dinner... is served.',1,16681,0,0,0,0,'Prince Valanar - SAY_VALANAR_KILL_1'),
(37970,4,1,'Do you see NOW the power of the Darkfallen?',1,16682,0,0,0,0,'Prince Valanar - SAY_VALANAR_KILL_2'),
(37970,5,0,'BOW DOWN BEFORE THE SAN''LAYN!',1,16684,0,0,0,0,'Prince Valanar - SAY_VALANAR_BERSERK'),
(37970,6,0,'...why...?',1,16683,0,0,0,0,'Prince Valanar - SAY_VALANAR_DEATH'),
(37972,0,0,'Such wondrous power! The Darkfallen Orb has made me INVINCIBLE!',1,16727,0,0,0,0,'Prince Keleseth - SAY_KELESETH_INVOCATION'),
(37972,1,0,'Invocation of Blood jumps to Prince Keleseth!',3,0,0,0,0,0,'Prince Keleseth - EMOTE_KELESETH_INVOCATION'),
(37972,2,0,'Blood will flow!',1,16728,0,0,0,0,'Prince Keleseth - SAY_KELESETH_SPECIAL'),
(37972,3,0,'Were you ever a threat?',1,16723,0,0,0,0,'Prince Keleseth - SAY_KELESETH_KILL_1'),
(37972,3,1,'Truth is found in death.',1,16724,0,0,0,0,'Prince Keleseth - SAY_KELESETH_KILL_2'),
(37972,4,0,'%s cackles maniacally!',2,16726,0,0,0,0,'Prince Keleseth - EMOTE_KELESETH_BERSERK'),
(37972,5,0,'My queen... they come...',1,16725,0,0,0,0,'Prince Keleseth - SAY_KELESETH_DEATH'),
(37973,0,0,'Tremble before Taldaram, mortals, for the power of the orb flows through me!',1,16857,0,0,0,0,'Prince Taldaram - SAY_TALDARAM_INVOCATION'),
(37973,1,0,'Invocation of Blood jumps to Prince Taldaram!',3,0,0,0,0,0,'Prince Taldaram - EMOTE_TALDARAM_INVOCATION'),
(37973,2,0,'Delight in the pain!',1,16858,0,0,0,0,'Prince Taldaram - SAY_TALDARAM_SPECIAL'),
(37973,3,0,'Inferno Flames speed toward $N!',3,0,0,0,0,0,'Prince Taldaram - EMOTE_TALDARAM_FLAME'),
(37973,4,0,'Worm food.',1,16853,0,0,0,0,'Prince Taldaram - SAY_TALDARAM_KILL_1'),
(37973,4,1,'Beg for mercy!',1,16854,0,0,0,0,'Prince Taldaram - SAY_TALDARAM_KILL_2'),
(37973,5,0,'%s laughs.',2,16856,0,0,0,0,'Prince Taldaram - EMOTE_TALDARAM_BERSERK'),
(37973,6,0,'%s gurgles and dies.',2,16855,0,0,0,0,'Prince Taldaram - EMOTE_TALDARAM_DEATH'),
(38004,0,0,'Foolish mortals. You thought us defeated so easily? The San''layn are the Lich King''s immortal soldiers! Now you shall face their might combined!',1,16795,0,0,1,0,'Blood-Queen Lana''thel - SAY_INTRO_1'),
(38004,1,0,'Rise up, brothers, and destroy our enemies.',1,16796,0,0,0,0,'Blood-Queen Lana''thel - SAY_INTRO_2');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (70572,72202);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES 
(13,0,70572,0,18,1,37920,0,0, '', 'Deathbringer Saurfang - Grip of Agony'),
(13,0,70572,0,18,1,37200,0,0, '', 'Deathbringer Saurfang - Grip of Agony'),
(13,0,70572,0,18,1,37187,0,0, '', 'Deathbringer Saurfang - Grip of Agony'),
(13,0,70572,0,18,1,37830,0,0, '', 'Deathbringer Saurfang - Grip of Agony'),
(13,0,72202,0,18,1,37813,0,0, '', 'Deathbringer Saurfang - Blood Link');  
-- [9607] Deathbringer Saurfang Additional Data (By Shauren)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=72260;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,72260,0,18,1,37920,0,0, '', 'Deathbringer Saurfang - Mark of the Fallen Champion heal');

-- [9607] Deathbringer Saurfang (By Shauren)
-- Deathbringer Saurfang
SET @NPCSaurfang10N := 37813;
SET @NPCSaurfang25N := 3781301;
SET @NPCSaurfang10H := 3781302;
SET @NPCSaurfang25H := 3781302;

-- High Overlord Saurfang
SET @NPCOverlord10N := 37187;
SET @NPCOverlord25N := 38156;
SET @NPCOverlord10H := 38637;
SET @NPCOverlord25H := 38638; 

-- Fix factions
UPDATE `creature_template` SET `faction_A`=974, `faction_H`=974 WHERE `entry` IN (@NPCSaurfang10N,@NPCSaurfang25N,@NPCSaurfang10H,@NPCSaurfang25H); -- Deathbringer Saurfang
UPDATE `creature_template` SET `faction_A`=1735, `faction_H`=1735 WHERE `entry` IN (@NPCOverlord10N,@NPCOverlord25N,@NPCOverlord10H,@NPCOverlord25H); -- High Overlord Saurfang
UPDATE `creature_template` SET `faction_A`=1735, `faction_H`=1735 WHERE `entry`=37920; -- Kor'kron Reaver
UPDATE `creature_template` SET `faction_A`=894, `faction_H`=894 WHERE `entry`=37188; -- Jaina Proudmoore
UPDATE `creature_template` SET `faction_A`=1732, `faction_H`=1732 WHERE `entry`=37830; -- Skybreaker Marine
UPDATE `creature_template` SET `faction_A`=1732, `faction_H`=1732 WHERE `entry`=37200; -- Muradin Bronzebeard 