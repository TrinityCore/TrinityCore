DELETE FROM `areatrigger_scripts` WHERE `entry`=6845;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES (6845, 'at_sulfuron_keep');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN
(99503,99581,100606,100342,100344,100345,101254,100907,100503,100567,100653,
100604,100594,100459,100771,98159,98171,98497,98498,100158,99012,99054,98703,
98708,101088,98928,100823,100906,100966,99125,99145,99267,99279);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceEntry`=100713;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `NegativeCondition`, `Comment`) VALUES
(13, 1,     99503,  0, 31, 0, 3,      53585,  0, 'Raise Lava - Target Lava'),
(13, 1,     99581,  0, 31, 0, 3,      53545,  0, 'Molten Eruption - Target Lava Spewer'),
(13, 1,     100606, 0, 31, 0, 3,      52409,  0, 'Empower Sulfuras Visual Missile - Target Ragnaros'),
(13, 1,     100342, 0, 31, 0, 3,      52409,  0, 'Draw Out Firelord - Target Ragnaros'),
(13, 1,     100344, 0, 31, 0, 3,      52409,  0, 'Draw Out Firelord - Target Ragnaros'),
(13, 1,     100345, 0, 31, 0, 3,      52409,  0, 'Draw Out Firelord - Target Ragnaros'),
(13, 1,     101254, 0, 31, 0, 3,      52409,  0, 'Heart of Ragnaros - Target Ragnaros'),
(13, 1,     100907, 0, 31, 0, 3,      53500,  0, 'Freeze Living Meteor - Target Living Meteor'),
(13, 1,     100503, 0, 31, 0, 4,      0,      0, 'Breadth of Frost - Target players'),
(13, 2,     100503, 0, 31, 0, 4,      0,      0, 'Breadth of Frost - Target players'),
(13, 7,     100567, 0, 31, 0, 3,      53500,  0, 'Breadth of Frost - Target Living Meteor'),
(13, 3,     100653, 0, 31, 0, 3,      52409,  0, 'Entrapping Roots - Target Ragnaros'),
(13, 2,     100604, 0, 31, 0, 3,      53186,  0, 'Empower Sulfuras Visual Missile Trigger - Target Molten Seed Caster'),
(13, 3,     100594, 1, 31, 0, 4,      0,      0, 'Superheated - Target players'),
(13, 3,     100594, 1,  1, 0, 100713, 0,      1, 'Superheated - Target does not have Deluge aura'),
(13, 3,     100594, 1,  1, 0, 100503, 0,      1, 'Superheated - Target does not have Breadth of Frost aura'),
(13, 1,     100459, 0, 31, 0, 4,      0,      0, 'Blazing Heat - Target players'),
(13, 1,     100771, 0, 31, 0, 4,      0,      0, 'Deluge aura cancel - Target players'),
(13, 1,     98159,  0, 31, 0, 4,      0,      0, 'Magma Trap - Target players'),
(13, 1,     98171,  0, 31, 0, 4,      0,      0, 'Magma Trap Dummy - Target players'),
(13, 2,     98497,  0, 31, 0, 3,      53186,  0, 'Molten Seed Missile Target Search - Target Molten Seed Caster'),
(13, 2,     98498,  0, 31, 0, 3,      53189,  0, 'Molten Seed Missile Hit - Target Molten Elemental'),
(13, 7,     100158, 0, 31, 0, 3,      53189,  0, 'Molten Power - Target Molten Elemental'),
(13, 1,     99012,  0, 31, 0, 3,      53393,  0, 'Splitting Blow Dummy - Target Splitting Blow'),
(13, 1,     99054,  0, 31, 0, 3,      53140,  0, 'Invoke Sons - Target Son of Flame'),
(13, 1,     98703,  0, 31, 0, 4,      0,      0, 'Sulfuras Smash Player Trigger - Target players'),
(13, 2,     98708,  0, 31, 0, 3,      53268,  0, 'Sulfuras Smash - Target Sulfuras Smash'),
(13, 4,     98708,  0, 31, 0, 3,      53363,  0, 'Sulfuras Smash - Target Lava Wave'),
(13, 1,     101088, 0, 31, 0, 3,      53500,  0, 'Lavalogged - Target Living Meteor'),
(13, 7,     98928,  1, 31, 0, 4,      0,      0, 'Lava Wave Effect 0 - Target players'),
(13, 7,     98928,  1, 1,  0, 98928,  1,      1, 'Lava Wave Effect 0 - Target without Lava Wave aura'),
(13, 1,     100823, 0, 1,  0, 100713, 0,      0, 'Dreadflame Deluge Control Aura - Target does not have Deluge aura'),
(13, 1,     100906, 0, 31, 0, 3,      54203,  0, 'Dreadflame Spawn Control Aura - Target Dreadflame Spawn'),
(13, 1,     100966, 1, 31, 0, 4,      0,      0, 'Dreadflame Damage Control Aura - Target players'),
(13, 1,     100966, 1, 1,  0, 100713, 1,      1, 'Dreadflame Damage Control Aura - Target without Deluge aura'),
(13, 1,     99125,  0, 31, 0, 3,      53473,  0, 'Blazing Heat Spawn - Target Blazing Heat'),
(13, 1,     99145,  0, 31, 0, 3,      53231,  0, 'Blazing Heat - Target Lava Scion'),
(13, 1,     99145,  1, 31, 0, 3,      53140,  0, 'Blazing Heat - Target Son of Flame'),
(18, 54147, 100713, 0, 1,  0, 100713, 0,      1, 'Cloudburst Spellclick - Target without Deluge aura'),
(13, 1,     99267,  0, 31, 0, 4,      0,      0, 'Living Meteor target search - Target players'),
(13, 1,     99279,  0, 31, 0, 4,      0,      0, 'Living Meteor target search - Target players');

-- Remove Ragnaros, Lava Scion, Son of Flame, Splitting Blow, Engulfing Flames, Magma, Cenarius, Malfurion Stormrage, Arch Druid Hamuul Runetotem and Platform Stalker sniff spawns
-- TODO: Unsafe, need to use guids instead, in case they are ever spawned in other locations at some point.
DELETE FROM `creature` WHERE `id` IN (52409,53231,53140,53393,53485,53729,53872,53875,53876,53952);
-- Fix Lava Wielder sniff spawn position
UPDATE `creature` SET `position_x`=765.467, `position_y`=-59.48264, `position_z`=86.39432, `orientation`=3.193953 WHERE `guid`=338816;
-- Fix Lava sniff spawn positions
UPDATE `creature` SET `position_z`=83.01068 WHERE `guid`=338815;
UPDATE `creature` SET `position_z`=83.00064 WHERE `guid`=338812;
UPDATE `creature` SET `position_z`=83.19267 WHERE `guid`=338810;
UPDATE `creature` SET `position_z`=83.03971 WHERE `guid`=338814;

-- Heroic Ragnaros last phase weapon swap
DELETE FROM `creature_equip_template` WHERE `CreatureID`=52409 AND `ID`=2;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`, `VerifiedBuild`) VALUES (52409, 2, 71036, 0, 0, 0);

