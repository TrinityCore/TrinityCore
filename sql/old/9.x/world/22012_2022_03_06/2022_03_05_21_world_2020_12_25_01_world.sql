--
UPDATE `serverside_spell` SET `ProcChance` = 101 WHERE `Id` = 47725; -- Tariolstrasz: Unlearned Taxi from Wrymrest Bottom to Top
UPDATE `serverside_spell` SET `ProcChance` = 101 WHERE `Id` = 49502; -- Tariolstrasz: Unlearned Taxi from Wrymrest Bottom to Middle
UPDATE `serverside_spell` SET `ProcChance` = 101 WHERE `Id` = 47734; -- Torastrasza: Unlearned Taxi to the Bottom of Wrymrest
UPDATE `serverside_spell` SET `ProcChance` = 101 WHERE `Id` = 49465; -- Torastrasza: Unlearned Taxi to the Middle of Wrymrest
UPDATE `serverside_spell` SET `ProcChance` = 101 WHERE `Id` = 49470; -- Lord Afrasastrasz: Unlearned Taxi to the Top of Wrymrest
UPDATE `serverside_spell` SET `ProcChance` = 101 WHERE `Id` = 49492; -- Lord Afrasastrasz: Unlearned Taxi to the Bottom of Wrymrest

DELETE FROM `serverside_spell_effect` WHERE `SpellID` IN (47725,49502,47734,49465,49470,49492);
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `Effect`, `EffectMiscValue1`, `ImplicitTarget1`) VALUES
(47725, 0, 123, 878, 25),
(49502, 0, 123, 883, 25),
(47734, 0, 123, 879, 25),
(49465, 0, 123, 880, 25),
(49470, 0, 123, 881, 25),
(49492, 0, 123, 882, 25);

UPDATE `smart_scripts` SET `action_type` = 11, `action_param1` = 47725, `comment` = "Tariolstrasz - On Gossip Option 0 Selected - Cast 'Tariolstrasz: Unlearned Taxi from Wrymrest Bottom to Top'" WHERE `entryorguid` = 26443 AND `source_type` = 0 AND `id` = 0;
UPDATE `smart_scripts` SET `action_type` = 11, `action_param1` = 49502, `comment` = "Tariolstrasz - On Gossip Option 1 Selected - Cast 'Tariolstrasz: Unlearned Taxi from Wrymrest Bottom to Middle'" WHERE `entryorguid` = 26443 AND `source_type` = 0 AND `id` = 1;
UPDATE `smart_scripts` SET `action_type` = 11, `action_param1` = 47734, `comment` = "Torastrasza - On Gossip Option 0 Selected - Cast 'Torastrasza: Unlearned Taxi to the Bottom of Wrymrest'" WHERE `entryorguid` = 26949 AND `source_type` = 0 AND `id` = 0;
UPDATE `smart_scripts` SET `action_type` = 11, `action_param1` = 49465, `comment` = "Torastrasza - On Gossip Option 1 Selected - Cast 'Torastrasza: Unlearned Taxi to the Middle of Wrymrest'" WHERE `entryorguid` = 26949 AND `source_type` = 0 AND `id` = 1;
UPDATE `smart_scripts` SET `action_type` = 11, `action_param1` = 49470, `comment` = "Lord Afrasastrasz - On Gossip Option 0 Selected - Cast 'Lord Afrasastrasz: Unlearned Taxi to the Top of Wrymrest'" WHERE `entryorguid` = 27575 AND `source_type` = 0 AND `id` = 0;
UPDATE `smart_scripts` SET `action_type` = 11, `action_param1` = 49492, `comment` = "Lord Afrasastrasz - On Gossip Option 1 Selected - Cast 'Lord Afrasastrasz: Unlearned Taxi to the Bottom of Wrymrest'" WHERE `entryorguid` = 27575 AND `source_type` = 0 AND `id` = 1;
