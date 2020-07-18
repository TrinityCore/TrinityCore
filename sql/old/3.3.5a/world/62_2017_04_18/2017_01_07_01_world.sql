-- At The Enemy's Gates - Phasing for Icecrown -- http://www.wowhead.com/quest=13847/at-the-enemys-gates
DELETE FROM `spell_area` WHERE `quest_start` IN (13847, 13851, 13852, 13854, 13855, 13856, 13857, 13858, 13859, 13860) AND `area`=4522;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(64576, 4522, 13847, 13847, 0, 0, 2, 1, 74, 11),
(64576, 4522, 13851, 13851, 0, 0, 2, 1, 74, 11),
(64576, 4522, 13852, 13852, 0, 0, 2, 1, 74, 11),
(64576, 4522, 13854, 13854, 0, 0, 2, 1, 74, 11),
(64576, 4522, 13855, 13855, 0, 0, 2, 1, 74, 11),
(64576, 4522, 13856, 13856, 0, 0, 2, 1, 74, 11),
(64576, 4522, 13857, 13857, 0, 0, 2, 1, 74, 11),
(64576, 4522, 13858, 13858, 0, 0, 2, 1, 74, 11),
(64576, 4522, 13859, 13859, 0, 0, 2, 1, 74, 11),
(64576, 4522, 13860, 13860, 0, 0, 2, 1, 74, 11);
