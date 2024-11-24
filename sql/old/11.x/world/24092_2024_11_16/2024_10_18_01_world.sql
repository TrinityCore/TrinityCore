DELETE FROM `spell_script_names` WHERE `spell_id` IN(268077);
UPDATE `creature_template` SET `ScriptName`='' WHERE `entry` IN(176533, 178081, 176532);
UPDATE `instance_template` SET `script` = '' WHERE `map`=1182;
