DELETE FROM spell_script_names WHERE scriptname IN ("spell_thousand_needles_speedbarge_diving_helm_check", "spell_thousand_needles_speedbarge_diving_helm_effect");
INSERT INTO spell_script_names VALUES
(75651, "spell_thousand_needles_speedbarge_diving_helm_check"),
(75627, "spell_thousand_needles_speedbarge_diving_helm_effect");

DELETE FROM spell_area WHERE spell = 75651 AND area = 400;
INSERT INTO spell_area (spell, area, autocast) VALUES
(75651, 400, 1);
