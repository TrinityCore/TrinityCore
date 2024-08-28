delete from spell_script_names WHERE ScriptName IN (
"spell_af_skyward_ascent",
"spell_af_energy",
"spell_af_surge_forward",
"spell_af_whirling_surge"
);
INSERT INTO spell_script_names VALUES
(374763, "spell_af_skyward_ascent"),
(372610, "spell_af_skyward_ascent"),
(372773, "spell_af_energy"),
(372608, "spell_af_surge_forward"),
(361584, "spell_af_whirling_surge");

DELETE FROM `spell_linked_spell` WHERE spell_trigger = 406095 AND spell_effect = 423624;
DELETE FROM `spell_linked_spell` WHERE spell_trigger = 372773 AND spell_effect = 433547;
INSERT INTO `spell_linked_spell` VALUES
(406095, 423624, 2, "Dragonriding energy widget"),
(372773, 433547, 2, "Vigor cache");
