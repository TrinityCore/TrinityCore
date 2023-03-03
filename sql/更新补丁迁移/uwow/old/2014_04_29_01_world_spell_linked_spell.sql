delete from spell_linked_spell where spell_effect = 144595 and hastalent = 144593;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `comment`) VALUES 
(53385, 144595, 0, 144593, 0, 25, 0, 0, 0, 0, 'cast Divine Storm add aura Divine Purpose'),
(53600, 144595, 0, 144593, 0, 25, 0, 0, 0, 0, 'cast Shield of the Righteous add aura Divine Purpose'),
(84963, 144595, 0, 144593, 0, 25, 0, 0, 0, 0, 'cast Inquisition add aura Divine Purpose'),
(85222, 144595, 0, 144593, 0, 25, 0, 0, 0, 0, 'cast Light of Dawn add aura Divine Purpose'),
(85256, 144595, 0, 144593, 0, 25, 0, 0, 0, 0, 'cast Templars Verdict add aura Divine Purpose'),
(85673, 144595, 0, 144593, 0, 25, 0, 0, 0, 0, 'cast Word of Glory add aura Divine Purpose'),
(114163, 144595, 0, 144593, 0, 25, 0, 0, 0, 0, 'cast Eternal Flame add aura Divine Purpose'),
(130552, 144595, 0, 144593, 0, 25, 0, 0, 0, 0, 'cast Harsh Word add aura Divine Purpose'),
(136494, 144595, 0, 144593, 0, 25, 0, 0, 0, 0, 'cast Word of Glory add aura Divine Purpose');

delete from spell_linked_spell where spell_effect = '-144595' and hastalent = 144593;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `comment`) VALUES 
(53385, -144595, 0, 144593, 0, 25, 0, 0, 0, 0, 'cast Divine Storm remove Divine Purpose');