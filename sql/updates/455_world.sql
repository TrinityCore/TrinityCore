-- demon fire
update creature_template set spell1 = 40029, flags_extra = 128, scriptname = '' where entry = 23069;
-- pillar of fire
update creature_template set spell1 = 43218, flags_extra = 128, scriptname = '' where entry = 24187;
-- Broggok Poison Cloud
update creature_template set spell1 = 30914, flags_extra = 128, scriptname = '' where entry = 17662;


INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (43468, 44007, 1, 'Storm Eye Safe Zone');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (43658, 43653, 0, 'Electrical Arc Visual');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (43658, 43654, 0, 'Electrical Arc Visual');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (43658, 43655, 0, 'Electrical Arc Visual');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (43658, 43656, 0, 'Electrical Arc Visual');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (43658, 43659, 0, 'Electrical Arc Visual');