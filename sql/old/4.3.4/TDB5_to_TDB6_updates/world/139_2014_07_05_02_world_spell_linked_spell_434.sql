DELETE FROM `spell_linked_spell` WHERE (`spell_trigger`=77767 AND `spell_effect`=91954) OR (`spell_trigger`=56641 AND `spell_effect`=77443);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `comment`) VALUES 
(77767, 91954, 'Cobra Shot Focus'), -- Gives 9 focus on fire
(56641, 77443, 'Steady Shot Focus'); -- Gives 9 focus on fire
