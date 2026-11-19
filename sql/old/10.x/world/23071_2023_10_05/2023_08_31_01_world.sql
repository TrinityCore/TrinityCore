-- 
ALTER TABLE `areatrigger` ADD COLUMN `SpellForVisuals` int NULL DEFAULT NULL AFTER `ShapeData7`;
ALTER TABLE `areatrigger` ADD COLUMN `VerifiedBuild` int NOT NULL DEFAULT '0' AFTER `Comment`;
