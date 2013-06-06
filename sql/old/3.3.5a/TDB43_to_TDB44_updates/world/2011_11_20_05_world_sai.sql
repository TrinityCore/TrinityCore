-- [Q] Jack Likes His Drink
-- We are making Jack dance through SAI instead of creature(_template)_addon so we can cancel it in the actual SAI

-- Olga, the Scalawag Wench SAI
SET @ENTRY_OLGA := 24639;
SET @ENTRY_JACK := 24788;
SET @GOSSIP := 9015;
SET @QUEST := 11466;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@ENTRY_OLGA,@ENTRY_JACK);
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP+10 WHERE `entry`=@ENTRY_JACK;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY_OLGA,@ENTRY_OLGA*100,@ENTRY_OLGA*100+1,@ENTRY_OLGA*100+2,@ENTRY_JACK,@ENTRY_JACK*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY_OLGA,0,0,0,62,0,100,0,@GOSSIP+1,0,0,0,80,@ENTRY_OLGA*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Olga, the Scalawag Wench - On Gossip Select - Run Script"),
(@ENTRY_OLGA*100,9,0,0,0,0,100,0,0,0,0,0,53,0,@ENTRY_OLGA,0,0,0,0,1,0,0,0,0,0,0,0,"Olga, the Scalawag Wench - On Script - Start WP"),
(@ENTRY_OLGA*100,9,1,0,0,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Olga, the Scalawag Wench - On Script - Close Gossip"),
(@ENTRY_OLGA*100,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Olga, the Scalawag Wench - On Script - Whisper Line 0"),
(@ENTRY_OLGA*100,9,3,0,0,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Olga, the Scalawag Wench - On Script - Remove Gossip Flag"),

(@ENTRY_OLGA,0,1,0,40,0,100,0,2,@ENTRY_OLGA,0,0,80,@ENTRY_OLGA*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Olga, the Scalawag Wench - On WP 2 - Run Script 2"),
(@ENTRY_OLGA*100+1,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,11,@ENTRY_JACK,15,0,0,0,0,0,"Olga, the Scalawag Wench - On Script 2 - Face Jack Adams"),
(@ENTRY_OLGA*100+1,9,1,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Olga, the Scalawag Wench - On Script 2 - Say Line 1"),
(@ENTRY_OLGA*100+1,9,2,0,0,0,100,0,3000,3000,0,0,45,1,1,0,0,0,0,19,@ENTRY_JACK,0,0,0,0,0,0,"Olga, the Scalawag Wench - On Script 2 - Set Data 1 1 Jack Adams"),
(@ENTRY_OLGA*100+1,9,3,0,0,0,100,0,3000,3000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Olga, the Scalawag Wench - On Script 2 - Say Line 2"),
(@ENTRY_OLGA*100+1,9,4,0,0,0,100,0,4000,4000,0,0,45,2,2,0,0,0,0,19,@ENTRY_JACK,0,0,0,0,0,0,"Olga, the Scalawag Wench - On Script 2 - Set Data 2 2 Jack Adams"),
(@ENTRY_OLGA,0,2,0,38,0,100,0,3,3,0,0,53,0,@ENTRY_OLGA*10,0,0,0,0,1,0,0,0,0,0,0,0,"Olga, the Scalawag Wench - On Data 3 3 Set - Start WP 2"),

(@ENTRY_JACK,0,0,0,1,0,100,1,0,0,0,0,5,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jack Adams - Out of Combat - Start Dancing"),
(@ENTRY_JACK,0,1,2,38,0,100,0,1,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jack Adams - On Data 1 1 Set - Say Line 0"),
(@ENTRY_JACK,0,2,0,61,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jack Adams - On Data 1 1 Set - Set Faction 35"),
(@ENTRY_JACK,0,3,4,62,0,100,0,@GOSSIP+10,0,0,0,56,34116,1,0,0,0,0,7,0,0,0,0,0,0,0,"Jack Adams - On Gossip Select - Give Quest Item"),
(@ENTRY_JACK,0,4,5,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Jack Adams - On Gossip Select - Close Gossip"),
(@ENTRY_JACK,0,5,6,61,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jack Adams - On Gossip Select - Remove Gossip Flag"), -- To prevent getting more than one item per event
(@ENTRY_JACK,0,6,0,61,0,100,0,0,0,0,0,45,3,3,0,0,0,0,19,@ENTRY_OLGA,0,0,0,0,0,0,"Jack Adams - On Gossip Select - Set Data Olga, the Scalawag Wench"),

(@ENTRY_JACK,0,7,0,38,0,100,0,2,2,0,0,80,@ENTRY_JACK*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jack Adams - On Data 2 2 Set - Run Script"),
(@ENTRY_JACK*100,9,0,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jack Adams - On Script - Say Line 1"),
(@ENTRY_JACK*100,9,1,0,0,0,100,0,0,0,0,0,5,26,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jack Adams - On Script - Stop Dancing"),
(@ENTRY_JACK*100,9,2,0,0,0,100,0,2000,2000,0,0,5,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jack Adams - On Script - EMOTE_ONESHOT_KNEEL"),
(@ENTRY_JACK*100,9,3,0,0,0,100,0,4000,4000,0,0,5,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jack Adams - On Script - EMOTE_ONESHOT_EAT"),
(@ENTRY_JACK*100,9,4,0,0,0,100,0,4000,4000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jack Adams - On Script - Say Line 2"),
(@ENTRY_JACK*100,9,5,0,0,0,100,0,4000,4000,0,0,11,43391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jack Adams - On Script - Cast Vomit"),
(@ENTRY_JACK*100,9,6,0,0,0,100,0,3000,3000,0,0,11,29266,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jack Adams - On Script - Cast Permanent Feign Death"),
(@ENTRY_JACK*100,9,7,0,0,0,100,0,0,0,0,0,81,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jack Adams - On Script - Add Gossip Flag"),
(@ENTRY_JACK*100,9,8,0,0,0,100,0,0,0,0,0,41,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jack Adams - On Script - Forced Despawn");

-- Texts
DELETE FROM `creature_text` WHERE `entry` IN (@ENTRY_OLGA,@ENTRY_JACK);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY_OLGA,0,0,"Keep quiet, will you? If anyone catches on, we're both dead.",15,0,100,0,0,0,"Olga, the Scalawag Wench"),
(@ENTRY_OLGA,1,0,"All right, fellas! Who ordered the spiced rum? Was it you, Jackie boy?",12,0,100,0,0,0,"Olga, the Scalawag Wench"),
(@ENTRY_OLGA,2,0,"It's okay, sweetheart. This one's on the house.",12,0,100,0,0,0,"Olga, the Scalawag Wench"),

(@ENTRY_JACK,0,0,"Sure thing, love. Put it on Harry's tab, will ya? He owes me a drink!",12,0,100,0,0,0,"Jack Adams"),
(@ENTRY_JACK,1,0,"Free rum? Why... that's me favorite kind!",12,0,100,0,0,0,"Jack Adams"),
(@ENTRY_JACK,2,0,"Sweet Neptulon! That was... one drink... too many!",12,0,100,0,0,0,"Jack Adams");

-- Insert option menu
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (@GOSSIP,@GOSSIP+1,@GOSSIP+10);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`box_money`,`box_text`) VALUES
(@GOSSIP+0,0,0,"I'd like to buy Jack a drink. Perhaps something... extra strong.",1,1,@GOSSIP+1,0,''),
(@GOSSIP+1,0,0,"Here's a gold, buy yourself something nice.",1,1,0,10000,'Do you really want to bribe Olga?'),
(@GOSSIP+10,0,0,"<Discreetly search the pirate's pockets for Taruk's payment.>",1,1,0,0,'');

-- Waypoints for Olga, the Scalawag Wench
DELETE FROM `waypoints` WHERE `entry` IN (@ENTRY_OLGA,@ENTRY_OLGA*10);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY_OLGA,1,-89.466621,-3539.939941,7.715524,'Olga, the Scalawag Wench'),
(@ENTRY_OLGA,2,-86.451447,-3544.374268,7.716601,'Olga, the Scalawag Wench'),

(@ENTRY_OLGA*10,1,-86.451447,-3544.374268,7.716601,'Olga, the Scalawag Wench'),
(@ENTRY_OLGA*10,2,-89.466621,-3539.939941,7.715524,'Olga, the Scalawag Wench');

-- Only show first gossip if player is on quest Gambling Debt
DELETE FROM `conditions` WHERE `SourceGroup` IN (@GOSSIP+0,@GOSSIP+10) AND `ConditionValue1` IN (@QUEST);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP+0,0,0,9,@QUEST,0,0,0,'',"Only show first gossip if player is on quest Gambling Debt"),

(15,@GOSSIP+10,0,0,9,@QUEST,0,0,0,'',"Only show first gossip if player is on quest Gambling Debt");
