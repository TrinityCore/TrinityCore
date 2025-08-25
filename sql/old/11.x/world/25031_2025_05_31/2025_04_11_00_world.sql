-- Update Ol'Sooty
DELETE FROM `creature_template_difficulty` WHERE (`Entry` = 1225 AND `DifficultyId` = 0 AND `VerifiedBuild` = 0);
UPDATE `creature_template_difficulty` SET `DifficultyId` = 0 WHERE (`Entry` = 1225 AND `DifficultyId` = 1);
