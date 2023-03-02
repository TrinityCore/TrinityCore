INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `comment`) VALUES ('74434', '93313', 'Warlock - Seed of Corruption(Soulburn)');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `comment`) VALUES ('74434', '93312', 'Warlock - Drain Life(Soulburn)');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `hastalent`, `comment`) VALUES ('755', '104220', '74434', 'Warlock - Health Funnel(Soulburn)');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `comment`) VALUES ('74434', '104245', 'Warlock - Curse(Soulburn)');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `comment`) VALUES ('74434', '104250', 'Warlock - Curse(Soulburn)');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `comment`) VALUES ('74434', '104249', 'Warlock - Demonic Circle: Teleport(Soulburn)');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `comment`) VALUES ('74434', '104251', 'Warlock - Soul Swap(Soulburn)');

INSERT INTO `spell_radius` (`spell_id`, `effectradius0`, `effectradius1`, `effectradius2`, `comments`) VALUES ('109468', '18', '18', '18', '15 Yards');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('89420', 'spell_warl_drain_life');

DELETE FROM `spell_bonus_data` WHERE (`entry`='89420');
INSERT INTO `spell_bonus_data` (`entry`, `dot_bonus`, `comments`) VALUES ('89420', '0.334', 'Warlock - Warlock - Drain Life(Soulburn)');