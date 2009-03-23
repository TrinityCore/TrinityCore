DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000164 AND -1000174;
INSERT INTO `script_texts` (entry,content_default,sound,type,language,emote,comment) VALUES
(-1000164,'Ah, $GPriest:Priestess; you came along just in time. I appreciate it.',0,0,0,2,'garments SAY_COMMON_HEALED'),
(-1000165,'Thank you! Thank you, $GPriest:Priestess;. Now I can take on those gnolls with your power to back me!',0,0,1,1,'garments SAY_DG_KEL_THANKS'),
(-1000166,'Farewell to you, and may shadow always protect you!',0,0,1,3,'garments SAY_DG_KEL_GOODBYE'),
(-1000167, 'Thank you! Thank you, $GPriest:Priestess;. Now I can take on those murlocs with the Light on my side!',0,0,7,1,'garments SAY_ROBERTS_THANKS'),
(-1000168, 'Farewell to you, and may the Light be with you always.',0,0,7,3,'garments SAY_ROBERTS_GOODBYE'),
(-1000169, 'Thank you! Thank you, $GPriest:Priestess;. Now I can take on those humans with your power to back me!',0,0,1,1,'garments SAY_KORJA_THANKS'),
(-1000170, 'Farewell to you, and may our ancestors be with you always!',0,0,1,3,'garments SAY_KORJA_GOODBYE'),
(-1000171, 'Thank you! Thank you, $GPriest:Priestess;. Now I can take on those wendigo with the Light on my side!',0,0,7,1,'garments SAY_DOLF_THANKS'),
(-1000172, 'Farewell to you, and may the Light be with you always.',0,0,7,3,'garments SAY_DOLF_GOODBYE'),
(-1000173, 'Thank you! Thank you, $GPriest:Priestess;. Now I can take on those corrupt timberlings with Elune\'s power behind me!',0,0,2,1,'garments SAY_SHAYA_THANKS'),
(-1000174, 'Farewell to you, and may Elune be with you always.',0,0,2,3,'garments SAY_SHAYA_GOODBYE');