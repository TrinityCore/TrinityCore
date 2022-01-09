SET @BOSS_IMMUNITY_MASK := 0x0 | 0x1 | 0x2 | 0x4 | 0x10 | 0x20 | 0x40 | 0x100 | 0x200 | 0x400 | 0x800 | 0x1000 | 0x2000 | 0x10000 | 0x20000 | 0x800000 | 0x2000000 | 0x4000000;
SET @FRAGMENT_IMMUNITY_MASK := 0x0 | 0x1 | 0x2 | 0x4 | 0x10 | 0x200 | 0x400 | 0x800 | 0x1000| 0x2000 | 0x10000 | 0x20000| 0x800000;
SET @OBSIDIAN_IMMUNITY_MASK := 0x0 | 0x1 | 0x2 | 0x4 | 0x10 | 0x200| 0x2000 | 0x10000 | 0x20000| 0x800000;

-- Lord Rhyolith
UPDATE `creature_template` SET `ScriptName`= 'boss_lord_rhyolith' WHERE `entry`= 52558;
UPDATE `creature_template` SET `unit_flags`= 0x40 | 0x8000, `unit_flags2`= 0x4000000 | 0x1000000| 0x800, `VehicleId`= 1606, `flags_extra`= 0x100 WHERE `entry` IN (52558, 52559, 52560, 52561, 54192, 54193, 54194, 54195, 54199, 54200, 54201, 54202);
UPDATE `creature_template` SET `unit_flags`= 0x40 | 0x8000, `unit_flags2`= 0x1000000| 0x800, `VehicleId`= 1606, `flags_extra`= 0x1 | 0x200000 WHERE `entry` IN (53772, 53773, 53774, 53775);
UPDATE `creature_template` SET `flags_extra`= `flags_extra` | 0x40000000, `mechanic_immune_mask`= @BOSS_IMMUNITY_MASK WHERE `entry` IN (52558, 52559, 52560, 52561, 54192, 54193, 54194, 54195, 54199, 54200, 54201, 54202, 53772, 53773, 53774, 53775);
UPDATE `creature_template` SET `DamageModifier`= 250, `BaseVariance`= 0.5 WHERE `entry` IN (53772, 53773, 53774, 53775);
-- Feet
UPDATE `creature_template` SET `ScriptName`= 'npc_rhyolith_foot' WHERE `entry` IN (52577, 53087);
UPDATE `creature_template` SET `difficulty_entry_1`= 53358, `difficulty_entry_2`= 53719, `difficulty_entry_3`= 53720 WHERE `entry`= 52577;
UPDATE `creature_template` SET `difficulty_entry_1`= 53359, `difficulty_entry_2`= 53721, `difficulty_entry_3`= 53722 WHERE `entry`= 53087;
UPDATE `creature_template` SET `exp`= 3, `minlevel`= 88, `maxlevel`= 88, `faction`= 16, `unit_flags`= 0x40, `unit_flags2`= 0, `RegenHealth`= 0, `mechanic_immune_mask`= @BOSS_IMMUNITY_MASK, `flags_extra`= 0x40000000 | 0x100 WHERE `entry` IN (52577, 53087, 53358, 53719, 53720, 53359, 53721, 53722);
-- Movement Controller
UPDATE `creature_template` SET `ScriptName`= 'npc_rhyolith_movement_controller_lord_rhyolith' WHERE `entry`= 52659;
-- Volcano
UPDATE `creature_template` SET `AIName`= '', `ScriptName`= 'npc_rhyolith_volcano' WHERE `entry`= 52582;
UPDATE `creature_template` SET `unit_flags`= 0x40 | 0x2000000, `unit_flags2`= 0x8000, `flags_extra`= 0x2 WHERE `entry` IN (52582, 54071, 52866);
-- Pillar
UPDATE `creature_template` SET `unit_flags` = `unit_flags`= 0x40 | 0x2000000, `flags_extra`= 0x80 WHERE `entry`= 53122;
-- Fragment of Rhyolith
UPDATE `creature_template` SET `difficulty_entry_1`= 53246, `difficulty_entry_2`= 53653, `difficulty_entry_3`= 53654 WHERE `entry`= 52620;
UPDATE `creature_template` SET  `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `faction`= 834, `mechanic_immune_mask`= @FRAGMENT_IMMUNITY_MASK, `flags_extra`= 0x40000000 WHERE `entry` IN (52620, 53246, 53653, 53654);
UPDATE `creature_template` SET `DamageModifier`= 20, `BaseVariance`= 0.5 WHERE `entry` IN (52620, 53653);
UPDATE `creature_template` SET `DamageModifier`= 40, `BaseVariance`= 0.5 WHERE `entry` IN (53246, 53654);
-- Spark of Ryholith
UPDATE `creature_template` SET `difficulty_entry_1`= 53247, `difficulty_entry_2`= 53650, `difficulty_entry_3`= 53651 WHERE `entry`= 53211;
UPDATE `creature_template` SET  `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `faction`= 834, `mechanic_immune_mask`= @FRAGMENT_IMMUNITY_MASK, `flags_extra`= 0x40000000 WHERE `entry` IN (53211, 53247, 53650, 53651);
UPDATE `creature_template` SET `DamageModifier`= 50, `BaseVariance`= 0.5 WHERE `entry` IN (53211, 53650);
UPDATE `creature_template` SET `DamageModifier`= 100, `BaseVariance`= 0.5 WHERE `entry` IN (53247, 53651);
-- Unleashed Flame
UPDATE `creature_template` SET `unit_flags`= 0x2000000, `flags_extra`= 128, `AIName`= 'NullCreatureAI' WHERE `entry`= 54347;
-- Liquid Obsidian
UPDATE `creature_template` SET `difficulty_entry_1`= 53248, `difficulty_entry_2`= 53725, `difficulty_entry_3`= 53726, `ScriptName`= 'npc_rhyolith_liquid_obsidian' WHERE `entry`= 52619;
UPDATE `creature_template` SET  `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `faction`= 834, `mechanic_immune_mask`= @OBSIDIAN_IMMUNITY_MASK, `flags_extra`= 0x40000000 | 0x100 WHERE `entry` IN (52619, 53248, 53725, 53726);

DELETE FROM `spell_dbc` WHERE `Id` IN (98192, 103019, 98266);
INSERT INTO `spell_dbc` (`Id`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `CastingTimeIndex`, `DurationIndex`, `RangeIndex`, `SchoolMask`, `SpellName`) VALUES
(98192, 0x20000100, 0x10000000, 0x00000004, 0x00040000, 1, 21, 13, 1, '(Serverside/Non-DB2) Foot Damage Tracker'),
(103019, 0, 0, 0, 0, 1, 0, 0, 0, '(Serverside/Non-DB2) Start Fight'),
(98266, 0, 0, 0x4, 0, 1, 21, 13, 0, '(Serverside/Non-DB2) Summon Tube');

DELETE FROM `spelleffect_dbc` WHERE `Id`= 160113;
INSERT INTO `spelleffect_dbc` (`Id`, `Effect`, `EffectAmplitude`, `EffectAura`, `EffectBasePoints`, `EffectMiscValue`, `EffectMiscValueB`, `EffectImplicitTargetA`, `SpellId`, `EffectIndex`, `Comment`) VALUES
(160113, 28, 0, 0, 0, 53122, 64, 87, 98266, 0, 'Summon Tube - Effect 0');

DELETE FROM `creature_text` WHERE `CreatureID` IN (52558, 53772, 54192, 54199);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
-- Base entry
(52558, 0, 0, 'Hah? Hruumph? Soft little fleshy-things? Here? Nuisances, nuisances!', 14, 0, 100, 0, 0, 24537, 52229, 'Lord Rhyolith - Engage'),
(52558, 1, 0, 'I\'ll crush you underfoot!', 14, 0, 100, 0, 0, 24557, 52239, 'Lord Rhyolith - Concussive Stomp 1'),
(52558, 1, 1, 'Stomp now.', 14, 0, 100, 0, 0, 24556, 52238, 'Lord Rhyolith - Concussive Stomp 2'),
(52558, 2, 0, '%s begins to drink from the magma pools.', 41, 0, 100, 0, 0, 0, 52585, 'Lord Rhyolith - Announce Drink Magma'),
(52558, 3, 0, 'Buuurrrnn!', 14, 0, 100, 0, 0, 24550, 52241, 'Lord Rhyolith - Heated Volcano 1'),
(52558, 3, 1, 'Succumb to living flame.', 14, 0, 100, 0, 0, 24551, 52242, 'Lord Rhyolith - Heated Volcano 2'),
(52558, 4, 0, '%s\'s armor is weakened by the active volcano.', 41, 0, 100, 0, 0, 0, 51876, 'Lord Rhyolith - Announce Obsidian Armor Weakened'),
(52558, 5, 0, 'Uurrghh now you... you infuriate me!', 14, 0, 100, 0, 0, 24543, 52236, 'Lord Rhyolith - Obsidian Armor Weakened 1'),
(52558, 5, 1, 'Oww now hey.', 14, 0, 100, 0, 0, 24540, 52233, 'Lord Rhyolith - Obsidian Armor Weakened 2'),
(52558, 5, 2, 'Graaahh!', 14, 0, 100, 0, 0, 24541, 52234, 'Lord Rhyolith - Obsidian Armor Weakened 3'),
(52558, 5, 3, 'Augh - smooshy little pests, look what you\'ve done!', 14, 0, 100, 0, 0, 24542, 52235, 'Lord Rhyolith - Obsidian Armor Weakened 4'),
(52558, 9, 0, 'Finished.', 14, 0, 100, 0, 0, 24546, 52230, 'Lord Rhyolith - Slay 1'),
(52558, 9, 1, 'So soft!', 14, 0, 100, 0, 0, 24547, 52231, 'Lord Rhyolith - Slay 2'),
(52558, 9, 2, 'Squeak, little pest.', 14, 0, 100, 0, 0, 24548, 52232, 'Lord Rhyolith - Slay 3'),
-- Damaged 1 entry
(54192, 0, 0, 'Hah? Hruumph? Soft little fleshy-things? Here? Nuisances, nuisances!', 14, 0, 100, 0, 0, 24537, 52229, 'Lord Rhyolith - Engage'),
(54192, 1, 0, 'I\'ll crush you underfoot!', 14, 0, 100, 0, 0, 24557, 52239, 'Lord Rhyolith - Concussive Stomp 1'),
(54192, 1, 1, 'Stomp now.', 14, 0, 100, 0, 0, 24556, 52238, 'Lord Rhyolith - Concussive Stomp 2'),
(54192, 2, 0, '%s begins to drink from the magma pools.', 41, 0, 100, 0, 0, 0, 52585, 'Lord Rhyolith - Announce Drink Magma'),
(54192, 3, 0, 'Buuurrrnn!', 14, 0, 100, 0, 0, 24550, 52241, 'Lord Rhyolith - Heated Volcano 1'),
(54192, 3, 1, 'Succumb to living flame.', 14, 0, 100, 0, 0, 24551, 52242, 'Lord Rhyolith - Heated Volcano 2'),
(54192, 4, 0, '%s\'s armor is weakened by the active volcano.', 41, 0, 100, 0, 0, 0, 51876, 'Lord Rhyolith - Announce Obsidian Armor Weakened'),
(54192, 5, 0, 'Uurrghh now you... you infuriate me!', 14, 0, 100, 0, 0, 24543, 52236, 'Lord Rhyolith - Obsidian Armor Weakened'),
(54192, 5, 1, 'Oww now hey.', 14, 0, 100, 0, 0, 24540, 52233, 'Lord Rhyolith - Obsidian Armor Weakened'),
(54192, 5, 2, 'Graaahh!', 14, 0, 100, 0, 0, 24541, 52234, 'Lord Rhyolith - Obsidian Armor Weakened 3'),
(54192, 5, 3, 'Augh - smooshy little pests, look what you\'ve done!', 14, 0, 100, 0, 0, 24542, 52235, 'Lord Rhyolith - Obsidian Armor Weakened 4'),
(54192, 9, 0, 'Finished.', 14, 0, 100, 0, 0, 24546, 52230, 'Lord Rhyolith - Slay 1'),
(54192, 9, 1, 'So soft!', 14, 0, 100, 0, 0, 24547, 52231, 'Lord Rhyolith - Slay 2'),
(54192, 9, 2, 'Squeak, little pest.', 14, 0, 100, 0, 0, 24548, 52232, 'Lord Rhyolith - Slay 3'),
-- Damaged 2 entry
(54199, 0, 0, 'Hah? Hruumph? Soft little fleshy-things? Here? Nuisances, nuisances!', 14, 0, 100, 0, 0, 24537, 52229, 'Lord Rhyolith - Engage'),
(54199, 1, 0, 'I\'ll crush you underfoot!', 14, 0, 100, 0, 0, 24557, 52239, 'Lord Rhyolith - Concussive Stomp 1'),
(54199, 1, 1, 'Stomp now.', 14, 0, 100, 0, 0, 24556, 52238, 'Lord Rhyolith - Concussive Stomp 2'),
(54199, 2, 0, '%s begins to drink from the magma pools.', 41, 0, 100, 0, 0, 0, 52585, 'Lord Rhyolith - Announce Drink Magma'),
(54199, 3, 0, 'Buuurrrnn!', 14, 0, 100, 0, 0, 24550, 52241, 'Lord Rhyolith - Heated Volcano 1'),
(54199, 3, 1, 'Succumb to living flame.', 14, 0, 100, 0, 0, 24551, 52242, 'Lord Rhyolith - Heated Volcano 2'),
(54199, 4, 0, '%s\'s armor is weakened by the active volcano.', 41, 0, 100, 0, 0, 0, 51876, 'Lord Rhyolith - Announce Obsidian Armor Weakened'),
(54199, 5, 0, 'Uurrghh now you... you infuriate me!', 14, 0, 100, 0, 0, 24543, 52236, 'Lord Rhyolith - Obsidian Armor Weakened'),
(54199, 5, 1, 'Oww now hey.', 14, 0, 100, 0, 0, 24540, 52233, 'Lord Rhyolith - Obsidian Armor Weakened'),
(54199, 5, 2, 'Graaahh!', 14, 0, 100, 0, 0, 24541, 52234, 'Lord Rhyolith - Obsidian Armor Weakened 3'),
(54199, 5, 3, 'Augh - smooshy little pests, look what you\'ve done!', 14, 0, 100, 0, 0, 24542, 52235, 'Lord Rhyolith - Obsidian Armor Weakened 4'),
(54199, 9, 0, 'Finished.', 14, 0, 100, 0, 0, 24546, 52230, 'Lord Rhyolith - Slay 1'),
(54199, 9, 1, 'So soft!', 14, 0, 100, 0, 0, 24547, 52231, 'Lord Rhyolith - Slay 2'),
(54199, 9, 2, 'Squeak, little pest.', 14, 0, 100, 0, 0, 24548, 52232, 'Lord Rhyolith - Slay 3'),
-- Phase two entry
(53772, 1, 0, 'I\'ll crush you underfoot!', 14, 0, 100, 0, 0, 24557, 52239, 'Lord Rhyolith - Concussive Stomp 1'),
(53772, 1, 1, 'Stomp now.', 14, 0, 100, 0, 0, 24556, 52238, 'Lord Rhyolith - Concussive Stomp 2'),
(53772, 6, 0, '%s stumbles as his armor is shattered!', 41, 0, 100, 0, 0, 0, 51766, 'Lord Rhyolith - Announce Armor Shattered'),
(53772, 7, 0, 'Eons I have slept undisturbed... Now this... Creatures of flesh, now you will BURN!', 14, 0, 100, 0, 0, 24558, 52240, 'Lord Rhyolith - Armor Shattered'),
(53772, 8, 0, 'Broken. Mnngghhh... broken...', 14, 0, 100, 0, 0, 24545, 52246, 'Lord Rhyolith - Death'),
(53772, 9, 0, 'Finished.', 14, 0, 100, 0, 0, 24546, 52230, 'Lord Rhyolith - Slay 1'),
(53772, 9, 1, 'So soft!', 14, 0, 100, 0, 0, 24547, 52231, 'Lord Rhyolith - Slay 2'),
(53772, 9, 2, 'Squeak, little pest.', 14, 0, 100, 0, 0, 24548, 52232, 'Lord Rhyolith - Slay 3');

DELETE FROM `conditions` WHERE `SourceEntry` IN (98493, 100650, 98255, 101157, 101158, 101159) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 98493, 0, 0, 31, 0, 3, 52582, 0, 0, 0, '', 'Heated Volcano - Target Volcano'),
(13, 1, 100650, 0, 0, 31, 0, 3, 52866, 0, 0, 0, '', 'Lava Line - Target Volcano'),
(13, 1, 98255, 0, 0, 31, 0, 3, 52558, 0, 0, 0, '', 'Molten Armor - Target Lord Rhyolith'),
(13, 1, 98255, 0, 1, 31, 0, 3, 54199, 0, 0, 0, '', 'Molten Armor - Target Lord Rhyolith'),
(13, 1, 98255, 0, 2, 31, 0, 3, 53772, 0, 0, 0, '', 'Molten Armor - Target Lord Rhyolith'),
(13, 2, 98255, 0, 0, 31, 0, 3, 52577, 0, 0, 0, '', 'Molten Armor - Target Left Foot'),
(13, 4, 98255, 0, 0, 31, 0, 3, 53087, 0, 0, 0, '', 'Molten Armor - Target Right Foot'),
(13, 1, 101157, 0, 0, 31, 0, 3, 52558, 0, 0, 0, '', 'Molten Armor - Target Lord Rhyolith'),
(13, 1, 101157, 0, 1, 31, 0, 3, 54199, 0, 0, 0, '', 'Molten Armor - Target Lord Rhyolith'),
(13, 1, 101157, 0, 2, 31, 0, 3, 53772, 0, 0, 0, '', 'Molten Armor - Target Lord Rhyolith'),
(13, 2, 101157, 0, 0, 31, 0, 3, 52577, 0, 0, 0, '', 'Molten Armor - Target Left Foot'),
(13, 4, 101157, 0, 0, 31, 0, 3, 53087, 0, 0, 0, '', 'Molten Armor - Target Right Foot'),
(13, 1, 101158, 0, 0, 31, 0, 3, 52558, 0, 0, 0, '', 'Molten Armor - Target Lord Rhyolith'),
(13, 1, 101158, 0, 1, 31, 0, 3, 54199, 0, 0, 0, '', 'Molten Armor - Target Lord Rhyolith'),
(13, 1, 101158, 0, 2, 31, 0, 3, 53772, 0, 0, 0, '', 'Molten Armor - Target Lord Rhyolith'),
(13, 2, 101158, 0, 0, 31, 0, 3, 52577, 0, 0, 0, '', 'Molten Armor - Target Left Foot'),
(13, 4, 101158, 0, 0, 31, 0, 3, 53087, 0, 0, 0, '', 'Molten Armor - Target Right Foot'),
(13, 1, 101159, 0, 0, 31, 0, 3, 52558, 0, 0, 0, '', 'Molten Armor - Target Lord Rhyolith'),
(13, 1, 101159, 0, 1, 31, 0, 3, 54199, 0, 0, 0, '', 'Molten Armor - Target Lord Rhyolith'),
(13, 1, 101159, 0, 2, 31, 0, 3, 53772, 0, 0, 0, '', 'Molten Armor - Target Lord Rhyolith'),
(13, 2, 101159, 0, 0, 31, 0, 3, 52577, 0, 0, 0, '', 'Molten Armor - Target Left Foot'),
(13, 4, 101159, 0, 0, 31, 0, 3, 53087, 0, 0, 0, '', 'Molten Armor - Target Right Foot');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_rhyolith_drink_magma',
'spell_rhyolith_concussive_stomp',
'spell_rhyolith_heated_volcano',
'spell_rhyolith_lava_strike_visual',
'spell_rhyolith_lava_strike',
'spell_rhyolith_lava_line',
'spell_rhyolith_magma_flow',
'spell_rhyolith_immolation',
'spell_rhyolith_meltdown',
'spell_rhyolith_summon_rock_elementals');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(98034, 'spell_rhyolith_drink_magma'),
(102306, 'spell_rhyolith_concussive_stomp'),
(102307, 'spell_rhyolith_concussive_stomp'),
(102308, 'spell_rhyolith_concussive_stomp'),
(102309, 'spell_rhyolith_concussive_stomp'),
(98493, 'spell_rhyolith_heated_volcano'),
(98489, 'spell_rhyolith_lava_strike_visual'),
(98276, 'spell_rhyolith_lava_strike'),
(100650, 'spell_rhyolith_lava_line'),
(97225, 'spell_rhyolith_magma_flow'),
(98597, 'spell_rhyolith_immolation'),
(98649, 'spell_rhyolith_meltdown'),
(101646, 'spell_rhyolith_meltdown'),
(101647, 'spell_rhyolith_meltdown'),
(101648, 'spell_rhyolith_meltdown'),
(98146, 'spell_rhyolith_summon_rock_elementals');


DELETE FROM `creature` WHERE `guid`= 317634;
DELETE FROM `creature_addon` WHERE `guid`= 317634;

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (53122);
INSERT INTO `creature_template_movement` (`CreatureID`, `Ground`, `Flight`, `Swim`, `Rooted`) VALUES
(53122, 0, 1, 0, 0);

DELETE FROM `world_states` WHERE `ID`= 5931;
INSERT INTO `world_states` (`ID`, `DefaultValue`, `MapID`, `Comment`) VALUES
(5931, 0, 720, 'Firelands - Lord Rhyolith - Not an Ambi-Turner');

DELETE FROM `spawn_group_template` WHERE `groupId`= 457;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(457, 'Firelands - Lord Rhyolith', 4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId`= 457;
INSERT INTO `instance_spawn_groups` (`instanceMapId`, `bossStateId`, `bossStates`, `spawnGroupId`, `flags`) VALUES
(720, 1, 7, 457, 1);

