-- Procced spell Pillar of Flame should not scale with spellpower
DELETE FROM `spell_bonus_data` WHERE `entry` IN (67760,67714);
INSERT INTO `spell_bonus_data` (`entry`,`direct_bonus`,`dot_bonus`,`ap_bonus`,`ap_dot_bonus`,`comments`) VALUES
(67760,0,0,0,0, 'Item - Coliseum 25 Heroic Caster Trinket - Pillar of Flame'),
(67714,0,0,0,0, 'Item - Coliseum 25 Normal Caster Trinket - Pillar of Flame');
-- Proc event for item spells
DELETE FROM `spell_proc_event` WHERE `entry` IN (67712,67758);
INSERT INTO `spell_proc_event` (`entry`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`procFlags`,`procEx`,`ppmRate`,`CustomChance`,`Cooldown`) VALUES
(67712,0,0,0,0,0,0x00011000,0x0000002,0,0,2),
(67758,0,0,0,0,0,0x00011000,0x0000002,0,0,2);
