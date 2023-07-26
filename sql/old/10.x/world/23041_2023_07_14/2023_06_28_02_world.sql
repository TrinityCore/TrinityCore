-- Creature templates
UPDATE `creature_template` SET `faction`=45, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=175185; -- Succubus Minion
UPDATE `creature_template` SET `unit_flags3`=16777216 WHERE `entry`=119287; -- Fenglow Stinger
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=66551; -- Ras'an
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=22823; -- Hch'uu
UPDATE `creature_template` SET `unit_flags3`=8912896 WHERE `entry`=22124; -- Air Force Alarm Bot (Cenarion)
UPDATE `creature_template` SET `unit_flags3`=8388608 WHERE `entry`=22088; -- Air Force Trip Wire - Rooftop (Sporeggar)
UPDATE `creature_template` SET `unit_flags3`=8388608 WHERE `entry`=22087; -- Air Force Guard Post (Sporeggar - Sporebat)
UPDATE `creature_template` SET `unit_flags3`=8912896 WHERE `entry`=22086; -- Air Force Alarm Bot (Sporeggar)
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=20710; -- Bogstrok Hatchling
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=20477; -- Terrorclaw
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=20295; -- Bogstrok Crusher
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=20294; -- Bogstrok Razorclaw
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=20293; -- Bogstrok Clacker
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=20292; -- Marsh Baron Brok
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=20090; -- Bloodscale Sentry
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=20089; -- Bloodscale Wavecaller
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=20028; -- Doba
UPDATE `creature_template` SET `speed_walk`=1, `unit_flags3`=1 WHERE `entry`=19733; -- Daggerfen Servant
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=19174; -- Chieftain Mummaki
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=18908; -- Innkeeper Kerp
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=18684; -- Bro'Gaz the Clanless
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=18586; -- Coosh'coosh
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=18581; -- Alliance Field Scout
UPDATE `creature_template` SET `faction`=35, `speed_run`=1.142857193946838378 WHERE `entry`=18382; -- Mycah
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=18358; -- Sporeggar Spawn
UPDATE `creature_template` SET `speed_walk`=1, `unit_flags`=16 WHERE `entry`=18282; -- Lord Klaq
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=18280; -- Sporewing
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=18201; -- Tamed Sporebat
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=18197; -- Elder Kuruti
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=18140; -- Sporeggar Harvester
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=18139; -- Sporeggar Preserver
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=18136; -- Marsh Lurker
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=18129; -- Greater Sporebat
UPDATE `creature_template` SET `speed_run`=1.142857193946838378, `unit_flags`=33587200, `unit_flags3`=1 WHERE `entry`=18123; -- Wrekt Slave
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857193946838378 WHERE `entry`=18116; -- Daggerfen Assassin
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=18115; -- Daggerfen Muckdweller
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=18113; -- Feralfen Hunter
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=18088; -- Bloodscale Enchantress
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=18087; -- Darkcrest Siren
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=18044; -- Rajis Fyashe
UPDATE `creature_template` SET `unit_flags`=537133824 WHERE `entry`=18035; -- Scout Jyoba
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=18010; -- Maktu
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=18009; -- Puluu
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=18008; -- Ikuti
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=17925; -- Gshaff
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=17924; -- Msshi'fn
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=17923; -- Fahssn
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=17866; -- Khn'nix
UPDATE `creature_template` SET `faction`=35, `speed_run`=1.142857193946838378 WHERE `entry`=17856; -- Gzhun'tt
UPDATE `creature_template` SET `faction`=45 WHERE `entry`=12922; -- Imp Minion

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`Entry`=24866 AND `DifficultyID`=0);
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `VerifiedBuild`) VALUES
(24866, 0, 0, 0, 40, 1, 1, 1, 22890, 0, 0, 49801);

