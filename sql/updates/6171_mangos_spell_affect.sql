DELETE FROM spell_affect WHERE (entry = 16757 OR entry = 16758) AND effectId = 1;
INSERT INTO spell_affect ( `entry` , `effectId` , `SpellFamilyMask` )
VALUES (
16757, 1, 0x240
), (
16758, 1, 0x240
);
DELETE FROM spell_affect WHERE (entry = 17904 OR (entry >= 17912 AND entry <= 17916)) AND effectId = 0;
INSERT INTO spell_affect ( `entry` , `effectId` , `SpellFamilyMask` )
VALUES (
17904, 0, 0
), (
17912, 0, 0
), (
17913, 0, 0
), (
17914, 0, 0
), (
17915, 0, 0
), (
17916, 0, 0
);
DELETE FROM spell_affect WHERE entry = 21899 AND effectId = 0;
INSERT INTO spell_affect ( `entry` , `effectId` , `SpellFamilyMask` )
VALUES (
21899, 0, 0x100
);
DELETE FROM spell_affect WHERE entry = 24542 AND effectId = 1;
INSERT INTO spell_affect ( `entry` , `effectId` , `SpellFamilyMask` )
VALUES (
24542, 1, 0xF0
);
DELETE FROM spell_affect WHERE entry = 24546 AND effectId = 1;
INSERT INTO spell_affect ( `entry` , `effectId` , `SpellFamilyMask` )
VALUES (
24546, 1, 0x400041E00
);
DELETE FROM spell_affect WHERE (entry = 29187 OR entry = 29189 OR entry = 29191) AND effectId = 1;
INSERT INTO spell_affect ( `entry` , `effectId` , `SpellFamilyMask` )
VALUES (
29187, 1, 0x4103000340750
), (
29189, 1, 0x4103000340750
), (
29191, 1, 0x4103000340750
);
DELETE FROM spell_affect WHERE entry = 39805 AND effectId = 1;
INSERT INTO spell_affect ( `entry` , `effectId` , `SpellFamilyMask` )
VALUES (
39805, 1, 0x3
);
DELETE FROM spell_affect WHERE entry = 44293 AND effectId = 0;
INSERT INTO spell_affect ( `entry` , `effectId` , `SpellFamilyMask` )
VALUES (
44293, 0, 0x200
);