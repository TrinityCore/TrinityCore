UPDATE `creature_template` SET `resistance2`=1000 WHERE `entry` IN (9816);
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry` IN (10339);
UPDATE `creature_template` SET `spell1`=0, `spell2`=0, `spell3`=0, `spell4`=0 WHERE `entry` IN (9816,10339,10429);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=16337 AND `ConditionValue2`=10429;
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry` IN (10317,10318);

-- Pathing for Warchief Rend Blackhand Entry: 10429
SET @PATH := 1379680;
DELETE FROM `waypoint_data` WHERE `id` IN (@PATH);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,165.4778,-452.2761,121.9753,0,0,1,0,100,0),
(@PATH,2,165.5801,-457.3273,121.9753,0,0,1,0,100,0),
(@PATH,3,165.5504,-465.8904,116.8073,0,0,1,0,100,0),
(@PATH,4,165.3594,-470.635,116.8296,0,0,1,0,100,0),
(@PATH,5,168.4351,-473.7489,116.8424,0,0,1,0,100,0),
(@PATH,6,179.0059,-473.894,116.8424,0,52000,1,0,100,0),
(@PATH,7,216.6058,-430.4544,110.9169,0,0,1,0,100,0),
(@PATH,8,216.5664,-412.0932,110.9822,0,0,1,0,100,0),
(@PATH,9,217.1734,-401.2561,111.0617,0,0,1,0,100,0),
(@PATH,10,216.5286,-397.7477,111.0883,0,0,1,0,100,0),
(@PATH,11,214.8428,-395.8612,111.1051,0,0,1,0,100,0),
(@PATH,12,213.5363,-395.6153,111.1093,0,0,1,0,100,0);

-- Text for Lord Victor Nefarius from sniff
SET @VICTOR := 10162;
DELETE FROM `creature_text` WHERE `entry` IN (@VICTOR);
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
(@VICTOR,9,0,"Taste in my power!",14,0,100,0,0,0,'Lord Victor Nefarius (UBRS)'),
(@VICTOR,10,0,"Your victory shall be short lived. The days of both the Alliance and Horde are coming to an end! The next time we meet shall be the last.",14,0,100,5,0,0,'Lord Victor Nefarius (UBRS)'),
(@VICTOR,11,0,"The mortals have fallen! The new age of the Blackrock legion is at hand!",14,0,100,22,0,0,'Lord Victor Nefarius (UBRS)'),
-- Lord Victor Nefarius texts BWL
(@VICTOR,12,0,"In this world where time is your enemy, it is my greatest ally. This grand game of life that you think you play in fact plays you. To that I say...",14,0,100,1,0,0,'Lord Victor Nefarius SAY_GAMESBEGIN_1 (BWL)'),
(@VICTOR,13,0,"Let the games begin!",14,0,100,22,0,8280,'Lord Victor Nefarius SAY_GAMESBEGIN_2 (BWL)'),
(@VICTOR,14,0,"Ah, the heroes. You are persistent, aren't you. Your allied attempted to match his power against mine, and had to pay the price. Now he shall serve me, by slaughtering you. Get up, little red wyrm...and destroy them!",14,0,100,23,0,8279,'Lord Victor Nefarius SAY_VAEL_INTRO (BWL)');
