UPDATE `creature_template` SET `dynamicflags`=`dynamicflags` &~ 1; -- lootable
UPDATE `creature_template` SET `dynamicflags`=`dynamicflags` &~ 4; -- tapped
UPDATE `creature_template` SET `dynamicflags`=`dynamicflags` &~ 8; -- tapped by player
UPDATE `creature_template` SET `dynamicflags`=`dynamicflags` &~ 128; -- tapped by threat list
