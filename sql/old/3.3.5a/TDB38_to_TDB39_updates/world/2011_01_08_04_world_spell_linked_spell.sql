-- Spells from teleporters
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (66548, 66549, 66550, 66551);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(66548, 66550, 0, 'Isle of Conquest (IN>OUT)'),
(66549, 66551, 0, 'Isle of Conquest (OUT>IN)'),
(66551, -66548, 2, 'Isle of Conquest Teleport (OUT>IN) Debuff limit'),
(66550, -66549, 2, 'Isle of Conquest Teleport (IN>OUT) Debuff limit');