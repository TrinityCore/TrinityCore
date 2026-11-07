SET @CGUID := 9800103;
SET @OGUID := 9804598;
SET @POOL := 5704;
SET @EVENT := 9;

-- Gameobject templates
DELETE FROM `gameobject_template` WHERE `entry`=415071;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(415071, 5, 86401, 'Noblegarden Ribbon 0.13 [DNT]', '', '', '', 0.129999995231628417, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 53989); -- Noblegarden Ribbon 0.13 [DNT]

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 32798, 1, 215, 222, '0', 0, 0, 0, 0, -2344.369873046875, -374.364593505859375, -8.00047779083251953, 4.940572738647460937, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Spring Gatherer (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@CGUID+1, 32837, 1, 215, 222, '0', 0, 0, 0, 1, -2345.982666015625, -375.46875, -7.89255952835083007, 5.916666030883789062, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989); -- Noblegarden Merchant (Area: Bloodhoof Village - Difficulty: 0) CreateObject1

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+83;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 113770, 1, 215, 222, '0', 0, 0, -2416.27294921875, -388.86981201171875, -2.01838111877441406, 1.85004889965057373, 0, 0, 0.798635482788085937, 0.60181504487991333, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+1, 113770, 1, 215, 222, '0', 0, 0, -2415.029296875, -396.488067626953125, -2.10432100296020507, 4.9218292236328125, 0, 0, -0.62932014465332031, 0.77714616060256958, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject2
(@OGUID+2, 113771, 1, 215, 222, '0', 0, 0, -2406.2900390625, -319.848968505859375, -13.8625097274780273, 2.585132598876953125, 0, 0, 0.961543083190917968, 0.274654179811477661, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject2
(@OGUID+3, 113769, 1, 215, 222, '0', 0, 0, -2402.84375, -323.6007080078125, -13.8191652297973632, 3.671252250671386718, 0.34107065200805664, -0.22704696655273437, -0.89994049072265625, 0.149089187383651733, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+4, 113769, 1, 215, 222, '0', 0, 0, -2401.508544921875, -397.7005615234375, 0.737452983856201171, 1.378809213638305664, 0, 0, 0.636077880859375, 0.771624863147735595, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+5, 113769, 1, 215, 222, '0', 0, 0, -2392.396240234375, -349.039459228515625, -9.12102603912353515, 5.393068790435791015, 0, 0, -0.43051052093505859, 0.902585566043853759, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject2
(@OGUID+6, 113768, 1, 215, 222, '0', 0, 0, -2390.044677734375, -339.814697265625, -9.407928466796875, 0.24434557557106018, 0, 0, 0.121869087219238281, 0.9925462007522583, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+7, 113768, 1, 215, 222, '0', 0, 0, -2388.350830078125, -336.115509033203125, -9.55712413787841796, 6.056293010711669921, 0, 0, -0.11320304870605468, 0.993571877479553222, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+8, 113768, 1, 215, 222, '0', 0, 0, -2382.197021484375, -327.314422607421875, -9.51232719421386718, 3.124123096466064453, 0, 0, 0.99996185302734375, 0.008734640665352344, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject2
(@OGUID+9, 113768, 1, 215, 222, '0', 0, 0, -2377.040771484375, -409.395477294921875, -4.16336297988891601, 0.261798173189163208, 0, 0, 0.130525588989257812, 0.991444945335388183, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+10, 113768, 1, 215, 222, '0', 0, 0, -2371.84326171875, -313.506591796875, -9.70726776123046875, 5.881760597229003906, 0, 0, -0.19936752319335937, 0.979924798011779785, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+11, 113768, 1, 215, 222, '0', 0, 0, -2370.638916015625, -357.866119384765625, -9.02785587310791015, 3.420850038528442382, 0, 0, -0.99026775360107421, 0.139175355434417724, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject2
(@OGUID+12, 113771, 1, 215, 222, '0', 0, 0, -2369.310791015625, -394.9913330078125, -4.64512872695922851, 5.052624702453613281, 0, 0, -0.57718753814697265, 0.816611647605895996, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject2
(@OGUID+13, 113770, 1, 215, 222, '0', 0, 0, -2361.63720703125, -364.892364501953125, -7.82731103897094726, 4.398232460021972656, 0, 0, -0.80901622772216796, 0.587786316871643066, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject2
(@OGUID+14, 113771, 1, 215, 222, '0', 0, 0, -2361.373779296875, -337.949462890625, -8.81586837768554687, 4.345870018005371093, 0, 0, -0.82412624359130859, 0.566406130790710449, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+15, 113768, 1, 215, 222, '0', 0, 0, -2361.177490234375, -363.4959716796875, -8.84961318969726562, 1.204277276992797851, 0, 0, 0.56640625, 0.824126183986663818, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject2
(@OGUID+16, 113770, 1, 215, 222, '0', 0, 0, -2355.528564453125, -364.94073486328125, -8.70328426361083984, 4.939284324645996093, 0, 0, -0.6225137710571289, 0.78260880708694458, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+17, 113771, 1, 215, 222, '0', 0, 0, -2352.67626953125, -366.20452880859375, -8.41767406463623046, 4.433136463165283203, 0, 0, -0.79863548278808593, 0.60181504487991333, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+18, 113768, 1, 215, 222, '0', 0, 0, -2350.813232421875, -305.639312744140625, -9.42381095886230468, 3.159062385559082031, 0, 0, -0.99996185302734375, 0.008734640665352344, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject2
(@OGUID+19, 113770, 1, 215, 222, '0', 0, 0, -2349.915283203125, -296.165771484375, -9.42484760284423828, 0.471238493919372558, 0, 0, 0.233445167541503906, 0.972369968891143798, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject2
(@OGUID+20, 113770, 1, 215, 222, '0', 0, 0, -2349.622802734375, -364.795989990234375, -8.49971580505371093, 5.93412017822265625, 0, 0, -0.17364788055419921, 0.984807789325714111, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject2
(@OGUID+21, 113768, 1, 215, 222, '0', 0, 0, -2347.83251953125, -413.63446044921875, -8.96202564239501953, 2.460912704467773437, 0, 0, 0.942641258239746093, 0.333807557821273803, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+22, 113769, 1, 215, 222, '0', 0, 0, -2347.507080078125, -372.798614501953125, -7.92784786224365234, 4.328419685363769531, 0, 0, -0.82903671264648437, 0.559194147586822509, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+23, 113769, 1, 215, 222, '0', 0, 0, -2346.15087890625, -345.013580322265625, -9.10674953460693359, 3.054326534271240234, 0, 0, 0.999048233032226562, 0.043619260191917419, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+24, 113769, 1, 215, 223, '0', 0, 0, -2343.528076171875, -346.439971923828125, -8.97362709045410156, 4.206246376037597656, 0, 0, -0.86162853240966796, 0.50753939151763916, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Stonebull Lake - Difficulty: 0) CreateObject2
(@OGUID+25, 113771, 1, 215, 222, '0', 0, 0, -2342.54736328125, -349.9722900390625, -9.09745502471923828, 2.216565132141113281, 0, 0, 0.894933700561523437, 0.44619917869567871, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+26, 113769, 1, 215, 222, '0', 0, 0, -2335.442626953125, -470.685882568359375, -7.50701808929443359, 5.044002056121826171, 0, 0, -0.58070278167724609, 0.814115643501281738, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+27, 113770, 1, 215, 222, '0', 0, 0, -2334.794189453125, -445.24102783203125, -6.3900618553161621, 6.265733242034912109, 0, 0, -0.00872611999511718, 0.999961912631988525, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject2
(@OGUID+28, 113768, 1, 215, 222, '0', 0, 0, -2332.2314453125, -467.31884765625, -7.18609809875488281, 1.762782454490661621, 0, 0, 0.771624565124511718, 0.636078238487243652, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+29, 113771, 1, 215, 222, '0', 0, 0, -2331.9541015625, -308.407806396484375, -9.42487525939941406, 2.111847877502441406, 0, 0, 0.870355606079101562, 0.492423713207244873, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+30, 113769, 1, 215, 223, '0', 0, 0, -2330.307861328125, -259.410980224609375, -7.49656295776367187, 2.757613182067871093, 0, 0, 0.981626510620117187, 0.190812408924102783, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Stonebull Lake - Difficulty: 0) CreateObject1
(@OGUID+31, 113770, 1, 215, 222, '0', 0, 0, -2328.320556640625, -390.059539794921875, -7.95401906967163085, 3.961898565292358398, 0, 0, -0.91705989837646484, 0.398749500513076782, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject2
(@OGUID+32, 113770, 1, 215, 222, '0', 0, 0, -2327.317626953125, -426.91119384765625, -6.94147777557373046, 0.15707901120185852, 0, 0, 0.078458786010742187, 0.996917366981506347, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+33, 113770, 1, 215, 222, '0', 0, 0, -2327.260498046875, -390.677093505859375, -7.06188678741455078, 2.007128477096557617, 0, 0, 0.84339141845703125, 0.537299633026123046, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject2
(@OGUID+34, 113771, 1, 215, 222, '0', 0, 0, -2326.96630859375, -465.051055908203125, -6.85657978057861328, 1.308995485305786132, 0, 0, 0.608760833740234375, 0.793353796005249023, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+35, 113770, 1, 215, 222, '0', 0, 0, -2325.057861328125, -384.087982177734375, -8.11107254028320312, 4.677483558654785156, 0, 0, -0.71933937072753906, 0.694658815860748291, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject2
(@OGUID+36, 113769, 1, 215, 223, '0', 0, 0, -2319.938720703125, -266.86553955078125, -8.62991046905517578, 5.881760597229003906, 0, 0, -0.19936752319335937, 0.979924798011779785, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Stonebull Lake - Difficulty: 0) CreateObject2
(@OGUID+37, 113771, 1, 215, 222, '0', 0, 0, -2300.449462890625, -311.462677001953125, -9.42492580413818359, 0.698131442070007324, 0, 0, 0.342020034790039062, 0.939692676067352294, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+38, 113770, 1, 215, 222, '0', 0, 0, -2299.219970703125, -420.457305908203125, -7.85126590728759765, 1.029743075370788574, 0, 0, 0.492423057556152343, 0.870355963706970214, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject2
(@OGUID+39, 113769, 1, 215, 222, '0', 0, 0, -2289.463623046875, -423.01214599609375, -6.42568063735961914, 4.489808082580566406, 0, 0, -0.78126430511474609, 0.624200344085693359, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject2
(@OGUID+40, 113768, 1, 215, 223, '0', 0, 0, -2287.876220703125, -288.458221435546875, -9.42492580413818359, 4.136432647705078125, 0, 0, -0.87881660461425781, 0.477159708738327026, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Stonebull Lake - Difficulty: 0) CreateObject1
(@OGUID+41, 113768, 1, 215, 222, '0', 0, 0, -2282.802978515625, -256.79791259765625, -9.42492580413818359, 4.206246376037597656, 0, 0, -0.86162853240966796, 0.50753939151763916, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+42, 113769, 1, 215, 222, '0', 0, 0, -2282.72021484375, -454.371795654296875, -8.42139911651611328, 5.794494152069091796, 0, 0, -0.24192142486572265, 0.970295846462249755, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+43, 113769, 1, 215, 223, '0', 0, 0, -2280.782958984375, -338.411468505859375, -9.42492580413818359, 3.683933496475219726, 0, 0, -0.96345806121826171, 0.267859220504760742, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Stonebull Lake - Difficulty: 0) CreateObject2
(@OGUID+44, 113768, 1, 215, 222, '0', 0, 0, -2278.845458984375, -396.289398193359375, -9.35440540313720703, 2.565631866455078125, 0, 0, 0.958819389343261718, 0.284016460180282592, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+45, 113769, 1, 215, 222, '0', 0, 0, -2277.632080078125, -455.945465087890625, -8.15755939483642578, 6.03883981704711914, 0, 0, -0.12186908721923828, 0.9925462007522583, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+46, 113770, 1, 215, 222, '0', 0, 0, -2273.411865234375, -276.89556884765625, -9.42492580413818359, 0.593410074710845947, 0, 0, 0.292370796203613281, 0.95630502700805664, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+47, 113770, 1, 215, 222, '0', 0, 0, -2273.23828125, -457.413421630859375, -8.11050796508789062, 5.096362113952636718, 0, 0, -0.55919265747070312, 0.829037725925445556, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+48, 113770, 1, 215, 222, '0', 0, 0, -2269.7197265625, -459.976287841796875, -8.11767196655273437, 3.106652259826660156, 0, 0, 0.999847412109375, 0.017469281330704689, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+49, 113769, 1, 215, 223, '0', 0, 0, -2267.097412109375, -251.08746337890625, -9.42489910125732421, 4.328419685363769531, 0, 0, -0.82903671264648437, 0.559194147586822509, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Stonebull Lake - Difficulty: 0) CreateObject1
(@OGUID+50, 113770, 1, 215, 222, '0', 0, 0, -2257.600341796875, -339.871673583984375, -9.42489910125732421, 4.694936752319335937, 0, 0, -0.71325016021728515, 0.700909554958343505, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject2
(@OGUID+51, 113770, 1, 215, 222, '0', 0, 0, -2253.6357421875, -330.25067138671875, -9.42489814758300781, 2.513273954391479492, 0, 0, 0.951056480407714843, 0.309017121791839599, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+52, 113770, 1, 215, 222, '0', 0, 0, -2252.828125, -331.364593505859375, -8.71656513214111328, 3.263772249221801757, 0, 0, -0.99813461303710937, 0.061051756143569946, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+53, 113771, 1, 215, 222, '0', 0, 0, -2241.80078125, -285.2822265625, -9.42489814758300781, 3.141592741012573242, 0, 0, -1, 0, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject2
(@OGUID+54, 113769, 1, 215, 222, '0', 0, 0, -2240.66650390625, -319.601287841796875, -9.42489814758300781, 1.553341388702392578, 0, 0, 0.700908660888671875, 0.713251054286956787, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+55, 113769, 1, 215, 222, '0', 0, 0, -2235.35595703125, -302.007354736328125, -9.42489814758300781, 0.401424884796142578, 0, 0, 0.199367523193359375, 0.979924798011779785, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+56, 113771, 1, 215, 222, '0', 0, 0, -2230.2548828125, -366.454803466796875, -9.53273487091064453, 3.036838293075561523, 0, 0, 0.998628616333007812, 0.052353221923112869, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+57, 113771, 1, 215, 222, '0', 0, 0, -2219.932861328125, -368.954986572265625, -8.82813453674316406, 3.90954136848449707, 0, 0, -0.92718315124511718, 0.37460830807685852, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+58, 113771, 1, 215, 222, '0', 0, 0, -2217.088623046875, -371.261260986328125, -8.67500782012939453, 5.881760597229003906, 0, 0, -0.19936752319335937, 0.979924798011779785, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject2
(@OGUID+59, 113771, 1, 215, 222, '0', 0, 0, -2215.665771484375, -302.492401123046875, -9.19234561920166015, 4.345870018005371093, 0, 0, -0.82412624359130859, 0.566406130790710449, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+60, 113768, 1, 215, 223, '0', 0, 0, -2189.530029296875, -402.936065673828125, -4.74416112899780273, 3.961898565292358398, 0, 0, -0.91705989837646484, 0.398749500513076782, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Stonebull Lake - Difficulty: 0) CreateObject2
(@OGUID+61, 113770, 1, 215, 222, '0', 0, 0, -2184.87548828125, -403.018524169921875, -4.54367780685424804, 0.942476630210876464, 0, 0, 0.453989982604980468, 0.891006767749786376, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+62, 113770, 1, 215, 222, '0', 0, 0, -2181.802490234375, -399.683929443359375, -4.33336496353149414, 1.623155713081359863, 0, 0, 0.725374221801757812, 0.688354730606079101, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+63, 113768, 1, 215, 222, '0', 0, 0, -2176.453369140625, -410.323516845703125, -4.76947498321533203, 1.954769015312194824, 0, 0, 0.829037666320800781, 0.559192776679992675, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+64, 113770, 1, 215, 222, '0', 0, 0, -2142.54638671875, -391.8114013671875, -2.58831405639648437, 5.84685373306274414, 0, 0, -0.21643924713134765, 0.976296067237854003, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Bloodhoof Village - Difficulty: 0) CreateObject2
(@OGUID+65, 415058, 1, 215, 222, '0', 0, 0, -2345.62158203125, -374.388885498046875, -8.35639667510986328, 5.386637210845947265, -0.0393080711364746, 0.008721351623535156, -0.43338394165039062, 0.900309503078460693, 120, 255, 1, 53989), -- Noblegarden Banner - Double Post [DNT] (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+66, 415060, 1, 215, 222, '0', 0, 0, -2256.041748046875, -283.26910400390625, -8.61530017852783203, 0, 0, 0, 0, 1, 120, 255, 1, 53989), -- Noblegarden Candle - Blue [DNT] (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+67, 415067, 1, 215, 222, '0', 0, 0, -2288.98095703125, -422.1875, -6.34389209747314453, 5.447711467742919921, 0, 0, -0.40569305419921875, 0.914009392261505126, 120, 255, 1, 53989), -- Noblegarden Crate - Closed [DNT] (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+68, 415067, 1, 215, 222, '0', 0, 0, -2347.842041015625, -373.760406494140625, -7.8786468505859375, 5.715007781982421875, 0, 0, -0.28028297424316406, 0.959917426109313964, 120, 255, 1, 53989), -- Noblegarden Crate - Closed [DNT] (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+69, 415067, 1, 215, 222, '0', 0, 0, -2289.546875, -422.869781494140625, -7.51388216018676757, 5.586318492889404296, 0, 0, -0.34142589569091796, 0.93990868330001831, 120, 255, 1, 53989), -- Noblegarden Crate - Closed [DNT] (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+70, 415067, 1, 215, 222, '0', 0, 0, -2346.564208984375, -372.484375, -7.99195766448974609, 0.04135998710989952, 0, 0, 0.020678520202636718, 0.999786198139190673, 120, 255, 1, 53989), -- Noblegarden Crate - Closed [DNT] (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+71, 415067, 1, 215, 222, '0', 0, 0, -2288.460205078125, -421.875, -7.52457189559936523, 5.715007781982421875, 0, 0, -0.28028297424316406, 0.959917426109313964, 120, 255, 1, 53989), -- Noblegarden Crate - Closed [DNT] (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+72, 415070, 1, 215, 222, '0', 0, 0, -2348.34375, -350.326385498046875, 0.678110480308532714, 0, 0, 0, 0, 1, 120, 255, 1, 53989), -- Noblegarden Flower Vase [DNT] (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+73, 415071, 1, 215, 222, '0', 0, 0, -2342.026123046875, -353.70660400390625, -4.33663415908813476, 5.928294658660888671, 0, 0, -0.17651557922363281, 0.984297871589660644, 120, 255, 1, 53989), -- Noblegarden Ribbon 0.13 [DNT] (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+74, 415071, 1, 215, 222, '0', 0, 0, -2346.1962890625, -362.532989501953125, -4.15650558471679687, 5.955219745635986328, 0, 0, -0.16324901580810546, 0.986584901809692382, 120, 255, 1, 53989), -- Noblegarden Ribbon 0.13 [DNT] (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+75, 415072, 1, 215, 222, '0', 0, 0, -2401.166748046875, -390.758697509765625, 2.152871370315551757, 0.129897832870483398, 0, 0, 0.06490325927734375, 0.997891545295715332, 120, 255, 1, 53989), -- Noblegarden Streamers - Small Hanging [DNT] (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+76, 415073, 1, 215, 222, '0', 0, 0, -2281.303955078125, -329.86285400390625, 0.933350861072540283, 0.980354487895965576, 0, 0, 0.470782279968261718, 0.882249414920806884, 120, 255, 1, 53989), -- Noblegarden Streamers - Large Hanging [DNT] (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+77, 415074, 1, 215, 222, '0', 0, 0, -2369.317626953125, -395.25, -4.60735177993774414, 1.204767465591430664, -0.03017377853393554, 0.086503028869628906, 0.562458038330078125, 0.821734607219696044, 120, 255, 1, 53989), -- Noblegarden Wreath Standing [DNT] (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+78, 415074, 1, 215, 222, '0', 0, 0, -2280.6650390625, -338.336822509765625, -9.42492580413818359, 3.379131317138671875, 0, 0, -0.99295520782470703, 0.118490226566791534, 120, 255, 1, 53989), -- Noblegarden Wreath Standing [DNT] (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+79, 415074, 1, 215, 222, '0', 0, 0, -2289.857666015625, -331.640625, -9.42492580413818359, 4.668062210083007812, 0, 0, -0.72260379791259765, 0.691262423992156982, 120, 255, 1, 53989), -- Noblegarden Wreath Standing [DNT] (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+80, 415074, 1, 215, 222, '0', 0, 0, -2371.828125, -344.414947509765625, -8.95698833465576171, 5.92438364028930664, 0, 0, -0.17844009399414062, 0.983950793743133544, 120, 255, 1, 53989), -- Noblegarden Wreath Standing [DNT] (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+81, 415075, 1, 215, 222, '0', 0, 0, -2319.3212890625, -423.685760498046875, -2.37148046493530273, 1.455099940299987792, 0, 0, 0.665041923522949218, 0.746806025505065917, 120, 255, 1, 53989), -- Noblegarden Hanging Wreath 0.1 [DNT] (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+82, 415075, 1, 215, 222, '0', 0, 0, -2304.614501953125, -420.2882080078125, -2.38129234313964843, 2.062447071075439453, 0, 0, 0.857928276062011718, 0.513769447803497314, 120, 255, 1, 53989), -- Noblegarden Hanging Wreath 0.1 [DNT] (Area: Bloodhoof Village - Difficulty: 0) CreateObject1
(@OGUID+83, 415075, 1, 215, 222, '0', 0, 0, -2180.986083984375, -409.604156494140625, -0.40508902072906494, 0.996169984340667724, 0, 0, 0.477744102478027343, 0.878499031066894531, 120, 255, 1, 53989); -- Noblegarden Hanging Wreath 0.1 [DNT] (Area: Bloodhoof Village - Difficulty: 0) CreateObject1

DELETE FROM `pool_members` WHERE `type`=1 AND `spawnId` BETWEEN @OGUID+0 AND @OGUID+64;
INSERT INTO `pool_members` (`type`, `spawnId`, `poolSpawnId`, `chance`, `description`) VALUES
(1, @OGUID+0, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+1, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+2, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+3, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+4, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+5, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+6, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+7, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+8, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+9, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+10, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+11, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+12, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+13, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+14, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+15, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+16, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+17, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+18, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+19, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+20, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+21, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+22, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+23, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+24, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+25, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+26, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+27, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+28, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+29, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+30, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+31, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+32, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+33, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+34, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+35, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+36, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+37, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+38, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+39, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+40, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+41, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+42, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+43, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+44, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+45, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+46, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+47, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+48, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+49, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+50, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+51, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+52, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+53, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+54, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+55, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+56, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+57, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+58, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+59, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+60, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+61, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+62, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+63, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+64, @POOL, 0, 'Noblegarden - Brightly Colored Egg');

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@EVENT, @CGUID+0),
(@EVENT, @CGUID+1);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @OGUID+0 AND @OGUID+83;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(@EVENT, @OGUID+65),
(@EVENT, @OGUID+66),
(@EVENT, @OGUID+67),
(@EVENT, @OGUID+68),
(@EVENT, @OGUID+69),
(@EVENT, @OGUID+70),
(@EVENT, @OGUID+71),
(@EVENT, @OGUID+72),
(@EVENT, @OGUID+73),
(@EVENT, @OGUID+74),
(@EVENT, @OGUID+75),
(@EVENT, @OGUID+76),
(@EVENT, @OGUID+77),
(@EVENT, @OGUID+78),
(@EVENT, @OGUID+79),
(@EVENT, @OGUID+80),
(@EVENT, @OGUID+81),
(@EVENT, @OGUID+82),
(@EVENT, @OGUID+83);
