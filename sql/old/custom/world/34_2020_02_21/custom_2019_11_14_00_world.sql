-- Template Updates
-- Nefarian
UPDATE `creature_template` SET `ScriptName`= 'boss_nefarians_end' WHERE `entry`= 41376;
UPDATE `creature_template` SET `speed_walk`= 3.2, `speed_run`= 1.71429, `unit_flags`= 33588032, `unit_flags2`= 134219776, `flags_extra`= 1 | 512, `DamageModifier`= 120, `BaseVariance`= 0.5, `BaseAttackTime`= 1500, `mechanic_immune_mask`= 650854271 WHERE `entry` IN (41376, 51104, 51105, 51106);
-- Onyxia
UPDATE `creature_template` SET `difficulty_entry_1`= 51116, `difficulty_entry_2`= 51117, `difficulty_entry_3` = 51118, `ScriptName`= 'npc_nefarians_end_onyxia' WHERE `entry`= 41270;
UPDATE `creature_template` SET `minlevel`= 88, `maxlevel`= 88, `exp`= 3, `faction`= 16, `speed_walk`= 3.2, `speed_run`= 1.71429, `BaseAttackTime`= 1500, `unit_flags2`= 134219776, `unit_flags`= 537166656, `dynamicflags`= 32, `DamageModifier`= 120, `BaseVariance`= 0.5, `mechanic_immune_mask`= 650854271, `flags_extra`= 1073741824 WHERE `entry` IN (41270, 51116, 51117, 51118);
-- Lord Victor Nefarius
UPDATE `creature_template` SET `ScriptName`= 'npc_nefarians_end_lord_victor_nefarius' WHERE `entry`= 41379;
-- Animated Bone Warrior
UPDATE `creature_template` SET `unit_flags`= 0x8000, `VehicleId`= 846, `speed_run`= 0.857, `speed_walk`= 5.6, `unit_class`= 4, `DamageModifier`= 6, `BaseVariance`= 0.5, `mechanic_immune_mask`= 0x1 | 0x2 | 0x16 | 0x200| 0x2000 | 0x10000 | 0x800000, `ScriptName`= 'npc_nefarians_end_animated_bone_warrior' WHERE `entry`= 41918;
-- Chromatic Prototype
UPDATE `creature_template` SET `difficulty_entry_1`= 51119, `difficulty_entry_2`= 51120, `difficulty_entry_3` = 51121, `ScriptName`= 'npc_nefarians_end_chromatic_prototype' WHERE `entry`= 41948;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `unit_class`= 2, `faction`= 16, `unit_flags`= 32768, `unit_flags2`= 134219776, `mechanic_immune_mask`= 80297855, `flags_extra`= 1073741824 WHERE `entry` IN (41948, 51119, 51120, 51121);
-- Controller Stalker
UPDATE `creature_template` SET `flags_extra`= 128, `AIName`= 'NullCreatureAI' WHERE `entry`= 42856;
-- Invisible Stalker (Cataclysm Boss, Ignore Combat)
UPDATE `creature_template` SET `flags_extra`= 128, `AIName`= 'NullCreatureAI' WHERE `entry`= 42844;
-- Invisible Stalker (Cataclysm Boss, Ignore Combat, Floating)
UPDATE `creature_template` SET `flags_extra`= 128, `AIName`= 'NullCreatureAI' WHERE `entry`= 42098;
-- Orb of Culmination
UPDATE `gameobject_template` SET `ScriptName`= 'go_nefarians_end_orb_of_culmination' WHERE `entry`= 203254;
-- Shadowblaze Flashpoint
UPDATE `creature_template` SET `flags_extra`= 128, `ScriptName`= 'npc_nefarians_end_shadowblaze' WHERE `entry`= 42595;
-- Shadowblaze
UPDATE `creature_template` SET `flags_extra`= 128, `ScriptName`= 'npc_nefarians_end_shadowblaze' WHERE `entry`= 42596;
-- Dominion Stalker
UPDATE `creature_template` SET `flags_extra`= 128, `unit_flags`= 33587200, `AIName`= 'NullCreatureAI' WHERE `entry`= 43656;

