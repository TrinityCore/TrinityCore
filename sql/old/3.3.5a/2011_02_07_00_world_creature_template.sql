UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`dynamicflags`=0,`VehicleId`=591,`minrangedmg`=345,`maxrangedmg`=509,`rangedattackpower`=103,`mindmg`=422,`maxdmg`=586,`attackpower`=642,`dmg_multiplier`=7.5,`spell3`=70542,`spell6`=71516 WHERE `entry` IN (37672,38285,38605,38786,38787,38788,38789,38790);
UPDATE `creature_template` SET `spell1`=70360,`spell2`=70539 WHERE `entry` IN (38605,38786,38787);
UPDATE `creature_template` SET `spell1`=72527,`spell2`=72457 WHERE `entry` IN (38788,38789,38790);
UPDATE `creature_template` SET `difficulty_entry_1`=38605,`difficulty_entry_2`=38786,`difficulty_entry_3`=38787 WHERE `entry`=37672;
UPDATE `creature_template` SET `difficulty_entry_1`=38788,`difficulty_entry_2`=38789,`difficulty_entry_3`=38790 WHERE `entry`=38285;
