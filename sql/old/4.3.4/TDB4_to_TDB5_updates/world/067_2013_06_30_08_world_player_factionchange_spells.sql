DELETE FROM `player_factionchange_spells` WHERE `alliance_id`=59791 AND `horde_id`=59793;
DELETE FROM `player_factionchange_spells` WHERE `alliance_id`=60114 AND `horde_id`=60116;
INSERT INTO `player_factionchange_spells` (`alliance_id`,`horde_id`) VALUES
(59791, 59793), -- Wooly Mammoth
(60114, 60116); -- Armored Brown Bear
