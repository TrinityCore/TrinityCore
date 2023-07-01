-- Creature templates
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=21962; -- Udalo
UPDATE `creature_template` SET `unit_flags3`=524289 WHERE `entry`=21761; -- Destroyed Sentinel
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=21440; -- Tempest Keep Prison Boss Pod Target
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=21439; -- Tempest Keep Prison Gamma Pod Target
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=21438; -- Tempest Keep Prison Delta Pod Target
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=21437; -- Tempest Keep Prison Beta Pod Target
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=21436; -- Tempest Keep Prison Alpha Pod Target
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=0.857142865657806396, `unit_flags2`=0, `unit_flags3`=524289 WHERE `entry`=21414; -- Negaton Field
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry`=21395; -- Protean Spawn
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=21303; -- Defender Corpse
UPDATE `creature_template` SET `speed_walk`=1, `unit_flags3`=524289 WHERE `entry`=21290; -- Arcane Explosion
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=21186; -- Arcane Warder Target
UPDATE `creature_template` SET `unit_flags2`=2097152, `unit_flags3`=524289 WHERE `entry`=21101; -- Unbound Void Zone
UPDATE `creature_template` SET `unit_flags3`=524289 WHERE `entry`=21030; -- Wrath-Scryer's Charge Target
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=20978; -- Wrath-Scryer's Felfire
UPDATE `creature_template` SET `npcflag`=0, `unit_flags`=64, `unit_flags2`=2099200 WHERE `entry`=20977; -- Millhouse Manastorm
UPDATE `creature_template` SET `npcflag`=0, `unit_flags`=33600, `unit_flags2`=2099200 WHERE `entry`=20912; -- Harbinger Skyriss
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=20910; -- Twilight Drakonaar
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=20908; -- Akkiris Lightning-Waker
UPDATE `creature_template` SET `unit_flags`=33344, `unit_flags2`=2099200 WHERE `entry`=20904; -- Warden Mellichar
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=20900; -- Unchained Doombringer
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=20898; -- Gargantuan Abyssal
UPDATE `creature_template` SET `npcflag`=0, `unit_flags2`=2099200 WHERE `entry`=20886; -- Wrath-Scryer Soccothrates
UPDATE `creature_template` SET `npcflag`=0, `unit_flags2`=2099200 WHERE `entry`=20885; -- Dalliah the Doomsayer
UPDATE `creature_template` SET `speed_walk`=1, `BaseAttackTime`=3000 WHERE `entry`=20880; -- Eredar Deathbringer
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=20879; -- Eredar Soul-Eater
UPDATE `creature_template` SET `npcflag`=0, `unit_flags2`=2099200 WHERE `entry`=20870; -- Zereketh the Unbound
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=20869; -- Arcatraz Sentinel
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=20865; -- Protean Horror
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=21304; -- Warder Corpse
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=20911; -- Blackwing Drakonaar
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=20909; -- Sulfuron Magma-Thrower
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.428571462631225585, `unit_flags`=64, `unit_flags2`=2099200 WHERE `entry`=20905; -- Blazing Trickster

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=2 AND `Entry` IN (21030));
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=1 AND `Entry` IN (21414,21346,21101,21030,20911));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `VerifiedBuild`) VALUES
(21414, 1, 0, 0, 226, 1, 1, 1, 17152, 0, 0, 50000),
(21346, 1, 0, 0, 226, 1, 0.200000002980232238, 1, 17082, 0, 0, 50000),
(21101, 1, 0, 0, 226, 1, 200, 1, 16812, 0, 0, 50000),
(21030, 1, -1, -1, 226, 1, 0.009999999776482582, 1, 16739, 1024, 0, 50000),
(20911, 1, 2, 2, 226, 1, 12, 4, 16612, 0, 0, 50000);

UPDATE `creature_template_difficulty` SET `VerifiedBuild`=50000 WHERE (`DifficultyID`=1 AND `Entry` IN (20905,20909,21962,21761,21702,21440,21439,21438,21437,21436,21395,21304,21303,21186,20978,20977,20912,20910,20904,20902,20901,20900,20898,20897,20896,20886,20885,20883,20882,20881,20880,20879,20875,20873,20870,20869,20868,20867,20866,20865,20864,20859));
UPDATE `creature_template_difficulty` SET `ContentTuningID`=226, `VerifiedBuild`=50000 WHERE (`DifficultyID`=1 AND `Entry` IN (21290,20908,20906));
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMax`=-1, `VerifiedBuild`=50000 WHERE (`Entry`=20857 AND `DifficultyID` IN (1,2));
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `HealthModifier`=7.5, `CreatureDifficultyID`=17342, `VerifiedBuild`=50000 WHERE (`Entry`=21702 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `HealthModifier`=0.75, `CreatureDifficultyID`=17153, `VerifiedBuild`=50000 WHERE (`Entry`=21414 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `HealthModifier`=1.265625, `CreatureDifficultyID`=17132, `VerifiedBuild`=50000 WHERE (`Entry`=21395 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `HealthModifier`=0.50625002384185791, `CreatureDifficultyID`=17083, `VerifiedBuild`=50000 WHERE (`Entry`=21346 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `HealthModifier`=2.25, `CreatureDifficultyID`=17038, `VerifiedBuild`=50000 WHERE (`Entry`=21304 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `HealthModifier`=2.25, `CreatureDifficultyID`=17035, `VerifiedBuild`=50000 WHERE (`Entry`=21303 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `HealthModifier`=150, `CreatureDifficultyID`=16813, `VerifiedBuild`=50000 WHERE (`Entry`=21101 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `CreatureDifficultyID`=16688, `VerifiedBuild`=50000 WHERE (`Entry`=20978 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `HealthModifier`=11.25, `CreatureDifficultyID`=16685, `VerifiedBuild`=50000 WHERE (`Entry`=20977 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `HealthModifier`=61.875, `CreatureDifficultyID`=16616, `TypeFlags2`=128, `VerifiedBuild`=50000 WHERE (`Entry`=20912 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=1070, `HealthModifier`=30, `CreatureDifficultyID`=16613, `VerifiedBuild`=50000 WHERE (`Entry`=20911 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `HealthModifier`=30, `CreatureDifficultyID`=16604, `VerifiedBuild`=50000 WHERE (`Entry`=20908 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `HealthModifier`=28.125, `CreatureDifficultyID`=16600, `VerifiedBuild`=50000 WHERE (`Entry`=20906 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `HealthModifier`=3.75, `CreatureDifficultyID`=16594, `VerifiedBuild`=50000 WHERE (`Entry`=20904 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `HealthModifier`=15.1875, `CreatureDifficultyID`=16590, `VerifiedBuild`=50000 WHERE (`Entry`=20902 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `HealthModifier`=15.1875, `CreatureDifficultyID`=16587, `VerifiedBuild`=50000 WHERE (`Entry`=20901 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `HealthModifier`=23.4375, `CreatureDifficultyID`=16584, `VerifiedBuild`=50000 WHERE (`Entry`=20900 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `HealthModifier`=25.3125, `CreatureDifficultyID`=16580, `VerifiedBuild`=50000 WHERE (`Entry`=20898 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `HealthModifier`=7.5, `CreatureDifficultyID`=16577, `VerifiedBuild`=50000 WHERE (`Entry`=20897 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `HealthModifier`=7.5, `CreatureDifficultyID`=16574, `VerifiedBuild`=50000 WHERE (`Entry`=20896 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `HealthModifier`=45, `CreatureDifficultyID`=16562, `TypeFlags2`=128, `VerifiedBuild`=50000 WHERE (`Entry`=20886 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `HealthModifier`=45, `CreatureDifficultyID`=16559, `TypeFlags2`=128, `VerifiedBuild`=50000 WHERE (`Entry`=20885 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `HealthModifier`=15.1875, `CreatureDifficultyID`=16555, `VerifiedBuild`=50000 WHERE (`Entry`=20883 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `HealthModifier`=15.1875, `CreatureDifficultyID`=16552, `VerifiedBuild`=50000 WHERE (`Entry`=20882 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `HealthModifier`=15.1875, `CreatureDifficultyID`=16549, `VerifiedBuild`=50000 WHERE (`Entry`=20881 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `HealthModifier`=15.1875, `CreatureDifficultyID`=16546, `VerifiedBuild`=50000 WHERE (`Entry`=20880 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `HealthModifier`=15.1875, `CreatureDifficultyID`=16543, `VerifiedBuild`=50000 WHERE (`Entry`=20879 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `HealthModifier`=15.1875, `CreatureDifficultyID`=16537, `VerifiedBuild`=50000 WHERE (`Entry`=20875 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `HealthModifier`=15.1875, `CreatureDifficultyID`=16533, `VerifiedBuild`=50000 WHERE (`Entry`=20873 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `HealthModifier`=50, `CreatureDifficultyID`=16528, `TypeFlags2`=128, `VerifiedBuild`=50000 WHERE (`Entry`=20870 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `HealthModifier`=41.8125, `CreatureDifficultyID`=16525, `VerifiedBuild`=50000 WHERE (`Entry`=20869 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `HealthModifier`=15.1875, `CreatureDifficultyID`=16522, `VerifiedBuild`=50000 WHERE (`Entry`=20868 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `HealthModifier`=15.1875, `CreatureDifficultyID`=16519, `VerifiedBuild`=50000 WHERE (`Entry`=20867 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `HealthModifier`=15.1875, `CreatureDifficultyID`=16516, `VerifiedBuild`=50000 WHERE (`Entry`=20866 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `HealthModifier`=2.34375, `CreatureDifficultyID`=16513, `VerifiedBuild`=50000 WHERE (`Entry`=20865 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `HealthModifier`=15.1875, `CreatureDifficultyID`=16510, `VerifiedBuild`=50000 WHERE (`Entry`=20864 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `HealthModifier`=7.59375, `CreatureDifficultyID`=16503, `VerifiedBuild`=50000 WHERE (`Entry`=20859 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMax`=-2, `ContentTuningID`=1070, `HealthModifier`=7.59375, `CreatureDifficultyID`=16499, `VerifiedBuild`=50000 WHERE (`Entry`=20857 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `HealthModifier`=0.75, `CreatureDifficultyID`=17020, `VerifiedBuild`=50000 WHERE (`Entry`=21290 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `HealthModifier`=30, `CreatureDifficultyID`=16610, `VerifiedBuild`=50000 WHERE (`Entry`=20910 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `HealthModifier`=30, `CreatureDifficultyID`=16607, `VerifiedBuild`=50000 WHERE (`Entry`=20909 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1070, `HealthModifier`=30, `CreatureDifficultyID`=16597, `VerifiedBuild`=50000 WHERE (`Entry`=20905 AND `DifficultyID`=2);

DELETE FROM `creature_questitem` WHERE (`CreatureEntry`=20912 AND `DifficultyID`=2 AND `Idx`=0);
INSERT INTO `creature_questitem` (`CreatureEntry`, `DifficultyID`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(20912, 2, 0, 33861, 50000); -- Harbinger Skyriss

-- Models
UPDATE `creature_model_info` SET `VerifiedBuild`=50000 WHERE `DisplayID` IN (20644, 21046, 15294, 20265, 14430, 15882, 19942, 19943, 14352, 14515, 19893, 19965, 11343, 12334, 19945, 20282, 21021, 19889, 19977, 19888, 19948, 19947, 18345, 19949, 19950, 19951, 19952, 19882, 19971, 19877, 19878, 19976, 18887, 19993, 19994, 19992, 19990);
UPDATE `creature_template_model` SET `VerifiedBuild`=50000 WHERE (`Idx`=1 AND `CreatureID` IN (21440,21030,21437,21436,21186,20978,20859,21303,21438,21304,21290,21439,20857)) OR (`Idx`=0 AND `CreatureID` IN (21440,20879,20886,21030,20901,20867,21437,20868,20870,20885,21101,21395,21436,20882,20869,21761,20904,21186,20880,20978,20977,20902,20897,20866,20873,20859,21346,20898,20864,21962,21303,20906,20875,20912,20908,20896,20900,20865,21414,20881,20883,21438,21304,20910,21290,21439,21702,20857));

-- Gameobject templates
UPDATE `gameobject_template` SET `VerifiedBuild`=50000 WHERE `entry` IN (182198, 214501, 184802, 183964, 183965, 183961, 184318, 184319, 183962, 183362, 183963, 183363);
