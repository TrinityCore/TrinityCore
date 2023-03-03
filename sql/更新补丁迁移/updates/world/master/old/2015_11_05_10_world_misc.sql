UPDATE `spell_proc_event` SET `ppmRate`='20', `CustomChance`='0' WHERE (`entry`='20165') AND (`effectmask`='7');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('348', 'spell_warl_burning_embers2');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('108686', 'spell_warl_burning_embers2');

UPDATE `spell_script_names` SET `ScriptName`='spell_warl_burning_embers' WHERE (`spell_id`='108685') AND (`ScriptName`='spell_warl_burning_embers_aoe');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('114654', 'spell_warl_burning_embers');

INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `actiontype`, `comment`) VALUES ('-114003', '-116257', '0', 'Маг - Чародейство');