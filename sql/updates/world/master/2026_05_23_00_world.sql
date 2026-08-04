-- Update creature spawns to createobject2 positions

-- Coyote
UPDATE `creature` SET `position_x`=-9765.7783203125, `position_y`=1345.98095703125, `position_z`=41.07471466064453125, `orientation`=5.586446762084960937 WHERE `guid` = 276019;
UPDATE `creature` SET `position_x`=-9826.8212890625, `position_y`=1567.611083984375, `position_z`=39.67414093017578125, `orientation`=1.970574259757995605 WHERE `guid` = 275936;
UPDATE `creature` SET `position_x`=-9832.703125, `position_y`=1404.3836669921875, `position_z`=48.96465682983398437, `orientation`=1.717794179916381835 WHERE `guid` = 275925;
UPDATE `creature` SET `position_x`=-9927.4931640625, `position_y`=1328.607666015625, `position_z`=43.4078216552734375, `orientation`=5.445637702941894531 WHERE `guid` = 275813;
UPDATE `creature` SET `position_x`=-10017.7861328125, `position_y`=1350.388916015625, `position_z`=41.94374465942382812, `orientation`=0.777366518974304199 WHERE `guid` = 275718;

UPDATE `creature` SET `wander_distance` = 8, `MovementType` = 1 WHERE `guid` IN (276019,275936,275925,275813,275718);

-- Young Goretusk
UPDATE `creature` SET `position_x`=-9787.576171875, `position_y`=1299.685791015625, `position_z`=40.55675506591796875, `orientation`=4.565766811370849609 WHERE `guid` = 275917;
UPDATE `creature` SET `position_x`=-9851.091796875, `position_y`=1384.953125, `position_z`=51.53354644775390625, `orientation`=5.42313385009765625 WHERE `guid` = 275912;
UPDATE `creature` SET `position_x`=-9908.3330078125, `position_y`=1359.1475830078125, `position_z`=45.46649932861328125, `orientation`=0.8707658052444458 WHERE `guid` = 275817;
UPDATE `creature` SET `position_x`=-9950.7236328125, `position_y`=1350.9288330078125, `position_z`=42.2512969970703125, `orientation`=2.370773792266845703 WHERE `guid` = 275782;
UPDATE `creature` SET `position_x`=-10048.919921875, `position_y`=1371.345458984375, `position_z`=43.65888214111328125, `orientation`=3.545768976211547851 WHERE `guid` = 275725;

UPDATE `creature` SET `wander_distance` = 6, `MovementType` = 1 WHERE `guid` IN (275917,275912,275817,275782,275725);

-- Young Fleshripper
UPDATE `creature` SET `position_x`=-9818.1484375, `position_y`=1351.0841064453125, `position_z`=45.45838546752929687, `orientation`=5.497895240783691406 WHERE `guid` = 275909;
UPDATE `creature` SET `position_x`=-9773.716796875, `position_y`=1268.1805419921875, `position_z`=40.6760101318359375, `orientation`=5.993234634399414062 WHERE `guid` = 276023;
UPDATE `creature` SET `position_x`=-9853.45703125, `position_y`=1451.2882080078125, `position_z`=59.78445816040039062, `orientation`=4.542524337768554687 WHERE `guid` = 275924;
UPDATE `creature` SET `position_x`=-10023.154296875, `position_y`=1406.0538330078125, `position_z`=41.21857452392578125, `orientation`=0.516912281513214111 WHERE `guid` = 275728;

UPDATE `creature` SET `wander_distance` = 12, `MovementType` = 1 WHERE `guid` IN (275909,276023,275924,275728);

-- Fleshripper
UPDATE `creature` SET `position_x`=-9826.2548828125, `position_y`=1498.7274169921875, `position_z`=42.78895187377929687, `orientation`=0.684449195861816406 WHERE `guid` = 275918;

UPDATE `creature` SET `wander_distance` = 8, `MovementType` = 1 WHERE `guid` IN (275918);
