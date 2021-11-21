DELETE FROM `creature_template_movement` WHERE `CreatureId` IN(14517,14965);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES (14517, 1, 0, 0, 0, 0, 0, NULL);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES (14965, 1, 0, 1, 1, 0, 0, NULL);
