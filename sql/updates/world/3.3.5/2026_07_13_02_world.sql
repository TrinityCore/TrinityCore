-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` = 23577;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23577,0,0,"Get on ya knees and bow.... to da fang and claw!",14,0,100,0,0,12020,23612,0,"Halazzi SAY_AGGRO"),
(23577,1,0,"I fight wit' untamed spirit....",14,0,100,0,0,12021,22963,0,"Halazzi SAY_SPLIT"),
(23577,2,0,"Spirit, come back to me!",14,0,100,0,0,12022,22964,0,"Halazzi SAY_MERGE"),
(23577,3,0,"Me gonna carve ya now!",14,0,100,0,0,12023,23615,0,"Halazzi SAY_MELEE_1"),
(23577,3,1,"You gonna leave in pieces!",14,0,100,0,0,12024,23616,0,"Halazzi SAY_MELEE_2"),
(23577,4,0,"Whatchoo been doin', pacin' yourselves?",14,0,100,0,0,12025,24321,0,"Halazzi SAY_BERSERK"),
(23577,5,0,"You can't fight da power!",14,0,100,0,0,12026,23613,0,"Halazzi SAY_SLAY_1"),
(23577,5,1,"Ya all gonna fail!",14,0,100,0,0,12027,23614,0,"Halazzi SAY_SLAY_2"),
(23577,6,0,"Chaga... choka'jinn.",14,0,100,0,0,12028,23611,0,"Halazzi SAY_DEATH"),
(23577,7,0,"Come, fools. Fill ma empty cages....",14,0,100,0,0,12029,23309,0,"Halazzi SAY_EVENT_1"),
(23577,7,1,"I be waitin, strangers. Your deaths gonna make me stronger!",14,0,100,0,0,12030,23310,0,"Halazzi SAY_EVENT_2");

-- Halazzi
UPDATE `creature_template` SET `flags_extra` = `flags_extra`|0x00200000 WHERE `entry` = 23577;

-- Halazzi (Transform)
UPDATE `creature_model_info` SET `BoundingRadius` = 0.7812495, `CombatReach` = 3.375 WHERE `DisplayID` = 22348;

-- Corrupted Lightning Totem
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1, `AIName` = '', `ScriptName` = 'npc_corrupted_lightning_totem' WHERE `entry` = 24224;

UPDATE `creature_model_info` SET `BoundingRadius` = 1.55, `CombatReach` = 1.55 WHERE `DisplayID` = 22523;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 24224 AND `source_type` = 0;

-- Spirit of the Lynx
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 70, `speed_walk` = 1, `speed_run` = 2.14286, `BaseAttackTime` = 1500, `ScriptName` = 'npc_spirit_of_the_lynx' WHERE `entry` = 24143;

UPDATE `creature_model_info` SET `BoundingRadius` = 0.62, `CombatReach` = 0 WHERE `DisplayID` = 20808;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 43615;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,43615,0,0,31,0,3,24144,0,0,0,0,"","Group 0: Spell 'Halazzi Transform' (Effect 0) targets creature 'Halazzi'");

-- Spell scripts (range of spells is confusing, we ignore it and make caster spell target)
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 77, `EffectDieSides1` = 1, `EffectBasePoints1` = 74, `EffectImplicitTargetA1` = 1, `DmgMultiplier1` = 1 WHERE `Id` = 43536;
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 77, `EffectDieSides1` = 1, `EffectBasePoints1` = 49, `EffectImplicitTargetA1` = 1, `DmgMultiplier1` = 1 WHERE `Id` = 43537;
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 77, `EffectDieSides1` = 1, `EffectBasePoints1` = 24, `EffectImplicitTargetA1` = 1, `DmgMultiplier1` = 1 WHERE `Id` = 43538;

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_halazzi_set_health';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(43536, 'spell_halazzi_set_health'),
(43537, 'spell_halazzi_set_health'),
(43538, 'spell_halazzi_set_health');
