-- Creature templates
UPDATE `creature_template` SET `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=32448; -- Alexstrasza's Gift
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=32295; -- Alexstrasza the Life-Binder
UPDATE `creature_template` SET `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=31253; -- Alexstrasza the Life-Binder
UPDATE `creature_template` SET `unit_flags2`=2080, `unit_flags3`=524289 WHERE `entry`=30592; -- Static Field
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=30334; -- Surge of Power
UPDATE `creature_template` SET `unit_flags3`=524289 WHERE `entry`=30282; -- Arcane Overload
UPDATE `creature_template` SET `faction`=35, `unit_flags`=512, `unit_flags3`=1 WHERE `entry`=30248; -- Hover Disk
UPDATE `creature_template` SET `faction`=35, `unit_flags`=512, `unit_flags3`=1 WHERE `entry`=30234; -- Hover Disk
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=30118; -- Portal (Malygos)
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=30090; -- Vortex
UPDATE `creature_template` SET `unit_flags2`=0, `unit_flags3`=524289 WHERE `entry`=30084; -- Power Spark
UPDATE `creature_template` SET `unit_flags`=64, `unit_flags2`=0 WHERE `entry`=28859; -- Malygos

UPDATE `creature_template_addon` SET `AnimTier`=3 WHERE `entry`=32448; -- 32448 (Alexstrasza's Gift) - Alexstrasza's Gift Visual
UPDATE `creature_template_addon` SET `AnimTier`=0 WHERE `entry`=30161; -- 30161 (Wyrmrest Skytalon)

-- Difficulties
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID` IN (1,3) AND `Entry` IN (32448,32295,31253,30592,30334,30282,30249,30248,30245,30234,30161,30118,30090,30084,28859));
DELETE FROM `creature_template_difficulty` WHERE `DifficultyID`=4 AND `Entry` IN (30084);

UPDATE `creature_template_difficulty` SET `ContentTuningID`=1019, `VerifiedBuild`=54904 WHERE (`Entry`=32448 AND `DifficultyID`=0); -- 32448 (Alexstrasza's Gift) - Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=1019, `VerifiedBuild`=54904 WHERE (`Entry`=32295 AND `DifficultyID`=0); -- 32295 (Alexstrasza the Life-Binder) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1019, `StaticFlags1`=536870912, `VerifiedBuild`=54904 WHERE (`Entry`=31253 AND `DifficultyID`=0); -- 31253 (Alexstrasza the Life-Binder) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1019, `VerifiedBuild`=54904 WHERE (`Entry`=30592 AND `DifficultyID`=0); -- 30592 (Static Field) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1019, `StaticFlags1`=536870912, `VerifiedBuild`=54904 WHERE (`Entry`=30334 AND `DifficultyID`=0); -- 30334 (Surge of Power) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1019, `StaticFlags1`=536870912, `VerifiedBuild`=54904 WHERE (`Entry`=30282 AND `DifficultyID`=0); -- 30282 (Arcane Overload) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1019, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=30249 AND `DifficultyID`=0); -- 30249 (Scion of Eternity) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1019, `VerifiedBuild`=54904 WHERE (`Entry`=30248 AND `DifficultyID`=0); -- 30248 (Hover Disk) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1019, `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=30245 AND `DifficultyID`=0); -- 30245 (Nexus Lord) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1019, `StaticFlags1`=536870912, `VerifiedBuild`=54904 WHERE (`Entry`=30234 AND `DifficultyID`=0); -- 30234 (Hover Disk) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1019, `StaticFlags1`=0, `VerifiedBuild`=54904 WHERE (`Entry`=30161 AND `DifficultyID`=0); -- 30161 (Wyrmrest Skytalon) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1019, `VerifiedBuild`=54904 WHERE (`Entry`=30118 AND `DifficultyID`=0); -- 30118 (Portal (Malygos)) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1019, `VerifiedBuild`=54904 WHERE (`Entry`=30090 AND `DifficultyID`=0); -- 30090 (Vortex) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1019, `StaticFlags1`=536870912, `VerifiedBuild`=54904 WHERE (`Entry`=30084 AND `DifficultyID`=0); -- 30084 (Power Spark) - Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=1019, `StaticFlags2`=2, `VerifiedBuild`=54904 WHERE (`Entry`=28859 AND `DifficultyID`=0); -- 28859 (Malygos) - Amphibious, Floating
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=34067 WHERE (`Entry`=30248 AND `DifficultyID`=4); -- Hover Disk
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=34058, `TypeFlags2`=128 WHERE (`Entry`=30245 AND `DifficultyID`=4); -- Nexus Lord
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=34035 WHERE (`Entry`=30234 AND `DifficultyID`=4); -- Hover Disk
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=33880 WHERE (`Entry`=30161 AND `DifficultyID`=4); -- Wyrmrest Skytalon
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=31035, `TypeFlags2`=128 WHERE (`Entry`=28859 AND `DifficultyID`=4); -- Malygos
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=34072, `TypeFlags2`=128 WHERE (`Entry`=30249 AND `DifficultyID`=4); -- Scion of Eternity
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=54904 WHERE (`DifficultyID`=0 AND `Entry` IN (155076,32548,32534,32520,26175,26127,25721,24770)) OR (`DifficultyID`=4 AND `Entry`=30248);
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=30249 AND `DifficultyID`=4); -- 30249 (Scion of Eternity) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268959744, `VerifiedBuild`=54904 WHERE (`Entry`=30245 AND `DifficultyID`=4); -- 30245 (Nexus Lord) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536870912, `VerifiedBuild`=54904 WHERE (`Entry`=30234 AND `DifficultyID`=4); -- 30234 (Hover Disk) - Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0, `VerifiedBuild`=54904 WHERE (`Entry`=30161 AND `DifficultyID`=4); -- 30161 (Wyrmrest Skytalon) - 
UPDATE `creature_template_difficulty` SET `StaticFlags2`=2, `VerifiedBuild`=54904 WHERE (`Entry`=28859 AND `DifficultyID`=4); -- 28859 (Malygos) - Amphibious, Floating

