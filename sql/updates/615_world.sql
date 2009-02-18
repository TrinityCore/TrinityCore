-- Wyvern Sting rank 5 and 6 not avail. till wotlk
DELETE FROM spell_linked_spell WHERE `spell_trigger` IN (-49011, -49012);

-- typo
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (43468, 43648);
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (43648, 44007, 1, 'Storm Eye Safe Zone');


