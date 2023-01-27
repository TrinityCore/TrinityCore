
    DELETE FROM `creature_addon` WHERE (`guid`=45877);
    REPLACE INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (45877, 0, 0, 50331648, 1, 0, '');
     
    -- http://www.wowhead.com/quest=24960  The Wakening
    -- remove the autocomplete flag
    UPDATE quest_template SET Flags=0 WHERE id=24960;
     
    -- npc needed  
    -- http://www.wowhead.com/npc=38895
    -- http://www.wowhead.com/npc=49230
    -- http://www.wowhead.com/npc=49231
     
    -- a ! over all npcs.. wrong
    DELETE FROM creature_questrelation WHERE id IN (38895,49230,49231) and quest=24960;
     
     
    DELETE FROM `creature_addon` WHERE guid in (select guid from creature WHERE id=49230);
    DELETE FROM `creature` WHERE `id`=49230;
    DELETE FROM waypoint_data WHERE id=99759051;
    DELETE FROM `creature` WHERE `id`=2307;
    REPLACE INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
    (45281, 2307, 0, 85, 5692, 1, 1, 3522, 2, 1685.67, 1647.57, 137.327, 2.1293, 500, 0, 0, 102, 0, 0, 0, 0, 0);
    DELETE FROM `creature_addon` WHERE (`guid`=5660);
     
     
    -- Lilian Voss
    SET @Entry  := 38895;
    SET @SOURCETYPE := 0;
    UPDATE creature_template SET gossip_menu_id=17564 WHERE entry=@Entry;
    DELETE FROM gossip_menu WHERE entry IN (17564,17565);
    REPLACE INTO gossip_menu VALUES(17564,17564);
    REPLACE INTO gossip_menu VALUES(17565,17565);
    DELETE FROM gossip_menu_option WHERE menu_id IN (17564,17565);
    REPLACE INTO gossip_menu_option VALUES (17564,0,0,"I\'m not an abomination, I\'m simply undead. I just want to speak with you.",1,1,17565,0,0,0,NULL);
    REPLACE INTO gossip_menu_option VALUES (17565,0,0,"Lilian, do you realize that you are undead yourself?",1,1,0,0,0,0,NULL);
    DELETE FROM npc_text WHERE ID IN (17564,17565);
    REPLACE INTO npc_text SET ID=17564,text0_0="Get away from me, you abomination!",WDBVerified=1;
    REPLACE INTO npc_text SET ID=17565,text0_0="The undead are a taint upon Azeroth! Every one of you creatures deserves to be destroyed!",WDBVerified=1;
    DELETE FROM creature_text WHERE entry=@Entry;
    REPLACE INTO creature_text VALUES (@Entry,0,0,"No. You\'re lying! My father will protect me!",12,0,100,0,0,0,NULL);
    REPLACE INTO creature_text VALUES (@Entry,0,1,"You don\'t understand... I CAN\'T be undead! Not me, not now...",12,0,100,0,0,0,NULL);
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@Entry AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@Entry LIMIT 1;
    REPLACE INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@Entry,@SOURCETYPE,0,0,62,0,100,0,17565,0,0,0,22,1,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"shift phase on gossip select"),
    (@Entry,@SOURCETYPE,1,0,1,1,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"close gossip menu"),
    (@Entry,@SOURCETYPE,2,0,1,1,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Talk"),
    (@Entry,@SOURCETYPE,3,0,52,1,100,0,0,@Entry,0,0,22,2,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Set phase 2"),
    (@Entry,@SOURCETYPE,4,0,1,2,100,0,0,0,0,0,33,@Entry,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Kill Monster");
     
    -- Marshal Redpath
    SET @Entry  := 49230;
    SET @SOURCETYPE := 0;
    UPDATE creature_template SET gossip_menu_id=17566 WHERE entry=@Entry;
     
    DELETE FROM gossip_menu WHERE entry IN (17566,17567);
    REPLACE INTO gossip_menu VALUES(17566,17566);
    REPLACE INTO gossip_menu VALUES(17567,17567);
    DELETE FROM gossip_menu_option WHERE menu_id IN (17566,17567);
    REPLACE INTO gossip_menu_option VALUES (17566,0,0,"I\'m not here to fight you. I\'ve only been asked to speak with you.",1,1,17567,0,0,0,NULL);
    REPLACE INTO gossip_menu_option VALUES (17567,0,0,"You are free to do whatever you like.",1,1,0,0,0,0,NULL);
    DELETE FROM npc_text WHERE ID IN (17566,17567);
    REPLACE INTO npc_text SET ID=17566,text0_0="Stand back, monster. You want a fight? Because I\'ll fight you.$B$BI\'ll fight any one of you creatures! Do you hear me?",WDBVerified=1;
    REPLACE INTO npc_text SET ID=17567,text0_0="Oh, really?$B$BFine. I don\'t want to join you and your Forsaken. Maybe I\'ll start my own Forsaken! Maybe I\'ll invent Forsaken with elbows!",WDBVerified=1;
    DELETE FROM creature_text WHERE entry=@Entry;
    REPLACE INTO creature_text VALUES (@Entry,0,0,"BLEEAAAGGHHH! I\'m a monster, don\'t look at me!",14,0,100,0,0,0,NULL);
    REPLACE INTO creature_text VALUES (@Entry,0,1,"Who are you calling a monster? You\'re the monster! I\'m just a man who died.",12,0,100,0,0,0,NULL);
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@Entry AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@Entry LIMIT 1;
    REPLACE INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@Entry,@SOURCETYPE,0,0,62,0,100,0,17567,0,0,0,22,1,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"shift phase on gossip select"),
    (@Entry,@SOURCETYPE,1,0,1,1,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"close gossip menu"),
    (@Entry,@SOURCETYPE,2,0,1,1,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Talk"),
    (@Entry,@SOURCETYPE,3,0,52,1,100,0,0,@Entry,0,0,22,2,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Set phase 2"),
    (@Entry,@SOURCETYPE,4,0,1,2,100,0,0,0,0,0,33,@Entry,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Kill Monster");
     
    SET @Entry  := 49231;
    SET @SOURCETYPE := 0;
    UPDATE creature_template SET gossip_menu_id=12487 WHERE entry=@Entry;
    DELETE FROM gossip_menu WHERE entry IN (12487,12488);
    REPLACE INTO gossip_menu VALUES(12487,17569); -- verweis auf npc text
    REPLACE INTO gossip_menu VALUES(12488,17570);
    DELETE FROM gossip_menu_option WHERE menu_id IN (12487,12488);
    REPLACE INTO gossip_menu_option VALUES (12487,0,0,"Calm down, Valdred.  Undertaker Mordo probably sewed some new ones on for you.",1,1,12488,0,0,0,NULL);
    REPLACE INTO gossip_menu_option VALUES (12488,0,0,"Don\'t you remember?  You died.",1,1,0,0,0,0,NULL);
    DELETE FROM npc_text WHERE ID IN (17569,17570);
    REPLACE INTO npc_text SET ID=17569,text0_0="What... what\'s going on? Who are you? What happened to me?",WDBVerified=1;
    REPLACE INTO npc_text SET ID=17570,text0_0="I... died? Yes, you\'re right. I died. It was an orc... he cut off my hands, and left me to die. <Valdred looks down at his hands.> These aren\'t my hands! THESE AREN\'T MY HANDS!",WDBVerified=1;
    DELETE FROM creature_text WHERE entry=@Entry;
    REPLACE INTO creature_text VALUES (@Entry,0,0,"Valdred Moray, reporting for duty, sir!",14,0,100,0,0,0,NULL);
    REPLACE INTO creature_text VALUES (@Entry,0,1,"I see. Well then, let\'s get to work, $N! The Dark Lady needs us, right?",12,0,100,0,0,0,NULL);
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@Entry AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@Entry LIMIT 1;
    REPLACE INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@Entry,@SOURCETYPE,0,0,62,0,100,0,12488,0,0,0,22,1,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"shift phase on gossip select"),
    (@Entry,@SOURCETYPE,1,0,1,1,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"close gossip menu"),
    (@Entry,@SOURCETYPE,2,0,1,1,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Talk"),
    (@Entry,@SOURCETYPE,3,0,52,1,100,0,0,@Entry,0,0,22,2,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Set phase 2"),
    (@Entry,@SOURCETYPE,4,0,1,2,100,0,0,0,0,0,33,@Entry,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Kill Monster");
     
     -- http://www.wowhead.com/quest=26801  Scourge on our Perimeter
    -- http://www.wowhead.com/npc=1502      Wretched Ghoul
    -- http://www.wowhead.com/npc=1890    Rattlecage Skeleton
     
    -- points only for killed skeleton, but not for kill a ghoul
    UPDATE creature_template SET KillCredit1=1890 WHERE entry=1502;
     
    -- no random move
    UPDATE creature SET spawndist=10,MovementType=1 WHERE id IN (1502,1890);
     
     
    -- the quest is broken with auto-complete flag
    -- now the player walk to the corpse and with open the gossip on the corpse, he finish the quest one by one
     
    -- http://www.wowhead.com/quest=26800 Recruitment
    -- no autocomplete for this quest
    UPDATE quest_template SET Method=2,Flags=0 WHERE id=26800;
     
    -- http://www.wowhead.com/npc=49340  Scarlet Corpse
    -- no questgiver for this npc
    UPDATE creature_template SET npcflag=1 WHERE entry=49340;
    DELETE FROM creature_questrelation WHERE id=49340 and quest=26800;
     
    -- create a gossip menu for the Scarlet Corpse
    DELETE FROM gossip_menu WHERE entry=49340;
    insert into gossip_menu values(49340,49340);
     
    DELETE FROM npc_text WHERE ID=49340;
    insert into npc_text set ID=49340,text0_0="Someone we should bury!";
     
    UPDATE creature_template SET gossip_menu_id=49340 WHERE entry=49340;
     
    -- Scarlet Corpse
    SET @ENTRY := 49340;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    REPLACE INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,64,0,100,0,0,0,0,0,33,49340,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"receive a monster kill"),
    (@ENTRY,@SOURCETYPE,1,0,64,0,100,0,0,0,0,0,41,0,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"delete corps");
     
     -- have wrong flag for gossip and questgiver
    update creature_template set npcflag=0 WHERE entry in (1501,1502,1890);
    DELETE FROM creature_questrelation WHERE id in (1501,1890);
     
    -- http://www.wowhead.com/quest=24969  Charging into Battle
    -- http://www.wowhead.com/npc=44794  Training Dummy
    -- http://www.wowhead.com/spell=100  Charge
    -- script for Training Dummy give no credits..
    update creature_template set KillCredit1=0,KillCredit2=0,ScriptName="",unit_flags=131588 WHERE entry=44794;
    UPDATE quest_template SET Flags=2621440,RequiredNpcOrGo1=44794 WHERE Id=24969;
     
    -- Training Dummy
    SET @ENTRY := 44794;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    REPLACE INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,8,0,100,0,100,0,0,0,33,44794,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Give credit for training dummy");
     
     -- http://www.wowhead.com/npc=49230
    -- wrong position / mising
    DELETE FROM creature WHERE id=49230;
    REPLACE INTO creature(id, map, spawnMask, phaseMask, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, dynamicflags) VALUES
    (49230, 0, 1, 1, 0, 0, 1750.78,1639.73,117.61,2.47749, 500, 0, 0, 5940, 0, 0, 0, 0, 0);
    UPDATE `creature` SET `position_x` = 1754.97, `position_y` = 1666.72, `position_z` = 121.37 WHERE `guid` = 65055;
     
     
    -- http://www.wowhead.com/quest=24961  The Truth of the Grave
    -- quest is autocomplete and not playable
    UPDATE quest_template SET Method=2,Flags=0,SpecialFlags=0 WHERE Id=24961;
     
    -- http://www.wowhead.com/npc=38910    Lilian Voss
    -- has questgiver flag.. this is wrong and wrong gossip menu to..
    UPDATE creature_template set npcflag=1, gossip_menu_id=15486 WHERE entry=38910;
    DELETE FROM creature_questrelation WHERE id=38910 and quest=24961;
     
     
    -- quest http://www.wowhead.com/quest=24964  The Thrill of the Hunt
    -- http://www.wowhead.com/spell=56641        Steady Shot
    -- http://www.wowhead.com/npc=44794            Training Dummy
    -- wrong required npc to kill
    UPDATE quest_template SET RequiredNpcOrGo1=44794 WHERE Id=24964;
     
    -- Training Dummy  update the smartscript for hunter..
    SET @ENTRY := 44794;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    REPLACE INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,8,0,100,0,100,0,0,0,33,44794,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Give credit for training dummy"),
    (@ENTRY,@SOURCETYPE,1,0,8,0,100,0,56641,0,0,0,33,44794,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Give credit for hunter");
     
     
    REPLACE INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,8,0,100,0,100,0,0,0,33,44794,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Give credit for Warrior"),
    (@ENTRY,@SOURCETYPE,1,0,8,0,100,0,56641,0,0,0,33,44794,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Give credit for hunter"),
    (@ENTRY,@SOURCETYPE,2,0,8,0,100,0,2098,0,0,0,33,44794,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Give credit for rogue"),
    (@ENTRY,@SOURCETYPE,3,0,8,0,100,0,115757,0,0,0,33,44794,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Give credit for Mage"),
    (@ENTRY,@SOURCETYPE,4,0,8,0,100,0,589,0,0,0,33,44794,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Give credit for Priest"),
    (@ENTRY,@SOURCETYPE,5,0,8,0,100,0,172,0,0,0,33,44794,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Give credit for Warlock"),
    (@ENTRY,@SOURCETYPE,6,0,8,0,100,0,100787,0,0,0,33,44794,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Give credit for Monk");
     
    -- Wounded Deathguard
    SET @ENTRY := 44795;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    REPLACE INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,8,0,100,0,2061,0,0,0,33,44795,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Get credit for healing");
     
    -- http://www.wowhead.com/quest=3098  Glyphic Scroll
    -- missing endtext
    UPDATE quest_template SET
    EndText="I knew you would come to me, $N. Not because you do not have the will to follow your own path, but because we are kindred spirits. We both have felt pain. We have both suffered. And now we want the power to take back what we know is ours: this land, our lives, our destinies. But there is much for you to learn still. "
    WHERE Id=3098;
     
    -- http://www.wowhead.com/item=9574  Glyphic Scroll
    -- wrong page text
    update item_template set PageText=2470 WHERE entry=9574;
    DELETE FROM page_text WHERE entry=2470;
    REPLACE INTO page_text values (2470,"The corruption and evil that rumor says travels with the arcane is nothing compared to the pain we've already felt. We are no longer victims, <name>. We are the ones who control our fate. Sylvanas has paved the way for us--she has proven that our will is our own; that we are no longer thralls to that bastard Arthas.$B$BSeek me out in the church, I shall instruct you further... if that is your desire.$B$B- Isabella, Mage Trainer",0,1);
     
     
    -- http://www.wowhead.com/npc=1513    Mangy Duskbat and other critters in this area
    -- no random move
    update creature set MovementType=1,spawndist=20 WHERE id in (1508,1509,1512,1513);
    update creature set MovementType=1,spawndist=8,npcflag=0 WHERE id in (1504,1505);
     
    -- wrong npcflag to
    update creature_template set npcflag=0 WHERE entry in (1504,1505);
     
    -- http://www.wowhead.com/npc=49428  Deathguard Protector
    -- wrong faction, no movement and spawndist. show fighting against Rotbrain Berserker
    update creature_template set faction_A=35,faction_H=35 WHERE entry =49428;
    update creature set MovementType=0,spawndist=0 WHERE id =49428;
     
    -- http://www.wowhead.com/npc=49422  Rotbrain Berserker
    -- no movement and spawndist. show fighting against Deathguard Protector
    update creature set MovementType=0,spawndist=0 WHERE id in (49422,49423,49424);
     DELETE FROM `creature` WHERE `id`=49423;
    REPLACE INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
    (44919, 49423, 0, 85, 4915, 1, 1, 36469, 2, 1743.76, 1340.42, 102.79, 5.50777, 500, 10, 0, 98, 115, 1, 0, 0, 0),
    (45023, 49423, 0, 85, 4915, 1, 1, 36473, 2, 1787.26, 1343.15, 89.4765, 5.65487, 500, 10, 0, 98, 115, 1, 0, 0, 0),
    (45283, 49423, 0, 85, 4915, 1, 1, 36470, 2, 1721.67, 1295.59, 125.724, 1.11533, 500, 10, 0, 98, 115, 1, 0, 0, 0),
    (45672, 49423, 0, 85, 4915, 1, 1, 36474, 2, 1776.66, 1380.7, 90.5345, 4.35888, 500, 10, 0, 83, 104, 1, 0, 0, 0),
    (45882, 49423, 0, 85, 4915, 1, 1, 36474, 2, 1695.12, 1344.03, 124.498, 0.325823, 500, 10, 0, 83, 104, 1, 0, 0, 0),
    (45976, 49423, 0, 85, 4915, 1, 1, 36473, 2, 1679.71, 1331.35, 129.635, 5.58266, 500, 10, 0, 83, 104, 1, 0, 0, 0),
    (46072, 49423, 0, 85, 4915, 1, 1, 36473, 2, 1727.64, 1394.07, 106.823, 1.92584, 500, 10, 0, 98, 115, 1, 0, 0, 0),
    (46084, 49423, 0, 85, 4915, 1, 1, 36470, 2, 1730.89, 1368.43, 104.198, 4.25494, 500, 10, 0, 98, 115, 1, 0, 0, 0),
    (46639, 49423, 0, 85, 4915, 1, 1, 36474, 2, 1745.7, 1384.42, 98.9848, 0.244346, 500, 10, 0, 83, 104, 1, 0, 0, 0);
     
    -- Deathguard Protector.. and "friend's" showfight
    SET @ENTRY := 49428;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    REPLACE INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,1,0,100,0,0,0,0,0,5,36,0,0,0,0,0,11,49422,5,0,0.0,0.0,0.0,0.0,"Showfight"),
    (@ENTRY,@SOURCETYPE,1,0,1,0,100,0,0,0,0,0,5,36,0,0,0,0,0,11,49423,5,0,0.0,0.0,0.0,0.0,"Showfight"),
    (@ENTRY,@SOURCETYPE,2,0,1,0,100,0,0,0,0,0,5,36,0,0,0,0,0,11,49424,5,0,0.0,0.0,0.0,0.0,"showfight");
     
    -- Rotbrain Berserker
    SET @ENTRY := 49422;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    REPLACE INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,4,0,1,0,100,0,0,0,0,0,5,36,0,0,0,0,0,11,49428,5,0,0.0,0.0,0.0,0.0,"Schowfight");
     
    -- Rotbrain Magus
    SET @ENTRY := 49423;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    REPLACE INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,11,0,1,0,100,0,0,0,0,0,5,36,0,0,0,0,0,11,49428,5,0,0.0,0.0,0.0,0.0,"Showfight");
     
    -- Marshal Redpath
    SET @ENTRY := 49424;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    REPLACE INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,1,0,100,0,0,0,0,0,5,36,0,0,0,0,0,11,49428,5,0,0.0,0.0,0.0,0.0,"Showfight");
     
     
     DELETE FROM `creature` WHERE `id`=49428;
    REPLACE INTO `creature` (`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
    (49428, 0, 1, 1, 2860, 0, 1809.99, 1320.96, 91.2928, 4.92116, 300, 0, 0, 102, 0, 0, 0, 0, 0),
    (49428, 0, 1, 1, 2860, 0, 1771.7, 1309.79, 100.949, 5.18036, 300, 0, 0, 102, 0, 0, 0, 0, 0),
    (49428, 0, 1, 1, 1588, 0, 1791.52, 1305.32, 102.447, 5.70265, 300, 0, 0, 102, 0, 0, 0, 0, 0),
    (49428, 0, 1, 1, 1587, 0, 1839.88, 1363.31, 73.7095, 5.44345, 300, 0, 0, 102, 0, 0, 0, 0, 0),
    (49428, 0, 1, 1, 1588, 0, 1709.13, 1340.23, 116.986, 3.69478, 300, 0, 0, 102, 0, 0, 0, 0, 0),
    (49428, 0, 1, 1, 1666, 0, 1769.12, 1374.38, 89.3674, 2.58068, 300, 0, 0, 102, 0, 0, 0, 0, 0),
    (49428, 0, 1, 1, 2860, 0, 1789.47, 1376.17, 85.8845, 4.65806, 300, 0, 0, 102, 0, 0, 0, 0, 0),
    (49428, 0, 1, 1, 1587, 0, 1817.7, 1386.79, 76.6104, 2.32151, 300, 0, 0, 102, 0, 0, 0, 0, 0),
    (49428, 0, 1, 1, 1588, 0, 1807.93, 1328.81, 88.7401, 2.29006, 300, 0, 0, 102, 0, 0, 0, 0, 0),
    (49428, 0, 1, 1, 1588, 0, 1824.78, 1310.1, 90.9666, 4.04939, 300, 0, 0, 102, 0, 0, 0, 0, 0),
    (49428, 0, 1, 1, 1587, 0, 1805.31, 1363.17, 84.3222, 5.75038, 300, 0, 0, 102, 0, 0, 0, 0, 0),
    (49428, 0, 1, 1, 1588, 0, 1777.73, 1373.71, 88.0653, 1.84241, 300, 0, 0, 102, 0, 0, 0, 0, 0),
    (49428, 0, 1, 1, 2860, 0, 1726.84, 1326.25, 108.741, 3.16823, 300, 0, 0, 102, 0, 0, 0, 0, 0),
    (49428, 0, 1, 1, 1587, 0, 1748.46, 1313.97, 103.743, 0.00851104, 300, 0, 0, 102, 0, 0, 0, 0, 0),
    (49428, 0, 1, 1, 1588, 0, 1807.03, 1295.23, 99.3504, -0.617658, 300, 0, 0, 102, 0, 0, 0, 0, 0),
    (49428, 0, 1, 1, 2860, 0, 1743.5, 1338.81, 102.904, 1.43401, 300, 0, 0, 102, 0, 0, 0, 0, 0),
    (49428, 0, 1, 1, 1666, 0, 1772.3, 1370.58, 88.1044, 5.78904, 300, 0, 0, 102, 0, 0, 0, 0, 0);
     
     
    DELETE FROM `creature` WHERE `id`=49422;
    REPLACE INTO `creature` (`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
    (49422, 0, 1, 1, 36472, 2, 1758.23, 1339.39, 95.1645, 0.81983, 300, 0, 0, 86, 0, 0, 0, 0, 0),
    (49422, 0, 1, 1, 36467, 2, 1823.64, 1308.75, 91.5621, 0.782129, 300, 0, 0, 102, 0, 0, 0, 0, 0),
    (49422, 0, 1, 1, 36471, 2, 1712.05, 1335.68, 114.861, 2.39004, 300, 0, 0, 86, 0, 0, 0, 0, 0),
    (49422, 0, 1, 1, 36471, 2, 1751.9, 1313.12, 102.94, 2.97339, 300, 0, 0, 86, 0, 0, 0, 0, 0),
    (49422, 0, 1, 1, 36472, 2, 1750.97, 1280.27, 111.969, 5.61056, 300, 0, 0, 102, 0, 0, 0, 0, 0),
    (49422, 0, 1, 1, 36472, 2, 1781.77, 1291.13, 111.625, 5.11186, 300, 0, 0, 86, 0, 0, 0, 0, 0),
    (49422, 0, 1, 1, 36468, 2, 1770.82, 1337.55, 89.9835, 0.672343, 300, 0, 0, 86, 0, 0, 0, 0, 0),
    (49422, 0, 1, 1, 36468, 2, 1806.26, 1331.6, 88.2395, 5.21568, 300, 0, 0, 86, 0, 0, 0, 0, 0),
    (49422, 0, 1, 1, 36472, 2, 1766.18, 1373.85, 89.7562, 0.197003, 300, 0, 0, 86, 0, 0, 0, 0, 0),
    (49422, 0, 1, 1, 36467, 2, 1840.57, 1360.39, 74.0216, 2.26261, 300, 0, 0, 102, 0, 0, 0, 0, 0),
    (49422, 0, 1, 1, 36467, 2, 1808.47, 1362.13, 83.8458, 3.06372, 300, 0, 0, 86, 0, 0, 0, 0, 0),
    (49422, 0, 1, 1, 36468, 2, 1837.68, 1342.01, 79.9634, 4.49459, 300, 0, 0, 86, 0, 0, 0, 0, 0),
    (49422, 0, 1, 1, 36468, 2, 1773.54, 1368.07, 87.8782, 2.03876, 300, 0, 0, 86, 0, 0, 0, 0, 0),
    (49422, 0, 1, 1, 36472, 2, 1728.19, 1349.22, 106.861, 4.07126, 300, 0, 0, 102, 0, 0, 0, 0, 0),
    (49422, 0, 1, 1, 36472, 2, 1810.3, 1318.41, 92.3959, 1.54395, 300, 0, 0, 86, 0, 0, 0, 0, 0),
    (49422, 0, 1, 1, 36468, 2, 1794.29, 1303.75, 102.826, 2.58384, 300, 0, 0, 86, 0, 0, 0, 0, 0),
    (49422, 0, 1, 1, 36471, 2, 1779.68, 1411.86, 92.3306, 2.74579, 300, 0, 0, 86, 0, 0, 0, 0, 0),
    (49422, 0, 1, 1, 36471, 2, 1788.98, 1373.07, 85.9256, 1.53956, 300, 0, 0, 102, 0, 0, 0, 0, 0),
    (49422, 0, 1, 1, 36471, 2, 1769.22, 1402.78, 95.0807, 0.687516, 300, 0, 0, 86, 0, 0, 0, 0, 0),
    (49422, 0, 1, 1, 36467, 2, 1795.91, 1342.81, 89.0869, 3.64774, 300, 0, 0, 102, 0, 0, 0, 0, 0),
    (49422, 0, 1, 1, 36471, 2, 1816.09, 1389.6, 77.2142, 5.25497, 300, 0, 0, 102, 0, 0, 0, 0, 0),
    (49422, 0, 1, 1, 36472, 2, 1724.27, 1323.69, 110.366, 2.66438, 300, 0, 0, 102, 0, 0, 0, 0, 0),
    (49422, 0, 1, 1, 36472, 2, 1701.66, 1360.84, 118.611, 0.395153, 300, 0, 0, 102, 0, 0, 0, 0, 0),
    (49422, 0, 1, 1, 36471, 2, 1772.6, 1308.01, 102.032, 2.07411, 300, 0, 0, 86, 0, 0, 0, 0, 0),
    (49422, 0, 1, 1, 36467, 2, 1808.46, 1291.55, 98.8042, 1.85027, 300, 0, 0, 86, 0, 0, 0, 0, 0);
     
     
    DELETE FROM `creature` WHERE `id`=49423;
    REPLACE INTO `creature` (`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
    (49423, 0, 1, 1, 36469, 2, 1743.76, 1340.42, 102.79, 5.50777, 300, 0, 0, 98, 115, 0, 0, 0, 0),
    (49423, 0, 1, 1, 36473, 2, 1787.26, 1343.15, 89.4765, 5.65487, 300, 0, 0, 98, 115, 0, 0, 0, 0),
    (49423, 0, 1, 1, 36470, 2, 1721.67, 1295.59, 125.724, 1.11533, 300, 0, 0, 98, 115, 0, 0, 0, 0),
    (49423, 0, 1, 1, 36474, 2, 1777.25, 1376.48, 88.9303, 5.06646, 300, 0, 0, 83, 104, 0, 0, 0, 0),
    (49423, 0, 1, 1, 36474, 2, 1695.12, 1344.03, 124.498, 0.325823, 300, 0, 0, 83, 104, 0, 0, 0, 0),
    (49423, 0, 1, 1, 36473, 2, 1679.71, 1331.35, 129.635, 5.58266, 300, 0, 0, 83, 104, 0, 0, 0, 0),
    (49423, 0, 1, 1, 36473, 2, 1727.64, 1394.07, 106.823, 1.92584, 300, 0, 0, 98, 115, 0, 0, 0, 0),
    (49423, 0, 1, 1, 36470, 2, 1730.89, 1368.43, 104.198, 4.25494, 300, 0, 0, 98, 115, 0, 0, 0, 0),
    (49423, 0, 1, 1, 36474, 2, 1745.7, 1384.42, 98.9848, 0.244346, 300, 0, 0, 83, 104, 0, 0, 0, 0);
     
    DELETE FROM `creature` WHERE `id`=49424;
    REPLACE INTO `creature` (`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
    (49424, 0, 1, 1, 36417, 2, 1768.41, 1378.34, 90.4255, 5.01542, 500, 0, 0, 147, 115, 0, 0, 0, 0);
     
     
    -- http://www.wowhead.com/quest=24972  Vital Intelligence
    -- wrong questgiver
    DELETE FROM creature_questrelation WHERE id=1519 and quest=24972;
     
    -- old quest 383 not avaible
    DELETE FROM creature_questrelation WHERE id=1570 and quest=383;
     
    -- http://www.wowhead.com/quest=31146  Scribbled Scroll
    -- missing quest
    insert ignore into creature_questrelation values(1569,31146);
     
    -- quest is not shown by questgiver
    UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 24972;
     
     
     
     
    -- By b4dm00n
     
     
     
    /*
     Quest progression
     
         [1] Fresh out of the Grave
         [1] The Shadow Grave
         [1] Those That Couldn't Be Saved
         [1] Caretaker Caice
         [1] The Wakening
         [1] Beyond the Graves
         [2] Recruitment
         [2] Shadow Priest Sarvis
         [3] Scourge on our Perimeter
         [3] The Truth of the Grave
           
           
            Class quests
     
        [3] Trail-Worn Scroll &  [3] The Thrill of the Hunt
        [3] Glyphic Scroll &  [3] ...? ? ?
        [3] Hallowed Scroll &  [3] ...? ? ?
        [3] Encrypted Scroll &  [3] Stab!
        [3] Tainted Scroll &  [3] ...? ? ?
        [3] Simple Scroll & [3] Charging into Battle? ? ?
     
     [3] The Executor In the Field
     [2] The Damned
     [4] Night Web's Hollow
     [4] No Better Than the Zombies
     [5] Assault on the Rotbrain Encampment
     [5] Vital Intelligence
    */
    -- Quest chain for starting quest #24959: Fresh out of the Grave
    UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 24959;
    UPDATE `quest_template` SET `PrevQuestId` = 24959, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 28608;
    UPDATE `quest_template` SET `PrevQuestId` = 28608, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 26799;
    UPDATE `quest_template` SET `PrevQuestId` = 26799, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 28652;
    UPDATE `quest_template` SET `PrevQuestId` = 28652, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 24960;
    UPDATE `quest_template` SET `PrevQuestId` = 24960, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 25089;
    UPDATE `quest_template` SET `PrevQuestId` = 25089, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 26800;
    UPDATE `quest_template` SET `PrevQuestId` = 26800, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 28653;
    UPDATE `quest_template` SET `PrevQuestId` = 28653, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 26801;
    UPDATE `quest_template` SET `PrevQuestId` = 26801 WHERE `Id` = 24961;
     
     
    -- class
    -- Quest chain for starting quest #3095: Simple Scroll
    UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 24964, `ExclusiveGroup` = 0 WHERE `Id` = 3095;
    UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 24965, `ExclusiveGroup` = 0 WHERE `Id` = 3096;
    UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 24966, `ExclusiveGroup` = 0 WHERE `Id` = 3097;
    UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 24967, `ExclusiveGroup` = 0 WHERE `Id` = 3098;
    UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 24968, `ExclusiveGroup` = 0 WHERE `Id` = 3099;
    UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 24969, `ExclusiveGroup` = 0 WHERE `Id` = 24962;
    UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 31147, `ExclusiveGroup` = 0 WHERE `Id` = 31146;
    UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 28651, `ExclusiveGroup` = 0 WHERE `Id` = 24964;
    UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 28651, `ExclusiveGroup` = 0 WHERE `Id` = 24965;
    UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 28651, `ExclusiveGroup` = 0 WHERE `Id` = 24966;
    UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 28651, `ExclusiveGroup` = 0 WHERE `Id` = 24967;
    UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 28651, `ExclusiveGroup` = 0 WHERE `Id` = 24968;
    UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 28651, `ExclusiveGroup` = 0 WHERE `Id` = 24969;
    UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 28651, `ExclusiveGroup` = 0 WHERE `Id` = 31147;
    UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 24961, `ExclusiveGroup` = 0 WHERE `Id` = 28651;
    UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 24961, `ExclusiveGroup` = 0 WHERE `Id` = 31148;
    UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 24961;
    UPDATE `quest_template` SET `PrevQuestId` = 24961, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 28672;
    UPDATE `quest_template` SET `PrevQuestId` = 28672, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 26802;
    UPDATE `quest_template` SET `PrevQuestId` = 26802, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 24973;
    UPDATE `quest_template` SET `PrevQuestId` = 24973, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 24970;
    UPDATE `quest_template` SET `PrevQuestId` = 24970, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 24971;
     
     
    UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 24978;
    UPDATE `quest_template` SET `PrevQuestId` = 24978, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 24980;

    DELETE FROM `spell_area` WHERE `spell`=73523 AND `area`=5692;
    -- REPLACE INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `racemask`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES ('73523', '5692', '0', '24959', '16', '1', '16', '9');
     
    UPDATE `quest_template` SET `Flags` = 0 WHERE `Id` = 24959;
    -- Agatha
    SET @ENTRY := 49044;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,1,19,0,100,0,24959,0,0,0,86,73524,0,7,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"On quest 24959 accept revive player"),
    (@ENTRY,@SOURCETYPE,1,2,61,0,100,0,0,0,0,0,28,73523,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Remove aura to player"),
    (@ENTRY,@SOURCETYPE,2,0,61,0,100,0,0,0,0,0,1,0,1000,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Talk to action invoker"),
    (@ENTRY,@SOURCETYPE,3,0,52,0,100,0,0,49044,0,0,1,1,3000,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"On text over say text 1");
     
    DELETE FROM creature_text WHERE entry=49044;
    INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `probability`) VALUES
    ('49044', '0', '0', 'Bow before your new master!', '14', '100'),
    ('49044', '0', '1', 'Rise and destroy our enemies!', '14', '100'),
    ('49044', '0', '2', 'Rise, Hillsbrad Refugee! Become Forsaken!', '14', '100'),
    ('49044', '1', '0', 'RUN!', '12', '100'),
    ('49044', '1', '1', 'This way, $n. We will take them by surprise.', '12', '100'),
    ('49044', '1', '2', 'Through me the Banshee Queen sees all...', '12', '100');
     
    UPDATE `playercreateinfo` SET `position_x`='1704.23', `position_y`='1701.18', `position_z`='134.87', `orientation`='6.24' WHERE (`race`='5') AND (`map`='0');
     
     
    UPDATE `quest_template` SET `Flags` = 0 WHERE `Id` = 28608;
     
     
    DELETE FROM `creature_template_addon` WHERE (`entry`=49213);
    INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (49213, 0, 0,  33554432 , 1, 0, '');
     
    DELETE FROM `creature` WHERE `id`=51107;
    UPDATE `quest_template` SET `RewardSpellCast` = 0 WHERE `Id` = 24959;
    DELETE FROM `creature` WHERE `id`=50374;
    DELETE FROM `creature` WHERE `id`=50414;
     
    DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13  AND SourceEntry=93446;
    INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`) VALUES ('13', '1', '93446', '31', '3', '50373');
     
    DELETE FROM waypoints WHERE entry =5037200;
    INSERT INTO waypoints(entry, pointid, position_x, position_y, position_z) VALUES
    (5037200, 1, 1684.38, 1685.77, 141.523),
    (5037200, 5, 1697.59, 1680.47, 138.574),
    (5037200, 4, 1698.4, 1688.53, 138.87),
    (5037200, 3, 1707.34, 1701.02, 138.108),
    (5037200, 2, 1733.52, 1701.92, 131.838);
    UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` = 50372;
     
    -- Aradne
    SET @ENTRY := 50372;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,60,0,100,1,1000,1000,1000,1000,53,0,5037200,1,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"On update 1 sec do WP and repeat"),
    (@ENTRY,@SOURCETYPE,1,2,40,0,100,0,1,5037200,0,0,54,10000,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"on WP reach 1 pause and cast spell"),
    (@ENTRY,@SOURCETYPE,2,0,61,0,100,0,0,0,0,0,80,5037200,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Link Call time action"),
    (@ENTRY,@SOURCETYPE,3,4,40,0,100,0,2,5037200,0,0,54,10000,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"On wp Reach 2 do pause and cast spell"),
    (@ENTRY,@SOURCETYPE,4,0,61,0,100,0,0,0,0,0,80,5037200,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Time actionList"),
    (@ENTRY,@SOURCETYPE,5,6,40,0,100,0,3,5037200,0,0,54,10000,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"On wp 3 pause and cast"),
    (@ENTRY,@SOURCETYPE,6,0,61,0,100,0,0,0,0,0,80,5037200,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Time actionList"),
    (@ENTRY,@SOURCETYPE,7,8,40,0,100,0,4,5037200,0,0,54,10000,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"on wp 4 pause and cast"),
    (@ENTRY,@SOURCETYPE,8,0,61,0,100,0,0,0,0,0,80,5037200,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Time actionList"),
    (@ENTRY,@SOURCETYPE,9,10,40,0,100,0,5,5037200,0,0,54,10000,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"On wp 5 pause and cast"),
    (@ENTRY,@SOURCETYPE,10,0,61,0,100,0,0,0,0,0,80,5037200,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Time actionList");
     
     
    -- Aradne
    SET @ENTRY := 5037200;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,500,500,500,500,66,0,0,0,0,0,0,19,50373,10,0,0.0,0.0,0.0,0.0,"Set orientation to near 50373"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,1000,1000,1000,1000,11,93446,0,0,0,0,0,19,50373,10,0,0.0,0.0,0.0,0.0,"Cast 50372"),
    (@ENTRY,@SOURCETYPE,2,0,0,0,100,0,2000,2000,2000,2000,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Talk text 0");
     
    DELETE FROM creature_text WHERE entry=50372;
    INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
    (50372, 0, 0, 'In the name of Sylvanas, the Banshee Queen, I bestow this gift upon you!', 12, 0, 100, 0, 0, 0, 'Aradne'),
    (50372, 0, 1, 'Rise from death''s slumber and join your brothers!', 12, 0, 100, 0, 0, 0, 'Aradne'),
    (50372, 0, 2, 'Rise from the grave and serve the Dark Lady!', 12, 0, 100, 0, 0, 0, 'Aradne'),
    (50372, 0, 3, 'Waken, sleeper. Your new life awaits.', 12, 0, 100, 0, 0, 0, 'Aradne'),
    (50372, 0, 4, 'You are returned to life. The Banshee Queen asks for your service.', 12, 0, 100, 0, 0, 0, 'Aradne');
     
    UPDATE `creature_template` SET `InhabitType` = 3, `HoverHeight` = 2.4 WHERE `entry` = 50372;
     
     
    -- Deathknell Grave Target
    SET @ENTRY := 50373;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,1,8,0,100,0,93446,0,0,0,11,89199,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"On spellhit do visual 89199"),
    (@ENTRY,@SOURCETYPE,1,0,61,0,100,0,0,0,0,0,12,50374,3,30000,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Summon creature");
     
     
    -- Risen Dead
    SET @ENTRY := 50374;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,60,0,100,1,1000,1000,1000,1000,87,5037400,5037401,5037402,5037403,5037404,5037405,1,0,0,0,0.0,0.0,0.0,0.0,"On summoned do random action");
     
    -- Risen Dead
    SET @ENTRY := 5037400;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,500,500,500,500,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Text 1"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,3000,3000,3000,3000,1,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Text 2 and kill himself"),
    (@ENTRY,@SOURCETYPE,2,0,0,0,100,0,5000,5000,5000,5000,37,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Die self");
     
    DELETE FROM waypoints WHERE entry =5037401;
    INSERT INTO waypoints(entry, pointid, position_x, position_y, position_z) VALUES
    (5037401, 1, 1702, 1677.55, 134.298),
    (5037401, 2, 1676.66, 1652.85, 138.6);
     
     
    DELETE FROM creature_text WHERE entry=50374;
    INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
    (50374, 0, 0, 'What... what''s happening to me? Why have you done this to me?', 12, 0, 100, 6, 0, 0, 'Auferstandener Toter to Aradne'),
    (50374, 1, 0, 'I should be dead and to death I will return!', 12, 0, 100, 5, 0, 0, 'Auferstandener Toter to Aradne'),
    (50374, 2, 0, 'I never asked for this! Leave me alone!', 12, 0, 100, 6, 0, 0, 'Auferstandener Toter to Aradne'),
    (50374, 3, 0, 'What magic is this that turns back the hand of death?', 12, 0, 100, 1, 0, 0, 'Auferstandener Toter to Aradne'),
    (50374, 4, 0, 'If the Banshee Queen has offered me this chance, I will gladly serve.', 12, 0, 100, 5, 0, 0, 'Auferstandener Toter to Aradne'),
    (50374, 5, 0, 'This is Lady Sylvanas''s doing?', 12, 0, 100, 6, 0, 0, 'Auferstandener Toter to Aradne'),
    (50374, 6, 0, 'What use has the Dark Lady for me?', 12, 0, 100, 6, 0, 0, 'Auferstandener Toter to Aradne'),
    (50374, 7, 0, 'I... I don''t remember... Why have you done this?', 12, 0, 100, 6, 0, 0, 'Auferstandener Toter to Aradne');
     
     
     
    -- Risen Dead
    SET @ENTRY := 5037401;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,2000,2000,2000,2000,1,2,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Say text 1"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,3000,3000,3000,3000,53,1,5037401,0,0,5000,0,1,0,0,0,0.0,0.0,0.0,0.0,"do WP 5037401"),
    (@ENTRY,@SOURCETYPE,2,0,0,0,100,0,100,100,100,100,36,1501,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Update template"),
    (@ENTRY,@SOURCETYPE,3,0,0,0,100,0,0,0,0,0,11,44427,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"add aura 44427 on self ");
     
     
     
    DELETE FROM waypoints WHERE entry =5037402;
    INSERT INTO waypoints(entry, pointid, position_x, position_y, position_z) VALUES
    (5037402, 1, 1695.44, 1672.29, 133.945),
    (5037402, 2, 1691.08, 1660.22, 131.406),
    (5037402, 3, 1709.56, 1643.45, 124.713);
     
     
    -- Risen Dead
    SET @ENTRY := 5037402;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,500,500,500,500,1,3,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"say text 3"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,2500,2500,2500,2500,1,4,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"say text 4"),
    (@ENTRY,@SOURCETYPE,2,0,0,0,100,0,2000,2000,2000,2000,53,0,5037402,0,0,12000,0,1,0,0,0,0.0,0.0,0.0,0.0,"Do wp");
     
     
    -- Risen Dead
    SET @ENTRY := 5037403;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,500,500,500,500,1,5,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"say text 5"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,2500,2500,2500,2500,1,4,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"say text 4"),
    (@ENTRY,@SOURCETYPE,2,0,0,0,100,0,2000,2000,2000,2000,53,0,5037402,0,0,12000,0,1,0,0,0,0.0,0.0,0.0,0.0,"Do wp");
     
    -- Risen Dead
    SET @ENTRY := 5037404;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,500,500,500,500,1,6,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"say text 6"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,2500,2500,2500,2500,1,4,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"say text 4"),
    (@ENTRY,@SOURCETYPE,2,0,0,0,100,0,2000,2000,2000,2000,53,0,5037402,0,0,12000,0,1,0,0,0,0.0,0.0,0.0,0.0,"Do wp");
     
     
    -- Risen Dead
    SET @ENTRY := 5037405;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,500,500,500,500,1,7,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Text 7"),
    (@ENTRY,@SOURCETYPE,2,0,0,0,100,0,2000,2000,2000,2000,37,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Die self");
     
     
    UPDATE `creature` SET `position_x` = '1689.712', `position_y` = '1674.793', `position_z` = '135.6747', `orientation` = '0.3490658' WHERE `guid` = 45083;
    DELETE FROM `creature_addon` WHERE (`guid`=45083);
     
    DELETE FROM creature_text WHERE entry=1568;
    INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
    (1568, 0, 0, 'Let''s see, I just saw a corpse with a jaw that would fit you...', 12, 0, 100, 0, 0, 0, 'Totengraber Mordo'),
    (1568, 1, 0, 'That should do the job. Come back right away if it falls off again.', 12, 0, 100, 0, 0, 0, 'Totengraber Mordo');
     
     
    -- Undertaker Mordo
    SET @ENTRY := 1568;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,60,0,100,0,60000,60000,60000,60000,80,156800,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Summon Risen Recruit");
     
     
    -- Undertaker Mordo
    SET @ENTRY := 156800;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,0,0,0,0,12,50414,7,0,0,0,0,8,0,0,0,1696.52,1681.96,134.8,4.15,"Summon Risen Recruit"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,3000,3000,3000,3000,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Talk 1"),
    (@ENTRY,@SOURCETYPE,2,0,0,0,100,0,10000,10000,10000,10000,1,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 2");
     
    DELETE FROM waypoints WHERE entry =5041400;
    INSERT INTO waypoints(entry, pointid, position_x, position_y, position_z) VALUES
    (5041400, 1, 1691.29, 1675.85, 135.295),
    (5041400, 2, 1690.59, 1661.87, 131.92),
    (5041400, 3, 1719.38, 1633.98, 121.065);
     
    DELETE FROM creature_text WHERE entry=50414;
    INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
    (50414, 0, 0, 'T-thank you, Undert-t-taker.', 12, 0, 100, 0, 0, 0, 'Totengraber Mordo');
     
    -- Risen Recruit
    SET @ENTRY := 50414;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,54,0,100,0,0,0,0,0,80,5041400,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"On sumoned calltimeaction"),
    (@ENTRY,@SOURCETYPE,1,0,40,0,100,0,1,5041400,0,0,54,11000,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"wp pause at wp1"),
    (@ENTRY,@SOURCETYPE,2,0,40,0,100,0,3,5041400,0,0,41,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"on wp 3 despawn");
     
     
     
    -- Risen Recruit
    SET @ENTRY := 5041400;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,0,0,0,0,53,0,5041400,0,0,20000,0,1,0,0,0,0.0,0.0,0.0,0.0,"waypoint"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,3000,3000,3000,3000,5,16,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Kneel after 3 sec"),
    (@ENTRY,@SOURCETYPE,2,0,0,0,100,0,11000,11000,11000,11000,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Type a script description here."),
    (@ENTRY,@SOURCETYPE,3,0,0,0,100,0,2000,2000,2000,2000,65,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"resume wp");
     
     
     
    DELETE FROM `creature` WHERE `id`=49129;
    DELETE FROM `creature` WHERE `guid`=45928;
    INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
    (45928, 49129, 0, 85, 5692, 1, 1, 33997, 2, 1725.54, 1681.13, 139.093, 4.90376, 7200, 0, 0, 5580, 3820, 2, 0, 0, 0);
    DELETE FROM `creature_addon` WHERE (`guid`=45928);
    INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (45928, 4912900, 0, 50331648, 1, 0, '');
    UPDATE `creature_template` SET `InhabitType` = 3, `HoverHeight` = '2.4' WHERE `entry` = 49129;
     
    UPDATE `creature_template` SET `AIName` = 'SmartAI', `equipment_id` = 49141, `ScriptName` = '' WHERE `entry` = 49141;
    DELETE FROM `creature_equip_template` WHERE (`entry`=49141);
    INSERT INTO `creature_equip_template` (`entry`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES (49141, 1895, 1957, 0);
    UPDATE `creature_template` SET `unit_flags` = 32776 WHERE `entry` = 49141;
    UPDATE `quest_template` SET `SourceSpellId` = 91576 WHERE `Id` = 28608;
     
    DELETE FROM `creature_text` WHERE (`entry`=49141);
    INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
    (49141, 0, 0, 'Greetings, $N.', 12, 0, 100, 1, 0, 0, 'Darnell'),
    (49141, 1, 0, 'The shadow grave is in this direction. Follow me, $N.', 12, 0, 100, 1, 0, 0, 'Darnell'),
    (49141, 2, 0, 'This way!', 12, 0, 100, 1, 0, 0, 'Darnell'),
    (49141, 3, 0, 'Let''s see now... WHERE could they be...', 12, 0, 100, 1, 0, 0, 'Darnell'),
    (49141, 4, 0, 'Maybe they''re over here?', 12, 0, 100, 1, 0, 0, 'Darnell'),
    (49141, 5, 0, 'Nice work! You''ve found them. Let''s bring these back to Mordo.', 12, 0, 100, 1, 0, 0, 'Darnell'),
    (49141, 6, 0, 'I saw someone up there whose jaw fell off. I wonder if Mordo can fix him up?', 12, 0, 100, 1, 0, 0, 'Darnell');
     
    UPDATE `creature_template` SET `faction_A` = 5, `faction_H` = 5 WHERE `entry` = 49141;
     
    update creature set equipment_id=0 WHERE equipment_id=2;
    update creature set equipment_id=0 WHERE equipment_id=1;
     
     
     
    -- Darnell
    SET @ENTRY := 49141;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,54,0,100,0,0,0,0,0,80,4914100,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"On summoned call time action 4914100"),
    (@ENTRY,@SOURCETYPE,1,0,38,0,100,1,0,1,0,0,80,4914101,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"On data set do event 4914101"),
    (@ENTRY,@SOURCETYPE,2,0,49,0,100,0,0,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"On qc DO action"),
    (@ENTRY,@SOURCETYPE,3,0,38,0,100,0,0,2,0,0,41,1000,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"On data set 2 despawn self");
     
     
    -- Darnell
    SET @ENTRY := 4914100;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,1500,1500,1500,1500,1,0,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Talk to owner"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,2000,2000,2000,2000,1,1,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Talk to player");
     
     
     
     
    -- Darnell
    SET @ENTRY := 4914101;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,23,0,0,0,0.0,0.0,0.0,0.0,"Talk to owner"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,0,0,0,0,53,1,4914100,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"do WP 4914100"),
    (@ENTRY,@SOURCETYPE,2,0,0,0,100,0,8000,8000,8000,8000,1,3,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk text 3"),
    (@ENTRY,@SOURCETYPE,3,0,0,0,100,0,3000,3000,3000,3000,1,4,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Say text 4"),
    (@ENTRY,@SOURCETYPE,4,0,0,0,100,0,4000,4000,4000,4000,29,0,0,0,0,0,0,23,0,0,0,0.0,0.0,0.0,0.0,"And follow Player");
    DELETE FROM waypoints WHERE entry=4914100;
    INSERT INTO waypoints(entry, pointid, position_x, position_y, position_z) VALUES
    (4914100, 1, 1659.16, 1662.94, 141.817),
    (4914100, 2, 1643.49, 1663.24, 132.478),
    (4914100, 3, 1642.96, 1677.41, 126.932),
    (4914100, 4, 1658.07, 1677.88, 120.719),
    (4914100, 5, 1664.8, 1661.36, 120.939);
     
     
     
     
    UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 41200;
     
    SET @ENTRY := -44900;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,60,0,100,0,700,700,700,700,45,0,1,0,0,0,0,19,49141,5,0,0.0,0.0,0.0,0.0,"Set data 1 to 49141");
     
    -- Undertaker Mordo
    SET @ENTRY := 1568;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,60,0,100,0,60000,60000,60000,60000,80,156800,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Summon Risen Recruit"),
    (@ENTRY,@SOURCETYPE,1,0,20,0,100,0,28608,0,0,0,45,0,2,0,0,0,0,19,49141,10,0,0.0,0.0,0.0,0.0,"On reward quest set data 2 to Darnell");
     
    DELETE FROM creature_text WHERE entry=49337;
    INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
    (49337, 0, 0, 'Hello again..', 12, 0, 100, 3, 0, 0, 'Darnell'),
    (49337, 1, 0, 'I know the way to Deathknell. Come with me!', 12, 0, 100, 273, 0, 0, 'Darnell'),
    (49337, 2, 0, 'Good, you''re still here. Now, WHERE''s Deathguard Saltain?', 12, 0, 100, 1, 0, 0, 'Darnell'),
    (49337, 3, 0, 'Ah, here he is.', 12, 0, 100, 1, 0, 0, 'Darnell'),
    (49337, 4, 0, 'We make our way, $N. Saltain said that we can find a few dead bodies up here.', 12, 0, 100, 1, 0, 0, 'Darnell');
    UPDATE `quest_template` SET `SourceSpellId` = 91938 WHERE `Id` = 25089;
     
    UPDATE `creature_template` SET `AIName` = 'SmartAI', `equipment_id` = 49337, `ScriptName` = '' WHERE `entry` = 49337;
    DELETE FROM `creature_equip_template` WHERE (`entry`=49337);
    INSERT INTO `creature_equip_template` (`entry`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES (49337, 1895, 1957, 0);
    UPDATE `creature_template` SET `unit_flags` = 32776 WHERE `entry` = 49337;
    UPDATE `creature_template` SET `minlevel` = 2, `maxlevel` = 2, `faction_A` = 5, `faction_H` = 5, `VehicleId` = 1392, `HoverHeight` = 1, `equipment_id` = 0 WHERE `entry` = 49337;
    UPDATE `quest_template` SET `Flags` = 0 WHERE `Id` = 25089;
    UPDATE `creature_template` SET `equipment_id` = 49337 WHERE `entry` = 49337;
     
     
    -- Darnell
    SET @ENTRY := 49337;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,54,0,100,0,0,0,0,0,80,4933700,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"On summoned talk text 0"),
    (@ENTRY,@SOURCETYPE,1,0,38,0,100,1,0,1,0,0,80,4933701,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"on data set 1 do actionlist 2"),
    (@ENTRY,@SOURCETYPE,2,0,38,0,100,0,0,2,0,0,1,4,0,0,0,0,0,23,0,0,0,0.0,0.0,0.0,0.0,"on data set 2 talk to player");
     
     
    -- Darnell
    SET @ENTRY := 4933700;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,2000,2000,2000,2000,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 0"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,3000,3000,3000,3000,1,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 1");
     
     
    -- Generic Bunny - PRK
    SET @ENTRY := -45287;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,60,0,100,0,1000,1000,1000,1000,45,0,1,0,0,0,0,19,49337,5,0,0.0,0.0,0.0,0.0,"set data 1 to darnell");
     
     
    -- Darnell
    SET @ENTRY := 4933701;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 2"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,500,500,500,500,69,0,0,0,0,0,0,8,0,0,0,1861.56,1603.44,98.11,0.0,"Move to Pos"),
    (@ENTRY,@SOURCETYPE,2,0,0,0,100,0,2500,2500,2500,2500,1,3,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 3"),
    (@ENTRY,@SOURCETYPE,3,0,0,0,100,0,4000,4000,4000,4000,29,0,0,0,0,0,0,23,0,0,0,0.0,0.0,0.0,0.0,"follow owner");
     
    -- Deathguard Saltain
    SET @ENTRY := 1740;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,20,0,100,0,25089,0,0,0,45,0,2,0,0,0,0,19,49337,10,0,0.0,0.0,0.0,0.0,"set data 2 after 25089 "),
    (@ENTRY,@SOURCETYPE,1,0,20,0,100,0,26800,0,0,0,45,0,4,0,0,0,0,19,49337,10,0,0.0,0.0,0.0,0.0,"set data 4 on reward 26800");
     
    UPDATE `creature_template` SET `npcflag` = 16777216 WHERE `entry` = 49340;
     
    DELETE FROM `npc_spellclick_spells` WHERE npc_entry=49340;
    INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`) VALUES ('49340', '91942', '0');
    UPDATE `npc_spellclick_spells` SET `cast_flags`='1' WHERE (`npc_entry`='49340') AND (`spell_id`='91942');
     
    -- Scarlet Corpse
    SET @ENTRY := 49340;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,1,8,0,100,0,91942,0,0,0,45,0,3,0,0,0,0,19,49337,10,0,0.0,0.0,0.0,0.0,"on spellhit 91942 set data 3 to darnell"),
    (@ENTRY,@SOURCETYPE,1,2,61,0,100,0,0,0,0,0,33,49340,0,0,0,0,0,21,10,0,0,0.0,0.0,0.0,0.0,"Give credit to player"),
    (@ENTRY,@SOURCETYPE,2,0,61,0,100,0,0,0,0,0,11,46598,0,0,0,0,0,19,49337,0,0,0.0,0.0,0.0,0.0,"Jump on darnell"),
    (@ENTRY,@SOURCETYPE,3,0,38,0,100,0,0,1,0,0,37,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"die self");
     
    -- Darnell
    SET @ENTRY := 49337;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,54,0,100,0,0,0,0,0,80,4933700,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"On summoned talk text 0"),
    (@ENTRY,@SOURCETYPE,1,0,38,0,100,1,0,1,0,0,80,4933701,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"on data set 1 do actionlist 2"),
    (@ENTRY,@SOURCETYPE,2,0,38,0,100,0,0,2,0,0,1,4,0,0,0,0,0,23,0,0,0,0.0,0.0,0.0,0.0,"on data set 2 talk to player"),
    (@ENTRY,@SOURCETYPE,3,0,38,0,100,0,0,3,0,0,11,91945,0,0,0,0,0,19,49340,10,0,0.0,0.0,0.0,0.0,"on data set 3 cast 91945"),
    (@ENTRY,@SOURCETYPE,4,5,38,0,100,0,0,4,0,0,37,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"on data set 4 die self"),
    (@ENTRY,@SOURCETYPE,5,0,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,9,49340,0,10,0.0,0.0,0.0,0.0,"set data 1 to scarlet");
    DELETE FROM `creature_template_addon` WHERE (`entry`=49340);
     
     
     
     
     
    DELETE FROM `npc_text` WHERE `ID` = 15486;
    INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `lang0`, `prob0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`, `text1_0`, `text1_1`, `lang1`, `prob1`, `em1_0`, `em1_1`, `em1_2`, `em1_3`, `em1_4`, `em1_5`, `text2_0`, `text2_1`, `lang2`, `prob2`, `em2_0`, `em2_1`, `em2_2`, `em2_3`, `em2_4`, `em2_5`, `text3_0`, `text3_1`, `lang3`, `prob3`, `em3_0`, `em3_1`, `em3_2`, `em3_3`, `em3_4`, `em3_5`, `text4_0`, `text4_1`, `lang4`, `prob4`, `em4_0`, `em4_1`, `em4_2`, `em4_3`, `em4_4`, `em4_5`, `text5_0`, `text5_1`, `lang5`, `prob5`, `em5_0`, `em5_1`, `em5_2`, `em5_3`, `em5_4`, `em5_5`, `text6_0`, `text6_1`, `lang6`, `prob6`, `em6_0`, `em6_1`, `em6_2`, `em6_3`, `em6_4`, `em6_5`, `text7_0`, `text7_1`, `lang7`, `prob7`, `em7_0`, `em7_1`, `em7_2`, `em7_3`, `em7_4`, `em7_5`, `WDBVerified`) VALUES
    (15486, '', 'Get away from me, you monster! Don''t look at me! I''m hideous! ', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15211); -- 15486
    UPDATE `creature_template` SET `gossip_menu_id` = 11132 WHERE `entry` = 38910;
     
    DELETE FROM `gossip_menu_option` WHERE menu_id=11132;
    INSERT INTO gossip_menu_option(menu_id, id, option_icon, option_text, option_id, npc_option_npcflag, action_menu_id, action_poi_id, box_coded, box_money, box_text) VALUES
    (11132, 0, 0, 'You''re not hideous, Lilian... you''re one of us. Here, look in this mirror, see for yourself.', 1, 1, 0, 0, 0, 0, '');
     
     
    -- Lilian Voss
    SET @ENTRY := 38910;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,1,62,0,100,0,11132,0,0,0,80,3891000,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"On gossip Select do action"),
    (@ENTRY,@SOURCETYPE,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Close gossip");
     
    DELETE FROM creature_text WHERE entry=38910;
    INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
    (38910, 0, 0, 'You don''t understand... I CAN''T be undead! Not me, not now...', 12, 0, 100, 18, 0, 0, 'Lilian Voss');
     
     
     
    -- Lilian Voss
    SET @ENTRY := 3891000;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,2000,2000,2000,2000,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Say text 0"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,2000,2000,2000,2000,33,38910,0,0,0,0,0,17,0,30,0,0.0,0.0,0.0,0.0,"Give credit to player"),
    (@ENTRY,@SOURCETYPE,2,0,0,0,100,0,0,0,0,0,53,1,3891000,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Do wp"),
    (@ENTRY,@SOURCETYPE,3,0,0,0,100,0,20000,20000,20000,20000,37,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Die self");
     
    DELETE FROM waypoints WHERE entry=3891000;
    INSERT INTO waypoints(entry, pointid, position_x, position_y, position_z) VALUES
    (3891000, 1, 1856.48, 1555.65, 94.7939);
     
     
     
    UPDATE `creature` SET `spawntimesecs` = 20 WHERE `guid` = 45494;
    UPDATE `creature_template` SET `scale` = 1 WHERE `entry` = 1512;
     
     
     
     
    -- Marshal Redpath
    SET @ENTRY := 49424;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,1,0,100,0,0,0,0,0,5,36,0,0,0,0,0,11,49428,5,0,0.0,0.0,0.0,0.0,"Showfight"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,1,0,0,0,0,11,83015,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Cast 83015 on victim"),
    (@ENTRY,@SOURCETYPE,2,0,0,0,100,0,6000,9000,5000,9000,11,33239,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"cast 33239 on victim"),
    (@ENTRY,@SOURCETYPE,3,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"on aggro talk");
     
     
    DELETE FROM creature_text WHERE entry=49424;
    INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
    (49424, 0, 0, 'BLEEAAAGGHHH! I''m a monster, don''t look at me!', 14, 0, 100, 0, 0, 0, 'Marschall Rotpfad');
     
     
    -- Shadow Priest Sarvis
    SET @ENTRY := 1569;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,1,20,0,100,0,24971,0,0,0,12,49426,3,40000,0,0,0,8,0,0,0,1843.19,1629.07,96.93,1.58,"on reward summon deathgard darnell"),
    (@ENTRY,@SOURCETYPE,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Say text 0");
     
    DELETE FROM creature_text WHERE entry=1569;
    INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
    (1569, 0, 0, 'Well, look who''s here!', 12, 0, 100, 5, 0, 0, 'Schattenpriester Sarvis');
     
     
     
    -- Deathguard Darnell
    SET @ENTRY := 49426;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,54,0,100,0,0,0,0,0,80,4942600,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"On Summoned do action");
     
     
    -- Deathguard Darnell
    SET @ENTRY := 4942600;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,2000,2000,2000,2000,1,0,0,0,0,0,0,21,100,0,0,0.0,0.0,0.0,0.0,"talk to player"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,6000,6000,6000,6000,1,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 1"),
    (@ENTRY,@SOURCETYPE,2,0,0,0,100,0,6000,6000,6000,6000,1,2,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Talk 2"),
    (@ENTRY,@SOURCETYPE,3,0,0,0,100,0,6000,6000,6000,6000,1,3,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 3"),
    (@ENTRY,@SOURCETYPE,4,0,0,0,100,0,6000,6000,6000,6000,1,4,0,0,0,0,0,21,100,0,0,0.0,0.0,0.0,0.0,"talk 4");
     
    DELETE FROM creature_text WHERE entry=49426;
    INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
    (49426, 0, 0, 'Hi, $s! What do you think about my new gear?', 12, 0, 100, 23, 0, 0, 'Todeswache Darnell'),
    (49426, 1, 0, 'They''re making me into a Deathguard. Can you believe it?', 12, 0, 100, 1, 0, 0, 'Todeswache Darnell'),
    (49426, 2, 0, 'I''ll probably be staying here in Deathknell. If things work out though... who knows? Maybe I''ll get to meet the Dark Lady herself.', 12, 0, 100, 6, 0, 0, 'Todeswache Darnell'),
    (49426, 3, 0, 'How about you? I''ve heard that Sarvis is going to send you off to Calston Estate. Big assignment, eh?', 12, 0, 100, 1, 0, 0, 'Todeswache Darnell'),
    (49426, 4, 0, 'Well, I won''t hold you up. It''s been a pleasure, $n. I hope our paths cross again soon.', 12, 0, 100, 66, 0, 0, 'Todeswache Darnell');
    UPDATE `quest_template` SET `RewardSpellCast` = 0 WHERE `Id` = 24971;
    UPDATE `creature_template` SET `equipment_id` = 49426 WHERE `entry` = 49426;
    UPDATE `creature_template` SET `faction_A` = 68, `faction_H` = 68, `unit_flags` = 32768, `HoverHeight` = 1 WHERE `entry` = 49426;
     
     
    -- Quest chain for starting quest #24994: Doom Weed
    UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 24994;
    UPDATE `quest_template` SET `PrevQuestId` = 24994, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 24995;
     

    UPDATE `creature_text` SET `text`='%s is ready for being capture!' WHERE (`entry`='1544') AND (`groupid`='0') AND (`id`='0');
     
     
    -- Vile Fin Minor Oracle
    SET @ENTRY := 1544;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,2,0,100,1,0,20,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"At 20 % health say text"),
    (@ENTRY,@SOURCETYPE,1,0,8,0,100,0,73108,0,0,0,86,73433,0,7,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"on spellhit 73108 summon creature");
     
     
    -- Captured Vile Fin Minor Oracle
    SET @ENTRY := 39078;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,60,0,100,0,1000,1000,20000,20000,29,0,0,0,0,0,0,23,0,0,0,0.0,0.0,0.0,0.0,"On summoned follow player"),
    (@ENTRY,@SOURCETYPE,1,0,60,0,100,1,1000,1000,1000,1000,33,38923,0,0,0,0,0,23,0,0,0,0.0,0.0,0.0,0.0,"give credit to owner"),
    (@ENTRY,@SOURCETYPE,2,3,38,0,100,0,0,1,0,0,33,38887,0,0,0,0,0,23,0,0,0,0.0,0.0,0.0,0.0,"On data set value 1 give credit"),
    (@ENTRY,@SOURCETYPE,3,0,61,0,100,0,0,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"despawn self");
     

     
    -- Vile Fin Puddlejumper
    SET @ENTRY := 1543;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,2,0,100,1,0,20,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"At 20 % health say text"),
    (@ENTRY,@SOURCETYPE,1,2,8,0,100,0,73108,0,0,0,86,73109,0,7,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"on spellhit 73108 summon creature"),
    (@ENTRY,@SOURCETYPE,2,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"despawn self");
     
     
     
     
    -- Captured Vile Fin Puddlejumper
    SET @ENTRY := 38923;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,60,0,100,0,1000,1000,20000,20000,29,0,0,0,0,0,0,23,0,0,0,0.0,0.0,0.0,0.0,"On summoned follow player"),
    (@ENTRY,@SOURCETYPE,1,0,60,0,100,1,1000,1000,1000,1000,33,38923,0,0,0,0,0,23,0,0,0,0.0,0.0,0.0,0.0,"give credit to owner"),
    (@ENTRY,@SOURCETYPE,2,3,38,0,100,0,0,1,0,0,33,38887,0,0,0,0,0,23,0,0,0,0.0,0.0,0.0,0.0,"On data set value 1 give credit"),
    (@ENTRY,@SOURCETYPE,3,0,61,0,100,0,0,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"despawn self");
     
    UPDATE `creature_text` SET `text`='%s is ready for being capture!' WHERE (`entry`='1543') AND (`groupid`='0') AND (`id`='0');
     
    UPDATE `creature_template` SET `minlevel` = 5, `maxlevel` = 5, `faction_A` = 5, `faction_H` = 5, `unit_flags` = 33288, `HoverHeight` = 1 WHERE `entry` = 38923;
    UPDATE `creature_template` SET `minlevel` = 5, `maxlevel` = 5, `faction_A` = 5, `faction_H` = 5, `unit_flags` = 33288, `HoverHeight` = 1 WHERE `entry` = 39078;
     
     
    -- Sedrick Calston
    SET @ENTRY := 38925;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,60,0,100,0,2000,2000,2000,2000,45,0,1,0,0,0,0,19,38923,9,0,0.0,0.0,0.0,0.0,"set data 1 to 38923"),
    (@ENTRY,@SOURCETYPE,1,0,60,0,100,0,2000,2000,2000,2000,45,0,1,0,0,0,0,19,39078,9,0,0.0,0.0,0.0,0.0,"set data 1 to 39078");
     
    UPDATE `creature_template` SET `IconName` = '' WHERE `entry` = 38933;
    UPDATE `creature_template` SET `faction_A` = 35, `faction_H` = 35, `npcflag` = 16777216 WHERE `entry` = 38933;
    REPLACE INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`) VALUES ('38933', '73123', '1');
     
    UPDATE `creature_template` SET `gossip_menu_id` = 11135, `AIName` = '' WHERE `entry` = 38999;
    UPDATE `gossip_menu_option` SET `option_id`='1', `npc_option_npcflag`='1' WHERE (`menu_id`='11135') AND (`id`='0');
    UPDATE `gossip_menu_option` SET `action_menu_id`='11134' WHERE (`menu_id`='11135') AND (`id`='0');
    UPDATE `gossip_menu_option` SET `option_id`='1', `npc_option_npcflag`='1', `action_menu_id`='11136' WHERE (`menu_id`='11134') AND (`id`='0');
    UPDATE `gossip_menu_option` SET `option_id`='1', `npc_option_npcflag`='1' WHERE (`menu_id`='11136') AND (`id`='0');
     
    -- Lilian Voss
    SET @ENTRY := 38999;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,1,62,0,100,0,11136,0,0,0,80,3899900,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"call event on gossip select 11136"),
    (@ENTRY,@SOURCETYPE,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"close gossip");
     
    -- Lilian Voss
    SET @ENTRY := 3899900;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Talk 0"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,2000,2000,2000,2000,12,39002,7,0,0,0,0,8,0,0,0,2446.84,1597.22,67.73,5.38,"Summon lieutenant"),
    (@ENTRY,@SOURCETYPE,2,0,0,0,100,0,13000,13000,13000,13000,1,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 1"),
    (@ENTRY,@SOURCETYPE,3,0,0,0,100,0,8000,8000,8000,8000,1,2,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 2"),
    (@ENTRY,@SOURCETYPE,4,0,0,0,100,0,12000,12000,12000,12000,11,73304,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"cast 73304 on self and jump on lieutenant to kill him"),
    (@ENTRY,@SOURCETYPE,5,0,0,0,100,0,1500,1500,1500,1500,11,46598,0,0,0,0,0,19,39002,20,0,0.0,0.0,0.0,0.0,"Jump on lieutenant"),
    (@ENTRY,@SOURCETYPE,6,0,0,0,100,0,2500,2500,2500,2500,97,10,10,0,0,0,0,8,0,0,0,2442.93,1600.72,72.15,1.94,"Jump back"),
    (@ENTRY,@SOURCETYPE,7,0,0,0,100,0,1000,1000,1000,1000,1,3,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 3"),
    (@ENTRY,@SOURCETYPE,8,0,0,0,100,0,4000,4000,4000,4000,1,4,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 4"),
    (@ENTRY,@SOURCETYPE,9,0,0,0,100,0,0,0,0,0,33,38999,0,0,0,0,0,17,0,50,0,0.0,0.0,0.0,0.0,"Give credit to player"),
    (@ENTRY,@SOURCETYPE,10,0,0,0,100,0,1000,1000,1000,1000,41,1000,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Force despawn");
     
     
    DELETE FROM waypoints WHERE entry=3900200;
    INSERT INTO waypoints(entry, pointid, position_x, position_y, position_z)  VALUES
    (3900200, 1, 2441.31, 1598.17, 72.1557);
     
    -- Scarlet Lieutenant Gebler
    SET @ENTRY := 39002;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,54,0,100,0,0,0,0,0,80,3900200,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"On summonet call time action"),
    (@ENTRY,@SOURCETYPE,1,2,8,0,100,0,46598,0,0,0,11,73304,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"cast 73304 on self when lilian jump on him"),
    (@ENTRY,@SOURCETYPE,2,0,61,0,100,0,0,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"die");
     
    -- Scarlet Lieutenant Gebler
    SET @ENTRY := 3900200;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,0,0,0,0,53,0,3900200,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Do wp 3900200"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,10000,10000,10000,10000,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 0"),
    (@ENTRY,@SOURCETYPE,2,0,0,0,100,0,8000,8000,8000,8000,1,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 1"),
    (@ENTRY,@SOURCETYPE,3,0,0,0,100,0,6000,6000,6000,6000,1,2,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 2"),
    (@ENTRY,@SOURCETYPE,4,0,0,0,100,0,5000,5000,5000,5000,1,3,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 3");
    DELETE FROM `creature` WHERE `id`=39002;
     
    DELETE FROM creature_text WHERE entry in (38999,39002);
    INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
    (38999, 0, 0, 'Yes, my... wait, be quiet! I hear the lieutenant approaching.', 12, 0, 100, 0, 0, 0, 'Lilian Voss'),
    (38999, 1, 0, 'Gebler, you came! What did he say?', 12, 0, 100, 0, 0, 0, 'Lilian Voss'),
    (38999, 2, 0, 'What? NO! This can''t be! Gebler, you know me... we were friends once!', 12, 0, 100, 0, 0, 0, 'Lilian Voss'),
    (38999, 3, 0, 'Gebler, father, why would you...', 12, 0, 100, 0, 0, 0, 'Lilian Voss'),
    (38999, 4, 0, 'The world of the living may have turned its back on me, but I''m no damned Scourge. Just go.', 12, 0, 100, 0, 0, 0, 'Lilian Voss'),
    (39002, 0, 0, 'The time has come, my little captive... word has come back from your father.', 12, 0, 100, 0, 0, 0, 'Scharlachroter Leutnant Gebler'),
    (39002, 1, 0, 'High Priest Voss denounces you as a daughter. He''s ordered that you be executed immediately.', 12, 0, 100, 0, 0, 0, 'Scharlachroter Leutnant Gebler'),
    (39002, 2, 0, 'The High Priest sends his regrets. He head hoped that one day you would be a powerful weapon against our enemies.', 12, 0, 100, 0, 0, 0, 'Scharlachroter Leutnant Gebler'),
    (39002, 3, 0, 'Unfortunately, you were too dangerous in life, and you''re far too dangerous in undeath. I will enjoy killing you, you Scourged witch...', 12, 0, 100, 0, 0, 0, 'Scharlachroter Leutnant Gebler');
     
     
    DELETE FROM `creature` WHERE `id`=10666;
    DELETE FROM `creature` WHERE `guid`=45898;
    INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
    (45898, 10666, 0, 85, 4916, 1, 1, 10006, 0, 2211.21, 1035.08, 35.3453, 1.16972, 500, 0, 0, 1910, 0, 2, 0, 0, 0);
    DELETE FROM `creature_addon` WHERE (`guid`=45898);
    INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (45898, 1066600, 0, 0, 257, 0, '');
    UPDATE `gossip_menu_option` SET `npc_option_npcflag`='4739' WHERE (`menu_id`='11159') AND (`id`='0');
    UPDATE `gossip_menu_option` SET `option_id`='3' WHERE (`menu_id`='11159') AND (`id`='0');
     
    DELETE FROM waypoint_data WHERE id=1066600;
    INSERT INTO waypoint_data(id, point, position_x, position_y, position_z, orientation, delay, move_flag, action, action_chance, wpguid) VALUES
    (1066600, 1, 2239.07, 1033.4, 35.8493, 0, 0, 0, 0, 100, 0),
    (1066600, 2, 2237.45, 1000, 36.6033, 0, 0, 0, 0, 100, 0),
    (1066600, 3, 2217.64, 1036.4, 35.2443, 0, 0, 0, 0, 100, 0),
    (1066600, 4, 2236.42, 1040.64, 34.6048, 0, 0, 0, 0, 100, 0),
    (1066600, 5, 2251.58, 1029.93, 36.5899, 0, 0, 0, 0, 100, 0),
    (1066600, 6, 2248.46, 1022.66, 36.4498, 0, 0, 0, 0, 100, 0);
    -- Quest chain for starting quest #24975: Fields of Grief
    UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 24975;
    UPDATE `quest_template` SET `PrevQuestId` = 24975, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 24976;
    UPDATE `quest_template` SET `PrevQuestId` = 24976, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 24977;
     
     
    -- Captured Scarlet Zealot
    SET @ENTRY := 1931;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,20,0,100,0,24977,0,0,0,80,193100,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Scarlet Zealot - On quest 24977 rewarded - Start action list");
     
    -- Captured Scarlet Zealot
    SET @ENTRY := 193100;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Scarlet Zealot - Action 0 - Say 0"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,3000,3000,0,0,11,43258,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Scarlet Zealot - Action 1 - Cast spell"),
    (@ENTRY,@SOURCETYPE,2,0,0,0,100,0,0,0,0,0,11,3287,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"change model"),
    (@ENTRY,@SOURCETYPE,3,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,2251.79,1026.03,36.55,0.0,"Scarlet Zealot - Action 2 - Move"),
    (@ENTRY,@SOURCETYPE,4,0,0,0,100,0,2000,2000,0,0,1,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Scarlet Zealot - Action 4 - Say 1"),
    (@ENTRY,@SOURCETYPE,5,0,0,0,100,0,3000,3000,0,0,69,0,0,0,0,0,0,8,0,0,0,2247.08,1021.9,36.47,0.0,"Scarlet Zealot - Action 3 - Move"),
    (@ENTRY,@SOURCETYPE,6,0,0,0,100,0,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,2251.77,1016.72,36.47,0.0,"Scarlet Zealot - Action 5 - Move"),
    (@ENTRY,@SOURCETYPE,7,0,0,0,100,0,3000,3000,0,0,69,0,0,0,0,0,0,8,0,0,0,2252.45,1012.92,36.64,0.0,"Scarlet Zealot - Action 6 - Move"),
    (@ENTRY,@SOURCETYPE,8,0,0,0,100,0,2000,2000,0,0,37,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Scarlet Zealot - Action 7 -die");
     
    UPDATE `quest_template` SET `PrevQuestId` = 24996 WHERE `Id` = 24991;
    -- Quest chain for starting quest #24997: Graverobbers
    UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 24997;
    UPDATE `quest_template` SET `PrevQuestId` = 24997, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 24998;
    UPDATE `quest_template` SET `PrevQuestId` = 24994 WHERE `Id` = 24999;
    -- Quest chain for starting quest #25031: Head for the Mills
    UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 25031;
    UPDATE `quest_template` SET `PrevQuestId` = 25031, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 25003;
    UPDATE `quest_template` SET `PrevQuestId` = 25003 WHERE `Id` = 25004;
    UPDATE `quest_template` SET `PrevQuestId` = 25003 WHERE `Id` = 25029;
     
     
     
     
           
            REPLACE INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`) VALUES ('19', '25031', '8', '24995');
            REPLACE INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`) VALUES ('19', '25031', '8', '24999');      
            REPLACE INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`) VALUES ('20', '25031', '8', '24995');
            REPLACE INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`) VALUES ('20', '25031', '8', '24999');      
           
           
           
     
            REPLACE INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`) VALUES ('19', '25005', '8', '25004');
            REPLACE INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`) VALUES ('19', '25005', '8', '25029');      
            REPLACE INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`) VALUES ('20', '25005', '8', '25004');
            REPLACE INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`) VALUES ('20', '25005', '8', '25029');
           
            UPDATE `quest_template` SET `PrevQuestId` = 24983 WHERE `Id` = 24988;
            UPDATE `quest_template` SET `PrevQuestId` = 24988 WHERE `Id` = 24989;
    UPDATE `quest_template` SET `PrevQuestId` = 25012, `NextQuestId` = 26965, `ExclusiveGroup` = 0 WHERE `Id` = 26964;
    UPDATE `quest_template` SET `PrevQuestId` = 25012, `NextQuestId` = 26965, `ExclusiveGroup` = 0 WHERE `Id` = 28568;
    UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 26965;
            DELETE FROM `creature_loot_template` WHERE `entry` = 1535;
    INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
    (1535, 2589, 59.2354, 1, 0, 1, 1), -- 6Linen Cloth
    (1535, 52079, 16.6101, 1, 0, 1, 1), -- 6A Scarlet Letter
    (1535, 2070, 5.5476, 1, 0, 1, 1), -- 6Darnassian Bleu
    (1535, 159, 2.4913, 1, 0, 1, 1), -- 6Refreshing Spring Water
    (1535, 774, 1.5368, 1, 0, 1, 1), -- 5Malachite
    (1535, 118, 1.3697, 1, 0, 1, 1), -- 6Minor Healing Potion
    (1535, 1411, 0.5909, 1, 0, 1, 1), -- 7Withered Staff
    (1535, 1416, 0.5806, 1, 0, 1, 1), -- 7Rusty Hatchet
    (1535, 818, 0.5772, 1, 0, 1, 1), -- 5Tigerseye
    (1535, 1414, 0.5668, 1, 0, 1, 1), -- 7Cracked Sledge
    (1535, 2138, 0.5599, 1, 0, 1, 1), -- 7Sharpened Letter Opener
    (1535, 1415, 0.5444, 1, 0, 1, 1), -- 7Carpenter's Mallet
    (1535, 2773, 0.5341, 1, 0, 1, 1), -- 7Cracked Shortbow
    (1535, 1423, 0.5220, 1, 0, 1, 1), -- 7Worn Leather Pants
    (1535, 1429, 0.5014, 1, 0, 1, 1), -- 7Patchwork Cloak
    (1535, 2774, 0.5014, 1, 0, 1, 1), -- 7Rust-Covered Blunderbuss
    (1535, 2875, -0.4858, 1, 0, 1, 1), -- 6Scarlet Insignia Ring
    (1535, 1413, 0.4790, 1, 0, 1, 1), -- 7Feeble Sword
    (1535, 1412, 0.4755, 1, 0, 1, 1), -- 7Crude Bastard Sword
    (1535, 1417, 0.4755, 1, 0, 1, 1), -- 7Beaten Battle Axe
    (1535, 1431, 0.4738, 1, 0, 1, 1), -- 7Patchwork Pants
    (1535, 1430, 0.4721, 1, 0, 1, 1), -- 7Patchwork Gloves
    (1535, 1433, 0.4721, 1, 0, 1, 1), -- 7Patchwork Armor
    (1535, 3370, 0.4652, 1, 0, 1, 1), -- 7Patchwork Belt
    (1535, 1425, 0.4497, 1, 0, 1, 1), -- 7Worn Leather Vest
    (1535, 1422, 0.4445, 1, 0, 1, 1), -- 7Worn Leather Gloves
    (1535, 3373, 0.4273, 1, 0, 1, 1), -- 7Patchwork Bracers
    (1535, 2213, 0.4135, 1, 0, 1, 1), -- 7Worn Large Shield
    (1535, 1419, 0.4118, 1, 0, 1, 1), -- 7Worn Leather Boots
    (1535, 1418, 0.4014, 1, 0, 1, 1), -- 7Worn Leather Belt
    (1535, 1427, 0.3842, 1, 0, 1, 1), -- 7Patchwork Shoes
    (1535, 2642, 0.3652, 1, 0, 1, 1), -- 7Loose Chain Boots
    (1535, 1420, 0.3566, 1, 0, 1, 1), -- 7Worn Leather Bracers
    (1535, 2643, 0.3566, 1, 0, 1, 1), -- 7Loose Chain Bracers
    (1535, 2212, 0.3549, 1, 0, 1, 1), -- 7Cracked Buckler
    (1535, 2645, 0.3515, 1, 0, 1, 1), -- 7Loose Chain Gloves
    (1535, 2646, 0.3273, 1, 0, 1, 1), -- 7Loose Chain Pants
    (1535, 2648, 0.3205, 1, 0, 1, 1), -- 7Loose Chain Vest
    (1535, 2635, 0.3015, 1, 0, 1, 1), -- 7Loose Chain Belt
    (1535, 766, 0.2274, 1, 0, 1, 1), -- 6Flanged Mace
    (1535, 8177, 0.2067, 1, 0, 1, 1), -- 6Practice Sword
    (1535, 4560, 0.1723, 1, 0, 1, 1), -- 6Fine Scimitar
    (1535, 3609, 0.1688, 1, 0, 1, 1), -- 5Plans: Copper Chain Vest
    (1535, 3265, -0.1688, 1, 0, 1, 1), -- 6Scavenger Paw
    (1535, 2598, 0.1654, 1, 0, 1, 1), -- 5Pattern: Red Linen Robe
    (1535, 8182, 0.1585, 1, 0, 1, 1), -- 6Pellet Rifle
    (1535, 5571, 0.1464, 1, 0, 1, 1), -- 6Small Black Pouch
    (1535, 5572, 0.1378, 1, 0, 1, 1), -- 6Small Green Pouch
    (1535, 3264, -0.1275, 1, 0, 1, 1), -- 6Duskbat Wing
    (1535, 4565, 0.1103, 1, 0, 1, 1), -- 6Simple Dagger
    (1535, 8179, 0.1051, 1, 0, 1, 1), -- 6Cadet's Bow
    (1535, 805, 0.0879, 1, 0, 1, 1), -- 6Small Red Pouch
    (1535, 828, 0.0879, 1, 0, 1, 1), -- 6Small Blue Pouch
    (1535, 3189, 0.0810, 1, 0, 1, 1), -- 6Wood Chopper
    (1535, 4496, 0.0775, 1, 0, 1, 1), -- 6Small Brown Pouch
    (1535, 767, 0.0775, 1, 0, 1, 1), -- 6Long Bo Staff
    (1535, 3190, 0.0775, 1, 0, 1, 1), -- 6Beatstick
    (1535, 4563, 0.0758, 1, 0, 1, 1), -- 6Billy Club
    (1535, 8181, 0.0724, 1, 0, 1, 1), -- 6Hunting Rifle
    (1535, 768, 0.0706, 1, 0, 1, 1), -- 6Lumberjack Axe
    (1535, 8178, 0.0413, 1, 0, 1, 1), -- 5Training Sword
    (1535, 727, 0.0310, 1, 0, 1, 1), -- 5Notched Shortsword
    (1535, 4562, 0.0293, 1, 0, 1, 1), -- 5Severing Axe
    (1535, 62328, 0.0241, 1, 0, 1, 1), -- 7Shed Fur
    (1535, 2855, -0.019, 1, 0, 1, 1), -- 6Putrid Claw
    (1535, 20797, -0.0155, 1, 0, 1, 1), -- 6Lynx Collar
    (1535, 2407, 0.0138, 1, 0, 1, 1), -- 5Pattern: White Leather Jerkin
    (1535, 62505, -0.0138, 1, 0, 1, 1), -- 6Bat Eye
    (1535, 5523, 0.0138, 1, 0, 1, 1), -- 6Small Barnacled Clam
    (1535, 7288, 0.0121, 1, 0, 1, 1), -- 5Pattern: Rugged Leather Pants
    (1535, 7074, 0.0121, 1, 0, 1, 1), -- 7Chipped Claw
    (1535, 4604, 0.0103, 1, 0, 1, 1), -- 6Forest Mushroom Cap
    (1535, 12223, 0.0103, 1, 0, 1, 1), -- 6Meaty Bat Wing
    (1535, 3300, 0.0103, 1, 0, 1, 1), -- 7Rabbit's Foot
    (1535, 2644, 0.0103, 1, 0, 1, 1), -- 7Loose Chain Cloak
    (1535, 4408, 0.0086, 1, 0, 1, 1), -- 5Schematic: Mechanical Squirrel Box
    (1535, 4757, 0.0086, 1, 0, 1, 1), -- 7Cracked Egg Shells
    (1535, 2406, 0.0069, 1, 0, 1, 1), -- 5Pattern: Fine Leather Boots
    (1535, 2876, -0.0069, 1, 0, 1, 1), -- 6Duskbat Pelt
    (1535, 5465, 0.0069, 1, 0, 1, 1), -- 6Small Spider Leg
    (1535, 1468, 0.0069, 1, 0, 1, 1), -- 6Murloc Fin
    (1535, 6296, 0.0069, 1, 0, 1, 1), -- 7Patch of Bat Hair
    (1535, 2553, 0.0052, 1, 0, 1, 1), -- 5Recipe: Elixir of Minor Agility
    (1535, 17056, 0.0052, 1, 0, 1, 1), -- 6Light Feather
    (1535, 6271, 0.0034, 1, 0, 1, 1), -- 5Pattern: Red Linen Vest
    (1535, 2555, 0.0034, 1, 0, 1, 1), -- 5Recipe: Swiftness Potion
    (1535, 3610, 0.0034, 1, 0, 1, 1), -- 5Plans: Gemmed Copper Gauntlets
    (1535, 117, 0.0034, 1, 0, 1, 1), -- 6Tough Jerky
    (1535, 2858, -0.0034, 1, 0, 1, 1), -- 6Darkhound Blood
    (1535, 2859, -0.0034, 1, 0, 1, 1), -- 6Vile Fin Scale
    (1535, 20482, -0.0034, 1, 0, 1, 1), -- 6Arcane Sliver
    (1535, 52077, 0.0034, 1, 0, 1, 1), -- 6Urgent Scarlet Memorandum
    (1535, 3082, -0.0034, 1, 0, 1, 1), -- 6Dargol's Skull
    (1535, 20847, 0.0034, 1, 0, 1, 1), -- 7Wraith Fragment
    (1535, 21005, 0.0034, 1, 0, 1, 1), -- 7Unkempt Gloves
    (1535, 21018, 0.0034, 1, 0, 1, 1), -- 7Shoddy Chain Gloves
    (1535, 1421, 0.0034, 1, 0, 1, 1), -- 7Worn Hide Cloak
    (1535, 21525, 0.0017, 1, 0, 1, 1), -- 5Green Winter Hat
    (1535, 68750, 0.0017, 1, 0, 1, 1), -- 5Imbued Pioneer Belt
    (1535, 6342, 0.0017, 1, 0, 1, 1), -- 5Formula: Enchant Chest - Minor Mana
    (1535, 9756, 0.0017, 1, 0, 1, 1), -- 5Gypsy Trousers
    (1535, 2408, 0.0017, 1, 0, 1, 1), -- 5Pattern: Fine Leather Gloves
    (1535, 15306, 0.0017, 1, 0, 1, 1), -- 5Feral Bindings
    (1535, 1210, 0.0017, 1, 0, 1, 1), -- 5Shadowgem
    (1535, 2834, -0.0017, 1, 0, 1, 1), -- 6Embalming Ichor
    (1535, 4888, -0.0017, 1, 0, 1, 1), -- 6Crawler Mucus
    (1535, 5168, -0.0017, 1, 0, 1, 1), -- 6Timberling Seed
    (1535, 8050, -0.0017, 1, 0, 1, 1), -- 6Tallonkai's Jewel
    (1535, 20764, -0.0017, 1, 0, 1, 1), -- 6Prospector Anvilward's Head
    (1535, 23334, 0.0017, 1, 0, 1, 1), -- 6Cracked Power Core
    (1535, 14087, 0.0017, 1, 0, 1, 1), -- 6Beaded Cuffs
    (1535, 4674, 0.0017, 1, 0, 1, 1), -- 6Tribal Cloak
    (1535, 3173, 0.0017, 1, 0, 1, 1), -- 6Bear Meat
    (1535, 9743, 0.0017, 1, 0, 1, 1), -- 6Simple Shoes
    (1535, 4305, 0.0017, 1, 0, 1, 1), -- 6Bolt of Silk Cloth
    (1535, 1476, 0.0017, 1, 0, 1, 1), -- 7Snapped Spider Limb
    (1535, 5367, 0.0017, 1, 0, 1, 1), -- 7Primitive Rock Tool
    (1535, 7101, 0.0017, 1, 0, 1, 1), -- 7Bug Eye
    (1535, 20812, 0.0017, 1, 0, 1, 1), -- 7Tattered Pelt
    (1535, 67405, 0.0017, 1, 0, 1, 1), -- 7Empty Snail Shell
    (1535, 21012, 0.0017, 1, 0, 1, 1), -- 7Scraggy Leather Gloves
    (1535, 21004, 0.0017, 1, 0, 1, 1), -- 7Unkempt Cloak
    (1535, 1507, 0.0017, 1, 0, 1, 1), -- 7Warped Leather Pants
    (1535, 1498, 0.0017, 1, 0, 1, 1); -- 7Calico Gloves
    UPDATE `creature_template` SET `lootid` = 1535 WHERE `entry` = 1535;
    -- Quest chain for starting quest #24982: The New Forsaken
    UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 24982;
    UPDATE `quest_template` SET `PrevQuestId` = 24982, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 24983;
    -- Captured Mountaineer
    SET @ENTRY := 2211;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,20,0,100,0,24996,0,0,0,80,221100,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Captured Mountaineer - On quest reward - Start timed action list");
     
    -- Captured Mountaineer
    SET @ENTRY := 221100;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Captured Mountaineer - Action 0 - Say 0"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,4000,4000,0,0,37,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Captured Mountaineer - Action 2 - Suicide");
     
       
     
     
     
       
    -- Data mined from www.wowhead.com
    -- Generated by Loot.php November 29, 2012 by Maibenrai
    --  http://www.wowhead.com/npc=1662
    DELETE FROM `creature_loot_template` WHERE `entry` = 1662;
    INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
    (1662, 52077, 14.0579, 1, 0, 1, 1), -- 6Urgent Scarlet Memorandum
    (1662, 2589, 9.3216, 1, 0, 1, 1), -- 6Linen Cloth
    (1662, 2070, 0.9907, 1, 0, 1, 1), -- 6Darnassian Bleu
    (1662, 2875, -0.6227, 1, 0, 1, 1), -- 6Scarlet Insignia Ring
    (1662, 159, 0.4434, 1, 0, 1, 1), -- 6Refreshing Spring Water
    (1662, 1413, 0.2076, 1, 0, 1, 1), -- 7Feeble Sword
    (1662, 118, 0.1981, 1, 0, 1, 1), -- 6Minor Healing Potion
    (1662, 1411, 0.1981, 1, 0, 1, 1), -- 7Withered Staff
    (1662, 2138, 0.1510, 1, 0, 1, 1), -- 7Sharpened Letter Opener
    (1662, 1423, 0.1415, 1, 0, 1, 1), -- 7Worn Leather Pants
    (1662, 4666, 0.1321, 1, 0, 1, 1), -- 6Burnt Leather Belt
    (1662, 7350, 0.1227, 1, 0, 1, 1), -- 6Disciple's Bracers
    (1662, 1415, 0.1227, 1, 0, 1, 1), -- 7Carpenter's Mallet
    (1662, 1420, 0.1227, 1, 0, 1, 1), -- 7Worn Leather Bracers
    (1662, 2959, 0.1132, 1, 0, 1, 1), -- 6Journeyman's Boots
    (1662, 3332, 0.1132, 1, 0, 1, 1), -- 6Perrine's Boots
    (1662, 1418, 0.1038, 1, 0, 1, 1), -- 7Worn Leather Belt
    (1662, 1419, 0.1038, 1, 0, 1, 1), -- 7Worn Leather Boots
    (1662, 6518, 0.0943, 1, 0, 1, 1), -- 6Pioneer Boots
    (1662, 767, 0.0849, 1, 0, 1, 1), -- 6Long Bo Staff
    (1662, 768, 0.0849, 1, 0, 1, 1), -- 6Lumberjack Axe
    (1662, 4663, 0.0849, 1, 0, 1, 1), -- 6Journeyman's Belt
    (1662, 9742, 0.0849, 1, 0, 1, 1), -- 6Simple Cord
    (1662, 1430, 0.0849, 1, 0, 1, 1), -- 7Patchwork Gloves
    (1662, 1417, 0.0849, 1, 0, 1, 1), -- 7Beaten Battle Axe
    (1662, 1414, 0.0849, 1, 0, 1, 1), -- 7Cracked Sledge
    (1662, 3641, 0.0755, 1, 0, 1, 1), -- 6Journeyman's Bracers
    (1662, 3214, 0.0755, 1, 0, 1, 1), -- 6Warrior's Bracers
    (1662, 4563, 0.0755, 1, 0, 1, 1), -- 6Billy Club
    (1662, 1422, 0.0755, 1, 0, 1, 1), -- 7Worn Leather Gloves
    (1662, 1412, 0.0755, 1, 0, 1, 1), -- 7Crude Bastard Sword
    (1662, 6508, 0.0660, 1, 0, 1, 1), -- 6Infantry Cloak
    (1662, 6520, 0.0660, 1, 0, 1, 1), -- 6Pioneer Cloak
    (1662, 1427, 0.0660, 1, 0, 1, 1), -- 7Patchwork Shoes
    (1662, 4658, 0.0566, 1, 0, 1, 1), -- 6Warrior's Cloak
    (1662, 4659, 0.0566, 1, 0, 1, 1), -- 6Warrior's Girdle
    (1662, 2968, 0.0566, 1, 0, 1, 1), -- 6Warrior's Gloves
    (1662, 2774, 0.0566, 1, 0, 1, 1), -- 7Rust-Covered Blunderbuss
    (1662, 3370, 0.0566, 1, 0, 1, 1), -- 7Patchwork Belt
    (1662, 5572, 0.0472, 1, 0, 1, 1), -- 6Small Green Pouch
    (1662, 2960, 0.0472, 1, 0, 1, 1), -- 6Journeyman's Gloves
    (1662, 6506, 0.0472, 1, 0, 1, 1), -- 6Infantry Boots
    (1662, 1429, 0.0472, 1, 0, 1, 1), -- 7Patchwork Cloak
    (1662, 2212, 0.0472, 1, 0, 1, 1), -- 7Cracked Buckler
    (1662, 1433, 0.0472, 1, 0, 1, 1), -- 7Patchwork Armor
    (1662, 2645, 0.0472, 1, 0, 1, 1), -- 7Loose Chain Gloves
    (1662, 1431, 0.0472, 1, 0, 1, 1), -- 7Patchwork Pants
    (1662, 2646, 0.0472, 1, 0, 1, 1), -- 7Loose Chain Pants
    (1662, 2773, 0.0472, 1, 0, 1, 1), -- 7Cracked Shortbow
    (1662, 3373, 0.0472, 1, 0, 1, 1), -- 7Patchwork Bracers
    (1662, 2962, 0.0377, 1, 0, 1, 1), -- 5Burnt Leather Breeches
    (1662, 4561, 0.0377, 1, 0, 1, 1), -- 5Scalping Tomahawk
    (1662, 5571, 0.0377, 1, 0, 1, 1), -- 6Small Black Pouch
    (1662, 3189, 0.0377, 1, 0, 1, 1), -- 6Wood Chopper
    (1662, 4665, 0.0377, 1, 0, 1, 1), -- 6Burnt Cloak
    (1662, 15895, 0.0377, 1, 0, 1, 1), -- 6Burnt Buckler
    (1662, 2963, 0.0377, 1, 0, 1, 1), -- 6Burnt Leather Boots
    (1662, 8181, 0.0377, 1, 0, 1, 1), -- 6Hunting Rifle
    (1662, 727, 0.0283, 1, 0, 1, 1), -- 5Notched Shortsword
    (1662, 4562, 0.0283, 1, 0, 1, 1), -- 5Severing Axe
    (1662, 2140, 0.0283, 1, 0, 1, 1), -- 5Carving Knife
    (1662, 15932, 0.0283, 1, 0, 1, 1), -- 5Disciple's Stein
    (1662, 3200, 0.0283, 1, 0, 1, 1), -- 6Burnt Leather Bracers
    (1662, 7109, 0.0283, 1, 0, 1, 1), -- 6Pioneer Buckler
    (1662, 2964, 0.0283, 1, 0, 1, 1), -- 6Burnt Leather Gloves
    (1662, 9760, 0.0283, 1, 0, 1, 1), -- 6Cadet Bracers
    (1662, 1416, 0.0283, 1, 0, 1, 1), -- 7Rusty Hatchet
    (1662, 1425, 0.0283, 1, 0, 1, 1), -- 7Worn Leather Vest
    (1662, 2598, 0.0189, 1, 0, 1, 1), -- 5Pattern: Red Linen Robe
    (1662, 2966, 0.0189, 1, 0, 1, 1), -- 5Warrior's Pants
    (1662, 2957, 0.0189, 1, 0, 1, 1), -- 5Journeyman's Vest
    (1662, 2855, -0.0189, 1, 0, 1, 1), -- 6Putrid Claw
    (1662, 52564, 0.0189, 1, 0, 1, 1), -- 6Burning Blade Spellscroll
    (1662, 805, 0.0189, 1, 0, 1, 1), -- 6Small Red Pouch
    (1662, 4496, 0.0189, 1, 0, 1, 1), -- 6Small Brown Pouch
    (1662, 4662, 0.0189, 1, 0, 1, 1), -- 6Journeyman's Cloak
    (1662, 6521, 0.0189, 1, 0, 1, 1), -- 6Pioneer Gloves
    (1662, 7351, 0.0189, 1, 0, 1, 1), -- 6Disciple's Boots
    (1662, 9745, 0.0189, 1, 0, 1, 1), -- 6Simple Cape
    (1662, 9750, 0.0189, 1, 0, 1, 1), -- 6Gypsy Sash
    (1662, 2213, 0.0189, 1, 0, 1, 1), -- 7Worn Large Shield
    (1662, 2643, 0.0189, 1, 0, 1, 1), -- 7Loose Chain Bracers
    (1662, 8178, 0.0094, 1, 0, 1, 1), -- 5Training Sword
    (1662, 2965, 0.0094, 1, 0, 1, 1), -- 5Warrior's Tunic
    (1662, 8180, 0.0094, 1, 0, 1, 1), -- 5Hunting Bow
    (1662, 2075, 0.0094, 1, 0, 1, 1), -- 5Heavy Mace
    (1662, 3192, 0.0094, 1, 0, 1, 1), -- 5Short Bastard Sword
    (1662, 5069, 0.0094, 1, 0, 1, 1), -- 5Fire Wand
    (1662, 6267, 0.0094, 1, 0, 1, 1), -- 5Disciple's Pants
    (1662, 6269, 0.0094, 1, 0, 1, 1), -- 5Pioneer Trousers
    (1662, 9753, 0.0094, 1, 0, 1, 1), -- 5Gypsy Buckler
    (1662, 3610, 0.0094, 1, 0, 1, 1), -- 5Plans: Gemmed Copper Gauntlets
    (1662, 2858, -0.0094, 1, 0, 1, 1), -- 6Darkhound Blood
    (1662, 2859, -0.0094, 1, 0, 1, 1), -- 6Vile Fin Scale
    (1662, 3265, -0.0094, 1, 0, 1, 1), -- 6Scavenger Paw
    (1662, 3190, 0.0094, 1, 0, 1, 1), -- 6Beatstick
    (1662, 1438, 0.0094, 1, 0, 1, 1), -- 6Warrior's Shield
    (1662, 2967, 0.0094, 1, 0, 1, 1), -- 6Warrior's Boots
    (1662, 6507, 0.0094, 1, 0, 1, 1), -- 6Infantry Bracers
    (1662, 6514, 0.0094, 1, 0, 1, 1), -- 6Disciple's Cloak
    (1662, 6517, 0.0094, 1, 0, 1, 1), -- 6Pioneer Belt
    (1662, 6519, 0.0094, 1, 0, 1, 1), -- 6Pioneer Bracers
    (1662, 9754, 0.0094, 1, 0, 1, 1), -- 6Gypsy Cloak
    (1662, 4677, 0.0094, 1, 0, 1, 1), -- 6Veteran Cloak
    (1662, 9752, 0.0094, 1, 0, 1, 1), -- 6Gypsy Bands
    (1662, 62328, 0.0094, 1, 0, 1, 1), -- 7Shed Fur
    (1662, 2635, 0.0094, 1, 0, 1, 1), -- 7Loose Chain Belt
    (1662, 2642, 0.0094, 1, 0, 1, 1), -- 7Loose Chain Boots
    (1662, 2648, 0.0094, 1, 0, 1, 1); -- 7Loose Chain Vest
     
       
    -- Data mined from www.wowhead.com
    -- Generated by Loot.php November 29, 2012 by Maibenrai
    --  http://www.wowhead.com/npc=1537
    DELETE FROM `creature_loot_template` WHERE `entry` = 1537;
    INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
    (1537, 2589, 39.6176, 1, 0, 1, 1), -- 6Linen Cloth
    (1537, 52077, 11.4676, 1, 0, 1, 1), -- 6Urgent Scarlet Memorandum
    (1537, 2070, 3.9634, 1, 0, 1, 1), -- 6Darnassian Bleu
    (1537, 159, 1.7909, 1, 0, 1, 1), -- 6Refreshing Spring Water
    (1537, 2875, -1.7273, 1, 0, 1, 1), -- 6Scarlet Insignia Ring
    (1537, 774, 1.0873, 1, 0, 1, 1), -- 5Malachite
    (1537, 118, 0.9970, 1, 0, 1, 1), -- 6Minor Healing Potion
    (1537, 1420, 0.4247, 1, 0, 1, 1), -- 7Worn Leather Bracers
    (1537, 1417, 0.4205, 1, 0, 1, 1), -- 7Beaten Battle Axe
    (1537, 2138, 0.4041, 1, 0, 1, 1), -- 7Sharpened Letter Opener
    (1537, 1423, 0.3918, 1, 0, 1, 1), -- 7Worn Leather Pants
    (1537, 2774, 0.3734, 1, 0, 1, 1), -- 7Rust-Covered Blunderbuss
    (1537, 1413, 0.3734, 1, 0, 1, 1), -- 7Feeble Sword
    (1537, 2773, 0.3528, 1, 0, 1, 1), -- 7Cracked Shortbow
    (1537, 1416, 0.3528, 1, 0, 1, 1), -- 7Rusty Hatchet
    (1537, 818, 0.3508, 1, 0, 1, 1), -- 5Tigerseye
    (1537, 1422, 0.3364, 1, 0, 1, 1), -- 7Worn Leather Gloves
    (1537, 767, 0.3241, 1, 0, 1, 1), -- 6Long Bo Staff
    (1537, 3189, 0.3221, 1, 0, 1, 1), -- 6Wood Chopper
    (1537, 1419, 0.3159, 1, 0, 1, 1), -- 7Worn Leather Boots
    (1537, 1412, 0.3118, 1, 0, 1, 1), -- 7Crude Bastard Sword
    (1537, 1414, 0.3077, 1, 0, 1, 1), -- 7Cracked Sledge
    (1537, 2212, 0.3036, 1, 0, 1, 1), -- 7Cracked Buckler
    (1537, 3190, 0.3016, 1, 0, 1, 1), -- 6Beatstick
    (1537, 1411, 0.3016, 1, 0, 1, 1), -- 7Withered Staff
    (1537, 1415, 0.3016, 1, 0, 1, 1), -- 7Carpenter's Mallet
    (1537, 1431, 0.2975, 1, 0, 1, 1), -- 7Patchwork Pants
    (1537, 1418, 0.2913, 1, 0, 1, 1), -- 7Worn Leather Belt
    (1537, 3370, 0.2831, 1, 0, 1, 1), -- 7Patchwork Belt
    (1537, 1427, 0.2749, 1, 0, 1, 1), -- 7Patchwork Shoes
    (1537, 1429, 0.2728, 1, 0, 1, 1), -- 7Patchwork Cloak
    (1537, 3373, 0.2728, 1, 0, 1, 1), -- 7Patchwork Bracers
    (1537, 766, 0.2708, 1, 0, 1, 1), -- 6Flanged Mace
    (1537, 2643, 0.2503, 1, 0, 1, 1), -- 7Loose Chain Bracers
    (1537, 1433, 0.2380, 1, 0, 1, 1), -- 7Patchwork Armor
    (1537, 2645, 0.2236, 1, 0, 1, 1), -- 7Loose Chain Gloves
    (1537, 1430, 0.2175, 1, 0, 1, 1), -- 7Patchwork Gloves
    (1537, 2646, 0.2154, 1, 0, 1, 1), -- 7Loose Chain Pants
    (1537, 1425, 0.2154, 1, 0, 1, 1), -- 7Worn Leather Vest
    (1537, 2213, 0.2092, 1, 0, 1, 1), -- 7Worn Large Shield
    (1537, 2635, 0.2072, 1, 0, 1, 1), -- 7Loose Chain Belt
    (1537, 2648, 0.1969, 1, 0, 1, 1), -- 7Loose Chain Vest
    (1537, 2642, 0.1764, 1, 0, 1, 1), -- 7Loose Chain Boots
    (1537, 768, 0.1744, 1, 0, 1, 1), -- 6Lumberjack Axe
    (1537, 4563, 0.1703, 1, 0, 1, 1), -- 6Billy Club
    (1537, 8182, 0.1662, 1, 0, 1, 1), -- 6Pellet Rifle
    (1537, 8177, 0.1498, 1, 0, 1, 1), -- 6Practice Sword
    (1537, 3264, -0.1436, 1, 0, 1, 1), -- 6Duskbat Wing
    (1537, 2672, 0.1251, 1, 0, 1, 1), -- 6Stringy Wolf Meat
    (1537, 727, 0.1190, 1, 0, 1, 1), -- 5Notched Shortsword
    (1537, 8178, 0.1190, 1, 0, 1, 1), -- 5Training Sword
    (1537, 2598, 0.1128, 1, 0, 1, 1), -- 5Pattern: Red Linen Robe
    (1537, 2855, -0.1108, 1, 0, 1, 1), -- 6Putrid Claw
    (1537, 3265, -0.1087, 1, 0, 1, 1), -- 6Scavenger Paw
    (1537, 3609, 0.1067, 1, 0, 1, 1), -- 5Plans: Copper Chain Vest
    (1537, 4562, 0.1026, 1, 0, 1, 1), -- 5Severing Axe
    (1537, 2140, 0.0985, 1, 0, 1, 1), -- 5Carving Knife
    (1537, 8181, 0.0903, 1, 0, 1, 1), -- 6Hunting Rifle
    (1537, 805, 0.0841, 1, 0, 1, 1), -- 6Small Red Pouch
    (1537, 4496, 0.0780, 1, 0, 1, 1), -- 6Small Brown Pouch
    (1537, 828, 0.0739, 1, 0, 1, 1), -- 6Small Blue Pouch
    (1537, 62328, 0.0739, 1, 0, 1, 1), -- 7Shed Fur
    (1537, 5571, 0.0615, 1, 0, 1, 1), -- 6Small Black Pouch
    (1537, 12223, 0.0615, 1, 0, 1, 1), -- 6Meaty Bat Wing
    (1537, 5572, 0.0574, 1, 0, 1, 1), -- 6Small Green Pouch
    (1537, 7074, 0.0554, 1, 0, 1, 1), -- 7Chipped Claw
    (1537, 4561, 0.0492, 1, 0, 1, 1), -- 5Scalping Tomahawk
    (1537, 8180, 0.0492, 1, 0, 1, 1), -- 5Hunting Bow
    (1537, 2834, -0.041, 1, 0, 1, 1), -- 6Embalming Ichor
    (1537, 5523, 0.0328, 1, 0, 1, 1), -- 6Small Barnacled Clam
    (1537, 2876, -0.0308, 1, 0, 1, 1), -- 6Duskbat Pelt
    (1537, 1421, 0.0308, 1, 0, 1, 1), -- 7Worn Hide Cloak
    (1537, 4662, 0.0267, 1, 0, 1, 1), -- 6Journeyman's Cloak
    (1537, 2859, -0.0246, 1, 0, 1, 1), -- 6Vile Fin Scale
    (1537, 4604, 0.0226, 1, 0, 1, 1), -- 6Forest Mushroom Cap
    (1537, 52079, 0.0205, 1, 0, 1, 1), -- 6A Scarlet Letter
    (1537, 3200, 0.0185, 1, 0, 1, 1), -- 6Burnt Leather Bracers
    (1537, 2968, 0.0185, 1, 0, 1, 1), -- 6Warrior's Gloves
    (1537, 1468, 0.0185, 1, 0, 1, 1), -- 6Murloc Fin
    (1537, 2408, 0.0164, 1, 0, 1, 1), -- 5Pattern: Fine Leather Gloves
    (1537, 117, 0.0164, 1, 0, 1, 1), -- 6Tough Jerky
    (1537, 2967, 0.0164, 1, 0, 1, 1), -- 6Warrior's Boots
    (1537, 4665, 0.0144, 1, 0, 1, 1), -- 6Burnt Cloak
    (1537, 6303, 0.0123, 1, 0, 1, 1), -- 6Raw Slitherskin Mackerel
    (1537, 2960, 0.0123, 1, 0, 1, 1), -- 6Journeyman's Gloves
    (1537, 7288, 0.0103, 1, 0, 1, 1), -- 5Pattern: Rugged Leather Pants
    (1537, 4408, 0.0103, 1, 0, 1, 1), -- 5Schematic: Mechanical Squirrel Box
    (1537, 20797, -0.0103, 1, 0, 1, 1), -- 6Lynx Collar
    (1537, 4565, 0.0103, 1, 0, 1, 1), -- 6Simple Dagger
    (1537, 3299, 0.0103, 1, 0, 1, 1), -- 7Fractured Canine
    (1537, 4757, 0.0103, 1, 0, 1, 1), -- 7Cracked Egg Shells
    (1537, 2555, 0.0082, 1, 0, 1, 1), -- 5Recipe: Swiftness Potion
    (1537, 3162, -0.0082, 1, 0, 1, 1), -- 6Notched Rib
    (1537, 20482, -0.0082, 1, 0, 1, 1), -- 6Arcane Sliver
    (1537, 62505, -0.0082, 1, 0, 1, 1), -- 6Bat Eye
    (1537, 5466, 0.0082, 1, 0, 1, 1), -- 6Scorpid Stinger
    (1537, 2966, 0.0062, 1, 0, 1, 1), -- 5Warrior's Pants
    (1537, 3635, -0.0062, 1, 0, 1, 1), -- 6Maggot Eye's Paw
    (1537, 21011, 0.0062, 1, 0, 1, 1), -- 7Scraggy Leather Bracers
    (1537, 15925, 0.0041, 1, 0, 1, 1), -- 5Journeyman's Stave
    (1537, 6271, 0.0041, 1, 0, 1, 1), -- 5Pattern: Red Linen Vest
    (1537, 6342, 0.0041, 1, 0, 1, 1), -- 5Formula: Enchant Chest - Minor Mana
    (1537, 2407, 0.0041, 1, 0, 1, 1), -- 5Pattern: White Leather Jerkin
    (1537, 3163, -0.0041, 1, 0, 1, 1), -- 6Blackened Skull
    (1537, 21781, -0.0041, 1, 0, 1, 1), -- 6Thaelis' Head
    (1537, 21808, -0.0041, 1, 0, 1, 1), -- 6Arcane Core
    (1537, 52564, 0.0041, 1, 0, 1, 1), -- 6Burning Blade Spellscroll
    (1537, 769, 0.0041, 1, 0, 1, 1), -- 6Chunk of Boar Meat
    (1537, 27668, 0.0041, 1, 0, 1, 1), -- 6Lynx Meat
    (1537, 4658, 0.0041, 1, 0, 1, 1), -- 6Warrior's Cloak
    (1537, 7109, 0.0041, 1, 0, 1, 1), -- 6Pioneer Buckler
    (1537, 6507, 0.0041, 1, 0, 1, 1), -- 6Infantry Bracers
    (1537, 6514, 0.0041, 1, 0, 1, 1), -- 6Disciple's Cloak
    (1537, 6519, 0.0041, 1, 0, 1, 1), -- 6Pioneer Bracers
    (1537, 7350, 0.0041, 1, 0, 1, 1), -- 6Disciple's Bracers
    (1537, 6518, 0.0041, 1, 0, 1, 1), -- 6Pioneer Boots
    (1537, 9754, 0.0041, 1, 0, 1, 1), -- 6Gypsy Cloak
    (1537, 6296, 0.0041, 1, 0, 1, 1), -- 7Patch of Bat Hair
    (1537, 20812, 0.0041, 1, 0, 1, 1), -- 7Tattered Pelt
    (1537, 20847, 0.0041, 1, 0, 1, 1), -- 7Wraith Fragment
    (1537, 20848, 0.0041, 1, 0, 1, 1), -- 7Sparkling Dust
    (1537, 62530, 0.0041, 1, 0, 1, 1), -- 7Spider Hair
    (1537, 3300, 0.0041, 1, 0, 1, 1), -- 7Rabbit's Foot
    (1537, 2644, 0.0041, 1, 0, 1, 1), -- 7Loose Chain Cloak
    (1537, 68743, 0.0021, 1, 0, 1, 1), -- 5Imbued Infantry Cloak
    (1537, 68744, 0.0021, 1, 0, 1, 1), -- 5Imbued Pioneer Cloak
    (1537, 68748, 0.0021, 1, 0, 1, 1), -- 5Imbued Disciple's Cloak
    (1537, 1210, 0.0021, 1, 0, 1, 1), -- 5Shadowgem
    (1537, 9776, 0.0021, 1, 0, 1, 1), -- 5Bandit Boots
    (1537, 2828, -0.0021, 1, 0, 1, 1), -- 6Nissa's Remains
    (1537, 2830, -0.0021, 1, 0, 1, 1), -- 6Thurman's Remains
    (1537, 2858, -0.0021, 1, 0, 1, 1), -- 6Darkhound Blood
    (1537, 2872, -0.0021, 1, 0, 1, 1), -- 6Vicious Night Web Spider Venom
    (1537, 20799, -0.0021, 1, 0, 1, 1), -- 6Felendren's Head
    (1537, 20857, 0.0021, 1, 0, 1, 1), -- 6Honey Bread
    (1537, 414, 0.0021, 1, 0, 1, 1), -- 6Dalaran Sharp
    (1537, 2287, 0.0021, 1, 0, 1, 1), -- 6Haunch of Meat
    (1537, 2963, 0.0021, 1, 0, 1, 1), -- 6Burnt Leather Boots
    (1537, 4666, 0.0021, 1, 0, 1, 1), -- 6Burnt Leather Belt
    (1537, 6513, 0.0021, 1, 0, 1, 1), -- 6Disciple's Sash
    (1537, 3173, 0.0021, 1, 0, 1, 1), -- 6Bear Meat
    (1537, 6515, 0.0021, 1, 0, 1, 1), -- 6Disciple's Gloves
    (1537, 9744, 0.0021, 1, 0, 1, 1), -- 6Simple Bands
    (1537, 9758, 0.0021, 1, 0, 1, 1), -- 6Cadet Belt
    (1537, 5363, 0.0021, 1, 0, 1, 1), -- 7Folded Handkerchief
    (1537, 5367, 0.0021, 1, 0, 1, 1), -- 7Primitive Rock Tool
    (1537, 6150, 0.0021, 1, 0, 1, 1), -- 7A Frayed Knot
    (1537, 6293, 0.0021, 1, 0, 1, 1), -- 7Dried Bat Blood
    (1537, 7101, 0.0021, 1, 0, 1, 1), -- 7Bug Eye
    (1537, 23333, 0.0021, 1, 0, 1, 1), -- 7Shattered Power Core
    (1537, 21015, 0.0021, 1, 0, 1, 1), -- 7Shoddy Chain Belt
    (1537, 21010, 0.0021, 1, 0, 1, 1), -- 7Scraggy Leather Boots
    (1537, 21007, 0.0021, 1, 0, 1, 1), -- 7Unkempt Robe
    (1537, 21018, 0.0021, 1, 0, 1, 1), -- 7Shoddy Chain Gloves
    (1537, 21003, 0.0021, 1, 0, 1, 1), -- 7Unkempt Bracers
    (1537, 21009, 0.0021, 1, 0, 1, 1), -- 7Scraggy Leather Belt
    (1537, 21014, 0.0021, 1, 0, 1, 1); -- 7Scraggy Leather Vest
     
       
    -- Data mined from www.wowhead.com
    -- Generated by Loot.php November 29, 2012 by Maibenrai
    --  http://www.wowhead.com/npc=1536
    DELETE FROM `creature_loot_template` WHERE `entry` = 1536;
    INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
    (1536, 2589, 28.2998, 1, 0, 1, 1), -- 6Linen Cloth
    (1536, 52077, 8.7924, 1, 0, 1, 1), -- 6Urgent Scarlet Memorandum
    (1536, 2070, 2.4482, 1, 0, 1, 1), -- 6Darnassian Bleu
    (1536, 2875, -1.3307, 1, 0, 1, 1), -- 6Scarlet Insignia Ring
    (1536, 159, 1.3247, 1, 0, 1, 1), -- 6Refreshing Spring Water
    (1536, 118, 0.7750, 1, 0, 1, 1), -- 6Minor Healing Potion
    (1536, 774, 0.7239, 1, 0, 1, 1), -- 5Malachite
    (1536, 3370, 0.3454, 1, 0, 1, 1), -- 7Patchwork Belt
    (1536, 1417, 0.3304, 1, 0, 1, 1), -- 7Beaten Battle Axe
    (1536, 2138, 0.3184, 1, 0, 1, 1), -- 7Sharpened Letter Opener
    (1536, 8177, 0.2794, 1, 0, 1, 1), -- 6Practice Sword
    (1536, 1413, 0.2794, 1, 0, 1, 1), -- 7Feeble Sword
    (1536, 1412, 0.2643, 1, 0, 1, 1), -- 7Crude Bastard Sword
    (1536, 1414, 0.2643, 1, 0, 1, 1), -- 7Cracked Sledge
    (1536, 1433, 0.2613, 1, 0, 1, 1), -- 7Patchwork Armor
    (1536, 1431, 0.2523, 1, 0, 1, 1), -- 7Patchwork Pants
    (1536, 1415, 0.2493, 1, 0, 1, 1), -- 7Carpenter's Mallet
    (1536, 818, 0.2403, 1, 0, 1, 1), -- 5Tigerseye
    (1536, 2774, 0.2343, 1, 0, 1, 1), -- 7Rust-Covered Blunderbuss
    (1536, 1422, 0.2253, 1, 0, 1, 1), -- 7Worn Leather Gloves
    (1536, 1420, 0.2193, 1, 0, 1, 1), -- 7Worn Leather Bracers
    (1536, 1430, 0.2163, 1, 0, 1, 1), -- 7Patchwork Gloves
    (1536, 1411, 0.2163, 1, 0, 1, 1), -- 7Withered Staff
    (1536, 8182, 0.2133, 1, 0, 1, 1), -- 6Pellet Rifle
    (1536, 1416, 0.2103, 1, 0, 1, 1), -- 7Rusty Hatchet
    (1536, 1427, 0.2103, 1, 0, 1, 1), -- 7Patchwork Shoes
    (1536, 2773, 0.2043, 1, 0, 1, 1), -- 7Cracked Shortbow
    (1536, 1429, 0.2013, 1, 0, 1, 1), -- 7Patchwork Cloak
    (1536, 1418, 0.2013, 1, 0, 1, 1), -- 7Worn Leather Belt
    (1536, 2646, 0.2013, 1, 0, 1, 1), -- 7Loose Chain Pants
    (1536, 1419, 0.1832, 1, 0, 1, 1), -- 7Worn Leather Boots
    (1536, 3189, 0.1802, 1, 0, 1, 1), -- 6Wood Chopper
    (1536, 2648, 0.1712, 1, 0, 1, 1), -- 7Loose Chain Vest
    (1536, 1423, 0.1682, 1, 0, 1, 1), -- 7Worn Leather Pants
    (1536, 2635, 0.1682, 1, 0, 1, 1), -- 7Loose Chain Belt
    (1536, 2642, 0.1652, 1, 0, 1, 1), -- 7Loose Chain Boots
    (1536, 766, 0.1562, 1, 0, 1, 1), -- 6Flanged Mace
    (1536, 3190, 0.1562, 1, 0, 1, 1), -- 6Beatstick
    (1536, 2643, 0.1562, 1, 0, 1, 1), -- 7Loose Chain Bracers
    (1536, 2212, 0.1502, 1, 0, 1, 1), -- 7Cracked Buckler
    (1536, 2213, 0.1502, 1, 0, 1, 1), -- 7Worn Large Shield
    (1536, 767, 0.1442, 1, 0, 1, 1), -- 6Long Bo Staff
    (1536, 3265, -0.1382, 1, 0, 1, 1), -- 6Scavenger Paw
    (1536, 2645, 0.1382, 1, 0, 1, 1), -- 7Loose Chain Gloves
    (1536, 3373, 0.1352, 1, 0, 1, 1), -- 7Patchwork Bracers
    (1536, 8181, 0.1202, 1, 0, 1, 1), -- 6Hunting Rifle
    (1536, 1425, 0.1051, 1, 0, 1, 1), -- 7Worn Leather Vest
    (1536, 3264, -0.0991, 1, 0, 1, 1), -- 6Duskbat Wing
    (1536, 727, 0.0901, 1, 0, 1, 1), -- 5Notched Shortsword
    (1536, 3609, 0.0871, 1, 0, 1, 1), -- 5Plans: Copper Chain Vest
    (1536, 4561, 0.0841, 1, 0, 1, 1), -- 5Scalping Tomahawk
    (1536, 4563, 0.0781, 1, 0, 1, 1), -- 6Billy Club
    (1536, 2855, -0.0751, 1, 0, 1, 1), -- 6Putrid Claw
    (1536, 2598, 0.0721, 1, 0, 1, 1), -- 5Pattern: Red Linen Robe
    (1536, 8178, 0.0691, 1, 0, 1, 1), -- 5Training Sword
    (1536, 768, 0.0631, 1, 0, 1, 1), -- 6Lumberjack Axe
    (1536, 5571, 0.0601, 1, 0, 1, 1), -- 6Small Black Pouch
    (1536, 8179, 0.0571, 1, 0, 1, 1), -- 6Cadet's Bow
    (1536, 62328, 0.0541, 1, 0, 1, 1), -- 7Shed Fur
    (1536, 828, 0.0511, 1, 0, 1, 1), -- 6Small Blue Pouch
    (1536, 4562, 0.0481, 1, 0, 1, 1), -- 5Severing Axe
    (1536, 4560, 0.0481, 1, 0, 1, 1), -- 6Fine Scimitar
    (1536, 4565, 0.0481, 1, 0, 1, 1), -- 6Simple Dagger
    (1536, 805, 0.0451, 1, 0, 1, 1), -- 6Small Red Pouch
    (1536, 12223, 0.0391, 1, 0, 1, 1), -- 6Meaty Bat Wing
    (1536, 5572, 0.0330, 1, 0, 1, 1), -- 6Small Green Pouch
    (1536, 2876, -0.024, 1, 0, 1, 1), -- 6Duskbat Pelt
    (1536, 4496, 0.0240, 1, 0, 1, 1), -- 6Small Brown Pouch
    (1536, 52079, 0.0240, 1, 0, 1, 1), -- 6A Scarlet Letter
    (1536, 7074, 0.0240, 1, 0, 1, 1), -- 7Chipped Claw
    (1536, 5523, 0.0210, 1, 0, 1, 1), -- 6Small Barnacled Clam
    (1536, 20482, -0.018, 1, 0, 1, 1), -- 6Arcane Sliver
    (1536, 1468, 0.0180, 1, 0, 1, 1), -- 6Murloc Fin
    (1536, 1421, 0.0180, 1, 0, 1, 1), -- 7Worn Hide Cloak
    (1536, 8180, 0.0150, 1, 0, 1, 1), -- 5Hunting Bow
    (1536, 4408, 0.0150, 1, 0, 1, 1), -- 5Schematic: Mechanical Squirrel Box
    (1536, 2644, 0.0150, 1, 0, 1, 1), -- 7Loose Chain Cloak
    (1536, 3299, 0.0120, 1, 0, 1, 1), -- 7Fractured Canine
    (1536, 2140, 0.0090, 1, 0, 1, 1), -- 5Carving Knife
    (1536, 2407, 0.0090, 1, 0, 1, 1), -- 5Pattern: White Leather Jerkin
    (1536, 2408, 0.0090, 1, 0, 1, 1), -- 5Pattern: Fine Leather Gloves
    (1536, 2858, -0.009, 1, 0, 1, 1), -- 6Darkhound Blood
    (1536, 4540, 0.0090, 1, 0, 1, 1), -- 6Tough Hunk of Bread
    (1536, 4604, 0.0090, 1, 0, 1, 1), -- 6Forest Mushroom Cap
    (1536, 3300, 0.0090, 1, 0, 1, 1), -- 7Rabbit's Foot
    (1536, 2553, 0.0060, 1, 0, 1, 1), -- 5Recipe: Elixir of Minor Agility
    (1536, 6271, 0.0060, 1, 0, 1, 1), -- 5Pattern: Red Linen Vest
    (1536, 4888, -0.006, 1, 0, 1, 1), -- 6Crawler Mucus
    (1536, 20799, -0.006, 1, 0, 1, 1), -- 6Felendren's Head
    (1536, 21808, -0.006, 1, 0, 1, 1), -- 6Arcane Core
    (1536, 6303, 0.0060, 1, 0, 1, 1), -- 6Raw Slitherskin Mackerel
    (1536, 68744, 0.0030, 1, 0, 1, 1), -- 5Imbued Pioneer Cloak
    (1536, 2834, -0.003, 1, 0, 1, 1), -- 6Embalming Ichor
    (1536, 4862, -0.003, 1, 0, 1, 1), -- 6Scorpid Worker Tail
    (1536, 17056, 0.0030, 1, 0, 1, 1), -- 6Light Feather
    (1536, 62505, -0.003, 1, 0, 1, 1), -- 6Bat Eye
    (1536, 2287, 0.0030, 1, 0, 1, 1), -- 6Haunch of Meat
    (1536, 2967, 0.0030, 1, 0, 1, 1), -- 6Warrior's Boots
    (1536, 67229, 0.0030, 1, 0, 1, 1), -- 6Stag Flank
    (1536, 4757, 0.0030, 1, 0, 1, 1), -- 7Cracked Egg Shells
    (1536, 5367, 0.0030, 1, 0, 1, 1), -- 7Primitive Rock Tool
    (1536, 6293, 0.0030, 1, 0, 1, 1), -- 7Dried Bat Blood
    (1536, 6296, 0.0030, 1, 0, 1, 1), -- 7Patch of Bat Hair
    (1536, 20813, 0.0030, 1, 0, 1, 1), -- 7Lynx Tooth
    (1536, 20846, 0.0030, 1, 0, 1, 1), -- 7Faintly Glowing Eye
    (1536, 20848, 0.0030, 1, 0, 1, 1), -- 7Sparkling Dust
    (1536, 23333, 0.0030, 1, 0, 1, 1), -- 7Shattered Power Core
    (1536, 62514, 0.0030, 1, 0, 1, 1), -- 7Cracked Pincer
    (1536, 21008, 0.0030, 1, 0, 1, 1), -- 7Unkempt Shoes
    (1536, 21011, 0.0030, 1, 0, 1, 1), -- 7Scraggy Leather Bracers
    (1536, 21014, 0.0030, 1, 0, 1, 1), -- 7Scraggy Leather Vest
    (1536, 21016, 0.0030, 1, 0, 1, 1); -- 7Shoddy Chain Vest
     
    DELETE FROM `creature_questrelation` WHERE `quest` = 24992;
    INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (1515, 24992);
    UPDATE `quest_template` SET `PrevQuestId` = 24981 WHERE `Id` = 24992;
     
    UPDATE `quest_template` SET `SourceSpellId` = 73162 WHERE `Id` = 24993;
    UPDATE `creature_template` SET `minlevel` = 7, `maxlevel` = 8, `faction_A` = 7, `faction_H` = 7 WHERE `entry` = 38967;
    DELETE FROM `creature_template_addon` WHERE (`entry`=38967);
    INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (38967, 0, 0, 196608, 1, 0, '32615 73167');
    update creature set spawndist=20 , movementtype=1 WHERE id=38967;
     
    DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND SourceEntry=73133;
    INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`) VALUES ('13', '1', '73133', '31', '3', '38937');
     
    -- Vile Fin Tadpole
    SET @ENTRY := 38937;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,10,0,100,0,1,15,0,0,80,3893700,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"on los do calltimeaction");
     
    -- Vile Fin Tadpole
    SET @ENTRY := 3893700;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,0,0,0,0,86,73133,0,21,15,0,0,21,15,0,0,0.0,0.0,0.0,0.0,"Make player cast fear on tadpole"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,5000,5000,5000,5000,11,85751,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"cast 85751 on self after 5 sec"),
    (@ENTRY,@SOURCETYPE,2,0,0,0,100,0,0,0,0,0,33,38937,0,0,0,0,0,17,0,40,0,0.0,0.0,0.0,0.0,"give credit to player"),
    (@ENTRY,@SOURCETYPE,3,0,0,0,100,0,3000,3000,3000,3000,41,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"despawn self");
     
    -- 85751, 73133
     
     
    DELETE FROM `creature_loot_template` WHERE `entry` = 1753;
    INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
    (1753, 3635, -91.9803, 1, 0, 1, 1), -- 6Maggot Eye's Paw
    (1753, 2589, 32.5821, 1, 0, 1, 1), -- 6Linen Cloth
    (1753, 117, 2.9849, 1, 0, 1, 1), -- 6Tough Jerky
    (1753, 159, 1.4625, 1, 0, 1, 1), -- 6Refreshing Spring Water
    (1753, 118, 0.8751, 1, 0, 1, 1), -- 6Minor Healing Potion
    (1753, 774, 0.7672, 1, 0, 1, 1), -- 5Malachite
    (1753, 2138, 0.4435, 1, 0, 1, 1), -- 7Sharpened Letter Opener
    (1753, 3189, 0.4076, 1, 0, 1, 1), -- 6Wood Chopper
    (1753, 1411, 0.3956, 1, 0, 1, 1), -- 7Withered Staff
    (1753, 2774, 0.3836, 1, 0, 1, 1), -- 7Rust-Covered Blunderbuss
    (1753, 1418, 0.3476, 1, 0, 1, 1), -- 7Worn Leather Belt
    (1753, 3190, 0.3237, 1, 0, 1, 1), -- 6Beatstick
    (1753, 1423, 0.3237, 1, 0, 1, 1), -- 7Worn Leather Pants
    (1753, 2645, 0.2997, 1, 0, 1, 1), -- 7Loose Chain Gloves
    (1753, 3373, 0.2877, 1, 0, 1, 1), -- 7Patchwork Bracers
    (1753, 1429, 0.2757, 1, 0, 1, 1), -- 7Patchwork Cloak
    (1753, 1433, 0.2757, 1, 0, 1, 1), -- 7Patchwork Armor
    (1753, 1413, 0.2757, 1, 0, 1, 1), -- 7Feeble Sword
    (1753, 1416, 0.2757, 1, 0, 1, 1), -- 7Rusty Hatchet
    (1753, 2212, 0.2517, 1, 0, 1, 1), -- 7Cracked Buckler
    (1753, 1417, 0.2517, 1, 0, 1, 1), -- 7Beaten Battle Axe
    (1753, 2773, 0.2517, 1, 0, 1, 1), -- 7Cracked Shortbow
    (1753, 1415, 0.2517, 1, 0, 1, 1), -- 7Carpenter's Mallet
    (1753, 1431, 0.2398, 1, 0, 1, 1), -- 7Patchwork Pants
    (1753, 1422, 0.2278, 1, 0, 1, 1), -- 7Worn Leather Gloves
    (1753, 1414, 0.2278, 1, 0, 1, 1), -- 7Cracked Sledge
    (1753, 1425, 0.2158, 1, 0, 1, 1), -- 7Worn Leather Vest
    (1753, 767, 0.2038, 1, 0, 1, 1), -- 6Long Bo Staff
    (1753, 3370, 0.2038, 1, 0, 1, 1), -- 7Patchwork Belt
    (1753, 8182, 0.1798, 1, 0, 1, 1), -- 6Pellet Rifle
    (1753, 1412, 0.1798, 1, 0, 1, 1), -- 7Crude Bastard Sword
    (1753, 2646, 0.1798, 1, 0, 1, 1), -- 7Loose Chain Pants
    (1753, 1430, 0.1678, 1, 0, 1, 1), -- 7Patchwork Gloves
    (1753, 2213, 0.1678, 1, 0, 1, 1), -- 7Worn Large Shield
    (1753, 3609, 0.1558, 1, 0, 1, 1), -- 5Plans: Copper Chain Vest
    (1753, 828, 0.1558, 1, 0, 1, 1), -- 6Small Blue Pouch
    (1753, 766, 0.1558, 1, 0, 1, 1), -- 6Flanged Mace
    (1753, 2643, 0.1558, 1, 0, 1, 1), -- 7Loose Chain Bracers
    (1753, 4563, 0.1439, 1, 0, 1, 1), -- 6Billy Club
    (1753, 1419, 0.1439, 1, 0, 1, 1), -- 7Worn Leather Boots
    (1753, 2140, 0.1319, 1, 0, 1, 1), -- 5Carving Knife
    (1753, 8177, 0.1199, 1, 0, 1, 1), -- 6Practice Sword
    (1753, 8178, 0.1079, 1, 0, 1, 1), -- 5Training Sword
    (1753, 8180, 0.1079, 1, 0, 1, 1), -- 5Hunting Bow
    (1753, 2642, 0.1079, 1, 0, 1, 1), -- 7Loose Chain Boots
    (1753, 1427, 0.1079, 1, 0, 1, 1), -- 7Patchwork Shoes
    (1753, 2648, 0.1079, 1, 0, 1, 1), -- 7Loose Chain Vest
    (1753, 4604, 0.0959, 1, 0, 1, 1), -- 6Forest Mushroom Cap
    (1753, 2635, 0.0959, 1, 0, 1, 1), -- 7Loose Chain Belt
    (1753, 1420, 0.0959, 1, 0, 1, 1), -- 7Worn Leather Bracers
    (1753, 727, 0.0839, 1, 0, 1, 1), -- 5Notched Shortsword
    (1753, 4562, 0.0839, 1, 0, 1, 1), -- 5Severing Axe
    (1753, 4561, 0.0719, 1, 0, 1, 1), -- 5Scalping Tomahawk
    (1753, 768, 0.0719, 1, 0, 1, 1), -- 6Lumberjack Axe
    (1753, 8181, 0.0719, 1, 0, 1, 1), -- 6Hunting Rifle
    (1753, 2855, -0.0599, 1, 0, 1, 1), -- 6Putrid Claw
    (1753, 5571, 0.0599, 1, 0, 1, 1), -- 6Small Black Pouch
    (1753, 52079, 0.0480, 1, 0, 1, 1), -- 6A Scarlet Letter
    (1753, 5523, 0.0480, 1, 0, 1, 1), -- 6Small Barnacled Clam
    (1753, 62328, 0.0480, 1, 0, 1, 1), -- 7Shed Fur
    (1753, 2834, -0.036, 1, 0, 1, 1), -- 6Embalming Ichor
    (1753, 6515, 0.0360, 1, 0, 1, 1), -- 6Disciple's Gloves
    (1753, 7074, 0.0360, 1, 0, 1, 1), -- 7Chipped Claw
    (1753, 4408, 0.0240, 1, 0, 1, 1), -- 5Schematic: Mechanical Squirrel Box
    (1753, 3265, -0.024, 1, 0, 1, 1), -- 6Scavenger Paw
    (1753, 5572, 0.0240, 1, 0, 1, 1), -- 6Small Green Pouch
    (1753, 12223, 0.0240, 1, 0, 1, 1), -- 6Meaty Bat Wing
    (1753, 2967, 0.0240, 1, 0, 1, 1), -- 6Warrior's Boots
    (1753, 6506, 0.0240, 1, 0, 1, 1), -- 6Infantry Boots
    (1753, 1468, 0.0240, 1, 0, 1, 1), -- 6Murloc Fin
    (1753, 2598, 0.0120, 1, 0, 1, 1), -- 5Pattern: Red Linen Robe
    (1753, 68755, 0.0120, 1, 0, 1, 1), -- 5Imbued Disciple's Gloves
    (1753, 2553, 0.0120, 1, 0, 1, 1), -- 5Recipe: Elixir of Minor Agility
    (1753, 6271, 0.0120, 1, 0, 1, 1), -- 5Pattern: Red Linen Vest
    (1753, 4577, 0.0120, 1, 0, 1, 1), -- 5Compact Shotgun
    (1753, 3610, 0.0120, 1, 0, 1, 1), -- 5Plans: Gemmed Copper Gauntlets
    (1753, 2070, 0.0120, 1, 0, 1, 1), -- 6Darnassian Bleu
    (1753, 2858, -0.012, 1, 0, 1, 1), -- 6Darkhound Blood
    (1753, 2859, -0.012, 1, 0, 1, 1), -- 6Vile Fin Scale
    (1753, 805, 0.0120, 1, 0, 1, 1), -- 6Small Red Pouch
    (1753, 6303, 0.0120, 1, 0, 1, 1), -- 6Raw Slitherskin Mackerel
    (1753, 2960, 0.0120, 1, 0, 1, 1), -- 6Journeyman's Gloves
    (1753, 3329, 0.0120, 1, 0, 1, 1), -- 6Spiked Wooden Plank
    (1753, 9761, 0.0120, 1, 0, 1, 1), -- 6Cadet Cloak
    (1753, 1421, 0.0120, 1, 0, 1, 1); -- 7Worn Hide Cloak
     
    -- Nissa Agamand
    SET @ENTRY := 1655;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,4000,6000,12000,13000,11,28993,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Cast Banshee Wail"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,10000,12000,22000,26000,11,51897,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Cast Banshee Screech");
     
    -- Gregor Agamand
    SET @ENTRY := 1654;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,1,0,100,1,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Cast Birth on Spawn");
     
     
    DELETE FROM `creature` WHERE `id`=1654;
    INSERT INTO `creature` (`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
    (1654, 0, 85, 157, 1, 1, 646, 0, 2910.7, 382.547, 31.6674, 3.31613, 500, 0, 0, 198, 0, 0, 0, 0, 0);
     
     
    DELETE FROM `creature` WHERE `id`=1656;
    INSERT INTO `creature` (`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
    (1656, 0, 85, 157, 1, 1, 1196, 0, 2926.93, 956.907, 122.312, 0.92, 500, 0, 0, 198, 0, 0, 0, 0, 0);
     
     
    DELETE FROM `creature` WHERE `id`=1657;
    INSERT INTO `creature` (`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
    (1657, 0, 85, 157, 1, 1, 11399, 0, 2815.8, 821.38, 113.084, 1.44862, 500, 0, 0, 216, 178, 0, 0, 0, 0);
     
     
    DELETE FROM `creature` WHERE `id`=1499;
    INSERT INTO `creature` (`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
    (1499, 0, 85, 159, 1, 1, 3514, 0, 2316.92, 277.321, 45.0204, 5.1692, 500, 0, 0, 300, 0, 0, 0, 0, 0);
    UPDATE `gossip_menu_option` SET `option_id`='1', `npc_option_npcflag`='1' WHERE (`menu_id`='11156') AND (`id`='0');
    UPDATE `creature_template` SET `gossip_menu_id` = 11156 WHERE `entry` = 39117;
     
    DELETE FROM `creature` WHERE `id`=38980;
    DELETE FROM `creature` WHERE `id`=38981;
     
     
     
    -- Shadow Priestess Malia
    SET @ENTRY := 39117;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,1,62,0,100,0,11156,0,0,0,80,3911700,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"On gossip select do action"),
    (@ENTRY,@SOURCETYPE,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Close gossip"),
    (@ENTRY,@SOURCETYPE,2,3,38,0,100,0,0,1,0,0,69,0,0,0,0,0,0,8,0,0,0,2242.28,230.375,34.5098,0.383972,"on data set 1 return home"),
    (@ENTRY,@SOURCETYPE,3,0,61,0,100,0,0,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 5");
     
     
    -- Shadow Priestess Malia
    SET @ENTRY := 3911700;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 0 self"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,3000,3000,3000,3000,69,0,0,0,0,0,0,8,0,0,0,2243.89,228.23,41.81,6.099,"Move to pos"),
    (@ENTRY,@SOURCETYPE,2,0,0,0,100,0,13000,13000,13000,13000,1,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 1"),
    (@ENTRY,@SOURCETYPE,3,0,0,0,100,0,5000,5000,5000,5000,1,2,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 2"),
    (@ENTRY,@SOURCETYPE,4,0,0,0,100,0,5000,5000,5000,5000,1,3,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 3"),
    (@ENTRY,@SOURCETYPE,5,0,0,0,100,0,5000,5000,5000,5000,1,4,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 4"),
    (@ENTRY,@SOURCETYPE,6,0,0,0,100,0,4000,4000,4000,4000,12,38980,7,0,0,0,0,8,0,0,0,2247.06,227.57,43.37,1.92,"summon creature ");
     
     
    DELETE FROM creature_text WHERE entry =39117;
    INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
    (39117, 0, 0, 'Very well. Follow me.', 12, 0, 100, 0, 0, 0, ''),
    (39117, 1, 0, 'Now it is time for us to begin.', 12, 0, 100, 0, 0, 0, ''),
    (39117, 2, 0, 'Devlin Agamand! Listen to my voice!', 14, 0, 100, 22, 0, 0, ''),
    (39117, 3, 0, 'Your mortal remains have been gathered, here in this place WHERE you spent your childhood!', 14, 0, 100, 22, 0, 0, ''),
    (39117, 4, 0, 'Resist the Lich King''s will, Devlin! Come to us!', 14, 0, 100, 22, 0, 0, ''),
    (39117, 5, 0, 'I had better return to my post. You can find me downstairs if you need anything.', 12, 0, 100, 0, 0, 0, '');
     
     
    -- 39839
    -- 73180
     
     
     
     
    DELETE FROM `creature_template_addon` WHERE (`entry`=38980);
    INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (38980, 0, 0, 50331648, 1, 0, '');
     
    -- Spirit of Devlin Agamand
    SET @ENTRY := 38980;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,54,0,100,0,0,0,0,0,80,3898000,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"On summoned call time action");
     
    -- Spirit of Devlin Agamand
    SET @ENTRY := 3898000;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 0"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,3000,3000,3000,3000,1,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 1"),
    (@ENTRY,@SOURCETYPE,2,0,0,0,100,0,3000,3000,0,0,1,2,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 2"),
    (@ENTRY,@SOURCETYPE,3,0,0,0,100,0,3500,3500,0,0,1,3,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 3"),
    (@ENTRY,@SOURCETYPE,4,0,0,0,100,0,3500,3500,3500,3500,1,4,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 4"),
    (@ENTRY,@SOURCETYPE,5,0,0,0,100,0,3500,3500,3500,3500,11,39839,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"cast 39839 "),
    (@ENTRY,@SOURCETYPE,6,0,0,0,100,0,300,300,0,0,1,5,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 5"),
    (@ENTRY,@SOURCETYPE,7,0,0,0,100,0,3500,3500,0,0,1,6,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 6"),
    (@ENTRY,@SOURCETYPE,8,0,0,0,100,0,0,0,0,0,28,39839,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"remove aura on self"),
    (@ENTRY,@SOURCETYPE,9,0,0,0,100,0,0,0,0,0,3,0,8475,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"morph to model"),
    (@ENTRY,@SOURCETYPE,11,0,0,0,100,0,15000,15000,0,0,37,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"die self"),
    (@ENTRY,@SOURCETYPE,10,0,0,0,100,0,0,0,0,0,11,73180,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"cast 73180 self");
     
     
     
    DELETE FROM creature_text WHERE entry =38980;
    INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
    (38980, 0, 0, 'What''s going on here?', 12, 0, 100, 0, 0, 0, ''),
    (38980, 1, 0, 'Wait, am I... home?', 12, 0, 100, 0, 0, 0, ''),
    (38980, 2, 0, 'You people... what are you doing here? Why are you in my house?', 12, 0, 100, 0, 0, 0, ''),
    (38980, 3, 0, 'Mother... father... Thurman... WHERE are you?', 12, 0, 100, 0, 0, 0, ''),
    (38980, 4, 0, 'No... I remember. My family is dead. And so am I.', 12, 0, 100, 0, 0, 0, ''),
    (38980, 5, 0, 'And my soul.... my soul belongs to the Scourge!', 12, 0, 100, 0, 0, 0, ''),
    (38980, 6, 0, 'DIE, YOU WRETCHES!', 14, 0, 100, 0, 0, 0, '');
     
     
     
    -- Shadow of Agamand
    SET @ENTRY := 38981;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,2000,4500,12000,16000,11,31516,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Cast Mind Blast"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,6000,9000,18000,22000,11,16568,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Cast Mind Flay"),
    (@ENTRY,@SOURCETYPE,2,0,6,0,100,0,0,0,0,0,45,0,1,0,0,0,0,19,39117,30,0,0.0,0.0,0.0,0.0,"on death set data1 to 39117");
     
    UPDATE `creature_template` SET `minlevel` = 11, `maxlevel` = 11, `faction_A` = 974, `faction_H` = 974, `unit_flags` = 526848, `AIName` = '', `InhabitType` = 4 WHERE `entry` = 38981;
    DELETE FROM `creature` WHERE `id`=38983;
    UPDATE `creature_template` SET `scale` = 1 WHERE `entry` = 1554;
    UPDATE `creature_template` SET `unit_flags` = 537166084 WHERE `entry` = 39086;
     
    UPDATE `creature` SET `position_x` = '2533.339', `position_y` = '-920.6719', `position_z` = '60.98916', `orientation` = '4.537856' WHERE `guid` = 45457;
    DELETE FROM `creature_template_addon` WHERE (`entry`=38936);
    INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (38936, 0, 0, 50331648, 1, 0, 73443);
    UPDATE `creature_template` SET `npcflag` = 16777216, `VehicleId` = 659 WHERE `entry` = 38936;
    DELETE FROM `creature` WHERE `id`=13158;
     
     
    -- 73443
    -- 73444
    -- Lieutenant Sanders' Noose
    SET @ENTRY := 38936;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,60,0,100,1,1000,1000,1000,1000,11,73444,0,0,0,0,0,19,39093,100,0,0.0,0.0,0.0,0.0,"cast 73444 on 39093");
     
    DELETE FROM `vehicle_template_accessory` WHERE entry=38936 AND accessory_entry=13158;
    INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `description`) VALUES ('38936', '13158', 'Lieutenant sanders');
    DELETE FROM `npc_spellclick_spells` WHERE npc_entry=38936 AND spell_id=46598;
    INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`) VALUES ('38936', '46598', '0');
    UPDATE `creature_template` SET `InhabitType` = 4 WHERE `entry` = 38936;
     
    update creature set MovementType=0,spawndist=0 WHERE id=39086;
    update creature set MovementType=0,spawndist=0 WHERE id=39087;
    UPDATE `quest_template` SET `SourceSpellId` = 73306 WHERE `Id` = 25046;
     
     
     
     
     
    UPDATE `creature_template` SET `minlevel` = 10, `maxlevel` = 10, `faction_A` = 5, `faction_H` = 5, `mindmg` = 186, `maxdmg` = 191, `attackpower` = 191, `unit_class` = 2, `unit_flags` = 8 WHERE `entry` = 39038;
    DELETE FROM `creature_template_addon` WHERE (`entry`=39038);
    INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (39038, 0, 0, 0, 0, 0, 73304);
    UPDATE `creature_template` SET `VehicleId` = 665 WHERE `entry` = 1538;
    UPDATE `creature_template` SET `dynamicflags` = 0, `AIName` = 'SmartAI' WHERE `entry` = 1538;
    DELETE FROM `creature_template_addon` WHERE (`entry`=1538);
    UPDATE `creature_template` SET `VehicleId` = 665, `AIName` = 'SmartAI' WHERE `entry` = 1539;
    UPDATE `creature_template` SET `VehicleId` = 665, `AIName` = 'SmartAI' WHERE `entry` = 1540;
     
     
     
     
     
    -- Scarlet Friar
    SET @ENTRY := 1538;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,4,0,30,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Say Text on Aggro"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,1000,7000,8000,28000,11,12169,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Cast Shield Block"),
    (@ENTRY,@SOURCETYPE,2,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Flee at 15% HP"),
    (@ENTRY,@SOURCETYPE,3,0,2,0,100,1,0,15,0,0,1,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Say Text at 15% HP"),
    (@ENTRY,@SOURCETYPE,4,0,0,0,100,0,6000,9000,17000,20000,11,75967,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Cast Whirlwind"),
    (@ENTRY,@SOURCETYPE,5,0,8,0,100,0,73309,0,0,0,11,64431,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"on spellhit 73309 cast 64431");
     
    -- Scarlet Neophyte
    SET @ENTRY := 1539;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,4,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Set Phase 1 on Aggro"),
    (@ENTRY,@SOURCETYPE,1,0,4,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Stop Moving on Aggro"),
    (@ENTRY,@SOURCETYPE,2,0,4,1,100,1,0,0,0,0,11,13322,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Cast bolt on Aggro"),
    (@ENTRY,@SOURCETYPE,3,0,9,1,100,0,0,40,3400,4700,11,13322,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Cast bolt"),
    (@ENTRY,@SOURCETYPE,4,0,9,1,100,0,40,100,0,0,21,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Start Moving when not in bolt Range"),
    (@ENTRY,@SOURCETYPE,5,0,9,1,100,0,10,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Stop Moving at 15 Yards"),
    (@ENTRY,@SOURCETYPE,6,0,9,1,100,0,0,40,0,0,21,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Stop Moving when in bolt Range"),
    (@ENTRY,@SOURCETYPE,7,0,3,1,100,0,0,15,0,0,22,2,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Set Phase 2 at 15% Mana"),
    (@ENTRY,@SOURCETYPE,8,0,3,2,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Start Moving at 15% Mana"),
    (@ENTRY,@SOURCETYPE,9,0,3,2,100,0,30,100,100,100,22,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Set Phase 1 When Mana is above 30%"),
    (@ENTRY,@SOURCETYPE,10,0,2,2,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Set Phase 3 at 15% HP"),
    (@ENTRY,@SOURCETYPE,11,0,2,3,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Flee at 15% HP"),
    (@ENTRY,@SOURCETYPE,12,0,7,3,100,1,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Reset on Evade"),
    (@ENTRY,@SOURCETYPE,13,0,2,3,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Say Text at 15% HP"),
    (@ENTRY,@SOURCETYPE,14,0,4,0,30,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Say Text on Aggro"),
    (@ENTRY,@SOURCETYPE,15,0,1,0,100,0,500,1000,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Cast Frost Armor on Spawn"),
    (@ENTRY,@SOURCETYPE,16,0,8,0,100,0,73309,0,0,0,11,64431,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Type a script description here.");
     
    -- Scarlet Vanguard
    SET @ENTRY := 1540;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,4,0,30,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Say Text on Aggro"),
    (@ENTRY,@SOURCETYPE,1,0,4,0,100,1,0,0,0,0,11,7164,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Cast Defensive Stance on Aggro"),
    (@ENTRY,@SOURCETYPE,2,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Flee at 15% HP"),
    (@ENTRY,@SOURCETYPE,3,0,2,0,100,1,0,15,0,0,1,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Say Text at 15% HP"),
    (@ENTRY,@SOURCETYPE,4,0,13,0,100,0,2000,4500,20000,30000,11,11972,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Cast Shield Bash on Player Spell Cast"),
    (@ENTRY,@SOURCETYPE,5,0,8,0,100,0,73309,0,0,0,11,64431,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Type a script description here.");
     
     
    UPDATE `creature_template` SET `VehicleId` = 665 WHERE `entry` = 1660;
    DELETE FROM creature WHERE guid=4731;
     
    UPDATE `creature_template` SET `VehicleId` = 665 WHERE `entry` = 39097;
    UPDATE `creature_template` SET `VehicleId` = 665, `AIName` = 'SmartAI' WHERE `entry` = 1665;
     
    -- Lilian Voss
    SET @ENTRY := 39038;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,4000,4000,2000,9000,87,3903800,3903801,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"on aggro do random action"),
    (@ENTRY,@SOURCETYPE,1,0,1,0,100,1,2000,2000,2000,2000,11,73392,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"update ooc cast stealth"),
    (@ENTRY,@SOURCETYPE,2,5,38,0,100,0,0,1,0,0,80,3903802,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"data set 1 do actiontime"),
    (@ENTRY,@SOURCETYPE,3,0,25,0,100,0,0,0,0,0,29,0,0,0,0,0,0,23,0,0,0,0.0,0.0,0.0,0.0,"follow owner"),
    (@ENTRY,@SOURCETYPE,5,0,61,0,100,0,0,0,0,0,18,776,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"set unit flag");
     
    -- 73309 poigne de la mort
    -- 73308 saut
    -- 73307 explose cerveau
    -- 64431 death grip
    -- 73453
     
     
    -- Lilian Voss
    SET @ENTRY := 3903800;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,3000,3000,0,0,11,73309,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"cast 73309 on victime"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,3000,3000,0,0,51,0,0,0,0,0,0,9,0,0,15,0.0,0.0,0.0,0.0,"kill unit after 1 sec");
     
    -- Lilian Voss
    SET @ENTRY := 3903801;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,2000,2000,0,0,11,46598,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"enter vehicle"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,0,0,0,0,51,0,0,0,0,0,0,9,0,0,5,0.0,0.0,0.0,0.0,"kill unit");
     
     
    DELETE FROM `creature_template` WHERE (`entry`=144952);
    INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES (144952, 0, 0, 0, 0, 0, 16480, 16480, 16480, 16480, 'Invisible Trigger One', '', '', 0, 1, 1, 0, 35, 35, 0, 0.91, 1.14286, 1, 0, 1007, 1354.7, 0, 1571, 1, 2000, 2200, 1, 0, 2048, 8, 0, 0, 0, 0, 0, 758.1, 1062.1, 220, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 128, '', 12340);
    -- Invisible Trigger One
    SET @ENTRY := 144952;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,60,0,100,0,3000,3000,3000,3000,45,0,1,0,0,0,0,19,39038,5,0,0.0,0.0,0.0,0.0,"send data 1 to 39038");
     
     
    -- Lilian Voss
    SET @ENTRY := 3903802;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,3073.76,-555.71,126.72,0.08,"Move to pos"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 0"),
    (@ENTRY,@SOURCETYPE,2,0,0,0,100,0,0,0,0,0,2,35,0,0,0,0,0,10,4730,1660,0,0.0,0.0,0.0,0.0,"change faction to 35"),
    (@ENTRY,@SOURCETYPE,3,0,0,0,100,0,0,0,0,0,2,35,0,0,0,0,0,10,4732,1665,0,0.0,0.0,0.0,0.0,"change faction to 35"),
    (@ENTRY,@SOURCETYPE,4,0,0,0,100,0,0,0,0,0,2,35,0,0,0,0,0,10,46305,39097,0,0.0,0.0,0.0,0.0,"change faction to 35"),
    (@ENTRY,@SOURCETYPE,5,0,0,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,46305,39097,0,0.0,0.0,0.0,0.0,"set data 1 to high priest"),
    (@ENTRY,@SOURCETYPE,6,0,0,0,100,0,5000,5000,5000,5000,1,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 1 self"),
    (@ENTRY,@SOURCETYPE,7,0,0,0,100,0,1000,1000,1000,1000,11,46598,0,0,0,0,0,10,4732,1665,0,0.0,0.0,0.0,0.0,"jump on closest"),
    (@ENTRY,@SOURCETYPE,8,0,0,0,100,0,500,500,0,0,51,0,0,0,0,0,0,10,4732,1665,0,0.0,0.0,0.0,0.0,"after kill it"),
    (@ENTRY,@SOURCETYPE,9,0,0,0,100,0,1000,1000,0,0,11,46598,0,0,0,0,0,10,4730,1660,0,0.0,0.0,0.0,0.0,"jump on the other one"),
    (@ENTRY,@SOURCETYPE,10,0,0,0,100,0,500,500,0,0,51,0,0,0,0,0,0,10,4730,1660,0,0.0,0.0,0.0,0.0,"Kill it"),
    (@ENTRY,@SOURCETYPE,11,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 2 self"),
    (@ENTRY,@SOURCETYPE,12,0,0,0,100,0,5000,5000,0,0,1,3,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 3"),
    (@ENTRY,@SOURCETYPE,13,0,0,0,100,0,5000,5000,0,0,1,4,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 4"),
    (@ENTRY,@SOURCETYPE,14,0,0,0,100,0,0,0,0,0,11,46598,0,0,0,0,0,10,46305,39097,0,0.0,0.0,0.0,0.0,"jump on guid 46598"),
    (@ENTRY,@SOURCETYPE,15,0,0,0,100,0,0,0,0,0,33,39098,0,0,0,0,0,23,0,0,0,0.0,0.0,0.0,0.0,"give credit to owner"),
    (@ENTRY,@SOURCETYPE,16,0,0,0,100,0,1000,1000,1000,1000,51,0,0,0,0,0,0,10,46305,39097,0,0.0,0.0,0.0,0.0,"kill unit"),
    (@ENTRY,@SOURCETYPE,17,0,0,0,100,0,10000,10000,0,0,37,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"die self after");
     
    -- High Priest Benedictus Voss
    SET @ENTRY := 3909700;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,1000,1000,1000,1000,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 0"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,9000,9000,9000,9000,1,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 1"),
    (@ENTRY,@SOURCETYPE,2,0,0,0,100,0,10000,10000,10000,10000,1,2,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 2");
     
     
    -- High Priest Benedictus Voss
    SET @ENTRY := 39097;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,38,0,100,0,0,1,0,0,80,3909700,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"on data set 1 do action");
     
    DELETE FROM creature_text WHERE entry=39038;
    INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
    (39038, 0, 0, 'Father!', 12, 0, 100, 0, 0, 0, ''),
    (39038, 1, 0, 'Shut up.', 12, 0, 100, 0, 0, 0, ''),
    (39038, 2, 0, 'You raised me to be a killer. How am I doing, daddy?', 12, 0, 100, 0, 0, 0, ''),
    (39038, 3, 0, 'But wait... I remember now. You taught me to only kill the undead. So you do want me to kill myself, daddy?', 12, 0, 100, 0, 0, 0, ''),
    (39038, 4, 0, 'Then again, why kill myself... when I can kill YOU instead!', 12, 0, 100, 0, 0, 0, '');

    DELETE FROM creature_text WHERE entry=39097;
    INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
    (39097, 0, 0, 'Lilian... you''re... it''s so nice to see you well.', 12, 0, 100, 0, 0, 0, ''),
    (39097, 1, 0, 'I, ah...', 12, 0, 100, 0, 0, 0, ''),
    (39097, 2, 0, 'Lilian, I...', 12, 0, 100, 0, 0, 0, '');
     
    DELETE FROM `creature` WHERE `id`=144952;
    INSERT INTO `creature` (`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
    (144952, 0, 85, 459, 1, 65535, 0, 0, 3038.11, -559.181, 121.427, 3.21225, 300, 0, 0, 42, 0, 0, 0, 33554432, 0);
     
     
    DELETE FROM `creature` WHERE `id`=1540;
    INSERT INTO `creature` (`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
    (1540, 0, 85, 459, 1, 1, 2481, 0, 2791.81, -473.694, 101.753, 1.25664, 500, 0, 0, 198, 0, 0, 0, 0, 0),
    (1540, 0, 85, 459, 1, 1, 2481, 0, 2750.31, -521.581, 106.324, 2.35619, 500, 0, 0, 198, 0, 0, 0, 0, 0),
    (1540, 0, 85, 459, 1, 1, 2470, 0, 2769.89, -485.563, 107.248, 3.78736, 500, 0, 0, 198, 0, 0, 0, 0, 0),
    (1540, 0, 85, 459, 1, 1, 2470, 0, 2848.74, -511.46, 106.835, 5.12463, 500, 0, 0, 198, 0, 0, 0, 0, 0),
    (1540, 0, 85, 459, 1, 1, 2470, 0, 2943.75, -554.264, 109.317, 3.22052, 500, 0, 0, 198, 0, 0, 0, 0, 0),
    (1540, 0, 85, 459, 1, 1, 2481, 0, 2870.57, -497.285, 101.174, 5.39186, 500, 0, 0, 198, 0, 0, 0, 0, 0),
    (1540, 0, 85, 459, 1, 1, 2470, 0, 3101.32, -548.31, 126.898, 0.925025, 500, 0, 0, 198, 0, 0, 0, 0, 0),
    (1540, 0, 85, 459, 1, 1, 2470, 0, 2849.83, -475.367, 99.6665, 1.67552, 500, 0, 0, 198, 0, 0, 0, 0, 0),
    (1540, 0, 85, 459, 1, 1, 2481, 0, 2792.01, -487.446, 101.4, 5.79449, 500, 0, 0, 198, 0, 0, 0, 0, 0),
    (1540, 0, 85, 459, 1, 1, 2481, 0, 3006.29, -538.512, 116.235, 5.79449, 500, 0, 0, 198, 0, 0, 0, 0, 0),
    (1540, 0, 85, 459, 1, 1, 2481, 0, 2923.53, -562.806, 109.015, 1.67552, 500, 0, 0, 198, 0, 0, 0, 0, 0),
    (1540, 0, 85, 459, 1, 1, 2481, 0, 2848.48, -507.172, 107.063, 2.04204, 500, 0, 0, 198, 0, 0, 0, 0, 0),
    (1540, 0, 85, 459, 1, 1, 2481, 0, 2850, -531.182, 108.825, 5.79449, 500, 0, 0, 222, 0, 0, 0, 0, 0),
    (1540, 0, 85, 459, 1, 1, 2470, 0, 2957.23, -553.232, 110.077, 3.32014, 500, 0, 0, 198, 0, 0, 0, 0, 0),
    (1540, 0, 85, 459, 1, 1, 2481, 0, 2880.77, -525.427, 105.685, 4.2237, 500, 0, 0, 198, 0, 0, 0, 0, 0),
    (1540, 0, 85, 459, 1, 1, 2470, 0, 2990.25, -527.663, 111.274, 5.79449, 500, 0, 0, 222, 0, 0, 0, 0, 0),
    (1540, 0, 85, 459, 1, 1, 2470, 0, 2827.28, -496.497, 101.523, 1.67552, 500, 0, 0, 222, 0, 0, 0, 0, 0),
    (1540, 0, 85, 459, 1, 1, 2470, 0, 3019.89, -560.585, 118.777, 5.79449, 500, 0, 0, 198, 0, 0, 0, 0, 0),
    (1540, 0, 85, 459, 1, 1, 2470, 0, 2892.33, -533.336, 106.112, 3.90954, 500, 0, 0, 222, 0, 0, 0, 0, 0),
    (1540, 0, 85, 459, 1, 1, 2481, 0, 2761.21, -484.215, 104.69, 5.79449, 500, 0, 0, 222, 0, 0, 0, 0, 0),
    (1540, 0, 85, 459, 1, 1, 2470, 0, 2994.17, -558.007, 116.411, 1.67552, 500, 0, 0, 198, 0, 0, 0, 0, 0),
    (1540, 0, 85, 459, 1, 1, 2470, 0, 3119.52, -573.777, 128.942, 0.680678, 500, 0, 0, 222, 0, 0, 0, 0, 0);
    DELETE FROM `creature` WHERE `id`=1538;
    INSERT INTO `creature` (`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
    (1538, 0, 85, 459, 1, 1, 2466, 0, 2750.02, -531.186, 104.635, 2.79253, 120, 0, 0, 166, 178, 0, 0, 0, 0),
    (1538, 0, 85, 167, 1, 1, 2477, 0, 2149.27, -513.366, 81.8476, 2.1293, 120, 0, 0, 166, 178, 0, 0, 0, 0),
    (1538, 0, 85, 167, 1, 1, 2466, 0, 2143.29, -554.631, 81.5568, 5.79449, 120, 0, 0, 166, 178, 0, 0, 0, 0),
    (1538, 0, 85, 167, 1, 1, 2477, 0, 2165.17, -556.663, 79.3422, 5.44543, 120, 0, 0, 166, 178, 0, 0, 0, 0),
    (1538, 0, 85, 459, 1, 1, 2466, 0, 2896.56, -537.532, 106.566, 3.24631, 120, 0, 0, 166, 178, 0, 0, 0, 0),
    (1538, 0, 85, 167, 1, 1, 2466, 0, 2169.06, -520.564, 81.5963, 4.86947, 120, 0, 0, 166, 178, 0, 0, 0, 0),
    (1538, 0, 85, 167, 1, 1, 2477, 0, 2143.57, -529.984, 81.7805, 5.60251, 120, 0, 0, 166, 178, 0, 0, 0, 0),
    (1538, 0, 85, 165, 1, 1, 2477, 0, 2113.39, -405.729, 71.3364, 3.102, 120, 0, 0, 166, 178, 0, 0, 0, 0),
    (1538, 0, 85, 167, 1, 1, 2466, 0, 2142.8, -505.647, 81.7233, 1.98477, 120, 0, 0, 166, 178, 0, 0, 0, 0),
    (1538, 0, 85, 167, 1, 1, 2466, 0, 2184.19, -450.619, 75.4925, 2.49582, 120, 0, 0, 166, 178, 0, 0, 0, 0),
    (1538, 0, 85, 167, 1, 1, 2466, 0, 2123.34, -632.033, 93.5874, 5.07891, 120, 0, 0, 166, 178, 0, 0, 0, 0),
    (1538, 0, 85, 167, 1, 1, 2466, 0, 2177.13, -610.977, 80.7263, 5.22851, 120, 0, 0, 166, 178, 0, 0, 0, 0),
    (1538, 0, 85, 167, 1, 1, 2466, 0, 2112.78, -625.056, 93.5988, 3.4383, 120, 0, 0, 166, 178, 0, 0, 0, 0),
    (1538, 0, 85, 459, 1, 1, 2477, 0, 3097.16, -552.221, 126.705, 2.99377, 120, 0, 0, 166, 178, 0, 0, 0, 0),
    (1538, 0, 85, 4918, 1, 1, 2466, 0, 2550.38, -905.022, 56.928, 0.959931, 120, 0, 0, 166, 178, 0, 0, 0, 0),
    (1538, 0, 85, 4918, 1, 1, 2466, 0, 2484.22, -879.037, 60.3536, 0.033223, 120, 0, 0, 166, 178, 0, 0, 0, 0),
    (1538, 0, 85, 167, 1, 1, 2477, 0, 2237.77, -653.93, 78.261, 2.04207, 120, 0, 0, 166, 178, 0, 0, 0, 0),
    (1538, 0, 85, 4918, 1, 1, 2477, 0, 2528.36, -904.647, 57.0912, 0.977384, 120, 0, 0, 166, 178, 0, 0, 0, 0),
    (1538, 0, 85, 4918, 1, 1, 2466, 0, 2517.75, -898.981, 56.1185, 1.98968, 120, 0, 0, 166, 178, 0, 0, 0, 0),
    (1538, 0, 85, 4918, 1, 1, 2477, 0, 2540.38, -886.911, 55.5066, 4.88814, 120, 0, 0, 166, 178, 0, 0, 0, 0),
    (1538, 0, 85, 4918, 1, 1, 2477, 0, 2563.66, -895.477, 55.6279, 2.46091, 120, 0, 0, 166, 178, 0, 0, 0, 0),
    (1538, 0, 85, 167, 1, 1, 2477, 0, 2147.25, -641.061, 94.1245, 4.4855, 120, 0, 0, 186, 191, 0, 0, 0, 0),
    (1538, 0, 85, 459, 1, 1, 2477, 0, 2814.89, -511.951, 104.53, 0.872665, 120, 0, 0, 166, 178, 0, 0, 0, 0),
    (1538, 0, 85, 459, 1, 1, 2466, 0, 2956.95, -562.66, 110.595, 1.36136, 120, 0, 0, 166, 178, 0, 0, 0, 0),
    (1538, 0, 85, 459, 1, 1, 2477, 0, 2985.34, -533.891, 111.998, 5.3058, 120, 0, 0, 166, 178, 0, 0, 0, 0),
    (1538, 0, 85, 459, 1, 1, 2477, 0, 2924.75, -542.059, 108.463, 5.3058, 120, 0, 0, 186, 191, 0, 0, 0, 0),
    (1538, 0, 85, 459, 1, 1, 2477, 0, 3026.9, -563.031, 119.64, 2.89725, 120, 0, 0, 186, 191, 0, 0, 0, 0);
     
    -- SilverPine Forest
     
    /*
     Quest progression
     
    Optional breadcrumb: H [10] Warchief's Command: Silverpine Forest!
     
        H [11] The Warchief Cometh
        H [11] Guts and Gore
     
            Side quests: H [11] The Gilneas Liberation Front / H [11] Agony Abounds
     
        H [11] Iterating Upon Success
        H [11] Dangerous Intentions
        H [11] Waiting to Exsanguinate
        H [11] Belmont's Report
        H [11] The Warchief's Fleet
        H [11] Steel Thunder & H [11] Give 'em Hell!
     
            Side quest chain:
                H [11] Playing Dirty
                H [11] It's Only Poisonous if You Ingest It
     
        H [11] Lost in the Darkness
            H [11] Skitterweb Menace
            H [11] Deeper into Darkness
        H [11] Orcs are in Order
        H [13] Rise, Forsaken
        H [13] No Escape
        H [13] Lordaeron
        H [13] Honor the Dead
            Decrepit fields quests:
                H [13] Hair of the Dog
            H [13] Reinforcements from Fenris
            H [13] The Waters Run Red...
            Worgen assassins quests:
            H [13] Excising the Taint
            H [13] Seek and Destroy
            H [13] Cornered and Crushed!
            H [13] NoWHERE to Run
        H [14] To Forsaken Forward Command
        H [14] In Time, All Will Be Revealed & H [14] Losing Ground & H [14] The F.C.D.
        H [14] Break in Communications: Dreadwatch Outpost
        H [14] Break in Communications: Rutsak's Guard
        H [14] Vengeance for Our Soldiers & H [14] On Whose Orders?
        H [15] What Tomorrow Brings
        H [15] Fall Back!
        H [16] A Man Named Godfrey & H [16] Resistance is Futile
        H [16] The Great Escape
        H [16] Rise, Godfrey
        H [17] Breaking the Barrier & H [17] Unyielding Servitors
        H [18] Dalar Dawnweaver
        H [18] Relios the Relic Keeper
     
            Side quests: H [18] Practical Vengeance & H [18] Ley Energies
     
        H [18] Only One May Enter
        H [18] Transdimensional Warfare: Chapter I & H [18] A Wolf in Bear's Clothing
        H [18] Transdimensional Warfare: Chapter II
        H [19] Transdimensional Warfare: Chapter III
        H [19] Taking the Battlefront
        H [19] Pyrewood's Fall & H [19] Lessons in Fear & H [19] Of No Consequence
        H [19] 7th Legion Battle Plans & H [19] Sowing Discord
        H [20] On Her Majesty's Secret Service
        H [20] Cities in Dust
    */
     
    UPDATE `quest_template` SET `PrevQuestId` = 27096, `Flags` = 0 WHERE `Id` = 27097;
    UPDATE `quest_template` SET `PrevQuestId` = 26965 WHERE `Id` = 26992;
    UPDATE `quest_template` SET `PrevQuestId` = 26965 WHERE `Id` = 26989;
    UPDATE `quest_template` SET `PrevQuestId` = 26998 WHERE `Id` = 27039;
    UPDATE `quest_template` SET `PrevQuestId` = 27098 WHERE `Id` = 27180;
    UPDATE `quest_template` SET `PrevQuestId` = 27195 WHERE `Id` = 27290;
    UPDATE `quest_template` SET `PrevQuestId` = 26965 WHERE `Id` = 26995;
    UPDATE `quest_template` SET `PrevQuestId` = 0 WHERE `Id` = 28089;
    UPDATE `quest_template` SET `PrevQuestId` = 27065 WHERE `Id` = 27073;
    UPDATE `quest_template` SET `PrevQuestId` = 27069 WHERE `Id` = 27095;
    UPDATE `quest_template` SET `PrevQuestId` = 27180 WHERE `Id` = 27226;
    UPDATE `quest_template` SET `PrevQuestId` = 27180 WHERE `Id` = 27231;
    UPDATE `quest_template` SET `PrevQuestId` = 27194 WHERE `Id` = 27195;
    UPDATE `quest_template` SET `PrevQuestId` = 27290 WHERE `Id` = 27333;
     
     
            REPLACE INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`) VALUES ('19', '27349', '8', '27342');
            REPLACE INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`) VALUES ('19', '27349', '8', '27333');
            REPLACE INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`) VALUES ('19', '27349', '8', '27345');
            REPLACE INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`) VALUES ('20', '27349', '8', '27342');
            REPLACE INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`) VALUES ('20', '27349', '8', '27333');
            REPLACE INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`) VALUES ('20', '27349', '8', '27345');
           
            UPDATE `quest_template` SET `PrevQuestId` = 27350 WHERE `Id` = 27364;
           
           
            REPLACE INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`) VALUES ('19', '27401', '8', '27360');
            REPLACE INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`) VALUES ('19', '27401', '8', '27364');
            REPLACE INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`) VALUES ('20', '27401', '8', '27360');
            REPLACE INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`) VALUES ('20', '27401', '8', '27364');
    UPDATE `quest_template` SET `PrevQuestId` = 27405 WHERE `Id` = 27423;
     
     
            REPLACE INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`) VALUES ('19', '27438', '8', '27406');
            REPLACE INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`) VALUES ('19', '27438', '8', '27423');
            REPLACE INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`) VALUES ('20', '27438', '8', '27406');
            REPLACE INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`) VALUES ('20', '27438', '8', '27423');
           
            UPDATE `quest_template` SET `PrevQuestId` = 27438 WHERE `Id` = 27472;
            UPDATE `quest_template` SET `PrevQuestId` = 27472 WHERE `Id` = 27474;
            UPDATE `quest_template` SET `PrevQuestId` = 27472 WHERE `Id` = 27475;
           
            REPLACE INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`) VALUES ('19', '27476', '8', '27474');
            REPLACE INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`) VALUES ('19', '27476', '8', '27475');
            REPLACE INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`) VALUES ('20', '27476', '8', '27474');
            REPLACE INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`) VALUES ('20', '27476', '8', '27475');
           
           
     
           
           
     
     
     
     
     
           
           
    UPDATE `quest_template` SET `PrevQuestId` = 27594 WHERE `Id` = 27601;
     
    -- delete orgrimmar portal
    DELETE FROM `creature` WHERE `id`=44630;
    -- delete Hellscream's Elite
    DELETE FROM `creature` WHERE `id`=44636;
     
    -- delete High Warlord Cromush
    DELETE FROM `creature` WHERE `id`=44640;
    INSERT INTO `creature` (`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
    (44640, 0, 130, 228, 1, 1, 34009, 0, 515.936, 1567.05, 129.833, 3.25311, 300, 0, 0, 387450, 0, 2, 0, 0, 0);
     
    -- delete Garrosh Hellscream
    DELETE FROM `creature` WHERE `id`=44629;
    DELETE FROM `creature` WHERE `id`=1978;
     
    DELETE FROM `creature` WHERE `id`=6739;
    INSERT INTO `creature` (`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
    (6739, 0, 130, 228, 1, 1, 7633, 0, 471.135, 1500.55, 135.605, 1.0821, 500, 0, 0, 1003, 0, 0, 0, 0, 0);
     
     
    UPDATE `creature_template` SET `InhabitType` = 4 WHERE `entry` = 44608;
    UPDATE `creature_template` SET `InhabitType` = 4 WHERE `entry` = 44609;
    UPDATE `creature_template` SET `InhabitType` = 4 WHERE `entry` = 44610;
     
    -- Grand Executor Mortuus
    SET @ENTRY := 44615;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,19,0,100,0,26965,0,0,0,80,4461500,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"on quest accept do actionlist");
     
     
    -- Grand Executor Mortuus
    SET @ENTRY := 4461500;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,0,0,0,0,45,0,1,0,0,0,0,19,44365,50,0,0.0,0.0,0.0,0.0,"on update send data 1 to Sylvanas"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,5000,5000,0,0,12,44630,3,180000,0,0,0,8,0,0,0,1358.62,1054.72,53.12,0.0,"Summon portal avec 5 sec despawn after 3 min"),
    (@ENTRY,@SOURCETYPE,2,0,0,0,100,0,0,0,0,0,12,44630,3,180000,0,0,0,8,0,0,0,1393.27,1021.2,53.2225,0.0,"Summon portal avec 5 sec despawn after 3 min"),
    (@ENTRY,@SOURCETYPE,3,0,0,0,100,0,0,0,0,0,12,44630,3,180000,0,0,0,8,0,0,0,1404.71,1063.73,60.5617,0.0,"Summon portal avec 5 sec despawn after 3 min"),
    (@ENTRY,@SOURCETYPE,4,0,0,0,100,0,3000,3000,0,0,12,44636,3,170000,0,0,0,8,0,0,0,0.9,1029.71,53.2185,2.82743,"Summon Hellscream''s Elite"),
    (@ENTRY,@SOURCETYPE,5,0,0,0,100,0,0,0,0,0,12,44636,3,170000,0,0,0,8,0,0,0,1389.79,1024.51,53.2083,2.82743,"Summon Hellscream''s Elite"),
    (@ENTRY,@SOURCETYPE,6,0,0,0,100,0,0,0,0,0,12,44636,3,170000,0,0,0,8,0,0,0,1388.05,1026.91,53.2083,2.82743,"Summon Hellscream''s Elite"),
    (@ENTRY,@SOURCETYPE,7,0,0,0,100,0,0,0,0,0,12,44636,3,170000,0,0,0,8,0,0,0,1388.16,1020.88,53.2552,2.82743,"Summon Hellscream''s Elite"),
    (@ENTRY,@SOURCETYPE,8,0,0,0,100,0,0,0,0,0,12,44636,3,170000,0,0,0,8,0,0,0,1385.79,1025.99,53.2259,2.82743,"Summon Hellscream''s Elite"),
    (@ENTRY,@SOURCETYPE,9,0,0,0,100,0,0,0,0,0,12,44636,3,170000,0,0,0,8,0,0,0,1386.69,1023.26,53.2439,2.82743,"Summon Hellscream''s Elite"),
    (@ENTRY,@SOURCETYPE,10,0,0,0,100,0,0,0,0,0,12,44636,3,170000,0,0,0,8,0,0,0,1384.33,1022.04,53.2812,2.82743,"Summon Hellscream''s Elite"),
    (@ENTRY,@SOURCETYPE,11,0,0,0,100,0,0,0,0,0,12,44636,3,170000,0,0,0,8,0,0,0,1391.1,1027.73,53.2048,2.82743,"Summon Hellscream''s Elite"),
    (@ENTRY,@SOURCETYPE,12,0,0,0,100,0,0,0,0,0,12,44636,3,170000,0,0,0,8,0,0,0,1359.1,1046.55,52.9705,5.25344,"Summon Hellscream''s Elite"),
    (@ENTRY,@SOURCETYPE,13,0,0,0,100,0,0,0,0,0,12,44636,3,170000,0,0,0,8,0,0,0,1360.89,1051.81,53.1979,5.25344,"Summon Hellscream''s Elite"),
    (@ENTRY,@SOURCETYPE,14,0,0,0,100,0,0,0,0,0,12,44636,3,170000,0,0,0,8,0,0,0,1360.75,1048.84,53.1289,5.25344,"Summon Hellscream''s Elite"),
    (@ENTRY,@SOURCETYPE,15,0,0,0,100,0,0,0,0,0,12,44636,3,170000,0,0,0,8,0,0,0,1364.43,1053.62,53.2934,5.25344,"Summon Hellscream''s Elite"),
    (@ENTRY,@SOURCETYPE,16,0,0,0,100,0,0,0,0,0,12,44636,3,170000,0,0,0,8,0,0,0,1363.08,1048.15,53.2222,5.25344,"Summon Hellscream''s Elite"),
    (@ENTRY,@SOURCETYPE,17,0,0,0,100,0,0,0,0,0,12,44636,3,170000,0,0,0,8,0,0,0,1364.08,1050.84,53.2916,5.25344,"Summon Hellscream''s Elite"),
    (@ENTRY,@SOURCETYPE,18,0,0,0,100,0,0,0,0,0,12,44636,3,170000,0,0,0,8,0,0,0,1366.69,1050.31,53.342,5.25344,"Summon Hellscream''s Elite"),
    (@ENTRY,@SOURCETYPE,19,0,0,0,100,0,0,0,0,0,12,44636,3,170000,0,0,0,8,0,0,0,1357.85,1050.12,52.9982,5.25344,"Summon Hellscream''s Elite"),
    (@ENTRY,@SOURCETYPE,20,0,0,0,100,0,0,0,0,0,12,44629,3,170000,0,0,0,8,0,0,0,1402.45, 1061.62, 60.56173, 3.926991,"Summon Hellscream''s Garrosh"),
    (@ENTRY,@SOURCETYPE,21,0,0,0,100,0,0,0,0,0,12,44640,3,170000,0,0,0,8,0,0,0,1402.152, 1067.262, 60.54778, 1.127564,"Summon Hellscream''s Crommur");
     
    -- SPELL 55761
    UPDATE `creature_template` SET `equipment_id` = 44640 WHERE `entry` = 44640;
    UPDATE `creature_template` SET `equipment_id` = 44629 WHERE `entry` = 44629;
    UPDATE `creature_template` SET `equipment_id` = 44636 WHERE `entry` = 44636;
     
    -- Portal from Orgrimmar
    SET @ENTRY := 44630;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,54,0,100,0,0,0,0,0,11,55761,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"On summoned cast 55761 on self");
     
     
    -- Hellscream's Elite
    SET @ENTRY := 44636;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,54,0,100,0,0,0,0,0,11,12980,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"cast 12980 on self at summoned"),
    (@ENTRY,@SOURCETYPE,1,0,60,0,100,0,169000,169000,169000,169000,11,12980,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"cast 12980 on self after 169000 ms");
     
    DELETE FROM creature_text WHERE entry in (44365,44640,44629);
    INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
    (44365, 0, 0, 'Where is that ogre-headed buffoon?', 12, 1, 100, 6, 0, 20459, 'Sylvanas'),
    (44365, 1, 0, 'Ah, speak of the devil...', 12, 1, 100, 1, 0, 20460, 'Sylvanas'),
    (44365, 2, 0, 'Warchief, so glad you could make it.', 12, 1, 100, 1, 0, 20461, 'Sylvanas'),
    (44365, 3, 0, 'With the death of the Lich King, many of the more intelligent Scourge became... unemployed. Those ''fiends,'' as you so delicately put it, are called val''kyr. They are under my command now...', 12, 1, 100, 0, 0, 20462, 'Sylvanas'),
    (44365, 4, 0, '...and they are part of the reason that I asked to see you.', 12, 1, 100, 1, 0, 20463, 'Sylvanas'),
    (44365, 5, 0, 'Very well, Warchief. I have solved the plight of the Forsaken!', 12, 1, 100, 5, 0, 20464, 'Sylvanas'),
    (44365, 6, 0, 'As a race, we Forsaken are unable to procreate', 12, 1, 100, 274, 0, 20465, 'Sylvanas'),
    (44365, 7, 0, 'With the aid of the val''kyr, we are now able to take the corpses of the fallen and create new Forsaken.', 12, 1, 100, 0, 0, 20466, 'Sylvanas'),
    (44365, 8, 0, 'Agatha, show the Warchief!', 12, 1, 100, 22, 0, 20467, 'Sylvanas'),
    (44365, 9, 0, 'Warchief, without these new Forsaken my people would die out... Our hold upon Gilneas and northern Lordaeron would crumble.', 12, 1, 100, 0, 0, 20468, 'Sylvanas'),
    (44365, 10, 0, 'Isn''t it obvious, Warchief? I serve the Horde.', 12, 1, 100, 66, 0, 20469, 'Sylvanas'),
    (44640, 0, 0, 'ABBERATION!', 12, 1, 100, 5, 0, 0, 'Верховный полководец Кромуш'),
    (44640, 1, 0, 'As you command, Warchief!', 12, 1, 100, 66, 0, 0, 'Верховный полководец Кромуш'),
    (44629, 0, 0, 'This better be important, Sylvanas. You know how I detest this place and its foul stench. Why have you called for me?', 12, 1, 100, 0, 0, 20496, 'Garosh'),
    (44629, 1, 0, 'And more importantly, what are those Scourge fiends doing here?', 12, 1, 100, 25, 0, 20497, 'Garosh'),
    (44629, 2, 0, 'Get on with it, Sylvanas.', 12, 1, 100, 1, 0, 20498, 'Garosh'),
    (44629, 3, 0, 'What you have done here, Sylvanas... it goes against the laws of nature. Disgusting is the only word I have to describe it.', 12, 1, 100, 0, 0, 20499, 'Garosh'),
    (44629, 4, 0, 'Have you given any thought to what this means, Sylvanas?', 12, 1, 100, 6, 0, 20500, 'Garosh'),
    (44629, 5, 0, 'What difference is there between you and the Lich King now?', 12, 1, 100, 6, 0, 20501, 'Garosh'),
    (44629, 6, 0, 'Watch your clever mouth, bitch.', 12, 1, 100, 397, 0, 20502, 'Garosh'),
    (44629, 7, 0, 'Cromush, you stay behind and make sure the Banshee Queen is well "guarded." I will be expecting a full report when next we meet.', 12, 1, 100, 0, 0, 20503, 'Garosh'),
    (44629, 8, 0, 'Remember, Sylvanas, eventually we all have to stand before our maker and face judgment. Your day may come sooner than others...', 12, 1, 100, 0, 0, 20504, 'Garosh');
     
     
    -- High Warlord Cromush
    SET @ENTRY := 44640;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,54,0,100,0,0,0,0,0,80,4464000,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"on summoned do action");
     
    DELETE FROM waypoints WHERE entry=4464000;
    INSERT INTO waypoints(entry, pointid, position_x, position_y, position_z) VALUES
    (4464000, 1, 1376.83, 1044.94, 53.3534);
     
     
    -- High Warlord Cromush
    SET @ENTRY := 4464000;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,0,0,0,0,53,1,4464000,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"do wp on summoned"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,93000,93000,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 0"),
    (@ENTRY,@SOURCETYPE,2,0,0,0,100,0,60000,60000,0,0,1,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 1");
     
    -- Lady Sylvanas Windrunner
    SET @ENTRY := 44365;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,38,0,100,0,0,1,0,0,80,4436500,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"on data set 1 do action");
     
     
    -- Lady Sylvanas Windrunner
    SET @ENTRY := 4436500;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 0"),
    (@ENTRY,@SOURCETYPE,1,0,1,0,100,0,7000,7000,0,0,1,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 1"),
    (@ENTRY,@SOURCETYPE,2,0,0,0,100,0,25000,25000,0,0,1,2,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 2"),
    (@ENTRY,@SOURCETYPE,3,0,0,0,100,0,4000,4000,0,0,1,3,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 3"),
    (@ENTRY,@SOURCETYPE,4,0,0,0,100,0,16000,16000,0,0,1,4,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 4 "),
    (@ENTRY,@SOURCETYPE,5,0,0,0,100,0,8000,8000,8000,8000,1,5,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 5"),
    (@ENTRY,@SOURCETYPE,6,0,0,0,100,0,6000,6000,0,0,1,6,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 6"),
    (@ENTRY,@SOURCETYPE,7,0,0,0,100,0,5000,5000,0,0,1,7,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 7"),
    (@ENTRY,@SOURCETYPE,8,0,0,0,100,0,10000,10000,0,0,1,8,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 8 1min21"),
    (@ENTRY,@SOURCETYPE,9,0,0,0,100,0,3000,3000,0,0,45,0,1,0,0,0,0,10,59236,44608,0,0.0,0.0,0.0,0.0,"send data 1 to valkir 1min24"),
    (@ENTRY,@SOURCETYPE,10,0,0,0,100,0,32000,32000,0,0,1,9,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 9"),
    (@ENTRY,@SOURCETYPE,11,0,0,0,100,0,20000,20000,0,0,1,10,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 10"),
    (@ENTRY,@SOURCETYPE,12,0,0,0,100,0,37000,37000,0,0,33,44629,0,0,0,0,0,17,0,100,0,0.0,0.0,0.0,0.0,"give credit to player");
     
     
    -- Garrosh Hellscream
    SET @ENTRY := 44629;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,54,0,100,0,0,0,0,0,80,4462900,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"on summoned call time action");
     
    -- Garrosh Hellscream
    SET @ENTRY := 4462900;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,2000,2000,0,0,97,16,16,0,0,0,0,8,0,0,0,1379.52,1044.37,54.19,5.38,"jump to pos"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 0"),
    (@ENTRY,@SOURCETYPE,2,0,0,0,100,0,13000,13000,0,0,1,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 1"),
    (@ENTRY,@SOURCETYPE,3,0,0,0,100,0,30000,30000,0,0,1,2,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 2"),
    (@ENTRY,@SOURCETYPE,4,0,0,0,100,0,47000,47000,0,0,1,3,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 3"),
    (@ENTRY,@SOURCETYPE,5,0,0,0,100,0,22000,22000,0,0,1,4,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 4"),
    (@ENTRY,@SOURCETYPE,6,0,0,0,100,0,5500,5500,0,0,1,5,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 5"),
    (@ENTRY,@SOURCETYPE,7,0,0,0,100,0,12000,12000,0,0,1,6,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 6"),
    (@ENTRY,@SOURCETYPE,8,0,0,0,100,0,5000,5000,0,0,1,7,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 7"),
    (@ENTRY,@SOURCETYPE,9,0,0,0,100,0,16000,16000,0,0,1,8,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 8"),
    (@ENTRY,@SOURCETYPE,10,0,0,0,100,0,11000,11000,0,0,69,0,0,0,0,0,0,8,0,0,0,1351.29,1045.22,52.292,0.0,"move to pos");
     
    REPLACE INTO conditions(SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorType, ErrorTextId, ScriptName, Comment) VALUES (13, 1, 83173, 0, 0, 31, 0, 3, 44592, 0, 0, 0, 0, '', null);
    REPLACE INTO conditions(SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorType, ErrorTextId, ScriptName, Comment) VALUES (13, 1, 83173, 0, 1, 31, 0, 3, 44593, 0, 0, 0, 0, '', null);
     
    -- Agatha
    SET @ENTRY := 44608;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,38,0,100,0,0,1,0,0,80,4460800,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"on data set 1 do action");
     
     
    -- Agatha
    SET @ENTRY := 4460800;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,1363.66,1028.2,64.706,0.686,"move to pos 1"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,3000,3000,3000,3000,69,0,0,0,0,0,0,8,0,0,0,1370.7,1033.03,59.019,0.667,"move to pos 2"),
    (@ENTRY,@SOURCETYPE,2,0,0,0,100,0,1500,1500,0,0,11,83173,0,0,0,0,0,9,44592,0,100,0.0,0.0,0.0,0.0,"cast on creature range"),
    (@ENTRY,@SOURCETYPE,3,0,0,0,100,0,9000,9000,0,0,69,0,0,0,0,0,0,8,0,0,0,1364.02,1028.54,55.99,0.855,"move to home"),
    (@ENTRY,@SOURCETYPE,4,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0.0,0.0,0.0,0.855,"set orientation");
     
     
     
    -- Fallen Human
    SET @ENTRY := 44592;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,8,0,100,0,83173,0,0,0,80,4459200,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"on spellhit do action");
     
     
    -- Fallen Human
    SET @ENTRY := 4459200;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,19,144951,15,0,0.0,0.0,0.0,0.0,"move to nearest trigger"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,5000,5000,0,0,69,0,0,0,0,0,0,19,144953,15,0,0.0,0.0,0.0,0.0,"move to nearest trigger"),
    (@ENTRY,@SOURCETYPE,2,0,0,0,100,0,2000,2000,0,0,12,44596,3,30000,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"summon 44596 on self"),
    (@ENTRY,@SOURCETYPE,3,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"force despawn self");
     
     
    -- Fallen Human
    SET @ENTRY := 44593;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,8,0,100,0,83173,0,0,0,80,4459300,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"on spellhit do action");
     
    -- Fallen Human
    SET @ENTRY := 4459300;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,19,144951,15,0,0.0,0.0,0.0,0.0,"move to nearest trigger"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,5000,5000,0,0,69,0,0,0,0,0,0,19,144953,15,0,0.0,0.0,0.0,0.0,"move to nearest trigger"),
    (@ENTRY,@SOURCETYPE,2,0,0,0,100,0,2000,2000,0,0,12,44597,3,30000,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"summon 44596 on self"),
    (@ENTRY,@SOURCETYPE,3,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"force despawn self");
     
     
    -- triger
    DELETE FROM `creature_template` WHERE (`entry`=144951);
    INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES (144951, 0, 0, 0, 0, 0, 16480, 16480, 16480, 16480, 'Invisible Trigger One', '', '', 0, 1, 1, 0, 35, 35, 0, 1, 1, 1, 0, 1007, 1354, 0, 1571, 1, 2000, 2200, 1, 0, 2048, 8, 0, 0, 0, 0, 0, 758, 1062, 220, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 4, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 128, '', 12340);
    INSERT INTO creature(id, map, zoneId, areaId, spawnMask, phaseMask, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, dynamicflags) VALUES
    (144951, 0, 130, 5369, 1, 1, 33981, 0, 1373.35, 1031.58, 54.6189, 0.959931, 500, 0, 0, 273, 0, 0, 0, 0, 0),
    (144951, 0, 130, 5369, 1, 1, 33978, 0, 1377.3, 1035.93, 55.0961, 3.14159, 500, 0, 0, 273, 0, 0, 0, 0, 0),
    (144951, 0, 130, 5369, 1, 1, 33981, 0, 1369.57, 1036.9, 54.998, 0.20944, 500, 0, 0, 273, 0, 0, 0, 0, 0),
    (144951, 0, 130, 5369, 1, 1, 33980, 0, 1374.14, 1036.35, 54.9217, 5.53269, 500, 0, 0, 273, 0, 0, 0, 0, 0),
    (144951, 0, 130, 5369, 1, 1, 33981, 0, 1370.66, 1030.82, 55.134, 0.890118, 500, 0, 0, 273, 0, 0, 0, 0, 0),
    (144951, 0, 130, 5369, 1, 1, 33978, 0, 1367.33, 1035.38, 55.304, 0.890118, 500, 0, 0, 273, 0, 0, 0, 0, 0),
    (144951, 0, 130, 5369, 1, 1, 33979, 0, 1369.65, 1033.67, 54.9668, 0.698132, 500, 0, 0, 273, 0, 0, 0, 0, 0),
    (144951, 0, 130, 5369, 1, 1, 33978, 0, 1375.42, 1033.81, 54.6522, 0.890118, 500, 0, 0, 273, 0, 0, 0, 0, 0),
    (144951, 0, 130, 5369, 1, 1, 33978, 0, 1372.58, 1038.07, 54.9666, 0.890118, 500, 0, 0, 273, 0, 0, 0, 0, 0),
    (144951, 0, 130, 5369, 1, 1, 33978, 0, 1378.16, 1031.71, 55.3717, 0.767945, 500, 0, 0, 273, 0, 0, 0, 0, 0),
    (144951, 0, 130, 5369, 1, 1, 33979, 0, 1372.98, 1041.06, 55.381, 0.226893, 500, 0, 0, 273, 0, 0, 0, 0, 0),
    (144951, 0, 130, 5369, 1, 1, 33984, 0, 1376, 1029.61, 54.9374, 0.890118, 500, 0, 0, 273, 0, 0, 0, 0, 0),
    (144951, 0, 130, 5369, 1, 1, 33985, 0, 1369.71, 1040.19, 55.0212, 5.58505, 500, 0, 0, 273, 0, 0, 0, 0, 0),
    (144951, 0, 130, 5369, 1, 1, 33983, 0, 1375.2, 1038.58, 55.2451, 4.55531, 500, 0, 0, 273, 0, 0, 0, 0, 0),
    (144951, 0, 130, 5369, 1, 1, 33985, 0, 1372.08, 1034.98, 54.8489, 0.890118, 500, 0, 0, 273, 0, 0, 0, 0, 0);
    UPDATE `creature_template` SET `modelid2` = 0, `modelid3` = 0, `modelid4` = 0 WHERE `entry` = 144951;
    DELETE FROM `creature_template` WHERE (`entry`=144953);
    INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES (144953, 0, 0, 0, 0, 0, 16480, 0, 0, 0, 'Invisible Trigger One', '', '', 0, 1, 1, 0, 35, 35, 0, 1, 1, 1, 0, 1007, 1354, 0, 1571, 1, 2000, 2200, 1, 0, 2048, 8, 0, 0, 0, 0, 0, 758, 1062, 220, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 4, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 128, '', 12340);
    INSERT INTO creature(id, map, zoneId, areaId, spawnMask, phaseMask, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, dynamicflags) VALUES
    (144953, 0, 130, 5369, 1, 1, 33981, 0, 1373.35, 1031.58, 50.6189, 0.959931, 500, 0, 0, 273, 0, 0, 0, 0, 0),
    (144953, 0, 130, 5369, 1, 1, 33978, 0, 1377.3, 1035.93, 51.0961, 3.14159, 500, 0, 0, 273, 0, 0, 0, 0, 0),
    (144953, 0, 130, 5369, 1, 1, 33981, 0, 1369.57, 1036.9, 50.998, 0.20944, 500, 0, 0, 273, 0, 0, 0, 0, 0),
    (144953, 0, 130, 5369, 1, 1, 33980, 0, 1374.14, 1036.35, 50.9217, 5.53269, 500, 0, 0, 273, 0, 0, 0, 0, 0),
    (144953, 0, 130, 5369, 1, 1, 33981, 0, 1370.66, 1030.82, 51.134, 0.890118, 500, 0, 0, 273, 0, 0, 0, 0, 0),
    (144953, 0, 130, 5369, 1, 1, 33978, 0, 1367.33, 1035.38, 51.304, 0.890118, 500, 0, 0, 273, 0, 0, 0, 0, 0),
    (144953, 0, 130, 5369, 1, 1, 33979, 0, 1369.65, 1033.67, 50.9668, 0.698132, 500, 0, 0, 273, 0, 0, 0, 0, 0),
    (144953, 0, 130, 5369, 1, 1, 33978, 0, 1375.42, 1033.81, 50.6522, 0.890118, 500, 0, 0, 273, 0, 0, 0, 0, 0),
    (144953, 0, 130, 5369, 1, 1, 33978, 0, 1372.58, 1038.07, 50.9666, 0.890118, 500, 0, 0, 273, 0, 0, 0, 0, 0),
    (144953, 0, 130, 5369, 1, 1, 33978, 0, 1378.16, 1031.71, 51.3717, 0.767945, 500, 0, 0, 273, 0, 0, 0, 0, 0),
    (144953, 0, 130, 5369, 1, 1, 33979, 0, 1372.98, 1041.06, 51.381, 0.226893, 500, 0, 0, 273, 0, 0, 0, 0, 0),
    (144953, 0, 130, 5369, 1, 1, 33984, 0, 1376, 1029.61, 50.9374, 0.890118, 500, 0, 0, 273, 0, 0, 0, 0, 0),
    (144953, 0, 130, 5369, 1, 1, 33985, 0, 1369.71, 1040.19, 51.0212, 5.58505, 500, 0, 0, 273, 0, 0, 0, 0, 0),
    (144953, 0, 130, 5369, 1, 1, 33983, 0, 1375.2, 1038.58, 51.2451, 4.55531, 500, 0, 0, 273, 0, 0, 0, 0, 0),
    (144953, 0, 130, 5369, 1, 1, 33985, 0, 1372.08, 1034.98, 50.8489, 0.890118, 500, 0, 0, 273, 0, 0, 0, 0, 0);
     
    -- Forsaken Trooper
    SET @ENTRY := 44596;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,54,0,100,0,0,0,0,0,11,83149,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"cast on self 83149");
     
    -- Forsaken Trooper
    SET @ENTRY := 44597;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,54,0,100,0,0,0,0,0,11,83149,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"cast on self 83149");
     
    UPDATE `creature_template` SET `InhabitType` = 7 WHERE `entry` = 44592;
    UPDATE `creature_template` SET `InhabitType` = 7 WHERE `entry` = 44593;
    DELETE FROM `creature_template_addon` WHERE (`entry`=44608);
    INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (44608, 0, 0, 50397184, 1, 0, '');
    DELETE FROM `creature_addon` WHERE (`guid`=59236);
     
     
       
    -- Data mined from www.wowhead.com
    -- Generated by Loot.php November 29, 2012 by Maibenrai
    --  http://www.wowhead.com/npc=1778
    DELETE FROM `creature_loot_template` WHERE `entry` = 1778;
    INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
    (1778, 60743, 85.8485, 1, 0, 1, 1), -- 7Diseased Beast Guts
    (1778, 60742, -43.219, 1, 0, 1, 1), --
    (1778, 3173, 41.1490, 1, 0, 1, 1), -- 6Bear Meat
    (1778, 4865, 35.5553, 1, 0, 1, 1), -- 7Ruined Pelt
    (1778, 7074, 35.5491, 1, 0, 1, 1), -- 7Chipped Claw
    (1778, 3169, 13.9499, 1, 0, 1, 1), -- 7Chipped Bear Tooth
    (1778, 3170, 13.8624, 1, 0, 1, 1), -- 7Large Bear Tooth
    (1778, 3253, -0.4815, 1, 0, 1, 1), -- 6Grizzled Bear Heart
    (1778, 774, 0.4301, 1, 0, 1, 1), -- 5Malachite
    (1778, 818, 0.2819, 1, 0, 1, 1), -- 5Tigerseye
    (1778, 1414, 0.1749, 1, 0, 1, 1), -- 7Cracked Sledge
    (1778, 727, 0.1718, 1, 0, 1, 1), -- 5Notched Shortsword
    (1778, 6513, 0.1718, 1, 0, 1, 1), -- 6Disciple's Sash
    (1778, 4562, 0.1687, 1, 0, 1, 1), -- 5Severing Axe
    (1778, 8178, 0.1636, 1, 0, 1, 1), -- 5Training Sword
    (1778, 7350, 0.1636, 1, 0, 1, 1), -- 6Disciple's Bracers
    (1778, 1411, 0.1533, 1, 0, 1, 1), -- 7Withered Staff
    (1778, 2138, 0.1451, 1, 0, 1, 1), -- 7Sharpened Letter Opener
    (1778, 8180, 0.1440, 1, 0, 1, 1), -- 5Hunting Bow
    (1778, 1416, 0.1379, 1, 0, 1, 1), -- 7Rusty Hatchet
    (1778, 1512, 0.1368, 1, 0, 1, 1), -- 7Crude Battle Axe
    (1778, 1513, 0.1358, 1, 0, 1, 1), -- 7Old Greatsword
    (1778, 1514, 0.1358, 1, 0, 1, 1), -- 7Rusty Warhammer
    (1778, 1417, 0.1337, 1, 0, 1, 1), -- 7Beaten Battle Axe
    (1778, 1430, 0.1317, 1, 0, 1, 1), -- 7Patchwork Gloves
    (1778, 1510, 0.1317, 1, 0, 1, 1), -- 7Heavy Hammer
    (1778, 1413, 0.1307, 1, 0, 1, 1), -- 7Feeble Sword
    (1778, 2763, 0.1307, 1, 0, 1, 1), -- 7Fisherman Knife
    (1778, 4561, 0.1296, 1, 0, 1, 1), -- 5Scalping Tomahawk
    (1778, 1503, 0.1276, 1, 0, 1, 1), -- 7Warped Leather Boots
    (1778, 3370, 0.1265, 1, 0, 1, 1), -- 7Patchwork Belt
    (1778, 6518, 0.1245, 1, 0, 1, 1), -- 6Pioneer Boots
    (1778, 2774, 0.1204, 1, 0, 1, 1), -- 7Rust-Covered Blunderbuss
    (1778, 2958, 0.1183, 1, 0, 1, 1), -- 5Journeyman's Pants
    (1778, 1431, 0.1183, 1, 0, 1, 1), -- 7Patchwork Pants
    (1778, 2773, 0.1173, 1, 0, 1, 1), -- 7Cracked Shortbow
    (1778, 2777, 0.1173, 1, 0, 1, 1), -- 7Feeble Shortbow
    (1778, 1415, 0.1163, 1, 0, 1, 1), -- 7Carpenter's Mallet
    (1778, 6514, 0.1142, 1, 0, 1, 1), -- 6Disciple's Cloak
    (1778, 1433, 0.1132, 1, 0, 1, 1), -- 7Patchwork Armor
    (1778, 2140, 0.1121, 1, 0, 1, 1), -- 5Carving Knife
    (1778, 3373, 0.1091, 1, 0, 1, 1), -- 7Patchwork Bracers
    (1778, 2778, 0.1091, 1, 0, 1, 1), -- 7Cheap Blunderbuss
    (1778, 1418, 0.1080, 1, 0, 1, 1), -- 7Worn Leather Belt
    (1778, 1516, 0.1080, 1, 0, 1, 1), -- 7Worn Hatchet
    (1778, 1497, 0.1070, 1, 0, 1, 1), -- 7Calico Cloak
    (1778, 1507, 0.1060, 1, 0, 1, 1), -- 7Warped Leather Pants
    (1778, 1420, 0.1049, 1, 0, 1, 1), -- 7Worn Leather Bracers
    (1778, 1511, 0.1049, 1, 0, 1, 1), -- 7Commoner's Sword
    (1778, 1412, 0.1039, 1, 0, 1, 1), -- 7Crude Bastard Sword
    (1778, 1425, 0.1039, 1, 0, 1, 1), -- 7Worn Leather Vest
    (1778, 6515, 0.1029, 1, 0, 1, 1), -- 6Disciple's Gloves
    (1778, 2214, 0.1029, 1, 0, 1, 1), -- 7Wooden Buckler
    (1778, 2645, 0.1019, 1, 0, 1, 1), -- 7Loose Chain Gloves
    (1778, 1499, 0.1019, 1, 0, 1, 1), -- 7Calico Pants
    (1778, 1515, 0.1019, 1, 0, 1, 1), -- 7Rough Wooden Staff
    (1778, 2212, 0.1008, 1, 0, 1, 1), -- 7Cracked Buckler
    (1778, 1502, 0.1008, 1, 0, 1, 1), -- 7Warped Leather Belt
    (1778, 2642, 0.0998, 1, 0, 1, 1), -- 7Loose Chain Boots
    (1778, 1504, 0.0998, 1, 0, 1, 1), -- 7Warped Leather Bracers
    (1778, 1501, 0.0998, 1, 0, 1, 1), -- 7Calico Tunic
    (1778, 2959, 0.0988, 1, 0, 1, 1), -- 6Journeyman's Boots
    (1778, 1427, 0.0988, 1, 0, 1, 1), -- 7Patchwork Shoes
    (1778, 2962, 0.0977, 1, 0, 1, 1), -- 5Burnt Leather Breeches
    (1778, 1509, 0.0977, 1, 0, 1, 1), -- 7Warped Leather Vest
    (1778, 1730, 0.0977, 1, 0, 1, 1), -- 7Worn Mail Belt
    (1778, 1419, 0.0967, 1, 0, 1, 1), -- 7Worn Leather Boots
    (1778, 6507, 0.0947, 1, 0, 1, 1), -- 6Infantry Bracers
    (1778, 2213, 0.0947, 1, 0, 1, 1), -- 7Worn Large Shield
    (1778, 2964, 0.0936, 1, 0, 1, 1), -- 6Burnt Leather Gloves
    (1778, 6509, 0.0936, 1, 0, 1, 1), -- 6Infantry Belt
    (1778, 2967, 0.0926, 1, 0, 1, 1), -- 6Warrior's Boots
    (1778, 1734, 0.0926, 1, 0, 1, 1), -- 7Worn Mail Gloves
    (1778, 7351, 0.0916, 1, 0, 1, 1), -- 6Disciple's Boots
    (1778, 9745, 0.0916, 1, 0, 1, 1), -- 6Simple Cape
    (1778, 1498, 0.0916, 1, 0, 1, 1), -- 7Calico Gloves
    (1778, 1422, 0.0905, 1, 0, 1, 1), -- 7Worn Leather Gloves
    (1778, 6519, 0.0895, 1, 0, 1, 1), -- 6Pioneer Bracers
    (1778, 1423, 0.0895, 1, 0, 1, 1), -- 7Worn Leather Pants
    (1778, 6521, 0.0885, 1, 0, 1, 1), -- 6Pioneer Gloves
    (1778, 1732, 0.0885, 1, 0, 1, 1), -- 7Worn Mail Bracers
    (1778, 9754, 0.0875, 1, 0, 1, 1), -- 6Gypsy Cloak
    (1778, 1429, 0.0875, 1, 0, 1, 1), -- 7Patchwork Cloak
    (1778, 2643, 0.0875, 1, 0, 1, 1), -- 7Loose Chain Bracers
    (1778, 1495, 0.0875, 1, 0, 1, 1), -- 7Calico Shoes
    (1778, 3375, 0.0864, 1, 0, 1, 1), -- 7Calico Bracers
    (1778, 1506, 0.0864, 1, 0, 1, 1), -- 7Warped Leather Gloves
    (1778, 4663, 0.0854, 1, 0, 1, 1), -- 6Journeyman's Belt
    (1778, 2215, 0.0844, 1, 0, 1, 1), -- 7Wooden Shield
    (1778, 6517, 0.0813, 1, 0, 1, 1), -- 6Pioneer Belt
    (1778, 3192, 0.0802, 1, 0, 1, 1), -- 5Short Bastard Sword
    (1778, 3374, 0.0792, 1, 0, 1, 1), -- 7Calico Belt
    (1778, 2966, 0.0782, 1, 0, 1, 1), -- 5Warrior's Pants
    (1778, 2940, 0.0782, 1, 0, 1, 1), -- 7Bloody Bear Paw
    (1778, 2635, 0.0782, 1, 0, 1, 1), -- 7Loose Chain Belt
    (1778, 2646, 0.0782, 1, 0, 1, 1), -- 7Loose Chain Pants
    (1778, 1737, 0.0772, 1, 0, 1, 1), -- 7Worn Mail Vest
    (1778, 2961, 0.0741, 1, 0, 1, 1), -- 5Burnt Leather Vest
    (1778, 6506, 0.0741, 1, 0, 1, 1), -- 6Infantry Boots
    (1778, 1735, 0.0741, 1, 0, 1, 1), -- 7Worn Mail Pants
    (1778, 1731, 0.0730, 1, 0, 1, 1), -- 7Worn Mail Boots
    (1778, 6510, 0.0720, 1, 0, 1, 1), -- 6Infantry Gauntlets
    (1778, 4577, 0.0700, 1, 0, 1, 1), -- 5Compact Shotgun
    (1778, 3214, 0.0700, 1, 0, 1, 1), -- 6Warrior's Bracers
    (1778, 8181, 0.0689, 1, 0, 1, 1), -- 6Hunting Rifle
    (1778, 3609, 0.0679, 1, 0, 1, 1), -- 5Plans: Copper Chain Vest
    (1778, 2965, 0.0669, 1, 0, 1, 1), -- 5Warrior's Tunic
    (1778, 2648, 0.0669, 1, 0, 1, 1), -- 7Loose Chain Vest
    (1778, 1210, 0.0658, 1, 0, 1, 1), -- 5Shadowgem
    (1778, 2963, 0.0648, 1, 0, 1, 1), -- 6Burnt Leather Boots
    (1778, 4563, 0.0648, 1, 0, 1, 1), -- 6Billy Club
    (1778, 5069, 0.0638, 1, 0, 1, 1), -- 5Fire Wand
    (1778, 9753, 0.0638, 1, 0, 1, 1), -- 5Gypsy Buckler
    (1778, 9761, 0.0638, 1, 0, 1, 1), -- 6Cadet Cloak
    (1778, 9742, 0.0628, 1, 0, 1, 1), -- 6Simple Cord
    (1778, 7108, 0.0617, 1, 0, 1, 1), -- 5Infantry Shield
    (1778, 15925, 0.0586, 1, 0, 1, 1), -- 5Journeyman's Stave
    (1778, 11406, 0.0586, 1, 0, 1, 1), -- 7Rotting Bear Carcass
    (1778, 2598, 0.0556, 1, 0, 1, 1), -- 5Pattern: Red Linen Robe
    (1778, 6337, 0.0556, 1, 0, 1, 1), -- 5Infantry Leggings
    (1778, 2960, 0.0556, 1, 0, 1, 1), -- 6Journeyman's Gloves
    (1778, 15932, 0.0535, 1, 0, 1, 1), -- 5Disciple's Stein
    (1778, 768, 0.0535, 1, 0, 1, 1), -- 6Lumberjack Axe
    (1778, 4666, 0.0525, 1, 0, 1, 1), -- 6Burnt Leather Belt
    (1778, 6508, 0.0525, 1, 0, 1, 1), -- 6Infantry Cloak
    (1778, 2075, 0.0494, 1, 0, 1, 1), -- 5Heavy Mace
    (1778, 2968, 0.0494, 1, 0, 1, 1), -- 6Warrior's Gloves
    (1778, 6520, 0.0484, 1, 0, 1, 1), -- 6Pioneer Cloak
    (1778, 4677, 0.0473, 1, 0, 1, 1), -- 6Veteran Cloak
    (1778, 9750, 0.0473, 1, 0, 1, 1), -- 6Gypsy Sash
    (1778, 2957, 0.0453, 1, 0, 1, 1), -- 5Journeyman's Vest
    (1778, 9743, 0.0442, 1, 0, 1, 1), -- 6Simple Shoes
    (1778, 6267, 0.0432, 1, 0, 1, 1), -- 5Disciple's Pants
    (1778, 4566, 0.0432, 1, 0, 1, 1), -- 5Sturdy Quarterstaff
    (1778, 5571, 0.0422, 1, 0, 1, 1), -- 6Small Black Pouch
    (1778, 9752, 0.0422, 1, 0, 1, 1), -- 6Gypsy Bands
    (1778, 9758, 0.0412, 1, 0, 1, 1), -- 6Cadet Belt
    (1778, 4684, 0.0412, 1, 0, 1, 1), -- 6Spellbinder Belt
    (1778, 9751, 0.0401, 1, 0, 1, 1), -- 6Gypsy Sandals
    (1778, 6269, 0.0391, 1, 0, 1, 1), -- 5Pioneer Trousers
    (1778, 9762, 0.0381, 1, 0, 1, 1), -- 6Cadet Gauntlets
    (1778, 6511, 0.0370, 1, 0, 1, 1), -- 5Journeyman's Robe
    (1778, 9744, 0.0370, 1, 0, 1, 1), -- 6Simple Bands
    (1778, 3213, 0.0370, 1, 0, 1, 1), -- 6Veteran Bracers
    (1778, 4564, 0.0360, 1, 0, 1, 1), -- 5Spiked Club
    (1778, 5572, 0.0360, 1, 0, 1, 1), -- 6Small Green Pouch
    (1778, 4690, 0.0350, 1, 0, 1, 1), -- 6Hunting Belt
    (1778, 828, 0.0329, 1, 0, 1, 1), -- 6Small Blue Pouch
    (1778, 9760, 0.0329, 1, 0, 1, 1), -- 6Cadet Bracers
    (1778, 4683, 0.0329, 1, 0, 1, 1), -- 6Spellbinder Cloak
    (1778, 6268, 0.0319, 1, 0, 1, 1), -- 5Pioneer Tunic
    (1778, 9747, 0.0319, 1, 0, 1, 1), -- 5Simple Britches
    (1778, 9759, 0.0319, 1, 0, 1, 1), -- 6Cadet Boots
    (1778, 4689, 0.0298, 1, 0, 1, 1), -- 6Hunting Cloak
    (1778, 9746, 0.0288, 1, 0, 1, 1), -- 6Simple Gloves
    (1778, 3610, 0.0278, 1, 0, 1, 1), -- 5Plans: Gemmed Copper Gauntlets
    (1778, 805, 0.0247, 1, 0, 1, 1), -- 6Small Red Pouch
    (1778, 5635, 0.0237, 1, 0, 1, 1), -- 6Sharp Claw
    (1778, 6336, 0.0216, 1, 0, 1, 1), -- 5Infantry Tunic
    (1778, 5071, 0.0216, 1, 0, 1, 1), -- 5Shadow Wand
    (1778, 9755, 0.0216, 1, 0, 1, 1), -- 6Gypsy Gloves
    (1778, 5573, 0.0216, 1, 0, 1, 1), -- 6Green Leather Bag
    (1778, 6512, 0.0195, 1, 0, 1, 1), -- 5Disciple's Robe
    (1778, 6266, 0.0185, 1, 0, 1, 1), -- 5Disciple's Vest
    (1778, 2555, 0.0185, 1, 0, 1, 1), -- 5Recipe: Swiftness Potion
    (1778, 4496, 0.0185, 1, 0, 1, 1), -- 6Small Brown Pouch
    (1778, 2855, -0.0165, 1, 0, 1, 1), -- 6Putrid Claw
    (1778, 1438, 0.0165, 1, 0, 1, 1), -- 6Warrior's Shield
    (1778, 2632, 0.0154, 1, 0, 1, 1), -- 5Curved Dagger
    (1778, 2589, 0.0154, 1, 0, 1, 1), -- 6Linen Cloth
    (1778, 15895, 0.0154, 1, 0, 1, 1), -- 6Burnt Buckler
    (1778, 7109, 0.0154, 1, 0, 1, 1), -- 6Pioneer Buckler
    (1778, 2971, 0.0144, 1, 0, 1, 1), -- 6Spellbinder Boots
    (1778, 3643, 0.0144, 1, 0, 1, 1), -- 6Spellbinder Bracers
    (1778, 62328, 0.0144, 1, 0, 1, 1), -- 7Shed Fur
    (1778, 6342, 0.0134, 1, 0, 1, 1), -- 5Formula: Enchant Chest - Minor Mana
    (1778, 3651, 0.0134, 1, 0, 1, 1), -- 5Veteran Shield
    (1778, 6555, 0.0123, 1, 0, 1, 1), -- 6Bard's Cloak
    (1778, 2553, 0.0113, 1, 0, 1, 1), -- 5Recipe: Elixir of Minor Agility
    (1778, 3652, 0.0113, 1, 0, 1, 1), -- 5Hunting Buckler
    (1778, 2975, 0.0113, 1, 0, 1, 1), -- 6Hunting Boots
    (1778, 4678, 0.0113, 1, 0, 1, 1), -- 6Veteran Girdle
    (1778, 4569, 0.0103, 1, 0, 1, 1), -- 5Staunch Hammer
    (1778, 15933, 0.0103, 1, 0, 1, 1), -- 5Simple Branch
    (1778, 7288, 0.0093, 1, 0, 1, 1), -- 5Pattern: Rugged Leather Pants
    (1778, 2406, 0.0093, 1, 0, 1, 1), -- 5Pattern: Fine Leather Boots
    (1778, 21808, -0.0093, 1, 0, 1, 1), -- 6Arcane Core
    (1778, 5574, 0.0093, 1, 0, 1, 1), -- 6White Leather Bag
    (1778, 2407, 0.0082, 1, 0, 1, 1), -- 5Pattern: White Leather Jerkin
    (1778, 9764, 0.0082, 1, 0, 1, 1), -- 5Cadet Shield
    (1778, 2657, 0.0082, 1, 0, 1, 1), -- 6Red Leather Bag
    (1778, 9756, 0.0072, 1, 0, 1, 1), -- 5Gypsy Trousers
    (1778, 2972, 0.0072, 1, 0, 1, 1), -- 6Spellbinder Gloves
    (1778, 2979, 0.0072, 1, 0, 1, 1), -- 6Veteran Boots
    (1778, 9763, 0.0062, 1, 0, 1, 1), -- 5Cadet Leggings
    (1778, 2408, 0.0062, 1, 0, 1, 1), -- 5Pattern: Fine Leather Gloves
    (1778, 2834, -0.0062, 1, 0, 1, 1), -- 6Embalming Ichor
    (1778, 3207, 0.0062, 1, 0, 1, 1), -- 6Hunting Bracers
    (1778, 6549, 0.0062, 1, 0, 1, 1), -- 6Soldier's Cloak
    (1778, 4408, 0.0041, 1, 0, 1, 1), -- 5Schematic: Mechanical Squirrel Box
    (1778, 2876, -0.0041, 1, 0, 1, 1), -- 6Duskbat Pelt
    (1778, 20797, -0.0041, 1, 0, 1, 1), -- 6Lynx Collar
    (1778, 856, 0.0041, 1, 0, 1, 1), -- 6Blue Leather Bag
    (1778, 2859, -0.0031, 1, 0, 1, 1), -- 6Vile Fin Scale
    (1778, 20482, -0.0031, 1, 0, 1, 1), -- 6Arcane Sliver
    (1778, 12223, 0.0031, 1, 0, 1, 1), -- 6Meaty Bat Wing
    (1778, 6271, 0.0021, 1, 0, 1, 1), -- 5Pattern: Red Linen Vest
    (1778, 4292, 0.0021, 1, 0, 1, 1), -- 5Pattern: Green Woolen Bag
    (1778, 2409, 0.0021, 1, 0, 1, 1), -- 5Pattern: Dark Leather Tunic
    (1778, 2070, 0.0021, 1, 0, 1, 1), -- 6Darnassian Bleu
    (1778, 20764, -0.0021, 1, 0, 1, 1), -- 6Prospector Anvilward's Head
    (1778, 20772, -0.0021, 1, 0, 1, 1), -- 6Springpaw Pelt
    (1778, 23334, 0.0021, 1, 0, 1, 1), -- 6Cracked Power Core
    (1778, 52077, 0.0021, 1, 0, 1, 1), -- 6Urgent Scarlet Memorandum
    (1778, 60615, -0.0021, 1, 0, 1, 1), -- 6Durotar Crocolisk Tooth
    (1778, 5523, 0.0021, 1, 0, 1, 1), -- 6Small Barnacled Clam
    (1778, 20848, 0.0021, 1, 0, 1, 1), -- 7Sparkling Dust
    (1778, 2881, 0.0010, 1, 0, 1, 1), -- 5Plans: Runed Copper Breastplate
    (1778, 4293, 0.0010, 1, 0, 1, 1), -- 5Pattern: Hillman's Leather Vest
    (1778, 4346, 0.0010, 1, 0, 1, 1), -- 5Pattern: Heavy Woolen Cloak
    (1778, 4409, 0.0010, 1, 0, 1, 1), -- 5Schematic: Small Seaforium Charge
    (1778, 6348, 0.0010, 1, 0, 1, 1), -- 5Formula: Enchant Weapon - Minor Beastslayer
    (1778, 159, 0.0010, 1, 0, 1, 1), -- 6Refreshing Spring Water
    (1778, 2858, -0.001, 1, 0, 1, 1), -- 6Darkhound Blood
    (1778, 3162, -0.001, 1, 0, 1, 1), -- 6Notched Rib
    (1778, 4751, -0.001, 1, 0, 1, 1), -- 6Windfury Talon
    (1778, 4769, -0.001, 1, 0, 1, 1), -- 6Trophy Swoop Quill
    (1778, 4888, -0.001, 1, 0, 1, 1), -- 6Crawler Mucus
    (1778, 20799, -0.001, 1, 0, 1, 1), -- 6Felendren's Head
    (1778, 27668, 0.0010, 1, 0, 1, 1), -- 6Lynx Meat
    (1778, 52079, 0.0010, 1, 0, 1, 1), -- 6A Scarlet Letter
    (1778, 4560, 0.0010, 1, 0, 1, 1), -- 6Fine Scimitar
    (1778, 766, 0.0010, 1, 0, 1, 1), -- 6Flanged Mace
    (1778, 5469, 0.0010, 1, 0, 1, 1), -- 6Strider Meat
    (1778, 2452, 0.0010, 1, 0, 1, 1), -- 6Swiftthistle
    (1778, 1468, 0.0010, 1, 0, 1, 1), -- 6Murloc Fin
    (1778, 20812, 0.0010, 1, 0, 1, 1), -- 7Tattered Pelt
    (1778, 20845, 0.0010, 1, 0, 1, 1), -- 7Torn Wyrm Scale
    (1778, 20847, 0.0010, 1, 0, 1, 1), -- 7Wraith Fragment
    (1778, 62391, 0.0010, 1, 0, 1, 1), -- 7Cat Hair
    (1778, 21006, 0.0010, 1, 0, 1, 1), -- 7Unkempt Pants
    (1778, 21005, 0.0010, 1, 0, 1, 1), -- 7Unkempt Gloves
    (1778, 21010, 0.0010, 1, 0, 1, 1), -- 7Scraggy Leather Boots
    (1778, 21007, 0.0010, 1, 0, 1, 1); -- 7Unkempt Robe
     
       
    -- Data mined from www.wowhead.com
    -- Generated by Loot.php November 29, 2012 by Maibenrai
    --  http://www.wowhead.com/npc=1765
    DELETE FROM `creature_loot_template` WHERE `entry` = 1765;
    INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
    (1765, 62328, 85.4053, 1, 0, 1, 1), -- 7Shed Fur
    (1765, 60743, 84.4924, 1, 0, 1, 1), -- 7Diseased Beast Guts
    (1765, 2672, 83.5304, 1, 0, 1, 1), -- 6Stringy Wolf Meat
    (1765, 60742, -41.9314, 1, 0, 1, 1), --
    (1765, 3299, 13.8183, 1, 0, 1, 1), -- 7Fractured Canine
    (1765, 774, 0.7875, 1, 0, 1, 1), -- 5Malachite
    (1765, 1416, 0.3157, 1, 0, 1, 1), -- 7Rusty Hatchet
    (1765, 1414, 0.2897, 1, 0, 1, 1), -- 7Cracked Sledge
    (1765, 1413, 0.2814, 1, 0, 1, 1), -- 7Feeble Sword
    (1765, 2773, 0.2786, 1, 0, 1, 1), -- 7Cracked Shortbow
    (1765, 1411, 0.2749, 1, 0, 1, 1), -- 7Withered Staff
    (1765, 1415, 0.2582, 1, 0, 1, 1), -- 7Carpenter's Mallet
    (1765, 1419, 0.2554, 1, 0, 1, 1), -- 7Worn Leather Boots
    (1765, 8181, 0.2545, 1, 0, 1, 1), -- 6Hunting Rifle
    (1765, 2774, 0.2433, 1, 0, 1, 1), -- 7Rust-Covered Blunderbuss
    (1765, 2138, 0.2387, 1, 0, 1, 1), -- 7Sharpened Letter Opener
    (1765, 1412, 0.2294, 1, 0, 1, 1), -- 7Crude Bastard Sword
    (1765, 818, 0.2284, 1, 0, 1, 1), -- 5Tigerseye
    (1765, 1417, 0.2266, 1, 0, 1, 1), -- 7Beaten Battle Axe
    (1765, 2959, 0.2257, 1, 0, 1, 1), -- 6Journeyman's Boots
    (1765, 4666, 0.2219, 1, 0, 1, 1), -- 6Burnt Leather Belt
    (1765, 1429, 0.2210, 1, 0, 1, 1), -- 7Patchwork Cloak
    (1765, 1433, 0.2182, 1, 0, 1, 1), -- 7Patchwork Armor
    (1765, 1418, 0.2145, 1, 0, 1, 1), -- 7Worn Leather Belt
    (1765, 2648, 0.2136, 1, 0, 1, 1), -- 7Loose Chain Vest
    (1765, 4663, 0.2099, 1, 0, 1, 1), -- 6Journeyman's Belt
    (1765, 3370, 0.2062, 1, 0, 1, 1), -- 7Patchwork Belt
    (1765, 1423, 0.2043, 1, 0, 1, 1), -- 7Worn Leather Pants
    (1765, 1422, 0.1987, 1, 0, 1, 1), -- 7Worn Leather Gloves
    (1765, 1420, 0.1969, 1, 0, 1, 1), -- 7Worn Leather Bracers
    (1765, 768, 0.1959, 1, 0, 1, 1), -- 6Lumberjack Axe
    (1765, 1431, 0.1941, 1, 0, 1, 1), -- 7Patchwork Pants
    (1765, 2960, 0.1913, 1, 0, 1, 1), -- 6Journeyman's Gloves
    (1765, 1430, 0.1913, 1, 0, 1, 1), -- 7Patchwork Gloves
    (1765, 4563, 0.1848, 1, 0, 1, 1), -- 6Billy Club
    (1765, 3373, 0.1839, 1, 0, 1, 1), -- 7Patchwork Bracers
    (1765, 1427, 0.1839, 1, 0, 1, 1), -- 7Patchwork Shoes
    (1765, 2645, 0.1811, 1, 0, 1, 1), -- 7Loose Chain Gloves
    (1765, 2642, 0.1774, 1, 0, 1, 1), -- 7Loose Chain Boots
    (1765, 6520, 0.1755, 1, 0, 1, 1), -- 6Pioneer Cloak
    (1765, 8178, 0.1737, 1, 0, 1, 1), -- 5Training Sword
    (1765, 2646, 0.1727, 1, 0, 1, 1), -- 7Loose Chain Pants
    (1765, 4562, 0.1681, 1, 0, 1, 1), -- 5Severing Axe
    (1765, 2212, 0.1653, 1, 0, 1, 1), -- 7Cracked Buckler
    (1765, 2968, 0.1597, 1, 0, 1, 1), -- 6Warrior's Gloves
    (1765, 6514, 0.1588, 1, 0, 1, 1), -- 6Disciple's Cloak
    (1765, 2213, 0.1588, 1, 0, 1, 1), -- 7Worn Large Shield
    (1765, 1425, 0.1560, 1, 0, 1, 1), -- 7Worn Leather Vest
    (1765, 2643, 0.1560, 1, 0, 1, 1), -- 7Loose Chain Bracers
    (1765, 2963, 0.1514, 1, 0, 1, 1), -- 6Burnt Leather Boots
    (1765, 727, 0.1495, 1, 0, 1, 1), -- 5Notched Shortsword
    (1765, 6513, 0.1449, 1, 0, 1, 1), -- 6Disciple's Sash
    (1765, 3164, 0.1365, 1, 0, 1, 1), -- 6Discolored Worg Heart
    (1765, 6508, 0.1337, 1, 0, 1, 1), -- 6Infantry Cloak
    (1765, 2962, 0.1328, 1, 0, 1, 1), -- 5Burnt Leather Breeches
    (1765, 2635, 0.1272, 1, 0, 1, 1), -- 7Loose Chain Belt
    (1765, 2958, 0.1226, 1, 0, 1, 1), -- 5Journeyman's Pants
    (1765, 2966, 0.1161, 1, 0, 1, 1), -- 5Warrior's Pants
    (1765, 3214, 0.1142, 1, 0, 1, 1), -- 6Warrior's Bracers
    (1765, 6517, 0.1142, 1, 0, 1, 1), -- 6Pioneer Belt
    (1765, 6519, 0.1124, 1, 0, 1, 1), -- 6Pioneer Bracers
    (1765, 3200, 0.1114, 1, 0, 1, 1), -- 6Burnt Leather Bracers
    (1765, 4662, 0.1114, 1, 0, 1, 1), -- 6Journeyman's Cloak
    (1765, 7350, 0.1059, 1, 0, 1, 1), -- 6Disciple's Bracers
    (1765, 6337, 0.1012, 1, 0, 1, 1), -- 5Infantry Leggings
    (1765, 8180, 0.0919, 1, 0, 1, 1), -- 5Hunting Bow
    (1765, 4658, 0.0919, 1, 0, 1, 1), -- 6Warrior's Cloak
    (1765, 4659, 0.0873, 1, 0, 1, 1), -- 6Warrior's Girdle
    (1765, 3189, 0.0864, 1, 0, 1, 1), -- 6Wood Chopper
    (1765, 4665, 0.0854, 1, 0, 1, 1), -- 6Burnt Cloak
    (1765, 2964, 0.0854, 1, 0, 1, 1), -- 6Burnt Leather Gloves
    (1765, 3641, 0.0836, 1, 0, 1, 1), -- 6Journeyman's Bracers
    (1765, 6509, 0.0836, 1, 0, 1, 1), -- 6Infantry Belt
    (1765, 2140, 0.0817, 1, 0, 1, 1), -- 5Carving Knife
    (1765, 2967, 0.0789, 1, 0, 1, 1), -- 6Warrior's Boots
    (1765, 6507, 0.0761, 1, 0, 1, 1), -- 6Infantry Bracers
    (1765, 2598, 0.0752, 1, 0, 1, 1), -- 5Pattern: Red Linen Robe
    (1765, 4561, 0.0715, 1, 0, 1, 1), -- 5Scalping Tomahawk
    (1765, 5069, 0.0669, 1, 0, 1, 1), -- 5Fire Wand
    (1765, 767, 0.0650, 1, 0, 1, 1), -- 6Long Bo Staff
    (1765, 3190, 0.0650, 1, 0, 1, 1), -- 6Beatstick
    (1765, 15895, 0.0650, 1, 0, 1, 1), -- 6Burnt Buckler
    (1765, 7351, 0.0650, 1, 0, 1, 1), -- 6Disciple's Boots
    (1765, 9744, 0.0650, 1, 0, 1, 1), -- 6Simple Bands
    (1765, 828, 0.0641, 1, 0, 1, 1), -- 6Small Blue Pouch
    (1765, 9745, 0.0631, 1, 0, 1, 1), -- 6Simple Cape
    (1765, 5572, 0.0585, 1, 0, 1, 1), -- 6Small Green Pouch
    (1765, 7109, 0.0585, 1, 0, 1, 1), -- 6Pioneer Buckler
    (1765, 9753, 0.0576, 1, 0, 1, 1), -- 5Gypsy Buckler
    (1765, 6518, 0.0576, 1, 0, 1, 1), -- 6Pioneer Boots
    (1765, 2075, 0.0566, 1, 0, 1, 1), -- 5Heavy Mace
    (1765, 4677, 0.0566, 1, 0, 1, 1), -- 6Veteran Cloak
    (1765, 3192, 0.0548, 1, 0, 1, 1), -- 5Short Bastard Sword
    (1765, 15925, 0.0529, 1, 0, 1, 1), -- 5Journeyman's Stave
    (1765, 3609, 0.0520, 1, 0, 1, 1), -- 5Plans: Copper Chain Vest
    (1765, 4496, 0.0520, 1, 0, 1, 1), -- 6Small Brown Pouch
    (1765, 15932, 0.0511, 1, 0, 1, 1), -- 5Disciple's Stein
    (1765, 1438, 0.0492, 1, 0, 1, 1), -- 6Warrior's Shield
    (1765, 9751, 0.0492, 1, 0, 1, 1), -- 6Gypsy Sandals
    (1765, 9742, 0.0474, 1, 0, 1, 1), -- 6Simple Cord
    (1765, 6515, 0.0464, 1, 0, 1, 1), -- 6Disciple's Gloves
    (1765, 7108, 0.0446, 1, 0, 1, 1), -- 5Infantry Shield
    (1765, 9752, 0.0436, 1, 0, 1, 1), -- 6Gypsy Bands
    (1765, 9754, 0.0427, 1, 0, 1, 1), -- 6Gypsy Cloak
    (1765, 9761, 0.0399, 1, 0, 1, 1), -- 6Cadet Cloak
    (1765, 2957, 0.0390, 1, 0, 1, 1), -- 5Journeyman's Vest
    (1765, 2961, 0.0390, 1, 0, 1, 1), -- 5Burnt Leather Vest
    (1765, 2965, 0.0390, 1, 0, 1, 1), -- 5Warrior's Tunic
    (1765, 9743, 0.0381, 1, 0, 1, 1), -- 6Simple Shoes
    (1765, 5571, 0.0371, 1, 0, 1, 1), -- 6Small Black Pouch
    (1765, 6506, 0.0371, 1, 0, 1, 1), -- 6Infantry Boots
    (1765, 6511, 0.0362, 1, 0, 1, 1), -- 5Journeyman's Robe
    (1765, 805, 0.0362, 1, 0, 1, 1), -- 6Small Red Pouch
    (1765, 9750, 0.0353, 1, 0, 1, 1), -- 6Gypsy Sash
    (1765, 6521, 0.0334, 1, 0, 1, 1), -- 6Pioneer Gloves
    (1765, 9758, 0.0316, 1, 0, 1, 1), -- 6Cadet Belt
    (1765, 6510, 0.0297, 1, 0, 1, 1), -- 6Infantry Gauntlets
    (1765, 6267, 0.0288, 1, 0, 1, 1), -- 5Disciple's Pants
    (1765, 4566, 0.0279, 1, 0, 1, 1), -- 5Sturdy Quarterstaff
    (1765, 6269, 0.0260, 1, 0, 1, 1), -- 5Pioneer Trousers
    (1765, 9746, 0.0241, 1, 0, 1, 1), -- 6Simple Gloves
    (1765, 4577, 0.0204, 1, 0, 1, 1), -- 5Compact Shotgun
    (1765, 9760, 0.0195, 1, 0, 1, 1), -- 6Cadet Bracers
    (1765, 4683, 0.0186, 1, 0, 1, 1), -- 6Spellbinder Cloak
    (1765, 9762, 0.0186, 1, 0, 1, 1), -- 6Cadet Gauntlets
    (1765, 4684, 0.0167, 1, 0, 1, 1), -- 6Spellbinder Belt
    (1765, 6336, 0.0158, 1, 0, 1, 1), -- 5Infantry Tunic
    (1765, 4689, 0.0158, 1, 0, 1, 1), -- 6Hunting Cloak
    (1765, 6512, 0.0149, 1, 0, 1, 1), -- 5Disciple's Robe
    (1765, 4564, 0.0139, 1, 0, 1, 1), -- 5Spiked Club
    (1765, 9759, 0.0130, 1, 0, 1, 1), -- 6Cadet Boots
    (1765, 6268, 0.0111, 1, 0, 1, 1), -- 5Pioneer Tunic
    (1765, 3213, 0.0111, 1, 0, 1, 1), -- 6Veteran Bracers
    (1765, 6271, 0.0102, 1, 0, 1, 1), -- 5Pattern: Red Linen Vest
    (1765, 2555, 0.0102, 1, 0, 1, 1), -- 5Recipe: Swiftness Potion
    (1765, 4408, 0.0102, 1, 0, 1, 1), -- 5Schematic: Mechanical Squirrel Box
    (1765, 5635, 0.0093, 1, 0, 1, 1), -- 6Sharp Claw
    (1765, 4690, 0.0084, 1, 0, 1, 1), -- 6Hunting Belt
    (1765, 7288, 0.0074, 1, 0, 1, 1), -- 5Pattern: Rugged Leather Pants
    (1765, 2406, 0.0074, 1, 0, 1, 1), -- 5Pattern: Fine Leather Boots
    (1765, 9755, 0.0074, 1, 0, 1, 1), -- 6Gypsy Gloves
    (1765, 6342, 0.0065, 1, 0, 1, 1), -- 5Formula: Enchant Chest - Minor Mana
    (1765, 6266, 0.0065, 1, 0, 1, 1), -- 5Disciple's Vest
    (1765, 2408, 0.0065, 1, 0, 1, 1), -- 5Pattern: Fine Leather Gloves
    (1765, 3610, 0.0065, 1, 0, 1, 1), -- 5Plans: Gemmed Copper Gauntlets
    (1765, 3651, 0.0065, 1, 0, 1, 1), -- 5Veteran Shield
    (1765, 21808, -0.0065, 1, 0, 1, 1), -- 6Arcane Core
    (1765, 2589, 0.0065, 1, 0, 1, 1), -- 6Linen Cloth
    (1765, 3300, 0.0056, 1, 0, 1, 1), -- 7Rabbit's Foot
    (1765, 2876, -0.0046, 1, 0, 1, 1), -- 6Duskbat Pelt
    (1765, 2553, 0.0028, 1, 0, 1, 1), -- 5Recipe: Elixir of Minor Agility
    (1765, 9764, 0.0028, 1, 0, 1, 1), -- 5Cadet Shield
    (1765, 3652, 0.0028, 1, 0, 1, 1), -- 5Hunting Buckler
    (1765, 2070, 0.0028, 1, 0, 1, 1), -- 6Darnassian Bleu
    (1765, 52077, 0.0028, 1, 0, 1, 1), -- 6Urgent Scarlet Memorandum
    (1765, 7074, 0.0028, 1, 0, 1, 1), -- 7Chipped Claw
    (1765, 2407, 0.0019, 1, 0, 1, 1), -- 5Pattern: White Leather Jerkin
    (1765, 15933, 0.0019, 1, 0, 1, 1), -- 5Simple Branch
    (1765, 2834, -0.0019, 1, 0, 1, 1), -- 6Embalming Ichor
    (1765, 20482, -0.0019, 1, 0, 1, 1), -- 6Arcane Sliver
    (1765, 20772, -0.0019, 1, 0, 1, 1), -- 6Springpaw Pelt
    (1765, 52564, 0.0019, 1, 0, 1, 1), -- 6Burning Blade Spellscroll
    (1765, 2674, 0.0019, 1, 0, 1, 1), -- 6Crawler Meat
    (1765, 7101, 0.0019, 1, 0, 1, 1), -- 7Bug Eye
    (1765, 68194, 0.0009, 1, 0, 1, 1), -- 4Oggleflint's Inspirer
    (1765, 3314, 0.0009, 1, 0, 1, 1), -- 5Ceremonial Leather Gloves
    (1765, 2855, -0.0009, 1, 0, 1, 1), -- 6Putrid Claw
    (1765, 2859, -0.0009, 1, 0, 1, 1), -- 6Vile Fin Scale
    (1765, 3162, -0.0009, 1, 0, 1, 1), -- 6Notched Rib
    (1765, 3635, -0.0009, 1, 0, 1, 1), -- 6Maggot Eye's Paw
    (1765, 20797, -0.0009, 1, 0, 1, 1), -- 6Lynx Collar
    (1765, 21776, -0.0009, 1, 0, 1, 1), -- 6Captain Kelisendra's Lost Rutters
    (1765, 21781, -0.0009, 1, 0, 1, 1), -- 6Thaelis' Head
    (1765, 52080, -0.0009, 1, 0, 1, 1), -- 6Fresh Crawler Meat
    (1765, 118, 0.0009, 1, 0, 1, 1), -- 6Minor Healing Potion
    (1765, 4560, 0.0009, 1, 0, 1, 1), -- 6Fine Scimitar
    (1765, 5466, 0.0009, 1, 0, 1, 1), -- 6Scorpid Stinger
    (1765, 4339, 0.0009, 1, 0, 1, 1), -- 6Bolt of Mageweave
    (1765, 4874, 0.0009, 1, 0, 1, 1), -- 7Clean Fishbones
    (1765, 23333, 0.0009, 1, 0, 1, 1), -- 7Shattered Power Core
    (1765, 67391, 0.0009, 1, 0, 1, 1), -- 7Polished Skull
    (1765, 21007, 0.0009, 1, 0, 1, 1), -- 7Unkempt Robe
    (1765, 1510, 0.0009, 1, 0, 1, 1); -- 7Heavy Hammer
     
    UPDATE `creature_template` SET `questItem2` = 60742 WHERE `entry` = 1778;
    UPDATE `creature_template` SET `questItem1` = 60742 WHERE `entry` = 1765;
     
    REPLACE INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
    (44825, 0, 0, 'You better bring that bat back in one piece, $N!', 12, 0, 100, 25, 0, 0, ''),
    (44821, 0, 0, 'Eliminate all murlocs by using the Blight Concoction!$B$B|r|TInterface\Icons\INV_ALCHEMY_POTION_05.BLP:24|t', 42, 1, 100, 0, 0, 0, ''),
    (44821, 1, 0, 'Returning to Forsaken High Command!$B$B|r|TInterface\Icons\ACHIEVEMENT_ZONE_SILVERPINE_01.BLP:24|t', 42, 1, 100, 0, 0, 0, '');
     
     
    UPDATE `creature_template` SET `gossip_menu_id` = 11892 WHERE `entry` = 44825;
    UPDATE `gossip_menu_option` SET `option_id`='1', `npc_option_npcflag`='8195' WHERE (`menu_id`='11892') AND (`id`='1');
    UPDATE `gossip_menu_option` SET `option_id`='1', `npc_option_npcflag`='8195' WHERE (`menu_id`='11892') AND (`id`='0');
    UPDATE `gossip_menu_option` SET `option_icon`='2' WHERE (`menu_id`='11892') AND (`id`='1');
    UPDATE `gossip_menu_option` SET `option_id`='4' WHERE (`menu_id`='11892') AND (`id`='1');
     
    UPDATE `creature_template` SET `minlevel` = 11, `maxlevel` = 11, `faction_A` = 1610, `faction_H` = 1610, `npcflag` = 16777224, `VehicleId` = 1051 WHERE `entry` = 44821;
    DELETE FROM `creature_template_addon` WHERE (`entry`=44821);
    INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (44821, 0, 0, 50331648, 0, 0, '');
    -- Bat Handler Maggotbreath
    SET @ENTRY := 44825;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,1,62,0,100,0,11892,0,0,0,86,83584,0,7,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"on gossip select "),
    (@ENTRY,@SOURCETYPE,1,2,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"talk 0"),
    (@ENTRY,@SOURCETYPE,2,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"close gossip");
    UPDATE `creature_template` SET `spell1` = 83573 WHERE `entry` = 44821;
     
     
    -- Forsaken Bat
    SET @ENTRY := 44821;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,54,0,100,0,0,0,0,0,86,46598,0,23,0,0,0,23,0,0,0,0.0,0.0,0.0,0.0,"player enter vehicle"),
    (@ENTRY,@SOURCETYPE,1,0,60,0,100,1,1000,1000,1000,1000,53,1,4482100,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"wp start "),
    (@ENTRY,@SOURCETYPE,2,0,27,0,100,0,0,0,0,0,33,44825,0,0,0,0,0,23,0,0,0,0.0,0.0,0.0,0.0,"give credit to player"),
    (@ENTRY,@SOURCETYPE,3,0,40,0,100,0,3,4482100,0,0,1,0,0,0,0,0,0,23,0,0,0,0.0,0.0,0.0,0.0,"talk 0"),
    (@ENTRY,@SOURCETYPE,4,0,40,0,100,0,20,4482100,0,0,1,1,0,0,0,0,0,23,0,0,0,0.0,0.0,0.0,0.0,"talk 1"),
    (@ENTRY,@SOURCETYPE,5,0,40,0,100,0,21,4482100,0,0,41,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"despawn");
    UPDATE `creature_template` SET `InhabitType` = 4 WHERE `entry` = 44821;
    REPLACE INTO waypoints(entry, pointid, position_x, position_y, position_z) VALUES
     (4482100, 1, 1349.3, 1020.34, 72.8816),
     (4482100, 2, 1194.8, 983.654, 60.1593),
     (4482100, 3, 1213.23, 433.797, 78.5396),
     (4482100, 4, 1225.53, 346.395, 74.7502),
     (4482100, 5, 1192.51, 278.76, 69.3665),
     (4482100, 6, 1148.45, 215.764, 70.6388),
     (4482100, 7, 1051.38, 154.551, 54.9989),
     (4482100, 8, 954.518, 112.691, 51.1877),
     (4482100, 9, 905.487, 82.7673, 53.5746),
     (4482100, 10, 831.469, 43.6282, 52.2309),
     (4482100, 11, 778.553, 60.0191, 50.8719),
     (4482100, 12, 744.348, 135.963, 49.2458),
     (4482100, 13, 721.343, 174.492, 50.9795),
     (4482100, 14, 686.726, 228.547, 51.1728),
     (4482100, 15, 695.595, 313.278, 48.0281),
     (4482100, 16, 748.613, 319.992, 48.1748),
     (4482100, 17, 860.879, 263.353, 54.5126),
     (4482100, 18, 988.018, 303.05, 51.6042),
     (4482100, 19, 1050.98, 348.021, 51.4449),
     (4482100, 20, 1124.67, 405.132, 51.8656),
     (4482100, 21, 1421.07, 1017.94, 56.7301);
     UPDATE `creature_template` SET `speed_walk` = 2, `speed_run` = 3 WHERE `entry` = 44821;
     DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15  AND SourceGroup=11892;
     INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `ConditionTypeOrReference`, `ConditionValue1`) VALUES ('15', '11892', '9', '26998');
     
     
     DELETE FROM `creature` WHERE `id`=1951;
    DELETE FROM `creature` WHERE `id`=1950;
     
    UPDATE `creature_template` SET `unit_flags` = 33536, `unit_flags2` = 2048 WHERE `entry` = 44899;
    DELETE FROM `creature` WHERE `id`=44899;
     
    UPDATE `creature_template` SET `equipment_id` = 44899 WHERE `entry` = 44899;
    UPDATE `creature_template` SET `unit_flags` = 537166592, `unit_flags2` = 2049 WHERE `entry` = 44899;
    UPDATE `quest_template` SET `SourceSpellId` = 83751 WHERE `Id` = 27045;
     
    UPDATE `creature_template` SET `minlevel` = 15, `maxlevel` = 15, `faction_A` = 5, `faction_H` = 5, `npcflag` = 2, `unit_flags` = 32776, `equipment_id` = 44882 WHERE `entry` = 44882;
    DELETE FROM `creature_template_addon` WHERE (`entry`=44882);
    INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (44882, 0, 0, 0, 1, 0, '');
    UPDATE `creature_template` SET `unit_flags` = 537166596 WHERE `entry` = 39086;
    UPDATE `creature_template` SET `unit_flags` = 537166592 WHERE `entry` = 39087;
    REPLACE INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
    (44882, 0, 0, 'We haven''t got much time. Crowly will be arriving shortly.', 12, 0, 100, 5, 0, 0, ''),
    (44882, 1, 0, 'THERE! Hide in the armoire! I''ll hide in the shadow next to you.', 12, 0, 100, 0, 0, 0, ''),
    (44882, 2, 0, 'I live... and die... for the Banshee Queen.', 12, 0, 100, 0, 0, 0, '');
     
     
    -- Deathstalker Rane Yorick
    SET @ENTRY := 44882;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,54,0,100,0,0,0,0,0,80,4488200,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"on summoned call timeaction"),
    (@ENTRY,@SOURCETYPE,1,0,38,0,100,0,0,1,0,0,80,4488201,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"on data set 1 do action list");
     
    -- Deathstalker Rane Yorick
    SET @ENTRY := 4488200;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,0,0,0,0,53,0,4488200,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Move to pos"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 0"),
    (@ENTRY,@SOURCETYPE,2,0,0,0,100,0,35000,35000,0,0,1,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk1"),
    (@ENTRY,@SOURCETYPE,3,0,0,0,100,0,500,500,0,0,11,34189,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"cast 34189 on self"),
    (@ENTRY,@SOURCETYPE,4,0,0,0,100,0,2000,2000,0,0,66,0,0,0,0,0,0,8,0,0,0,0.0,0.0,0.0,4.65,"set orientation"),
    (@ENTRY,@SOURCETYPE,5,0,0,0,100,0,2000,2000,2000,2000,12,44883,3,180000,0,0,0,8,0,0,0,1299.36,1206.64,58.57063,0.0,"after 2 sec summon crowley"),
    (@ENTRY,@SOURCETYPE,6,0,0,0,100,0,0,0,0,0,12,44884,3,180000,0,0,0,8,0,0,0,1296.2,1210.54,58.55333,0.0,"summon Ivar");
     
     
    -- Deathstalker Rane Yorick
    SET @ENTRY := 4488201;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,0,0,0,0,11,46598,0,0,0,0,0,11,44884,15,0,0.0,0.0,0.0,0.0,"enter vehicle"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,7000,7000,0,0,1,2,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 2"),
    (@ENTRY,@SOURCETYPE,2,0,0,0,100,0,6000,6000,0,0,33,44882,0,0,0,0,0,18,100,0,0,0.0,0.0,0.0,0.0,"give credit to player"),
    (@ENTRY,@SOURCETYPE,3,0,0,0,100,0,0,0,0,0,97,15,15,0,0,0,0,8,0,0,0,1296.29,1206.47,58.5,0.0,"jump"),
    (@ENTRY,@SOURCETYPE,4,0,0,0,100,0,1000,1000,0,0,37,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"die self");
     
    -- Lord Darius Crowley
    SET @ENTRY := 44883;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,54,0,100,0,0,0,0,0,80,4488300,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"call time action on summoned");
     
    -- Lord Darius Crowley
    SET @ENTRY := 4488300;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,1313.48,1206.09,58.5119,0.0,"move to pos"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,8000,8000,8000,8000,66,0,0,0,0,0,0,11,44884,30,0,0.0,0.0,0.0,0.0,"set orientation after 8 sec"),
    (@ENTRY,@SOURCETYPE,2,0,0,0,100,0,5000,5000,5000,5000,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 0"),
    (@ENTRY,@SOURCETYPE,3,0,0,0,100,0,19000,19000,19000,19000,1,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 1"),
    (@ENTRY,@SOURCETYPE,4,0,0,0,100,0,8000,8000,8000,8000,1,2,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 2"),
    (@ENTRY,@SOURCETYPE,5,0,0,0,100,0,29000,29000,0,0,1,3,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 3"),
    (@ENTRY,@SOURCETYPE,6,0,0,0,100,0,52000,52000,0,0,69,0,0,0,0,0,0,8,0,0,0,1297.23,1212.63,58.58,0.0,"after 52 sec move"),
    (@ENTRY,@SOURCETYPE,7,0,0,0,100,0,4000,4000,0,0,41,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"force despawn self");
     
    -- Packleader Ivar Bloodfang
    SET @ENTRY := 44884;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,54,0,100,0,0,0,0,0,80,4488400,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"CALL TIME ACTION");
     
     
    -- Packleader Ivar Bloodfang
    SET @ENTRY := 4488400;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,1308.4,1206.28,58.5109,0.0,"move to pos"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,15500,15500,15500,15500,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 0"),
    (@ENTRY,@SOURCETYPE,2,0,0,0,100,0,31000,31000,0,0,1,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"TALK 1"),
    (@ENTRY,@SOURCETYPE,3,0,0,0,100,0,11000,11000,0,0,1,2,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"TALK 2"),
    (@ENTRY,@SOURCETYPE,4,0,0,0,100,0,2000,2000,0,0,1,3,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"TALK 3"),
    (@ENTRY,@SOURCETYPE,5,0,0,0,100,0,17000,17000,0,0,1,4,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"TALK 4"),
    (@ENTRY,@SOURCETYPE,6,0,0,0,100,0,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,1312.2,1208.56,58.51,0.0,"move"),
    (@ENTRY,@SOURCETYPE,7,0,0,0,100,0,2000,2000,0,0,1,5,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 5"),
    (@ENTRY,@SOURCETYPE,8,0,0,0,100,0,5000,5000,0,0,1,6,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 6"),
    (@ENTRY,@SOURCETYPE,9,0,0,0,100,0,5000,5000,0,0,69,0,0,0,0,0,0,8,0,0,0,1313.58,1210.62,58.51,0.0,"move"),
    (@ENTRY,@SOURCETYPE,10,0,0,0,100,0,3000,3000,0,0,1,7,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 7"),
    (@ENTRY,@SOURCETYPE,11,0,0,0,100,0,3000,3000,0,0,45,0,1,0,0,0,0,11,44882,10,0,0.0,0.0,0.0,0.0,"set data 1 to yorrick"),
    (@ENTRY,@SOURCETYPE,12,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,1309.41,1206.23,58.51,0.0,"move"),
    (@ENTRY,@SOURCETYPE,13,0,0,0,100,0,3000,3000,0,0,1,8,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 8"),
    (@ENTRY,@SOURCETYPE,14,0,0,0,100,0,10000,10000,0,0,1,9,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"text 9"),
    (@ENTRY,@SOURCETYPE,15,0,0,0,100,0,0,0,0,0,11,80743,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"cast 80743 self eject passenger"),
    (@ENTRY,@SOURCETYPE,16,0,0,0,100,0,3000,3000,0,0,66,0,0,0,0,0,0,11,44883,30,0,0.0,0.0,0.0,0.0,"orientation crowley"),
    (@ENTRY,@SOURCETYPE,17,0,0,0,100,0,1000,1000,0,0,1,10,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 10"),
    (@ENTRY,@SOURCETYPE,18,0,0,0,100,0,7000,7000,0,0,59,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"set run self"),
    (@ENTRY,@SOURCETYPE,19,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,1297.07,1212.5,58.49,0.0,"move to pos"),
    (@ENTRY,@SOURCETYPE,20,0,0,0,100,0,3000,3000,0,0,41,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"force despawn");
     
    UPDATE `creature_template` SET `minlevel` = 20, `maxlevel` = 20, `faction_A` = 2173, `faction_H` = 2173, `unit_flags` = 33536, `equipment_id` = 44883 WHERE `entry` = 44883;
    UPDATE `creature_template` SET `unit_flags` = 33536 WHERE `entry` = 44884;
     
    REPLACE INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
    (44883, 0, 0, 'Have you given any more thought to my proposal, Ivar?', 12, 0, 100, 6, 0, 0, ''),
    (44883, 1, 0, 'If we''re to win this war we will need your help. Our packs must unite! The Forsaken will destroy us otherwise.', 12, 0, 100, 396, 0, 0, ''),
    (44883, 2, 0, 'You are the alpha mate, Ivar. The rest of the ferals in Silverpine will do as you command.', 12, 0, 100, 397, 0, 0, ''),
    (44883, 3, 0, 'So will you help?', 12, 0, 100, 6, 0, 0, ''),
    (44884, 0, 0, 'Why trust you now, Crowley? You abandoned us. Left us to die.', 12, 0, 100, 6, 0, 0, ''),
    (44884, 1, 0, 'I don''t care about your war, Crowley.', 12, 0, 100, 274, 0, 0, ''),
    (44884, 2, 0, 'But...', 12, 0, 100, 1, 0, 0, ''),
    (44884, 3, 0, 'I have seen firsthand what the Forsaken of capable of doing. It is true. They hunt us... slaughter the defenseless.', 12, 0, 100, 1, 0, 0, ''),
    (44884, 4, 0, 'Aye, I will gather my pack... we...', 12, 0, 100, 1, 0, 0, ''),
    (44884, 5, 0, '%s sniffs the air.', 16, 0, 100, 479, 0, 0, ''),
    (44884, 6, 0, 'It would appear that we are being watched, Crowley. You have grown soft... Likely Greymane''s fault.', 12, 0, 100, 1, 0, 0, ''),
    (44884, 7, 0, 'Treacherous little pup!', 12, 0, 100, 15, 0, 0, ''),
    (44884, 8, 0, 'What say you now, spy?', 12, 0, 100, 0, 0, 0, ''),
    (44884, 9, 0, 'I was hoping you''d say that...', 12, 0, 100, 0, 0, 0, ''),
    (44884, 10, 0, 'I will prepare the pack. It will take some time to gather them all, but we will join... for now.', 12, 0, 100, 1, 0, 0, '');
     
     
     
    REPLACE INTO waypoints(entry, pointid, position_x, position_y, position_z) VALUES
    (4488200, 1, 1290.64, 1199.6, 52.6067),
    (4488200, 2, 1290.97, 1207.31, 52.6957),
    (4488200, 3, 1304.15, 1207.26, 53.7452),
    (4488200, 4, 1305.02, 1221.21, 53.7452),
    (4488200, 5, 1298.04, 1221.44, 53.7452),
    (4488200, 6, 1296.98, 1205.85, 58.4962),
    (4488200, 7, 1307.24, 1206.27, 58.5102),
    (4488200, 8, 1312.84, 1209.18, 58.5116),
    (4488200, 9, 1313.81, 1211.76, 58.5015);
     
     
    UPDATE `creature_template` SET `minlevel` = 20, `maxlevel` = 20, `faction_A` = 2173, `faction_H` = 2173, `VehicleId` = 1059 WHERE `entry` = 44884;
    UPDATE `creature_template` SET `minlevel` = 12, `maxlevel` = 12, `faction_A` = 5, `faction_H` = 5, `unit_flags` = 8, `VehicleId` = 1055 WHERE `entry` = 44893;
     
    DELETE FROM `creature` WHERE `id`=44893;
    INSERT INTO `creature` (`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
    (44893, 0, 130, 239, 1, 1, 34165, 0, 1315.06, 1211.81, 58.5562, 4.67748, 500, 0, 0, 42, 0, 0, 0, 0, 0);
    UPDATE `creature_template` SET `npcflag` = 16777216 WHERE `entry` = 44894;
    UPDATE `creature_template` SET `unit_flags` = 33554440 WHERE `entry` = 44893;
     
    UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 44894;
    DELETE FROM `smart_scripts` WHERE (`entryorguid`=44894 AND `source_type`=0);
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (44894, 0, 0, 0, 64, 0, 100, 0, 0, 0, 0, 0, 86, 83788, 0, 7, 0, 0, 0, 19, 44893, 10, 0, 0, 0, 0, 0, "Test");
     
     
    DELETE FROM `creature_addon` WHERE (`guid`=59001);
    DELETE FROM `creature_addon` WHERE (`guid`=59122);
    DELETE FROM `creature_template_addon` WHERE (`entry`=44916);
    INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (44916, 0, 0, 65536, 0, 0, 83847);
    DELETE FROM `creature_template_addon` WHERE (`entry`=44917);
    INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (44917, 0, 0, 65536, 1, 0, '');
    -- Quest chain for starting quest #27082: Playing Dirty
    UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 27082;
    UPDATE `quest_template` SET `PrevQuestId` = 27082, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 27088;
     
     
    DELETE FROM `creature_template_addon` WHERE (`entry`=45228);
    INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (45228, 0, 0, 0, 257, 0, '');
    DELETE FROM `creature_template_addon` WHERE (`entry`=45225);
    INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (45225, 0, 0, 0, 1, 0, '');
     
    INSERT INTO `creature` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
    (44365, 0, 1, 1, 500.622, 1564.54, 128.3453, 4.29351, 120, 0, 0); -- 44365 (Area: 228)
    -- Quest chain for starting quest #27333: Losing Ground
    UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 27349, `ExclusiveGroup` = 0 WHERE `Id` = 27333;
    UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 27349, `ExclusiveGroup` = 0 WHERE `Id` = 27345;
    UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 27349;
    UPDATE `quest_template` SET `PrevQuestId` = 27349, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 27350;
    UPDATE `quest_template` SET `PrevQuestId` = 27350, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 27360;
     
    -- Quest chain for starting quest #27364: On Whose Orders?
    UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 27364;
    UPDATE `quest_template` SET `PrevQuestId` = 27364, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 27401;
    UPDATE `quest_template` SET `PrevQuestId` = 27401, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 27405;
    UPDATE `quest_template` SET `PrevQuestId` = 27405, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 27406;
     
    -- Quest chain for starting quest #27548: Lessons in Fear
    UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 27548;
    UPDATE `quest_template` SET `PrevQuestId` = 27548, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 27577;
     
    -- Quest chain for starting quest #27550: Pyrewood's Fall
    UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 27550;
    UPDATE `quest_template` SET `PrevQuestId` = 27550, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 27580;
    UPDATE `quest_template` SET `PrevQuestId` = 27580, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 27594;
     
     
    -- Quest chain for starting quest #28089: Warchief's Command: Hillsbrad Foothills!
    UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 28096, `ExclusiveGroup` = 0 WHERE `Id` = 28089;
    UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 28096, `ExclusiveGroup` = 0 WHERE `Id` = 28571;
    UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 28096;
    UPDATE `quest_template` SET `PrevQuestId` = 28096, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 28111;
    UPDATE `quest_template` SET `PrevQuestId` = 28111, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 28138;
     
     
    DELETE FROM `creature` WHERE `id`=44915;
     
    UPDATE `quest_template` SET `SourceSpellId` = 83839 WHERE `Id` = 27069;
    UPDATE `creature_template` SET `minlevel` = 9, `maxlevel` = 9, `faction_A` = 5, `faction_H` = 5, `unit_flags` = 33288, `VehicleId` = 1060, `HoverHeight` = 1 WHERE `entry` = 44914;
    DELETE FROM `creature_text` WHERE `entry`=44914;
    INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
    (44914, 0, 0, 'Dis not so bad. Maybe little heavy, but me ok.', 12, 0, 100, 66, 0, 0, ''),
    (44914, 0, 1, 'Maybe captain carry one box too?', 12, 1, 100, 0, 0, 0, ''),
    (44914, 0, 2, 'Ugh.. dese boxes too heavy. Dey might fall!', 12, 1, 100, 0, 0, 0, ''),
    (44914, 0, 3, 'CAN NO SEE! WHERE TO GO!? WHAT DOING?!', 12, 1, 100, 0, 0, 0, ''),
    (44914, 0, 4, 'НDis hurt so bad. Like da time poop came out sideways.!', 12, 1, 100, 0, 0, 0, ''),
    (44914, 1, 0, 'Where to put? Dey falling! HELP!', 12, 1, 100, 0, 0, 0, ''),
    (44914, 2, 0, 'OOF!', 12, 1, 100, 0, 0, 0, '');
    DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND SourceEntry=83838;
    INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`) VALUES ('13', '1', '83838', '31', '3', '44914');
     
    -- Orc Sea Pup
    SET @ENTRY := 44914;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,8,0,100,0,83838,0,0,0,80,4491400,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"on spellhit call event"),
    (@ENTRY,@SOURCETYPE,1,0,60,0,100,0,0,0,5000,5000,29,0,0,0,0,0,0,23,0,0,0,0.0,0.0,0.0,0.0,"on update follow owner"),
    (@ENTRY,@SOURCETYPE,2,0,8,0,100,0,83865,0,0,0,80,4491401,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"on spellhit");
     
    -- Orc Sea Pup
    SET @ENTRY := 4491400;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,0,0,0,0,11,83835,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"cast 83835 on self"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,1000,1000,0,0,33,44915,0,0,0,0,0,23,0,0,0,0.0,0.0,0.0,0.0,"give credit to player"),
    (@ENTRY,@SOURCETYPE,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 0");
     
     
    -- Orc Crate
    SET @ENTRY := 44915;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,60,0,100,1,500,500,0,0,11,46598,0,0,0,0,0,11,44914,10,0,0.0,0.0,0.0,0.0,"on summon cast 46598 to owner");
     
    DELETE FROM `creature` WHERE `id`=44367;
    INSERT INTO `creature` (`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
    (44367, 0, 130, 928, 1, 1, 33949, 0, 819.152, 1735.18, 22.5499, 4.78279, 7200, 10, 0, 819, 0, 1, 0, 0, 0),
    (44367, 0, 130, 130, 1, 1, 33949, 0, 860.453, 1547.99, 33.4494, 4.66367, 7200, 10, 0, 819, 0, 1, 0, 0, 0);
     
     
    -- Orc Sea Pup
    SET @ENTRY := 4491401;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 1 self"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,2000,2000,0,0,11,68576,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"cast 68576"),
    (@ENTRY,@SOURCETYPE,2,0,0,0,100,0,0,0,0,0,11,35356,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"cast self"),
    (@ENTRY,@SOURCETYPE,3,0,0,0,100,0,2000,2000,0,0,1,2,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 2"),
    (@ENTRY,@SOURCETYPE,4,0,0,0,100,0,3000,3000,0,0,41,2000,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"force despawn"),
    (@ENTRY,@SOURCETYPE,5,0,0,0,100,0,0,0,0,0,51,0,0,0,0,0,0,11,44915,30,0,0.0,0.0,0.0,0.0,"kill 44915"),
    (@ENTRY,@SOURCETYPE,6,0,0,0,100,0,0,0,0,0,28,83839,0,0,0,0,0,23,0,0,0,0.0,0.0,0.0,0.0,"remove 83839 from playuer");
     
    DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND  SourceEntry=83865;
    INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`) VALUES ('13', '1', '83865', '31', '3', '44914');
     
     
     
     
     
    UPDATE `creature_template` SET `unit_flags` = 33280 WHERE `entry` = 44916;
     
     
    UPDATE `quest_template` SET `Flags` = 0 WHERE `Id` = 27095;
    UPDATE `quest_template` SET `PrevQuestId` = 27073 WHERE `Id` = 27095;
     
       
    -- Data mined from www.wowhead.com
    -- Generated by Loot.php November 29, 2012 by Maibenrai
    --  http://www.wowhead.com/npc=35245
    DELETE FROM `creature_loot_template` WHERE `entry` = 35245;
    INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
    (35245, 62340, 77.1639, 1, 0, 1, 1), -- 7Flaky Basilisk Scale
    (35245, 62341, 22.6504, 1, 0, 1, 1), -- 7Gluey Basilisk Tear
    (35245, 818, 0.3708, 1, 0, 1, 1), -- 5Tigerseye
    (35245, 1514, 0.3018, 1, 0, 1, 1), -- 7Rusty Warhammer
    (35245, 1510, 0.2861, 1, 0, 1, 1), -- 7Heavy Hammer
    (35245, 1515, 0.2798, 1, 0, 1, 1), -- 7Rough Wooden Staff
    (35245, 1511, 0.2791, 1, 0, 1, 1), -- 7Commoner's Sword
    (35245, 1516, 0.2581, 1, 0, 1, 1), -- 7Worn Hatchet
    (35245, 2777, 0.2531, 1, 0, 1, 1), -- 7Feeble Shortbow
    (35245, 1512, 0.2524, 1, 0, 1, 1), -- 7Crude Battle Axe
    (35245, 2763, 0.2441, 1, 0, 1, 1), -- 7Fisherman Knife
    (35245, 2778, 0.2298, 1, 0, 1, 1), -- 7Cheap Blunderbuss
    (35245, 1513, 0.2294, 1, 0, 1, 1), -- 7Old Greatsword
    (35245, 1506, 0.2278, 1, 0, 1, 1), -- 7Warped Leather Gloves
    (35245, 1509, 0.2217, 1, 0, 1, 1), -- 7Warped Leather Vest
    (35245, 3374, 0.2207, 1, 0, 1, 1), -- 7Calico Belt
    (35245, 1499, 0.2157, 1, 0, 1, 1), -- 7Calico Pants
    (35245, 1504, 0.2147, 1, 0, 1, 1), -- 7Warped Leather Bracers
    (35245, 1498, 0.2134, 1, 0, 1, 1), -- 7Calico Gloves
    (35245, 1497, 0.2021, 1, 0, 1, 1), -- 7Calico Cloak
    (35245, 1507, 0.1947, 1, 0, 1, 1), -- 7Warped Leather Pants
    (35245, 1502, 0.1934, 1, 0, 1, 1), -- 7Warped Leather Belt
    (35245, 1503, 0.1914, 1, 0, 1, 1), -- 7Warped Leather Boots
    (35245, 1732, 0.1897, 1, 0, 1, 1), -- 7Worn Mail Bracers
    (35245, 1495, 0.1884, 1, 0, 1, 1), -- 7Calico Shoes
    (35245, 1501, 0.1871, 1, 0, 1, 1), -- 7Calico Tunic
    (35245, 1734, 0.1867, 1, 0, 1, 1), -- 7Worn Mail Gloves
    (35245, 3375, 0.1867, 1, 0, 1, 1), -- 7Calico Bracers
    (35245, 2215, 0.1647, 1, 0, 1, 1), -- 7Wooden Shield
    (35245, 1730, 0.1634, 1, 0, 1, 1), -- 7Worn Mail Belt
    (35245, 1737, 0.1571, 1, 0, 1, 1), -- 7Worn Mail Vest
    (35245, 2214, 0.1557, 1, 0, 1, 1), -- 7Wooden Buckler
    (35245, 1735, 0.1547, 1, 0, 1, 1), -- 7Worn Mail Pants
    (35245, 1731, 0.1517, 1, 0, 1, 1), -- 7Worn Mail Boots
    (35245, 8180, 0.1471, 1, 0, 1, 1), -- 5Hunting Bow
    (35245, 3192, 0.1414, 1, 0, 1, 1), -- 5Short Bastard Sword
    (35245, 2140, 0.1407, 1, 0, 1, 1), -- 5Carving Knife
    (35245, 4561, 0.1397, 1, 0, 1, 1), -- 5Scalping Tomahawk
    (35245, 5069, 0.1381, 1, 0, 1, 1), -- 5Fire Wand
    (35245, 1210, 0.1207, 1, 0, 1, 1), -- 5Shadowgem
    (35245, 14090, 0.1160, 1, 0, 1, 1), -- 5Beaded Britches
    (35245, 2075, 0.1150, 1, 0, 1, 1), -- 5Heavy Mace
    (35245, 774, 0.1117, 1, 0, 1, 1), -- 5Malachite
    (35245, 3644, 0.1027, 1, 0, 1, 1), -- 6Barbaric Cloth Bracers
    (35245, 4686, 0.0974, 1, 0, 1, 1), -- 6Barbaric Cloth Cloak
    (35245, 14099, 0.0970, 1, 0, 1, 1), -- 6Native Sash
    (35245, 15010, 0.0954, 1, 0, 1, 1), -- 5Primal Wraps
    (35245, 15297, 0.0950, 1, 0, 1, 1), -- 6Grizzly Bracers
    (35245, 3290, 0.0947, 1, 0, 1, 1), -- 6Ancestral Gloves
    (35245, 15479, 0.0924, 1, 0, 1, 1), -- 5Charger's Armor
    (35245, 3289, 0.0924, 1, 0, 1, 1), -- 6Ancestral Boots
    (35245, 14095, 0.0894, 1, 0, 1, 1), -- 6Native Bands
    (35245, 15009, 0.0850, 1, 0, 1, 1), -- 5Primal Leggings
    (35245, 15302, 0.0847, 1, 0, 1, 1), -- 6Grizzly Belt
    (35245, 3287, 0.0830, 1, 0, 1, 1), -- 5Tribal Pants
    (35245, 3286, 0.0800, 1, 0, 1, 1), -- 6Tribal Gloves
    (35245, 3284, 0.0784, 1, 0, 1, 1), -- 6Tribal Boots
    (35245, 3281, 0.0757, 1, 0, 1, 1), -- 6Battle Chain Gloves
    (35245, 15477, 0.0744, 1, 0, 1, 1), -- 5Charger's Pants
    (35245, 15484, 0.0720, 1, 0, 1, 1), -- 6War Torn Handgrips
    (35245, 4577, 0.0704, 1, 0, 1, 1), -- 5Compact Shotgun
    (35245, 4692, 0.0690, 1, 0, 1, 1), -- 6Ceremonial Cloak
    (35245, 3303, 0.0680, 1, 0, 1, 1), -- 6Brackwater Bracers
    (35245, 3282, 0.0670, 1, 0, 1, 1), -- 5Battle Chain Pants
    (35245, 4566, 0.0637, 1, 0, 1, 1), -- 5Sturdy Quarterstaff
    (35245, 15482, 0.0637, 1, 0, 1, 1), -- 6War Torn Bands
    (35245, 3279, 0.0627, 1, 0, 1, 1), -- 6Battle Chain Boots
    (35245, 4564, 0.0617, 1, 0, 1, 1), -- 5Spiked Club
    (35245, 15486, 0.0574, 1, 0, 1, 1), -- 5War Torn Shield
    (35245, 14094, 0.0557, 1, 0, 1, 1), -- 5Beaded Wraps
    (35245, 15969, 0.0544, 1, 0, 1, 1), -- 5Beaded Orb
    (35245, 3649, 0.0544, 1, 0, 1, 1), -- 6Tribal Buckler
    (35245, 2632, 0.0524, 1, 0, 1, 1), -- 5Curved Dagger
    (35245, 14091, 0.0510, 1, 0, 1, 1), -- 5Beaded Robe
    (35245, 15015, 0.0490, 1, 0, 1, 1), -- 6Lupine Cloak
    (35245, 14110, 0.0487, 1, 0, 1, 1), -- 6Native Sandals
    (35245, 4680, 0.0467, 1, 0, 1, 1), -- 6Brackwater Cloak
    (35245, 727, 0.0460, 1, 0, 1, 1), -- 5Notched Shortsword
    (35245, 4562, 0.0457, 1, 0, 1, 1), -- 5Severing Axe
    (35245, 4672, 0.0454, 1, 0, 1, 1), -- 6Ancestral Belt
    (35245, 15944, 0.0447, 1, 0, 1, 1), -- 5Ancestral Orb
    (35245, 14089, 0.0437, 1, 0, 1, 1), -- 6Beaded Gloves
    (35245, 15480, 0.0427, 1, 0, 1, 1), -- 6War Torn Girdle
    (35245, 14098, 0.0420, 1, 0, 1, 1), -- 6Native Cloak
    (35245, 5071, 0.0407, 1, 0, 1, 1), -- 5Shadow Wand
    (35245, 4569, 0.0387, 1, 0, 1, 1), -- 5Staunch Hammer
    (35245, 15299, 0.0383, 1, 0, 1, 1), -- 6Grizzly Cape
    (35245, 14102, 0.0377, 1, 0, 1, 1), -- 6Native Handwraps
    (35245, 14116, 0.0377, 1, 0, 1, 1), -- 6Aboriginal Cape
    (35245, 3312, 0.0373, 1, 0, 1, 1), -- 6Ceremonial Leather Bracers
    (35245, 3288, 0.0370, 1, 0, 1, 1), -- 5Tribal Vest
    (35245, 15481, 0.0367, 1, 0, 1, 1), -- 6War Torn Greaves
    (35245, 8178, 0.0353, 1, 0, 1, 1), -- 5Training Sword
    (35245, 3291, 0.0350, 1, 0, 1, 1), -- 5Ancestral Woollies
    (35245, 14097, 0.0347, 1, 0, 1, 1), -- 5Native Pants
    (35245, 3285, 0.0327, 1, 0, 1, 1), -- 6Tribal Bracers
    (35245, 4693, 0.0323, 1, 0, 1, 1), -- 6Ceremonial Leather Belt
    (35245, 15301, 0.0320, 1, 0, 1, 1), -- 6Grizzly Slippers
    (35245, 14115, 0.0317, 1, 0, 1, 1), -- 6Aboriginal Bands
    (35245, 14086, 0.0310, 1, 0, 1, 1), -- 6Beaded Sandals
    (35245, 15303, 0.0303, 1, 0, 1, 1), -- 5Grizzly Pants
    (35245, 4669, 0.0293, 1, 0, 1, 1), -- 6Battle Chain Girdle
    (35245, 15008, 0.0290, 1, 0, 1, 1), -- 6Primal Mitts
    (35245, 4687, 0.0290, 1, 0, 1, 1), -- 6Barbaric Cloth Belt
    (35245, 4681, 0.0280, 1, 0, 1, 1), -- 6Brackwater Girdle
    (35245, 4675, 0.0273, 1, 0, 1, 1), -- 6Tribal Belt
    (35245, 15473, 0.0273, 1, 0, 1, 1), -- 6Charger's Boots
    (35245, 15476, 0.0273, 1, 0, 1, 1), -- 6Charger's Handwraps
    (35245, 2589, 0.0270, 1, 0, 1, 1), -- 6Linen Cloth
    (35245, 15013, 0.0267, 1, 0, 1, 1), -- 6Lupine Cuffs
    (35245, 15483, 0.0260, 1, 0, 1, 1), -- 6War Torn Cape
    (35245, 15300, 0.0243, 1, 0, 1, 1), -- 6Grizzly Gloves
    (35245, 15485, 0.0240, 1, 0, 1, 1), -- 5War Torn Pants
    (35245, 3609, 0.0237, 1, 0, 1, 1), -- 5Plans: Copper Chain Vest
    (35245, 2657, 0.0237, 1, 0, 1, 1), -- 6Red Leather Bag
    (35245, 3653, 0.0233, 1, 0, 1, 1), -- 5Ceremonial Buckler
    (35245, 15298, 0.0230, 1, 0, 1, 1), -- 5Grizzly Buckler
    (35245, 15490, 0.0227, 1, 0, 1, 1), -- 6Bloodspattered Cloak
    (35245, 3283, 0.0223, 1, 0, 1, 1), -- 5Battle Chain Tunic
    (35245, 14365, 0.0217, 1, 0, 1, 1), -- 5Mystic's Cape
    (35245, 3292, 0.0210, 1, 0, 1, 1), -- 5Ancestral Tunic
    (35245, 6527, 0.0210, 1, 0, 1, 1), -- 5Ancestral Robe
    (35245, 3036, 0.0210, 1, 0, 1, 1), -- 5Heavy Shortbow
    (35245, 15970, 0.0210, 1, 0, 1, 1), -- 5Native Branch
    (35245, 856, 0.0210, 1, 0, 1, 1), -- 6Blue Leather Bag
    (35245, 2598, 0.0197, 1, 0, 1, 1), -- 5Pattern: Red Linen Robe
    (35245, 48128, -0.0197, 1, 0, 1, 1), -- 6Mountainfoot Iron
    (35245, 3304, 0.0197, 1, 0, 1, 1), -- 6Brackwater Gauntlets
    (35245, 5574, 0.0197, 1, 0, 1, 1), -- 6White Leather Bag
    (35245, 3654, 0.0187, 1, 0, 1, 1), -- 5Brackwater Shield
    (35245, 4570, 0.0180, 1, 0, 1, 1), -- 5Birchwood Maul
    (35245, 2407, 0.0170, 1, 0, 1, 1), -- 5Pattern: White Leather Jerkin
    (35245, 2073, 0.0170, 1, 0, 1, 1), -- 5Dwarven Hatchet
    (35245, 5573, 0.0170, 1, 0, 1, 1), -- 6Green Leather Bag
    (35245, 6342, 0.0163, 1, 0, 1, 1), -- 5Formula: Enchant Chest - Minor Mana
    (35245, 6271, 0.0160, 1, 0, 1, 1), -- 5Pattern: Red Linen Vest
    (35245, 15011, 0.0143, 1, 0, 1, 1), -- 5Lupine Cord
    (35245, 3314, 0.0137, 1, 0, 1, 1), -- 5Ceremonial Leather Gloves
    (35245, 14113, 0.0137, 1, 0, 1, 1), -- 5Aboriginal Sash
    (35245, 3308, 0.0130, 1, 0, 1, 1), -- 5Barbaric Cloth Gloves
    (35245, 15492, 0.0130, 1, 0, 1, 1), -- 5Bloodspattered Sash
    (35245, 3311, 0.0130, 1, 0, 1, 1), -- 6Ceremonial Leather Ankleguards
    (35245, 2555, 0.0127, 1, 0, 1, 1), -- 5Recipe: Swiftness Potion
    (35245, 7288, 0.0123, 1, 0, 1, 1), -- 5Pattern: Rugged Leather Pants
    (35245, 3307, 0.0117, 1, 0, 1, 1), -- 5Barbaric Cloth Boots
    (35245, 15309, 0.0107, 1, 0, 1, 1), -- 5Feral Cloak
    (35245, 2406, 0.0100, 1, 0, 1, 1), -- 5Pattern: Fine Leather Boots
    (35245, 4408, 0.0100, 1, 0, 1, 1), -- 5Schematic: Mechanical Squirrel Box
    (35245, 15491, 0.0100, 1, 0, 1, 1), -- 5Bloodspattered Gloves
    (35245, 2408, 0.0093, 1, 0, 1, 1), -- 5Pattern: Fine Leather Gloves
    (35245, 3302, 0.0083, 1, 0, 1, 1), -- 5Brackwater Boots
    (35245, 3610, 0.0083, 1, 0, 1, 1), -- 5Plans: Gemmed Copper Gauntlets
    (35245, 2553, 0.0077, 1, 0, 1, 1), -- 5Recipe: Elixir of Minor Agility
    (35245, 15495, 0.0073, 1, 0, 1, 1), -- 5Bloodspattered Wristbands
    (35245, 6347, 0.0070, 1, 0, 1, 1), -- 5Formula: Enchant Bracer - Minor Strength
    (35245, 5466, 0.0063, 1, 0, 1, 1), -- 6Scorpid Stinger
    (35245, 2409, 0.0057, 1, 0, 1, 1), -- 5Pattern: Dark Leather Tunic
    (35245, 769, 0.0057, 1, 0, 1, 1), -- 6Chunk of Boar Meat
    (35245, 4409, 0.0053, 1, 0, 1, 1), -- 5Schematic: Small Seaforium Charge
    (35245, 4757, 0.0053, 1, 0, 1, 1), -- 7Cracked Egg Shells
    (35245, 4292, 0.0033, 1, 0, 1, 1), -- 5Pattern: Green Woolen Bag
    (35245, 6348, 0.0033, 1, 0, 1, 1), -- 5Formula: Enchant Weapon - Minor Beastslayer
    (35245, 52564, 0.0033, 1, 0, 1, 1), -- 6Burning Blade Spellscroll
    (35245, 6344, 0.0030, 1, 0, 1, 1), -- 5Formula: Enchant Bracer - Minor Spirit
    (35245, 6716, 0.0030, 1, 0, 1, 1), -- 5Schematic: EZ-Thro Dynamite
    (35245, 4345, 0.0027, 1, 0, 1, 1), -- 5Pattern: Red Woolen Boots
    (35245, 4293, 0.0027, 1, 0, 1, 1), -- 5Pattern: Hillman's Leather Vest
    (35245, 20772, -0.0027, 1, 0, 1, 1), -- 6Springpaw Pelt
    (35245, 2070, 0.0023, 1, 0, 1, 1), -- 6Darnassian Bleu
    (35245, 4888, -0.0023, 1, 0, 1, 1), -- 6Crawler Mucus
    (35245, 56968, 0.0023, 1, 0, 1, 1), -- 7Bug Juice
    (35245, 2881, 0.0020, 1, 0, 1, 1), -- 5Plans: Runed Copper Breastplate
    (35245, 4346, 0.0020, 1, 0, 1, 1), -- 5Pattern: Heavy Woolen Cloak
    (35245, 117, 0.0020, 1, 0, 1, 1), -- 6Tough Jerky
    (35245, 4751, -0.002, 1, 0, 1, 1), -- 6Windfury Talon
    (35245, 56151, 0.0020, 1, 0, 1, 1), -- 7Broken Hoof Piece
    (35245, 17056, 0.0017, 1, 0, 1, 1), -- 6Light Feather
    (35245, 47038, -0.0017, 1, 0, 1, 1), -- 6Slab of Venison
    (35245, 60793, -0.0017, 1, 0, 1, 1), -- 6Diseased Organ
    (35245, 779, 0.0017, 1, 0, 1, 1), -- 7Shiny Seashell
    (35245, 62328, 0.0017, 1, 0, 1, 1), -- 7Shed Fur
    (35245, 1414, 0.0017, 1, 0, 1, 1), -- 7Cracked Sledge
    (35245, 159, 0.0013, 1, 0, 1, 1), -- 6Refreshing Spring Water
    (35245, 4540, 0.0013, 1, 0, 1, 1), -- 6Tough Hunk of Bread
    (35245, 4769, -0.0013, 1, 0, 1, 1), -- 6Trophy Swoop Quill
    (35245, 20764, -0.0013, 1, 0, 1, 1), -- 6Prospector Anvilward's Head
    (35245, 21757, -0.0013, 1, 0, 1, 1), -- 6Grimscale Murloc Head
    (35245, 21776, -0.0013, 1, 0, 1, 1), -- 6Captain Kelisendra's Lost Rutters
    (35245, 60615, -0.0013, 1, 0, 1, 1), -- 6Durotar Crocolisk Tooth
    (35245, 47039, -0.0013, 1, 0, 1, 1), -- 6Scout's Orders
    (35245, 3173, 0.0013, 1, 0, 1, 1), -- 6Bear Meat
    (35245, 67229, 0.0013, 1, 0, 1, 1), -- 6Stag Flank
    (35245, 3685, 0.0013, 1, 0, 1, 1), -- 6Raptor Egg
    (35245, 4752, -0.001, 1, 0, 1, 1), -- 6Azure Feather
    (35245, 4802, -0.001, 1, 0, 1, 1), -- 6Cougar Claws
    (35245, 21808, -0.001, 1, 0, 1, 1), -- 6Arcane Core
    (35245, 3299, 0.0010, 1, 0, 1, 1), -- 7Fractured Canine
    (35245, 23333, 0.0010, 1, 0, 1, 1), -- 7Shattered Power Core
    (35245, 56150, 0.0010, 1, 0, 1, 1), -- 7Glue Material
    (35245, 1417, 0.0010, 1, 0, 1, 1), -- 7Beaten Battle Axe
    (35245, 2958, 0.0007, 1, 0, 1, 1), -- 5Journeyman's Pants
    (35245, 3635, -0.0007, 1, 0, 1, 1), -- 6Maggot Eye's Paw
    (35245, 4536, 0.0007, 1, 0, 1, 1), -- 6Shiny Red Apple
    (35245, 4753, -0.0007, 1, 0, 1, 1), -- 6Bronze Feather
    (35245, 4819, -0.0007, 1, 0, 1, 1), -- 6Fizsprocket's Clipboard
    (35245, 4862, -0.0007, 1, 0, 1, 1), -- 6Scorpid Worker Tail
    (35245, 5085, -0.0007, 1, 0, 1, 1), -- 6Quilboar Tusk
    (35245, 5086, -0.0007, 1, 0, 1, 1), -- 6Zhevra Hooves
    (35245, 7097, 0.0007, 1, 0, 1, 1), -- 6Leg Meat
    (35245, 20765, -0.0007, 1, 0, 1, 1), -- 6Incriminating Documents
    (35245, 828, 0.0007, 1, 0, 1, 1), -- 6Small Blue Pouch
    (35245, 5465, 0.0007, 1, 0, 1, 1), -- 6Small Spider Leg
    (35245, 6303, 0.0007, 1, 0, 1, 1), -- 6Raw Slitherskin Mackerel
    (35245, 27668, 0.0007, 1, 0, 1, 1), -- 6Lynx Meat
    (35245, 5523, 0.0007, 1, 0, 1, 1), -- 6Small Barnacled Clam
    (35245, 2675, 0.0007, 1, 0, 1, 1), -- 6Crawler Claw
    (35245, 4813, 0.0007, 1, 0, 1, 1), -- 7Small Leather Collar
    (35245, 7074, 0.0007, 1, 0, 1, 1), -- 7Chipped Claw
    (35245, 7096, 0.0007, 1, 0, 1, 1), -- 7Plucked Feather
    (35245, 7101, 0.0007, 1, 0, 1, 1), -- 7Bug Eye
    (35245, 60743, 0.0007, 1, 0, 1, 1), -- 7Diseased Beast Guts
    (35245, 1429, 0.0007, 1, 0, 1, 1), -- 7Patchwork Cloak
    (35245, 1433, 0.0007, 1, 0, 1, 1), -- 7Patchwork Armor
    (35245, 2773, 0.0007, 1, 0, 1, 1), -- 7Cracked Shortbow
    (35245, 3370, 0.0007, 1, 0, 1, 1), -- 7Patchwork Belt
    (35245, 1415, 0.0007, 1, 0, 1, 1), -- 7Carpenter's Mallet
    (35245, 9753, 0.0003, 1, 0, 1, 1), -- 5Gypsy Buckler
    (35245, 6556, 0.0003, 1, 0, 1, 1), -- 5Bard's Bracers
    (35245, 2828, -0.0003, 1, 0, 1, 1), -- 6Nissa's Remains
    (35245, 2829, -0.0003, 1, 0, 1, 1), -- 6Gregor's Remains
    (35245, 2855, -0.0003, 1, 0, 1, 1), -- 6Putrid Claw
    (35245, 2859, -0.0003, 1, 0, 1, 1), -- 6Vile Fin Scale
    (35245, 3162, -0.0003, 1, 0, 1, 1), -- 6Notched Rib
    (35245, 3264, -0.0003, 1, 0, 1, 1), -- 6Duskbat Wing
    (35245, 3265, -0.0003, 1, 0, 1, 1), -- 6Scavenger Paw
    (35245, 4604, 0.0003, 1, 0, 1, 1), -- 6Forest Mushroom Cap
    (35245, 4871, -0.0003, 1, 0, 1, 1), -- 6Searing Collar
    (35245, 4905, -0.0003, 1, 0, 1, 1), -- 6Sarkoth's Mangled Claw
    (35245, 5203, -0.0003, 1, 0, 1, 1), -- 6Flatland Prowler Claw
    (35245, 22487, -0.0003, 1, 0, 1, 1), -- 6Aldaron's Head
    (35245, 22567, -0.0003, 1, 0, 1, 1), -- 6Gargoyle Fragment
    (35245, 805, 0.0003, 1, 0, 1, 1), -- 6Small Red Pouch
    (35245, 2287, 0.0003, 1, 0, 1, 1), -- 6Haunch of Meat
    (35245, 4496, 0.0003, 1, 0, 1, 1), -- 6Small Brown Pouch
    (35245, 4537, 0.0003, 1, 0, 1, 1), -- 6Tel'Abim Banana
    (35245, 8179, 0.0003, 1, 0, 1, 1), -- 6Cadet's Bow
    (35245, 766, 0.0003, 1, 0, 1, 1), -- 6Flanged Mace
    (35245, 8177, 0.0003, 1, 0, 1, 1), -- 6Practice Sword
    (35245, 767, 0.0003, 1, 0, 1, 1), -- 6Long Bo Staff
    (35245, 768, 0.0003, 1, 0, 1, 1), -- 6Lumberjack Axe
    (35245, 4563, 0.0003, 1, 0, 1, 1), -- 6Billy Club
    (35245, 8181, 0.0003, 1, 0, 1, 1), -- 6Hunting Rifle
    (35245, 15004, 0.0003, 1, 0, 1, 1), -- 6Primal Boots
    (35245, 15472, 0.0003, 1, 0, 1, 1), -- 6Charger's Belt
    (35245, 2674, 0.0003, 1, 0, 1, 1), -- 6Crawler Meat
    (35245, 2924, 0.0003, 1, 0, 1, 1), -- 6Crocolisk Meat
    (35245, 22644, 0.0003, 1, 0, 1, 1), -- 6Crunchy Spider Leg
    (35245, 4865, 0.0003, 1, 0, 1, 1), -- 7Ruined Pelt
    (35245, 4872, 0.0003, 1, 0, 1, 1), -- 7Dry Scorpid Eye
    (35245, 20847, 0.0003, 1, 0, 1, 1), -- 7Wraith Fragment
    (35245, 20848, 0.0003, 1, 0, 1, 1), -- 7Sparkling Dust
    (35245, 55983, 0.0003, 1, 0, 1, 1), -- 7Inert Elemental Scintilla
    (35245, 62514, 0.0003, 1, 0, 1, 1), -- 7Cracked Pincer
    (35245, 21006, 0.0003, 1, 0, 1, 1), -- 7Unkempt Pants
    (35245, 21011, 0.0003, 1, 0, 1, 1), -- 7Scraggy Leather Bracers
    (35245, 21019, 0.0003, 1, 0, 1, 1), -- 7Shoddy Chain Bracers
    (35245, 1412, 0.0003, 1, 0, 1, 1), -- 7Crude Bastard Sword
    (35245, 1418, 0.0003, 1, 0, 1, 1), -- 7Worn Leather Belt
    (35245, 1423, 0.0003, 1, 0, 1, 1), -- 7Worn Leather Pants
    (35245, 2774, 0.0003, 1, 0, 1, 1), -- 7Rust-Covered Blunderbuss
    (35245, 1411, 0.0003, 1, 0, 1, 1), -- 7Withered Staff
    (35245, 1419, 0.0003, 1, 0, 1, 1), -- 7Worn Leather Boots
    (35245, 1420, 0.0003, 1, 0, 1, 1); -- 7Worn Leather Bracers
    UPDATE `creature_template` SET `lootid` = 35245 WHERE `entry` = 35245;
     
    --  http://www.wowhead.com/npc=1504
    DELETE FROM `creature_loot_template` WHERE `entry` = 1504;
    INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
    (1504, 62530, 74.2609, 1, 0, 1, 1), -- 7Spider Hair
    (1504, 1476, 24.6941, 1, 0, 1, 1), -- 7Snapped Spider Limb
    (1504, 7101, 0.6681, 1, 0, 1, 1), -- 7Bug Eye
    (1504, 7100, 0.6597, 1, 0, 1, 1), -- 7Sticky Ichor
    (1504, 805, 0.1069, 1, 0, 1, 1), -- 6Small Red Pouch
    (1504, 828, 0.1041, 1, 0, 1, 1), -- 6Small Blue Pouch
    (1504, 4496, 0.0970, 1, 0, 1, 1), -- 6Small Brown Pouch
    (1504, 5572, 0.0942, 1, 0, 1, 1), -- 6Small Green Pouch
    (1504, 5571, 0.0731, 1, 0, 1, 1), -- 6Small Black Pouch
    (1504, 3264, -0.0605, 1, 0, 1, 1), -- 6Duskbat Wing
    (1504, 1372, 0.0436, 1, 0, 1, 1), -- 7Ragged Cloak
    (1504, 1376, 0.0436, 1, 0, 1, 1), -- 7Frayed Cloak
    (1504, 3265, -0.0366, 1, 0, 1, 1), -- 6Scavenger Paw
    (1504, 1370, 0.0352, 1, 0, 1, 1), -- 7Ragged Leather Bracers
    (1504, 3363, 0.0338, 1, 0, 1, 1), -- 7Frayed Belt
    (1504, 1374, 0.0323, 1, 0, 1, 1), -- 7Frayed Shoes
    (1504, 1369, 0.0323, 1, 0, 1, 1), -- 7Ragged Leather Belt
    (1504, 2649, 0.0267, 1, 0, 1, 1), -- 7Flimsy Chain Belt
    (1504, 1380, 0.0253, 1, 0, 1, 1), -- 7Frayed Robe
    (1504, 3365, 0.0253, 1, 0, 1, 1), -- 7Frayed Bracers
    (1504, 2654, 0.0239, 1, 0, 1, 1), -- 7Flimsy Chain Pants
    (1504, 1378, 0.0225, 1, 0, 1, 1), -- 7Frayed Pants
    (1504, 2589, 0.0211, 1, 0, 1, 1), -- 6Linen Cloth
    (1504, 2650, 0.0211, 1, 0, 1, 1), -- 7Flimsy Chain Boots
    (1504, 2651, 0.0183, 1, 0, 1, 1), -- 7Flimsy Chain Bracers
    (1504, 2211, 0.0169, 1, 0, 1, 1), -- 7Bent Large Shield
    (1504, 2653, 0.0169, 1, 0, 1, 1), -- 7Flimsy Chain Gloves
    (1504, 1364, 0.0169, 1, 0, 1, 1), -- 7Ragged Leather Vest
    (1504, 2210, 0.0155, 1, 0, 1, 1), -- 7Battered Buckler
    (1504, 2652, 0.0141, 1, 0, 1, 1), -- 7Flimsy Chain Cloak
    (1504, 1368, 0.0113, 1, 0, 1, 1), -- 7Ragged Leather Gloves
    (1504, 1366, 0.0098, 1, 0, 1, 1), -- 7Ragged Leather Pants
    (1504, 62328, 0.0070, 1, 0, 1, 1), -- 7Shed Fur
    (1504, 1367, 0.0070, 1, 0, 1, 1), -- 7Ragged Leather Boots
    (1504, 1377, 0.0070, 1, 0, 1, 1), -- 7Frayed Gloves
    (1504, 772, -0.0056, 1, 0, 1, 1), -- 6Large Candle
    (1504, 2855, -0.0056, 1, 0, 1, 1), -- 6Putrid Claw
    (1504, 2656, 0.0056, 1, 0, 1, 1), -- 7Flimsy Chain Vest
    (1504, 773, -0.0042, 1, 0, 1, 1), -- 6Gold Dust
    (1504, 4604, 0.0042, 1, 0, 1, 1), -- 6Forest Mushroom Cap
    (1504, 21757, -0.0042, 1, 0, 1, 1), -- 6Grimscale Murloc Head
    (1504, 12223, 0.0042, 1, 0, 1, 1), -- 6Meaty Bat Wing
    (1504, 5466, 0.0042, 1, 0, 1, 1), -- 6Scorpid Stinger
    (1504, 1430, 0.0042, 1, 0, 1, 1), -- 7Patchwork Gloves
    (1504, 159, 0.0028, 1, 0, 1, 1), -- 6Refreshing Spring Water
    (1504, 49535, -0.0028, 1, 0, 1, 1), -- 6Stolen Rifle
    (1504, 52080, -0.0028, 1, 0, 1, 1), -- 6Fresh Crawler Meat
    (1504, 62505, -0.0028, 1, 0, 1, 1), -- 6Bat Eye
    (1504, 20847, 0.0028, 1, 0, 1, 1), -- 7Wraith Fragment
    (1504, 20848, 0.0028, 1, 0, 1, 1), -- 7Sparkling Dust
    (1504, 56968, 0.0028, 1, 0, 1, 1), -- 7Bug Juice
    (1504, 21006, 0.0028, 1, 0, 1, 1), -- 7Unkempt Pants
    (1504, 3300, 0.0028, 1, 0, 1, 1), -- 7Rabbit's Foot
    (1504, 2834, -0.0014, 1, 0, 1, 1), -- 6Embalming Ichor
    (1504, 2858, -0.0014, 1, 0, 1, 1), -- 6Darkhound Blood
    (1504, 2859, -0.0014, 1, 0, 1, 1), -- 6Vile Fin Scale
    (1504, 4862, -0.0014, 1, 0, 1, 1), -- 6Scorpid Worker Tail
    (1504, 4905, -0.0014, 1, 0, 1, 1), -- 6Sarkoth's Mangled Claw
    (1504, 20799, -0.0014, 1, 0, 1, 1), -- 6Felendren's Head
    (1504, 49424, -0.0014, 1, 0, 1, 1), -- 6Gyrochoppa Keys
    (1504, 60793, -0.0014, 1, 0, 1, 1), -- 6Diseased Organ
    (1504, 769, 0.0014, 1, 0, 1, 1), -- 6Chunk of Boar Meat
    (1504, 5179, -0.0014, 1, 0, 1, 1), -- 6Moss-Twined Heart
    (1504, 5465, 0.0014, 1, 0, 1, 1), -- 6Small Spider Leg
    (1504, 8182, 0.0014, 1, 0, 1, 1), -- 6Pellet Rifle
    (1504, 3189, 0.0014, 1, 0, 1, 1), -- 6Wood Chopper
    (1504, 3190, 0.0014, 1, 0, 1, 1), -- 6Beatstick
    (1504, 5523, 0.0014, 1, 0, 1, 1), -- 6Small Barnacled Clam
    (1504, 2675, 0.0014, 1, 0, 1, 1), -- 6Crawler Claw
    (1504, 1468, 0.0014, 1, 0, 1, 1), -- 6Murloc Fin
    (1504, 3299, 0.0014, 1, 0, 1, 1), -- 7Fractured Canine
    (1504, 6296, 0.0014, 1, 0, 1, 1), -- 7Patch of Bat Hair
    (1504, 21015, 0.0014, 1, 0, 1, 1), -- 7Shoddy Chain Belt
    (1504, 21022, 0.0014, 1, 0, 1, 1), -- 7Weather Beaten Buckler
    (1504, 21014, 0.0014, 1, 0, 1, 1), -- 7Scraggy Leather Vest
    (1504, 1429, 0.0014, 1, 0, 1, 1), -- 7Patchwork Cloak
    (1504, 1431, 0.0014, 1, 0, 1, 1), -- 7Patchwork Pants
    (1504, 1416, 0.0014, 1, 0, 1, 1); -- 7Rusty Hatchet
    UPDATE `creature_template` SET `lootid` = 1504 WHERE `entry` = 1504;
     
     
    --  http://www.wowhead.com/npc=1797
    DELETE FROM `creature_loot_template` WHERE `entry` = 1797;
    INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
    (1797, 4865, 70.9613, 1, 0, 1, 1), -- 7Ruined Pelt
    (1797, 60793, -48.2654, 1, 0, 1, 1), -- 6Diseased Organ
    (1797, 3173, 41.3530, 1, 0, 1, 1), -- 6Bear Meat
    (1797, 3170, 28.0905, 1, 0, 1, 1), -- 7Large Bear Tooth
    (1797, 818, 0.3704, 1, 0, 1, 1), -- 5Tigerseye
    (1797, 1511, 0.3405, 1, 0, 1, 1), -- 7Commoner's Sword
    (1797, 1516, 0.3034, 1, 0, 1, 1), -- 7Worn Hatchet
    (1797, 1513, 0.2897, 1, 0, 1, 1), -- 7Old Greatsword
    (1797, 3253, -0.2832, 1, 0, 1, 1), -- 6Grizzled Bear Heart
    (1797, 1515, 0.2695, 1, 0, 1, 1), -- 7Rough Wooden Staff
    (1797, 2763, 0.2606, 1, 0, 1, 1), -- 7Fisherman Knife
    (1797, 1512, 0.2582, 1, 0, 1, 1), -- 7Crude Battle Axe
    (1797, 2777, 0.2526, 1, 0, 1, 1), -- 7Feeble Shortbow
    (1797, 1510, 0.2518, 1, 0, 1, 1), -- 7Heavy Hammer
    (1797, 1514, 0.2445, 1, 0, 1, 1), -- 7Rusty Warhammer
    (1797, 2778, 0.2372, 1, 0, 1, 1), -- 7Cheap Blunderbuss
    (1797, 1504, 0.2284, 1, 0, 1, 1), -- 7Warped Leather Bracers
    (1797, 1497, 0.2155, 1, 0, 1, 1), -- 7Calico Cloak
    (1797, 1506, 0.2106, 1, 0, 1, 1), -- 7Warped Leather Gloves
    (1797, 3374, 0.2074, 1, 0, 1, 1), -- 7Calico Belt
    (1797, 1509, 0.2042, 1, 0, 1, 1), -- 7Warped Leather Vest
    (1797, 1498, 0.2034, 1, 0, 1, 1), -- 7Calico Gloves
    (1797, 1499, 0.2001, 1, 0, 1, 1), -- 7Calico Pants
    (1797, 1502, 0.1993, 1, 0, 1, 1), -- 7Warped Leather Belt
    (1797, 1501, 0.1985, 1, 0, 1, 1), -- 7Calico Tunic
    (1797, 1507, 0.1929, 1, 0, 1, 1), -- 7Warped Leather Pants
    (1797, 3375, 0.1896, 1, 0, 1, 1), -- 7Calico Bracers
    (1797, 2215, 0.1856, 1, 0, 1, 1), -- 7Wooden Shield
    (1797, 1734, 0.1824, 1, 0, 1, 1), -- 7Worn Mail Gloves
    (1797, 2214, 0.1816, 1, 0, 1, 1), -- 7Wooden Buckler
    (1797, 1732, 0.1751, 1, 0, 1, 1), -- 7Worn Mail Bracers
    (1797, 1735, 0.1703, 1, 0, 1, 1), -- 7Worn Mail Pants
    (1797, 1495, 0.1670, 1, 0, 1, 1), -- 7Calico Shoes
    (1797, 1503, 0.1654, 1, 0, 1, 1), -- 7Warped Leather Boots
    (1797, 1731, 0.1566, 1, 0, 1, 1), -- 7Worn Mail Boots
    (1797, 1737, 0.1541, 1, 0, 1, 1), -- 7Worn Mail Vest
    (1797, 3169, 0.1501, 1, 0, 1, 1), -- 7Chipped Bear Tooth
    (1797, 8180, 0.1453, 1, 0, 1, 1), -- 5Hunting Bow
    (1797, 9754, 0.1453, 1, 0, 1, 1), -- 6Gypsy Cloak
    (1797, 1730, 0.1396, 1, 0, 1, 1), -- 7Worn Mail Belt
    (1797, 2140, 0.1315, 1, 0, 1, 1), -- 5Carving Knife
    (1797, 4561, 0.1299, 1, 0, 1, 1), -- 5Scalping Tomahawk
    (1797, 1210, 0.1267, 1, 0, 1, 1), -- 5Shadowgem
    (1797, 9742, 0.1219, 1, 0, 1, 1), -- 6Simple Cord
    (1797, 3192, 0.1194, 1, 0, 1, 1), -- 5Short Bastard Sword
    (1797, 6267, 0.1122, 1, 0, 1, 1), -- 5Disciple's Pants
    (1797, 2075, 0.1097, 1, 0, 1, 1), -- 5Heavy Mace
    (1797, 4577, 0.1049, 1, 0, 1, 1), -- 5Compact Shotgun
    (1797, 6515, 0.1049, 1, 0, 1, 1), -- 6Disciple's Gloves
    (1797, 774, 0.1025, 1, 0, 1, 1), -- 5Malachite
    (1797, 5069, 0.1009, 1, 0, 1, 1), -- 5Fire Wand
    (1797, 9745, 0.0984, 1, 0, 1, 1), -- 6Simple Cape
    (1797, 9744, 0.0952, 1, 0, 1, 1), -- 6Simple Bands
    (1797, 7351, 0.0936, 1, 0, 1, 1), -- 6Disciple's Boots
    (1797, 9750, 0.0936, 1, 0, 1, 1), -- 6Gypsy Sash
    (1797, 9761, 0.0928, 1, 0, 1, 1), -- 6Cadet Cloak
    (1797, 2965, 0.0888, 1, 0, 1, 1), -- 5Warrior's Tunic
    (1797, 6521, 0.0872, 1, 0, 1, 1), -- 6Pioneer Gloves
    (1797, 9751, 0.0839, 1, 0, 1, 1), -- 6Gypsy Sandals
    (1797, 6337, 0.0807, 1, 0, 1, 1), -- 5Infantry Leggings
    (1797, 9743, 0.0807, 1, 0, 1, 1), -- 6Simple Shoes
    (1797, 9758, 0.0807, 1, 0, 1, 1), -- 6Cadet Belt
    (1797, 9753, 0.0799, 1, 0, 1, 1), -- 5Gypsy Buckler
    (1797, 9760, 0.0791, 1, 0, 1, 1), -- 6Cadet Bracers
    (1797, 2961, 0.0734, 1, 0, 1, 1), -- 5Burnt Leather Vest
    (1797, 6518, 0.0718, 1, 0, 1, 1), -- 6Pioneer Boots
    (1797, 6269, 0.0702, 1, 0, 1, 1), -- 5Pioneer Trousers
    (1797, 4566, 0.0662, 1, 0, 1, 1), -- 5Sturdy Quarterstaff
    (1797, 6510, 0.0654, 1, 0, 1, 1), -- 6Infantry Gauntlets
    (1797, 9752, 0.0654, 1, 0, 1, 1), -- 6Gypsy Bands
    (1797, 2957, 0.0621, 1, 0, 1, 1), -- 5Journeyman's Vest
    (1797, 7350, 0.0621, 1, 0, 1, 1), -- 6Disciple's Bracers
    (1797, 6506, 0.0621, 1, 0, 1, 1), -- 6Infantry Boots
    (1797, 4677, 0.0621, 1, 0, 1, 1), -- 6Veteran Cloak
    (1797, 4684, 0.0605, 1, 0, 1, 1), -- 6Spellbinder Belt
    (1797, 4569, 0.0597, 1, 0, 1, 1), -- 5Staunch Hammer
    (1797, 727, 0.0565, 1, 0, 1, 1), -- 5Notched Shortsword
    (1797, 4562, 0.0525, 1, 0, 1, 1), -- 5Severing Axe
    (1797, 4678, 0.0516, 1, 0, 1, 1), -- 6Veteran Girdle
    (1797, 2958, 0.0508, 1, 0, 1, 1), -- 5Journeyman's Pants
    (1797, 2632, 0.0508, 1, 0, 1, 1), -- 5Curved Dagger
    (1797, 2940, 0.0508, 1, 0, 1, 1), -- 7Bloody Bear Paw
    (1797, 4564, 0.0500, 1, 0, 1, 1), -- 5Spiked Club
    (1797, 7108, 0.0476, 1, 0, 1, 1), -- 5Infantry Shield
    (1797, 4683, 0.0476, 1, 0, 1, 1), -- 6Spellbinder Cloak
    (1797, 4690, 0.0468, 1, 0, 1, 1), -- 6Hunting Belt
    (1797, 15925, 0.0460, 1, 0, 1, 1), -- 5Journeyman's Stave
    (1797, 2964, 0.0460, 1, 0, 1, 1), -- 6Burnt Leather Gloves
    (1797, 11406, 0.0460, 1, 0, 1, 1), -- 7Rotting Bear Carcass
    (1797, 6336, 0.0444, 1, 0, 1, 1), -- 5Infantry Tunic
    (1797, 6511, 0.0436, 1, 0, 1, 1), -- 5Journeyman's Robe
    (1797, 15932, 0.0436, 1, 0, 1, 1), -- 5Disciple's Stein
    (1797, 3213, 0.0436, 1, 0, 1, 1), -- 6Veteran Bracers
    (1797, 2972, 0.0420, 1, 0, 1, 1), -- 6Spellbinder Gloves
    (1797, 6268, 0.0412, 1, 0, 1, 1), -- 5Pioneer Tunic
    (1797, 8178, 0.0403, 1, 0, 1, 1), -- 5Training Sword
    (1797, 6514, 0.0395, 1, 0, 1, 1), -- 6Disciple's Cloak
    (1797, 6513, 0.0387, 1, 0, 1, 1), -- 6Disciple's Sash
    (1797, 3643, 0.0387, 1, 0, 1, 1), -- 6Spellbinder Bracers
    (1797, 4689, 0.0379, 1, 0, 1, 1), -- 6Hunting Cloak
    (1797, 5071, 0.0371, 1, 0, 1, 1), -- 5Shadow Wand
    (1797, 3207, 0.0371, 1, 0, 1, 1), -- 6Hunting Bracers
    (1797, 2962, 0.0363, 1, 0, 1, 1), -- 5Burnt Leather Breeches
    (1797, 9756, 0.0363, 1, 0, 1, 1), -- 5Gypsy Trousers
    (1797, 9746, 0.0355, 1, 0, 1, 1), -- 6Simple Gloves
    (1797, 2971, 0.0339, 1, 0, 1, 1), -- 6Spellbinder Boots
    (1797, 6509, 0.0315, 1, 0, 1, 1), -- 6Infantry Belt
    (1797, 6519, 0.0315, 1, 0, 1, 1), -- 6Pioneer Bracers
    (1797, 9759, 0.0315, 1, 0, 1, 1), -- 6Cadet Boots
    (1797, 2975, 0.0291, 1, 0, 1, 1), -- 6Hunting Boots
    (1797, 9762, 0.0282, 1, 0, 1, 1), -- 6Cadet Gauntlets
    (1797, 2073, 0.0274, 1, 0, 1, 1), -- 5Dwarven Hatchet
    (1797, 2407, 0.0266, 1, 0, 1, 1), -- 5Pattern: White Leather Jerkin
    (1797, 3651, 0.0258, 1, 0, 1, 1), -- 5Veteran Shield
    (1797, 9755, 0.0258, 1, 0, 1, 1), -- 6Gypsy Gloves
    (1797, 6517, 0.0242, 1, 0, 1, 1), -- 6Pioneer Belt
    (1797, 6512, 0.0234, 1, 0, 1, 1), -- 5Disciple's Robe
    (1797, 6555, 0.0234, 1, 0, 1, 1), -- 6Bard's Cloak
    (1797, 2966, 0.0226, 1, 0, 1, 1), -- 5Warrior's Pants
    (1797, 6266, 0.0218, 1, 0, 1, 1), -- 5Disciple's Vest
    (1797, 9747, 0.0218, 1, 0, 1, 1), -- 5Simple Britches
    (1797, 2967, 0.0218, 1, 0, 1, 1), -- 6Warrior's Boots
    (1797, 6549, 0.0218, 1, 0, 1, 1), -- 6Soldier's Cloak
    (1797, 2657, 0.0218, 1, 0, 1, 1), -- 6Red Leather Bag
    (1797, 6507, 0.0210, 1, 0, 1, 1), -- 6Infantry Bracers
    (1797, 9763, 0.0202, 1, 0, 1, 1), -- 5Cadet Leggings
    (1797, 5574, 0.0202, 1, 0, 1, 1), -- 6White Leather Bag
    (1797, 856, 0.0194, 1, 0, 1, 1), -- 6Blue Leather Bag
    (1797, 9764, 0.0186, 1, 0, 1, 1), -- 5Cadet Shield
    (1797, 2976, 0.0178, 1, 0, 1, 1), -- 5Hunting Gloves
    (1797, 3652, 0.0169, 1, 0, 1, 1), -- 5Hunting Buckler
    (1797, 15933, 0.0169, 1, 0, 1, 1), -- 5Simple Branch
    (1797, 2553, 0.0153, 1, 0, 1, 1), -- 5Recipe: Elixir of Minor Agility
    (1797, 3610, 0.0153, 1, 0, 1, 1), -- 5Plans: Gemmed Copper Gauntlets
    (1797, 3609, 0.0145, 1, 0, 1, 1), -- 5Plans: Copper Chain Vest
    (1797, 3036, 0.0145, 1, 0, 1, 1), -- 5Heavy Shortbow
    (1797, 5573, 0.0145, 1, 0, 1, 1), -- 6Green Leather Bag
    (1797, 9757, 0.0137, 1, 0, 1, 1), -- 5Gypsy Tunic
    (1797, 2979, 0.0129, 1, 0, 1, 1), -- 6Veteran Boots
    (1797, 62328, 0.0129, 1, 0, 1, 1), -- 7Shed Fur
    (1797, 6271, 0.0121, 1, 0, 1, 1), -- 5Pattern: Red Linen Vest
    (1797, 2555, 0.0121, 1, 0, 1, 1), -- 5Recipe: Swiftness Potion
    (1797, 2589, 0.0121, 1, 0, 1, 1), -- 6Linen Cloth
    (1797, 2980, 0.0113, 1, 0, 1, 1), -- 5Veteran Gloves
    (1797, 4408, 0.0113, 1, 0, 1, 1), -- 5Schematic: Mechanical Squirrel Box
    (1797, 4570, 0.0113, 1, 0, 1, 1), -- 5Birchwood Maul
    (1797, 6542, 0.0113, 1, 0, 1, 1), -- 5Willow Cape
    (1797, 6342, 0.0105, 1, 0, 1, 1), -- 5Formula: Enchant Chest - Minor Mana
    (1797, 6537, 0.0105, 1, 0, 1, 1), -- 5Willow Boots
    (1797, 5635, 0.0105, 1, 0, 1, 1), -- 6Sharp Claw
    (1797, 2598, 0.0097, 1, 0, 1, 1), -- 5Pattern: Red Linen Robe
    (1797, 2978, 0.0097, 1, 0, 1, 1), -- 5Veteran Leggings
    (1797, 6543, 0.0097, 1, 0, 1, 1), -- 5Willow Bracers
    (1797, 9749, 0.0097, 1, 0, 1, 1), -- 5Simple Blouse
    (1797, 6556, 0.0089, 1, 0, 1, 1), -- 5Bard's Bracers
    (1797, 7288, 0.0081, 1, 0, 1, 1), -- 5Pattern: Rugged Leather Pants
    (1797, 2406, 0.0081, 1, 0, 1, 1), -- 5Pattern: Fine Leather Boots
    (1797, 6550, 0.0081, 1, 0, 1, 1), -- 5Soldier's Wristguards
    (1797, 2408, 0.0073, 1, 0, 1, 1), -- 5Pattern: Fine Leather Gloves
    (1797, 6558, 0.0065, 1, 0, 1, 1), -- 5Bard's Belt
    (1797, 9765, 0.0065, 1, 0, 1, 1), -- 5Cadet Vest
    (1797, 4345, 0.0056, 1, 0, 1, 1), -- 5Pattern: Red Woolen Boots
    (1797, 2855, -0.0048, 1, 0, 1, 1), -- 6Putrid Claw
    (1797, 5571, 0.0048, 1, 0, 1, 1), -- 6Small Black Pouch
    (1797, 12223, 0.0048, 1, 0, 1, 1), -- 6Meaty Bat Wing
    (1797, 4757, 0.0048, 1, 0, 1, 1), -- 7Cracked Egg Shells
    (1797, 9748, 0.0040, 1, 0, 1, 1), -- 5Simple Robe
    (1797, 6344, 0.0040, 1, 0, 1, 1), -- 5Formula: Enchant Bracer - Minor Spirit
    (1797, 4292, 0.0040, 1, 0, 1, 1), -- 5Pattern: Green Woolen Bag
    (1797, 4346, 0.0040, 1, 0, 1, 1), -- 5Pattern: Heavy Woolen Cloak
    (1797, 4409, 0.0040, 1, 0, 1, 1), -- 5Schematic: Small Seaforium Charge
    (1797, 4751, -0.004, 1, 0, 1, 1), -- 6Windfury Talon
    (1797, 7074, 0.0040, 1, 0, 1, 1), -- 7Chipped Claw
    (1797, 2876, -0.0032, 1, 0, 1, 1), -- 6Duskbat Pelt
    (1797, 21808, -0.0032, 1, 0, 1, 1), -- 6Arcane Core
    (1797, 118, 0.0032, 1, 0, 1, 1), -- 6Minor Healing Potion
    (1797, 2774, 0.0032, 1, 0, 1, 1), -- 7Rust-Covered Blunderbuss
    (1797, 6347, 0.0024, 1, 0, 1, 1), -- 5Formula: Enchant Bracer - Minor Strength
    (1797, 4293, 0.0024, 1, 0, 1, 1), -- 5Pattern: Hillman's Leather Vest
    (1797, 6348, 0.0024, 1, 0, 1, 1), -- 5Formula: Enchant Weapon - Minor Beastslayer
    (1797, 2859, -0.0024, 1, 0, 1, 1), -- 6Vile Fin Scale
    (1797, 20797, -0.0024, 1, 0, 1, 1), -- 6Lynx Collar
    (1797, 2881, 0.0016, 1, 0, 1, 1), -- 5Plans: Runed Copper Breastplate
    (1797, 2409, 0.0016, 1, 0, 1, 1), -- 5Pattern: Dark Leather Tunic
    (1797, 6716, 0.0016, 1, 0, 1, 1), -- 5Schematic: EZ-Thro Dynamite
    (1797, 52564, 0.0016, 1, 0, 1, 1), -- 6Burning Blade Spellscroll
    (1797, 5466, 0.0016, 1, 0, 1, 1), -- 6Scorpid Stinger
    (1797, 2452, 0.0016, 1, 0, 1, 1), -- 6Swiftthistle
    (1797, 6149, 0.0016, 1, 0, 1, 1), -- 6Greater Mana Potion
    (1797, 2642, 0.0016, 1, 0, 1, 1), -- 7Loose Chain Boots
    (1797, 68762, 0.0008, 1, 0, 1, 1), -- 5Imbued Cadet Cloak
    (1797, 15210, 0.0008, 1, 0, 1, 1), -- 5Raider Shortsword
    (1797, 117, 0.0008, 1, 0, 1, 1), -- 6Tough Jerky
    (1797, 2070, 0.0008, 1, 0, 1, 1), -- 6Darnassian Bleu
    (1797, 2830, -0.0008, 1, 0, 1, 1), -- 6Thurman's Remains
    (1797, 3163, -0.0008, 1, 0, 1, 1), -- 6Blackened Skull
    (1797, 3635, -0.0008, 1, 0, 1, 1), -- 6Maggot Eye's Paw
    (1797, 4802, -0.0008, 1, 0, 1, 1), -- 6Cougar Claws
    (1797, 21770, -0.0008, 1, 0, 1, 1), -- 6Ring of Mmmrrrggglll
    (1797, 52077, 0.0008, 1, 0, 1, 1), -- 6Urgent Scarlet Memorandum
    (1797, 828, 0.0008, 1, 0, 1, 1), -- 6Small Blue Pouch
    (1797, 4496, 0.0008, 1, 0, 1, 1), -- 6Small Brown Pouch
    (1797, 4537, 0.0008, 1, 0, 1, 1), -- 6Tel'Abim Banana
    (1797, 6303, 0.0008, 1, 0, 1, 1), -- 6Raw Slitherskin Mackerel
    (1797, 27668, 0.0008, 1, 0, 1, 1), -- 6Lynx Meat
    (1797, 52079, 0.0008, 1, 0, 1, 1), -- 6A Scarlet Letter
    (1797, 2960, 0.0008, 1, 0, 1, 1), -- 6Journeyman's Gloves
    (1797, 1468, 0.0008, 1, 0, 1, 1), -- 6Murloc Fin
    (1797, 4339, 0.0008, 1, 0, 1, 1), -- 6Bolt of Mageweave
    (1797, 779, 0.0008, 1, 0, 1, 1), -- 7Shiny Seashell
    (1797, 1423, 0.0008, 1, 0, 1, 1), -- 7Worn Leather Pants
    (1797, 1417, 0.0008, 1, 0, 1, 1), -- 7Beaten Battle Axe
    (1797, 1431, 0.0008, 1, 0, 1, 1), -- 7Patchwork Pants
    (1797, 2773, 0.0008, 1, 0, 1, 1), -- 7Cracked Shortbow
    (1797, 3370, 0.0008, 1, 0, 1, 1), -- 7Patchwork Belt
    (1797, 1427, 0.0008, 1, 0, 1, 1); -- 7Patchwork Shoes
    UPDATE `creature_template` SET `lootid` = 1797 WHERE `entry` = 1797;
     
    --  http://www.wowhead.com/npc=1766
    DELETE FROM `creature_loot_template` WHERE `entry` = 1766;
    INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
    (1766, 7074, 85.0962, 1, 0, 1, 1), -- 7Chipped Claw
    (1766, 2672, 83.4398, 1, 0, 1, 1), -- 6Stringy Wolf Meat
    (1766, 60793, -41.889, 1, 0, 1, 1), -- 6Diseased Organ
    (1766, 3301, 12.4787, 1, 0, 1, 1), -- 7Sharp Canine
    (1766, 3164, 0.7866, 1, 0, 1, 1), -- 6Discolored Worg Heart
    (1766, 3299, 0.4134, 1, 0, 1, 1), -- 7Fractured Canine
    (1766, 818, 0.3660, 1, 0, 1, 1), -- 5Tigerseye
    (1766, 1516, 0.2971, 1, 0, 1, 1), -- 7Worn Hatchet
    (1766, 1510, 0.2846, 1, 0, 1, 1), -- 7Heavy Hammer
    (1766, 1511, 0.2658, 1, 0, 1, 1), -- 7Commoner's Sword
    (1766, 1514, 0.2649, 1, 0, 1, 1), -- 7Rusty Warhammer
    (1766, 1515, 0.2541, 1, 0, 1, 1), -- 7Rough Wooden Staff
    (1766, 1512, 0.2452, 1, 0, 1, 1), -- 7Crude Battle Axe
    (1766, 2777, 0.2371, 1, 0, 1, 1), -- 7Feeble Shortbow
    (1766, 1513, 0.2318, 1, 0, 1, 1), -- 7Old Greatsword
    (1766, 3375, 0.2255, 1, 0, 1, 1), -- 7Calico Bracers
    (1766, 2778, 0.2210, 1, 0, 1, 1), -- 7Cheap Blunderbuss
    (1766, 1503, 0.2157, 1, 0, 1, 1), -- 7Warped Leather Boots
    (1766, 2763, 0.2148, 1, 0, 1, 1), -- 7Fisherman Knife
    (1766, 1509, 0.2130, 1, 0, 1, 1), -- 7Warped Leather Vest
    (1766, 1499, 0.2076, 1, 0, 1, 1), -- 7Calico Pants
    (1766, 1504, 0.2076, 1, 0, 1, 1), -- 7Warped Leather Bracers
    (1766, 1507, 0.2058, 1, 0, 1, 1), -- 7Warped Leather Pants
    (1766, 1506, 0.2022, 1, 0, 1, 1), -- 7Warped Leather Gloves
    (1766, 1502, 0.1996, 1, 0, 1, 1), -- 7Warped Leather Belt
    (1766, 1497, 0.1987, 1, 0, 1, 1), -- 7Calico Cloak
    (1766, 3374, 0.1987, 1, 0, 1, 1), -- 7Calico Belt
    (1766, 1495, 0.1906, 1, 0, 1, 1), -- 7Calico Shoes
    (1766, 3300, 0.1879, 1, 0, 1, 1), -- 7Rabbit's Foot
    (1766, 1501, 0.1852, 1, 0, 1, 1), -- 7Calico Tunic
    (1766, 2214, 0.1826, 1, 0, 1, 1), -- 7Wooden Buckler
    (1766, 1498, 0.1754, 1, 0, 1, 1), -- 7Calico Gloves
    (1766, 1731, 0.1664, 1, 0, 1, 1), -- 7Worn Mail Boots
    (1766, 9745, 0.1647, 1, 0, 1, 1), -- 6Simple Cape
    (1766, 8180, 0.1602, 1, 0, 1, 1), -- 5Hunting Bow
    (1766, 1732, 0.1584, 1, 0, 1, 1), -- 7Worn Mail Bracers
    (1766, 1734, 0.1557, 1, 0, 1, 1), -- 7Worn Mail Gloves
    (1766, 1737, 0.1557, 1, 0, 1, 1), -- 7Worn Mail Vest
    (1766, 1730, 0.1512, 1, 0, 1, 1), -- 7Worn Mail Belt
    (1766, 2140, 0.1468, 1, 0, 1, 1), -- 5Carving Knife
    (1766, 2215, 0.1450, 1, 0, 1, 1), -- 7Wooden Shield
    (1766, 4561, 0.1441, 1, 0, 1, 1), -- 5Scalping Tomahawk
    (1766, 1735, 0.1423, 1, 0, 1, 1), -- 7Worn Mail Pants
    (1766, 7351, 0.1333, 1, 0, 1, 1), -- 6Disciple's Boots
    (1766, 774, 0.1199, 1, 0, 1, 1), -- 5Malachite
    (1766, 4562, 0.1154, 1, 0, 1, 1), -- 5Severing Axe
    (1766, 6510, 0.1154, 1, 0, 1, 1), -- 6Infantry Gauntlets
    (1766, 9754, 0.1154, 1, 0, 1, 1), -- 6Gypsy Cloak
    (1766, 6518, 0.1083, 1, 0, 1, 1), -- 6Pioneer Boots
    (1766, 6515, 0.1038, 1, 0, 1, 1), -- 6Disciple's Gloves
    (1766, 727, 0.1020, 1, 0, 1, 1), -- 5Notched Shortsword
    (1766, 6506, 0.1011, 1, 0, 1, 1), -- 6Infantry Boots
    (1766, 2961, 0.0984, 1, 0, 1, 1), -- 5Burnt Leather Vest
    (1766, 1210, 0.0949, 1, 0, 1, 1), -- 5Shadowgem
    (1766, 2965, 0.0850, 1, 0, 1, 1), -- 5Warrior's Tunic
    (1766, 6521, 0.0850, 1, 0, 1, 1), -- 6Pioneer Gloves
    (1766, 8178, 0.0832, 1, 0, 1, 1), -- 5Training Sword
    (1766, 9761, 0.0832, 1, 0, 1, 1), -- 6Cadet Cloak
    (1766, 6513, 0.0814, 1, 0, 1, 1), -- 6Disciple's Sash
    (1766, 2957, 0.0796, 1, 0, 1, 1), -- 5Journeyman's Vest
    (1766, 6514, 0.0796, 1, 0, 1, 1), -- 6Disciple's Cloak
    (1766, 2958, 0.0779, 1, 0, 1, 1), -- 5Journeyman's Pants
    (1766, 2964, 0.0779, 1, 0, 1, 1), -- 6Burnt Leather Gloves
    (1766, 3192, 0.0770, 1, 0, 1, 1), -- 5Short Bastard Sword
    (1766, 5069, 0.0770, 1, 0, 1, 1), -- 5Fire Wand
    (1766, 6519, 0.0698, 1, 0, 1, 1), -- 6Pioneer Bracers
    (1766, 6517, 0.0662, 1, 0, 1, 1), -- 6Pioneer Belt
    (1766, 6511, 0.0653, 1, 0, 1, 1), -- 5Journeyman's Robe
    (1766, 7350, 0.0653, 1, 0, 1, 1), -- 6Disciple's Bracers
    (1766, 9742, 0.0635, 1, 0, 1, 1), -- 6Simple Cord
    (1766, 9743, 0.0635, 1, 0, 1, 1), -- 6Simple Shoes
    (1766, 2962, 0.0626, 1, 0, 1, 1), -- 5Burnt Leather Breeches
    (1766, 9753, 0.0600, 1, 0, 1, 1), -- 5Gypsy Buckler
    (1766, 7108, 0.0582, 1, 0, 1, 1), -- 5Infantry Shield
    (1766, 15925, 0.0573, 1, 0, 1, 1), -- 5Journeyman's Stave
    (1766, 2075, 0.0564, 1, 0, 1, 1), -- 5Heavy Mace
    (1766, 4677, 0.0564, 1, 0, 1, 1), -- 6Veteran Cloak
    (1766, 15932, 0.0555, 1, 0, 1, 1), -- 5Disciple's Stein
    (1766, 4566, 0.0546, 1, 0, 1, 1), -- 5Sturdy Quarterstaff
    (1766, 6507, 0.0546, 1, 0, 1, 1), -- 6Infantry Bracers
    (1766, 4577, 0.0537, 1, 0, 1, 1), -- 5Compact Shotgun
    (1766, 6267, 0.0501, 1, 0, 1, 1), -- 5Disciple's Pants
    (1766, 9744, 0.0501, 1, 0, 1, 1), -- 6Simple Bands
    (1766, 9751, 0.0501, 1, 0, 1, 1), -- 6Gypsy Sandals
    (1766, 9760, 0.0483, 1, 0, 1, 1), -- 6Cadet Bracers
    (1766, 4683, 0.0465, 1, 0, 1, 1), -- 6Spellbinder Cloak
    (1766, 9752, 0.0456, 1, 0, 1, 1), -- 6Gypsy Bands
    (1766, 2966, 0.0447, 1, 0, 1, 1), -- 5Warrior's Pants
    (1766, 4684, 0.0421, 1, 0, 1, 1), -- 6Spellbinder Belt
    (1766, 2967, 0.0412, 1, 0, 1, 1), -- 6Warrior's Boots
    (1766, 2971, 0.0412, 1, 0, 1, 1), -- 6Spellbinder Boots
    (1766, 6269, 0.0403, 1, 0, 1, 1), -- 5Pioneer Trousers
    (1766, 4690, 0.0403, 1, 0, 1, 1), -- 6Hunting Belt
    (1766, 4564, 0.0394, 1, 0, 1, 1), -- 5Spiked Club
    (1766, 6268, 0.0394, 1, 0, 1, 1), -- 5Pioneer Tunic
    (1766, 4689, 0.0394, 1, 0, 1, 1), -- 6Hunting Cloak
    (1766, 6337, 0.0385, 1, 0, 1, 1), -- 5Infantry Leggings
    (1766, 9750, 0.0376, 1, 0, 1, 1), -- 6Gypsy Sash
    (1766, 6509, 0.0367, 1, 0, 1, 1), -- 6Infantry Belt
    (1766, 6555, 0.0349, 1, 0, 1, 1), -- 6Bard's Cloak
    (1766, 9746, 0.0340, 1, 0, 1, 1), -- 6Simple Gloves
    (1766, 2632, 0.0322, 1, 0, 1, 1), -- 5Curved Dagger
    (1766, 9758, 0.0322, 1, 0, 1, 1), -- 6Cadet Belt
    (1766, 5071, 0.0313, 1, 0, 1, 1), -- 5Shadow Wand
    (1766, 9755, 0.0313, 1, 0, 1, 1), -- 6Gypsy Gloves
    (1766, 9764, 0.0286, 1, 0, 1, 1), -- 5Cadet Shield
    (1766, 4569, 0.0286, 1, 0, 1, 1), -- 5Staunch Hammer
    (1766, 3643, 0.0286, 1, 0, 1, 1), -- 6Spellbinder Bracers
    (1766, 2972, 0.0277, 1, 0, 1, 1), -- 6Spellbinder Gloves
    (1766, 9762, 0.0268, 1, 0, 1, 1), -- 6Cadet Gauntlets
    (1766, 9759, 0.0260, 1, 0, 1, 1), -- 6Cadet Boots
    (1766, 9747, 0.0233, 1, 0, 1, 1), -- 5Simple Britches
    (1766, 2553, 0.0224, 1, 0, 1, 1), -- 5Recipe: Elixir of Minor Agility
    (1766, 6336, 0.0215, 1, 0, 1, 1), -- 5Infantry Tunic
    (1766, 6512, 0.0215, 1, 0, 1, 1), -- 5Disciple's Robe
    (1766, 4408, 0.0215, 1, 0, 1, 1), -- 5Schematic: Mechanical Squirrel Box
    (1766, 5573, 0.0215, 1, 0, 1, 1), -- 6Green Leather Bag
    (1766, 6266, 0.0206, 1, 0, 1, 1), -- 5Disciple's Vest
    (1766, 3213, 0.0206, 1, 0, 1, 1), -- 6Veteran Bracers
    (1766, 5574, 0.0206, 1, 0, 1, 1), -- 6White Leather Bag
    (1766, 9756, 0.0188, 1, 0, 1, 1), -- 5Gypsy Trousers
    (1766, 2979, 0.0179, 1, 0, 1, 1), -- 6Veteran Boots
    (1766, 856, 0.0179, 1, 0, 1, 1), -- 6Blue Leather Bag
    (1766, 6342, 0.0161, 1, 0, 1, 1), -- 5Formula: Enchant Chest - Minor Mana
    (1766, 6549, 0.0161, 1, 0, 1, 1), -- 6Soldier's Cloak
    (1766, 2657, 0.0161, 1, 0, 1, 1), -- 6Red Leather Bag
    (1766, 3207, 0.0152, 1, 0, 1, 1), -- 6Hunting Bracers
    (1766, 4678, 0.0152, 1, 0, 1, 1), -- 6Veteran Girdle
    (1766, 5635, 0.0152, 1, 0, 1, 1), -- 6Sharp Claw
    (1766, 3651, 0.0143, 1, 0, 1, 1), -- 5Veteran Shield
    (1766, 2407, 0.0134, 1, 0, 1, 1), -- 5Pattern: White Leather Jerkin
    (1766, 2406, 0.0134, 1, 0, 1, 1), -- 5Pattern: Fine Leather Boots
    (1766, 2975, 0.0134, 1, 0, 1, 1), -- 6Hunting Boots
    (1766, 2598, 0.0125, 1, 0, 1, 1), -- 5Pattern: Red Linen Robe
    (1766, 3609, 0.0125, 1, 0, 1, 1), -- 5Plans: Copper Chain Vest
    (1766, 3652, 0.0125, 1, 0, 1, 1), -- 5Hunting Buckler
    (1766, 2408, 0.0125, 1, 0, 1, 1), -- 5Pattern: Fine Leather Gloves
    (1766, 6271, 0.0116, 1, 0, 1, 1), -- 5Pattern: Red Linen Vest
    (1766, 9763, 0.0116, 1, 0, 1, 1), -- 5Cadet Leggings
    (1766, 2555, 0.0116, 1, 0, 1, 1), -- 5Recipe: Swiftness Potion
    (1766, 3610, 0.0107, 1, 0, 1, 1), -- 5Plans: Gemmed Copper Gauntlets
    (1766, 15933, 0.0107, 1, 0, 1, 1), -- 5Simple Branch
    (1766, 62328, 0.0089, 1, 0, 1, 1), -- 7Shed Fur
    (1766, 7288, 0.0081, 1, 0, 1, 1), -- 5Pattern: Rugged Leather Pants
    (1766, 4293, 0.0054, 1, 0, 1, 1), -- 5Pattern: Hillman's Leather Vest
    (1766, 4346, 0.0054, 1, 0, 1, 1), -- 5Pattern: Heavy Woolen Cloak
    (1766, 3173, 0.0054, 1, 0, 1, 1), -- 6Bear Meat
    (1766, 4292, 0.0045, 1, 0, 1, 1), -- 5Pattern: Green Woolen Bag
    (1766, 4751, -0.0045, 1, 0, 1, 1), -- 6Windfury Talon
    (1766, 828, 0.0045, 1, 0, 1, 1), -- 6Small Blue Pouch
    (1766, 3169, 0.0045, 1, 0, 1, 1), -- 7Chipped Bear Tooth
    (1766, 2881, 0.0036, 1, 0, 1, 1), -- 5Plans: Runed Copper Breastplate
    (1766, 2409, 0.0036, 1, 0, 1, 1), -- 5Pattern: Dark Leather Tunic
    (1766, 5204, -0.0036, 1, 0, 1, 1), -- 6Bloodfeather Belt
    (1766, 6347, 0.0027, 1, 0, 1, 1), -- 5Formula: Enchant Bracer - Minor Strength
    (1766, 6716, 0.0027, 1, 0, 1, 1), -- 5Schematic: EZ-Thro Dynamite
    (1766, 2855, -0.0027, 1, 0, 1, 1), -- 6Putrid Claw
    (1766, 2859, -0.0027, 1, 0, 1, 1), -- 6Vile Fin Scale
    (1766, 2589, 0.0027, 1, 0, 1, 1), -- 6Linen Cloth
    (1766, 6344, 0.0018, 1, 0, 1, 1), -- 5Formula: Enchant Bracer - Minor Spirit
    (1766, 117, 0.0018, 1, 0, 1, 1), -- 6Tough Jerky
    (1766, 6303, 0.0018, 1, 0, 1, 1), -- 6Raw Slitherskin Mackerel
    (1766, 1468, 0.0018, 1, 0, 1, 1), -- 6Murloc Fin
    (1766, 4757, 0.0018, 1, 0, 1, 1), -- 7Cracked Egg Shells
    (1766, 20812, 0.0018, 1, 0, 1, 1), -- 7Tattered Pelt
    (1766, 60743, 0.0018, 1, 0, 1, 1), -- 7Diseased Beast Guts
    (1766, 6556, 0.0009, 1, 0, 1, 1), -- 5Bard's Bracers
    (1766, 6548, 0.0009, 1, 0, 1, 1), -- 5Soldier's Girdle
    (1766, 4345, 0.0009, 1, 0, 1, 1), -- 5Pattern: Red Woolen Boots
    (1766, 4409, 0.0009, 1, 0, 1, 1), -- 5Schematic: Small Seaforium Charge
    (1766, 6348, 0.0009, 1, 0, 1, 1), -- 5Formula: Enchant Weapon - Minor Beastslayer
    (1766, 2070, 0.0009, 1, 0, 1, 1), -- 6Darnassian Bleu
    (1766, 2831, -0.0009, 1, 0, 1, 1), -- 6Devlin's Remains
    (1766, 2834, -0.0009, 1, 0, 1, 1), -- 6Embalming Ichor
    (1766, 2858, -0.0009, 1, 0, 1, 1), -- 6Darkhound Blood
    (1766, 4604, 0.0009, 1, 0, 1, 1), -- 6Forest Mushroom Cap
    (1766, 7097, 0.0009, 1, 0, 1, 1), -- 6Leg Meat
    (1766, 20764, -0.0009, 1, 0, 1, 1), -- 6Prospector Anvilward's Head
    (1766, 20797, -0.0009, 1, 0, 1, 1), -- 6Lynx Collar
    (1766, 21808, -0.0009, 1, 0, 1, 1), -- 6Arcane Core
    (1766, 23334, 0.0009, 1, 0, 1, 1), -- 6Cracked Power Core
    (1766, 52077, 0.0009, 1, 0, 1, 1), -- 6Urgent Scarlet Memorandum
    (1766, 118, 0.0009, 1, 0, 1, 1), -- 6Minor Healing Potion
    (1766, 12223, 0.0009, 1, 0, 1, 1), -- 6Meaty Bat Wing
    (1766, 2452, 0.0009, 1, 0, 1, 1), -- 6Swiftthistle
    (1766, 4865, 0.0009, 1, 0, 1, 1), -- 7Ruined Pelt
    (1766, 56151, 0.0009, 1, 0, 1, 1), -- 7Broken Hoof Piece
    (1766, 3370, 0.0009, 1, 0, 1, 1), -- 7Patchwork Belt
    (1766, 1415, 0.0009, 1, 0, 1, 1), -- 7Carpenter's Mallet
    (1766, 1425, 0.0009, 1, 0, 1, 1); -- 7Worn Leather Vest
    UPDATE `creature_template` SET `lootid` = 1766 WHERE `entry` = 1766;
     
    DELETE FROM creature_addon WHERE guid in (47250,58678,58726,58728,58741,58750,58752,58800,58826,58833,58864,58869,58878,58941,58959,58979,58982,58984,59028,59050,59052,59054,59071,59081,59110,59114,59115,59147,59155,59159,59242,59243,59303,59326,59331,59339,59340,59344,59353,59388,59394,59399,59477,59478,59481,59482,59503,59515,59555,59558,59573,59576,59586,59632,59637,59641,59677,59679,59681,59691,59707,59723,59747,59751,59772,59799,59804,59806,59872,59879,59928,59942,59944,59956,59968,59970,59971,59983,60014,60018,60023);
     
    UPDATE `quest_template` SET `PrevQuestId` = 27476 WHERE `Id` = 27483;
    UPDATE `quest_template` SET `PrevQuestId` = 27476 WHERE `Id` = 27480;
    UPDATE `quest_template` SET `PrevQuestId` = 27484 WHERE `Id` = 27510;
    UPDATE `quest_template` SET `PrevQuestId` = 27518 WHERE `Id` = 27542;
    UPDATE `quest_template` SET `PrevQuestId` = 27542 WHERE `Id` = 27550;
    UPDATE `quest_template` SET `PrevQuestId` = 27542 WHERE `Id` = 27548;
    UPDATE `quest_template` SET `PrevQuestId` = 27542 WHERE `Id` = 27547;
     
    DELETE FROM `gameobject` WHERE `id`=106319;
    DELETE FROM `creature_text` WHERE `entry`=44942;
    INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
    (44942, 0, 0, 'Thank you, friend. Let''ll end a couple of those ... Spider-age. Y-yes ... it sounds like something out loud is not very ...', 12, 0, 100, 5, 0, 0, ''),
    (44942, 0, 1, 'We will find the commander of the operation and finish!', 12, 0, 100, 5, 0, 0, ''),
    (44942, 0, 2, 'I need a drink!', 12, 0, 100, 5, 0, 0, '');
     
     
    -- Webbed Victim
    SET @ENTRY := 44941;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,6,0,100,0,0,0,0,0,86,83927,0,21,100,0,0,21,100,0,0,0.0,0.0,0.0,0.0,"closest player cast 83927");
     
    UPDATE `creature_template` SET `minlevel` = 11, `maxlevel` = 11, `faction_A` = 5, `faction_H` = 5, `unit_flags` = 32776, `AIName` = '' WHERE `entry` = 44942;
     
     
    -- Orc Sea Dog
    SET @ENTRY := 44942;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,54,0,100,0,0,0,0,0,80,4494200,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"just summoned do action");
     
     
    -- Orc Sea Dog
    SET @ENTRY := 4494200;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 0"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,0,0,0,0,33,44942,0,0,0,0,0,23,0,0,0,0.0,0.0,0.0,0.0,"give credit to owner");
     
    UPDATE `creature_template` SET `KillCredit1` = 1781 WHERE `entry` = 1780;
     
    UPDATE `creature_template` SET `VehicleId` = 1063 WHERE `entry` = 44367;
     
    DELETE FROM creature WHERE id=44367;
    INSERT INTO `creature` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
    (44367, 0, 1, 1, 781.967, 1633.18, 29.73663, 0.8739128, 120, 0, 0); -- 44367 (Area: 928) (possible waypoints or random movement)
     
    update creature set movementtype=1,spawndist=120 WHERE id=44367;
     
    -- Mutant Bush Chicken
    SET @ENTRY := 44935;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,2,60,0,100,1,1000,1000,0,0,29,0,0,0,0,0,0,11,44367,100,0,0.0,0.0,0.0,0.0,"on summon go to Ettin"),
    (@ENTRY,@SOURCETYPE,1,0,38,0,100,0,0,1,0,0,80,4493500,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"on data set 1 do action"),
    (@ENTRY,@SOURCETYPE,2,0,61,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"set run self");
     
    -- Mutant Bush Chicken
    SET @ENTRY := 4493500;
    SET @SOURCETYPE := 9;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,100,100,0,0,11,46598,0,0,0,0,0,19,44367,100,0,0.0,0.0,0.0,0.0,"jump on vehicle"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,3000,3000,0,0,11,83903,0,0,0,0,0,1,44367,100,0,0.0,0.0,0.0,0.0,"cast 83903on self"),
    (@ENTRY,@SOURCETYPE,2,0,0,0,100,0,100,100,0,0,51,0,0,0,0,0,0,19,44367,0,0,0.0,0.0,0.0,0.0,"kill unit"),
    (@ENTRY,@SOURCETYPE,3,0,0,0,100,0,0,0,0,0,33,44367,0,0,0,0,0,23,0,0,0,0.0,0.0,0.0,0.0,"give credit");
     
    -- Forest Ettin
    SET @ENTRY := 44367;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,0,0,100,0,5000,7000,17000,22000,11,80146,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Cast Bonk"),
    (@ENTRY,@SOURCETYPE,1,0,0,0,100,0,12000,15000,28000,35000,11,88421,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Cast Log Smash"),
    (@ENTRY,@SOURCETYPE,2,0,60,0,100,0,5000,5000,10000,10000,45,0,1,0,0,0,0,19,44935,10,0,0.0,0.0,0.0,0.0,"update send data to chicken");
     
     
    UPDATE `quest_template` SET `SourceSpellId` = 83982 WHERE `Id` = 27097;
    UPDATE `creature_template` SET `minlevel` = 15, `maxlevel` = 15, `faction_A` = 5, `faction_H` = 5, `attackpower` = 6520, `unit_flags` = 32776, `type_flags` = 0, `VehicleId` = 1075, `InhabitType` = 4, `HoverHeight` = 2.4 WHERE `entry` = 44951;
    DELETE FROM `creature_template_addon` WHERE (`entry`=44951);
    INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (44951, 0, 0, 50397184, 1, 0, '');
    UPDATE `creature_template` SET `unit_class` = 2 WHERE `entry` = 44951;
     
    DELETE FROM `creature_text` WHERE entry=44951;
    INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
    (44951, 0, 1, 'The warmth of this place sickens me.', 12, 0, 100, 0, 0, 0, ''),
    (44951, 0, 0, 'I sense doom in your future, $n.', 12, 0, 100, 0, 0, 0, ''),
    (44951, 1, 0, 'Rise and destroy our enemies!', 14, 0, 100, 0, 0, 0, ''),
    (44951, 1, 1, 'Rise, Hillsbrad Refugee! Become Forsaken!', 14, 0, 100, 0, 0, 0, ''),
    (44951, 0, 2, 'Waste no time, $n. We mustn''t keep the Banshee Queen waiting.', 12, 0, 100, 0, 0, 0, ''),
    (44951, 1, 2, 'Bow before your new master!', 14, 0, 100, 0, 0, 0, ''),
    (44951, 2, 0, 'This way, $n. We will take them by surprise.', 12, 0, 100, 457, 0, 0, ''),
    (44951, 3, 0, 'Run...', 12, 0, 100, 457, 0, 0, ''),
    (44951, 3, 1, 'RUN!', 12, 0, 100, 457, 0, 0, '');
     
    DELETE FROM `creature_involvedrelation` WHERE id=44951;
    INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES ('44951', '27097');
     
    DELETE FROM `creature_text` WHERE entry=44963;
    INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
    (44963, 0, 0, 'To the glory of the Dark Lady!', 12, 1, 100, 15, 0, 0, ''),
    (44963, 0, 1, 'I am eternal... I am death.', 12, 1, 100, 273, 0, 0, ''),
    (44963, 0, 2, 'Wha... What has happened?', 12, 1, 100, 6, 0, 0, ''),
    (44963, 0, 3, 'I am Forsaken.', 12, 1, 100, 66, 0, 0, '');
    UPDATE `creature_template` SET `faction_A` = 68, `faction_H` = 68, `unit_flags` = 33536 WHERE `entry` = 44963;
     
     
    DELETE FROM `creature_template_addon` WHERE (`entry`=45270);
    DELETE FROM `creature` WHERE `id`=45270;
     
    DELETE FROM `creature` WHERE `id`=44954;
    INSERT INTO `creature` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
    (44954, 0, 1, 1, 1065.004, 739.4683, 45.38259, 2.951549, 120, 0, 0),
    (44954, 0, 1, 1, 1078.26, 716.108, 46.21903, 3.065562, 120, 0, 0),
    (44954, 0, 1, 1, 1078.032, 713.1166, 46.86649, 3.071656, 120, 0, 0),
    (44954, 0, 1, 1, 977.925, 630.656, 53.40493, 2.984513, 120, 0, 0),
    (44954, 0, 1, 1, 950.566, 627.721, 53.61423, 1.48353, 120, 0, 0),
    (44954, 0, 1, 1, 988.238, 605.0987, 55.0663, 5.943095, 120, 0, 0),
    (44954, 0, 1, 1, 948.477, 634.106, 53.43565, 5.646388, 120, 0, 0),
    (44954, 0, 1, 1, 953.5855, 712.905, 59.39228, 4.721546, 120, 0, 0),
    (44954, 0, 1, 1, 985.6078, 743.5355, 60.09973, 1.385859, 120, 0, 0),
    (44954, 0, 1, 1, 944.83, 681.802, 59.34833, 3.228859, 120, 0, 0),
    (44954, 0, 1, 1, 977.24, 636.233, 53.70723, 3.036873, 120, 0, 0),
    (44954, 0, 1, 1, 914.627, 697.276, 54.19193, 1.518436, 120, 0, 0),
    (44954, 0, 1, 1, 913.1692, 712.7667, 55.29779, 2.358877, 120, 0, 0),
    (44954, 0, 1, 1, 912.052, 680.637, 53.63503, 3.193953, 120, 0, 0),
    (44954, 0, 1, 1, 855.2161, 594.6187, 35.90318, 2.884347, 120, 0, 0),
    (44954, 0, 1, 1, 863.6045, 595.5145, 36.40539, 2.884965, 120, 0, 0);
     
    DELETE FROM `creature` WHERE `id`=44962;
    DELETE FROM `creature` WHERE `id`=44963;
    DELETE FROM `creature` WHERE `id`=44964;
    DELETE FROM `creature` WHERE `id`=44965;
     
    DELETE FROM creature WHERE id=44966;
    INSERT INTO creature(id, map, zoneId, areaId, spawnMask, phaseMask, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, dynamicflags) VALUES
    (44966, 0, 0, 0, 1, 1, 0, 0, 977.655, 614.695, 54.0813, 1.13184, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (44966, 0, 0, 0, 1, 1, 0, 0, 1002.91, 734.892, 59.2673, 2.38464, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (44966, 0, 0, 0, 1, 1, 0, 0, 963.105, 729.727, 59.3923, 2.82878, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (44966, 0, 0, 0, 1, 1, 0, 0, 1022.21, 725.2, 60.2404, 0.10472, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (44966, 0, 0, 0, 1, 1, 0, 0, 946.639, 696.479, 59.3605, 1.58825, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (44966, 0, 0, 0, 1, 1, 0, 0, 1022.32, 728.483, 59.4135, 6.10865, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (44966, 0, 0, 0, 1, 1, 0, 0, 944.477, 694.101, 59.367, 3.26377, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (44966, 0, 0, 0, 1, 1, 0, 0, 944.193, 679.759, 59.3609, 3.28122, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (44966, 0, 0, 0, 1, 1, 0, 0, 1051.47, 693.757, 53.5873, 0.478449, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (44966, 0, 0, 0, 1, 1, 0, 0, 1047.48, 729.684, 51.9015, 0.668456, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (44966, 0, 0, 0, 1, 1, 0, 0, 912.061, 693.785, 53.6937, 3.15905, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (44966, 0, 0, 0, 1, 1, 0, 0, 854.571, 687.913, 53.501, 6.24887, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (44966, 0, 0, 0, 1, 1, 0, 0, 854.613, 696.894, 53.6658, 3.35103, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (44966, 0, 0, 0, 1, 1, 0, 0, 912.061, 693.785, 53.6937, 3.15905, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (44966, 0, 0, 0, 1, 1, 0, 0, 912.052, 680.637, 53.635, 3.19395, 120, 0, 0, 1, 0, 0, 0, 0, 0);
     
    DELETE FROM `creature` WHERE `id`=44961;
    DELETE FROM `creature` WHERE `id`=44960;
    DELETE FROM `creature` WHERE `id`=44959;
    DELETE FROM `creature` WHERE `id`=44958;
    DELETE FROM `creature` WHERE `id`=1954;
    DELETE FROM `creature` WHERE `id`=1953;
    DELETE FROM `creature` WHERE `id`=1944;
    DELETE FROM `creature` WHERE `id`=1909;
    DELETE FROM creature WHERE id=1908;
    INSERT INTO creature(id, map, zoneId, areaId, spawnMask, phaseMask, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, dynamicflags) VALUES
    (1908, 0, 0, 0, 1, 1, 0, 0, 1185.31, 414.162, 49.5933, 4.84222, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1187.02, 395.631, 33.68, 0.2357, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1206.91, 392.507, 33.8836, 2.39373, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1207.46, 391.894, 33.8453, 1.309, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1164.88, 389.356, 42.8029, 5.49843, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1205.21, 386.459, 35.1851, 6.05968, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1208.71, 384.444, 34.2874, 0, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1209.09, 384.243, 34.1787, 3.91543, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1205.48, 379.745, 35.3102, 5.32067, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1191.52, 377.749, 34.6118, 4.9681, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1209.65, 377.613, 34.9533, 0, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1209.81, 377.42, 34.9229, 2.87392, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1213.38, 375.974, 33.7508, 6.02605, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1214.07, 375.45, 33.4909, 0.837758, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1205.97, 372.136, 34.5291, 5.71359, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1214.88, 368.227, 33.1559, 5.63741, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1186.54, 357.611, 33.3138, 0.934485, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1201.2, 355.009, 34.2184, 0, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1202.37, 348.826, 34.8965, 1.02232, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1207.03, 343.741, 35.096, 3.53238, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1197.2, 341.508, 34.8138, 5.38283, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1197.86, 341.314, 34.8853, 0, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1206.43, 330.7, 35.6831, 0, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1206.9, 327.5, 35.4892, 6.03252, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1184.9, 326.56, 35.8642, 5.85624, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1173.31, 304.035, 34.0949, 0, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1119.49, 313.508, 33.9023, 0.215139, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1092.34, 320.01, 36.1971, 0.191366, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1121.07, 295.027, 33.3797, 0.478103, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1091.06, 307.8, 37.5178, 1.73181, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1080.39, 316.139, 36.0186, 3.95285, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1108.75, 275.125, 34.3927, 3.13995, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1109.46, 247.474, 34.0745, 0, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1085.44, 261.636, 34.9729, 1.79655, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1070.9, 270.911, 35.8935, 2.33091, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1125.61, 223.517, 34.0261, 1.84197, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1110.43, 230.991, 34.0745, 0, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1082.79, 251.669, 35.2698, 0.555996, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1051.01, 280.637, 36.1067, 0.594788, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1041.67, 225, 35.67, 2.93736, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1043.96, 247.663, 36.7806, 1.62172, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1111.41, 211.209, 36.0015, 2.07539, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1095.72, 212.644, 35.2188, 1.50264, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1089.88, 241.215, 35.1162, 0.544105, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1098.63, 222.955, 36.14, 0, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1096.52, 207.795, 35.247, 0, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1027.68, 275.652, 34.9801, 2.2359, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1034.48, 178.321, 31.1297, 0.153508, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1023.49, 153.177, 37.0377, 5.19873, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1012.83, 168.328, 40.1206, 0, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 994.842, 196.868, 34.3679, 0, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 1008.83, 154.12, 40.7567, 0, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 995.319, 163.626, 39.0784, 1.76921, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 981.296, 181.96, 36.7678, 2.72071, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 979.833, 180.622, 37.1221, 0, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 979.486, 157.065, 37.472, 1.95009, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 978.288, 150.145, 37.554, 3.13382, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 959.114, 208.201, 35.6375, 5.91845, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 980.2, 137.755, 35.6254, 0, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 961.119, 167.971, 38.0604, 4.65768, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 969.842, 147.526, 36.8377, 0, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 952.331, 188.18, 38.5821, 2.18379, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 961.591, 140.566, 35.5633, 4.78558, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 938.368, 206.513, 37.2047, 0.230281, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 865.994, 170.738, 35.268, 6.13052, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 924.341, 190.332, 38.7584, 2.08073, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 894.284, 221.898, 33.486, 5.48674, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 909.298, 149.083, 37.3836, 4.11309, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 905.318, 159.471, 37.6319, 5.88782, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 939.165, 128.749, 33.882, 0.0960076, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 903.497, 141.882, 35.7757, 0.971526, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 861.962, 116.549, 33.515, 0, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 853.469, 127.627, 37.5903, 0, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 879.9, 86.4353, 34.0746, 2.34897, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 838.171, 145.387, 37.6239, 3.2433, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 872.78, 80.9699, 33.9976, 1.48454, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 872.813, 80.6458, 33.9618, 0, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 869.172, 78.7587, 34.0472, 0, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 867.599, 75.3351, 33.7361, 0, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 858.809, 82.6181, 34.7726, 0, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 862.194, 79.0052, 34.6184, 0, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 858.93, 82.3663, 34.6082, 5.81076, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 858.623, 70.6493, 34.3896, 0, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 859.623, 69.5067, 34.0515, 0.802738, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 804.986, 164.122, 34.3587, 5.18034, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 819.247, 102.375, 37.679, 4.40664, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 803.295, 194.98, 34.9169, 1.44366, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 806.287, 122.9, 38.423, 3.93483, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 798.25, 156.826, 35.5367, 0.965001, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 826.067, 76.3143, 36.1883, 1.70838, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 821.309, 79.309, 35.5278, 0, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 831.438, 63.7344, 36.2486, 0, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 829.065, 62.3845, 36.008, 3.67354, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 789.902, 195.952, 37.925, 2.95889, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 808.007, 60.4895, 34.936, 1.47733, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 786.403, 96.8742, 35.2005, 4.06828, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 775.06, 215.804, 42.0516, 5.83742, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 775.745, 241.594, 37.6443, 2.79971, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 769.191, 112.995, 35.1718, 3.05854, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 714.389, 202.537, 34.5639, 0.899462, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 710.434, 206.7, 34.2309, 1.60301, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 713.254, 211.199, 35.5809, 2.35584, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 727.64, 192.201, 33.5958, 3.12837, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 719.01, 197.271, 34.1878, 5.16304, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 728.743, 203.755, 35.8935, 5.22318, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 744.735, 203.953, 37.9123, 2.71028, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 737.135, 190.452, 33.9445, 1.16531, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 782.693, 271.252, 36.7301, 5.88035, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 750.909, 275.238, 38.6943, 3.53114, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (1908, 0, 0, 0, 1, 1, 0, 0, 740.213, 307.378, 33.6491, 2.09507, 120, 0, 0, 1, 0, 0, 0, 0, 0);
     
    DELETE FROM `creature` WHERE id=44966;
    INSERT INTO `creature` (id, map, zoneId, areaId, spawnMask, phaseMask, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, dynamicflags) VALUES
    (44966, 0, 0, 0, 1, 1, 0, 0, 912.052, 680.637, 53.635, 3.19395, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (44966, 0, 0, 0, 1, 1, 0, 0, 912.061, 693.785, 53.6937, 3.15905, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (44966, 0, 0, 0, 1, 1, 0, 0, 854.613, 696.894, 53.6658, 3.35103, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (44966, 0, 0, 0, 1, 1, 0, 0, 854.571, 687.913, 53.501, 6.24887, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (44966, 0, 0, 0, 1, 1, 0, 0, 912.061, 693.785, 53.6937, 3.15905, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (44966, 0, 0, 0, 1, 1, 0, 0, 1047.48, 729.684, 51.9015, 0.668456, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (44966, 0, 0, 0, 1, 1, 0, 0, 1051.47, 693.757, 53.5873, 0.478449, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (44966, 0, 0, 0, 1, 1, 0, 0, 944.193, 679.759, 59.3609, 3.28122, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (44966, 0, 0, 0, 1, 1, 0, 0, 944.477, 694.101, 59.367, 3.26377, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (44966, 0, 0, 0, 1, 1, 0, 0, 1022.32, 728.483, 59.4135, 6.10865, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (44966, 0, 0, 0, 1, 1, 0, 0, 946.639, 696.479, 59.3605, 1.58825, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (44966, 0, 0, 0, 1, 1, 0, 0, 1022.21, 725.2, 60.2404, 0.10472, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (44966, 0, 0, 0, 1, 1, 0, 0, 963.105, 729.727, 59.3923, 2.82878, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (44966, 0, 0, 0, 1, 1, 0, 0, 1002.91, 734.892, 59.2673, 2.38464, 120, 0, 0, 1, 0, 0, 0, 0, 0),
    (44966, 0, 0, 0, 1, 1, 0, 0, 977.655, 614.695, 54.0813, 1.13184, 120, 0, 0, 1, 0, 0, 0, 0, 0);
     
    DELETE FROM `creature` WHERE `id`=1947;
    DELETE FROM `creature` WHERE `id`=1948;
    DELETE FROM `creature` WHERE `id`=45032;
     
     
    UPDATE `creature_template` SET `npcflag` = 0 WHERE `entry` = 45195;
    -- Bloodfang Stalker
    SET @ENTRY := 45195;
    SET @SOURCETYPE := 0;
     
    DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
    UPDATE `creature_template` SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
    INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
    (@ENTRY,@SOURCETYPE,0,0,11,0,100,1,0,0,0,0,11,86237,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Cast Stalking on Spawn"),
    (@ENTRY,@SOURCETYPE,1,0,7,0,100,1,0,0,0,0,11,86237,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Cast Stalking on Evade"),
    (@ENTRY,@SOURCETYPE,2,0,2,0,100,1,0,30,0,0,11,79864,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Cast Shadowstep at 30% HP"),
    (@ENTRY,@SOURCETYPE,3,0,0,0,100,0,3000,4500,12000,15000,11,60195,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Cast Sinister Strike"),
    (@ENTRY,@SOURCETYPE,4,0,6,0,100,0,0,0,0,0,7,27181,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"on death add quest 27181");
     
     
    DELETE FROM `conditions` WHERE SourceTypeOrReferenceId=22 AND ConditionTypeOrReference=8;
    DELETE FROM `conditions` WHERE SourceTypeOrReferenceId=22 AND ConditionTypeOrReference=9;
    DELETE FROM `conditions` WHERE SourceTypeOrReferenceId=22 AND ConditionTypeOrReference=28;
    INSERT INTO `conditions` (SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorType, ErrorTextId, ScriptName, Comment) VALUES
    (22, 5, 45195, 0, 0, 8, 0, 27181, 0, 0, 1, 0, 0, '', null),
    (22, 5, 45195, 0, 0, 9, 0, 27181, 0, 0, 1, 0, 0, '', null),
    (22, 5, 45195, 0, 0, 28, 0, 27181, 0, 0, 1, 0, 0, '', null);
     
    UPDATE creature_template SET faction_A=16 WHERE entry=49424;
    UPDATE creature_template SET faction_H=16 WHERE entry=49424;
    UPDATE creature_template set modelid1=16480,modelid2=0, modelid3=0,modelid4=0 WHERE entry=50373;
    UPDATE creature_template set flags_extra=128 WHERE entry=50373;
     
    DELETE FROM gameobject WHERE id IN (
    2843  ,
    2849  ,
    75293 ,
    106318,
    205878,
    205879,
    205880,
    205881);
    INSERT INTO gameobject(id, map, spawnMask, phaseMask, position_x, position_y, position_z, orientation, rotation0, rotation1, rotation2, rotation3, spawntimesecs, animprogress, state) VALUES
    (2843, 0, 1, 1, 2081.69, 1967.03, 101.193, 2.82743, 0, 0, 0.987688, 0.156436, 120, 100, 1),
    (2849, 0, 1, 1, -11332, 1731.29, 38.489, -1, 0, 0, -0.479426, 0.877583, 120, 100, 1),
    (106318, 0, 1, 1, 2549.84, 783.776, 110.478, 3.072, 0, 0, 0.999395, 0.0347893, 120, 100, 1),
    (2843, 0, 1, 1, 1788.45, 1344.75, 89.389, -1, 0, 0, -0.479426, 0.877583, 120, 100, 1),
    (106318, 0, 1, 1, -9973.6, -155.299, 24.4805, 1.23918, 0, 0, 0.580701, 0.814117, 120, 100, 1),
    (106318, 0, 1, 1, 2603.06, 1464.46, -10.673, 2.53072, 0, 0, 0.953716, 0.300709, 120, 100, 1),
    (106318, 0, 1, 1, -9734, 136.241, 18.712, -3, 0, 0, -0.997495, 0.0707372, 120, 100, 1),
    (2849, 0, 1, 1, -5700.12, -3867.4, 331.614, -1.27409, 0, 0, -0.594823, 0.803857, 120, 100, 1),
    (2849, 0, 1, 1, -5117.36, -3315.32, 250.467, -1.18682, 0, 0, -0.559191, 0.829039, 120, 100, 1),
    (2849, 0, 1, 1, -9251.55, -2707.21, 88.8043, 1.93731, 0, 0, 0.824125, 0.566409, 120, 100, 1),
    (2849, 0, 1, 1, -8949.61, -2309.69, 132.443, 2.72271, 0, 0, 0.978147, 0.207914, 120, 100, 1),
    (2849, 0, 1, 1, -9779.8, -2270.56, 59.3705, 2.65289, 0, 0, 0.970294, 0.241927, 120, 100, 1),
    (2843, 0, 1, 1, -6524.63, 362.427, 388.329, -2.75761, 0, 0, -0.981626, 0.190814, 120, 100, 1),
    (2843, 0, 1, 1, -6507.27, 688.761, 387.274, -0.314158, 0, 0, -0.156434, 0.987688, 120, 100, 1),
    (106318, 0, 1, 1, -9838.12, 207.45, 14.054, 1.06465, 0, 0, 0.507538, 0.861629, 120, 100, 1),
    (106318, 0, 1, 1, 2036.27, -455.528, 35.8657, 2.25147, 0, 0, 0.902584, 0.430513, 120, 100, 1),
    (106318, 0, 1, 1, -9303.33, -282.874, 71.1022, -2.23402, 0, 0, -0.898794, 0.438372, 120, 100, 1),
    (106318, 0, 1, 1, -9796.16, -929.679, 39.1327, -0.401425, 0, 0, -0.199368, 0.979925, 120, 100, 1),
    (106318, 0, 1, 1, -10071.6, 631.747, 39.3654, 0, 0, 0, 0, 1, 120, 100, 1),
    (106318, 0, 1, 1, -9940.88, -116.771, 24.9764, 2.23402, 0, 0, 0.898794, 0.438372, 120, 100, 1),
    (106318, 0, 1, 1, -9739.5, -934.509, 38.9182, 1.51844, 0, 0, 0.688356, 0.725373, 120, 100, 1),
    (106318, 0, 1, 1, -9828, 86.875, 0.879, 0, 0, 0, 0, 1, 120, 100, 1),
    (106318, 0, 1, 1, -9216, -1228, 72.3836, 5.891, 0, 0, 0.194838, -0.980835, 120, 100, 1),
    ( 205879, 0, 1, 1, 1598.97, -5280.33, 75.8868, -0.401424, 0, 0, -0.199367, 0.979925, 120, 100, 1),
    ( 205880, 0, 1, 1, 1579.63, -5315.36, 75.8868, -0.750491, 0, 0, -0.366501, 0.930418, 120, 100, 1),
    ( 205881, 0, 1, 1, 1621.18, -5346.45, 75.8869, 1.65806, 0, 0, 0.737277, 0.675591, 120, 100, 1),
    ( 205878, 0, 1, 1, 1643.2, -5301.81, 75.8869, 2.67035, 0, 0, 0.972369, 0.233448, 120, 100, 1),
    ( 2849, 0, 1, 1, -11151, 729.512, 33.619, 2.356, 0, 0, 0.923842, 0.382773, 120, 100, 1),
    ( 106318, 0, 1, 1, 2909.79, 379.327, 31.667, -3, 0, 0, -0.997495, 0.0707372, 120, 100, 1),
    ( 2843, 0, 1, 1, -9039, -304, 74.354, 2.286, 0, 0, 0.909882, 0.414867, 120, 100, 1),
    ( 106318, 0, 1, 1, -5660, 655.705, 383.569, 2.635, 0, 0, 0.968092, 0.250596, 120, 100, 1),
    ( 2843, 0, 1, 1, 1964.25, 1383.72, 64.0972, -1, 0, 0, -0.479426, 0.877583, 120, 100, 1),
    ( 106318, 0, 1, 1, -9749, 84.423, 13.209, 2.653, 0, 0, 0.970308, 0.241874, 120, 100, 1),
    ( 106318, 0, 1, 1, -9804.88, -933.027, 39.8566, 0.995, 0, 0, 0.47723, 0.878778, 120, 100, 1),
    ( 106318, 0, 1, 1, -5589, 669.436, 394.492, -1, 0, 0, -0.479426, 0.877583, 120, 100, 1),
    ( 2843, 0, 1, 1, 2017.35, 1853.37, 102.838, -2, 0, 0, -0.841471, 0.540302, 120, 100, 1),
    ( 106318, 0, 1, 1, -5534.88, -1703.65, 342.914, -2, 0, 0, -0.841471, 0.540302, 120, 100, 1),
    ( 106318, 0, 1, 1, -5406.3, -128.7, 368.288, -1, 0, 0, -0.479426, 0.877583, 120, 100, 1),
    ( 106318, 0, 1, 1, 2760.54, 790.103, 114.367, 1.955, 0, 0, 0.829102, 0.559097, 120, 100, 1),
    ( 106318, 0, 1, 1, -9051, -625, 53.454, 1.361, 0, 0, 0.629182, 0.777258, 120, 100, 1),
    ( 106318, 0, 1, 1, -9268, -1179, 70.1113, 0.436, 0, 0, 0.216277, 0.976332, 120, 100, 1),
    ( 2843, 0, 1, 1, 1901.25, 1488.57, 93.95, 1.449, 0, 0, 0.662761, 0.748831, 120, 100, 1),
    ( 106318, 0, 1, 1, -5513, -1746, 336.938, 2.059, 0, 0, 0.857041, 0.515247, 120, 100, 1),
    ( 2849, 0, 1, 1, -4836, -3880, 301.562, 3.089, 0, 0, 0.999654, 0.0262933, 120, 100, 1),
    ( 106318, 0, 1, 1, 1806.8, 726.838, 54.2283, 2.356, 0, 0, 0.923842, 0.382773, 120, 100, 1),
    ( 106318, 0, 1, 1, -5586, -1750, 372.8, 0, 0, 0, 0, 1, 120, 100, 1),
    ( 106318, 0, 1, 1, -5671, -2124, 400.933, 2.409, 0, 0, 0.93366, 0.35816, 120, 100, 1),
    ( 2843, 0, 1, 1, -5054.1, -266.36, 441.729, 0.6322, 0, 0, 0.310862, 0.950455, 120, 100, 1),
    ( 2843, 0, 1, 1, -6489, 512.694, 387.292, 0.925, 0, 0, 0.446187, 0.89494, 120, 100, 1),
    ( 106318, 0, 1, 1, -9203, -1219, 70.0934, -1, 0, 0, -0.479426, 0.877583, 120, 100, 1),
    ( 106318, 0, 1, 1, -9716, -943, 38.412, 3.089, 0, 0, 0.999654, 0.0262933, 120, 100, 1),
    ( 2849, 0, 1, 1, -9504, -1897, 79.263, 0.175, 0, 0, 0.0873884, 0.996174, 120, 100, 1),
    ( 2843, 0, 1, 1, 1965.91, 1617.19, 88.2, 5.648, 0, 0, 0.312281, -0.94999, 120, 100, 1),
    ( 2849, 0, 1, 1, -9471, -1887, 83.315, -1, 0, 0, -0.479426, 0.877583, 120, 100, 1),
    ( 2849, 0, 1, 1, -11398, 1805.32, 6.738, 0, 0, 0, 0, 1, 120, 100, 1),
    ( 106318, 0, 1, 1, -5580, 735.881, 392.456, 2.897, 0, 0, 0.992531, 0.121992, 120, 100, 1),
    ( 106318, 0, 1, 1, -5301.79, -98.5944, 400.765, 1.623, 0, 0, 0.725321, 0.688411, 120, 100, 1),
    ( 2843, 0, 1, 1, -9728, 113.06, 24.463, 6.055, 0, 0, 0.113845, -0.993499, 120, 100, 1),
    ( 106318, 0, 1, 1, -8882, -762, 68.411, 3.054, 0, 0, 0.999041, 0.0437824, 120, 100, 1),
    ( 106318, 0, 1, 1, -9442, 468.709, 53.275, 0, 0, 0, 0, 1, 120, 100, 1),
    ( 106318, 0, 1, 1, -9914, -1087, 25.253, 1.082, 0, 0, 0.514993, 0.857194, 120, 100, 1),
    ( 2849, 0, 1, 1, -5710, -3918, 344.945, 0.367, 0, 0, 0.182472, 0.983211, 120, 100, 1),
    ( 2849, 1, 1, 1, 1261.72, -3628, 90.402, 0, 0, 0, 0, 1, 120, 100, 1),
    ( 106318, 1, 1, 1, -2389, 449.59, 74.992, 1.152, 0, 0, 0.544674, 0.838648, 120, 100, 1),
    ( 106318, 1, 1, 1, -910, -4489, 29.686, -2, 0, 0, -0.841471, 0.540302, 120, 100, 1),
    ( 2849, 1, 1, 1, 7356.2, -800, 8.262, 0, 0, 0, 0, 1, 120, 100, 1),
    ( 106318, 1, 1, 1, 936.459, -4764, 23.514, 1.083, 0, 0, 0.515422, 0.856937, 120, 100, 1),
    ( 106318, 1, 1, 1, -825, -44, -13, -2, 0, 0, -0.841471, 0.540302, 120, 100, 1),
    ( 106318, 1, 1, 1, 876.966, -4741.63, 30.0402, -1, 0, 0, -0.479426, 0.877583, 120, 100, 1),
    ( 106318, 1, 1, 1, -666, -786, 43.129, 1.431, 0, 0, 0.655995, 0.754765, 120, 100, 1),
    ( 106318, 1, 1, 1, 960.305, -4781, 21.444, 2.025, 0, 0, 0.848159, 0.529742, 120, 100, 1),
    ( 2849, 1, 1, 1, -1915, -1761, 91.668, 1.92, 0, 0, 0.819192, 0.57352, 120, 100, 1),
    ( 106318, 1, 1, 1, 1442.9, -4723, -17, -1, 0, 0, -0.479426, 0.877583, 120, 100, 1),
    ( 106318, 1, 1, 1, -1161, 529.876, 28.384, -1, 0, 0, -0.479426, 0.877583, 120, 100, 1),
    ( 106318, 1, 1, 1, -157, -5240, -2, -2, 0, 0, -0.841471, 0.540302, 120, 100, 1),
    ( 106318, 1, 1, 1, 717.344, -4469, 15.668, -1, 0, 0, -0.479426, 0.877583, 120, 100, 1),
    ( 106318, 1, 1, 1, -2402, 233.932, 49.28, 2.81, 0, 0, 0.986287, 0.165038, 120, 100, 1),
    ( 2843, 1, 1, 1, 8009.84, -887, 1.243, 1.777, 0, 0, 0.776127, 0.630577, 120, 100, 1),
    ( 2849, 1, 1, 1, 7186.58, -748, 76.089, 0, 0, 0, 0, 1, 120, 100, 1),
    ( 2849, 1, 1, 1, 3459.36, 633.122, 9.543, 2.304, 0, 0, 0.913579, 0.406661, 120, 100, 1),
    ( 2849, 1, 1, 1, -2010, -2135, 91.667, 0.314, 0, 0, 0.156356, 0.987701, 120, 100, 1),
    ( 106318, 1, 1, 1, -89, -4047, 64.565, -1, 0, 0, -0.479426, 0.877583, 120, 100, 1),
    ( 2849, 1, 1, 1, -2058, -1966, 91.667, 0.14, 0, 0, 0.0699428, 0.997551, 120, 100, 1),
    ( 106318, 1, 1, 1, -1734.92, 420.683, 97.2078, 0.279252, 0, 0, 0.139173, 0.990268, 120, 100, 1),
    ( 106318, 1, 1, 1, 1106.89, -4706.9, 17.5527, -0.244346, 0, 0, -0.121869, 0.992546, 120, 100, 1),
    ( 106318, 1, 1, 1, -2750.03, -430.934, -2.93079, 2.94959, 0, 0, 0.995395, 0.0958539, 120, 100, 1),
    ( 106318, 1, 1, 1, 852.074, -4187.02, -10.9082, -0.157079, 0, 0, -0.0784588, 0.996917, 120, 100, 1),
    ( 106318, 1, 1, 1, 440.375, -4213.46, 25.2133, -1.74533, 0, 0, -0.766045, 0.642787, 120, 100, 1),
    ( 106318, 1, 1, 1, 51.3314, -4452.3, 48.4894, 0.331611, 0, 0, 0.165047, 0.986286, 120, 100, 1),
    ( 106318, 1, 1, 1, 856.534, -4209.93, -11.351, -0.977383, 0, 0, -0.469471, 0.882948, 120, 100, 1),
    ( 106318, 1, 1, 1, 915.269, -4714.02, 22.9547, -1.27409, 0, 0, -0.594823, 0.803857, 120, 100, 1),
    ( 106318, 1, 1, 1, 35.211, -4301, 69.052, 1.588, 0, 0, 0.713163, 0.700998, 120, 100, 1),
    ( 2849, 1, 1, 1, 7461.66, -861.202, 1.05914, 2.11185, 0, 0, 0.870356, 0.492423, 120, 100, 1),
    ( 2849, 1, 1, 1, 7562.19, -879.454, 17.5976, 2.84488, 0, 0, 0.989015, 0.147813, 120, 100, 1),
    ( 2849, 1, 1, 1, -1921, -2706, 93.0172, 2.007, 0, 0, 0.843357, 0.537354, 120, 100, 1),
    ( 2849, 1, 1, 1, -2095, -2576, 91.757, -1, 0, 0, -0.479426, 0.877583, 120, 100, 1),
    ( 106318, 1, 1, 1, -715, 163.091, 43.758, 1.257, 0, 0, 0.587932, 0.80891, 120, 100, 1),
    ( 2849, 1, 1, 1, 7050.3, 426.994, -5, 0, 0, 0, 0, 1, 120, 100, 1),
    ( 106318, 1, 1, 1, 9184.01, 1373.37, 1315.07, -3, 0, 0, -0.997495, 0.0707372, 120, 100, 1),
    ( 106318, 1, 1, 1, 9674, 454.641, 1309.96, 1.641, 0, 0, 0.731487, 0.681856, 120, 100, 1),
    ( 2849, 1, 1, 1, 4544.61, 425.187, 33.743, 0.733, 0, 0, 0.35835, 0.933587, 120, 100, 1),
    ( 106318, 1, 1, 1, -1190, -5575, 9.364, 0.175, 0, 0, 0.0873884, 0.996174, 120, 100, 1),
    ( 106318, 1, 1, 1, -546, 71.777, 52.759, 0.803, 0, 0, 0.390799, 0.920476, 120, 100, 1),
    ( 106318, 1, 1, 1, -1922, -692, 2.54, 0, 0, 0, 0, 1, 120, 100, 1),
    ( 106318, 1, 1, 1, -1923, -1051, 44.403, -1, 0, 0, -0.479426, 0.877583, 120, 100, 1),
    ( 106318, 1, 1, 1, 10889.5, 1968.89, 1321.76, -1, 0, 0, -0.479426, 0.877583, 120, 100, 1),
    ( 106318, 1, 1, 1, 1484.49, -4739, -4, 0.105, 0, 0, 0.0524759, 0.998622, 120, 100, 1),
    ( 106318, 1, 1, 1, 94.593, -4555, 55.006, -2, 0, 0, -0.841471, 0.540302, 120, 100, 1),
    ( 2843, 1, 1, 1, 10995.5, 964.79, 1334.47, 2.925, 0, 0, 0.994142, 0.108085, 120, 100, 1),
    ( 106318, 1, 1, 1, 1067.85, -4672, 13.7875, 0, 0, 0, 0, 1, 120, 100, 1),
    ( 106318, 1, 1, 1, -2782, -708, 6.352, 2.688, 0, 0, 0.974392, 0.224857, 120, 100, 1),
    ( 106318, 1, 1, 1, 10419.2, 1909.93, 1321.25, 2.618, 0, 0, 0.965927, 0.258816, 120, 100, 1),
    ( 106318, 1, 1, 1, 421.608, -4252, 26.858, 2.513, 0, 0, 0.951014, 0.309147, 120, 100, 1),
    ( 2843, 1, 1, 1, 10328.6, 1030.53, 1339.13, 2.798, 0, 0, 0.985279, 0.170952, 120, 100, 1),
    ( 106318, 1, 1, 1, 10619.6, 2089.65, 1336.64, -2, 0, 0, -0.841471, 0.540302, 120, 100, 1),
    ( 106318, 1, 1, 1, -174.871, -5115.7, 22.1271, 0.838, 0, 0, 0.406847, 0.913496, 120, 100, 1),
    ( 106318, 1, 1, 1, 19.877, -4274, 72.578, 1.588, 0, 0, 0.713163, 0.700998, 120, 100, 1),
    ( 106318, 1, 1, 1, 817.75, -4807, 11.162, 0.733, 0, 0, 0.35835, 0.933587, 120, 100, 1),
    ( 106318, 1, 1, 1, 10085.3, 1155.55, 1318.6, 1.466, 0, 0, 0.669102, 0.74317, 120, 100, 1),
    ( 2849, 1, 1, 1, 7389.17, -1117, 41.935, 0.541, 0, 0, 0.267213, 0.963637, 120, 100, 1),
    ( 106318, 1, 1, 1, 10875.1, 2073.58, 1328.34, 0, 0, 0, 0, 1, 120, 100, 1),
    ( 106318, 1, 1, 1, 116.43, -4558, 59.8, -3, 0, 0, -0.997495, 0.0707372, 120, 100, 1),
    ( 2849, 1, 1, 1, 4547.23, 154.427, 59.672, 1.815, 0, 0, 0.787967, 0.615718, 120, 100, 1),
    ( 75293, 36, 1, 1, -312.046, -477.501, 49.5979, -1.55334, 0, 0, 0.700909, -0.71325, 120, 100, 1),
    ( 75293, 36, 1, 1, -77.7409, -788.596, 26.1097, 1.16937, 0, 0, 0.551937, 0.833886, 120, 100, 1),
    ( 75293, 36, 1, 1, -209.206, -602.72, 19.3065, -0.139626, 0, 0, 0.069756, -0.997564, 120, 100, 1),
    ( 75293, 36, 1, 1, -63.0889, -797.013, 39.0067, 1.55334, 0, 0, 0.700909, 0.71325, 120, 100, 1),
    ( 75293, 36, 1, 1, -300.887, -532.542, 49.4236, 0.226893, 0, 0, 0.113203, 0.993572, 120, 100, 1),
    ( 75293, 43, 1, 1, -49.9295, 370.574, -59.6856, 0.575959, 0, 0, 0.284015, 0.95882, 120, 100, 1),
    ( 75293, 43, 1, 1, -79.462, -32.6, -59.1092, -0.296706, 0, 0, 0.147809, -0.989016, 120, 100, 1),
    ( 75293, 43, 1, 1, -95.0718, -311.132, -61.8035, 2.32129, 0, 0, 0.91706, 0.398749, 120, 100, 1),
    ( 75293, 43, 1, 1, -10.4679, -272.442, -66.1606, 0.715585, 0, 0, 0.350207, 0.936672, 120, 100, 1),
    ( 2849, 530, 1, 1, -1318.83, -11245.7, 0.202506, 1.18682, 0, 0, 0.559193, 0.829038, 120, 100, 1),
    ( 75293, 530, 1, 1, 6272.09, -6348.59, 79.1625, 0.401426, 0, 0, 0.199368, 0.979925, 120, 100, 1),
    ( 2843, 530, 1, 1, 8249.34, -6885.52, 87.3604, 5.15803, 0, 0, 0.533368, -0.845884, 120, 100, 1),
    ( 2843, 530, 1, 1, 8086.65, -6748.09, 64.5604, 5.50596, 0, 0, 0.378903, -0.925436, 120, 100, 1),
    ( 2843, 530, 1, 1, 8453.67, -6996.44, 93.1697, 2.0777, 0, 0, 0.861822, 0.507211, 120, 100, 1),
    ( 2843, 530, 1, 1, 8815.11, -6988.26, 33.6424, 3.25815, 0, 0, 0.998302, -0.058248, 120, 100, 1),
    ( 2843, 530, 1, 1, 7823.81, -6640.25, 27.4591, 0.393303, 0, 0, 0.195387, 0.980726, 120, 100, 1),
    ( 2843, 530, 1, 1, 7232.46, -6414.72, 56.1665, 3.2655, 0, 0, 0.998081, -0.0619165, 120, 100, 1),
    ( 2843, 530, 1, 1, 7157.67, -6612.69, 60.6594, 5.86517, 0, 0, 0.207487, -0.978238, 120, 100, 1),
    ( 2843, 530, 1, 1, 6301.62, -6475.85, 83.0104, 1.67507, 0, 0, 0.742996, 0.669296, 120, 100, 1);
     
    DELETE FROM  creature_questrelation WHERE id=31146;
    DELETE FROM  creature_questrelation WHERE id=31146;
    DELETE FROM creature_addon WHERE guid=24934;
    DELETE FROM creature_addon WHERE guid=25004;
    DELETE FROM creature_addon WHERE guid=25030;
    DELETE FROM creature_addon WHERE guid=25057;
    DELETE FROM creature_addon WHERE guid=25063;
    DELETE FROM creature_addon WHERE guid=25158;
    DELETE FROM creature_addon WHERE guid=25223;
    DELETE FROM creature_addon WHERE guid=25384;
    DELETE FROM creature_addon WHERE guid=25442;
    DELETE FROM creature_addon WHERE guid=25494;
    DELETE FROM creature_addon WHERE guid=25597;
    DELETE FROM creature_addon WHERE guid=25652;
    DELETE FROM creature_addon WHERE guid=25654;
    DELETE FROM creature_addon WHERE guid=25680;
    DELETE FROM creature_addon WHERE guid=25818;
    DELETE FROM creature_addon WHERE guid=25960;
    DELETE FROM creature_addon WHERE guid=26089;
    DELETE FROM creature_addon WHERE guid=26097;
    DELETE FROM creature_addon WHERE guid=63957;
    DELETE FROM smart_scripts WHERE event_param1=115757;
    DELETE FROM smart_scripts WHERE event_param1=100787;
     
    DELETE FROM creature WHERE guid=65055;
     
    UPDATE `creature_template` SET `npcflag` = '8' WHERE `entry` IN (44821,44894);
     
    UPDATE `creature_template` SET `npcflag` = '2' WHERE `entry` =45195;
     
    UPDATE `creature_template` SET `faction_A` = '190' WHERE `entry` =49424;
     
    UPDATE `creature_template` SET `npcflag` = '0' WHERE `entry` =44894;
     
    DELETE FROM `creature_questrelation` WHERE `quest` = 31146;