DELETE FROM `spawn_group` WHERE `groupId`= 457;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(457, 0, 317635),
(457, 0, 338763);

UPDATE `instance_encounters` SET `creditEntry`= 53772 WHERE `entry`= 1204;

-- Normal Difficulty
SET @ENTRY := 52558;
DELETE FROM `reference_loot_template` WHERE `Entry`= @ENTRY * 10;
INSERT INTO `reference_loot_template` (`Entry`, `Reference`, `Item`, `Chance`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(@ENTRY * 10, 0, 70912, 0, 1, 1, 1),
(@ENTRY * 10, 0, 71007, 0, 1, 1, 1),
(@ENTRY * 10, 0, 71012, 0, 1, 1, 1),
(@ENTRY * 10, 0, 71010, 0, 1, 1, 1),
(@ENTRY * 10, 0, 71009, 0, 1, 1, 1),
(@ENTRY * 10, 0, 71004, 0, 1, 1, 1),
(@ENTRY * 10, 0, 70993, 0, 1, 1, 1),
(@ENTRY * 10, 0, 71003, 0, 1, 1, 1),
(@ENTRY * 10, 0, 71006, 0, 1, 1, 1),
(@ENTRY * 10, 0, 70991, 0, 1, 1, 1),
(@ENTRY * 10, 0, 71005, 0, 1, 1, 1),
(@ENTRY * 10, 0, 71011, 0, 1, 1, 1),
(@ENTRY * 10, 0, 70992, 0, 1, 1, 1),
(@ENTRY * 10, 0, 71775, 0, 1, 1, 1),
(@ENTRY * 10, 0, 71780, 0, 1, 1, 1),
(@ENTRY * 10, 0, 71776, 0, 1, 1, 1),
(@ENTRY * 10, 0, 71785, 0, 1, 1, 1),
(@ENTRY * 10, 0, 71782, 0, 1, 1, 1),
(@ENTRY * 10, 0, 71779, 0, 1, 1, 1),
(@ENTRY * 10, 0, 71787, 0, 1, 1, 1);

DELETE FROM `creature_loot_template` WHERE `entry` IN (53772, 53774);
INSERT INTO `creature_loot_template` (`Entry`, `Reference`, `Item`, `Chance`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(53772, @ENTRY * 10, @ENTRY * 10, 100, 0, 2, 2),
(53772, 0,           69237,       45 , 0, 1, 2),
(53774, @ENTRY * 10, @ENTRY * 10, 100, 0, 5, 5),
(53774, 0,           69237,       45 , 0, 1, 2);

UPDATE `creature_template` SET `lootid`= `entry` WHERE `entry` IN (53772, 53774); 

-- Heroic
SET @ENTRY := 52560;
DELETE FROM `reference_loot_template` WHERE `Entry`= @ENTRY * 10;
INSERT INTO `reference_loot_template` (`Entry`, `Reference`, `Item`, `Chance`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(@ENTRY * 10, 0, 71415, 0, 1, 1, 1),
(@ENTRY * 10, 0, 71426, 0, 1, 1, 1),
(@ENTRY * 10, 0, 71423, 0, 1, 1, 1),
(@ENTRY * 10, 0, 71420, 0, 1, 1, 1),
(@ENTRY * 10, 0, 71419, 0, 1, 1, 1),
(@ENTRY * 10, 0, 71417, 0, 1, 1, 1),
(@ENTRY * 10, 0, 71416, 0, 1, 1, 1),
(@ENTRY * 10, 0, 71422, 0, 1, 1, 1),
(@ENTRY * 10, 0, 71414, 0, 1, 1, 1),
(@ENTRY * 10, 0, 71418, 0, 1, 1, 1),
(@ENTRY * 10, 0, 71425, 0, 1, 1, 1),
(@ENTRY * 10, 0, 71424, 0, 1, 1, 1),
(@ENTRY * 10, 0, 71421, 0, 1, 1, 1),
(@ENTRY * 10, 0, 71617, 0, 1, 1, 1),
(@ENTRY * 10, 0, 71783, 0, 1, 1, 1),
(@ENTRY * 10, 0, 71777, 0, 1, 1, 1),
(@ENTRY * 10, 0, 71784, 0, 1, 1, 1),
(@ENTRY * 10, 0, 71774, 0, 1, 1, 1),
(@ENTRY * 10, 0, 71781, 0, 1, 1, 1),
(@ENTRY * 10, 0, 71778, 0, 1, 1, 1),
(@ENTRY * 10, 0, 71786, 0, 1, 1, 1);

DELETE FROM `creature_loot_template` WHERE `entry` IN (53774, 53775);
INSERT INTO `creature_loot_template` (`Entry`, `Reference`, `Item`, `Chance`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(53774, @ENTRY * 10, @ENTRY * 10, 100, 0, 2, 2),
(53774, 0,           69237,       45 , 0, 1, 2),
(53775, @ENTRY * 10, @ENTRY * 10, 100, 0, 5, 5),
(53775, 0,           69237,       45 , 0, 1, 2);

UPDATE `creature_template` SET `lootid`= `entry` WHERE `entry` IN (53774, 53775); 

UPDATE `creature_template` SET `mingold`= 2250000, `maxgold`= 2750000 WHERE `entry` IN (53772, 53774);
UPDATE `creature_template` SET `mingold`= 5625000, `maxgold`= 6875000 WHERE `entry` IN (53773, 53775);