-- Lava Worms
DELETE FROM `creature_formations` WHERE `memberGUID` IN (338820,338821);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`) VALUES
(338820, 338820, 0, 0, 2),
(338820, 338821, 0, 0, 2);

-- Ragnaros (10-man Heroic)
DELETE FROM `creature_loot_template` WHERE `Entry`=53798;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(53798, 69815,     0, 100, 1, 1, 1, 23, 26, 'Ragnaros 10H - Seething Cinder'),
(53798, 71141,     0,  80, 1, 1, 1,  1,  1, 'Ragnaros 10H - Eternal Ember'),
(53798,     1, 50022, 100, 0, 1, 1,  2,  2, 'Ragnaros 10H - Gear'),
(53798,     2, 50023, 100, 0, 1, 1,  1,  1, 'Ragnaros 10H - Token'),
(53798, 69224,     0,   1, 0, 1, 1,  1,  1, 'Ragnaros 10H - Smoldering Egg of Millagazor');
-- Ragnaros (25-man Heroic)
DELETE FROM `creature_loot_template` WHERE `Entry`=53799;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(53799, 69815,     0, 100, 1, 1, 1, 55, 66, 'Ragnaros 25H - Seething Cinder'),
(53799, 71141,     0, 100, 1, 1, 1,  1,  3, 'Ragnaros 25H - Eternal Ember'),
(53799,     1, 50022, 100, 0, 1, 1,  6,  6, 'Ragnaros 25H - Gear'),
(53799,     2, 50023, 100, 0, 1, 1,  3,  3, 'Ragnaros 25H - Tokens'),
(53799, 69224,     0,   1, 0, 1, 1,  1,  1, 'Ragnaros 25H - Smoldering Egg of Millagazor');

-- Heroic Ragnaros model
UPDATE `creature_model_info` SET `BoundingRadius`=0.75, `CombatReach`=21 WHERE `DisplayID`=38570;

-- Magma, west, middle and east splitting bow, near, middle and far Engulfing Flames, Lava Scions, heroic difficulty player helper spell targets, 
DELETE FROM `creature_summon_groups` WHERE `summonerId`=52409;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES
(52409, 0, 0, 53729, 1078.43, -57.5295, 52.8818, 0, 8, 0),
(52409, 0, 0, 53729, 1088.52, -57.2986, 52.8818, 0, 8, 0),
(52409, 0, 1, 53393, 1035.45, -25.3646, 55.4924, 2.49582, 8, 0),
(52409, 0, 2, 53393, 1023.55, -57.158, 55.4215, 3.12414, 8, 0),
(52409, 0, 3, 53393, 1036.27, -89.2396, 55.5098, 3.83972, 8, 0),
(52409, 0, 4, 53485, 1033.93, -57.092, 55.4225, 6.26573, 8, 0),
(52409, 0, 4, 53485, 1034.76, -63.9583, 55.4397, 6.26573, 8, 0),
(52409, 0, 4, 53485, 1036.34, -69.8281, 55.4425, 0.314159, 8, 0),
(52409, 0, 4, 53485, 1036.82, -44.3385, 55.4425, 6.02139, 8, 0),
(52409, 0, 4, 53485, 1041.26, -81.434, 55.424, 0.575959, 8, 0),
(52409, 0, 4, 53485, 1042.34, -32.1059, 55.4254, 5.68977, 8, 0),
(52409, 0, 4, 53485, 1049.27, -90.6892, 55.4259, 0.890118, 8, 0),
(52409, 0, 4, 53485, 1051.8, -24.0903, 55.4258, 5.41052, 8, 0),
(52409, 0, 4, 53485, 1063.59, -97.0573, 55.4934, 1.23918, 8, 0),
(52409, 0, 4, 53485, 1065.44, -17.7049, 55.425, 5.0091, 8, 0),
(52409, 0, 4, 53485, 1078.01, -97.776, 55.4227, 1.5708, 8, 0),
(52409, 0, 4, 53485, 1079.15, -15.5312, 55.423, 4.71239, 8, 0),
(52409, 0, 4, 53485, 1086.23, -96.1927, 55.4226, 4.71239, 8, 0),
(52409, 0, 4, 53485, 1086.42, -96.7812, 55.4226, 1.5708, 8, 0),
(52409, 0, 4, 53485, 1086.55, -18.0885, 55.4228, 1.5708, 8, 0),
(52409, 0, 4, 53485, 1087.91, -18.6493, 55.4237, 4.71239, 8, 0),
(52409, 0, 4, 53485, 1091.83, -21.9254, 55.4241, 4.71239, 8, 0),
(52409, 0, 4, 53485, 1092.52, -92.3924, 55.4241, 4.71239, 8, 0),
(52409, 0, 5, 53485, 1016.99, -57.5642, 55.4133, 0, 8, 0),
(52409, 0, 5, 53485, 1018.29, -70.1875, 55.4231, 0, 8, 0),
(52409, 0, 5, 53485, 1018.47, -43.7674, 55.4218, 0, 8, 0),
(52409, 0, 5, 53485, 1021.49, -79.6076, 55.4261, 0, 8, 0),
(52409, 0, 5, 53485, 1021.84, -33.7483, 55.4239, 0, 8, 0),
(52409, 0, 5, 53485, 1025.29, -86.2326, 55.4071, 0, 8, 0),
(52409, 0, 5, 53485, 1025.34, -25.8472, 55.4069, 0, 8, 0),
(52409, 0, 5, 53485, 1030.22, -92.8403, 55.4344, 0, 8, 0),
(52409, 0, 5, 53485, 1036.9, -14.6181, 55.5715, 0, 8, 0),
(52409, 0, 5, 53485, 1038.53, -100.254, 55.6012, 0, 8, 0),
(52409, 0, 5, 53485, 1049.66, -104.906, 55.4556, 0, 8, 0),
(52409, 0, 5, 53485, 1049.98, -7.22396, 55.4537, 0, 8, 0),
(52409, 0, 5, 53485, 1057.03, -4.10417, 55.4258, 0, 8, 0),
(52409, 0, 5, 53485, 1062.13, -109.005, 55.4259, 0, 8, 0),
(52409, 0, 5, 53485, 1062.94, -4.34201, 55.5682, 0, 8, 0),
(52409, 0, 5, 53485, 1069.91, -109.651, 55.4277, 0, 8, 0),
(52409, 0, 5, 53485, 1069.66, -4.53993, 55.4308, 0, 8, 0),
(52409, 0, 5, 53485, 1075.01, -111.233, 55.8345, 0, 8, 0),
(52409, 0, 6, 53485, 989.866, -66.0868, 55.4331, 0, 8, 0),
(52409, 0, 6, 53485, 988.208, -50.3646, 55.4291, 0, 8, 0),
(52409, 0, 6, 53485, 985.18, -77.3785, 55.4409, 0, 8, 0),
(52409, 0, 6, 53485, 986.608, -37.7656, 55.4411, 0, 8, 0),
(52409, 0, 6, 53485, 991.738, -87.1632, 55.4445, 0, 8, 0),
(52409, 0, 6, 53485, 991.799, -25.0955, 55.4441, 0, 8, 0),
(52409, 0, 6, 53485, 980.927, -58.2656, 55.4542, 0, 8, 0),
(52409, 0, 6, 53485, 1002, -58.2396, 55.4331, 0, 8, 0),
(52409, 0, 6, 53485, 1002.21, -49.7049, 55.4075, 0, 8, 0),
(52409, 0, 6, 53485, 1003.07, -66.4913, 55.4067, 0, 8, 0),
(52409, 0, 6, 53485, 1002.72, -40.7431, 55.4063, 0, 8, 0),
(52409, 0, 6, 53485, 1003.44, -74.0243, 55.4063, 0, 8, 0),
(52409, 0, 6, 53485, 999.755, -98.4792, 55.4426, 0, 8, 0),
(52409, 0, 6, 53485, 1000.81, -14.5069, 55.4566, 0, 8, 0),
(52409, 0, 6, 53485, 1005.49, -86.4566, 55.4275, 0, 8, 0),
(52409, 0, 6, 53485, 1006.1, -27.3681, 55.4277, 0, 8, 0),
(52409, 0, 6, 53485, 1005.8, -8.81771, 55.4672, 0, 8, 0),
(52409, 0, 6, 53485, 1012.09, -97.5122, 55.457, 0, 8, 0),
(52409, 0, 6, 53485, 1009.56, -108.161, 55.4697, 0, 8, 0),
(52409, 0, 6, 53485, 1014.15, -17.3281, 55.4629, 0, 8, 0),
(52409, 0, 6, 53485, 1012.7, -4.83333, 55.605, 0, 8, 0),
(52409, 0, 6, 53485, 1018.29, -117.833, 55.4471, 0, 8, 0),
(52409, 0, 6, 53485, 1019.6, 7.7691, 55.447, 0, 8, 0),
(52409, 0, 6, 53485, 1024.45, -8.13889, 55.447, 0, 8, 0),
(52409, 0, 6, 53485, 1024.91, -106.852, 55.4471, 0, 8, 0),
(52409, 0, 6, 53485, 1023.05, -128.257, 55.4471, 0, 8, 0),
(52409, 0, 6, 53485, 1023.83, 12.9774, 55.447, 0, 8, 0),
(52409, 0, 6, 53485, 1035.56, -114.156, 55.4471, 0, 8, 0),
(52409, 0, 6, 53485, 1035.91, 0.909722, 55.447, 0, 8, 0),
(52409, 0, 6, 53485, 1032.48, 13.2708, 55.4469, 0, 8, 0),
(52409, 0, 6, 53485, 1035.17, -125.646, 55.4471, 0, 8, 0),
(52409, 0, 6, 53485, 1049.74, -118.396, 55.5661, 0, 8, 0),
(52409, 0, 6, 53485, 1049.33, 5.0434, 55.4633, 0, 8, 0),
(52409, 0, 6, 53485, 1052.59, -120.562, 55.4563, 0, 8, 0),
(52409, 0, 6, 53485, 1055.34, 5.06771, 55.4471, 0, 8, 0),
(52409, 0, 7, 53231, 1026.86, 5.89583, 55.357, 4.90448, 8, 0),
(52409, 0, 7, 53231, 1027.31, -121.746, 55.3708, 1.36127, 8, 0),
(52409, 0, 8, 53872, 787.639, -59.9396, 86.2755, 6.20131, 8, 0),
(52409, 0, 8, 53875, 787.285, -68.8034, 94.0955, 3.33302, 8, 0),
(52409, 0, 8, 53876, 788.131, -50.6921, 94.0005, 2.96047, 8, 0),
(52409, 0, 9, 53952, 1041.278, -57.23958, 55.44501, 0, 8, 0),
(52409, 0, 10, 53952, 1014.509, -74.72743, 55.41998, 0, 8, 0),
(52409, 0, 10, 53952, 1014.66, -38.87153, 55.41859, 0, 8, 0),
(52409, 0, 10, 53952, 1060.047, -76.69965, 56.40898, 0, 8, 0),
(52409, 0, 10, 53952, 1063.8, -37.46007, 56.13575, 0, 8, 0);

-- Lava Wielder
UPDATE `creature_template` SET `difficulty_entry_1`=53902, `speed_walk`=1.42857, `BaseAttackTime`=1500, `mechanic_immune_mask`=650854263, `flags_extra`=1073741824, `ScriptName`='npc_fl_ragnaros_lava_wielder' WHERE `entry`=53575;
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `faction`=16, `speed_walk`=1.42857, `speed_run`=1.42857, `BaseAttackTime`=1500, `unit_flags`=32768, `mechanic_immune_mask`=650854263, `flags_extra`=1073741824 WHERE `entry`=53902;
-- Lava
UPDATE `creature_template` SET `InhabitType`=4, `ScriptName`='npc_fl_ragnaros_lava_wielder_lava' WHERE `entry`=53585;
-- Molten Spewer
UPDATE `creature_template` SET `difficulty_entry_1`=53906, `InhabitType`=4, `mechanic_immune_mask`=650854263, `flags_extra`=1073741824, `ScriptName`='npc_fl_ragnaros_molten_spewer' WHERE  `entry`=53545;
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `faction`=16, `InhabitType`=4, `mechanic_immune_mask`=650854263, `flags_extra`=1073741824, `VerifiedBuild`=0 WHERE `entry`=53906;
-- Molten Erupter
UPDATE `creature_template` SET `difficulty_entry_1`=53907, `InhabitType`=4, `mechanic_immune_mask`=650854263, `flags_extra`=1073741824, `ScriptName`='npc_fl_ragnaros_molten_erupter' WHERE  `entry`=53617;
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `faction`=16, `InhabitType`=4, `mechanic_immune_mask`=650854263, `flags_extra`=1073741824, `VerifiedBuild`=0 WHERE `entry`=53907;
-- Molten Eruption
UPDATE `creature_template` SET `speed_walk`=0.428571, `speed_run`=0.428571, `unit_flags`=33554432, `unit_flags2`=2099200, `flags_extra`=128, `ScriptName`='npc_fl_ragnaros_molten_eruption' WHERE `entry`=53621;
-- Magma
UPDATE `creature_template` SET `speed_walk`=0.428571, `unit_flags2`=2099200, `AIName`='NullCreatureAI', `InhabitType`=4, `VerifiedBuild`=0 WHERE `entry`=53729;
-- Ragnaros	
UPDATE `creature_template` SET `difficulty_entry_1`=53797, `difficulty_entry_2`=53798, `difficulty_entry_3`=53799, `speed_walk`=0.357143, `InhabitType`=4, `mechanic_immune_mask`=650854271, `flags_extra`=1073741825, `ScriptName`='boss_fl_ragnaros', `VerifiedBuild`=0 WHERE `entry`=52409;
UPDATE `creature_template` SET `minlevel`=88, `maxlevel`=88, `faction`=2234, `speed_walk`=0.357143, `speed_run`=1.42857, `BaseAttackTime`=1500, `unit_flags2`=134219776, `type_flags2`=128, `InhabitType`=4, `mechanic_immune_mask`=650854271, `flags_extra`=1073741825, `VerifiedBuild`=0 WHERE `entry`=53797;
UPDATE `creature_template` SET `minlevel`=88, `maxlevel`=88, `faction`=2234, `speed_walk`=0.357143, `speed_run`=1.42857, `BaseAttackTime`=1500, `unit_flags2`=134219776, `type_flags2`=128, `lootid`=53798, `InhabitType`=4, `mechanic_immune_mask`=650854271, `flags_extra`=1073741825, `VerifiedBuild`=0 WHERE `entry`=53798;
UPDATE `creature_template` SET `minlevel`=88, `maxlevel`=88, `faction`=2234, `speed_walk`=0.357143, `speed_run`=1.42857, `BaseAttackTime`=1500, `unit_flags2`=134219776, `type_flags2`=128, `lootid`=53799, `InhabitType`=4, `mechanic_immune_mask`=650854271, `flags_extra`=1073741825, `VerifiedBuild`=0 WHERE `entry`=53799;
-- Magma Trap
UPDATE `creature_template` SET `speed_walk`=0.428571, `speed_run`=0.428571, `unit_flags`=33554432, `unit_flags2`=2099200, `ScriptName`='npc_fl_ragnaros_magma_trap', `VerifiedBuild`=0 WHERE `entry`=53086;
-- Sulfuras Smash
UPDATE `creature_template` SET `speed_walk`=0.428571, `speed_run`=0.428571, `unit_flags`=33554432, `unit_flags2`=2099200, `AIName`='NullCreatureAI', `InhabitType`=4, `flags_extra`=128, `VerifiedBuild`=0 WHERE `entry`=53266;
-- Sulfuras, Hand of Ragnaros
UPDATE `creature_template` SET `speed_walk`=0.428571, `speed_run`=0.428571, `unit_flags`=33554432, `unit_flags2`=2129920, `AIName`='NullCreatureAI', `InhabitType`=4, `flags_extra`=128, `VerifiedBuild`=0 WHERE `entry`=53420;
-- Sulfuras Smash
UPDATE `creature_template` SET `speed_walk`=0.428571, `speed_run`=0.428571, `unit_flags`=33554432, `unit_flags2`=2099200, `InhabitType`=4, `flags_extra`=128, `ScriptName`='npc_fl_ragnaros_sulfuras_smash', `VerifiedBuild`=0 WHERE `entry`=53268;
-- Lava Wave
UPDATE `creature_template` SET `speed_walk`=2.14286, `speed_run`=2.14286,  `unit_flags`=33554432, `unit_flags2`=2099200, `InhabitType`=4, `flags_extra`=128, `ScriptName`='npc_fl_ragnaros_lava_wave', `VerifiedBuild`=0 WHERE `entry`=53363;
-- Splitting Blow
UPDATE `creature_template` SET `speed_walk`=0.428571, `unit_flags2`=2099200, `AIName`='NullCreatureAI', `InhabitType`=4, `flags_extra`=128, `VerifiedBuild`=0 WHERE `entry`=53393;
-- Son of Flame
UPDATE `creature_template` SET `difficulty_entry_1`=53800, `difficulty_entry_2`=53801, `difficulty_entry_3`=53802, `speed_walk`=0.357143, `unit_flags2`=2097152, `mechanic_immune_mask`=650852191, `ScriptName`='npc_fl_ragnaros_son_of_flame', `VerifiedBuild`=0 WHERE `entry`=53140;
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `faction`=16, `speed_walk`=0.357143, `speed_run`=0.142857, `unit_flags`=33554432, `unit_flags2`=2097152, `mechanic_immune_mask`=650852191, `VerifiedBuild`=0 WHERE `entry`=53800;
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `faction`=16, `speed_walk`=0.357143, `speed_run`=0.142857, `unit_flags`=33554432, `unit_flags2`=2097152, `mechanic_immune_mask`=650852191, `VerifiedBuild`=0 WHERE `entry`=53801;
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `faction`=16, `speed_walk`=0.357143, `speed_run`=0.142857, `unit_flags`=33554432, `unit_flags2`=2097152, `mechanic_immune_mask`=650852191, `VerifiedBuild`=0 WHERE `entry`=53802;
-- Molten Elemental
UPDATE `creature_template` SET `difficulty_entry_1`=53810, `difficulty_entry_2`=53811, `difficulty_entry_3`=53812, `speed_walk`=0.357143, `speed_run`=1.42857, `BaseAttackTime`=1000, `unit_flags`=33554432, `unit_flags2`=136316928, `mechanic_immune_mask`=650846751, `ScriptName`='npc_fl_ragnaros_molten_elemental', `VerifiedBuild`=0 WHERE `entry`=53189;
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `faction`=14, `speed_walk`=0.357143, `speed_run`=1.42857, `BaseAttackTime`=1000, `unit_flags`=33554432, `unit_flags2`=136316928, `mechanic_immune_mask`=650846751, `VerifiedBuild`=0 WHERE `entry`=53810;
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `faction`=14, `speed_walk`=0.357143, `speed_run`=1.42857, `BaseAttackTime`=1000, `unit_flags`=33554432, `unit_flags2`=136316928, `mechanic_immune_mask`=650846751, `VerifiedBuild`=0 WHERE `entry`=53811;
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `faction`=14, `speed_walk`=0.357143, `speed_run`=1.42857, `BaseAttackTime`=1000, `unit_flags`=33554432, `unit_flags2`=136316928, `mechanic_immune_mask`=650846751, `VerifiedBuild`=0 WHERE `entry`=53812;
-- Molten Seed Caster
UPDATE `creature_template` SET `speed_walk`=0.428571, `unit_flags2`=2099200, `InhabitType`=4, `AIName`='NullCreatureAI', `VerifiedBuild`=0 WHERE `entry`=53186;
-- Engulfing Flames
UPDATE `creature_template` SET `speed_walk`=0.428571, `unit_flags2`=2099200, `InhabitType`=4, `ScriptName`='npc_fl_ragnaros_engulfing_flames', `VerifiedBuild`=0 WHERE `entry`=53485;
-- Lava Scion
UPDATE `creature_template` SET `difficulty_entry_1`=53816, `difficulty_entry_2`=53817, `difficulty_entry_3`=53818, `speed_walk`=1.42857, `unit_flags2`=2099200, `mechanic_immune_mask`=650852191, `flags_extra`=1073741824, `ScriptName`='npc_fl_ragnaros_lava_scion', `VerifiedBuild`=0 WHERE `entry`=53231;
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `faction`=14, `speed_walk`=1.42857, `speed_run`=1.42857, `BaseAttackTime`=1500, `unit_flags`=32768, `unit_flags2`=2099200, `mechanic_immune_mask`=650852191, `flags_extra`=1073741824, `VerifiedBuild`=0 WHERE `entry`=53816;
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `faction`=14, `speed_walk`=1.42857, `speed_run`=1.42857, `BaseAttackTime`=1500, `unit_flags`=32768, `unit_flags2`=2099200, `mechanic_immune_mask`=650852191, `flags_extra`=1073741824, `VerifiedBuild`=0 WHERE `entry`=53817;
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `faction`=14, `speed_walk`=1.42857, `speed_run`=1.42857, `BaseAttackTime`=1500, `unit_flags`=32768, `unit_flags2`=2099200, `mechanic_immune_mask`=650852191, `flags_extra`=1073741824, `VerifiedBuild`=0 WHERE `entry`=53818;
-- Blazing Heat
UPDATE `creature_template` SET `speed_walk`=0.428571, `speed_run`=0.428571, `unit_flags`=33554432, `unit_flags2`=2099200, `AIName`='NullCreatureAI', `InhabitType`=4, `flags_extra`=128, `VerifiedBuild`=0 WHERE `entry`=53473;
-- Living Meteor
UPDATE `creature_template` SET `difficulty_entry_1`=53813, `difficulty_entry_2`=53814, `difficulty_entry_3`=53815, `speed_walk`=0.714286, `speed_run`=0.714286, `unit_flags`=526336, `unit_flags2`=136316928, `mechanic_immune_mask`=650854271, `flags_extra`=1073741824, `ScriptName`='npc_fl_ragnaros_living_meteor', `VerifiedBuild`=0 WHERE `entry`=53500;
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `faction`=14, `speed_walk`=0.714286, `speed_run`=0.714286, `unit_flags`=526336, `unit_flags2`=136316928, `mechanic_immune_mask`=650854271, `flags_extra`=1073741824, `VerifiedBuild`=0 WHERE `entry`=53813;
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `faction`=14, `speed_walk`=0.714286, `speed_run`=0.714286, `unit_flags`=526336, `unit_flags2`=136316928, `mechanic_immune_mask`=650854271, `flags_extra`=1073741824, `VerifiedBuild`=0 WHERE `entry`=53814;
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `faction`=14, `speed_walk`=0.714286, `speed_run`=0.714286, `unit_flags`=526336, `unit_flags2`=136316928, `mechanic_immune_mask`=650854271, `flags_extra`=1073741824, `VerifiedBuild`=0 WHERE `entry`=53815;
-- Cenarius
UPDATE `creature_template` SET `speed_walk`=0.428571, `unit_flags2`=4194304, `ScriptName`='npc_fl_ragnaros_cenarius', `VerifiedBuild`=0 WHERE `entry`=53872;
-- Malfurion Stormrage
UPDATE `creature_template` SET `speed_walk`=0.357143, `unit_flags2`=4196352, `ScriptName`='npc_fl_ragnaros_malfurion_stormrage', `VerifiedBuild`=0 WHERE `entry`=53875;
-- Arch Druid Hamuul Runetotem
UPDATE `creature_template` SET `speed_walk`=0.357143, `unit_flags2`=4196352, `ScriptName`='npc_fl_ragnaros_hamuul_runetotem', `VerifiedBuild`=0 WHERE `entry`=53876;
-- Dreadflame
UPDATE `creature_template` SET `speed_walk`=0.357143, `unit_flags`=33554432, `unit_flags2`=4196352, `InhabitType`=4, `flags_extra`=128, `ScriptName`='npc_fl_ragnaros_dreadflame', `VerifiedBuild`=0 WHERE `entry`=54127;
-- Dreadflame Spawn
UPDATE `creature_template` SET `speed_walk`=0.357143, `unit_flags2`=2099200, `AIName`='NullCreatureAI', `InhabitType`=4, `flags_extra`=128, `VerifiedBuild`=0 WHERE `entry`=54203;
-- Platform Stalker
UPDATE `creature_template` SET `speed_walk`=0.428571, `unit_flags2`=2099200, `InhabitType`=4, `ScriptName`='npc_fl_ragnaros_platform_stalker', `VerifiedBuild`=0 WHERE `entry`=53952;
-- Cloudburst
UPDATE `creature_template` SET `npcflag`=16777216, `speed_walk`=0.428571, `speed_run`=0.428571, `unit_flags2`=2099200, `InhabitType`=4, `ScriptName`='npc_fl_ragnaros_cloudburst', `VerifiedBuild`=0 WHERE `entry`=54147;
-- Entrapping Roots
UPDATE `creature_template` SET `speed_walk`=0.428571, `speed_run`=0.428571, `unit_flags`=33554432, `unit_flags2`=2099200, `InhabitType`=4, `flags_extra`=128, `ScriptName`='npc_fl_ragnaros_entrapping_roots', `VerifiedBuild`=0 WHERE `entry`=54074;
-- Breadth of Frost
UPDATE `creature_template` SET `speed_walk`=0.428571, `speed_run`=0.428571, `unit_flags`=33554432, `unit_flags2`=2099200, `InhabitType`=4, `flags_extra`=128, `ScriptName`='npc_fl_ragnaros_breadth_of_frost', `VerifiedBuild`=0 WHERE `entry`=53953;
-- Heart of Ragnaros
UPDATE `creature_template` SET `npcflag`=16777216, `unit_flags2`=67108864, `InhabitType`=4, `ScriptName`='npc_fl_ragnaros_heart_of_ragnaros' WHERE `entry`=54293;

-- Magma
UPDATE `creature_template_addon` SET `auras`='99908' WHERE `entry`=53729;
-- Ragnaros - 25 Normal
DELETE FROM `creature_template_addon` WHERE `entry`=53797;
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`) VALUES (53797, 50331648, 1);
-- Ragnaros - 10 Heroic
DELETE FROM `creature_template_addon` WHERE `entry`=53798;
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`) VALUES (53798, 50331648, 1);
-- Ragnaros - 25 Heroic
DELETE FROM `creature_template_addon` WHERE `entry`=53799;
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`) VALUES (53799, 50331648, 1);
-- Blazing Heat
DELETE FROM `creature_template_addon` WHERE `entry`=53473;
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES (53473, 1, '99128');
-- Heart of Flame
DELETE FROM `creature_template_addon` WHERE `entry`=54293;
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`, `auras`) VALUES (54293, 50331648, 1, '101127');

-- Ragnaros Texts
DELETE FROM `creature_text` WHERE `CreatureID`=52409;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(52409, 0, 0, 'Mortal Insects! You dare trespass into MY domain?  Your arrogance will be purged in living flame.', 14, 0, 100, 0, 0, 24517, 52203, 1, 'Ragnaros - Intro'),
(52409, 1, 0, 'Die, insect!', 14, 0, 100, 0, 0, 24531, 52204, 1, 'Ragnaros - Kill'),
(52409, 1, 1, 'Pathetic.', 14, 0, 100, 0, 0, 24530, 52205, 1, 'Ragnaros - Kill'),
(52409, 1, 2, 'This is MY realm!', 14, 0, 100, 0, 0, 24529, 52206, 1, 'Ragnaros - Kill'),
(52409, 2, 0, 'Come forth, my servants! Defend your master!', 14, 0, 100, 0, 0, 24513, 52207, 1, 'Ragnaros - Splitting Blow Submerge'),
(52409, 2, 1, 'Minions of fire! Purge the outsiders!', 14, 0, 100, 0, 0, 24514, 52208, 1, 'Ragnaros - Splitting Blow Submerge'),
(52409, 2, 2, 'Denizens of flame, come to me!', 14, 0, 100, 0, 0, 24515, 52209, 1, 'Ragnaros - Splitting Blow Submerge'),
(52409, 2, 3, 'Arise, servants of fire, consume their flesh!', 14, 0, 100, 0, 0, 24516, 52210, 1, 'Ragnaros - Splitting Blow Submerge'),
(52409, 3, 0, 'By fire be purged!', 14, 0, 100, 0, 0, 24532, 52211, 1, 'Ragnaros - Wrath of Ragnaros'),
(52409, 4, 0, 'You will be crushed!', 14, 0, 100, 0, 0, 24520, 52212, 1, 'Ragnaros - Splitting Blow'),
(52409, 4, 1, 'Die!', 14, 0, 100, 0, 0, 24521, 52213, 1, 'Ragnaros - Splitting Blow'),
(52409, 4, 2, 'Your judgement has come!', 14, 0, 100, 0, 0, 24522, 52214, 1, 'Ragnaros - Splitting Blow'),
(52409, 5, 0, 'Enough! I will finish this.', 14, 0, 100, 0, 0, 24523, 52215, 1, 'Ragnaros - Splitting Blow Emerge'),
(52409, 5, 1, 'Fall to your knees, mortals!  This ends now.', 14, 0, 100, 0, 0, 24524, 52216, 1, 'Ragnaros - Splitting Blow Emerge'),
(52409, 5, 2, 'Sulfuras will be your end.', 14, 0, 100, 0, 0, 24525, 52217, 1, 'Ragnaros - Splitting Blow Emerge'),
(52409, 6, 0, 'Too soon! ... You have come too soon...', 14, 0, 100, 0, 0, 24519, 52218, 1, 'Ragnaros - Defeat'),
(52409, 7, 0, 'Too soon...', 14, 0, 100, 0, 0, 24528, 52219, 1, 'Ragnaros - Heroic Transition'),
(52409, 8, 0, 'Arrggh, outsiders - this is not your realm!', 14, 0, 100, 0, 0, 24527, 52220, 1, 'Ragnaros - Heroic Transition'),
(52409, 9, 0, 'When I finish this, your pathetic mortal world will burn with my vengeance!', 14, 0, 100, 0, 0, 24526, 52221, 1, 'Ragnaros - Heroic Transition'),
(52409, 10, 0, 'No, noooo- This was to be my hour of triumph...', 14, 0, 100, 0, 0, 24518, 52222, 1, 'Ragnaros - Death'),
(52409, 11, 0, 'Begone from my realm, insects.', 14, 0, 100, 0, 0, 24533, 52411, 1, 'Ragnaros - Aggro'),
(52409, 11, 1, 'I will see you all burn.', 14, 0, 100, 0, 0, 24534, 52412, 1, 'Ragnaros - Aggro'),
(52409, 11, 2, 'Be consumed by flame!', 14, 0, 100, 0, 0, 24535, 52413, 1, 'Ragnaros - Aggro'),
(52409, 11, 3, 'The realm of fire will consume you!', 14, 0, 100, 0, 0, 24536, 52414, 1, 'Ragnaros - Aggro'),
(52409, 12, 0, 'Deathwing has prepared me to face the vessel of Tarecgosa, your fools journey ends here!', 14, 0, 100, 0, 0, 25162, 52852, 1, 'Ragnaros - Rage of Ragnaros'),
(52409, 13, 0, '|TInterface\\Icons\\ability_mage_worldinflames.blp:20|t%s begins to cast |cFFFF6600|Hspell:99171|h[Engulfing Flames]|h|r!', 41, 0, 100, 0, 0, 0, 52084, 1, 'Ragnaros - Engulfing Flames'),
(52409, 14, 0, '|TInterface\\Icons\\spell_fire_ragnaros_splittingblow.blp:20|t%s begins to cast |cFFFF0000|Hspell:98951|h[Splitting Blow]|h|r!', 41, 0, 100, 0, 0, 0, 52114, 1, 'Ragnaros - Splitting Blow'),
(52409, 15, 0, '|TInterface\\Icons\\spell_fire_selfdestruct.blp:20|t%s casts |cFFFF6600|Hspell:98164|h[Magma Trap]|h|r!', 41, 0, 100, 0, 0, 0, 52115, 1, 'Ragnaros - Magma Trap'),
(52409, 16, 0, '|TInterface\\Icons\\spell_shaman_lavasurge.blp:20|t%s begins to cast |cFFFF0000|Hspell:98710|h[Sulfuras Smash]|h|r!', 41, 0, 100, 0, 0, 0, 52125, 1, 'Ragnaros - Sulfuras Smash'),
(52409, 17, 0, '|TInterface\\Icons\\ability_mage_worldinflames.blp:20|t%s begins to cast |cFFFF6600|Hspell:100171|h[World In Flames]|h|r!', 41, 0, 100, 0, 0, 0, 52450, 1, 'Ragnaros - World In Flames'),
(52409, 18, 0, '|TInterface\\Icons\\inv_mace_2h_sulfuras_d_01.blp:20|t%s begins to cast |cFFFF6600|Hspell:100604|h[Empower Sulfuras]|h|r!', 41, 0, 100, 0, 0, 0, 52709, 1, 'Ragnaros - Empower Sulfuras'),
(52409, 19, 0, '|TInterface\\Icons\\ability_mage_firestarter.blp:20|t%s casts |cFFFF0000|Hspell:100675|h[Dreadflame]|h|r!', 41, 0, 100, 0, 0, 0, 52849, 1, 'Ragnaros - Dreadflame'),
(52409, 20, 0, '|TInterface\\Icons\\achievement_boss_ragnaros.blp:20|tYou are about to cast |cFFFF0000|Hspell:101109|h[Rage of Ragnaros]|h|r!', 42, 0, 100, 0, 0, 0, 52887, 0, 'Ragnaros - Rage of Ragnaros'),
(52409, 21, 0, '%s is about to |cFFFF0000Emerge|r!', 41, 0, 100, 0, 0, 0, 52594, 1, 'Ragnaros - Splitting Blow Emerge'),
(52409, 22, 0, '%s goes into a berserker rage!', 41, 0, 100, 0, 0, 0, 4428, 1, 'Ragnaros - Berserk');

-- Lava Scion
DELETE FROM `creature_text` WHERE `CreatureID`=53231;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(53231, 0, 0, '|TInterface\\Icons\\inv_elemental_mote_fire01.blp:16|tYou are about to burst into |cFFFF0000|Hspell:100460|h[Blazing Heat]|h|r!', 42, 0, 100, 0, 0, 0, 52819, 0, 'Lava Scion - Blazing Heat Warning');

-- Cenarius Texts
DELETE FROM `creature_text` WHERE `CreatureID`=53872;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(53872, 0, 0, 'No, fiend. Your time is NOW.', 14, 0, 100, 0, 0, 25159, 52569, 1, 'Cenarius - Ragnaros Heroic Phase'),
(53872, 1, 0, 'Perhaps...', 14, 0, 100, 0, 0, 25160, 52572, 1, 'Cenarius - Ragnaros Heroic Outro'),
(53872, 2, 0, 'Ragnaros has perished.  But the primal powers he represents can never be vanquished.  Another will rise to power, someday.', 14, 0, 100, 0, 0, 25158, 52574, 1, 'Cenarius - Ragnaros Heroic Outro'),
(53872, 3, 0, 'Indeed.', 14, 0, 100, 0, 0, 25161, 52576, 1, 'Cenarius - Ragnaros Heroic Outro');

-- Malfurion Stormrage Texts
DELETE FROM `creature_text` WHERE `CreatureID`=53875;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(53875, 0, 0, 'Heroes! He is bound. Finish him!', 14, 0, 100, 0, 0, 25169, 52570, 1, 'Malfurion Stormrage - Ragnaros Heroic Phase'),
(53875, 1, 0, 'It is finished then!', 14, 0, 100, 0, 0, 25170, 52571, 1, 'Malfurion Stormrage - Ragnaros Heroic Outro'),
(53875, 2, 0, 'Heroes, the world owes you a great debt.', 14, 0, 100, 0, 0, 25171, 52573, 1, 'Malfurion Stormrage - Ragnaros Heroic Outro');

-- Arch Druid Hamuul Runetotem Texts
DELETE FROM `creature_text` WHERE `CreatureID`=53876;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(53876, 0, 0, 'Yes Cenarius, we must maintain a constant vigil over this realm.  But let us celebrate this day and the great victory we have earned here.', 14, 0, 100, 0, 0, 25168, 52575, 1, 'Arch Druid Hamuul Runetotem - Ragnaros Heroic Outro');

-- Achievement - Ragnar-O's
DELETE FROM `criteria_data` WHERE `criteria_id`=17863;
INSERT INTO `criteria_data` (`criteria_id`, `type`, `ScriptName`) VALUES (17863, 11, 'achievement_ragnar_os');

-- Remove Lava Wielder Fire Wall temp spawn
DELETE FROM `gameobject` WHERE guid IN (200163, 200169);

-- Cache of the Fire Lord (10-man Normal)
DELETE FROM `gameobject_loot_template` WHERE `Entry`=40061;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(40061, 69815,     0, 100, 1, 1, 1, 18, 23, 'Cache of the Fire Lord 10N - Seething Cinder'),
(40061, 71141,     0,  80, 1, 1, 1,  1,  1, 'Cache of the Fire Lord 10N - Eternal Ember'),
(40061,     1, 50020, 100, 0, 1, 1,  2,  2, 'Cache of the Fire Lord 10N - Gear'),
(40061,     2, 50021, 100, 0, 1, 1,  1,  1, 'Cache of the Fire Lord 10N - Token'),
(40061, 69224,     0,   1, 0, 1, 1,  1,  1, 'Cache of the Fire Lord 10N - Smoldering Egg of Millagazor');

-- Cache of the Fire Lord (25-man Normal)
DELETE FROM `gameobject_loot_template` WHERE `Entry`=40107;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(40107, 69815,     0, 100, 1, 1, 1, 48, 55, 'Cache of the Fire Lord 25N - Seeting Cinder'),
(40107, 71141,     0, 100, 1, 1, 1,  1,  3, 'Cache of the Fire Lord 25N - Eternal Ember'),
(40107,     1, 50020, 100, 0, 1, 1,  5,  5, 'Cache of the Fire Lord 25N - Gear'),
(40107,     2, 50021, 100, 0, 1, 1,  3,  3, 'Cache of the Fire Lord 25N - Tokens'),
(40107, 69224,     0,   1, 0, 1, 1,  1,  1, 'Cache of the Fire Lord 25N - Smoldering Egg of Millagazor');

-- Add Deluge spell click to Cloudburst
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN(54147,54293);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(54147, 100713, 3, 1),
(54293, 101125, 3, 1);

-- Normal shared items
DELETE FROM `reference_loot_template` WHERE `Entry`=50018;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(50018, 71782, 0,     16, 0, 1, 1, 1, 1, 'Normal - Shatterskull Bonecrusher'),
(50018, 71775, 0,     16, 0, 1, 1, 1, 1, 'Normal - Smoldering Censer of Purity'),
(50018, 71776, 0,     16, 0, 1, 1, 1, 1, 'Normal - Eye of Purification'),
(50018, 71780, 0,     13, 0, 1, 1, 1, 1, 'Normal - Zoid\'s Firelit Greatsword'),
(50018, 71779, 0,     11, 0, 1, 1, 1, 1, 'Normal - Avool\'s Incendiary Shanker'),
(50018, 71787, 0,     11, 0, 1, 1, 1, 1, 'Normal - Entrail Disgorger'),
(50018, 71785, 0,     17, 0, 1, 1, 1, 1, 'Normal - Firethorn Mindslicer');
-- Heroic shared items
DELETE FROM `reference_loot_template` WHERE `Entry`=50019;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(50019, 71783, 0,     15, 0, 1, 1, 1, 1, 'Heroic - Shatterskull Bonecrusher'),
(50019, 71774, 0,     15, 0, 1, 1, 1, 1, 'Heroic - Smoldering Censer of Purity'),
(50019, 71777, 0,     15, 0, 1, 1, 1, 1, 'Heroic - Eye of Purification'),
(50019, 71781, 0,     12, 0, 1, 1, 1, 1, 'Heroic - Zoid\'s Firelit Greatsword'),
(50019, 71778, 0,     11, 0, 1, 1, 1, 1, 'Heroic - Avool\'s Incendiary Shanker'),
(50019, 71786, 0,     11, 0, 1, 1, 1, 1, 'Heroic - Entrail Disgorger'),
(50019, 71784, 0,     16, 0, 1, 1, 1, 1, 'Heroic - Firethorn Mindslicer'),
(50019, 71617, 0,      5, 0, 1, 1, 1, 1, 'Heroic - Crystallized Firestone');
-- Ragnaros normal
DELETE FROM `reference_loot_template` WHERE `Entry`=50020;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(50020, 71354,     0, 11, 0, 1, 1, 1, 1, 'Normal - Choker of the Vanquished Lord'),
(50020, 68994,     0, 10, 0, 1, 1, 1, 1, 'Normal - Matrix Restabilizer'),
(50020, 68925,     0, 10, 0, 1, 1, 1, 1, 'Normal - Variable Pulse Lightning Capacitor'),
(50020, 68995,     0, 10, 0, 1, 1, 1, 1, 'Normal - Vessel of Acceleration'),
(50020, 71355,     0,  9, 0, 1, 1, 1, 1, 'Normal - Ko\'gun, Hammer of the Firelord'),
(50020, 71353,     0,  8, 0, 1, 1, 1, 1, 'Normal - Arathar, the Eye of Flame'),
(50020, 71358,     0,  8, 0, 1, 1, 1, 1, 'Normal - Fingers of Incineration'),
(50020, 71357,     0,  8, 0, 1, 1, 1, 1, 'Normal - Majordomo\'s Chain of Office'),
(50020, 71798,     0,  8, 0, 1, 1, 1, 1, 'Normal - Sho\'ravon, Greatstaff of Annihilation'),
(50020, 71356,     0,  5, 0, 1, 1, 1, 1, 'Normal - Crown of Flame'),
(50020, 70921,     0,  5, 0, 1, 1, 1, 1, 'Normal - Pauldrons of Roaring Flame'),
(50020, 71352,     0,  3, 0, 1, 1, 1, 1, 'Normal - Sulfuras, the Extinguished Hand'),
(50020,     1, 50018,  5, 0, 1, 1, 1, 1, 'Heroic - Shared loot table');
-- Ragnaros normal tokens
DELETE FROM `reference_loot_template` WHERE `Entry`=50021;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(50021, 71668,     0, 40, 0, 1, 1, 1, 1, 'Normal - Helm of the Fiery Vanquisher'),
(50021, 71675,     0, 30, 0, 1, 1, 1, 1, 'Normal - Helm of the Fiery Conqueror'),
(50021, 71682,     0, 30, 0, 1, 1, 1, 1, 'Normal - Helm of the Fiery Protector');
-- Ragnaros heroic
DELETE FROM `reference_loot_template` WHERE `Entry`=50022;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(50022, 71610,     0, 11, 0, 1, 1, 1, 1, 'Heroic - Choker of the Vanquished Lord'),
(50022, 69150,     0, 10, 0, 1, 1, 1, 1, 'Heroic - Matrix Restabilizer'),
(50022, 69110,     0, 10, 0, 1, 1, 1, 1, 'Heroic - Variable Pulse Lightning Capacitor'),
(50022, 69167,     0, 10, 0, 1, 1, 1, 1, 'Heroic - Vessel of Acceleration'),
(50022, 71615,     0,  9, 0, 1, 1, 1, 1, 'Heroic - Ko\'gun, Hammer of the Firelord'),
(50022, 71611,     0,  8, 0, 1, 1, 1, 1, 'Heroic - Arathar, the Eye of Flame'),
(50022, 71614,     0,  8, 0, 1, 1, 1, 1, 'Heroic - Fingers of Incineration'),
(50022, 71613,     0,  8, 0, 1, 1, 1, 1, 'Heroic - Majordomo\'s Chain of Office'),
(50022, 71797,     0,  8, 0, 1, 1, 1, 1, 'Heroic - Sho\'ravon, Greatstaff of Annihilation'),
(50022, 71616,     0,  5, 0, 1, 1, 1, 1, 'Heroic - Crown of Flame'),
(50022, 71612,     0,  5, 0, 1, 1, 1, 1, 'Heroic - Pauldrons of Roaring Flame'),
(50022, 70723,     0,  3, 0, 1, 1, 1, 1, 'Heroic - Sulfuras, the Extinguished Hand'),
(50022,     1, 50019,  5, 0, 1, 1, 1, 1, 'Heroic - Shared loot table');
-- Ragnaros heroic tokens
DELETE FROM `reference_loot_template` WHERE `Entry`=50023;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(50023, 71670,     0, 40, 0, 1, 1, 1, 1, 'Heroic - Crown of the Fiery Vanquisher'),
(50023, 71677,     0, 30, 0, 1, 1, 1, 1, 'Heroic - Crown of the Fiery Conqueror'),
(50023, 71684,     0, 30, 0, 1, 1, 1, 1, 'Heroic - Crown of the Fiery Protector');

-- Burning Wounds 5 second cooldown
DELETE FROM `spell_proc` WHERE `SpellId`=99399;
INSERT INTO `spell_proc` (`SpellId`,`Cooldown`) VALUES
(99399, 4);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_fl_ragnaros_lava_wielder_raise_lava',
'spell_fl_ragnaros_lava_spewer_submerge',
'spell_fl_ragnaros_magma',
'spell_fl_ragnaros_burning_blast',
'spell_fl_ragnaros_rage_of_ragnaros',
'spell_fl_ragnaros_rage_of_ragnaros_dummy',
'spell_fl_ragnaros_magma_trap',
'spell_fl_ragnaros_magma_trap_dummy',
'spell_fl_ragnaros_wrath_of_ragnaros',
'spell_fl_ragnaros_sulfuras_smash',
'spell_fl_ragnaros_sulfuras_smash_summon',
'spell_fl_ragnaros_sulfuras_smash_player_trigger',
'spell_fl_ragnaros_invoke_sons',
'spell_fl_ragnaros_burning_speed',
'spell_fl_ragnaros_splitting_blow',
'spell_fl_ragnaros_splitting_blow_dummy',
'spell_fl_ragnaros_molten_seed_grow',
'spell_fl_ragnaros_molten_seed_target_search',
'spell_fl_ragnaros_molten_seed_missile_target_search',
'spell_fl_ragnaros_molten_inferno',
'spell_fl_ragnaros_engulfing_flames_near',
'spell_fl_ragnaros_engulfing_flames_near_visual',
'spell_fl_ragnaros_engulfing_flames_middle',
'spell_fl_ragnaros_engulfing_flames_middle_visual',
'spell_fl_ragnaros_engulfing_flames_far',
'spell_fl_ragnaros_engulfing_flames_far_visual',
'spell_fl_ragnaros_world_in_flames',
'spell_fl_ragnaros_blazing_heat_spawn',
'spell_fl_ragnaros_blazing_heat_target_search',
'spell_fl_ragnaros_living_meteor_target_search',
'spell_fl_ragnaros_living_meteor_combustible',
'spell_fl_ragnaros_magma_knockup',
'spell_fl_ragnaros_dreadflame_dummy',
'spell_fl_ragnaros_dreadflame_spawn_control_aura',
'spell_fl_ragnaros_dreadflame_spread_control_aura',
'spell_fl_ragnaros_dreadflame_damage_control_aura',
'spell_fl_ragnaros_dreadflame_deluge_control_aura',
'spell_fl_ragnaros_npc_helper_summon',
'spell_fl_ragnaros_cloudburst',
'spell_fl_ragnaros_entrapping_roots',
'spell_fl_ragnaros_entrapping_roots_trigger',
'spell_fl_ragnaros_breadth_of_frost_trigger',
'spell_fl_ragnaros_breadth_of_frost_player_aura',
'spell_fl_ragnaros_breadth_of_frost_meteor_aura',
'spell_fl_ragnaros_empower_sulfuras',
'spell_fl_ragnaros_empower_sulfuras_aura',
'spell_fl_ragnaros_empower_sulfuras_aura_dummy',
'spell_fl_ragnaros_deluge_aura_cancel',
'spell_fl_ragnaros_heart_of_ragnaros_h',
'spell_fl_ragnaros_heart_of_ragnaros_a');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(99503,  'spell_fl_ragnaros_lava_wielder_raise_lava'),
(99593,  'spell_fl_ragnaros_lava_spewer_submerge'),
(99907,  'spell_fl_ragnaros_magma'),
(99400,  'spell_fl_ragnaros_burning_blast'),
(101110, 'spell_fl_ragnaros_rage_of_ragnaros'),
(101107, 'spell_fl_ragnaros_rage_of_ragnaros_dummy'),
(98159,  'spell_fl_ragnaros_magma_trap'),
(98171,  'spell_fl_ragnaros_magma_trap_dummy'),
(98259,  'spell_fl_ragnaros_wrath_of_ragnaros'),
(98710,  'spell_fl_ragnaros_sulfuras_smash'),
(98706,  'spell_fl_ragnaros_sulfuras_smash_summon'),
(98703,  'spell_fl_ragnaros_sulfuras_smash_player_trigger'),
(99054,  'spell_fl_ragnaros_invoke_sons'),
(98473,  'spell_fl_ragnaros_burning_speed'),
(98951,  'spell_fl_ragnaros_splitting_blow'),
(98952,  'spell_fl_ragnaros_splitting_blow'),
(98953,  'spell_fl_ragnaros_splitting_blow'),
(99012,  'spell_fl_ragnaros_splitting_blow_dummy'),
(98520,  'spell_fl_ragnaros_molten_seed_grow'),
(98333,  'spell_fl_ragnaros_molten_seed_target_search'),
(98497,  'spell_fl_ragnaros_molten_seed_missile_target_search'),
(98518,  'spell_fl_ragnaros_molten_inferno'),
(99172,  'spell_fl_ragnaros_engulfing_flames_near'),
(99216,  'spell_fl_ragnaros_engulfing_flames_near_visual'),
(99235,  'spell_fl_ragnaros_engulfing_flames_middle'),
(99217,  'spell_fl_ragnaros_engulfing_flames_middle_visual'),
(99236,  'spell_fl_ragnaros_engulfing_flames_far'),
(99218,  'spell_fl_ragnaros_engulfing_flames_far_visual'),
(99171,  'spell_fl_ragnaros_world_in_flames'),
(99125,  'spell_fl_ragnaros_blazing_heat_spawn'),
(100459, 'spell_fl_ragnaros_blazing_heat_target_search'),
(99267,  'spell_fl_ragnaros_living_meteor_target_search'),
(99296,  'spell_fl_ragnaros_living_meteor_combustible'),
(108773, 'spell_fl_ragnaros_magma_knockup'),
(100691, 'spell_fl_ragnaros_dreadflame_dummy'),
(100906, 'spell_fl_ragnaros_dreadflame_spawn_control_aura'),
(100695, 'spell_fl_ragnaros_dreadflame_spread_control_aura'),
(100966, 'spell_fl_ragnaros_dreadflame_damage_control_aura'),
(100823, 'spell_fl_ragnaros_dreadflame_deluge_control_aura'),
(100644, 'spell_fl_ragnaros_npc_helper_summon'),
(100476, 'spell_fl_ragnaros_npc_helper_summon'),
(100751, 'spell_fl_ragnaros_cloudburst'),
(100653, 'spell_fl_ragnaros_entrapping_roots'),
(100645, 'spell_fl_ragnaros_entrapping_roots_trigger'),
(100472, 'spell_fl_ragnaros_breadth_of_frost_trigger'),
(100503, 'spell_fl_ragnaros_breadth_of_frost_player_aura'),
(100567, 'spell_fl_ragnaros_breadth_of_frost_meteor_aura'),
(100604, 'spell_fl_ragnaros_empower_sulfuras'),
(100628, 'spell_fl_ragnaros_empower_sulfuras_aura'),
(100605, 'spell_fl_ragnaros_empower_sulfuras_aura_dummy'),
(100771, 'spell_fl_ragnaros_deluge_aura_cancel'),
(101252, 'spell_fl_ragnaros_heart_of_ragnaros_h'),
(101253, 'spell_fl_ragnaros_heart_of_ragnaros_a');

DELETE FROM `spell_target_position` WHERE `ID` IN (101095);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`) VALUES
(101095, 0, 720, 1012.49, -57.2882, 55.3302);
