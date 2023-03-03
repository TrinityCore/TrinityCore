INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `comment`) VALUES ('77513', '48263', 'Blood Presence');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `comment`) VALUES ('-77513', '-48263', 'Blood Presence');

INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `comment`) VALUES ('77514', '48266', 'Frost Presence');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `comment`) VALUES ('-77514', '-48266', 'Frost Presence');

INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `comment`) VALUES ('77515', '48265', 'Unholy Presence');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `comment`) VALUES ('-77515', '-48265', 'Unholy Presence');

DELETE FROM `spell_script_names` WHERE (`spell_id`='48265') AND (`ScriptName`='spell_dk_unholy_presence');
DELETE FROM `spell_script_names` WHERE (`spell_id`='50392') AND (`ScriptName`='spell_dk_unholy_presence');