-- Spell Scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_bwd_dragon_orb',
'spell_nefarians_end_electrical_charge',
'spell_nefarians_end_lightning_discharge_triggered_periodic_aura',
'spell_nefarians_end_lightning_discharge_cone',
'spell_nefarians_end_lightning_discharge_damage',
'spell_nefarians_end_children_of_deathwing',
'spell_nefarians_end_animate_bones',
'spell_nefarians_end_animate_bones_dummy',
'spell_nefarians_end_shadowflame_breath',
'spell_nefarians_end_jump_down_to_platform',
'spell_nefarians_end_shadow_of_cowardice',
'spell_nefarians_end_onyxia_start_fight_2_effect',
'spell_nefarians_end_empowering_strikes',
'spell_nefarians_end_brushfire_pre_start_periodic',
'spell_nefarians_end_brushfire_start',
'spell_nefarians_end_brushfire_growth',
'spell_nefarians_end_shadowblaze',
'spell_nefarians_end_dominion_dummy',
'spell_nefarians_end_dominion',
'spell_nefarians_end_determine_farthest_portal_stalker',
'spell_nefarians_end_dominion_portal_trigger',
'spell_nefarians_end_free_your_mind',
'spell_nefarians_end_siphon_power',
'spell_nefarians_end_explosive_cinders');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(78219, 'spell_bwd_dragon_orb'),
(78220, 'spell_bwd_dragon_orb'),
(78949, 'spell_nefarians_end_electrical_charge'),
(95793, 'spell_nefarians_end_electrical_charge'),
(77832, 'spell_nefarians_end_lightning_discharge_triggered_periodic_aura'),
(77833, 'spell_nefarians_end_lightning_discharge_cone'),
(77836, 'spell_nefarians_end_lightning_discharge_cone'),
(77943, 'spell_nefarians_end_lightning_discharge_damage'),
(94113, 'spell_nefarians_end_lightning_discharge_damage'),
(94114, 'spell_nefarians_end_lightning_discharge_damage'),
(94115, 'spell_nefarians_end_lightning_discharge_damage'),
(80785, 'spell_nefarians_end_children_of_deathwing'),
(80787, 'spell_nefarians_end_children_of_deathwing'),
(78122, 'spell_nefarians_end_animate_bones'),
(78123, 'spell_nefarians_end_animate_bones_dummy'),
(94077, 'spell_nefarians_end_animate_bones_dummy'),
(94078, 'spell_nefarians_end_animate_bones_dummy'),
(94079, 'spell_nefarians_end_animate_bones_dummy'),
(77826, 'spell_nefarians_end_shadowflame_breath'),
(94124, 'spell_nefarians_end_shadowflame_breath'),
(94125, 'spell_nefarians_end_shadowflame_breath'),
(94126, 'spell_nefarians_end_shadowflame_breath'),
(79205, 'spell_nefarians_end_jump_down_to_platform'),
(80963, 'spell_nefarians_end_shadow_of_cowardice'),
(81517, 'spell_nefarians_end_onyxia_start_fight_2_effect'),
(79329, 'spell_nefarians_end_empowering_strikes'),
(94630, 'spell_nefarians_end_brushfire_pre_start_periodic'),
(79813, 'spell_nefarians_end_brushfire_start'),
(79393, 'spell_nefarians_end_brushfire_growth'),
(81007, 'spell_nefarians_end_shadowblaze'),
(94085, 'spell_nefarians_end_shadowblaze'),
(94086, 'spell_nefarians_end_shadowblaze'),
(94087, 'spell_nefarians_end_shadowblaze'),
(94211, 'spell_nefarians_end_dominion_dummy'),
(79318, 'spell_nefarians_end_dominion'),
(81664, 'spell_nefarians_end_determine_farthest_portal_stalker'),
(81752, 'spell_nefarians_end_dominion_portal_trigger'),
(79323, 'spell_nefarians_end_free_your_mind'),
(79319, 'spell_nefarians_end_siphon_power'),
(79339, 'spell_nefarians_end_explosive_cinders');

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (81198, 81159, 81174, 81176, 81158, 81175, 81177, 78619, 78620, 78682, 77826, 94124, 94125, 94126, 79205, 79813, 79401, 81007, 94085, 94086, 94087) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 81198, 0, 0, 31, 0, 3, 42844, 0, 0, 0, '', 'Electrocute - Target Invisible Stalker'),
(13, 1, 81159, 0, 0, 31, 0, 3, 41270, 0, 0, 0, '', 'Chains A Steel - Target Onyxia'),
(13, 1, 81174, 0, 0, 31, 0, 3, 41270, 0, 0, 0, '', 'Chains B Steel - Target Onyxia'),
(13, 1, 81176, 0, 0, 31, 0, 3, 41270, 0, 0, 0, '', 'Chains C Steel - Target Onyxia'),
(13, 1, 81158, 0, 0, 31, 0, 3, 41270, 0, 0, 0, '', 'Chains A Lightning - Target Onyxia'),
(13, 1, 81175, 0, 0, 31, 0, 3, 41270, 0, 0, 0, '', 'Chains B Lightning - Target Onyxia'),
(13, 1, 81177, 0, 0, 31, 0, 3, 41270, 0, 0, 0, '', 'Chains C Lightning - Target Onyxia'),
(13, 1, 78619, 0, 0, 31, 0, 3, 41376, 0, 0, 0, '', 'Children of Deathwing - Target Nefarian'),
(13, 1, 78620, 0, 0, 31, 0, 3, 41270, 0, 0, 0, '', 'Children of Deathwing - Target Onyxia'),
(13, 1, 78682, 0, 0, 31, 0, 3, 42844, 0, 0, 0, '', 'Hail of Bones - Target Invisible Stalker'),
(13, 4, 77826, 0, 0, 31, 0, 3, 41918, 0, 0, 0, '', 'Shadowflame Breath - Target Animated Bone Warrior'),
(13, 4, 94124, 0, 0, 31, 0, 3, 41918, 0, 0, 0, '', 'Shadowflame Breath - Target Animated Bone Warrior'),
(13, 4, 94125, 0, 0, 31, 0, 3, 41918, 0, 0, 0, '', 'Shadowflame Breath - Target Animated Bone Warrior'),
(13, 4, 94126, 0, 0, 31, 0, 3, 41918, 0, 0, 0, '', 'Shadowflame Breath - Target Animated Bone Warrior'),
(13, 1, 79205, 0, 0, 31, 0, 3, 42098, 0, 0, 0, '', 'Jump down to platform - Target Invisible Stalker'),
(13, 1, 79813, 0, 0, 31, 0, 3, 41918, 0, 0, 0, '', 'Brushfire Start - Target Animated Bone Warrior'),
(13, 1, 79401, 0, 0, 31, 0, 3, 42856, 0, 0, 0, '', 'Brushfire Check Valid Location - Target Controller Stalker'),
(13, 2, 81007, 0, 0, 31, 0, 3, 41918, 0, 0, 0, '', 'Shadowblaze - Target Animated Bone Warrior'),
(13, 2, 94085, 0, 0, 31, 0, 3, 41918, 0, 0, 0, '', 'Shadowblaze - Target Animated Bone Warrior'),
(13, 2, 94086, 0, 0, 31, 0, 3, 41918, 0, 0, 0, '', 'Shadowblaze - Target Animated Bone Warrior'),
(13, 2, 94087, 0, 0, 31, 0, 3, 41918, 0, 0, 0, '', 'Shadowblaze - Target Animated Bone Warrior');

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (41379, 41376, 41270);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
-- Nefarian
(41376, 0, 0, 'The air crackles with electricity!', 41, 0, 100, 0, 0, 0, 43521, 'Nefarian to Player'),
(41376, 1, 0, 'See how the shadowflame animates their bones! They fight at my command!', 14, 0, 100, 0, 0, 20073, 49418, 'Nefarian to Controller Stalker'),
(41376, 2, 0, 'Curse you, mortals! Such a callous disregard for one\'s possessions must be met with extreme force!', 14, 0, 100, 15, 0, 20155, 49420, 'Nefarian to Onyxia'),
(41376, 3, 0, 'I hope you can swim... in molten lava!', 14, 0, 100, 0, 0, 20075, 49421, 'Nefarian'),
(41376, 4, 0, 'I have tried to be an accommodating host, but you simply will not die! Time to throw all pretense aside and just... KILL YOU ALL!', 14, 0, 100, 0, 0, 20077, 49422, 'Nefarian to Nefarian'),
(41376, 5, 0, 'Flesh turns to ash!', 14, 0, 100, 0, 0, 20074, 49419, 'Nefarian'),
(41376, 6, 0, 'It has been a pleasure!', 14, 0, 100, 0, 0, 20079, 49424, 'Nefarian to Player'),
(41376, 6, 1, 'HAH!', 14, 0, 100, 0, 0, 20080, 49425, 'Nefarian to Player'),
(41376, 6, 2, 'You really have to want it!', 14, 0, 100, 0, 0, 20081, 49426, 'Nefarian to Player'),
(41376, 7, 0, 'Defeat has never tasted so bitter...', 14, 0, 100, 0, 0, 20083, 49427, 'Nefarian to Player'),
(41376, 8, 0, 'Mortal minds... So easily manipulated.', 14, 0, 100, 0, 0, 20078, 49423, 'Nefarian'),
-- Lord Victor Nefarius
(41379, 0, 0, 'Ha ha ha ha ha! The heroes have made it to the glorious finale. I take it you are in good spirits? Prepared for the final battle? Then gaze now upon my ultimate creation! RISE, SISTER!', 14, 0, 100, 1, 0, 20066, 41762, 'Lord Victor Nefarius to Player'),
(41379, 1, 0, 'Behold the brood mother, Onyxia, REBORN! Perhaps my finest work.', 14, 0, 100, 22, 0, 20070, 49416, 'Lord Victor Nefarius to Player'),
(41379, 2, 0, 'My dearest sibling, do you hunger? THEN FEAST UPON OUR ENEMIES!', 14, 0, 100, 22, 0, 20071, 49417, 'Lord Victor Nefarius to Player'),
-- Onyxia
(41270, 0, 0, 'Energy begins to arc across Onyxia''s body as her electrical charge increases.', 41, 0, 100, 0, 0, 0, 43631, 'Onyxia to Onyxia'),
(41270, 1, 0, 'The arcing bolts intensify as Onyxia''s electrical charge reaches dangerous levels!', 41, 0, 100, 0, 0, 0, 43632, 'Onyxia to Onyxia');

