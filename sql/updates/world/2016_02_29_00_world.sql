-- creature text 23576 Nalorakk + sound ID + broadcast_text ID
DELETE FROM `creature_text` WHERE `entry` = 23576 AND `type` = 14;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(23576,  0,0, "Get da move on, guards! It be killin' time!",                                                             14,0,100,0,0, 12066, 22144, 1, 'Nalorakk - YELL_NALORAKK_WAVE1'),
(23576,  1,0, "Guards, go already! Who you more afraid of, dem... or me?",                                               14,0,100,0,0, 12067, 22146, 1, 'Nalorakk - YELL_NALORAKK_WAVE2'),
(23576,  2,0, "Ride now! Ride out dere and bring me back some heads!",                                                   14,0,100,0,0, 12068, 22151, 1, 'Nalorakk - YELL_NALORAKK_WAVE3'),
(23576,  3,0, "I be losin' me patience! Go on: make dem wish dey was never born!",                                       14,0,100,0,0, 12069, 22155, 1, 'Nalorakk - YELL_NALORAKK_WAVE4'),
(23576,  4,0, "You be dead soon enough!",                                                                                14,0,100,0,0, 12070, 23166, 1, 'Nalorakk - YELL_AGGRO'),
(23576,  5,0, "I bring da pain!",                                                                                        14,0,100,0,0, 12071, 23167, 1, 'Nalorakk - YELL_SURGE'),
(23576,  6,0, "You call on da beast, you gonna get more dan you bargain for!",                                           14,0,100,0,0, 12072, 23168, 1, 'Nalorakk - YELL_SHIFTEDTOBEAR '),
(23576,  7,0, "Make way for da Nalorakk!",                                                                               14,0,100,0,0, 12073, 23169, 1, 'Nalorakk - YELL_SHIFTEDTOTROLL'),
(23576,  8,0, "You had your chance; now it be too late!",                                                                14,0,100,0,0, 12074, 23170, 1, 'Nalorakk - YELL_BERSERK'),
(23576,  9,0, "Now whatchoo got to say?",                                                                                14,0,100,0,0, 12075, 23171, 1, 'Nalorakk - YELL_KILL_ONE'),
(23576, 10,0, "Da Amani gonna rule again!",                                                                              14,0,100,0,0, 12076, 23172, 1, 'Nalorakk - YELL_KILL_TWO'),
(23576, 11,0, "I... be waitin' on da udda side....",                                                                     14,0,100,0,0, 12077, 23173, 1, 'Nalorakk - YELL_DEATH'),
(23576, 12,0, "What could be better than servin' da bear spirit for eternity? Come closer now. Bring your souls to me!", 14,0,100,0,0, 12078, 23305, 1, 'Nalorakk - YELL_NALORAKK_EVENT1'),
(23576, 13,0, "I smell you, strangers. Don't be delayin' your fate. Come to me now. I make your sacrifice quick.",       14,0,100,0,0, 12079, 23306, 1, 'Nalorakk - YELL_NALORAKK_EVENT1');

-- creature text 24239 Hex Lord Malacrass + sound ID + broadcast_text ID
DELETE FROM `creature_text` WHERE `entry` = 24239 AND `type` = 14;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(24239, 0,0, "Da shadow gonna fall on you....",       14,0,100,0,0, 12041, 23591, 1, 'Hex Lord Malacrass - YELL_AGGRO'),
(24239, 1,0, "Dis a nightmare ya don' wake up from!", 14,0,100,0,0, 12043, 23593, 1, 'Hex Lord Malacrass - YELL_KILL_ONE'),
(24239, 2,0, "Azzaga choogo zinn!",                   14,0,100,0,0, 12044, 23594, 1, 'Hex Lord Malacrass - YELL_KILL_TWO'),
(24239, 3,0, "Darkness comin' for you....",           14,0,100,0,0, 12046, 23596, 1, 'Hex Lord Malacrass - YELL_DRAIN_POWER'),
(24239, 4,0, "Your soul gonna bleed!",                14,0,100,0,0, 12047, 23597, 1, 'Hex Lord Malacrass - YELL_SPIRIT_BOLTS'),
(24239, 5,0, "Dis not... da end for me!",             14,0,100,0,0, 12051, 23601, 1, 'Hex Lord Malacrass - YELL_DEATH');
