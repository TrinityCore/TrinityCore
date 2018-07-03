--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=43244;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 43244, 0, 0, 31, 0, 5, 186234, 0, 0, 0, 0, "", "Spell Headless Horseman - Create Water Bucket, Barrel Splash's EFFECT_0 targets gameobject Water Barrel");

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=42144;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(42144, 42229, 1, "Spell Headless Horseman - Create Water Bucket triggers cast of Headless Horseman - Create Water Bucket (Cosmetic)");
