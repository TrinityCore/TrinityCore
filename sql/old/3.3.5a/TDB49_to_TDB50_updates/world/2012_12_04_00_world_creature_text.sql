-- ------------------------------- --
-- Creature text conversion part 6 --
-- ------------------------------- --
-- moorabi
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1604017 AND -1604010;
DELETE FROM `creature_text` WHERE `entry`=29305;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(29305,0,0,14,0,100,"moorabi SAY_AGGRO","We fought back da Scourge. What chance joo be thinkin' JOO got?"),
(29305,1,0,14,0,100,"moorabi SAY_SLAY_1","Who gonna stop me; you? "),
(29305,1,1,14,0,100,"moorabi SAY_SLAY_2","Not so tough now."),
(29305,2,0,14,0,100,"moorabi SAY_DEATH","If our gods can die... den so can we... "),
(29305,3,0,14,0,100,"moorabi SAY_TRANSFORM","Get ready for somethin'... much... BIGGAH! "),
(29305,4,0,14,0,100,"moorabi SAY_QUAKE","Da ground gonna swallow you up"),
(29305,5,0,41,0,100,"moorabi EMOTE_TRANSFORM","%s begins to transform!");

-- Slad'ran
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1604023 AND -1604017;
DELETE FROM `creature_text` WHERE `entry`=29304;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(29304,0,0,41,0,100,"Slad'ran EMOTE_TRANSFORM","%s begins to transform!"),
(29304,1,0,12,0,100,"Slad'ran SAY_SLAY_1","Ye not breathin'! Good."),
(29304,1,1,12,0,100,"Slad'ran SAY_SLAY_2","You ssscared now?"),
(29304,1,2,12,0,100,"Slad'ran SAY_SLAY_3","I'll eat you next, mon!"),
(29304,2,0,12,0,100,"Slad'ran SAY_DEATH","I sssee now... Ssscourge wasss not... our greatessst enemy..."),
(29304,3,0,12,0,100,"Slad'ran SAY_SUMMON_SNAKES","Minionsss of the scale, heed my call!"),
(29304,4,0,12,0,100,"Slad'ran SAY_SUMMON_CONSTRICTORS","A thousssand fangs gonna rend your flesh!");

-- blood queen lana thel
DELETE FROM `creature_text` WHERE `entry`=37955 AND `groupid`=12;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(37955,12,0,41,0,100,"blood queen lana thel EMOTE_BERSERK_RAID","%s goes into a berserker rage!");

-- sindragosa
DELETE FROM `creature_text` WHERE `entry`=36853 AND `groupid`=11;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(36853,11,0,41,0,100,"sindragosa EMOTE_BERSERK_RAID","%s goes into a berserker rage!");

-- anubrekhan
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1533008 AND -1533000;
DELETE FROM `creature_text` WHERE `entry`=15956;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(15956,0,0,14,8785,100,"anubrekhan SAY_AGGRO1","Just a little taste..."),
(15956,0,1,14,8786,100,"anubrekhan SAY_AGGRO2","There is no way out."),
(15956,0,2,14,8787,100,"anubrekhan SAY_AGGRO3","Yes, Run! It makes the blood pump faster!"),
(15956,1,0,14,8788,100,"anubrekhan SAY_GREET1","Ahh... welcome to my parlor."),
(15956,1,1,14,8790,100,"anubrekhan SAY_GREET2","I hear little hearts beating. Yesss... beating faster now. Soon the beating will stop."),
(15956,1,2,14,8791,100,"anubrekhan SAY_GREET3","Where to go? What to do? So many choices that all end in pain, end in death."),
(15956,1,3,14,8792,100,"anubrekhan SAY_GREET4","Which one shall I eat first? So difficult to choose... the all smell so delicious."),
(15956,1,4,14,8793,100,"anubrekhan SAY_GREET5","Closer now... tasty morsels. I've been too long without food. Without blood to drink."),
(15956,2,0,14,8789,100,"anubrekhan SAY_SLAY","Shh... it will all be over soon.");

