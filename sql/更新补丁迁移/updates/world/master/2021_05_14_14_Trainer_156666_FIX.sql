-- Delete data from npc_trainer (not using it anymore)
DELETE FROM `npc_trainer` WHERE (`ID` = 156666);

DELETE FROM `creature_trainer` WHERE `CreatureId` = '156666';
INSERT INTO `creature_trainer`(`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES (156666, 1056, 0, 0);

-- Define trainer
DELETE FROM `trainer` WHERE `Id` = '1056';
INSERT INTO `trainer`(`Id`, `Type`, `Greeting`, `VerifiedBuild`) VALUES (1056, 2, 'Welcome!', 35662);


-- Delete data from npc_trainer (not using it anymore)
DELETE FROM `npc_trainer` WHERE (`ID` = 156666);

UPDATE creature_template SET npcflag=80 WHERE entry = 156666 ;
UPDATE creature_template SET gossip_menu_id =0 WHERE entry = 156666 ;
UPDATE creature_template SET faction =35 WHERE entry = 156666 ;


