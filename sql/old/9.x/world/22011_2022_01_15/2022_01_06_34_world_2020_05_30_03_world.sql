--
DELETE FROM `creature_template_movement` WHERE `CreatureId` = 21071;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`) VALUES
(21071,1,1,0,1,0,0);
