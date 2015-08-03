/*
Approximate damage of NPCs before armor reduction
75k-90k - The Lich King
25k-30k - Shambling Horror
3.5-5k - Drudge Ghoul
30k-40k - Raging Spirit
10k-12k - Spirit Warden
10k-12k - Terenas Menethil

Multipliers
1.2 = 10H/25N
1.5 = 25H
*/

UPDATE `creature_template` SET `mindmg`=509,`maxdmg`=683,`attackpower`=805,`dmg_multiplier`=150 WHERE `entry`=36597; -- The Lich King 10N
UPDATE `creature_template` SET `mindmg`=509,`maxdmg`=683,`attackpower`=805,`dmg_multiplier`=180 WHERE `entry`=39167; -- The Lich King 25N
UPDATE `creature_template` SET `mindmg`=509,`maxdmg`=683,`attackpower`=805,`dmg_multiplier`=180 WHERE `entry`=39168; -- The Lich King 10H
UPDATE `creature_template` SET `mindmg`=509,`maxdmg`=683,`attackpower`=805,`dmg_multiplier`=225 WHERE `entry`=39169; -- The Lich King 25H

UPDATE `creature_template` SET `mindmg`=509,`maxdmg`=683,`attackpower`=805,`dmg_multiplier`=50 WHERE `entry`=37698; -- Shambling Horror 10N
UPDATE `creature_template` SET `mindmg`=509,`maxdmg`=683,`attackpower`=805,`dmg_multiplier`=60 WHERE `entry`=39299; -- Shambling Horror 25N
UPDATE `creature_template` SET `mindmg`=509,`maxdmg`=683,`attackpower`=805,`dmg_multiplier`=60 WHERE `entry`=39300; -- Shambling Horror 10H
UPDATE `creature_template` SET `mindmg`=509,`maxdmg`=683,`attackpower`=805,`dmg_multiplier`=75 WHERE `entry`=39301; -- Shambling Horror 25H

UPDATE `creature_template` SET `mindmg`=509,`maxdmg`=683,`attackpower`=805,`dmg_multiplier`=7 WHERE `entry`=37695; -- Drudge Ghoul 10N
UPDATE `creature_template` SET `mindmg`=509,`maxdmg`=683,`attackpower`=805,`dmg_multiplier`=8.4 WHERE `entry`=39309; -- Drudge Ghoul 25N
UPDATE `creature_template` SET `mindmg`=509,`maxdmg`=683,`attackpower`=805,`dmg_multiplier`=8.4 WHERE `entry`=39310; -- Drudge Ghoul 10H
UPDATE `creature_template` SET `mindmg`=509,`maxdmg`=683,`attackpower`=805,`dmg_multiplier`=10.5 WHERE `entry`=39311; -- Drudge Ghoul 25H

UPDATE `creature_template` SET `difficulty_entry_1`=39302,`difficulty_entry_2`=39303,`difficulty_entry_3`=39304 WHERE `entry`=36701; -- Raging Spirit
UPDATE `creature_template` SET `speed_walk`=2,`speed_run`=1.42857,`exp`=2,`minlevel`=83,`maxlevel`=83,`faction_A`=14,`faction_H`=14,`dynamicflags`=0 WHERE `entry` IN (39302,39303,39304); -- Raging Spirit
UPDATE `creature_template` SET `mindmg`=509,`maxdmg`=683,`attackpower`=805,`dmg_multiplier`=60 WHERE `entry`=36701; -- Raging Spirit 10N
UPDATE `creature_template` SET `mindmg`=509,`maxdmg`=683,`attackpower`=805,`dmg_multiplier`=72 WHERE `entry`=39302; -- Raging Spirit 25N
UPDATE `creature_template` SET `mindmg`=509,`maxdmg`=683,`attackpower`=805,`dmg_multiplier`=72 WHERE `entry`=39303; -- Raging Spirit 10H
UPDATE `creature_template` SET `mindmg`=509,`maxdmg`=683,`attackpower`=805,`dmg_multiplier`=90 WHERE `entry`=39304; -- Raging Spirit 25H

UPDATE `creature_template` SET `difficulty_entry_1`=39296 WHERE `entry`=36824; -- Spirit Warden
UPDATE `creature_template` SET `minlevel`=83,`maxlevel`=83,`exp`=2,`faction_A`=14,`faction_H`=14,`flags_extra`=256 WHERE `entry`=39296; -- Spirit Warden (1)
UPDATE `creature_template` SET `mindmg`=509,`maxdmg`=683,`attackpower`=805,`dmg_multiplier`=20 WHERE `entry`=36824; -- Spirit Warden 10N
UPDATE `creature_template` SET `mindmg`=509,`maxdmg`=683,`attackpower`=805,`dmg_multiplier`=20 WHERE `entry`=39296; -- Spirit Warden 25N

UPDATE `creature_template` SET `mindmg`=509,`maxdmg`=683,`attackpower`=805,`dmg_multiplier`=20 WHERE `entry`=36823; -- Terenas Menethil
