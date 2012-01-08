-- Move text used in Svala Sorrowgrave from script_texts to  creature_text
-- Remove old script text for boss_svala.cpp
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1575027 AND -1575015;
DELETE FROM `script_texts` WHERE `entry` IN (-1575003, -1575014);

-- Svala say text
DELETE FROM `creature_text` WHERE `entry`=29281;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(29281,0,0, 'My liege! I have done as you asked, and now beseech you for your blessing!',14,0,0,0,0,13856, 'Svala SAY_DIALOG_WITH_ARTHAS_1');

-- Svala Sorrowgrave say text
DELETE FROM `creature_text` WHERE `entry`=26668;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(26668,0,0, 'The sensation is... beyond my imagining. I am yours to command, my king.',14,0,0,0,0,13857, 'Svala Sorrowgrave SAY_DIALOG_WITH_ARTHAS_2'),
(26668,1,0, 'I will be happy to slaughter them in your name! Come, enemies of the Scourge! I will show you the might of the Lich King!',14,0,0,0,0,13858, 'Svala Sorrowgrave SAY_DIALOG_WITH_ARTHAS_3'),
(26668,2,0, 'I will vanquish your soul!',14,0,0,0,0,13842, 'Svala Sorrowgrave SAY_AGGRO'),
(26668,3,0, 'You were a fool to challenge the power of the Lich King!',14,0,0,0,0,13845, 'Svala Sorrowgrave SAY_SLAY_1'),
(26668,3,1, 'Your will is done, my king.',14,0,0,0,0,13847, 'Svala Sorrowgrave SAY_SLAY_2'),
(26668,3,2, 'Another soul for my master.',14,0,0,0,0,13848, 'Svala Sorrowgrave SAY_SLAY_3'),
(26668,4,0, 'Nooo! I did not come this far... to...',14,0,0,0,0,13855, 'Svala Sorrowgrave SAY_DEATH'),
(26668,5,0, 'Your death approaches.',14,0,0,0,0,13850, 'Svala Sorrowgrave SAY_SACRIFICE_1'),
(26668,5,1, 'Go now to my master.',14,0,0,0,0,13851, 'Svala Sorrowgrave SAY_SACRIFICE_2'),
(26668,5,2, 'Your end is inevitable.',14,0,0,0,0,13852, 'Svala Sorrowgrave SAY_SACRIFICE_3'),
(26668,5,3, 'Yor-guul mak!',14,0,0,0,0,13853, 'Svala Sorrowgrave SAY_SACRIFICE_4'),
(26668,5,4, 'Any last words?',14,0,0,0,0,13854, 'Svala Sorrowgrave SAY_SACRIFICE_5');

-- Image of Arthas say text
DELETE FROM `creature_text` WHERE `entry`=29280;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(29280,0,0, 'Your sacrifice is a testament to your obedience. Indeed you are worthy of this charge. Arise, and forever be known as Svala Sorrowgrave!',14,0,0,0,0,14732, 'Image of Arthas SAY_DIALOG_OF_ARTHAS_1'),
(29280,1,0, 'Your first test awaits you. Destroy our uninvited guests.',14,0,0,0,0,14733, 'Image of Arthas SAY_DIALOG_OF_ARTHAS_2');
