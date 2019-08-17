DELETE FROM `item_script_names` WHERE  `Id`=19169;
INSERT INTO `item_script_names` (`Id`, `ScriptName`) VALUES (19169, 'item_generic_limit_chance_above_60');
UPDATE `item_template_addon` SET `SpellPPMChance`='2.5' WHERE  `Id`=19169;
