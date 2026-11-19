-- Battle Pet Trainer
UPDATE `trainer` SET `VerifiedBuild`=41079 WHERE `Id`=580;

DELETE FROM `trainer_locale` WHERE `Id`=580;
INSERT INTO `trainer_locale` (`Id`, `locale`, `Greeting_lang`, `VerifiedBuild`) VALUES
(580, 'deDE', 'Kein Gruß.', 41079),
(580, 'esES', 'Sin saludo.', 41079),
(580, 'esMX', 'Sin saludo.', 41079),
(580, 'frFR', 'Je ne vous salue pas.', 41079),
(580, 'itIT', 'Nessun saluto.', 41079),
(580, 'koKR', '안녕하지 않소.', 41079),
(580, 'ptBR', 'Sem comentários.', 41079),
(580, 'ruRU', 'Здороваться даже и не буду.', 41079),
(580, 'zhCN', '无问候', 41079),
(580, 'zhTW', '嘿。', 41079);

DELETE FROM `trainer_spell` WHERE `TrainerId`=580;
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
(580,125610,1000,0,0,0,0,0,1,41079),
(580,10676,500,0,0,119467,0,0,0,41079),
(580,10688,500,0,0,119467,0,0,0,41079),
(580,10707,500,0,0,119467,0,0,0,41079),
(580,10709,500,0,0,119467,0,0,0,41079),
(580,10711,500,0,0,119467,0,0,0,41079),
(580,10714,500,0,0,119467,0,0,0,41079),
(580,35907,500,0,0,119467,0,0,0,41079),
(580,36027,500,0,0,119467,0,0,0,41079),
(580,123212,500,0,0,119467,0,0,0,41079),
(580,123214,500,0,0,119467,0,0,0,41079),
(580,127816,500,0,0,119467,0,0,0,41079);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=31 AND `SourceGroup`=580;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(31,580,10676,0,0,16,0,1,0,0,0,0,0,'','Spell is taught if player is Human'),
(31,580,10688,0,0,16,0,16,0,0,0,0,0,'','Spell is taught if player is Undead'),
(31,580,10707,0,0,16,0,8,0,0,0,0,0,'','Spell is taught if player is Night Elf'),
(31,580,10709,0,0,16,0,(32 | 134217728),0,0,0,0,0,'','Spell is taught if player is Tauren or Highmountain Tauren'),
(31,580,10711,0,0,16,0,(4 | 64 | 2048),0,0,0,0,0,'','Spell is taught if player is Dwarf, Gnome or Dark Iron Dwarf'),
(31,580,10714,0,0,16,0,(2 | 128 | 8192),0,0,0,0,0,'','Spell is taught if player is Orc, Troll or Mag''har Orc'),
(31,580,35907,0,0,16,0,(1024 | 536870912),0,0,0,0,0,'','Spell is taught if player is Draenei or Lightforged Draenei'),
(31,580,36027,0,0,16,0,512,0,0,0,0,0,'','Spell is taught if player is Blood Elf'),
(31,580,123212,0,0,16,0,256,0,0,0,0,0,'','Spell is taught if player is Goblin'),
(31,580,123214,0,0,16,0,2097152,0,0,0,0,0,'','Spell is taught if player is Worgen'),
(31,580,127816,0,0,16,0,(16777216 | 33554432),0,0,0,0,0,'','Spell is taught if player is Pandaren');

UPDATE `gossip_menu` SET `VerifiedBuild`=41079 WHERE (`MenuId`=14991 AND `TextId`=20326);
UPDATE `npc_text` SET `VerifiedBuild`=41079 WHERE `ID`=20326;

UPDATE `gossip_menu_option` SET `OptionType`=5, `VerifiedBuild`=41079 WHERE (`MenuId`=14991 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=41079 WHERE (`MenuId`=14991 AND `OptionIndex`=1);
