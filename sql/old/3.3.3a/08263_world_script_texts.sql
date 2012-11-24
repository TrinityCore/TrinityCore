-- King Ymiron voice by SnakeIce
DELETE FROM `script_texts` WHERE `npc_entry`=26861;
INSERT INTO `script_texts` (`npc_entry`, `entry`, `content_default`,`sound`,`type`,`language`,`emote`,`comment`) VALUES
(26861,-1575028, 'You invade my home and then dare to challenge me? I will tear the hearts from your chests and offer them as gifts to the death god! Rualg nja gaborr!' ,13609,1,0,0, 'King Ymirom - SAY_AGGRO'),
(26861,-1575029, 'Your death is only the beginning!' ,13614,1,0,0, 'King Ymirom - SAY_SLAY_1'),
(26861,-1575030, 'You have failed your people!' ,13615,1,0,0, 'King Ymirom - SAY_SLAY_2'),
(26861,-1575031, 'There is a reason I am king!' ,13616,1,0,0, 'King Ymirom - SAY_SLAY_3'),
(26861,-1575032, 'Bleed no more!' ,13617,1,0,0, 'King Ymirom - SAY_SLAY_4'),
(26861,-1575033, 'What... awaits me... now?' ,13618,1,0,0, 'King Ymirom - SAY_DEATH'),
(26861,-1575034, 'Bjorn of the Black Storm! Honor me now with your presence!' ,13610,1,0,0, 'King Ymirom - SAY_SUMMON_BJORN'),
(26861,-1575035, 'Haldor of the Rocky Cliffs, grant me your strength!' ,13611,1,0,0, 'King Ymirom - SAY_SUMMON_HALDOR'),
(26861,-1575036, 'Ranulf of the Screaming Abyss, snuff these maggots with darkest night! ' ,13612,1,0,0, 'King Ymirom - SAY_SUMMON_RANULF'),
(26861,-1575037, 'Tor of the Brutal Siege! Bestow your might upon me!' ,13613,1,0,0, 'King Ymirom - SAY_SUMMON_TORGYN');
