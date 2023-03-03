-- Delete data from npc_trainer (not using it anymore)
DELETE FROM `npc_trainer` WHERE (`ID` = 156669);

DELETE FROM `creature_trainer` WHERE `CreatureId` = '156669';
INSERT INTO `creature_trainer`(`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES (156669, 1045, 10185, 0);

-- Define trainer
DELETE FROM `trainer` WHERE `Id` = '1045';
INSERT INTO `trainer`(`Id`, `Type`, `Greeting`, `VerifiedBuild`) VALUES (1045, 2, 'Welcome!', 35662);


-- Delete data from npc_trainer (not using it anymore)
DELETE FROM `npc_trainer` WHERE (`ID` = 156669);

UPDATE creature_template SET npcflag=19 WHERE entry = 156669 ;
UPDATE creature_template SET gossip_menu_id =10185 WHERE entry = 156669 ;
UPDATE creature_template SET faction =35 WHERE entry = 156669 ;
UPDATE creature_template SET unit_flags =33024 WHERE entry = 156669 ;
UPDATE creature_template SET unit_flags2 =2048 WHERE entry = 156669 ;
