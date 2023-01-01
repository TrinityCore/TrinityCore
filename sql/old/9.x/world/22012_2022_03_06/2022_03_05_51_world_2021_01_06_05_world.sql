--
UPDATE `creature` SET `unit_flags` = `unit_flags` &~ 0x00000008 WHERE `guid` IN (81085,3431);
UPDATE `creature` SET `unit_flags` = `unit_flags` &~ 0x08000000 WHERE `guid` IN (145494,145495);
