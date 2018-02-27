DELETE FROM `areatrigger_template` WHERE `Id` IN (11515, 14843, 14978, 11346);
INSERT INTO `areatrigger_template` (`Id`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `VerifiedBuild`) VALUES
(11515, 0, 4, 40, 40, 0, 0, 0, 0, 25996),
(14843, 0, 16, 3, 3, 0, 0, 0, 0, 25996),
(14978, 0, 0, 2, 2, 0, 0, 0, 0, 25996),
(11346, 4, 0, 3.5, 3.5, 16, 16, 8, 8, 25996);

UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=11516;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=12599;
UPDATE `areatrigger_template` SET `Type`=0, `Data0`=4, `Data1`=4, `Data2`=0, `Data3`=0, `Data4`=0, `Data5`=0 WHERE `Id`=6197;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=9448;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=12770;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=3319;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=12740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=7020;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10704;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=2947;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10707;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=12536;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=12051;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10670;
UPDATE `areatrigger_template` SET `Flags`=0, `Data0`=30, `Data1`=30, `VerifiedBuild`=25996 WHERE `Id`=0;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10625;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10690;
UPDATE `areatrigger_template` SET `Data0`=4, `Data1`=4, `VerifiedBuild`=25996 WHERE `Id`=11719;

DELETE FROM `spell_areatrigger` WHERE (`SpellMiscId`=7048 AND `AreaTriggerId`=11516) OR (`SpellMiscId`=7047 AND `AreaTriggerId`=11515) OR (`SpellMiscId`=9951 AND `AreaTriggerId`=14843) OR (`SpellMiscId`=10104 AND `AreaTriggerId`=14978) OR (`SpellMiscId`=6020 AND `AreaTriggerId`=10707) OR (`SpellMiscId`=8375 AND `AreaTriggerId`=12536) OR (`SpellMiscId`=6818 AND `AreaTriggerId`=11346) OR (`SpellMiscId`=5934 AND `AreaTriggerId`=10625);
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(7048, 11516, 0, 0, 0, 0, 0, 0, 0, 25996), -- SpellId : 212826
(7047, 11515, 0, 0, 0, 0, 0, 0, 0, 25996), -- SpellId : 212824
(9951, 14843, 0, 0, 0, 0, 0, 10355, 5000, 25996), -- SpellId : 238509
(10104, 14978, 0, 0, 0, 0, 0, 0, 2000, 25996), -- SpellId : 239663
(6020, 10707, 0, 0, 0, 0, 0, 0, 15000, 25996), -- SpellId : 204443
(8375, 12536, 0, 0, 0, 0, 0, 0, 60000, 25996), -- SpellId : 223785
(6818, 11346, 0, 0, 0, 0, 0, 0, 30000, 25996), -- SpellId : 210688
(5934, 10625, 0, 0, 0, 0, 0, 0, 6000, 25996); -- SpellId : 201667

UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=5972 AND `AreaTriggerId`=10660); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=8448 AND `AreaTriggerId`=12599); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=8430 AND `AreaTriggerId`=6197); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=8000 WHERE (`SpellMiscId`=6917 AND `AreaTriggerId`=11420); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1501, `TimeToTargetScale`=10000, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=4714 AND `AreaTriggerId`=9448); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1655, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1654, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=7179 AND `AreaTriggerId`=12770); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1818, `TimeToTargetScale`=5000 WHERE (`SpellMiscId`=5280 AND `AreaTriggerId`=10003); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=56750, `TimeToTargetScale`=15000, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=120000, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=2442 AND `AreaTriggerId`=7020); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=5000 WHERE (`SpellMiscId`=7597 AND `AreaTriggerId`=12013); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6017 AND `AreaTriggerId`=10704); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=10000, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=304 AND `AreaTriggerId`=2947); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9249 AND `AreaTriggerId`=13267); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=43, `TimeToTarget`=0, `TimeToTargetScale`=600000 WHERE (`SpellMiscId`=7363 AND `AreaTriggerId`=12515); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=7663 AND `AreaTriggerId`=12051); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=5982 AND `AreaTriggerId`=10670); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6003 AND `AreaTriggerId`=10690); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=7263 AND `AreaTriggerId`=11719); -- SpellId : 0

DELETE FROM `conversation_actors` WHERE (`ConversationId`=3935 AND `ConversationActorId`=53609 AND `Idx`=0) OR (`ConversationId`=2301 AND `ConversationActorId`=51109 AND `Idx`=0) OR (`ConversationId`=3936 AND `ConversationActorId`=53609 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `VerifiedBuild`) VALUES
(3935, 53609, 0, 25996),
(2301, 51109, 0, 25996),
(3936, 53609, 0, 25996);


DELETE FROM `conversation_actor_template` WHERE `Id`=51109;
INSERT INTO `conversation_actor_template` (`Id`, `CreatureId`, `CreatureModelId`, `VerifiedBuild`) VALUES
(51109, 98548, 65843, 25996);

UPDATE `conversation_actor_template` SET `CreatureId`=115096, `CreatureModelId`=68890 WHERE `Id`=53609;
UPDATE `conversation_actor_template` SET `CreatureId`=115096, `CreatureModelId`=68890 WHERE `Id`=53609;

DELETE FROM `conversation_line_template` WHERE `Id` IN (8988, 4855, 4854, 8989);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Unk`, `VerifiedBuild`) VALUES
(8988, 0, 793, 0, 0, 25996),
(4855, 6674, 574, 0, 0, 25996),
(4854, 0, 574, 0, 0, 25996),
(8989, 0, 793, 0, 0, 25996);


DELETE FROM `conversation_template` WHERE `Id` IN (2301, 3936, 3935);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `VerifiedBuild`) VALUES
(2301, 4854, 12816, 25996),
(3936, 8989, 8064, 25996),
(3935, 8988, 8249, 25996);


DELETE FROM `gameobject_template_addon` WHERE `entry` IN (279671 /*Portal to Shal'Aran*/, 266633 /*Teleporter Pad*/, 266032 /*Nightborne Arms Cache*/, 265439 /*Doodad_7sr_hubmanatree_lightbeam002*/, 266175 /*Fel Rune*/, 266171 /*Fel Rune*/, 267065 /*Nightborne Cage*/, 266172 /*Book*/, 251565 /*Unfortified Arcwine*/, 273294 /*School of Golden Minnows*/, 265444 /*Doodad_7sr_hubmanatree_lightbeam004*/, 247848 /*Mail Tube*/, 249023 /*Inert Waters*/, 248994 /*Moonwell*/, 252879 /*The Winterskorn War*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(279671, 0, 32), -- Portal to Shal'Aran
(266633, 114, 0), -- Teleporter Pad
(266032, 0, 4), -- Nightborne Arms Cache
(265439, 0, 8192), -- Doodad_7sr_hubmanatree_lightbeam002
(266175, 1375, 8192), -- Fel Rune
(266171, 1375, 8192), -- Fel Rune
(267065, 0, 262144), -- Nightborne Cage
(266172, 1375, 8192), -- Book
(251565, 0, 262144), -- Unfortified Arcwine
(273294, 35, 0), -- School of Golden Minnows
(265444, 0, 8192), -- Doodad_7sr_hubmanatree_lightbeam004
(247848, 0, 262144), -- Mail Tube
(249023, 0, 262144), -- Inert Waters
(248994, 0, 1048608), -- Moonwell
(252879, 0, 4); -- The Winterskorn War

UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=260493; -- Mana-Infused Gem
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=260492; -- Glowing Tome
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=260494; -- Twice-Fortified Arcwine
UPDATE `gameobject_template_addon` SET `flags`=2113540 WHERE `entry`=247851; -- Sealed Powder Keg
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=248080; -- Needle Coral
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=245887; -- Driftwood
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=245792; -- Driftwood
UPDATE `gameobject_template_addon` SET `flags`=2113540 WHERE `entry`=245507; -- Supply Cache
UPDATE `gameobject_template_addon` SET `flags`=8192 WHERE `entry`=254023; -- Arcane Power Unit
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=246704; -- Aftermath of the Well
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=250417; -- Archmage Vargoth's Journal
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=249729; -- The Masterful Miller's Manual
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=266619; -- A Mysterious Note
UPDATE `gameobject_template_addon` SET `flags`=33 WHERE `entry`=251033; -- Facade
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=246710; -- Nomi's Silver Mackerel
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=252261; -- Leyline Feed
UPDATE `gameobject_template_addon` SET `flags`=6 WHERE `entry`=244853; -- Tharillon's Stash
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=246703; -- Magical Manifest of the Moon

DELETE FROM `scene_template` WHERE (`SceneId`=1747 AND `ScriptPackageID`=1929);
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`) VALUES
(1747, 20, 1929);