UPDATE `creature_text` SET `TextRange`= 3 WHERE `CreatureID` IN (41379, 41376, 41270);

-- Addons
DELETE FROM `creature_template_addon` WHERE `entry` IN (35592, 41376, 51104, 51105, 51106, 41270, 41918, 51116, 51117, 51118);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES
(35592, 0, '78173'),
-- Nefarian
(41376, 1, '94132'),
(51104, 1, '94132'),
(51105, 1, '94132'),
(51106, 1, '94132'),
-- Onyxia
(41270, 1, '94132 29266'),
(51116, 1, '94132 29266'),
(51117, 1, '94132 29266'),
(51118, 1, '94132 29266'),
-- Animated Bone Warrior
(41918, 1, '79329');

-- Spawn Groups
DELETE FROM `creature_summon_groups` WHERE `summonerId`= 41376 AND `summonerType`= 0;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES
(41376, 0, 0, 41270, -107.324, -224.6647, -7.330293, 3.141593, 8, 0),
(41376, 0, 0, 42844, -143.6852, -249.2931, -5.34586, 3.141593, 8, 0),
(41376, 0, 0, 42844, -111.4442, -268.6278, -5.34586, 3.141593, 8, 0),
(41376, 0, 0, 42844, -67.22468, -244.3953, -5.34586, 3.141593, 8, 0),
(41376, 0, 0, 42844, -66.85265, -205.3938, -5.34586, 3.141593, 8, 0),
(41376, 0, 0, 42844, -108.5982, -180.2777, -5.34586, 3.141593, 8, 0),
(41376, 0, 0, 42844, -143.3391, -199.5975, -5.34586, 3.141593, 8, 0),
(41376, 0, 0, 42844, -107.2374, -224.5609, -7.330293, 3.141593, 8, 0),
(41376, 0, 0, 42098, -141.3331, -224.6247, 1.512104, 0, 8, 0),
(41376, 0, 0, 42098, -90.35625, -253.4714, 1.46139, 2.111848, 8, 0),
(41376, 0, 0, 42098, -90.22045, -195.6071, 1.505078, 4.118977, 8, 0),
(41376, 0, 1, 42856, -107.2045, -224.5931, 6.571427, 4.118977, 8, 0);

