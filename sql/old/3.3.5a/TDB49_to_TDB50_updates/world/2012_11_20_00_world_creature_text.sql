-- Undercity
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000197 AND -1000196;
DELETE FROM `creature_text` WHERE `entry`=10181;
INSERT INTO `creature_text`(`entry`,`groupid`,`text`,`type`,`probability`,`comment`) VALUES
(10181,0,'%s kneels down and pick up the amulet.',16,100,'npc_lady_sylvanas_windrunner EMOTE_LAMENT_END'),
(10181,1,'Belore...',14,100,'npc_lady_sylvanas_windrunner SAY_LAMENT_END');

-- Ironaya
DELETE FROM `script_texts` WHERE `entry`=-1070000;
DELETE FROM `creature_text` WHERE `entry`=7228;
INSERT INTO `creature_text`(`entry`,`groupid`,`text`,`type`,`sound`,`probability`,`comment`) VALUES
(7228,0,'None may steal the secrets of the makers!',14,5851,100,'ironaya SAY_AGGRO');

-- Opera
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1532028 AND -1532025;
DELETE FROM `creature_text` WHERE `entry`=17535;
INSERT INTO `creature_text`(`entry`,`groupid`,`text`,`type`,`sound`,`probability`,`comment`) VALUES
(17535,0,'Oh at last, at last. I can go home.',14,9190,100,'dorothee SAY_DOROTHEE_DEATH'),
(17535,1,"Don't let them hurt us, Tito! Oh, you won't, will you?",14,9191,100,'dorothee SAY_DOROTHEE_SUMMON'),
(17535,2,'Tito, oh Tito, no!',14,9192,100,'dorothee SAY_DOROTHEE_TITO_DEATH'),
(17535,3,'Oh dear, we simply must find a way home! The old wizard could be our only hope! Strawman, Roar, Tinhead, will you... wait! Oh golly, look! We have visitors!',14,9195,100,'dorothee SAY_DOROTHEE_AGGRO');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1532031 AND -1532029;
DELETE FROM `creature_text` WHERE `entry`=17546;
INSERT INTO `creature_text`(`entry`,`groupid`,`text`,`type`,`sound`,`probability`,`comment`) VALUES
(17546,0,"Wanna fight? Huh? Do ya? C'mon, I'll fight you with both claws behind my back!",14,9227,100,'roar SAY_ROAR_AGGRO'),
(17546,1,"You didn't have to go and do that.",14,9229,100,'roar SAY_ROAR_DEATH'),
(17546,2,"I think I'm going to go take fourty winks.",14,9230,100,'roar SAY_ROAR_SLAY');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1532034 AND -1532032;
DELETE FROM `creature_text` WHERE `entry`=17543;
INSERT INTO `creature_text`(`entry`,`groupid`,`text`,`type`,`sound`,`probability`,`comment`) VALUES
(17543,0,"Now what should I do with you? I simply can't make up my mind.",14,9254,100,'strawman SAY_STRAWMAN_AGGRO'),
(17543,1,"Don't let them make a mattress... out of me.",14,9256,100,'strawman SAY_STRAWMAN_DEATH'),
(17543,2,"I guess I'm not a failure after all.",14,9257,100,'strawman SAY_STRAWMAN_SLAY');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1532038 AND -1532035;
DELETE FROM `creature_text` WHERE `entry`=17547;
INSERT INTO `creature_text`(`entry`,`groupid`,`text`,`type`,`sound`,`probability`,`comment`) VALUES
(17547,0,"I could really use a heart. Say, can I have yours?",14,9268,100,'tinhead SAY_TINHEAD_AGGRO'),
(17547,1,"Back to being an old rustbucket.",14,9270,100,'tinhead SAY_TINHEAD_DEATH'),
(17547,2,"Guess I'm not so rusty, after all.",14,9271,100,'tinhead SAY_TINHEAD_SLAY'),
(17547,3,"%s begins to rust.",16,0,100,'tinhead EMOTE_RUST');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1532042 AND -1532039;
DELETE FROM `creature_text` WHERE `entry`=18168;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`text`,`type`,`sound`,`probability`,`comment`) VALUES
(18168,0,0,"Woe to each and every one of you my pretties! <cackles>",14,9179,100,'crone SAY_CRONE_AGGRO'),
(18168,0,1,"It will all be over soon! <cackles>",14,9307,100,'crone SAY_CRONE_AGGRO2'),
(18168,1,0,"How could you? What a cruel, cruel world!",14,9178,100,'crone SAY_CRONE_DEATH'),
(18168,2,0,"Fixed you, didn't I? <cackles>",14,9180,100,'crone SAY_CRONE_SLAY');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1532045 AND -1532043;
DELETE FROM `creature_text` WHERE `entry`=17521;
INSERT INTO `creature_text`(`entry`,`groupid`,`text`,`type`,`sound`,`probability`,`comment`) VALUES
(17521,0,"All the better to own you with!",14,9276,100,'wolf SAY_WOLF_AGGRO'),
(17521,1,"Mmmm... delicious.",14,9277,100,'SAY_WOLF_SLAY'),
(17521,2,"Run away little girl, run away!",14,9278,100,'SAY_WOLF_HOOD');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1532051 AND -1532046;
DELETE FROM `creature_text` WHERE `entry`=17534;
INSERT INTO `creature_text`(`entry`,`groupid`,`text`,`type`,`sound`,`probability`,`comment`) VALUES
(17534,0,"What devil art thou, that dost torment me thus?",14,9196,100,'julianne SAY_JULIANNE_AGGRO'),
(17534,1,"Where is my lord? Where is my Romulo?",14,9199,100,'julianne SAY_JULIANNE_ENTER'),
(17534,2,"Romulo, I come! Oh... this do I drink to thee!",14,9199,100,'julianne SAY_JULIANNE_DEATH01'),
(17534,3,"Where is my Lord? Where is my Romulo? Ohh, happy dagger! This is thy sheath! There rust, and let me die!",14,9310,100,'julianne SAY_JULIANNE_DEATH02'),
(17534,4,"Come, gentle night; and give me back my Romulo!",14,9200,100,'julianne SAY_JULIANNE_RESURRECT'),
(17534,5,"Parting is such sweet sorrow.",14,9201,100,'julianne SAY_JULIANNE_SLAY');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1532056 AND -1532052;
DELETE FROM `creature_text` WHERE `entry`=17533;
INSERT INTO `creature_text`(`entry`,`groupid`,`text`,`type`,`sound`,`probability`,`comment`) VALUES
(17533,0,"Wilt thou provoke me? Then have at thee, boy!",14,9233,100,'romulo SAY_ROMULO_AGGRO'),
(17533,1,"Thou smilest... upon the stroke that... murders me.",14,9235,100,'romulo SAY_ROMULO_DEATH'),
(17533,2,"This day's black fate on more days doth depend. This but begins the woe. Others must end.",14,9236,100,'romulo SAY_ROMULO_ENTER'),
(17533,3,"Thou detestable maw, thou womb of death; I enforce thy rotten jaws to open!",14,9237,100,'romulo SAY_ROMULO_RESURRECT'),
(17533,4,"How well my comfort is revived by this!",14,9238,100,'romulo SAY_ROMULO_SLAY');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1532114 AND -1532103;
DELETE FROM `creature_text` WHERE `entry`=16812;
INSERT INTO `creature_text`(`entry`,`groupid`,`text`,`type`,`sound`,`probability`,`comment`) VALUES
(16812,0,"Welcome Ladies and Gentlemen, to this evening's presentation!",14,9174,100,'barnes OZ1'),
(16812,1,"Tonight we plumb the depths of the human soul as we join a lost, lonely girl trying desperately -- with the help of her loyal companions -- to find her way home!",14,9338,100,'barnes OZ2'),
(16812,2,"But she is pursued... by a wicked malevolent crone!",14,9339,100,'barnes OZ3'),
(16812,3,"Will she survive? Will she prevail? Only time will tell. And now ... on with the show!",14,9340,100,'barnes OZ4'),
(16812,4,"Good evening, Ladies and Gentlemen! Welcome to this evening's presentation!",14,9175,100,'barnes HOOD1'),
(16812,5,"Tonight, things are not what they seem. For tonight, your eyes may not be trusted",14,9335,100,'barnes HOOD2'),
(16812,6,"Take for instance, this quiet, elderly woman, waiting for a visit from her granddaughter. Surely there is nothing to fear from this sweet, grey-haired, old lady.",14,9336,100,'barnes HOOD3'),
(16812,7,"But don't let me pull the wool over your eyes. See for yourself what lies beneath those covers! And now... on with the show!",14,9337,100,'barnes HOOD4'),
(16812,8,"Welcome, Ladies and Gentlemen, to this evening's presentation!",14,9176,100,'barnes RAJ1'),
(16812,9,"Tonight, we explore a tale of forbidden love!",14,9341,100,'barnes RAJ2'),
(16812,10,"But beware, for not all love stories end happily, as you may find out. Sometimes, love pricks like a thorn.",14,9342,100,'barnes RAJ3'),
(16812,11,"But don't take it from me, see for yourself what tragedy lies ahead when the paths of star-crossed lovers meet. And now...on with the show!",14,9343,100,'barnes RAJ4');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1532102 AND -1532091;
DELETE FROM `creature_text` WHERE `entry`=15690;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`text`,`type`,`sound`,`probability`,`comment`) VALUES
(15690,0,0,"Madness has brought you here to me. I shall be your undoing!",14,9218,100,'malchezaar SAY_AGGRO'),
(15690,1,0,"Simple fools! Time is the fire in which you'll burn!",14,9220,100,'malchezaar SAY_AXE_TOSS1'),
(15690,2,0,"I see the subtlety of conception is beyond primitives such as you.",14,9317,100,'malchezaar SAY_AXE_TOSS2'),
(15690,3,0,"Who knows what secrets hide in the dark.",14,9223,100,'malchezaar SAY_SPECIAL1'),
(15690,4,0,"The cerestial forces are mine to manipulate.",14,9320,100,'malchezaar SAY_SPECIAL2'),
(15690,5,0,"How can you hope to withstand against such overwhelming power?",14,9321,100,'malchezaar SAY_SPECIAL3'),
(15690,6,0,"Surely you did not think you could win.",14,9222,100,'malchezaar SAY_SLAY1'),
(15690,6,1,"Your greed, your foolishness has brought you to this end.",14,9318,100,'malchezaar SAY_SLAY2'),
(15690,6,2,"You are, but a plaything, unfit even to amuse.",14,9319,100,'malchezaar SAY_SLAY3'),
(15690,7,0,"All realities, all dimensions are open to me!",14,9224,100,'malchezaar SAY_SUMMON1'),
(15690,7,1,"You face not Malchezaar alone, but the legions I command!",14,9322,100,'malchezaar SAY_SUMMON2'),
(15690,8,0,"I refuse to concede defeat. I am a prince of the Eredar! I am...",14,9221,100,'malchezaar SAY_DEATH');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1532088 AND -1532073;
DELETE FROM `creature_text` WHERE `entry`=16524;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`text`,`type`,`sound`,`probability`,`comment`) VALUES
(16524,0,0,"Please, no more. My son... he's gone mad!",14,9241,100,'aran SAY_AGGRO1'),
(16524,0,1,"I'll not be tortured again!",14,9323,100,'aran SAY_AGGRO2'),
(16524,0,2,"Who are you? What do you want? Stay away from me!",14,9324,100,'aran SAY_AGGRO3'),
(16524,1,0,"I'll show you this beaten dog still has some teeth!",14,9245,100,'aran SAY_FLAMEWREATH1'),
(16524,1,1,"Burn you hellish fiends!",14,9326,100,'aran SAY_FLAMEWREATH2'),
(16524,2,0,"I'll freeze you all!",14,9246,100,'aran SAY_BLIZZARD1'),
(16524,2,1,"Back to the cold dark with you!",14,9327,100,'aran SAY_BLIZZARD2'),
(16524,3,0,"Yes, yes, my son is quite powerful... but I have powers of my own!",14,9242,100,'aran SAY_EXPLOSION1'),
(16524,3,1,"I am not some simple jester! I am Nielas Aran!",14,9325,100,'aran SAY_EXPLOSION2'),
(16524,4,0,"Surely you would not deny an old man a replenishing drink? No, no I thought not.",14,9248,100,'aran SAY_DRINK'),
(16524,5,0,"I'm not finished yet! No, I have a few more tricks up me sleeve.",14,9251,100,'aran SAY_ELEMENTALS'),
(16524,6,0,"I want this nightmare to be over!",14,9250,100,'aran SAY_KILL1'),
(16524,6,1,"Torment me no more!",14,9328,100,'aran SAY_KILL2'),
(16524,7,0,"You've wasted enough of my time. Let these games be finished!",14,9247,100,'aran SAY_TIMEOVER'),
(16524,8,0,"At last... The nightmare is.. over...",14,9244,100,'aran SAY_DEATH'),
(16524,9,0,"Where did you get that?! Did HE send you?!",14,9249,100,'aran SAY_ATIESH');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1532072 AND -1532065;
DELETE FROM `creature_text` WHERE `entry`=15688;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`text`,`type`,`sound`,`probability`,`comment`) VALUES
(15688,0,0,"Your blood will anoint my circle.",14,9264,100,'terestian SAY_SLAY1'),
(15688,0,1,"The great one will be pleased.",14,9329,100,'terestian SAY_SLAY2'),
(15688,1,0,"My life, is yours. Oh great one.",14,9262,100,'terestian SAY_DEATH'),
(15688,2,0,"Ah, you're just in time. The rituals are about to begin.",14,9260,100,'terestian SAY_AGGRO'),
(15688,3,0,"Please, accept this humble offering, oh great one.",14,9263,100,'terestian SAY_SACRIFICE1'),
(15688,3,1,"Let the sacrifice serve his testament to my fealty.",14,9330,100,'terestian SAY_SACRIFICE2'),
(15688,4,0,"Come, you dwellers in the dark. Rally to my call!",14,9265,100,'terestian SAY_SUMMON1'),
(15688,4,1,"Gather, my pets. There is plenty for all.",14,9331,100,'terestian SAY_SUMMON2');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1532017 AND -1532011;
DELETE FROM `creature_text` WHERE `entry`=15687;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`text`,`type`,`sound`,`probability`,`comment`) VALUES
(15687,0,0,"Hmm, unannounced visitors? Preparations must be made.",14,9211,100,'moroes SAY_AGGRO'),
(15687,1,0,"Now, where was I? Oh yes...",14,9215,100,'moroes SAY_SPECIAL_1'),
(15687,1,1,"You rang?",14,9316,100,'moroes SAY_SPECIAL_2'),
(15687,2,0,"One more for dinner this evening.",14,9214,100,'moroes SAY_KILL_1'),
(15687,2,1,"Time... Never enough time.",14,9314,100,'moroes SAY_KILL_2'),
(15687,2,2,"I've gone and made a mess.",14,9315,100,'moroes SAY_KILL_3'),
(15687,3,0,"How terribly clumsy of me...",14,9213,100,'moroes SAY_DEATH');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1532064 AND -1532057;
DELETE FROM `creature_text` WHERE `entry`=15691;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`text`,`type`,`sound`,`probability`,`comment`) VALUES
(15691,0,0,"The Menagerie is for guests only.",14,9183,100,'curator SAY_AGGRO'),
(15691,1,0,"Gallery rules will be strictly enforced.",14,9188,100,'curator SAY_SUMMON1'),
(15691,1,1,"This curator is equipped for gallery protection.",14,9309,100,'curator SAY_SUMMON2'),
(15691,2,0,"Your request cannot be processed.",14,9186,100,'curator SAY_EVOCATE'),
(15691,3,0,"Failure to comply will result in offensive action.",14,9185,100,'curator SAY_ENRAGE'),
(15691,4,0,"Do not touch the displays.",14,9187,100,'curator SAY_KILL1'),
(15691,4,1,"You are not a guest.",14,9308,100,'curator SAY_KILL2'),
(15691,5,0,"This Curator is no longer op... er... ation... al.",14,9184,100,'curator SAY_DEATH');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1532010 AND -1532000;
DELETE FROM `creature_text` WHERE `entry`=16151;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`text`,`type`,`sound`,`probability`,`comment`) VALUES
(16151,0,0,"Well done Midnight!",14,9173,100,'attumen SAY_MIDNIGHT_KILL'),
(16151,1,0,"Cowards! Wretches!",14,9167,100,'attumen SAY_APPEAR1'),
(16151,1,1,"Who dares attack the steed of the Huntsman?",14,9298,100,'attumen SAY_APPEAR2'),
(16151,1,2,"Perhaps you would rather test yourselves against a more formidable opponent?!",14,9299,100,'attumen SAY_APPEAR3'),
(16151,2,0,"Come, Midnight, let's disperse this petty rabble!",14,9168,100,'attumen SAY_MOUNT'),
(16151,3,0,"It was... inevitable.",14,9169,100,'attumen SAY_KILL1'),
(16151,3,1,"Another trophy to add to my collection!",14,9300,100,'attumen SAY_KILL2'),
(16151,4,0,"Weapons are merely a convenience for a warrior of my skill!",14,9166,100,'attumen SAY_DISARMED'),
(16151,5,0,"I always knew... someday I would become... the hunted.",14,9165,100,'attumen SAY_DEATH'),
(16151,6,0,"Such easy sport.",14,9170,100,'attumen SAY_RANDOM1'),
(16151,6,1,"Amateurs! Do not think you can best me! I kill for a living.",14,9304,100,'attumen SAY_RANDOM2');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1532024 AND -1532018;
DELETE FROM `creature_text` WHERE `entry`=16457;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`text`,`type`,`sound`,`probability`,`comment`) VALUES
(16457,0,0,"Your behavior will not be tolerated!",14,9204,100,'maiden SAY_AGGRO'),
(16457,1,0,"Ah ah ah...",14,9207,100,'maiden SAY_SLAY1'),
(16457,1,1,"This is for the best.",14,9312,100,'maiden SAY_SLAY2'),
(16457,1,2,"Impure thoughts lead to profane actions.",14,9311,100,'maiden SAY_SLAY3'),
(16457,2,0,"Cast out your corrupt thoughts.",14,9313,100,'maiden SAY_REPENTANCE1'),
(16457,2,1,"Your impurity must be cleansed.",14,9208,100,'maiden SAY_REPENTANCE2'),
(16457,3,0,"Death comes. Will your conscience be clear?",14,9206,100,'maiden SAY_DEATH');

