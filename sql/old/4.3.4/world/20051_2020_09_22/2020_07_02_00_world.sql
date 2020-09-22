DELETE FROM `gossip_menu` WHERE `MenuId` IN (12186, 12185, 12180, 12199, 12193, 12198, 12190, 12197, 12189, 12196, 12188, 12195, 12192, 12191);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(12186, 17127, 15595), -- 47384
(12185, 17126, 15595), -- 47384
(12180, 17125, 15595), -- 47384
(12199, 17138, 15595), -- 47384
(12193, 17133, 15595), -- 47384
(12198, 17137, 15595), -- 47384
(12190, 17130, 15595), -- 47384
(12197, 17136, 15595), -- 47384
(12189, 17129, 15595), -- 47384
(12196, 17135, 15595), -- 47384
(12188, 17128, 15595), -- 47384
(12195, 17134, 15595), -- 47384
(12192, 17132, 15595), -- 47384
(12191, 17131, 15595); -- 47384

DELETE FROM `gossip_menu_option` WHERE `MenuId` IN (12186, 12185, 12180, 12199, 12193, 12198, 12190, 12197, 12189, 12196, 12188, 12195, 12192, 12191);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(12186, 19, 0, 'Tell me about gathering professions.', 0, 15595),
(12186, 18, 0, 'Tell me about Tailoring.', 0, 15595),
(12186, 17, 0, 'Tell me about Leatherworking.', 0, 15595),
(12186, 16, 0, 'Tell me about Jewelcrafting.', 0, 15595),
(12186, 15, 0, 'Tell me about Inscription.', 0, 15595),
(12186, 14, 0, 'Tell me about Engineering.', 0, 15595),
(12186, 13, 0, 'Tell me about Enchanting.', 0, 15595),
(12186, 12, 0, 'Tell me about Blacksmithing.', 0, 15595),
(12186, 11, 0, 'Tell me about Alchemy.', 0, 15595),
(12185, 14, 0, 'Tell me about production professions.', 0, 15595),
(12185, 13, 0, 'Tell me about Skinning.', 0, 15595),
(12185, 12, 0, 'Tell me about Mining.', 0, 15595),
(12185, 11, 0, 'Tell me about Herbalism.', 0, 15595),
(12180, 12, 0, 'Tell me about production professions.', 0, 15595),
(12180, 11, 0, 'Tell me about gathering professions.', 0, 15595),
(12199, 14, 0, 'Tell me about production professions.', 0, 15595),
(12199, 13, 0, 'Tell me about gathering professions.', 0, 15595),
(12199, 12, 0, 'Tell me about Enchanting.', 0, 15595),
(12199, 11, 3, 'Train me in Tailoring.', 0, 15595),
(12193, 14, 0, 'Tell me about production professions.', 0, 15595),
(12193, 13, 0, 'Tell me about gathering professions.', 0, 15595),
(12193, 12, 0, 'Tell me about Tailoring.', 0, 15595),
(12193, 11, 3, 'Train me in Enchanting.', 0, 15595),
(12198, 14, 0, 'Tell me about production professions.', 0, 15595),
(12198, 13, 0, 'Tell me about gathering professions.', 0, 15595),
(12198, 12, 0, 'Tell me about Skinning.', 0, 15595),
(12198, 11, 3, 'Train me in Leatherworking.', 0, 15595),
(12190, 14, 0, 'Tell me about production professions.', 0, 15595),
(12190, 13, 0, 'Tell me about gathering professions.', 0, 15595),
(12190, 12, 0, 'Tell me about Leatherworking.', 0, 15595),
(12190, 11, 3, 'Train me in Skinning.', 0, 15595),
(12197, 14, 0, 'Tell me about production professions.', 0, 15595),
(12197, 13, 0, 'Tell me about gathering professions.', 0, 15595),
(12197, 12, 0, 'Tell me about Mining.', 0, 15595),
(12197, 11, 3, 'Train me in Jewelcrafting.', 0, 15595),
(12189, 16, 0, 'Tell me about production professions.', 0, 15595),
(12189, 15, 0, 'Tell me about gathering professions.', 0, 15595),
(12189, 14, 0, 'Tell me about Jewelcrafting.', 0, 15595),
(12189, 13, 0, 'Tell me about Engineering.', 0, 15595),
(12189, 12, 0, 'Tell me about Blacksmithing.', 0, 15595),
(12189, 11, 3, 'Train me in Mining.', 0, 15595),
(12196, 14, 0, 'Tell me about production professions.', 0, 15595),
(12196, 13, 0, 'Tell me about gathering professions.', 0, 15595),
(12196, 12, 0, 'Tell me about Herbalism.', 0, 15595),
(12196, 11, 3, 'Train me in Inscription.', 0, 15595),
(12188, 15, 0, 'Tell me about production professions.', 0, 15595),
(12188, 14, 0, 'Tell me about gathering professions.', 0, 15595),
(12188, 13, 0, 'Tell me about Inscription.', 0, 15595),
(12188, 12, 0, 'Tell me about Alchemy.', 0, 15595),
(12188, 11, 3, 'Train me in Herbalism.', 0, 15595),
(12195, 14, 0, 'Tell me about production professions.', 0, 15595),
(12195, 13, 0, 'Tell me about gathering professions.', 0, 15595),
(12195, 12, 0, 'Tell me about Mining.', 0, 15595),
(12195, 11, 3, 'Train me in Engineering.', 0, 15595),
(12192, 14, 0, 'Tell me about production professions.', 0, 15595),
(12192, 13, 0, 'Tell me about gathering professions.', 0, 15595),
(12192, 12, 0, 'Tell me about Mining.', 0, 15595),
(12192, 11, 3, 'Train me in Blacksmithing.', 0, 15595),
(12191, 15, 0, 'Tell me about production professions.', 0, 15595),
(12191, 14, 0, 'Tell me about gathering professions.', 0, 15595),
(12191, 13, 0, 'Tell me about Inscription.', 0, 15595),
(12191, 12, 0, 'Tell me about Herbalism.', 0, 15595),
(12191, 11, 3, 'Train me in Alchemy.', 0, 15595);

