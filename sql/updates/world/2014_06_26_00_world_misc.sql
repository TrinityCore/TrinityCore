/*  [Q] A Suitable Disguise

SUMMARY:
Basically we are running a random script (4 in total) every 12 seconds after gossip select. Every script has a different subject. For example when we run script @ENTRY*100+1 it will require you to throw a bucket of water into the tub. If you don't do this on time, the event will fail and you'll have to start it over again.
The gossip flags are turned off on gossip select (@ENTRY*100+0) because we don't want the same event to be ran more than once at a time.
As you might have noticed we are using phases a LOT. This helps us to basically add conditions to some lines so they won't occur all the time, yet we can easily time them OOC.
We are also using Data Set event and action types a lot. As you can see when a bunny is hit by the spell which belongs to it, it will set data to Shandy which makes Shandy say something like 'Well done'.
The way the gameobjects are handled is maybe pretty much a work-around but it will need a LOT of core work to make this work like it works on Blizzlike. It should be different objects if you're either horde or alliance. Right now I've just spawned them on-top of each other, because in the end you can only use the object which belongs to your faction.


PROBLEMS:
Shandy Glossgleam should start a waypoint after completing script. (wtb sniffs)
Aquanos' evocation spell seems to have a bugged effect.

RESOURCES:
http://www.youtube.com/watch?v=Fe4mRWO20Hw
http://www.youtube.com/watch?v=tqBbFr_BhC4
http://www.youtube.com/watch?v=OFBRam2MgUw
http://www.wowwiki.com/Quest:A_Suitable_Disguise_(Alliance)

PHASES:
Phase 0: when event did not start yet
Phase 1: when event is happening
Phase 2: when event failed
Phase 4: resetting everything */

-- Shandy Glossgleam SAI
SET @ENTRY := 36856;
SET @QUEST_A := 20438;
SET @QUEST_H := 24556;
SET @OGUID := 56249; 
SET @GOSSIP := 10854; 

