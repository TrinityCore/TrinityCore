/* Dragonblight (Emerald Dragonshrine) */
-- Ysera should be laying down
DELETE FROM `creature_addon` WHERE `guid`=108844;
INSERT INTO `creature_addon` (`guid`,`bytes1`) VALUES
(108844,3);
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/* Grizzly Hills (Bloodmoon Isle) */
-- Adding teleport
DELETE FROM `game_tele` WHERE `id`=1422;
INSERT INTO `game_tele` (`id`,`position_x`,`position_y`,`position_z`,`orientation`,`map`,`name`) VALUES
(1422,4682.07,-5569.67,53.61,3.85,571,"BloodmoonIsle");
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Fixing spawns (Non-Elites)
DELETE FROM `creature` WHERE `guid` IN (100918,113585,109405,109404,109408,109403,109384,109382,109390,109409);
-- Bloodmoon worgen
UPDATE `creature` SET `spawndist`=2.5,`movementType`=1 WHERE `guid`=108834;
UPDATE `creature` SET `spawndist`=5,`movementType`=1 WHERE `guid`=108830;
-- Bloodmoon Cultists
UPDATE `creature` SET `orientation`=2.70 WHERE `guid`=109406;
-- Bloodmoon Cultists
DELETE FROM `creature_addon` WHERE `guid` IN (109406,109407,109383,109412,109334);
INSERT INTO `creature_addon` (`guid`,`bytes1`) VALUES
(109406,8),(109407,8),(109383,8),
(109412,1),(109334,1);
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Reparing Elite(s)
-- Correcting Varlam spawn
UPDATE `creature` SET `position_x`=4700.48,`position_y`=-5568.50,`position_z`=53.61,`orientation`=3.39 WHERE `guid`=113673;
-- Correcting Shade of Arugal spawn
UPDATE `creature` SET `position_x`=4590.02,`position_y`=-5712.43,`position_z`=184.50,`orientation`=1.01 WHERE `guid`=108492;