DELETE FROM `creature_text` WHERE `entry` IN(18927,19171,19175,19177,19173,19172,19176,19148) AND `groupid`=8;
DELETE FROM `creature_text` WHERE `entry` =15746;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(18927, 8, 0, 'The goblins of Smokywood Pastures always have such wonderful treats for sale this time of year.', 12, 7, 100, 6, 0, 0, 24341, 'Human Commoner to Human Commoner'),
(18927, 8, 1, 'The goblins of Smokywood Pastures always have such wonderful treats for sale this time of year.', 12, 7, 100, 0, 0, 0, 24341, 'Human Commoner to Human Commoner'),
(18927, 8, 2, 'I should take the tram to Ironforge and visit Greatfather Winter.', 12, 7, 100, 6, 0, 0, 16032, 'Human Commoner to Human Commoner'),
(18927, 8, 3, 'Greatfather Winter will leave presents for everyone under the tree in Ironforge. I can''t wait to get mine!', 12, 7, 100, 0, 0, 0, 16422, 'Human Commoner to Human Commoner'),
(18927, 8, 4, 'Greatfather Winter will leave presents for everyone under the tree in Ironforge. I can''t wait to get mine!', 12, 7, 100, 396, 0, 0, 16422, 'Human Commoner to Human Commoner'),
(18927, 8, 5, 'I should take the tram to Ironforge and visit Greatfather Winter.', 12, 7, 100, 0, 0, 0, 16032, 'Human Commoner to Human Commoner'),
(18927, 8, 6, 'Where are all those wonderful winter hats coming from?', 12, 7, 100, 0, 0, 0, 24342, 'Human Commoner to Human Commoner'),
(18927, 8, 7, 'I should take the tram to Ironforge and visit Greatfather Winter.', 12, 7, 100, 396, 0, 0, 16032, 'Human Commoner to Human Commoner'),
(19171, 8, 0, 'The goblins of Smokywood Pastures always have such wonderful treats for sale this time of year.', 12, 7, 100, 0, 0, 0, 24341, 'Draenei Commoner to Draenei Commoner'),
(19171, 8, 1, 'Where are all those wonderful winter hats coming from?', 12, 7, 100, 0, 0, 0, 24342, 'Draenei Commoner to Draenei Commoner'),
(19171, 8, 2, 'Greatfather Winter will leave presents for everyone under the tree in Ironforge. I can''t wait to get mine!', 12, 7, 100, 0, 0, 0, 16422, 'Draenei Commoner to Draenei Commoner'),
(19171, 8, 3, 'It is my understanding that the people of the Alliance celebrate this Winter Veil in Ironforge.', 12, 7, 100, 0, 0, 0, 16161, 'Draenei Commoner to Draenei Commoner'),
(19175, 8, 0, 'Though we do not truly understand the traditions of Winter Veil, we have taken to them.', 12, 1, 100, 0, 0, 0, 16164, 'Orc Commoner to Orc Commoner'),
(19175, 8, 1, 'I hope I have a chance to visit with Greatfather Winter before Winter Veil is over.', 12, 1, 100, 0, 0, 0, 24323, 'Orc Commoner to Orc Commoner'),
(19175, 8, 2, 'I hope I have a chance to visit with Greatfather Winter before Winter Veil is over.', 12, 1, 100, 6, 0, 0, 24323, 'Orc Commoner to Orc Commoner'),
(19177, 8, 0, 'I hope I have a chance to visit with Greatfather Winter before Winter Veil is over.', 12, 1, 100, 0, 0, 0, 24323, 'Troll Commoner to Troll Commoner'),
(19177, 8, 1, 'Greatfather Winter will leave presents for everyone under the tree in Orgrimmar. I wonder what he''ll bring me this year.', 12, 1, 100, 0, 0, 0, 16464, 'Troll Commoner to Troll Commoner'),
(19177, 8, 2, 'The goblins of Smokywood Pastures always have such wonderful treats for sale this time of year.', 12, 1, 100, 0, 0, 0, 24324, 'Troll Commoner to Troll Commoner'),
(15746, 8, 0, 'Presents for everyone! Father Winter''s put gifts under the tree for all.', 14, 0, 100, 0, 0, 0, 11430, 'Great-father Winter''s Helper'),
(19173, 8, 0, 'It feels like everyone wants to kiss me under the mistletoe.', 12, 7, 100, 0, 0, 0, 16158, 'Night Elf Commoner to Night Elf Commoner'),
(19173, 8, 1, 'It feels like everyone wants to kiss me under the mistletoe.', 12, 7, 100, 396, 0, 0, 16158, 'Night Elf Commoner to Night Elf Commoner'),
(19173, 8, 2, 'Where are all those wonderful winter hats coming from?', 12, 7, 100, 0, 0, 0, 24342, 'Night Elf Commoner to Night Elf Commoner'),
(19173, 8, 3, 'Greatfather Winter will leave presents for everyone under the tree in Ironforge. I can''t wait to get mine!', 12, 7, 100, 6, 0, 0, 16422, 'Night Elf Commoner to Night Elf Commoner'),
(19173, 8, 4, 'I hope I have a chance to visit with Greatfather Winter before Winter Veil is over.', 12, 7, 100, 0, 0, 0, 0, 'Night Elf Commoner to Night Elf Commoner'),
(19172, 8, 0, 'Greatfather Winter will leave presents for everyone under the tree in Ironforge. I can''t wait to get mine!', 12, 7, 100, 0, 0, 0, 16422, 'Gnome Commoner to Gnome Commoner'),
(19172, 8, 1, 'I hope I have a chance to visit with Greatfather Winter before Winter Veil is over.', 12, 7, 100, 0, 0, 0, 24340, 'Gnome Commoner to Gnome Commoner'),
(19172, 8, 2, 'How embarrassing! Someone mistook me for one of Greatfather Winter''s helpers.', 12, 7, 100, 0, 0, 0, 016204, 'Gnome Commoner to Gnome Commoner'),
(19172, 8, 3, 'I hope I have a chance to visit with Greatfather Winter before Winter Veil is over.', 12, 7, 100, 273, 0, 0, 24340, 'Gnome Commoner to Gnome Commoner'),
(19172, 8, 4, 'Where are all those wonderful winter hats coming from?', 12, 7, 100, 0, 0, 0, 24342, 'Gnome Commoner to Gnome Commoner'),
(19176, 8, 0, 'I hope I have a chance to visit with Greatfather Winter before Winter Veil is over.', 12, 1, 100, 0, 0, 0, 24323, 'Tauren Commoner to Tauren Commoner'),
(19176, 8, 1, 'Greatfather Winter will leave presents for everyone under the tree in Orgrimmar. I wonder what he''ll bring me this year.', 12, 1, 100, 0, 0, 0, 16464, 'Tauren Commoner to Tauren Commoner'),
(19176, 8, 2, 'The goblins of Smokywood Pastures always have such wonderful treats for sale this time of year.', 12, 1, 100, 0, 0, 0, 24324, 'Tauren Commoner to Tauren Commoner'),
(19176, 8, 3, 'Greatfather Winter is only a wyvern''s ride away to Orgrimmar.', 12, 1, 100, 0, 0, 0, 16170, 'Tauren Commoner to Tauren Commoner'),
(19148, 8, 0, 'The goblins of Smokywood Pastures always have such wonderful treats for sale this time of year.', 12, 7, 100, 0, 0, 0, 24341, 'Dwarf Commoner to Dwarf Commoner'),
(19148, 8, 1, 'Where are all those wonderful winter hats coming from?', 12, 7, 100, 274, 0, 0, 24342, 'Dwarf Commoner to Dwarf Commoner'),
(19148, 8, 2, 'I hope I have a chance to visit with Greatfather Winter before Winter Veil is over.', 12, 7, 100, 0, 0, 0, 24340, 'Dwarf Commoner to Dwarf Commoner'),
(19148, 8, 3, 'The goblins of Smokywood Pastures always have such wonderful treats for sale this time of year.', 12, 7, 100, 0, 0, 0, 24341, 'Dwarf Commoner to Dwarf Commoner');


UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry`IN(19148,15746,19173);
DELETE FROM `smart_scripts` WHERE `entryorguid`=15746  AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(18927,19171,19175,19177,19173,19172,19176,19148)  AND `source_type`=0 AND  `id`=8;
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(18927,19171,19175,19177,19173,19172,19176,19148,19148,19173)  AND `source_type`=0 AND  `id`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES

(18927,0,8,0,1,0,100,0,3000,15000,45000,90000,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Human Commoner - OOC - Say'),
(19171,0,8,0,1,0,100,0,3000,15000,45000,90000,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dreani Commoner - OOC - Say'),
(19175,0,8,0,1,0,100,0,3000,15000,45000,90000,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Orc Commoner - OOC - Say'),
(19177,0,8,0,1,0,100,0,3000,15000,45000,90000,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Troll Commoner - OOC - Say'),
(19173,0,8,0,1,0,100,0,3000,15000,45000,90000,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Night Elf Commoner - OOC - Say'),
(19172,0,8,0,1,0,100,0,3000,15000,45000,90000,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gnome Commoner - OOC - Say'),
(19176,0,8,0,1,0,100,0,3000,15000,45000,90000,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tauren Commoner - OOC - Say'),
(19148,0,8,0,1,0,100,0,3000,15000,45000,90000,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dwarf Commoner - OOC - Say'),
(15746,0,0,0,1,0,100,0,3000,15000,600000,600000,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Great-father Winter''s Helper - OOC - Say'),

(18927,0,9,0,64,0,100,0,0,0,0,0,98,7862, 9626,0,0,0,0,7,0,0,0,0,0,0,0,'Human Commoner - On Gossip Hello - Send Gossip Menu'),
(19148,0,9,0,64,0,100,0,0,0,0,0,98,7907, 9686,0,0,0,0,7,0,0,0,0,0,0,0,'Dwarf Commoner - On Gossip Hello - Send Gossip Menu'),
(19169,0,9,0,64,0,100,0,0,0,0,0,98,7911, 9698,0,0,0,0,7,0,0,0,0,0,0,0,'Blood Elf Commoner - On Gossip Hello - Send Gossip Menu'),
(19171,0,9,0,64,0,100,0,0,0,0,0,98,7910, 9694,0,0,0,0,7,0,0,0,0,0,0,0,'Draeni Commoner - On Gossip Hello - Send Gossip Menu'),
(19172,0,9,0,64,0,100,0,0,0,0,0,98,7929, 9717,0,0,0,0,7,0,0,0,0,0,0,0,'Gnome Commoner - On Gossip Hello - Send Gossip Menu'),
(19173,0,9,0,64,0,100,0,0,0,0,0,98,7909, 9690,0,0,0,0,7,0,0,0,0,0,0,0,'Night Elf Commoner - On Gossip Hello - Send Gossip Menu'),
(19175,0,9,0,64,0,100,0,0,0,0,0,98,7912, 9702,0,0,0,0,7,0,0,0,0,0,0,0,'Orc Commoner - On Gossip Hello - Send Gossip Menu'),
(19176,0,9,0,64,0,100,0,0,0,0,0,98,7913, 9706,0,0,0,0,7,0,0,0,0,0,0,0,'Tauren Commoner - On Gossip Hello - Send Gossip Menu'),
(19177,0,9,0,64,0,100,0,0,0,0,0,98,7933, 9718,0,0,0,0,7,0,0,0,0,0,0,0,'Troll Commoner - On Gossip Hello - Send Gossip Menu'),
(19178,0,9,0,64,0,100,0,0,0,0,0,98,7914, 9710,0,0,0,0,7,0,0,0,0,0,0,0,'Forsaken Commoner - On Gossip Hello - Send Gossip Menu');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` in(18927,19171,19175,19177,19173,19172,19176,19148) AND `SourceGroup`=9;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` in(18927,19171,19175,19177,19173,19172,19176,19148,19148,19173) AND `SourceGroup`=10;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` =15746;

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 9, 18927, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 9, 19171, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 9, 19175, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 9, 19177, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 9, 19173, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 9, 19172, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 9, 19176, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 9, 19148, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 1, 15746, 0, 0, 12, 1, 52, 0, 0, 0, 0, 0, '', 'Great-father Winter''s Helper - Winter Veil: Gifts must be active'),
(22, 10, 18927, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 10, 19148, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 10, 19169, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 10, 19171, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 10, 19172, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 10, 19173, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 10, 19175, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 10, 19176, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 10, 19177, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active'),
(22, 10, 19178, 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, '', 'Commoner - Winterveil must be active');

DELETE FROM `gossip_menu` WHERE `entry` IN(7929,7913,7912,7909,7862,7907,7911,7914,7933,7910);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES 
(7929, 9717), -- 19172
(7913, 9706), -- 19176
(7912, 9702), -- 19175
(7909, 9690), -- 19173
(7862, 9626), -- 18927
(7907, 9686), -- 19148
(7911, 9698), -- 19169
(7914, 9710), -- 19178
(7933, 9718), -- 19177
(7910, 9694); -- 19171

