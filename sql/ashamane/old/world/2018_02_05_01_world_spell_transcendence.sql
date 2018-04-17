UPDATE `creature_template` SET `ScriptName` = '' WHERE entry = 54569;

DELETE FROM spell_script_names WHERE scriptname IN ("spell_monk_transcendence", "spell_monk_transcendence_clone_visual", "spell_monk_transcendence_transfer");
INSERT INTO spell_script_names VALUES
(101643, "spell_monk_transcendence"),
(119051, "spell_monk_transcendence_clone_visual"),
(119996, "spell_monk_transcendence_transfer");
