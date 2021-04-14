-- NPC entry 29665 (Pazik "The Pick" Prylock), 29725 (Benik Boltshear) and 29728 (Walter Soref)
SET @MENU_ID := 9823;
SET @Pazik  := 29665;
SET @Benik  := 29725;
SET @Walter := 29728;

-- Corrected gossip menu options based on text found in broadcast_text:
DELETE FROM `gossip_menu_option` WHERE `menu_id` = @MENU_ID;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES
(@MENU_ID, 0,0, "I've lost my key to Scholomance.",                            30315,1,1,0,0,0,0,'',0),
(@MENU_ID, 1,0, "I've lost my key to The Arcatraz.",                           30316,1,1,0,0,0,0,'',0),
(@MENU_ID, 2,0, "I've lost my key to The Shattered Halls.",                    30317,1,1,0,0,0,0,'',0),
(@MENU_ID, 3,0, "I've lost my key to Searing Gorge.",                          30318,1,1,0,0,0,0,'',0),
(@MENU_ID, 4,0, "I've lost my Shadowforge Key.",                               30319,1,1,0,0,0,0,'',0),
(@MENU_ID, 5,0, "I've lost The Eye of Haramad.",                               30320,1,1,0,0,0,0,'',0),
(@MENU_ID, 6,0, "I've lost my key to Karazhan.",                               30321,1,1,0,0,0,0,'',0),
(@MENU_ID, 7,0, "I've lost my key to the Violet Hold.",                        35500,1,1,0,0,0,0,'',0),
(@MENU_ID, 8,0, "I've lost my Essence-Infused Moonstone. Can you replace it?", 20969,1,1,0,0,0,0,'',0);

-- Walter Soref is missing his npcflag for gossip (the other 2 locksmiths are OK)
UPDATE `creature` SET `npcflag`=(`npcflag`|1) WHERE `id` = @Walter;

UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName`= ''  WHERE `entry` IN (@Pazik,@Benik,@Walter);

DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` IN (@Pazik,@Benik,@Walter);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Pazik, 0,0,9,62,0,100,0,9823,0,0,0,11,54883,0,0,0,0,0,7,0,0,0,0,0,0,0,"Pazik \"The Pick\" Prylock - on Gossip Option 0 selected - cast 'Create Skeleton Key'"),
(@Pazik, 0,1,9,62,0,100,0,9823,1,0,0,11,54881,0,0,0,0,0,7,0,0,0,0,0,0,0,"Pazik \"The Pick\" Prylock - on Gossip Option 1 selected - cast 'Create Key to the Arcatraz'"),
(@Pazik, 0,2,9,62,0,100,0,9823,2,0,0,11,54884,0,0,0,0,0,7,0,0,0,0,0,0,0,"Pazik \"The Pick\" Prylock - on Gossip Option 2 selected - cast 'Create Shattered Halls Key'"),
(@Pazik, 0,3,9,62,0,100,0,9823,3,0,0,11,54880,0,0,0,0,0,7,0,0,0,0,0,0,0,"Pazik \"The Pick\" Prylock - on Gossip Option 3 selected - cast 'Create Key to Searing Gorge'"),
(@Pazik, 0,4,9,62,0,100,0,9823,4,0,0,11,54882,0,0,0,0,0,7,0,0,0,0,0,0,0,"Pazik \"The Pick\" Prylock - on Gossip Option 4 selected - cast 'Create Shadowforge Key'"),
(@Pazik, 0,5,9,62,0,100,0,9823,5,0,0,11,54887,0,0,0,0,0,7,0,0,0,0,0,0,0,"Pazik \"The Pick\" Prylock - on Gossip Option 5 selected - cast 'Create They Eye of Haramad'"),
(@Pazik, 0,6,9,62,0,100,0,9823,6,0,0,11,54885,0,0,0,0,0,7,0,0,0,0,0,0,0,"Pazik \"The Pick\" Prylock - on Gossip Option 6 selected - cast 'Create The Master's Key'"),
(@Pazik, 0,7,9,62,0,100,0,9823,7,0,0,11,67253,0,0,0,0,0,7,0,0,0,0,0,0,0,"Pazik \"The Pick\" Prylock - on Gossip Option 7 selected - cast 'Create The Violet Hold Key'"),
(@Pazik, 0,8,9,62,0,100,0,9823,8,0,0,11,40173,0,0,0,0,0,7,0,0,0,0,0,0,0,"Pazik \"The Pick\" Prylock - on Gossip Option 8 selected - cast 'Create Essence-Infused Moonstone'"),
(@Pazik, 0,9,0,61,0,100,0,   0,0,0,0,72,    0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Pazik \"The Pick\" Prylock - on Gossip Option * selected - close Gossip"),
(@Benik, 0,0,9,62,0,100,0,9823,0,0,0,11,54883,0,0,0,0,0,7,0,0,0,0,0,0,0,"Benik Boltshear - on Gossip Option 0 selected - cast 'Create Skeleton Key'"),
(@Benik, 0,1,9,62,0,100,0,9823,1,0,0,11,54881,0,0,0,0,0,7,0,0,0,0,0,0,0,"Benik Boltshear - on Gossip Option 1 selected - cast 'Create Key to the Arcatraz'"),
(@Benik, 0,2,9,62,0,100,0,9823,2,0,0,11,54884,0,0,0,0,0,7,0,0,0,0,0,0,0,"Benik Boltshear - on Gossip Option 2 selected - cast 'Create Shattered Halls Key'"),
(@Benik, 0,3,9,62,0,100,0,9823,3,0,0,11,54880,0,0,0,0,0,7,0,0,0,0,0,0,0,"Benik Boltshear - on Gossip Option 3 selected - cast 'Create Key to Searing Gorge'"),
(@Benik, 0,4,9,62,0,100,0,9823,4,0,0,11,54882,0,0,0,0,0,7,0,0,0,0,0,0,0,"Benik Boltshear - on Gossip Option 4 selected - cast 'Create Shadowforge Key'"),
(@Benik, 0,5,9,62,0,100,0,9823,5,0,0,11,54887,0,0,0,0,0,7,0,0,0,0,0,0,0,"Benik Boltshear - on Gossip Option 5 selected - cast 'Create They Eye of Haramad'"),
(@Benik, 0,6,9,62,0,100,0,9823,6,0,0,11,54885,0,0,0,0,0,7,0,0,0,0,0,0,0,"Benik Boltshear - on Gossip Option 6 selected - cast 'Create The Master's Key'"),
(@Benik, 0,7,9,62,0,100,0,9823,7,0,0,11,67253,0,0,0,0,0,7,0,0,0,0,0,0,0,"Benik Boltshear - on Gossip Option 7 selected - cast 'Create The Violet Hold Key'"),
(@Benik, 0,8,9,62,0,100,0,9823,8,0,0,11,40173,0,0,0,0,0,7,0,0,0,0,0,0,0,"Benik Boltshear - on Gossip Option 8 selected - cast 'Create Essence-Infused Moonstone'"),
(@Benik, 0,9,0,61,0,100,0,   0,0,0,0,72,    0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Benik Boltshear - on Gossip Option * selected - close Gossip"),
(@Walter,0,0,9,62,0,100,0,9823,0,0,0,11,54883,0,0,0,0,0,7,0,0,0,0,0,0,0,"Walter Soref - on Gossip Option 0 selected - cast 'Create Skeleton Key'"),
(@Walter,0,1,9,62,0,100,0,9823,1,0,0,11,54881,0,0,0,0,0,7,0,0,0,0,0,0,0,"Walter Soref - on Gossip Option 1 selected - cast 'Create Key to the Arcatraz'"),
(@Walter,0,2,9,62,0,100,0,9823,2,0,0,11,54884,0,0,0,0,0,7,0,0,0,0,0,0,0,"Walter Soref - on Gossip Option 2 selected - cast 'Create Shattered Halls Key'"),
(@Walter,0,3,9,62,0,100,0,9823,3,0,0,11,54880,0,0,0,0,0,7,0,0,0,0,0,0,0,"Walter Soref - on Gossip Option 3 selected - cast 'Create Key to Searing Gorge'"),
(@Walter,0,4,9,62,0,100,0,9823,4,0,0,11,54882,0,0,0,0,0,7,0,0,0,0,0,0,0,"Walter Soref - on Gossip Option 4 selected - cast 'Create Shadowforge Key'"),
(@Walter,0,5,9,62,0,100,0,9823,5,0,0,11,54887,0,0,0,0,0,7,0,0,0,0,0,0,0,"Walter Soref - on Gossip Option 5 selected - cast 'Create They Eye of Haramad'"),
(@Walter,0,6,9,62,0,100,0,9823,6,0,0,11,54885,0,0,0,0,0,7,0,0,0,0,0,0,0,"Walter Soref - on Gossip Option 6 selected - cast 'Create The Master's Key'"),
(@Walter,0,7,9,62,0,100,0,9823,7,0,0,11,67253,0,0,0,0,0,7,0,0,0,0,0,0,0,"Walter Soref - on Gossip Option 7 selected - cast 'Create The Violet Hold Key'"),
(@Walter,0,8,9,62,0,100,0,9823,8,0,0,11,40173,0,0,0,0,0,7,0,0,0,0,0,0,0,"Walter Soref - on Gossip Option 8 selected - cast 'Create Essence-Infused Moonstone'"),
(@Walter,0,9,0,61,0,100,0,   0,0,0,0,72,    0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Walter Soref - on Gossip Option * selected - close Gossip");

-- conditions for gossip_menu_option.menu_id 9823:
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 15 AND `SourceGroup`= @MENU_ID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@MENU_ID,0,0, 0, 8,0, 5505,0,0, 0,0,0,'',"Show gossip option 9823 id 0 if quest 5505 is rewarded AND player does NOT have item 13704."),
(15,@MENU_ID,0,0, 0, 2,0,13704,1,0, 1,0,0,'',"Show gossip option 9823 id 0 if player does NOT have item 13704 AND quest 5505 is rewarded."),
(15,@MENU_ID,0,0, 1, 8,0, 5511,0,0, 0,0,0,'',"Show gossip option 9823 id 0 if quest 5511 is rewarded AND player does NOT have item 13704."),
(15,@MENU_ID,0,0, 1, 2,0,13704,1,0, 1,0,0,'',"Show gossip option 9823 id 0 if player does NOT have item 13704 AND quest 5511 is rewarded."),
(15,@MENU_ID,1,0, 0, 8,0,10704,0,0, 0,0,0,'',"Show gossip option 9823 id 1 if quest 10704 is rewarded AND player does NOT have item 31084."),
(15,@MENU_ID,1,0, 0, 2,0,31084,1,0, 1,0,0,'',"Show gossip option 9823 id 1 if player does NOT have item 31084 AND quest 10704 is rewarded."),
(15,@MENU_ID,2,0, 0, 8,0,10758,0,0, 0,0,0,'',"Show gossip option 9823 id 2 if quest 10758 is rewarded AND player does NOT have item 28395."),
(15,@MENU_ID,2,0, 0, 2,0,28395,1,0, 1,0,0,'',"Show gossip option 9823 id 2 if player does NOT have item 28395 AND quest 10758 is rewarded."),
(15,@MENU_ID,2,0, 1, 8,0,10764,0,0, 0,0,0,'',"Show gossip option 9823 id 2 if quest 10764 is rewarded AND player does NOT have item 28395."),
(15,@MENU_ID,2,0, 1, 2,0,28395,1,0, 1,0,0,'',"Show gossip option 9823 id 2 if player does NOT have item 28395 AND quest 10764 is rewarded."),
(15,@MENU_ID,3,0, 0, 8,0, 3201,0,0, 0,0,0,'',"Show gossip option 9823 id 3 if quest 3201 is rewarded AND player does NOT have item 5396."),
(15,@MENU_ID,3,0, 0, 2,0, 5396,1,0, 1,0,0,'',"Show gossip option 9823 id 3 if player does NOT have item 5396 AND quest 3201 is rewarded."),
(15,@MENU_ID,4,0, 0, 8,0, 3802,0,0, 0,0,0,'',"Show gossip option 9823 id 4 if quest 3802 is rewarded AND player does NOT have item 11000."),
(15,@MENU_ID,4,0, 0, 2,0,11000,1,0, 1,0,0,'',"Show gossip option 9823 id 4 if player does NOT have item 11000 AND quest 3802 is rewarded."),
(15,@MENU_ID,5,0, 0, 8,0,10982,0,0, 0,0,0,'',"Show gossip option 9823 id 5 if quest 10982 is rewarded AND player does NOT have item 32092."),
(15,@MENU_ID,5,0, 0, 2,0,32092,1,0, 1,0,0,'',"Show gossip option 9823 id 5 if player does NOT have item 32092 AND quest 10982 is rewarded."),
(15,@MENU_ID,6,0, 0, 8,0, 9837,0,0, 0,0,0,'',"Show gossip option 9823 id 6 if quest 9837 is rewarded AND player does NOT have item 24490."),
(15,@MENU_ID,6,0, 0, 2,0,24490,1,0, 1,0,0,'',"Show gossip option 9823 id 6 if player does NOT have item 24490 AND quest 9837 is rewarded."),
(15,@MENU_ID,7,0, 0, 8,0,13159,0,0, 0,0,0,'',"Show gossip option 9823 id 7 if quest 13159 is rewarded AND player does NOT have item 42482."),
(15,@MENU_ID,7,0, 0, 2,0,42482,1,0, 1,0,0,'',"Show gossip option 9823 id 7 if player does NOT have item 42482 AND quest 13159 is rewarded."),
(15,@MENU_ID,8,0, 0, 8,0,11011,0,0, 0,0,0,'',"Show gossip option 9823 id 8 if quest 11011 is rewarded AND player does NOT have item 32449."),
(15,@MENU_ID,8,0, 0, 2,0,32449,1,0, 1,0,0,'',"Show gossip option 9823 id 8 if player does NOT have item 32449 AND quest 11011 is rewarded.");
