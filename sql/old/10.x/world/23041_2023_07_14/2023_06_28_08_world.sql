-- Creature templates
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=21350; -- Gronn-Priest
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=19389; -- Lair Brute
UPDATE `creature_template` SET `unit_flags3`=524289 WHERE `entry`=19198; -- Invisible Tractor Beam Source
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=19044; -- Gruul the Dragonkiller
UPDATE `creature_template` SET `unit_flags2`=2099200, `unit_flags3`=524288 WHERE `entry`=18847; -- Wild Fel Stalker
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=18836; -- Blindeye the Seer
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=18835; -- Kiggler the Crazed
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=18834; -- Olm the Summoner
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=18832; -- Krosh Firehand
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=18831; -- High King Maulgar

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=1 AND `Entry` IN (19198));

UPDATE `creature_template_difficulty` SET `DifficultyID`=4 WHERE (`DifficultyID`=2 AND `Entry` IN (21350,19389,19044,18847,18836,18835,18834,18832,18831));
UPDATE `creature_template_difficulty` SET `DifficultyID`=0 WHERE (`DifficultyID`=2 AND `Entry` IN (19198));
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=1009, `VerifiedBuild`=49890 WHERE (`DifficultyID`=4 AND `Entry` IN (21350,19389));
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=1009, `VerifiedBuild`=49890 WHERE (`DifficultyID`=4 AND `Entry` IN (19044,18847,18836,18835,18834,18832,18831));

-- Models
UPDATE `creature_model_info` SET `VerifiedBuild`=49890 WHERE `DisplayID` IN (20241, 18356, 18698, 11585, 12472, 20195, 20194, 18649);
UPDATE `creature_model_info` SET `BoundingRadius`=3.656038999557495117, `VerifiedBuild`=49890 WHERE `DisplayID`=7972;
UPDATE `creature_template_model` SET `VerifiedBuild`=49890 WHERE (`Idx`=0 AND `CreatureID` IN (19389,18831,18836,18832,18847,21350,19198,19044,18835,18834)) OR (`Idx`=1 AND `CreatureID`=19198);

-- Gameobject templates
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=49890 WHERE `entry`=183817; -- Doodad_Portcullis_Gronn01
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=49890 WHERE `entry`=184662; -- Doodad_Portcullis_Gronn02
