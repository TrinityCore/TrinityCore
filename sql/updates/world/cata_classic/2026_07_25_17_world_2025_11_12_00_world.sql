-- CREATURE_STATIC_FLAG_4_PREVENT_SWIM
UPDATE `creature_template_difficulty` ctd
LEFT JOIN `creature_template` AS ct ON ct.`entry`=ctd.`Entry`
SET ctd.`StaticFlags4`= ctd.`StaticFlags4` | 0x01000000
WHERE (ct.`unit_flags2` & 0x01000000) != 0 AND ct.`entry` != 48182;

UPDATE `creature_template` SET `unit_flags2`= `unit_flags2` &~ 0x01000000;
UPDATE `creature_template_difficulty` SET `StaticFlags4`=`StaticFlags4` | 0x01000000 WHERE `Entry` IN (60292,55996,54470,54199,54192,53772,53740,50748,50741,50051,39943,42102,41610,41595,63172,63201,63356,64055,67057,73166);