DELETE FROM `spell_target_position` WHERE (`ID`=229432 AND `EffectIndex`=0) OR (`ID`=225232 AND `EffectIndex`=0) OR (`ID`=236618 AND `EffectIndex`=0) OR (`ID`=245992 AND `EffectIndex`=1);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(229432, 0, 1220, 871.91, 3637.16, 98.1, 25996), -- Spell: Téléportation : port d'Astravar Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(225232, 0, 1220, 1616.85, 4781.16, 138.31, 25996), -- Spell: Saut céleste vers Suramar Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(236618, 0, 1463, 481.75, 715.29, 23.3, 25996), -- Spell: Saut céleste vers Helheim Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(245992, 1, 0, -8998.14, 861.25, 29.62, 25996); -- Spell: Portail : Hurlevent Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=213948 AND `EffectIndex`=2);
UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=217753 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=212830 AND `EffectIndex`=1);
UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=222327 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=221996 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=209422 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=221909 AND `EffectIndex`=0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (116715 /*Rebelle souffrenuit - Lire le parchemin*/, 113304 /*113304 (Suramar Orphan)*/, 112403 /*112403 (Spawn Bunny)*/, 111902 /*111902 (Suramar Refugee)*/, 111901 /*111901 (Suramar Refugee)*/, 116716 /*116716 (Nightborne Rebel)*/, 108616 /*108616 (Guard Morgaine)*/, 107473 /*107473 (Conveniently Placed Basket)*/, 107997 /*107997 (Silgryn)*/, 107613 /*107613 (Line Bunny)*/, 111619 /*111619 (Duskwatch Shroud)*/, 109473 /*109473 (Duskwatch Shroud) - Détecteur, Détection de l'invisibilité et du camouflage*/, 114958 /*114958 (Duskwatch Subjugator)*/, 114961 /*114961 (Controller)*/, 109408 /*109408 (Lieutenant Piet)*/, 108386 /*108386 (Ambrena)*/, 108345 /*108345 (Clotaire)*/, 114874 /*114874 (Wyrmtongue Pilferer)*/, 108347 /*108347 (Ambrena)*/, 108810 /*108810 (Chloe)*/, 108346 /*108346 (Lunette)*/, 108405 /*108405 (Kal) - Ride Vehicle Hardcoded*/, 108411 /*108411 (Silgryn)*/, 108344 /*108344 (Donatien)*/, 114876 /*Garde-courroux vengeur*/, 115806 /*115806 (Duskwatch Punisher) - Lame ensanglantée*/, 115216 /*115216 (Duskwatch Veteran)*/, 114892 /*Civil flétrissant - Conduire véhicule*/, 114889 /*Civile shal’dorei - Conduire véhicule*/, 114888 /*114888 (Shal'dorei Civilian) - Ride Vehicle Seat 3 - JSB*/, 115627 /*115627 (Frightened Refugee)*/, 115626 /*115626 (Rebel Guardian)*/, 115628 /*115628 (Refugee Child)*/, 115606 /*115606 (Spell-Fencer Adept)*/, 115607 /*115607 (Thoramir)*/, 107632 /*Ly’leth Lunastre*/, 109447 /*109447 (Lunastre Attendant) - Plateau - femme, Masque de serviteur*/, 115517 /*Magus Sendath*/, 106897 /*106897 (Nighteyes)*/, 104821 /*104821 (Makeshift Ballista)*/, 104830 /*104830 (Makeshift Ballista) - RShwayder Test 02*/, 102410 /*102410 (Toryl)*/, 104550 /*104550 (Brytag)*/, 103611 /*103611 (Sashj'tar Overseer)*/, 103610 /*103610 (Sashj'tar Collier)*/, 103613 /*103613 (Sashj'tar Deep Witch)*/, 104586 /*104586 (Fjolrik) - Breuvage de marche-sous-l’eau*/, 104685 /*104685 (Kell) - Feindre la mort permanent (ne peut être pisté) (ne peut être étourdi)*/, 102390 /*102390 (Toryl)*/, 102388 /*102388 (Toryl)*/, 102527 /*102527 (Toryl)*/, 100016 /*100016 (Fjolrik)*/, 100017 /*100017 (Stokalfr)*/, 102845 /*102845 (Brandolf)*/, 112226 /*112226 (Markus Hjolbruk)*/, 100015 /*100015 (Katarine)*/, 102862 /*102862 (Trenchwalker Envoy)*/, 102841 /*102841 (Commander Malt'his)*/, 101144 /*101144 (Throndyr's Pyre Flame) - Flamme du bûcher de Throndyr*/, 102776 /*102776 (Stokalfr)*/, 102775 /*102775 (Fjolrik)*/, 102774 /*102774 (Katarine)*/, 102334 /*102334 (Brandolf)*/, 103239 /*103239 (Jarl Throndyr) - Feindre la mort permanent (ne peut être pisté) (ne peut être étourdi)*/, 101131 /*101131 (Throndyr's Pyre) - Assistant du bûcher de Throndyr*/, 115724 /*115724 (Felborne Marauder) - Ambidextrie*/, 116119 /*116119 (Felborne Energist)*/, 99948 /*99948 (Toryl)*/, 117355 /*117355 (Torturer Relyn)*/, 111923 /*111923 (Forgotten Wretch)*/, 113570 /*113570 (Forgotten Thirster)*/, 116052 /*116052 (Ley Bunny)*/, 117412 /*117412 (Felborne Trapper)*/, 116116 /*116116 (Felblade Protector)*/, 117246 /*117246 (Nighthuntress Syrenne)*/, 116115 /*116115 (Scathing Felbeast) - Morsure pénétrante, Cosmetic - Sleep Zzz*/, 116117 /*116117 (Felborne Marauder) - Ambidextrie*/, 115691 /*115691 (Felborne Magus)*/, 115690 /*115690 (Felborne Energist) - Détecteur, Détection de l'invisibilité et du camouflage*/, 116068 /*116068 (Arm of the Magistrix)*/, 120459 /*120459 (Sha'leth)*/, 120454 /*120454 (Magicus)*/, 114879 /*Golem d’animus*/, 114305 /*114305 (Nightborne Siegecaster) - Canalisation des Arcanes*/, 114301 /*114301 (Nightborne Invader)*/, 114300 /*114300 (Imperial Arcanist) - Canalisation des Arcanes*/, 114303 /*Assemblage cherche-sort - Sens arcaniques*/, 114302 /*114302 (Mana Saber)*/, 114299 /*114299 (Imperial Spellbreaker)*/, 114304 /*114304 (Nightborne Infiltrator)*/, 114306 /*114306 (Ensorcelled Mana Wraith)*/, 114307 /*114307 (Imperial Conjurer) - Canalisation des Arcanes*/, 111606 /*111606 (Moonfall Riding Hippogryph)*/, 111605 /*111605 (Moonfall Riding Hippogryph)*/, 111604 /*111604 (Moonfall Riding Hippogryph)*/, 102740 /*102740 (Moonfall Riding Hippogryph)*/, 102426 /*102426 (Beakbuck)*/, 111539 /*111539 (Kailea Windfeather)*/, 103348 /*103348 (Galar'thus Rivertree)*/, 107984 /*Ragnvald Drake-Né*/, 113793 /*Val’kyr d’Odyn*/, 113794 /*Val’kyr d’Odyn*/, 113777 /*Val’kyr d’Odyn*/, 111774 /*Matilda Skoptidottir*/, 107985 /*Finna Bjornsdottir*/, 113268 /*Valarjar forge-foudre*/, 124679 /*124679 (Dalaran Citizen)*/, 106095 /*106095 (Ivanel Meadowsong)*/, 103347 /*103347 (Nyellus Starweaver)*/, 112067 /*112067 (Volatile Leywraith)*/, 105956 /*105956 (Nightborne Eradicator)*/, 106049 /*106049 (Nightborne Eradicator)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(116715, 0, 0, 0, 1, 0, 0, 0, 0, '133464'), -- Rebelle souffrenuit - Lire le parchemin
(113304, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113304 (Suramar Orphan)
(112403, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 112403 (Spawn Bunny)
(111902, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- 111902 (Suramar Refugee)
(111901, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111901 (Suramar Refugee)
(116716, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 116716 (Nightborne Rebel)
(108616, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 108616 (Guard Morgaine)
(107473, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 107473 (Conveniently Placed Basket)
(107997, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 107997 (Silgryn)
(107613, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 107613 (Line Bunny)
(111619, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111619 (Duskwatch Shroud)
(109473, 0, 0, 0, 1, 0, 0, 0, 0, '203761 67236'), -- 109473 (Duskwatch Shroud) - Détecteur, Détection de l'invisibilité et du camouflage
(114958, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114958 (Duskwatch Subjugator)
(114961, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 114961 (Controller)
(109408, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 109408 (Lieutenant Piet)
(108386, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- 108386 (Ambrena)
(108345, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 108345 (Clotaire)
(114874, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114874 (Wyrmtongue Pilferer)
(108347, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 108347 (Ambrena)
(108810, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 108810 (Chloe)
(108346, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 108346 (Lunette)
(108405, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 108405 (Kal) - Ride Vehicle Hardcoded
(108411, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 108411 (Silgryn)
(108344, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 108344 (Donatien)
(114876, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Garde-courroux vengeur
(115806, 0, 0, 0, 1, 0, 0, 0, 0, '204227'), -- 115806 (Duskwatch Punisher) - Lame ensanglantée
(115216, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115216 (Duskwatch Veteran)
(114892, 0, 0, 0, 1, 0, 0, 0, 0, '56687'), -- Civil flétrissant - Conduire véhicule
(114889, 0, 0, 0, 1, 0, 0, 0, 0, '63316'), -- Civile shal’dorei - Conduire véhicule
(114888, 0, 0, 0, 1, 0, 0, 0, 0, '87782'), -- 114888 (Shal'dorei Civilian) - Ride Vehicle Seat 3 - JSB
(115627, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115627 (Frightened Refugee)
(115626, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115626 (Rebel Guardian)
(115628, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115628 (Refugee Child)
(115606, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115606 (Spell-Fencer Adept)
(115607, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115607 (Thoramir)
(107632, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Ly’leth Lunastre
(109447, 0, 0, 0, 1, 0, 0, 0, 0, '209901 209898'), -- 109447 (Lunastre Attendant) - Plateau - femme, Masque de serviteur
(115517, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Magus Sendath
(106897, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 106897 (Nighteyes)
(104821, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 104821 (Makeshift Ballista)
(104830, 0, 0, 0, 1, 0, 0, 0, 0, '144373'), -- 104830 (Makeshift Ballista) - RShwayder Test 02
(102410, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 102410 (Toryl)
(104550, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 104550 (Brytag)
(103611, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 103611 (Sashj'tar Overseer)
(103610, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 103610 (Sashj'tar Collier)
(103613, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 103613 (Sashj'tar Deep Witch)
(104586, 0, 0, 0, 1, 0, 0, 0, 0, '206905'), -- 104586 (Fjolrik) - Breuvage de marche-sous-l’eau
(104685, 0, 0, 262144, 1, 0, 0, 0, 0, '163090'), -- 104685 (Kell) - Feindre la mort permanent (ne peut être pisté) (ne peut être étourdi)
(102390, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 102390 (Toryl)
(102388, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 102388 (Toryl)
(102527, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 102527 (Toryl)
(100016, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100016 (Fjolrik)
(100017, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100017 (Stokalfr)
(102845, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 102845 (Brandolf)
(112226, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 112226 (Markus Hjolbruk)
(100015, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100015 (Katarine)
(102862, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 102862 (Trenchwalker Envoy)
(102841, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 102841 (Commander Malt'his)
(101144, 0, 0, 0, 1, 0, 0, 0, 0, '199473'), -- 101144 (Throndyr's Pyre Flame) - Flamme du bûcher de Throndyr
(102776, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 102776 (Stokalfr)
(102775, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 102775 (Fjolrik)
(102774, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 102774 (Katarine)
(102334, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 102334 (Brandolf)
(103239, 0, 0, 262144, 1, 0, 0, 0, 0, '163090'), -- 103239 (Jarl Throndyr) - Feindre la mort permanent (ne peut être pisté) (ne peut être étourdi)
(101131, 0, 0, 0, 1, 0, 0, 0, 0, '199459'), -- 101131 (Throndyr's Pyre) - Assistant du bûcher de Throndyr
(115724, 0, 0, 8, 1, 0, 0, 0, 0, '42459'), -- 115724 (Felborne Marauder) - Ambidextrie
(116119, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 116119 (Felborne Energist)
(99948, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 99948 (Toryl)
(117355, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 117355 (Torturer Relyn)
(111923, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111923 (Forgotten Wretch)
(113570, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113570 (Forgotten Thirster)
(116052, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 116052 (Ley Bunny)
(117412, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 117412 (Felborne Trapper)
(116116, 0, 67575, 0, 1, 0, 0, 0, 0, ''), -- 116116 (Felblade Protector)
(117246, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 117246 (Nighthuntress Syrenne)
(116115, 0, 0, 0, 1, 0, 0, 0, 0, '231772 84186'), -- 116115 (Scathing Felbeast) - Morsure pénétrante, Cosmetic - Sleep Zzz
(116117, 0, 0, 0, 1, 0, 0, 0, 0, '42459'), -- 116117 (Felborne Marauder) - Ambidextrie
(115691, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115691 (Felborne Magus)
(115690, 0, 0, 0, 1, 0, 0, 0, 0, '203761 67236'), -- 115690 (Felborne Energist) - Détecteur, Détection de l'invisibilité et du camouflage
(116068, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 116068 (Arm of the Magistrix)
(120459, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 120459 (Sha'leth)
(120454, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 120454 (Magicus)
(114879, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Golem d’animus
(114305, 0, 0, 0, 1, 0, 0, 0, 0, '54219'), -- 114305 (Nightborne Siegecaster) - Canalisation des Arcanes
(114301, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114301 (Nightborne Invader)
(114300, 0, 0, 0, 1, 0, 0, 0, 0, '54219'), -- 114300 (Imperial Arcanist) - Canalisation des Arcanes
(114303, 0, 0, 0, 1, 0, 0, 0, 0, '203886'), -- Assemblage cherche-sort - Sens arcaniques
(114302, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114302 (Mana Saber)
(114299, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114299 (Imperial Spellbreaker)
(114304, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 114304 (Nightborne Infiltrator)
(114306, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114306 (Ensorcelled Mana Wraith)
(114307, 0, 0, 0, 1, 0, 0, 0, 0, '182938'), -- 114307 (Imperial Conjurer) - Canalisation des Arcanes
(111606, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111606 (Moonfall Riding Hippogryph)
(111605, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111605 (Moonfall Riding Hippogryph)
(111604, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111604 (Moonfall Riding Hippogryph)
(102740, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 102740 (Moonfall Riding Hippogryph)
(102426, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 102426 (Beakbuck)
(111539, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 111539 (Kailea Windfeather)
(103348, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 103348 (Galar'thus Rivertree)
(107984, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Ragnvald Drake-Né
(113793, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val’kyr d’Odyn
(113794, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val’kyr d’Odyn
(113777, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val’kyr d’Odyn
(111774, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Matilda Skoptidottir
(107985, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Finna Bjornsdottir
(113268, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Valarjar forge-foudre
(124679, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 124679 (Dalaran Citizen)
(106095, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 106095 (Ivanel Meadowsong)
(103347, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 103347 (Nyellus Starweaver)
(112067, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 112067 (Volatile Leywraith)
(105956, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 105956 (Nightborne Eradicator)
(106049, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- 106049 (Nightborne Eradicator)

UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=59114; -- Generic Bunny
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=107712; -- 107712 (Verene)
UPDATE `creature_template_addon` SET `auras`='221101' WHERE `entry`=111056; -- 111056 (Tiny Illusory Dancer)
UPDATE `creature_template_addon` SET `bytes1`=8 WHERE `entry`=108811; -- 108811 (Audric)
UPDATE `creature_template_addon` SET `auras`='213486' WHERE `entry`=107727; -- 107727 (Legion Harbinger)
UPDATE `creature_template_addon` SET `auras`='145953' WHERE `entry`=113850; -- 113850 (Wyrmtongue Gorger)
UPDATE `creature_template_addon` SET `auras`='226562' WHERE `entry`=112150; -- Lapin à tout faire (JSB)
UPDATE `creature_template_addon` SET `bytes1`=5 WHERE `entry`=113840; -- 113840 (Shal'dorei Harpist)
UPDATE `creature_template_addon` SET `auras`='213486 67236' WHERE `entry`=107717; -- 107717 (Burning Chaplain)
UPDATE `creature_template_addon` SET `auras`='203761 67236' WHERE `entry`=115273; -- 115273 (Felborne Sorcerer)
UPDATE `creature_template_addon` SET `auras`='213486' WHERE `entry`=107720; -- 107720 (Felwing Doombringer)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=108495; -- 108495 (Outspoken Citizen)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=113752; -- 113752 (Shal'dorei Civilian)
UPDATE `creature_template_addon` SET `aiAnimKit`=1244 WHERE `entry`=115630; -- 115630 (Desperate Refugee)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=113738; -- 113738 (Duskwatch Moonmage)
UPDATE `creature_template_addon` SET `auras`='213486' WHERE `entry`=107521; -- 107521 (Legion Emissary)
UPDATE `creature_template_addon` SET `bytes1`=5 WHERE `entry`=113618; -- Loyaliste de Suramar
UPDATE `creature_template_addon` SET `bytes1`=3, `auras`='' WHERE `entry`=107451; -- 107451 (Shal'dorei Civilian)
UPDATE `creature_template_addon` SET `auras`='232234' WHERE `entry`=115594; -- 115594 (Duskwatch Adjudicator)
UPDATE `creature_template_addon` SET `auras`='203761 67236 232234' WHERE `entry`=115595; -- 115595 (Duskwatch Executor)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=101821; -- 101821 (Nightborne Warpcaster)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=101825; -- 101825 (Nightborne Enforcer)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='163090' WHERE `entry`=104600; -- 104600 (Sashj'tar Scaleflayer)
UPDATE `creature_template_addon` SET `auras`='224840' WHERE `entry`=68553; -- 68553 (SLG Generic MoP (Large AOI))
UPDATE `creature_template_addon` SET `aiAnimKit`=9829 WHERE `entry`=99563; -- 99563 (Fjolrik)
UPDATE `creature_template_addon` SET `auras`='204515' WHERE `entry`=100947; -- 100947 (Sashj'tar Reef Runner)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='213988' WHERE `entry`=111921; -- 111921 (Buried Exile)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='193723' WHERE `entry`=112972; -- Ecrabouilleur des fourrés géant
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=104404; -- 104404 (Thicket Hunter)
UPDATE `creature_template_addon` SET `bytes1`=0, `bytes2`=2, `auras`='' WHERE `entry`=100778; -- 100778 (Nightborne Trapper)
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=106609; -- 106609 (Adolescent Stormwing)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='145363' WHERE `entry`=112796; -- 112796 (Exiled Scavenger)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=108873; -- 108873 (Distillery Attendant)
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=106648; -- 106648 (Stormwing Drake)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=110043; -- 110043 (Heartwood Doe)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=110042; -- 110042 (Heartwood Stag)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=108869; -- Travailleur du vignoble
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=107296; -- 107296 (Suramar Aristocrat)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=108875; -- 108875 (Vineyard Enforcer)
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=105655; -- 105655 (Bound Vulture)
UPDATE `creature_template_addon` SET `auras`='203761 67236 155893' WHERE `entry`=113707; -- 113707 (Duskwatch Astralite)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=113818; -- 113818 (Glitterpool Chick)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=115926; -- Sentinelle de Darnassus
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=114931; -- Rebelle souffrenuit
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=115924; -- Magus garde de l’aube
UPDATE `creature_template_addon` SET `auras`='211187' WHERE `entry`=101774; -- 101774 (Moonfall Acolyte)
UPDATE `creature_template_addon` SET `auras`='211187' WHERE `entry`=111669; -- Adjurateur impérial
UPDATE `creature_template_addon` SET `auras`='211187' WHERE `entry`=111670; -- 111670 (Imperial Conjurer)
UPDATE `creature_template_addon` SET `auras`='211187' WHERE `entry`=101765; -- 101765 (Syrana Starweaver)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=106182; -- 106182 (Wounded Moonfall Defender)
UPDATE `creature_template_addon` SET `auras`='225291 152209' WHERE `entry`=113185; -- 113185 (Mana-Infused Bushtail)
UPDATE `creature_template_addon` SET `auras`='225291' WHERE `entry`=113126; -- 113126 (Meredil Lockjaw)
UPDATE `creature_template_addon` SET `auras`='167385' WHERE `entry`=114558; -- 114558 (Greater Sparring Partner)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=122130; -- 122130 (High Vindicator)
UPDATE `creature_template_addon` SET `auras`='187063' WHERE `entry`=41200; -- Generic Bunny - PRK
UPDATE `creature_template_addon` SET `auras`='60913' WHERE `entry`=93544; -- 93544 (Jang Quillpaw)
UPDATE `creature_template_addon` SET `auras`='46598' WHERE `entry`=121541; -- Ban Lu
UPDATE `creature_template_addon` SET `aiAnimKit`=0 WHERE `entry`=112720; -- 112720 (Jemma Wilson)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=116408; -- 116408 (Glowing Red Gem)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=116419; -- 116419 (Glowing Green Gem)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=96198; -- 96198 (Catriona Macrae)
UPDATE `creature_template_addon` SET `auras`='122729 123236' WHERE `entry`=62821; -- 62821 (Mystic Birdhat)
UPDATE `creature_template_addon` SET `auras`='122729 123240' WHERE `entry`=62822; -- 62822 (Cousin Slowhands)
UPDATE `creature_template_addon` SET `auras`='60913' WHERE `entry`=96778; -- 96778 (Aemara)
UPDATE `creature_template_addon` SET `auras`='183111' WHERE `entry`=104091; -- Gardien du Kirin Tor
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=104147; -- 104147 (Nightmarish Grizzly)
UPDATE `creature_template_addon` SET `auras`='203218' WHERE `entry`=101766; -- 101766 (Thalrenus Rivertree)
UPDATE `creature_template_addon` SET `bytes1`=3 WHERE `entry`=116675; -- 116675 (Defiant Feathermane Kitten)
UPDATE `creature_template_addon` SET `bytes1`=3, `auras`='55701' WHERE `entry`=103326; -- 103326 (Mana Saber)
UPDATE `creature_template_addon` SET `bytes1`=8, `bytes2`=0 WHERE `entry`=111599; -- 111599 (Nightborne Invader)
UPDATE `creature_template_addon` SET `auras`='54219' WHERE `entry`=111530; -- 111530 (Imperial Arcanist)
UPDATE `creature_template_addon` SET `auras`='152209' WHERE `entry`=112068; -- 112068 (Leyline Prowler)
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=102034; -- 102034 (Wild Moonfall Hippogryph)
UPDATE `creature_template_addon` SET `aiAnimKit`=0 WHERE `entry`=105405; -- 105405 (Petrified Nightsaber Cub)
UPDATE `creature_template_addon` SET `aiAnimKit`=0 WHERE `entry`=103816; -- 103816 (Petrified Nightsaber)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=104234; -- 104234 (Val'Sharah Refugee)
UPDATE `creature_template_addon` SET `bytes1`=3 WHERE `entry`=104235; -- 104235 (Val'Sharah Refugee)
UPDATE `creature_template_addon` SET `bytes1`=3 WHERE `entry`=104224; -- Grogneur de Suramar
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=103540; -- 103540 (Starclutch Screecher)
UPDATE `creature_template_addon` SET `bytes1`=0, `aiAnimKit`=11737 WHERE `entry`=112336; -- 112336 (Meredil Glider)

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (111599, 102739, 110050, 103805, 113850, 115606, 103540, 102738, 103616, 115381, 113190, 111530, 101783, 99075, 113195, 102415, 99502, 106048, 110415, 112068, 99070, 111045, 106609, 106837, 111618, 100889, 103534, 113619, 117412, 102242, 111527, 106032, 101784, 110043, 114474, 104242, 111871, 103518, 108096, 110042, 105645, 112444, 112825, 100890, 113571, 112067, 98213, 102747, 99899, 114472, 103326, 100947, 116117, 112392, 105723, 104404, 103639, 98555, 111612, 106055, 104576, 113679, 115691, 105232, 115806, 113606, 104638, 105480, 103529, 113201, 113618, 100999, 104224, 112796, 114470, 114897, 102960, 102796, 111445, 114931, 113184, 111921, 114849, 106648, 114480, 100778, 119077, 101688, 41200, 107521, 113680, 106654, 114865, 99506, 102551, 100888, 99770, 114874, 103610, 100891, 107333, 114845, 112331, 113570, 113634, 106047, 111446, 103804, 114468, 110870, 104877, 113707, 99749, 103575, 112370, 107449, 99893, 115216, 102575, 114995, 99304, 100100, 104220, 103631, 116715, 103929, 114876, 104454, 102819, 100949, 108871, 112336, 112301, 100948, 100950, 108875, 119437, 100945, 103527, 100237, 105014, 109782, 111872, 113633, 113738, 109023, 114927, 116063, 107717, 109199, 116116, 112827, 100998, 102913, 113198, 115924, 104837, 103126, 101773, 115926, 114929, 115517, 101772, 115279, 111389, 102828, 108942, 101774, 114866, 115690, 101771, 102660, 107567, 105644, 114926, 105655, 102748, 104810, 113854, 115526, 112545, 102746, 111870, 103645, 105650, 112972, 114924, 119907, 113102, 111376, 113765, 110726, 100946, 111197, 105759, 110438, 69759, 113268, 112543, 104829, 119436, 119438, 104845, 115700, 105956, 111619, 111621, 113096, 112334, 112910, 107720, 110944, 103808, 110727, 105564, 100635, 116068, 111923, 115595, 111620, 116206, 99755, 111869, 115607, 100777, 109055, 110418, 115273, 122130, 111056, 113126, 112441, 114880, 120454, 107994, 114718, 104359, 106349, 105332, 109473, 99793, 106049, 104226, 109950, 104459, 106275, 116716, 108148, 110354, 115594, 102495, 100780, 114879, 111675, 121411, 119396, 108129, 113185, 105656, 105653, 108628, 105640, 94180, 113205, 107483, 105339, 117355, 121414, 111622, 107727, 112140, 116119, 104821, 106263, 106262, 101825, 109954, 118678, 111007, 115724, 114958, 100864, 107772, 105481, 114946, 104147, 111050, 101821, 119226, 112948, 103092);
INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingDelta`, `VerifiedBuild`) VALUES
(111599, 0, 25996),
(102739, 0, 25996),
(110050, 0, 25996),
(103805, 0, 25996),
(113850, 0, 25996),
(115606, 0, 25996),
(103540, 0, 25996),
(102738, 0, 25996),
(103616, 0, 25996),
(115381, 0, 25996),
(113190, 0, 25996),
(111530, 0, 25996),
(101783, 0, 25996),
(99075, 0, 25996),
(113195, 0, 25996),
(102415, 0, 25996),
(99502, 0, 25996),
(106048, 0, 25996),
(110415, 0, 25996),
(112068, 0, 25996),
(99070, 0, 25996),
(111045, 0, 25996),
(106609, 0, 25996),
(106837, 0, 25996),
(111618, 0, 25996),
(100889, 0, 25996),
(103534, 0, 25996),
(113619, 0, 25996),
(117412, 0, 25996),
(102242, 0, 25996),
(111527, 0, 25996),
(106032, 0, 25996),
(101784, 0, 25996),
(110043, 0, 25996),
(114474, 0, 25996),
(104242, 0, 25996),
(111871, 0, 25996),
(103518, 0, 25996),
(108096, 0, 25996),
(110042, 0, 25996),
(105645, 0, 25996),
(112444, 0, 25996),
(112825, 0, 25996),
(100890, 0, 25996),
(113571, 0, 25996),
(112067, 0, 25996),
(98213, 0, 25996),
(102747, 0, 25996),
(99899, 0, 25996),
(114472, 0, 25996),
(103326, 0, 25996),
(100947, 0, 25996),
(116117, 0, 25996),
(112392, 0, 25996),
(105723, 0, 25996),
(104404, 0, 25996),
(103639, 0, 25996),
(98555, 0, 25996),
(111612, 0, 25996),
(106055, 0, 25996),
(104576, 0, 25996),
(113679, 0, 25996),
(115691, 0, 25996),
(105232, 0, 25996),
(115806, 0, 25996),
(113606, 0, 25996),
(104638, 0, 25996),
(105480, 0, 25996),
(103529, 0, 25996),
(113201, 0, 25996),
(113618, 0, 25996),
(100999, 0, 25996),
(104224, 0, 25996),
(112796, 0, 25996),
(114470, 0, 25996),
(114897, 0, 25996),
(102960, 0, 25996),
(102796, 0, 25996),
(111445, 0, 25996),
(114931, 0, 25996),
(113184, 0, 25996),
(111921, 0, 25996),
(114849, 0, 25996),
(106648, 0, 25996),
(114480, 0, 25996),
(100778, 0, 25996),
(119077, 0, 25996),
(101688, 0, 25996),
(41200, 0, 25996),
(107521, 0, 25996),
(113680, 0, 25996),
(106654, 0, 25996),
(114865, 0, 25996),
(99506, 0, 25996),
(102551, 0, 25996),
(100888, 0, 25996),
(99770, 0, 25996),
(114874, 0, 25996),
(103610, 0, 25996),
(100891, 0, 25996),
(107333, 0, 25996),
(114845, 0, 25996),
(112331, 0, 25996),
(113570, 0, 25996),
(113634, 0, 25996),
(106047, 0, 25996),
(111446, 0, 25996),
(103804, 0, 25996),
(114468, 0, 25996),
(110870, 0, 25996),
(104877, 0, 25996),
(113707, 0, 25996),
(99749, 0, 25996),
(103575, 0, 25996),
(112370, 0, 25996),
(107449, 0, 25996),
(99893, 0, 25996),
(115216, 0, 25996),
(102575, 0, 25996),
(114995, 0, 25996),
(99304, 0, 25996),
(100100, 0, 25996),
(104220, 0, 25996),
(103631, 0, 25996),
(116715, 0, 25996),
(103929, 0, 25996),
(114876, 0, 25996),
(104454, 0, 25996),
(102819, 0, 25996),
(100949, 0, 25996),
(108871, 0, 25996),
(112336, 0, 25996),
(112301, 0, 25996),
(100948, 0, 25996),
(100950, 0, 25996),
(108875, 0, 25996),
(119437, 0, 25996),
(100945, 0, 25996),
(103527, 0, 25996),
(100237, 0, 25996),
(105014, 0, 25996),
(109782, 0, 25996),
(111872, 0, 25996),
(113633, 0, 25996),
(113738, 0, 25996),
(109023, 0, 25996),
(114927, 0, 25996),
(116063, 0, 25996),
(107717, 0, 25996),
(109199, 0, 25996),
(116116, 0, 25996),
(112827, 0, 25996),
(100998, 0, 25996),
(102913, 0, 25996),
(113198, 0, 25996),
(115924, 0, 25996),
(104837, 0, 25996),
(103126, 0, 25996),
(101773, 0, 25996),
(115926, 0, 25996),
(114929, 0, 25996),
(115517, 0, 25996),
(101772, 0, 25996),
(115279, 0, 25996),
(111389, 0, 25996),
(102828, 0, 25996),
(108942, 0, 25996),
(101774, 0, 25996),
(114866, 0, 25996),
(115690, 0, 25996),
(101771, 0, 25996),
(102660, 0, 25996),
(107567, 0, 25996),
(105644, 0, 25996),
(114926, 0, 25996),
(105655, 0, 25996),
(102748, 0, 25996),
(104810, 0, 25996),
(113854, 0, 25996),
(115526, 0, 25996),
(112545, 0, 25996),
(102746, 0, 25996),
(111870, 0, 25996),
(103645, 0, 25996),
(105650, 0, 25996),
(112972, 0, 25996),
(114924, 0, 25996),
(119907, 0, 25996),
(113102, 0, 25996),
(111376, 0, 25996),
(113765, 0, 25996),
(110726, 0, 25996),
(100946, 0, 25996),
(111197, 0, 25996),
(105759, 0, 25996),
(110438, 0, 25996),
(69759, 0, 25996),
(113268, 0, 25996),
(112543, 0, 25996),
(104829, 0, 25996),
(119436, 0, 25996),
(119438, 0, 25996),
(104845, 0, 25996),
(115700, 0, 25996),
(105956, 0, 25996),
(111619, 0, 25996),
(111621, 0, 25996),
(113096, 0, 25996),
(112334, 0, 25996),
(112910, 0, 25996),
(107720, 0, 25996),
(110944, 0, 25996),
(103808, 0, 25996),
(110727, 0, 25996),
(105564, 0, 25996),
(100635, 0, 25996),
(116068, 0, 25996),
(111923, 0, 25996),
(115595, 0, 25996),
(111620, 0, 25996),
(116206, 0, 25996),
(99755, 0, 25996),
(111869, 0, 25996),
(115607, 0, 25996),
(100777, 0, 25996),
(109055, 1, 25996),
(110418, 0, 25996),
(115273, 0, 25996),
(122130, 0, 25996),
(111056, 0, 25996),
(113126, 0, 25996),
(112441, 0, 25996),
(114880, 0, 25996),
(120454, 0, 25996),
(107994, 0, 25996),
(114718, 0, 25996),
(104359, 0, 25996),
(106349, 0, 25996),
(105332, 0, 25996),
(109473, 0, 25996),
(99793, 0, 25996),
(106049, 0, 25996),
(104226, 0, 25996),
(109950, 0, 25996),
(104459, 0, 25996),
(106275, 0, 25996),
(116716, 0, 25996),
(108148, 0, 25996),
(110354, 0, 25996),
(115594, 0, 25996);

INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingDelta`, `VerifiedBuild`) VALUES
(102495, 0, 25996),
(100780, 0, 25996),
(114879, 0, 25996),
(111675, 0, 25996),
(121411, 0, 25996),
(119396, 0, 25996),
(108129, 0, 25996),
(113185, 0, 25996),
(105656, 0, 25996),
(105653, 0, 25996),
(108628, 0, 25996),
(105640, 0, 25996),
(94180, 0, 25996),
(113205, 0, 25996),
(107483, 0, 25996),
(105339, 0, 25996),
(117355, 0, 25996),
(121414, 0, 25996),
(111622, 0, 25996),
(107727, 0, 25996),
(112140, 0, 25996),
(116119, 0, 25996),
(104821, 0, 25996),
(106263, 0, 25996),
(106262, 0, 25996),
(101825, 0, 25996),
(109954, 0, 25996),
(118678, 0, 25996),
(111007, 0, 25996),
(115724, 0, 25996),
(114958, 0, 25996),
(100864, 0, 25996),
(107772, 0, 25996),
(105481, 0, 25996),
(114946, 0, 25996),
(104147, 0, 25996),
(111050, 0, 25996),
(101821, 0, 25996),
(119226, 0, 25996),
(112948, 0, 25996),
(103092, 0, 25996);



UPDATE `creature_model_info` SET `BoundingRadius`=0.383, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=47723;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71929;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2883655, `VerifiedBuild`=25996 WHERE `DisplayID`=73477;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27710;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73416;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=32028;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69990;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73646;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66258;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70172;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2015157, `VerifiedBuild`=25996 WHERE `DisplayID`=69607;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73414;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73518;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73517;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72972;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70173;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70250;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=38497;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66255;
UPDATE `creature_model_info` SET `CombatReach`=1.5 WHERE `DisplayID`=70082;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70924;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72004;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66592;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3, `VerifiedBuild`=25996 WHERE `DisplayID`=35312;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72003;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71712;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72841;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72840;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72842;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73954;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73519;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73516;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=62277;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2015157, `VerifiedBuild`=25996 WHERE `DisplayID`=69605;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71907;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73415;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73409;
UPDATE `creature_model_info` SET `BoundingRadius`=1.249467, `VerifiedBuild`=25996 WHERE `DisplayID`=19589;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69529;
UPDATE `creature_model_info` SET `BoundingRadius`=1.031494 WHERE `DisplayID`=64629;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71601;
UPDATE `creature_model_info` SET `CombatReach`=1.5 WHERE `DisplayID`=70078;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73644;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66265;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70139;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71959;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70140;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71026;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73501;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71028;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66573;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=64754;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=62719;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70015;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70137;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2883655, `VerifiedBuild`=25996 WHERE `DisplayID`=69608;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73645;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70044;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73643;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69667;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71988;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71989;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72002;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72001;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71793;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70013;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66568;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69665;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69666;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=26071;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=63336;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=26067;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70750;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69766;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=68617;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66112;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=63664;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=47928;
UPDATE `creature_model_info` SET `BoundingRadius`=1.073914, `VerifiedBuild`=25996 WHERE `DisplayID`=66908;
UPDATE `creature_model_info` SET `BoundingRadius`=1.649186, `VerifiedBuild`=25996 WHERE `DisplayID`=66907;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66812;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=32025;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=60916;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72971;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=68652;
UPDATE `creature_model_info` SET `BoundingRadius`=1.649186, `VerifiedBuild`=25996 WHERE `DisplayID`=68298;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7159426, `VerifiedBuild`=25996 WHERE `DisplayID`=67398;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=32250;
UPDATE `creature_model_info` SET `BoundingRadius`=1.431885, `VerifiedBuild`=25996 WHERE `DisplayID`=67815;
UPDATE `creature_model_info` SET `BoundingRadius`=1.649186, `VerifiedBuild`=25996 WHERE `DisplayID`=66894;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=68659;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=68227;
UPDATE `creature_model_info` SET `BoundingRadius`=2.198914, `VerifiedBuild`=25996 WHERE `DisplayID`=67813;
UPDATE `creature_model_info` SET `BoundingRadius`=1.073914, `VerifiedBuild`=25996 WHERE `DisplayID`=66892;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=33012;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67527;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67951;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=32572;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=32453;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=32124;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67755;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=36292;
UPDATE `creature_model_info` SET `BoundingRadius`=2.198914, `VerifiedBuild`=25996 WHERE `DisplayID`=67814;
UPDATE `creature_model_info` SET `BoundingRadius`=1.610871, `VerifiedBuild`=25996 WHERE `DisplayID`=67800;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65051;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72899;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=68595;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=33718;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=68602;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66813;
UPDATE `creature_model_info` SET `BoundingRadius`=1.649186, `VerifiedBuild`=25996 WHERE `DisplayID`=66893;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66235;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66234;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66763;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66761;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=32568;
UPDATE `creature_model_info` SET `BoundingRadius`=1.073914, `VerifiedBuild`=25996 WHERE `DisplayID`=66891;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25812;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66996;
UPDATE `creature_model_info` SET `BoundingRadius`=2.198914, `VerifiedBuild`=25996 WHERE `DisplayID`=68273;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=12198;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=32056;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66874;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66873;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25813;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67584;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25821;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66232;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66233;
UPDATE `creature_model_info` SET `BoundingRadius`=1.073914, `VerifiedBuild`=25996 WHERE `DisplayID`=66070;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66872;
UPDATE `creature_model_info` SET `BoundingRadius`=1.649186, `VerifiedBuild`=25996 WHERE `DisplayID`=66069;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66871;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67581;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66870;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=62862;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25818;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=6302;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66869;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67580;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70516;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66836;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66835;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67551;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69435;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70879;
UPDATE `creature_model_info` SET `BoundingRadius`=0.87234, `VerifiedBuild`=25996 WHERE `DisplayID`=70279;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=62591;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73940;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=59116;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70878;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70756;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73437;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70755;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=28435;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=74040;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70762;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71437;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70443;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70749;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70751;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70021;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70752;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70022;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70020;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70018;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66271;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73499;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9906794, `VerifiedBuild`=25996 WHERE `DisplayID`=37169;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73411;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=23482;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=42395;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=68661;
UPDATE `creature_model_info` SET `BoundingRadius`=2.084895, `VerifiedBuild`=25996 WHERE `DisplayID`=34653;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=2598;
UPDATE `creature_model_info` SET `BoundingRadius`=0.443447, `VerifiedBuild`=25996 WHERE `DisplayID`=2189;
UPDATE `creature_model_info` SET `BoundingRadius`=1.43469, `CombatReach`=2, `VerifiedBuild`=25996 WHERE `DisplayID`=47652;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67990;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69761;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67987;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69923;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71845;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69530;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70698;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67991;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71846;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66971;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66970;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66959;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72860;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66960;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3645831, `CombatReach`=1.575, `VerifiedBuild`=25996 WHERE `DisplayID`=72036;
UPDATE `creature_model_info` SET `CombatReach`=3, `VerifiedBuild`=25996 WHERE `DisplayID`=67158;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67923;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=251;
UPDATE `creature_model_info` SET `BoundingRadius`=0.383, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=47522;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69197;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65450;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=3585;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65356;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65371;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65424;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69150;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=11709;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1004;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66571;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67972;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71126;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67985;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66266;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70234;
UPDATE `creature_model_info` SET `BoundingRadius`=1.790547, `VerifiedBuild`=25996 WHERE `DisplayID`=68157;
UPDATE `creature_model_info` SET `BoundingRadius`=1.257362, `VerifiedBuild`=25996 WHERE `DisplayID`=46086;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66957;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67988;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67992;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66949;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66972;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66269;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66580;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66595;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66561;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66958;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66954;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=68083;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66261;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67986;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72885;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66590;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72883;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72887;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72652;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67633;
UPDATE `creature_model_info` SET `BoundingRadius`=0.58156, `VerifiedBuild`=25996 WHERE `DisplayID`=68063;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2942548, `VerifiedBuild`=25996 WHERE `DisplayID`=51830;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65959;


UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=25996 WHERE (`entry`=114527 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1); -- Poussière évanescente
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=25996 WHERE (`entry`=114527 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1); -- Coffret de calligraphie de virtuose
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=25996 WHERE (`entry`=114527 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1); -- Trousse de joaillier
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=25996 WHERE (`entry`=114527 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Marteau de forgeron
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=25996 WHERE (`entry`=114527 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Bâtonnet en cuivre
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=25996 WHERE (`entry`=114527 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Canne à pêche
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=25996 WHERE (`entry`=114527 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1); -- Bêche d'herboriste
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=25996 WHERE (`entry`=114527 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Couteau à dépecer
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=25996 WHERE (`entry`=114527 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Pioche de mineur
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=114527 AND `item`=138293 AND `ExtendedCost`=0 AND `type`=1); -- Sac d'explorateur
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=25996 WHERE (`entry`=114527 AND `item`=90146 AND `ExtendedCost`=0 AND `type`=1); -- Kit de bricoleur
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=25996 WHERE (`entry`=114527 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Bois simple
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=25996 WHERE (`entry`=114527 AND `item`=38682 AND `ExtendedCost`=0 AND `type`=1); -- Vélin d'enchantement
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=25996 WHERE (`entry`=114527 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Fiole de cristal
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=25996 WHERE (`entry`=114527 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1); -- Parchemin léger
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=25996 WHERE (`entry`=98548 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1); -- Parchemin léger
UPDATE `npc_vendor` SET `slot`=13, `maxcount`=3, `VerifiedBuild`=25996 WHERE (`entry`=98548 AND `item`=4364 AND `ExtendedCost`=0 AND `type`=1); -- Poudre d'explosion grossière
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=25996 WHERE (`entry`=98548 AND `item`=4357 AND `ExtendedCost`=0 AND `type`=1); -- Poudre d'explosion basique
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=25996 WHERE (`entry`=98548 AND `item`=10647 AND `ExtendedCost`=0 AND `type`=1); -- Encre d'ingénieur
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=25996 WHERE (`entry`=98548 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Catalyseur puissant
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=25996 WHERE (`entry`=98548 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Catalyseur léger
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=25996 WHERE (`entry`=98548 AND `item`=39684 AND `ExtendedCost`=0 AND `type`=1); -- Déclencheur sensible
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=25996 WHERE (`entry`=98548 AND `item`=40533 AND `ExtendedCost`=0 AND `type`=1); -- Crosse en noyer
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=98548 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Crosse lourde
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=25996 WHERE (`entry`=98548 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Crosse en bois
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=25996 WHERE (`entry`=98548 AND `item`=90146 AND `ExtendedCost`=0 AND `type`=1); -- Kit de bricoleur
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=25996 WHERE (`entry`=98548 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Pioche de mineur
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=25996 WHERE (`entry`=98548 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Marteau de forgeron
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=25996 WHERE (`entry`=98548 AND `item`=140324 AND `ExtendedCost`=0 AND `type`=1); -- Balise de télémancie mobile
UPDATE `npc_vendor` SET `slot`=22 WHERE (`entry`=32642 AND `item`=33449 AND `ExtendedCost`=0 AND `type`=1); -- Galette croustillante
UPDATE `npc_vendor` SET `slot`=22 WHERE (`entry`=32642 AND `item`=33449 AND `ExtendedCost`=0 AND `type`=1); -- Galette croustillante
UPDATE `npc_vendor` SET `slot`=22 WHERE (`entry`=32642 AND `item`=33449 AND `ExtendedCost`=0 AND `type`=1); -- Galette croustillante
UPDATE `npc_vendor` SET `slot`=22 WHERE (`entry`=32642 AND `item`=33449 AND `ExtendedCost`=0 AND `type`=1); -- Galette croustillante
UPDATE `npc_vendor` SET `slot`=22 WHERE (`entry`=32642 AND `item`=33449 AND `ExtendedCost`=0 AND `type`=1); -- Galette croustillante
UPDATE `npc_vendor` SET `slot`=22 WHERE (`entry`=32642 AND `item`=33449 AND `ExtendedCost`=0 AND `type`=1); -- Galette croustillante

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=108616 AND `ID`=1) OR (`CreatureID`=107997 AND `ID`=1) OR (`CreatureID`=111619 AND `ID`=1) OR (`CreatureID`=109473 AND `ID`=1) OR (`CreatureID`=114958 AND `ID`=1) OR (`CreatureID`=109408 AND `ID`=1) OR (`CreatureID`=108411 AND `ID`=1) OR (`CreatureID`=114876 AND `ID`=1) OR (`CreatureID`=115806 AND `ID`=1) OR (`CreatureID`=115216 AND `ID`=1) OR (`CreatureID`=115626 AND `ID`=1) OR (`CreatureID`=115606 AND `ID`=1) OR (`CreatureID`=115607 AND `ID`=1) OR (`CreatureID`=103610 AND `ID`=1) OR (`CreatureID`=100016 AND `ID`=1) OR (`CreatureID`=102841 AND `ID`=1) OR (`CreatureID`=102334 AND `ID`=1) OR (`CreatureID`=115724 AND `ID`=1) OR (`CreatureID`=116119 AND `ID`=1) OR (`CreatureID`=100948 AND `ID`=1) OR (`CreatureID`=117412 AND `ID`=1) OR (`CreatureID`=116116 AND `ID`=1) OR (`CreatureID`=117246 AND `ID`=1) OR (`CreatureID`=116117 AND `ID`=1) OR (`CreatureID`=115691 AND `ID`=1) OR (`CreatureID`=115690 AND `ID`=1) OR (`CreatureID`=114931 AND `ID`=1) OR (`CreatureID`=114305 AND `ID`=1) OR (`CreatureID`=114301 AND `ID`=1) OR (`CreatureID`=114300 AND `ID`=1) OR (`CreatureID`=114299 AND `ID`=1) OR (`CreatureID`=114304 AND `ID`=1) OR (`CreatureID`=114307 AND `ID`=1) OR (`CreatureID`=107984 AND `ID`=1) OR (`CreatureID`=113793 AND `ID`=1) OR (`CreatureID`=113794 AND `ID`=1) OR (`CreatureID`=113777 AND `ID`=1) OR (`CreatureID`=111774 AND `ID`=1) OR (`CreatureID`=107985 AND `ID`=1) OR (`CreatureID`=113268 AND `ID`=1) OR (`CreatureID`=105956 AND `ID`=1) OR (`CreatureID`=106049 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(108616, 1, 137256, 0, 0, 0, 0, 0, 0, 0, 0), -- Guard Morgaine
(107997, 1, 132170, 0, 0, 0, 0, 0, 0, 0, 0), -- Silgryn
(111619, 1, 132171, 0, 0, 0, 0, 0, 0, 0, 0), -- Duskwatch Shroud
(109473, 1, 132171, 0, 0, 0, 0, 0, 0, 0, 0), -- Duskwatch Shroud
(114958, 1, 143500, 0, 0, 0, 0, 0, 0, 0, 0), -- Duskwatch Subjugator
(109408, 1, 137254, 0, 0, 0, 0, 0, 0, 0, 0), -- Lieutenant Piet
(108411, 1, 132170, 0, 0, 0, 0, 0, 0, 0, 0), -- Silgryn
(114876, 1, 138422, 0, 0, 138422, 0, 0, 0, 0, 0), -- Garde-courroux vengeur
(115806, 1, 133178, 0, 0, 0, 0, 0, 0, 0, 0), -- Duskwatch Punisher
(115216, 1, 137254, 0, 0, 0, 0, 0, 0, 0, 0), -- Duskwatch Veteran
(115626, 1, 132170, 0, 0, 137253, 0, 0, 0, 0, 0), -- Rebel Guardian
(115606, 1, 132170, 0, 0, 0, 0, 0, 0, 0, 0), -- Spell-Fencer Adept
(115607, 1, 137256, 0, 0, 0, 0, 0, 0, 0, 0), -- Thoramir
(103610, 1, 1910, 0, 0, 0, 0, 0, 0, 0, 0), -- Sashj'tar Collier
(100016, 1, 5322, 0, 0, 0, 0, 0, 0, 0, 0), -- Fjolrik
(102841, 1, 54820, 0, 0, 0, 0, 0, 0, 0, 0), -- Commander Malt'his
(102334, 1, 37608, 0, 0, 40540, 0, 0, 0, 0, 0), -- Brandolf
(115724, 1, 137257, 0, 0, 137257, 0, 0, 0, 0, 0), -- Felborne Marauder
(116119, 1, 143591, 0, 0, 137260, 0, 0, 0, 0, 0), -- Felborne Energist
(100948, 1, 0, 0, 0, 0, 0, 0, 40759, 0, 0), -- Jandvik Bonepiercer
(117412, 1, 132170, 0, 0, 0, 0, 0, 73040, 0, 0), -- Felborne Trapper
(116116, 1, 142316, 0, 0, 137260, 0, 0, 0, 0, 0), -- Felblade Protector
(117246, 1, 137254, 0, 0, 0, 0, 0, 0, 0, 0), -- Nighthuntress Syrenne
(116117, 1, 137257, 0, 0, 137257, 0, 0, 0, 0, 0), -- Felborne Marauder
(115691, 1, 140089, 0, 0, 0, 0, 0, 0, 0, 0), -- Felborne Magus
(115690, 1, 143591, 0, 0, 137260, 0, 0, 0, 0, 0), -- Felborne Energist
(114931, 1, 34284, 0, 0, 27496, 0, 0, 0, 0, 0), -- Rebelle souffrenuit
(114305, 1, 132171, 0, 0, 0, 0, 0, 0, 0, 0), -- Nightborne Siegecaster
(114301, 1, 132170, 0, 0, 0, 0, 0, 0, 0, 0), -- Nightborne Invader
(114300, 1, 133174, 0, 0, 0, 0, 0, 0, 0, 0), -- Imperial Arcanist
(114299, 1, 132170, 0, 0, 132249, 0, 0, 0, 0, 0), -- Imperial Spellbreaker
(114304, 1, 132170, 0, 0, 132170, 0, 0, 0, 0, 0), -- Nightborne Infiltrator
(114307, 1, 133174, 0, 0, 0, 0, 0, 0, 0, 0), -- Imperial Conjurer
(107984, 1, 137176, 0, 0, 0, 0, 0, 0, 0, 0), -- Ragnvald Drake-Né
(113793, 1, 137262, 0, 0, 0, 0, 0, 0, 0, 0), -- Val’kyr d’Odyn
(113794, 1, 137262, 0, 0, 0, 0, 0, 0, 0, 0), -- Val’kyr d’Odyn
(113777, 1, 137262, 0, 0, 0, 0, 0, 0, 0, 0), -- Val’kyr d’Odyn
(111774, 1, 137262, 0, 0, 0, 0, 0, 0, 0, 0), -- Matilda Skoptidottir
(107985, 1, 140345, 0, 0, 140748, 0, 0, 0, 0, 0), -- Finna Bjornsdottir
(113268, 1, 137174, 0, 0, 137264, 0, 0, 0, 0, 0), -- Valarjar forge-foudre
(105956, 1, 132170, 0, 0, 133174, 0, 0, 0, 0, 0), -- Nightborne Eradicator
(106049, 1, 132170, 0, 0, 133174, 0, 0, 0, 0, 0); -- Nightborne Eradicator

UPDATE `creature_equip_template` SET `ItemID2`=109309, `ItemID3`=0 WHERE (`CreatureID`=99589 AND `ID`=1); -- Syana
UPDATE `creature_equip_template` SET `ItemID2`=133174, `ItemID3`=0 WHERE (`CreatureID`=109199 AND `ID`=1); -- Nightborne Tempomancer
UPDATE `creature_equip_template` SET `ItemID2`=137253, `ItemID3`=0 WHERE (`CreatureID`=107333 AND `ID`=1); -- Surveillant Durant
UPDATE `creature_equip_template` SET `ItemID2`=121793, `ItemID3`=0 WHERE (`CreatureID`=104829 AND `ID`=1); -- Sashj'tar Scaleguard
UPDATE `creature_equip_template` SET `ItemID2`=108780, `ItemID3`=0 WHERE (`CreatureID`=102551 AND `ID`=1); -- Jandvik Splintershield
UPDATE `creature_equip_template` SET `ItemID2`=108780, `ItemID3`=0 WHERE (`CreatureID`=100945 AND `ID`=1); -- Jandvik Splintershield
UPDATE `creature_equip_template` SET `ItemID2`=34816, `ItemID3`=0 WHERE (`CreatureID`=99544 AND `ID`=1); -- Brandolf
UPDATE `creature_equip_template` SET `ItemID3`=40759 WHERE (`CreatureID`=100891 AND `ID`=1); -- Jandvik Bonepiercer
UPDATE `creature_equip_template` SET `ItemID2`=108780, `ItemID3`=0 WHERE (`CreatureID`=100888 AND `ID`=1); -- Jandvik Splintershield
UPDATE `creature_equip_template` SET `ItemID3`=73040 WHERE (`CreatureID`=100778 AND `ID`=1); -- Nightborne Trapper
UPDATE `creature_equip_template` SET `ItemID2`=132170, `ItemID3`=0 WHERE (`CreatureID`=106275 AND `ID`=1); -- Commander Domitille
UPDATE `creature_equip_template` SET `ItemID2`=137266, `ItemID3`=0 WHERE (`CreatureID`=107484 AND `ID`=1); -- Greater Sparring Partner
UPDATE `creature_equip_template` SET `ItemID2`=137264, `ItemID3`=0 WHERE (`CreatureID`=107483 AND `ID`=1); -- Lesser Sparring Partner
UPDATE `creature_equip_template` SET `ItemID2`=137264, `ItemID3`=0 WHERE (`CreatureID`=114559 AND `ID`=1); -- Lesser Sparring Partner
UPDATE `creature_equip_template` SET `ItemID2`=137264, `ItemID3`=0 WHERE (`CreatureID`=96401 AND `ID`=1); -- Aspirant valarjar
UPDATE `creature_equip_template` SET `ItemID1`=121767, `ItemID2`=133367 WHERE (`CreatureID`=110437 AND `ID`=1); -- Haklang Ulfsson
UPDATE `creature_equip_template` SET `ItemID1`=30802, `ItemID2`=0 WHERE (`CreatureID`=122130 AND `ID`=1); -- High Vindicator
UPDATE `creature_equip_template` SET `ItemID2`=132249, `ItemID3`=0 WHERE (`CreatureID`=111527 AND `ID`=1); -- Imperial Spellbreaker
UPDATE `creature_equip_template` SET `ItemID2`=132170, `ItemID3`=0 WHERE (`CreatureID`=101784 AND `ID`=1); -- Nightborne Infiltrator

DELETE FROM `gossip_menu` WHERE (`MenuID`=19042 AND `TextID`=27820) OR (`MenuID`=18748 AND `TextID`=27380) OR (`MenuID`=19929 AND `TextID`=29607) OR (`MenuID`=19692 AND `TextID`=29185) OR (`MenuID`=19692 AND `TextID`=29184) OR (`MenuID`=19832 AND `TextID`=29442) OR (`MenuID`=19831 AND `TextID`=29441) OR (`MenuID`=19830 AND `TextID`=29440) OR (`MenuID`=19829 AND `TextID`=29439) OR (`MenuID`=19783 AND `TextID`=29308) OR (`MenuID`=19960 AND `TextID`=28198) OR (`MenuID`=19301 AND `TextID`=28397) OR (`MenuID`=19687 AND `TextID`=29172) OR (`MenuID`=6944 AND `TextID`=7778) OR (`MenuID`=20121 AND `TextID`=29914) OR (`MenuID`=20417 AND `TextID`=30524) OR (`MenuID`=19238 AND `TextID`=28244) OR (`MenuID`=18987 AND `TextID`=27720) OR (`MenuID`=18973 AND `TextID`=27706) OR (`MenuID`=19318 AND `TextID`=28438) OR (`MenuID`=20121 AND `TextID`=29913) OR (`MenuID`=20728 AND `TextID`=11093) OR (`MenuID`=19286 AND `TextID`=28360) OR (`MenuID`=19319 AND `TextID`=28442) OR (`MenuID`=20466 AND `TextID`=30627) OR (`MenuID`=18724 AND `TextID`=27208) OR (`MenuID`=18747 AND `TextID`=27251) OR (`MenuID`=20345 AND `TextID`=30434) OR (`MenuID`=18558 AND `TextID`=26867);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES
(19042, 27820), -- 100192 (Astoril)
(18748, 27380), -- 97140 (First Arcanist Thalyssra)
(19929, 29607), -- 113455 (Nightborne Wretch)
(19692, 29185), -- 107225 (Deline)
(19692, 29184), -- 107225 (Deline)
(19832, 29442), -- 108344 (Donatien)
(19831, 29441), -- 108345 (Clotaire)
(19830, 29440), -- 108347 (Ambrena)
(19829, 29439), -- 108346 (Lunette)
(19783, 29308), -- Ly’leth Lunastre
(19960, 28198), -- 98548 (Chief Telemancer Oculeth)
(19301, 28397), -- 103155 (Arcanist Valtrois)
(19687, 29172), -- 104618 (Theryn)
(6944, 7778), -- 114718 (Ancient Cloudwing)
(20121, 29914), -- 100775 (Lilryia Dawnwind)
(20417, 30524), -- 113680 (Naga Armaments)
(19238, 28244), -- 102388 (Toryl)
(18987, 27720), -- 99564 (Stokalfr)
(18973, 27706), -- 99563 (Fjolrik)
(19318, 28438), -- 99544 (Brandolf)
(20121, 29913), -- 100775 (Lilryia Dawnwind)
(20728, 11093), -- 101766 (Thalrenus Rivertree)
(19286, 28360), -- 101765 (Syrana Starweaver)
(19319, 28442), -- 101768 (Lothrius Mooncaller)
(20466, 30627), -- 102426 (Beakbuck)
(18724, 27208), -- 96679 (Aerylia)
(18747, 27251), -- 97389 (Eye of Odyn)
(20345, 30434), -- Matilda Skoptidottir
(18558, 26867); -- 90417 (Archmage Khadgar)

DELETE FROM `gossip_menu_option` WHERE (`MenuId`=19042 AND `OptionIndex`=0) OR (`MenuId`=18748 AND `OptionIndex`=4) OR (`MenuId`=18748 AND `OptionIndex`=1) OR (`MenuId`=19692 AND `OptionIndex`=0) OR (`MenuId`=19692 AND `OptionIndex`=1) OR (`MenuId`=19832 AND `OptionIndex`=0) OR (`MenuId`=19831 AND `OptionIndex`=0) OR (`MenuId`=19830 AND `OptionIndex`=0) OR (`MenuId`=19829 AND `OptionIndex`=0) OR (`MenuId`=19783 AND `OptionIndex`=0) OR (`MenuId`=20417 AND `OptionIndex`=0) OR (`MenuId`=19238 AND `OptionIndex`=0) OR (`MenuId`=18987 AND `OptionIndex`=0) OR (`MenuId`=18973 AND `OptionIndex`=0) OR (`MenuId`=20728 AND `OptionIndex`=0) OR (`MenuId`=18724 AND `OptionIndex`=8) OR (`MenuId`=18724 AND `OptionIndex`=7) OR (`MenuId`=18724 AND `OptionIndex`=6) OR (`MenuId`=18724 AND `OptionIndex`=5) OR (`MenuId`=18724 AND `OptionIndex`=4) OR (`MenuId`=18724 AND `OptionIndex`=3) OR (`MenuId`=18724 AND `OptionIndex`=2) OR (`MenuId`=20345 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`) VALUES
(19042, 0, 0, '"We shall drink of the Well again."', 101823),
(18748, 4, 0, '<Gain Ward of the First Arcanist for 50 |TINTERFACE\\ICONS\\INV_MISC_ANCIENT_MANA.BLP:20|t Ancient Mana.>', 121814),
(18748, 1, 0, '<Offer the Gift-Wrapped Arcwine Bottle.>', 115438),
(19692, 0, 0, 'I found a cask of wine!', 111355),
(19692, 1, 0, '<Show your Sigil.>', 111841), -- OptionBroadcastTextID: 111841 - 114966
(19832, 0, 0, '<Offer Mana Wine.>', 112433),
(19831, 0, 0, '<Offer Mana Wine.>', 112433),
(19830, 0, 0, '<Offer Mana Wine.>', 112433),
(19829, 0, 0, '<Offer Mana Wine.>', 112433),
(19783, 0, 0, 'You wished to speak to me?', 112392),
(20417, 0, 0, '<Imbue one of the tridents with 25 |TINTERFACE\\ICONS\\INV_MISC_ANCIENT_MANA.BLP:15|t Ancient Mana.>', 122513),
(19238, 0, 0, 'What''s going on here, Toryl?', 104639),
(18987, 0, 0, 'I am no naga, Stokalfr! I come on behalf of Brandolf!', 101383),
(18973, 0, 0, 'Try to rouse the vrykul.', 101337),
(20728, 0, 0, 'I am ready.', 101165), -- OptionBroadcastTextID: 35320 - 35539 - 39152 - 52091 - 52966 - 68157 - 72264 - 98694 - 101165 - 102817 - 104314 - 105294 - 105455 - 105611 - 106714 - 107434 - 108067 - 110410 - 114311 - 115011 - 120845 - 120867 - 120960 - 122483 - 130536 - 129525
(18724, 8, 0, 'The Broken Shore.', 130376),
(18724, 7, 0, 'Suramar.', 98628),
(18724, 6, 0, 'Highmountain.', 98627),
(18724, 5, 0, 'Val''sharah.', 98626),
(18724, 4, 0, 'Azsuna.', 98625),
(18724, 3, 0, 'Stormheim.', 98624),
(18724, 2, 0, 'Dalaran.', 98623),
(20345, 0, 28, 'Begin the Call', 122239);

UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=122365 WHERE (`MenuId`=19929 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=122365 WHERE (`MenuId`=19929 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=122365 WHERE (`MenuId`=19929 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=122365 WHERE (`MenuId`=19929 AND `OptionIndex`=1);





UPDATE `creature_template` SET `gossip_menu_id`=19042 WHERE `entry`=100192; -- Astoril
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2802, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536 WHERE `entry`=116715; -- Rebelle souffrenuit
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=113304; -- Suramar Orphan
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=112403; -- Spawn Bunny
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=111902; -- Suramar Refugee
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=111901; -- Suramar Refugee
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2884, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=116716; -- Nightborne Rebel
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111900; -- Rosaine
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108930; -- Nightborne Envoy
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=113630; -- Exasperated Child
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2823, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=108616; -- Guard Morgaine
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108063; -- Korine
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108466; -- Terrified Suramar Child
UPDATE `creature_template` SET `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=107473; -- Conveniently Placed Basket
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=107997; -- Silgryn
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=107613; -- Line Bunny
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2824, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=111619; -- Duskwatch Shroud
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2824, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=109473; -- Duskwatch Shroud
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2824, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114958; -- Duskwatch Subjugator
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=256, `unit_flags2`=67143680 WHERE `entry`=114961; -- Controller
UPDATE `creature_template` SET `gossip_menu_id`=19692, `speed_run`=1.142857 WHERE `entry`=107225; -- Deline
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=99589; -- Syana
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2821, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=109408; -- Lieutenant Piet
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=93979; -- Leyweaver Jorjana
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=99588; -- Tallian
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=109563; -- Sundries Merchant
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=114529; -- Anxious Trader
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=112058; -- Palu
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=99585; -- Feorias
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=107137; -- Nightborne Vintner
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108387; -- Donatien
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags3`=1 WHERE `entry`=107712; -- Verene
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108388; -- Clotaire
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=112063; -- Cornelius Crispin
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111056; -- Tiny Illusory Dancer
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=106797; -- Caline Starsoul
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111007; -- Randril
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111050; -- Drunken Reveler
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=34816 WHERE `entry`=108386; -- Ambrena
UPDATE `creature_template` SET `gossip_menu_id`=19831, `minlevel`=110, `maxlevel`=110, `faction`=2855, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=34816 WHERE `entry`=108345; -- Clotaire
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108811; -- Audric
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=109782; -- Arcanist Doralin
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111045; -- Drunken Reveler
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=109058; -- Palanquin Bearer
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=113455; -- Nightborne Wretch
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108385; -- Lunette
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags3`=8192 WHERE `entry`=114439; -- Shal'dorei Civilian
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=106926; -- Selin Sidoran
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2851, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114874; -- Wyrmtongue Pilferer
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=114528; -- Nervous Vendor
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=113515; -- Maribeth
UPDATE `creature_template` SET `gossip_menu_id`=19830, `minlevel`=110, `maxlevel`=110, `faction`=2855, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=34816 WHERE `entry`=108347; -- Ambrena
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=108810; -- Chloe
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108809; -- Emille
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108807; -- Eneas
UPDATE `creature_template` SET `gossip_menu_id`=19829, `minlevel`=110, `maxlevel`=110, `faction`=2855, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=34816 WHERE `entry`=108346; -- Lunette
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108808; -- Brigitte
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags2`=2048 WHERE `entry`=107598; -- Vanthir
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `speed_run`=0.8571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=108405; -- Kal
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=107467; -- Jacin
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048, `VehicleId`=4820 WHERE `entry`=108411; -- Silgryn
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags2`=0 WHERE `entry`=113516; -- Dasdonia
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=113514; -- Joshen Lafave
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=107601; -- Afflicted Citizen
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=107606; -- Nightborne Child
UPDATE `creature_template` SET `gossip_menu_id`=19832, `minlevel`=110, `maxlevel`=110, `faction`=2855, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=34816 WHERE `entry`=108344; -- Donatien
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=107604; -- Afflicted Citizen
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108812; -- Iseult
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2851, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114876; -- Garde-courroux vengeur
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2821, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags2`=2048 WHERE `entry`=115806; -- Duskwatch Punisher
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=106080; -- Nightborne Child
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111445; -- Loyaliste de Suramar
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=106055; -- Suramar Loyalist
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=107727; -- Legion Harbinger
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=112555; -- Flameweaver Ovin
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=110419; -- Grapple Point
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=114530; -- Concerned Merchant
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=107717; -- Burning Chaplain
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=109199; -- Nightborne Tempomancer
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=107720; -- Felwing Doombringer
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2883, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115216; -- Duskwatch Veteran
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=102747; -- Tamed Owl
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=113457; -- Nightborne Wretch
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=110356; -- Grapple Point
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108495; -- Outspoken Citizen
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=114470; -- Duskwatch Orbitist
UPDATE `creature_template` SET `unit_flags`=33024, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=113752; -- Shal'dorei Civilian
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=106617; -- Nightborne Child
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=107333; -- Surveillant Durant
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33587456, `unit_flags2`=2048 WHERE `entry`=114892; -- Civil flétrissant
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587456, `unit_flags2`=2048 WHERE `entry`=114889; -- Civile shal’dorei
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587456, `unit_flags2`=2048 WHERE `entry`=114888; -- Shal'dorei Civilian
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=109048; -- Arcane Engineer
UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry`=115630; -- Desperate Refugee
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=106616; -- Nightborne Child
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=114468; -- Duskwatch Orbitist
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=102496; -- Shal'dorei Servant
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=110334; -- Grapple Point
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108496; -- Outspoken Citizen
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=107521; -- Legion Emissary
UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry`=115696; -- Desperate Refugee
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=109654; -- Grapple Point
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=113449; -- Nightborne Wretch
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=115627; -- Frightened Refugee
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2884, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags2`=2048 WHERE `entry`=115626; -- Rebel Guardian
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=115628; -- Refugee Child
UPDATE `creature_template` SET `unit_flags`=33024, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=107451; -- Shal'dorei Civilian
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=112213; -- Huddled Vagrant
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=109562; -- Sundries Merchant
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111622; -- Arcane Chronomaton
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108096; -- Duskwatch Scion
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2823, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115606; -- Spell-Fencer Adept
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2823, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115607; -- Thoramir
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=113629; -- Exasperated Child
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108622; -- Withering Suramar Citizen
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=114549; -- Withering Suramar Citizen
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108068; -- Accused Suramar Citizen
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108070; -- Accused Suramar Citizen
UPDATE `creature_template` SET `gossip_menu_id`=19783, `minlevel`=110, `maxlevel`=110, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=107632; -- Ly’leth Lunastre
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=109447; -- Lunastre Attendant
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=105481; -- Oll'ison
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111446; -- Duskwatch Battlemaster
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2361, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33024, `unit_flags2`=33572864 WHERE `entry`=115517; -- Magus Sendath
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=101821; -- Nightborne Warpcaster
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=101825; -- Nightborne Enforcer
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=106897; -- Nighteyes
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=100237; -- Leyline Hunter
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111872; -- Leyline Researcher
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=103929; -- Sashj'tar Wave Breaker
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048, `VehicleId`=4698 WHERE `entry`=104821; -- Makeshift Ballista
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=104359; -- Tidemistress Sashj'tar
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=104829; -- Sashj'tar Scaleguard
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=190, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=104830; -- Makeshift Ballista
UPDATE `creature_template` SET `npcflag`=16777216, `unit_flags3`=1 WHERE `entry`=100179; -- Willbreaker Incubator
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=100999; -- Sashj'tar Siren
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2809, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=102410; -- Toryl
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2809, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=104550; -- Brytag
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=74, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=18876416 WHERE `entry`=103611; -- Sashj'tar Overseer
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2205, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=103610; -- Sashj'tar Collier
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2205, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=103613; -- Sashj'tar Deep Witch
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=100998; -- Sashj'tar Myrmidon
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=104459; -- Seawarden Largush
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2811, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=104586; -- Fjolrik
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2809, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536903680, `unit_flags2`=34817, `unit_flags3`=8192 WHERE `entry`=104685; -- Kell
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2809, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=2099200 WHERE `entry`=102390; -- Toryl
UPDATE `creature_template` SET `gossip_menu_id`=19238, `minlevel`=110, `maxlevel`=110, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=102388; -- Toryl
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags2`=2048 WHERE `entry`=102527; -- Toryl
UPDATE `creature_template` SET `unit_flags3`=8192 WHERE `entry`=100953; -- Jandvik Splintershield
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2811, `speed_run`=1.142857, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768 WHERE `entry`=100016; -- Fjolrik
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2811, `npcflag`=4227, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024 WHERE `entry`=100017; -- Stokalfr
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2811, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=102845; -- Brandolf
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2811, `npcflag`=66177, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=112226; -- Markus Hjolbruk
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2811, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024 WHERE `entry`=100015; -- Katarine
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111178; -- Gardécaille sashj’tar
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=103645; -- Sashj'tar Tidecaller
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=102844; -- Commander Kel'tariss
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags`=536871680, `unit_flags3`=8192 WHERE `entry`=104600; -- Sashj'tar Scaleflayer
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=102913; -- Sashj'tar Enforcer
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=102840; -- Commander Raz'jira
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=99770; -- Sashj'tar Deep Witch
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=103502; -- Empowered Globule
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=102685; -- Sashj'tar Overseer
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=99304; -- Trenchwalker Scavenger
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=74, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=16779264 WHERE `entry`=102862; -- Trenchwalker Envoy
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=74, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=102841; -- Commander Malt'his
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=102796; -- Siren Naz'jul
UPDATE `creature_template` SET `unit_flags3`=8192 WHERE `entry`=103216; -- Jandvik Splintershield
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags3`=8192 WHERE `entry`=103219; -- Axetail Basilisk
UPDATE `creature_template` SET `gossip_menu_id`=20417 WHERE `entry`=113680; -- Naga Armaments
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=100100; -- Axetail Basilisk
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=100949; -- Sashj'tar Lancer
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=100950; -- Sashj'tar Enchantress
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=103518; -- Barbed Puffer
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=104454; -- Trenchwalker Guardian
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=102828; -- Sashj'tar Sandcrusher
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67110912 WHERE `entry`=101144; -- Throndyr's Pyre Flame
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2811, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=102776; -- Stokalfr
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2811, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=102775; -- Fjolrik
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2811, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=102774; -- Katarine
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags3`=8192 WHERE `entry`=100962; -- Sashj'tar Lancer
UPDATE `creature_template` SET `gossip_menu_id`=18987 WHERE `entry`=99564; -- Stokalfr
UPDATE `creature_template` SET `gossip_menu_id`=18973 WHERE `entry`=99563; -- Fjolrik
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=103211; -- Injured Vrykul
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags3`=8192 WHERE `entry`=100963; -- Sashj'tar Enchantress
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=99562; -- Katarine
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2811, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=34816 WHERE `entry`=102334; -- Brandolf
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536903680, `unit_flags2`=34817, `unit_flags3`=8192 WHERE `entry`=103239; -- Jarl Throndyr
UPDATE `creature_template` SET `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=512, `unit_flags2`=67110912 WHERE `entry`=101131; -- Throndyr's Pyre
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=103575; -- Seigneur du récif Raj’his
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2823, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115724; -- Felborne Marauder
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2824, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=116119; -- Felborne Energist
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=99948; -- Toryl
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=100946; -- Jandvik Runecaller
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=100947; -- Sashj'tar Reef Runner
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=99070; -- Sashj'tar Reef Runner
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=99075; -- Sashj'tar Stormcaller
UPDATE `creature_template` SET `unit_flags3`=8192 WHERE `entry`=99559; -- Jarl Throndyr
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags3`=8192 WHERE `entry`=103474; -- Sashj'tar Diviner
UPDATE `creature_template` SET `faction`=14, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=63420; -- SLG Generic MoP
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags3`=8192 WHERE `entry`=99637; -- Sashj'tar Reef Runner
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=100890; -- Jandvik Ripfang
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=100889; -- Jandvik Runecaller
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=102309; -- Toryl
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111869; -- Leyline Hunter
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111871; -- Leyline Researcher
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags3`=1 WHERE `entry`=114718; -- Ancient Cloudwing
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=100780; -- Trapper Rodoon
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=100777; -- Nighteyes
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=110253; -- Rôdeur plumelune
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=2823, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=117355; -- Torturer Relyn
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=110726; -- Cadraeus
UPDATE `creature_template` SET `gossip_menu_id`=20121 WHERE `entry`=100775; -- Lilryia Dawnwind
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=1692, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=111923; -- Forgotten Wretch
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=1692, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113570; -- Forgotten Thirster
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=33556480, `unit_flags3`=1 WHERE `entry`=116052; -- Ley Bunny
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=111921; -- Buried Exile
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=113198; -- Trapped Thicket Hunter
UPDATE `creature_template` SET `unit_flags`=570721024, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=112972; -- Ecrabouilleur des fourrés géant
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=104404; -- Thicket Hunter
UPDATE `creature_template` SET `faction`=2883, `speed_run`=1.142857 WHERE `entry`=100778; -- Nightborne Trapper
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2883, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=117412; -- Felborne Trapper
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=113201; -- Thicket Manahunter
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2823, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=116116; -- Felblade Protector
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=35, `npcflag`=2, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33536, `unit_flags2`=2099200 WHERE `entry`=117246; -- Nighthuntress Syrenne
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags`=537166592, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=112796; -- Exiled Scavenger
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2824, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=116115; -- Scathing Felbeast
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2823, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=116117; -- Felborne Marauder
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2824, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115691; -- Felborne Magus
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2824, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115690; -- Felborne Energist
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108873; -- Distillery Attendant
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2821, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=116068; -- Arm of the Magistrix
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108877; -- Sacheverell Leburque
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=110043; -- Heartwood Doe
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=110042; -- Heartwood Stag
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108869; -- Travailleur du vignoble
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108943; -- Domestique du vignoble
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=107296; -- Suramar Aristocrat
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108875; -- Vineyard Enforcer
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=107600; -- Shal'dorei Civilian
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=107603; -- Shal'dorei Civilian
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108871; -- Gardien du vignoble
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=103631; -- Confined Lion
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=112059; -- Sasunne Dameuse
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=112064; -- Dolse Shimmersong
UPDATE `creature_template` SET `minlevel`=101, `maxlevel`=101, `faction`=35, `npcflag`=129, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=120459; -- Sha'leth
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=1620, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=120454; -- Magicus
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=105656; -- Bound Makrura
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=105644; -- Penned 'Monohorn'
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=113484; -- Menagerie Shopkeeper
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=1933, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=320, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=114879; -- Golem d’animus
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=113818; -- Glitterpool Chick
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=114841; -- Dame Liadrin
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=114883; -- Grand Magister Rommath
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=115684; -- Garde-paix du Kirin Tor
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=115498; -- Lothrius Mooncaller
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=102575; -- Conjurer Thalerian
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2831, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114305; -- Nightborne Siegecaster
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2823, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114301; -- Nightborne Invader
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2831, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114300; -- Imperial Arcanist
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2831, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=114303; -- Assemblage cherche-sort
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2831, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114302; -- Mana Saber
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2823, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114299; -- Imperial Spellbreaker
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2823, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114304; -- Nightborne Infiltrator
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2831, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114306; -- Ensorcelled Mana Wraith
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2831, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114307; -- Imperial Conjurer
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=16777218, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=111606; -- Moonfall Riding Hippogryph
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=101774; -- Moonfall Acolyte
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags`=33536, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=111669; -- Adjurateur impérial
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags`=33536, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=111670; -- Imperial Conjurer
UPDATE `creature_template` SET `npcflag`=0, `unit_flags3`=1 WHERE `entry`=101765; -- Syrana Starweaver
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=16777218, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=111605; -- Moonfall Riding Hippogryph
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags3`=1 WHERE `entry`=106349; -- Damaged Spell Seeker Construct
UPDATE `creature_template` SET `gossip_menu_id`=19319, `npcflag`=3, `unit_flags3`=1 WHERE `entry`=101768; -- Lothrius Mooncaller
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=110438; -- Maître de siège Aedrin
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=0, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=111604; -- Moonfall Riding Hippogryph
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=106275; -- Commander Domitille
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=0, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=102740; -- Moonfall Riding Hippogryph
UPDATE `creature_template` SET `gossip_menu_id`=20466, `minlevel`=110, `maxlevel`=110, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=33654784, `VehicleId`=4994 WHERE `entry`=102426; -- Beakbuck
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=102243; -- Assemblage cherche-sort
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=111539; -- Kailea Windfeather
UPDATE `creature_template` SET `unit_flags3`=8192 WHERE `entry`=102030; -- Kailea Windfeather
UPDATE `creature_template` SET `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=113574; -- Portal to Suramar City
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=103348; -- Galar'thus Rivertree
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=110, `faction`=1665, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=107984; -- Ragnvald Drake-Né
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33536, `unit_flags2`=18432, `HoverHeight`=2.8 WHERE `entry`=113793; -- Val’kyr d’Odyn
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33536, `unit_flags2`=18432, `HoverHeight`=2.8 WHERE `entry`=113794; -- Val’kyr d’Odyn
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33536, `unit_flags2`=18432, `HoverHeight`=2.8 WHERE `entry`=113777; -- Val’kyr d’Odyn
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags3`=1 WHERE `entry`=107484; -- Greater Sparring Partner
UPDATE `creature_template` SET `minlevel`=98, `unit_flags3`=1 WHERE `entry`=107483; -- Lesser Sparring Partner
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=106459; -- Capitaine Hjalmar Stahlstrom
UPDATE `creature_template` SET `gossip_menu_id`=20345, `minlevel`=100, `maxlevel`=100, `npcflag`=1168231104515, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33536, `unit_flags2`=18432, `HoverHeight`=4 WHERE `entry`=111774; -- Matilda Skoptidottir
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=107994; -- Einar the Runecaster
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=112392; -- Quartermaster Durnolf
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=110, `faction`=1665, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `HoverHeight`=3 WHERE `entry`=107985; -- Finna Bjornsdottir
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `speed_walk`=1.2, `speed_run`=0.7142857, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=113268; -- Valarjar forge-foudre
UPDATE `creature_template` SET `gossip_menu_id`=18724 WHERE `entry`=96679; -- Aerylia
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=110437; -- Haklang Ulfsson
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=90418; -- Archmage Modera
UPDATE `creature_template` SET `minlevel`=104, `maxlevel`=107 WHERE `entry`=105904; -- Raven
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=96813; -- Aludane Whitecloud
UPDATE `creature_template` SET `minlevel`=105, `maxlevel`=105, `faction`=2007, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=124679; -- Dalaran Citizen
UPDATE `creature_template` SET `minlevel`=106, `maxlevel`=106 WHERE `entry`=96635; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=109, `maxlevel`=109 WHERE `entry`=96636; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=109, `maxlevel`=109 WHERE `entry`=96592; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=104, `maxlevel`=104 WHERE `entry`=96639; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=106, `maxlevel`=106 WHERE `entry`=96643; -- Stabled Hunter Pet
UPDATE `creature_template` SET `unit_flags3`=8192 WHERE `entry`=102031; -- Galar'thus Rivertree
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=101780; -- Moonfall Hippogryph
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2828, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33536 WHERE `entry`=106095; -- Ivanel Meadowsong
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=103347; -- Nyellus Starweaver
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=102242; -- Imperial Conjurer
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags3`=8192 WHERE `entry`=102024; -- Moonfall Hippogryph
UPDATE `creature_template` SET `unit_flags3`=8192 WHERE `entry`=102029; -- Nyellus Starweaver
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=112067; -- Volatile Leywraith
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=112334; -- Frenzied Riverbug
UPDATE `creature_template` SET `npcflag`=2, `unit_flags2`=33587200, `unit_flags3`=1 WHERE `entry`=101766; -- Thalrenus Rivertree
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=2824, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=105956; -- Nightborne Eradicator
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=2824, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=106049; -- Nightborne Eradicator
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=98213; -- Herbalist Tharillon
UPDATE `creature_template` SET `unit_flags3`=8192 WHERE `entry`=102027; -- Moonfall Acolyte
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags3`=8192 WHERE `entry`=106047; -- Nightborne Eradicator
UPDATE `creature_template` SET `unit_flags3`=8192 WHERE `entry`=102025; -- Moonfall Defender
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111527; -- Imperial Spellbreaker
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags`=32768 WHERE `entry`=103326; -- Mana Saber
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111599; -- Nightborne Invader
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111530; -- Imperial Arcanist
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=112068; -- Leyline Prowler
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags`=32768 WHERE `entry`=102034; -- Wild Moonfall Hippogryph
UPDATE `creature_template` SET `faction`=2831, `speed_run`=1.142857, `unit_flags`=32768 WHERE `entry`=101783; -- Nightborne Siegecaster
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=103808; -- Managazer
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=101784; -- Nightborne Infiltrator
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags3`=8192 WHERE `entry`=106048; -- Nightborne Eradicator
UPDATE `creature_template` SET `unit_flags`=67141632 WHERE `entry`=99793; -- Leyscale Manalisk
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=94180; -- Sho'hallan
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=105405; -- Petrified Nightsaber Cub
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=104226; -- Gloomfang
UPDATE `creature_template` SET `HoverHeight`=2.8 WHERE `entry`=93819; -- Val’kyr d’Odyn
UPDATE `creature_template` SET `gossip_menu_id`=6944 WHERE `entry`=111675; -- Ancient Cloudwing
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=103155; -- Arcanist Valtrois
UPDATE `creature_template` SET `npcflag`=65667 WHERE `entry`=97140; -- First Arcanist Thalyssra

SET @GROUP_ID := 0;
SET @ID := 0;

REPLACE INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(32642, @GROUP_ID+0, @ID+0, 'Dis bad mojo what you doin''. Don''t say Mojodishu didn''t warn ya!', 12, 0, 100, 1, 0, 0, 33028, 'Mojodishu to Player'),
(32642, @GROUP_ID+1, @ID+0, 'Really, mon? Just like dat you be leavin'' Mojodishu behind?', 12, 0, 100, 1, 0, 0, 33027, 'Mojodishu to Player'),
(32642, @GROUP_ID+2, @ID+0, 'Be dat way den!', 12, 0, 100, 1, 0, 0, 33029, 'Mojodishu to Player'),
(97140, @GROUP_ID+0, @ID+0, 'A gift, for me?', 12, 0, 100, 0, 0, 67591, 113328, 'First Arcanist Thalyssra to Player'),
(97140, @GROUP_ID+1, @ID+0, 'Thalyssra smiles warmly.', 16, 0, 100, 0, 0, 0, 115439, 'First Arcanist Thalyssra to Player'),
(97140, @GROUP_ID+2, @ID+0, 'I will see that it is not wasted. Well done, my friend.', 12, 0, 100, 0, 0, 67590, 115440, 'First Arcanist Thalyssra to Player'),
(98548, @GROUP_ID+0, @ID+0, 'Ahh, thank you.', 12, 0, 100, 0, 0, 71457, 121587, 'Chief Telemancer Oculeth to Player'),
(99070, @GROUP_ID+0, @ID+0, 'Jandvik is oursss.', 12, 0, 100, 61, 0, 0, 105275, 'Sashj''tar Reef Runner to Player'),
(99070, @GROUP_ID+1, @ID+0, 'For the Tidemistress...', 12, 0, 100, 0, 0, 0, 105279, 'Sashj''tar Reef Runner to Player'),
(99070, @GROUP_ID+2, @ID+0, 'Black abyss...', 12, 0, 100, 0, 0, 0, 105283, 'Sashj''tar Reef Runner to Player'),
(99070, @GROUP_ID+3, @ID+0, 'The Sashj''tar will stand victoriousss.', 12, 0, 100, 61, 0, 0, 104964, 'Sashj''tar Reef Runner to Player'),
(99070, @GROUP_ID+4, @ID+0, 'The sea callsss me home...', 12, 0, 100, 15, 0, 0, 105281, 'Sashj''tar Reef Runner to Player'),
(99070, @GROUP_ID+5, @ID+0, 'The Tidemistress will stain Jandvik with vrykul blood.', 12, 0, 100, 0, 0, 0, 104965, 'Sashj''tar Reef Runner to Player'),
(99070, @GROUP_ID+6, @ID+0, 'You cannot stop usss!', 12, 0, 100, 0, 0, 0, 105276, 'Sashj''tar Reef Runner to Player'),
(99070, @GROUP_ID+7, @ID+0, 'I will gut you like a fish.', 12, 0, 100, 15, 0, 0, 105274, 'Sashj''tar Reef Runner to Player'),
(99070, @GROUP_ID+8, @ID+0, 'Death to our enemiesss!', 12, 0, 100, 0, 0, 0, 105277, 'Sashj''tar Reef Runner to Player'),
(99070, @GROUP_ID+9, @ID+0, 'Sashj''tar do not take prisonersss.', 12, 0, 100, 15, 0, 68513, 104961, 'Sashj''tar Reef Runner to Player'),
(99075, @GROUP_ID+0, @ID+0, 'The Sashj''tar will wash over Jandvik like the tide upon the ssshore.', 12, 0, 100, 0, 0, 0, 104971, 'Sashj''tar Stormcaller to Player'),
(99075, @GROUP_ID+1, @ID+0, 'I will ssslay you.', 12, 0, 100, 0, 0, 0, 104960, 'Sashj''tar Stormcaller to Player'),
(99075, @GROUP_ID+2, @ID+0, 'Jandvik will fall to the Sashj''tar.', 12, 0, 100, 0, 0, 0, 104963, 'Sashj''tar Stormcaller to Player'),
(99075, @GROUP_ID+3, @ID+0, 'Sashj''tar do not take prisoners.', 12, 0, 100, 0, 0, 0, 104967, 'Sashj''tar Stormcaller to Player'),
(99304, @GROUP_ID+0, @ID+0, 'I honor the Tidemistress.', 12, 0, 100, 0, 0, 0, 104986, 'Trenchwalker Scavenger to Player'),
(99304, @GROUP_ID+1, @ID+0, 'I return to the sea...', 12, 0, 100, 0, 0, 0, 104988, 'Trenchwalker Scavenger to Player'),
(99544, @GROUP_ID+0, @ID+0, 'Find wood to construct a pyre. I will take care of moving his body.', 12, 0, 100, 0, 0, 0, 105974, 'Brandolf to Player'),
(99562, @GROUP_ID+0, @ID+0, 'I see that you are no ally to these naga, $r! Get me out of this cage!', 12, 0, 100, 0, 0, 0, 105168, 'Katarine to Player'),
(99562, @GROUP_ID+1, @ID+0, 'I must find Jarl Throndyr!', 12, 0, 100, 0, 0, 0, 105169, 'Katarine to Player'),
(99563, @GROUP_ID+0, @ID+0, 'Why did you kick me, you mongrel of Fenrir?', 12, 0, 100, 0, 0, 0, 101718, 'Fjolrik to Player'),
(99563, @GROUP_ID+1, @ID+0, 'You are no naga! Where is Brandolf?', 12, 0, 100, 0, 0, 0, 105170, 'Fjolrik to Player'),
(99564, @GROUP_ID+0, @ID+0, 'Come closer if you want to die, naga!', 14, 0, 100, 0, 0, 0, 101365, 'Stokalfr to Player'),
(99564, @GROUP_ID+1, @ID+0, 'Brandolf''s alive! I must go to him!', 12, 0, 100, 0, 0, 0, 105171, 'Stokalfr to Player'),
(99770, @GROUP_ID+0, @ID+0, 'Ssslay the intruder!', 12, 0, 100, 0, 0, 0, 105811, 'Sashj''tar Deep Witch to Player'),
(99770, @GROUP_ID+1, @ID+0, 'I will cut you into eel food!', 12, 0, 100, 0, 0, 68512, 105808, 'Sashj''tar Deep Witch to Player'),
(99770, @GROUP_ID+2, @ID+0, 'You cannot stop the Tidemistresss...', 12, 0, 100, 0, 0, 0, 105815, 'Sashj''tar Deep Witch to Player'),
(99770, @GROUP_ID+3, @ID+0, 'I will ssslay you in the name of the Tidemistress!', 12, 0, 100, 0, 0, 0, 105805, 'Sashj''tar Deep Witch to Player'),
(99825, @GROUP_ID+0, @ID+0, 'They were going to eat me!', 12, 0, 100, 0, 0, 0, 106019, 'Captured Vrykul to Player'), -- BroadcastTextID: 79786 - 106019
(99825, @GROUP_ID+1, @ID+0, 'I despise the sea!', 12, 0, 100, 0, 0, 0, 106015, 'Captured Vrykul to Player'),
(99825, @GROUP_ID+2, @ID+0, 'Gratitude stranger.', 12, 0, 100, 0, 0, 0, 106014, 'Captured Vrykul to Player'),
(99948, @GROUP_ID+0, @ID+0, 'Kinsmen of Jandvik! Calder and Eynar have fallen in combat. They were not worthy to lead Jandvik.', 14, 0, 100, 0, 0, 0, 104569, 'Toryl to Player'),
(99948, @GROUP_ID+1, @ID+0, 'As the last remaining successor, it falls on me to lead our people against the invading Sashj''tar naga!', 14, 0, 100, 0, 0, 0, 104570, 'Toryl to Player'),
(99948, @GROUP_ID+2, @ID+0, 'This outsider is under my aegis. Those that show aggression against $ghim:her; will answer to me.', 14, 0, 100, 0, 0, 0, 104571, 'Toryl to Player'),
(99948, @GROUP_ID+3, @ID+0, 'Without me, Jandvik will stand no chance in this battle. Come quickly!', 12, 0, 100, 0, 0, 0, 105994, 'Toryl to Player'),
(100777, @GROUP_ID+0, @ID+0, 'Nighteyes hoots at you in a grateful tone.', 16, 0, 100, 0, 0, 0, 103174, 'Nighteyes to Player'),
(100864, @GROUP_ID+0, @ID+0, 'Vile... ssslime...', 12, 0, 100, 0, 0, 0, 105883, 'Cora''kar to Player'),
(100888, @GROUP_ID+0, @ID+0, 'By my blade!', 12, 0, 100, 15, 0, 0, 105245, 'Jandvik Splintershield to Player'),
(100888, @GROUP_ID+1, @ID+0, 'By your hand, I meet my end...', 12, 0, 100, 0, 0, 0, 105250, 'Jandvik Splintershield to Player'),
(100888, @GROUP_ID+2, @ID+0, '$R are not welcome here!', 12, 0, 100, 15, 0, 0, 104830, 'Jandvik Splintershield to Player'),
(100888, @GROUP_ID+3, @ID+0, 'Val''kyr take me!', 12, 0, 100, 0, 0, 0, 104831, 'Jandvik Splintershield to Player'),
(100889, @GROUP_ID+0, @ID+0, 'I will cast you down!', 12, 0, 100, 0, 0, 0, 104835, 'Jandvik Runecaller to Player'),
(100889, @GROUP_ID+1, @ID+0, 'Judgment awaits...', 12, 0, 100, 0, 0, 0, 105252, 'Jandvik Runecaller to Player'),
(100949, @GROUP_ID+0, @ID+0, 'The sssilence of the deep...', 12, 0, 100, 0, 0, 0, 105280, 'Sashj''tar Lancer to Player'),
(101765, @GROUP_ID+0, @ID+0, 'There!', 12, 0, 100, 0, 0, 66358, 129805, 'Syrana Starweaver to Player'),
(101765, @GROUP_ID+1, @ID+0, 'Lothrius'' magic called to me. He must still be alive! Quickly- you can help us rejoin the others.', 12, 0, 100, 0, 0, 66359, 109666, 'Syrana Starweaver to Player'),
(101765, @GROUP_ID+2, @ID+0, 'We will move when the way is clear. Your bravery is worth more than you know, friend.', 12, 0, 100, 0, 0, 66357, 109667, 'Syrana Starweaver to Player'),
(101765, @GROUP_ID+3, @ID+0, 'It is Nightborne magic... but it called to us.', 12, 0, 100, 0, 0, 0, 120199, 'Syrana Starweaver to Player'),
(101766, @GROUP_ID+0, @ID+0, 'Thank you for that welcome distraction.', 12, 0, 100, 2, 0, 66367, 108941, 'Thalrenus Rivertree to Player'),
(101766, @GROUP_ID+1, @ID+0, 'I will take this opportunity to lay traps for the intruders. I am certain we will meet again!', 12, 0, 100, 2, 0, 66367, 117046, 'Thalrenus Rivertree to Player'),
(101766, @GROUP_ID+2, @ID+0, 'We meet again! Lothrius and Syrana have just informed me of your deeds.', 12, 0, 100, 1, 0, 66387, 117107, 'Thalrenus Rivertree to Player'),
(101766, @GROUP_ID+3, @ID+0, 'They will be upon us shortly. I can teleport us somewhere safe.', 12, 0, 100, 1, 0, 66388, 117145, 'Thalrenus Rivertree to Player'),
(101766, @GROUP_ID+4, @ID+0, 'Here we go!', 12, 0, 100, 603, 0, 66389, 118556, 'Thalrenus Rivertree to Player'), -- BroadcastTextID: 35296 - 60088 - 87308 - 118556
(101766, @GROUP_ID+5, @ID+0, 'I detected a strange signal coming from this place.', 12, 0, 100, 603, 0, 0, 120198, 'Thalrenus Rivertree to Player'),
(101767, @GROUP_ID+0, @ID+0, 'I didn''t make it in time...', 12, 0, 100, 0, 0, 0, 105980, 'Lyrea Windfeather to Player'),
(101767, @GROUP_ID+1, @ID+0, 'Do not come back for us. We are already doomed by the Nightborne''s betrayal.', 12, 0, 100, 0, 0, 0, 109645, 'Lyrea Windfeather to Player'),
(101768, @GROUP_ID+0, @ID+0, 'Sometimes I forget how talented Serena is. Welcome, as it were. It is high time we dealt with these intruders.', 12, 0, 100, 603, 0, 68991, 109661, 'Lothrius Mooncaller to Player'),
(101768, @GROUP_ID+1, @ID+0, 'Manafiend!', 12, 0, 100, 0, 0, 66255, 117035, 'Lothrius Mooncaller to Imperial Spellbreaker'),
(101768, @GROUP_ID+2, @ID+0, 'Be wary, my friend- their constructs do not seem at all effected by my runes.', 12, 0, 100, 1, 0, 68992, 109405, 'Lothrius Mooncaller to Player'),
(101768, @GROUP_ID+3, @ID+0, 'You found them! I will have them properly preserved and sent somewhere safe immediately.', 12, 0, 100, 603, 0, 66257, 117056, 'Lothrius Mooncaller to Player'),
(101768, @GROUP_ID+4, @ID+0, 'I have laid out a safe path for you. Touching the crystals will summon my guardians to you. Make good use of it and go swiftly!', 12, 0, 100, 603, 0, 66264, 109664, 'Lothrius Mooncaller to Player'),
(101768, @GROUP_ID+5, @ID+0, 'We have also decided that it is time to leave this place.', 12, 0, 100, 1, 0, 66386, 117109, 'Lothrius Mooncaller to Player'),
(101768, @GROUP_ID+6, @ID+0, 'Come. I see an opening in the rock.', 12, 0, 100, 1, 0, 0, 120200, 'Lothrius Mooncaller to Player'),
(101783, @GROUP_ID+0, @ID+0, 'Arash-falas...', 12, 0, 100, 0, 0, 66018, 116791, 'Nightborne Siegecaster to Player'), -- BroadcastTextID: 102165 - 116431 - 116760 - 116771 - 116781 - 116791
(101783, @GROUP_ID+1, @ID+0, 'The shal''dorei will rule this world!', 12, 0, 100, 0, 0, 66019, 116430, 'Nightborne Siegecaster to Player'), -- BroadcastTextID: 102164 - 116430
(101783, @GROUP_ID+2, @ID+0, 'We are chosen to rule!', 12, 0, 100, 0, 0, 66025, 116693, 'Nightborne Siegecaster to Player'), -- BroadcastTextID: 116679 - 116693
(101783, @GROUP_ID+3, @ID+0, 'Our magic will break you!', 12, 0, 100, 0, 0, 66022, 116704, 'Nightborne Siegecaster to Player'), -- BroadcastTextID: 100930 - 116704
(101783, @GROUP_ID+4, @ID+0, 'How DARE you!!', 12, 0, 100, 0, 0, 0, 109129, 'Nightborne Siegecaster to Player'),
(101783, @GROUP_ID+5, @ID+0, 'My eyes!', 12, 0, 100, 0, 0, 68513, 109131, 'Nightborne Siegecaster to Player'),
(101784, @GROUP_ID+0, @ID+0, 'Lowborn scum!', 12, 0, 100, 0, 0, 65666, 116685, 'Nightborne Infiltrator to Player'), -- BroadcastTextID: 116685 - 116699
(101784, @GROUP_ID+1, @ID+0, 'No mercy for outlanders!', 12, 0, 100, 0, 0, 65869, 116680, 'Nightborne Infiltrator to Player'), -- BroadcastTextID: 116680 - 116694
(101784, @GROUP_ID+2, @ID+0, 'I cannot lose to a lowborn!', 12, 0, 100, 0, 0, 65857, 116756, 'Nightborne Infiltrator to Player'), -- BroadcastTextID: 116756 - 116787
(101784, @GROUP_ID+3, @ID+0, 'Agh!', 12, 0, 100, 0, 0, 0, 109120, 'Nightborne Infiltrator to Player'), -- BroadcastTextID: 19526 - 109120 - 115114
(101784, @GROUP_ID+4, @ID+0, 'What is this filth?!', 12, 0, 100, 0, 0, 0, 105984, 'Nightborne Infiltrator to Player'),
(101784, @GROUP_ID+5, @ID+0, 'What is the meaning of this?!', 12, 0, 100, 0, 0, 0, 105985, 'Nightborne Infiltrator to Player'), -- BroadcastTextID: 15487 - 51666 - 93643 - 105985
(102034, @GROUP_ID+0, @ID+0, 'Wild Moonfall Hippogryph claws defiantly at the air and remains unmoved.', 16, 0, 100, 377, 0, 0, 109644, 'Wild Moonfall Hippogryph to Player'),
(102309, @GROUP_ID+0, @ID+0, 'I warn you, my kin do not like outsiders. You would be wise to avoid unnecessary confrontation.', 12, 0, 100, 0, 0, 0, 104672, 'Toryl to Player'),
(102309, @GROUP_ID+1, @ID+0, 'Calder is a headstrong fool...', 14, 0, 100, 0, 0, 0, 105263, 'Toryl to Toryl'),
(102334, @GROUP_ID+0, @ID+0, 'May your soul find its way to Valhalas.', 12, 0, 100, 0, 0, 0, 105681, 'Brandolf to Player'),
(102334, @GROUP_ID+1, @ID+0, 'Hail Jarl Throndyr!', 12, 0, 100, 66, 0, 0, 105685, 'Brandolf to Player'), -- BroadcastTextID: 105682 - 105684 - 105685
(102381, @GROUP_ID+0, @ID+0, 'Come $n! I will fight by your side as we cut a bloody swath into these naga!', 12, 0, 100, 0, 0, 0, 105173, 'Brandolf to Player'),
(102381, @GROUP_ID+1, @ID+0, 'For Jandvik!', 14, 0, 100, 0, 0, 0, 104920, 'Brandolf to Player'),
(102381, @GROUP_ID+2, @ID+0, 'Let us slay these serpents, $n!', 14, 0, 100, 15, 0, 0, 104922, 'Brandolf to Player'),
(102381, @GROUP_ID+3, @ID+0, 'Share my strength, $n!', 14, 0, 100, 15, 0, 68513, 104924, 'Brandolf to Player'),
(102381, @GROUP_ID+4, @ID+0, 'For Throndyr!', 14, 0, 100, 0, 0, 0, 104919, 'Brandolf to Player'), -- BroadcastTextID: 104919 - 105739
(102381, @GROUP_ID+5, @ID+0, 'Fight for Jandvik, $n!', 14, 0, 100, 15, 0, 0, 104923, 'Brandolf to Player'),
(102381, @GROUP_ID+6, @ID+0, 'I must return to Jandvik.', 12, 0, 100, 0, 0, 0, 105241, 'Brandolf to Player'),
(102388, @GROUP_ID+0, @ID+0, 'I ssshould thank you for doing my dirty work, $n. But now you are proving too troublesome to keep alive.', 12, 0, 100, 0, 0, 0, 105966, 'Toryl to Player'),
(102388, @GROUP_ID+1, @ID+0, 'You will die in the name of the Sashj''tar!', 12, 0, 100, 0, 0, 0, 101739, 'Tidemistress Sashj''tar to Player'),
(102388, @GROUP_ID+2, @ID+0, 'Without its leaders, I will easily destroy Jandvik from within!', 12, 0, 100, 0, 0, 0, 105967, 'Tidemistress Sashj''tar'),
(102388, @GROUP_ID+3, @ID+0, 'My naga will wash over Jandvik in a tidal wave of destruction!', 12, 0, 100, 0, 0, 0, 105968, 'Tidemistress Sashj''tar'),
(102388, @GROUP_ID+4, @ID+0, 'Enough!', 12, 0, 100, 0, 0, 0, 121025, 'Tidemistress Sashj''tar'), -- BroadcastTextID: 7381 - 42297 - 53980 - 121025
(102388, @GROUP_ID+5, @ID+0, 'You will never ssstop usss. Jandvik will fall!', 12, 0, 100, 1, 0, 0, 106795, 'Tidemistress Sashj''tar'),
(102410, @GROUP_ID+0, @ID+0, 'Citizens of Jandvik! Gather round the fire and hear the glorious news!', 14, 0, 100, 1, 0, 0, 105614, 'Toryl to Player'),
(102410, @GROUP_ID+1, @ID+0, 'We have lost much at the hands of the Sashj''tar. Calder, Eynar, and Jarl Throndyr have all fallen to their treachery.', 14, 0, 100, 1, 0, 0, 105618, 'Toryl to Player'),
(102410, @GROUP_ID+2, @ID+0, 'Hail the glorious dead!', 14, 0, 100, 1, 0, 0, 105626, 'Toryl to Player'),
(102410, @GROUP_ID+3, @ID+0, 'We all owe Jandvik''s salvation to one brave $c. Glory to $n! Slayer of Tidemistress Sashj''tar!', 14, 0, 100, 1, 0, 0, 105620, 'Toryl to Player'),
(102410, @GROUP_ID+4, @ID+0, 'As sole remaining elder of Jandvik, it is my duty to lead Jandvik into prosperity.', 14, 0, 100, 1, 0, 0, 105621, 'Toryl to Player'),
(102410, @GROUP_ID+5, @ID+0, 'For this, I proclaim that $n is the new Jarl of Jandvik. All hail $n!', 14, 0, 100, 1, 0, 0, 105622, 'Toryl to Player'),
(102425, @GROUP_ID+0, @ID+0, 'We need to - Beakbuck, no!', 12, 0, 100, 0, 0, 0, 109646, 'Serena Windfeather to Player'),
(102425, @GROUP_ID+1, @ID+0, 'Ignore him. I need you to find Lothrius. We were separated in the attack- I think he is still holding out at the Athenaeum.', 12, 0, 100, 2, 0, 0, 109650, 'Serena Windfeather to Player'),
(102425, @GROUP_ID+2, @ID+0, 'Thanks for everything, Beakbuck. I hope we meet again.', 12, 0, 100, 2, 0, 0, 109149, 'Serena Windfeather to Player'),
(102425, @GROUP_ID+3, @ID+0, 'Don''t worry about me. Just focus on finding Lothrius.', 12, 0, 100, 1, 0, 0, 109150, 'Serena Windfeather to Player'),
(102426, @GROUP_ID+0, @ID+0, 'Beakbuck turns and charges toward you!', 16, 0, 100, 0, 0, 0, 109647, 'Beakbuck to Player'),
(102527, @GROUP_ID+0, @ID+0, 'Watch out! This is an imposter!', 14, 0, 100, 0, 0, 0, 105468, 'Toryl to Player'),
(102527, @GROUP_ID+1, @ID+0, 'Jandvik will never fall to your vile naga! Never!', 14, 0, 100, 0, 0, 0, 105469, 'Toryl to Player'),
(102527, @GROUP_ID+2, @ID+0, 'Get me out of this cage!', 14, 0, 100, 0, 0, 0, 105389, 'Toryl to Player'),
(102685, @GROUP_ID+0, @ID+0, 'I smash you!', 12, 0, 100, 0, 0, 0, 105056, 'Sashj''tar Overseer to Player'),
(102685, @GROUP_ID+1, @ID+0, 'Little pest.', 12, 0, 100, 0, 0, 0, 105358, 'Sashj''tar Overseer to Player'),
(102685, @GROUP_ID+2, @ID+0, 'Little weakling...', 12, 0, 100, 0, 0, 0, 105066, 'Sashj''tar Overseer to Player'),
(102685, @GROUP_ID+3, @ID+0, 'Sashj''tar survive...', 12, 0, 100, 0, 0, 0, 105364, 'Sashj''tar Overseer to Player'),
(102738, @GROUP_ID+0, @ID+0, 'Beaten... by a weakling... like you...', 12, 0, 100, 0, 0, 0, 104678, 'Calder to Player'),
(102739, @GROUP_ID+0, @ID+0, 'A puny outsider challenges me?', 12, 0, 100, 0, 0, 0, 104898, 'Eynar to Player'),
(102739, @GROUP_ID+1, @ID+0, 'I will see you... in Helheim...', 12, 0, 100, 0, 0, 0, 104679, 'Eynar to Player'),
(102796, @GROUP_ID+0, @ID+0, 'Tidemistress... I have failed you...', 12, 0, 100, 0, 0, 0, 105344, 'Siren Naz''jul to Player'),
(102828, @GROUP_ID+0, @ID+0, 'Tidemistress...', 12, 0, 100, 0, 0, 0, 105062, 'Sashj''tar Sandcrusher to Player'),
(102828, @GROUP_ID+1, @ID+0, 'Sashj''tar destroy you!', 12, 0, 100, 0, 0, 68512, 105060, 'Sashj''tar Sandcrusher to Finna Bjornsdottir'),
(102828, @GROUP_ID+2, @ID+0, 'Too... strong...', 12, 0, 100, 0, 0, 0, 105367, 'Sashj''tar Sandcrusher to Player'), -- BroadcastTextID: 60269 - 105367
(102840, @GROUP_ID+0, @ID+0, 'We have uninvited guestsss.', 12, 0, 100, 0, 0, 0, 105270, 'Commander Raz''jira to Player'),
(102840, @GROUP_ID+1, @ID+0, 'Jandvik will be oursss...', 12, 0, 100, 0, 0, 0, 105271, 'Commander Raz''jira to Player'),
(102841, @GROUP_ID+0, @ID+0, 'What''s thisss? A trespasser intrudesss on our conversation.', 12, 0, 100, 0, 0, 68513, 105268, 'Commander Malt''his to Player'),
(102841, @GROUP_ID+1, @ID+0, 'We mussst inform the Tidemistressss...', 12, 0, 100, 0, 0, 0, 105269, 'Commander Malt''his to Player'),
(102844, @GROUP_ID+0, @ID+0, 'What''s thisss?', 12, 0, 100, 0, 0, 0, 105272, 'Commander Kel''tariss to Player'),
(102844, @GROUP_ID+1, @ID+0, 'My death stopsss nothing...', 12, 0, 100, 0, 0, 0, 105273, 'Commander Kel''tariss to Player'),
(103092, @GROUP_ID+0, @ID+0, 'Gather ''round and witness mystical wonders like you''ve never seen before!', 12, 0, 100, 1, 0, 61693, 105636, 'The Great Akazamzarak'),
(103111, @GROUP_ID+0, @ID+0, 'Hail Jarl $n! Hail!', 14, 0, 100, 66, 0, 0, 105627, 'Jandvik Splintershield to Player'),
(103122, @GROUP_ID+0, @ID+0, 'Hail the fallen!', 14, 0, 100, 0, 0, 0, 105629, 'Jandvik Runecaller to Player'),
(103122, @GROUP_ID+1, @ID+0, 'Hail $n! Savior of Jandvik!', 14, 0, 100, 0, 0, 0, 105630, 'Jandvik Runecaller to Player'),
(103126, @GROUP_ID+0, @ID+0, 'Destroy the $c!', 14, 0, 100, 0, 0, 0, 105651, 'Jandvik Splintershield to Player'),
(103126, @GROUP_ID+1, @ID+0, 'I don''t trust her.', 12, 0, 100, 0, 0, 0, 105661, 'Jandvik Splintershield to Player'),
(103126, @GROUP_ID+2, @ID+0, 'Something foul is afoot.', 12, 0, 100, 0, 0, 0, 105663, 'Jandvik Splintershield to Player'),
(103127, @GROUP_ID+0, @ID+0, 'A $r!', 14, 0, 100, 0, 0, 0, 105650, 'Jandvik Runecaller to Player'),
(103129, @GROUP_ID+0, @ID+0, 'The Moon Guard are no more. There is no saving our beloved Stronghold.', 12, 0, 100, 1, 0, 66384, 117110, 'Syrana Starweaver to Player'),
(103207, @GROUP_ID+0, @ID+0, 'Death to the Sashj''tar!', 12, 0, 100, 0, 0, 0, 105870, 'Injured Vrykul to Cora''kar'),
(103211, @GROUP_ID+0, @ID+0, 'Now''s our chance!', 12, 0, 100, 0, 0, 0, 105871, 'Injured Vrykul to Cora''kar'),
(103211, @GROUP_ID+1, @ID+0, 'Gratitude, stranger.', 12, 0, 100, 0, 0, 0, 105888, 'Injured Vrykul to Player'),
(103212, @GROUP_ID+0, @ID+0, 'Kill the naga!', 12, 0, 100, 0, 0, 0, 105872, 'Injured Vrykul to Cora''kar'),
(103347, @GROUP_ID+0, @ID+0, 'I could not protect them all...', 12, 0, 100, 603, 0, 0, 105978, 'Nyellus Starweaver to Player'),
(103348, @GROUP_ID+0, @ID+0, 'The Guard is no more.', 12, 0, 100, 457, 0, 0, 105979, 'Galar''thus Rivertree to Player'),
(103529, @GROUP_ID+0, @ID+0, 'Where... what...', 12, 0, 100, 0, 0, 0, 106882, 'Possessed Vrykul to Player'),
(103529, @GROUP_ID+1, @ID+0, 'Can''t breathe...', 12, 0, 100, 0, 0, 0, 106881, 'Possessed Vrykul to Player'),
(103529, @GROUP_ID+2, @ID+0, 'Stupid squid!', 12, 0, 100, 0, 0, 0, 106883, 'Possessed Vrykul to Player'),
(103529, @GROUP_ID+3, @ID+0, 'Curse these naga!', 12, 0, 100, 0, 0, 0, 106887, 'Possessed Vrykul to Player'),
(103546, @GROUP_ID+0, @ID+0, 'Redhoof carefully digs into the soil with a hoof.', 16, 0, 100, 0, 0, 0, 108537, 'Redhoof the Ancient to Player'),
(103546, @GROUP_ID+1, @ID+0, 'Redhoof peers at Mythandros expectantly.', 16, 0, 100, 0, 0, 0, 119989, 'Redhoof the Ancient to Player'),
(103568, @GROUP_ID+0, @ID+0, 'It is done!', 12, 0, 100, 4, 0, 0, 86779, 'Mayruna Moonwing to Player'), -- BroadcastTextID: 20937 - 54686 - 86779
(103569, @GROUP_ID+0, @ID+0, 'Fresh green food grows and your enemies are fewer. We seek only your blessing in return.', 12, 0, 100, 0, 0, 0, 108539, 'Mythandros Irongrove to Player'),
(103569, @GROUP_ID+1, @ID+0, 'What is this...?', 12, 0, 100, 0, 0, 0, 111018, 'Mythandros Irongrove to Player'), -- BroadcastTextID: 79588 - 111018
(103569, @GROUP_ID+2, @ID+0, 'Oh my, a rare bloom indeed.', 12, 0, 100, 0, 0, 0, 119990, 'Mythandros Irongrove to Player'),
(103569, @GROUP_ID+3, @ID+0, 'Thank you, noble Redhoof. We accept your blessing and give our thanks.', 12, 0, 100, 0, 0, 0, 119991, 'Mythandros Irongrove to Player'),
(103569, @GROUP_ID+4, @ID+0, 'This moonwell will nourish and protect everything around it. We can finally call this place home.', 12, 0, 100, 2, 0, 0, 120016, 'Mythandros Irongrove to Player'),
(103570, @GROUP_ID+0, @ID+0, 'Thank you.', 12, 0, 100, 2, 0, 0, 111252, 'Mardranel Forestheart to Player'), -- BroadcastTextID: 4590 - 13214 - 38169 - 64352 - 77983 - 98217 - 111252 - 111253 - 115479 - 115661 - 119221 - 119622 - 131567
(103571, @GROUP_ID+0, @ID+0, 'Our efforts were not in vain. The Moonwhisper Matriarch watches from afar.', 12, 0, 100, 0, 0, 0, 108550, 'Solendra Featherdown to Player'),
(103571, @GROUP_ID+1, @ID+0, 'I will bring the blessing to Mythandros directly. See you there!', 12, 0, 100, 0, 0, 0, 120002, 'Solendra Featherdown to Player'),
(103571, @GROUP_ID+2, @ID+0, 'May your hunt be ever fruitful, my sister.', 12, 0, 100, 2, 0, 0, 108551, 'Solendra Featherdown to Player'),
(103571, @GROUP_ID+3, @ID+0, 'Thank you!', 12, 0, 100, 2, 0, 0, 122116, 'Solendra Featherdown to Player'), -- BroadcastTextID: 18708 - 18709 - 27898 - 35230 - 37121 - 37237 - 41471 - 41477 - 41537 - 58873 - 75228 - 81301 - 84724 - 84764 - 96436 - 101019 - 122116 - 131553
(103575, @GROUP_ID+0, @ID+0, 'Sashj''tar attack!', 12, 0, 100, 0, 0, 0, 105278, 'Reef Lord Raj''his to Player'),
(103575, @GROUP_ID+1, @ID+0, 'Tidecaller, shield me!', 12, 0, 100, 0, 0, 0, 119736, 'Reef Lord Raj''his'),
(103575, @GROUP_ID+2, @ID+0, 'Scaleguard, freeze them to their bones!', 12, 0, 100, 0, 0, 0, 119735, 'Reef Lord Raj''his'),
(103575, @GROUP_ID+3, @ID+0, 'Work hard, my naga! We will destroy Jandvik!', 14, 0, 100, 0, 0, 0, 106170, 'Reef Lord Raj''his'),
(103809, @GROUP_ID+0, @ID+0, 'Silverfang deposits a shiny, smooth Nightsaber Fang onto the dirt.', 16, 0, 100, 0, 0, 0, 108545, 'Silverfang to Player'),
(103809, @GROUP_ID+1, @ID+0, 'Silverfang lets out a low, passive growl.', 16, 0, 100, 0, 0, 0, 108546, 'Silverfang to Player'),
(104359, @GROUP_ID+0, @ID+0, 'Jandvik will fall!', 12, 0, 100, 0, 0, 0, 101740, 'Tidemistress Sashj''tar to Player'),
(104406, @GROUP_ID+0, @ID+0, 'My kin are safe and the seawarden is dead. I will return to Jandvik now.', 12, 0, 100, 0, 0, 0, 106960, 'Brytag to Player'),
(104454, @GROUP_ID+0, @ID+0, 'You... useless... worm food...', 12, 0, 100, 0, 0, 0, 104987, 'Trenchwalker Guardian to Player'),
(104459, @GROUP_ID+0, @ID+0, 'Forgalash... I was not... strong enough...', 12, 0, 100, 0, 0, 0, 104989, 'Seawarden Largush to Player'),
(104586, @GROUP_ID+0, @ID+0, 'Slay them all... for Jandvik...', 12, 0, 100, 0, 0, 0, 107060, 'Fjolrik to Player'),
(104630, @GROUP_ID+0, @ID+0, 'Find Brytag... kill the naga...', 12, 0, 100, 0, 0, 0, 107146, 'Kell to Player'),
(105956, @GROUP_ID+0, @ID+0, 'Who goes there?', 12, 0, 100, 0, 0, 66421, 108940, 'Nightborne Eradicator to Player'), -- BroadcastTextID: 13251 - 104608 - 108940 - 112905
(106095, @GROUP_ID+0, @ID+0, 'Over here! I haven''t much time.', 12, 0, 100, 0, 0, 0, 109029, 'Ivanel Meadowsong to Player'),
(106095, @GROUP_ID+1, @ID+0, 'Ivanel Meadowsong reaches out toward the nearby hippogryph and weakly tries to shoo it away.', 16, 0, 100, 0, 0, 0, 109642, 'Ivanel Meadowsong to Player'),
(106095, @GROUP_ID+2, @ID+0, 'Go on, fly away!', 12, 0, 100, 0, 0, 0, 109643, 'Ivanel Meadowsong to Player'),
(106616, @GROUP_ID+0, @ID+0, 'Pew pew pew! Lightning Missiles!', 12, 0, 100, 0, 0, 65974, 112867, 'Nightborne Child'), -- BroadcastTextID: 112867 - 112868
(106616, @GROUP_ID+1, @ID+0, 'Hearts are full of pity...', 12, 0, 100, 0, 0, 65979, 112859, 'Nightborne Child'),
(106616, @GROUP_ID+2, @ID+0, 'Crashing! Clashing!', 12, 0, 100, 1, 0, 65978, 112860, 'Nightborne Child'),
(106617, @GROUP_ID+0, @ID+0, 'Ring around the city...', 12, 0, 100, 0, 0, 65778, 112858, 'Nightborne Child'),
(106617, @GROUP_ID+1, @ID+0, 'Outside lies doom.', 12, 0, 100, 0, 0, 65777, 112861, 'Nightborne Child'),
(106617, @GROUP_ID+2, @ID+0, 'No fair, I never get to be the Grand Magistrix!', 12, 0, 100, 0, 0, 65771, 112863, 'Nightborne Child'), -- BroadcastTextID: 112863 - 112871
(106897, @GROUP_ID+0, @ID+0, 'I believe our wounds have healed enough. I will continue my scouting. Be well, Lilryia.', 12, 0, 100, 0, 0, 0, 122610, 'Nighteyes to Player'),
(107225, @GROUP_ID+0, @ID+0, 'I see! You are the one I was waiting for. All I need is a full boat and I''ll be on my way.', 12, 0, 100, 0, 0, 0, 111360, 'Deline to Player'),
(107225, @GROUP_ID+1, @ID+0, 'Ah! This cask contains a large amount of arcwine. Go ahead and put it into the gondola.', 12, 0, 100, 0, 0, 0, 111356, 'Deline to Player'),
(107318, @GROUP_ID+0, @ID+0, 'Keep it down, brats. You will join the others soon.', 12, 0, 100, 0, 0, 66315, 115406, 'Guard Morgaine to Player'),
(107598, @GROUP_ID+0, @ID+0, 'Enough for those most in need. The rest- Ah! Welcome, welcome.', 12, 0, 100, 0, 0, 67584, 113883, 'Vanthir to Player'),
(107598, @GROUP_ID+1, @ID+0, 'It is not much, but please take it.', 12, 0, 100, 1, 0, 67581, 113199, 'Vanthir to Shal''dorei Civilian'),
(107601, @GROUP_ID+0, @ID+0, 'The Afflicted Nightborne Citizen shivers violently while staring blankly into the distance.', 16, 0, 100, 0, 0, 0, 114128, 'Afflicted Citizen to Player'),
(107603, @GROUP_ID+0, @ID+0, 'Haven''t seen a porter in days... how is it possible to overlook an entire community like this?', 12, 0, 100, 274, 0, 0, 114130, 'Shal''dorei Civilian to Player'),
(107603, @GROUP_ID+1, @ID+0, 'Somehow I do not think we have been merely overlooked.', 12, 0, 100, 6, 0, 0, 114131, 'Shal''dorei Civilian to Player'),
(107604, @GROUP_ID+0, @ID+0, 'S-soon, little one. Soon,  I promise.', 12, 0, 100, 0, 0, 0, 114127, 'Afflicted Citizen to Player'),
(107604, @GROUP_ID+1, @ID+0, 'Is the shipment in? Please tell me there is more... please...', 12, 0, 100, 0, 0, 0, 114136, 'Afflicted Citizen to Player'),
(107606, @GROUP_ID+0, @ID+0, 'Father, I''m thirsty... can I have some mana juice?', 12, 0, 100, 18, 0, 0, 114126, 'Nightborne Child to Player'),
(107712, @GROUP_ID+0, @ID+0, 'Oh where could she have gone...', 12, 0, 100, 0, 0, 66374, 113899, 'Verene to Player'),
(107712, @GROUP_ID+1, @ID+0, 'Do you think Korine could be with the other children?', 12, 0, 100, 0, 0, 66377, 113185, 'Verene to Player'),
(107712, @GROUP_ID+2, @ID+0, 'Oh my sweet little girl! Are you hurt? Were they mean to you?', 12, 0, 100, 0, 0, 66378, 113268, 'Verene to Player'),
(107712, @GROUP_ID+3, @ID+0, 'You''re home now. Thank goodness.', 12, 0, 100, 0, 0, 66379, 113271, 'Verene to Player'),
(107712, @GROUP_ID+4, @ID+0, 'Thank -you-. I cannot begin to express my gratitude.', 12, 0, 100, 0, 0, 66376, 114305, 'Verene to Player'),
(107997, @GROUP_ID+0, @ID+0, 'Let me see...', 12, 0, 100, 0, 0, 67572, 113182, 'Silgryn to Player'),
(107997, @GROUP_ID+1, @ID+0, 'Silgryn quickly shuffles through the stack of letters.', 16, 0, 100, 0, 0, 0, 113183, 'Silgryn to Player'),
(107997, @GROUP_ID+2, @ID+0, 'Hm. They''ve been rounding up a lot of people lately. Children, too.', 12, 0, 100, 0, 0, 67573, 113184, 'Silgryn to Player'),
(107997, @GROUP_ID+3, @ID+0, 'Very possible. I''ll have our friend here follow a guard in and find out.', 12, 0, 100, 0, 0, 67574, 113186, 'Silgryn to Player'),
(108063, @GROUP_ID+0, @ID+0, 'Mommy!', 12, 0, 100, 0, 0, 66227, 113824, 'Korine to Player'), -- BroadcastTextID: 832 - 14143 - 39497 - 41643 - 113824
(108063, @GROUP_ID+1, @ID+0, 'They yelled and put me in a cage! I missed you...', 12, 0, 100, 0, 0, 66251, 113269, 'Korine to Player'),
(108068, @GROUP_ID+0, @ID+0, 'I did not know if I would make it out of this alive. Thank you.', 12, 0, 100, 0, 0, 0, 114054, 'Accused Suramar Citizen to Player'),
(108075, @GROUP_ID+0, @ID+0, 'I want my mommy...', 12, 0, 100, 0, 0, 66239, 113217, 'Korine to Player'),
(108075, @GROUP_ID+1, @ID+0, 'AH! NO!', 12, 0, 100, 0, 0, 66240, 113218, 'Korine to Player'),
(108075, @GROUP_ID+2, @ID+0, 'Waaaah!', 12, 0, 100, 0, 0, 66241, 113219, 'Korine to Player'),
(108075, @GROUP_ID+3, @ID+0, '.... Waaaaah!!', 12, 0, 100, 0, 0, 66250, 113246, 'Korine to Player'),
(108075, @GROUP_ID+4, @ID+0, 'I... *sniff* I know this street, maybe.', 12, 0, 100, 0, 0, 66242, 113220, 'Korine to Player'),
(108075, @GROUP_ID+5, @ID+0, 'Uh... yeah... YEAH! That''s Vanthir''s house!', 12, 0, 100, 0, 0, 66243, 113221, 'Korine to Player'),
(108075, @GROUP_ID+6, @ID+0, 'Bye!', 12, 0, 100, 0, 0, 66244, 116983, 'Korine to Player'), -- BroadcastTextID: 59884 - 63544 - 116983
(108096, @GROUP_ID+0, @ID+0, 'After her!', 12, 0, 100, 463, 0, 66319, 113257, 'Duskwatch Scion to Player'),
(108344, @GROUP_ID+0, @ID+0, 'He found more?', 12, 0, 100, 0, 0, 0, 113848, 'Donatien to Player'),
(108344, @GROUP_ID+1, @ID+0, 'Donatien takes a quick draught of the mana-wine.', 16, 0, 100, 0, 0, 0, 113851, 'Donatien to Player'),
(108345, @GROUP_ID+0, @ID+0, 'W-what?', 12, 0, 100, 0, 0, 0, 113839, 'Clotaire to Player'),
(108345, @GROUP_ID+1, @ID+0, 'Clotaire tentatively sips at the wine, then takes a deep gulp.', 16, 0, 100, 0, 0, 65974, 113841, 'Clotaire to Player'),
(108346, @GROUP_ID+0, @ID+0, 'But you need...', 12, 0, 100, 0, 0, 0, 113820, 'Lunette to Player'),
(108346, @GROUP_ID+1, @ID+0, 'Lunette nods and takes a drink.', 16, 0, 100, 0, 0, 0, 113822, 'Lunette to Player'),
(108347, @GROUP_ID+0, @ID+0, 'Nightwell be praised... I thought I was going to die.', 12, 0, 100, 0, 0, 0, 113831, 'Ambrena to Player'),
(108347, @GROUP_ID+1, @ID+0, 'Ambrena shakily takes a drink.', 16, 0, 100, 0, 0, 0, 113836, 'Ambrena to Player'),
(108385, @GROUP_ID+0, @ID+0, 'Much better. Thank you. Thank you so much.', 12, 0, 100, 0, 0, 0, 113823, 'Lunette to Player'),
(108386, @GROUP_ID+0, @ID+0, 'It isn''t far. Thank you.', 12, 0, 100, 0, 0, 0, 113834, 'Ambrena to Player'),
(108387, @GROUP_ID+0, @ID+0, 'Vanthir came through again... how can he keep this up?', 12, 0, 100, 0, 0, 0, 113852, 'Donatien to Player'),
(108388, @GROUP_ID+0, @ID+0, 'Hush you... Thank Vanthir for me, won''t you?', 12, 0, 100, 0, 0, 0, 113843, 'Clotaire to Player'),
(108411, @GROUP_ID+0, @ID+0, 'Do you think you will have enough?', 12, 0, 100, 0, 0, 67571, 113882, 'Silgryn to Player'),
(108411, @GROUP_ID+1, @ID+0, 'Try to relax, friend. We will find her.', 12, 0, 100, 0, 0, 67569, 113900, 'Silgryn to Player'),
(108807, @GROUP_ID+0, @ID+0, 'Take a drink, darling. You will feel better.', 12, 0, 100, 0, 0, 0, 113818, 'Eneas to Player'),
(108807, @GROUP_ID+1, @ID+0, 'We will survive until tomorrow. Vanthir always takes care of us. You know that.', 12, 0, 100, 0, 0, 0, 113821, 'Eneas to Player'),
(108808, @GROUP_ID+0, @ID+0, 'Get up...', 12, 0, 100, 0, 0, 0, 113817, 'Brigitte to Player'),
(108810, @GROUP_ID+0, @ID+0, 'I will get her home. It is nice to know Vanthir still thinks of us.', 12, 0, 100, 0, 0, 0, 113832, 'Chloe to Player'),
(108811, @GROUP_ID+0, @ID+0, 'It is Arcwine. For you. Go on, brother.', 12, 0, 100, 0, 0, 0, 113840, 'Audric to Player'),
(108811, @GROUP_ID+1, @ID+0, 'Hah. Not so fast! You may choke.', 12, 0, 100, 0, 0, 0, 113842, 'Audric to Player'),
(108812, @GROUP_ID+0, @ID+0, 'Yes! Plenty for both of us today.', 12, 0, 100, 0, 0, 0, 113849, 'Iseult to Player'),
(109409, @GROUP_ID+0, @ID+0, 'So generous! Thank you, I owe you my life!', 12, 0, 100, 7, 0, 0, 115295, 'Nightborne Wretch to Player'),
(109473, @GROUP_ID+0, @ID+0, 'Who goes there?!', 12, 0, 100, 0, 0, 66005, 118520, 'Duskwatch Shroud to Player'), -- BroadcastTextID: 105557 - 118520 - 124631
(111318, @GROUP_ID+0, @ID+0, 'I was so certain he was dead...', 12, 0, 100, 0, 0, 0, 119885, 'Noressa to Player'),
(111318, @GROUP_ID+1, @ID+0, 'Noressa quickly glances over the letter.', 16, 0, 100, 0, 0, 0, 119886, 'Noressa to Player'),
(111318, @GROUP_ID+2, @ID+0, 'Oh, Absolon...', 12, 0, 100, 0, 0, 0, 119887, 'Noressa to Player'),
(111318, @GROUP_ID+3, @ID+0, 'Thank you. I will hold his words in my heart.', 12, 0, 100, 0, 0, 0, 119891, 'Noressa to Player'),
(111530, @GROUP_ID+0, @ID+0, 'Hah! Where are your manafiends now?!', 12, 0, 100, 0, 0, 0, 122538, 'Imperial Arcanist to Player'),
(111530, @GROUP_ID+1, @ID+0, 'What?!', 12, 0, 100, 0, 0, 0, 120909, 'Imperial Arcanist to Player'), -- BroadcastTextID: 32630 - 58529 - 120909 - 122539
(111539, @GROUP_ID+0, @ID+0, 'I will join my fallen brothers and sisters. Goodbye, Lyrea.', 12, 0, 100, 0, 0, 0, 120114, 'Kailea Windfeather to Player'),
(111619, @GROUP_ID+0, @ID+0, 'Dissent is forbidden, by order of Grand Magistrix Elisande!', 12, 0, 100, 0, 0, 66005, 124226, 'Duskwatch Shroud'),
(111619, @GROUP_ID+1, @ID+0, 'Something''s not quite right...', 12, 0, 100, 0, 0, 65803, 124630, 'Duskwatch Shroud to Player'), -- BroadcastTextID: 105558 - 118519 - 124630
(111621, @GROUP_ID+0, @ID+0, 'Your fate is sealed!', 12, 0, 100, 0, 0, 66021, 116689, 'Duskwatch Executor to Player'), -- BroadcastTextID: 11455 - 94769 - 116675 - 116689
(111774, @GROUP_ID+0, @ID+0, 'Val''kyr!  The Call has gone out!  Prepare yourselves!', 14, 0, 100, 5, 0, 0, 122615, 'Matilda Skoptidottir to Player');

INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(111871, @GROUP_ID+0, @ID+0, 'Inconceivable...', 12, 0, 100, 0, 0, 65808, 116788, 'Ley Line Researcher to Player'), -- BroadcastTextID: 93926 - 116757 - 116788
(111871, @GROUP_ID+1, @ID+0, 'Tor''theras falar!', 12, 0, 100, 432, 0, 65809, 116780, 'Ley Line Researcher to Player'), -- BroadcastTextID: 102166 - 116432 - 116759 - 116770 - 116780 - 116790
(111872, @GROUP_ID+0, @ID+0, 'No! It is not my time....', 12, 0, 100, 0, 0, 66015, 116778, 'Leyline Researcher to Player'), -- BroadcastTextID: 116768 - 116778
(111900, @GROUP_ID+0, @ID+0, 'I will follow you through. Thank you for allowing me to accompany you.', 12, 0, 100, 0, 0, 0, 121191, 'Rosaine to Player'),
(112301, @GROUP_ID+0, @ID+0, 'I fear nothing!', 12, 0, 100, 0, 0, 68513, 117446, 'Finna Bjornsdottir to Player'),
(112301, @GROUP_ID+1, @ID+0, 'This should be good!', 12, 0, 100, 0, 0, 68512, 117445, 'Finna Bjornsdottir to Player'),
(112301, @GROUP_ID+2, @ID+0, 'I will crush you!', 12, 0, 100, 0, 0, 68464, 104829, 'Finna Bjornsdottir to Player'), -- BroadcastTextID: 25224 - 31795 - 58070 - 65264 - 79965 - 80170 - 83593 - 87324 - 95421 - 104829
(113597, @GROUP_ID+0, @ID+0, 'The shal''dorei are... chosen...', 12, 0, 100, 0, 0, 65697, 116624, 'Duskwatch Adjudicator to Player'), -- BroadcastTextID: 116624 - 116710
(113679, @GROUP_ID+0, @ID+0, 'We will cleanse the universe in fire.', 12, 0, 100, 0, 0, 55370, 98766, 'Wrathguard Soulsplitter to Player'),
(113679, @GROUP_ID+1, @ID+0, 'This is where you die.', 12, 0, 100, 0, 0, 55362, 98765, 'Wrathguard Soulsplitter to Player'),
(113738, @GROUP_ID+0, @ID+0, 'An illusion! What are you hiding?', 12, 0, 100, 0, 0, 65819, 124629, 'Duskwatch Moonmage to Player'), -- BroadcastTextID: 105559 - 118518 - 124629
(113777, @GROUP_ID+0, @ID+0, 'My spear is yours.', 12, 0, 100, 66, 0, 0, 122617, 'Val''kyr of Odyn to Player'),
(113793, @GROUP_ID+0, @ID+0, 'They shall fear our wrath.', 12, 0, 100, 0, 0, 0, 122620, 'Val''kyr of Odyn to Player'),
(113794, @GROUP_ID+0, @ID+0, 'My life for Odyn!', 12, 0, 100, 0, 0, 0, 122619, 'Val''kyr of Odyn to Player'),
(114470, @GROUP_ID+0, @ID+0, 'Confess! You are harboring traitors to Suramar!', 12, 0, 100, 0, 0, 65771, 124223, 'Duskwatch Orbitist'),
(114549, @GROUP_ID+0, @ID+0, 'Vanthir... Vanthir!', 12, 0, 100, 0, 0, 0, 120312, 'Withering Suramar Citizen to Player'),
(114549, @GROUP_ID+1, @ID+0, 'Mind is... slipping...', 12, 0, 100, 0, 0, 0, 120313, 'Withering Suramar Citizen to Player'),
(114876, @GROUP_ID+0, @ID+0, 'Scurry, little mice!', 12, 0, 100, 0, 0, 0, 124635, 'Vengeful Wrathguard'),
(114876, @GROUP_ID+1, @ID+0, 'Stay inside if you want to live!', 12, 0, 100, 0, 0, 0, 124633, 'Vengeful Wrathguard'),
(115631, @GROUP_ID+0, @ID+0, 'Hurry! We''re not safe here!', 12, 0, 100, 0, 0, 0, 124196, 'Desperate Refugee to Player'),
(115631, @GROUP_ID+1, @ID+0, 'I am safe... thank you.', 12, 0, 100, 0, 0, 0, 124195, 'Desperate Refugee'),
(115697, @GROUP_ID+0, @ID+0, 'There are demons everywhere...', 12, 0, 100, 0, 0, 55370, 124198, 'Desperate Refugee to Player'),
(115697, @GROUP_ID+1, @ID+0, 'This city has devolved to madness...', 12, 0, 100, 0, 0, 0, 124194, 'Desperate Refugee'),
(115703, @GROUP_ID+0, @ID+0, 'We... we were almost killed!', 12, 0, 100, 0, 0, 0, 124193, 'Desperate Refugee'),
(117412, @GROUP_ID+0, @ID+0, 'This cannot be...', 12, 0, 100, 0, 0, 65692, 116434, 'Felborne Trapper to Player'); -- BroadcastTextID: 102168 - 116434


UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=7456; -- Winterspring Screecher
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=50051; -- Ghostcrawler
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116716; -- Nightborne Rebel
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116715; -- Rebelle souffrenuit
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112403; -- Spawn Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111900; -- Rosaine
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108075; -- Korine
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108930; -- Nightborne Envoy
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113630; -- Exasperated Child
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110456; -- Unseen Marksman
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108616; -- Guard Morgaine
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108063; -- Korine
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108466; -- Terrified Suramar Child
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107318; -- Guard Morgaine
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107474; -- Conveniently Placed Basket
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=92870; -- Sindragosa's Fury
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107473; -- Conveniently Placed Basket
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107613; -- Line Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111619; -- Duskwatch Shroud
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109473; -- Duskwatch Shroud
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114904; -- Geôlier du moteur d’âmes
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=94365; -- Ashbringer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114958; -- Duskwatch Subjugator
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107997; -- Silgryn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111389; -- Great Sea Whale Shark
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `VerifiedBuild`=25996 WHERE `entry`=59114; -- Generic Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113346; -- Beast
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3809; -- Ashenvale Bear
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=121661; -- Sneaky Snake
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=3, `type_flags`=2147483648, `HealthModifier`=5, `VerifiedBuild`=25996 WHERE `entry`=120208; -- Rayesh
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114961; -- Controller
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111376; -- Charged Knifefish
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99589; -- Syana
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109408; -- Lieutenant Piet
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102746; -- Elemental Servant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=93979; -- Leyweaver Jorjana
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99588; -- Tallian
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109563; -- Sundries Merchant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112058; -- Palu
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99585; -- Feorias
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114529; -- Anxious Trader
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102748; -- Tamed Manasaber
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107137; -- Nightborne Vintner
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107225; -- Deline
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98553; -- Silgryn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108387; -- Donatien
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107712; -- Verene
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108388; -- Clotaire
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112063; -- Cornelius Crispin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111056; -- Tiny Illusory Dancer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111050; -- Drunken Reveler
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111007; -- Randril
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106797; -- Caline Starsoul
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108386; -- Ambrena
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108811; -- Audric
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109058; -- Palanquin Bearer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109780; -- Palanquin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109782; -- Arcanist Doralin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111045; -- Drunken Reveler
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113455; -- Nightborne Wretch
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111961; -- Survey Bunny
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=7, `type_flags`=4096, `HealthModifier`=5, `VerifiedBuild`=25996 WHERE `entry`=119907; -- Nightborne Rebel
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108345; -- Clotaire
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108385; -- Lunette
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114439; -- Shal'dorei Civilian
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=70018; -- Primal Direhorn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106926; -- Selin Sidoran
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114874; -- Wyrmtongue Pilferer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114528; -- Nervous Vendor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113515; -- Maribeth
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108347; -- Ambrena
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108810; -- Chloe
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108809; -- Emille
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108808; -- Brigitte
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108807; -- Eneas
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108405; -- Kal
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108411; -- Silgryn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107467; -- Jacin
UPDATE `creature_template` SET `type_flags`=0, `VerifiedBuild`=25996 WHERE `entry`=113516; -- Dasdonia
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113514; -- Joshen Lafave
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107601; -- Afflicted Citizen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107606; -- Nightborne Child
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107604; -- Afflicted Citizen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108812; -- Iseult
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108344; -- Donatien
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114876; -- Garde-courroux vengeur
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115806; -- Duskwatch Punisher
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106080; -- Nightborne Child
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106055; -- Suramar Loyalist
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111445; -- Loyaliste de Suramar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107727; -- Legion Harbinger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110419; -- Grapple Point
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114530; -- Concerned Merchant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107717; -- Burning Chaplain
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115697; -- Desperate Refugee
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115706; -- Desperate Refugee
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107720; -- Felwing Doombringer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109199; -- Nightborne Tempomancer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115216; -- Duskwatch Veteran
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114527; -- Timid Shopkeeper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113457; -- Nightborne Wretch
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110356; -- Grapple Point
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102747; -- Tamed Owl
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114480; -- Observateur de la Garde crépusculaire
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108495; -- Outspoken Citizen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108655; -- Spawn of Serpentrix
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114470; -- Duskwatch Orbitist
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109055; -- Suramar Custodian
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115703; -- Desperate Refugee
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115631; -- Desperate Refugee
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111506; -- Dark Zealot
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106617; -- Nightborne Child
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107333; -- Surveillant Durant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114889; -- Civile shal’dorei
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114888; -- Shal'dorei Civilian
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114892; -- Civil flétrissant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109048; -- Arcane Engineer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106919; -- Nightborne Courier
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115096; -- Silgryn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106616; -- Nightborne Child
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102496; -- Shal'dorei Servant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110334; -- Grapple Point
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114468; -- Duskwatch Orbitist
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108496; -- Outspoken Citizen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107521; -- Legion Emissary
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109654; -- Grapple Point
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100132; -- Window Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114474; -- Hautelame de la Garde crépusculaire
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115626; -- Rebel Guardian
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115627; -- Frightened Refugee
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115628; -- Refugee Child
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116018; -- Survey Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114472; -- Duskwatch Highblade
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114960; -- Felsoul Ferry
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116658; -- Felborne Conspirator
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112213; -- Huddled Vagrant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109562; -- Sundries Merchant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111622; -- Arcane Chronomaton
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115606; -- Spell-Fencer Adept
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108096; -- Duskwatch Scion
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115607; -- Thoramir
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114549; -- Withering Suramar Citizen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113629; -- Exasperated Child
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108622; -- Withering Suramar Citizen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108070; -- Accused Suramar Citizen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108068; -- Accused Suramar Citizen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108346; -- Lunette
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107598; -- Vanthir
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109447; -- Lunastre Attendant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105481; -- Oll'ison
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111446; -- Duskwatch Battlemaster
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115517; -- Magus Sendath
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107632; -- Ly’leth Lunastre
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98386; -- Manafiel surnaturel
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111872; -- Leyline Researcher
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100237; -- Leyline Hunter
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106897; -- Nighteyes
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103122; -- Jandvik Runecaller
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103111; -- Jandvik Splintershield
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103929; -- Sashj'tar Wave Breaker
UPDATE `creature_template` SET `family`=160, `VerifiedBuild`=25996 WHERE `entry`=112241; -- Khadgar's Gryphon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104821; -- Makeshift Ballista
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104829; -- Sashj'tar Scaleguard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104367; -- Writhing Willbreaker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100999; -- Sashj'tar Siren
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100179; -- Willbreaker Incubator
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104830; -- Makeshift Ballista
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104359; -- Tidemistress Sashj'tar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104550; -- Brytag
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102410; -- Toryl
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104210; -- Powder Keg
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104209; -- Powder Keg Loc
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103610; -- Sashj'tar Collier
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103611; -- Sashj'tar Overseer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103613; -- Sashj'tar Deep Witch
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100998; -- Sashj'tar Myrmidon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104459; -- Seawarden Largush
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103804; -- Azuregale Paddlefoot
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104685; -- Kell
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104586; -- Fjolrik
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104769; -- Sand Scuttler
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99720; -- Coastal Spikeback
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102390; -- Toryl
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99866; -- Tidemistress Sashj'tar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102527; -- Toryl
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100953; -- Jandvik Splintershield
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102388; -- Toryl
UPDATE `creature_template` SET `modelid1`=66234, `modelid2`=0, `HealthScalingExpansion`=6, `type`=7, `type_flags`=0, `VerifiedBuild`=25996 WHERE `entry`=100016; -- Fjolrik
UPDATE `creature_template` SET `modelid1`=66235, `modelid2`=0, `HealthScalingExpansion`=6, `type`=7, `type_flags`=0, `VerifiedBuild`=25996 WHERE `entry`=100017; -- Stokalfr
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112226; -- Markus Hjolbruk
UPDATE `creature_template` SET `modelid1`=25812, `modelid2`=0, `HealthScalingExpansion`=6, `type`=7, `type_flags`=0, `VerifiedBuild`=25996 WHERE `entry`=100015; -- Katarine
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104630; -- Kell
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113854; -- Leycharged Eel
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111178; -- Gardécaille sashj’tar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103645; -- Sashj'tar Tidecaller
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103060; -- Sashj'tar Grotto Entrance
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103062; -- Forgalash's Den Entrance
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104600; -- Sashj'tar Scaleflayer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102845; -- Brandolf
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102913; -- Sashj'tar Enforcer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104638; -- Sashj'tar Harpooner
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99899; -- Vicious Whale Shark
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103534; -- Writhing Willbreaker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99770; -- Sashj'tar Deep Witch
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103502; -- Empowered Globule
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102999; -- Deepwater Crab
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103529; -- Possessed Vrykul
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103555; -- Writhing Willbreaker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102685; -- Sashj'tar Overseer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104242; -- Azuregale Paddlefoot
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104576; -- Azuregale Eel
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99502; -- Azuregale Zapper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99304; -- Trenchwalker Scavenger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104279; -- Juvenile Zapper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102862; -- Trenchwalker Envoy
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99506; -- Colossal Striper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103061; -- Azuregale Hollow Entrance
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99825; -- Captured Vrykul
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102844; -- Commander Kel'tariss
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102841; -- Commander Malt'his
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102840; -- Commander Raz'jira
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102796; -- Siren Naz'jul
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103216; -- Jandvik Splintershield
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103219; -- Axetail Basilisk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113680; -- Naga Armaments
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100100; -- Axetail Basilisk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99504; -- Deepwater Spikeback
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=68553; -- SLG Generic MoP (Large AOI)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104406; -- Brytag
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100950; -- Sashj'tar Enchantress
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100949; -- Sashj'tar Lancer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103518; -- Barbed Puffer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104454; -- Trenchwalker Guardian
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102828; -- Sashj'tar Sandcrusher
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102381; -- Jandvik Warrior
UPDATE `creature_template` SET `modelid1`=66232, `modelid2`=0, `HealthScalingExpansion`=6, `type`=7, `type_flags`=8650752, `HealthModifier`=3, `VerifiedBuild`=25996 WHERE `entry`=100004; -- Brandolf
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101144; -- Throndyr's Pyre Flame
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102776; -- Stokalfr
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102775; -- Fjolrik
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102774; -- Katarine
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103212; -- Injured Vrykul
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99564; -- Stokalfr
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103211; -- Injured Vrykul
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103207; -- Injured Vrykul
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100962; -- Sashj'tar Lancer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100963; -- Sashj'tar Enchantress
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100864; -- Cora'kar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99562; -- Katarine
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102334; -- Brandolf
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103239; -- Jarl Throndyr
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101131; -- Throndyr's Pyre
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99563; -- Fjolrik
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103575; -- Seigneur du récif Raj’his
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99893; -- Razortail Hammerhead
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102819; -- Sashj'tar Pincher
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=60199; -- Rune of Power
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103774; -- Lightning Storm
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115724; -- Felborne Marauder
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116119; -- Felborne Energist
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102660; -- Jandvik Metalsmith
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103127; -- Jandvik Runecaller
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103128; -- Jandvik Ripfang
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103126; -- Jandvik Splintershield
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102551; -- Jandvik Splintershield
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99948; -- Toryl
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100947; -- Sashj'tar Reef Runner
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100946; -- Jandvik Runecaller
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100945; -- Jandvik Splintershield
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99070; -- Sashj'tar Reef Runner
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100948; -- Jandvik Bonepiercer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99075; -- Sashj'tar Stormcaller
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99559; -- Jarl Throndyr
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99544; -- Brandolf
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103474; -- Sashj'tar Diviner
UPDATE `creature_template` SET `modelid1`=169, `modelid2`=11686, `VerifiedBuild`=25996 WHERE `entry`=63420; -- SLG Generic MoP
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99637; -- Sashj'tar Reef Runner
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100891; -- Jandvik Bonepiercer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100890; -- Jandvik Ripfang
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100889; -- Jandvik Runecaller
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101073; -- Jandvik Rabbit
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100888; -- Jandvik Splintershield
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112436; -- Déclencheur d’Etoile filante
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112352; -- Cible d’Etoile filante
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102739; -- Eynar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102738; -- Calder
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102309; -- Toryl
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111870; -- Elemental Assistant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111871; -- Leyline Researcher
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111869; -- Leyline Hunter
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100780; -- Trapper Rodoon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100777; -- Nighteyes
UPDATE `creature_template` SET `family`=160, `type_flags`=1, `VerifiedBuild`=25996 WHERE `entry`=110253; -- Rôdeur plumelune
UPDATE `creature_template` SET `KillCredit1`=116215, `HealthScalingExpansion`=6, `type`=7, `type_flags`=2147483720, `VerifiedBuild`=25996 WHERE `entry`=117355; -- Torturer Relyn
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `family`=2, `type`=1, `VerifiedBuild`=25996 WHERE `entry`=118678; -- Felbound Prowler
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110726; -- Cadraeus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110727; -- Astrix
UPDATE `creature_template` SET `family`=160, `type`=1, `VerifiedBuild`=25996 WHERE `entry`=114718; -- Ancient Cloudwing
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100775; -- Lilryia Dawnwind
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113570; -- Forgotten Thirster
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111923; -- Forgotten Wretch
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116052; -- Ley Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113198; -- Trapped Thicket Hunter
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112972; -- Ecrabouilleur des fourrés géant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104404; -- Thicket Hunter
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100778; -- Nightborne Trapper
UPDATE `creature_template` SET `KillCredit1`=116215, `KillCredit2`=100778, `HealthScalingExpansion`=6, `type`=7, `VerifiedBuild`=25996 WHERE `entry`=117412; -- Felborne Trapper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113201; -- Thicket Manahunter
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `HealthModifier`=20, `VerifiedBuild`=25996 WHERE `entry`=117246; -- Nighthuntress Syrenne
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116116; -- Felblade Protector
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112796; -- Exiled Scavenger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116117; -- Felborne Marauder
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116115; -- Scathing Felbeast
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115691; -- Felborne Magus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115690; -- Felborne Energist
UPDATE `creature_template` SET `name`='Nightwell Spring Bunny', `VerifiedBuild`=25996 WHERE `entry`=109345; -- Nightwell Spring Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108873; -- Distillery Attendant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109025; -- Moonglow Locust
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109023; -- Shadescale Flyeater
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116068; -- Arm of the Magistrix
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108877; -- Sacheverell Leburque
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110043; -- Heartwood Doe
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110042; -- Heartwood Stag
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108869; -- Travailleur du vignoble
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108943; -- Domestique du vignoble
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107296; -- Suramar Aristocrat
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108875; -- Vineyard Enforcer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107603; -- Shal'dorei Civilian
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107600; -- Shal'dorei Civilian
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108871; -- Gardien du vignoble
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112064; -- Dolse Shimmersong
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112059; -- Sasunne Dameuse
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103631; -- Confined Lion
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105655; -- Bound Vulture
UPDATE `creature_template` SET `movementId`=100, `VerifiedBuild`=25996 WHERE `entry`=61704; -- Lapin des pâturages
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104837; -- Caged Tiger
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `VerifiedBuild`=25996 WHERE `entry`=120459; -- Sha'leth
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=4, `type_flags`=2097224, `VerifiedBuild`=25996 WHERE `entry`=120454; -- Magicus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105656; -- Bound Makrura
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105644; -- Penned 'Monohorn'
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113484; -- Menagerie Shopkeeper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114879; -- Golem d’animus
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=7, `VerifiedBuild`=25996 WHERE `entry`=121414; -- Assassin sans-couronne
UPDATE `creature_template` SET `type`=12, `VerifiedBuild`=25996 WHERE `entry`=87705; -- Aile-tempête
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101082; -- Lothrius Mooncaller
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101083; -- Thalrenus Rivertree
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101080; -- Syrana Starweaver
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=123512; -- Magechaser Marsuul
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103129; -- Syrana Starweaver
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101773; -- Moonfall Acolyte
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102954; -- Trap Rune Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103305; -- Frost Orb
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102575; -- Conjurer Thalerian
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114305; -- Nightborne Siegecaster
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114301; -- Nightborne Invader
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114300; -- Imperial Arcanist
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114303; -- Assemblage cherche-sort
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114302; -- Mana Saber
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114299; -- Imperial Spellbreaker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114304; -- Nightborne Infiltrator
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114307; -- Imperial Conjurer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114306; -- Ensorcelled Mana Wraith
UPDATE `creature_template` SET `family`=160, `type`=1, `VerifiedBuild`=25996 WHERE `entry`=111611; -- Moonfall Riding Hippogryph
UPDATE `creature_template` SET `family`=160, `type`=1, `VerifiedBuild`=25996 WHERE `entry`=111606; -- Moonfall Riding Hippogryph
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101774; -- Moonfall Acolyte
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101765; -- Syrana Starweaver
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111670; -- Imperial Conjurer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111669; -- Adjurateur impérial
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=42718; -- Young Cat
UPDATE `creature_template` SET `family`=160, `type`=1, `VerifiedBuild`=25996 WHERE `entry`=111605; -- Moonfall Riding Hippogryph
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106349; -- Damaged Spell Seeker Construct
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97055; -- Horreur titubante
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101983; -- Moonfall Manafiend
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110438; -- Maître de siège Aedrin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102967; -- Controller Bunny
UPDATE `creature_template` SET `family`=160, `type`=1, `VerifiedBuild`=25996 WHERE `entry`=111604; -- Moonfall Riding Hippogryph
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106275; -- Commander Domitille
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101768; -- Lothrius Mooncaller
UPDATE `creature_template` SET `family`=160, `type`=1, `VerifiedBuild`=25996 WHERE `entry`=102740; -- Moonfall Riding Hippogryph
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102243; -- Assemblage cherche-sort
UPDATE `creature_template` SET `family`=160, `type`=1, `VerifiedBuild`=25996 WHERE `entry`=102426; -- Beakbuck
UPDATE `creature_template` SET `family`=160, `type`=1, `VerifiedBuild`=25996 WHERE `entry`=102712; -- Wild Moonfall Hippogryph
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111539; -- Kailea Windfeather
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106182; -- Wounded Moonfall Defender
UPDATE `creature_template` SET `type_flags`=1611661328, `VerifiedBuild`=25996 WHERE `entry`=113574; -- Portal to Suramar City
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101767; -- Lyrea Windfeather
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102030; -- Kailea Windfeather
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103348; -- Galar'thus Rivertree
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103019; -- Mana Focuser Obliterator Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101772; -- Moonfall Defender
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112301; -- Finna Bjornsdottir
UPDATE `creature_template` SET `KillCredit2`=0, `VerifiedBuild`=25996 WHERE `entry`=29319; -- Icepaw Bear
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=7, `VerifiedBuild`=25996 WHERE `entry`=121411; -- Myrmidon glissentaille
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107984; -- Ragnvald Drake-Né
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113794; -- Val’kyr d’Odyn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113793; -- Val’kyr d’Odyn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113777; -- Val’kyr d’Odyn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107483; -- Lesser Sparring Partner
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=107484; -- Greater Sparring Partner
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111774; -- Matilda Skoptidottir
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=114559; -- Lesser Sparring Partner
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `type_flags`=262144, `VerifiedBuild`=25996 WHERE `entry`=77789; -- Blingtron 5000
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=29238; -- Hantise du Fléau
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107985; -- Finna Bjornsdottir
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113268; -- Valarjar forge-foudre
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=59753; -- Golden Tiger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111709; -- Aluneth
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=88403; -- Blacksmithing Follower - Alliance
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `type`=12, `movementId`=121, `VerifiedBuild`=25996 WHERE `entry`=36979; -- Mini K.T.
UPDATE `creature_template` SET `type`=12, `movementId`=100, `VerifiedBuild`=25996 WHERE `entry`=87669; -- Hainetincelle le Minuscule
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=7, `type_flags`=4096, `VerifiedBuild`=25996 WHERE `entry`=124679; -- Dalaran Citizen
UPDATE `creature_template` SET `type`=12, `VerifiedBuild`=25996 WHERE `entry`=68664; -- Diablotin du magma
UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=25996 WHERE `entry`=74402; -- Chiot porte-tonnelet d’Alterac
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3825; -- Ghostpaw Alpha
UPDATE `creature_template` SET `family`=160, `type`=1, `VerifiedBuild`=25996 WHERE `entry`=101780; -- Moonfall Hippogryph
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103347; -- Nyellus Starweaver
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102031; -- Galar'thus Rivertree
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101771; -- Moonfall Defender
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111623; -- Ensorcelled Mana Wraith
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102242; -- Imperial Conjurer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106095; -- Ivanel Meadowsong
UPDATE `creature_template` SET `family`=160, `type`=1, `VerifiedBuild`=25996 WHERE `entry`=102024; -- Moonfall Hippogryph
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102029; -- Nyellus Starweaver
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112067; -- Volatile Leywraith
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112444; -- Highland Skyraptor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112334; -- Frenzied Riverbug
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106049; -- Nightborne Eradicator
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105956; -- Nightborne Eradicator
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101766; -- Thalrenus Rivertree
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106812; -- Ox Initiate
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104877; -- Leystone Basilisk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98213; -- Herbalist Tharillon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102027; -- Moonfall Acolyte
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103213; -- Spell Seeker Portal
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106047; -- Nightborne Eradicator
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102025; -- Moonfall Defender
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111527; -- Imperial Spellbreaker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103326; -- Mana Saber
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111599; -- Nightborne Invader
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111530; -- Imperial Arcanist
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112068; -- Leyline Prowler
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112140; -- Pafcoupe Brisetronc
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111433; -- Solendra Featherdown
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103809; -- Silverfang
UPDATE `creature_template` SET `family`=160, `type`=1, `VerifiedBuild`=25996 WHERE `entry`=102034; -- Wild Moonfall Hippogryph
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106048; -- Nightborne Eradicator
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102425; -- Serena Windfeather
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101784; -- Nightborne Infiltrator
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101783; -- Nightborne Siegecaster
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=94180; -- Sho'hallan
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103808; -- Managazer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105405; -- Petrified Nightsaber Cub
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98720; -- Ske'rit
UPDATE `creature_template` SET `KillCredit1`=115945, `HealthScalingExpansion`=6, `rank`=1, `type`=3, `type_flags`=2147483720, `HealthModifier`=5, `VerifiedBuild`=25996 WHERE `entry`=116721; -- Gor'lok Fleshgrinder
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110002; -- Bestioles des forêts
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104226; -- Gloomfang

DELETE FROM `creature_questitem` WHERE (`CreatureEntry`=117355 AND `Idx`=0) OR (`CreatureEntry`=118678 AND `Idx`=0);
INSERT INTO `creature_questitem` (`CreatureEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(117355, 0, 143830, 25996), -- Torturer Relyn
(118678, 0, 129888, 25996); -- Felbound Prowler

UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=108616 AND `Idx`=0); -- Guard Morgaine
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=107318 AND `Idx`=0); -- Guard Morgaine
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=111619 AND `Idx`=0); -- Duskwatch Shroud
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=109473 AND `Idx`=0); -- Duskwatch Shroud
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=114904 AND `Idx`=0); -- Geôlier du moteur d’âmes
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=111389 AND `Idx`=0); -- Great Sea Whale Shark
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=111376 AND `Idx`=0); -- Charged Knifefish
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=102748 AND `Idx`=2); -- Tamed Manasaber
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=102748 AND `Idx`=1); -- Tamed Manasaber
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=102748 AND `Idx`=0); -- Tamed Manasaber
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=114874 AND `Idx`=2); -- Wyrmtongue Pilferer
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=114874 AND `Idx`=1); -- Wyrmtongue Pilferer
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=114874 AND `Idx`=0); -- Wyrmtongue Pilferer
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=114876 AND `Idx`=2); -- Garde-courroux vengeur
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=114876 AND `Idx`=1); -- Garde-courroux vengeur
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=114876 AND `Idx`=0); -- Garde-courroux vengeur
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=102747 AND `Idx`=0); -- Tamed Owl
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=114470 AND `Idx`=0); -- Duskwatch Orbitist
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=106919 AND `Idx`=0); -- Nightborne Courier
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=114468 AND `Idx`=0); -- Duskwatch Orbitist
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=108096 AND `Idx`=0); -- Duskwatch Scion
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=115607 AND `Idx`=0); -- Thoramir
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=105481 AND `Idx`=0); -- Oll'ison
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=99720 AND `Idx`=3); -- Coastal Spikeback
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=99720 AND `Idx`=2); -- Coastal Spikeback
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=99720 AND `Idx`=1); -- Coastal Spikeback
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=99720 AND `Idx`=0); -- Coastal Spikeback
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=113854 AND `Idx`=0); -- Leycharged Eel
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=104638 AND `Idx`=0); -- Sashj'tar Harpooner
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=99899 AND `Idx`=0); -- Vicious Whale Shark
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=104242 AND `Idx`=0); -- Azuregale Paddlefoot
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=104576 AND `Idx`=0); -- Azuregale Eel
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=99502 AND `Idx`=0); -- Azuregale Zapper
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=99304 AND `Idx`=0); -- Trenchwalker Scavenger
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=99506 AND `Idx`=1); -- Colossal Striper
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=99506 AND `Idx`=0); -- Colossal Striper
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=102796 AND `Idx`=0); -- Siren Naz'jul
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=100100 AND `Idx`=3); -- Axetail Basilisk
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=100100 AND `Idx`=2); -- Axetail Basilisk
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=100100 AND `Idx`=1); -- Axetail Basilisk
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=100100 AND `Idx`=0); -- Axetail Basilisk
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=99504 AND `Idx`=2); -- Deepwater Spikeback
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=99504 AND `Idx`=1); -- Deepwater Spikeback
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=99504 AND `Idx`=0); -- Deepwater Spikeback
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=100950 AND `Idx`=0); -- Sashj'tar Enchantress
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=100949 AND `Idx`=0); -- Sashj'tar Lancer
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=102828 AND `Idx`=0); -- Sashj'tar Sandcrusher
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=99893 AND `Idx`=0); -- Razortail Hammerhead
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=102819 AND `Idx`=2); -- Sashj'tar Pincher
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=102819 AND `Idx`=1); -- Sashj'tar Pincher
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=102819 AND `Idx`=0); -- Sashj'tar Pincher
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=100947 AND `Idx`=0); -- Sashj'tar Reef Runner
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=99070 AND `Idx`=0); -- Sashj'tar Reef Runner
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=99075 AND `Idx`=0); -- Sashj'tar Stormcaller
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=100890 AND `Idx`=2); -- Jandvik Ripfang
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=100890 AND `Idx`=1); -- Jandvik Ripfang
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=100890 AND `Idx`=0); -- Jandvik Ripfang
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=100780 AND `Idx`=0); -- Trapper Rodoon
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=110253 AND `Idx`=1); -- Rôdeur plumelune
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=110253 AND `Idx`=0); -- Rôdeur plumelune
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=110727 AND `Idx`=2); -- Astrix
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=110727 AND `Idx`=1); -- Astrix
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=110727 AND `Idx`=0); -- Astrix
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=113198 AND `Idx`=2); -- Trapped Thicket Hunter
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=113198 AND `Idx`=1); -- Trapped Thicket Hunter
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=113198 AND `Idx`=0); -- Trapped Thicket Hunter
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=104404 AND `Idx`=2); -- Thicket Hunter
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=104404 AND `Idx`=1); -- Thicket Hunter
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=104404 AND `Idx`=0); -- Thicket Hunter
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=113201 AND `Idx`=2); -- Thicket Manahunter
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=113201 AND `Idx`=1); -- Thicket Manahunter
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=113201 AND `Idx`=0); -- Thicket Manahunter
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=109023 AND `Idx`=0); -- Shadescale Flyeater
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=110043 AND `Idx`=2); -- Heartwood Doe
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=110043 AND `Idx`=1); -- Heartwood Doe
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=110043 AND `Idx`=0); -- Heartwood Doe
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=110042 AND `Idx`=2); -- Heartwood Stag
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=110042 AND `Idx`=1); -- Heartwood Stag
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=110042 AND `Idx`=0); -- Heartwood Stag
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=103631 AND `Idx`=5); -- Confined Lion
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=103631 AND `Idx`=4); -- Confined Lion
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=103631 AND `Idx`=3); -- Confined Lion
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=103631 AND `Idx`=2); -- Confined Lion
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=103631 AND `Idx`=1); -- Confined Lion
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=103631 AND `Idx`=0); -- Confined Lion
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=105655 AND `Idx`=0); -- Bound Vulture
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=105644 AND `Idx`=1); -- Penned 'Monohorn'
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=105644 AND `Idx`=0); -- Penned 'Monohorn'
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=102575 AND `Idx`=0); -- Conjurer Thalerian
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=112067 AND `Idx`=0); -- Volatile Leywraith
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=112444 AND `Idx`=0); -- Highland Skyraptor
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=104877 AND `Idx`=1); -- Leystone Basilisk
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=104877 AND `Idx`=0); -- Leystone Basilisk
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=111527 AND `Idx`=0); -- Imperial Spellbreaker
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=103326 AND `Idx`=2); -- Mana Saber
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=103326 AND `Idx`=1); -- Mana Saber
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=103326 AND `Idx`=0); -- Mana Saber
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=111530 AND `Idx`=0); -- Imperial Arcanist
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=112068 AND `Idx`=2); -- Leyline Prowler
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=112068 AND `Idx`=1); -- Leyline Prowler
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=112068 AND `Idx`=0); -- Leyline Prowler
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=112140 AND `Idx`=0); -- Pafcoupe Brisetronc
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=101784 AND `Idx`=0); -- Nightborne Infiltrator
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=101783 AND `Idx`=0); -- Nightborne Siegecaster
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=103808 AND `Idx`=1); -- Managazer
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=103808 AND `Idx`=0); -- Managazer
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=104226 AND `Idx`=2); -- Gloomfang
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=104226 AND `Idx`=1); -- Gloomfang
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=104226 AND `Idx`=0); -- Gloomfang

DELETE FROM `gameobject_template` WHERE `entry` IN (258672 /*Doodad_7ne_nightelf_box002*/, 258671 /*Doodad_7ne_druid_basket005*/, 258670 /*Doodad_7ne_druid_basket004*/, 258654 /*Doodad_7ne_druid_pillow004*/, 258628 /*Doodad_7ne_nightelf_crate01_open001*/, 258626 /*Doodad_7ne_druid_pillow003*/, 258625 /*Doodad_7ne_nightelf_barrel002*/, 258624 /*Doodad_7ne_druid_pillow002*/, 258623 /*Doodad_7ne_druid_pillow001*/, 258621 /*Doodad_7ne_nightelf_crate001*/, 258630 /*Doodad_7ne_druid_plantpot_large002*/, 258629 /*Doodad_7ne_druid_plantpot_large001*/, 258633 /*Doodad_7ne_druid_wallshelf002*/, 259246 /*Doodad_7ne_ancient_table003*/, 259244 /*Doodad_7ne_ancient_table002*/, 253756 /*Right Chamber - D - Clean - Magicalbook*/, 253754 /*Right Chamber - D - Clean - Schooldesk*/, 253731 /*Right Chamber - C - Clean - Bookshelf*/, 253755 /*Right Chamber - D - Clean - Harp*/, 253757 /*Right Chamber - D - Clean - Chair*/, 253730 /*Right Chamber - C - Clean - Bookshelf 02*/, 253722 /*Right Chamber - C - Clean - Desk*/, 253761 /*Right Chamber - B - Clean - Basketset 01*/, 253765 /*Right Chamber - B - Clean - Basketset 02*/, 253703 /*Right Chamber - J - Clean - Table*/, 253725 /*Right Chamber - K - Clean - Desk 02*/, 253724 /*Right Chamber - K -  Clean -Desk*/, 253716 /*Right Chamber - A - Clean - Bookshelf*/, 258616 /*Doodad_7nb_nightborn_basketstack006*/, 258600 /*Doodad_7nb_nightborn_crate014*/, 258596 /*Doodad_7nb_nightborn_scrollpile001*/, 258593 /*Doodad_7nb_nightborn_scrollbag004*/, 258568 /*Doodad_7nb_nightborn_scrollbag010*/, 258567 /*Doodad_7nb_nightborn_scrollpile004*/, 258517 /*Doodad_7nb_nightborn_jewelcontainer001*/, 258510 /*Doodad_7nb_nightborn_crate010*/, 258505 /*Doodad_7nb_nightborn_crate01_open004*/, 258504 /*Doodad_7nb_nightborn_crate006*/, 258474 /*Main Chamber - 4 - Clean - Crate 04*/, 258435 /*Main Chamber - 2 - Clean - Crate 02*/, 258434 /*Main Chamber - 2 - Clean - Scroll 03*/, 258433 /*Main Chamber - 2 - Clean - Scroll 04*/, 258422 /*Main Chamber - 3 - Clean - Book 01*/, 258421 /*Main Chamber - 3 - Clean - Book 02*/, 258420 /*Main Chamber - 3 - Clean - Table 01*/, 258399 /*Doodad_7ne_ancient_pylon002*/, 258384 /*Doodad_7nb_nightborn_basketstack002*/, 258050 /*Main Chamber - 2 - Clean - Scroll 04*/, 258450 /*Main Chamber - 1 - Clean - Basketset 01*/, 258376 /*Doodad_7nb_nightborn_bazaarbasketset008*/, 258364 /*Doodad_7nb_nightborn_bazaarbasketset001*/, 260270 /*Portal to Shal'Aran*/, 250986 /*Casks of Arcwine*/, 254329 /*Bench*/, 254302 /*Bench*/, 254304 /*Bench*/, 254303 /*Bench*/, 254330 /*Bench*/, 254333 /*Bench*/, 254305 /*Bench*/, 254332 /*Bench*/, 254331 /*Chair*/, 254327 /*Bench*/, 254326 /*Bench*/, 254580 /*Chair*/, 254579 /*Chair*/, 254578 /*Chair*/, 254319 /*Chair*/, 254321 /*Chair*/, 254320 /*Chair*/, 254322 /*Bench*/, 254323 /*Bench*/, 254318 /*Bench*/, 254317 /*Bench*/, 254316 /*Bench*/, 279671 /*Portal to Shal'Aran*/, 254454 /*Bench*/, 254467 /*Bench*/, 254465 /*Bench*/, 254452 /*Bench*/, 254345 /*Bench*/, 254340 /*Bench*/, 254338 /*Bench*/, 254336 /*Bench*/, 254464 /*Bench*/, 251208 /*Quarter-Full Glass of Mana Wine*/, 266555 /*Pre Suramar 7.0 Complete Barrel*/, 266556 /*Pre Suramar 7.0 Complete Barrel*/, 254570 /*Bench*/, 258683 /*Doodad_7vs_roadrock_a029*/, 258681 /*Doodad_7ne_nightelf_barrel004*/, 258678 /*Doodad_7vs_roadrock_a026*/, 258649 /*Doodad_7vs_roadrock_a015*/, 258645 /*Doodad_7vs_roadrock_a011*/, 258632 /*Doodad_7ne_druid_wallshelf001*/, 258631 /*Doodad_7ne_druid_table001*/, 258627 /*Doodad_7ne_nightelf_box001*/, 258622 /*Doodad_7ne_nightelf_barrel001*/, 258679 /*Doodad_7vs_roadrock_a027*/, 258680 /*Doodad_7vs_roadrock_a028*/, 258659 /*Doodad_7ne_druid_waterbrazier001*/, 258668 /*Doodad_7ne_druid_basket003*/, 258661 /*Doodad_7ne_druid_basket001*/, 258669 /*Doodad_7ne_nightelf_crate002*/, 258682 /*Doodad_7ne_druid_basket006*/, 258677 /*Doodad_7vs_roadrock_a025*/, 258676 /*Doodad_7vs_roadrock_a024*/, 258675 /*Doodad_7vs_roadrock_a023*/, 258658 /*Doodad_7ne_druid_plantpot_large004*/, 258656 /*Doodad_7ne_druid_wallshelf004*/, 258685 /*Doodad_7vs_roadrock_a031*/, 258684 /*Doodad_7vs_roadrock_a030*/, 258667 /*Doodad_7ne_druid_table002*/, 258666 /*Doodad_7ne_druid_plantpot_large006*/, 258665 /*Doodad_7ne_druid_plantpot_small001*/, 258664 /*Doodad_7ne_druid_plantpot_large005*/, 258663 /*Doodad_7ne_druid_foodnuts001*/, 258662 /*Doodad_7ne_druid_basket002*/, 258660 /*Doodad_7ne_druid_cup001*/, 258657 /*Doodad_7ne_druid_plantpot_large003*/, 258655 /*Doodad_7ne_druid_wallshelf003*/, 258651 /*Doodad_7vs_roadrock_a017*/, 258643 /*Doodad_7vs_roadrock_a009*/, 258673 /*Doodad_7ne_nightelf_crate003*/, 258650 /*Doodad_7vs_roadrock_a016*/, 258647 /*Doodad_7vs_roadrock_a013*/, 265439 /*Doodad_7sr_hubmanatree_lightbeam002*/, 245795 /*Throndyr's Pyre*/, 258674 /*Doodad_7ne_nightelf_barrel003*/, 258648 /*Doodad_7vs_roadrock_a014*/, 258644 /*Doodad_7vs_roadrock_a010*/, 258642 /*Doodad_7vs_roadrock_a008*/, 258641 /*Doodad_7vs_roadrock_a007*/, 258640 /*Doodad_7vs_roadrock_a006*/, 258638 /*Doodad_7vs_roadrock_a004*/, 258637 /*Doodad_7vs_roadrock_a003*/, 258639 /*Doodad_7vs_roadrock_a005*/, 258636 /*Doodad_7vs_roadrock_a002*/, 258635 /*Doodad_7vs_roadrock_a001*/, 260266 /*Portal to Shal'Aran*/, 246462 /*Elemental Summoner*/, 265444 /*Doodad_7sr_hubmanatree_lightbeam004*/, 247848 /*Mail Tube*/, 249351 /*Imbued Waters*/, 248994 /*Moonwell*/, 248116 /*Grass Tall*/, 252444 /*Peace Lily*/, 248115 /*Grass Short*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `VerifiedBuild`) VALUES
(258672, 5, 25508, 'Doodad_7ne_nightelf_box002', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_nightelf_box002
(258671, 5, 37533, 'Doodad_7ne_druid_basket005', '', '', '', 1.14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_druid_basket005
(258670, 5, 37533, 'Doodad_7ne_druid_basket004', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_druid_basket004
(258654, 5, 31977, 'Doodad_7ne_druid_pillow004', '', '', '', 1.08, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_druid_pillow004
(258628, 5, 25973, 'Doodad_7ne_nightelf_crate01_open001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_nightelf_crate01_open001
(258626, 5, 31977, 'Doodad_7ne_druid_pillow003', '', '', '', 0.8500003, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_druid_pillow003
(258625, 5, 25392, 'Doodad_7ne_nightelf_barrel002', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_nightelf_barrel002
(258624, 5, 37524, 'Doodad_7ne_druid_pillow002', '', '', '', 0.9999997, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_druid_pillow002
(258623, 5, 37524, 'Doodad_7ne_druid_pillow001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_druid_pillow001
(258621, 5, 30083, 'Doodad_7ne_nightelf_crate001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_nightelf_crate001
(258630, 5, 37526, 'Doodad_7ne_druid_plantpot_large002', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_druid_plantpot_large002
(258629, 5, 37525, 'Doodad_7ne_druid_plantpot_large001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_druid_plantpot_large001
(258633, 5, 37528, 'Doodad_7ne_druid_wallshelf002', '', '', '', 1.09, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_druid_wallshelf002
(259246, 5, 38095, 'Doodad_7ne_ancient_table003', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_ancient_table003
(259244, 5, 38095, 'Doodad_7ne_ancient_table002', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_ancient_table002
(253756, 5, 34727, 'Right Chamber - D - Clean - Magicalbook', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - D - Clean - Magicalbook
(253754, 5, 36079, 'Right Chamber - D - Clean - Schooldesk', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - D - Clean - Schooldesk
(253731, 5, 36371, 'Right Chamber - C - Clean - Bookshelf', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - C - Clean - Bookshelf
(253755, 5, 34335, 'Right Chamber - D - Clean - Harp', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - D - Clean - Harp
(253757, 5, 34334, 'Right Chamber - D - Clean - Chair', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - D - Clean - Chair
(253730, 5, 36372, 'Right Chamber - C - Clean - Bookshelf 02', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - C - Clean - Bookshelf 02
(253722, 5, 34371, 'Right Chamber - C - Clean - Desk', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - C - Clean - Desk
(253761, 5, 36384, 'Right Chamber - B - Clean - Basketset 01', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - B - Clean - Basketset 01
(253765, 5, 36385, 'Right Chamber - B - Clean - Basketset 02', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - B - Clean - Basketset 02
(253703, 5, 35093, 'Right Chamber - J - Clean - Table', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - J - Clean - Table
(253725, 5, 36079, 'Right Chamber - K - Clean - Desk 02', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - K - Clean - Desk 02
(253724, 5, 34371, 'Right Chamber - K -  Clean -Desk', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - K -  Clean -Desk
(253716, 5, 36371, 'Right Chamber - A - Clean - Bookshelf', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - A - Clean - Bookshelf
(258616, 5, 34880, 'Doodad_7nb_nightborn_basketstack006', '', '', '', 1.01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_basketstack006
(258600, 5, 37501, 'Doodad_7nb_nightborn_crate014', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_crate014
(258596, 5, 34363, 'Doodad_7nb_nightborn_scrollpile001', '', '', '', 0.9900004, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_scrollpile001
(258593, 5, 36370, 'Doodad_7nb_nightborn_scrollbag004', '', '', '', 0.9899997, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_scrollbag004
(258568, 5, 35102, 'Doodad_7nb_nightborn_scrollbag010', '', '', '', 0.99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_scrollbag010
(258567, 5, 34582, 'Doodad_7nb_nightborn_scrollpile004', '', '', '', 0.9899999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_scrollpile004
(258517, 5, 37512, 'Doodad_7nb_nightborn_jewelcontainer001', '', '', '', 1.01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_jewelcontainer001
(258510, 5, 37501, 'Doodad_7nb_nightborn_crate010', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_crate010
(258505, 5, 37508, 'Doodad_7nb_nightborn_crate01_open004', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_crate01_open004
(258504, 5, 37501, 'Doodad_7nb_nightborn_crate006', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_crate006
(258474, 5, 37501, 'Main Chamber - 4 - Clean - Crate 04', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 4 - Clean - Crate 04
(258435, 5, 37508, 'Main Chamber - 2 - Clean - Crate 02', '', '', '', 0.8042859, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 2 - Clean - Crate 02
(258434, 5, 34582, 'Main Chamber - 2 - Clean - Scroll 03', '', '', '', 0.6500002, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 2 - Clean - Scroll 03
(258433, 5, 34981, 'Main Chamber - 2 - Clean - Scroll 04', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 2 - Clean - Scroll 04
(258422, 5, 36366, 'Main Chamber - 3 - Clean - Book 01', '', '', '', 0.9200003, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 3 - Clean - Book 01
(258421, 5, 37511, 'Main Chamber - 3 - Clean - Book 02', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 3 - Clean - Book 02
(258420, 5, 35093, 'Main Chamber - 3 - Clean - Table 01', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 3 - Clean - Table 01
(258399, 5, 34597, 'Doodad_7ne_ancient_pylon002', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_ancient_pylon002
(258384, 5, 36279, 'Doodad_7nb_nightborn_basketstack002', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_basketstack002
(258050, 5, 35102, 'Main Chamber - 2 - Clean - Scroll 04', '', '', '', 0.8391461, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 2 - Clean - Scroll 04
(258450, 5, 37509, 'Main Chamber - 1 - Clean - Basketset 01', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 1 - Clean - Basketset 01
(258376, 5, 36384, 'Doodad_7nb_nightborn_bazaarbasketset008', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_bazaarbasketset008
(258364, 5, 36384, 'Doodad_7nb_nightborn_bazaarbasketset001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_bazaarbasketset001
(260270, 22, 36654, 'Portal to Shal''Aran', '', '', '', 1, 202605, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Portal to Shal'Aran
(250986, 5, 34495, 'Casks of Arcwine', '', '', '', 0.6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Casks of Arcwine
(254329, 7, 36542, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(254302, 7, 36542, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(254304, 7, 36542, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(254303, 7, 36542, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(254330, 7, 36542, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(254333, 7, 36542, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(254305, 7, 36542, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(254332, 7, 36542, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(254331, 7, 34334, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Chair
(254327, 7, 34367, 'Bench', '', '', '', 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(254326, 7, 34367, 'Bench', '', '', '', 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(254580, 7, 34334, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Chair
(254579, 7, 34334, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Chair
(254578, 7, 34334, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Chair
(254319, 7, 34334, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Chair
(254321, 7, 34334, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Chair
(254320, 7, 34334, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Chair
(254322, 7, 36542, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(254323, 7, 36542, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(254318, 7, 36542, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(254317, 7, 36542, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(254316, 7, 36542, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(279671, 22, 36654, 'Portal to Shal''Aran', '', '', '', 1, 263029, -1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Portal to Shal'Aran
(254454, 7, 36542, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(254467, 7, 36542, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(254465, 7, 36542, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(254452, 7, 36542, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(254345, 7, 36542, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(254340, 7, 36542, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(254338, 7, 36542, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(254336, 7, 36542, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(254464, 7, 36542, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(251208, 5, 30913, 'Quarter-Full Glass of Mana Wine', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Quarter-Full Glass of Mana Wine
(266555, 1, 35138, 'Pre Suramar 7.0 Complete Barrel', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Pre Suramar 7.0 Complete Barrel
(266556, 1, 35138, 'Pre Suramar 7.0 Complete Barrel', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Pre Suramar 7.0 Complete Barrel
(254570, 7, 34367, 'Bench', '', '', '', 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(258683, 5, 37529, 'Doodad_7vs_roadrock_a029', '', '', '', 1.15567, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7vs_roadrock_a029
(258681, 5, 25392, 'Doodad_7ne_nightelf_barrel004', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_nightelf_barrel004
(258678, 5, 37530, 'Doodad_7vs_roadrock_a026', '', '', '', 1.111629, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7vs_roadrock_a026
(258649, 5, 37531, 'Doodad_7vs_roadrock_a015', '', '', '', 2.75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7vs_roadrock_a015
(258645, 5, 37529, 'Doodad_7vs_roadrock_a011', '', '', '', 1.67, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7vs_roadrock_a011
(258632, 5, 37528, 'Doodad_7ne_druid_wallshelf001', '', '', '', 1.09, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_druid_wallshelf001
(258631, 5, 37527, 'Doodad_7ne_druid_table001', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_druid_table001
(258627, 5, 25508, 'Doodad_7ne_nightelf_box001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_nightelf_box001
(258622, 5, 25392, 'Doodad_7ne_nightelf_barrel001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_nightelf_barrel001
(258679, 5, 37530, 'Doodad_7vs_roadrock_a027', '', '', '', 1.764985, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7vs_roadrock_a027
(258680, 5, 37529, 'Doodad_7vs_roadrock_a028', '', '', '', 1.444979, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7vs_roadrock_a028
(258659, 5, 27535, 'Doodad_7ne_druid_waterbrazier001', '', '', '', 0.71, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_druid_waterbrazier001
(258668, 5, 37533, 'Doodad_7ne_druid_basket003', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_druid_basket003
(258661, 5, 37533, 'Doodad_7ne_druid_basket001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_druid_basket001
(258669, 5, 30083, 'Doodad_7ne_nightelf_crate002', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_nightelf_crate002
(258682, 5, 37533, 'Doodad_7ne_druid_basket006', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_druid_basket006
(258677, 5, 37529, 'Doodad_7vs_roadrock_a025', '', '', '', 0.8049789, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7vs_roadrock_a025
(258676, 5, 37530, 'Doodad_7vs_roadrock_a024', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7vs_roadrock_a024
(258675, 5, 37529, 'Doodad_7vs_roadrock_a023', '', '', '', 1.510093, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7vs_roadrock_a023
(258658, 5, 37526, 'Doodad_7ne_druid_plantpot_large004', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_druid_plantpot_large004
(258656, 5, 37528, 'Doodad_7ne_druid_wallshelf004', '', '', '', 1.09, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_druid_wallshelf004
(258685, 5, 37529, 'Doodad_7vs_roadrock_a031', '', '', '', 0.804979, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7vs_roadrock_a031
(258684, 5, 37529, 'Doodad_7vs_roadrock_a030', '', '', '', 1.510093, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7vs_roadrock_a030
(258667, 5, 37535, 'Doodad_7ne_druid_table002', '', '', '', 1.149768, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_druid_table002
(258666, 5, 37525, 'Doodad_7ne_druid_plantpot_large006', '', '', '', 0.7699998, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_druid_plantpot_large006
(258665, 5, 32841, 'Doodad_7ne_druid_plantpot_small001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_druid_plantpot_small001
(258664, 5, 37526, 'Doodad_7ne_druid_plantpot_large005', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_druid_plantpot_large005
(258663, 5, 37534, 'Doodad_7ne_druid_foodnuts001', '', '', '', 1.65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_druid_foodnuts001
(258662, 5, 28723, 'Doodad_7ne_druid_basket002', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_druid_basket002
(258660, 5, 37532, 'Doodad_7ne_druid_cup001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_druid_cup001
(258657, 5, 37525, 'Doodad_7ne_druid_plantpot_large003', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_druid_plantpot_large003
(258655, 5, 37528, 'Doodad_7ne_druid_wallshelf003', '', '', '', 1.09, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_druid_wallshelf003
(258651, 5, 37531, 'Doodad_7vs_roadrock_a017', '', '', '', 2.079508, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7vs_roadrock_a017
(258643, 5, 37530, 'Doodad_7vs_roadrock_a009', '', '', '', 0.8688315, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7vs_roadrock_a009
(258673, 5, 30083, 'Doodad_7ne_nightelf_crate003', '', '', '', 0.8800001, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_nightelf_crate003
(258650, 5, 37530, 'Doodad_7vs_roadrock_a016', '', '', '', 1.357974, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7vs_roadrock_a016
(258647, 5, 37529, 'Doodad_7vs_roadrock_a013', '', '', '', 1.79, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7vs_roadrock_a013
(265439, 5, 33841, 'Doodad_7sr_hubmanatree_lightbeam002', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7sr_hubmanatree_lightbeam002
(245795, 5, 324, 'Throndyr''s Pyre', '', '', '', 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Throndyr's Pyre
(258674, 5, 25392, 'Doodad_7ne_nightelf_barrel003', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_nightelf_barrel003
(258648, 5, 37531, 'Doodad_7vs_roadrock_a014', '', '', '', 2.57, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7vs_roadrock_a014
(258644, 5, 37529, 'Doodad_7vs_roadrock_a010', '', '', '', 1.790001, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7vs_roadrock_a010
(258642, 5, 37529, 'Doodad_7vs_roadrock_a008', '', '', '', 1.67, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7vs_roadrock_a008
(258641, 5, 37529, 'Doodad_7vs_roadrock_a007', '', '', '', 1.857201, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7vs_roadrock_a007
(258640, 5, 37530, 'Doodad_7vs_roadrock_a006', '', '', '', 0.82939, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7vs_roadrock_a006
(258638, 5, 37529, 'Doodad_7vs_roadrock_a004', '', '', '', 1.510093, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7vs_roadrock_a004
(258637, 5, 37530, 'Doodad_7vs_roadrock_a003', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7vs_roadrock_a003
(258639, 5, 37530, 'Doodad_7vs_roadrock_a005', '', '', '', 1.864985, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7vs_roadrock_a005
(258636, 5, 37530, 'Doodad_7vs_roadrock_a002', '', '', '', 1.111629, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7vs_roadrock_a002
(258635, 5, 37529, 'Doodad_7vs_roadrock_a001', '', '', '', 0.804979, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7vs_roadrock_a001
(260266, 22, 36654, 'Portal to Shal''Aran', '', '', '', 1, 202605, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Portal to Shal'Aran
(246462, 22, 31823, 'Elemental Summoner', 'questinteract', '', '', 0.5, 201717, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Elemental Summoner
(265444, 5, 33845, 'Doodad_7sr_hubmanatree_lightbeam004', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7sr_hubmanatree_lightbeam004
(247848, 10, 32409, 'Mail Tube', '', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 206185, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 38795, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mail Tube
(249351, 5, 27535, 'Imbued Waters', '', '', '', 0.5, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Imbued Waters
(248994, 43, 34482, 'Moonwell', '', '', '', 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Moonwell
(248116, 5, 32573, 'Grass Tall', '', '', '', 0.6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Grass Tall
(252444, 5, 35194, 'Peace Lily', '', '', '', 0.2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Peace Lily
(248115, 5, 32573, 'Grass Short', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996); -- Grass Short

UPDATE `gameobject_template` SET `name`='Portal to The Waning Crescent', `VerifiedBuild`=25996 WHERE `entry`=254137; -- Portal to The Waning Crescent
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254472; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254473; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254453; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254337; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254395; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254394; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254550; -- Bench
UPDATE `gameobject_template` SET `type`=3, `displayId`=33265, `castBarCaption`='Opening', `Data0`=57, `Data2`=1, `Data13`=1, `Data14`=21400, `Data18`=110, `Data19`=3, `Data29`=1594, `Data30`=67972, `RequiredLevel`=110, `VerifiedBuild`=25996 WHERE `entry`=252844; -- Treasure Chest
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266477; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266476; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266475; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266474; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253313; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253310; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266480; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266479; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266478; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253312; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253311; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266633; -- Teleporter Pad
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266574; -- Teleporter Pad
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266573; -- Teleporter Pad
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254484; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254485; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254483; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254482; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254478; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254479; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254481; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254497; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254489; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254480; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254637; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254498; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254499; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=250238; -- Gondola
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254475; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254476; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254474; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254477; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254565; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254674; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253333; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253330; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253329; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253332; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253331; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253334; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254566; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254567; -- Bench
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=257393; -- Treasure Chest
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254568; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253388; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252487; -- Window
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252474; -- Window
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252473; -- Window
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254546; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254408; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252472; -- Window
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252486; -- Window
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=255288; -- Window
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=252842; -- Treasure Chest
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=257548; -- Window
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252508; -- Window
UPDATE `gameobject_template` SET `castBarCaption`='Gathering', `Data1`=70255, `Data3`=0, `Data6`=30, `Data9`=24982, `Data13`=0, `Data14`=228183, `Data18`=10, `Data19`=1, `Data26`=0, `Data30`=0, `VerifiedBuild`=25996 WHERE `entry`=260493; -- Mana-Infused Gem
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252509; -- Window
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=255287; -- Window
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=255242; -- Window
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252501; -- Window
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254564; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252505; -- Window
UPDATE `gameobject_template` SET `castBarCaption`='Taking', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=246266; -- Custom Jewelry Order
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254407; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254575; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252502; -- Window
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252497; -- Window
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252498; -- Window
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252499; -- Window
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254628; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254422; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254398; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252477; -- Window
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254397; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252475; -- Window
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252476; -- Window
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254406; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252512; -- Window
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252510; -- Window
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252511; -- Window
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254659; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254662; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254660; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252490; -- Window
UPDATE `gameobject_template` SET `castBarCaption`='Taking', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=252692; -- Nightborne Jewelry Case
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254490; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254661; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254400; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252489; -- Window
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254641; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254643; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254644; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254486; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254646; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254488; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254645; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254504; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254650; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254487; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254503; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254648; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254501; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254502; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254600; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254500; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254656; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254654; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254658; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254657; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254642; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254494; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254493; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254495; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254446; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254438; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254437; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254496; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254440; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254444; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254441; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254442; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254491; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254663; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254664; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254492; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254640; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253314; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254396; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=250240; -- Bottle of Arcwine
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=250239; -- Bottle of Arcwine
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=250086; -- Cask of Arcwine
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254667; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254509; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254507; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254543; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254387; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253308; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254544; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254540; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254510; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254508; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254447; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253309; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254506; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254505; -- Bench
UPDATE `gameobject_template` SET `type`=3, `displayId`=33265, `castBarCaption`='Opening', `Data0`=57, `Data2`=1, `Data13`=1, `Data14`=21400, `Data18`=110, `Data19`=3, `Data29`=1676, `Data30`=69082, `RequiredLevel`=110, `VerifiedBuild`=25996 WHERE `entry`=257546; -- Treasure Chest
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254541; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254542; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254593; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254594; -- Bench
UPDATE `gameobject_template` SET `Data1`=70255, `Data3`=0, `Data6`=30, `Data13`=0, `Data14`=228183, `Data18`=10, `Data19`=1, `Data26`=0, `Data30`=0, `VerifiedBuild`=25996 WHERE `entry`=260492; -- Glowing Tome
UPDATE `gameobject_template` SET `type`=3, `displayId`=33264, `castBarCaption`='Opening', `Data0`=57, `Data2`=1, `Data13`=1, `Data14`=21400, `Data18`=110, `Data19`=3, `Data29`=1590, `Data30`=67968, `RequiredLevel`=110, `VerifiedBuild`=25996 WHERE `entry`=252839; -- Small Treasure Chest
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254307; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253344; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253343; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253341; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254325; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254324; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254328; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254315; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254314; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254313; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254312; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254311; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254310; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254309; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254308; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254306; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253342; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253383; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253382; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253381; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252493; -- Window
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253380; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253379; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253378; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252492; -- Window
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253376; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253377; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253375; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254378; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254380; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254377; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254379; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254596; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254384; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254382; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254383; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254381; -- Chair
UPDATE `gameobject_template` SET `castBarCaption`='Gathering', `Data1`=70256, `Data3`=0, `Data6`=30, `Data9`=24982, `Data13`=0, `Data14`=228183, `Data18`=10, `Data19`=1, `Data26`=0, `Data30`=0, `VerifiedBuild`=25996 WHERE `entry`=260494; -- Twice-Fortified Arcwine
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254599; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254598; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254595; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252156; -- Window
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254589; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252157; -- Window
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252152; -- Window
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254591; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254590; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254597; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254592; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254584; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254583; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254582; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254581; -- Chair
UPDATE `gameobject_template` SET `type`=3, `displayId`=33264, `castBarCaption`='Opening', `Data0`=57, `Data2`=1, `Data13`=1, `Data14`=21400, `Data18`=110, `Data19`=3, `Data29`=1592, `Data30`=67970, `RequiredLevel`=110, `VerifiedBuild`=25996 WHERE `entry`=252841; -- Small Treasure Chest
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254585; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254587; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254586; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254588; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=250609; -- Teleporter Pad
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=253392; -- Telemancy Beacon
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253320; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253318; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253319; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253317; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253316; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253322; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254535; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254536; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254537; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254539; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253321; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253315; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254538; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254451; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254448; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254386; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254450; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254449; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254385; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254666; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254665; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254638; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254670; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252060; -- Window
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252491; -- Window
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254671; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254639; -- Bench
UPDATE `gameobject_template` SET `castBarCaption`='Placing seal.', `VerifiedBuild`=25996 WHERE `entry`=252776; -- Arcway Outlet
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254627; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254626; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254392; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254390; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253374; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253373; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254393; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254391; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=257547; -- Window
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=252840; -- Small Treasure Chest
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253371; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253372; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253370; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253369; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254435; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253368; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252458; -- Window
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252460; -- Window
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252459; -- Window
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253387; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253386; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253385; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253384; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254651; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254652; -- Bench
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=257545; -- Treasure Chest
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254428; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254533; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254534; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254426; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254417; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254558; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254427; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254416; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254653; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254415; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254434; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254630; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254629; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254669; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254631; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254433; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254423; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254602; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254633; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254632; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254425; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254635; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254563; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254562; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254561; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254560; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254634; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254424; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254405; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254676; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254668; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254675; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252456; -- Window
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254420; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254421; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254559; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254547; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=253307; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254548; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254413; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254699; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254686; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266032; -- Nightborne Arms Cache
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254414; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254685; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254702; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254687; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254700; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254399; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254701; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254688; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254401; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254532; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254531; -- Bench
UPDATE `gameobject_template` SET `name`='Sentenced for bribing an official.', `VerifiedBuild`=25996 WHERE `entry`=257482; -- Sentenced for bribing an official.
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254576; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254574; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254530; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254680; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254691; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254521; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254694; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254522; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254679; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254529; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254471; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254681; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254692; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254519; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254470; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254693; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254682; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254520; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254523; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254524; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254572; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254573; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254696; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254678; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254697; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254527; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254526; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254683; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254677; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254528; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254695; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254684; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254698; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254525; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254518; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254517; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254374; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254545; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254375; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254376; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254334; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254301; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254335; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254516; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258026; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255107; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=251190; -- Containment Field
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254300; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254299; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254298; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254297; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258148; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255108; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254515; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258149; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258027; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=259191; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=259190; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=259192; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=259189; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=259188; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=259187; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258215; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258214; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258213; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258212; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=206602; -- Guild Chest
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=254289; -- Pride of the Menagerie
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=254281; -- Beasts of Barren Savannas
UPDATE `gameobject_template` SET `castBarCaption`='Attuning', `VerifiedBuild`=25996 WHERE `entry`=252557; -- Hungering Orb
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252258; -- Leyline Feed
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `VerifiedBuild`=25996 WHERE `entry`=252837; -- Treasure Chest
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `VerifiedBuild`=25996 WHERE `entry`=252836; -- Small Treasure Chest
UPDATE `gameobject_template` SET `type`=3, `displayId`=27856, `IconName`='questinteract', `castBarCaption`='Collecting', `Data0`=93, `Data14`=19676, `Data30`=65128, `RequiredLevel`=110, `VerifiedBuild`=25996 WHERE `entry`=247851; -- Sealed Powder Keg
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `VerifiedBuild`=25996 WHERE `entry`=248080; -- Needle Coral
UPDATE `gameobject_template` SET `type`=10, `displayId`=12777, `IconName`='openhandglow', `castBarCaption`='Collecting', `size`=0.05, `Data0`=43, `Data5`=1, `Data10`=204856, `Data14`=19676, `Data23`=1, `VerifiedBuild`=25996 WHERE `entry`=247415; -- Condensed Energy
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `VerifiedBuild`=25996 WHERE `entry`=252835; -- Small Treasure Chest
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `VerifiedBuild`=25996 WHERE `entry`=246923; -- Toryl's Cage
UPDATE `gameobject_template` SET `name`='Cracked Powder Keg', `VerifiedBuild`=25996 WHERE `entry`=248405; -- Cracked Powder Keg
UPDATE `gameobject_template` SET `name`='Sashj''tar Trident', `VerifiedBuild`=25996 WHERE `entry`=247944; -- Sashj'tar Trident
UPDATE `gameobject_template` SET `name`='Spine', `VerifiedBuild`=25996 WHERE `entry`=247068; -- Spine
UPDATE `gameobject_template` SET `name`='Ribcage', `VerifiedBuild`=25996 WHERE `entry`=247066; -- Ribcage
UPDATE `gameobject_template` SET `name`='Rib Bones', `VerifiedBuild`=25996 WHERE `entry`=247067; -- Rib Bones
UPDATE `gameobject_template` SET `name`='Sashj''tar Weapons', `VerifiedBuild`=25996 WHERE `entry`=246858; -- Sashj'tar Weapons
UPDATE `gameobject_template` SET `name`='Cage', `VerifiedBuild`=25996 WHERE `entry`=249369; -- Cage
UPDATE `gameobject_template` SET `name`='Cage', `VerifiedBuild`=25996 WHERE `entry`=249370; -- Cage
UPDATE `gameobject_template` SET `name`='Cage', `VerifiedBuild`=25996 WHERE `entry`=249367; -- Cage
UPDATE `gameobject_template` SET `name`='Cage', `VerifiedBuild`=25996 WHERE `entry`=249368; -- Cage
UPDATE `gameobject_template` SET `name`='Cage', `VerifiedBuild`=25996 WHERE `entry`=249366; -- Cage
UPDATE `gameobject_template` SET `name`='Cage', `VerifiedBuild`=25996 WHERE `entry`=249375; -- Cage
UPDATE `gameobject_template` SET `name`='Cage', `VerifiedBuild`=25996 WHERE `entry`=249372; -- Cage
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=247064; -- Sashj'tar Cage
UPDATE `gameobject_template` SET `name`='Cage', `VerifiedBuild`=25996 WHERE `entry`=249371; -- Cage
UPDATE `gameobject_template` SET `name`='Cage', `VerifiedBuild`=25996 WHERE `entry`=249373; -- Cage
UPDATE `gameobject_template` SET `name`='Cage', `VerifiedBuild`=25996 WHERE `entry`=249374; -- Cage
UPDATE `gameobject_template` SET `name`='Cage', `VerifiedBuild`=25996 WHERE `entry`=249377; -- Cage
UPDATE `gameobject_template` SET `name`='Cage', `VerifiedBuild`=25996 WHERE `entry`=249376; -- Cage
UPDATE `gameobject_template` SET `name`='Cage', `VerifiedBuild`=25996 WHERE `entry`=249365; -- Cage
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `VerifiedBuild`=25996 WHERE `entry`=245321; -- Katarine's Cage
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `VerifiedBuild`=25996 WHERE `entry`=245887; -- Driftwood
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `VerifiedBuild`=25996 WHERE `entry`=245792; -- Driftwood
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=252834; -- Small Treasure Chest
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=246798; -- Sashj'tar Ballista
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266175; -- Fel Rune
UPDATE `gameobject_template` SET `name`='Sashj''tar Banner', `VerifiedBuild`=25996 WHERE `entry`=246799; -- Sashj'tar Banner
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266171; -- Fel Rune
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=252832; -- Small Treasure Chest
UPDATE `gameobject_template` SET `name`='Sprung Trap', `VerifiedBuild`=25996 WHERE `entry`=248396; -- Sprung Trap
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252259; -- Leyline Feed
UPDATE `gameobject_template` SET `castBarCaption`='Activating', `VerifiedBuild`=25996 WHERE `entry`=253071; -- Leyline Feed Primer
UPDATE `gameobject_template` SET `type`=10, `displayId`=36092, `IconName`='questinteract', `castBarCaption`='Opening', `Data0`=2647, `Data3`=1, `Data14`=21400, `Data20`=1, `VerifiedBuild`=25996 WHERE `entry`=267065; -- Nightborne Cage
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=247412; -- Arcane Trap
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266172; -- Book
UPDATE `gameobject_template` SET `type`=10, `displayId`=34013, `IconName`='questinteract', `castBarCaption`='Infusing...', `Data0`=43, `Data3`=3000, `Data10`=217672, `Data14`=120660, `Data20`=1, `Data22`=41238, `Data23`=1, `VerifiedBuild`=25996 WHERE `entry`=251565; -- Unfortified Arcwine
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=251556; -- Energy Vessel
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=251507; -- Unctuous Draught
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=251506; -- Supple Nectar
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=251499; -- Honeyed Infusion
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255183; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255184; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255185; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255186; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=254288; -- Pride of the Menagerie
UPDATE `gameobject_template` SET `type`=25, `displayId`=18020, `size`=3, `Data0`=15, `Data1`=72122, `Data2`=65535, `Data3`=65535, `Data4`=1628, `VerifiedBuild`=25996 WHERE `entry`=273294; -- School of Golden Minnows
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258102; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258101; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258098; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258097; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258096; -- Chair
UPDATE `gameobject_template` SET `name`='Right Chamber - I - Clean - Rug', `VerifiedBuild`=25996 WHERE `entry`=253758; -- Right Chamber - I - Clean - Rug
UPDATE `gameobject_template` SET `name`='Right Chamber - I - Clean - Table', `VerifiedBuild`=25996 WHERE `entry`=253753; -- Right Chamber - I - Clean - Table
UPDATE `gameobject_template` SET `name`='Right Chamber - I - Clean - Scrollbag', `VerifiedBuild`=25996 WHERE `entry`=253750; -- Right Chamber - I - Clean - Scrollbag
UPDATE `gameobject_template` SET `name`='Right Chamber - I - Clean - Pedestal', `VerifiedBuild`=25996 WHERE `entry`=253749; -- Right Chamber - I - Clean - Pedestal
UPDATE `gameobject_template` SET `name`='Right Chamber - I - Clean - Scrollpile 01', `VerifiedBuild`=25996 WHERE `entry`=253748; -- Right Chamber - I - Clean - Scrollpile 01
UPDATE `gameobject_template` SET `name`='Right Chamber - I - Clean - Scrollopen', `VerifiedBuild`=25996 WHERE `entry`=253747; -- Right Chamber - I - Clean - Scrollopen
UPDATE `gameobject_template` SET `name`='Right Chamber - I - Clean - Scrollpile 02', `VerifiedBuild`=25996 WHERE `entry`=253746; -- Right Chamber - I - Clean - Scrollpile 02
UPDATE `gameobject_template` SET `name`='Right Chamber - I - Clean - Pylon 01', `VerifiedBuild`=25996 WHERE `entry`=253705; -- Right Chamber - I - Clean - Pylon 01
UPDATE `gameobject_template` SET `name`='Right Chamber - I - Clean - Pylon 02', `VerifiedBuild`=25996 WHERE `entry`=253704; -- Right Chamber - I - Clean - Pylon 02
UPDATE `gameobject_template` SET `name`='Right Chamber - I - Clean - Floatingbook', `VerifiedBuild`=25996 WHERE `entry`=253702; -- Right Chamber - I - Clean - Floatingbook
UPDATE `gameobject_template` SET `name`='Portal to Moon Guard Stronghold', `VerifiedBuild`=25996 WHERE `entry`=254135; -- Portal to Moon Guard Stronghold
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254858; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254857; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254863; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254859; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252814; -- Unpowered Telemancy Beacon
UPDATE `gameobject_template` SET `Data1`=68401, `VerifiedBuild`=25996 WHERE `entry`=254023; -- Arcane Power Unit
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=246702; -- Anthology of the Guard
UPDATE `gameobject_template` SET `name`='Unfinished Spellwork', `VerifiedBuild`=25996 WHERE `entry`=247044; -- Unfinished Spellwork
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=246704; -- Aftermath of the Well
UPDATE `gameobject_template` SET `name`='Mana Focuser', `VerifiedBuild`=25996 WHERE `entry`=246940; -- Mana Focuser
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250307; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250306; -- Chair
UPDATE `gameobject_template` SET `name`='Mailbox', `VerifiedBuild`=25996 WHERE `entry`=242044; -- Mailbox
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250400; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250399; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250398; -- Chair
UPDATE `gameobject_template` SET `type`=3, `displayId`=8345, `Data3`=1, `Data30`=71613, `VerifiedBuild`=25996 WHERE `entry`=268047; -- Archimonde's Return and the Flight to Kalimdor
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=251212; -- Magical Tome
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=251210; -- Crystal Ball
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=251209; -- Frosted Doughnut
UPDATE `gameobject_template` SET `type`=3, `displayId`=34085, `IconName`='questinteract', `castBarCaption`='Retrieving', `Data0`=1691, `Data2`=1, `Data6`=51916, `Data14`=23645, `Data26`=215528, `Data30`=66210, `VerifiedBuild`=25996 WHERE `entry`=250417; -- Archmage Vargoth's Journal
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250406; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250405; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250403; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250402; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250401; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250396; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250407; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250404; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250397; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250395; -- Chair
UPDATE `gameobject_template` SET `type`=3, `displayId`=9450, `Data3`=1, `Data30`=71639, `VerifiedBuild`=25996 WHERE `entry`=268079; -- The New Horde
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=35591; -- Fishing Bobber
UPDATE `gameobject_template` SET `type`=3, `displayId`=41744, `IconName`='pickup', `castBarCaption`='Looting', `size`=0.5, `Data0`=43, `Data1`=72491, `Data3`=1, `Data14`=108144, `VerifiedBuild`=25996 WHERE `entry`=269037; -- Loose Pebble
UPDATE `gameobject_template` SET `type`=10, `displayId`=8399, `size`=0.75, `Data3`=3000, `Data5`=1, `Data10`=210598, `Data23`=1, `VerifiedBuild`=25996 WHERE `entry`=244950; -- Dusty Rug
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=252821; -- Treasure Chest
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=252820; -- Small Treasure Chest
UPDATE `gameobject_template` SET `type`=2, `displayId`=34065, `Data1`=20393, `VerifiedBuild`=25996 WHERE `entry`=252261; -- Leyline Feed
UPDATE `gameobject_template` SET `type`=10, `displayId`=27535, `IconName`='questinteract', `size`=0.5, `Data0`=2536, `Data3`=3000, `Data10`=209883, `Data20`=1, `Data23`=1, `VerifiedBuild`=25996 WHERE `entry`=249023; -- Inert Waters
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252260; -- Leyline Feed
UPDATE `gameobject_template` SET `type`=3, `displayId`=34727, `IconName`='openhandglow', `castBarCaption`='Retrieving', `size`=1.5, `Data0`=1691, `Data4`=1, `Data5`=1, `Data14`=23645, `Data16`=1, `Data30`=67967, `Data31`=1, `VerifiedBuild`=25996 WHERE `entry`=252879; -- The Winterskorn War
UPDATE `gameobject_template` SET `castBarCaption`='Gathering', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=244853; -- Tharillon's Stash
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=246703; -- Magical Manifest of the Moon
UPDATE `gameobject_template` SET `Data1`=67839, `VerifiedBuild`=25996 WHERE `entry`=246816; -- Hippogryph Vial

DELETE FROM `gameobject_questitem` WHERE (`GameObjectEntry`=252879 AND `Idx`=0);
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(252879, 0, 140131, 25996); -- The Winterskorn War

UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=246266 AND `Idx`=0); -- Custom Jewelry Order
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=252692 AND `Idx`=0); -- Nightborne Jewelry Case
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=250240 AND `Idx`=0); -- Bottle of Arcwine
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=250239 AND `Idx`=0); -- Bottle of Arcwine
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=247851 AND `Idx`=0); -- Sealed Powder Keg
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=248080 AND `Idx`=0); -- Needle Coral
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=245887 AND `Idx`=0); -- Driftwood
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=245792 AND `Idx`=0); -- Driftwood
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=247412 AND `Idx`=0); -- Arcane Trap
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=246702 AND `Idx`=0); -- Anthology of the Guard
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=246704 AND `Idx`=0); -- Aftermath of the Well
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=250417 AND `Idx`=0); -- Archmage Vargoth's Journal
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=244853 AND `Idx`=0); -- Tharillon's Stash
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=246703 AND `Idx`=0); -- Magical Manifest of the Moon

DELETE FROM `npc_text` WHERE `ID` IN (27208 /*27208*/, 30434 /*30434*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(27208, 1, 0, 0, 0, 0, 0, 0, 0, 98622, 0, 0, 0, 0, 0, 0, 0, 25996), -- 27208
(30434, 1, 0, 0, 0, 0, 0, 0, 0, 122238, 0, 0, 0, 0, 0, 0, 0, 25996); -- 30434

UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=27820; -- 27820
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=29185; -- 29185
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=29184; -- 29184
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=29607; -- 29607
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=29442; -- 29442
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=29441; -- 29441
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=29440; -- 29440
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=29439; -- 29439
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=29308; -- 29308
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=29914; -- 29914
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=28244; -- 28244
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=30524; -- 30524
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=27720; -- 27720
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=27706; -- 27706
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=28438; -- 28438
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=29913; -- 29913
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=11093; -- 11093
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=28360; -- 28360
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=28442; -- 28442
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=30627; -- 30627
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=7778; -- 7778

