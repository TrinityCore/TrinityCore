-- Re-order texts
DELETE FROM `creature_text` WHERE `CreatureID` = 17968;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17968,0,0,"All of your efforts have been in vain, for the draining of the World Tree has already begun!  Soon the heart of your world will beat no more!",14,0,100,0,0,10986,20432,3,"Archimonde - SAY_INTRO"),
(17968,1,0,"Your resistance is insignificant.",14,0,100,0,0,10987,18257,0,"Archimonde - SAY_AGGRO"),
(17968,2,0,"You are mine now.",14,0,100,0,0,10988,18258,0,"Archimonde - SAY_CHARM_1"),
(17968,2,1,"Bow to my will.",14,0,100,0,0,11042,18259,0,"Archimonde - SAY_CHARM_2"),
(17968,3,0,"A-kreesh!",14,0,100,0,0,10989,18260,0,"Archimonde - SAY_AIR_BURST_1"),
(17968,3,1,"Away, vermin!",14,0,100,0,0,11043,18261,0,"Archimonde - SAY_AIR_BURST_2"),
(17968,4,0,"This world will burn!",14,0,100,0,0,10990,18262,0,"Archimonde - SAY_DOOMFIRE_1"),
(17968,4,1,"Manach sheek-thrish!",14,0,100,0,0,11041,18263,0,"Archimonde - SAY_DOOMFIRE_2"),
(17968,5,0,"Your soul will languish for eternity.",14,0,100,0,0,10991,18264,0,"Archimonde - SAY_SLAY_1"),
(17968,5,1,"All creation will be devoured.",14,0,100,0,0,11044,18265,0,"Archimonde - SAY_SLAY_2"),
(17968,5,2,"I am the coming of the end!",14,0,100,0,0,11045,18266,0,"Archimonde - SAY_SLAY_3"),
(17968,6,0,"No, it cannot be! Nooo!",14,0,100,0,0,10992,14991,0,"Archimonde - SAY_DEATH"),
(17968,7,0,"At last it is here! Mourn and lament the passing of all you have ever known, and all that would have been! Hach min corai!",14,0,100,0,0,10993,14990,0,"Archimonde - SAY_ENRAGE");

-- Spell scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_protection_of_elune';
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_archimonde_eternal_silence';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(42201, 'spell_archimonde_eternal_silence');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (32111,32124);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,32111,0,0,31,0,3,17946,0,0,0,0,"","Group 0: Spell 'Finger of Death' (Effect 0) targets creature 'Ancient Wisp'"),
(13,1,32124,0,0,31,0,3,17946,0,0,0,0,"","Group 0: Spell 'Denouement Wisp' targets creature 'Ancient Wisp'"),
(13,1,32124,0,1,31,0,3,18502,0,0,0,0,"","Group 1: Spell 'Denouement Wisp' targets creature 'Night Elf Wisp'");

-- Disable proc of Soul Charge spells, doesn't look like they proc on retail
DELETE FROM `spell_proc` WHERE `SpellId` IN (32045,32051,32052);
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `DisableEffectsMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(32045,0,0,0,0,0,0,0,2,0,0,1,0,0,0,0),
(32051,0,0,0,0,0,0,0,2,0,0,1,0,0,0,0),
(32052,0,0,0,0,0,0,0,2,0,0,1,0,0,0,0);

-- Creatures involved in encounter
UPDATE `creature_template` SET `speed_walk` = 3.2, `speed_run` = 2.28571, `BaseAttackTime` = 1500 WHERE `entry` = 17968;
UPDATE `creature_template` SET `speed_walk` = 1.6, `flags_extra` = `flags_extra` &~ 2 WHERE `entry` = 17946;
UPDATE `creature_template` SET `speed_walk` = 2.8, `speed_run` = 1 WHERE `entry` = 18095;
UPDATE `creature_template` SET `speed_walk` = 1, `ScriptName` = 'npc_doomfire_spirit' WHERE `entry` = 18104;
UPDATE `creature_model_info` SET `BoundingRadius` = 4.2, `CombatReach` = 12 WHERE `DisplayID` = 20939;
