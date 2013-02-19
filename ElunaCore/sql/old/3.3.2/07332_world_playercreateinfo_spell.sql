-- Add new start weapons as of 3.3 patch

-- Warrior: Two-Handed Sword
DELETE FROM `playercreateinfo_spell` WHERE `class`=1 AND `Spell`=202;
INSERT INTO `playercreateinfo_spell` (`race`,`class`,`Spell`,`Note`) VALUES
(1,1,202, 'Two-Handed Swords'),
(4,1,202, 'Two-Handed Swords'),
(5,1,202, 'Two-Handed Swords'),
(7,1,202, 'Two-Handed Swords'),
(8,1,202, 'Two-Handed Swords'),
(11,1,202, 'Two-Handed Swords');

-- Hunter: Two-Handed Axe
DELETE FROM `playercreateinfo_spell` WHERE `class`=3 AND `Spell`=197;
INSERT INTO `playercreateinfo_spell` (`race`,`class`,`Spell`,`Note`) VALUES
(2,3,197, 'Two-Handed Axes'),
(3,3,197, 'Two-Handed Axes'),
(4,3,197, 'Two-Handed Axes'),
(6,3,197, 'Two-Handed Axes'),
(8,3,197, 'Two-Handed Axes'),
(10,3,197, 'Two-Handed Axes'),
(11,3,197, 'Two-Handed Axes');

-- Rogue: Dual Wield
DELETE FROM `playercreateinfo_spell` WHERE `class`=4 AND `Spell`=674;
INSERT INTO `playercreateinfo_spell` (`race`,`class`,`Spell`,`Note`) VALUES
(1,4,674, 'Dual Wield'),
(2,4,674, 'Dual Wield'),
(3,4,674, 'Dual Wield'),
(4,4,674, 'Dual Wield'),
(5,4,674, 'Dual Wield'),
(7,4,674, 'Dual Wield'),
(8,4,674, 'Dual Wield'),
(10,4,674, 'Dual Wield');

-- Priest: Staff
DELETE FROM `playercreateinfo_spell` WHERE `class`=5 AND `Spell`=227;
INSERT INTO `playercreateinfo_spell` (`race`,`class`,`Spell`,`Note`) VALUES
(1,5,227, 'Staves'),
(3,5,227, 'Staves'),
(4,5,227, 'Staves'),
(5,5,227, 'Staves'),
(8,5,227, 'Staves'),
(10,5,227, 'Staves'),
(11,5,227, 'Staves');

-- Warlock: Staff
DELETE FROM `playercreateinfo_spell` WHERE `class`=9 AND `Spell`=227;
INSERT INTO `playercreateinfo_spell` (`race`,`class`,`Spell`,`Note`) VALUES
(1,9,227, 'Staves'),
(2,9,227, 'Staves'),
(5,9,227, 'Staves'),
(7,9,227, 'Staves'),
(10,9,227, 'Staves');
