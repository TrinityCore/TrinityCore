--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 57387;
INSERT INTO `spell_linked_spell` VALUES (57387, 57608, 0, 'Argent Cannon - Powering Up The Core');
UPDATE `creature` SET `curhealth`=126000 WHERE `id`=30236;
UPDATE `creature_template` SET `unit_flags2`=0, `RegenHealth`=0 WHERE `entry`=30236;