UPDATE `creature_template_difficulty` SET `DifficultyID`=0 WHERE (`DifficultyID` IN (1,2) AND `Entry` IN (175185,66551,66536,66535,66534,62564,22829,22823,22489,22488,22485,22124,22088,22087,22086,22044,20710,20477,20445,20444,20443,20442,20295,20294,20293,20292,20280,20279,20198,20090,20089,20088,20028,19734,19733,19732,19730,19729,19722,19519,19174,18992,18943,18908,18684,18680,18586,18581,18382,18358,18340,18285,18282,18280,18201,18197,18160,18140,18139,18133,18129,18127,18125,18123,18121,18120,18119,18118,18117,18116,18115,18113,18089,18088,18087,18046,18044,18019,18010,18009,18008,18002,18000,17999,17998,17925,17924,17923,17877,17866,17856));
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=49801 WHERE (`DifficultyID`=0 AND `Entry` IN (119287,61142,61071,23373,22843,22842,22832,22126,22125,22002,21854,21172,20762,20387,20324,20291,20290,20283,20270,20197,20196,20115,20079,19947,19946,19706,19694,19402,19383,19380,19350,19349,18993,18922,18912,18911,18910,18909,18907,18791,18788,18750,18733,18564,18476,18466,18461,18332,18295,18283,18281,18275,18251,18250,18247,18246,18245,18244,18243,18214,18213,18212,18151,18150,18138,18137,18136,18135,18134,18132,18131,18130,18128,18124,18122,18114,18091,18086,18080,18079,18077,18070,18035,18018,18017,18016,18015,18014,18013,18012,18011,18007,18006,18005,18004,18003,17985,17969,17956,17909,17904,17901,17900,17896,17858,17855,17841,17834,17637,17634,17378,13321));
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=49801 WHERE (`DifficultyID`=0 AND `Entry` IN (175185,66551,66536,66535,66534,62564,22829,22823,22489,22488,22485,22124,22088,22087,22086,22044,20710,20477,20445,20444,20443,20442,20295,20294,20293,20292,20280,20279,20198,20090,20089,20088,20028,19734,19733,19732,19730,19729,19722,19519,19174,18992,18943,18908,18684,18586,18581,18382,18358,18340,18285,18282,18280,18201,18197,18160,18140,18139,18133,18129,18127,18125,18123,18121,18120,18119,18118,18117,18116,18115,18113,18089,18088,18087,18046,18044,18019,18010,18009,18008,18002,18000,17999,17998,17925,17924,17923,17877,17866,17856));
UPDATE `creature_template_difficulty` SET `ContentTuningID`=38, `VerifiedBuild`=49801 WHERE (`Entry`=18680 AND `DifficultyID`=0);

UPDATE `creature_questitem` SET `VerifiedBuild`=49801 WHERE (`CreatureEntry`=18586 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=18476 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=19349 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=18280 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=20324 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=20283 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=19706 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=18214 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=18201 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=20196 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=18285 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=20387 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=19730 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=18283 AND `DifficultyID`=0 AND `Idx`=1) OR (`CreatureEntry`=18283 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=19729 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=20198 AND `DifficultyID`=0 AND `Idx`=1) OR (`CreatureEntry`=20198 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=18213 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=18133 AND `DifficultyID`=0 AND `Idx`=1) OR (`CreatureEntry`=18133 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=21854 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=18129 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=19350 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=18131 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=18132 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=20197 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=18128 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=20280 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=18461 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=18130 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=20279 AND `DifficultyID`=0 AND `Idx`=0);

-- Models
UPDATE `creature_model_info` SET `VerifiedBuild`=49801 WHERE `DisplayID` IN (4162, 75132, 45231, 45616, 45615, 45614, 42554, 21440, 21119, 21106, 20208, 2306, 17436, 1088, 16878, 2200, 10726, 19726, 19658, 18358, 17753, 19678, 17107, 17106, 17101, 9011, 31773, 19408, 18723, 19405, 4606, 19297, 18227, 19163, 19158, 16879, 19147, 19164, 18823, 18792, 20063, 20308, 18620, 10564, 19477, 18330, 19476, 18331, 18312, 18320, 19666, 18309, 18308, 19665, 18307, 18306, 18714, 18332, 31984, 18671, 18070, 2027, 13808, 11419, 8271, 16876, 17695, 11255, 10916, 17661, 19400, 18724, 18316, 45045, 18029, 17638, 17637, 17634, 17633, 17632, 17631, 17630, 18314, 705, 18030, 11653, 11574, 15398, 15394, 17627, 18323, 31771, 18313, 18615, 17781, 19252, 18722, 19401, 19404, 17752, 17751, 18229, 18449, 19687, 17609, 17955, 11537, 20172, 11533, 11559, 18422, 18424, 18423, 17521, 17954, 17953, 17952, 17951, 10920, 18425, 17529, 17581, 17582, 17426, 17422, 17421, 17420, 17419, 17418, 17417, 17416, 17415, 17414, 17588, 17680, 17585, 17413, 17412, 17411, 17410, 17409, 17471, 17767, 17313, 17320, 16975, 17310, 17319, 18228, 17285, 17626, 20621, 20618, 20619, 20620, 17275, 17274, 17272, 17136, 18075, 6295, 6297, 1924);
UPDATE `creature_template_model` SET `VerifiedBuild`=49801 WHERE (`Idx`=0 AND `CreatureID` IN (18122,18912,18079,17901,18733,18911,20324,22002,19733,22088,17923,13321,17998,19947,18077,17956,18016,18003,18908,18564,18014,19732,66551,17856,17904,18295,18251,18285,18246,18119,18750,22124,20387,18017,22823,18139,19730,18086,18137,22843,17834,18007,18000,18008,18466,19349,18070,20028,20270,18013,18340,18461,18907,18035,18130,19734,18151,20294,62564,61071,20115,18332,18160,18002,20090,18089,18012,18006,22488,18201,18134,22086,20291,22126,18243,23373,20196,18909,18118,17378,18282,17969,21172,20762,20088,18010,18283,18197,19380,18992,18680,61142,19729,18135,18046,19350,22125,18910,18250,18581,18275,18015,20710,18131,18080,17841,18788,18044,18213,18113,18018,18358,18133,19946,18136,119287,17985,18005,18117,66536,20279,19519,18125,20292,20079,18281,19694,22489,17637,20445,20444,18088,66534,18132,18009,20197,18128,18245,20280,22832,17909,18138,17855,18004,18214,18120,20477,20293,17866,18280,19402,18244,20442,20443,22087,18087,18011,22485,18943,175185,66535,17925,20295,20290,21854,22842,19383,18382,18129,18684,18476,17896,17634,18124,18019,18247,18116,17924,17877,17999,18586,17900,18993,22044,20089,19722,18212,18127,19174,18115,18121,18922,20283,19706,18150,22829,17858,18114,18791,18091,18123,18140,20198)) OR (`Idx`=1 AND `CreatureID` IN (22002,22088,13321,17998,22124,18000,61071,18002,22086,22126,18909,61142,22125,18910,17855,22087,18943,17999,18922,22829)) OR (`Idx`=3 AND `CreatureID` IN (13321,61071,18909,61142,17855,18922)) OR (`Idx`=2 AND `CreatureID` IN (13321,61071,18909,61142,17855,18922));

