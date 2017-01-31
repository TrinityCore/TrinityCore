-- Remove spawns of Perimeter Bunny - they are spawned by spell 54355 used by GO 191502 (Land Mine)
DELETE FROM `creature` WHERE `id`=29397;
