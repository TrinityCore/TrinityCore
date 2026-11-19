-- 
DELETE FROM `creature_addon` WHERE `guid` IN (129727, 129769);
INSERT INTO `creature_addon` (`guid`, `auras`) VALUES
(129727, "29266"),
(129769, "29266");