-- Spawns
SET @OGUID := 239510;
DELETE FROM `gameobject` WHERE `guid`= @OGUID;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 203254, 669, 5094, 0, 15, 169, 0, -27.84375, -224.4774, 63.30268, 6.265733, 0, 0, -0.00872612, 0.9999619, 7200, 255, 1, 26365); -- Orb of Culmination (Area: 0 - Difficulty: 6)

SET @CGUID := 259779;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 35592, 669, 5094, 0, 15, 169, 0, 0, 0, -27.80208, -224.4497, 63.34686, 6.248279, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Invisible Stalker (Float, Uninteractible, GiganticAOI) (Area: 0 - Difficulty: 6) (Auras: 78173 - Dragon Orb)
(@CGUID+1, 42098, 669, 5094, 0, 15, 169, 0, 0, 0, -166.655, -224.602, 40.48163, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365); -- Invisible Stalker (Cataclysm Boss, Ignore Combat, Floating) (Area: 0 - Difficulty: 6) (Auras: 78495 - Aura of Dread)

DELETE FROM `creature_addon` WHERE `guid`= @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `auras`) VALUES
(@CGUID+1, '78495');

-- Spawn Groups
DELETE FROM `instance_spawn_groups` WHERE `instanceMapId`= 669;
UPDATE `spawn_group_template` SET `groupFlags`= 4 WHERE `groupId`= 402;
DELETE FROM `spawn_group` WHERE `groupId`= 402 AND `spawnType`= 1 AND `spawnId`= @OGUID;
DELETE FROM `spawn_group` WHERE `groupId`= 402 AND `spawnType`= 0 AND `spawnId` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(402, 1, @OGUID),
(402, 0, @CGUID+0),
(402, 0, @CGUID+1);

