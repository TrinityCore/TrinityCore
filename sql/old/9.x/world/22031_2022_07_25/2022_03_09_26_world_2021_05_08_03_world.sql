-- Teronis' Corpse
UPDATE `creature_template` SET `dynamicflags` = 0 WHERE `entry` = 3891;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 3891);

-- Sedai's Corpse
UPDATE `creature_template` SET `dynamicflags` = 0 WHERE `entry` = 16852;

-- Fel Orc Corpse
UPDATE `creature_template` SET `dynamicflags` = 0 WHERE `entry` = 17062;

-- Udalo
UPDATE `creature_template` SET `dynamicflags` = 0 WHERE `entry` = 21962;
UPDATE `creature_template_addon` SET `bytes1` = 0 WHERE `entry` = 21962;

-- Nozzlerust Supply Runner
UPDATE `creature_template` SET `dynamicflags` = 0 WHERE `entry` = 26896;
UPDATE `creature_template_addon` SET `bytes1` = 0, `bytes2` = 1, `auras` = "31261" WHERE `entry` = 26896;

-- Disassembled Mechano-Tank
UPDATE `creature_template` SET `dynamicflags` = 0 WHERE `entry` = 39263;

-- Tyrith
UPDATE `creature_template` SET `dynamicflags` = 0 WHERE `entry` = 24822;
UPDATE `creature_template_addon` SET `bytes2` = 1 WHERE `entry` = 24822;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 24822);

-- Slain Tualiq Villager
UPDATE `creature_template` SET `unit_flags` = 768, `dynamicflags` = 0 WHERE `entry` = 34852;
UPDATE `creature_template_addon` SET `bytes1` = 0, `bytes2` = 1 WHERE `entry` = 34852;

-- Dead Mage Hunter
UPDATE `creature_template` SET `dynamicflags` = 0 WHERE `entry` = 26477;
UPDATE `creature_template_addon` SET `bytes1` = 0 WHERE `entry` = 26477;

-- Harkor's Corpse
UPDATE `creature_template` SET `dynamicflags` = 0 WHERE `entry` = 24443;

-- Broken Sentinel
UPDATE `creature` SET `unit_flags` = 0, `dynamicflags` = 0 WHERE `id` = 24808;

-- Azure Scalebane
UPDATE `creature` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `id` = 31402;

-- K3 Snow Runner
UPDATE `creature` SET `dynamicflags` = 0 WHERE `id` = 29546;

-- Venomspite Riding Bat
UPDATE `creature` SET `unit_flags` = 0, `dynamicflags` = 0 WHERE `id` = 27787;

-- Warsong Blacksmith
UPDATE `creature` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `id` = 25275;

-- Warsong Honor Guard
UPDATE `creature` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `id` = 25243;
