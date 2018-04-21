UPDATE `spell_bonus_data` SET `ap_bonus`=0.15 WHERE `entry`=60089;
DELETE FROM `spell_bonus_data` WHERE `entry`=52042;
INSERT INTO `spell_bonus_data` (`entry`,`direct_bonus`,`dot_bonus`,`ap_bonus`,`ap_dot_bonus`,`comments`) VALUES (52042,-1,-1,-1,-1,'Shaman - Healing Stream Totem Triggered Heal');

DELETE FROM `spell_bonus_data` WHERE `entry` IN (8443,8504,8505,11310,11311,25538,25539,61651,61660);
