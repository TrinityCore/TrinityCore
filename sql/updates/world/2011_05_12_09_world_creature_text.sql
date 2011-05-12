DELETE FROM `creature_text` WHERE `entry` IN (18728);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`sound`,`language`,`probability`,`emote`,`duration`,`comment`) VALUES
(18728,0,0,'I remember well the sting of defeat at the conclusion of the Third War. I have waited far too long for my revenge. Now the shadow of the Legion falls over this world. It is only a matter of time until all of your failed creation... is undone.',1,11332,'kazzak SAY_INTRO'),
(18728,1,0,'The Legion will conquer all!',1,11333,'kazzak SAY_AGGRO1'),
(18728,1,1,'All mortals will perish!',1,11334,'kazzak SAY_AGGRO2'),
(18728,2,0,'All life must be eradicated!',1,11335,'kazzak SAY_SURPREME1'),
(18728,2,1,'I''ll rip the flesh from your bones!',1,11336,'kazzak SAY_SURPREME2'),
(18728,3,0,'Kirel Narak!',1,11337,'kazzak SAY_KILL1'),
(18728,3,1,'Contemptible wretch!',1,11338,'kazzak SAY_KILL2'),
(18728,3,2,'The universe will be remade.',1,11339,'kazzak SAY_KILL3'),
(18728,4,0,'The Legion... will never... fall.',1,11340,'kazzak SAY_DEATH'),
(18728,5,0,'%s goes into a frenzy!',2,0,'kazzak EMOTE_FRENZY'),
(18728,6,0,'Invaders, you dangle upon the precipice of oblivion! The Burning Legion comes and with it comes your end.',1,0,'kazzak SAY_RAND1'),
(18728,6,1,'Impudent whelps, you only delay the inevitable. Where one has fallen, ten shall rise. Such is the will of Kazzak...',1,0,'kazzak SAY_RAND2');
