-- Chief Hawkwind
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=2 WHERE `entry`=2981;

DELETE FROM `quest_greeting` WHERE `ID`=2981;
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES
(2981,0,0,0,"Hail, $c. In my years I have seen many eager tauren who wish to prove their worth to the tribe. It should not be forgotten that eagerness is no substitute for wisdom and experience.",0);
