DELETE FROM `spell_script_names` WHERE `spell_id` IN (
42924,
43310,
42992,
42993,
42994,
43052,
43450
);
INSERT INTO `spell_script_names` (`spell_id` ,`ScriptName`) VALUES
(42924, 'spell_brewfest_giddyup'),
(43310, 'spell_brewfest_ram'),
(42992, 'spell_brewfest_ram'),
(42993, 'spell_brewfest_ram'),
(42994, 'spell_brewfest_ram'),
(43052, 'spell_brewfest_ram_fatigue'),
(43450, 'spell_brewfest_apple_trap');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=42924;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=43450;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 42924, 0, 0, 1, 0, 43332, 0, 0, 1, 172, 0, '', 'Cast Gore Bladder only if Cosmetic - Underwater Blood (no sound) aura is active'),
(13, 1, 43450, 0, 0, 1, 0, 43052, 0, 0, 0, 0, 0, '', 'Brewfest - apple trap - friendly DND targets only if does have aura Ram Fatigue');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=-43883 AND `spell_effect`=-43052;
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=43450 AND `spell_effect`=-43052;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(-43883, -43052, 0, 'Rental racing ram removed removes Ram Fatigue');
