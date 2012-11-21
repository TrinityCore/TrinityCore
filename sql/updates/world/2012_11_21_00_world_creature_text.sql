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
