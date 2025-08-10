-- Update Warrior Class Start Actions for Dragonflight (Unlocked Races)
DELETE FROM `playercreateinfo_action` WHERE `race` IN (1,2,3,4,5,6,7,8,9,10,11,22,24,25,26) AND `class`=1;
INSERT INTO `playercreateinfo_action` (`race`,`class`,`button`,`action`,`type`) VALUES
(1,1,0,1464,0), -- Human (Sniffed)
(1,1,9,59752,0),
(1,1,72,88163,0),
(1,1,81,59752,0),
(2,1,0,1464,0), -- Orc (Sniffed)
(2,1,9,20572,0),
(2,1,72,88163,0),
(2,1,81,20572,0),
(3,1,0,1464,0), -- Dwarf (Sniffed)
(3,1,9,20594,0),
(3,1,72,88163,0),
(3,1,81,20594,0),
(4,1,0,1464,0), -- Night Elf (Sniffed)
(4,1,9,58984,0),
(4,1,72,88163,0),
(4,1,81,58984,0),
(5,1,0,1464,0), -- Undead (Sniffed)
(5,1,8,7744,0),
(5,1,9,20577,0),
(5,1,72,88163,0),
(5,1,81,20577,0),
(6,1,0,1464,0), -- Tauren (Sniffed)
(6,1,9,20549,0),
(6,1,72,88163,0),
(6,1,81,20549,0),
(7,1,0,1464,0), -- Gnome (Sniffed)
(7,1,9,20589,0),
(7,1,72,88163,0),
(7,1,81,20589,0),
(8,1,0,1464,0), -- Troll (Sniffed)
(8,1,9,26297,0),
(8,1,72,88163,0),
(8,1,81,26297,0),
(9,1,0,1464,0), -- Goblin (Sniffed)
(9,1,9,69070,0),
(9,1,10,69041,0),
(9,1,72,88163,0),
(9,1,81,69070,0),
(9,1,82,69041,0),
(10,1,0,1464,0), -- Blood Elf (Sniffed)
(10,1,9,69179,0),
(10,1,72,88163,0),
(10,1,81,69179,0),
(11,1,0,1464,0), -- Draenei (Sniffed)
(11,1,9,28880,0),
(11,1,72,88163,0),
(11,1,81,28880,0),
(22,1,0,1464,0), -- Worgan (Sniffed)
(22,1,72,88163,0),
(24,1,0,88163,0), -- Pandarian Neutral (Sniffed)
(24,1,1,1464,0),
(24,1,9,107079,0),
(24,1,11,77273,0),
(24,1,72,88163,0),
(24,1,81,107079,0),
(24,1,83,77273,0),
(25,1,0,1464,0), -- Pandarian Alliance (Sniffed)
(25,1,9,107079,0),
(26,1,0,1464,0), -- Pandarian Horde (Sniffed)
(26,1,9,107079,0);

-- Update Paladin Class Start Actions for Dragonflight (Unlocked Races)
DELETE FROM `playercreateinfo_action` WHERE `race` IN (1,3,6,10,11) AND `class`=2;
INSERT INTO `playercreateinfo_action` (`race`,`class`,`button`,`action`,`type`) VALUES
(1,2,0,35395,0), -- Human (Sniffed)
(1,2,9,59752,0),
(3,2,0,35395,0), -- Dwarf (Sniffed)
(3,2,9,20594,0),
(6,2,0,35395,0), -- Tauren (Sniffed)
(6,2,9,20549,0),
(10,2,0,35395,0), -- Blood Elf (Sniffed)
(10,2,9,155145,0),
(11,2,0,35395,0), -- Draenei (Sniffed)
(11,2,9,59542,0),
(11,2,83,4540,128);

