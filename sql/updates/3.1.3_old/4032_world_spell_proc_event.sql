DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (51209, 50334);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(51209, 55095, 1, 'Hungering cold - frost fever'),
(50334, 58923, 2, 'Berserk - modify target number aura');
