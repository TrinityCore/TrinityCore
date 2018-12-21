-- Template Updates
-- Zanzil
UPDATE `creature_template` SET `DamageModifier`= 65, `mechanic_immune_mask`= 80297855, `mingold`= 20000, `maxgold`= 22500 WHERE `entry`= 52053;
-- Zanzil's Toxic Gas
UPDATE `creature_template` SET `unit_flags`= 33554432, `unit_flags2`= 4196352, `flags_extra`= 128 WHERE `entry`= 52062;
-- Zanzili Berserker
UPDATE `creature_template` SET `ScriptName`= 'npc_zanzil_zanzili_berserker', `DamageModifier`= 65, `mechanic_immune_mask`= 1 | 2 | 4 | 8 | 16 | 32 | 64 | 256 | 4096 | 8192 | 65536 | 131072 | 33554432 | 8388608 | 2048 , `flags_extra`= 256 | 1073741824 WHERE `entry`= 52054;
-- Zanzili Zombie
UPDATE `creature_template` SET `DamageModifier`= 10 WHERE `entry`= 52055;

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_zanzil_zanzili_fire',
'spell_zanzil_zanzils_resurrection_elixir',
'spell_zanzil_zanzils_resurrection_elixir_red_script',
'spell_zanzil_zanzils_graveyard_gas',
'spell_zanzil_frostburn_formula');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(96914, 'spell_zanzil_zanzili_fire'),
(96316, 'spell_zanzil_zanzils_resurrection_elixir'),
(96319, 'spell_zanzil_zanzils_resurrection_elixir'),
(96470, 'spell_zanzil_zanzils_resurrection_elixir_red_script'),
(96339, 'spell_zanzil_zanzils_graveyard_gas'),
(96325, 'spell_zanzil_frostburn_formula');

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (96317, 96316, 96319, 96470, 96339) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 96317, 0, 0, 31, 0, 3, 52054, 0, 0, 0, '', 'Zanzil''s Resurrection Elixir - Target Zanzili Berserker'),
(13, 1, 96470, 0, 0, 31, 0, 3, 52055, 0, 0, 0, '', 'Zanzil''s Resurrection Elixir - Target Zanzili Zombie'),
(13, 1, 96339, 0, 0, 31, 0, 3, 52062, 0, 0, 0, '', 'Zanzil''s Graveyard Gas - Target Zanzil''s Toxic Gas');

-- Template Addons
UPDATE `creature_template_addon` SET `aiAnimKit`= 1288 WHERE `entry`= 52055;
UPDATE `creature_template_addon` SET `aiAnimKit`= 1293 WHERE `entry`= 52054;

-- Delete encounter related creatures
DELETE FROM `creature` WHERE `guid` IN (294874, 295332, 335931, 335932, 335933, 335934, 335935, 335936, 335940, 335941, 335943, 335944, 335945, 335946, 335947, 335948, 335949, 335950, 335951, 335952, 335953, 335954, 335955, 335956, 335957, 335958, 335959, 335960, 335962, 335963, 335964, 335965, 335966, 335967, 335968, 335969, 335970, 335971, 335972, 335973, 335974, 335975, 335976, 335977, 335980, 335981, 335982, 335983, 335984, 335985, 335986, 335987, 335988, 335989, 335990, 335991, 335996, 335979, 335978, 295120, 295121, 295122, 295123, 295124, 295125, 295126, 295127, 295128, 295129, 295130, 295131, 295132, 295133, 295134, 295135, 295136, 295137, 295138, 295143, 295144, 295145);

DELETE FROM `creature_addon` WHERE `guid` IN (294874, 295332, 335931, 335932, 335933, 335934, 335935, 335936, 335940, 335941, 335943, 335944, 335945, 335946, 335947, 335948, 335949, 335950, 335951, 335952, 335953, 335954, 335955, 335956, 335957, 335958, 335959, 335960, 335962, 335963, 335964, 335965, 335966, 335967, 335968, 335969, 335970, 335971, 335972, 335973, 335974, 335975, 335976, 335977, 335980, 335981, 335982, 335983, 335984, 335985, 335986, 335987, 335988, 335989, 335990, 335991, 335996, 335979, 335978, 295120, 295121, 295122, 295123, 295124, 295125, 295126, 295127, 295128, 295129, 295130, 295131, 295132, 295133, 295134, 295135, 295136, 295137, 295138, 295143, 295144, 295145);

