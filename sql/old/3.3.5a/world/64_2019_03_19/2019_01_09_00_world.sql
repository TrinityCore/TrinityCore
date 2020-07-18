-- 
UPDATE `creature_template` SET `npcflag`=`npcflag`|1 WHERE `entry` IN (4794,5190,5191,6626,7937,9598,14368,16610,23139,23376,25841,26666,28284,29319,29327,30007,30631,33956,33957);
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry` IN (2080,2501);

DELETE FROM `gossip_menu` WHERE `MenuID` IN (2080,2502);
DELETE FROM `npc_text` WHERE `id` IN (2080,2505);

DELETE FROM `quest_greeting` WHERE `Id` IN (2501);
INSERT INTO `quest_greeting` (`Id`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES
(2501, 0, 0, 0, 'Oy!  You here for a game of knuckles?', 0);

UPDATE `smart_scripts` SET `action_param1`=3 WHERE `entryorguid`=3395700 AND `source_type`=9 AND `id`=13;