-- Gameobject templates
UPDATE `gameobject_template` SET `VerifiedBuild`=49801 WHERE `entry` IN (181872, 182206, 183894, 183113, 182270, 183986, 183118, 182561, 182579, 182053, 181664, 183045, 182536, 182066, 181874, 182116, 184567, 183177, 183121, 207478, 182535, 183046, 182402, 182271, 152614, 182529, 183116, 182576, 176584, 184566, 183346, 182569, 183043, 184044, 183040, 184041, 181873, 182139, 183345, 181276, 183418, 184038, 182571, 182578, 182537, 185501, 182165, 182574, 182952, 183117, 182095, 184049, 183042, 182119, 182377, 214500, 182256, 183119, 142144, 182346, 182269, 184045, 184578, 183111, 182082, 184212, 182065, 184043, 184047, 182205, 183114, 182577, 182400, 182541, 183787, 278457, 183039, 184042, 182558, 183120, 183044, 182606, 184740, 182567, 183415, 182107, 183112, 182568, 182345, 214503, 182573, 184836, 182534, 182062, 182376, 182378, 214501, 182538, 182344, 182401, 184039, 184048, 181876, 181875, 176583, 182944, 183985, 182570, 182575, 182954, 182953, 184040, 184046, 181871, 182580);
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=18676, `ContentTuningId`=38, `VerifiedBuild`=49801 WHERE `entry`=182031; -- Discarded Nutriment
UPDATE `gameobject_template` SET `ContentTuningId`=38, `VerifiedBuild`=49801 WHERE `entry` IN (183284, 182115); -- Wanted Poster
UPDATE `gameobject_template` SET `Data1`=0, `Data2`=1, `Data30`=18793, `ContentTuningId`=38, `VerifiedBuild`=49801 WHERE `entry`=182166; -- Ango'rosh Attack Plans
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=19430, `ContentTuningId`=40, `VerifiedBuild`=49801 WHERE `entry`=182600; -- Marshberry
UPDATE `gameobject_template` SET `Data8`=103829, `Data10`=30092, `VerifiedBuild`=49801 WHERE `entry`=183818; -- Forge
UPDATE `gameobject_template` SET `Data1`=0, `Data2`=1, `Data30`=19098, `ContentTuningId`=38, `VerifiedBuild`=49801 WHERE `entry`=182184; -- Daggerfen Poison Manual
UPDATE `gameobject_template` SET `Data8`=103828, `Data10`=30091, `VerifiedBuild`=49801 WHERE `entry`=183795; -- Anvil
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=18700, `ContentTuningId`=38, `VerifiedBuild`=49801 WHERE `entry`=182069; -- Mature Spore Sac
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=19099, `ContentTuningId`=38, `VerifiedBuild`=49801 WHERE `entry`=182185; -- Daggerfen Poison Vial
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=19433, `ContentTuningId`=38, `VerifiedBuild`=49801 WHERE `entry`=182050; -- Box of Mushrooms

UPDATE `gameobject_template_addon` SET `WorldEffectID`=8830 WHERE `entry`=278457; -- Warchief's Command Board
UPDATE `gameobject_template_addon` SET `faction`=35, `flags`=8192 WHERE `entry`=214503; -- Instance Portal (Party + Heroic)
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=183046; -- Blindweed
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=183043; -- Ragveil
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=181276; -- Flame Cap

UPDATE `gameobject_questitem` SET `VerifiedBuild`=49801 WHERE (`Idx`=0 AND `GameObjectEntry` IN (182541,181876,181875,181874,182116,181873,182139,182119,182256,181872,182031,182185,182184,182606,182600,181871,182050,182166,182095));
