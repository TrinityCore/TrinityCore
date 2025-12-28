-- Reorder & regroup texts
DELETE FROM `creature_text` WHERE `CreatureID` = 18805;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(18805,0,0,"Tal anu'men no sin'dorei!",14,0,100,0,0,11134,20849,0,"Solarian SAY_AGGRO"),
(18805,1,0,"The warmth of the sun... awaits.",14,0,100,0,0,11135,20850,0,"Solarian SAY_DEATH"),
(18805,2,0,"Your soul belongs to the abyss!",14,0,100,0,0,11136,20851,0,"Solarian SAY_SLAY_1"),
(18805,2,1,"By the blood of the Highborne!",14,0,100,0,0,11137,20852,0,"Solarian SAY_SLAY_2"),
(18805,2,2,"For the Sunwell!",14,0,100,0,0,11138,20853,0,"Solarian SAY_SLAY_3"),
(18805,3,0,"You are hopelessly outmatched!",14,0,100,0,0,11139,20854,0,"Solarian SAY_SUMMON_1"),
(18805,3,1,"I will crush your delusions of grandeur!",14,0,100,0,0,11140,20855,0,"Solarian SAY_SUMMON_2"),
(18805,4,0,"Enough of this!  Now I call upon the fury of the cosmos itself.",14,0,100,0,0,0,20372,0,"Solarian SAY_VOID_1"),
(18805,5,0,"I become ONE... with the VOID!",14,0,100,0,0,0,20373,0,"Solarian SAY_VOID_2");

-- Solarium Agent
UPDATE `creature_template` SET `ScriptName` = 'npc_solarium_agent' WHERE `entry` = 18925;

-- Astromancer Solarian Spotlight
UPDATE `creature_template` SET `unit_flags` = 33554688 WHERE `entry` = 18928;
UPDATE `creature_template_addon` SET `auras` = '25824' WHERE `entry` = 18928;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 33366;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,33366,0,0,31,0,3,18805,0,0,0,0,"","Group 0: Spell 'Summon Astromancer Solarian' (Effect 0) targets creature 'High Astromancer Solarian'");

-- Summon Astromancer Adds (should summon 4 creature, not 5)
UPDATE `spell_dbc` SET `EffectDieSides1` = 0 WHERE `Id` = 33362;
