ALTER TABLE `creature_queststarter` ADD COLUMN `VerifiedBuild` int unsigned NOT NULL DEFAULT 0 AFTER `quest`;
ALTER TABLE `creature_questender` ADD COLUMN `VerifiedBuild` int unsigned NOT NULL DEFAULT 0 AFTER `quest`;
ALTER TABLE `gameobject_queststarter` ADD COLUMN `VerifiedBuild` int unsigned NOT NULL DEFAULT 0 AFTER `quest`;
ALTER TABLE `gameobject_questender` ADD COLUMN `VerifiedBuild` int unsigned NOT NULL DEFAULT 0 AFTER `quest`;
