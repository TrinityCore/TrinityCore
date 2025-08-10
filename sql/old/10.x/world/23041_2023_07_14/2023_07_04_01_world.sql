-- Creature templates
UPDATE `creature_template` SET `unit_flags3`=524289 WHERE `entry`=20602; -- Flame Patch (Al'ar)
UPDATE `creature_template` SET `unit_flags`=33024, `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=20064; -- Thaladred the Darkener
UPDATE `creature_template` SET `unit_flags`=33024, `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=20063; -- Master Engineer Telonicus
UPDATE `creature_template` SET `unit_flags`=33024, `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=20062; -- Grand Astromancer Capernian
UPDATE `creature_template` SET `unit_flags`=256, `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=20060; -- Lord Sanguinar
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=20052; -- Crystalcore Mechanic
UPDATE `creature_template` SET `unit_flags2`=2099200, `unit_flags3`=524288 WHERE `entry`=19551; -- Ember of Al'ar
UPDATE `creature_template` SET `unit_flags3`=524289 WHERE `entry`=21369; -- Flame Strike Trigger (Kael)
UPDATE `creature_template` SET `unit_flags2`=2097152, `unit_flags3`=524289 WHERE `entry`=21364; -- Phoenix Egg
UPDATE `creature_template` SET `unit_flags2`=2097152, `unit_flags3`=524288 WHERE `entry`=21362; -- Phoenix
UPDATE `creature_template` SET `unit_flags2`=2099200, `unit_flags3`=524288 WHERE `entry`=21274; -- Staff of Disintegration
UPDATE `creature_template` SET `unit_flags2`=2099200, `unit_flags3`=524288 WHERE `entry`=21273; -- Phaseshift Bulwark
UPDATE `creature_template` SET `unit_flags2`=2099200, `unit_flags3`=524288 WHERE `entry`=21272; -- Warp Slicer
UPDATE `creature_template` SET `unit_flags2`=2099200, `unit_flags3`=524288 WHERE `entry`=21271; -- Infinity Blades
UPDATE `creature_template` SET `unit_flags2`=2099200, `unit_flags3`=524288 WHERE `entry`=21270; -- Cosmic Infuser
UPDATE `creature_template` SET `unit_flags2`=2099200, `unit_flags3`=524288 WHERE `entry`=21269; -- Devastation
UPDATE `creature_template` SET `unit_flags2`=2099200, `unit_flags3`=524288 WHERE `entry`=21268; -- Netherstrand Longbow
UPDATE `creature_template` SET `unit_flags3`=524289 WHERE `entry`=21002; -- Nether Vapor
UPDATE `creature_template` SET `unit_flags`=33554688, `unit_flags2`=2099200, `unit_flags3`=524288 WHERE `entry`=18928; -- Astromancer Solarian Spotlight
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2099200, `unit_flags3`=524288 WHERE `entry`=18925; -- Solarium Agent
UPDATE `creature_template` SET `BaseAttackTime`=1500, `unit_flags`=32768, `unit_flags2`=2099200, `unit_flags3`=524288 WHERE `entry`=18806; -- Solarium Priest

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=9 AND `Entry` IN (12999));
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=1 AND `Entry` IN (22517));

UPDATE `creature_template_difficulty` SET `DifficultyID`=0 WHERE (`Entry`=12999 AND `DifficultyID`=1);
UPDATE `creature_template_difficulty` SET `DifficultyID`=4 WHERE (`DifficultyID`=0 AND `Entry` IN (21369,21364,21362,21274,21273,21272,21271,21270,21269,21268,21002,18928,18925,18806,20602,20064,20063,20062,20060,20052,20050,20049,20048,20047,20046,20045,20044,20043,20042,20041,20040,20039,20038,20037,20036,20035,20034,20033,20032,20031,19622,19551,19516,19514,18805));
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=1012, `VerifiedBuild`=50000 WHERE (`DifficultyID`=4 AND `Entry` IN (21369,20602,20064,20063,20062,20060,19622,19516,19514,18805));
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=1012, `VerifiedBuild`=50000 WHERE (`DifficultyID`=4 AND `Entry` IN (20052,20049,20048,20047,20042,20037,20036,20034,20033,20032,20031));
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=1012, `VerifiedBuild`=50000 WHERE (`DifficultyID`=4 AND `Entry` IN (18806,20050,20046,20045,20041,20040,20039,20035));
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=-1, `ContentTuningID`=1012, `VerifiedBuild`=50000 WHERE (`Entry`=18925 AND `DifficultyID`=4);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1012, `VerifiedBuild`=50000 WHERE (`DifficultyID`=4 AND `Entry` IN (21364,21362,21274,21273,21272,21271,21270,21269,21268,21002,18928,20044,20043,20038,19551));

-- Models
UPDATE `creature_model_info` SET `VerifiedBuild`=50000 WHERE `DisplayID` IN (20245, 17765, 26085, 26084, 26086, 26082, 26080, 26081, 26083, 19988, 20236, 20177, 20237, 20178, 19470, 19300, 19410, 19299, 19298, 20023, 19682, 18945, 18239);
UPDATE `creature_model_info` SET `BoundingRadius`=0.478749990463256835, `CombatReach`=1.875, `DisplayID_Other_Gender`=0, `VerifiedBuild`=50000 WHERE `DisplayID` IN (19049, 19048);
UPDATE `creature_model_info` SET `BoundingRadius`=0.765999972820281982, `CombatReach`=3, `DisplayID_Other_Gender`=0, `VerifiedBuild`=50000 WHERE `DisplayID` IN (19050, 19051);
UPDATE `creature_model_info` SET `BoundingRadius`=3.423345565795898437, `VerifiedBuild`=50000 WHERE `DisplayID`=19254;
UPDATE `creature_model_info` SET `DisplayID_Other_Gender`=0, `VerifiedBuild`=50000 WHERE `DisplayID` IN (19474, 19508, 19507, 19503, 19504, 19506, 19505, 19500, 19499, 19423, 19475, 19473, 19472, 19471, 19412, 19413, 19398, 19394, 21001, 19397, 20978, 19393, 19392, 19391, 21000, 19388, 19386, 19387);
UPDATE `creature_model_info` SET `BoundingRadius`=12.33326530456542968, `CombatReach`=18, `VerifiedBuild`=50000 WHERE `DisplayID`=18951;
UPDATE `creature_template_model` SET `VerifiedBuild`=50000 WHERE (`Idx`=0 AND `CreatureID` IN (20040,20034,20039,12999,20033,20041,20036,20049,20602,20064,22517,19551,20037,20050,20032,20046,20042,19514,20043,20044,20060,20045,20038,19622,20048,19516,20047,20052,54423,20063,20035,18805,20062,20031)) OR (`Idx`=1 AND `CreatureID` IN (20034,12999,20033,20036,20049,20602,22517,20037,20050,20032,20046,20042,20043,20044,20045,20048,20047,20035,20031));
UPDATE `creature_template_model` SET `VerifiedBuild`=50000 WHERE (`Idx`=0 AND `CreatureID` IN (21273,21271,21002,21274,18925,21369,18806,21272,21362,21270,21269,21364,18928,21268,22515)) OR (`Idx`=1 AND `CreatureID` IN (18925,18806,22515)) OR (`Idx`=2 AND `CreatureID`=18806);

-- Gameobject templates
UPDATE `gameobject_template` SET `VerifiedBuild`=50000 WHERE `entry` IN (184328, 184597, 184069, 184324, 184329, 184596, 184325, 184327, 184326);

UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=32 WHERE `entry`=184069; -- Tempest Bridge Window
