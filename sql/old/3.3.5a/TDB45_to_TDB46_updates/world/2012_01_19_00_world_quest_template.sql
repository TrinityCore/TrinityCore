-- Non sword wielders quests
UPDATE `quest_template` SET `RequiredClasses`=`RequiredClasses`
|16 -- Priest
|64 -- Shaman
|1024 -- Druid
WHERE `Id` IN (24795,24798,24798);

-- Sword wielders quests
UPDATE `quest_template` SET `RequiredClasses`=`RequiredClasses`
|1 -- Warrior
|2 -- Paladin
|4 -- Hunter
|8 -- Rouge
|32 -- Death Kinght
|128 -- Mage
|256 -- Warlock
WHERE `Id` IN (24796,24800,24801);
