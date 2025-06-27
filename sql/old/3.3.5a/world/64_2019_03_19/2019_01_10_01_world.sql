-- 
DELETE FROM `npc_text` WHERE `ID` IN (773,737,733,2498);
DELETE FROM `gossip_menu` WHERE `MenuID` IN (773,737,733,2498);

UPDATE `creature_template` SET `npcflag` = `npcflag`&~1 WHERE `entry` = 733;

DELETE FROM `quest_greeting` WHERE `Id` = 733;
INSERT INTO `quest_greeting` (`Id`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES
(733, 0, 0, 0, 'You watch where you step around here, $Glad:lass;.  You might not be a part of our outfit, but that doesn\'t mean I won\'t take a cane to you if you fall out of line!', 0);
