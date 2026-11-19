-- Creature templates
UPDATE `creature_template` SET `unit_flags3`=16777216 WHERE `entry`=172096; -- Reinforced Hellfire Door
UPDATE `creature_template` SET `speed_run`=1.714285731315612792, `BaseAttackTime`=1600, `unit_flags2`=2099200, `unit_flags3`=524288 WHERE `entry`=23524; -- Ashtongue Spiritbinder
UPDATE `creature_template` SET `speed_run`=1.714285731315612792, `BaseAttackTime`=1600, `unit_flags2`=2099200, `unit_flags3`=524288 WHERE `entry`=23523; -- Ashtongue Elementalist
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry`=23469; -- Enslaved Soul
UPDATE `creature_template` SET `speed_walk`=2, `speed_run`=1.428571462631225585, `unit_flags3`=524289 WHERE `entry`=23451; -- Veras Vanish Effect
UPDATE `creature_template` SET `speed_walk`=2, `speed_run`=1.428571462631225585, `BaseAttackTime`=200000, `unit_flags`=32832, `unit_flags2`=2099200, `unit_flags3`=524288 WHERE `entry`=23436; -- Image of Dementia
UPDATE `creature_template` SET `unit_flags3`=524289 WHERE `entry`=23429; -- Arcane Charge
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.714285731315612792, `unit_flags2`=2099200, `unit_flags3`=524288 WHERE `entry`=23420; -- Essence of Anger
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.714285731315612792, `unit_flags2`=2099200, `unit_flags3`=524288 WHERE `entry`=23419; -- Essence of Desire
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.714285731315612792, `BaseAttackTime`=1000, `unit_flags2`=2099200, `unit_flags3`=524288 WHERE `entry`=23418; -- Essence of Suffering
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=23411; -- Spirit of Olum
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=23410; -- Spirit of Udalo
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry`=23379; -- Black Temple - Houndmaster Flare Dummy
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry`=23369; -- Whirling Blade
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry`=23351; -- Shade of Akama Trigger
UPDATE `creature_template` SET `unit_flags3`=524289 WHERE `entry`=23336; -- Flame Crash
UPDATE `creature_template` SET `unit_flags2`=2099200, `unit_flags3`=524288 WHERE `entry`=23318; -- Ashtongue Rogue
UPDATE `creature_template` SET `unit_flags3`=524289 WHERE `entry`=23259; -- Blaze
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=23239; -- Bonechewer Combatant
UPDATE `creature_template` SET `unit_flags`=32832, `unit_flags3`=0 WHERE `entry`=23237; -- Bonechewer Blood Prophet
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags3`=0 WHERE `entry`=23232; -- Mutant War Hound
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=23226; -- Illidari Elite
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=23222; -- Bonechewer Brawler
UPDATE `creature_template` SET `unit_flags2`=2099200, `unit_flags3`=524288 WHERE `entry`=23216; -- Ashtongue Defender
UPDATE `creature_template` SET `unit_flags2`=2097152, `unit_flags3`=524289 WHERE `entry`=23215; -- Ashtongue Sorcerer
UPDATE `creature_template` SET `unit_flags2`=2099200, `unit_flags3`=524288 WHERE `entry`=23197; -- Maiev Shadowsong
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=23191; -- Akama
UPDATE `creature_template` SET `speed_walk`=0.400000005960464477, `speed_run`=0.142857149243354797, `unit_flags3`=524289 WHERE `entry`=23124; -- Doom Blossom Move Target
UPDATE `creature_template` SET `speed_walk`=0.400000005960464477, `speed_run`=0.142857149243354797, `unit_flags3`=524288 WHERE `entry`=23123; -- Doom Blossom
UPDATE `creature_template` SET `speed_run`=1.285714268684387207, `unit_flags3`=524288 WHERE `entry`=23095; -- Supremus Punch Invis Stalker
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=23083; -- Shadowmoon Riding Hound
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=23018; -- Shadowmoon Houndmaster
UPDATE `creature_template` SET `speed_walk`=1, `BaseAttackTime`=1500, `unit_flags2`=2099200, `unit_flags3`=524288 WHERE `entry`=22997; -- Flame of Azzinoth
UPDATE `creature_template` SET `unit_flags2`=2099232, `unit_flags3`=524289 WHERE `entry`=22996; -- Blade of Azzinoth
UPDATE `creature_template` SET `speed_walk`=0.960000038146972656 WHERE `entry`=22964; -- Priestess of Delight
UPDATE `creature_template` SET `speed_walk`=0.960000038146972656 WHERE `entry`=22962; -- Mistress of Woe
UPDATE `creature_template` SET `speed_walk`=0.960000038146972656 WHERE `entry`=22957; -- Mistress of Dementia
UPDATE `creature_template` SET `speed_walk`=0.960000038146972656 WHERE `entry`=22956; -- Priestess of Torment
UPDATE `creature_template` SET `faction`=1813, `speed_run`=0.714285731315612792, `BaseAttackTime`=1500 WHERE `entry`=22929; -- Greater Shadowfiend
UPDATE `creature_template` SET `faction`=1813, `unit_flags2`=0 WHERE `entry`=22897; -- Summoned Windfury Totem
UPDATE `creature_template` SET `faction`=1813, `speed_run`=1, `unit_flags2`=0 WHERE `entry`=22896; -- Ashtongue Searing Totem
UPDATE `creature_template` SET `faction`=1813, `speed_run`=1, `unit_flags2`=0 WHERE `entry`=22894; -- Cyclone Totem

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=1 AND `Entry` IN (23472));

UPDATE `creature_template_difficulty` SET `DifficultyID`=0, `DamageModifier`=1, `VerifiedBuild`=50000 WHERE (`DifficultyID`=1 AND `Entry` IN (22897,23086,23087));
UPDATE `creature_template_difficulty` SET `ContentTuningID`=0, `DifficultyID`=0 WHERE (`DifficultyID`=1 AND `Entry` IN (22897));
UPDATE `creature_template_difficulty` SET `DifficultyID`=14 WHERE (`DifficultyID`=0 AND `Entry` IN (23451,23436,23429,23371,23336,23259,23095,23080,22929,22896,22894,22885,22874));
UPDATE `creature_template_difficulty` SET `HealthModifier`=4.703999996185302734, `ManaModifier`=10, `CreatureDifficultyID`=127015, `VerifiedBuild`=50000 WHERE (`Entry`=23524 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=4.703999996185302734, `ManaModifier`=10, `CreatureDifficultyID`=127024, `VerifiedBuild`=50000 WHERE (`Entry`=23523 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=0.755999982357025146, `CreatureDifficultyID`=126986, `VerifiedBuild`=50000 WHERE (`Entry`=23502 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=50000 WHERE (`DifficultyID`=14 AND `Entry` IN (23499,23379,23369));
UPDATE `creature_template_difficulty` SET `HealthModifier`=2.240000009536743164, `CreatureDifficultyID`=127050, `VerifiedBuild`=50000 WHERE (`Entry`=23469 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=1014, `HealthModifier`=6.860000133514404296, `CreatureDifficultyID`=126910, `VerifiedBuild`=50000 WHERE (`Entry`=23451 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=0.195999994874000549, `CreatureDifficultyID`=126924, `VerifiedBuild`=50000 WHERE (`Entry`=23448 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=1014, `HealthModifier`=1.567999958992004394, `CreatureDifficultyID`=126930, `VerifiedBuild`=50000 WHERE (`Entry`=23436 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1014, `HealthModifier`=0.211679995059967041, `CreatureDifficultyID`=126987, `VerifiedBuild`=50000 WHERE (`Entry`=23429 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=29.39999961853027343, `CreatureDifficultyID`=127017, `VerifiedBuild`=50000 WHERE (`Entry`=23421 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=302.399993896484375, `CreatureDifficultyID`=127054, `VerifiedBuild`=50000 WHERE (`Entry`=23420 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=252, `CreatureDifficultyID`=127056, `VerifiedBuild`=50000 WHERE (`Entry`=23419 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=252, `CreatureDifficultyID`=127055, `VerifiedBuild`=50000 WHERE (`Entry`=23418 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=0.211679995059967041, `CreatureDifficultyID`=127038, `VerifiedBuild`=50000 WHERE (`Entry`=23417 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=0.755999982357025146, `CreatureDifficultyID`=126981, `VerifiedBuild`=50000 WHERE (`Entry`=23412 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=1.019199967384338378, `ManaModifier`=1, `CreatureDifficultyID`=126935, `VerifiedBuild`=50000 WHERE (`Entry`=23411 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=1.019199967384338378, `ManaModifier`=1, `CreatureDifficultyID`=126938, `VerifiedBuild`=50000 WHERE (`Entry`=23410 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=23.79999923706054687, `CreatureDifficultyID`=127058, `VerifiedBuild`=50000 WHERE (`Entry`=23403 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=23.52000045776367187, `ManaModifier`=10, `CreatureDifficultyID`=127057, `VerifiedBuild`=50000 WHERE (`Entry`=23402 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=4.703999996185302734, `CreatureDifficultyID`=126989, `VerifiedBuild`=50000 WHERE (`Entry`=23401 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=29.39999961853027343, `ManaModifier`=10, `CreatureDifficultyID`=127059, `VerifiedBuild`=50000 WHERE (`Entry`=23400 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=9.407999038696289062, `ManaModifier`=20, `CreatureDifficultyID`=126990, `VerifiedBuild`=50000 WHERE (`Entry`=23399 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=0.783999979496002197, `CreatureDifficultyID`=127013, `VerifiedBuild`=50000 WHERE (`Entry`=23398 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=31.3600006103515625, `ManaModifier`=15, `CreatureDifficultyID`=126931, `VerifiedBuild`=50000 WHERE (`Entry`=23397 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=98.55999755859375, `CreatureDifficultyID`=126932, `VerifiedBuild`=50000 WHERE (`Entry`=23394 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=127020, `VerifiedBuild`=50000 WHERE (`Entry`=23374 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=1014, `HealthModifier`=11.76000022888183593, `CreatureDifficultyID`=126927, `VerifiedBuild`=50000 WHERE (`Entry`=23371 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=0.755999982357025146, `CreatureDifficultyID`=126982, `VerifiedBuild`=50000 WHERE (`Entry`=23351 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=23.52000045776367187, `CreatureDifficultyID`=126961, `VerifiedBuild`=50000 WHERE (`Entry`=23339 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=31.3600006103515625, `CreatureDifficultyID`=127009, `VerifiedBuild`=50000 WHERE (`Entry`=23337 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=1014, `HealthModifier`=0.195999994874000549, `CreatureDifficultyID`=126923, `VerifiedBuild`=50000 WHERE (`Entry`=23336 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=27.44000053405761718, `ManaModifier`=15, `CreatureDifficultyID`=127008, `VerifiedBuild`=50000 WHERE (`Entry`=23330 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=5.487999916076660156, `CreatureDifficultyID`=126939, `VerifiedBuild`=50000 WHERE (`Entry`=23319 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=4.703999996185302734, `CreatureDifficultyID`=127023, `VerifiedBuild`=50000 WHERE (`Entry`=23318 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=0.800000011920928955, `CreatureDifficultyID`=126983, `VerifiedBuild`=50000 WHERE (`Entry`=23288 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=1014, `HealthModifier`=0.195999994874000549, `CreatureDifficultyID`=126926, `VerifiedBuild`=50000 WHERE (`Entry`=23259 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=43.11999893188476562, `CreatureDifficultyID`=126968, `VerifiedBuild`=50000 WHERE (`Entry`=23239 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=23.52000045776367187, `ManaModifier`=10, `CreatureDifficultyID`=126971, `VerifiedBuild`=50000 WHERE (`Entry`=23237 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=23.52000045776367187, `CreatureDifficultyID`=126972, `VerifiedBuild`=50000 WHERE (`Entry`=23236 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=23.52000045776367187, `CreatureDifficultyID`=126973, `VerifiedBuild`=50000 WHERE (`Entry`=23235 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=15.68000030517578125, `CreatureDifficultyID`=126947, `VerifiedBuild`=50000 WHERE (`Entry`=23232 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=2.351999998092651367, `CreatureDifficultyID`=127029, `VerifiedBuild`=50000 WHERE (`Entry`=23226 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=3.528000116348266601, `CreatureDifficultyID`=126970, `VerifiedBuild`=50000 WHERE (`Entry`=23223 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=10.7799997329711914, `CreatureDifficultyID`=126967, `VerifiedBuild`=50000 WHERE (`Entry`=23222 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=14.1120004653930664, `CreatureDifficultyID`=127016, `VerifiedBuild`=50000 WHERE (`Entry`=23216 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=23.52000045776367187, `CreatureDifficultyID`=127022, `VerifiedBuild`=50000 WHERE (`Entry`=23215 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=0.560000002384185791, `CreatureDifficultyID`=126984, `VerifiedBuild`=50000 WHERE (`Entry`=23210 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=2.940000057220458984, `CreatureDifficultyID`=126920, `VerifiedBuild`=50000 WHERE (`Entry`=23197 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=62.04800033569335937, `CreatureDifficultyID`=126969, `VerifiedBuild`=50000 WHERE (`Entry`=23196 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=112, `ManaModifier`=100, `CreatureDifficultyID`=127035, `VerifiedBuild`=50000 WHERE (`Entry`=23191 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=21.95199966430664062, `CreatureDifficultyID`=127001, `VerifiedBuild`=50000 WHERE (`Entry`=23172 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=5.487999916076660156, `CreatureDifficultyID`=126937, `VerifiedBuild`=50000 WHERE (`Entry`=23159 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=5.487999916076660156, `CreatureDifficultyID`=126936, `VerifiedBuild`=50000 WHERE (`Entry`=23158 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=5.487999916076660156, `CreatureDifficultyID`=126934, `VerifiedBuild`=50000 WHERE (`Entry`=23157 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=3.528000116348266601, `CreatureDifficultyID`=127004, `VerifiedBuild`=50000 WHERE (`Entry`=23147 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=126914, `VerifiedBuild`=50000 WHERE (`Entry`=23124 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=0.783999979496002197, `CreatureDifficultyID`=126913, `VerifiedBuild`=50000 WHERE (`Entry`=23123 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1014, `HealthModifier`=0.560000002384185791, `CreatureDifficultyID`=126985, `VerifiedBuild`=50000 WHERE (`Entry`=23095 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=56, `ManaModifier`=10, `CreatureDifficultyID`=126940, `VerifiedBuild`=50000 WHERE (`Entry`=23089 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=0.560000002384185791, `CreatureDifficultyID`=127052, `VerifiedBuild`=50000 WHERE (`Entry`=23084 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=15.68000030517578125, `CreatureDifficultyID`=126946, `VerifiedBuild`=50000 WHERE (`Entry`=23083 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=1014, `HealthModifier`=0.156800001859664916, `CreatureDifficultyID`=126952, `VerifiedBuild`=50000 WHERE (`Entry`=23080 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=39.20000076293945312, `CreatureDifficultyID`=127003, `VerifiedBuild`=50000 WHERE (`Entry`=23049 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=3.920000076293945312, `CreatureDifficultyID`=126998, `VerifiedBuild`=50000 WHERE (`Entry`=23047 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=127007, `VerifiedBuild`=50000 WHERE (`Entry`=23030 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=23.52000045776367187, `CreatureDifficultyID`=126994, `VerifiedBuild`=50000 WHERE (`Entry`=23028 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=27.44000053405761718, `ManaModifier`=20, `CreatureDifficultyID`=127000, `VerifiedBuild`=50000 WHERE (`Entry`=23018 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=88.1999969482421875, `CreatureDifficultyID`=126925, `VerifiedBuild`=50000 WHERE (`Entry`=22997 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=0.783999979496002197, `CreatureDifficultyID`=126955, `VerifiedBuild`=50000 WHERE (`Entry`=22996 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=0.211679995059967041, `CreatureDifficultyID`=126980, `VerifiedBuild`=50000 WHERE (`Entry`=22984 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=19.60000038146972656, `CreatureDifficultyID`=126977, `VerifiedBuild`=50000 WHERE (`Entry`=22965 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=39.20000076293945312, `ManaModifier`=10, `CreatureDifficultyID`=126954, `VerifiedBuild`=50000 WHERE (`Entry`=22964 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=3.528000116348266601, `CreatureDifficultyID`=126995, `VerifiedBuild`=50000 WHERE (`Entry`=22963 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=59.97600173950195312, `CreatureDifficultyID`=126956, `VerifiedBuild`=50000 WHERE (`Entry`=22962 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=27.44000053405761718, `CreatureDifficultyID`=127028, `VerifiedBuild`=50000 WHERE (`Entry`=22960 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=23.52000045776367187, `ManaModifier`=10, `CreatureDifficultyID`=126976, `VerifiedBuild`=50000 WHERE (`Entry`=22959 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=59.97600173950195312, `CreatureDifficultyID`=126957, `VerifiedBuild`=50000 WHERE (`Entry`=22957 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=39.20000076293945312, `ManaModifier`=10, `CreatureDifficultyID`=126953, `VerifiedBuild`=50000 WHERE (`Entry`=22956 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=3.528000116348266601, `CreatureDifficultyID`=126975, `VerifiedBuild`=50000 WHERE (`Entry`=22955 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=58.79999923706054687, `CreatureDifficultyID`=127012, `VerifiedBuild`=50000 WHERE (`Entry`=22954 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=39.20000076293945312, `CreatureDifficultyID`=126928, `VerifiedBuild`=50000 WHERE (`Entry`=22953 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=479.808013916015625, `CreatureDifficultyID`=127031, `VerifiedBuild`=50000 WHERE (`Entry`=22952 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=479.808013916015625, `ManaModifier`=100, `CreatureDifficultyID`=127032, `VerifiedBuild`=50000 WHERE (`Entry`=22951 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=479.808013916015625, `ManaModifier`=100, `CreatureDifficultyID`=127030, `VerifiedBuild`=50000 WHERE (`Entry`=22950 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=479.808013916015625, `ManaModifier`=100, `CreatureDifficultyID`=127033, `VerifiedBuild`=50000 WHERE (`Entry`=22949 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=470.399993896484375, `CreatureDifficultyID`=126993, `VerifiedBuild`=50000 WHERE (`Entry`=22948 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=400.399993896484375, `ManaModifier`=100, `CreatureDifficultyID`=126958, `VerifiedBuild`=50000 WHERE (`Entry`=22947 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=7.840000152587890625, `CreatureDifficultyID`=126948, `VerifiedBuild`=50000 WHERE (`Entry`=22946 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=19.60000038146972656, `ManaModifier`=10, `CreatureDifficultyID`=127005, `VerifiedBuild`=50000 WHERE (`Entry`=22945 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=3.528000116348266601, `CreatureDifficultyID`=126978, `VerifiedBuild`=50000 WHERE (`Entry`=22939 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1014, `HealthModifier`=0.391999989748001098, `CreatureDifficultyID`=126919, `VerifiedBuild`=50000 WHERE (`Entry`=22929 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=846.719970703125, `CreatureDifficultyID`=127026, `VerifiedBuild`=50000 WHERE (`Entry`=22917 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=470.399993896484375, `CreatureDifficultyID`=127037, `VerifiedBuild`=50000 WHERE (`Entry`=22898 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1014, `HealthModifier`=0.195999994874000549, `CreatureDifficultyID`=126917, `VerifiedBuild`=50000 WHERE (`Entry`=22896 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1014, `VerifiedBuild`=50000 WHERE (`Entry`=22894 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=399.839996337890625, `CreatureDifficultyID`=127053, `VerifiedBuild`=50000 WHERE (`Entry`=22887 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=0.313600003719329833, `CreatureDifficultyID`=127051, `VerifiedBuild`=50000 WHERE (`Entry`=22886 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1014, `HealthModifier`=11.76000022888183593, `CreatureDifficultyID`=126911, `VerifiedBuild`=50000 WHERE (`Entry`=22885 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=58.79999923706054687, `CreatureDifficultyID`=127049, `VerifiedBuild`=50000 WHERE (`Entry`=22884 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=7.056000232696533203, `CreatureDifficultyID`=126933, `VerifiedBuild`=50000 WHERE (`Entry`=22883 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=23.52000045776367187, `ManaModifier`=10, `CreatureDifficultyID`=127002, `VerifiedBuild`=50000 WHERE (`Entry`=22882 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=11.76000022888183593, `CreatureDifficultyID`=126909, `VerifiedBuild`=50000 WHERE (`Entry`=22881 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=35.279998779296875, `CreatureDifficultyID`=126997, `VerifiedBuild`=50000 WHERE (`Entry`=22880 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=23.52000045776367187, `CreatureDifficultyID`=127006, `VerifiedBuild`=50000 WHERE (`Entry`=22879 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=47.04000091552734375, `CreatureDifficultyID`=126908, `VerifiedBuild`=50000 WHERE (`Entry`=22878 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=23.52000045776367187, `ManaModifier`=10, `CreatureDifficultyID`=126945, `VerifiedBuild`=50000 WHERE (`Entry`=22877 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=23.52000045776367187, `ManaModifier`=40, `CreatureDifficultyID`=126944, `VerifiedBuild`=50000 WHERE (`Entry`=22875 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=1014, `HealthModifier`=23.52000045776367187, `ManaModifier`=40, `CreatureDifficultyID`=126943, `VerifiedBuild`=50000 WHERE (`Entry`=22874 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=31.3600006103515625, `CreatureDifficultyID`=126941, `VerifiedBuild`=50000 WHERE (`Entry`=22873 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=381.02398681640625, `ManaModifier`=500, `CreatureDifficultyID`=126963, `VerifiedBuild`=50000 WHERE (`Entry`=22871 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=23.52000045776367187, `CreatureDifficultyID`=126960, `VerifiedBuild`=50000 WHERE (`Entry`=22869 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=784, `CreatureDifficultyID`=127027, `VerifiedBuild`=50000 WHERE (`Entry`=22856 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=50.40000152587890625, `CreatureDifficultyID`=127011, `VerifiedBuild`=50000 WHERE (`Entry`=22855 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=23.52000045776367187, `ManaModifier`=10, `CreatureDifficultyID`=126959, `VerifiedBuild`=50000 WHERE (`Entry`=22853 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=11.76000022888183593, `CreatureDifficultyID`=126949, `VerifiedBuild`=50000 WHERE (`Entry`=22849 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=11.76000022888183593, `CreatureDifficultyID`=127036, `VerifiedBuild`=50000 WHERE (`Entry`=22848 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=23.52000045776367187, `ManaModifier`=10, `CreatureDifficultyID`=127014, `VerifiedBuild`=50000 WHERE (`Entry`=22847 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=23.52000045776367187, `ManaModifier`=10, `CreatureDifficultyID`=127019, `VerifiedBuild`=50000 WHERE (`Entry`=22846 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=23.52000045776367187, `ManaModifier`=10, `CreatureDifficultyID`=127018, `VerifiedBuild`=50000 WHERE (`Entry`=22845 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=35.279998779296875, `CreatureDifficultyID`=127021, `VerifiedBuild`=50000 WHERE (`Entry`=22844 AND `DifficultyID`=14);
UPDATE `creature_template_difficulty` SET `HealthModifier`=155.23199462890625, `CreatureDifficultyID`=127034, `VerifiedBuild`=50000 WHERE (`Entry`=22841 AND `DifficultyID`=14);

-- Models
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (103408, 103090, 103086, 103085, 103089, 103065, 103077, 103081, 103073);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(103408, 0.574499964714050292, 2.25, 0, 50000),
(103090, 0.397799968719482421, 1.949999928474426269, 0, 50000),
(103086, 0.397799968719482421, 1.949999928474426269, 0, 50000),
(103085, 0.397799968719482421, 1.949999928474426269, 0, 50000),
(103089, 0.397799968719482421, 1.949999928474426269, 0, 50000),
(103065, 0.517049968242645263, 2.02500009536743164, 0, 50000),
(103077, 0.517049968242645263, 2.02500009536743164, 0, 50000),
(103081, 0.517049968242645263, 2.02500009536743164, 0, 50000),
(103073, 0.517049968242645263, 2.02500009536743164, 0, 50000);

UPDATE `creature_model_info` SET `VerifiedBuild`=50000 WHERE `DisplayID` IN (64228, 21606, 21607, 21455, 21594, 21484, 21485, 21483, 21475, 21476, 21570, 21568, 21559, 21468, 21557, 21587, 21565, 16255, 21560, 21561, 21563, 21460, 21442, 11342, 21546, 21547, 21592, 21591, 21550, 21552, 21551, 21553, 21556, 21554, 21555, 21355, 18197, 20778, 20779, 18196, 21549, 21596, 21402, 21349, 21490, 21318, 21345, 21346, 21344, 21376, 21377, 18996, 21112, 21242, 21241, 21380, 21384, 21385, 21383, 10771, 21544, 21543, 21539, 21538, 21379, 21378, 20431, 70437, 21535, 21536, 21537, 21502, 21216, 21532, 21531, 21503, 21456, 21534, 21452, 21454, 21453, 21151, 21418, 21417, 21416, 21443, 21252, 21372, 21449, 21451, 21533, 21450, 21135, 21145, 4589, 4590, 21174, 18568, 17540, 21457, 17528, 5492, 21373, 5563, 21368, 21367, 21369, 21370, 20609, 21166, 21165, 21162, 21163, 21161, 21159, 21160, 21262, 21120, 21146, 11335, 21114, 21117, 21118, 21116, 21115, 21357, 20923, 44816, 901);
UPDATE `creature_model_info` SET `DisplayID_Other_Gender`=0, `VerifiedBuild`=50000 WHERE `DisplayID` IN (21569, 21571, 21567, 21196, 21420);
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=2, `VerifiedBuild`=50000 WHERE `DisplayID`=21138;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.25, `VerifiedBuild`=50000 WHERE `DisplayID`=5187;
UPDATE `creature_template_model` SET `VerifiedBuild`=50000 WHERE (`Idx`=3 AND `CreatureID` IN (23319,23403,23400,22939,23047,23397,22959,23226,22886,23402,22955,22965)) OR (`Idx`=2 AND `CreatureID` IN (23319,22963,23223,23403,23235,23400,22939,23047,23397,23147,22959,23226,22886,23402,22955,22965)) OR (`Idx`=1 AND `CreatureID` IN (23319,23084,22880,22963,23223,23030,23412,23210,22873,23417,23403,23398,23288,14881,23216,23379,23448,23235,23472,23400,22939,23028,172096,23095,22871,23047,23018,22984,23330,23502,23237,23086,23318,23397,23147,22959,22877,23226,22886,23499,23402,22955,23369,22879,22965,23215,22951,22875)) OR (`Idx`=0 AND `CreatureID` IN (23319,23084,22880,22963,23399,23223,22949,23030,23420,22897,22856,23412,23210,22873,22874,23371,22896,23089,22948,23523,23417,23239,22960,23421,22884,23351,23124,23403,22853,23259,23524,23374,23339,22881,23123,23398,22957,23288,22845,23080,14881,23216,23379,23448,23235,23472,23400,22849,22885,23083,23159,23222,22939,23028,172096,23429,23469,23410,22847,23095,22871,23047,23451,23436,23018,22950,22984,23330,1420,22846,22917,22844,22887,23502,23237,22882,23086,23318,23419,22946,22929,23232,23196,23397,23394,23172,23147,22959,23337,22841,22877,22997,23226,23336,22886,23157,23499,90202,22848,22964,23191,90203,22894,23049,23402,22952,22855,22953,23087,22955,22878,23369,23401,23158,22879,22962,22869,23411,23197,22947,22965,22898,22883,22996,23215,23418,23236,22951,22945,22956,22954,22875)) OR (`Idx`=7 AND `CreatureID` IN (22939,22955)) OR (`Idx`=6 AND `CreatureID` IN (22939,22955)) OR (`Idx`=5 AND `CreatureID` IN (22939,22955)) OR (`Idx`=4 AND `CreatureID` IN (22939,22959,22955,22965));

-- Gameobject templates
UPDATE `gameobject_template` SET `ContentTuningId`=1014, `VerifiedBuild`=50000 WHERE `entry`=185946; -- Frost Trap
UPDATE `gameobject_template` SET `VerifiedBuild`=50000 WHERE `entry` IN (185887, 185490, 185886, 185487, 185485, 185486, 185888, 185483, 185488, 186262, 185905, 185479, 185883, 186152, 185481, 185478, 185489, 186153, 185882, 185885, 185480, 185884, 186261, 185482, 185892);
