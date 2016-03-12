-- 
UPDATE `quest_template` SET `AllowableRaces`=0 WHERE `id` IN (13094, 13095);
UPDATE `quest_template` SET `AllowableRaces`=`AllowableRaces`|1|4|8|64|1024|2097152 WHERE id=13094;
UPDATE `quest_template` SET `AllowableRaces`=`AllowableRaces`|2|16|32|128|256|512 WHERE id=13095;
