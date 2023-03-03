DELETE FROM `spell_script_names` WHERE (`spell_id`='60103') AND (`ScriptName`='spell_sha_static_shock');
DELETE FROM `spell_script_names` WHERE (`spell_id`='17364') AND (`ScriptName`='spell_sha_static_shock');

INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `aura`, `procFlags`, `procEx`, `check_spell_id`, `comment`) VALUES ('51527', '26364', '20', '324', '16', '3', '32175', 'Lightning Shield Proc');
INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `aura`, `procFlags`, `procEx`, `check_spell_id`, `comment`) VALUES ('51527', '26364', '20', '324', '16', '3', '32176', 'Lightning Shield Proc');
INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `aura`, `procFlags`, `procEx`, `check_spell_id`, `comment`) VALUES ('51527', '26364', '20', '324', '16', '3', '60103', 'Lightning Shield Proc');
INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `aura`, `procFlags`, `procEx`, `comment`) VALUES ('51527', '26364', '20', '118472', '4', '3', 'Lightning Shield Proc');