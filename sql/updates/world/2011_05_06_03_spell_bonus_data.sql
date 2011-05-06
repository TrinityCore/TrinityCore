-- Procced spell Pillar of Flame should not scale with spellpower
DELETE FROM `spell_bonus_data` WHERE `entry` IN (67760,67714);
INSERT INTO `spell_bonus_data` (`entry`,`direct_bonus`,`dot_bonus`,`ap_bonus`,`ap_dot_bonus`,`comments`) VALUES
(67760,0,0,0,0, 'Item - Coliseum 25 Heroic Caster Trinket - Pillar of Flame'),
(67714,0,0,0,0, 'Item - Coliseum 25 Normal Caster Trinket - Pillar of Flame');