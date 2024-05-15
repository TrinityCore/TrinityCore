SET @CGUID := 208509;
SET @OGUID := 152118;
SET @EVENT := 82;

-- Creature templates
DELETE FROM `creature_template_addon` WHERE `entry` IN (39711 /*39711 (Mechano-Tank Attack Target)*/, 39678 /*39678 (Toby Zeigear)*/, 39624 /*39624 (Motivated Citizen)*/, 39466 /*39466 (Motivated Citizen)*/, 39396 /*39396 ('Thunderflash')*/, 39386 /*39386 (Pilot Muzzlesprock)*/, 39368 /*39368 (Drill Sergeant Steamcrank)*/, 39349 /*39349 (Gnomeregan Trainee)*/, 39275 /*Gnomeregan Medic*/);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(39711, 0, 0, 0, 0, 1, 0, 0, 0, ''), -- 39711 (Mechano-Tank Attack Target)
(39678, 0, 0, 0, 0, 1, 0, 0, 0, ''), -- 39678 (Toby Zeigear)
(39624, 0, 0, 0, 0, 1, 0, 0, 0, ''), -- 39624 (Motivated Citizen)
(39466, 0, 0, 0, 0, 1, 0, 0, 0, ''), -- 39466 (Motivated Citizen)
(39396, 0, 1, 3, 0, 1, 0, 0, 0, ''), -- 39396 ('Thunderflash')
(39386, 0, 0, 0, 0, 1, 0, 0, 0, ''), -- 39386 (Pilot Muzzlesprock)
(39368, 0, 0, 0, 0, 1, 0, 0, 0, ''), -- 39368 (Drill Sergeant Steamcrank)
(39349, 0, 0, 0, 0, 1, 0, 0, 0, ''), -- 39349 (Gnomeregan Trainee)
(39275, 0, 0, 0, 0, 1, 0, 0, 0, ''); -- 39275 (Gnomeregan Medic)

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (39396, 39420, 39711);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(39396, 0, 0, 1, 0, 0, 0, NULL),
(39420, 0, 0, 1, 1, 0, 0, NULL),
(39711, 0, 0, 1, 1, 0, 0, NULL);

