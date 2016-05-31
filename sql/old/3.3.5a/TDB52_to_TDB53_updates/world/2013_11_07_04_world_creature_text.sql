-- Creature text for Mennu the Betrayer
SET @ENTRY = 17941;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY, 0, 0, 'The work must continue.',         14, 0, 100, 0, 0, 10376, 'Mennu the Betrayer - Aggro'),
(@ENTRY, 0, 1, 'You brought this on yourselves.', 14, 0, 100, 0, 0, 10378, 'Mennu the Betrayer - Aggro'),
(@ENTRY, 0, 2, 'Don''t make me kill you!',        14, 0, 100, 0, 0, 10379, 'Mennu the Betrayer - Aggro'),
(@ENTRY, 1, 0, 'It had to be done.',              14, 0, 100, 0, 0, 10380, 'Mennu the Betrayer - Kill'),
(@ENTRY, 1, 1, 'You should not have come.',       14, 0, 100, 0, 0, 10381, 'Mennu the Betrayer - Kill'),
(@ENTRY, 2, 0, 'I... Deserve this.',              14, 0, 100, 0, 0, 10382, 'Mennu the Betrayer - Death');
