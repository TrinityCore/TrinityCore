-- Text for Lord Victor Nefarius from sniff
SET @VICTOR := 10162;
SET @REND   := 10429;
DELETE FROM `creature_text` WHERE `entry` IN (@VICTOR,@REND);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
-- Lord Victor Nefarius texts UBRS
(@VICTOR,0,0,"Excellent... it would appear as if the meddlesome insects have arrived just in time to feed my legion. Welcome, mortals!",14,0,100,22,0,0,'Lord Victor Nefarius (UBRS)'),
(@VICTOR,1,0,"Let not even a drop of their blood remain upon the arena floor, my children. Feast on their souls!",14,0,100,22,0,0,'Lord Victor Nefarius (UBRS)'),
(@VICTOR,2,0,"Foolsss... Kill the one in the dress!",14,0,100,22,0,0,'Lord Victor Nefarius (UBRS)'),
(@VICTOR,3,0,"Inconceivable!",14,0,100,22,0,0,'Lord Victor Nefarius (UBRS)'),
(@VICTOR,4,0,"Your efforts will prove fruitless. None shall stand in our way!",14,0,100,22,0,0,'Lord Victor Nefarius (UBRS)'),
(@VICTOR,5,0,"Do not force my hand, children! I shall use your hides to line my boots.",14,0,100,22,0,0,'Lord Victor Nefarius (UBRS)'),
(@VICTOR,6,0,"Use the freezing breath, imbecile!",14,0,100,22,0,0,'Lord Victor Nefarius (UBRS)'),
(@VICTOR,7,0,"THIS CANNOT BE!!! Rend, deal with these insects.",14,0,100,0,0,0,'Lord Victor Nefarius (UBRS)'),
(@VICTOR,8,0,"The Warchief shall make quick work of you, mortals. Prepare yourselves!",14,0,100,25,0,0,'Lord Victor Nefarius (UBRS)'),
(@VICTOR,9,0,"Your victory shall be short lived. The days of both the Alliance and Horde are coming to an end! The next time we meet shall be the last.",14,0,100,5,0,0,'Lord Victor Nefarius (UBRS)'),
-- Lord Victor Nefarius texts BWL
(@VICTOR,10,0,"In this world where time is your enemy, it is my greatest ally. This grand game of life that you think you play in fact plays you. To that I say...",12,0,100,22,0,0,'Lord Victor Nefarius SAY_GAMESBEGIN_1 (BWL)'),
(@VICTOR,11,0,"Let the games begin!",14,0,100,22,0,8280,'Lord Victor Nefarius SAY_GAMESBEGIN_2 (BWL)'),
(@VICTOR,12,0,"Ah, the heroes. You are persistent, aren't you. Your allied attempted to match his power against mine, and had to pay the price. Now he shall serve me, by slaughtering you. Get up little red wyrm and destroy them!",14,0,100,22,0,8279,'Lord Victor Nefarius SAY_VAEL_INTRO (BWL)'),
-- Warchief Rend Blackhand text
(@REND,0,0,"With pleasure...",14,0,100,0,0,0,'Warchief Rend Blackhand');
