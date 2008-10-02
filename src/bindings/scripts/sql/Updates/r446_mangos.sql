-- Set ACID (mob_eventai) ScriptName for 4 Hyjal-wave bosses
UPDATE `creature_template` SET `ScriptName` = 'mob_eventai' WHERE `entry` IN (17767, 17808, 17888, 17842);
