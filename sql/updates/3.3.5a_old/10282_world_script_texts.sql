UPDATE `script_texts` SET `language`=0 WHERE `entry`='-1000600';
DELETE FROM `script_texts` WHERE `entry` IN (-1619006,-1575021,-1619015,-1619016);
INSERT INTO `script_texts` (`npc_entry`, `entry`, `content_default`, `comment`) VALUES
(26668,-1575021,'Another soul for my master.','Svala Sorrowgrave SAY_SLAY_3'),
(29310,-1619006,'You are unworthy!','Jedoga Shadowseeker SAY_SLAY_2'),
(29309,-1619015,'Sleep now, in the cold dark.','Elder Nadox SAY_SLAY_1'),
(29309,-1619016,'For the Lich King!','Elder Nadox SAY_SLAY_2');

DELETE FROM `script_texts` WHERE `entry` IN (-1000637,-1000638,-1000639,-1000640);
INSERT INTO `script_texts` (`npc_entry`, `entry`, `content_default`, `comment`) VALUES 
('17807', '-1000637', 'Let the trial begin, Bloodwrath, attack!', 'npc_second_trial_controller TEXT_SECOND_TRIAL_1'),
('17807', '-1000638', 'Champion Lightrend, make me proud!', 'npc_second_trial_controller TEXT_SECOND_TRIAL_2'),
('17807', '-1000639', 'Show this upstart how a real Blood Knight fights, Swiftblade!', 'npc_second_trial_controller TEXT_SECOND_TRIAL_3'),
('17807', '-1000640', 'Show $n the meaning of pain, Sunstriker!', 'npc_second_trial_controller TEXT_SECOND_TRIAL_4');
