DELETE FROM `creature_template_addon` WHERE `entry`=120652;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(120652, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- 120652 (Global Affix Stalker)

UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=106785; -- 106785 (Bitterbrine Slave)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=106787; -- 106787 (Bitterbrine Slave)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=106786; -- 106786 (Bitterbrine Slave)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=91808; -- 91808 (Serpentrix)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=95920; -- 95920 (Animated Storm)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=97170; -- Lieuse de vague glissefiel
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=97173; -- 97173 (Restless Tides)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=97172; -- 97172 (Saltsea Droplet)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=91787; -- 91787 (Cove Seagull)
UPDATE `creature_template_addon` SET `auras`='199865 197115' WHERE `entry`=97171; -- 97171 (Hatecoil Arcanist)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=91782; -- 91782 (Hatecoil Crusher)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=95861; -- 95861 (Hatecoil Oracle)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=100216; -- 100216 (Hatecoil Wrangler)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=91781; -- 91781 (Hatecoil Warrior)

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (99901, 97853, 97713, 97063);
INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingMin`, `LevelScalingMax`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `VerifiedBuild`) VALUES
(99901, 98, 110, 0, 0, 26654),
(97853, 98, 110, 0, 0, 26654),
(97713, 98, 110, 0, 0, 26654),
(97063, 98, 110, 0, 0, 26654);



UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=67001;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=66508;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=66509;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=66510;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=65110;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=31183;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=66819;
UPDATE `creature_model_info` SET `BoundingRadius`=1.614789, `VerifiedBuild`=26654 WHERE `DisplayID`=4878;
UPDATE `creature_model_info` SET `BoundingRadius`=1.042447, `VerifiedBuild`=26654 WHERE `DisplayID`=23504;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=19365;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=66397;
UPDATE `creature_model_info` SET `BoundingRadius`=2.505799, `CombatReach`=3.5, `VerifiedBuild`=26654 WHERE `DisplayID`=66535;
UPDATE `creature_model_info` SET `BoundingRadius`=2.505799, `CombatReach`=3.5, `VerifiedBuild`=26654 WHERE `DisplayID`=66534;
UPDATE `creature_model_info` SET `BoundingRadius`=2.505799, `CombatReach`=3.5, `VerifiedBuild`=26654 WHERE `DisplayID`=66536;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=67254;
UPDATE `creature_model_info` SET `BoundingRadius`=2.013742, `VerifiedBuild`=26654 WHERE `DisplayID`=36212;
UPDATE `creature_model_info` SET `BoundingRadius`=2.505799, `CombatReach`=3.5, `VerifiedBuild`=26654 WHERE `DisplayID`=29934;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=11686;
UPDATE `creature_model_info` SET `BoundingRadius`=5.497285, `VerifiedBuild`=26654 WHERE `DisplayID`=65114;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=51219;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=25675;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=39490;
UPDATE `creature_model_info` SET `BoundingRadius`=2.147828, `VerifiedBuild`=26654 WHERE `DisplayID`=66163;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=66813;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=66152;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=69708;
UPDATE `creature_model_info` SET `BoundingRadius`=1.217102, `VerifiedBuild`=26654 WHERE `DisplayID`=66153;
UPDATE `creature_model_info` SET `BoundingRadius`=1.92405, `VerifiedBuild`=26654 WHERE `DisplayID`=18393;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=45060;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=45568;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=51409;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=51124;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=32063;
UPDATE `creature_model_info` SET `VerifiedBuild`=26654 WHERE `DisplayID`=16925;
UPDATE `creature_model_info` SET `BoundingRadius`=2.198914, `VerifiedBuild`=26654 WHERE `DisplayID`=66499;


UPDATE `creature_equip_template` SET `ItemID3`=45872 WHERE (`CreatureID`=91789 AND `ID`=1); -- Lady Hatecoil


UPDATE `creature_template` SET `minlevel`=110 WHERE `entry`=106785; -- Bitterbrine Slave
UPDATE `creature_template` SET `minlevel`=110 WHERE `entry`=106787; -- Bitterbrine Slave
UPDATE `creature_template` SET `minlevel`=110 WHERE `entry`=106786; -- Bitterbrine Slave
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112 WHERE `entry`=91808; -- Serpentrix
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `speed_run`=1.142857 WHERE `entry`=91796; -- Skrog Wavecrasher
UPDATE `creature_template` SET `minlevel`=110 WHERE `entry`=95920; -- Animated Storm
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `unit_flags3`=1 WHERE `entry`=91789; -- Lady Hatecoil
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111 WHERE `entry`=100249; -- Channeler Varisz
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `unit_flags3`=1 WHERE `entry`=100248; -- Ritualist Lesha
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111 WHERE `entry`=100250; -- Binder Ashioi
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=97063; -- Weatherman
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112 WHERE `entry`=91797; -- King Deepbeard
UPDATE `creature_template` SET `minlevel`=110, `speed_walk`=1 WHERE `entry`=97173; -- Restless Tides
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111 WHERE `entry`=98173; -- Mystic Ssa'veh
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=97713; -- Lightning Stalker
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112 WHERE `entry`=91784; -- Warlord Parjesh
UPDATE `creature_template` SET `minlevel`=110 WHERE `entry`=91786; -- Gritslime Snail
UPDATE `creature_template` SET `minlevel`=110 WHERE `entry`=97172; -- Saltsea Droplet
UPDATE `creature_template` SET `minlevel`=110 WHERE `entry`=91787; -- Cove Seagull
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111 WHERE `entry`=97171; -- Hatecoil Arcanist
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111 WHERE `entry`=91782; -- Hatecoil Crusher
UPDATE `creature_template` SET `minlevel`=110 WHERE `entry`=91783; -- Hatecoil Stormweaver
UPDATE `creature_template` SET `minlevel`=110 WHERE `entry`=95861; -- Hatecoil Oracle
UPDATE `creature_template` SET `minlevel`=110 WHERE `entry`=100216; -- Hatecoil Wrangler
UPDATE `creature_template` SET `minlevel`=110 WHERE `entry`=91785; -- Wandering Shellback
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=1073743872, `unit_flags3`=1 WHERE `entry`=120652; -- Global Affix Stalker
UPDATE `creature_template` SET `minlevel`=110 WHERE `entry`=91781; -- Hatecoil Warrior


UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=111221; -- Xal'atath
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=106785; -- Bitterbrine Slave
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=106787; -- Bitterbrine Slave
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=106786; -- Bitterbrine Slave
UPDATE `creature_template` SET `type`=1, `VerifiedBuild`=26654 WHERE `entry`=91808; -- Serpentrix
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=97853; -- Sand Dune
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=97170; -- Lieuse de vague glissefiel
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=95920; -- Animated Storm
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=91796; -- Skrog Wavecrasher
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=100688; -- Brightscale Darters
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=91797; -- King Deepbeard
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=100249; -- Channeler Varisz
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=100248; -- Ritualist Lesha
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=100250; -- Binder Ashioi
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=91789; -- Lady Hatecoil
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=97063; -- Weatherman
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=97713; -- Lightning Stalker
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=98173; -- Mystic Ssa'veh
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=97173; -- Restless Tides
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=91787; -- Cove Seagull
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=97172; -- Saltsea Droplet
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=91784; -- Warlord Parjesh
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=91786; -- Gritslime Snail
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=97171; -- Hatecoil Arcanist
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=91782; -- Hatecoil Crusher
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=305; -- Etalon blanc
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=32335; -- Griffon neigeux cuirassé
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=18406; -- Swift Blue Gryphon
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=14565; -- Charger
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=14505; -- Destrier de l'effroi
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=9158; -- Warhorse
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=65011; -- Albino Riding Crane
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=18362; -- Swift Purple Gryphon
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=304; -- Palefroi corrompu
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=95861; -- Hatecoil Oracle
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=91783; -- Hatecoil Stormweaver
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=111639; -- Aluneth
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=99901; -- Cove Seagull
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=91785; -- Wandering Shellback
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=100216; -- Hatecoil Wrangler
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=99908; -- Skittering Softshell
UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=26654 WHERE `entry`=124944; -- Drake bronze sans âge
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=40295; -- Rob-fusée mécanique bleu
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=97205; -- Dragonnet né-des-tempêtes
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=112144; -- Corgnelius
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=112132; -- Jeune chauve-souris de feu
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=99394; -- Ondulin fétide
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=106152; -- Bébé noble-bois
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=71033; -- Diablotin diabolique
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=71015; -- Gardien de ménagerie
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=111423; -- Wyrmelin détaché
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=35399; -- Jeune raptor d'obsidienne
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=97238; -- Araignée nourrice
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=113136; -- Bénax
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=99403; -- Jeune sabre fantomatique
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=98116; -- Méduse aiguemorne
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=97207; -- Emmigosa
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=108568; -- Chouette pygmée
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=90205; -- Fragment de désir
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=34364; -- Chat calico
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=7561; -- Serpent albinos
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=7382; -- Chat tigré roux
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=10, `type_flags`=1048576, `VerifiedBuild`=26654 WHERE `entry`=120652; -- Global Affix Stalker
UPDATE `creature_template` SET `VerifiedBuild`=26654 WHERE `entry`=91781; -- Hatecoil Warrior


UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=91808 AND `Idx`=4); -- Serpentrix
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=91808 AND `Idx`=3); -- Serpentrix
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=91808 AND `Idx`=2); -- Serpentrix
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=91808 AND `Idx`=1); -- Serpentrix
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=91808 AND `Idx`=0); -- Serpentrix
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=91797 AND `Idx`=1); -- King Deepbeard
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=91797 AND `Idx`=0); -- King Deepbeard
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=100249 AND `Idx`=0); -- Channeler Varisz
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=100248 AND `Idx`=0); -- Ritualist Lesha
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=100250 AND `Idx`=0); -- Binder Ashioi
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=91789 AND `Idx`=2); -- Lady Hatecoil
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=91789 AND `Idx`=1); -- Lady Hatecoil
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=91789 AND `Idx`=0); -- Lady Hatecoil
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=98173 AND `Idx`=0); -- Mystic Ssa'veh
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=91787 AND `Idx`=0); -- Cove Seagull
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=91784 AND `Idx`=1); -- Warlord Parjesh
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=91784 AND `Idx`=0); -- Warlord Parjesh
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=91785 AND `Idx`=1); -- Wandering Shellback
UPDATE `creature_questitem` SET `VerifiedBuild`=26654 WHERE (`CreatureEntry`=91785 AND `Idx`=0); -- Wandering Shellback

DELETE FROM `gameobject_template` WHERE `entry`=246779;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `VerifiedBuild`) VALUES
(246779, 49, 11554, 'Font of Power', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26654); -- Font of Power

UPDATE `gameobject_template` SET `name`='Water Door', `VerifiedBuild`=26654 WHERE `entry`=246983; -- Water Door
UPDATE `gameobject_template` SET `name`='Water Door', `VerifiedBuild`=26654 WHERE `entry`=246982; -- Water Door
UPDATE `gameobject_template` SET `VerifiedBuild`=26654 WHERE `entry`=240788; -- Bubble
UPDATE `gameobject_template` SET `VerifiedBuild`=26654 WHERE `entry`=244690; -- Sand Dune
UPDATE `gameobject_template` SET `VerifiedBuild`=26654 WHERE `entry`=252247; -- Instance Portal

UPDATE creature_template SET inhabitType = 4 WHERE entry IN (39375);

DELETE FROM scenarios WHERE map = 1466;
INSERT INTO scenarios VALUES
(1466, 0, 1172, 1172);