-- Npc Text
UPDATE `npc_text` SET `text0_0`= 'A large humanoid hand print is embedded on the surface of the orb. A soft green glow seems to pulse within.', `BroadcastTextID0`= 41760 WHERE `ID`= 16139;

-- Custom Attributes
DELETE FROM `spell_custom_attr` WHERE `entry` IN (77833, 79353);
INSERT INTO `spell_custom_attr` (`entry`, `attributes`) VALUES
(77833, 0x2), -- Electrical Discharge
(79353, 0x2000); -- Shadow of Cowardice

-- Movements
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (42595, 42596, 43656);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(42595, 0, 0, 1, 0), -- Shadowblaze Flashpoint
(42596, 0, 0, 1, 0), -- Shadowblaze
(43656, 0, 0, 1, 1); -- Dominion Stalker

-- Achievement
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`= 15671;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(15671, 11, 0, 0, 'achievement_keeping_it_in_the_family');

-- Currency Loot
DELETE FROM `creature_onkill_reward` WHERE `creature_id` IN (41376, 51104, 51105, 51106);
INSERT INTO `creature_onkill_reward` (`creature_id`, `CurrencyId1`, `CurrencyCount1`) VALUES
(41376, 396, 3500),
(51104, 396, 4500),
(51105, 396, 3500),
(51106, 396, 4500);

-- Gold Loot
UPDATE `creature_template` SET `mingold`= 2500000, `maxgold`= 2500000 WHERE `entry` IN (41376, 51105);
UPDATE `creature_template` SET `mingold`= 6250000, `maxgold`= 6250000 WHERE `entry` IN (51104, 51106);

-- Item Loot
UPDATE `creature_template` SET `lootid`= `entry` WHERE `entry` IN (41376, 51104, 51105, 51106);
DELETE FROM `creature_loot_template` WHERE `Entry` IN (41376, 51104, 51105, 51106);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `Reference`, `MinCount`, `MaxCount`, `GroupId`) VALUES
-- 10n
(41376, 413760, 100, 1, 413760, 2, 2, 0),
(41376, 63682, 0, 1, 0, 1, 1, 1),
(41376, 63683, 0, 1, 0, 1, 1, 1),
(41376, 63684, 0, 1, 0, 1, 1, 1),
-- 25n
(51104, 413760, 100, 1, 413760, 5, 5, 0),
(51104, 63682, 0, 1, 0, 1, 1, 1),
(51104, 63683, 0, 1, 0, 1, 1, 1),
(51104, 63684, 0, 1, 0, 1, 1, 1),
-- 10hc
(51105, 413761, 100, 1, 413761, 2, 2, 0),
(51105, 65000, 0, 1, 0, 1, 1, 1),
(51105, 65001, 0, 1, 0, 1, 1, 1),
(51105, 65002, 0, 1, 0, 1, 1, 1),
-- 25hc
(51106, 413761, 100, 1, 413761, 5, 5, 0),
(51106, 65000, 0, 1, 0, 1, 1, 1),
(51106, 65001, 0, 1, 0, 1, 1, 1),
(51106, 65002, 0, 1, 0, 1, 1, 1);

DELETE FROM `reference_loot_template` WHERE `Entry` IN (413760, 413761);
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
-- Normal Difficulty
(413760, 59222, 0, 1, 1, 1 ,1),
(413760, 59321, 0, 1, 1, 1 ,1),
(413760, 59337, 0, 1, 1, 1 ,1),
(413760, 59356, 0, 1, 1, 1 ,1),
(413760, 59441, 0, 1, 1, 1 ,1),
(413760, 59442, 0, 1, 1, 1 ,1),
(413760, 59443, 0, 1, 1, 1 ,1),
(413760, 59444, 0, 1, 1, 1 ,1),
(413760, 59450, 0, 1, 1, 1 ,1),
(413760, 59454, 0, 1, 1, 1 ,1),
(413760, 59457, 0, 1, 1, 1 ,1),
(413760, 59459, 0, 1, 1, 1 ,1),
(413760, 63679, 0, 1, 1, 1 ,1),
-- Heroic Difficulty
(413761, 65003, 0, 1, 1, 1 ,1),
(413761, 65017, 0, 1, 1, 1 ,1),
(413761, 65018, 0, 1, 1, 1 ,1),
(413761, 65019, 0, 1, 1, 1 ,1),
(413761, 65022, 0, 1, 1, 1 ,1),
(413761, 65023, 0, 1, 1, 1 ,1),
(413761, 65024, 0, 1, 1, 1 ,1),
(413761, 65025, 0, 1, 1, 1 ,1),
(413761, 65026, 0, 1, 1, 1 ,1),
(413761, 65027, 0, 1, 1, 1 ,1),
(413761, 65043, 0, 1, 1, 1 ,1),
(413761, 65057, 0, 1, 1, 1 ,1),
(413761, 65074, 0, 1, 1, 1 ,1);
