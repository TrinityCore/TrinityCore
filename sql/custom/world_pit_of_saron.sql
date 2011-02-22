UPDATE `creature_template` SET `faction_A` = 14, `faction_H` = 14, `unit_flags` = 66 WHERE `entry` IN ('36658', '36938'); -- Now faction is 35: boss locked in his start position so make it unattackable
UPDATE `creature_template` SET `flags_extra` = 128 WHERE `entry` = 36731;
