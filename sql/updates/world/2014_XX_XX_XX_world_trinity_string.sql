/* new trinity_strings */
DELETE FROM `trinity_string` WHERE `entry` IN(5057,5058,5059);
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
('5057', 'Mutes for account: %s'),
('5058', 'No mutes for account: %s'),
('5059', 'Mute Date: %20s Mutetime: %10u mins. Reason: %s Set by: %s');
