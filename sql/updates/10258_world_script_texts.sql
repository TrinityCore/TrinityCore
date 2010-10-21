UPDATE `script_texts` SET `language`=0 WHERE `entry`='-1000600';
DELETE FROM `script_texts` WHERE `entry` IN (-1619006,-1575021,-1619015,1619016);
INSERT INTO `script_texts` (`npc_entry`, `entry`, `content_default`, `comment`) VALUES
(26668,-1575021,'Another soul for my master.','Svala Sorrowgrave SAY_SLAY_3'),
(29310,-1619006,'You are unworthy!','Jedoga Shadowseeker SAY_SLAY_2'),
(29309,-1619015,'Sleep now, in the cold dark.','Elder Nadox SAY_SLAY_1'),
(29309,-1619016,'For the Lich King!','Elder Nadox SAY_SLAY_2');
