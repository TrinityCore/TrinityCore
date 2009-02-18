-- demon fire
UPDATE `creature_template` SET spell1 = 40029, flags_extra = 128, ScriptName = '' WHERE entry = 23069;
-- pillar of fire
UPDATE `creature_template` SET spell1 = 43218, flags_extra = 128, ScriptName = '' WHERE entry = 24187;
-- Broggok Poison Cloud
UPDATE `creature_template` SET spell1 = 30914, flags_extra = 128, ScriptName = '' WHERE entry = 17662;

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (43468, 43648, 43658, 43658, 43658, 43658, 43658);
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (43648, 44007, 1, 'Storm Eye Safe Zone');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (43658, 43653, 0, 'Electrical Arc Visual');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (43658, 43654, 0, 'Electrical Arc Visual');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (43658, 43655, 0, 'Electrical Arc Visual');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (43658, 43656, 0, 'Electrical Arc Visual');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (43658, 43659, 0, 'Electrical Arc Visual');

