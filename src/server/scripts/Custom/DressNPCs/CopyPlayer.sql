SET @OUTFIT_ENTRY := 3000000123;
SET @PLAYER_GUID := 1;

-- Manually repalce WORLD_DB and CHAR_DB with your own database names below

REPLACE INTO WORLD_DB.creature_template_outfits (`entry`, `race`, `class`, `gender`, `customizations`,
`head`     ,
`shoulders`,
`body`     ,
`chest`    ,
`waist`    ,
`legs`     ,
`feet`     ,
`wrists`   ,
`hands`    ,
`back`     ,
`tabard`)
SELECT @OUTFIT_ENTRY, c.`race`, c.`class`, c.`gender`, cc.customizations,
- SUBSTRING_INDEX(SUBSTRING_INDEX(SUBSTRING_INDEX(c.equipmentCache, ' ', (0+1)*5), ' ', -4), ' ', 1)  AS HEAD      ,
- SUBSTRING_INDEX(SUBSTRING_INDEX(SUBSTRING_INDEX(c.equipmentCache, ' ', (2+1)*5), ' ', -4), ' ', 1)  AS SHOULDERS ,
- SUBSTRING_INDEX(SUBSTRING_INDEX(SUBSTRING_INDEX(c.equipmentCache, ' ', (3+1)*5), ' ', -4), ' ', 1)  AS BODY      ,
- SUBSTRING_INDEX(SUBSTRING_INDEX(SUBSTRING_INDEX(c.equipmentCache, ' ', (4+1)*5), ' ', -4), ' ', 1)  AS CHEST     ,
- SUBSTRING_INDEX(SUBSTRING_INDEX(SUBSTRING_INDEX(c.equipmentCache, ' ', (5+1)*5), ' ', -4), ' ', 1)  AS WAIST     ,
- SUBSTRING_INDEX(SUBSTRING_INDEX(SUBSTRING_INDEX(c.equipmentCache, ' ', (6+1)*5), ' ', -4), ' ', 1)  AS LEGS      ,
- SUBSTRING_INDEX(SUBSTRING_INDEX(SUBSTRING_INDEX(c.equipmentCache, ' ', (7+1)*5), ' ', -4), ' ', 1)  AS FEET      ,
- SUBSTRING_INDEX(SUBSTRING_INDEX(SUBSTRING_INDEX(c.equipmentCache, ' ', (8+1)*5), ' ', -4), ' ', 1)  AS WRISTS    ,
- SUBSTRING_INDEX(SUBSTRING_INDEX(SUBSTRING_INDEX(c.equipmentCache, ' ', (9+1)*5), ' ', -4), ' ', 1)  AS HANDS     ,
- SUBSTRING_INDEX(SUBSTRING_INDEX(SUBSTRING_INDEX(c.equipmentCache, ' ', (14+1)*5), ' ', -4), ' ', 1) AS BACK      ,
- SUBSTRING_INDEX(SUBSTRING_INDEX(SUBSTRING_INDEX(c.equipmentCache, ' ', (18+1)*5), ' ', -4), ' ', 1) AS TABARD    
FROM CHAR_DB.characters c,
(SELECT GROUP_CONCAT(CONCAT_WS(' ', chrCustomizationOptionID, chrCustomizationChoiceID) SEPARATOR ' ') AS customizations FROM CHAR_DB.character_customizations WHERE guid = @PLAYER_GUID) cc
WHERE guid = @PLAYER_GUID;
