-- Druid
UPDATE `spell_bonus_data` SET `direct_bonus`=0,`dot_bonus`=0 WHERE `entry` IN (779,1822,60089);
DELETE FROM `spell_bonus_data` WHERE `entry` IN (1079,9007,22568);
INSERT INTO `spell_bonus_data` (`entry`,`direct_bonus`,`dot_bonus`,`ap_bonus`,`ap_dot_bonus`,`comments`) VALUES
(1079,0,0,-1,-1, 'Druid - Rip'),
(9007,0,0,-1,-1, 'Druid - Pounce Bleed'),
(22568,0,0,-1,-1, 'Druid - Ferocious Bite');

-- Hunter
UPDATE `spell_bonus_data` SET `direct_bonus`=0,`dot_bonus`=0 WHERE `entry` IN (3044,3674,53352,13812,13797,1978,42243);
UPDATE `spell_bonus_data` SET `ap_dot_bonus`=0.1 WHERE `entry`=13812;
DELETE FROM `spell_bonus_data` WHERE `entry` IN (24131,53353);
INSERT INTO `spell_bonus_data` (`entry`,`direct_bonus`,`dot_bonus`,`ap_bonus`,`ap_dot_bonus`,`comments`) VALUES
(24131,0,0,-1,-1, 'Hunter - Wyvern Sting (triggered)'),
(53353,0,0,-1,-1, 'Hunter - Chimera Shot (Serpent)');
DELETE FROM `spell_ranks` WHERE `first_spell_id`=24131;
INSERT INTO `spell_ranks` VALUES
(24131,24131,1),
(24131,24134,2),
(24131,24135,3),
(24131,27069,4),
(24131,49009,5),
(24131,49010,6);

-- Rogue
UPDATE `spell_bonus_data` SET `direct_bonus`=0,`dot_bonus`=0 WHERE `entry` IN (2818,2819,11353,11354,25349,26968,27187,57969,57970);

-- Howling blast
UPDATE `spell_bonus_data` SET `ap_bonus`=0.2 WHERE `entry`=49184;