UPDATE `gossip_menu_option` SET `OptionType`= 1, `OptionNpcFlag`= 1 WHERE `MenuId` IN (12186, 12185, 12180, 12199, 12193, 12198, 12190, 12197, 12189, 12196, 12188, 12195, 12192, 12191) AND `OptionIcon`= 0;
UPDATE `gossip_menu_option` SET `OptionType`= 5, `OptionNpcFlag`= 16 WHERE `MenuId` IN (12186, 12185, 12180, 12199, 12193, 12198, 12190, 12197, 12189, 12196, 12188, 12195, 12192, 12191) AND `OptionIcon`= 3;

DELETE FROM `gossip_menu_option_action` WHERE `MenuId` IN (12186, 12185, 12180, 12199, 12193, 12198, 12190, 12197, 12189, 12196, 12188, 12195, 12192, 12191);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(12185, 14, 12186, 0),
(12180, 11, 12185, 0),
(12186, 19, 12185, 0),
(12180, 12, 12186, 0),
(12199, 14, 12186, 0),
(12186, 18, 12199, 0),
(12199, 13, 12185, 0),
(12199, 12, 12193, 0),
(12198, 14, 12186, 0),
(12186, 17, 12198, 0),
(12198, 13, 12185, 0),
(12198, 12, 12190, 0),
(12197, 14, 12186, 0),
(12186, 16, 12197, 0),
(12197, 13, 12185, 0),
(12197, 12, 12189, 0),
(12196, 14, 12186, 0),
(12186, 15, 12196, 0),
(12196, 13, 12185, 0),
(12196, 12, 12188, 0),
(12195, 14, 12186, 0),
(12186, 14, 12195, 0),
(12195, 13, 12185, 0),
(12195, 12, 12189, 0),
(12193, 14, 12186, 0),
(12186, 13, 12193, 0),
(12193, 13, 12185, 0),
(12193, 12, 12199, 0),
(12192, 14, 12186, 0),
(12186, 12, 12192, 0),
(12192, 13, 12185, 0),
(12192, 12, 12189, 0),
(12186, 11, 12191, 0),
(12191, 14, 12185, 0),
(12191, 13, 12196, 0),
(12191, 12, 12188, 0),
(12190, 14, 12186, 0),
(12185, 13, 12190, 0),
(12190, 13, 12185, 0),
(12190, 12, 12198, 0),
(12189, 16, 12186, 0),
(12185, 12, 12189, 0),
(12189, 15, 12185, 0),
(12189, 14, 12197, 0),
(12189, 13, 12195, 0),
(12189, 12, 12192, 0),
(12188, 15, 12186, 0),
(12185, 11, 12188, 0),
(12188, 14, 12185, 0),
(12188, 13, 12196, 0),
(12188, 12, 12191, 0);


DELETE FROM `gossip_menu_option_trainer` WHERE `MenuId` IN (12186, 12185, 12180, 12199, 12193, 12198, 12190, 12197, 12189, 12196, 12188, 12195, 12192, 12191);
INSERT INTO `gossip_menu_option_trainer` (`MenuId`, `OptionIndex`, `TrainerId`) VALUES
(12199, 11, 117),
(12198, 11, 103),
(12197, 11, 48),
(12196, 11, 387),
(12195, 11, 102),
(12193, 11, 51),
(12192, 11, 80),
(12191, 11, 59),
(12190, 11, 390),
(12189, 11, 389),
(12188, 11, 388);

UPDATE `creature_template` SET `gossip_menu_id`= 12180 WHERE `entry`= 47384;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 15 AND `SourceGroup` IN (12186, 12185, 12180, 12199, 12193, 12198, 12190, 12197, 12189, 12196, 12188, 12195, 12192, 12191);

DELETE FROM `trainer` WHERE `Id`= 387;
INSERT INTO `trainer` (`Id`, `Type`, `Greeting`, `VerifiedBuild`) VALUES
(387, 2, 'Would you like to learn the intricacies of inscription?', 15595);

DELETE FROM `trainer_spell` WHERE `TrainerId`= 387;
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
(387, 50598, 400, 773, 75, 0, 0, 0, 0, 15595),
(387, 50605, 400, 773, 75, 0, 0, 0, 0, 15595),
(387, 50612, 400, 773, 75, 0, 0, 0, 0, 15595),
(387, 52739, 150, 773, 35, 0, 0, 0, 0, 15595),
(387, 52843, 50, 773, 1, 0, 0, 0, 0, 15595),
(387, 48248, 50, 773, 35, 0, 0, 0, 0, 15595),
(387, 53462, 300, 773, 75, 0, 0, 0, 0, 15595),
(387, 58484, 50, 773, 15, 0, 0, 0, 0, 15595),
(387, 58472, 50, 773, 15, 0, 0, 0, 0, 15595),
(387, 45375, 10, 0, 0, 0, 0, 0, 5, 15595);
