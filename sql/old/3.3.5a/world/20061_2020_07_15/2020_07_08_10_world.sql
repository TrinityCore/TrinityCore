-- Source: https://www.wowhead.com/item=17909/frostwolf-insignia-rank-6#comments:id=6412:reply=45710
-- Still valid https://www.wowhead.com/item=17904/stormpike-insignia-rank-6#comments:id=200026:reply=664433
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (5441,5442);
INSERT INTO `gossip_menu_option` (`MenuID`,`OptionID`,`OptionIcon`,`OptionText`,`OptionBroadcastTextID`,`OptionType`,`OptionNpcFlag`,`ActionMenuID`,`ActionPoiID`,`BoxCoded`,`BoxMoney`,`BoxText`,`BoxBroadcastTextID`,`VerifiedBuild`) VALUES
(5441,0,0,"Warmaster, I have lost my insignia. Could you supply me with a replacement?",9001,1,1,0,0,0,0,"",0,0),
(5441,1,0,"Warmaster, I have lost my insignia. Could you supply me with a replacement?",9001,1,1,0,0,0,0,"",0,0),
(5441,2,0,"Warmaster, I have lost my insignia. Could you supply me with a replacement?",9001,1,1,0,0,0,0,"",0,0),
(5441,3,0,"Warmaster, I have lost my insignia. Could you supply me with a replacement?",9001,1,1,0,0,0,0,"",0,0),
(5441,4,0,"Warmaster, I have lost my insignia. Could you supply me with a replacement?",9001,1,1,0,0,0,0,"",0,0),
(5441,5,0,"Warmaster, I have lost my insignia. Could you supply me with a replacement?",9001,1,1,0,0,0,0,"",0,0),

