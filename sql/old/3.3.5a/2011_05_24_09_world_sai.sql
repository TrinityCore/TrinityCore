-- Quest 12321 "A Righteous Sermon"
-- SAI for Inquisitor Hallard 
SET @ENTRY := 27316;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY; 
UPDATE `creature` SET `position_x`=3797.918,`position_y`=-677.4138,`position_z`=213.7526 WHERE id=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY; 
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (@ENTRY*100); 
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
-- AI
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,@ENTRY,1,0,0,0,1,0,0,0,0,0,0,0, 'Inquisitor Hallard - on reset - load path 0'),
(@ENTRY,0,1,0,19,0,100,0,12321,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Inquisitor Hallard - on quest accept 12321 - run script'),
-- Script
(@ENTRY*100,9,0,0,0,0,100,0,1000,1000,0,0,54,180000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Inquisitor Hallard - script - pause path'),
(@ENTRY*100,9,1,0,0,0,100,0,100,100,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Inquisitor Hallard - script - Turn off Questgiver flag'),
(@ENTRY*100,9,2,0,0,0,100,0,100,100,0,0,69,0,0,0,0,0,0,1,0,0,0,3801.585,-678.4510,213.7526,0, 'Inquisitor Hallard - Script - Move to'),
(@ENTRY*100,9,3,0,0,0,100,0,1500,1500,0,0,69,0,0,0,0,0,0,1,0,0,0,3800.602,-680.9520,213.5028,0, 'Inquisitor Hallard - Script - Move to'),
(@ENTRY*100,9,4,0,0,0,100,0,4000,4000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Inquisitor Hallard - script - Say text 0'),
(@ENTRY*100,9,5,0,0,0,100,0,6000,6000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Inquisitor Hallard - script - Say text 1'),
(@ENTRY*100,9,6,0,0,0,100,0,8000,8000,0,0,1,0,0,0,0,0,0,9,27577,0,30,0,0,0,0, 'Inquisitor Hallard - script - Mayor Godfrey Say text 0'),
(@ENTRY*100,9,7,0,0,0,100,0,3000,3000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Inquisitor Hallard - script - Say text 2'),
(@ENTRY*100,9,8,0,0,0,100,0,7000,7000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Inquisitor Hallard - script - Say text 3'),
(@ENTRY*100,9,9,0,0,0,100,0,3000,3000,0,0,1,1,0,0,0,0,0,9,27577,0,30,0,0,0,0, 'Inquisitor Hallard - script - Mayor Godfrey Say text 1'),
(@ENTRY*100,9,10,0,0,0,100,0,4000,4000,0,0,1,2,0,0,0,0,0,9,27577,0,30,0,0,0,0, 'Inquisitor Hallard - script - Mayor Godfrey Say text 2'),
(@ENTRY*100,9,11,0,0,0,100,0,4000,4000,0,0,1,3,0,0,0,0,0,9,27577,0,30,0,0,0,0, 'Inquisitor Hallard - script - Mayor Godfrey Say text 3'),
(@ENTRY*100,9,12,0,0,0,100,0,7000,7000,0,0,1,4,0,0,0,0,0,9,27577,0,30,0,0,0,0, 'Inquisitor Hallard - script - Mayor Godfrey Say text 4'),
(@ENTRY*100,9,13,0,0,0,100,0,7000,7000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Inquisitor Hallard - script - Say text 4'),
(@ENTRY*100,9,14,0,0,0,100,0,5000,5000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Inquisitor Hallard - script - Say text 5'),
(@ENTRY*100,9,15,0,0,0,100,0,5000,5000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Inquisitor Hallard - script - Say text 6'),
(@ENTRY*100,9,16,0,0,0,100,0,5000,5000,0,0,11,49061,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Inquisitor Hallard - script - cast spell 49061'),
(@ENTRY*100,9,17,0,0,0,100,0,4000,4000,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Inquisitor Hallard - script - Say text 7'),
(@ENTRY*100,9,18,0,0,0,100,0,5000,5000,0,0,1,5,0,0,0,0,0,9,27577,0,30,0,0,0,0, 'Inquisitor Hallard - script - Mayor Godfrey Say text 5'),
(@ENTRY*100,9,19,0,0,0,100,0,3500,3500,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Inquisitor Hallard - script - Say text 8'),
(@ENTRY*100,9,20,0,0,0,100,0,3500,3500,0,0,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Inquisitor Hallard - script - Say text 9'),
(@ENTRY*100,9,21,0,0,0,100,0,500,500,0,0,1,6,0,0,0,0,0,9,27577,0,30,0,0,0,0, 'Inquisitor Hallard - script - Mayor Godfrey Say text 6'),
(@ENTRY*100,9,22,0,0,0,100,0,3000,3000,0,0,1,10,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Inquisitor Hallard - script - Say text 10'),
(@ENTRY*100,9,23,0,0,0,100,0,2000,2000,0,0,1,11,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Inquisitor Hallard - script - Say text 11'),
(@ENTRY*100,9,24,0,0,0,100,0,7000,7000,0,0,1,7,0,0,0,0,0,9,27577,0,30,0,0,0,0, 'Inquisitor Hallard - script - Mayor Godfrey Say text 7'),
(@ENTRY*100,9,25,0,0,0,100,0,7000,7000,0,0,1,12,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Inquisitor Hallard - script - Say text 12'),
(@ENTRY*100,9,26,0,0,0,100,0,12000,12000,0,0,1,8,0,0,0,0,0,9,27577,0,30,0,0,0,0, 'Inquisitor Hallard - script - Mayor Godfrey Say text 8'),
(@ENTRY*100,9,27,0,0,0,100,0,5000,5000,0,0,1,9,0,0,0,0,0,9,27577,0,30,0,0,0,0, 'Inquisitor Hallard - script - Mayor Godfrey Say text 9'),
(@ENTRY*100,9,28,0,0,0,100,0,13000,13000,0,0,1,13,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Inquisitor Hallard - script - Say text 13'),
(@ENTRY*100,9,29,0,0,0,100,0,7000,7000,0,0,1,10,0,0,0,0,0,9,27577,0,30,0,0,0,0, 'Inquisitor Hallard - script - Mayor Godfrey Say text 10'),
(@ENTRY*100,9,30,0,0,0,100,0,9000,9000,0,0,1,11,0,0,0,0,0,9,27577,0,30,0,0,0,0, 'Inquisitor Hallard - script - Mayor Godfrey Say text 11'),
(@ENTRY*100,9,31,0,0,0,100,0,5000,5000,0,0,1,14,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Inquisitor Hallard - script - Say text 14'),
(@ENTRY*100,9,32,0,0,0,100,0,5000,5000,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Inquisitor Hallard - script - turn to player'),
(@ENTRY*100,9,33,0,0,0,100,0,1000,1000,0,0,1,15,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Inquisitor Hallard - script - Say text 15'),
(@ENTRY*100,9,34,0,0,0,100,0,9000,9000,0,0,15,12321,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Inquisitor Hallard - script - give quest credit to player'),
(@ENTRY*100,9,35,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,9,27577,0,30,0,0,0,0, 'Inquisitor Hallard - script - turn to Mayor Godfrey'),
(@ENTRY*100,9,36,0,0,0,100,0,3000,3000,0,0,1,16,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Inquisitor Hallard - script - Say text 16'),
(@ENTRY*100,9,37,0,0,0,100,0,10000,10000,0,0,81,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Inquisitor Hallard - script - Turn on Questgiver flag'),
(@ENTRY*100,9,38,0,0,0,100,0,0,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Inquisitor Hallard - script - reset creature');

-- waypoints for Inquisitor Hallard
DELETE FROM `waypoints` WHERE `entry` IN (@ENTRY); 
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES 
(@ENTRY,1,3804.538,-679.7090,213.7526, 'Inquisitor Hallard'), 
(@ENTRY,2,3802.979,-678.8114,214.2526, 'Inquisitor Hallard'),
(@ENTRY,3,3800.479,-678.0614,214.2526, 'Inquisitor Hallard'),
(@ENTRY,4,3797.918,-677.4138,213.7526, 'Inquisitor Hallard');

-- NPC talk text insert from sniff 
DELETE FROM `creature_text` WHERE `entry` IN (27316,27577); 
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES 
(27316,0,0, 'Stand back, $N, the beast might lash out and harm you.',12,7,100,396,0,0, 'Inquisitor Hallard'),
(27316,1,0, 'GODFREY! Hear me, fiend! Hear me, for I am the Light, here to deliver you from evil!',12,7,100,5,0,0, 'Inquisitor Hallard'),
(27577,0,0, '%s growls.',16,0,100,0,0,409, 'Mayor Godfrey'),
(27316,2,0, 'Good. I have your attention, then, Godfrey?',12,7,100,396,0,0, 'Inquisitor Hallard'),
(27316,3,0, 'We can do this in one of two ways, Godfrey. First, I will simply ask you to tell me what the unholy markings etched upon the pages of this tome mean. What say you?',12,7,100,1,0,0, 'Inquisitor Hallard'),
(27577,1,0, '%s hisses!',16,0,100,0,0,410, 'Mayor Godfrey'),
(27577,2,0, 'Tell you nothing, preacher.',12,0,100,1,0,0, 'Mayor Godfrey'),
(27577,3,0, 'What can you do to me that Kel''Thuzad has not? That the Lich King will not?',12,0,100,1,0,0, 'Mayor Godfrey'),
(27577,4,0, 'The book is your salvation, yes... but nothing will you know! NOTHING I SAY! NOTHING! ',12,0,100,1,0,0, 'Mayor Godfrey'),
(27316,4,0, 'Then it is option two.',12,7,100,1,0,0, 'Inquisitor Hallard'),
(27316,5,0, 'I say a prayer for you now, lost soul. May the Light take you gracefully.',12,7,100,68,4000,0, 'Inquisitor Hallard'),
(27316,6,0, 'Let the sermon begin.',12,7,100,1,0,0, 'Inquisitor Hallard'),
(27316,7,0, 'LIGHT TAKE YOU, BEAST!',12,7,100,0,0,0, 'Inquisitor Hallard'),
(27577,5,0, 'No more LIGHT! NO MORE! I BEG YOU!',12,0,100,0,0,0, 'Mayor Godfrey'),
(27316,8,0, 'BURN IN HOLY FIRE!',12,7,100,0,0,0, 'Inquisitor Hallard'),
(27316,9,0, 'LET THE LIGHT IN, GODFREY GOODARD!',12,7,100,0,0,0, 'Inquisitor Hallard'),
(27577,6,0, 'Never felt hurt like this!',12,0,100,0,0,0, 'Mayor Godfrey'),
(27316,10,0, 'May the power of Light compel you!',12,7,100,0,0,0, 'Inquisitor Hallard'),
(27316,11,0, 'I thought you would see the Light, Godfrey... Now speak quickly, fiend. What does it say?',12,7,100,396,0,0, 'Inquisitor Hallard'),
(27577,7,0, 'It tells of the coming apocalypse. How this world will burn and be reborn from death.',12,0,100,1,0,0, 'Mayor Godfrey'),
(27316,12,0, 'RUBBISH! Godfrey do you take me for a fool? Do not spew your Scourge propaganda at a man of the Light, heathen! Speak now or I will have the peasants craft a holy water bath and dip you into it like a dog with fleas!',12,7,100,6,0,0, 'Inquisitor Hallard'),
(27577,8,0, 'NOOOO!!! I tell you! I tell you everything!',12,0,100,39,0,0, 'Mayor Godfrey'),
(27577,9,0, 'Humans... Beneath the earth of Wintergarde Village you built a mausoleum! Why do you think Naxxramas attacked that spot? Thel''zan hides deep in your own crypt and sends a thousand-thousand corpses at you! Perish you will...',12,0,100,1,0,0, 'Mayor Godfrey'),
(27316,13,0, 'What? There is a mausoleum beneath the old village? What fools we are to not have noticed! We will find and strike down your master now, Godfrey. We will end this nightmare.',12,7,100,6,0,0, 'Inquisitor Hallard'),
(27577,10,0, 'How? Humans truly are stupid, yes? Thel''zan the Duskbringer! Thel''zan the Lich! He who is born of human flesh and bone, sacrificed all for power, protected by the Lich King!',12,0,100,1,0,0, 'Mayor Godfrey'),
(27577,11,0, 'You cannot stop Thel''zan! He bears the dark gift, bestowed upon him by the Lich King himself!',12,0,100,1,0,0, 'Mayor Godfrey'),
(27316,14,0, 'You let us worry about how we kill the monster, Godfrey.',12,7,100,396,0,0, 'Inquisitor Hallard'),
(27316,15,0, 'Return to Halford with the information that the good mayor was kind enough to submit, $N. I will finish here and squeeze whatever else this wretch might know about Thel''zan. Now, I will show Godfrey the rarely seen "option three."',12,7,100,1,0,0, 'Inquisitor Hallard'),
(27316,16,0, 'Let''s you and I have a chat about some things, Godfrey.',12,7,100,1,0,0, 'Inquisitor Hallard');

-- Add spell conditions for 49062
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=49062;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,49062,0,18,1,27577,0,0,'','Spell 49062 target creature 27577');
