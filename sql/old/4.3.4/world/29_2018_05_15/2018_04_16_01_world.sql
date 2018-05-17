--
UPDATE `creature_template` SET `difficulty_entry_1`=48902 WHERE `entry`=39788;
UPDATE `creature_template` SET `difficulty_entry_1`=48710 WHERE `entry`=39587;
UPDATE `creature_template` SET `difficulty_entry_1`=48776 WHERE `entry`=39732;
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `exp`=3, `faction`=16, `unit_flags`=33555008, `mechanic_immune_mask`=536941137 WHERE `entry`=48902;
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `exp`=3, `faction`=16, `speed_walk`=2, `unit_class`=2, `unit_flags`=32832 WHERE `entry`=48710;
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `exp`=3, `faction`=16, `speed_walk`=2.8, `unit_class`=2, `unit_flags`=32832 WHERE `entry`=48776;

UPDATE `spell_script_names` SET `spell_id`= 53290 WHERE `spell_id`= -53290;
UPDATE `spell_script_names` SET `spell_id`= 31876 WHERE `spell_id`= -31876;
UPDATE `spell_script_names` SET `spell_id`= 31661 WHERE `spell_id`= -31661;
UPDATE `spell_script_names` SET `spell_id`= 27243 WHERE `spell_id`= -27243;
UPDATE `spell_script_names` SET `spell_id`= 44445 WHERE `spell_id`= -44445;
UPDATE `spell_script_names` SET `spell_id`= 10400 WHERE `spell_id`= -10400;

UPDATE `creature_template` SET `ScriptName`= '' WHERE `ScriptName`= 'npc_lunaclaw_spirit';
