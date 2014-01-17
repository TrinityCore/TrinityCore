-- Add Missing Gossip Menu Gurgthock
UPDATE `creature_template` SET `gossip_menu_id`=9863 WHERE `entry`=30007;
-- Add Missing Gossip Menu items for Gurgthock
DELETE FROM `gossip_menu` WHERE `entry`=9863 AND `text_id`=13679; -- Before Quest 12948
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9863,13679);
DELETE FROM `gossip_menu` WHERE `entry`=9863 AND `text_id`=13680; -- After Quest 12948
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9863,13680);
-- Add Gossip Menu conditions for Gurgthock
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14) AND `SourceGroup` IN (9863);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,9863,13679,0,8,12948,0,0,1,0,'','Gurgthock - Show gossip text only if player does not have Quest 12948 rewarded'),
(14,9863,13680,0,8,12948,0,0,0,0,'','Gurgthock - Show gossip text only if player does have Quest 12948 rewarded');
-- Add some miss texts for Gurgthock
DELETE FROM `creature_text` WHERE `entry`=30007 AND `groupid` IN (7,8,9);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(30007,7,0,'The grand Amphitheater of Anguish awaits, $N. Remember, once a battle starts you have to stay in the area. WIN OR DIE!',12,0,100,1,0,0,'Gurgthock'),
(30007,8,0,'Here we are once again, ladies and gentlemen. The epic struggle between life and death in the Amphitheater of Anguish! For this round we have $N versus the hulking jormungar, Yg... Yggd? Yggdoze? Who comes up with these names?! $N versus big worm!',14,0,100,0,0,13363,'Gurgthock SAY_QUEST_AMPHITHEATER_ANGUISH_YGGDRAS'),
(30007,9,0,'Prepare to make you stand, $N! Get in the Amphitheater and stand ready! Remember, you and your opponent must stay in the arena at all times or you will be disqualified!',12,0,100,1,0,0,'Gurgthock');