-- faerlina
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1533016 AND -1533009;
DELETE FROM `creature_text` WHERE `entry`=15953;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(15953,0,0,14,8799,100,"faerlina SAY_GREET","Your old lives, your mortal desires, mean nothing. You are acolytes of the master now, and you will serve the cause without question! The greatest glory is to die in the master's service!"),
(15953,1,0,14,8794,100,"faerlina SAY_AGGRO1","Slay them in the master's name!"),
(15953,1,1,14,8795,100,"faerlina SAY_AGGRO2","You cannot hide from me!"),
(15953,1,2,14,8796,100,"faerlina SAY_AGGRO3","Kneel before me, worm!"),
(15953,1,3,14,8797,100,"faerlina SAY_AGGRO4","Run while you still can!"),
(15953,2,0,14,8800,100,"faerlina SAY_SLAY1","You have failed!"),
(15953,2,1,14,8801,100,"faerlina SAY_SLAY2","Pathetic wretch!"),
(15953,3,0,14,8798,100,"faerlina SAY_DEATH","The master... will avenge me!");

-- korthazz
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1533057 AND -1533051;
DELETE FROM `creature_text` WHERE `entry`=16064;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(16064,0,0,14,8899,100,"korthazz SAY_KORT_AGGRO","Come out and fight, ye wee ninny!"),
(16064,1,0,14,8903,100,"korthazz SAY_KORT_TAUNT1","To arms, ye roustabouts! We've got company!"),
(16064,1,1,14,8904,100,"korthazz SAY_KORT_TAUNT2","I heard about enough of yer sniveling. Shut yer fly trap 'afore I shut it for ye!"),
(16064,1,2,14,8905,100,"korthazz SAY_KORT_TAUNT3","I'm gonna enjoy killin' these slack-jawed daffodils!"),
(16064,2,0,14,8902,100,"korthazz SAY_KORT_SPECIAl","I like my meat extra crispy!"),
(16064,3,0,14,8901,100,"korthazz SAY_KORT_SLAY","Next time, bring more friends!"),
(16064,4,0,14,8900,100,"korthazz SAY_KORT_DEATH","What a bloody waste this is!");

-- blaumeux
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1533050 AND -1533044;
DELETE FROM `creature_text` WHERE `entry`=16065;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(16065,0,0,14,8892,100,"blaumeux SAY_BLAU_AGGRO","Defend youself!"),
(16065,1,0,14,8896,100,"blaumeux SAY_BLAU_TAUNT1","Come, Zeliek, do not drive them out. Not before we've had our fun."),
(16065,1,1,14,8897,100,"blaumeux SAY_BLAU_TAUNT2","I do hope they stay alive long enough for me to... introduce myself."),
(16065,1,2,14,8898,100,"blaumeux SAY_BLAU_TAUNT3","The first kill goes to me! Anyone care to wager?"),
(16065,2,0,14,8895,100,"blaumeux SAY_BLAU_SPECIAL","Your life is mine!"),
(16065,3,0,14,8894,100,"blaumeux SAY_BLAU_SLAY","Who's next?"),
(16065,4,0,14,8893,100,"blaumeux SAY_BLAU_DEATH","Tou... che!");

-- rivendare
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1533074 AND -1533065;
DELETE FROM `creature_text` WHERE `entry`=30549;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(30549,0,0,14,14571,100,"rivendare SAY_RIVE_AGGRO1","You seek death?"),
(30549,0,1,14,14572,100,"rivendare SAY_RIVE_AGGRO2","None shall pass!"),
(30549,0,2,14,14573,100,"rivendare SAY_RIVE_AGGRO3","Be still!"),
(30549,1,0,14,14577,100,"rivendare SAY_RIVE_TAUNT1","Enough prattling. Let them come! We shall grind their bones to dust."),
(30549,1,1,14,14578,100,"rivendare SAY_RIVE_TAUNT2","Conserve your anger! Harness your rage! You will all have outlets for your frustration soon enough."),
(30549,1,2,14,14579,100,"rivendare SAY_RIVE_TAUNT3","Life is meaningless. It is in death that we are truly tested."),
(30549,2,0,14,14576,100,"rivendare SAY_RIVE_SPECIAL","Bow to the might of the scourge!"),
(30549,3,0,14,14574,100,"rivendare SAY_RIVE_SLAY1","You will find no peace in death."),
(30549,3,1,14,14575,100,"rivendare SAY_RIVE_SLAY2","The master's will is done."),
(30549,4,0,14,14580,100,"rivendare SAY_RIVE_DEATH","Death... will not stop me...");

