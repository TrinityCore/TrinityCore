DELETE FROM `creature_text` WHERE `entry` IN (14887, 14888, 14889, 14890);
INSERT INTO `creature_text`(`entry`,`groupid`,`text`,`type`,`comment`) VALUES
(14887,0,'The strands of LIFE have been severed! The Dreamers must be avenged!',14,'Ysondre - SAY_YSONDRE_AGGRO'),
(14887,1,'Come forth, ye Dreamers - and claim your vengeance!',14,'Ysondre - SAY_YSONDRE_SUMMON_DRUIDS'),
(14888,0,'I can sense the SHADOW on your hearts. There can be no rest for the wicked!',14,'Lethon - SAY_LETHON_AGGRO'),
(14888,1,'Your wicked souls shall feed my power!',14,'Lethon - SAY_LETHON_DRAW_SPIRIT'),
(14889,0,'Hope is a DISEASE of the soul! This land shall wither and die!',14,'Emeriss - SAY_EMERISS_AGGRO'),
(14889,1,'Taste your world\'s corruption!',14,'Emeriss - SAY_EMERISS_CAST_CORRUPTION'),
(14890,0,'Peace is but a fleeting dream! Let the NIGHTMARE reign!',14,'Taerar - SAY_TAERAR_AGGRO'),
(14890,1,'Children of Madness - I release you upon this world!',14,'Taerar - SAY_TAERAR_SUMMON_SHADE');
