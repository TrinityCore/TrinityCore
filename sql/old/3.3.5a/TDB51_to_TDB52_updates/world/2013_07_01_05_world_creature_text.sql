SET @AKAMA           := 23089;
SET @ILLIDAN         := 22917;
SET @FLAMEOFAZZINOTH := 22997;
SET @MAIEV           := 23197;
DELETE FROM `creature_text` WHERE `entry` IN (@AKAMA, @ILLIDAN, @FLAMEOFAZZINOTH, @MAIEV);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@AKAMA,0,0, "Be wary friends, The Betrayer meditates in the court just beyond.",14,0,100,0,0,11388, 'Akama SAY_AKAMA_BEWARE'),
(@AKAMA,1,0, "I'll deal with these mongrels. Strike now, friends! Strike at the betrayer!",14,0,100,0,0,11390, 'Akama SAY_AKAMA_LEAVE'),
(@ILLIDAN,0,0, "Come, my minions. Deal with this traitor as he deserves!",14,0,100,0,0,11465, 'Illidan SAY_ILLIDAN_MINION'),
(@ILLIDAN,1,0, "Who shall be next to taste my blades?!",14,0,100,0,0,11473, 'Illidan SAY_ILLIDAN_KILL'),
(@ILLIDAN,1,1, "This is too easy!",14,0,100,0,0,11472, 'Illidan SAY_ILLIDAN_KILL'),
(@ILLIDAN,2,0, "I will not be touched by rabble such as you!",14,0,100,0,0,11479, 'Illidan SAY_ILLIDAN_TAKEOFF'),
(@ILLIDAN,3,0, "Behold the flames of Azzinoth!",14,0,100,0,0,11480, 'Illidan SAY_ILLIDAN_SUMMONFLAMES'),
(@ILLIDAN,4,0, "Stare into the eyes of the Betrayer!",14,0,100,0,0,11481, 'Illidan SAY_ILLIDAN_EYE_BLAST'),
(@ILLIDAN,5,0, "Behold the power... of the demon within!",14,0,100,0,0,11475, 'Illidan SAY_ILLIDAN_MORPH'),
(@ILLIDAN,6,0, "You've wasted too much time mortals, now you shall fall!",14,0,100,0,0,11474, 'Illidan SAY_ILLIDAN_ENRAGE'),
(@ILLIDAN,7,0, "I can feel your hatred.",14,0,100,0,0,11467, 'Illidan SAY_ILLIDAN_TAUNT'),
(@ILLIDAN,7,1, "Give in to your fear!",14,0,100,0,0,11468, 'Illidan SAY_ILLIDAN_TAUNT'),
(@ILLIDAN,7,2, "You know nothing of power!",14,0,100,0,0,11469, 'Illidan SAY_ILLIDAN_TAUNT'),
(@ILLIDAN,7,3, "Such... arrogance!",14,0,100,0,0,11471, 'Illidan SAY_ILLIDAN_TAUNT'),
(@FLAMEOFAZZINOTH,0,0, "%s sets its gaze on $N!",16,0,100,0,0,0, 'Flame of Azzinoth EMOTE_AZZINOTH_GAZE'),
(@MAIEV,0,0, "That is for Naisha!",14,0,100,0,0,11493, 'Maiev Shadowsong SAY_MAIEV_SHADOWSONG_TAUNT'),
(@MAIEV,0,1, "Bleed as I have bled!",14,0,100,0,0,11494, 'Maiev Shadowsong SAY_MAIEV_SHADOWSONG_TAUNT'),
(@MAIEV,0,2, "There shall be no prison for you this time!",14,0,100,0,0,11495, 'Maiev Shadowsong SAY_MAIEV_SHADOWSONG_TAUNT'),
(@MAIEV,0,3, "Meet your end, demon!",14,0,100,0,0,11500, 'Maiev Shadowsong SAY_MAIEV_SHADOWSONG_TAUNT');

-- The time has come to face Illidan, $N.  Are you ready?
UPDATE `creature_template` SET `gossip_menu_id`=8713 WHERE `entry`=23089;
DELETE FROM `gossip_menu` WHERE `entry`=8713 AND `text_id`=10960;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (8713, 10960);
DELETE FROM `gossip_menu_option` WHERE `menu_id`=8713 AND `id`=0;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`,`option_icon`,`option_text`,`box_coded`,`box_money`,`box_text`) VALUES
(8713, 0, 0, 'I''m ready, Akama.', 0, 0, '');