-- zeliek
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1533064 AND -1533058;
DELETE FROM `creature_text` WHERE `entry`=16063;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(16063,0,0,14,8913,100,"zeliek SAY_ZELI_AGGRO","Flee, before it's too late!"),
(16063,1,0,14,8917,100,"zeliek SAY_ZELI_TAUNT1","Invaders, cease this foolish venture at once! Turn away while you still can!"),
(16063,1,1,14,8918,100,"zeliek SAY_ZELI_TAUNT2","Perhaps they will come to their senses, and run away as fast as they can!"),
(16063,1,2,14,8919,100,"zeliek SAY_ZELI_TAUNT3","Do not continue! Turn back while there's still time!"),
(16063,2,0,14,8916,100,"zeliek SAY_ZELI_SPECIAL","I- I have no choice but to obey!"),
(16063,3,0,14,8915,100,"zeliek SAY_ZELI_SLAY","Forgive me!"),
(16063,4,0,14,8914,100,"zeliek SAY_ZELI_DEATH","It is... as it should be.");

-- gothik
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1533043 AND -1533040;
DELETE FROM `creature_text` WHERE `entry`=16060;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(16060,0,0,14,8807,100,"gothik SAY_SPEECH","Foolishly you have sought your own demise. Brazenly you have disregarded powers beyond your understanding. You have fought hard to invade the realm of the harvester. Now there is only one way out - to walk the lonely path of the damned."),
(16060,1,0,14,8806,100,"gothik SAY_KILL","Death is the only escape."),
(16060,2,0,14,8805,100,"gothik SAY_DEATH","I... am... undone!"),
(16060,3,0,14,8808,100,"gothik SAY_TELEPORT","I have waited long enough! Now, you face the harvester of souls!");

-- heigan
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1533118 AND -1533109;
DELETE FROM `creature_text` WHERE `entry`=15936;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(15936,0,0,14,8825,100,"heigan SAY_AGGRO1","You are mine now!"),
(15936,0,1,14,8826,100,"heigan SAY_AGGRO2","I see you!"),
(15936,0,2,14,8827,100,"heigan SAY_AGGRO3","You...are next!"),
(15936,1,0,14,8829,100,"heigan SAY_SLAY","Close your eyes... sleep!"),
(15936,2,0,14,8830,100,"heigan SAY_TAUNT1","The races of the world will perish. It is only a matter of time."),
(15936,2,1,14,8831,100,"heigan SAY_TAUNT2","I see endless suffering, I see torment, I see rage. I see... everything!"),
(15936,2,2,14,8832,100,"heigan SAY_TAUNT3","Soon... the world will tremble!"),
(15936,2,3,14,8833,100,"heigan SAY_TAUNT4","The end is upon you."),
(15936,2,4,14,8834,100,"heigan SAY_TAUNT5","Hungry worms will feast on your rotten flesh!"),
(15936,3,0,14,8828,100,"heigan SAY_DEATH","Noo... o...");

-- noth
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1533081 AND -1533075;
DELETE FROM `creature_text` WHERE `entry`=15954;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(15954,0,0,14,8845,100,"noth SAY_AGGRO1","Glory to the master!"),
(15954,0,1,14,8846,100,"noth SAY_AGGRO2","Your life is forfeit!"),
(15954,0,2,14,8847,100,"noth SAY_AGGRO3","Die, trespasser!"),
(15954,1,0,14,8851,100,"noth SAY_SUMMON","Rise, my soldiers! Rise and fight once more!"),
(15954,2,0,14,8849,100,"noth SAY_SLAY1","My task is done!"),
(15954,2,1,14,8850,100,"noth SAY_SLAY2","Breathe no more!"),
(15954,3,0,14,8848,100,"noth SAY_DEATH","I will serve the master... in... death!");

-- patchwerk
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1533022 AND -1533017;
DELETE FROM `creature_text` WHERE `entry`=16028;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(16028,0,0,14,8909,100,"patchwerk SAY_AGGRO1","Patchwerk want to play!"),
(16028,0,1,14,8910,100,"patchwerk SAY_AGGRO2","Kel'Thuzad make Patchwerk his Avatar of War!"),
(16028,1,0,14,8912,100,"patchwerk SAY_SLAY","No more play?"),
(16028,2,0,14,8911,100,"patchwerk SAY_DEATH","What happened to... Patch..."),
(16028,3,0,16,0,100,"patchwerk EMOTE_BERSERK","goes into a berserker rage!"),
(16028,4,0,16,0,100,"patchwerk EMOTE_ENRAGE","%s becomes enraged!");

