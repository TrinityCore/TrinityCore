DELETE FROM `waypoint_scripts` WHERE `id` BETWEEN 16 AND 18;
-- hmmm?
DELETE FROM `db_script_string` WHERE `entry` IN (2000000107,2000000108);
INSERT INTO `db_script_string` (`entry`,`content_default`) VALUES
(2000000107, 'These aren''t Shango''s tracks.'),
(2000000108, 'These tracks must belong to Shango.');
