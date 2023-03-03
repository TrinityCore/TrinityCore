delete from spell_proc_event where entry = 86172;

delete from spell_linked_spell where spell_effect = 90174;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `comment`) VALUES 
(53385, 90174, 0, 86172, 0, 25, 0, 0, 0, 0, 'cast Divine Storm add aura Divine Purpose'),
(53600, 90174, 0, 86172, 0, 25, 0, 0, 0, 0, 'cast Shield of the Righteous add aura Divine Purpose'),
(84963, 90174, 0, 86172, 0, 25, 0, 0, 0, 0, 'cast Inquisition add aura Divine Purpose'),
(85222, 90174, 0, 86172, 0, 25, 0, 0, 0, 0, 'cast Light of Dawn add aura Divine Purpose'),
(85256, 90174, 0, 86172, 0, 25, 0, 0, 0, 0, 'cast Templars Verdict add aura Divine Purpose'),
(85673, 90174, 0, 86172, 0, 25, 0, 0, 0, 0, 'cast Word of Glory add aura Divine Purpose'),
(114163, 90174, 0, 86172, 0, 25, 0, 0, 0, 0, 'cast Eternal Flame add aura Divine Purpose'),
(130552, 90174, 0, 86172, 0, 25, 0, 0, 0, 0, 'cast Harsh Word add aura Divine Purpose'),
(136494, 90174, 0, 86172, 0, 25, 0, 0, 0, 0, 'cast Word of Glory add aura Divine Purpose');