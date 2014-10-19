-- Vazruden the herald
DELETE FROM `creature_text` WHERE `entry`=17307;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`probability`,`sound`,`comment`,`text`) VALUES
(17307,0,0,14,100,10292,"vazruden the herald SAY_INTRO","You have faced many challenges, pity they were all in vain. Soon your people will kneel to my lord!");

-- Nazan
DELETE FROM `creature_text` WHERE `entry`=17536;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`probability`,`comment`,`text`) VALUE
(17536,0,0,41,100,"nazan EMOTE","%s descends from the sky");

-- Vazruden
DELETE FROM `creature_text` WHERE `entry`=17537;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`probability`,`sound`,`comment`,`text`) VALUES
(17537,0,0,14,100,10293,"vazruden SAY_WIPE","Is there no one left to test me?"),
(17537,1,0,14,100,10294,"vazruden SAY_AGGRO_1","Your time is running out!"),
(17537,1,1,14,100,10295,"vazruden SAY_AGGRO_2","You are nothing, I answer a higher call!"),
(17537,1,2,14,100,10296,"vazruden SAY_AGGRO_3","The Dark Lord laughs at you!"),
(17537,2,0,14,100,10297,"vazruden SAY_KILL_1","It is over. Finished!"),
(17537,2,1,14,100,10298,"vazruden SAY_KILL_2","Your days are done!"),
(17537,3,0,14,100,10299,"vazruden SAY_DIE","My lord will be the end you all...");

-- Talbot aka Prince Valanar (There's an UpdateEntry() call in the script which I did not see)
UPDATE `creature_text` SET `entry`=28189 WHERE `entry`=25301;

-- Darion Mograine
UPDATE `creature_text` SET `entry`=29228 WHERE `entry`=29173 AND `groupid`=74;

-- Core rager
UPDATE `creature_text` SET `entry`=11672 WHERE `entry`=11988;

DELETE FROM `creature_text` WHERE `entry` IN (15550,16151);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`probability`,`sound`,`comment`,`text`) VALUES
-- Attumen
(15550,0,0,14,100,9169,"attumen SAY_KILL1","It was... inevitable."),
(15550,0,1,14,100,9300,"attumen SAY_KILL2","Another trophy to add to my collection!"),
(15550,1,0,14,100,9166,"attumen SAY_DISARMED","Weapons are merely a convenience for a warrior of my skill!"),
(15550,2,0,14,100,9165,"attumen SAY_DEATH","I always knew... someday I would become... the hunted."),
(15550,3,0,14,100,9170,"attumen SAY_RANDOM1","Such easy sport."),
(15550,3,1,14,100,9304,"attumen SAY_RANDOM2","Amateurs! Do not think you can best me! I kill for a living."),
-- Midnight
(16151,0,0,14,100,9173,"attumen SAY_MIDNIGHT_KILL","Well done Midnight!"),
(16151,1,0,14,100,9167,"attumen SAY_APPEAR1","Cowards! Wretches!"),
(16151,1,1,14,100,9298,"attumen SAY_APPEAR2","Who dares attack the steed of the Huntsman?"),
(16151,1,2,14,100,9299,"attumen SAY_APPEAR3","Perhaps you would rather test yourselves against a more formidable opponent?!"),
(16151,2,0,14,100,9168,"attumen SAY_MOUNT","Come, Midnight, let\'s disperse this petty rabble!");

-- Creature text preparation for rajaxx
DELETE FROM `creature_text` WHERE `entry` IN (15471,15341);
INSERT INTO `creature_text`(`entry`,`groupid`,`sound`,`type`,`probability`,`comment`,`text`) VALUES
(15471,0,0,14,100,"andorov SAY_ANDOROV_INTRO","They come now. Try not to get yourself killed, young blood."),
(15471,1,0,14,100,"andorov SAY_ANDOROV_ATTACK","Remember, Rajaxx, when I said I\'d kill you last? I lied..."),
(15341,0,8612,14,100,"rajaxx SAY_WAVE3","The time of our retribution is at hand! Let darkness reign in the hearts of our enemies!"),
(15341,1,8610,14,100,"rajaxx SAY_WAVE4","No longer will we wait behind barred doors and walls of stone! No longer will our vengeance be denied! The dragons themselves will tremble before our wrath!"),
(15341,2,8608,14,100,"rajaxx SAY_WAVE5","Fear is for the enemy! Fear and death!"),
(15341,3,8611,14,100,"rajaxx SAY_WAVE6","Staghelm will whimper and beg for his life, just as his whelp of a son did! One thousand years of injustice will end this day!"),
(15341,4,8607,14,100,"rajaxx SAY_WAVE7","Fandral! Your time has come! Go and hide in the Emerald Dream and pray we never find you!"),
(15341,5,8609,14,100,"rajaxx SAY_INTRO","Impudent fool! I will kill you myself!"),
(15341,6,8603,14,100,"rajaxx SAY_UNK1","Attack and make them pay dearly!"),
(15341,7,8605,14,100,"rajaxx SAY_UNK2","Crush them! Drive them out!"),
(15341,8,8606,14,100,"rajaxx SAY_UNK3","Do not hesitate! Destroy them!"),
(15341,9,8613,14,100,"rajaxx SAY_UNK4","Warriors! Captains! Continue the fight!"),
(15341,10,8614,14,100,"rajaxx SAY_DEAGGRO","You are not worth my time $N!"),
(15341,11,8604,14,100,"rajaxx SAY_KILLS_ANDOROV","Breath your last!"),
(15341,12,0,14,100,"rajaxx SAY_COMPLETE_QUEST","Soon you will know the price of your meddling, mortals... The master is nearly whole... And when he rises, your world will be cease!");

-- moam
DELETE FROM `creature_text` WHERE `entry`=15340;
INSERT INTO `creature_text`(`entry`,`groupid`,`type`,`probability`,`comment`,`text`) VALUES
(15340,0,16,100,"moam EMOTE_AGGRO","%s senses your fear."),
(15340,1,16,100,"moan EMOTE_MANA_FULL","%s bristles with energy!");

-- buru
DELETE FROM `creature_text` WHERE `entry`=15370;
INSERT INTO `creature_text`(`entry`,`groupid`,`type`,`probability`,`comment`,`text`) VALUES
(15370,0,16,100,"buru EMOTE_TARGET","%s sets eyes on $N!");
