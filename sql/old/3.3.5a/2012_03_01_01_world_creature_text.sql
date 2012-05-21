-- NPC talk text insert from sniff
DELETE FROM `script_texts` WHERE `npc_entry`=28586;
DELETE FROM `creature_text` WHERE `entry`=28586;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(28586,0,0, 'I am the greatest of my father''s sons! Your end has come!',14,0,100,0,0,14149, 'General Bjarngrim'),
(28586,1,0, 'Give me your worst!',14,0,100,0,0,14150, 'General Bjarngrim'),
(28586,2,0, 'Defend yourself, for all the good it will do!',14,0,100,0,0,14151, 'General Bjarngrim'),
(28586,3,0, 'GRAAAAAH! Behold the fury of iron and steel!',14,0,100,0,0,14152, 'General Bjarngrim'),
(28586,4,0, 'So ends your curse!',14,0,100,0,0,14153, 'General Bjarngrim'),
(28586,4,1, 'Flesh... is... weak!',14,0,100,0,0,14154, 'General Bjarngrim'),
(28586,4,2, '...',14,0,100,0,0,14155, 'General Bjarngrim'),
(28586,5,0, 'How can it be...? Flesh is not... stronger!',14,0,100,0,0,14156, 'General Bjarngrim'),
(28586,6,0, '%s switches to Defensive Stance!',41,0,100,0,0,0, 'General Bjarngrim'),
(28586,7,0, '%s switches to Battle Stance!',41,0,100,0,0,0, 'General Bjarngrim'),
(28586,8,0, '%s switches to Berserker Stance!',41,0,100,0,0,0, 'General Bjarngrim');
