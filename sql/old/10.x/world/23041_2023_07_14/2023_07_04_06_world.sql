-- Creature templates
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=18829; -- Hellfire Warder
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=17474; -- Target Trigger
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=17257; -- Magtheridon
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=17256; -- Hellfire Channeler

-- Difficulty
UPDATE `creature_template_difficulty` SET `DifficultyID`=4 WHERE (`DifficultyID`=1 AND `Entry` IN (18829,17474,17376,17257));
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=50000 WHERE (`DifficultyID`=4 AND `Entry` IN (18829,17474,17376,17257));

-- Models
UPDATE `creature_model_info` SET `VerifiedBuild`=50000 WHERE `DisplayID` IN (11440, 18527);
UPDATE `creature_template_model` SET `VerifiedBuild`=50000 WHERE (`Idx`=1 AND `CreatureID` IN (18829,17376,17474)) OR (`Idx`=0 AND `CreatureID` IN (18829,17376,17257,17474));

-- Gameobject templates
UPDATE `gameobject_template` SET `ContentTuningId`=1010, `VerifiedBuild`=50000 WHERE `entry`=181832; -- Blaze
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=50000 WHERE `entry`=184637; -- Magtheridon Column 005
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=50000 WHERE `entry`=184636; -- Magtheridon Column 004
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=50000 WHERE `entry`=184639; -- Magtheridon Column 001
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=50000 WHERE `entry`=183847; -- Doodad_HF_Mag_door01
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=50000 WHERE `entry`=184638; -- Magtheridon Column 000
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=50000 WHERE `entry`=184653; -- Doodad_Hellfire_Raid_FX01
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=50000 WHERE `entry`=184635; -- Magtheridon Column 002
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=50000 WHERE `entry`=184634; -- Magtheridon Column 003
