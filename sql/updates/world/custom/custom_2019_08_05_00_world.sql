-- Template Updates
-- Maloriak
UPDATE `creature_template` SET `ScriptName`= 'boss_maloriak' WHERE `entry`= 41378;
UPDATE `creature_template` SET `speed_run`= 1.71429, `DamageModifier`= 120, `BaseVariance`= 0.5, `mechanic_immune_mask`= 617299839 WHERE `entry` IN (41378, 49974, 49980, 49986);
-- Flash Freeze
UPDATE `creature_template` SET `difficulty_entry_1`= 49973, `difficulty_entry_2`= 49979, `difficulty_entry_3`= 49985, `ScriptName`= 'npc_maloriak_flash_freeze' WHERE `entry`= 41576;
UPDATE `creature_template` SET `minlevel`= 88, `maxlevel`= 88, `exp`= 3, `faction`= 14, `unit_flags`= 33554432, `mechanic_immune_mask`= 650854271, `flags_extra`= 128 | 1073741824, `exp`= 3 WHERE `entry` IN (41576, 49973, 49979, 49985);
-- Aberration
UPDATE `creature_template` SET `difficulty_entry_1`= 49971, `difficulty_entry_2`= 49977, `difficulty_entry_3`= 49983, `ScriptName`= 'npc_maloriak_experiment' WHERE `entry`= 41440;
UPDATE `creature_template` SET `minlevel`= 88, `maxlevel`= 88, `exp`= 3, `faction`= 103, `unit_flags`= 33554688, `DamageModifier`= 15, `BaseVariance`= 0.5, `mechanic_immune_mask`= 8388608, `flags_extra`= 0x00000200 WHERE `entry` IN (41440, 49971, 49977, 49983);
-- Prime Subject
UPDATE `creature_template` SET `difficulty_entry_1`= 49975, `difficulty_entry_2`= 49981, `difficulty_entry_3`= 49987, `ScriptName`= 'npc_maloriak_experiment' WHERE `entry`= 41841;
UPDATE `creature_template` SET `minlevel`= 88, `maxlevel`= 88, `exp`= 3, `faction`= 103, `speed_run`= 1, `unit_flags`= 33554688, `DamageModifier`= 30, `BaseVariance`= 0.5, `mechanic_immune_mask`= 667893631, `flags_extra`= 0x00000200 | 0x40000000 WHERE `entry` IN (41841, 49975, 49981, 49987);
-- Magma Jet
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 128, `ScriptName`= 'npc_maloriak_magma_jet' WHERE `entry`= 50030;
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 128, `AIName`= 'NullCreatureAI' WHERE `entry`= 41901;
-- Absolute Zero
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 128, `AIName`= 'NullCreatureAI' WHERE `entry`= 41961;
-- Lord Victor Nefarius
UPDATE `creature_template` SET `unit_flags`= 33554496, `ScriptName`= 'npc_maloriak_lord_victor_nefarius' WHERE `entry`= 49799;
-- Vile Swill Pre-Effect
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 128, `AIName`= 'NullCreatureAI' WHERE `entry`= 49812;
-- Vile Swill
UPDATE `creature_template` SET `difficulty_entry_1`= 49976, `difficulty_entry_2`= 49982, `difficulty_entry_3`= 49988, `ScriptName`= 'npc_maloriak_vile_swill' WHERE `entry`= 49811;
UPDATE `creature_template` SET `minlevel`= 88, `maxlevel`= 88, `exp`= 3, `faction`= 14, `DamageModifier`= 30, `BaseVariance`= 0.5, `mechanic_immune_mask`= 8388608 WHERE `entry` IN (49811, 49976, 49982, 49988);

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_maloriak_throw_bottle',
'spell_maloriak_throw_bottle_triggered',
'spell_maloriak_consuming_flames',
'spell_maloriak_flash_freeze_targeting',
'spell_maloriak_flash_freeze_dummy',
'spell_maloriak_release_experiments',
'spell_maloriak_magma_jets_periodic',
'spell_maloriak_absolute_zero',
'spell_maloriak_vile_swill_summon',
'spell_maloriak_vile_swill',
'spell_maloriak_master_adventurer_award');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(77925, 'spell_maloriak_throw_bottle'),
(77932, 'spell_maloriak_throw_bottle'),
(77937, 'spell_maloriak_throw_bottle'),
(92831, 'spell_maloriak_throw_bottle'),
(77928, 'spell_maloriak_throw_bottle_triggered'),
(77934, 'spell_maloriak_throw_bottle_triggered'),
(77938, 'spell_maloriak_throw_bottle_triggered'),
(92837, 'spell_maloriak_throw_bottle_triggered'),
(77786, 'spell_maloriak_consuming_flames'),
(92971, 'spell_maloriak_consuming_flames'),
(92972, 'spell_maloriak_consuming_flames'),
(92973, 'spell_maloriak_consuming_flames'),
(97693, 'spell_maloriak_flash_freeze_targeting'),
(77716, 'spell_maloriak_flash_freeze_dummy'),
(77569, 'spell_maloriak_release_experiments'),
(77991, 'spell_maloriak_release_experiments'),
(93018, 'spell_maloriak_magma_jets_periodic'),
(78206, 'spell_maloriak_absolute_zero'),
(92737, 'spell_maloriak_vile_swill_summon'),
(92720, 'spell_maloriak_vile_swill'),
(89798, 'spell_maloriak_master_adventurer_award');

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (41378, 49799);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
-- Maloriak
(41378, 0, 0, 'There can be no disruptions! Mustn\'t keep the master waiting! Mustn\'t fail again!', 14, 0, 100, 0, 0, 19847, 47028, 'Maloriak to Player'),
(41378, 1, 0, 'Mix and stir, apply heat...', 14, 0, 100, 0, 0, 19851, 41594, 'Maloriak to Maloriak'),
(41378, 2, 0, '|TInterface\\Icons\\INV_POTION_24.BLP:20|tMaloriak throws a |cFFFF0000red|r vial into the cauldron!', 41, 0, 100, 0, 0, 0, 47036, 'Maloriak to Maloriak'),
(41378, 3, 0, 'How well does the mortal shell handle extreme temperature change? Must find out! For science!', 14, 0, 100, 0, 0, 19853, 41595, 'Maloriak to Maloriak'),
(41378, 4, 0, '|TInterface\\Icons\\INV_POTION_20.BLP:20|tMaloriak throws a |cFF809FFEblue|r vial into the cauldron!', 41, 0, 100, 0, 0, 0, 47037, 'Maloriak to Maloriak'),
(41378, 5, 0, 'This one\'s a little unstable, but what\'s progress without failure?', 14, 0, 100, 0, 0, 19852, 41596, 'Maloriak to Maloriak'),
(41378, 6, 0, '|TInterface\\Icons\\INV_POTION_162.BLP:20|tMaloriak throws a |cFF33FF00green|r vial into the cauldron!', 41, 0, 100, 0, 0, 0, 47038, 'Maloriak to Maloriak'),
(41378, 7, 0, 'What they lack in intelligence they make up for in ferocity!', 14, 0, 100, 0, 0, 19856, 47032, 'Maloriak'),
(41378, 7, 1, 'My failings will be your downfall!', 14, 0, 100, 0, 0, 19857, 47033, 'Maloriak'),
(41378, 8, 0, 'Meet the brawn to my brains! Prime subjects, devour them!', 14, 0, 100, 0, 0, 19859, 47035, 'Maloriak'),
(41378, 8, 1, 'Too early, but no choice... They must be tested! Face now my prime subjects!', 14, 0, 100, 0, 0, 19858, 47034, 'Maloriak'),
(41378, 8, 2, 'When pushed to the edge, results may become unpredictable...', 14, 0, 100, 0, 0, 19854, 41625, 'Maloriak'),
(41378, 9, 0, 'Nothing goes to waste... ', 14, 0, 100, 0, 0, 19848, 47029, 'Maloriak'),
(41378, 9, 1, 'Strip the flesh, harvest the organs!', 14, 0, 100, 0, 0, 19849, 47030, 'Maloriak'),
(41378, 10, 0, 'There will never be another like me...', 14, 0, 100, 0, 0, 19850, 47031, 'Maloriak to Player'),
-- Lord Victor Nefarius
(49799, 0, 0, 'Maloriak, try not to lose to these mortals. Semicompetent help is SO hard to create.', 14, 0, 100, 0, 0, 23372, 49068, 'Lord Victor Nefarius to Player'),
(49799, 1, 0, 'Your mixtures are weak, Maloriak! They need a bit more... kick!', 14, 0, 100, 0, 0, 23370, 49069, 'Lord Victor Nefarius to Maloriak'),
(49799, 2, 0, '|TInterface\\Icons\\INV_ELEMENTAL_PRIMAL_SHADOW.BLP:20|t%s throws |cFF660099dark|r magic into the cauldron!', 41, 0, 100, 0, 0, 0, 49793, 'Lord Victor Nefarius to Maloriak'),
(49799, 3, 0, 'Congratulations! Allow me to grant you a title befitting the amazing achievement you just performed. Henceforth you shall be known as the \"Slayer of Stupid, Incompetent, and Disappointing Minions.\"', 14, 0, 100, 21, 0, 23371, 49070, 'Lord Victor Nefarius to Player');

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (77925, 77932, 77937, 92831, 77928, 77934, 77938, 92837, 77948, 77615, 77569, 77716, 77715, 95655, 95656, 95657) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`,  `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 77925, 0, 0, 31, 0, 3, 41505, 0, 0, 0, '', 'Throw Red Bottle - Target Cauldron Trigger'),
(13, 1, 77932, 0, 0, 31, 0, 3, 41505, 0, 0, 0, '', 'Throw Blue Bottle - Target Cauldron Trigger'),
(13, 1, 77937, 0, 0, 31, 0, 3, 41505, 0, 0, 0, '', 'Throw Green Bottle - Target Cauldron Trigger'),
(13, 1, 92831, 0, 0, 31, 0, 3, 41505, 0, 0, 0, '', 'Throw Black Bottle - Target Cauldron Trigger'),
(13, 1, 77928, 0, 0, 31, 0, 3, 41505, 0, 0, 0, '', 'Throw Red Bottle - Target Cauldron Trigger'),
(13, 1, 77934, 0, 0, 31, 0, 3, 41505, 0, 0, 0, '', 'Throw Blue Bottle - Target Cauldron Trigger'),
(13, 1, 77938, 0, 0, 31, 0, 3, 41505, 0, 0, 0, '', 'Throw Green Bottle - Target Cauldron Trigger'),
(13, 1, 92837, 0, 0, 31, 0, 3, 41505, 0, 0, 0, '', 'Throw Black Bottle - Target Cauldron Trigger'),
(13, 2, 77948, 0, 0, 31, 0, 3, 41378, 0, 0, 0, '', 'Dibilitating Slime - Target Maloriak'),
(13, 4, 77948, 0, 0, 31, 0, 3, 41440, 0, 0, 0, '', 'Dibilitating Slime - Target Aberration'),
(13, 2, 77615, 0, 0, 31, 0, 3, 41378, 0, 0, 0, '', 'Dibilitating Slime - Target Maloriak'),
(13, 4, 77615, 0, 0, 31, 0, 3, 41440, 0, 0, 0, '', 'Dibilitating Slime - Target Aberration'),
(13, 4, 77615, 0, 1, 31, 0, 3, 41841, 0, 0, 0, '', 'Dibilitating Slime - Target Prime Subject'),
(13, 1, 77569, 0, 0, 31, 0, 3, 41440, 0, 0, 0, '', 'Release Aberrations - Target Aberration'),
(13, 1, 77716, 0, 0, 31, 0, 3, 41576, 0, 0, 0, '', 'Flash Freeze - Target Flash Freeze'),
(13, 2, 77715, 0, 0, 31, 0, 3, 41576, 0, 0, 0, '', 'Shatter - Target Flash Freeze'),
(13, 2, 95655, 0, 0, 31, 0, 3, 41576, 0, 0, 0, '', 'Shatter - Target Flash Freeze'),
(13, 2, 95656, 0, 0, 31, 0, 3, 41576, 0, 0, 0, '', 'Shatter - Target Flash Freeze'),
(13, 2, 95657, 0, 0, 31, 0, 3, 41576, 0, 0, 0, '', 'Shatter - Target Flash Freeze');

