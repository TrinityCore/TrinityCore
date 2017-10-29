/*
-- 
UPDATE `creature_template` SET `npcflag`=2, `gossip_menu_id`=0 WHERE `entry`=240;
DELETE FROM `gossip_menu` WHERE `MenuID`=11611;
DELETE FROM `npc_text` WHERE `ID`=16211;

DELETE FROM `quest_greeting` WHERE `ID`=240;
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES
(240, 0, 0, 0, "Ach, it's hard enough keeping order around here without all these new troubles popping up!  I hope you have good news, $n...", 0);
*/
