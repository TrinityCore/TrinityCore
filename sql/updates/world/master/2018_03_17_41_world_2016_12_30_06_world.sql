-- Warsong Battleguard
-- 2 more found
UPDATE `creature` SET `PhaseId` = 170 WHERE `guid` IN (110370,110378);
-- some must have individual addons
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE  `guid` IN (110370,110378);
DELETE FROM `creature_addon` WHERE `guid` IN (110370,110378);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(110370, 0, 0, 7, 0, 0, "29266"),
(110378, 0, 0, 7, 0, 0, "29266");
