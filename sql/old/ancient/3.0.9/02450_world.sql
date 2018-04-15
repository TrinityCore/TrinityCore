UPDATE `gameobject_template` SET `ScriptName`='go_jump_a_tron' WHERE `entry`=183146;
UPDATE `gameobject_template` SET `ScriptName`='go_ethereum_prison' WHERE `entry`=184421;
UPDATE `gameobject_template` SET `scriptname`='go_sacred_fire_of_life' WHERE `entry`=175944;
UPDATE `gameobject_template` SET `scriptname`='go_skull_pile' WHERE `entry`=185913;
DELETE FROM `command` WHERE `name` IN ('reload spell_linked_spell');
INSERT INTO `command` VALUES
('reload spell_linked_spell','3','Usage: .reload spell_linked_spell\r\nReloads the spell_linked_spell DB table.');