DELETE FROM `script_texts` WHERE `entry`=-1189021;
DELETE FROM `creature_text` WHERE `entry`=3974;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`text`,`type`,`sound`,`probability`,`comment`) VALUES
(3974,0,0,"Release the hounds!",14,5841,100,'loksey SAY_AGGRO');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1189007 AND -1189001;
DELETE FROM `creature_text` WHERE `entry` IN (23682,23775);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`text`,`type`,`sound`,`probability`,`comment`) VALUES
(23775,0,0,"Hah, is that all?",14,5831,100,'headless horseman SAY_LOST_HEAD'),
(23775,1,0,"Unworthy!",14,5836,100,'headless horseman SAY_PLAYER_DEATH'),
(23682,0,0,"Blades of Light!",14,5832,100,'headless horseman SAY_ENTRANCE'),
(23682,1,0,"Light, give me strength!",14,5833,100,'headless horseman SAY_REJOINED'),
(23682,2,0,"%s becomes enraged!",16,0,100,'headless horseman SAY_CONFLAGRATION'),
(23682,3,0,"Infidels! They must be purified!",14,5835,100,'headless horseman SAY_SPROUTING_PUMPKINS'),
(23682,4,0,"At your side, milady!",14,5837,100,'headless horseman SAY_DEATH');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1189004 AND -1189000;
DELETE FROM `creature_text` WHERE `entry`=3975;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`text`,`type`,`sound`,`probability`,`comment`) VALUES
(3975,0,0,"Ah, I have been waiting for a real challenge!",14,5830,100,'herod SAY_AGGRO'),
(3975,1,0,"Blades of Light!",14,5832,100,'herod SAY_WHIRLWIND'),
(3975,2,0,"Light, give me strength!",14,5833,100,'herod SAY_ENRAGE'),
(3975,3,0,"Hah, is that all?",14,5831,100,'herod SAY_KILL'),
(3975,4,0,"%s becomes enraged!",16,0,100,'herod EMOTE_ENRAGE');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1189020 AND -1189019;
DELETE FROM `creature_text` WHERE `entry`=6487;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`text`,`type`,`sound`,`probability`,`comment`) VALUES
(6487,0,0,"You will not defile these mysteries!",14,5842,100,'doan SAY_AGGRO'),
(6487,1,0,"Burn in righteous fire!",14,5843,100,'doan SAY_SPECIALAE');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1189007 AND -1189005;
DELETE FROM `creature_text` WHERE `entry`=3976;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`text`,`type`,`sound`,`probability`,`comment`) VALUES
(3976,0,0,"Infidels! They must be purified!",14,5835,100,'mograine SAY_MO_AGGRO'),
(3976,1,0,"Unworthy!",14,5836,100,'mograine SAY_MO_KILL'),
(3976,2,0,"At your side, milady!",14,5837,100,'mograine SAY_MO_RESSURECTED');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1189010 AND -1189008;
DELETE FROM `creature_text` WHERE `entry`=3977;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`text`,`type`,`sound`,`probability`,`comment`) VALUES
(3977,0,0,"What, Mograine has fallen? You shall pay for this treachery!",14,5838,100,'whitemane SAY_WH_INTRO'),
(3977,1,0,"The Light has spoken!",14,5839,100,'whitemane SAY_WH_KILL'),
(3977,2,0,"Arise, my champion!",14,5840,100,'whitemane SAY_WH_RESSURECT');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1189018 AND -1189016;
DELETE FROM `creature_text` WHERE `entry`=4543;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`text`,`type`,`sound`,`probability`,`comment`) VALUES
(4543,0,0,"We hunger for vengeance.",14,5844,100,'thalnos SAY_AGGRO'),
(4543,1,0,"No rest, for the angry dead.",14,5846,100,'thalnos SAY_HEALTH'),
(4543,2,0,"More... More souls.",14,5845,100,'thalnos SAY_KILL');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1189015 AND -1189011;
DELETE FROM `creature_text` WHERE `entry` IN (3983,3981);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`text`,`type`,`sound`,`probability`,`comment`) VALUES
(3983,0,0,"Tell me... tell me everything!",14,5847,100,'vishas SAY_AGGRO'),
(3983,1,0,"Naughty secrets!",14,5849,100,'vishas SAY_HEALTH1'),
(3983,2,0,"I'll rip the secrets from your flesh!",14,5850,100,'vishas SAY_HEALTH2'),
(3983,3,0,"Purged by pain!",14,5848,100,'vishas SAY_KILL'),
(3981,0,0,"The monster got what he deserved.",12,0,100,'vishas SAY_TRIGGER_VORREL');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1033009 AND -1033007;
DELETE FROM `creature_text` WHERE `entry` IN (3849,3850,4275);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`text`,`type`,`sound`,`probability`,`language`,`emote`,`comment`) VALUES
(3849,0,0,"About time someone killed the wretch.",12,0,100,1,1,'prisoner adamant SAY_BOSS_DIE_AD'),
(3850,0,0,"For once I agree with you... scum.",12,0,100,7,1,'prisoner ashcrombe SAY_BOSS_DIE_AS'),
(4275,0,0,"Who dares interfere with the Sons of Arugal?",14,0,100,0,0,'');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1033006 AND -1033000;
DELETE FROM `creature_text` WHERE `entry` IN (3849,3850);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`text`,`type`,`sound`,`probability`,`language`,`emote`,`comment`) VALUES
(3850,0,0,"Follow me and I'll open the courtyard door for you.",14,0,100,7,1,'prisoner ashcrombe SAY_FREE_AS'),
(3850,1,0,"I have just the spell to get this door open. Too bad the cell doors weren't locked so haphazardly.",14,0,100,7,1,'prisoner ashcrombe SAY_OPEN_DOOR_AS'),
(3850,2,0,"There it is! Wide open. Good luck to you conquering what lies beyond. I must report back to the Kirin Tor at once!",14,0,100,7,1,'prisoner ashcrombe SAY_POST_DOOR_AS'),
(3849,0,0,"Free from this wretched cell at last! Let me show you to the courtyard....",14,0,100,1,1,'prisoner adamant SAY_FREE_AD'),
(3849,1,0,"You are indeed courageous for wanting to brave the horrors that lie beyond this door.",14,0,100,1,1,'prisoner adamant SAY_OPEN_DOOR_AD'),
(3849,2,0,"There we go!",14,0,100,1,1,'prisoner adamant SAY_POST1_DOOR_AD'),
(3849,3,0,"Good luck with Arugal. I must hurry back to Hadrec now.",14,0,100,1,1,'prisoner adamant SAY_POST2_DOOR_AD');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1580016 AND -1580000;
DELETE FROM `creature_text` WHERE `entry` IN (24892,24850,24891);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`text`,`type`,`sound`,`probability`,`comment`) VALUES
(24892,0,0,"There will be no reprieve. My work here is nearly finished.",14,12451,100,'sathrovarr SAY_SATH_AGGRO'),
(24892,1,0,"Pitious mortal!",14,12455,100,'sathrovarr SAY_SATH_SLAY1'),
(24892,1,1,"Haven't you heard? I always win!",14,12456,100,'sathrovarr SAY_SATH_SLAY2'),
(24892,2,0,"I'm... never on... the losing... side...",14,12452,100,'sathrovarr SAY_SATH_DEATH'),
(24892,3,0,"Your misery is my delight!",14,12453,100,'sathrovarr SAY_SATH_SPELL1'),
(24892,4,0,"I will watch you bleed!",14,12454,100,'sathrovarr SAY_SATH_SPELL2'),
(24850,0,0,"Aggh! No longer will I be a slave to Malygos! Challenge me and you will be destroyed!",14,12422,100,'kalecgos SAY_EVIL_AGGRO'),
(24850,1,0,"In the name of Kil'jaeden!",14,12425,100,'kalecgos SAY_EVIL_SLAY1'),
(24850,1,1,"You were warned!",14,12426,100,'kalecgos SAY_EVIL_SLAY2'),
(24850,2,0,"I am forever in your debt. Once we have triumphed over Kil'jaeden, this entire world will be in your debt as well.",14,12431,100,'kalecgos SAY_GOOD_PLRWIN'),
(24850,3,0,"My awakening is complete! You shall all perish!",14,12427,100,'kalecgos SAY_EVIL_ENRAGE'),
(24891,0,0,"I need... your help... Cannot... resist him... much longer...",14,12428,100,'kalecgos SAY_GOOD_AGGRO'),
(24891,1,0,"Aaahhh! Help me, before I lose my mind!",14,12429,100,'kalecgos SAY_GOOD_NEAR_DEATH'),
(24891,2,0,"Hurry! There is not much of me left!",14,12430,100,'kalecgos SAY_GOOD_NEAR_DEATH2');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1580065 AND -1580044;
DELETE FROM `creature_text` WHERE `entry` IN (24882,24895);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`text`,`type`,`sound`,`probability`,`comment`) VALUES
(24882,0,0,"Puny lizard! Death is the only answer you'll find here!",14,12458,100,'brutallus YELL_INTRO'),
(24882,1,0,"Grah! Your magic is weak!",14,12459,100,'brutallus YELL_INTRO_BREAK_ICE'),
(24882,2,0,"I will crush you!",14,12460,100,'brutallus YELL_INTRO_CHARGE'),
(24882,3,0,"That was fun.",14,12461,100,'brutallus YELL_INTRO_KILL_MADRIGOSA'),
(24882,4,0,"Come, try your luck!",14,12462,100,'brutallus YELL_INTRO_TAUNT'),
(24882,5,0,"Ahh! More lambs to the slaughter!",14,12463,100,'brutallus YELL_AGGRO'),
(24882,6,0,"Perish, insect!",14,12464,100,'brutallus YELL_KILL1'),
(24882,6,1,"You are meat!",14,12465,100,'brutallus YELL_KILL2'),
(24882,6,2,"Too easy!",14,12466,100,'brutallus YELL_KILL3'),
(24882,7,0,"Bring the fight to me!",14,12467,100,'brutallus YELL_LOVE1'),
(24882,7,1,"Another day, another glorious battle!",14,12468,100,'brutallus YELL_LOVE2'),
(24882,7,2,"I live for this!",14,12469,100,'brutallus YELL_LOVE3'),
(24882,8,0,"So much for a real challenge... Die!",14,12470,100,'brutallus YELL_BERSERK'),
(24882,9,0,"Gah! Well done... Now... this gets... interesting...",14,12471,100,'brutallus YELL_DEATH'),
(24895,0,0,"Hold, friends! There is information to be had before this devil meets his fate!",14,12472,100,'madrigosa YELL_MADR_ICE_BARRIER'),
(24895,1,0,"Where is Anveena, demon? What has become of Kalec?",14,12473,100,'madrigosa YELL_MADR_INTRO'),
(24895,2,0,"You will tell me where they are!",14,12474,100,'madrigosa YELL_MADR_ICE_BLOCK'),
(24895,3,0,"Speak, I grow weary of asking!",14,12475,100,'madrigosa YELL_MADR_TRAP'),
(24895,4,0,"Malygos, my lord! I did my best!",14,12476,100,'madrigosa YELL_MADR_DEATH');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1580065 AND -1580044;
DELETE FROM `creature_text` WHERE `entry` IN (25166,25165);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(25165,0,0,14,12484,100,"eredar - YELL_INTRO_SAC_1","Misery..."),
(25165,1,0,14,0,100,"eredar - YELL_INTRO_SAC_3","Confusion..."),
(25165,2,0,14,0,100,"eredar - YELL_INTRO_SAC_5","Mistrust..."),
(25165,3,0,14,0,100,"eredar - YELL_INTRO_SAC_7","These are the hallmarks..."),
(25165,4,0,14,0,100,"eredar - YELL_SAC_DEAD","I... fade."),
(25165,5,0,41,0,100,"eredar - EMOTE_SHADOW_NOVA","%s directs Shadow Nova at $N"),
(25165,6,0,14,0,100,"eredar - YELL_ENRAGE","Time is a luxury you no longer possess!"),
(25165,7,0,14,12488,100,"eredar - YELL_SISTER_ALYTHESS_DEAD","Alythess! Your fire burns within me!"),
(25165,8,0,14,12486,100,"eredar - YELL_SAC_KILL_1","Shadow engulf."),
(25165,8,1,14,12487,100,"eredar - YELL_SAC_KILL_2","Ee-nok Kryul!"),
(25165,9,0,14,12485,100,"eredar - YELL_SHADOW_NOVA","Shadow to the aid of fire!"),
(25166,0,0,14,0,100,"eredar - YELL_INTRO_ALY_2","Depravity..."),
(25166,1,0,14,0,100,"eredar - YELL_INTRO_ALY_4","Hatred..."),
(25166,2,0,14,0,100,"eredar - YELL_INTRO_ALY_6","Chaos..."),
(25166,3,0,14,0,100,"eredar - YELL_INTRO_ALY_8","These are the pillars..."),
(25166,4,0,41,0,100,"eredar - EMOTE_CONFLAGRATION","%s directs Conflagration at $N"),
(25166,5,0,14,12490,100,"eredar - YELL_ALY_KILL_1","Fire consume."),
(25166,5,1,14,12491,100,"eredar - YELL_ALY_KILL_2","Ed-ir Halach!"),
(25166,6,0,14,12494,100,"eredar - YELL_ALY_DEAD","De-ek Anur!"),
(25166,7,0,14,12492,100,"eredar - YELL_SISTER_SACROLASH_DEAD","Sacrolash!"),
(25166,8,0,14,12489,100,"eredar - YELL_CANFLAGRATION","Fire to the aid of shadow!"),
(25166,9,0,14,12493,100,"eredar - YELL_BERSERK","Your luck has run its curse!");

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1580098 AND -1580066;
DELETE FROM `creature_text` WHERE `entry` IN (25608,25319,25315,26046);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(25608,0,0,14,12495,100,"KJ - SAY_KJ_OFFCOMBAT1","All my plans have led to this!"),
(25608,0,1,14,12496,100,"KJ - SAY_KJ_OFFCOMBAT2","Stay on task! Do not waste time!"),
(25608,0,2,14,12497,100,"KJ - SAY_KJ_OFFCOMBAT3","I have waited long enough!"),
(25608,0,3,14,12498,100,"KJ - SAY_KJ_OFFCOMBAT4","Fail me and suffer for eternity!"),
(25608,0,4,14,12499,100,"KJ - SAY_KJ_OFFCOMBAT5","Drain the girl! Drain her power until there is nothing but a vacant shell!"),
(25319,0,0,14,12449,100,"KJ - SAY_KALECGOS_ENCOURAGE","Strike now, heroes, while he is weakened! Vanquish the Deceiver!"),
(25319,1,0,14,12440,100,"KJ - SAY_KALECGOS_READY1","I will channel my power into the orbs, be ready!"),
(25319,2,0,14,12441,100,"KJ - SAY_KALECGOS_READY2","I have empowered another orb! Use it quickly!"),
(25319,3,0,14,12442,100,"KJ - SAY_KALECGOS_READY3","Another orb is ready! Make haste!"),
(25319,4,0,14,12443,100,"KJ - SAY_KALECGOS_READY4","I have channeled all I can! The power is in your hands!"),
(25319,5,0,14,12445,100,"KJ - SAY_KALECGOS_AWAKEN","Anveena, you must awaken, this world needs you!"),
(25319,6,0,14,12446,100,"KJ - SAY_KALECGOS_LETGO","You must let go! You must become what you were always meant to be! The time is now, Anveena!"),
(25319,7,0,14,12447,100,"KJ - SAY_KALECGOS_FOCUS","Anveena, I love you! Focus on my voice, come back for me now! Only you can cleanse the Sunwell!"),
(25319,8,0,14,12448,100,"KJ - SAY_KALECGOS_FATE","Yes, Anveena! Let fate embrace you now!"),
(25319,9,0,14,12450,100,"KJ - SAY_KALECGOS_GOODBYE","Goodbye, Anveena, my love. Few will remember your name, yet this day you change the course of destiny. What was once corrupt is now pure. Heroes, do not let her sacrifice be in vain."),
(25319,10,0,14,12438,100,"KJ - SAY_KALECGOS_JOIN","You are not alone. The Blue Dragonflight shall help you vanquish the Deceiver."),
(25315,0,0,14,12527,100,"KJ - SAY_KJ_DEATH","Nooooooooooooo!"),
(25315,1,0,14,12501,100,"KJ - SAY_KJ_SLAY1","Another step towards destruction!"),
(25315,1,1,14,12502,100,"KJ - SAY_KJ_SLAY2","Anak-ky'ri!"),
(25315,2,0,14,12503,100,"KJ - SAY_KJ_REFLECTION1","Who can you trust?"),
(25315,2,1,14,12504,100,"KJ - SAY_KJ_REFLECTION2","The enemy is among you."),
(25315,3,0,14,12500,100,"KJ - SAY_KJ_EMERGE","The expendible have perished... So be it! Now I shall succeed where Sargeras could not! I will bleed this wretched world and secure my place as the true master of the Burning Legion. The end has come! Let the unraveling of this world commence!"),
(25315,4,0,14,12505,100,"KJ - SAY_KJ_DARKNESS1","Chaos!"),
(25315,4,1,14,12506,100,"KJ - SAY_KJ_DARKNESS2","Destruction!"),
(25315,4,2,14,12507,100,"KJ - SAY_KJ_DARKNESS3","Oblivion!"),
(25315,5,0,14,12508,100,"KJ - SAY_KJ_PHASE3","I will not be denied! This world shall fall!"),
(25315,6,0,14,12509,100,"KJ - SAY_KJ_PHASE4","Do not harbor false hope. You cannot win!"),
(25315,7,0,14,12510,100,"KJ - SAY_KJ_PHASE5","Aggghh! The powers of the Sunwell... turned... against me! What have you done? WHAT HAVE YOU DONE?"),
(25315,8,0,41,0,100,"KJ - EMOTE_KJ_DARKNESS","%s begins to channel dark energy"),
(26046,0,0,14,12511,100,"KJ - SAY_ANVEENA_IMPRISONED","I serve only the Master now."),
(26046,1,0,14,12512,100,"KJ - SAY_ANVEENA_LOST","But I'm... lost... I cannot find my way back!"),
(26046,2,0,14,12513,100,"KJ - SAY_ANVEENA_KALEC","Kalec... Kalec?"),
(26046,3,0,14,12514,100,"KJ - SAY_ANVEENA_GOODBYE","The nightmare is over, the spell is broken! Goodbye, Kalec, my love!");

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1580043 AND -1580036;
DELETE FROM `creature_text` WHERE `entry`=25038;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(25038,0,0,14,12477,100,"felmyst - YELL_BIRTH","Glory to Kil'jaeden! Death to all who oppose!"),
(25038,1,0,14,12480,100,"felmyst - YELL_KILL1","I kill for the master!"),
(25038,1,1,14,12481,100,"felmyst - YELL_KILL2","The end has come!"),
(25038,2,0,14,12478,100,"felmyst - YELL_BREATH","Choke on your final breath!"),
(25038,3,0,14,12479,100,"felmyst - YELL_TAKEOFF","I am stronger than ever before!"),
(25038,4,0,14,12482,100,"felmyst - YELL_BERSERK","No more hesitation! Your fates are written!"),
(25038,5,0,14,12483,100,"felmyst - YELL_DEATH","Kil'jaeden... will... prevail..."),
(25038,6,0,14,12439,100,"felmyst - YELL_KALECGOS","Madrigosa deserved a far better fate. You did what had to be done, but this battle is far from over.");

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000292 AND -1000287;
DELETE FROM `creature_text` WHERE `entry`=7806;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(7806,0,0,12,0,100,"oox SAY_OOX_START","Emergency power activated! Initializing ambulanory motor! CLUCK!"),
(7806,1,0,12,0,100,"oox SAY_OOX_AGGRO1","Physical threat detected! Evasive action! CLUCK!"),
(7806,1,1,12,0,100,"oox SAY_OOX_AGGRO2","Thread analyzed! Activating combat plan beta! CLUCK!"),
(7806,2,0,12,0,100,"oox SAY_OOX_AMBUSH","CLUCK! Sensors detect spatial anomaly - danger imminent! CLUCK!"),
(7806,3,0,12,0,100,"oox SAY_OOX_AMBUSH_REPLY","No one challanges the Wastewander nomads - not even robotic chickens! ATTACK!"),
(7806,4,0,12,0,100,"oox SAY_OOX_END","Cloaking systems online! CLUCK! Engaging cloak for transport to Booty Bay!");

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000409 AND -1000403;
DELETE FROM `creature_text` WHERE `entry` IN (2691,7780);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(2691,0,0,12,0,100,"SAY_RIN_BY_OUTRUNNER","Attack my sisters! The troll must not escape!"),
(7780,0,0,12,0,100,"SAY_RIN_FREE","Rin'ji is free!"),
(7780,1,0,12,0,100,"SAY_RIN_HELP_1","Rin'ji needs help!"),
(7780,1,1,12,0,100,"SAY_RIN_HELP_2","Rin'ji is being attacked!"),
(7780,2,0,12,0,100,"SAY_RIN_COMPLETE","Rin'ji can see road now, $n. Rin'ji knows the way home."),
(7780,3,0,12,0,100,"SAY_RIN_PROGRESS_1","Rin'ji will tell you secret now... $n, should go to the Overlook Cliffs. Rin'ji hid something on island there"),
(7780,4,0,12,0,100,"SAY_RIN_PROGRESS_2","You find it, you keep it! Don't tell no one that Rin'ji talked to you!");

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1568009 AND -1568000;
DELETE FROM `creature_text` WHERE `entry`=23578;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(23578,0,0,14,12031,100,"janalai SAY_AGGRO","Spirits of da wind be your doom!"),
(23578,1,0,14,12032,100,"janalai SAY_FIRE_BOMBS","I burn ya now!"),
(23578,2,0,14,12033,100,"janalai SAY_SUMMON_HATCHER","Where ma hatcha? Get to work on dem eggs!"),
(23578,3,0,14,12034,100,"janalai SAY_ALL_EGGS","I show you strength... in numbers."),
(23578,4,0,14,12035,100,"janalai SAY_BERSERK","You done run outta time!"),
(23578,5,0,14,12036,100,"janalai SAY_SLAY_1","It all be over now, mon!"),
(23578,5,1,14,12037,100,"janalai SAY_SLAY_2","Tazaga-choo!"),
(23578,6,0,14,12038,100,"janalai SAY_DEATH","Zul'jin... got a surprise for you..."),
(23578,7,0,14,12039,100,"janalai SAY_EVENT_STRANGERS","Come, strangers. The spirit of the dragonhawk hot be hungry for worthy souls."),
(23578,8,0,14,12040,100,"janalai SAY_EVENT_FRIENDS","Come, friends. Your bodies gonna feed ma hatchlings, and your souls are going to feed me with power!");

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1469006 AND -1469004;
DELETE FROM `creature_text` WHERE `entry`=10162;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(10162,0,0,12,0,100,"victor_nefarius SAY_GAMESBEGIN_1","In this world where time is your enemy, it is my greatest ally. This grand game of life that you think you play in fact plays you. To that I say..."),
(10162,1,0,14,8280,100,"victor_nefarius SAY_GAMESBEGIN_2","Let the games begin!"),
(10162,2,0,14,8279,100,"victor_nefarius SAY_VAEL_INTRO","Ah, the heroes. You are persistent, aren't you. Your allied attempted to match his power against mine, and had to pay the price. Now he shall serve me, by slaughtering you. Get up little red wyrm and destroy them!");
