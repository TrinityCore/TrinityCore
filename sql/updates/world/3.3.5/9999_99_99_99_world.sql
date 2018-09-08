DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (7800,7915);
UPDATE `creature_template` SET `ScriptName`='boss_mekgineer_thermaplugg', `AIName`='' WHERE entry=7800;
UPDATE `creature_template` SET `ScriptName`='npc_walking_bomb', `AIName`='' WHERE entry=7915;

UPDATE `gameobject_template` SET `ScriptName`='go_button' WHERE `entry` IN (142214, 142215, 142216, 142217, 142218, 142219);
UPDATE `gameobject_template` SET `ScriptName`='go_gnome_face' WHERE `entry` IN (142214, 142215, 142216, 142217, 142218, 142219);

