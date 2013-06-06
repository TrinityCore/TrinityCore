-- http://www.youtube.com/watch?v=G89A9ITuTfs
-- Missing combat spell entries; Cata spells: 70316 (Cleave),84419 (Challenging Shout)

-- Paval should also attack --- faction 35 to 232 ----
-- Couldn't fix Ogron evading when entering combat

-- [Q] Questioning Reethe
SET @ENTRY_OGRON := 4983; -- Ogron
SET @ENTRY_PAVAL := 4980; -- Paval Reethe
SET @ENTRY_CALDWELL := 5046; -- Lieutenant Caldwell
SET @ENTRY_SKIRM := 5044; -- Theramore Skirmisher
SET @ENTRY_HALAN := 5045; -- Private Hallan
SET @SPELL_FAKE_SHOT := 7105;

-- Quest completable by external event
UPDATE `quest_template` SET `SpecialFlags`=`SpecialFlags`|2 WHERE `Id`=1273; -- Questioning Reethe

-- Set SAI AIName
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@ENTRY_OGRON,@ENTRY_PAVAL,@ENTRY_CALDWELL,@ENTRY_SKIRM,@ENTRY_HALAN);

-- Template updates
UPDATE `creature` SET `spawntimesecs`=120 WHERE `id`=@ENTRY_PAVAL;
UPDATE `creature_template` SET `faction_A`=35,`faction_H`=35 WHERE `entry` IN (@ENTRY_CALDWELL,@ENTRY_SKIRM,@ENTRY_HALAN); -- Script changes faction to 151 later
UPDATE `creature_template` SET `equipment_id`=189 WHERE `entry`=@ENTRY_HALAN;
UPDATE `creature_model_info` SET `bounding_radius`=1.29485,`combat_reach`=2.175,`gender`=0 WHERE `modelid`=10704; -- Ogron
DELETE FROM `creature_template_addon` WHERE `entry` IN (@ENTRY_OGRON,@ENTRY_PAVAL);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@ENTRY_OGRON,0,0,257,0,NULL),-- Ogron
(@ENTRY_PAVAL,0,0,1,0,NULL); -- Paval Reethe

