-- Updates for Quest A Blade Fit For A Champion

UPDATE `creature_template` SET `ScriptName`= 'npc_lake_frog' WHERE `entry` IN (33211,33224);
UPDATE `creature_template` SET `npcflag`=1 WHERE `entry` IN (33224);

-- Add option conditions for gossip
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (15) AND `SourceGroup` IN (10316);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,10316,0,0,2,44981,1,1,1,0,'','Maiden of Ashwood Lake - Show gossip option if player does not have Ashwood Brand');

-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry`=33220;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(33220,0,0, 'Can it really be? Free after all these years?',12,0,100,1,0,0, 'Maiden of Ashwood Lake'),
(33220,1,0, 'And now, I must return to the waters of the lake.',12,0,100,2,0,0, 'Maiden of Ashwood Lake');