(5442,0,0,"Lieutenant, I have lost my insignia. Could you please supply me with a replacement?",9003,1,1,0,0,0,0,"",0,0), 
(5442,1,0,"Lieutenant, I have lost my insignia. Could you please supply me with a replacement?",9003,1,1,0,0,0,0,"",0,0), 
(5442,2,0,"Lieutenant, I have lost my insignia. Could you please supply me with a replacement?",9003,1,1,0,0,0,0,"",0,0), 
(5442,3,0,"Lieutenant, I have lost my insignia. Could you please supply me with a replacement?",9003,1,1,0,0,0,0,"",0,0), 
(5442,4,0,"Lieutenant, I have lost my insignia. Could you please supply me with a replacement?",9003,1,1,0,0,0,0,"",0,0), 
(5442,5,0,"Lieutenant, I have lost my insignia. Could you please supply me with a replacement?",9003,1,1,0,0,0,0,"",0,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` IN (5441,5442);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,5441,0,0,0,8,0,7161,0,0,0,0,0,"","Group 0: Show Gossip Option 0 if quest 'Proving Grounds' is rewarded"),
(15,5441,1,0,0,8,0,7163,0,0,0,0,0,"","Group 0: Show Gossip Option 1 if quest 'Rise and Be Recognized' is rewarded"),
(15,5441,2,0,0,8,0,7164,0,0,0,0,0,"","Group 0: Show Gossip Option 2 if quest 'Honored Amongst the Clan' is rewarded"),
(15,5441,3,0,0,8,0,7165,0,0,0,0,0,"","Group 0: Show Gossip Option 3 if quest 'Earned Reverence' is rewarded"),
(15,5441,4,0,0,8,0,7166,0,0,0,0,0,"","Group 0: Show Gossip Option 4 if quest 'Legendary Heroes' is rewarded"),
(15,5441,5,0,0,8,0,7167,0,0,0,0,0,"","Group 0: Show Gossip Option 5 if quest 'The Eye of Command' is rewarded"),

(15,5441,0,0,0,8,0,7163,0,0,1,0,0,"","Group 0: Show Gossip Option 0 if quest 'Rise and Be Recognized' is not rewarded"),
(15,5441,1,0,0,8,0,7164,0,0,1,0,0,"","Group 0: Show Gossip Option 1 if quest 'Honored Amongst the Clan' is not rewarded"),
(15,5441,2,0,0,8,0,7165,0,0,1,0,0,"","Group 0: Show Gossip Option 2 if quest 'Earned Reverence' is not rewarded"),
(15,5441,3,0,0,8,0,7166,0,0,1,0,0,"","Group 0: Show Gossip Option 3 if quest 'Legendary Heroes' is not rewarded"),
(15,5441,4,0,0,8,0,7167,0,0,1,0,0,"","Group 0: Show Gossip Option 4 if quest 'The Eye of Command' is not rewarded"),

(15,5441,0,0,0,2,0,17690,1,1,1,0,0,"","Group 0: Show Gossip Option 0 if player does not have item 'Frostwolf Insignia Rank 1'"),
(15,5441,1,0,0,2,0,17905,1,1,1,0,0,"","Group 0: Show Gossip Option 1 if player does not have item 'Frostwolf Insignia Rank 2'"),
(15,5441,2,0,0,2,0,17906,1,1,1,0,0,"","Group 0: Show Gossip Option 2 if player does not have item 'Frostwolf Insignia Rank 3'"),
(15,5441,3,0,0,2,0,17907,1,1,1,0,0,"","Group 0: Show Gossip Option 3 if player does not have item 'Frostwolf Insignia Rank 4'"),
(15,5441,4,0,0,2,0,17908,1,1,1,0,0,"","Group 0: Show Gossip Option 4 if player does not have item 'Frostwolf Insignia Rank 5'"),
(15,5441,5,0,0,2,0,17909,1,1,1,0,0,"","Group 0: Show Gossip Option 5 if player does not have item 'Frostwolf Insignia Rank 6'"),

(15,5442,0,0,0,8,0,7162,0,0,0,0,0,"","Group 0: Show Gossip Option 0 if quest 'Proving Grounds' is rewarded"),
(15,5442,1,0,0,8,0,7168,0,0,0,0,0,"","Group 0: Show Gossip Option 1 if quest 'Rise and Be Recognized' is rewarded"),
(15,5442,2,0,0,8,0,7169,0,0,0,0,0,"","Group 0: Show Gossip Option 2 if quest 'Honored Amongst the Guard' is rewarded"),
(15,5442,3,0,0,8,0,7170,0,0,0,0,0,"","Group 0: Show Gossip Option 3 if quest 'Earned Reverence' is rewarded"),
(15,5442,4,0,0,8,0,7171,0,0,0,0,0,"","Group 0: Show Gossip Option 4 if quest 'Legendary Heroes' is rewarded"),
(15,5442,5,0,0,8,0,7172,0,0,0,0,0,"","Group 0: Show Gossip Option 5 if quest 'The Eye of Command' is rewarded"),

(15,5442,0,0,0,8,0,7168,0,0,1,0,0,"","Group 0: Show Gossip Option 0 if quest 'Rise and Be Recognized' is not rewarded"),
(15,5442,1,0,0,8,0,7169,0,0,1,0,0,"","Group 0: Show Gossip Option 1 if quest 'Honored Amongst the Guard' is not rewarded"),
(15,5442,2,0,0,8,0,7170,0,0,1,0,0,"","Group 0: Show Gossip Option 2 if quest 'Earned Reverence' is not rewarded"),
(15,5442,3,0,0,8,0,7171,0,0,1,0,0,"","Group 0: Show Gossip Option 3 if quest 'Legendary Heroes' is not rewarded"),
(15,5442,4,0,0,8,0,7172,0,0,1,0,0,"","Group 0: Show Gossip Option 4 if quest 'The Eye of Command' is not rewarded"),

(15,5442,0,0,0,2,0,17691,1,1,1,0,0,"","Group 0: Show Gossip Option 0 if player does not have item 'Stormpike Insignia Rank 1'"),
(15,5442,1,0,0,2,0,17900,1,1,1,0,0,"","Group 0: Show Gossip Option 1 if player does not have item 'Stormpike Insignia Rank 2'"),
(15,5442,2,0,0,2,0,17901,1,1,1,0,0,"","Group 0: Show Gossip Option 2 if player does not have item 'Stormpike Insignia Rank 3'"),
(15,5442,3,0,0,2,0,17902,1,1,1,0,0,"","Group 0: Show Gossip Option 3 if player does not have item 'Stormpike Insignia Rank 4'"),
(15,5442,4,0,0,2,0,17903,1,1,1,0,0,"","Group 0: Show Gossip Option 4 if player does not have item 'Stormpike Insignia Rank 5'"),
(15,5442,5,0,0,2,0,17904,1,1,1,0,0,"","Group 0: Show Gossip Option 5 if player does not have item 'Stormpike Insignia Rank 6'");

-- Warmaster Laggrond SAI
SET @ID := 13840;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,6200,12100,9800,13400,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warmaster Laggrond - In Combat - Cast 'Cleave'"),
(@ID,0,1,0,0,0,100,0,8400,14600,9800,15100,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warmaster Laggrond - In Combat - Cast 'Mortal Strike'"),
(@ID,0,2,8,62,0,100,0,5441,0,0,0,11,22108,0,0,0,0,0,7,0,0,0,0,0,0,0,"Warmaster Laggrond - On Gossip Option 0 Selected - Cast 'Conjure Frostwolf Rank 1 Insignia'"),
(@ID,0,3,8,62,0,100,0,5441,1,0,0,11,22109,0,0,0,0,0,7,0,0,0,0,0,0,0,"Warmaster Laggrond - On Gossip Option 1 Selected - Cast 'Conjure Frostwolf Rank 2 Insignia'"),
(@ID,0,4,8,62,0,100,0,5441,2,0,0,11,22110,0,0,0,0,0,7,0,0,0,0,0,0,0,"Warmaster Laggrond - On Gossip Option 2 Selected - Cast 'Conjure Frostwolf Rank 3 Insignia'"),
(@ID,0,5,8,62,0,100,0,5441,3,0,0,11,22111,0,0,0,0,0,7,0,0,0,0,0,0,0,"Warmaster Laggrond - On Gossip Option 3 Selected - Cast 'Conjure Frostwolf Rank 4 Insignia'"),
(@ID,0,6,8,62,0,100,0,5441,4,0,0,11,22112,0,0,0,0,0,7,0,0,0,0,0,0,0,"Warmaster Laggrond - On Gossip Option 4 Selected - Cast 'Conjure Frostwolf Rank 5 Insignia'"),
(@ID,0,7,8,62,0,100,0,5441,5,0,0,11,22113,0,0,0,0,0,7,0,0,0,0,0,0,0,"Warmaster Laggrond - On Gossip Option 5 Selected - Cast 'Conjure Frostwolf Rank 6 Insignia'"),
(@ID,0,8,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Warmaster Laggrond - On Link - Close Gossip");

-- Lieutenant Haggerdin SAI
SET @ID := 13841;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,1200,6300,10200,15500,11,12169,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lieutenant Haggerdin - In Combat - Cast 'Shield Block'"),
(@ID,0,1,0,0,0,100,0,5300,9800,13200,18600,11,19130,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lieutenant Haggerdin - In Combat - Cast 'Revenge'"),
(@ID,0,2,8,62,0,100,0,5442,0,0,0,11,22114,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lieutenant Haggerdin - On Gossip Option 0 Selected - Cast 'Conjure Stormpike Rank 1 Insignia'"),
(@ID,0,3,8,62,0,100,0,5442,1,0,0,11,22115,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lieutenant Haggerdin - On Gossip Option 1 Selected - Cast 'Conjure Stormpike Rank 2 Insignia'"),
(@ID,0,4,8,62,0,100,0,5442,2,0,0,11,22116,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lieutenant Haggerdin - On Gossip Option 2 Selected - Cast 'Conjure Stormpike Rank 3 Insignia'"),
(@ID,0,5,8,62,0,100,0,5442,3,0,0,11,22117,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lieutenant Haggerdin - On Gossip Option 3 Selected - Cast 'Conjure Stormpike Rank 4 Insignia'"),
(@ID,0,6,8,62,0,100,0,5442,4,0,0,11,22118,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lieutenant Haggerdin - On Gossip Option 4 Selected - Cast 'Conjure Stormpike Rank 5 Insignia'"),
(@ID,0,7,8,62,0,100,0,5442,5,0,0,11,22119,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lieutenant Haggerdin - On Gossip Option 5 Selected - Cast 'Conjure Stormpike Rank 6 Insignia'"),
(@ID,0,8,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lieutenant Haggerdin - On Link - Close Gossip");
