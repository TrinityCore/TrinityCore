UPDATE `creature_template_addon` SET auras = NULL WHERE `auras` LIKE '29266';
UPDATE `creature_template_addon` SET auras = REPLACE(auras, '29266', ' ');