-- Creature text for Wrath-Scryer Soccothrates
SET @ENTRY = 20886;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY, 0, 0, 'Have you come to kill Dalliah? Can I watch?',     14, 0, 100, 0, 0, 11237, 'Wrath-Scryer Soccothrates - OCC'),
(@ENTRY, 1, 0, 'At last, a target for my frustrations!',          14, 0, 100, 0, 0, 11238, 'Wrath-Scryer Soccothrates - Aggro'),
(@ENTRY, 2, 0, 'Yes, that was quite satisfying',                  14, 0, 100, 0, 0, 11239, 'Wrath-Scryer Soccothrates - Kill'),
(@ENTRY, 3, 0, 'On guard!',                                       14, 0, 100, 0, 0, 11241, 'Wrath-Scryer Soccothrates - Charge'),
(@ENTRY, 3, 1, 'Defend yourself, for all the good it will do...', 14, 0, 100, 0, 0, 11242, 'Wrath-Scryer Soccothrates - Charge'),
(@ENTRY, 4, 0, 'Knew this was... the only way out',               14, 0, 100, 0, 0, 11243, 'Wrath-Scryer Soccothrates - Death');
