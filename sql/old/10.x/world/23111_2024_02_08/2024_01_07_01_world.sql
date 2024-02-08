-- Make winged ghost" fly Deathknell Graveyard
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (49044,49128,50372);
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`,`Chase`,`Random`,`InteractionPauseTimer`) VALUES
(49044,0,0,1,0,0,0,0),
(49128,0,0,1,0,0,0,0),
(50372,0,0,1,0,0,0,0);