-- Old creature spawns
DELETE FROM `creature` WHERE `guid` IN (130847, 130848, 130849, 130853, 130855, 130906, 130907, 130908, 130971);
DELETE FROM `creature` WHERE `guid` BETWEEN 207174 AND 207209;
DELETE FROM `creature_addon` WHERE `guid` IN (130847, 130848, 130849, 130853, 130855, 130906, 130907, 130908, 130971);
DELETE FROM `creature_addon` WHERE `guid` BETWEEN 207174 AND 207209;
DELETE FROM `game_event_creature` WHERE `guid` BETWEEN 207174 AND 207209;
DELETE FROM `game_event_creature` WHERE `guid` IN (130847, 130848, 130849, 130853, 130855, 130906, 130907, 130908, 130971);

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+54;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `VerifiedBuild`) VALUES
-- Steelgrill's Depot
(@CGUID+0, 39263, 0, 1, 189, 1, 1, 0, 0, -5456.2587890625, -671.8507080078125, 393.0345458984375, 0.645771801471710205, 120, 0, 0, 42, 100, 0, 53788), -- Disassembled Mechano-Tank (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1 (Auras: 29266 - Permanent Feign Death)
(@CGUID+1, 39263, 0, 1, 189, 1, 1, 0, 0, -5462.94091796875, -675.2725830078125, 392.849609375, 2.565634012222290039, 120, 0, 0, 42, 100, 0, 53788), -- Disassembled Mechano-Tank (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1 (Auras: 29266 - Permanent Feign Death)
(@CGUID+2, 39263, 0, 1, 189, 1, 1, 0, 0, -5469.34912109375, -674.9461669921875, 392.5477294921875, 3.769911050796508789, 120, 0, 0, 42, 100, 0, 53788), -- Disassembled Mechano-Tank (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1 (Auras: 29266 - Permanent Feign Death)
(@CGUID+3, 39349, 0, 1, 189, 1, 1, 0, 1, -5422.046875, -632.66668701171875, 394.719482421875, 4.729842185974121093, 120, 0, 0, 176, 0, 0, 53788), -- Gnomeregan Trainee (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+4, 39349, 0, 1, 189, 1, 1, 0, 1, -5424.9306640625, -629.92535400390625, 394.91375732421875, 4.729842185974121093, 120, 0, 0, 176, 0, 0, 53788), -- Gnomeregan Trainee (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+5, 39349, 0, 1, 189, 1, 1, 0, 1, -5427.7880859375, -630.07464599609375, 394.7366943359375, 4.729842185974121093, 120, 0, 0, 176, 0, 0, 53788), -- Gnomeregan Trainee (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@CGUID+6, 39349, 0, 1, 189, 1, 1, 0, 1, -5427.9931640625, -632.55731201171875, 394.62030029296875, 4.729842185974121093, 120, 0, 0, 156, 0, 0, 53788), -- Gnomeregan Trainee (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+7, 39349, 0, 1, 189, 1, 1, 0, 1, -5428.20166015625, -628.0225830078125, 394.84637451171875, 4.729842185974121093, 120, 0, 0, 156, 0, 0, 53788), -- Gnomeregan Trainee (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+8, 39349, 0, 1, 189, 1, 1, 0, 1, -5419.32275390625, -630.03125, 394.83953857421875, 4.729842185974121093, 120, 0, 0, 156, 0, 0, 53788), -- Gnomeregan Trainee (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+9, 39349, 0, 1, 189, 1, 1, 0, 1, -5428.2900390625, -635.16668701171875, 394.535614013671875, 4.729842185974121093, 120, 0, 0, 176, 0, 0, 53788), -- Gnomeregan Trainee (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+10, 39349, 0, 1, 189, 1, 1, 0, 1, -5422.27783203125, -628.24481201171875, 395.105010986328125, 4.729842185974121093, 120, 0, 0, 198, 0, 0, 53788), -- Gnomeregan Trainee (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+11, 39349, 0, 1, 189, 1, 1, 0, 1, -5425.080078125, -635.295166015625, 394.43603515625, 4.729842185974121093, 120, 0, 0, 176, 0, 0, 53788), -- Gnomeregan Trainee (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+12, 39349, 0, 1, 189, 1, 1, 0, 1, -5425.36279296875, -627.8125, 395.06195068359375, 4.729842185974121093, 120, 0, 0, 176, 0, 0, 53788), -- Gnomeregan Trainee (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@CGUID+13, 39349, 0, 1, 189, 1, 1, 0, 1, -5419.375, -627.920166015625, 395.061614990234375, 4.729842185974121093, 120, 0, 0, 156, 0, 0, 53788), -- Gnomeregan Trainee (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+14, 39349, 0, 1, 189, 1, 1, 0, 1, -5418.8525390625, -635.701416015625, 394.34320068359375, 4.729842185974121093, 120, 0, 0, 176, 0, 0, 53788), -- Gnomeregan Trainee (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+15, 39368, 0, 1, 189, 1, 1, 0, 1, -5424.02783203125, -638.08160400390625, 393.9921875, 1.588249532384327854, 120, 0, 0, 10635, 0, 0, 53788), -- Drill Sergeant Steamcrank (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+16, 39386, 0, 1, 189, 1, 1, 0, 0, -5444.3212890625, -665.154541015625, 393.80096435546875, 2.164208173751831054, 120, 0, 0, 12600, 0, 0, 53788), -- Pilot Muzzlesprock (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@CGUID+17, 39396, 0, 1, 189, 1, 1, 0, 0, -5447.55224609375, -667.30902099609375, 395.18896484375, 2.268928050994873046, 120, 0, 0, 1753, 0, 0, 53788), -- 'Thunderflash' (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@CGUID+18, 39675, 0, 1, 189, 1, 1, 0, 1, -5464.71728515625, -668.71527099609375, 393.602447509765625, 1.850049018859863281, 120, 0, 0, 10635, 0, 0, 53788), -- Captain Tread Sparknozzle (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1 (Auras: 73954 - [DND] Persuaded)
(@CGUID+19, 39678, 0, 1, 189, 1, 1, 0, 0, -5461.8349609375, -626.95831298828125, 393.68707275390625, 5.183627605438232421, 120, 0, 0, 198, 0, 0, 53788), -- Toby Zeigear (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@CGUID+20, 39711, 0, 1, 189, 1, 1, 0, 0, -5453.7099609375, -701.3038330078125, 397.677825927734375, 0.418879032135009765, 120, 0, 0, 42, 0, 0, 53788), -- Mechano-Tank Attack Target (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@CGUID+21, 39711, 0, 1, 189, 1, 1, 0, 0, -5458.6962890625, -691.717041015625, 396.82049560546875, 0.418879032135009765, 120, 0, 0, 42, 0, 0, 53788), -- Mechano-Tank Attack Target (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@CGUID+22, 39715, 0, 1, 189, 1, 1, 0, 0, -5474.34375, -670.2725830078125, 392.29296875, 1.65806281566619873, 120, 0, 0, 42, 100, 0, 53788), -- Ejector Mechano-Tank (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@CGUID+23, 39716, 0, 1, 189, 1, 1, 0, 0, -5459.3349609375, -666.44964599609375, 392.48077392578125, 1.93731546401977539, 120, 0, 0, 42, 100, 0, 53788), -- Scuttling Mechano-Tank (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1 (Auras: 16245 - Freeze Anim)
(@CGUID+24, 39717, 0, 1, 189, 1, 1, 0, 0, -5440.40625, -681.72918701171875, 395.342132568359375, 3.857177734375, 120, 0, 0, 42, 100, 0, 53788), -- Shooting Mechano-Tank (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1 (Auras: 16245 - Freeze Anim)
-- Tinkertown
(@CGUID+25, 39420, 0, 1, 133, 1, 1, 0, 0, -5272.158203125, 471.59375, 386.891082763671875, 4.171336650848388671, 120, 0, 0, 42, 0, 0, 53788), -- [DND] Probe Target Bunny (Area: Iceflow Lake - Difficulty: 0) CreateObject1
(@CGUID+26, 39420, 0, 1, 133, 1, 1, 0, 0, -5299.33154296875, 466.90625, 386.6923828125, 4.171336650848388671, 120, 0, 0, 42, 0, 0, 53788), -- [DND] Probe Target Bunny (Area: Iceflow Lake - Difficulty: 0) CreateObject1
(@CGUID+27, 39420, 0, 1, 133, 1, 1, 0, 0, -5299.2880859375, 554.82293701171875, 386.44189453125, 4.171336650848388671, 120, 0, 0, 42, 0, 0, 53788), -- [DND] Probe Target Bunny (Area: Tinkertown - Difficulty: 0) CreateObject1
(@CGUID+28, 39420, 0, 1, 133, 1, 1, 0, 0, -5018.890625, 544.22918701171875, 474.3267822265625, 4.171336650848388671, 120, 0, 0, 42, 0, 0, 53788), -- [DND] Probe Target Bunny (Area: Iceflow Lake - Difficulty: 0) CreateObject1 (Auras: 75779 - [DND] Marker)
(@CGUID+29, 39420, 0, 1, 133, 1, 1, 0, 0, -5125.2744140625, 593.85589599609375, 461.769866943359375, 3.351032257080078125, 120, 0, 0, 42, 0, 0, 53788), -- [DND] Probe Target Bunny (Area: Tinkertown - Difficulty: 0) CreateObject1 (Auras: 75779 - [DND] Marker)
(@CGUID+30, 39420, 0, 1, 133, 1, 1, 0, 0, -5159.70654296875, 629.78125, 466.691650390625, 4.660028934478759765, 120, 0, 0, 42, 0, 0, 53788), -- [DND] Probe Target Bunny (Area: Tinkertown - Difficulty: 0) CreateObject1 (Auras: 75779 - [DND] Marker)
(@CGUID+31, 39420, 0, 1, 133, 1, 1, 0, 0, -5223.38037109375, 625.94793701171875, 456.428009033203125, 4.380776405334472656, 120, 0, 0, 42, 0, 0, 53788), -- [DND] Probe Target Bunny (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 75779 - [DND] Marker)
(@CGUID+32, 39420, 0, 1, 133, 1, 1, 0, 0, -5304.75341796875, 665.59893798828125, 447.205474853515625, 4.694935798645019531, 120, 0, 0, 42, 0, 0, 53788), -- [DND] Probe Target Bunny (Area: Tinkertown - Difficulty: 0) CreateObject1 (Auras: 75779 - [DND] Marker)
(@CGUID+33, 39420, 0, 1, 133, 1, 1, 0, 0, -5349.8056640625, 648.625, 443.591217041015625, 4.97418832778930664, 120, 0, 0, 42, 0, 0, 53788), -- [DND] Probe Target Bunny (Area: Tinkertown - Difficulty: 0) CreateObject1 (Auras: 75779 - [DND] Marker)
-- Ironforge
(@CGUID+34, 39253, 0, 1537, 1537, 1, 1, 0, 0, -4981.658203125, -1256.7291259765625, 501.77008056640625, 1.431169986724853515, 120, 0, 0, 42, 0, 0, 53788), -- Gnome Citizen (Area: Ironforge - Difficulty: 0) CreateObject1 (Auras: 73930 - Citizen Costume)
(@CGUID+35, 39253, 0, 1537, 1537, 1, 1, 0, 0, -4981.4462890625, -1255.4635009765625, 501.76953125, 4.642575740814208984, 120, 0, 0, 42, 0, 0, 53788), -- Gnome Citizen (Area: Ironforge - Difficulty: 0) CreateObject1 (Auras: 73930 - Citizen Costume)
(@CGUID+36, 39253, 0, 1537, 1537, 1, 1, 0, 0, -4969.00341796875, -1276.376708984375, 502.0528564453125, 0.506145477294921875, 120, 0, 0, 42, 0, 0, 53788), -- Gnome Citizen (Area: Ironforge - Difficulty: 0) CreateObject1 (Auras: 73930 - Citizen Costume)
(@CGUID+37, 39253, 0, 1537, 1537, 1, 1, 0, 0, -4968.92724609375, -1274.329833984375, 510.36865234375, 2.914699792861938476, 120, 0, 0, 42, 0, 0, 53788), -- Gnome Citizen (Area: Ironforge - Difficulty: 0) CreateObject1 (Auras: 73930 - Citizen Costume)
(@CGUID+38, 39253, 0, 1537, 1537, 1, 1, 0, 0, -4970.5087890625, -1273.7117919921875, 510.36865234375, 6.2657318115234375, 120, 0, 0, 42, 0, 0, 53788), -- Gnome Citizen (Area: Ironforge - Difficulty: 0) CreateObject1 (Auras: 73930 - Citizen Costume)
(@CGUID+39, 39253, 0, 1537, 1537, 1, 1, 0, 0, -4842.38525390625, -1245.9149169921875, 501.853759765625, 5.393067359924316406, 120, 0, 0, 42, 0, 0, 53788), -- Gnome Citizen (Area: Ironforge - Difficulty: 0) CreateObject1 (Auras: 73930 - Citizen Costume)
(@CGUID+40, 39253, 0, 1537, 1537, 1, 1, 0, 0, -4840.55224609375, -1246.7396240234375, 501.873443603515625, 3.333578824996948242, 120, 0, 0, 42, 0, 0, 53788), -- Gnome Citizen (Area: Ironforge - Difficulty: 0) CreateObject1 (Auras: 73930 - Citizen Costume)
(@CGUID+41, 39253, 0, 1537, 1537, 1, 1, 0, 0, -4834.71337890625, -1245.8160400390625, 501.89208984375, 4.572762489318847656, 120, 0, 0, 42, 0, 0, 53788), -- Gnome Citizen (Area: Ironforge - Difficulty: 0) CreateObject1 (Auras: 73930 - Citizen Costume)
(@CGUID+42, 39253, 0, 1537, 1537, 1, 1, 0, 0, -4814.96533203125, -1287.9930419921875, 501.8604736328125, 1.431169986724853515, 120, 0, 0, 42, 0, 0, 53788), -- Gnome Citizen (Area: Ironforge - Difficulty: 0) CreateObject1 (Auras: 73930 - Citizen Costume)
(@CGUID+43, 39253, 0, 1537, 1537, 1, 1, 0, 0, -4815.46728515625, -1303.9444580078125, 501.9512939453125, 3.543018341064453125, 120, 0, 0, 42, 0, 0, 53788), -- Gnome Citizen (Area: Ironforge - Difficulty: 0) CreateObject1 (Auras: 73930 - Citizen Costume)
(@CGUID+44, 39253, 0, 1537, 1537, 1, 1, 0, 0, -4816.845703125, -1304.5052490234375, 501.9512939453125, 0.506145477294921875, 120, 0, 0, 42, 0, 0, 53788), -- Gnome Citizen (Area: Ironforge - Difficulty: 0) CreateObject1 (Auras: 73930 - Citizen Costume)
(@CGUID+45, 39623, 0, 1537, 1537, 1, 1, 0, 0, -4864.23291015625, -1148.6146240234375, 502.248046875, 1.274090290069580078, 120, 0, 0, 42, 0, 0, 53788), -- Gnome Citizen (Area: Ironforge - Difficulty: 0) CreateObject1 (Auras: 73930 - Citizen Costume)
(@CGUID+46, 39623, 0, 1537, 1537, 1, 1, 0, 0, -4916.4462890625, -1217.7066650390625, 501.645782470703125, 5.078907966613769531, 120, 0, 0, 42, 0, 0, 53788), -- Gnome Citizen (Area: Ironforge - Difficulty: 0) CreateObject1 (Auras: 73929 - Citizen Costume)
(@CGUID+47, 39623, 0, 1537, 1537, 1, 1, 0, 0, -4967.8349609375, -1275.9271240234375, 502.0528564453125, 3.577924966812133789, 120, 0, 0, 42, 0, 0, 53788), -- Gnome Citizen (Area: Ironforge - Difficulty: 0) CreateObject1 (Auras: 73929 - Citizen Costume)
(@CGUID+48, 39623, 0, 1537, 1537, 1, 1, 0, 0, -4842.0224609375, -1248.0069580078125, 501.87469482421875, 1.186823844909667968, 120, 0, 0, 42, 0, 0, 53788), -- Gnome Citizen (Area: Ironforge - Difficulty: 0) CreateObject1 (Auras: 73929 - Citizen Costume)
(@CGUID+49, 39623, 0, 1537, 1537, 1, 1, 0, 0, -4854.5537109375, -1283.921875, 501.9512939453125, 0.593411922454833984, 120, 0, 0, 42, 0, 0, 53788), -- Gnome Citizen (Area: Ironforge - Difficulty: 0) CreateObject1 (Auras: 73929 - Citizen Costume)
(@CGUID+50, 39623, 0, 1537, 1537, 1, 1, 0, 0, -4814.625, -1286.12158203125, 501.9512939453125, 4.572762489318847656, 120, 0, 0, 42, 0, 0, 53788), -- Gnome Citizen (Area: Ironforge - Difficulty: 0) CreateObject1 (Auras: 73929 - Citizen Costume)
(@CGUID+51, 39623, 0, 1537, 1537, 1, 1, 0, 0, -4818.11962890625, -1252.0242919921875, 501.956817626953125, 0.261799395084381103, 120, 0, 0, 42, 0, 0, 53788), -- Gnome Citizen (Area: Ironforge - Difficulty: 0) CreateObject1 (Auras: 73929 - Citizen Costume)
(@CGUID+52, 39623, 0, 1537, 1537, 1, 1, 0, 0, -4863.75341796875, -1146.90283203125, 502.250946044921875, 4.485496044158935546, 120, 0, 0, 42, 0, 0, 53788), -- Gnome Citizen (Area: Ironforge - Difficulty: 0) CreateObject1 (Auras: 73929 - Citizen Costume)
(@CGUID+53, 39623, 0, 1537, 1537, 1, 1, 0, 0, -4763.94091796875, -1173.501708984375, 502.157012939453125, 0.436332315206527709, 120, 0, 0, 42, 0, 0, 53788), -- Gnome Citizen (Area: Ironforge - Difficulty: 0) CreateObject1 (Auras: 73929 - Citizen Costume)
(@CGUID+54, 39623, 0, 1537, 1537, 1, 1, 0, 0, -4814.4912109375, -1296.0972900390625, 501.9512939453125, 2.181661605834960937, 120, 0, 0, 42, 0, 0, 53788); -- Gnome Citizen (Area: Ironforge - Difficulty: 0) CreateObject1 (Auras: 73929 - Citizen Costume)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+54;
INSERT INTO `creature_addon` (`guid`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+25, 0, 0, 0, 0, 1, 0, 0, 4, ''), -- [DND] Probe Target Bunny
(@CGUID+26, 0, 0, 0, 0, 1, 0, 0, 4, ''), -- [DND] Probe Target Bunny
(@CGUID+27, 0, 0, 0, 0, 1, 0, 0, 4, ''), -- [DND] Probe Target Bunny
(@CGUID+46, 0, 3, 0, 0, 1, 0, 0, 0, '73929'), -- Gnome Citizen - 73929 - Citizen Costume
(@CGUID+53, 0, 3, 0, 0, 1, 0, 0, 0, '73929'), -- Gnome Citizen - 73929 - Citizen Costume
(@CGUID+54, 0, 3, 0, 0, 1, 0, 0, 0, '73929'); -- Gnome Citizen - 73929 - Citizen Costume

-- Old gameobject spawns
DELETE FROM `gameobject` WHERE `guid`=151888;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 151244 AND 151277;
DELETE FROM `gameobject_addon` WHERE `guid`=151888;
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN 151244 AND 151277;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 151244 AND 151277;

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+35;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
-- Steelgrill's Depot
(@OGUID+0, 179968, 0, 1, 189, 1, 1, -5457.0244140625, -695.94793701171875, 398.040985107421875, 0.436331570148468017, 0, 0, 0.216439247131347656, 0.976296067237854003, 120, 255, 1, 53788), -- Haystack 01 (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@OGUID+1, 179968, 0, 1, 189, 1, 1, -5457.79150390625, -694.56597900390625, 397.83416748046875, 0.436331570148468017, 0, 0, 0.216439247131347656, 0.976296067237854003, 120, 255, 1, 53788), -- Haystack 01 (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@OGUID+2, 179968, 0, 1, 189, 1, 1, -5455.611328125, -696.06597900390625, 397.884002685546875, 0.436331570148468017, 0, 0, 0.216439247131347656, 0.976296067237854003, 120, 255, 1, 53788), -- Haystack 01 (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@OGUID+3, 179968, 0, 1, 189, 1, 1, -5454.9375, -697.3975830078125, 397.884063720703125, 0.436331570148468017, 0, 0, 0.216439247131347656, 0.976296067237854003, 120, 255, 1, 53788), -- Haystack 01 (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@OGUID+4, 179968, 0, 1, 189, 1, 1, -5457.1474609375, -693.5555419921875, 397.535858154296875, 0.436331570148468017, 0, 0, 0.216439247131347656, 0.976296067237854003, 120, 255, 1, 53788), -- Haystack 01 (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@OGUID+5, 179968, 0, 1, 189, 1, 1, -5454.35595703125, -698.7899169921875, 397.880218505859375, 0.436331570148468017, 0, 0, 0.216439247131347656, 0.976296067237854003, 120, 255, 1, 53788), -- Haystack 01 (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@OGUID+6, 179968, 0, 1, 189, 1, 1, -5455.69091796875, -698.6336669921875, 398.054229736328125, 0.436331570148468017, 0, 0, 0.216439247131347656, 0.976296067237854003, 120, 255, 1, 53788), -- Haystack 01 (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@OGUID+7, 179968, 0, 1, 189, 1, 1, -5456.32275390625, -697.28643798828125, 398.05120849609375, 0.436331570148468017, 0, 0, 0.216439247131347656, 0.976296067237854003, 120, 255, 1, 53788), -- Haystack 01 (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@OGUID+8, 179968, 0, 1, 189, 1, 1, -5456.3505859375, -694.81597900390625, 397.74237060546875, 0.436331570148468017, 0, 0, 0.216439247131347656, 0.976296067237854003, 120, 255, 1, 53788), -- Haystack 01 (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@OGUID+9, 180038, 0, 1, 189, 1, 1, -5457.8818359375, -698.607666015625, 398.394927978515625, 0.069811686873435974, 0, 0, 0.034898757934570312, 0.999390840530395507, 120, 255, 1, 53788), -- Haybail 02 (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@OGUID+10, 180038, 0, 1, 189, 1, 1, -5456.3369140625, -701.29864501953125, 398.25640869140625, 1.867502212524414062, 0, 0, 0.803856849670410156, 0.594822824001312255, 120, 255, 1, 53788), -- Haybail 02 (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@OGUID+11, 180038, 0, 1, 189, 1, 1, -5459.6162109375, -693.85418701171875, 398.018218994140625, 2.949595451354980468, 0, 0, 0.995395660400390625, 0.095851235091686248, 120, 255, 1, 53788), -- Haybail 02 (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@OGUID+12, 180038, 0, 1, 189, 1, 1, -5459.80712890625, -696.357666015625, 398.621246337890625, 1.186823248863220214, 0, 0, 0.559192657470703125, 0.829037725925445556, 120, 255, 1, 53788), -- Haybail 02 (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@OGUID+13, 187254, 0, 1, 189, 1, 1, -5463.8681640625, -626.44097900390625, 394.500885009765625, 0, 0, 0, 0, 1, 120, 255, 1, 53788), -- Rolled Scroll (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@OGUID+14, 187254, 0, 1, 189, 1, 1, -5464.3818359375, -626.8211669921875, 394.505340576171875, 0.261798173189163208, 0, 0, 0.130525588989257812, 0.991444945335388183, 120, 255, 1, 53788), -- Rolled Scroll (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@OGUID+15, 194498, 0, 1, 189, 1, 1, -5399.82666015625, -627.45831298828125, 392.36993408203125, 5.84685373306274414, 0, 0, -0.21643924713134765, 0.976296067237854003, 120, 255, 1, 53788), -- Gnomeregan Banner (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@OGUID+16, 194498, 0, 1, 189, 1, 1, -5462.3349609375, -692.32464599609375, 398.11553955078125, 0.506144583225250244, 0, 0, 0.250379562377929687, 0.968147754669189453, 120, 255, 1, 53788), -- Gnomeregan Banner (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@OGUID+17, 194498, 0, 1, 189, 1, 1, -5435.580078125, -706.25, 393.914031982421875, 5.759587764739990234, 0, 0, -0.25881862640380859, 0.965925931930541992, 120, 255, 1, 53788), -- Gnomeregan Banner (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@OGUID+18, 194498, 0, 1, 189, 1, 1, -5456.85791015625, -702.98785400390625, 398.340423583984375, 0.506144583225250244, 0, 0, 0.250379562377929687, 0.968147754669189453, 120, 255, 1, 53788), -- Gnomeregan Banner (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@OGUID+19, 194498, 0, 1, 189, 1, 1, -5388.81103515625, -603.154541015625, 392.115478515625, 5.84685373306274414, 0, 0, -0.21643924713134765, 0.976296067237854003, 120, 255, 1, 53788), -- Gnomeregan Banner (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@OGUID+20, 194498, 0, 1, 189, 1, 1, -5467.99658203125, -679.295166015625, 392.318267822265625, 1.291541695594787597, 0, 0, 0.60181427001953125, 0.798636078834533691, 120, 255, 1, 53788), -- Gnomeregan Banner (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@OGUID+21, 194498, 0, 1, 189, 1, 1, -5409.43408203125, -654.05206298828125, 392.521240234375, 5.969027042388916015, 0, 0, -0.1564340591430664, 0.987688362598419189, 120, 255, 1, 53788), -- Gnomeregan Banner (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@OGUID+22, 202564, 0, 1, 189, 1, 1, -5463.98974609375, -626.967041015625, 393.528717041015625, 0, 0, 0, 0, 1, 120, 255, 1, 53788), -- Gnome Table (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@OGUID+23, 202713, 0, 1, 189, 1, 1, -5417.48779296875, -667.49481201171875, 394.615875244140625, 1.291541695594787597, 0, 0, 0.60181427001953125, 0.798636078834533691, 120, 255, 1, 53788), -- Hazard Light Red 02 (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@OGUID+24, 202713, 0, 1, 189, 1, 1, -5432.19287109375, -700.07464599609375, 395.03656005859375, 1.291541695594787597, 0, 0, 0.60181427001953125, 0.798636078834533691, 120, 255, 1, 53788), -- Hazard Light Red 02 (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@OGUID+25, 202713, 0, 1, 189, 1, 1, -5412.611328125, -659.8211669921875, 393.9151611328125, 1.291541695594787597, 0, 0, 0.60181427001953125, 0.798636078834533691, 120, 255, 1, 53788), -- Hazard Light Red 02 (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@OGUID+26, 202713, 0, 1, 189, 1, 1, -5414.6943359375, -662.7117919921875, 394.140045166015625, 1.291541695594787597, 0, 0, 0.60181427001953125, 0.798636078834533691, 120, 255, 1, 53788), -- Hazard Light Red 02 (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@OGUID+27, 202713, 0, 1, 189, 1, 1, -5410.23974609375, -654.8975830078125, 393.749176025390625, 1.291541695594787597, 0, 0, 0.60181427001953125, 0.798636078834533691, 120, 255, 1, 53788), -- Hazard Light Red 02 (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@OGUID+28, 202713, 0, 1, 189, 1, 1, -5391.9443359375, -609.545166015625, 393.589263916015625, 1.291541695594787597, 0, 0, 0.60181427001953125, 0.798636078834533691, 120, 255, 1, 53788), -- Hazard Light Red 02 (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@OGUID+29, 202713, 0, 1, 189, 1, 1, -5434.78466796875, -704.91143798828125, 395.076080322265625, 1.291541695594787597, 0, 0, 0.60181427001953125, 0.798636078834533691, 120, 255, 1, 53788), -- Hazard Light Red 02 (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@OGUID+30, 202713, 0, 1, 189, 1, 1, -5389.4599609375, -604.69793701171875, 393.34521484375, 1.291541695594787597, 0, 0, 0.60181427001953125, 0.798636078834533691, 120, 255, 1, 53788), -- Hazard Light Red 02 (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@OGUID+31, 202713, 0, 1, 189, 1, 1, -5393.62353515625, -612.3680419921875, 393.79925537109375, 1.291541695594787597, 0, 0, 0.60181427001953125, 0.798636078834533691, 120, 255, 1, 53788), -- Hazard Light Red 02 (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@OGUID+32, 202713, 0, 1, 189, 1, 1, -5430.65087890625, -697.17364501953125, 394.862701416015625, 1.291541695594787597, 0, 0, 0.60181427001953125, 0.798636078834533691, 120, 255, 1, 53788), -- Hazard Light Red 02 (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@OGUID+33, 202713, 0, 1, 189, 1, 1, -5396.00537109375, -617.33331298828125, 393.740631103515625, 1.291541695594787597, 0, 0, 0.60181427001953125, 0.798636078834533691, 120, 255, 1, 53788), -- Hazard Light Red 02 (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@OGUID+34, 202713, 0, 1, 189, 1, 1, -5428.03125, -692.39581298828125, 394.647613525390625, 1.291541695594787597, 0, 0, 0.60181427001953125, 0.798636078834533691, 120, 255, 1, 53788), -- Hazard Light Red 02 (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1
(@OGUID+35, 202898, 0, 1, 189, 1, 1, -5463.5244140625, -627.1961669921875, 394.483184814453125, 1.169368624687194824, 0, 0, 0.551936149597167968, 0.833886384963989257, 120, 255, 1, 53788); -- Scroll (Area: Steelgrill's Depot - Difficulty: 0) CreateObject1

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @CGUID+0 AND @CGUID+54;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@EVENT, @CGUID+0),
(@EVENT, @CGUID+1),
(@EVENT, @CGUID+2),
(@EVENT, @CGUID+3),
(@EVENT, @CGUID+4),
(@EVENT, @CGUID+5),
(@EVENT, @CGUID+6),
(@EVENT, @CGUID+7),
(@EVENT, @CGUID+8),
(@EVENT, @CGUID+9),
(@EVENT, @CGUID+10),
(@EVENT, @CGUID+11),
(@EVENT, @CGUID+12),
(@EVENT, @CGUID+13),
(@EVENT, @CGUID+14),
(@EVENT, @CGUID+15),
(@EVENT, @CGUID+16),
(@EVENT, @CGUID+17),
(@EVENT, @CGUID+18),
(@EVENT, @CGUID+19),
(@EVENT, @CGUID+20),
(@EVENT, @CGUID+21),
(@EVENT, @CGUID+22),
(@EVENT, @CGUID+23),
(@EVENT, @CGUID+24),
(@EVENT, @CGUID+25),
(@EVENT, @CGUID+26),
(@EVENT, @CGUID+27),
(@EVENT, @CGUID+28),
(@EVENT, @CGUID+29),
(@EVENT, @CGUID+30),
(@EVENT, @CGUID+31),
(@EVENT, @CGUID+32),
(@EVENT, @CGUID+33),
(@EVENT, @CGUID+34),
(@EVENT, @CGUID+35),
(@EVENT, @CGUID+36),
(@EVENT, @CGUID+37),
(@EVENT, @CGUID+38),
(@EVENT, @CGUID+39),
(@EVENT, @CGUID+40),
(@EVENT, @CGUID+41),
(@EVENT, @CGUID+42),
(@EVENT, @CGUID+43),
(@EVENT, @CGUID+44),
(@EVENT, @CGUID+45),
(@EVENT, @CGUID+46),
(@EVENT, @CGUID+47),
(@EVENT, @CGUID+48),
(@EVENT, @CGUID+49),
(@EVENT, @CGUID+50),
(@EVENT, @CGUID+51),
(@EVENT, @CGUID+52),
(@EVENT, @CGUID+53),
(@EVENT, @CGUID+54);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @OGUID+0 AND @OGUID+35;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(@EVENT, @OGUID+0),
(@EVENT, @OGUID+1),
(@EVENT, @OGUID+2),
(@EVENT, @OGUID+3),
(@EVENT, @OGUID+4),
(@EVENT, @OGUID+5),
(@EVENT, @OGUID+6),
(@EVENT, @OGUID+7),
(@EVENT, @OGUID+8),
(@EVENT, @OGUID+9),
(@EVENT, @OGUID+10),
(@EVENT, @OGUID+11),
(@EVENT, @OGUID+12),
(@EVENT, @OGUID+13),
(@EVENT, @OGUID+14),
(@EVENT, @OGUID+15),
(@EVENT, @OGUID+16),
(@EVENT, @OGUID+17),
(@EVENT, @OGUID+18),
(@EVENT, @OGUID+19),
(@EVENT, @OGUID+20),
(@EVENT, @OGUID+21),
(@EVENT, @OGUID+22),
(@EVENT, @OGUID+23),
(@EVENT, @OGUID+24),
(@EVENT, @OGUID+25),
(@EVENT, @OGUID+26),
(@EVENT, @OGUID+27),
(@EVENT, @OGUID+28),
(@EVENT, @OGUID+29),
(@EVENT, @OGUID+30),
(@EVENT, @OGUID+31),
(@EVENT, @OGUID+32),
(@EVENT, @OGUID+33),
(@EVENT, @OGUID+34),
(@EVENT, @OGUID+35);
