DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (31224,41292,44007,44867);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(31224,  -1543,  2, 'Cloak of Shadows - Flare'),
(41292,  42017,  2, 'Aura of Suffering'),
(44007,  -43657, 2, 'Storm Eye Safe Zone Immune'),
(44867,  -46019, 2, 'Spectral Exhaustion - Teleport: Spectral Realm');
