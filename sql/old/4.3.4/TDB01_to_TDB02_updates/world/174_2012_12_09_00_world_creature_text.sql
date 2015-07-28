DELETE FROM `creature_text` WHERE `entry`=1756;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(1756,0,0,12,0,100,"lord gregor lescovar SAY_GUARD_2","Yes, sir!"),
(1756,1,0,12,0,100,"tyrion spybot SAY_GUARD_1","Of course. He awaits you in the library.");

DELETE FROM `creature_text` WHERE `entry`=1754;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(1754,0,0,12,0,100,"lord gregor lescovar SAY_LESCOVAR_2","It's time for my meditation, leave me."),
(1754,1,0,12,0,100,"lord gregor lescovar SAY_LESCOVAR_3","There you are. What news from Westfall?"),
(1754,2,0,12,0,100,"lord gregor lescovar SAY_LESCOVAR_4","Hmm, it could be that meddle Shaw. I will see what I can discover. Be off with you. I'll contact you again soon."),
(1754,3,0,12,0,100,"tyrion spybot SAY_LESCOVAR_1","Ah, thank you kindly. I will leave you to the library while I tend to this small matter.");

DELETE FROM `creature_text` WHERE `entry`=3849;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(3849,0,0,14,0,100,"prisoner adamant SAY_FREE_AD","Free from this wretched cell at last! Let me show you to the courtyard...."),
(3849,1,0,14,0,100,"prisoner adamant SAY_OPEN_DOOR_AD","You are indeed courageous for wanting to brave the horrors that lie beyond this door."),
(3849,2,0,14,0,100,"prisoner adamant SAY_POST1_DOOR_AD","There we go!"),
(3849,3,0,14,0,100,"prisoner adamant SAY_POST2_DOOR_AD","Good luck with Arugal. I must hurry back to Hadrec now."),
(3849,4,0,12,0,100,"prisoner adamant SAY_BOSS_DIE_AD","About time someone killed the wretch.");

DELETE FROM `creature_text` WHERE `entry`=17243;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(17243,0,0,12,0,100,"engineer spark SAY_TEXT","Yes Master, all goes along as planned."),
(17243,1,0,16,0,100,"engineer spark EMOTE_SHELL","%s puts the shell to his ear."),
(17243,2,0,14,0,100,"engineer spark SAY_ATTACK","Now I cut you!"),
(17243,3,0,12,0,100,"geezle SPARK_SAY_2","What's the big idea? You nearly blew my cover, idiot! I told you to put the compass and navigation maps somewhere safe - not out in the open for any fool to discover."),
(17243,4,0,12,0,100,"geezle SPARK_SAY_3","The Master has gone to great lengths to secure information about the whereabouts of the Exodar. You could have blown the entire operation, including the cover of our spy on the inside."),
(17243,5,0,12,0,100,"geezle SPARK_SAY_5","Relax? Do you know what Kael'thas does to those that fail him, Geezle? Eternal suffering and pain... Do NOT screw this up, fool."),
(17243,6,0,12,0,100,"geezle SPARK_SAY_6","Our Bloodmyst scouts have located our contact. The fool, Velen, will soon leave himself open and defenseless -- long enough for us to strike! Now get out of my sight before I vaporize you..."),
(17243,7,0,16,0,100,"geezle EMOTE_SPARK","picks up the naga flag.");

DELETE FROM `creature_text` WHERE `entry`=38113;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(38113,0,0,14,16734,100,"marwyn SAY_AGGRO","Death is all that you will find here!"),
(38113,1,0,14,16735,100,"marwyn SAY_SLAY_1","I saw the same look in his eyes when he died. Terenas could hardly believe it. Hahahaha!"),
(38113,1,1,14,16736,100,"marwyn SAY_SLAY_2","Choke on your suffering!"),
(38113,2,0,14,16737,100,"marwyn SAY_DEATH","Yes... Run... Run to meet your destiny... Its bitter, cold embrace, awaits you."),
(38113,3,0,14,16739,100,"marwyn SAY_CORRUPTED_FLESH_1","Your flesh has decayed before your very eyes!"),
(38113,3,1,14,16740,100,"marwyn SAY_CORRUPTED_FLESH_2","Waste away into nothingness!"),
(38113,4,0,14,16741,100,"marwyn SAY_MARWYN_INTRO_1","As you wish, my lord.");
