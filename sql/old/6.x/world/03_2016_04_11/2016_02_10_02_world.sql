-- DB/Creature: Loot for NPC Tunneling Worm
UPDATE `creature_template` SET `lootid`= 34865 WHERE `entry`= 34865;
DELETE FROM `creature_loot_template` WHERE `entry`= 34865;
INSERT INTO `creature_loot_template` (`entry`,`item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(34865, 55973, 0,  75, 0,1,0,1,1,'Tunneling Worm - Inert Elemental Speck'),
(34865, 55983, 0,  25, 0,1,0,1,1,'Tunneling Worm - Inert Elemental Scintilla'),
(34865,   805, 0, 0.5, 0,1,0,1,1,'Tunneling Worm - Small Red Pouch'),
(34865,   828, 0, 0.5, 0,1,0,1,1,'Tunneling Worm - Small Blue Pouch'),
(34865,  1411, 0, 0.5, 0,1,0,1,1,'Tunneling Worm - Withered Staff'),
(34865,  1431, 0, 0.5, 0,1,0,1,1,'Tunneling Worm - Patchwork Pants'),
(34865,  2589, 0, 0.5, 0,1,0,1,1,'Tunneling Worm - Linen Cloth'),
(34865,  4469, 0, 0.5, 0,1,0,1,1,'Tunneling Worm - Rod of Order - Quest item'),
(34865,  5571, 0, 0.5, 0,1,0,1,1,'Tunneling Worm - Small Black Pouch'),
(34865,  5572, 0, 0.5, 0,1,0,1,1,'Tunneling Worm - Small Green Pouch'),
(34865, 23333, 0, 0.5, 0,1,0,1,1,'Tunneling Worm - Shattered Power Core');
