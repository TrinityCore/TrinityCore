-- Defense System
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144) WHERE `entry` = 30837;

-- Flame Sphere
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144) WHERE `entry` IN (30106,31458,31686,31687);

-- Crystalline Tangler
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144) WHERE `entry` = 32665;

-- Wrath Enforcer
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 536870912 WHERE `entry` = 25030;

-- Drom Frostgrip
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144) WHERE `entry` = 29751;

-- Forsaken Prisoner
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 536870912, `dynamicflags` = 0 WHERE `entry` = 27400;
UPDATE `creature_addon` SET `auras` = "31261" WHERE `guid` = 97213;
