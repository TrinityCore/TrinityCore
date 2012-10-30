/* World_Script.sql INSC. Myendras
 * Myendras SQL script
 * Last Update: Saqirmdev
 * Thanks: Phailure, Saqirmdev
 */ 

-- Variables
SET @QUEST := 10722;
SET @ENTRY := 22019;
SET @SPELL1:= 37704; -- Whirlwind
SET @SPELL2:= 8599; -- Enrage

-- Remove aura when trinket is unequipped fix by nelegalno
-- Spirit-World Glass (39388)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=60527;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17,0,60527,0,0,3,0,39388,0,0,0,0,'',"Essence Flow aura only if Spirit-World Glass is equipped");

-- Defender's Code (40257)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=60286;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17,0,60286,0,0,3,0,40257,0,0,0,0,'',"Defender's Code aura only if Defender's Code is equipped");

-- Furnace Stone (45313)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=65011;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17,0,65011,0,0,3,0,45313,0,0,0,0,'',"Furnace Stone aura only if Furnace Stone is equipped");

-- Satrina's Impeding Scarab (47080)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=67699 AND `ElseGroup`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17,0,67699,0,0,3,0,47080,0,0,0,0,'',"Fortitude aura only if Satrina's Impeding Scarab is equipped");

-- Satrina's Impeding Scarab Heroic (47088)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=67753 AND `ElseGroup`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17,0,67753,0,0,3,0,47088,0,0,0,0,'',"Fortitude aura only if Satrina's Impeding Scarab Heroic is equipped");

-- Juggernaut's Vitality (47290)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=67699 AND `ElseGroup`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17,0,67699,0,1,3,0,47290,0,0,0,0,'',"Fortitude aura only if Juggernaut's Vitality is equipped");

-- Juggernaut's Vitality Heroic (47451)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=67753 AND `ElseGroup`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17,0,67753,0,1,3,0,47451,0,0,0,0,'',"Fortitude aura only if Satrina's Impeding Scarab is equipped");

-- Binding Light (47728)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=67726 AND `ElseGroup`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17,0,67726,0,0,3,0,47728,0,0,0,0,'',"Escalating Power aura only if Binding Light is equipped");

-- Binding Stone (47880)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=67726 AND `ElseGroup`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17,0,67726,0,1,3,0,47880,0,0,0,0,'',"Escalating Power aura only if Binding Stone is equipped");

-- Fervor of the Frostborn (47727)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=67728 AND `ElseGroup`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17,0,67728,0,0,3,0,47727,0,0,0,0,'',"Hardening Armor aura only if Fervor of the Frostborn is equipped");

-- Eitrigg's Oath (47882)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=67728 AND `ElseGroup`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17,0,67728,0,1,3,0,47882,0,0,0,0,'',"Hardening Armor aura only if Eitrigg's Oath is equipped");

-- Binding Light Heroic (47947)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=67740 AND `ElseGroup`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17,0,67740,0,0,3,0,47947,0,0,0,0,'',"Escalating Power aura only if Binding Light Heroic is equipped");

-- Binding Stone Heroic (48019)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=67740 AND `ElseGroup`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17,0,67740,0,1,3,0,48019,0,0,0,0,'',"Escalating Power aura only if Binding Stone Heroic is equipped");

-- Fervor of the Frostborn Heroic (47949)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=67742 AND `ElseGroup`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17,0,67742,0,0,3,0,47949,0,0,0,0,'',"Hardening Armor aura only if Fervor of the Frostborn Heroic is equipped");

-- Eitrigg's Oath Heroic (48021)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=67742 AND `ElseGroup`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17,0,67742,0,1,3,0,48021,0,0,0,0,'',"Hardening Armor aura only if Eitrigg's Oath Heroic is equipped");

-- Shard of the Crystal Heart (48722)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=67683;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17,0,67683,0,0,3,0,48722,0,0,0,0,'',"Celerity aura only if Shard of the Crystal Heart is equipped");

-- Talisman of Resurgence (48724)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=67684;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17,0,67684,0,0,3,0,48724,0,0,0,0,'',"Hospitality aura only if Talisman of Resurgence is equipped");

-- Ick's Rotting Thumb (50235)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=71569;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17,0,71569,0,0,3,0,50235,0,0,0,0,'',"Increased Fortitude aura only if Ick's Rotting Thumb is equipped");

-- Nevermelting Ice Crystal (50259)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=71563;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17,0,71563,0,0,3,0,50259,0,0,0,0,'',"Deadly Precision aura only if Nevermelting Ice Crystal is equipped");

-- Corroded Skeleton Key (50356)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=71586;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17,0,71586,0,0,3,0,50356,0,0,0,0,'',"Hardened Skin aura only if Corroded Skeleton Key is equipped");

-- Maghia's Misguided Quill (50357)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=71579;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17,0,71579,0,0,3,0,50357,0,0,0,0,'',"Elusive Power aura only if Maghia's Misguided Quill is equipped");



UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `guid` IN (106595,106596,106597,106598,106603,106604,106605,106607,106608,106626,106629,106631,106643,106646,106658,106663,106665,106668,106669,106675,106676,106679,106680,106681,106682,106683,106684,106685,106686,106687,106688,106692,106693,106696,106702,106703,106706,106722,106723,106724,106726,106727,106728,106733,106737,106741,106749,106755,106757,131072);
UPDATE `creature` SET `position_z`=72.130 WHERE `guid`=106631;
UPDATE `creature` SET `position_z`=72.902 WHERE `guid`=106675;
UPDATE `creature` SET `position_z`=69.505 WHERE `guid`=131072;

REPLACE INTO battleground_template (id, MinPlayersPerTeam, MaxPlayersPerTeam, MinLvl, MaxLvl, AllianceStartLoc, AllianceStartO, HordeStartLoc, HordeStartO, StartMaxDist, Weight, ScriptName, Comment) values
(6,0,2,10,80,0,0,0,0,0,1,'','All Arena');


INSERT INTO spell_linked_spell (spell_trigger, spell_effect, type, comment) VALUES
(7744, 72757, 0, 'Will of the Forsaken Cooldown Trigger (WOTF)'),
(42292, 72752, 0, 'Will of the Forsaken Cooldown Trigger');

REPLACE INTO `spell_linked_spell` VALUES (51724, -1784, 1, 'Stealth (Sap Rem.)');
REPLACE INTO `spell_linked_spell` VALUES (51724, -58984, 1, 'Shadomeld (Sap Rem.)');
REPLACE INTO `spell_linked_spell` VALUES (51724, -24453, 1, 'Prowl (Sap Rem.)');

