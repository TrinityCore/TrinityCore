UPDATE script_texts SET entry=-1609080 WHERE entry=-1609017;
UPDATE script_texts SET entry=-1609081 WHERE entry=-1609018;
UPDATE script_texts SET entry=-1609082 WHERE entry=-1609019;
UPDATE script_texts SET entry=-1609083 WHERE entry=-1609020;
UPDATE script_texts SET entry=-1609084 WHERE entry=-1609021;
UPDATE script_texts SET entry=-1609085 WHERE entry=-1609022;

DELETE FROM script_texts WHERE entry IN (-1609086,-1609087,-1609088);
INSERT INTO `script_texts` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`, `sound`, `type`, `language`, `emote`, `comment`) VALUES
(-1609086,'The Lich King will see his true champion on this day!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,0,0,0,0,'dk_initiate SAY_DUEL_G'),
(-1609087,'You\'re going down!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,0,0,0,0,'dk_initiate SAY_DUEL_H'),
(-1609088,'You don\'t stand a chance, $n', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,0,0,0,0,'dk_initiate SAY_DUEL_I');
