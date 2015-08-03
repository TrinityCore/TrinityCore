-- Fix some Flying Stormpeaks Wyms
UPDATE `creature_addon` SET `bytes1`=50331648 WHERE `guid` IN (101109,101111,101112,101121,101123,101124);
-- Fix some Flying Wild Wyms
UPDATE `creature_addon` SET `bytes1`=50331648 WHERE `guid` IN (202972,202973,202974,202975,202976,202977);
-- remove some bad creature_addon records
DELETE FROM `creature_addon` WHERE `guid` NOT IN (SELECT `guid` FROM `creature`);