-- Procs
DELETE FROM `spell_proc` WHERE `SpellId` IN (77786, 92971, 92972, 92973);
INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Charges`, `AttributesMask`) VALUES
(77786, 0x00020000, 0, 0, 0, 0, 2),
(92971, 0x00020000, 0, 0, 0, 0, 2),
(92972, 0x00020000, 0, 0, 0, 0, 2),
(92973, 0x00020000, 0, 0, 0, 0, 2);

-- Custom Attributes
DELETE FROM `spell_custom_attr` WHERE `entry` IN (77679, 92968, 92969, 92970);
INSERT INTO `spell_custom_attr` (`entry`, `attributes`) VALUES
(77679, 0x00000008),
(92968, 0x00000008),
(92969, 0x00000008),
(92970, 0x00000008);

-- Addons
DELETE FROM `creature_template_addon` WHERE `entry` IN (41440, 41841, 41901, 50030, 41961, 49799, 49812, 49971, 49977, 49983, 49975, 49981, 49987);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
-- Aberration
(41440, '91334, 77564'),
(49971, '91334, 77564'),
(49977, '91334, 77564'),
(49983, '91334, 77564'),
-- Prime Subject
(41841, '91334, 77564'),
(49975, '91334, 77564'),
(49981, '91334, 77564'),
(49987, '91334, 77564'),
-- Magma Jet
(50030, '93018'),
-- Lord Victor Nefarius
(49799, '78494'),
-- Vile Swill Pre-Effect
(49812, '92737');

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (41440, 41841, 49799, 49812);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Flight`, `Rooted`) VALUES
(49799, 1, 1, 0),
(49812, 0, 1, 1);

