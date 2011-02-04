-- Fix nonexisting required races for Gorishi Grub
UPDATE `quest_template` SET `RequiredRaces`=`RequiredRaces`|512|2 WHERE `entry`=13903; -- Orc and Blood Elf (2+512)
UPDATE `quest_template` SET `RequiredRaces`=`RequiredRaces`|128|32|16 WHERE `entry`=13917; -- Undead, Tauren, Troll (16+32+128)
