-- Creature text for Dalliah the Doomsayer
SET @ENTRY = 20885;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY, 0, 0, 'Don''t worry about me; kill that worthless dullard instead!', 14, 0, 100, 0, 0, 11085, 'Dalliah the Doomsayer - Aggro Soccothrates First'),
(@ENTRY, 1, 0, 'It is unwise to anger me.',                                   14, 0, 100, 0, 0, 11086, 'Dalliah the Doomsayer - Aggro'),
(@ENTRY, 2, 0, 'Completely ineffective. Just like someone else I know.',      14, 0, 100, 0, 0, 11087, 'Dalliah the Doomsayer - Kill'),
(@ENTRY, 2, 1, 'You chose the wrong opponent.',                               14, 0, 100, 0, 0, 11088, 'Dalliah the Doomsayer - Kill'),
(@ENTRY, 3, 0, 'Reap the Whirlwind!',                                         14, 0, 100, 0, 0, 11089, 'Dalliah the Doomsayer - Cast Whirlwind'),
(@ENTRY, 3, 1, 'I''ll cut you to pieces!',                                    14, 0, 100, 0, 0, 11090, 'Dalliah the Doomsayer - Cast Whirlwind'),
(@ENTRY, 4, 0, 'Ahh... That is much better.',                                 14, 0, 100, 0, 0, 11091, 'Dalliah the Doomsayer - Cast Heal'),
(@ENTRY, 4, 1, 'Ahh... Just what I needed.',                                  14, 0, 100, 0, 0, 11092, 'Dalliah the Doomsayer - Cast Heal'),
(@ENTRY, 5, 0, 'Now I''m really... angry...',                                 14, 0, 100, 0, 0, 11093, 'Dalliah the Doomsayer - Death'),
(@ENTRY, 6, 0, 'More than you can handle, scryer?',                           14, 0, 100, 0, 0, 11094, 'Dalliah the Doomsayer - Soccothrates at 25%'),
(@ENTRY, 6, 1, 'I suppose I''ll end up fighting them all myself.',            14, 0, 100, 0, 0, 11095, 'Dalliah the Doomsayer - Soccothrates at 25%'),
(@ENTRY, 6, 2, 'I''ve grown used to cleaning up your messes.',                14, 0, 100, 0, 0, 11096, 'Dalliah the Doomsayer - Soccothrates at 25%'),
(@ENTRY, 7, 0, 'Congratulations. I''ve wanted to do that for years.',         14, 0, 100, 0, 0, 11097, 'Dalliah the Doomsayer - Soccothratess dies');

-- Creature text for Wrath-Scryer Soccothrates
SET @ENTRY = 20886;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY, 0, 0, 'Have you come to kill Dalliah? Can I watch?',                                             14, 0, 100, 0, 0, 11237, 'Wrath-Scryer Soccothrates - Aggro Dalliah First'),
(@ENTRY, 1, 0, 'At last, a target for my frustrations!',                                                  14, 0, 100, 0, 0, 11238, 'Wrath-Scryer Soccothrates - Aggro'),
(@ENTRY, 2, 0, 'Yes, that was quite satisfying',                                                          14, 0, 100, 0, 0, 11239, 'Wrath-Scryer Soccothrates - Kill'),
(@ENTRY, 3, 0, 'On guard!',                                                                               14, 0, 100, 0, 0, 11241, 'Wrath-Scryer Soccothrates - Charge'),
(@ENTRY, 3, 1, 'Defend yourself, for all the good it will do...',                                         14, 0, 100, 0, 0, 11242, 'Wrath-Scryer Soccothrates - Charge'),
(@ENTRY, 4, 0, 'Knew this was... the only way out',                                                       14, 0, 100, 0, 0, 11243, 'Wrath-Scryer Soccothrates - Death'),
(@ENTRY, 5, 0, 'Having problems, Dalliah? How nice.',                                                     14, 0, 100, 0, 0, 11244, 'Wrath-Scryer Soccothrates - Dalliah at 25%'),
(@ENTRY, 5, 1, 'This may be the end of you Dalliah, what a shame that would be.',                         14, 0, 100, 0, 0, 11245, 'Wrath-Scryer Soccothrates - Dalliah at 25%'),
(@ENTRY, 5, 2, 'I suggest a new strategy, you draw the attackers while I gather reinforcements. Hahaha!', 14, 0, 100, 0, 0, 11246, 'Wrath-Scryer Soccothrates - Dalliah at 25%'),
(@ENTRY, 6, 0, 'Finally! Well done!',                                                                     14, 0, 100, 0, 0, 11247, 'Wrath-Scryer Soccothrates - Dalliah dies');