-- Loot
DELETE FROM `creature_onkill_reward` WHERE `creature_id`= 52053;
INSERT INTO `creature_onkill_reward` (`creature_id`, `CurrencyId1`, `CurrencyCount1`) VALUES
(52053, 395, 7000);

DELETE FROM `creature_loot_template` WHERE `Entry`= 52053;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `Reference`, `MaxCount`) VALUES
(52053, 520530, 100, 1, 520530, 1);

DELETE FROM `reference_loot_template` WHERE `Entry`= 520530;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(520530, 69618, 0, 1, 1, 1, 1),
(520530, 69617, 0, 1, 1, 1, 1),
(520530, 69616, 0, 1, 1, 1, 1),
(520530, 69619, 0, 1, 1, 1, 1),
(520530, 69615, 0, 1, 1, 1, 1);

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (52053, 52054);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
-- Zanzil
(52053, 0, 0, 'What? You\'ve come to laugh at Zanzil, too? Not again! I\'ll make you pay!', 14, 0, 100, 0, 0, 24337, 51935, 'Zanzil - Aggro'),
(52053, 1, 0, '%s begins to resurrect a swarm of |cFFCC0000Zanzili Zombies|r!', 41, 0, 100, 0, 0, 0, 50877, 'Zanzil - Announce Zanzili Zombies'),
(52053, 2, 0, 'Rise up! Zanzil\'s elixir gives you life!', 14, 0, 100, 0, 0, 24352, 51942, 'Zanzil - Zanzili Zombies 1'),
(52053, 2, 1, 'Who needs friends? Zanzil just makes his own! ', 14, 0, 100, 0, 0, 24351, 51941, 'Zanzil - Zanzili Zombies 2'),
(52053, 3, 0, '%s fills the area with a |cFF33FF00toxic gas|r!', 41, 0, 100, 0, 0, 0, 50878, 'Zanzil to Zanzil - Announce Graveyard Gas'),
(52053, 4, 0, 'Breathe deep, friends! Breathe it all in!', 14, 0, 100, 0, 0, 24341, 51944, 'Zanzil to Zanzil - Graveyard Gas'),
(52053, 5, 0, '%s begins to resurrect a |cFF3366CCZanzili Berserker|r!', 41, 0, 100, 0, 0, 0, 50876, 'Zanzil - Announce Zanzili Berserker'),
(52053, 6, 0, 'Maybe you need someone bigger to play with!', 14, 0, 100, 0, 0, 24349, 51939, 'Zanzil - Zanzili Berserker 1'),
(52053, 6, 1, 'Go, little one! Fight them! KILL THEM!', 14, 0, 100, 0, 0, 24350, 51940, 'Zanzil - Zanzili Berserker 2'),
(52053, 7, 0, 'Don''t worry. Zanzil won''t leave you dead for long...', 14, 0, 100, 0, 0, 24342, 51936, 'Zanzil - Slay 1'),
(52053, 7, 1, 'How does that taste?', 14, 0, 100, 0, 0, 24343, 51937, 'Zanzil - Slay 2'),
(52053, 7, 2, 'Oooh, pretty... Zanzil''s got big plans for this one...', 14, 0, 100, 0, 0, 24344, 51938, 'Zanzil - Slay 3'),
(52053, 8, 0, 'You\'ll all suffer for this! Zul\'Gurub is NOTHING without Zan... Zan...', 14, 0, 100, 0, 0, 24338, 51945, 'Zanzil - Death'),
-- Zanzili Berserker
(52054, 0, 0, '%s is chasing you. Run!', 42, 0, 100, 0, 0, 0, 36529, 'Zanzili Berserker - Whisper Pursuit'),
(52054, 1, 0, '%s is chasing $n.', 16, 0, 100, 0, 0, 0, 36530, 'Zanzili Berserker - Announce Pursuit');

