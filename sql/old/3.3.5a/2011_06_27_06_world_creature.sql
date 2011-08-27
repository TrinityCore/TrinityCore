-- Drop DeathState column
ALTER TABLE `creature` DROP COLUMN `DeathState`;
-- Remove spawns for Kologarn (not boss) and Focused Eyebeam (summoned).
DELETE FROM `creature` WHERE `id` IN (34297,33632,33802);
