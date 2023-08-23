-- 
ALTER TABLE `areatrigger` ADD COLUMN `SpellForVisuals` int UNSIGNED NULL AFTER `ShapeData7`;
ALTER TABLE `areatrigger` ADD COLUMN `VerifiedBuild` int UNSIGNED NOT NULL AFTER `Comment`;
