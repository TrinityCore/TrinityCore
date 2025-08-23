-- Update Horrorjaw
DELETE FROM `creature_template_difficulty` WHERE (`Entry` = 41420 AND `DifficultyId` = 0 AND `VerifiedBuild` = 0);
UPDATE `creature_template_difficulty` SET `DifficultyId` = 0 WHERE (`Entry` = 41420 AND `DifficultyId` = 1);

-- Update Gobbler
DELETE FROM `creature_template_difficulty` WHERE (`Entry` = 1259 AND `DifficultyId` = 0 AND `VerifiedBuild` = 0);
UPDATE `creature_template_difficulty` SET `DifficultyId` = 0 WHERE (`Entry` = 1259 AND `DifficultyId` = 1);

-- Update Kor'gresh
DELETE FROM `creature_template_difficulty` WHERE (`Entry` = 2793 AND `DifficultyId` = 0 AND `VerifiedBuild` = 0);
UPDATE `creature_template_difficulty` SET `DifficultyId` = 0 WHERE (`Entry` = 2793 AND `DifficultyId` = 1);
