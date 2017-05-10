-- ----------------------------------
-- Creature text conversion part 2 --
-- ----------------------------------
-- razorgore
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1469025 AND -1469022;
DELETE FROM `creature_text` WHERE `entry`=12435;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(12435,0,0,14,8275,100,"razorgore SAY_EGGS_BROKEN1","You'll pay for forcing me to do this."),
(12435,1,0,14,8276,100,"razorgore SAY_EGGS_BROKEN2","Fools! These eggs are more precious than you know."),
(12435,2,0,14,8277,100,"razorgore SAY_EGGS_BROKEN3","No! Not another one! I'll have your heads for this atrocity."),
(12435,3,0,14,8278,100,"razorgore SAY_DEATH","If I fall into the abyss I'll take all of you mortals with me...");

-- nefarian
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1469021 AND -1469007;
DELETE FROM `creature_text` WHERE `entry`=11583;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(11583,0,0,14,8288,100,"nefarian SAY_AGGRO","Well done, my minions. The mortals' courage begins to wane! Now, let's see how they contend with the true Lord of Blackrock Spire!"),
(11583,0,1,14,8289,100,"nefarian SAY_XHEALTH","Enough! Now you vermin shall feel the force of my birthright, the fury of the earth itself."),
(11583,0,2,14,8290,100,"nefarian SAY_SHADOWFLAME","Burn, you wretches! Burn!"),
(11583,1,0,14,8291,100,"nefarian SAY_RAISE_SKELETONS","Impossible! Rise my minions! Serve your master once more!"),
(11583,2,0,14,8293,100,"nefarian SAY_SLAY","Worthless $N! Your friends will join you soon enough!"),
(11583,3,0,14,8292,100,"nefarian SAY_DEATH","This cannot be! I am the Master here! You mortals are nothing to my kind! DO YOU HEAR? NOTHING!"),
(11583,4,0,14,0,100,"nefarian SAY_MAGE","Mages too? You should be more careful when you play with magic..."),
(11583,5,0,14,0,100,"nefarian SAY_WARRIOR","Warriors, I know you can hit harder than that! Let's see it!"),
(11583,6,0,14,0,100,"nefarian SAY_DRUID","Druids and your silly shapeshifting. Let's see it in action!"),
(11583,7,0,14,0,100,"nefarian SAY_PRIEST","Priests! If you're going to keep healing like that, we might as well make it a little more interesting!"),
(11583,8,0,14,0,100,"nefarian SAY_PALADIN","Paladins, I've heard you have many lives. Show me."),
(11583,9,0,14,0,100,"nefarian SAY_SHAMAN","Shamans, show me what your totems can do!"),
(11583,10,0,14,0,100,"nefarian SAY_WARLOCK","Warlocks, you shouldn't be playing with magic you don't understand. See what happens?"),
(11583,11,0,14,0,100,"nefarian SAY_HUNTER","Hunters and your annoying pea-shooters!"),
(11583,12,0,14,0,100,"nefarian SAY_ROGUE","Rogues? Stop hiding and face me!");

-- broodlord
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1469001 AND -1469000;
DELETE FROM `creature_text` WHERE `entry`=12017;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(12017,0,0,14,8286,100,"broodlord SAY_AGGRO","None of your kind should be here! You've doomed only yourselves!"),
(12017,1,0,14,8287,100,"broodlord SAY_LEASH","Clever Mortals but I am not so easily lured away from my sanctum!");

-- flamegor
DELETE FROM `script_texts` WHERE `entry`=-1469031;
DELETE FROM `creature_text` WHERE `entry`=11981;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(11981,0,0,16,0,100,"flamegor EMOTE_FRENZY","%s goes into a frenzy!");

-- chromaggus
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1469003 AND -1469002;
DELETE FROM `creature_text` WHERE `entry`=14020;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(14020,0,0,16,0,100,"chromaggus EMOTE_FRENZY","goes into a killing frenzy!"),
(14020,1,0,16,0,100,"chromaggus EMOTE_SHIMMER","flinches as its skin shimmers.");

-- vaelastrasz
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1469030 AND -1469026;
DELETE FROM `creature_text` WHERE `entry`=13020;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(13020,0,0,14,8281,100,"vaelastrasz SAY_LINE1","Too late...friends. Nefarius' corruption has taken hold. I cannot...control myself."),
(13020,1,0,14,8282,100,"vaelastrasz SAY_LINE2","I beg you Mortals, flee! Flee before I lose all control. The Black Fire rages within my heart. I must release it!"),
(13020,2,0,14,8283,100,"vaelastrasz SAY_LINE3","FLAME! DEATH! DESTRUCTION! COWER MORTALS BEFORE THE WRATH OF LORD....NO! I MUST FIGHT THIS!"),
(13020,3,0,14,8285,100,"vaelastrasz SAY_HALFLIFE","Nefarius' hate has made me stronger than ever before. You should have fled, while you could, mortals! The fury of Blackrock courses through my veins!"),
(13020,4,0,14,8284,100,"vaelastrasz SAY_KILLTARGET","Forgive me $N, your death only adds to my failure.");

-- doctor theolen krastinov
-- No delete query here, it's a generic script text for frenzy emotes.
DELETE FROM `creature_text` WHERE `entry`=11261;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(11261,0,0,16,0,100,"doctor theolen krastinov EMOTE_FRENZY_KILL","%s goes into a killing frenzy!");

-- vectus
-- No delete query here, it's a generic script text for frenzy emotes.
DELETE FROM `creature_text` WHERE `entry`=10432;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(10432,0,0,16,0,100,"vectus EMOTE_FRENZY_KILL","%s goes into a killing frenzy!");

-- galen
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000506 AND -1000500;
DELETE FROM `creature_text` WHERE `entry`=5391;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(5391,0,0,12,0,100,"galen SAY_PERIODIC","Help! Please, You must help me!"),
(5391,1,0,12,0,100,"galen SAY_QUEST_ACCEPTED","Let us leave this place."),
(5391,2,0,12,0,100,"galen SAY_ATTACKED_1","Look out! The $c attacks!"),
(5391,2,1,12,0,100,"galen SAY_ATTACKED_2","Help! I'm under attack!"),
(5391,3,0,12,0,100,"galen SAY_QUEST_COMPLETE","Thank you $N. I will remember you always. You can find my strongbox in my camp, north of Stonard."),
(5391,4,0,16,0,100,"galen EMOTE_WHISPER","%s whispers to $N the secret to opening his strongbox."),
(5391,5,0,16,0,100,"galen EMOTE_DISAPPEAR","%s disappears into the swamp.");

-- smite
DELETE FROM `script_texts` WHERE `entry`=-1036001;
DELETE FROM `creature_text` WHERE `entry`=646;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(646,0,0,14,5777,100,"smite SAY_AGGRO","We're under attack! A vast, ye swabs! Repel the invaders!");

-- crusader
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1609519 AND -1609501;
DELETE FROM `creature_text` WHERE `entry` IN (28939,28610,28940);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
-- Scarlet Preacher
(28939,1,0,12,0,100,"crusader SAY_CRUSADER1","You'll be hanging in the gallows shortly, Scourge fiend!"),
(28939,1,1,12,0,100,"crusader SAY_CRUSADER2","You'll have to kill me, monster! I will tell you NOTHING!"),
(28939,1,2,12,0,100,"crusader SAY_CRUSADER3","You hit like a girl. Honestly. Is that the best you can do?"),
(28939,1,3,12,0,100,"crusader SAY_CRUSADER4","ARGH! You burned my last good tabard!"),
(28939,1,4,12,0,100,"crusader SAY_CRUSADER5","Argh... The pain... The pain is almost as unbearable as the lashings I received in grammar school when I was but a child."),
(28939,1,5,12,0,100,"crusader SAY_CRUSADER6","I used to work for Grand Inquisitor Isillien! Your idea of pain is a normal mid-afternoon for me!"),
(28939,2,0,12,0,100,"break crusader SAY_PERSUADED1","I'll tell you everything! STOP! PLEASE!"),
(28939,3,0,12,0,100,"break crusader SAY_PERSUADED2","We... We have only been told that the \"Crimson Dawn\" is an awakening. You see, the Light speaks to the High General. It is the Light..."),
(28939,4,0,12,0,100,"break crusader SAY_PERSUADED3","The Light that guides us. The movement was set in motion before you came... We... We do as we are told. It is what must be done."),
(28939,5,0,12,0,100,"break crusader SAY_PERSUADED4","I know very little else... The High General chooses who may go and who must stay behind. There's nothing else... You must believe me!"),
(28939,6,0,12,0,100,"break crusader SAY_PERSUADED6","NO! PLEASE! There is one more thing that I forgot to mention... A courier comes soon... From Hearthglen. It..."),
-- Scarlet Crusader
(28940,1,0,12,0,100,"crusader SAY_CRUSADER1","You'll be hanging in the gallows shortly, Scourge fiend!"),
(28940,1,1,12,0,100,"crusader SAY_CRUSADER2","You'll have to kill me, monster! I will tell you NOTHING!"),
(28940,1,2,12,0,100,"crusader SAY_CRUSADER3","You hit like a girl. Honestly. Is that the best you can do?"),
(28940,1,3,12,0,100,"crusader SAY_CRUSADER4","ARGH! You burned my last good tabard!"),
(28940,1,4,12,0,100,"crusader SAY_CRUSADER5","Argh... The pain... The pain is almost as unbearable as the lashings I received in grammar school when I was but a child."),
(28940,1,5,12,0,100,"crusader SAY_CRUSADER6","I used to work for Grand Inquisitor Isillien! Your idea of pain is a normal mid-afternoon for me!"),
(28940,2,0,12,0,100,"break crusader SAY_PERSUADED1","I'll tell you everything! STOP! PLEASE!"),
(28940,3,0,12,0,100,"break crusader SAY_PERSUADED2","We... We have only been told that the \"Crimson Dawn\" is an awakening. You see, the Light speaks to the High General. It is the Light..."),
(28940,4,0,12,0,100,"break crusader SAY_PERSUADED3","The Light that guides us. The movement was set in motion before you came... We... We do as we are told. It is what must be done."),
(28940,5,0,12,0,100,"break crusader SAY_PERSUADED4","I know very little else... The High General chooses who may go and who must stay behind. There's nothing else... You must believe me!"),
(28940,6,0,12,0,100,"break crusader SAY_PERSUADED6","NO! PLEASE! There is one more thing that I forgot to mention... A courier comes soon... From Hearthglen. It..."),
-- Scarlet Marksman
(28610,1,0,12,0,100,"crusader SAY_CRUSADER1","You'll be hanging in the gallows shortly, Scourge fiend!"),
(28610,1,1,12,0,100,"crusader SAY_CRUSADER2","You'll have to kill me, monster! I will tell you NOTHING!"),
(28610,1,2,12,0,100,"crusader SAY_CRUSADER3","You hit like a girl. Honestly. Is that the best you can do?"),
(28610,1,3,12,0,100,"crusader SAY_CRUSADER4","ARGH! You burned my last good tabard!"),
(28610,1,4,12,0,100,"crusader SAY_CRUSADER5","Argh... The pain... The pain is almost as unbearable as the lashings I received in grammar school when I was but a child."),
(28610,1,5,12,0,100,"crusader SAY_CRUSADER6","I used to work for Grand Inquisitor Isillien! Your idea of pain is a normal mid-afternoon for me!"),
(28610,2,0,12,0,100,"break crusader SAY_PERSUADED1","I'll tell you everything! STOP! PLEASE!"),
(28610,3,0,12,0,100,"break crusader SAY_PERSUADED2","We... We have only been told that the \"Crimson Dawn\" is an awakening. You see, the Light speaks to the High General. It is the Light..."),
(28610,4,0,12,0,100,"break crusader SAY_PERSUADED3","The Light that guides us. The movement was set in motion before you came... We... We do as we are told. It is what must be done."),
(28610,5,0,12,0,100,"break crusader SAY_PERSUADED4","I know very little else... The High General chooses who may go and who must stay behind. There's nothing else... You must believe me!"),
(28610,6,0,12,0,100,"break crusader SAY_PERSUADED6","NO! PLEASE! There is one more thing that I forgot to mention... A courier comes soon... From Hearthglen. It...");

-- koltira deathweaver
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1609570 AND -1609561;
DELETE FROM `creature_text` WHERE `entry`=28912;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(28912,0,0,12,0,100,"koltira deathweaver SAY_BREAKOUT1","I'll need to get my runeblade and armor... Just need a little more time."),
(28912,1,0,12,0,100,"koltira deathweaver SAY_BREAKOUT2","I'm still weak, but I think I can get an anti-magic barrier up. Stay inside it or you'll be destroyed by their spells."),
(28912,2,0,12,0,100,"koltira deathweaver SAY_BREAKOUT3","Maintaining this barrier will require all of my concentration. Kill them all!"),
(28912,3,0,12,0,100,"koltira deathweaver SAY_BREAKOUT4","There are more coming. Defend yourself! Don't fall out of the anti-magic field! They'll tear you apart without its protection!"),
(28912,4,0,12,0,100,"koltira deathweaver SAY_BREAKOUT5","I can't keep barrier up much longer... Where is that coward?"),
(28912,5,0,12,0,100,"koltira deathweaver SAY_BREAKOUT6","The High Inquisitor comes! Be ready, death knight! Do not let him draw you out of the protective bounds of my anti-magic field! Kill him and take his head!"),
(28912,6,0,12,0,100,"koltira deathweaver SAY_BREAKOUT7","Stay in the anti-magic field! Make them come to you!"),
(28912,7,0,12,0,100,"koltira deathweaver SAY_BREAKOUT8","The death of the High Inquisitor of New Avalon will not go unnoticed. You need to get out of here at once! Go, before more of them show up. I'll be fine on my own."),
(28912,8,0,12,0,100,"koltira deathweaver SAY_BREAKOUT9","I'll draw their fire, you make your escape behind me."),
(28912,9,0,14,0,100,"koltira deathweaver SAY_BREAKOUT10","Your High Inquisitor is nothing more than a pile of meat, Crusaders! There are none beyond the grasp of the Scourge!");

-- scarlet courier
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1609532 AND -1609531;
DELETE FROM `creature_text` WHERE `entry`=29076;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(29076,0,0,12,0,100,"scarlet courier SAY_TREE1","Hrm, what a strange tree. I must investigate."),
(29076,1,0,12,0,100,"scarlet courier SAY_TREE2","What's this!? This isn't a tree at all! Guards! Guards!");

-- high inquisitor valroth
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1609586 AND -1609581;
DELETE FROM `creature_text` WHERE `entry`=29001;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(29001,0,0,14,0,100,"high inquisitor valroth start","The Crusade will purge your kind from this world!"),
(29001,1,0,14,0,100,"high inquisitor valroth SAY_VALROTH_AGGRO","It seems that I'll need to deal with you myself. The High Inquisitor comes for you, Scourge!"),
(29001,2,0,12,0,100,"high inquisitor valroth SAY_VALROTH_RAND","You have come seeking deliverance? I have come to deliver!"),
(29001,2,1,12,0,100,"high inquisitor valroth SAY_VALROTH_RAND","LIGHT PURGE YOU!"),
(29001,2,2,12,0,100,"high inquisitor valroth SAY_VALROTH_RAND","Coward!"),
(29001,3,0,16,0,100,"high inquisitor valroth SAY_VALROTH_DEATH","High Inquisitor Valroth's remains fall to the ground.");

