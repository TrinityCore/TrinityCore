-- 3.3.5 - 6.x
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=49889;

-- 6.x only
DELETE FROM `spell_script_names` WHERE `spell_id` IN (71505,76753,76757,79483,84259,84286,85682,85912,86270,86784,87439,88630,93996,98581,100856,102288,106935,126240,136757,176747);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(71505, 'spell_gen_clone'),
(76753, 'spell_gen_clone'),
(76757, 'spell_gen_clone'),
(79483, 'spell_gen_clone'),
(84259, 'spell_gen_clone'),
(84286, 'spell_gen_clone'),
(85682, 'spell_gen_clone'),
(85912, 'spell_gen_clone'),
(86270, 'spell_gen_clone'),
(86784, 'spell_gen_clone'),
(87439, 'spell_gen_clone'),
(88630, 'spell_gen_clone'),
(93996, 'spell_gen_clone'),
(98581, 'spell_gen_clone'),
(100856, 'spell_gen_clone'),
(102288, 'spell_gen_clone'),
(106935, 'spell_gen_clone'),
(126240, 'spell_gen_clone'),
(136757, 'spell_gen_clone'),
(176747, 'spell_gen_clone');

DELETE FROM `spell_script_names` WHERE `spell_id`=149319;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(149319, 'spell_gen_clone_weapon');
