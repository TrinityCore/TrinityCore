DELETE FROM `spell_script_names` WHERE (`spell_id`='59548') AND (`ScriptName`='spell_gen_gift_of_the_naaru');
DELETE FROM `spell_script_names` WHERE (`spell_id`='59547') AND (`ScriptName`='spell_gen_gift_of_the_naaru');
DELETE FROM `spell_script_names` WHERE (`spell_id`='59545') AND (`ScriptName`='spell_gen_gift_of_the_naaru');
DELETE FROM `spell_script_names` WHERE (`spell_id`='59544') AND (`ScriptName`='spell_gen_gift_of_the_naaru');
DELETE FROM `spell_script_names` WHERE (`spell_id`='59543') AND (`ScriptName`='spell_gen_gift_of_the_naaru');
DELETE FROM `spell_script_names` WHERE (`spell_id`='59542') AND (`ScriptName`='spell_gen_gift_of_the_naaru');

DELETE FROM `spell_bonus_data` WHERE (`entry`='121093');
INSERT INTO `spell_bonus_data` (`entry`, `comments`) VALUES ('121093', 'Monk - Gift of the Naaru');