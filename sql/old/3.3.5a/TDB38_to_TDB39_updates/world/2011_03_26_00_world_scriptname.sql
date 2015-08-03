DELETE FROM `instance_template` WHERE `map`=616;
INSERT INTO `instance_template` (map,parent,script) VALUES (616,571,'instance_eye_of_eternity');

UPDATE `creature_template` SET `ScriptName`='boss_malygos' WHERE `entry`=28859;
UPDATE `creature_template` SET `ScriptName`='npc_power_spark' WHERE `entry`=30084;
UPDATE `creature_template` SET `ScriptName`='npc_portal_eoe' WHERE `entry`=30118;
UPDATE `creature_template` SET `ScriptName`='npc_hover_disk' WHERE `entry` IN (30234,30248);
UPDATE `creature_template` SET `ScriptName`='npc_arcane_overload' WHERE `entry`=30282;
UPDATE `creature_template` SET `ScriptName`='npc_wyrmrest_skytalon' WHERE `entry`=30161;
UPDATE `creature_template` SET `ScriptName`='npc_alexstrasza_eoe' WHERE `entry`=32295;

DELETE FROM `spell_script_names` WHERE `spell_id`=56105;
INSERT INTO `spell_script_names` VALUES (56105,'spell_malygos_vortex_dummy');
DELETE FROM `spell_script_names` WHERE `spell_id`=55873;
INSERT INTO `spell_script_names` VALUES (55873,'spell_malygos_vortex_visual');