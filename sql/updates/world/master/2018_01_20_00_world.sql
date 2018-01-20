-- Quest: The Burning Blade
DELETE FROM `creature_loot_template` WHERE `Item`= 52564;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Chance`,`QuestRequired`,`MinCount`,`MaxCount`) VALUES
(3196,52564,86,1,1,1),(3199,52564,64,1,1,1),(3195,52564,43,1,1,1);
