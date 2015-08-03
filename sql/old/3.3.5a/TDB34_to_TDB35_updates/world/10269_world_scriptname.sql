UPDATE `gameobject_template` SET `ScriptName`='go_keystone_chamber' WHERE `entry`=124371;

DELETE FROM `areatrigger_scripts` WHERE `entry`=822;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES (822, 'at_map_chamber');