-- stalagg
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1533025 AND -1533023;
DELETE FROM `creature_text` WHERE `entry`=15929;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(15929,0,0,14,8864,100,"stalagg SAY_STAL_AGGRO","Stalagg crush you!"),
(15929,1,0,14,8866,100,"stalagg SAY_STAL_SLAY","Stalagg kill!"),
(15929,2,0,14,8865,100,"stalagg SAY_STAL_DEATH","Master save me...");

-- feugen
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1533028 AND -1533026;
DELETE FROM `creature_text` WHERE `entry`=15930;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(15930,0,0,14,8802,100,"feugen SAY_FEUG_AGGRO","Feed you to master!"),
(15930,1,0,14,8804,100,"feugen SAY_FEUG_SLAY","Feugen make master happy!"),
(15930,2,0,14,8803,100,"feugen SAY_FEUG_DEATH","No... more... Feugen...");

-- thaddius
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1533039 AND -1533029;
DELETE FROM `creature_text` WHERE `entry`=15928;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(15928,0,0,14,8872,100,"thaddius SAY_GREET","You are too late... I... must... OBEY!"),
(15928,1,0,14,8867,100,"thaddius SAY_AGGRO1","KILL!"),
(15928,1,1,14,8868,100,"thaddius SAY_AGGRO2","EAT YOUR BONES!"),
(15928,1,2,14,8869,100,"thaddius SAY_AGGRO3","BREAK YOU!"),
(15928,2,0,14,8877,100,"thaddius SAY_SLAY","You die now!"),
(15928,3,0,14,8871,100,"thaddius SAY_ELECT","Now YOU feel pain!"),
(15928,4,0,14,8870,100,"thaddius SAY_DEATH","Thank... you..."),
(15928,5,0,14,8873,100,"thaddius SAY_SCREAM1","Pleeease!"),
(15928,5,1,14,8874,100,"thaddius SAY_SCREAM2","Stop, make it stop!"),
(15928,5,2,14,8875,100,"thaddius SAY_SCREAM3","Help me! Save me!"),
(15928,5,3,14,8876,100,"thaddius SAY_SCREAM4","Please, nooo!");

-- anomalus
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1576013 AND -1576010;
DELETE FROM `creature_text` WHERE `entry`=26763;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(26763,0,0,14,13186,100,"anomalus SAY_AGGRO","Chaos beckons."),
(26763,1,0,14,13187,100,"anomalus SAY_DEATH","Of course."),
(26763,2,0,14,13188,100,"anomalus SAY_RIFT","Reality... unwoven."),
(26763,3,0,14,13189,100,"anomalus SAY_SHIELD","Indestructible.");

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1576044 AND -1576040;
DELETE FROM `creature_text` WHERE `entry`=26723;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(26723,0,0,14,13450,100,"keristrasza SAY_AGGRO","Preserve? Why? There's no truth in it. No no no... only in the taking! I see that now!"),
(26723,1,0,14,13453,100,"keristrasza SAY_SLAY","Now we've come to the truth!"),
(26723,2,0,14,13452,100,"keristrasza SAY_ENRAGE","Finish it! FINISH IT! Kill me, or I swear by the Dragonqueen you'll never see daylight again!"),
(26723,3,0,14,13454,100,"keristrasza SAY_DEATH","Dragonqueen... Life-Binder... preserve... me."),
(26723,4,0,14,13451,100,"keristrasza SAY_CRYSTAL_NOVA","Stay. Enjoy your final moments.");

-- grand magus telestra
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1576005 AND -1576000;
DELETE FROM `creature_text` WHERE `entry`=26731;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(26731,0,0,14,13319,100,"grand magus telestra SAY_AGGRO","You know what they say about curiosity."),
(26731,1,0,14,13324,100,"grand magus telestra SAY_KILL","Death becomes you!"),
(26731,2,0,14,13320,100,"grand magus telestra SAY_DEATH","Damn the... luck."),
(26731,3,0,14,13323,100,"grand magus telestra SAY_MERGE","Now to finish the job!"),
(26731,4,0,14,13321,100,"grand magus telestra SAY_SPLIT_1","There's plenty of me to go around."),
(26731,4,1,14,13322,100,"grand magus telestra SAY_SPLIT_2","I'll give you more than you can handle.");

