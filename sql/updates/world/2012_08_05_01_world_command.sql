DELETE FROM `command` WHERE `name` IN (
'disable add quest','disable add map','disable add battleground','disable add achievement_criteria','disable add spell','disable add outdoorpvp','disable add vmap',
'disable remove quest','disable remove map','disable remove battleground','disable remove achievement_criteria','disable remove spell','disable remove outdoorpvp','disable remove vmap'
);
INSERT INTO `command` (`name`,`security`,`help`) VALUES
('disable add quest',3,'Syntax: .disable add quest $entry $flag $comment'),
('disable add map',3,'Syntax: .disable add map $entry $flag $comment'),
('disable add battleground',3,'Syntax: .disable add battleground $entry $flag $comment'),
('disable add achievement_criteria',3,'Syntax: .disable add achievement_criteria $entry $flag $comment'),
('disable add spell',3,'Syntax: .disable add spell $entry $flag $comment'),
('disable add outdoorpvp',3,'Syntax: .disable add outdoorpvp $entry $flag $comment'),
('disable add vmap',3,'Syntax: .disable add vmap $entry $flag $comment'),
('disable remove quest',3,'Syntax: .disable remove quest $entry'),
('disable remove map',3,'Syntax: .disable remove map $entry'),
('disable remove battleground',3,'Syntax: .disable remove battleground $entry'),
('disable remove achievement_criteria',3,'Syntax: .disable remove achievement_criteria $entry'),
('disable remove spell',3,'Syntax: .disable remove spell $entry'),
('disable remove outdoorpvp',3,'Syntax: .disable remove outdoorpvp $entry'),
('disable remove vmap',3,'Syntax: .disable remove vmap $entry');
