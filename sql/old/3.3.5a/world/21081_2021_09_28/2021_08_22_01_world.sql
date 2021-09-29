-- Dead Iron Giant
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 29914;
UPDATE `creature_template_addon` SET `bytes2` = 1 WHERE `entry` = 29914;

-- Dead Iron Giant
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144) WHERE `entry` = 30163;
UPDATE `creature_template_addon` SET `bytes2` = 1, `auras` = '56779 29266' WHERE `entry` = 30163;

-- Elementalist Avuun, whatever it was, it will be not stored in DB
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 262144 WHERE `entry` = 32900;

-- Scarlet Commander, whatever it was, it will be not stored in DB
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 262144 WHERE `entry` = 28936;

-- Brittle Golem
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 2, `unit_flags` = 32768 WHERE `entry` = 28681;
