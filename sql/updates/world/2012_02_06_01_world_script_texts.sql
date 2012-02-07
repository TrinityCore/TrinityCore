DELETE FROM `script_texts` WHERE `entry` IN (-1999926, -1999927, -1999928, -1999929);
INSERT INTO `script_texts` (`entry`, `content_default`, `sound`, `type`, `language`, `emote`, `comment`) VALUES
(-1999926,'Together we will fight our way out of here. Are you ready?',0,0,0,0,'Lurgglbr - SAY_START_1'),
(-1999927,'Then we leave.',0,0,0,0,'Lurgglbr - SAY_START_2'),
(-1999928,'This is far enough. I can make it on my own from here.',0,0,0,0,'Lurgglbr - SAY_END_1'),
(-1999929,'Thank you for helping me $r. Please tell the king I am back.',0,0,0,0,'Lurgglbr - SAY_END_2');
