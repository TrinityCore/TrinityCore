DELETE FROM trinity_string WHERE entry IN (57,58,5009);

INSERT INTO trinity_string VALUES
(57,'Using World DB: %s',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(58,'Using script library: %s',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(5009,'Sound %u Played to server',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);


DELETE FROM `command` WHERE name IN ('pet create','pet learn','pet unlearn','pet tp','gobject activate','playall');
INSERT INTO `command` (name,security,help) VALUES
('pet create',2,'Syntax: .pet create\r\n\r\nCreates a pet of the selected creature.'),
('pet learn',2,'Syntax: .pet learn\r\n\r\nLearn #spellid to pet.'),
('pet unlearn',2,'Syntax: .pet unlean\r\n\r\nunLearn #spellid to pet.'),
('pet tp',2,'Syntax: .pet tp #\r\n\r\nChange pet\'s amount of training points.'),
('modify gender',2,'Syntax: .modify gender\r\n\r\n.modify gender #male/female - Turns selected player into a male or female'),
('gobject activate',2,'Syntax: .gobject activate #guid\r\n\r\nActivates an object like a door or a button.'),
('playall',2,'Syntax: .playall #soundid\r\n\r\nPlayer a sound to whole server.');