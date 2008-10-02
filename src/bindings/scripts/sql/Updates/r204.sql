-- lady vashj event
UPDATE `gameobject_template` SET `type`=0,`ScriptName`='' WHERE `entry` IN (185052, 185053, 185051, 185054);
UPDATE `item_template` SET `ScriptName` = 'item_tainted_core' WHERE `entry` = 31088;
UPDATE `creature_template` SET `ScriptName` = 'mob_shield_generator_channel' WHERE `entry` = 19870;

-- BWL trash mobs
UPDATE `creature_template` SET `ScriptName` = 'mob_blackwing_lair' WHERE `entry` IN (14265, 12457, 13996, 12459, 14261, 14263, 12467, 12463, 12461, 12464, 12460, 12465, 14262, 14264);