-- Summon Groups
DELETE FROM `creature_summon_groups` WHERE `summonerId`= 52053 AND `summonerType`= 0;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES
-- Zanzili Zombies 1
(52053, 0, 0, 52055, -11538.6, -1254.12, 79.2066, 0, 6, 4000),
(52053, 0, 0, 52055, -11535.5, -1257.36, 79.5052, 0, 6, 4000),
(52053, 0, 0, 52055, -11540.8, -1253.51, 78.9323, 0, 6, 4000),
(52053, 0, 0, 52055, -11536.4, -1261.72, 79.4727, 0, 6, 4000),
(52053, 0, 0, 52055, -11540.7, -1260.35, 79.0832, 0, 6, 4000),
(52053, 0, 0, 52055, -11544.3, -1258.24, 78.474,  0, 6, 4000), 
(52053, 0, 0, 52055, -11534.9, -1261.8,  79.632,  0, 6, 4000), 
(52053, 0, 0, 52055, -11542.8, -1256.29, 79.0399, 0, 6, 4000),
(52053, 0, 0, 52055, -11534.2, -1258.53, 79.507,  0, 6, 4000), 
(52053, 0, 0, 52055, -11538.7, -1258.52, 79.091,  0, 6, 4000), 
(52053, 0, 0, 52055, -11537.8, -1264.41, 79.3455, 0, 6, 4000),
(52053, 0, 0, 52055, -11541,   -1264.2,  78.9616, 0, 6, 4000),
(52053, 0, 0, 52055, -11546.4, -1260.98, 78.2899, 0, 6, 4000),
(52053, 0, 0, 52055, -11544.3, -1262.48, 78.4120, 0, 6, 4000),
-- Zanzili Zombies 2
(52053, 0, 1, 52055, -11584.4, -1258.12, 77.8612, 0, 6, 4000),
(52053, 0, 1, 52055, -11588.2, -1254.84, 77.6245, 0, 6, 4000),
(52053, 0, 1, 52055, -11590.2, -1256.68, 77.6088, 0, 6, 4000),
(52053, 0, 1, 52055, -11585,   -1253.69, 77.9192, 0, 6, 4000),
(52053, 0, 1, 52055, -11587.3, -1260.73, 77.5984, 0, 6, 4000),
(52053, 0, 1, 52055, -11585.9, -1258.05, 77.7285, 0, 6, 4000),
(52053, 0, 1, 52055, -11583.7, -1254.85, 78.0329, 0, 6, 4000),
(52053, 0, 1, 52055, -11593.8, -1258.81, 77.8374, 0, 6, 4000),
(52053, 0, 1, 52055, -11593.8, -1254.56, 77.9005, 0, 6, 4000),
(52053, 0, 1, 52055, -11592.3, -1252.61, 77.6953, 0, 6, 4000),
(52053, 0, 1, 52055, -11590.5, -1260.52, 77.595,  0, 6, 4000), 
(52053, 0, 1, 52055, -11590.3, -1249.84, 77.8057, 0, 6, 4000),
(52053, 0, 1, 52055, -11596,   -1257.31, 78.4782, 0, 6, 4000),
(52053, 0, 1, 52055, -11588.1, -1250.44, 77.8582, 0, 6, 4000), 
-- Zanzili Zombies 3
(52053, 0, 2, 52055, -11586.5, -1327.73, 78.651,  0, 6, 4000), 
(52053, 0, 2, 52055, -11588.7, -1327.12, 78.3854, 0, 6, 4000),
(52053, 0, 2, 52055, -11592.2, -1331.85, 78.3594, 0, 6, 4000),
(52053, 0, 2, 52055, -11586.6, -1332.13, 79.1948, 0, 6, 4000),
(52053, 0, 2, 52055, -11590.7, -1329.9,  78.3559, 0, 6, 4000),
(52053, 0, 2, 52055, -11583.4, -1330.97, 79.5243, 0, 6, 4000),
(52053, 0, 2, 52055, -11582.1, -1332.14, 79.9445, 0, 6, 4000),
(52053, 0, 2, 52055, -11588.6, -1333.96, 80.1995, 0, 6, 4000),
(52053, 0, 2, 52055, -11594.4, -1334.59, 78.2969, 0, 6, 4000),
(52053, 0, 2, 52055, -11588.9, -1337.81, 79.7257, 0, 6, 4000),
(52053, 0, 2, 52055, -11582.8, -1335.41, 80.3524, 0, 6, 4000),
(52053, 0, 2, 52055, -11584.3, -1335.33, 80.191,  0, 6, 4000), 
(52053, 0, 2, 52055, -11585.7, -1338.02, 80.3073, 0, 6, 4000),
(52053, 0, 2, 52055, -11592.2, -1336.09, 78.7726, 0, 6, 4000),
--  Zanzili Zombies 4
(52053, 0, 3, 52055, -11618.1, -1311.61, 78.6514, 0, 6, 4000),
(52053, 0, 3, 52055, -11614.7, -1312.7,  79.0384, 0, 6, 4000),
(52053, 0, 3, 52055, -11616.9, -1313.22, 78.6516, 0, 6, 4000),
(52053, 0, 3, 52055, -11620.2, -1314.36, 78.2763, 0, 6, 4000),
(52053, 0, 3, 52055, -11611.5, -1314.75, 78.4497, 0, 6, 4000),
(52053, 0, 3, 52055, -11614.1, -1314.81, 78.545,  0, 6, 4000), 
(52053, 0, 3, 52055, -11615.5, -1315.01, 78.537,  0, 6, 4000), 
(52053, 0, 3, 52055, -11618.6, -1315.94, 78.3023, 0, 6, 4000),
(52053, 0, 3, 52055, -11622,   -1316.31, 77.951,  0, 6, 4000), 
(52053, 0, 3, 52055, -11617.5, -1317.2,  78.6535, 0, 6, 4000),
(52053, 0, 3, 52055, -11614.4, -1317.85, 78.3475, 0, 6, 4000),
(52053, 0, 3, 52055, -11620.8, -1318.51, 78.0817, 0, 6, 4000),
(52053, 0, 3, 52055, -11621.9, -1320.01, 78.0138, 0, 6, 4000),
(52053, 0, 3, 52055, -11617.4, -1320.57, 79.0296, 0, 6, 4000),
-- Zanzil's Toxic Gas
(52053, 0, 4, 52062, -11623.7, -1355.4, 82.2363, 0.942478, 8, 0),
(52053, 0, 4, 52062, -11607.4, -1220.11, 87.6618, 5.18363, 8, 0),
(52053, 0, 4, 52062, -11626.5, -1357.79, 86.3576, 0.907571, 8, 0),
(52053, 0, 4, 52062, -11536.6, -1225.1, 81.7799, 4.18879, 8, 0),
(52053, 0, 4, 52062, -11537.2, -1223.78, 85.8028, 4.2237, 8, 0),
(52053, 0, 4, 52062, -11625.2, -1278.44, 87.4016, 6.0912, 8, 0),
(52053, 0, 4, 52062, -11609.9, -1222.7, 87.919, 5.20108, 8, 0),
(52053, 0, 4, 52062, -11532.1, -1294.95, 87.5052, 2.32129, 8, 0),
(52053, 0, 4, 52062, -11607.4, -1223.03, 84.6856, 5.20108, 8, 0),
(52053, 0, 4, 52062, -11627.2, -1354.4, 86.699, 0.872665, 8, 0),
(52053, 0, 4, 52062, -11529.5, -1256.81, 83.3696, 3.76991, 8, 0),
(52053, 0, 4, 52062, -11623.1, -1276.96, 83.8367, 6.05629, 8, 0),
(52053, 0, 4, 52062, -11529.4, -1292.84, 87.3956, 2.3911, 8, 0),
(52053, 0, 4, 52062, -11534.7, -1225.67, 85.6265, 3.78736, 8, 0),
(52053, 0, 4, 52062, -11529.3, -1254.09, 87.5675, 3.94444, 8, 0),
(52053, 0, 4, 52062, -11624.9, -1275.04, 87.3894, 6.03884, 8, 0),
(52053, 0, 4, 52062, -11573, -1272.29, 77.6361, 0, 8, 0),
(52053, 0, 4, 52062, -11531.4, -1292.22, 83.7441, 2.32129, 8, 0),
(52053, 0, 4, 52062, -11526.5, -1256.37, 87.4362, 3.87463, 8, 0),
(52053, 0, 4, 52062, -11564.2, -1258.8, 78.7486, 0, 8, 0),
(52053, 0, 4, 52062, -11570.5, -1313.09, 79.3255, 0, 8, 0),
(52053, 0, 4, 52062, -11612.7, -1283.43, 78.4788, 0, 8, 0);