-- drakos
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1578016 AND -1578005;
DELETE FROM `creature_text` WHERE `entry`=27654;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(27654,0,0,14,13594,100,"drakos SAY_AGGRO","The prisoners shall not go free! The word of Malygos is law!"),
(27654,1,0,14,13602,100,"drakos SAY_KILL_1","A fitting punishment!"),
(27654,1,1,14,13603,100,"drakos SAY_KILL_2","Sentence: executed!"),
(27654,1,2,14,13604,100,"drakos SAY_KILL_3","Another casualty of war!"),
(27654,2,0,14,13605,100,"drakos SAY_DEATH","The war... goes on."),
(27654,3,0,14,13598,100,"drakos SAY_PULL_1","It is too late to run!"),
(27654,3,1,14,13599,100,"drakos SAY_PULL_2","Gather 'round...."),
(27654,3,2,14,13600,100,"drakos SAY_PULL_3","None shall escape!"),
(27654,3,3,14,13601,100,"drakos SAY_PULL_4","I condemn you to death!"),
(27654,4,0,14,13595,100,"drakos SAY_STOMP_1","Tremble, worms!"),
(27654,4,1,14,13596,100,"drakos SAY_STOMP_2","I will crush you!"),
(27654,4,2,14,13597,100,"drakos SAY_STOMP_3","Can you fly?");

-- urom
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1578004 AND -1578000;
DELETE FROM `creature_text` WHERE `entry`=27655;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(27655,0,0,14,0,100,"urom SAY_AGGRO_1","What do we have here... those that would defy the Spell-Weaver? Those without foresight our understanding. How can i make you see? Malygos is saving the world from itself! Bah! You are hardly worth my time!"),
(27655,1,0,14,0,100,"urom SAY_AGGRO_2","Clearly my pets failed. Perhaps another demonstration is in order."),
(27655,2,0,14,0,100,"urom SAY_AGGRO_3","Still you fight. Still you cling to misguided principles. If you survive, you'll find me in the center ring."),
(27655,3,0,14,0,100,"urom SAY_AGGRO_4","Poor blind fools!"),
(27655,4,0,14,0,100,"urom SAY_TELEPORT","A taste... just a small taste... of the Spell-Weaver's power!");

-- injured rainspeaker oracle
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1571002 AND -1571000;
DELETE FROM `creature_text` WHERE `entry`=28217;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(28217,0,0,12,0,100,"injured rainspeaker oracle SAY_END_IRO","You save me! We thank you. We going to go back to village now. You come too... you can stay with us! Puppy-men kind of mean anyway. "),
(28217,1,0,12,0,100,"injured rainspeaker oracle SAY_QUEST_ACCEPT_IRO ","Let me know when you ready to go, okay?"),
(28217,2,0,12,0,100,"injured rainspeaker oracle SAY_START_IRO","Home time!");

-- vekjik
DELETE FROM `script_texts` WHERE `entry`=-1000208;
DELETE FROM `creature_text` WHERE `entry`=28315;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(28315,0,0,12,0,100,"vekjik SAY_TEXTID_VEKJIK1","Frenzyheart kill you if you come back. You no welcome here no more!");

-- engineer helice
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1800053 AND -1800047;
DELETE FROM `creature_text` WHERE `entry`=28787;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(28787,0,0,12,0,100,"engineer helice SAY_WP_1","We made it! Thank you for getting me out of that hell hole. Tell Hemet to expect me!"),
(28787,1,0,12,0,100,"engineer helice SAY_WP_2","You really shouldn't play with this stuff. Someone could get hurt."),
(28787,2,0,12,0,100,"engineer helice SAY_WP_3","Oh, look, it's another cartload of explosives! Let's help them dispose of it."),
(28787,3,0,12,0,100,"engineer helice SAY_WP_4","It's getting a little hot over here. Shall we move on?"),
(28787,4,0,12,0,100,"engineer helice SAY_WP_5","Or THIS is what you get."),
(28787,5,0,12,0,100,"engineer helice SAY_WP_6","Listen up, Venture Company goons! Rule #1: Never keep the prisoner near the explosives."),
(28787,6,0,12,0,100,"engineer helice SAY_WP_7","Let's get the hell out of here");

