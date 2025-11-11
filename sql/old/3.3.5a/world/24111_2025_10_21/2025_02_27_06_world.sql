-- Add missing movement flags to The Lich King
DELETE FROM `creature_template_movement` WHERE `CreatureId`=29110;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(29110, 0, 0, 0, 1, 0, 0, NULL);
