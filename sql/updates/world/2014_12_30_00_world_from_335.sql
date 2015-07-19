-- Lunar 0
-- Lita  1
-- Noblegarden 2
-- Childrens week 3
-- Midsummer 4
-- Brewfest 5
-- Hallows End 6
-- Pilgrims 7
-- Winterveil 8

-- Undead  Hallows End Winterveil
-- Bloodelf Luna winterveil midsummer
-- Orc Luna brewfest hallows end 
-- Troll Luna 
-- Tauren 
-- Goblin Hallows end   Winterveil
-- Human Luna Hallows end
-- Gnome Hallows end
-- Dwarf 
-- Lunar
-- Night elf
-- Dreanei Brewfest

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry`IN(20102,18927,19177,19169,19175,19171,19172,19176,19178);

DELETE FROM `smart_scripts` WHERE `entryorguid`IN(20102,18927,19177,19169,19175,19171,19172,19176,19178)  AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(20102,0,0,0,1,0,100,0,3000,15000,45000,90000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Goblin Commoner - OOC - Say'),
(18927,0,0,0,1,0,100,0,3000,15000,45000,90000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Human Commoner - OOC - Say'),
(19177,0,0,0,1,0,100,0,3000,15000,45000,90000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Troll Commoner - OOC - Say'),
(19169,0,0,0,1,0,100,0,3000,15000,45000,90000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blood Elf Commoner - OOC - Say'),
(19175,0,0,0,1,0,100,0,3000,15000,45000,90000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Orc Commoner - OOC - Say'),
(19169,0,4,0,1,0,100,0,3000,15000,45000,90000,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blood Elf Commoner - OOC - Say'),
(19175,0,5,0,1,0,100,0,3000,15000,45000,90000,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Orc Commoner - OOC - Say'),
(19171,0,5,0,1,0,100,0,3000,15000,45000,90000,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blood Elf Commoner - OOC - Say'),
(20102,0,6,0,1,0,100,0,3000,15000,45000,90000,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'Goblin Commoner - OOC - Say'),
(19172,0,6,0,1,0,100,0,3000,15000,45000,90000,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gnome Commoner - OOC - Say'),
(18927,0,6,0,1,0,100,0,3000,15000,45000,90000,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'Human Commoner - OOC - Say'),
(19175,0,6,0,1,0,100,0,3000,15000,45000,90000,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'Orc Commoner - OOC - Say'),
(19178,0,6,0,1,0,100,0,3000,15000,45000,90000,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'Forsaken Commoner - OOC - Say'),
(19178,0,8,0,1,0,100,0,3000,15000,45000,90000,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Forsaken Commoner - OOC - Say'),
(20102,0,8,0,1,0,100,0,3000,15000,45000,90000,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Goblin Commoner - OOC - Say'),
(19169,0,8,0,1,0,100,0,3000,15000,45000,90000,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blood Elf Commoner - OOC - Say');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` in(20102,18927,19177,19169,19175,19171,19172,19176,19178);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, 20102, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Luna Festival must be active'),
(22, 1, 18927, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Luna Festival must be active'),
(22, 1, 19175, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Luna Festival must be active'),
(22, 1, 19169, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Luna Festival must be active'),
(22, 1, 19177, 0, 0, 12, 1, 7, 0, 0, 0, 0, 0, '', 'Commoner - Luna Festival must be active'),
(22, 5, 19169, 0, 0, 12, 1, 1, 0, 0, 0, 0, 0, '', 'Commoner - Midsummer must be active'),
(22, 6, 19175, 0, 0, 12, 1, 24, 0, 0, 0, 0, 0, '', 'Commoner - BrewFest must be active'),
(22, 6, 19171, 0, 0, 12, 1, 24, 0, 0, 0, 0, 0, '', 'Commoner - BrewFest must be active'),
(22, 7, 20102, 0, 0, 12, 1, 12, 0, 0, 0, 0, 0, '', 'Commoner - Hallows End must be active'),
(22, 7, 19172, 0, 0, 12, 1, 12, 0, 0, 0, 0, 0, '', 'Commoner - Hallows End must be active'),
(22, 7, 18927, 0, 0, 12, 1, 12, 0, 0, 0, 0, 0, '', 'Commoner - Hallows End must be active'),
(22, 7, 19175, 0, 0, 12, 1, 12, 0, 0, 0, 0, 0, '', 'Commoner - Hallows End must be active'),
(22, 7, 19178, 0, 0, 12, 1, 12, 0, 0, 0, 0, 0, '', 'Commoner - Hallows End must be active'),
(22, 9, 20102, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 9, 19169, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 9, 19178, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active');

DELETE FROM `creature_text` WHERE `entry` IN(20102,18927,19177,19169,19175,19171,19172,19176,19178);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(20102, 0, 0, 'Legend says that the great beast Omen sleeps in the waters of Lake Elune''ara in Moonglade, only to appear once a year. But that''s just a legend.', 12, 0, 100, 0, 0, 0, 16465, 'Goblin Commoner to Goblin Commoner'),
(20102, 0, 1, 'The druids of Nighthaven are holding a great celebration in Moonglade for the Lunar Festival.', 12, 0, 100, 0, 0, 0, 16468, 'Goblin Commoner to Goblin Commoner'),
(18927, 0, 0, 'During the Lunar Festival, we should take time to seek out our elders and consider their wisdom.', 12, 7, 100, 274, 0, 0, 24350, 'Human Commoner to Human Commoner'),
(19177, 0, 0, 'Legend says that the great beast Omen sleeps in the waters of Lake Elune''ara in Moonglade, only to appear once a year. But that''s just a legend.', 12, 1, 100, 0, 0, 0, 24332, 'Troll Commoner to Troll Commoner'),
(19169, 0, 0, 'Legend says that the great beast Omen sleeps in the waters of Lake Elune''ara in Moonglade, only to appear once a year. But that''s just a legend.', 12, 1, 100, 0, 0, 0, 24332, 'Blood Elf Commoner to Blood Elf Commoner'),
(19169, 0, 1, 'The festival of the moon was ever more important to the kaldorei. The great festival of the druids is surely in full swing.', 12, 1, 100, 274, 0, 0, 16171, 'Blood Elf Commoner to Blood Elf Commoner'),
(19175, 0, 0, 'During the Lunar Festival, we should take time to seek out our elders and consider their wisdom.', 12, 1, 100, 0, 0, 0, 24333, 'Orc Commoner to Orc Commoner'),
(19175, 0, 1, 'Have you seen the fireworks? This is the best time of year to buy them.', 12, 1, 100, 0, 0, 0, 24334, 'Orc Commoner to Orc Commoner'),
(19175, 0, 2, 'The druids of Nighthaven are holding a great celebration in Moonglade for the Lunar Festival.', 12, 1, 100, 0, 0, 0, 24335, 'Orc Commoner to Orc Commoner'),
-- Brew Fest
(19171, 5, 0, 'To Brewfest!', 12, 7, 100, 5, 0, 0, 23630, 'Draenei Commoner to Draenei Commoner'),
(19175, 5, 0, 'Where''s me gold? Where''s me beer? Where''s me feet?', 12, 1, 100, 5, 0, 0, 23352, 'Orc Commoner to Orc Commoner'),
-- Hallows end
(20102, 6, 0, 'There MUST be a way to make more money off of this holiday.', 12, 0, 100, 0, 0, 0, 23299, 'Goblin Commoner to Goblin Commoner'),
(20102, 6, 1, 'For the Alliance! Wait... the Horde! Wait... which was I again?', 12, 0, 100, 4, 0, 149, 23364, 'Goblin Commoner to Goblin Commoner'),
(20102, 6, 2, 'The innkeepers are mad to be giving away treats for free.', 12, 0, 100, 0, 0, 0, 23300, 'Goblin Commoner to Goblin Commoner'),
(20102, 6, 3, 'Happy Hallow''s End!', 12, 0, 100, 0, 0, 0, 23284, 'Goblin Commoner to Goblin Commoner'),
(19172, 6, 0, 'We should go trick or treating later.', 12, 7, 100, 0, 0, 0, 24348, 'Gnome Commoner to Gnome Commoner'),
(19172, 6, 1, 'Happy Hallow''s End!', 12, 7, 100, 0, 0, 0, 24346, 'Gnome Commoner to Gnome Commoner'),
(19172, 6, 2, 'We should go trick or treating later.', 12, 7, 100, 1, 0, 0, 24348, 'Gnome Commoner to Gnome Commoner'),
(19172, 6, 3, 'Me got the mad voodoo, mon!', 12, 7, 100, 1, 0, 0, 23361, 'Gnome Commoner to Gnome Commoner'),
(18927, 6, 0, 'I think I''ve eaten too much candy...', 12, 7, 100, 15, 0, 0, 24347, 'Human Commoner to Human Commoner'),
(18927, 6, 1, 'Brains... braaaiiins!', 12, 7, 100, 15, 0, 0, 23358, 'Human Commoner to Human Commoner'),
(18927, 6, 2, 'We should go trick or treating later.', 12, 7, 100, 0, 0, 0, 24348, 'Human Commoner to Human Commoner'),
(18927, 6, 3, 'I think I''ve eaten too much candy...', 12, 7, 100, 0, 0, 0, 24347, 'Human Commoner to Human Commoner'),
(18927, 6, 4, 'Are there any more inns we can visit for treats?', 12, 7, 100, 0, 0, 0, 23293, 'Human Commoner to Human Commoner'),
(18927, 6, 5, 'Next year, I''m dressing up as either a corsair or an assassin.', 12, 7, 100, 0, 0, 0, 24338, 'Human Commoner to Human Commoner'),
(18927, 6, 6, 'What do you think of the mask?', 12, 7, 100, 0, 0, 0, 24339, 'Human Commoner to Human Commoner'),
(18927, 6, 7, 'You know... why DO we celebrate this holiday?', 12, 7, 100, 0, 0, 0, 23287, 'Human Commoner to Human Commoner'),
(19175, 6, 0, 'Happy Hallow''s End!', 12, 1, 100, 0, 0, 0, 24329, 'Orc Commoner to Orc Commoner'),
(19175, 6, 1, 'Next year, I''m dressing up as either a corsair or an assassin.', 12, 1, 100, 0, 0, 0, 24336, 'Orc Commoner to Orc Commoner'),
(19175, 6, 2, 'The Forsaken are right to celebrate their freedom.', 12, 1, 100, 0, 0, 0, 23295, 'Orc Commoner to Orc Commoner'),
(19175, 6, 3, 'We should attend the next burning of the Wickerman.', 12, 1, 100, 0, 0, 0, 23292, 'Orc Commoner to Orc Commoner'),
(19175, 6, 4, 'What do you think of the mask?', 12, 1, 100, 0, 0, 0, 24337, 'Orc Commoner to Orc Commoner'),
(19175, 6, 5, 'We should go trick or treating later.', 12, 1, 100, 1, 0, 0, 24331, 'Orc Commoner to Orc Commoner'),
(19178, 6, 0, 'We should go trick or treating later.', 12, 1, 100, 0, 0, 0, 24331, 'Forsaken Commoner to Forsaken Commoner'),
(19178, 6, 1, 'Happy Hallow''s End!', 12, 1, 100, 0, 0, 0, 24329, 'Forsaken Commoner to Forsaken Commoner'),
(19178, 6, 2, 'I think I''ve eaten too much candy...', 12, 1, 100, 15, 0, 0, 24330, 'Forsaken Commoner to Forsaken Commoner'),
-- Winterveil
(19178, 8, 0, 'Winter Veil just isn''t the same now, but going through the motions still makes me feel something.', 12, 1, 100, 0, 0, 0, 16167, 'Forsaken Commoner to Forsaken Commoner'),
(19178, 8, 1, 'Greatfather Winter will leave presents for everyone under the tree in Orgrimmar. I wonder what he''ll bring me this year.', 12, 1, 100, 6, 0, 0, 16464, 'Forsaken Commoner to Forsaken Commoner'),
(19178, 8, 2, 'Where are all those wonderful winter hats coming from?', 12, 1, 100, 0, 0, 0, 24325, 'Forsaken Commoner to Forsaken Commoner'),
(19178, 8, 3, 'I hope I have a chance to visit with Greatfather Winter before Winter Veil is over.', 12, 1, 100, 0, 0, 0, 24323, 'Forsaken Commoner to Forsaken Commoner'),
(19178, 8, 4, 'Winter Veil just isn''t the same now, but going through the motions still makes me feel something.', 12, 1, 100, 396, 0, 0, 16167, 'Forsaken Commoner to Forsaken Commoner'),
(19178, 8, 5, 'I hope I have a chance to visit with Greatfather Winter before Winter Veil is over.', 12, 1, 100, 273, 0, 0, 24323, 'Forsaken Commoner to Forsaken Commoner'),
(19178, 8, 6, 'Where are all those wonderful winter hats coming from?', 12, 1, 100, 273, 0, 0, 24325, 'Forsaken Commoner to Forsaken Commoner'),
(19178, 8, 7, 'Winter Veil just isn''t the same now, but going through the motions still makes me feel something.', 12, 1, 100, 6, 0, 0, 16167, 'Forsaken Commoner to Forsaken Commoner'),
(19178, 8, 8, 'The goblins of Smokywood Pastures always have such wonderful treats for sale this time of year.', 12, 1, 100, 273, 0, 0, 24324, 'Forsaken Commoner to Forsaken Commoner'),
(19178, 8, 9, 'Greatfather Winter will leave presents for everyone under the tree in Orgrimmar. I wonder what he''ll bring me this year.', 12, 1, 100, 396, 0, 0, 16464, 'Forsaken Commoner to Forsaken Commoner'),
(20102, 8, 0, 'Where are all those wonderful winter hats coming from?', 12, 0, 100, 0, 0, 0, 16503, 'Goblin Commoner to Goblin Commoner'),
(20102, 8, 1, 'Ah, the Winter Wondervolt. What will we think of next?', 12, 0, 100, 0, 0, 0, 16501, 'Goblin Commoner to Goblin Commoner'),
(20102, 8, 2, 'The goblins of Smokywood Pastures always have such wonderful treats for sale this time of year.', 12, 0, 100, 0, 0, 0, 0, 'Goblin Commoner to Goblin Commoner'),
(20102, 8, 3, 'Ah, the Winter Wondervolt. What will we think of next?', 12, 0, 100, 274, 0, 0, 16501, 'Goblin Commoner to Goblin Commoner'),
(19169, 8, 0, 'Winter Veil has always been a human thing. To see the goblins and orcs take it up is rather strange.', 12, 1, 100, 0, 0, 0, 16173, 'Blood Elf Commoner to Blood Elf Commoner'),
(19169, 8, 1, 'Greatfather Winter will leave presents for everyone under the tree in Orgrimmar. I wonder what he''ll bring me this year.', 12, 1, 100, 0, 0, 0, 16464, 'Blood Elf Commoner to Blood Elf Commoner'),
(19169, 8, 2, 'Greatfather Winter will leave presents for everyone under the tree in Orgrimmar. I wonder what he''ll bring me this year.', 12, 1, 100, 6, 0, 0, 16464, 'Blood Elf Commoner to Blood Elf Commoner'),
(19169, 8, 3, 'I hope I have a chance to visit with Greatfather Winter before Winter Veil is over.', 12, 1, 100, 0, 0, 0, 24323, 'Blood Elf Commoner to Blood Elf Commoner'),
-- Midsummer
(19169, 4, 0, 'The Horde fires will never be extinguished!', 12, 1, 100, 4, 0, 0, 24534, 'Blood Elf Commoner to Blood Elf Commoner');
