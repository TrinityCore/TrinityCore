DELETE FROM `script_texts` WHERE `entry` IN (-1574000,-1574001,-1574002,-1574003,-1574004);

DELETE FROM `creature_text` WHERE `entry`=23953;
INSERT INTO `creature_text` (`entry`, `groupid`, `text`, `sound`, `emote`, `type`) VALUES 
(23953,1,'Your blood is mine!',13221,7,14),
(23953,2,'Aranal, ledel! Their fate shall be yours!',13224,0,14),
(23953,3,'Not so fast.',13222,0,14),
(23953,4,'%s casts Frost Tomb on $n.',0,0,41),
(23953,5,'I join... the night.',13225,0,14);
