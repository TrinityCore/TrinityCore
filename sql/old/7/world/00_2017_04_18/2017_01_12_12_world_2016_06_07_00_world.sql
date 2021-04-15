-- remove incorrect trigger flag from hodir ice blocks that prevents encounter from starting
UPDATE `creature_template` SET `flags_extra`=(`flags_extra`&~128) WHERE `entry` IN (32938,33353);
