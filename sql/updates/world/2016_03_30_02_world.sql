--
UPDATE `gameobject_template` SET `faction`= 29 WHERE `entry` IN (206116, 206109, 207324, 207279, 208317, 207323, 207325);
UPDATE `gameobject_template` SET `faction`= 12 WHERE `entry` IN (206111, 206294, 207320, 208316, 207321, 207322);
UPDATE `quest_template` SET `AllowableRaces`=`AllowableRaces` | 1 | 4 | 8 | 64 | 1024 | 2097152 WHERE `id` IN (SELECT `quest` FROM `gameobject_queststarter` WHERE `id` IN (206111, 206294, 207320, 208316, 207321, 207322));
UPDATE `quest_template` SET `AllowableRaces`=`AllowableRaces` | 2 | 16 | 32 | 128 | 256 | 512 WHERE `id` IN (SELECT `quest` FROM `gameobject_queststarter` WHERE `id` IN (206116, 206109, 207324, 207279, 208317, 207323, 207325));
