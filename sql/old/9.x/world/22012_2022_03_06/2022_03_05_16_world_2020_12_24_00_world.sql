--
UPDATE `serverside_spell` SET `ProcChance` = 101 WHERE `Id` = 56204; -- Ebon Blade Prisoners: Force Cast Summon Ebon Blade Knight - Human
UPDATE `serverside_spell` SET `ProcChance` = 101 WHERE `Id` = 56210; -- Ebon Blade Prisoners: Force Cast Summon Ebon Blade Knight - Night Elf
UPDATE `serverside_spell` SET `ProcChance` = 101 WHERE `Id` = 56213; -- Ebon Blade Prisoners: Force Cast Summon Ebon Blade Knight - Orc
UPDATE `serverside_spell` SET `ProcChance` = 101 WHERE `Id` = 56215; -- Ebon Blade Prisoners: Force Cast Summon Ebon Blade Knight - Troll

DELETE FROM `serverside_spell_effect` WHERE `SpellID` IN (56204,56210,56213,56215);
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `Effect`, `EffectTriggerSpell`, `ImplicitTarget1`) VALUES
(56204, 0, 140, 56207, 25),
(56210, 0, 140, 56209, 25),
(56213, 0, 140, 56212, 25),
(56215, 0, 140, 56214, 25);

UPDATE `smart_scripts` SET `action_type` = 11, `action_param1` = 56204, `comment` = "Ebon Blade Prisoner - On Link - Cast 'Ebon Blade Prisoners: Force Cast Summon Ebon Blade Knight - Human'" WHERE `entryorguid` = 30186 AND `source_type` = 0 AND `id` = 3;
UPDATE `smart_scripts` SET `action_type` = 11, `action_param1` = 56210, `comment` = "Ebon Blade Prisoner - On Link - Cast 'Ebon Blade Prisoners: Force Cast Summon Ebon Blade Knight - Night Elf'" WHERE `entryorguid` = 30194 AND `source_type` = 0 AND `id` = 3;
UPDATE `smart_scripts` SET `action_type` = 11, `action_param1` = 56213, `comment` = "Ebon Blade Prisoner - On Link - Cast 'Ebon Blade Prisoners: Force Cast Summon Ebon Blade Knight - Orc'" WHERE `entryorguid` = 30195 AND `source_type` = 0 AND `id` = 3;
UPDATE `smart_scripts` SET `action_type` = 11, `action_param1` = 56215, `comment` = "Ebon Blade Prisoner - On Link - Cast 'Ebon Blade Prisoners: Force Cast Summon Ebon Blade Knight - Troll'" WHERE `entryorguid` = 30196 AND `source_type` = 0 AND `id` = 3;
