UPDATE `creature_template_addon` SET `auras` = REPLACE(`auras`, ", ", " ");
UPDATE `creature_template_addon` SET `auras` = REPLACE(`auras`, ",", " ");

UPDATE `creature_addon` SET `auras` = REPLACE(`auras`, ", ", " ");
UPDATE `creature_addon` SET `auras` = REPLACE(`auras`, ",", " ");
