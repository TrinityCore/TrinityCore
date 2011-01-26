DELETE FROM `spell_script_names` WHERE `spell_id`=51162;
INSERT INTO `spell_script_names`(spell_id, ScriptName) VALUES (51162,'spell_eregos_planar_shift');

UPDATE `creature_template` SET `ScriptName`='boss_eregos' WHERE `entry`=27656;