UPDATE `creature_template` SET `AIName`='SmartAI',`gossip_menu_id`=@GOSSIP WHERE `entry`=@ENTRY;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100+0,@ENTRY*100+1,@ENTRY*100+2,@ENTRY*100+3,@ENTRY*100+4,@ENTRY*100+5,@ENTRY*100+6,@ENTRY*100+7);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`, `event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`, `target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,@GOSSIP,0,0,0,80,@ENTRY*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandy Glossgleam - On Gossip Select - Run script"),
(@ENTRY,0,1,0,1,1,100,0,8000,8000,12000,12000,88,@ENTRY*100+1,@ENTRY*100+4,0,0,0,0,1,0,0,0,0,0,0,0,"Shandy Glossgleam - Timed - Run Random Script"),
(@ENTRY,0,2,0,38,1,100,0,1,1,0,0,80,@ENTRY*100+5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandy Glossgleam - On Data Set 1 1 - Run Task Successful Script"),
(@ENTRY,0,3,0,1,1,100,0,120000,120000,120000,120000,80,@ENTRY*100+7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandy Glossgleam - Timed - Run Complete Script"),
(@ENTRY,0,4,0,1,2,100,0,0,0,0,0,80,@ENTRY*100+6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandy Glossgleam - Timed - Run Failure Script"),
(@ENTRY,0,5,6,1,4,100,0,30000,30000,30000,30000,81,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandy Glossgleam - Timed - Set Back Gossip & Quest Flags"), -- This can only occur in phase 4 so no need to time it (P4 is set in completion script)
(@ENTRY,0,6,7,61,4,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandy Glossgleam - Timed - Set Phase 0"),
(@ENTRY,0,7,0,61,4,100,0,0,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandy Glossgleam - Timed - Reset Scripts"),
(@ENTRY,0,8,0,40,0,100,0,16,@ENTRY,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandy Glossgleam - On Reached WP 16 - Despawn"),
(@ENTRY,0,9,0,62,0,100,0,@GOSSIP,1,0,0,80,@ENTRY*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandy Glossgleam - On Gossip Select - Run script"),

-- Start script
(@ENTRY*100+0,9,0,0,0,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Shandy Glossgleam - Script 0 - Close Gossip"),
(@ENTRY*100+0,9,1,0,0,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandy Glossgleam - Script 0 - Turn of Gossip & Questgiver flags"),
(@ENTRY*100+0,9,2,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandy Glossgleam - Script 0 - Say Line 0"),
(@ENTRY*100+0,9,3,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandy Glossgleam - Script 0 - Say Line 1"),
(@ENTRY*100+0,9,4,0,0,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandy Glossgleam - Script 0 - Set Phase 1"),
-- Wants Water
(@ENTRY*100+1,9,0,0,0,0,100,0,0,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandy Glossgleam - Script 1 - Say Line 4"),
(@ENTRY*100+1,9,1,0,0,0,100,0,0,0,0,0,12,36947,1,10000,0,0,0,8,0,0,0,5796.970215,693.942993,658.351990,0,"Shandy Glossgleam - Script 1 - Summon Wants Water"),
(@ENTRY*100+1,9,2,0,0,0,100,0,10000,10000,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandy Glossgleam - Script 1 - Set Phase 2"),
-- Wants Pants
(@ENTRY*100+2,9,0,0,0,0,100,0,0,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandy Glossgleam - Script 2 - Say Line 5"),
(@ENTRY*100+2,9,1,0,0,0,100,0,0,0,0,0,12,36945,1,10000,0,0,0,8,0,0,0,5796.970215,693.942993,658.351990,0,"Shandy Glossgleam - Script 2 - Summon Wants Pants"),
(@ENTRY*100+2,9,2,0,0,0,100,0,10000,10000,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandy Glossgleam - Script 2 - Set Phase 2"),
-- Wants Unmentionables
(@ENTRY*100+3,9,0,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandy Glossgleam - Script 3 - Say Line 3"),
(@ENTRY*100+3,9,1,0,0,0,100,0,0,0,0,0,12,36946,1,10000,0,0,0,8,0,0,0,5796.970215,693.942993,658.351990,0,"Shandy Glossgleam - Script 3 - Summon Wants Unmentionables"),
(@ENTRY*100+3,9,2,0,0,0,100,0,10000,10000,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandy Glossgleam - Script 3 - Set Phase 2"),
-- Wants Shirts
(@ENTRY*100+4,9,0,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandy Glossgleam - Script 4 - Say Line 2"),
(@ENTRY*100+4,9,1,0,0,0,100,0,0,0,0,0,12,36944,1,10000,0,0,0,8,0,0,0,5796.970215,693.942993,658.351990,0,"Shandy Glossgleam - Script 4 - Summon Wants Shirts"),
(@ENTRY*100+4,9,2,0,0,0,100,0,10000,10000,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandy Glossgleam - Script 4 - Set Phase 2"),

-- Task successful
(@ENTRY*100+5,9,0,0,0,0,100,0,0,0,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandy Glossgleam - Script 6 - Say Line 6 (random)"),
-- End failure
(@ENTRY*100+6,9,0,0,0,0,100,0,0,0,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandy Glossgleam - Script 7 - Say Line 7"),
(@ENTRY*100+6,9,1,0,0,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandy Glossgleam - Script 7 - Set Phase  0"),
(@ENTRY*100+6,9,2,0,0,0,100,0,0,0,0,0,81,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandy Glossgleam - Script 7 - Set Gossip Flag"),
-- Completion script
(@ENTRY*100+7,9,0,0,0,0,100,0,0,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandy Glossgleam - Script 8 - Stop Current Scripts"),
(@ENTRY*100+7,9,1,0,0,0,100,0,2000,2000,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandy Glossgleam - Script 8 - Say Line 8"),
(@ENTRY*100+7,9,2,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,19,36851,0,0,0,0,0,0,"Shandy Glossgleam - Script 8 - Face Aquanos"),
(@ENTRY*100+7,9,3,0,0,0,100,0,8000,8000,0,0,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shandy Glossgleam - Script 8 - Say Line 9"),
(@ENTRY*100+7,9,4,0,0,0,100,0,0,0,0,0,50,201384,30000,0,0,0,0,8,0,0,0,5797.147461,696.602417,657.949463,6.090852,"Shandy Glossgleam - Script 8 - Summon Clean Laundry"),
(@ENTRY*100+7,9,5,0,0,0,100,0,3000,3000,0,0,53,0,@ENTRY,0,0,0,0,1,0,0,0,0,0,0,0,"Shandy Glossgleam - Script 8 - Set Phase 4");

-- Texts
-- They all emote ONESHOT_TALK apart from request texts (as seen in videos)
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextID`) VALUES
-- Start
(@ENTRY,0,0,"You're in luck. I've got just what you need in the load I'm about to wash.",12,0,100,0,0,0,"Shandy Glossgleam",36761),
(@ENTRY,1,0,"See the piles of laundry and the bucket of water? I'll run out what I need next, and you put it in the tub. Ready?",12,0,100,0,0,0,"Shandy Glossgleam",36762),
-- Requests
(@ENTRY,2,0,"Quick, add some shirts to the laundry!",12,0,100,0,0,0,"Shandy Glossgleam",36788), -- Emote ONESHOT_POINT
(@ENTRY,3,0,"Add the unmentionables... uh, I mean, the 'delicates'!",12,0,100,25,0,0,"Shandy Glossgleam",36789), -- Emote ONESHOT_POINT
(@ENTRY,4,0,"The tub needs more water!",12,0,100,25,0,0,"Shandy Glossgleam",36790), -- Emote ONESHOT_POINT
(@ENTRY,5,0,"Toss some pants in to the tub!",12,0,100,25,0,0,"Shandy Glossgleam",36787), -- Emote ONESHOT_POINT
-- Correct
(@ENTRY,6,0,"I should keep you around.",12,0,100,0,0,0,"Shandy Glossgleam",37989),
(@ENTRY,6,1,"Well done!",12,0,100,0,0,0,"Shandy Glossgleam",36764),
(@ENTRY,6,2,"That's how it's done!",12,0,100,0,0,0,"Shandy Glossgleam",37986),
(@ENTRY,6,3,"Clean and tidy!",12,0,100,0,0,0,"Shandy Glossgleam",37985),
(@ENTRY,6,4,"Nice. I don't want to know what that stain was.",12,0,100,0,0,0,"Shandy Glossgleam",37987),
(@ENTRY,6,5,"Aquanos can hardly keep up!",12,0,40,0,0,0,"Shandy Glossgleam",37988),
-- Incorrect
(@ENTRY,7,0,"Oh, no! That wasn't right. Now I'll have to go get more detergent so we can start over!",12,0,100,0,0,0,"Shandy Glossgleam",36763),
-- End
(@ENTRY,8,0,"Aquanos, stop sending the clothes so high! You didn't have to see the look on Aethas Sunreaver's face when he found his pants in the fountain!",12,0,100,0,0,0,"Shandy Glossgleam",36817),
(@ENTRY,9,0,"See how easy that was with everyone working together? Just take what you need from the clean laundry here, but don't forget to return it when you're finished.",12,0,100,0,0,0,"Shandy Glossgleam",36791);

-- Give Clean Laundry quest item loot
DELETE FROM `gameobject_loot_template` WHERE `entry`=27725;
INSERT INTO `gameobject_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(27725,49648,-100,1,0,1,1);

-- Summon quest gameobjects
DELETE FROM `gameobject` WHERE `id` IN (201295,201931,201301,201296,201300,201932,201936,201933,201299,201855,201298,201297,201934,201935) AND `guid` BETWEEN @OGUID AND @OGUID+13;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
-- Game objects for Alliance quest 20438
-- Water Bucket
(@OGUID, 201298, 571, 1, 1, 5807.094, 690.5868, 659.1125, 0, 0, 0, 0, 1, 120, 255, 1), -- 201298 (Area: 4613)
-- Pants
(@OGUID+1, 201295, 571, 1, 1, 5806.047, 694.5938, 657.949, 1.710422, 0, 0, 0, 1, 120, 255, 1), -- 201295 (Area: 4613)
(@OGUID+2, 201931, 571, 1, 1, 5806.068, 694.5799, 658.4567, 0, 0, 0, 0, 1, 120, 255, 1), -- 201931 (Area: 4613)
-- Shirts
(@OGUID+3, 201296, 571, 1, 1, 5805.592, 691.0816, 657.9492, 0, 0, 0, 0, 1, 120, 255, 1), -- 201296 (Area: 4613)
(@OGUID+4, 201932, 571, 1, 1, 5805.556, 691.1024, 658.3948, 0, 0, 0, 0, 1, 120, 255, 1), -- 201932 (Area: 4613)
-- Unmentionalables
(@OGUID+5, 201933, 571, 1, 1, 5805.316, 697.5625, 658.3061, 0, 0, 0, 0, 1, 120, 255, 1), -- 201933 (Area: 4613)
(@OGUID+6, 201297, 571, 1, 1, 5805.338, 697.5729, 657.9791, 1.640607, 0, 0, 0, 1, 120, 255, 1), -- 201297 (Area: 4613)
-- Game objects for Horde quest 24556
-- Water Bucket
(@OGUID+7, 201855, 571, 1, 1, 5807.094, 690.5868, 659.1125, 0, 0, 0, 0, 1, 120, 255, 1), -- 201855 (Area: 4613)
-- Pants
(@OGUID+8, 201301, 571, 1, 1, 5806.068, 694.5799, 658.4575, 0, 0, 0, 0, 1, 120, 255, 1), -- 201301 (Area: 4613)
(@OGUID+9, 201934, 571, 1, 1, 5806.015, 694.6285, 657.949, 1.710422, 0, 0, 0, 1, 120, 255, 1), -- 201934 (Area: 4613)
-- Shirts
(@OGUID+10, 201300, 571, 1, 1, 5805.579, 691.0868, 658.3615, 0, 0, 0, 0, 1, 120, 255, 1), -- 201300 (Area: 4613)
(@OGUID+11, 201935, 571, 1, 1, 5805.587, 691.0608, 657.9492, 0, 0, 0, 0, 1, 120, 255, 1), -- 201935 (Area: 4613)
-- Unmentionalables
(@OGUID+12, 201936, 571, 1, 1, 5805.326, 697.5555, 657.949, 1.640607, 0, 0, 0, 1, 120, 255, 1), -- 201936 (Area: 4613)
(@OGUID+13, 201299, 571, 1, 1, 5805.316, 697.5625, 658.3046, 0, 0, 0, 0, 1, 120, 255, 1); -- 201299 (Area: 4613)

-- Insert option menu
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`BoxBroadcastTextID`) VALUES
(@GOSSIP,0,0,'Arcanist Tybalin said you might be able to lend me a certain tabard.',1,1,36760),
(@GOSSIP,1,0,'Magister Hathorel said you might be able to lend me a certain tabard.',1,1,37552);

-- Add conditions for gossip - as you see we are using ElseGroup (logical 'OR')
DELETE FROM `conditions` WHERE `SourceGroup` IN (@GOSSIP) AND `ConditionValue1` IN (@QUEST_A,@QUEST_H);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP,0,0,9,@QUEST_A,0,0,0,'',"Only show first gossip if player is on quest A Suitable Disguise (A)"),
(15,@GOSSIP,1,0,9,@QUEST_H,0,0,0,'',"Only show first gossip if player is on quest A Suitable Disguise (H)");

-- Aquanos SAI
SET @ENTRY := 36851;
SET @SPELL_EVOCATION := 69659;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`, `event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`, `target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,2,2,0,0,11,@SPELL_EVOCATION,1,0,0,0,0,1,0,0,0,0,0,0,0,"Aquanos - On Data Set 2 2 - Cast Evocation (Visual Only)");

-- Wants Water SAI
SET @ENTRY := 36947;
SET @SPELL_WATER := 69614;
UPDATE `creature_template` SET `AIName`='SmartAI',`minlevel`=70,`maxlevel`=70,`exp`=2,`unit_class`=2,`unit_flags`=`unit_flags`|33554432,`flags_extra`=`flags_extra`|128 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`, `event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`, `target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,1,@SPELL_WATER,0,0,0,45,1,1,0,0,0,0,19,36856,0,0,0,0,0,0,"Wants Water - On Spellhit - Set Data Shandy Glossgleam"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,45,2,2,0,0,0,0,19,36851,0,0,0,0,0,0,"Wants Water - On Spellhit - Set Data Aquanos");

-- Wants Pants SAI
SET @ENTRY := 36945;
SET @SPELL_PANTS := 69600;
UPDATE `creature_template` SET `AIName`='SmartAI',`minlevel`=70,`maxlevel`=70,`exp`=2,`unit_class`=2,`unit_flags`=`unit_flags`|33554432,`flags_extra`=`flags_extra`|128 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`, `event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`, `target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,1,@SPELL_PANTS,0,0,0,45,1,1,0,0,0,0,19,36856,0,0,0,0,0,0,"Wants Pants - On Spellhit - Set Data Shandy Glossgleam"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,45,2,2,0,0,0,0,19,36851,0,0,0,0,0,0,"Wants Pants - On Spellhit - Set Data Aquanos");

-- Wants Unmentionables SAI
SET @ENTRY := 36946;
SET @SPELL_UNMENTIONABLES := 69601;
UPDATE `creature_template` SET `AIName`='SmartAI',`minlevel`=70,`maxlevel`=70,`exp`=2,`unit_class`=2,`unit_flags`=`unit_flags`|33554432,`flags_extra`=`flags_extra`|128 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`, `event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`, `target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,1,@SPELL_UNMENTIONABLES,0,0,0,45,1,1,0,0,0,0,19,36856,0,0,0,0,0,0,"Wants Unmentionables - On Spellhit - Set Data Shandy Glossgleam"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,45,2,2,0,0,0,0,19,36851,0,0,0,0,0,0,"Wants Unmentionables - On Spellhit - Set Data Aquanos");

-- Wants Shirts SAI
SET @ENTRY := 36944;
SET @SPELL_SHIRT := 69593;
UPDATE `creature_template` SET `AIName`='SmartAI',`minlevel`=70,`maxlevel`=70,`exp`=2,`unit_class`=2,`unit_flags`=`unit_flags`|33554432,`flags_extra`=`flags_extra`|128 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`, `event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`, `target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,1,@SPELL_SHIRT,0,0,0,45,1,1,0,0,0,0,19,36856,0,0,0,0,0,0,"Wants Shirts - On Spellhit - Set Data Shandy Glossgleam"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,45,2,2,0,0,0,0,19,36851,0,0,0,0,0,0,"Wants Shirts - On Spellhit - Set Data Aquanos");

-- The conditions are made this way because the PLAYER should throw the 'item'. (water, shirt, pant, etc.) Basically when you click the object it casts a trigger spell on you. This trigger spell can only target players and will make the player cast 'Toss XX', which has direct conditions to one of the Wants XX imps.
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (69593,69600,69601,69614,69548,69542,69544,69543);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`comment`) VALUES
(13,1,69593,31,3,36944, 'Toss Shirts requires target Wants Shirts'),
(13,1,69600,31,3,36945, 'Toss Pants requires target Wants Pants'),
(13,1,69601,31,3,36946, 'Toss Unmentionables requires target Wants Unmentionables'),
(13,1,69614,31,3,36947, 'Toss Water requires target Wants Water'),
-- other conditions are unneeded, and having them causes problems.
-- These are erroring still, but the quest works with this change:
(13,1,69548,32,128,0,'Trigger Throw Water requires target player'),
(13,1,69542,32,128,0,'Trigger Throw Pants requires target player'),
(13,1,69544,32,128,0,'Trigger Throw Unmentionables requires target player'),
(13,1,69543,32,128,0,'Trigger Throw Shirt requires target player');

-- Waypoints
DELETE FROM `waypoints` WHERE `entry`=36856;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(36856, 1, 5800.057, 691.5624, 658.0007, 'Shandy Glossgleam WP 1'),
(36856, 2, 5802.057, 691.5624, 658.0007, 'Shandy Glossgleam WP 2'),
(36856, 3, 5802.307, 690.0624, 658.0007, 'Shandy Glossgleam WP 3'),
(36856, 4, 5802.557, 688.8124, 658.0007, 'Shandy Glossgleam WP 4'),
(36856, 5, 5802.824, 688.4631, 657.9935, 'Shandy Glossgleam WP 5'),
(36856, 6, 5803.074, 686.4631, 658.2435, 'Shandy Glossgleam WP 6'),
(36856, 7, 5803.574, 681.9631, 658.2435, 'Shandy Glossgleam WP 7'),
(36856, 8, 5804.324, 677.7131, 658.2435, 'Shandy Glossgleam WP 8'),
(36856, 9, 5804.842, 673.8136, 658.0798, 'Shandy Glossgleam WP 9'),
(36856, 10, 5802.092, 671.8136, 658.3298, 'Shandy Glossgleam WP 10'),
(36856, 11, 5801.806, 671.6563, 658.1652, 'Shandy Glossgleam WP 11'),
(36856, 12, 5801.306, 671.1563, 658.1652, 'Shandy Glossgleam WP 12'),
(36856, 13, 5800.306, 671.9063, 658.4152, 'Shandy Glossgleam WP 13'),
(36856, 14, 5799.306, 672.9063, 657.4152, 'Shandy Glossgleam WP 14'),
(36856, 15, 5798.056, 673.4063, 656.4152, 'Shandy Glossgleam WP 15'),
(36856, 16, 5795.953, 674.7413, 654.7663, 'Shandy Glossgleam WP 16 - Despawn');
