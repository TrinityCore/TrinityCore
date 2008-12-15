DELETE FROM command WHERE name IN ('npc follow','npc unfollow','waterwalk','repairitems');

INSERT INTO command VALUES
('repairitems',2,'Syntax: .repairitems\r\n\r\nRepair all selected player''s items.'),
('npc follow',2,'Syntax: .npc follow\r\n\r\nSelected creature start follow you until death/fight/etc.'),
('npc unfollow',2,'Syntax: .npc unfollow\r\n\r\nSelected creature (non pet) stop follow you.'),
('waterwalk',2,'Syntax: .waterwalk on/off\r\n\r\nSet on/off waterwalk state for selected player or self if no player selected.');

DELETE FROM trinity_string WHERE entry IN (171,172,336,337,338,339,340,341,342,5007,5008);

INSERT INTO trinity_string VALUES
(172,'server console command',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(336,'You repair all %s''s items.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(337,'All your items repaired by %s.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(338,'You set waterwalk mode %s for %s.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(339,'Your waterwalk mode set to %s by %s.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(340,'%s is now following you.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(341,'%s is not following you.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(342,'%s is now not following you.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(810,'You must be in a raid group to enter the instance %s!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(811,'You cannot enter %s while in a ghost mode!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);