-- Summon Groups
DELETE FROM `creature_summon_groups` WHERE `summonerId`= 41378 AND `summonerType`= 0;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES
-- Aberration
(41378, 0, 0, 41440, -149.401, -421.208, 82.86744, 4.782202, 8, 0),
(41378, 0, 0, 41440, -143.931, -418.472, 94.99654, 5.201081, 8, 0),
(41378, 0, 0, 41440, -143.809, -418.507, 103.9453, 5.113815, 8, 0),
(41378, 0, 0, 41440, -144.153, -418.741, 85.51984, 5.585053, 8, 0),
(41378, 0, 0, 41440, -148.575, -438.087, 104.4583, 5.689773, 8, 0),
(41378, 0, 0, 41440, -151.0955, -426.809, 83.10994, 0.1745329, 8, 0),
(41378, 0, 0, 41440, -148.835, -438.078, 85.23814, 5.654867, 8, 0),
(41378, 0, 0, 41440, -149.1545, -438.099, 94.94753, 5.67232, 8, 0),
(41378, 0, 0, 41440, -150.332, -432.316, 83.05254, 5.742133, 8, 0),
(41378, 0, 0, 41440, -69.3472, -417.59, 104.4583, 3.141593, 8, 0),
(41378, 0, 0, 41440, -69.1615, -417.741, 94.94753, 3.124139, 8, 0),
(41378, 0, 0, 41440, -69.0035, -417.688, 85.23814, 3.106686, 8, 0),
(41378, 0, 0, 41440, -63.2465, -437.377, 103.9453, 2.687807, 8, 0),
(41378, 0, 0, 41440, -63.1927, -437.582, 94.99654, 2.775074, 8, 0),
(41378, 0, 0, 41440, -64.0729, -420.663, 83.64043, 3.420845, 8, 0),
(41378, 0, 0, 41440, -61.3299, -425.25, 83.69794, 3.804818, 8, 0),
(41378, 0, 0, 41440, -63.2135, -437.502, 85.51984, 3.159046, 8, 0),
(41378, 0, 0, 41440, -61.2656, -431.288, 83.45544, 2.70526, 8, 0),
-- Prime Subject
(41378, 0, 0, 41841, -145.46, -427.517, 97.17764, 0.6108652, 8, 0),
(41378, 0, 0, 41841, -66.408, -426.899, 97.17764, 4.18879, 8, 0);