-- Update Hunter Class Start Actions for Dragonflight (Unlocked Races)
DELETE FROM `playercreateinfo_action` WHERE `race` IN (1,2,3,4,5,6,7,8,9,10,11,22,24,25,26) AND `class`=3;
INSERT INTO `playercreateinfo_action` (`race`,`class`,`button`,`action`,`type`) VALUES
(1,3,0,56641,0),  -- Human (Sniffed)
(1,3,9,59752,0),
(2,3,0,56641,0),  -- Orc (Sniffed)
(2,3,9,20572,0),
(3,3,0,56641,0),  -- Dwarf (Sniffed)
(3,3,9,20594,0),
(4,3,0,56641,0),  -- Night Elf (Sniffed)
(4,3,9,58984,0),
(5,3,0,56641,0),  -- Undead (Sniffed)
(5,3,8,7744,0),
(5,3,9,20577,0),
(6,3,0,56641,0),  -- Tauren (Sniffed)
(6,3,9,20549,0),
(7,3,0,56641,0),  -- Gnome (Sniffed)
(7,3,9,20589,0),
(8,3,0,56641,0),  -- Troll (Sniffed)
(8,3,9,26297,0),
(9,3,0,56641,0),  -- Goblin (Sniffed)
(9,3,8,69041,0),
(9,3,9,69070,0),
(10,3,0,56641,0), -- Blood Elf (Sniffed)
(10,3,9,80483,0),
(11,3,0,56641,0), -- Draenei (Sniffed)
(11,3,9,59543,0),
(22,3,0,56641,0), -- Worgan (Sniffed)
(24,3,0,56641,0), -- Pandaren Neutral (Sniffed)
(24,3,7,77272,0),
(24,3,9,107079,0),
(25,3,0,56641,0), -- Pandaren Alliance (Sniffed)
(25,3,9,107079,0),
(26,3,0,56641,0), -- Pandaren Horde (Sniffed)
(26,3,9,107079,0);

-- Update Rogue Class Start Actions for Dragonflight (Unlocked Races)
DELETE FROM `playercreateinfo_action` WHERE `race` IN (1,2,3,4,5,6,7,8,9,10,11,22,24,25,26) AND `class`=4;
INSERT INTO `playercreateinfo_action` (`race`,`class`,`button`,`action`,`type`) VALUES
(1,4,0,1752,0),  -- Human (Sniffed)
(1,4,9,59752,0),
(2,4,0,1752,0),  -- Orc (Sniffed)
(2,4,9,20572,0),
(3,4,0,1752,0),  -- Dwarf (Sniffed)
(3,4,9,20594,0),
(4,4,0,1752,0),  -- Night Elf (Sniffed)
(4,4,9,58984,0),
(4,4,81,58984,0),
(5,4,0,1752,0),  -- Undead (Sniffed)
(5,4,8,7744,0),
(5,4,9,20577,0),
(6,4,0,1752,0),  -- Tauren (Sniffed)
(6,4,9,20549,0),
(7,4,0,1752,0),  -- Gnome (Sniffed)
(7,4,9,20589,0),
(8,4,0,1752,0),  -- Troll (Sniffed)
(8,4,9,26297,0),
(8,4,76,26297,0),
(9,4,0,1752,0),  -- Goblin (Sniffed)
(9,4,9,69070,0),
(9,4,10,69041,0),
(10,4,0,1752,0), -- Blood Elf (Sniffed)
(10,4,9,25046,0),
(11,4,0,1752,0), -- Draenei (Sniffed)
(11,4,9,370626,0),
(22,4,0,1752,0), -- Worgan (Sniffed)
(24,4,0,1752,0), -- Pandaren Neutral (Sniffed)
(24,4,9,107079,0),
(24,4,11,77272,0),
(25,4,0,1752,0), -- Pandaren Alliance (Sniffed)
(25,4,9,107079,0),
(26,4,0,1752,0), -- Pandaren Horde (Sniffed)
(26,4,9,107079,0);

