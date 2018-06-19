-- Desactivation de Lava dans le Gouffre de Feu
UPDATE `creature_template` SET `flags_extra` = 128 WHERE (entry = 61560);
