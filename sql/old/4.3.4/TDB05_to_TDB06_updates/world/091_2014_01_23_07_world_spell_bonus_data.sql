-- Living Ruby Pendant (item 24110) shouldn't get SP bonuses
DELETE FROM `spell_bonus_data` WHERE `entry`=31024;
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES (31024,0,0,0,0,'Living ruby pendant should not get bonuses');
