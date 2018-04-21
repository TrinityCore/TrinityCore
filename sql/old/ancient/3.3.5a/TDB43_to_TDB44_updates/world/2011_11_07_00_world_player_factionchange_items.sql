DELETE FROM `player_factionchange_items` WHERE `alliance_id` IN (48072,48073,48074,48075,48076) AND horde_id IN (48097,48098,48099,48100,48101);
INSERT INTO `player_factionchange_items` (`race_A`,`alliance_id`,`commentA`,`race_H`,`horde_id`,`commentH`) VALUES
(0,48076, 'Velen''s Mantle of Conquest',0,48101, 'Zabra''s Mantle of Conquest'),
(0,48075, 'Velen''s Raiments of Conquest',0,48100, 'Zabra''s Raiments of Conquest'),
(0,48074, 'Velen''s Pants of Conquest',0,48099, 'Zabra''s Pants of Conquest'),
(0,48072, 'Velen''s Handwraps of Conquest',0,48097, 'Zabra''s Handwraps of Conquest'),
(0,48073, 'Velen''s Circlet of Conquest',0,48098, 'Zabra''s Circlet of Conquest');
