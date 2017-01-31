-- Missing Image of Arthas say text
DELETE FROM `creature_text` WHERE `entry`=29280;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(29280,0,0, 'Your sacrifice is a testament to your obedience. Indeed you are worthy of this charge. Arise, and forever be known as Svala Sorrowgrave!',14,0,0,0,0,14732, 'Image of Arthas SAY_DIALOG_OF_ARTHAS_1'),
(29280,1,0, 'Your first test awaits you. Destroy our uninvited guests.',14,0,0,0,0,14733, 'Image of Arthas SAY_DIALOG_OF_ARTHAS_2');
