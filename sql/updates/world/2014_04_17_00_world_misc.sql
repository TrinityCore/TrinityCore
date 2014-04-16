DELETE FROM `spelldifficulty_dbc` WHERE `id`=42739;
INSERT INTO `spelldifficulty_dbc` (`id`, `spellid0`, `spellid1`) VALUES
(42739,42739,59736);

DELETE FROM `spell_script_names` WHERE `spell_id` IN (42730,59735,42912);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(42730,'spell_ingvar_woe_strike'),
(59735,'spell_ingvar_woe_strike'),
(42912,'spell_ingvar_summon_banshee');

UPDATE `creature_text` SET `entry`=23980, `groupid`=`groupid`-3 WHERE `entry`=23954 AND `groupid` IN (3,4,5);

UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry` IN (23997,31835);

UPDATE `creature_template` SET `mingold`=0, `maxgold`=0, `lootid`=0 WHERE `entry` IN (23954,31673);
UPDATE `creature_template` SET `mingold`=4056, `maxgold`=6760, `lootid`=23980 WHERE `entry`=23980;
UPDATE `creature_template` SET `mingold`=8112, `maxgold`=13520, `lootid`=31674 WHERE `entry`=31674;

UPDATE `creature_loot_template` SET `entry`=23980 WHERE `entry`=23954;
UPDATE `creature_loot_template` SET `entry`=31674 WHERE `entry`=31673;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceGroup` IN (23980,31674,23954,31673);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(1,23980,43228,0,0,1,0,57940,0,0,0,0,0,'','Can loot Stone Keeper''s Shard only with aura Essence of Wintergrasp'),
(1,31674,43228,0,0,1,0,57940,0,0,0,0,0,'','Can loot Stone Keeper''s Shard only with aura Essence of Wintergrasp');

UPDATE `instance_encounters` SET `creditEntry`=23980 WHERE `entry` IN (575,576);

UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (24068,31655);
