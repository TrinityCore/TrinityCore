--
DELETE FROM `areatrigger_scripts` WHERE `entry` = 4937;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(4937, 'at_witchs_sanctum');

DELETE FROM `creature_text` WHERE `CreatureID` IN (25165,25166);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(25165,0,0,"Misery...confusion...mistrust. These are the hallmarks.",12,0,100,0,0,0,25512,0,"Sacrolash SAY_INTRO_SAC"),
(25165,1,0,"Shadow to the aid of fire!",14,0,100,0,0,12485,24423,0,"Sacrolash - SAY_SHADOW_NOVA"),
(25165,2,0,"Shadows engulf.",14,0,100,0,0,12486,25519,0,"Sacrolash - SAY_SLAY_SAC_1"),
(25165,2,1,"Ee-nok Kryul!",14,0,100,0,0,12487,25520,0,"Sacrolash - SAY_SLAY_SAC_2"),
(25165,3,0,"Alythess! Your fire burns within me!",14,0,100,0,0,12488,24452,0,"Sacrolash - SAY_ALYTHESS_DEAD"),
(25165,4,0,"Time is a luxury you no longer possess!",14,0,100,0,0,0,25521,0,"Sacrolash - SAY_BERSERK_SAC"),
(25165,5,0,"I... fade.",12,0,100,0,0,0,25522,0,"Sacrolash - SAY_DEATH_SAC"),
(25165,6,0,"Sacrolash directs Shadow Nova at $n.",41,0,100,0,0,0,24424,0,"Sacrolash - EMOTE_SHADOW_NOVA_SAC"),
(25165,7,0,"Alythess directs Conflagration at $n.",41,0,100,0,0,0,24426,0,"Sacrolash - EMOTE_CONFLAGRATION_SAC"),

(25166,0,0,"Depravity...hatred...chaos. These are the pillars.",12,0,100,0,0,0,25511,0,"Alythess - SAY_INTRO_ALY"),
(25166,1,0,"Fire to the aid of shadow!",14,0,100,0,0,12489,25513,0,"Alythess - SAY_CONFLAGRATION"),
(25166,2,0,"Fires consume.",14,0,100,0,0,12490,25514,0,"Alythess - SAY_SLAY_ALY_1"),
(25166,2,1,"Edir harach!",14,0,100,0,0,12491,25515,0,"Alythess - SAY_SLAY_ALY_2"),
(25166,3,0,"Sacrolash!",14,0,100,0,0,12492,25516,0,"Alythess - SAY_SACROLASH_DEAD"),
(25166,4,0,"Your luck has run its course!",14,0,100,0,0,12493,25517,0,"Alythess - SAY_BERSERK_ALY"),
(25166,5,0,"Der'ek... manul.",12,0,100,0,0,12494,25518,0,"Alythess - SAY_DEATH_ALY"),
(25166,6,0,"Alythess directs Conflagration at $n.",41,0,100,0,0,0,24426,0,"Alythess - EMOTE_CONFLAGRATION_ALY"),
(25166,7,0,"Sacrolash directs Shadow Nova at $n.",41,0,100,0,0,0,24424,0,"Alythess - EMOTE_SHADOW_NOVA_ALY");

DELETE FROM `creature_formations` WHERE `leaderGUID` = 53687;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(53687,53687,0,0,3,0,0),
(53687,53668,0,0,3,0,0);

UPDATE `creature_template_addon` SET `auras` = '' WHERE `entry` IN (25165,25166);

UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 28, `EffectBasePoints1` = 3, `EffectImplicitTargetA1` = 18, `EffectMiscValue1` = 25214, `EffectMiscValueB1` = 64 WHERE `Id` = 45258;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_eredar_twins_blaze',
'spell_eredar_twins_dark_flame_aura_shadow',
'spell_eredar_twins_dark_flame_aura_fire');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(45235, 'spell_eredar_twins_blaze'),
(45343, 'spell_eredar_twins_dark_flame_aura_shadow'),
(47300, 'spell_eredar_twins_dark_flame_aura_fire');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (45347,45348,45270,45271,45256,45248,45329,45246,45342,46771);