DELETE FROM `creature_questitem` WHERE (`CreatureEntry`=28859 AND `DifficultyID` IN (0,1) AND `Idx`=0);
INSERT INTO `creature_questitem` (`CreatureEntry`, `DifficultyID`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(28859, 0, 0, 44650, 54904); -- Malygos

DELETE FROM `creature_questitem` WHERE (`CreatureEntry`=28859 AND `DifficultyID`=4 AND `Idx`=0);
INSERT INTO `creature_questitem` (`CreatureEntry`, `DifficultyID`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(28859, 4, 0, 44651, 54904); -- Malygos

-- Models
UPDATE `creature_model_info` SET `VerifiedBuild`=54904 WHERE `DisplayID` IN (27569, 27401, 24316, 24317, 24319, 26876, 25835, 14501, 11686, 26753, 26752, 16925);
UPDATE `creature_template_model` SET `VerifiedBuild`=54904 WHERE (`Idx`=0 AND `CreatureID` IN (59072,30090,69066,18362,31253,305,54423,32158,47654,35362,22517,30234,64993,304,68288,56921,71486,308,40625,30245,30118,40725,32295,54741,65011,14505,30161,30282,28363,32448,60941,53488,30592,25064,40165,31698,54879,30249,28859,30248,30084,70356,30334)) OR (`Idx`=1 AND `CreatureID` IN (30090,31253,22517,30245,30118,40725,32448,53488,30592,40165,30249,30334)) OR (`Idx`=3 AND `CreatureID` IN (30245,30249)) OR (`Idx`=2 AND `CreatureID` IN (30245,30249));
UPDATE `creature_template_model` SET `VerifiedBuild`=54904 WHERE (`Idx`=0 AND `CreatureID` IN (32534,26175,32548,155076,32520,356,24770,34337,26127,18379,25721,25414,25421)) OR (`Idx`=1 AND `CreatureID` IN (26175,155076,32520,25414,25421));

-- Gameobject templates
UPDATE `gameobject_template` SET `Data1`=0, `Data10`=1, `Data12`=1, `Data15`=0, `Data25`=1094, `Data30`=88624, `ContentTuningId`=1019, `VerifiedBuild`=54904 WHERE `entry`=193905; -- Alexstrasza's Gift
UPDATE `gameobject_template` SET `Data1`=0, `Data15`=0, `Data25`=1094, `Data30`=26859, `ContentTuningId`=1019, `VerifiedBuild`=54904 WHERE `entry`=194158; -- Heart of Magic
UPDATE `gameobject_template` SET `Data26`=1, `ContentTuningId`=1019, `VerifiedBuild`=54904 WHERE `entry`=193908; -- Exit Portal
UPDATE `gameobject_template` SET `ContentTuningId`=1019, `VerifiedBuild`=54904 WHERE `entry`=193958; -- The Focusing Iris
UPDATE `gameobject_template` SET `VerifiedBuild`=54904 WHERE `entry`=193070;
UPDATE `gameobject_template` SET `VerifiedBuild`=54904 WHERE `entry` IN (214523, 214507, 208632, 188514, 188521, 193602, 188100, 188133);
UPDATE `gameobject_template` SET `Data1`=0, `Data10`=1, `Data12`=1, `Data15`=0, `Data25`=1094, `Data30`=88632, `ContentTuningId`=1019, `VerifiedBuild`=54904 WHERE `entry`=193967; -- Alexstrasza's Gift
UPDATE `gameobject_template` SET `Data1`=0, `Data15`=0, `Data25`=1094, `Data30`=26860, `ContentTuningId`=1019, `VerifiedBuild`=54904 WHERE `entry`=194159; -- Heart of Magic
UPDATE `gameobject_template` SET `ContentTuningId`=1019, `VerifiedBuild`=54904 WHERE `entry`=193960; -- The Focusing Iris

UPDATE `gameobject_template_addon` SET `flags`=16388 WHERE `entry`=194158; -- Heart of Magic
UPDATE `gameobject_template_addon` SET `flags`=2113536 WHERE `entry`=193905; -- Alexstrasza's Gift
UPDATE `gameobject_template_addon` SET `flags`=1048608 WHERE `entry`=193070; -- Nexus Raid Platform
UPDATE `gameobject_template_addon` SET `flags`=16388 WHERE `entry`=194159; -- Heart of Magic
UPDATE `gameobject_template_addon` SET `flags`=2113536 WHERE `entry`=193967; -- Alexstrasza's Gift

UPDATE `gameobject_questitem` SET `VerifiedBuild`=54904 WHERE (`GameObjectEntry`=194158 AND `Idx`=0);
UPDATE `gameobject_questitem` SET `VerifiedBuild`=54904 WHERE (`GameObjectEntry`=194159 AND `Idx`=0);
