DELETE FROM `player_factionchange_spells` WHERE `alliance_id`=60118 AND `horde_id`=60119; -- Black War Bear
DELETE FROM `player_factionchange_spells` WHERE `alliance_id`=59785 AND `horde_id`=59788; -- Black War Mammoth
INSERT INTO `player_factionchange_spells` (`alliance_id`, `horde_id`) VALUES
(60118, 60119), -- Black War Bear
(59785, 59788); -- Black War Mammoth