-- Update Priest Class Start Actions for Dragonflight (Unlocked Races)
DELETE FROM `playercreateinfo_action` WHERE `race` IN (1,2,3,4,5,6,7,8,9,10,11,22,24,25,26) AND `class`=5;
INSERT INTO `playercreateinfo_action` (`race`,`class`,`button`,`action`,`type`) VALUES
(1,5,0,585,0),  -- Human (Sniffed)
(1,5,9,59752,0),
(2,5,0,585,0),  -- Orc (Sniffed)
(2,5,9,33702,0),
(3,5,0,585,0),  -- Dwarf (Sniffed)
(3,5,9,20594,0),
(4,5,0,585,0),  -- Night Elf (Sniffed)
(4,5,9,58984,0),
(4,5,81,58984,0),
(5,5,0,585,0),  -- Undead (Sniffed)
(5,5,8,7744,0),
(5,5,9,20577,0),
(6,5,0,585,0),  -- Tauren (Sniffed)
(6,5,9,20549,0),
(7,5,0,585,0),  -- Gnome (Sniffed)
(7,5,9,20589,0),
(8,5,0,585,0),  -- Troll (Sniffed)
(8,5,9,26297,0),
(9,5,0,585,0),  -- Goblin (Sniffed)
(9,5,9,69070,0),
(9,5,10,69041,0),
(10,5,0,585,0), -- Blood Elf (Sniffed)
(11,5,0,585,0), -- Draenei (Sniffed)
(11,5,9,59544,0),
(11,5,83,4540,128),
(22,5,0,585,0), -- Worgan (Sniffed)
(24,5,0,585,0), -- Pandaren Neutral
(24,5,9,107079,0),
(25,5,0,585,0), -- Pandaren Alliance (Sniffed)
(25,5,9,107079,0),
(26,5,0,585,0), -- Pandaren Horde (Sniffed)
(26,5,9,107079,0);

-- Update Shaman Class Start Actions for Dragonflight (Unlocked Races)
DELETE FROM `playercreateinfo_action` WHERE `race` IN (2,3,6,8,9,10,11,24,25,26) AND `class`=7;
INSERT INTO `playercreateinfo_action` (`race`,`class`,`button`,`action`,`type`) VALUES
(2,7,0,188196,0),  -- Orc (Sniffed)
(2,7,9,33697,0),
(2,7,72,188196,0),
(3,7,0,188196,0),  -- Dwarf (Sniffed)
(3,7,9,20594,0),
(3,7,72,188196,0),
(6,7,0,188196,0),  -- Tauren (Sniffed)
(6,7,9,20549,0),
(6,7,75,20549,0),
(8,7,0,188196,0),  -- Troll (Sniffed)
(8,7,9,26297,0),
(8,7,72,188196,0),
(9,7,0,188196,0),  -- Goblin (Sniffed)
(9,7,9,69070,0),
(9,7,10,69041,0),
(9,7,72,188196,0),
(11,7,0,188196,0), -- Draenei (Sniffed)
(11,7,9,59547,0),
(24,7,0,188196,0), -- Pandaren Neutral (Sniffed)
(24,7,9,107079,0),
(24,7,11,77272,0),
(24,7,72,188196,0),
(25,7,0,188196,0), -- Pandaren Alliance (Sniffed)
(25,7,9,107079,0),
(26,7,0,188196,0), -- Pandaren Horde (Sniffed)
(26,7,9,107079,0);

-- Update Mage Class Start Actions for Dragonflight (Unlocked Races)
DELETE FROM `playercreateinfo_action` WHERE `race` IN (1,2,3,4,5,6,7,8,9,10,11,22,24,25,26) AND `class`=8;
INSERT INTO `playercreateinfo_action` (`race`,`class`,`button`,`action`,`type`) VALUES
(1,8,0,116,0),  -- Human (Sniffed)
(1,8,9,59752,0),
(2,8,0,116,0),  -- Orc (Sniffed)
(2,8,9,33702,0),
(3,8,0,116,0),  -- Dwarf (Sniffed)
(3,8,9,20594,0),
(4,8,0,116,0),  -- Night Elf (Sniffed)
(4,8,9,58984,0),
(5,8,0,116,0),  -- Undead (Sniffed)
(5,8,8,7744,0),
(5,8,9,20577,0),
(6,8,0,116,0),  -- Tauren (Sniffed)
(6,8,9,20549,0),
(7,8,0,116,0),  -- Gnome (Sniffed)
(7,8,9,20589,0),
(8,8,0,116,0),  -- Troll (Sniffed)
(8,8,9,26297,0),
(9,8,0,116,0),  -- Goblin (Sniffed)
(9,8,9,69070,0),
(9,8,10,69041,0),
(10,8,0,116,0), -- Blood Elf (Sniffed)
(10,8,9,28730,0),
(11,8,0,116,0), -- Draenei (Sniffed)
(11,8,9,59548,0),
(11,8,83,4540,128),
(22,8,0,116,0), -- Worgan (Sniffed)
(24,8,0,116,0), -- Pandaren Neutral (Sniffed)
(24,8,9,107079,0),
(24,8,11,77264,128),
(25,8,0,116,0), -- Pandaren Alliance (Sniffed)
(25,8,9,107079,0),
(26,8,0,116,0), -- Pandaren Horde (Sniffed)
(26,8,9,107079,0);

