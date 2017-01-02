DELETE FROM `linked_respawn` WHERE `guid`IN(201369,201493,201577,201286);
DELETE FROM `creature` WHERE `id` IN(37973,37972,37970);
DELETE FROM `creature_summon_groups` WHERE `summonerId`=38008; -- Blood orb controller
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`) VALUES
(38008,0,1,37973,4682.89,2755.11,364.17,3.14159 ,6,3600000), -- Taldaram
(38008,0,1,37972,4682.73,2783.42,364.17,3.14159,6,3600000), -- Keleseth
(38008,0,1,37970,4680.29,2769.24,364.17,3.14159,6,3600000); -- Valanar

DELETE FROM spell_proc WHERE SpellId=72059;
INSERT INTO spell_proc (SpellId, SchoolMask, SpellFamilyName, SpellFamilyMask0, SpellFamilyMask1, SpellFamilyMask2, ProcFlags, SpellTypeMask, SpellPhaseMask, HitMask, AttributesMask, ProcsPerMinute, Chance, Cooldown, Charges) VALUES
(72059, 0, 0, 0x0, 0x0, 0x0, 0, 0x1, 0x2, 0x403, 0x2, 0, 0, 0, 0); -- Unstable

UPDATE `creature_template` SET `speed_walk`=0.4, `speed_run`=0.142857 WHERE `entry` IN (38454,38775); -- normal kinetic
