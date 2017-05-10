-- Orb rotation focus
UPDATE `creature_template` SET `modelid1`=11868,`modelid2`=169,`minlevel`=80,`maxlevel`=80,`faction_A`=14,`faction_H`=14,`speed_walk`=2.2,`speed_run`=0.785714,`baseattacktime`=2000,`unit_flags`=33554688 WHERE `entry` IN(43280,43281,43282);
UPDATE `creature_template` SET `difficulty_entry_1`=43280, `difficulty_entry_2`=43281,`difficulty_entry_3`=43282 WHERE `entry`=40091;

-- Orb carrier
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`exp`=2,`faction_A`=14,`faction_H`=14,`speed_walk`=1.2,`speed_run`=1.14286,`baseattacktime`=2000 WHERE `entry` IN(40470,40471,40472);
UPDATE `creature_template` SET `difficulty_entry_1`=40470, `difficulty_entry_2`=40471,`difficulty_entry_3`=40472 WHERE `entry`=40081;

-- Saviana Ragefire
UPDATE `creature_template` SET `exp`=2 WHERE `entry`=39823;

-- General Zarithrian
UPDATE `creature_template` SET `exp`=2 WHERE `entry`=39805;

-- Twilight Halion
UPDATE `creature_template` SET `difficulty_entry_1`=40143, `difficulty_entry_2`=40144,`difficulty_entry_3`=40145 WHERE `entry`=40142;
UPDATE `creature_template` SET `minlevel`=83,`maxlevel`=83,`speed_walk`=1.6,`speed_run`=1.42857,`baseattacktime`=1800,`unit_flags`=559168,`dynamicflags`=12 WHERE `entry` IN(40143,40144,40145);

-- Halion
UPDATE `creature_template` SET `speed_walk`=1.6,`speed_run`=1.42857,`baseattacktime`=1500,`unit_flags`=32832,`dynamicflags`=12,`flags_extra`=1 WHERE `entry` IN(39864,39944,39945);
UPDATE `creature_template` SET `dmg_multiplier`=50 WHERE `entry`=39944;
UPDATE `creature_template` SET `dmg_multiplier`=85 WHERE `entry`=39945;

-- Onyx Flamecaller
UPDATE `creature_template` SET `minlevel`=82,`maxlevel`=82,`faction_A`=103,`faction_H`=103,`exp`=2,`speed_walk`=0.88888,`speed_run`=1.42857,`baseattacktime`=2000,`unit_flags`=32768,`equipment_id`=2468 WHERE `entry`=39815;