-- Update Warlock Class Start Actions for Dragonflight (Unlocked Races)
DELETE FROM `playercreateinfo_action` WHERE `race` IN (1,2,3,5,7,8,9,10,22) AND `class`=9;
INSERT INTO `playercreateinfo_action` (`race`,`class`,`button`,`action`,`type`) VALUES
(1,9,0,686,0),  -- Human (Sniffed)
(1,9,9,59752,0),
(2,9,0,686,0),  -- Orc (Sniffed)
(2,9,9,33702,0),
(3,9,0,686,0),  -- Dwarf (Sniffed)
(3,9,9,20594,0),
(5,9,0,686,0),  -- Undead (Sniffed)
(5,9,8,7744,0),
(5,9,9,20577,0),
(7,9,0,686,0),  -- Gnome (Sniffed)
(7,9,9,20589,0),
(8,9,0,686,0),  -- Troll (Sniffed)
(8,9,9,26297,0),
(9,9,0,686,0),  -- Goblin (Sniffed)
(9,9,9,69070,0),
(9,9,10,69041,0),
(10,9,0,686,0), -- Blood Elf (Sniffed)
(10,9,9,28730,0),
(22,9,0,686,0); -- Worgan (Sniffed)

-- Update Monk Class Start Actions for Dragonflight (Unlocked Races)
DELETE FROM `playercreateinfo_action` WHERE `race` IN (1,2,3,4,5,6,7,8,9,10,11,22,24,25,26) AND `class`=10;
INSERT INTO `playercreateinfo_action` (`race`,`class`,`button`,`action`,`type`) VALUES
(1,10,0,100780,0),  -- Human (Sniffed)
(1,10,9,59752,0),
(2,10,0,100780,0),  -- Orc (Sniffed)
(2,10,9,33697,0),
(3,10,0,100780,0),  -- Dwarf (Sniffed)
(3,10,9,20594,0),
(4,10,0,100780,0),  -- Night Elf (Sniffed)
(4,10,9,58984,0),
(5,10,0,100780,0),  -- Undead (Sniffed)
(5,10,8,7744,0),
(5,10,9,20577,0),
(6,10,0,100780,0),  -- Tauren (Sniffed)
(6,10,9,20549,0),
(7,10,0,100780,0),  -- Gnome (Sniffed)
(7,10,9,20589,0),
(8,10,0,100780,0),  -- Troll (Sniffed)
(8,10,9,26297,0),
(9,10,0,100780,0),  -- Goblin (Sniffed)
(10,10,0,100780,0), -- Blood Elf (Sniffed)
(10,10,9,129597,0),
(11,10,0,100780,0), -- Draenei (Sniffed)
(11,10,9,121093,0),
(22,10,0,100780,0), -- Worgan (Sniffed)
(24,10,0,100780,0), -- Pandaren Neutral (Sniffed)
(24,10,9,107079,0),
(25,10,0,100780,0), -- Pandaren Alliance (Sniffed)
(25,10,9,107079,0),
(26,10,0,100780,0), -- Pandaren Horde (Sniffed)
(26,10,9,107079,0);

-- Update Druid Class Start Actions for Dragonflight (Unlocked Races)
DELETE FROM `playercreateinfo_action` WHERE `race` IN (4,6,8,22) AND `class`=11;
INSERT INTO `playercreateinfo_action` (`race`,`class`,`button`,`action`,`type`) VALUES
(4,11,0,5176,0),  -- Night Elf (Sniffed)
(4,11,9,58984,0),
(4,11,81,58984,0),
(6,11,0,5176,0),  -- Tauren (Sniffed)
(6,11,9,20549,0),
(6,11,81,20549,0),
(8,11,0,5176,0),  -- Troll (Sniffed)
(8,11,9,26297,0),
(8,11,81,26297,0),
(8,11,84,6603,128),
(22,11,0,5176,0); -- Worgan (Sniffed)
