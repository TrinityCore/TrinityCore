UPDATE `script_texts` SET `entry`=`entry`+20 WHERE `entry` IN(-1574001,-1574002,-1574003,-1574004,);
UPDATE `script_texts` SET `entry`=-1574001 WHERE `entry`=-1574023;
UPDATE `script_texts` SET `entry`=-1574002 WHERE `entry`=-1574024;
UPDATE `script_texts` SET `entry`=-1574003 WHERE `entry`=-1574021;
UPDATE `script_texts` SET `entry`=-1574004 WHERE `entry`=-1574022;

INSERT INTO `script_texts` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`, `sound`, `type`, `language`, `emote`, `comment`) VALUES
(-1574005,'I\'ll paint my face with your blood!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,13207,1,0,0,'ingvar SAY_AGGRO_FIRST'),
(-1574006,'I return! A second chance to carve out your skull!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,13209,1,0,0,'ingvar SAY_AGGRO_SECOND'),
(-1574007,'My life for the... death god!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,13213,1,0,0,'ingvar SAY_DEATH_FIRST'),
(-1574008,'No! I can do... better! I can...', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,13211,1,0,0,'ingvar SAY_DEATH_SECOND'),
(-1574009,'Mjul orm agn gjor!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,13212,1,0,0,'ingvar SAY_KILL_FIRST'),
(-1574010,'I am a warrior born!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,13214,1,0,0,'ingvar SAY_KILL_SECOND'),
(-1574011,'Dalronn! See if you can muster the nerve to join my attack!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,13229,1,0,0,'skarvald YELL_SKARVALD_AGGRO'),
(-1574012,'Not... over... yet.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,13230,1,0,0,'skarvald YELL_SKARVALD_DAL_DIED'),
(-1574013,'A warrior\'s death.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,13231,1,0,0,'skarvald YELL_SKARVALD_SKA_DIEDFIRST'),
(-1574014,'???', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,13232,1,0,0,'skarvald YELL_SKARVALD_KILL'),
(-1574015,'Pagh! What sort of necromancer lets death stop him? I knew you were worthless!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,13233,1,0,0,'skarvald YELL_SKARVALD_DAL_DIEDFIRST'),
(-1574016,'By all means, don\'t assess the situation, you halfwit! Just jump into the fray!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,13199,1,0,0,'dalronn YELL_DALRONN_AGGRO'),
(-1574017,'See... you... soon.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,13200,1,0,0,'dalronn YELL_DALRONN_SKA_DIED'),
(-1574018,'There\'s no... greater... glory.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,13201,1,0,0,'dalronn YELL_DALRONN_DAL_DIEDFIRST'),
(-1574019,'You may serve me yet.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,13202,1,0,0,'dalronn YELL_DALRONN_KILL'),
(-1574020,'Skarvald, you incompetent slug! Return and make yourself useful!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,13203,1,0,0,'dalronn YELL_DALRONN_SKA_DIEDFIRST');
