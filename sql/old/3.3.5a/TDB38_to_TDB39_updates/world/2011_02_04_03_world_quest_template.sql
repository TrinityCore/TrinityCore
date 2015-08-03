-- Fix nonexisting required races for Hungry Hungry Hatching
UPDATE `quest_template` SET `RequiredRaces`=`RequiredRaces`|512|2 WHERE `entry`=13889; -- Orc and Blood Elf (2+512)
UPDATE `quest_template` SET `RequiredRaces`=`RequiredRaces`|128|32|16 WHERE `entry`=13915; -- Undead, Tauren, Troll (16+32+128)