-- Spawn Group
DELETE FROM `spawn_group_template` WHERE `groupId`= 401;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(401, 'Blackwing Descent - Growth Chambers', 4);

DELETE FROM `spawn_group` WHERE `groupId`= 401;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(401, 1, 235157),
(401, 1, 235158),
(401, 1, 235159),
(401, 1, 235160),
(401, 1, 235161),
(401, 1, 235162),
(401, 1, 235163),
(401, 1, 235164),
(401, 1, 235165),
(401, 1, 235166),
(401, 1, 235167),
(401, 1, 235168),
(401, 1, 235169),
(401, 1, 235170),
(401, 1, 235171),
(401, 1, 235172),
(401, 1, 235173),
(401, 1, 235174),
(401, 1, 235175),
(401, 1, 235176);

-- Delete encounter relatest spawns
DELETE FROM `creature` WHERE `guid` IN (250115, 250114);
DELETE FROM `creature_addon` WHERE `guid` IN (250115, 250114);

-- Currency Loot
DELETE FROM `creature_onkill_reward` WHERE `creature_id` IN (41378, 49974, 49980, 49986);
INSERT INTO `creature_onkill_reward` (`creature_id`, `CurrencyId1`, `CurrencyCount1`) VALUES
(41378, 396, 3500),
(49974, 396, 4500),
(49980, 396, 3500),
(49986, 396, 4500);