-- adventurous dwarf
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1571043 AND -1571042;
DELETE FROM `creature_text` WHERE `entry`=28604;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(28604,0,0,12,0,100,"adventurous dwarf SAY_DWARF_OUCH","Ouch! Watch where you're tugging!"),
(28604,1,0,12,0,100,"adventurous dwarf SAY_DWARF_HELP","Glad I could help!");

-- agnetta
DELETE FROM `script_texts` WHERE `entry`=-1571003;
DELETE FROM `creature_text` WHERE `entry`=30154;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(30154,0,0,12,0,100,"agnetta SAY_AGGRO","I'm not afraid of anything -- bring it on!");

-- injured goblin
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1800043 AND -1800042;
DELETE FROM `creature_text` WHERE `entry`=29434;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(29434,0,0,12,0,100,"injured goblin SAY_QUEST_START","Let me know when you're ready. I'd prefer sooner than later... what with the slowly dying from poison and all."),
(29434,1,0,12,0,100,"injured goblin SAY_END_WP_REACHED","I'm going to bring the venom sack to Ricket... and then... you know... collapse. Thank you for helping me!");

-- krystallus
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1599010 AND -1599007;
DELETE FROM `creature_text` WHERE `entry`=27977;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(27977,0,0,14,14176,100,"krystallus SAY_AGGRO","Crush...."),
(27977,1,0,14,14177,100,"krystallus SAY_KILL","Ha...ha...ha...ha..."),
(27977,2,0,14,14179,100,"krystallus SAY_DEATH","Uuuuhhhhhhhhhh......"),
(27977,3,0,14,14178,100,"krystallus SAY_SHATTER","Break.... you....");

-- maiden of grief
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1599006 AND -1599000;
DELETE FROM `creature_text` WHERE `entry`=27975;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(27975,0,0,14,13487,100,"maiden of grief SAY_AGGRO","You shouldn't have come...now you will die!"),
(27975,1,0,14,13488,100,"maiden of grief SAY_SLAY_1","Why must it be this way?"),
(27975,1,1,14,13489,100,"maiden of grief SAY_SLAY_2","You had it coming!"),
(27975,1,2,14,13490,100,"maiden of grief SAY_SLAY_3","My burden grows heavier."),
(27975,1,3,14,13491,100,"maiden of grief SAY_SLAY_4","This is your own fault!"),
(27975,2,0,14,13493,100,"maiden of grief SAY_DEATH","I hope you all rot! I never...wanted...this."),
(27975,3,0,14,13492,100,"maiden of grief SAY_STUN","So much lost time... that you'll never get back!");

-- Sjonnir
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1599006 AND -1599000;
DELETE FROM `creature_text` WHERE `entry`=27978;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(27978,0,0,14,14180,100,"Sjonnir SAY_AGGRO","Soft, vulnerable shells. Brief, fragile lives. You can not escape the curse of flesh!"),
(27978,1,0,14,14182,100,"Sjonnir SAY_SLAY_1","Flesh is no match for iron!"),
(27978,1,1,14,14183,100,"Sjonnir SAY_SLAY_2","Armies of iron will smother the world!"),
(27978,1,2,12,0,100,"Sjonnir SAY_SLAY_3","Folvynn buul hrom onn!"),
(27978,2,0,14,14184,100,"Sjonnir SAY_DEATH","Loken will not rest, until the forge is retaken. You changed nothing!");

