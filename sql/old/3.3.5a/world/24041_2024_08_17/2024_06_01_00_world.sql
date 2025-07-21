-- Add missing movement flags to Warsong Cannon
DELETE FROM `creature_template_movement` WHERE `CreatureId`=31243;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(31243, 0, 0, 0, 1, 0, 0, NULL);
