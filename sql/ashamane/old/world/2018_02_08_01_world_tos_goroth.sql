UPDATE creature_template SET scriptname = "boss_goroth" WHERE entry = 115844;

DELETE FROM spell_script_names WHERE scriptname IN ("spell_burning_armor", "spell_crashing_comet_damage", "spell_infernal_burning", "spell_infernal_burning_remove_spikes");
INSERT INTO spell_script_names VALUES
(231363, "spell_burning_armor"),
(230345, "spell_crashing_comet_damage"),
(233062, "spell_infernal_burning"),
(233078, "spell_infernal_burning_remove_spikes");

UPDATE areatrigger_template SET scriptname = "at_goroth_shattering_star" WHERE Id = 13412;
