-- lady vashj event
UPDATE `creature_template` SET `ScriptName` = 'boss_lady_vashj' WHERE `entry` = 21212;
UPDATE `creature_template` SET `ScriptName` = 'mob_enchanted_elemental' WHERE `entry` = 21958;
UPDATE `creature_template` SET `ScriptName` = 'mob_tainted_elemental' WHERE `entry` = 22009;
UPDATE `creature_template` SET `ScriptName` = 'mob_coilfang_elite' WHERE `entry` = 22055;
UPDATE `creature_template` SET `ScriptName` = 'mob_coilfang_strider' WHERE `entry` = 22056;
UPDATE `creature_template` SET `ScriptName` = 'mob_fathom_sporebat' WHERE `entry` = 22120;

UPDATE `gameobject_template` SET `ScriptName` = 'go_shield_generator' WHERE `entry` IN (185052, 185053, 185051, 185054);
