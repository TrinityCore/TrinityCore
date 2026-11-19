-- DB/Item: Bryntroll, the Bone Arbiter
DELETE FROM `item_template_addon` WHERE `Id` IN (50415,50709);
INSERT INTO `item_template_addon` (`Id`,`SpellPPMChance`) VALUES
(50415,2),
(50709,2);
