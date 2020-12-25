--
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 123, `EffectImplicitTargetA1` = 25, `EffectMiscValue1` = 878 WHERE `Id` = 47725; -- Tariolstrasz: Unlearned Taxi from Wrymrest Bottom to Top
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 123, `EffectImplicitTargetA1` = 25, `EffectMiscValue1` = 883 WHERE `Id` = 49502; -- Tariolstrasz: Unlearned Taxi from Wrymrest Bottom to Middle
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 123, `EffectImplicitTargetA1` = 25, `EffectMiscValue1` = 879 WHERE `Id` = 47734; -- Torastrasza: Unlearned Taxi to the Bottom of Wrymrest
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 123, `EffectImplicitTargetA1` = 25, `EffectMiscValue1` = 880 WHERE `Id` = 49465; -- Torastrasza: Unlearned Taxi to the Middle of Wrymrest
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 123, `EffectImplicitTargetA1` = 25, `EffectMiscValue1` = 881 WHERE `Id` = 49470; -- Lord Afrasastrasz: Unlearned Taxi to the Top of Wrymrest
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 123, `EffectImplicitTargetA1` = 25, `EffectMiscValue1` = 882 WHERE `Id` = 49492; -- Lord Afrasastrasz: Unlearned Taxi to the Bottom of Wrymrest

UPDATE `smart_scripts` SET `action_type` = 11, `action_param1` = 47725, `comment` = "Tariolstrasz - On Gossip Option 0 Selected - Cast 'Tariolstrasz: Unlearned Taxi from Wrymrest Bottom to Top'" WHERE `entryorguid` = 26443 AND `source_type` = 0 AND `id` = 0;
UPDATE `smart_scripts` SET `action_type` = 11, `action_param1` = 49502, `comment` = "Tariolstrasz - On Gossip Option 1 Selected - Cast 'Tariolstrasz: Unlearned Taxi from Wrymrest Bottom to Middle'" WHERE `entryorguid` = 26443 AND `source_type` = 0 AND `id` = 1;
UPDATE `smart_scripts` SET `action_type` = 11, `action_param1` = 47734, `comment` = "Torastrasza - On Gossip Option 0 Selected - Cast 'Torastrasza: Unlearned Taxi to the Bottom of Wrymrest'" WHERE `entryorguid` = 26949 AND `source_type` = 0 AND `id` = 0;
UPDATE `smart_scripts` SET `action_type` = 11, `action_param1` = 49465, `comment` = "Torastrasza - On Gossip Option 1 Selected - Cast 'Torastrasza: Unlearned Taxi to the Middle of Wrymrest'" WHERE `entryorguid` = 26949 AND `source_type` = 0 AND `id` = 1;
UPDATE `smart_scripts` SET `action_type` = 11, `action_param1` = 49470, `comment` = "Lord Afrasastrasz - On Gossip Option 0 Selected - Cast 'Lord Afrasastrasz: Unlearned Taxi to the Top of Wrymrest'" WHERE `entryorguid` = 27575 AND `source_type` = 0 AND `id` = 0;
UPDATE `smart_scripts` SET `action_type` = 11, `action_param1` = 49492, `comment` = "Lord Afrasastrasz - On Gossip Option 1 Selected - Cast 'Lord Afrasastrasz: Unlearned Taxi to the Bottom of Wrymrest'" WHERE `entryorguid` = 27575 AND `source_type` = 0 AND `id` = 1;
