--
UPDATE `gameobject_template` SET `ScriptName` = 'go_ahune_ice_spear' WHERE `entry` = 188077;

UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_ahune_ice_spear_bunny' WHERE `entry` = 25985;
UPDATE `creature_template` SET `unit_flags` = 33554432 WHERE `entry` IN (25985,26337);
DELETE FROM `smart_scripts` WHERE `entryorguid` = 25985 AND `source_type` = 0;