-- A special surprise
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1609078 AND -1609025;
DELETE FROM `creature_text` WHERE `entry` IN (29032,29061,29065,29067,29068,29070,29074,29072,29073,29071,29053);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
-- Malar Bravehorn
(29032,0,0,12,0,100,"special_surprise SAY_EXEC_START_1","Come to finish the job, have you?"),
(29032,1,0,12,0,100,"special_surprise SAY_EXEC_START_2","Come to finish the job, have ye?"),
(29032,2,0,12,0,100,"special_surprise SAY_EXEC_START_3","Come ta finish da job, mon?"),
(29032,3,0,12,0,100,"special_surprise SAY_EXEC_PROG_1","You'll look me in the eyes when..."),
(29032,4,0,12,0,100,"special_surprise SAY_EXEC_PROG_2","Well this son o' Ironforge would like..."),
(29032,5,0,12,0,100,"special_surprise SAY_EXEC_PROG_3","Ironic, isn't it? To be killed..."),
(29032,6,0,12,0,100,"special_surprise SAY_EXEC_PROG_4","If you'd allow me just one..."),
(29032,7,0,12,0,100,"special_surprise SAY_EXEC_PROG_5","I'd like to stand for..."),
(29032,8,0,12,0,100,"special_surprise SAY_EXEC_PROG_6","I want to die like an orc..."),
(29032,9,0,12,0,100,"special_surprise SAY_EXEC_PROG_7","Dis troll gonna stand for da..."),
(29032,10,0,12,0,100,"special_surprise SAY_EXEC_NAME_1","$N?"),
(29032,11,0,12,0,100,"special_surprise SAY_EXEC_NAME_2","$N? Mon?"),
(29032,12,0,12,0,100,"special_surprise SAY_EXEC_RECOG_1","$N, I'd recognize that face anywhere... What... What have they done to you, $N?"),
(29032,13,0,12,0,100,"special_surprise SAY_EXEC_RECOG_2","$N, I'd recognize those face tentacles anywhere... What... What have they done to you, $N?"),
(29032,14,0,12,0,100,"special_surprise SAY_EXEC_RECOG_3","$N, I'd recognize that face anywhere... What... What have they done to ye, $Glad:lass;?"),
(29032,15,0,12,0,100,"special_surprise SAY_EXEC_RECOG_4","$N, I'd recognize that decay anywhere... What... What have they done to you, $N?"),
(29032,16,0,12,0,100,"special_surprise SAY_EXEC_RECOG_5","$N, I'd recognize those horns anywhere... What have they done to you, $N?"),
(29032,17,0,12,0,100,"special_surprise SAY_EXEC_RECOG_6","$N, I'd recognize dem tusks anywhere... What... What have dey done ta you, mon?"),
(29032,18,0,12,0,100,"special_surprise SAY_EXEC_NOREM_1","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a draenei!"),
(29032,19,0,12,0,100,"special_surprise SAY_EXEC_NOREM_2","Ye don't remember me, do ye? Blasted Scourge... They've tried to drain ye o' everything that made ye a righteous force o' reckoning. Every last ounce o' good... Everything that made you a $Gson:daughter; of Ironforge!"),
(29032,20,0,12,0,100,"special_surprise SAY_EXEC_NOREM_3","You don't remember me, do you? We were humans once - long, long ago - until Lordaeron fell to the Scourge. Your transformation to a Scourge zombie came shortly after my own. Not long after that, our minds were freed by the Dark Lady."),
(29032,21,0,12,0,100,"special_surprise SAY_EXEC_NOREM_4","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a pint-sized force of reckoning. Every last ounce of good... Everything that made you a gnome!"),
(29032,22,0,12,0,100,"special_surprise SAY_EXEC_NOREM_5","You don't remember me, do you? Blasted Scourge...They've tried to drain of everything that made you a righteous force of reckoning. Every last ounce of good...Everything that made you a human!"),
(29032,23,0,12,0,100,"special_surprise SAY_EXEC_NOREM_6","You don't remember me? When you were a child your mother would leave you in my care while she served at the Temple of the Moon. I held you in my arms and fed you with honey and sheep's milk to calm you until she would return. You were my little angel. Blasted Scourge... What have they done to you, $N?"),
(29032,24,0,12,0,100,"special_surprise SAY_EXEC_NOREM_7","You don't recognize me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you an orc!"),
(29032,25,0,12,0,100,"special_surprise SAY_EXEC_NOREM_8","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a tauren!"),
(29032,26,0,12,0,100,"special_surprise SAY_EXEC_NOREM_9","You don't remember me, mon? Damn da Scourge! Dey gone ta drain you of everytin dat made ya a mojo masta. Every last ounce of good... Everytin' dat made ya a troll hero, mon!"),
(29032,27,0,12,0,100,"special_surprise SAY_EXEC_THINK_1","A pact was made, $Gbrother:sister;! We vowed vengeance against the Lich King! For what he had done to us! We battled the Scourge as Forsaken, pushing them back into the plaguelands and freeing Tirisfal! You and I were champions of the Forsaken!"),
(29032,28,0,12,0,100,"special_surprise SAY_EXEC_THINK_2","You must remember the splendor of life, $Gbrother:sister;. You were a champion of the Kaldorei once! This isn't you!"),
(29032,29,0,12,0,100,"special_surprise SAY_EXEC_THINK_3","Think, $N. Think back. Try and remember the majestic halls of Silvermoon City, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the sin'dorei once! This isn't you."),
(29032,30,0,12,0,100,"special_surprise SAY_EXEC_THINK_4","Think, $N. Think back. Try and remember the proud mountains of Argus, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the draenei once! This isn't you."),
(29032,31,0,12,0,100,"special_surprise SAY_EXEC_THINK_5","Think, $N. Think back. Try and remember the snow capped mountains o' Dun Morogh! Ye were born there, $Glad:lass;. Remember the splendor o' life, $N! Ye were a champion o' the dwarves once! This isn't ye!"),
(29032,32,0,12,0,100,"special_surprise SAY_EXEC_THINK_6","Think, $N. Think back. Try and remember Gnomeregan before those damned troggs! Remember the feel of an [arclight spanner] $Gbrother:sister;. You were a champion of gnome-kind once! This isn't you."),
(29032,33,0,12,0,100,"special_surprise SAY_EXEC_THINK_7","Think, $N. Think back. Try and remember the hills and valleys of Elwynn, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the Alliance once! This isn't you."),
(29032,34,0,12,0,100,"special_surprise SAY_EXEC_THINK_8","Think, $N. Think back. Try and remember Durotar, $Gbrother:sister;! Remember the sacrifices our heroes made so that we could be free of the blood curse. Harken back to the Valley of Trials, where we were reborn into a world without demonic influence. We found the splendor of life, $N. Together! This isn't you. You were a champion of the Horde once!"),
(29032,35,0,12,0,100,"special_surprise SAY_EXEC_THINK_9","Think, $N. Think back. Try and remember the rolling plains of Mulgore, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the tauren once! This isn't you."),
(29032,36,0,12,0,100,"special_surprise SAY_EXEC_THINK_10","TINK $N. Tink back, mon! We be Darkspear, mon! Bruddas and sistas! Remember when we fought the Zalazane and done took he head and freed da Echo Isles? MON! TINK! You was a champion of da Darkspear trolls!"),
(29032,37,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_1","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29032,38,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_2","Listen to me, $N Ye must fight against the Lich King's control. He's a monster that wants to see this world - our world - in ruin. Don't let him use ye to accomplish his goals. Ye were once a hero and ye can be again. Fight, damn ye! Fight his control!"),
(29032,39,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_3","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals AGAIN. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29032,40,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_4","Listen ta me, $Gbrudda:sista;. You must fight against da Lich King's control. He be a monstar dat want ta see dis world - our world - be ruined. Don't let he use you ta accomplish he goals. You be a hero once and you be a hero again! Fight it, mon! Fight he control!"),

(29032,42,0,12,0,100,"special_surprise SAY_EXEC_TIME_1","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Silvermoon. This world is worth saving!"),
(29032,43,0,12,0,100,"special_surprise SAY_EXEC_TIME_2","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Argus. Don't let that happen to this world."),
(29032,44,0,12,0,100,"special_surprise SAY_EXEC_TIME_3","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both $N... For KHAAAAAAAAZZZ MODAAAAAANNNNNN!!!"),
(29032,45,0,12,0,100,"special_surprise SAY_EXEC_TIME_4","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Tirisfal! This world is worth saving!"),
(29032,46,0,12,0,100,"special_surprise SAY_EXEC_TIME_5","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Gnomeregan! This world is worth saving."),
(29032,47,0,12,0,100,"special_surprise SAY_EXEC_TIME_6","There... There's no more time for me. I'm done for. FInish me off, $N. Do it or they'll kill us both. $N...Remember Elwynn. This world is worth saving."),
(29032,48,0,12,0,100,"special_surprise SAY_EXEC_TIME_7","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Teldrassil, our beloved home. This world is worth saving."),
(29032,49,0,12,0,100,"special_surprise SAY_EXEC_TIME_8","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... For the Horde! This world is worth saving."),
(29032,50,0,12,0,100,"special_surprise SAY_EXEC_TIME_9","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Mulgore. This world is worth saving."),
(29032,51,0,12,0,100,"special_surprise SAY_EXEC_TIME_10","Der... Der's no more time for me. I be done for. Finish me off $N. Do it or they'll kill us both. $N... Remember Sen'jin Village, mon! Dis world be worth saving!"),
(29032,52,0,12,0,100,"special_surprise SAY_EXEC_WAITING","Do it, $N! Put me out of my misery!"),
(29032,53,0,16,0,100,"special_surprise EMOTE_DIES","%s dies from his wounds."),
-- Ellen Stanbridge
(29061,0,0,12,0,100,"special_surprise SAY_EXEC_START_1","Come to finish the job, have you?"),
(29061,1,0,12,0,100,"special_surprise SAY_EXEC_START_2","Come to finish the job, have ye?"),
(29061,2,0,12,0,100,"special_surprise SAY_EXEC_START_3","Come ta finish da job, mon?"),
(29061,3,0,12,0,100,"special_surprise SAY_EXEC_PROG_1","You'll look me in the eyes when..."),
(29061,4,0,12,0,100,"special_surprise SAY_EXEC_PROG_2","Well this son o' Ironforge would like..."),
(29061,5,0,12,0,100,"special_surprise SAY_EXEC_PROG_3","Ironic, isn't it? To be killed..."),
(29061,6,0,12,0,100,"special_surprise SAY_EXEC_PROG_4","If you'd allow me just one..."),
(29061,7,0,12,0,100,"special_surprise SAY_EXEC_PROG_5","I'd like to stand for..."),
(29061,8,0,12,0,100,"special_surprise SAY_EXEC_PROG_6","I want to die like an orc..."),
(29061,9,0,12,0,100,"special_surprise SAY_EXEC_PROG_7","Dis troll gonna stand for da..."),
(29061,10,0,12,0,100,"special_surprise SAY_EXEC_NAME_1","$N?"),
(29061,11,0,12,0,100,"special_surprise SAY_EXEC_NAME_2","$N? Mon?"),
(29061,12,0,12,0,100,"special_surprise SAY_EXEC_RECOG_1","$N, I'd recognize that face anywhere... What... What have they done to you, $N?"),
(29061,13,0,12,0,100,"special_surprise SAY_EXEC_RECOG_2","$N, I'd recognize those face tentacles anywhere... What... What have they done to you, $N?"),
(29061,14,0,12,0,100,"special_surprise SAY_EXEC_RECOG_3","$N, I'd recognize that face anywhere... What... What have they done to ye, $Glad:lass;?"),
(29061,15,0,12,0,100,"special_surprise SAY_EXEC_RECOG_4","$N, I'd recognize that decay anywhere... What... What have they done to you, $N?"),
(29061,16,0,12,0,100,"special_surprise SAY_EXEC_RECOG_5","$N, I'd recognize those horns anywhere... What have they done to you, $N?"),
(29061,17,0,12,0,100,"special_surprise SAY_EXEC_RECOG_6","$N, I'd recognize dem tusks anywhere... What... What have dey done ta you, mon?"),
(29061,18,0,12,0,100,"special_surprise SAY_EXEC_NOREM_1","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a draenei!"),
(29061,19,0,12,0,100,"special_surprise SAY_EXEC_NOREM_2","Ye don't remember me, do ye? Blasted Scourge... They've tried to drain ye o' everything that made ye a righteous force o' reckoning. Every last ounce o' good... Everything that made you a $Gson:daughter; of Ironforge!"),
(29061,20,0,12,0,100,"special_surprise SAY_EXEC_NOREM_3","You don't remember me, do you? We were humans once - long, long ago - until Lordaeron fell to the Scourge. Your transformation to a Scourge zombie came shortly after my own. Not long after that, our minds were freed by the Dark Lady."),
(29061,21,0,12,0,100,"special_surprise SAY_EXEC_NOREM_4","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a pint-sized force of reckoning. Every last ounce of good... Everything that made you a gnome!"),
(29061,22,0,12,0,100,"special_surprise SAY_EXEC_NOREM_5","You don't remember me, do you? Blasted Scourge...They've tried to drain of everything that made you a righteous force of reckoning. Every last ounce of good...Everything that made you a human!"),
(29061,23,0,12,0,100,"special_surprise SAY_EXEC_NOREM_6","You don't remember me? When you were a child your mother would leave you in my care while she served at the Temple of the Moon. I held you in my arms and fed you with honey and sheep's milk to calm you until she would return. You were my little angel. Blasted Scourge... What have they done to you, $N?"),
(29061,24,0,12,0,100,"special_surprise SAY_EXEC_NOREM_7","You don't recognize me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you an orc!"),
(29061,25,0,12,0,100,"special_surprise SAY_EXEC_NOREM_8","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a tauren!"),
(29061,26,0,12,0,100,"special_surprise SAY_EXEC_NOREM_9","You don't remember me, mon? Damn da Scourge! Dey gone ta drain you of everytin dat made ya a mojo masta. Every last ounce of good... Everytin' dat made ya a troll hero, mon!"),
(29061,27,0,12,0,100,"special_surprise SAY_EXEC_THINK_1","A pact was made, $Gbrother:sister;! We vowed vengeance against the Lich King! For what he had done to us! We battled the Scourge as Forsaken, pushing them back into the plaguelands and freeing Tirisfal! You and I were champions of the Forsaken!"),
(29061,28,0,12,0,100,"special_surprise SAY_EXEC_THINK_2","You must remember the splendor of life, $Gbrother:sister;. You were a champion of the Kaldorei once! This isn't you!"),
(29061,29,0,12,0,100,"special_surprise SAY_EXEC_THINK_3","Think, $N. Think back. Try and remember the majestic halls of Silvermoon City, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the sin'dorei once! This isn't you."),
(29061,30,0,12,0,100,"special_surprise SAY_EXEC_THINK_4","Think, $N. Think back. Try and remember the proud mountains of Argus, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the draenei once! This isn't you."),
(29061,31,0,12,0,100,"special_surprise SAY_EXEC_THINK_5","Think, $N. Think back. Try and remember the snow capped mountains o' Dun Morogh! Ye were born there, $Glad:lass;. Remember the splendor o' life, $N! Ye were a champion o' the dwarves once! This isn't ye!"),
(29061,32,0,12,0,100,"special_surprise SAY_EXEC_THINK_6","Think, $N. Think back. Try and remember Gnomeregan before those damned troggs! Remember the feel of an [arclight spanner] $Gbrother:sister;. You were a champion of gnome-kind once! This isn't you."),
(29061,33,0,12,0,100,"special_surprise SAY_EXEC_THINK_7","Think, $N. Think back. Try and remember the hills and valleys of Elwynn, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the Alliance once! This isn't you."),
(29061,34,0,12,0,100,"special_surprise SAY_EXEC_THINK_8","Think, $N. Think back. Try and remember Durotar, $Gbrother:sister;! Remember the sacrifices our heroes made so that we could be free of the blood curse. Harken back to the Valley of Trials, where we were reborn into a world without demonic influence. We found the splendor of life, $N. Together! This isn't you. You were a champion of the Horde once!"),
(29061,35,0,12,0,100,"special_surprise SAY_EXEC_THINK_9","Think, $N. Think back. Try and remember the rolling plains of Mulgore, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the tauren once! This isn't you."),
(29061,36,0,12,0,100,"special_surprise SAY_EXEC_THINK_10","TINK $N. Tink back, mon! We be Darkspear, mon! Bruddas and sistas! Remember when we fought the Zalazane and done took he head and freed da Echo Isles? MON! TINK! You was a champion of da Darkspear trolls!"),
(29061,37,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_1","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29061,38,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_2","Listen to me, $N Ye must fight against the Lich King's control. He's a monster that wants to see this world - our world - in ruin. Don't let him use ye to accomplish his goals. Ye were once a hero and ye can be again. Fight, damn ye! Fight his control!"),
(29061,39,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_3","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals AGAIN. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29061,40,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_4","Listen ta me, $Gbrudda:sista;. You must fight against da Lich King's control. He be a monstar dat want ta see dis world - our world - be ruined. Don't let he use you ta accomplish he goals. You be a hero once and you be a hero again! Fight it, mon! Fight he control!"),
(29061,42,0,12,0,100,"special_surprise SAY_EXEC_TIME_1","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Silvermoon. This world is worth saving!"),
(29061,43,0,12,0,100,"special_surprise SAY_EXEC_TIME_2","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Argus. Don't let that happen to this world."),
(29061,44,0,12,0,100,"special_surprise SAY_EXEC_TIME_3","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both $N... For KHAAAAAAAAZZZ MODAAAAAANNNNNN!!!"),
(29061,45,0,12,0,100,"special_surprise SAY_EXEC_TIME_4","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Tirisfal! This world is worth saving!"),
(29061,46,0,12,0,100,"special_surprise SAY_EXEC_TIME_5","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Gnomeregan! This world is worth saving."),
(29061,47,0,12,0,100,"special_surprise SAY_EXEC_TIME_6","There... There's no more time for me. I'm done for. FInish me off, $N. Do it or they'll kill us both. $N...Remember Elwynn. This world is worth saving."),
(29061,48,0,12,0,100,"special_surprise SAY_EXEC_TIME_7","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Teldrassil, our beloved home. This world is worth saving."),
(29061,49,0,12,0,100,"special_surprise SAY_EXEC_TIME_8","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... For the Horde! This world is worth saving."),
(29061,50,0,12,0,100,"special_surprise SAY_EXEC_TIME_9","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Mulgore. This world is worth saving."),
(29061,51,0,12,0,100,"special_surprise SAY_EXEC_TIME_10","Der... Der's no more time for me. I be done for. Finish me off $N. Do it or they'll kill us both. $N... Remember Sen'jin Village, mon! Dis world be worth saving!"),
(29061,52,0,12,0,100,"special_surprise SAY_EXEC_WAITING","Do it, $N! Put me out of my misery!"),
(29061,53,0,16,0,100,"special_surprise EMOTE_DIES","%s dies from his wounds."),
-- Yazmina Oakenthorn
(29065,0,0,12,0,100,"special_surprise SAY_EXEC_START_1","Come to finish the job, have you?"),
(29065,1,0,12,0,100,"special_surprise SAY_EXEC_START_2","Come to finish the job, have ye?"),
(29065,2,0,12,0,100,"special_surprise SAY_EXEC_START_3","Come ta finish da job, mon?"),
(29065,3,0,12,0,100,"special_surprise SAY_EXEC_PROG_1","You'll look me in the eyes when..."),
(29065,4,0,12,0,100,"special_surprise SAY_EXEC_PROG_2","Well this son o' Ironforge would like..."),
(29065,5,0,12,0,100,"special_surprise SAY_EXEC_PROG_3","Ironic, isn't it? To be killed..."),
(29065,6,0,12,0,100,"special_surprise SAY_EXEC_PROG_4","If you'd allow me just one..."),
(29065,7,0,12,0,100,"special_surprise SAY_EXEC_PROG_5","I'd like to stand for..."),
(29065,8,0,12,0,100,"special_surprise SAY_EXEC_PROG_6","I want to die like an orc..."),
(29065,9,0,12,0,100,"special_surprise SAY_EXEC_PROG_7","Dis troll gonna stand for da..."),
(29065,10,0,12,0,100,"special_surprise SAY_EXEC_NAME_1","$N?"),
(29065,11,0,12,0,100,"special_surprise SAY_EXEC_NAME_2","$N? Mon?"),
(29065,12,0,12,0,100,"special_surprise SAY_EXEC_RECOG_1","$N, I'd recognize that face anywhere... What... What have they done to you, $N?"),
(29065,13,0,12,0,100,"special_surprise SAY_EXEC_RECOG_2","$N, I'd recognize those face tentacles anywhere... What... What have they done to you, $N?"),
(29065,14,0,12,0,100,"special_surprise SAY_EXEC_RECOG_3","$N, I'd recognize that face anywhere... What... What have they done to ye, $Glad:lass;?"),
(29065,15,0,12,0,100,"special_surprise SAY_EXEC_RECOG_4","$N, I'd recognize that decay anywhere... What... What have they done to you, $N?"),
(29065,16,0,12,0,100,"special_surprise SAY_EXEC_RECOG_5","$N, I'd recognize those horns anywhere... What have they done to you, $N?"),
(29065,17,0,12,0,100,"special_surprise SAY_EXEC_RECOG_6","$N, I'd recognize dem tusks anywhere... What... What have dey done ta you, mon?"),
(29065,18,0,12,0,100,"special_surprise SAY_EXEC_NOREM_1","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a draenei!"),
(29065,19,0,12,0,100,"special_surprise SAY_EXEC_NOREM_2","Ye don't remember me, do ye? Blasted Scourge... They've tried to drain ye o' everything that made ye a righteous force o' reckoning. Every last ounce o' good... Everything that made you a $Gson:daughter; of Ironforge!"),
(29065,20,0,12,0,100,"special_surprise SAY_EXEC_NOREM_3","You don't remember me, do you? We were humans once - long, long ago - until Lordaeron fell to the Scourge. Your transformation to a Scourge zombie came shortly after my own. Not long after that, our minds were freed by the Dark Lady."),
(29065,21,0,12,0,100,"special_surprise SAY_EXEC_NOREM_4","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a pint-sized force of reckoning. Every last ounce of good... Everything that made you a gnome!"),
(29065,22,0,12,0,100,"special_surprise SAY_EXEC_NOREM_5","You don't remember me, do you? Blasted Scourge...They've tried to drain of everything that made you a righteous force of reckoning. Every last ounce of good...Everything that made you a human!"),
(29065,23,0,12,0,100,"special_surprise SAY_EXEC_NOREM_6","You don't remember me? When you were a child your mother would leave you in my care while she served at the Temple of the Moon. I held you in my arms and fed you with honey and sheep's milk to calm you until she would return. You were my little angel. Blasted Scourge... What have they done to you, $N?"),
(29065,24,0,12,0,100,"special_surprise SAY_EXEC_NOREM_7","You don't recognize me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you an orc!"),
(29065,25,0,12,0,100,"special_surprise SAY_EXEC_NOREM_8","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a tauren!"),
(29065,26,0,12,0,100,"special_surprise SAY_EXEC_NOREM_9","You don't remember me, mon? Damn da Scourge! Dey gone ta drain you of everytin dat made ya a mojo masta. Every last ounce of good... Everytin' dat made ya a troll hero, mon!"),
(29065,27,0,12,0,100,"special_surprise SAY_EXEC_THINK_1","A pact was made, $Gbrother:sister;! We vowed vengeance against the Lich King! For what he had done to us! We battled the Scourge as Forsaken, pushing them back into the plaguelands and freeing Tirisfal! You and I were champions of the Forsaken!"),
(29065,28,0,12,0,100,"special_surprise SAY_EXEC_THINK_2","You must remember the splendor of life, $Gbrother:sister;. You were a champion of the Kaldorei once! This isn't you!"),
(29065,29,0,12,0,100,"special_surprise SAY_EXEC_THINK_3","Think, $N. Think back. Try and remember the majestic halls of Silvermoon City, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the sin'dorei once! This isn't you."),
(29065,30,0,12,0,100,"special_surprise SAY_EXEC_THINK_4","Think, $N. Think back. Try and remember the proud mountains of Argus, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the draenei once! This isn't you."),
(29065,31,0,12,0,100,"special_surprise SAY_EXEC_THINK_5","Think, $N. Think back. Try and remember the snow capped mountains o' Dun Morogh! Ye were born there, $Glad:lass;. Remember the splendor o' life, $N! Ye were a champion o' the dwarves once! This isn't ye!"),
(29065,32,0,12,0,100,"special_surprise SAY_EXEC_THINK_6","Think, $N. Think back. Try and remember Gnomeregan before those damned troggs! Remember the feel of an [arclight spanner] $Gbrother:sister;. You were a champion of gnome-kind once! This isn't you."),
(29065,33,0,12,0,100,"special_surprise SAY_EXEC_THINK_7","Think, $N. Think back. Try and remember the hills and valleys of Elwynn, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the Alliance once! This isn't you."),
(29065,34,0,12,0,100,"special_surprise SAY_EXEC_THINK_8","Think, $N. Think back. Try and remember Durotar, $Gbrother:sister;! Remember the sacrifices our heroes made so that we could be free of the blood curse. Harken back to the Valley of Trials, where we were reborn into a world without demonic influence. We found the splendor of life, $N. Together! This isn't you. You were a champion of the Horde once!"),
(29065,35,0,12,0,100,"special_surprise SAY_EXEC_THINK_9","Think, $N. Think back. Try and remember the rolling plains of Mulgore, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the tauren once! This isn't you."),
(29065,36,0,12,0,100,"special_surprise SAY_EXEC_THINK_10","TINK $N. Tink back, mon! We be Darkspear, mon! Bruddas and sistas! Remember when we fought the Zalazane and done took he head and freed da Echo Isles? MON! TINK! You was a champion of da Darkspear trolls!"),
(29065,37,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_1","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29065,38,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_2","Listen to me, $N Ye must fight against the Lich King's control. He's a monster that wants to see this world - our world - in ruin. Don't let him use ye to accomplish his goals. Ye were once a hero and ye can be again. Fight, damn ye! Fight his control!"),
(29065,39,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_3","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals AGAIN. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29065,40,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_4","Listen ta me, $Gbrudda:sista;. You must fight against da Lich King's control. He be a monstar dat want ta see dis world - our world - be ruined. Don't let he use you ta accomplish he goals. You be a hero once and you be a hero again! Fight it, mon! Fight he control!"),
(29065,42,0,12,0,100,"special_surprise SAY_EXEC_TIME_1","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Silvermoon. This world is worth saving!"),
(29065,43,0,12,0,100,"special_surprise SAY_EXEC_TIME_2","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Argus. Don't let that happen to this world."),
(29065,44,0,12,0,100,"special_surprise SAY_EXEC_TIME_3","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both $N... For KHAAAAAAAAZZZ MODAAAAAANNNNNN!!!"),
(29065,45,0,12,0,100,"special_surprise SAY_EXEC_TIME_4","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Tirisfal! This world is worth saving!"),
(29065,46,0,12,0,100,"special_surprise SAY_EXEC_TIME_5","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Gnomeregan! This world is worth saving."),
(29065,47,0,12,0,100,"special_surprise SAY_EXEC_TIME_6","There... There's no more time for me. I'm done for. FInish me off, $N. Do it or they'll kill us both. $N...Remember Elwynn. This world is worth saving."),
(29065,48,0,12,0,100,"special_surprise SAY_EXEC_TIME_7","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Teldrassil, our beloved home. This world is worth saving."),
(29065,49,0,12,0,100,"special_surprise SAY_EXEC_TIME_8","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... For the Horde! This world is worth saving."),
(29065,50,0,12,0,100,"special_surprise SAY_EXEC_TIME_9","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Mulgore. This world is worth saving."),
(29065,51,0,12,0,100,"special_surprise SAY_EXEC_TIME_10","Der... Der's no more time for me. I be done for. Finish me off $N. Do it or they'll kill us both. $N... Remember Sen'jin Village, mon! Dis world be worth saving!"),
(29065,52,0,12,0,100,"special_surprise SAY_EXEC_WAITING","Do it, $N! Put me out of my misery!"),
(29065,53,0,16,0,100,"special_surprise EMOTE_DIES","%s dies from his wounds."),
-- Donovan Pulfrost
(29067,0,0,12,0,100,"special_surprise SAY_EXEC_START_1","Come to finish the job, have you?"),
(29067,1,0,12,0,100,"special_surprise SAY_EXEC_START_2","Come to finish the job, have ye?"),
(29067,2,0,12,0,100,"special_surprise SAY_EXEC_START_3","Come ta finish da job, mon?"),
(29067,3,0,12,0,100,"special_surprise SAY_EXEC_PROG_1","You'll look me in the eyes when..."),
(29067,4,0,12,0,100,"special_surprise SAY_EXEC_PROG_2","Well this son o' Ironforge would like..."),
(29067,5,0,12,0,100,"special_surprise SAY_EXEC_PROG_3","Ironic, isn't it? To be killed..."),
(29067,6,0,12,0,100,"special_surprise SAY_EXEC_PROG_4","If you'd allow me just one..."),
(29067,7,0,12,0,100,"special_surprise SAY_EXEC_PROG_5","I'd like to stand for..."),
(29067,8,0,12,0,100,"special_surprise SAY_EXEC_PROG_6","I want to die like an orc..."),
(29067,9,0,12,0,100,"special_surprise SAY_EXEC_PROG_7","Dis troll gonna stand for da..."),
(29067,10,0,12,0,100,"special_surprise SAY_EXEC_NAME_1","$N?"),
(29067,11,0,12,0,100,"special_surprise SAY_EXEC_NAME_2","$N? Mon?"),
(29067,12,0,12,0,100,"special_surprise SAY_EXEC_RECOG_1","$N, I'd recognize that face anywhere... What... What have they done to you, $N?"),
(29067,13,0,12,0,100,"special_surprise SAY_EXEC_RECOG_2","$N, I'd recognize those face tentacles anywhere... What... What have they done to you, $N?"),
(29067,14,0,12,0,100,"special_surprise SAY_EXEC_RECOG_3","$N, I'd recognize that face anywhere... What... What have they done to ye, $Glad:lass;?"),
(29067,15,0,12,0,100,"special_surprise SAY_EXEC_RECOG_4","$N, I'd recognize that decay anywhere... What... What have they done to you, $N?"),
(29067,16,0,12,0,100,"special_surprise SAY_EXEC_RECOG_5","$N, I'd recognize those horns anywhere... What have they done to you, $N?"),
(29067,17,0,12,0,100,"special_surprise SAY_EXEC_RECOG_6","$N, I'd recognize dem tusks anywhere... What... What have dey done ta you, mon?"),
(29067,18,0,12,0,100,"special_surprise SAY_EXEC_NOREM_1","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a draenei!"),
(29067,19,0,12,0,100,"special_surprise SAY_EXEC_NOREM_2","Ye don't remember me, do ye? Blasted Scourge... They've tried to drain ye o' everything that made ye a righteous force o' reckoning. Every last ounce o' good... Everything that made you a $Gson:daughter; of Ironforge!"),
(29067,20,0,12,0,100,"special_surprise SAY_EXEC_NOREM_3","You don't remember me, do you? We were humans once - long, long ago - until Lordaeron fell to the Scourge. Your transformation to a Scourge zombie came shortly after my own. Not long after that, our minds were freed by the Dark Lady."),
(29067,21,0,12,0,100,"special_surprise SAY_EXEC_NOREM_4","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a pint-sized force of reckoning. Every last ounce of good... Everything that made you a gnome!"),
(29067,22,0,12,0,100,"special_surprise SAY_EXEC_NOREM_5","You don't remember me, do you? Blasted Scourge...They've tried to drain of everything that made you a righteous force of reckoning. Every last ounce of good...Everything that made you a human!"),
(29067,23,0,12,0,100,"special_surprise SAY_EXEC_NOREM_6","You don't remember me? When you were a child your mother would leave you in my care while she served at the Temple of the Moon. I held you in my arms and fed you with honey and sheep's milk to calm you until she would return. You were my little angel. Blasted Scourge... What have they done to you, $N?"),
(29067,24,0,12,0,100,"special_surprise SAY_EXEC_NOREM_7","You don't recognize me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you an orc!"),
(29067,25,0,12,0,100,"special_surprise SAY_EXEC_NOREM_8","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a tauren!"),
(29067,26,0,12,0,100,"special_surprise SAY_EXEC_NOREM_9","You don't remember me, mon? Damn da Scourge! Dey gone ta drain you of everytin dat made ya a mojo masta. Every last ounce of good... Everytin' dat made ya a troll hero, mon!"),
(29067,27,0,12,0,100,"special_surprise SAY_EXEC_THINK_1","A pact was made, $Gbrother:sister;! We vowed vengeance against the Lich King! For what he had done to us! We battled the Scourge as Forsaken, pushing them back into the plaguelands and freeing Tirisfal! You and I were champions of the Forsaken!"),
(29067,28,0,12,0,100,"special_surprise SAY_EXEC_THINK_2","You must remember the splendor of life, $Gbrother:sister;. You were a champion of the Kaldorei once! This isn't you!"),
(29067,29,0,12,0,100,"special_surprise SAY_EXEC_THINK_3","Think, $N. Think back. Try and remember the majestic halls of Silvermoon City, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the sin'dorei once! This isn't you."),
(29067,30,0,12,0,100,"special_surprise SAY_EXEC_THINK_4","Think, $N. Think back. Try and remember the proud mountains of Argus, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the draenei once! This isn't you."),
(29067,31,0,12,0,100,"special_surprise SAY_EXEC_THINK_5","Think, $N. Think back. Try and remember the snow capped mountains o' Dun Morogh! Ye were born there, $Glad:lass;. Remember the splendor o' life, $N! Ye were a champion o' the dwarves once! This isn't ye!"),
(29067,32,0,12,0,100,"special_surprise SAY_EXEC_THINK_6","Think, $N. Think back. Try and remember Gnomeregan before those damned troggs! Remember the feel of an [arclight spanner] $Gbrother:sister;. You were a champion of gnome-kind once! This isn't you."),
(29067,33,0,12,0,100,"special_surprise SAY_EXEC_THINK_7","Think, $N. Think back. Try and remember the hills and valleys of Elwynn, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the Alliance once! This isn't you."),
(29067,34,0,12,0,100,"special_surprise SAY_EXEC_THINK_8","Think, $N. Think back. Try and remember Durotar, $Gbrother:sister;! Remember the sacrifices our heroes made so that we could be free of the blood curse. Harken back to the Valley of Trials, where we were reborn into a world without demonic influence. We found the splendor of life, $N. Together! This isn't you. You were a champion of the Horde once!"),
(29067,35,0,12,0,100,"special_surprise SAY_EXEC_THINK_9","Think, $N. Think back. Try and remember the rolling plains of Mulgore, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the tauren once! This isn't you."),
(29067,36,0,12,0,100,"special_surprise SAY_EXEC_THINK_10","TINK $N. Tink back, mon! We be Darkspear, mon! Bruddas and sistas! Remember when we fought the Zalazane and done took he head and freed da Echo Isles? MON! TINK! You was a champion of da Darkspear trolls!"),
(29067,37,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_1","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29067,38,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_2","Listen to me, $N Ye must fight against the Lich King's control. He's a monster that wants to see this world - our world - in ruin. Don't let him use ye to accomplish his goals. Ye were once a hero and ye can be again. Fight, damn ye! Fight his control!"),
(29067,39,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_3","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals AGAIN. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29067,40,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_4","Listen ta me, $Gbrudda:sista;. You must fight against da Lich King's control. He be a monstar dat want ta see dis world - our world - be ruined. Don't let he use you ta accomplish he goals. You be a hero once and you be a hero again! Fight it, mon! Fight he control!"),
(29067,42,0,12,0,100,"special_surprise SAY_EXEC_TIME_1","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Silvermoon. This world is worth saving!"),
(29067,43,0,12,0,100,"special_surprise SAY_EXEC_TIME_2","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Argus. Don't let that happen to this world."),
(29067,44,0,12,0,100,"special_surprise SAY_EXEC_TIME_3","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both $N... For KHAAAAAAAAZZZ MODAAAAAANNNNNN!!!"),
(29067,45,0,12,0,100,"special_surprise SAY_EXEC_TIME_4","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Tirisfal! This world is worth saving!"),
(29067,46,0,12,0,100,"special_surprise SAY_EXEC_TIME_5","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Gnomeregan! This world is worth saving."),
(29067,47,0,12,0,100,"special_surprise SAY_EXEC_TIME_6","There... There's no more time for me. I'm done for. FInish me off, $N. Do it or they'll kill us both. $N...Remember Elwynn. This world is worth saving."),
(29067,48,0,12,0,100,"special_surprise SAY_EXEC_TIME_7","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Teldrassil, our beloved home. This world is worth saving."),
(29067,49,0,12,0,100,"special_surprise SAY_EXEC_TIME_8","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... For the Horde! This world is worth saving."),
(29067,50,0,12,0,100,"special_surprise SAY_EXEC_TIME_9","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Mulgore. This world is worth saving."),
(29067,51,0,12,0,100,"special_surprise SAY_EXEC_TIME_10","Der... Der's no more time for me. I be done for. Finish me off $N. Do it or they'll kill us both. $N... Remember Sen'jin Village, mon! Dis world be worth saving!"),
(29067,52,0,12,0,100,"special_surprise SAY_EXEC_WAITING","Do it, $N! Put me out of my misery!"),
(29067,53,0,16,0,100,"special_surprise EMOTE_DIES","%s dies from his wounds."),
-- Goby Blastenheimer
(29068,0,0,12,0,100,"special_surprise SAY_EXEC_START_1","Come to finish the job, have you?"),
(29068,1,0,12,0,100,"special_surprise SAY_EXEC_START_2","Come to finish the job, have ye?"),
(29068,2,0,12,0,100,"special_surprise SAY_EXEC_START_3","Come ta finish da job, mon?"),
(29068,3,0,12,0,100,"special_surprise SAY_EXEC_PROG_1","You'll look me in the eyes when..."),
(29068,4,0,12,0,100,"special_surprise SAY_EXEC_PROG_2","Well this son o' Ironforge would like..."),
(29068,5,0,12,0,100,"special_surprise SAY_EXEC_PROG_3","Ironic, isn't it? To be killed..."),
(29068,6,0,12,0,100,"special_surprise SAY_EXEC_PROG_4","If you'd allow me just one..."),
(29068,7,0,12,0,100,"special_surprise SAY_EXEC_PROG_5","I'd like to stand for..."),
(29068,8,0,12,0,100,"special_surprise SAY_EXEC_PROG_6","I want to die like an orc..."),
(29068,9,0,12,0,100,"special_surprise SAY_EXEC_PROG_7","Dis troll gonna stand for da..."),
(29068,10,0,12,0,100,"special_surprise SAY_EXEC_NAME_1","$N?"),
(29068,11,0,12,0,100,"special_surprise SAY_EXEC_NAME_2","$N? Mon?"),
(29068,12,0,12,0,100,"special_surprise SAY_EXEC_RECOG_1","$N, I'd recognize that face anywhere... What... What have they done to you, $N?"),
(29068,13,0,12,0,100,"special_surprise SAY_EXEC_RECOG_2","$N, I'd recognize those face tentacles anywhere... What... What have they done to you, $N?"),
(29068,14,0,12,0,100,"special_surprise SAY_EXEC_RECOG_3","$N, I'd recognize that face anywhere... What... What have they done to ye, $Glad:lass;?"),
(29068,15,0,12,0,100,"special_surprise SAY_EXEC_RECOG_4","$N, I'd recognize that decay anywhere... What... What have they done to you, $N?"),
(29068,16,0,12,0,100,"special_surprise SAY_EXEC_RECOG_5","$N, I'd recognize those horns anywhere... What have they done to you, $N?"),
(29068,17,0,12,0,100,"special_surprise SAY_EXEC_RECOG_6","$N, I'd recognize dem tusks anywhere... What... What have dey done ta you, mon?"),
(29068,18,0,12,0,100,"special_surprise SAY_EXEC_NOREM_1","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a draenei!"),
(29068,19,0,12,0,100,"special_surprise SAY_EXEC_NOREM_2","Ye don't remember me, do ye? Blasted Scourge... They've tried to drain ye o' everything that made ye a righteous force o' reckoning. Every last ounce o' good... Everything that made you a $Gson:daughter; of Ironforge!"),
(29068,20,0,12,0,100,"special_surprise SAY_EXEC_NOREM_3","You don't remember me, do you? We were humans once - long, long ago - until Lordaeron fell to the Scourge. Your transformation to a Scourge zombie came shortly after my own. Not long after that, our minds were freed by the Dark Lady."),
(29068,21,0,12,0,100,"special_surprise SAY_EXEC_NOREM_4","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a pint-sized force of reckoning. Every last ounce of good... Everything that made you a gnome!"),
(29068,22,0,12,0,100,"special_surprise SAY_EXEC_NOREM_5","You don't remember me, do you? Blasted Scourge...They've tried to drain of everything that made you a righteous force of reckoning. Every last ounce of good...Everything that made you a human!"),
(29068,23,0,12,0,100,"special_surprise SAY_EXEC_NOREM_6","You don't remember me? When you were a child your mother would leave you in my care while she served at the Temple of the Moon. I held you in my arms and fed you with honey and sheep's milk to calm you until she would return. You were my little angel. Blasted Scourge... What have they done to you, $N?"),
(29068,24,0,12,0,100,"special_surprise SAY_EXEC_NOREM_7","You don't recognize me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you an orc!"),
(29068,25,0,12,0,100,"special_surprise SAY_EXEC_NOREM_8","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a tauren!"),
(29068,26,0,12,0,100,"special_surprise SAY_EXEC_NOREM_9","You don't remember me, mon? Damn da Scourge! Dey gone ta drain you of everytin dat made ya a mojo masta. Every last ounce of good... Everytin' dat made ya a troll hero, mon!"),
(29068,27,0,12,0,100,"special_surprise SAY_EXEC_THINK_1","A pact was made, $Gbrother:sister;! We vowed vengeance against the Lich King! For what he had done to us! We battled the Scourge as Forsaken, pushing them back into the plaguelands and freeing Tirisfal! You and I were champions of the Forsaken!"),
(29068,28,0,12,0,100,"special_surprise SAY_EXEC_THINK_2","You must remember the splendor of life, $Gbrother:sister;. You were a champion of the Kaldorei once! This isn't you!"),
(29068,29,0,12,0,100,"special_surprise SAY_EXEC_THINK_3","Think, $N. Think back. Try and remember the majestic halls of Silvermoon City, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the sin'dorei once! This isn't you."),
(29068,30,0,12,0,100,"special_surprise SAY_EXEC_THINK_4","Think, $N. Think back. Try and remember the proud mountains of Argus, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the draenei once! This isn't you."),
(29068,31,0,12,0,100,"special_surprise SAY_EXEC_THINK_5","Think, $N. Think back. Try and remember the snow capped mountains o' Dun Morogh! Ye were born there, $Glad:lass;. Remember the splendor o' life, $N! Ye were a champion o' the dwarves once! This isn't ye!"),
(29068,32,0,12,0,100,"special_surprise SAY_EXEC_THINK_6","Think, $N. Think back. Try and remember Gnomeregan before those damned troggs! Remember the feel of an [arclight spanner] $Gbrother:sister;. You were a champion of gnome-kind once! This isn't you."),
(29068,33,0,12,0,100,"special_surprise SAY_EXEC_THINK_7","Think, $N. Think back. Try and remember the hills and valleys of Elwynn, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the Alliance once! This isn't you."),
(29068,34,0,12,0,100,"special_surprise SAY_EXEC_THINK_8","Think, $N. Think back. Try and remember Durotar, $Gbrother:sister;! Remember the sacrifices our heroes made so that we could be free of the blood curse. Harken back to the Valley of Trials, where we were reborn into a world without demonic influence. We found the splendor of life, $N. Together! This isn't you. You were a champion of the Horde once!"),
(29068,35,0,12,0,100,"special_surprise SAY_EXEC_THINK_9","Think, $N. Think back. Try and remember the rolling plains of Mulgore, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the tauren once! This isn't you."),
(29068,36,0,12,0,100,"special_surprise SAY_EXEC_THINK_10","TINK $N. Tink back, mon! We be Darkspear, mon! Bruddas and sistas! Remember when we fought the Zalazane and done took he head and freed da Echo Isles? MON! TINK! You was a champion of da Darkspear trolls!"),
(29068,37,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_1","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29068,38,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_2","Listen to me, $N Ye must fight against the Lich King's control. He's a monster that wants to see this world - our world - in ruin. Don't let him use ye to accomplish his goals. Ye were once a hero and ye can be again. Fight, damn ye! Fight his control!"),
(29068,39,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_3","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals AGAIN. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29068,40,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_4","Listen ta me, $Gbrudda:sista;. You must fight against da Lich King's control. He be a monstar dat want ta see dis world - our world - be ruined. Don't let he use you ta accomplish he goals. You be a hero once and you be a hero again! Fight it, mon! Fight he control!"),
(29068,42,0,12,0,100,"special_surprise SAY_EXEC_TIME_1","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Silvermoon. This world is worth saving!"),
(29068,43,0,12,0,100,"special_surprise SAY_EXEC_TIME_2","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Argus. Don't let that happen to this world."),
(29068,44,0,12,0,100,"special_surprise SAY_EXEC_TIME_3","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both $N... For KHAAAAAAAAZZZ MODAAAAAANNNNNN!!!"),
(29068,45,0,12,0,100,"special_surprise SAY_EXEC_TIME_4","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Tirisfal! This world is worth saving!"),
(29068,46,0,12,0,100,"special_surprise SAY_EXEC_TIME_5","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Gnomeregan! This world is worth saving."),
(29068,47,0,12,0,100,"special_surprise SAY_EXEC_TIME_6","There... There's no more time for me. I'm done for. FInish me off, $N. Do it or they'll kill us both. $N...Remember Elwynn. This world is worth saving."),
(29068,48,0,12,0,100,"special_surprise SAY_EXEC_TIME_7","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Teldrassil, our beloved home. This world is worth saving."),
(29068,49,0,12,0,100,"special_surprise SAY_EXEC_TIME_8","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... For the Horde! This world is worth saving."),
(29068,50,0,12,0,100,"special_surprise SAY_EXEC_TIME_9","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Mulgore. This world is worth saving."),
(29068,51,0,12,0,100,"special_surprise SAY_EXEC_TIME_10","Der... Der's no more time for me. I be done for. Finish me off $N. Do it or they'll kill us both. $N... Remember Sen'jin Village, mon! Dis world be worth saving!"),
(29068,52,0,12,0,100,"special_surprise SAY_EXEC_WAITING","Do it, $N! Put me out of my misery!"),
(29068,53,0,16,0,100,"special_surprise EMOTE_DIES","%s dies from his wounds."),
-- Valok the Righteous
(29070,0,0,12,0,100,"special_surprise SAY_EXEC_START_1","Come to finish the job, have you?"),
(29070,1,0,12,0,100,"special_surprise SAY_EXEC_START_2","Come to finish the job, have ye?"),
(29070,2,0,12,0,100,"special_surprise SAY_EXEC_START_3","Come ta finish da job, mon?"),
(29070,3,0,12,0,100,"special_surprise SAY_EXEC_PROG_1","You'll look me in the eyes when..."),
(29070,4,0,12,0,100,"special_surprise SAY_EXEC_PROG_2","Well this son o' Ironforge would like..."),
(29070,5,0,12,0,100,"special_surprise SAY_EXEC_PROG_3","Ironic, isn't it? To be killed..."),
(29070,6,0,12,0,100,"special_surprise SAY_EXEC_PROG_4","If you'd allow me just one..."),
(29070,7,0,12,0,100,"special_surprise SAY_EXEC_PROG_5","I'd like to stand for..."),
(29070,8,0,12,0,100,"special_surprise SAY_EXEC_PROG_6","I want to die like an orc..."),
(29070,9,0,12,0,100,"special_surprise SAY_EXEC_PROG_7","Dis troll gonna stand for da..."),
(29070,10,0,12,0,100,"special_surprise SAY_EXEC_NAME_1","$N?"),
(29070,11,0,12,0,100,"special_surprise SAY_EXEC_NAME_2","$N? Mon?"),
(29070,12,0,12,0,100,"special_surprise SAY_EXEC_RECOG_1","$N, I'd recognize that face anywhere... What... What have they done to you, $N?"),
(29070,13,0,12,0,100,"special_surprise SAY_EXEC_RECOG_2","$N, I'd recognize those face tentacles anywhere... What... What have they done to you, $N?"),
(29070,14,0,12,0,100,"special_surprise SAY_EXEC_RECOG_3","$N, I'd recognize that face anywhere... What... What have they done to ye, $Glad:lass;?"),
(29070,15,0,12,0,100,"special_surprise SAY_EXEC_RECOG_4","$N, I'd recognize that decay anywhere... What... What have they done to you, $N?"),
(29070,16,0,12,0,100,"special_surprise SAY_EXEC_RECOG_5","$N, I'd recognize those horns anywhere... What have they done to you, $N?"),
(29070,17,0,12,0,100,"special_surprise SAY_EXEC_RECOG_6","$N, I'd recognize dem tusks anywhere... What... What have dey done ta you, mon?"),
(29070,18,0,12,0,100,"special_surprise SAY_EXEC_NOREM_1","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a draenei!"),
(29070,19,0,12,0,100,"special_surprise SAY_EXEC_NOREM_2","Ye don't remember me, do ye? Blasted Scourge... They've tried to drain ye o' everything that made ye a righteous force o' reckoning. Every last ounce o' good... Everything that made you a $Gson:daughter; of Ironforge!"),
(29070,20,0,12,0,100,"special_surprise SAY_EXEC_NOREM_3","You don't remember me, do you? We were humans once - long, long ago - until Lordaeron fell to the Scourge. Your transformation to a Scourge zombie came shortly after my own. Not long after that, our minds were freed by the Dark Lady."),
(29070,21,0,12,0,100,"special_surprise SAY_EXEC_NOREM_4","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a pint-sized force of reckoning. Every last ounce of good... Everything that made you a gnome!"),
(29070,22,0,12,0,100,"special_surprise SAY_EXEC_NOREM_5","You don't remember me, do you? Blasted Scourge...They've tried to drain of everything that made you a righteous force of reckoning. Every last ounce of good...Everything that made you a human!"),
(29070,23,0,12,0,100,"special_surprise SAY_EXEC_NOREM_6","You don't remember me? When you were a child your mother would leave you in my care while she served at the Temple of the Moon. I held you in my arms and fed you with honey and sheep's milk to calm you until she would return. You were my little angel. Blasted Scourge... What have they done to you, $N?"),
(29070,24,0,12,0,100,"special_surprise SAY_EXEC_NOREM_7","You don't recognize me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you an orc!"),
(29070,25,0,12,0,100,"special_surprise SAY_EXEC_NOREM_8","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a tauren!"),
(29070,26,0,12,0,100,"special_surprise SAY_EXEC_NOREM_9","You don't remember me, mon? Damn da Scourge! Dey gone ta drain you of everytin dat made ya a mojo masta. Every last ounce of good... Everytin' dat made ya a troll hero, mon!"),
(29070,27,0,12,0,100,"special_surprise SAY_EXEC_THINK_1","A pact was made, $Gbrother:sister;! We vowed vengeance against the Lich King! For what he had done to us! We battled the Scourge as Forsaken, pushing them back into the plaguelands and freeing Tirisfal! You and I were champions of the Forsaken!"),
(29070,28,0,12,0,100,"special_surprise SAY_EXEC_THINK_2","You must remember the splendor of life, $Gbrother:sister;. You were a champion of the Kaldorei once! This isn't you!"),
(29070,29,0,12,0,100,"special_surprise SAY_EXEC_THINK_3","Think, $N. Think back. Try and remember the majestic halls of Silvermoon City, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the sin'dorei once! This isn't you."),
(29070,30,0,12,0,100,"special_surprise SAY_EXEC_THINK_4","Think, $N. Think back. Try and remember the proud mountains of Argus, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the draenei once! This isn't you."),
(29070,31,0,12,0,100,"special_surprise SAY_EXEC_THINK_5","Think, $N. Think back. Try and remember the snow capped mountains o' Dun Morogh! Ye were born there, $Glad:lass;. Remember the splendor o' life, $N! Ye were a champion o' the dwarves once! This isn't ye!"),
(29070,32,0,12,0,100,"special_surprise SAY_EXEC_THINK_6","Think, $N. Think back. Try and remember Gnomeregan before those damned troggs! Remember the feel of an [arclight spanner] $Gbrother:sister;. You were a champion of gnome-kind once! This isn't you."),
(29070,33,0,12,0,100,"special_surprise SAY_EXEC_THINK_7","Think, $N. Think back. Try and remember the hills and valleys of Elwynn, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the Alliance once! This isn't you."),
(29070,34,0,12,0,100,"special_surprise SAY_EXEC_THINK_8","Think, $N. Think back. Try and remember Durotar, $Gbrother:sister;! Remember the sacrifices our heroes made so that we could be free of the blood curse. Harken back to the Valley of Trials, where we were reborn into a world without demonic influence. We found the splendor of life, $N. Together! This isn't you. You were a champion of the Horde once!"),
(29070,35,0,12,0,100,"special_surprise SAY_EXEC_THINK_9","Think, $N. Think back. Try and remember the rolling plains of Mulgore, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the tauren once! This isn't you."),
(29070,36,0,12,0,100,"special_surprise SAY_EXEC_THINK_10","TINK $N. Tink back, mon! We be Darkspear, mon! Bruddas and sistas! Remember when we fought the Zalazane and done took he head and freed da Echo Isles? MON! TINK! You was a champion of da Darkspear trolls!"),
(29070,37,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_1","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29070,38,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_2","Listen to me, $N Ye must fight against the Lich King's control. He's a monster that wants to see this world - our world - in ruin. Don't let him use ye to accomplish his goals. Ye were once a hero and ye can be again. Fight, damn ye! Fight his control!"),
(29070,39,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_3","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals AGAIN. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29070,40,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_4","Listen ta me, $Gbrudda:sista;. You must fight against da Lich King's control. He be a monstar dat want ta see dis world - our world - be ruined. Don't let he use you ta accomplish he goals. You be a hero once and you be a hero again! Fight it, mon! Fight he control!"),
(29070,42,0,12,0,100,"special_surprise SAY_EXEC_TIME_1","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Silvermoon. This world is worth saving!"),
(29070,43,0,12,0,100,"special_surprise SAY_EXEC_TIME_2","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Argus. Don't let that happen to this world."),
(29070,44,0,12,0,100,"special_surprise SAY_EXEC_TIME_3","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both $N... For KHAAAAAAAAZZZ MODAAAAAANNNNNN!!!"),
(29070,45,0,12,0,100,"special_surprise SAY_EXEC_TIME_4","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Tirisfal! This world is worth saving!"),
(29070,46,0,12,0,100,"special_surprise SAY_EXEC_TIME_5","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Gnomeregan! This world is worth saving."),
(29070,47,0,12,0,100,"special_surprise SAY_EXEC_TIME_6","There... There's no more time for me. I'm done for. FInish me off, $N. Do it or they'll kill us both. $N...Remember Elwynn. This world is worth saving."),
(29070,48,0,12,0,100,"special_surprise SAY_EXEC_TIME_7","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Teldrassil, our beloved home. This world is worth saving."),
(29070,49,0,12,0,100,"special_surprise SAY_EXEC_TIME_8","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... For the Horde! This world is worth saving."),
(29070,50,0,12,0,100,"special_surprise SAY_EXEC_TIME_9","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Mulgore. This world is worth saving."),
(29070,51,0,12,0,100,"special_surprise SAY_EXEC_TIME_10","Der... Der's no more time for me. I be done for. Finish me off $N. Do it or they'll kill us both. $N... Remember Sen'jin Village, mon! Dis world be worth saving!"),
(29070,52,0,12,0,100,"special_surprise SAY_EXEC_WAITING","Do it, $N! Put me out of my misery!"),
(29070,53,0,16,0,100,"special_surprise EMOTE_DIES","%s dies from his wounds."),
-- Lady Eonys
(29074,0,0,12,0,100,"special_surprise SAY_EXEC_START_1","Come to finish the job, have you?"),
(29074,1,0,12,0,100,"special_surprise SAY_EXEC_START_2","Come to finish the job, have ye?"),
(29074,2,0,12,0,100,"special_surprise SAY_EXEC_START_3","Come ta finish da job, mon?"),
(29074,3,0,12,0,100,"special_surprise SAY_EXEC_PROG_1","You'll look me in the eyes when..."),
(29074,4,0,12,0,100,"special_surprise SAY_EXEC_PROG_2","Well this son o' Ironforge would like..."),
(29074,5,0,12,0,100,"special_surprise SAY_EXEC_PROG_3","Ironic, isn't it? To be killed..."),
(29074,6,0,12,0,100,"special_surprise SAY_EXEC_PROG_4","If you'd allow me just one..."),
(29074,7,0,12,0,100,"special_surprise SAY_EXEC_PROG_5","I'd like to stand for..."),
(29074,8,0,12,0,100,"special_surprise SAY_EXEC_PROG_6","I want to die like an orc..."),
(29074,9,0,12,0,100,"special_surprise SAY_EXEC_PROG_7","Dis troll gonna stand for da..."),
(29074,10,0,12,0,100,"special_surprise SAY_EXEC_NAME_1","$N?"),
(29074,11,0,12,0,100,"special_surprise SAY_EXEC_NAME_2","$N? Mon?"),
(29074,12,0,12,0,100,"special_surprise SAY_EXEC_RECOG_1","$N, I'd recognize that face anywhere... What... What have they done to you, $N?"),
(29074,13,0,12,0,100,"special_surprise SAY_EXEC_RECOG_2","$N, I'd recognize those face tentacles anywhere... What... What have they done to you, $N?"),
(29074,14,0,12,0,100,"special_surprise SAY_EXEC_RECOG_3","$N, I'd recognize that face anywhere... What... What have they done to ye, $Glad:lass;?"),
(29074,15,0,12,0,100,"special_surprise SAY_EXEC_RECOG_4","$N, I'd recognize that decay anywhere... What... What have they done to you, $N?"),
(29074,16,0,12,0,100,"special_surprise SAY_EXEC_RECOG_5","$N, I'd recognize those horns anywhere... What have they done to you, $N?"),
(29074,17,0,12,0,100,"special_surprise SAY_EXEC_RECOG_6","$N, I'd recognize dem tusks anywhere... What... What have dey done ta you, mon?"),
(29074,18,0,12,0,100,"special_surprise SAY_EXEC_NOREM_1","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a draenei!"),
(29074,19,0,12,0,100,"special_surprise SAY_EXEC_NOREM_2","Ye don't remember me, do ye? Blasted Scourge... They've tried to drain ye o' everything that made ye a righteous force o' reckoning. Every last ounce o' good... Everything that made you a $Gson:daughter; of Ironforge!"),
(29074,20,0,12,0,100,"special_surprise SAY_EXEC_NOREM_3","You don't remember me, do you? We were humans once - long, long ago - until Lordaeron fell to the Scourge. Your transformation to a Scourge zombie came shortly after my own. Not long after that, our minds were freed by the Dark Lady."),
(29074,21,0,12,0,100,"special_surprise SAY_EXEC_NOREM_4","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a pint-sized force of reckoning. Every last ounce of good... Everything that made you a gnome!"),
(29074,22,0,12,0,100,"special_surprise SAY_EXEC_NOREM_5","You don't remember me, do you? Blasted Scourge...They've tried to drain of everything that made you a righteous force of reckoning. Every last ounce of good...Everything that made you a human!"),
(29074,23,0,12,0,100,"special_surprise SAY_EXEC_NOREM_6","You don't remember me? When you were a child your mother would leave you in my care while she served at the Temple of the Moon. I held you in my arms and fed you with honey and sheep's milk to calm you until she would return. You were my little angel. Blasted Scourge... What have they done to you, $N?"),
(29074,24,0,12,0,100,"special_surprise SAY_EXEC_NOREM_7","You don't recognize me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you an orc!"),
(29074,25,0,12,0,100,"special_surprise SAY_EXEC_NOREM_8","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a tauren!"),
(29074,26,0,12,0,100,"special_surprise SAY_EXEC_NOREM_9","You don't remember me, mon? Damn da Scourge! Dey gone ta drain you of everytin dat made ya a mojo masta. Every last ounce of good... Everytin' dat made ya a troll hero, mon!"),
(29074,27,0,12,0,100,"special_surprise SAY_EXEC_THINK_1","A pact was made, $Gbrother:sister;! We vowed vengeance against the Lich King! For what he had done to us! We battled the Scourge as Forsaken, pushing them back into the plaguelands and freeing Tirisfal! You and I were champions of the Forsaken!"),
(29074,28,0,12,0,100,"special_surprise SAY_EXEC_THINK_2","You must remember the splendor of life, $Gbrother:sister;. You were a champion of the Kaldorei once! This isn't you!"),
(29074,29,0,12,0,100,"special_surprise SAY_EXEC_THINK_3","Think, $N. Think back. Try and remember the majestic halls of Silvermoon City, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the sin'dorei once! This isn't you."),
(29074,30,0,12,0,100,"special_surprise SAY_EXEC_THINK_4","Think, $N. Think back. Try and remember the proud mountains of Argus, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the draenei once! This isn't you."),
(29074,31,0,12,0,100,"special_surprise SAY_EXEC_THINK_5","Think, $N. Think back. Try and remember the snow capped mountains o' Dun Morogh! Ye were born there, $Glad:lass;. Remember the splendor o' life, $N! Ye were a champion o' the dwarves once! This isn't ye!"),
(29074,32,0,12,0,100,"special_surprise SAY_EXEC_THINK_6","Think, $N. Think back. Try and remember Gnomeregan before those damned troggs! Remember the feel of an [arclight spanner] $Gbrother:sister;. You were a champion of gnome-kind once! This isn't you."),
(29074,33,0,12,0,100,"special_surprise SAY_EXEC_THINK_7","Think, $N. Think back. Try and remember the hills and valleys of Elwynn, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the Alliance once! This isn't you."),
(29074,34,0,12,0,100,"special_surprise SAY_EXEC_THINK_8","Think, $N. Think back. Try and remember Durotar, $Gbrother:sister;! Remember the sacrifices our heroes made so that we could be free of the blood curse. Harken back to the Valley of Trials, where we were reborn into a world without demonic influence. We found the splendor of life, $N. Together! This isn't you. You were a champion of the Horde once!"),
(29074,35,0,12,0,100,"special_surprise SAY_EXEC_THINK_9","Think, $N. Think back. Try and remember the rolling plains of Mulgore, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the tauren once! This isn't you."),
(29074,36,0,12,0,100,"special_surprise SAY_EXEC_THINK_10","TINK $N. Tink back, mon! We be Darkspear, mon! Bruddas and sistas! Remember when we fought the Zalazane and done took he head and freed da Echo Isles? MON! TINK! You was a champion of da Darkspear trolls!"),
(29074,37,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_1","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29074,38,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_2","Listen to me, $N Ye must fight against the Lich King's control. He's a monster that wants to see this world - our world - in ruin. Don't let him use ye to accomplish his goals. Ye were once a hero and ye can be again. Fight, damn ye! Fight his control!"),
(29074,39,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_3","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals AGAIN. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29074,40,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_4","Listen ta me, $Gbrudda:sista;. You must fight against da Lich King's control. He be a monstar dat want ta see dis world - our world - be ruined. Don't let he use you ta accomplish he goals. You be a hero once and you be a hero again! Fight it, mon! Fight he control!"),
(29074,42,0,12,0,100,"special_surprise SAY_EXEC_TIME_1","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Silvermoon. This world is worth saving!"),
(29074,43,0,12,0,100,"special_surprise SAY_EXEC_TIME_2","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Argus. Don't let that happen to this world."),
(29074,44,0,12,0,100,"special_surprise SAY_EXEC_TIME_3","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both $N... For KHAAAAAAAAZZZ MODAAAAAANNNNNN!!!"),
(29074,45,0,12,0,100,"special_surprise SAY_EXEC_TIME_4","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Tirisfal! This world is worth saving!"),
(29074,46,0,12,0,100,"special_surprise SAY_EXEC_TIME_5","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Gnomeregan! This world is worth saving."),
(29074,47,0,12,0,100,"special_surprise SAY_EXEC_TIME_6","There... There's no more time for me. I'm done for. FInish me off, $N. Do it or they'll kill us both. $N...Remember Elwynn. This world is worth saving."),
(29074,48,0,12,0,100,"special_surprise SAY_EXEC_TIME_7","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Teldrassil, our beloved home. This world is worth saving."),
(29074,49,0,12,0,100,"special_surprise SAY_EXEC_TIME_8","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... For the Horde! This world is worth saving."),
(29074,50,0,12,0,100,"special_surprise SAY_EXEC_TIME_9","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Mulgore. This world is worth saving."),
(29074,51,0,12,0,100,"special_surprise SAY_EXEC_TIME_10","Der... Der's no more time for me. I be done for. Finish me off $N. Do it or they'll kill us both. $N... Remember Sen'jin Village, mon! Dis world be worth saving!"),
(29074,52,0,12,0,100,"special_surprise SAY_EXEC_WAITING","Do it, $N! Put me out of my misery!"),
(29074,53,0,16,0,100,"special_surprise EMOTE_DIES","%s dies from his wounds."),
-- Kug Ironjaw
(29072,0,0,12,0,100,"special_surprise SAY_EXEC_START_1","Come to finish the job, have you?"),
(29072,1,0,12,0,100,"special_surprise SAY_EXEC_START_2","Come to finish the job, have ye?"),
(29072,2,0,12,0,100,"special_surprise SAY_EXEC_START_3","Come ta finish da job, mon?"),
(29072,3,0,12,0,100,"special_surprise SAY_EXEC_PROG_1","You'll look me in the eyes when..."),
(29072,4,0,12,0,100,"special_surprise SAY_EXEC_PROG_2","Well this son o' Ironforge would like..."),
(29072,5,0,12,0,100,"special_surprise SAY_EXEC_PROG_3","Ironic, isn't it? To be killed..."),
(29072,6,0,12,0,100,"special_surprise SAY_EXEC_PROG_4","If you'd allow me just one..."),
(29072,7,0,12,0,100,"special_surprise SAY_EXEC_PROG_5","I'd like to stand for..."),
(29072,8,0,12,0,100,"special_surprise SAY_EXEC_PROG_6","I want to die like an orc..."),
(29072,9,0,12,0,100,"special_surprise SAY_EXEC_PROG_7","Dis troll gonna stand for da..."),
(29072,10,0,12,0,100,"special_surprise SAY_EXEC_NAME_1","$N?"),
(29072,11,0,12,0,100,"special_surprise SAY_EXEC_NAME_2","$N? Mon?"),
(29072,12,0,12,0,100,"special_surprise SAY_EXEC_RECOG_1","$N, I'd recognize that face anywhere... What... What have they done to you, $N?"),
(29072,13,0,12,0,100,"special_surprise SAY_EXEC_RECOG_2","$N, I'd recognize those face tentacles anywhere... What... What have they done to you, $N?"),
(29072,14,0,12,0,100,"special_surprise SAY_EXEC_RECOG_3","$N, I'd recognize that face anywhere... What... What have they done to ye, $Glad:lass;?"),
(29072,15,0,12,0,100,"special_surprise SAY_EXEC_RECOG_4","$N, I'd recognize that decay anywhere... What... What have they done to you, $N?"),
(29072,16,0,12,0,100,"special_surprise SAY_EXEC_RECOG_5","$N, I'd recognize those horns anywhere... What have they done to you, $N?"),
(29072,17,0,12,0,100,"special_surprise SAY_EXEC_RECOG_6","$N, I'd recognize dem tusks anywhere... What... What have dey done ta you, mon?"),
(29072,18,0,12,0,100,"special_surprise SAY_EXEC_NOREM_1","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a draenei!"),
(29072,19,0,12,0,100,"special_surprise SAY_EXEC_NOREM_2","Ye don't remember me, do ye? Blasted Scourge... They've tried to drain ye o' everything that made ye a righteous force o' reckoning. Every last ounce o' good... Everything that made you a $Gson:daughter; of Ironforge!"),
(29072,20,0,12,0,100,"special_surprise SAY_EXEC_NOREM_3","You don't remember me, do you? We were humans once - long, long ago - until Lordaeron fell to the Scourge. Your transformation to a Scourge zombie came shortly after my own. Not long after that, our minds were freed by the Dark Lady."),
(29072,21,0,12,0,100,"special_surprise SAY_EXEC_NOREM_4","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a pint-sized force of reckoning. Every last ounce of good... Everything that made you a gnome!"),
(29072,22,0,12,0,100,"special_surprise SAY_EXEC_NOREM_5","You don't remember me, do you? Blasted Scourge...They've tried to drain of everything that made you a righteous force of reckoning. Every last ounce of good...Everything that made you a human!"),
(29072,23,0,12,0,100,"special_surprise SAY_EXEC_NOREM_6","You don't remember me? When you were a child your mother would leave you in my care while she served at the Temple of the Moon. I held you in my arms and fed you with honey and sheep's milk to calm you until she would return. You were my little angel. Blasted Scourge... What have they done to you, $N?"),
(29072,24,0,12,0,100,"special_surprise SAY_EXEC_NOREM_7","You don't recognize me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you an orc!"),
(29072,25,0,12,0,100,"special_surprise SAY_EXEC_NOREM_8","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a tauren!"),
(29072,26,0,12,0,100,"special_surprise SAY_EXEC_NOREM_9","You don't remember me, mon? Damn da Scourge! Dey gone ta drain you of everytin dat made ya a mojo masta. Every last ounce of good... Everytin' dat made ya a troll hero, mon!"),
(29072,27,0,12,0,100,"special_surprise SAY_EXEC_THINK_1","A pact was made, $Gbrother:sister;! We vowed vengeance against the Lich King! For what he had done to us! We battled the Scourge as Forsaken, pushing them back into the plaguelands and freeing Tirisfal! You and I were champions of the Forsaken!"),
(29072,28,0,12,0,100,"special_surprise SAY_EXEC_THINK_2","You must remember the splendor of life, $Gbrother:sister;. You were a champion of the Kaldorei once! This isn't you!"),
(29072,29,0,12,0,100,"special_surprise SAY_EXEC_THINK_3","Think, $N. Think back. Try and remember the majestic halls of Silvermoon City, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the sin'dorei once! This isn't you."),
(29072,30,0,12,0,100,"special_surprise SAY_EXEC_THINK_4","Think, $N. Think back. Try and remember the proud mountains of Argus, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the draenei once! This isn't you."),
(29072,31,0,12,0,100,"special_surprise SAY_EXEC_THINK_5","Think, $N. Think back. Try and remember the snow capped mountains o' Dun Morogh! Ye were born there, $Glad:lass;. Remember the splendor o' life, $N! Ye were a champion o' the dwarves once! This isn't ye!"),
(29072,32,0,12,0,100,"special_surprise SAY_EXEC_THINK_6","Think, $N. Think back. Try and remember Gnomeregan before those damned troggs! Remember the feel of an [arclight spanner] $Gbrother:sister;. You were a champion of gnome-kind once! This isn't you."),
(29072,33,0,12,0,100,"special_surprise SAY_EXEC_THINK_7","Think, $N. Think back. Try and remember the hills and valleys of Elwynn, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the Alliance once! This isn't you."),
(29072,34,0,12,0,100,"special_surprise SAY_EXEC_THINK_8","Think, $N. Think back. Try and remember Durotar, $Gbrother:sister;! Remember the sacrifices our heroes made so that we could be free of the blood curse. Harken back to the Valley of Trials, where we were reborn into a world without demonic influence. We found the splendor of life, $N. Together! This isn't you. You were a champion of the Horde once!"),
(29072,35,0,12,0,100,"special_surprise SAY_EXEC_THINK_9","Think, $N. Think back. Try and remember the rolling plains of Mulgore, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the tauren once! This isn't you."),
(29072,36,0,12,0,100,"special_surprise SAY_EXEC_THINK_10","TINK $N. Tink back, mon! We be Darkspear, mon! Bruddas and sistas! Remember when we fought the Zalazane and done took he head and freed da Echo Isles? MON! TINK! You was a champion of da Darkspear trolls!"),
(29072,37,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_1","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29072,38,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_2","Listen to me, $N Ye must fight against the Lich King's control. He's a monster that wants to see this world - our world - in ruin. Don't let him use ye to accomplish his goals. Ye were once a hero and ye can be again. Fight, damn ye! Fight his control!"),
(29072,39,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_3","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals AGAIN. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29072,40,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_4","Listen ta me, $Gbrudda:sista;. You must fight against da Lich King's control. He be a monstar dat want ta see dis world - our world - be ruined. Don't let he use you ta accomplish he goals. You be a hero once and you be a hero again! Fight it, mon! Fight he control!"),
(29072,42,0,12,0,100,"special_surprise SAY_EXEC_TIME_1","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Silvermoon. This world is worth saving!"),
(29072,43,0,12,0,100,"special_surprise SAY_EXEC_TIME_2","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Argus. Don't let that happen to this world."),
(29072,44,0,12,0,100,"special_surprise SAY_EXEC_TIME_3","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both $N... For KHAAAAAAAAZZZ MODAAAAAANNNNNN!!!"),
(29072,45,0,12,0,100,"special_surprise SAY_EXEC_TIME_4","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Tirisfal! This world is worth saving!"),
(29072,46,0,12,0,100,"special_surprise SAY_EXEC_TIME_5","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Gnomeregan! This world is worth saving."),
(29072,47,0,12,0,100,"special_surprise SAY_EXEC_TIME_6","There... There's no more time for me. I'm done for. FInish me off, $N. Do it or they'll kill us both. $N...Remember Elwynn. This world is worth saving."),
(29072,48,0,12,0,100,"special_surprise SAY_EXEC_TIME_7","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Teldrassil, our beloved home. This world is worth saving."),
(29072,49,0,12,0,100,"special_surprise SAY_EXEC_TIME_8","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... For the Horde! This world is worth saving."),
(29072,50,0,12,0,100,"special_surprise SAY_EXEC_TIME_9","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Mulgore. This world is worth saving."),
(29072,51,0,12,0,100,"special_surprise SAY_EXEC_TIME_10","Der... Der's no more time for me. I be done for. Finish me off $N. Do it or they'll kill us both. $N... Remember Sen'jin Village, mon! Dis world be worth saving!"),
(29072,52,0,12,0,100,"special_surprise SAY_EXEC_WAITING","Do it, $N! Put me out of my misery!"),
(29072,53,0,16,0,100,"special_surprise EMOTE_DIES","%s dies from his wounds."),
-- Iggy Darktusk
(29073,0,0,12,0,100,"special_surprise SAY_EXEC_START_1","Come to finish the job, have you?"),
(29073,1,0,12,0,100,"special_surprise SAY_EXEC_START_2","Come to finish the job, have ye?"),
(29073,2,0,12,0,100,"special_surprise SAY_EXEC_START_3","Come ta finish da job, mon?"),
(29073,3,0,12,0,100,"special_surprise SAY_EXEC_PROG_1","You'll look me in the eyes when..."),
(29073,4,0,12,0,100,"special_surprise SAY_EXEC_PROG_2","Well this son o' Ironforge would like..."),
(29073,5,0,12,0,100,"special_surprise SAY_EXEC_PROG_3","Ironic, isn't it? To be killed..."),
(29073,6,0,12,0,100,"special_surprise SAY_EXEC_PROG_4","If you'd allow me just one..."),
(29073,7,0,12,0,100,"special_surprise SAY_EXEC_PROG_5","I'd like to stand for..."),
(29073,8,0,12,0,100,"special_surprise SAY_EXEC_PROG_6","I want to die like an orc..."),
(29073,9,0,12,0,100,"special_surprise SAY_EXEC_PROG_7","Dis troll gonna stand for da..."),
(29073,10,0,12,0,100,"special_surprise SAY_EXEC_NAME_1","$N?"),
(29073,11,0,12,0,100,"special_surprise SAY_EXEC_NAME_2","$N? Mon?"),
(29073,12,0,12,0,100,"special_surprise SAY_EXEC_RECOG_1","$N, I'd recognize that face anywhere... What... What have they done to you, $N?"),
(29073,13,0,12,0,100,"special_surprise SAY_EXEC_RECOG_2","$N, I'd recognize those face tentacles anywhere... What... What have they done to you, $N?"),
(29073,14,0,12,0,100,"special_surprise SAY_EXEC_RECOG_3","$N, I'd recognize that face anywhere... What... What have they done to ye, $Glad:lass;?"),
(29073,15,0,12,0,100,"special_surprise SAY_EXEC_RECOG_4","$N, I'd recognize that decay anywhere... What... What have they done to you, $N?"),
(29073,16,0,12,0,100,"special_surprise SAY_EXEC_RECOG_5","$N, I'd recognize those horns anywhere... What have they done to you, $N?"),
(29073,17,0,12,0,100,"special_surprise SAY_EXEC_RECOG_6","$N, I'd recognize dem tusks anywhere... What... What have dey done ta you, mon?"),
(29073,18,0,12,0,100,"special_surprise SAY_EXEC_NOREM_1","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a draenei!"),
(29073,19,0,12,0,100,"special_surprise SAY_EXEC_NOREM_2","Ye don't remember me, do ye? Blasted Scourge... They've tried to drain ye o' everything that made ye a righteous force o' reckoning. Every last ounce o' good... Everything that made you a $Gson:daughter; of Ironforge!"),
(29073,20,0,12,0,100,"special_surprise SAY_EXEC_NOREM_3","You don't remember me, do you? We were humans once - long, long ago - until Lordaeron fell to the Scourge. Your transformation to a Scourge zombie came shortly after my own. Not long after that, our minds were freed by the Dark Lady."),
(29073,21,0,12,0,100,"special_surprise SAY_EXEC_NOREM_4","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a pint-sized force of reckoning. Every last ounce of good... Everything that made you a gnome!"),
(29073,22,0,12,0,100,"special_surprise SAY_EXEC_NOREM_5","You don't remember me, do you? Blasted Scourge...They've tried to drain of everything that made you a righteous force of reckoning. Every last ounce of good...Everything that made you a human!"),
(29073,23,0,12,0,100,"special_surprise SAY_EXEC_NOREM_6","You don't remember me? When you were a child your mother would leave you in my care while she served at the Temple of the Moon. I held you in my arms and fed you with honey and sheep's milk to calm you until she would return. You were my little angel. Blasted Scourge... What have they done to you, $N?"),
(29073,24,0,12,0,100,"special_surprise SAY_EXEC_NOREM_7","You don't recognize me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you an orc!"),
(29073,25,0,12,0,100,"special_surprise SAY_EXEC_NOREM_8","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a tauren!"),
(29073,26,0,12,0,100,"special_surprise SAY_EXEC_NOREM_9","You don't remember me, mon? Damn da Scourge! Dey gone ta drain you of everytin dat made ya a mojo masta. Every last ounce of good... Everytin' dat made ya a troll hero, mon!"),
(29073,27,0,12,0,100,"special_surprise SAY_EXEC_THINK_1","A pact was made, $Gbrother:sister;! We vowed vengeance against the Lich King! For what he had done to us! We battled the Scourge as Forsaken, pushing them back into the plaguelands and freeing Tirisfal! You and I were champions of the Forsaken!"),
(29073,28,0,12,0,100,"special_surprise SAY_EXEC_THINK_2","You must remember the splendor of life, $Gbrother:sister;. You were a champion of the Kaldorei once! This isn't you!"),
(29073,29,0,12,0,100,"special_surprise SAY_EXEC_THINK_3","Think, $N. Think back. Try and remember the majestic halls of Silvermoon City, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the sin'dorei once! This isn't you."),
(29073,30,0,12,0,100,"special_surprise SAY_EXEC_THINK_4","Think, $N. Think back. Try and remember the proud mountains of Argus, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the draenei once! This isn't you."),
(29073,31,0,12,0,100,"special_surprise SAY_EXEC_THINK_5","Think, $N. Think back. Try and remember the snow capped mountains o' Dun Morogh! Ye were born there, $Glad:lass;. Remember the splendor o' life, $N! Ye were a champion o' the dwarves once! This isn't ye!"),
(29073,32,0,12,0,100,"special_surprise SAY_EXEC_THINK_6","Think, $N. Think back. Try and remember Gnomeregan before those damned troggs! Remember the feel of an [arclight spanner] $Gbrother:sister;. You were a champion of gnome-kind once! This isn't you."),
(29073,33,0,12,0,100,"special_surprise SAY_EXEC_THINK_7","Think, $N. Think back. Try and remember the hills and valleys of Elwynn, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the Alliance once! This isn't you."),
(29073,34,0,12,0,100,"special_surprise SAY_EXEC_THINK_8","Think, $N. Think back. Try and remember Durotar, $Gbrother:sister;! Remember the sacrifices our heroes made so that we could be free of the blood curse. Harken back to the Valley of Trials, where we were reborn into a world without demonic influence. We found the splendor of life, $N. Together! This isn't you. You were a champion of the Horde once!"),
(29073,35,0,12,0,100,"special_surprise SAY_EXEC_THINK_9","Think, $N. Think back. Try and remember the rolling plains of Mulgore, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the tauren once! This isn't you."),
(29073,36,0,12,0,100,"special_surprise SAY_EXEC_THINK_10","TINK $N. Tink back, mon! We be Darkspear, mon! Bruddas and sistas! Remember when we fought the Zalazane and done took he head and freed da Echo Isles? MON! TINK! You was a champion of da Darkspear trolls!"),
(29073,37,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_1","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29073,38,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_2","Listen to me, $N Ye must fight against the Lich King's control. He's a monster that wants to see this world - our world - in ruin. Don't let him use ye to accomplish his goals. Ye were once a hero and ye can be again. Fight, damn ye! Fight his control!"),
(29073,39,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_3","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals AGAIN. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29073,40,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_4","Listen ta me, $Gbrudda:sista;. You must fight against da Lich King's control. He be a monstar dat want ta see dis world - our world - be ruined. Don't let he use you ta accomplish he goals. You be a hero once and you be a hero again! Fight it, mon! Fight he control!"),
(29073,42,0,12,0,100,"special_surprise SAY_EXEC_TIME_1","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Silvermoon. This world is worth saving!"),
(29073,43,0,12,0,100,"special_surprise SAY_EXEC_TIME_2","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Argus. Don't let that happen to this world."),
(29073,44,0,12,0,100,"special_surprise SAY_EXEC_TIME_3","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both $N... For KHAAAAAAAAZZZ MODAAAAAANNNNNN!!!"),
(29073,45,0,12,0,100,"special_surprise SAY_EXEC_TIME_4","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Tirisfal! This world is worth saving!"),
(29073,46,0,12,0,100,"special_surprise SAY_EXEC_TIME_5","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Gnomeregan! This world is worth saving."),
(29073,47,0,12,0,100,"special_surprise SAY_EXEC_TIME_6","There... There's no more time for me. I'm done for. FInish me off, $N. Do it or they'll kill us both. $N...Remember Elwynn. This world is worth saving."),
(29073,48,0,12,0,100,"special_surprise SAY_EXEC_TIME_7","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Teldrassil, our beloved home. This world is worth saving."),
(29073,49,0,12,0,100,"special_surprise SAY_EXEC_TIME_8","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... For the Horde! This world is worth saving."),
(29073,50,0,12,0,100,"special_surprise SAY_EXEC_TIME_9","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Mulgore. This world is worth saving."),
(29073,51,0,12,0,100,"special_surprise SAY_EXEC_TIME_10","Der... Der's no more time for me. I be done for. Finish me off $N. Do it or they'll kill us both. $N... Remember Sen'jin Village, mon! Dis world be worth saving!"),
(29073,52,0,12,0,100,"special_surprise SAY_EXEC_WAITING","Do it, $N! Put me out of my misery!"),
(29073,53,0,16,0,100,"special_surprise EMOTE_DIES","%s dies from his wounds."),
-- Antoine Brack
(29071,0,0,12,0,100,"special_surprise SAY_EXEC_START_1","Come to finish the job, have you?"),
(29071,1,0,12,0,100,"special_surprise SAY_EXEC_START_2","Come to finish the job, have ye?"),
(29071,2,0,12,0,100,"special_surprise SAY_EXEC_START_3","Come ta finish da job, mon?"),
(29071,3,0,12,0,100,"special_surprise SAY_EXEC_PROG_1","You'll look me in the eyes when..."),
(29071,4,0,12,0,100,"special_surprise SAY_EXEC_PROG_2","Well this son o' Ironforge would like..."),
(29071,5,0,12,0,100,"special_surprise SAY_EXEC_PROG_3","Ironic, isn't it? To be killed..."),
(29071,6,0,12,0,100,"special_surprise SAY_EXEC_PROG_4","If you'd allow me just one..."),
(29071,7,0,12,0,100,"special_surprise SAY_EXEC_PROG_5","I'd like to stand for..."),
(29071,8,0,12,0,100,"special_surprise SAY_EXEC_PROG_6","I want to die like an orc..."),
(29071,9,0,12,0,100,"special_surprise SAY_EXEC_PROG_7","Dis troll gonna stand for da..."),
(29071,10,0,12,0,100,"special_surprise SAY_EXEC_NAME_1","$N?"),
(29071,11,0,12,0,100,"special_surprise SAY_EXEC_NAME_2","$N? Mon?"),
(29071,12,0,12,0,100,"special_surprise SAY_EXEC_RECOG_1","$N, I'd recognize that face anywhere... What... What have they done to you, $N?"),
(29071,13,0,12,0,100,"special_surprise SAY_EXEC_RECOG_2","$N, I'd recognize those face tentacles anywhere... What... What have they done to you, $N?"),
(29071,14,0,12,0,100,"special_surprise SAY_EXEC_RECOG_3","$N, I'd recognize that face anywhere... What... What have they done to ye, $Glad:lass;?"),
(29071,15,0,12,0,100,"special_surprise SAY_EXEC_RECOG_4","$N, I'd recognize that decay anywhere... What... What have they done to you, $N?"),
(29071,16,0,12,0,100,"special_surprise SAY_EXEC_RECOG_5","$N, I'd recognize those horns anywhere... What have they done to you, $N?"),
(29071,17,0,12,0,100,"special_surprise SAY_EXEC_RECOG_6","$N, I'd recognize dem tusks anywhere... What... What have dey done ta you, mon?"),
(29071,18,0,12,0,100,"special_surprise SAY_EXEC_NOREM_1","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a draenei!"),
(29071,19,0,12,0,100,"special_surprise SAY_EXEC_NOREM_2","Ye don't remember me, do ye? Blasted Scourge... They've tried to drain ye o' everything that made ye a righteous force o' reckoning. Every last ounce o' good... Everything that made you a $Gson:daughter; of Ironforge!"),
(29071,20,0,12,0,100,"special_surprise SAY_EXEC_NOREM_3","You don't remember me, do you? We were humans once - long, long ago - until Lordaeron fell to the Scourge. Your transformation to a Scourge zombie came shortly after my own. Not long after that, our minds were freed by the Dark Lady."),
(29071,21,0,12,0,100,"special_surprise SAY_EXEC_NOREM_4","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a pint-sized force of reckoning. Every last ounce of good... Everything that made you a gnome!"),
(29071,22,0,12,0,100,"special_surprise SAY_EXEC_NOREM_5","You don't remember me, do you? Blasted Scourge...They've tried to drain of everything that made you a righteous force of reckoning. Every last ounce of good...Everything that made you a human!"),
(29071,23,0,12,0,100,"special_surprise SAY_EXEC_NOREM_6","You don't remember me? When you were a child your mother would leave you in my care while she served at the Temple of the Moon. I held you in my arms and fed you with honey and sheep's milk to calm you until she would return. You were my little angel. Blasted Scourge... What have they done to you, $N?"),
(29071,24,0,12,0,100,"special_surprise SAY_EXEC_NOREM_7","You don't recognize me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you an orc!"),
(29071,25,0,12,0,100,"special_surprise SAY_EXEC_NOREM_8","You don't remember me, do you? Blasted Scourge... They've tried to drain you of everything that made you a righteous force of reckoning. Every last ounce of good... Everything that made you a tauren!"),
(29071,26,0,12,0,100,"special_surprise SAY_EXEC_NOREM_9","You don't remember me, mon? Damn da Scourge! Dey gone ta drain you of everytin dat made ya a mojo masta. Every last ounce of good... Everytin' dat made ya a troll hero, mon!"),
(29071,27,0,12,0,100,"special_surprise SAY_EXEC_THINK_1","A pact was made, $Gbrother:sister;! We vowed vengeance against the Lich King! For what he had done to us! We battled the Scourge as Forsaken, pushing them back into the plaguelands and freeing Tirisfal! You and I were champions of the Forsaken!"),
(29071,28,0,12,0,100,"special_surprise SAY_EXEC_THINK_2","You must remember the splendor of life, $Gbrother:sister;. You were a champion of the Kaldorei once! This isn't you!"),
(29071,29,0,12,0,100,"special_surprise SAY_EXEC_THINK_3","Think, $N. Think back. Try and remember the majestic halls of Silvermoon City, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the sin'dorei once! This isn't you."),
(29071,30,0,12,0,100,"special_surprise SAY_EXEC_THINK_4","Think, $N. Think back. Try and remember the proud mountains of Argus, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the draenei once! This isn't you."),
(29071,31,0,12,0,100,"special_surprise SAY_EXEC_THINK_5","Think, $N. Think back. Try and remember the snow capped mountains o' Dun Morogh! Ye were born there, $Glad:lass;. Remember the splendor o' life, $N! Ye were a champion o' the dwarves once! This isn't ye!"),
(29071,32,0,12,0,100,"special_surprise SAY_EXEC_THINK_6","Think, $N. Think back. Try and remember Gnomeregan before those damned troggs! Remember the feel of an [arclight spanner] $Gbrother:sister;. You were a champion of gnome-kind once! This isn't you."),
(29071,33,0,12,0,100,"special_surprise SAY_EXEC_THINK_7","Think, $N. Think back. Try and remember the hills and valleys of Elwynn, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the Alliance once! This isn't you."),
(29071,34,0,12,0,100,"special_surprise SAY_EXEC_THINK_8","Think, $N. Think back. Try and remember Durotar, $Gbrother:sister;! Remember the sacrifices our heroes made so that we could be free of the blood curse. Harken back to the Valley of Trials, where we were reborn into a world without demonic influence. We found the splendor of life, $N. Together! This isn't you. You were a champion of the Horde once!"),
(29071,35,0,12,0,100,"special_surprise SAY_EXEC_THINK_9","Think, $N. Think back. Try and remember the rolling plains of Mulgore, where you were born. Remember the splendor of life, $Gbrother:sister;. You were a champion of the tauren once! This isn't you."),
(29071,36,0,12,0,100,"special_surprise SAY_EXEC_THINK_10","TINK $N. Tink back, mon! We be Darkspear, mon! Bruddas and sistas! Remember when we fought the Zalazane and done took he head and freed da Echo Isles? MON! TINK! You was a champion of da Darkspear trolls!"),
(29071,37,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_1","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29071,38,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_2","Listen to me, $N Ye must fight against the Lich King's control. He's a monster that wants to see this world - our world - in ruin. Don't let him use ye to accomplish his goals. Ye were once a hero and ye can be again. Fight, damn ye! Fight his control!"),
(29071,39,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_3","Listen to me, $N. You must fight against the Lich King's control. He is a monster that wants to see this world - our world - in ruin. Don't let him use you to accomplish his goals AGAIN. You were once a hero and you can be again. Fight, damn you! Fight his control!"),
(29071,40,0,12,0,100,"special_surprise SAY_EXEC_LISTEN_4","Listen ta me, $Gbrudda:sista;. You must fight against da Lich King's control. He be a monstar dat want ta see dis world - our world - be ruined. Don't let he use you ta accomplish he goals. You be a hero once and you be a hero again! Fight it, mon! Fight he control!"),
(29071,42,0,12,0,100,"special_surprise SAY_EXEC_TIME_1","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Silvermoon. This world is worth saving!"),
(29071,43,0,12,0,100,"special_surprise SAY_EXEC_TIME_2","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Argus. Don't let that happen to this world."),
(29071,44,0,12,0,100,"special_surprise SAY_EXEC_TIME_3","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both $N... For KHAAAAAAAAZZZ MODAAAAAANNNNNN!!!"),
(29071,45,0,12,0,100,"special_surprise SAY_EXEC_TIME_4","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Tirisfal! This world is worth saving!"),
(29071,46,0,12,0,100,"special_surprise SAY_EXEC_TIME_5","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Gnomeregan! This world is worth saving."),
(29071,47,0,12,0,100,"special_surprise SAY_EXEC_TIME_6","There... There's no more time for me. I'm done for. FInish me off, $N. Do it or they'll kill us both. $N...Remember Elwynn. This world is worth saving."),
(29071,48,0,12,0,100,"special_surprise SAY_EXEC_TIME_7","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Teldrassil, our beloved home. This world is worth saving."),
(29071,49,0,12,0,100,"special_surprise SAY_EXEC_TIME_8","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... For the Horde! This world is worth saving."),
(29071,50,0,12,0,100,"special_surprise SAY_EXEC_TIME_9","There... There's no more time for me. I'm done for. Finish me off, $N. Do it or they'll kill us both. $N... Remember Mulgore. This world is worth saving."),
(29071,51,0,12,0,100,"special_surprise SAY_EXEC_TIME_10","Der... Der's no more time for me. I be done for. Finish me off $N. Do it or they'll kill us both. $N... Remember Sen'jin Village, mon! Dis world be worth saving!"),
(29071,52,0,12,0,100,"special_surprise SAY_EXEC_WAITING","Do it, $N! Put me out of my misery!"),
(29071,53,0,16,0,100,"special_surprise EMOTE_DIES","%s dies from his wounds."),
-- Plaguefist
(29053,41,0,14,0,100,"special_surprise SAY_PLAGUEFIST","What's going on in there? What's taking so long, $N?");

-- Highlord Darion Mograine
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1609286 AND -1609201;
DELETE FROM `creature_text` WHERE `entry` IN (29183,29175,29227,29228,29176,29178,29204,29173);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(29173,0,0,14,14677,100,"Highlord Darion Mograine","Soldiers of the Scourge, stand ready! You will soon be able to unleash your fury upon the Argent Dawn!"),
(29173,1,0,14,14678,100,"Highlord Darion Mograine","The sky weeps at the devastation of sister earth! Soon, tears of blood will rain down upon us!"),
(29173,2,0,14,14681,100,"Highlord Darion Mograine","Death knights of Acherus, the death march begins!"),
(29173,3,0,14,14679,100,"Highlord Darion Mograine","Soldiers of the Scourge, death knights of Acherus, minions of the darkness: hear the call of the Highlord!"),
(29173,4,0,14,14680,100,"Highlord Darion Mograine","RISE!"),
(29173,5,0,14,14682,100,"Highlord Darion Mograine","The skies turn red with the blood of the fallen! The Lich King watches over us, minions! Onward! Leave only ashes and misery in your destructive wake!"),
(29176,6,0,14,0,100,"Korfax, Champion of the Light","Scourge armies approach!"),
(29178,7,0,14,14487,100,"Lord Maxwell Tyrosus","Stand fast, brothers and sisters! The Light will prevail!"),
(29173,8,0,12,14683,100,"Highlord Darion Mograine","Kneel before the Highlord!"),
(29173,8,1,12,14684,100,"Highlord Darion Mograine","You stand no chance!"),
(29173,8,2,12,14685,100,"Highlord Darion Mograine","The Scourge will destroy this place!"),
(29173,8,3,12,14686,100,"Highlord Darion Mograine","Your life is forfeit."),
(29173,8,4,12,14687,100,"Highlord Darion Mograine","Life is meaningless without suffering."),
(29173,8,5,12,14688,100,"Highlord Darion Mograine","How much longer will your forces hold out?"),
(29173,8,6,12,14689,100,"Highlord Darion Mograine","The Argent Dawn is finished!"),
(29173,8,7,12,14690,100,"Highlord Darion Mograine","Spare no one!"),
(29173,8,8,12,14691,100,"Highlord Darion Mograine","What is this?! My... I cannot strike..."),
(29173,8,9,14,14692,100,"Highlord Darion Mograine","Obey me, blade!"),
(29173,8,10,12,14693,100,"Highlord Darion Mograine","You will do as I command! I am in control here!"),
(29173,8,11,12,14694,100,"Highlord Darion Mograine","I can not... the blade fights me."),
(29173,8,12,12,14695,100,"Highlord Darion Mograine","What is happening to me?"),
(29173,8,13,12,14696,100,"Highlord Darion Mograine","Power...wanes..."),
(29173,8,14,12,14697,100,"Highlord Darion Mograine","Ashbringer defies me..."),
(29173,8,15,12,14698,100,"Highlord Darion Mograine","Minions, come to my aid!"),
(29175,24,0,14,14584,100,"Highlord Tirion Fordring","You cannot win, Darion!"),
(29175,25,0,14,14585,100,"Highlord Tirion Fordring","Bring them before the chapel!"),
(29173,26,0,12,14699,100,"Highlord Darion Mograine","Stand down, death knights. We have lost... The Light... This place... No hope..."),
(29175,27,0,12,14586,100,"Highlord Tirion Fordring","Have you learned nothing, boy? You have become all that your father fought against! Like that coward, Arthas, you allowed yourself to be consumed by the darkness...the hate... Feeding upon the misery of those you tortured and killed!"),
(29175,28,0,12,14587,100,"Highlord Tirion Fordring","Your master knows what lies beneath the chapel. It is why he dares not show his face! He's sent you and your death knights to meet their doom, Darion."),
(29175,29,0,12,14588,100,"Highlord Tirion Fordring","What you are feeling right now is the anguish of a thousand lost souls! Souls that you and your master brought here! The Light will tear you apart, Darion!"),
(29173,30,0,12,14700,100,"Highlord Darion Mograine","Save your breath, old man. It might be the last you ever draw."),
(29227,31,0,12,14493,100,"Highlord Alexandros Mograine","My son! My dear, beautiful boy!"),
(29173,32,0,12,14701,100,"Highlord Darion Mograine","Father!"),
(29173,33,0,12,14702,100,"Highlord Darion Mograine","Argh...what...is..."),
(29228,34,0,12,14703,100,"Darion Mograine","Father, you have returned!"),
(29228,35,0,12,14704,100,"Darion Mograine","You have been gone a long time, father. I thought..."),
(29227,36,0,12,14494,100,"Highlord Alexandros Mograine","Nothing could have kept me away from here, Darion. Not from my home and family."),
(29228,37,0,12,14705,100,"Darion Mograine","Father, I wish to join you in the war against the undead. I want to fight! I can sit idle no longer!"),
(29227,38,0,12,14495,100,"Highlord Alexandros Mograine","Darion Mograine, you are barely of age to hold a sword, let alone battle the undead hordes of Lordaeron! I couldn't bear losing you. Even the thought..."),
(29228,39,0,12,14706,100,"Darion Mograine","If I die, father, I would rather it be on my feet, standing in defiance against the undead legions! If I die, father, I die with you!"),
(29227,40,0,12,14496,100,"Highlord Alexandros Mograine","My son, there will come a day when you will command the Ashbringer and, with it, mete justice across this land. I have no doubt that when that day finally comes, you will bring pride to our people and that Lordaeron will be a better place because of you. But, my son, that day is not today."),
(29227,41,0,12,14497,100,"Highlord Alexandros Mograine","Do not forget..."),
(29183,42,0,14,14803,100,"The Lich King","Touching..."),
(29173,43,0,14,14707,100,"Highlord Darion Mograine","You have've betrayed me! You betrayed us all you monster! Face the might of Mograine!"),
(29183,44,0,12,14805,100,"The Lich King","He's mine now..."),
(29183,45,0,12,14804,100,"The Lich King","Pathetic..."),
(29175,46,0,12,14589,100,"Highlord Tirion Fordring","You're a damned monster, Arthas!"),
(29183,47,0,12,14806,100,"The Lich King","You were right, Fordring. I did send them in to die. Their lives are meaningless, but yours..."),
(29183,48,0,12,14807,100,"The Lich King","How simple it was to draw the great Tirion Fordring out of hiding. You've left yourself exposed, paladin. Nothing will save you..."),
(29178,49,0,14,14488,100,"Lord Maxwell Tyrosus","ATTACK!!!"),
(29183,50,0,14,14808,100,"The Lich King","APOCALYPSE!"),
(29173,51,0,12,14708,100,"Highlord Darion Mograine","That day is not today..."),
(29173,52,0,14,14709,100,"Highlord Darion Mograine","Tirion!"),
(29175,53,0,14,14591,100,"Highlord Tirion Fordring","ARTHAS!!!!"),
(29183,54,0,14,14809,100,"The Lich King","What is this?"),
(29175,55,0,14,14592,100,"Highlord Tirion Fordring","Your end."),
(29183,56,0,14,14810,100,"The Lich King","Impossible..."),
(29183,57,0,14,14811,100,"The Lich King","This... isn't... over..."),
(29183,58,0,14,14812,100,"The Lich King","When next we meet it won't be on holy ground, paladin."),
(29175,59,0,12,14593,100,"Highlord Tirion Fordring","Rise, Darion, and listen..."),
(29175,60,0,12,14594,100,"Highlord Tirion Fordring","We have all been witness to a terrible tragedy. The blood of good men has been shed upon this soil! Honorable knights, slain defending their lives - our lives!"),
(29175,61,0,12,14595,100,"Highlord Tirion Fordring","And while such things can never be forgotten, we must remain vigilant in our cause!"),
(29175,62,0,12,14596,100,"Highlord Tirion Fordring","The Lich King must answer for what he has done and must not be allowed to cause further destruction to our world."),
(29175,63,0,12,14597,100,"Highlord Tirion Fordring","I make a promise to you now, brothers and sisters: The Lich King will be defeated! On this day, I call for a union."),
(29175,64,0,12,14598,100,"Highlord Tirion Fordring","The Argent Dawn and the Order of the Silver Hand will come together as one! We will succeed where so many before us have failed!"),
(29175,65,0,12,14599,100,"Highlord Tirion Fordring","We will take the fight to Arthas and tear down the walls of Icecrown!"),
(29175,66,0,14,14600,100,"Highlord Tirion Fordring","The Argent Crusade comes for you, Arthas!"),
(29173,67,0,12,14710,100,"Highlord Darion Mograine","So too do the Knights of the Ebon Blade... While our kind has no place in your world, we will fight to bring an end to the Lich King. This I vow!"),
(29173,68,0,16,0,100,"","Thousands of Scourge rise up at the Highlord's command."),
(29173,69,0,16,0,100,"","The army marches towards Light's Hope Chapel."),
(29173,70,0,16,0,100,"","After over a hundred Defenders of the Light fall, Highlord Tirion Fordring arrives."),
(29204,71,0,16,0,100,"Orbaz","%s flee"),
(29173,72,0,16,0,100,"Highlord Darion Mograine","%s kneels in defeat before Tirion Fordring."),
(29227,73,0,16,0,100,"Highlord Alexandros Mograine","%s arrives."),
(29173,74,0,16,0,100,"Highlord Darion Mograine","%s becomes a shade of his past, and walks up to his father."),
(29228,75,0,16,0,100,"Darion Mograine","%s hugs his father."),
(29173,76,0,16,0,100,"Alexandros","%s disappears, and the Lich King appears."),
(29173,77,0,16,0,100,"Highlord Darion Mograine","%s becomes himself again...and is now angry."),
(29183,78,0,16,0,100,"The Lich King","%s casts a spell on Tirion."),
(29175,79,0,16,0,100,"Highlord Tirion Fordring","%s gasps for air."),
(29183,80,0,16,0,100,"The Lich King","%s casts a powerful spell, killing the Defenders and knocking back the others."),
(29173,81,0,16,0,100,"Highlord Darion Mograine","%s throws the Corrupted Ashbringer to Tirion, who catches it. Tirion becomes awash with Light, and the Ashbringer is cleansed."),
(29173,82,0,16,0,100,"Highlord Darion Mograine","%s collapses."),
(29175,83,0,16,0,100,"Highlord Tirion Fordring","%s charges towards the Lich King, Ashbringer in hand and strikes the Lich King."),
(29183,84,0,16,0,100,"The Lich King","%s disappears. Tirion walks over to where Darion lay"),
(29173,85,0,16,0,100,"","Light washes over the chapel ? the Light of Dawn is uncovered.");

-- grimstone
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1230008 AND -1230003;
DELETE FROM `creature_text` WHERE `entry`=10096;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(10096,0,0,14,0,100,"grimstone SCRIPT_TEXT1","You have been sentenced to death for crimes against the Dark Iron nation!"),
(10096,1,0,14,0,100,"grimstone SCRIPT_TEXT2","The Sons of Thaurissan shall watch you perish in the Ring of the Law!"),
(10096,2,0,14,0,100,"grimstone SCRIPT_TEXT3","Unleash the fury and let it be done!"),
(10096,3,0,14,0,100,"grimstone SCRIPT_TEXT4","Haha! I bet you thought you were done!"),
(10096,4,0,14,0,100,"grimstone SCRIPT_TEXT5","But your real punishment lies ahead."),
(10096,5,0,14,0,100,"grimstone SCRIPT_TEXT6","Good riddance!");

-- rocknot
DELETE FROM `script_texts` WHERE `entry`=-1230000;
DELETE FROM `creature_text` WHERE `entry`=9503;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(9503,0,0,12,0,100,"rocknot SAY_GOT_BEER","Ah, hits the spot!");

-- doctor theolen krastinov
-- No delete query here, it's a generic script text for frenzy emotes.
DELETE FROM `creature_text` WHERE `entry`=9028;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(9028,0,0,16,0,100,"grizzle EMOTE_FRENZY_KILL","%s goes into a killing frenzy!");

-- dagran
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1230002 AND -1230001;
DELETE FROM `creature_text` WHERE `entry`=9019;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(9019,0,0,14,0,100,"dagran SAY_AGGRO","Come to aid the Throne!"),
(9019,1,0,14,0,100,"dagran SAY_SLAY","Hail to the king, baby!");

-- lilatha
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000146 AND -1000140;
DELETE FROM `creature_text` WHERE `entry` IN (16295,16220);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(16295,0,0,12,0,100,"lilatha SAY_START","Let's go."),
(16295,1,0,12,0,100,"lilatha SAY_PROGRESS1","$N, let's use the antechamber to the right."),
(16295,2,0,12,0,100,"lilatha SAY_PROGRESS2","I can see the light at the end of the tunnel!"),
(16295,3,0,12,0,100,"lilatha SAY_PROGRESS3","There's Farstrider Enclave now, $C. Not far to go... Look out! Troll ambush!!"),
(16295,4,0,12,0,100,"lilatha SAY_END1","Thank you for saving my life and bringing me back to safety, $N"),
(16295,5,0,12,0,100,"lilatha SAY_END2","Captain Helios, I've been rescued from the Amani Catacombs. Reporting for duty, sir!"),
(16220,0,0,12,0,100,"lilatha CAPTAIN_ANSWER","Liatha, get someone to look at those injuries. Thank you for bringing her back safely.");

-- stillblade
DELETE FROM `script_texts` WHERE `entry`=-1000193;
DELETE FROM `creature_text` WHERE `entry`=17768;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(17768,0,0,12,0,100,"stillblade SAY_HEAL","Thank you, dear $C, you just saved my life.");

-- stilwell
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000297 AND -1000293;
DELETE FROM `creature_text` WHERE `entry`=6182;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(6182,0,0,12,0,100,"stilwell SAY_DS_START","To the house! Stay close to me, no matter what! I have my gun and ammo there!"),
(6182,1,0,12,0,100,"stilwell SAY_DS_DOWN_1","We showed that one!"),
(6182,2,0,12,0,100,"stilwell SAY_DS_DOWN_2","One more down!"),
(6182,3,0,12,0,100,"stilwell SAY_DS_DOWN_3","We've done it! We won!"),
(6182,4,0,12,0,100,"stilwell SAY_DS_PROLOGUE","Meet me down by the orchard-- I just need to put my gun away.");

-- defias traitor
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000105 AND -1000101;
DELETE FROM `creature_text` WHERE `entry`=467;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(467,0,0,12,0,100,"defias traitor SAY_START","Follow me, $N. I'll take you to the Defias hideout. But you better protect me or I am as good as dead."),
(467,1,0,12,0,100,"defias traitor SAY_PROGRESS","The entrance is hidden here in Moonbrook. Keep your eyes peeled for thieves. They want me dead."),
(467,2,0,12,0,100,"defias traitor SAY_END","You can go tell Stoutmantle this is where the Defias Gang is holed up, $N."),
(467,3,0,12,0,100,"defias traitor SAY_AGGRO_1","%s coming in fast! Prepare to fight!"),
(467,3,1,12,0,100,"defias traitor SAY_AGGRO_2","Help!");

-- vexallus
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1585011 AND -1585007;
DELETE FROM `creature_text` WHERE `entry`=24744;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(24744,0,0,14,12389,100,"vexallus SAY_AGGRO","Drain...life!"),
(24744,1,0,14,12392,100,"vexallus SAY_ENERGY","Un...con...tainable."),
(24744,2,0,14,12390,100,"vexallus SAY_OVERLOAD","Un...leash..."),
(24744,3,0,14,12393,100,"vexallus SAY_KILL","Con...sume."),
(24744,4,0,41,0,100,"vexallus EMOTE_DISCHARGE_ENERGY","%s discharges pure energy!");

-- kaelthas
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1585029 AND -1585023;
DELETE FROM `creature_text` WHERE `entry`=24664;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(24664,0,0,14,12413,100,"kaelthas MT SAY_AGGRO","Don't look so smug! I know what you're thinking, but Tempest Keep was merely a set back. Did you honestly believe I would trust the future to some blind, half-night elf mongrel? Oh no, he was merely an instrument, a stepping stone to a much larger plan! It has all led to this, and this time, you will not interfere!"),
(24664,1,0,14,12415,100,"kaelthas MT SAY_PHOENIX","Vengeance burns!"),
(24664,2,0,14,12417,100,"kaelthas MT SAY_FLAMESTRIKE","Felomin ashal!"),
(24664,3,0,14,12418,100,"kaelthas MT SAY_GRAVITY_LAPSE","I'll turn your world... upside... down..."),
(24664,4,0,14,12419,100,"kaelthas MT SAY_TIRED","Master... grant me strength."),
(24664,5,0,14,12420,100,"kaelthas MT SAY_RECAST_GRAVITY","Do not... get too comfortable."),
(24664,6,0,14,12421,100,"kaelthas MT SAY_DEATH","My demise accomplishes nothing! The Master will have you! You will drown in your own blood! This world shall burn! Aaaghh!");

-- selin
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1585006 AND -1585000;
DELETE FROM `creature_text` WHERE `entry`=24723;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(24723,0,0,14,12378,100,"selin SAY_AGGRO","You only waste my time!"),
(24723,1,0,14,12381,100,"selin SAY_ENERGY","My hunger knows no bounds!"),
(24723,2,0,14,12382,100,"selin SAY_EMPOWERED","Yes! I am a god!"),
(24723,3,0,14,12388,100,"selin SAY_KILL_1","Enough distractions!"),
(24723,3,1,14,12385,100,"selin SAY_KILL_2","I am invincible!"),
(24723,4,0,14,12383,100,"selin SAY_DEATH","No! More... I must have more!"),
(24723,5,0,41,0,100,"selin EMOTE_CRYSTAL","%s begins to channel from the nearby Fel Crystal...");

-- delrissa
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1585022 AND -1585012;
DELETE FROM `creature_text` WHERE `entry`=24560;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(24560,0,0,14,12395,100,"delrissa SAY_AGGRO","Annihilate them!"),
(24560,1,0,14,12398,100,"delrissa LackeyDeath1","Oh, the horror."),
(24560,2,0,14,12400,100,"delrissa LackeyDeath2","Well, aren't you lucky?"),
(24560,3,0,14,12401,100,"delrissa LackeyDeath3","Now I'm getting annoyed."),
(24560,4,0,14,12403,100,"delrissa LackeyDeath4","Lackies be damned! I'll finish you myself!"),
(24560,5,0,14,12405,100,"delrissa PlayerDeath1","I call that a good start."),
(24560,6,0,14,12407,100,"delrissa PlayerDeath2","I could have sworn there were more of you."),
(24560,7,0,14,12409,100,"delrissa PlayerDeath3","Not really much of a group, anymore, is it?"),
(24560,8,0,14,12410,100,"delrissa PlayerDeath4","One is such a lonely number."),
(24560,9,0,14,12411,100,"delrissa PlayerDeath5","It's been a kick, really."),
(24560,10,0,14,12397,100,"delrissa SAY_DEATH","Not what I had... planned...");

-- lord gregor lescovar
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000463 AND -1000457;
DELETE FROM `creature_text` WHERE `entry` IN (1755,7766,1754,1756);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(1756,0,0,12,0,100,"lord gregor lescovar SAY_GUARD_2","Yes, sir!"),
(1754,0,0,12,0,100,"lord gregor lescovar SAY_LESCOVAR_2","It's time for my meditation, leave me."),
(1754,1,0,12,0,100,"lord gregor lescovar SAY_LESCOVAR_3","There you are. What news from Westfall?"),
(1754,2,0,12,0,100,"lord gregor lescovar SAY_LESCOVAR_4","Hmm, it could be that meddle Shaw. I will see what I can discover. Be off with you. I'll contact you again soon."),
(1755,0,0,12,0,100,"lord gregor lescovar SAY_MARZON_1","VanCleef sends word that the plans are underway. But he's hear rumors about someone snooping about."),
(1755,1,0,12,0,100,"lord gregor lescovar SAY_MARZON_2","The Defias shall succeed! No meek adventurer will stop us!"),
(7766,0,0,14,0,100,"lord gregor lescovar SAY_TYRION_2","That's it! That's what you were waiting for! KILL THEM!");

-- tyrion spybot
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000456 AND -1000450 OR `entry`=-1000499;
DELETE FROM `creature_text` WHERE `entry` IN (7766,8856,1756,1754);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(8856,0,0,12,0,100,"tyrion spybot SAY_QUEST_ACCEPT_ATTACK","By your command!"),
(8856,1,0,12,0,100,"tyrion spybot SAY_SPYBOT_1","Good day to you both. I would speak to Lord Lescovar."),
(8856,2,0,12,0,100,"tyrion spybot SAY_SPYBOT_2","Thank you. The Light be with you both."),
(8856,3,0,12,0,100,"tyrion spybot SAY_SPYBOT_3","Milord, your guest has arrived. He awaits your presence."),
(8856,4,0,12,0,100,"tyrion spybot SAY_SPYBOT_4","I shall use the time wisely, milord. Thank you."),
(7766,0,0,12,0,100,"tyrion spybot SAY_TYRION_1","Wait here. Spybot will make Lescovar come out as soon as possible. Be ready! Attack only after you've overheard their conversation."),
(1756,0,0,12,0,100,"tyrion spybot SAY_GUARD_1","Of course. He awaits you in the library."),
(1754,0,0,12,0,100,"tyrion spybot SAY_LESCOVAR_1","Ah, thank you kindly. I will leave you to the library while I tend to this small matter.");

-- rager
DELETE FROM `script_texts` WHERE `entry`=-1409002;
DELETE FROM `creature_text` WHERE `entry`=11988;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(11988,0,0,16,0,100,"core rager EMOTE_LOWHP","%s refuses to die while its master is in trouble.");

-- ragnaros
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1409018 AND -1409008;
DELETE FROM `creature_text` WHERE `entry`=11502;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(11502,0,0,14,8040,100,"ragnaros SAY_SUMMON_MAJ","Behold Ragnaros, the Firelord! He who was ancient when this world was young! Bow before him, mortals! Bow before your ending!"),
(11502,1,0,14,8043,100,"ragnaros SAY_ARRIVAL1_RAG","TOO SOON! YOU HAVE AWAKENED ME TOO SOON, EXECUTUS! WHAT IS THE MEANING OF THIS INTRUSION?"),
(11502,2,0,14,8041,100,"ragnaros SAY_ARRIVAL2_MAJ","These mortal infidels, my lord! They have invaded your sanctum, and seek to steal your secrets!"),
(11502,3,0,14,8044,100,"ragnaros SAY_ARRIVAL3_RAG","FOOL! YOU ALLOWED THESE INSECTS TO RUN RAMPANT THROUGH THE HALLOWED CORE, AND NOW YOU LEAD THEM TO MY VERY LAIR? YOU HAVE FAILED ME, EXECUTUS! JUSTICE SHALL BE MET, INDEED!"),
(11502,4,0,14,8045,100,"ragnaros SAY_ARRIVAL5_RAG","NOW FOR YOU, INSECTS. BOLDLY YOU SAUGHT THE POWER OF RAGNAROS NOW YOU SHALL SEE IT FIRST HAND."),
(11502,5,0,14,8049,100,"ragnaros SAY_REINFORCEMENTS1","COME FORTH, MY SERVANTS! DEFEND YOUR MASTER!"),
(11502,6,0,14,8050,100,"ragnaros SAY_REINFORCEMENTS2","YOU CANNOT DEFEAT THE LIVING FLAME! COME YOU MINIONS OF FIRE! COME FORTH YOU CREATURES OF HATE! YOUR MASTER CALLS!"),
(11502,7,0,14,8046,100,"ragnaros SAY_HAND","BY FIRE BE PURGED!"),
(11502,8,0,14,8047,100,"ragnaros SAY_WRATH","TASTE THE FLAMES OF SULFURON!"),
(11502,9,0,14,8051,100,"ragnaros SAY_KILL","DIE INSECT!"),
(11502,10,0,14,8048,100,"ragnaros SAY_MAGMABURST","MY PATIENCE IS DWINDLING! COME, GNATS, TO YOUR DEATH!");