-- Waypoints
DELETE FROM `waypoints` WHERE `entry`=@ENTRY_OGRON;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY_OGRON,1,-3349.78,-3134.81,28.5267,'Ogron'),
(@ENTRY_OGRON,2,-3366.01,-3144.31,35.2659,'Ogron'),
(@ENTRY_OGRON,3,-3367.34,-3164.10,35.9618,'Ogron'),
(@ENTRY_OGRON,4,-3372.77,-3174.81,35.8517,'Ogron'),
(@ENTRY_OGRON,5,-3378.53,-3191.64,35.7204,'Ogron'),
(@ENTRY_OGRON,6,-3370.92,-3190.48,34.1671,'Ogron'),
(@ENTRY_OGRON,7,-3366.86,-3209.47,33.9713,'Ogron');
-- (@ENTRY_OGRON,8,-3365.56,-3209.19,34.0187,'Ogron');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY_OGRON,@ENTRY_HALAN,@ENTRY_SKIRM,@ENTRY_CALDWELL,@ENTRY_PAVAL) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY_OGRON*100,@ENTRY_OGRON*100+1,@ENTRY_CALDWELL*100,@ENTRY_HALAN*100,@ENTRY_PAVAL*100,@ENTRY_CALDWELL*100+1,@ENTRY_PAVAL*100+1,@ENTRY_OGRON*100+2) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY_OGRON,0,0,0,6,0,100,0,0,0,0,0,6,1273,0,0,0,0,0,7,0,0,0,0,0,0,0,'Ogron - On Death - Fail Quest'),
(@ENTRY_OGRON,0,1,0,19,0,100,0,1273,0,0,0,80,@ENTRY_OGRON*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ogron - On Quest Accept - Script'),
(@ENTRY_OGRON*100,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'Ogron - On Script - Say "I noticed some fire.."'),
(@ENTRY_OGRON*100,9,1,0,0,0,100,0,0,0,0,0,53,0,@ENTRY_OGRON,0,0,0,2,1,0,0,0,0,0,0,0,'Ogron - On Script - Start WP'),
(@ENTRY_OGRON,0,2,0,40,0,100,0,5,@ENTRY_OGRON,0,0,54,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ogron - On WP 5 - Pause Path'),
(@ENTRY_OGRON,0,3,4,55,0,100,0,5,@ENTRY_OGRON,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ogron - On WP 5 - Say "That''s Reethe..."'), -- Link to 4
(@ENTRY_OGRON,0,4,0,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,6.281,'Ogron - On Link (WP 5) - Set Orientation'),
(@ENTRY_OGRON,0,5,0,58,0,100,0,7,@ENTRY_OGRON,0,0,80,@ENTRY_OGRON*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ogron - On WP 7 - Run Second Script'),
(@ENTRY_OGRON*100+1,9,0,0,0,0,100,0,0,0,0,0,54,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Paval - On Script - Pause WP'),
(@ENTRY_OGRON*100+1,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,9,@ENTRY_PAVAL,0,15,0,0,0,0,'Paval - On Script - Say "W-what do you..."'),
(@ENTRY_OGRON*100+1,9,2,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,9,@ENTRY_PAVAL,0,15,0,0,0,0,'Paval - On Script - Say "I swear, I didn''t..."'),
(@ENTRY_OGRON*100+1,9,3,0,0,0,100,0,4000,4000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ogron - On Script - Say "Just tell us..."'),
(@ENTRY_OGRON*100+1,9,4,0,0,0,100,0,3500,3500,0,0,1,2,0,0,0,0,0,9,@ENTRY_PAVAL,0,15,0,0,0,0,'Paval - On Script - Say "I... Well, I may..."'),
(@ENTRY_OGRON*100+1,9,5,0,0,0,100,0,3500,3500,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ogron - On Script - Say "Look here,if you..."'),
(@ENTRY_OGRON*100+1,9,6,0,0,0,100,0,2000,2000,0,0,1,3,0,0,0,0,0,9,@ENTRY_PAVAL,0,15,0,0,0,0,'Paval - On Script - Say "Not one step closer..."'),
(@ENTRY_OGRON*100+1,9,7,0,0,0,100,0,3000,3000,0,0,1,4,0,0,0,0,0,9,@ENTRY_PAVAL,0,15,0,0,0,0,'Paval - On Script - Say "And I don''t know..."'),
(@ENTRY_OGRON*100+1,9,8,0,0,0,100,0,3500,3500,0,0,1,5,0,0,0,0,0,9,@ENTRY_PAVAL,0,15,0,0,0,0,'Paval - On Script - Say "What was that? Did..."'),
(@ENTRY_OGRON*100+1,9,9,0,0,0,100,0,0,0,0,0,12,@ENTRY_HALAN,2,5*60*1000,0,0,0,8,0,0,0,-3384.600098,-3211.340088,34.868,0,'Ogron - On Script - Summon Private Hallan'),
(@ENTRY_OGRON*100+1,9,10,0,0,0,100,0,0,0,0,0,12,@ENTRY_SKIRM,2,5*60*1000,0,0,0,8,0,0,0,-3384.443604,-3208.477539,34.849,0,'Ogron - On Script - Summon Theramore Skirmisher'),
(@ENTRY_OGRON*100+1,9,11,0,0,0,100,0,0,0,0,0,12,@ENTRY_SKIRM,2,5*60*1000,0,0,0,8,0,0,0,-3385.615234,-3209.867432,34.904,0,'Ogron - On Script - Summon Theramore Skirmisher'),
(@ENTRY_OGRON*100+1,9,12,0,0,0,100,0,0,0,0,0,12,@ENTRY_CALDWELL,2,5*60*1000,0,0,0,8,0,0,0,-3381.498535,-3209.195068,35.037,0,'Ogron - On Script - Summon Lieutenant Caldwell'),
(@ENTRY_OGRON*100+1,9,13,0,0,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ogron - On Script - Set react state aggresive'),

(@ENTRY_HALAN,0,0,0,11,0,100,0,0,0,0,0,46,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Hallan - On Spawn - Move forward'),
(@ENTRY_SKIRM,0,0,0,11,0,100,0,0,0,0,0,46,4.5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Skirmisher - On Spawn - Move forward'),
(@ENTRY_HALAN,0,1,0,11,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Hallan - On Spawn - Set Run 0'),
(@ENTRY_SKIRM,0,1,0,11,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Skirmisher - On Spawn - Set Run 0'),

(@ENTRY_CALDWELL,0,0,0,11,0,100,0,0,0,0,0,80,@ENTRY_CALDWELL*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Caldwell - On spawn - Script'),
(@ENTRY_CALDWELL*100,9,0,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-3373.983398,-3210.881104,34.711,0,'Caldwell - On Script - Move'),
(@ENTRY_CALDWELL*100,9,1,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'Caldwell - On Script - Say "Paval Reethe! Found..."'),
(@ENTRY_CALDWELL*100,9,2,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,'Caldwell - On Script - Say "Private, show Lieutenant..."'),
(@ENTRY_CALDWELL*100,9,3,0,0,0,100,0,500,500,0,0,45,1,1,0,0,0,0,11,@ENTRY_HALAN,20,0,0,0,0,0,'Caldwell - On Script - Set Data Hallan'),

(@ENTRY_HALAN,0,2,0,38,0,100,0,1,1,0,0,80,@ENTRY_HALAN*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Hallan - On Data Set - Run Script'),
(@ENTRY_HALAN*100,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'Hallan - On Script - Say "Gladly, sir."'),
(@ENTRY_HALAN*100,9,1,0,0,0,100,0,0,0,0,0,11,@SPELL_FAKE_SHOT,0,0,0,0,0,11,@ENTRY_PAVAL,60,0,0,0,0,0,'Hallan - On Script - Cast Fake Shot'),

(@ENTRY_PAVAL,0,0,0,8,0,100,0,@SPELL_FAKE_SHOT,0,0,0,80,@ENTRY_PAVAL*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Paval - On Spellhit - Run Script'),
(@ENTRY_PAVAL*100,9,0,0,0,0,100,0,0,0,0,0,1,6,0,0,0,0,0,9,@ENTRY_PAVAL,0,15,0,0,0,0,'Paval - On Script - Say "Paval staggers back..."'),
(@ENTRY_PAVAL*100,9,1,0,0,0,100,0,2000,2000,0,0,1,7,0,0,0,0,0,9,@ENTRY_PAVAL,0,15,0,0,0,0,'Paval - On Script - Say "Ugh... Hallan..."'),
(@ENTRY_PAVAL*100,9,2,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.771,'Paval - On Script - Face Caldwell'),
(@ENTRY_PAVAL*100,9,3,0,0,0,100,0,2000,2000,0,0,1,2,0,0,0,0,0,9,@ENTRY_CALDWELL,0,15,0,0,0,0,'Caldwell - On Script - Say "Now let''s..."'),
(@ENTRY_PAVAL*100,9,4,0,0,0,100,0,1000,1000,0,0,1,4,0,0,0,0,0,9,@ENTRY_OGRON,0,15,0,0,0,0,'Ogron - On Script - Say "Damn it! You..."'),
(@ENTRY_PAVAL*100,9,5,0,0,0,100,0,0,0,0,0,2,16,0,0,0,0,0,9,@ENTRY_HALAN,0,15,0,0,0,0,'Paval - On Script - Set faction 151 on Hallan'),
(@ENTRY_PAVAL*100,9,6,0,0,0,100,0,0,0,0,0,2,16,0,0,0,0,0,9,@ENTRY_SKIRM,0,15,0,0,0,0,'Paval - On Script - Set faction 151 on Skirm'),
(@ENTRY_PAVAL*100,9,7,0,0,0,100,0,0,0,0,0,2,16,0,0,0,0,0,9,@ENTRY_CALDWELL,0,15,0,0,0,0,'Paval - On Script - Set faction 151 on Caldwell'),

(@ENTRY_CALDWELL,0,1,0,6,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,@ENTRY_PAVAL,20,0,0,0,0,0,'Caldwell - On Death - Set data to Paval'),
(@ENTRY_CALDWELL,0,2,0,6,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,@ENTRY_OGRON,20,0,0,0,0,0,'Caldwell - On Death - Set data to Ogron'),
(@ENTRY_OGRON,0,7,0,38,0,100,0,1,1,0,0,69,0,0,0,0,0,0,8,0,0,0,-3366.86,-3209.47,33.9713,0,'Ogron - On Data set - Move to pos'),
(@ENTRY_PAVAL,0,6,0,38,0,100,0,1,1,0,0,80,@ENTRY_PAVAL*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Paval - On Data Set - Run second timed action list'),
(@ENTRY_PAVAL*100+1,9,0,0,0,0,100,0,0,0,0,0,15,1273,0,0,0,0,0,17,0,15,0,0,0,0,0,'Paval - On Script - Quest Credit'),
(@ENTRY_PAVAL*100+1,9,1,0,0,0,100,0,2000,2000,0,0,84,5,0,0,0,0,0,9,@ENTRY_OGRON,0,15,0,0,0,0,'Ogron - On Script - Say "Still with us..."'),
(@ENTRY_PAVAL*100+1,9,2,0,0,0,100,0,2000,2000,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Paval - On Script - Say "Must be your lucky day..."'),
(@ENTRY_PAVAL*100+1,9,3,0,0,0,100,0,0,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Paval - On Script - Die'),
(@ENTRY_PAVAL*100+1,9,4,0,0,0,100,0,1000,1000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Paval - On Script - Despawn'),
(@ENTRY_PAVAL*100+1,9,5,0,0,0,100,0,1000,1000,0,0,84,6,0,0,0,0,0,9,@ENTRY_OGRON,0,15,0,0,0,0,'Ogron - On Script - Say "Looks dead to me..."'),
(@ENTRY_PAVAL*100+1,9,6,0,0,0,100,0,3500,3500,0,0,84,7,0,0,0,0,0,9,@ENTRY_OGRON,0,15,0,0,0,0,'Ogron - On Script - Say "By the way..."'),
(@ENTRY_PAVAL*100+1,9,7,0,0,0,100,0,0,0,0,0,45,4,4,0,0,0,0,9,@ENTRY_OGRON,0,15,0,0,0,0,'Paval - On Script - Set Data Ogron'),

(@ENTRY_OGRON,0,8,0,0,0,100,1,500,1500,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ogron - In combat say "Me smash.." or "I''ll crush you!"');

-- Texts
DELETE FROM `creature_text` WHERE `entry` IN (@ENTRY_OGRON,@ENTRY_PAVAL,@ENTRY_CALDWELL,@ENTRY_HALAN);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY_OGRON,0,0,'I noticed some fire on that island over there. A human, too. Let''s go check it out, $N.',12,0,0,0,0,0,'Ogron'),
(@ENTRY_OGRON,1,0,'That''s Reethe alright. Let''s go see what he has to say, yeah?',12,0,0,0,0,0,'Ogron'),

(@ENTRY_PAVAL,0,0,'W-what do you want? Just leave me alone...',12,0,0,0,0,0,'Paval'),
(@ENTRY_PAVAL,1,0,'I swear, I didn''t steal anything from you! Here, take some of my supplies, just go away!',12,0,0,0,0,0,'Paval'),
(@ENTRY_OGRON,2,0,'Just tell us what you know about the Shady Rest Inn, and I won''t bash your skull in.',12,0,0,0,0,0,'Ogron'),
(@ENTRY_PAVAL,2,0,'I... Well, I may of taken a little thing or two from the inn... but what would an ogre care about that?',12,0,0,0,0,0,'Paval'),
(@ENTRY_OGRON,3,0,'Look here, if you don''t tell me about the fire--',12,0,0,0,0,0,'Ogron'),
(@ENTRY_PAVAL,3,0,'Not one step closer, ogre!',12,0,0,0,0,0,'Paval'),
(@ENTRY_PAVAL,4,0,'And I don''t know anything about this fire of yours...',12,0,0,0,0,0,'Paval'),
(@ENTRY_PAVAL,5,0,'What was that? Did you hear something?',12,0,0,0,0,0,'Paval'),

(@ENTRY_CALDWELL,0,0,'Paval Reethe! Found you at last. And consorting with ogres now? No fear, even deserters and traitors are afforded some mercy.',12,0,0,0,0,0,'Caldwell'),
(@ENTRY_CALDWELL,1,0,'Private, show Lieutenant Reethe some mercy.',12,0,0,0,0,0,'Caldwell'),
(@ENTRY_HALAN,0,0,'Gladly, sir.',12,0,0,0,0,0,'Hallan'),
(@ENTRY_PAVAL,6,0,'%s staggers back as the arrow lodges itself deeply in his chest.',16,0,0,0,0,0,'Paval'),
(@ENTRY_PAVAL,7,0,'Ugh... Hallan, didn''t think you had it in you...',12,0,0,16,0,0,'Paval'),
(@ENTRY_CALDWELL,2,0,'Now, let''s clean up the rest of the trash, men!',12,0,0,0,0,0,'Caldwell'),
(@ENTRY_OGRON,4,0,'Damn it! You''d better not die on me, human!',12,0,0,0,0,0,'Ogron'),
-- QC
(@ENTRY_OGRON,5,0,'Still with us, Reethe?',12,0,0,0,0,0,'Ogron'),
(@ENTRY_PAVAL,8,0,'Must be your lucky day. Alright, I''ll talk. Just leave me alone. Look, you''re not going to believe me, but it wa... oh, Light, looks like the girl could shoot...',12,0,0,0,0,0,'Paval'),
-- Paval dies & despawns
(@ENTRY_OGRON,6,0,'Looks dead to me. Not much use to us like this. You''d better go back and tell Krog what happened.',12,0,0,0,0,0,'Ogron'),
(@ENTRY_OGRON,7,0,'By the way, thanks for watching my back.',12,0,0,0,0,0,'Ogron'),

(@ENTRY_OGRON,8,0,'Me smash! You die!',12,0,0,0,0,0,'Ogron'),
(@ENTRY_OGRON,8,1,'I''ll crush you!',12,0,0,0,0,0,'Ogron');