-- halls of stone
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1599068 AND -1599016;
DELETE FROM `creature_text` WHERE `entry` IN (30898,30899,30897,28070);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
-- brann
(28070,0,0,14,14244,100,"brann SAY_KILL_1","Now that's owning your supper!"),
(28070,0,1,14,14245,100,"brann SAY_KILL_2","Press on, that's the way!"),
(28070,0,2,14,14246,100,"brann SAY_KILL_3","Keep it up now. Plenty of death-dealing for everyone!"),
(28070,1,0,14,14257,100,"brann SAY_LOW_HEALTH","I'm all kinds of busted up. Might not... make it..."),
(28070,2,0,14,14258,100,"brann SAY_DEATH","Not yet, not... yet-"),
(28070,3,0,14,14260,100,"brann SAY_PLAYER_DEATH_1","I'm doing everything I can!"),
(28070,3,1,14,14261,100,"brann SAY_PLAYER_DEATH_2","Light preserve you!"),
(28070,3,2,14,14262,100,"brann SAY_PLAYER_DEATH_3","I hope this is all worth it!"),
(28070,4,0,14,14259,100,"brann SAY_ESCORT_START","Time to get some answers! Let's get this show on the road!"),
(28070,5,0,14,14274,100,"brann SAY_SPAWN_DWARF","Don't worry. Old Brann has got your back. Keep that metal monstrosity busy and I'll see if I can sweet talk this machine into helping you."),
(28070,6,0,14,14275,100,"brann SAY_SPAWN_TROGG","This is a wee bit trickier that before... Oh, bloody--incomin'!"),
(28070,7,0,14,14276,100,"brann SAY_SPAWN_OOZE","What in the name o' Madoran did THAT do? Oh! Wait: I just about got it..."),
(28070,8,0,14,14277,100,"brann SAY_SPAWN_EARTHEN","Ha, that did it. Help's a-coming. Take this you glow-eying brute!"),
(28070,9,0,14,14247,100,"brann SAY_EVENT_INTRO_1","Take a moment and relish this with me! Soon all will be revealed! Okay then, let's do this!"),
(28070,10,0,14,14248,100,"brann SAY_EVENT_INTRO_2","Now keep an eye out! I'll have this licked in two shakes of a--"),
(28070,11,0,14,14249,100,"brann SAY_EVENT_A_1","Oh, that doesn't sound good. We might have a complication or two..."),
(28070,12,0,14,14250,100,"brann SAY_EVENT_A_3","Ah, you want to play hardball, eh? That's just my game!"),
(28070,13,0,14,14251,100,"brann SAY_EVENT_B_1","Couple more minutes and I'll--"),
(28070,14,0,14,14252,100,"brann SAY_EVENT_B_3","Heightened? What's the good news?"),
(28070,15,0,14,14253,100,"brann SAY_EVENT_C_1","So that was the problem? Now I'm makin' progress..."),
(28070,16,0,14,14254,100,"brann SAY_EVENT_C_3","Hang on! Nobody's gonna' be sanitized as long as I have a say in it!"),
(28070,17,0,14,14255,100,"brann SAY_EVENT_D_1","Ha! The old magic fingers finally won through! Now let's get down to-"),
(28070,18,0,14,14256,100,"brann SAY_EVENT_D_3","Purge? No no no no no! Where did I-- Aha, this should do the trick..."),
(28070,19,0,14,14263,100,"brann SAY_EVENT_END_01","Query? What do you think I'm here for? Tea and biscuits? Spill the beans already!"),
(28070,20,0,14,14264,100,"brann SAY_EVENT_END_02","Tell me how that dwarfs came to be! And start at the beginning!"),
(28070,21,0,14,14265,100,"brann SAY_EVENT_END_04","Right, right! I know that the Earthen were made of stone to shape the deep reaches of the world but what about the anomalies? Matrix non-stabilizing and whatnot."),
(28070,22,0,14,14266,100,"brann SAY_EVENT_END_06","Necro-what? Speak bloody common will ya?"),
(28070,23,0,14,14267,100,"brann SAY_EVENT_END_08","Old Gods eh? So they zapped the Earthen with this Curse of Flesh. And then what?"),
(28070,24,0,14,14268,100,"brann SAY_EVENT_END_10","If they killed the Old Gods Azeroth would have been destroyed."),
(28070,25,0,14,14269,100,"brann SAY_EVENT_END_12","What protectors?"),
(28070,26,0,14,14270,100,"brann SAY_EVENT_END_14","Aesir and Vanir. Okay. So the Forge of Wills started to make new Earthen. But what happened to the old ones?"),
(28070,27,0,14,14271,100,"brann SAY_EVENT_END_16","Hold everything! The Aesir and Vanir went to war? Why?"),
(28070,28,0,14,14272,100,"brann SAY_EVENT_END_18","This Loken sounds like a nasty character. Glad we don't have to worry about the likes of him anymore. So if I'm understanding you lads the original Earthen eventually woke up from this statis. And by that time this destabily-whatever had turned them into our brother dwarfs. Or at least dwarf ancestors. Hm?"),
(28070,29,0,14,14273,100,"brann SAY_EVENT_END_20","Well now. That's a lot to digest. I'm gonna need some time to take all of this in. Thank you!"),
(28070,30,0,14,14278,100,"brann SAY_VICTORY_SJONNIR_1","Loken?! That's downright bothersome... We might've neutralized the iron dwarves, but I'd lay odds there's another machine somewhere else churnin' out a whole mess o' these iron vrykul!"),
(28070,31,0,14,14279,100,"brann SAY_VICTORY_SJONNIR_2","I'll use the forge to make badtches o' earthen to stand guard... But our greatest challenge still remains: find and stop Loken!"),
(28070,32,0,14,0,100,"brann SAY_ENTRANCE_MEET","I think it's time to see what's behind the door near the entrance. I'm going to sneak over there, nice and quiet. Meet me at the door and I'll get us in."),
-- marnak
(30897,0,0,14,13761,100,"brann SAY_EVENT_B_2_MARN","Threat index threshold exceeded. Celestial archive aborted. Security level heightened."),
(30897,1,0,14,13762,100,"brann SAY_EVENT_END_15_MARN","Additional background is relevant to your query. Following global combat between-"),
(30897,2,0,14,13763,100,"brann SAY_EVENT_END_17_MARN","Unknown. Data suggests that impetus for global combat originated with prime designate Loken who neutralized all remaining Aesir and Vanir affecting termination of conflict. Prime designate Loken then initiated stasis of several seed races including Earthen, Giant and Vrykul at designated holding facilities."),
(30897,3,0,14,13764,100,"brann SAY_EVENT_END_19_MARN","Essentially that is correct."),
-- kaddrak
(30898,0,0,14,13756,100,"brann SAY_EVENT_A_2_KADD","Security breach in progress. Analysis of historical archives transferred to lower priority queue. Countermeasures engaged."),
(30898,1,0,14,13757,100,"brann SAY_EVENT_END_09_KADD","Accessing. Creators arrived to extirpate symbiotic infection. Assessment revealed that Old God infestation had grown malignant. Excising parasites would result in loss of host."),
(30898,2,0,14,13758,100,"brann SAY_EVENT_END_11_KADD","Correct. Creators neutralized parasitic threat and contained it within the host. Forge of Wills and other systems were instituted to create new Earthen. Safeguards were implemented and protectors were appointed."),
(30898,3,0,14,13759,100,"brann SAY_EVENT_END_13_KADD","Designations: Aesir and Vanir or in common nomenclator Storm and Earth Giants. Sentinel Loken designated supreme. Dragon Aspects appointed to monitor evolution of Azeroth."),
-- abedneum
(30899,0,0,14,13765,100,"brann SAY_EVENT_INTRO_3_ABED","Warning! Life form pattern not recognized. Archival processing terminated. Continued interference will result in targeted response."),
(30899,1,0,14,13767,100,"brann SAY_EVENT_C_2_ABED","Critical threat index. Void analysis diverted. Initiating sanitization protocol."),
(30899,2,0,14,13768,100,"brann SAY_EVENT_D_2_ABED","Alert! Security fail safes deactivated. Beginning memory purge..."),
(30899,3,0,14,13769,100,"brann SAY_EVENT_D_4_ABED","System online. Life form pattern recognized. Welcome Branbronzan. Query?"),
(30899,4,0,14,13770,100,"brann SAY_EVENT_END_03_ABED","Accessing prehistoric data. Retrieved. In the beginning Earthen were created to-"),
(30899,5,0,14,13771,100,"brann SAY_EVENT_END_05_ABED","Accessing. In the early stages of its development cycle Azeroth suffered infection by parasitic, necrophotic symbiotes."),
(30899,6,0,14,13772,100,"brann SAY_EVENT_END_07_ABED","Designation: Old Gods. Old Gods rendered all systems, including Earthen defenseless in order to facilitate assimilation. This matrix destabilization has been termed the Curse of Flesh. Effects of destabilization increased over time."),
(30899,7,0,14,13773,100,"brann SAY_EVENT_END_21_ABED","Acknowledged Branbronzan. Session terminated.");
