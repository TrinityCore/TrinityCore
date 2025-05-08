-- Add AnimTier Hover
UPDATE `creature_addon` SET `AnimTier`=2 WHERE `guid`=105234;

DELETE FROM `creature_template_movement` WHERE `CreatureId`=31848;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(31848, 0, 0, 1, 0, 0, 0, NULL);
