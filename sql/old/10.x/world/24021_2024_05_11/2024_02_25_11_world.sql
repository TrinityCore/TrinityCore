-- Shadowglen Loot fix
SET @REF := 2000;

-- Reference Demon Loot
SET @REFDEMON := @REF;
DELETE FROM `reference_loot_template` WHERE `Entry`=@REFDEMON;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFDEMON,67310,0,80,0,1,1,1,1, 'Demon Junk 1 - Demon Hair'),
(@REFDEMON,23384,0,20,0,1,1,1,1, 'Demon Junk 1 - Dimly Glowing Eye');

-- Reference Boar Loot
SET @REFBOAR := @REF + 1;
DELETE FROM `reference_loot_template` WHERE `Entry`=@REFBOAR;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFBOAR,117,0,80,0,1,1,1,1, 'Boar Junk 1 - Tough Jerky'),
(@REFBOAR,771,0,20,0,1,1,1,1, 'Boar Junk 1 - Chipped Boar tusk');

-- Reference Spider Loot
SET @REFSPIDER := @REF + 2;
DELETE FROM `reference_loot_template` WHERE `Entry`=@REFSPIDER;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFSPIDER,7101,0,50,0,1,1,1,1, 'Spider Junk 1 - Bug Eye'),
(@REFSPIDER,1288,0,30,0,1,1,1,1, 'Spider Junk 1 - Large Venom Sac'),
(@REFSPIDER,32714,0,20,0,1,1,1,1, 'Spider Junk 1 - Splintered Spider Fang');

-- Young Thistle Boar junk loot fix for master
DELETE FROM `creature_loot_template` WHERE `Entry`=1984 AND `Item` IN (4865,7098);
UPDATE `creature_loot_template` SET `Chance`=100, `MaxCount`=1, `Comment`='Young Thistle Boar <Junk> - Tough Jerky'  WHERE `Entry`=1984 AND `Item`=117;

-- Thistle Boar junk loot fix for master
DELETE FROM `creature_loot_template` WHERE `Entry`=1985 AND `Item` IN (117,159,769,4540,4865,7098,@REFBOAR);
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(1985,@REFBOAR,@REFBOAR,100,0,1,0,1,1, 'Thistle Boar <Junk> - Ref Boar Junk 1');

-- Webwood Spider junk loot fix for master
DELETE FROM `creature_loot_template` WHERE `Entry`=1986 AND `Item` IN (117,159,1476,2070,4536,4540,5166,7100,7101,10640,@REFSPIDER);
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(1986,@REFSPIDER,@REFSPIDER,100,0,1,0,1,1, 'Webwood Spider <Junk> - Ref Spider Junk 1');

-- Grell junk loot fix for master
DELETE FROM `creature_loot_template` WHERE `Entry`=1988 AND `Item` IN (117,159,2070,4536,4540,@REFDEMON);
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(1988,@REFDEMON,@REFDEMON,100,0,1,0,1,1, 'Grell <Junk> - Ref Demon Junk 1');

-- Grellkin junk loot fix for master
DELETE FROM `creature_loot_template` WHERE `Entry`=1989 AND `Item` IN (117,159,2070,4536,4540,10639,@REFDEMON);
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(1989,@REFDEMON,@REFDEMON,100,0,1,0,1,1, 'Grellkin <Junk> - Ref Demon Junk 1');

-- Githyiss the Vile junk loot fix for master
DELETE FROM `creature_loot_template` WHERE `Entry`=1994 AND `Item` IN (117,159,1476,2070,4536,4540,7100,7101,@REFSPIDER);
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(1994,@REFSPIDER,@REFSPIDER,100,0,1,0,1,1, 'Githyiss the Vile <Junk> - Ref Spider Junk 1');

-- Young Nightsaber junk loot fix for master
DELETE FROM `creature_loot_template` WHERE `Entry`=2031 AND `Item` IN (4865,7073,7074,62391);
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(2031,62391,0,100,0,1,0,1,1, 'Young Nightsaber <Junk> - Cat Hair');

-- Mangy Nightsaber junk loot fix for master
DELETE FROM `creature_loot_template` WHERE `Entry`=2032 AND `Item` IN (4865,7073,7074,62391);
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(2032,62391,0,100,0,1,0,1,1, 'Mangy Nightsaber <Junk> - Cat Hair');

-- Grell and Grellkin no longer hav coin
UPDATE `creature_template_difficulty` SET `GoldMin`=0, `GoldMax`=0 WHERE `Entry` IN (1988,1989);
