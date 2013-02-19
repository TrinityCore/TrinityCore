UPDATE `creature_template` SET `WDBVerified`=12340 WHERE `entry`=40624; -- Verified

-- Remove temp entry 68686 and replace with wdb verified 38686
UPDATE `creature_template` SET `difficulty_entry_3`=38686 WHERE `entry`=36950;
UPDATE `creature_template` SET `minlevel`=82,`maxlevel`=82,`exp`=2,`faction_A`=84,`faction_H`=84,`mindmg`=488,`maxdmg`=642,`attackpower`=782,`unit_flags`=32832,`dynamicflags`=8,`minrangedmg`=363,`maxrangedmg`=521,`rangedattackpower`=121 WHERE `entry`=38686;
DELETE FROM `creature_template` WHERE `entry`=68686;
