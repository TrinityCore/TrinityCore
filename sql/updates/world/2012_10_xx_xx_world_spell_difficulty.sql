-- Boss Elder Nadox Move Heroic Spell in spelldifficulty
DELETE FROM `spelldifficulty_dbc` WHERE `id` =56130;
INSERT INTO `spelldifficulty_dbc`(`id`,`spellid0`,`spellid1`) VALUES
(56130,56130,59467); -- Spell Pound 

DELETE FROM `spell_script_names` WHERE `spell_id`=56153;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(56153, 'spell_elder_nadox_guardian');
